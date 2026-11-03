#include "new_horizons_apu.h"
#include "new_horizons_sdsp.h"
#include "new_horizons_spc700_aot.h"
#include "new_horizons_spc700.h"
#include <string.h>

static const uint8_t nh_ipl_rom[64] = {
    0xCDu,0xEFu,0xBDu,0xE8u,0x00u,0xC6u,0x1Du,0xD0u,
    0xFCu,0x8Fu,0xAAu,0xF4u,0x8Fu,0xBBu,0xF5u,0x78u,
    0xCCu,0xF4u,0xD0u,0xFBu,0x2Fu,0x19u,0xEBu,0xF4u,
    0xD0u,0xFCu,0x7Eu,0xF4u,0xD0u,0x0Bu,0xE4u,0xF5u,
    0xCBu,0xF4u,0xD7u,0x00u,0xFCu,0xD0u,0xF3u,0xABu,
    0x01u,0x10u,0xEFu,0x7Eu,0xF4u,0x10u,0xEBu,0xBAu,
    0xF6u,0xDAu,0x00u,0xBAu,0xF4u,0xC4u,0xF4u,0xDDu,
    0x5Du,0xD0u,0xDBu,0x1Fu,0x00u,0x00u,0xC0u,0xFFu
};

static int attached(const NHApu12 *a) {
    return a != NULL && a->bus != NULL && a->scheduler != NULL &&
           a->scheduler->bus == a->bus;
}

static NHBusStop fail(NHApu12 *a, NHBusStop reason, uint32_t address,
                      NHBusValue value) {
    if (a != NULL) a->phase = NH_APU12_FAILED;
    if (a != NULL && a->bus != NULL && a->bus->failure.reason == NH_BUS_OK) {
        a->bus->failure.reason = reason;
        a->bus->failure.owner = NH_OWNER_APUIO_12;
        a->bus->failure.address = address;
        a->bus->failure.value = value.value;
        a->bus->failure.known_mask = value.known_mask;
    }
    return reason;
}

static void mark_known(NHApu12 *a, uint16_t address) {
    a->aram_known[address >> 3u] |= (uint8_t)(1u << (address & 7u));
}

int nh_apu12_aram_known(const NHApu12 *a, uint16_t address) {
    return a != NULL &&
        (a->aram_known[address >> 3u] & (uint8_t)(1u << (address & 7u))) != 0u;
}

static void timer_tick(NHApuTimer12 *t, uint64_t clocks, uint16_t period) {
    uint64_t stages, remainder, limit, distance, remaining, fires;
    if (t->enabled == 0u || clocks == 0u) return;
    stages = clocks / period;
    remainder = clocks % period + t->divider;
    stages += remainder / period;
    t->divider = (uint16_t)(remainder % period);
    if (stages == 0u) return;
    limit = t->target == 0u ? 256u : t->target;
    if ((uint64_t)t->stage < limit) distance = limit - t->stage;
    else distance = 256u - t->stage + limit;
    if (stages < distance) {
        t->stage = (uint8_t)((t->stage + stages) & 0xFFu);
        return;
    }
    remaining = stages - distance;
    fires = 1u + remaining / limit;
    t->stage = (uint8_t)(remaining % limit);
    t->output = (uint8_t)((t->output + fires) & 0x0Fu);
}

static int exact(NHBusValue value) { return value.known_mask == 0xFFu; }

static int ipl_read(NHApu12 *a, uint16_t address, uint8_t *value) {
    NHBusValue bus_value;
    if (value == NULL || nh_apu12_smp_read(a, address, &bus_value) != NH_BUS_OK ||
        bus_value.known_mask != 0xFFu) return 0;
    *value = bus_value.value;
    return 1;
}

static int ipl_write(NHApu12 *a, uint16_t address, uint8_t value) {
    return nh_apu12_smp_write(a, address,
                              (NHBusValue){value, 0xFFu}) == NH_BUS_OK;
}

static int ipl_begin(NHApu12 *a) {
    NHSpc700State13 *s = &a->spc;
    uint32_t cycles;
    uint16_t pc = s->pc;
    switch (pc) {
        case 0xFFC0u: case 0xFFC3u: cycles=2u; s->pc+=2u; break;
        case 0xFFC2u: case 0xFFC6u: case 0xFFE4u: case 0xFFF7u:
        case 0xFFF8u: cycles=2u; s->pc+=1u; break;
        case 0xFFC5u: cycles=4u; s->pc+=1u; break;
        case 0xFFC7u: case 0xFFD2u: case 0xFFD8u: case 0xFFDCu:
        case 0xFFE5u: case 0xFFE9u: case 0xFFEBu: case 0xFFEDu:
        case 0xFFF9u: cycles=2u; s->pc+=2u; break;
        case 0xFFC9u: case 0xFFCCu: case 0xFFCFu: cycles=5u; s->pc+=3u; break;
        case 0xFFD4u: cycles=4u; s->pc+=2u; break;
        case 0xFFD6u: case 0xFFDAu: case 0xFFDEu: cycles=3u; s->pc+=2u; break;
        case 0xFFE0u: case 0xFFE7u: case 0xFFF5u: cycles=4u; s->pc+=2u; break;
        case 0xFFE2u: cycles=7u; s->pc+=2u; break;
        case 0xFFEFu: case 0xFFF1u: case 0xFFF3u: cycles=5u; s->pc+=2u; break;
        case 0xFFFBu: cycles=6u; s->pc+=3u; break;
        default: return 0;
    }
    s->active_pc=pc;
    s->active_cycle_index=0u;
    s->active_latch_low=s->active_latch_high=s->active_latch_data=0u;
    s->active_branch_taken=0u;
    if (pc==0xFFC7u||pc==0xFFD2u||pc==0xFFD8u||pc==0xFFDCu||
        pc==0xFFE5u||pc==0xFFE9u||pc==0xFFEDu||pc==0xFFF9u) {
        int take=(pc==0xFFE9u||pc==0xFFEDu) ?
            (s->psw&NH_SPC_N)==0u : (s->psw&NH_SPC_Z)==0u;
        s->active_branch_taken=(uint8_t)take;
        if (take) cycles+=2u;
    }
    s->active_cycles_remaining=cycles;
    s->active=1u;
    return 1;
}

static int ipl_event(NHApu12 *a) {
    NHSpc700State13 *s=&a->spc;
    uint8_t cycle=(uint8_t)(++s->active_cycle_index);
    uint8_t fetched;
    uint16_t address;
    uint16_t length=(uint16_t)(s->pc-s->active_pc);
    if(cycle<=length){
        address=(uint16_t)(s->active_pc+cycle-1u);
        if(address<0xFFC0u||!ipl_read(a,address,&fetched)||
           fetched!=nh_ipl_rom[address-0xFFC0u])return 0;
    }
    switch (s->active_pc) {
        case 0xFFC5u:
            if(cycle==3u){if(!ipl_read(a,nh_spc_dp(a,s->x),&fetched))return 0;}
            else if(cycle==4u&&!ipl_write(a,nh_spc_dp(a,s->x),s->a))return 0;
            break;
        case 0xFFC9u: case 0xFFCCu:
            if(cycle==4u){if(!ipl_read(a,nh_spc_dp(a,s->active_pc==0xFFC9u?0xF4u:0xF5u),&fetched))return 0;}
            else if(cycle==5u&&!ipl_write(a,nh_spc_dp(a,s->active_pc==0xFFC9u?0xF4u:0xF5u),s->active_pc==0xFFC9u?0xAAu:0xBBu))return 0;
            break;
        case 0xFFCFu:
            if (cycle==4u) { if(!ipl_read(a,0x00F4u,&s->active_latch_low))return 0; nh_spc_cmp8(a,s->active_latch_low,0xCCu); }
            break;
        case 0xFFE2u:
            if(cycle==3u){if(!ipl_read(a,nh_spc_dp(a,0u),&s->active_latch_low))return 0;}
            else if(cycle==4u){if(!ipl_read(a,nh_spc_dp(a,1u),&s->active_latch_high))return 0;}
            else if(cycle==7u){
                uint8_t expected;
                address=(uint16_t)((uint16_t)(s->active_latch_low|((uint16_t)s->active_latch_high<<8u))+s->y);
                if(a->uploaded_bytes>=NH_APU_UPLOAD_BYTES ||
                   address!=(uint16_t)(NH_APU_UPLOAD_DESTINATION+a->uploaded_bytes)) return 0;
                expected=a->bus->memory.verified_rom[NH_APU_UPLOAD_ROM_OFFSET+a->uploaded_bytes];
                if(s->a!=expected) return 0;
                if(!ipl_write(a,address,s->a))return 0;
                if(a->uploaded_bytes==0u)++a->upload_epoch;
                a->upload_address=address;
                ++a->uploaded_bytes;
            }
            break;
        case 0xFFE7u:
            if(cycle==3u){if(!ipl_read(a,nh_spc_dp(a,1u),&s->active_latch_low))return 0;++s->active_latch_low;nh_spc_nz8(a,s->active_latch_low);}
            else if(cycle==4u&&!ipl_write(a,nh_spc_dp(a,1u),s->active_latch_low))return 0;
            break;
        case 0xFFD6u:
            if(cycle==3u){if(!ipl_read(a,0x00F4u,&s->y))return 0;nh_spc_nz8(a,s->y);}
            break;
        case 0xFFDAu: case 0xFFEBu:
            if(cycle==3u){if(!ipl_read(a,0x00F4u,&fetched))return 0;nh_spc_cmp8(a,s->y,fetched);}
            break;
        case 0xFFDEu:
            if(cycle==3u){if(!ipl_read(a,0x00F5u,&s->a))return 0;nh_spc_nz8(a,s->a);}
            break;
        case 0xFFE0u:
            if(cycle==3u){if(!ipl_read(a,0x00F4u,&fetched))return 0;}
            else if(cycle==4u){if(!ipl_write(a,0x00F4u,s->y))return 0;a->last_ack=s->y;a->expected_token=(uint8_t)(s->y+1u);}
            break;
        case 0xFFEFu:
            if(cycle==3u){if(!ipl_read(a,0x00F6u,&s->active_latch_low))return 0;}
            else if(cycle==5u){if(!ipl_read(a,0x00F7u,&s->active_latch_high))return 0;s->a=s->active_latch_low;s->y=s->active_latch_high;nh_spc_nz16(a,(uint16_t)(s->a|((uint16_t)s->y<<8u)));}
            break;
        case 0xFFF1u:
            if(cycle==4u&&!ipl_write(a,nh_spc_dp(a,0u),s->a))return 0;
            else if(cycle==5u){if(!ipl_write(a,nh_spc_dp(a,1u),s->y))return 0;a->upload_address=(uint16_t)(s->a|((uint16_t)s->y<<8u));}
            break;
        case 0xFFF3u:
            if(cycle==3u){if(!ipl_read(a,0x00F4u,&s->active_latch_low))return 0;}
            else if(cycle==5u){if(!ipl_read(a,0x00F5u,&s->active_latch_high))return 0;s->a=s->active_latch_low;s->y=s->active_latch_high;nh_spc_nz16(a,(uint16_t)(s->a|((uint16_t)s->y<<8u)));}
            break;
        case 0xFFF5u:
            if(cycle==3u){if(!ipl_read(a,0x00F4u,&fetched))return 0;}
            else if(cycle==4u){if(!ipl_write(a,0x00F4u,s->a))return 0;a->last_ack=s->a;}
            break;
        case 0xFFFBu:
            if(cycle==5u){if(!ipl_read(a,(uint16_t)s->x,&s->active_latch_low))return 0;}
            else if(cycle==6u&&!ipl_read(a,(uint16_t)(uint8_t)(s->x+1u),&s->active_latch_high))return 0;
            break;
        default: break;
    }
    return 1;
}

static int ipl_complete(NHApu12 *a) {
    NHSpc700State13 *s=&a->spc;
    if(!s->active||s->active_cycles_remaining!=0u)return 0;
    switch(s->active_pc){
        case 0xFFC0u:s->x=0xEFu;nh_spc_nz8(a,s->x);break;
        case 0xFFC2u:s->sp=s->x;break;
        case 0xFFC3u:s->a=0u;nh_spc_nz8(a,s->a);break;
        case 0xFFC5u:break;
        case 0xFFC6u:--s->x;nh_spc_nz8(a,s->x);break;
        case 0xFFC7u:if(s->active_branch_taken)s->pc=0xFFC5u;break;
        case 0xFFC9u:case 0xFFCCu:break;
        case 0xFFCFu:break;
        case 0xFFD2u:if(s->active_branch_taken)s->pc=0xFFCFu;break;
        case 0xFFD4u:s->pc=0xFFEFu;break;
        case 0xFFD6u:break;
        case 0xFFD8u:if(s->active_branch_taken)s->pc=0xFFD6u;break;
        case 0xFFDAu:break;
        case 0xFFDCu:if(s->active_branch_taken)s->pc=0xFFE9u;break;
        case 0xFFDEu:case 0xFFE0u:break;
        case 0xFFE2u:break;
        case 0xFFE4u:++s->y;nh_spc_nz8(a,s->y);break;
        case 0xFFE5u:if(s->active_branch_taken)s->pc=0xFFDAu;break;
        case 0xFFE7u:break;
        case 0xFFE9u:if(s->active_branch_taken)s->pc=0xFFDAu;break;
        case 0xFFEBu:break;
        case 0xFFEDu:if(s->active_branch_taken)s->pc=0xFFDAu;break;
        case 0xFFEFu:case 0xFFF1u:case 0xFFF3u:break;
        case 0xFFF5u:break;
        case 0xFFF7u:s->a=s->y;nh_spc_nz8(a,s->a);break;
        case 0xFFF8u:s->x=s->a;nh_spc_nz8(a,s->x);break;
        case 0xFFF9u:if(s->active_branch_taken)s->pc=0xFFD6u;break;
        case 0xFFFBu:
            s->pc=(uint16_t)(s->active_latch_low|((uint16_t)s->active_latch_high<<8u));
            if(s->pc!=NH_APU_STATIC_ENTRY||a->uploaded_bytes!=NH_APU_UPLOAD_BYTES)return 0;
            a->static_entry_pc=s->pc;a->phase=NH_APU13_STATIC_RUNNING;break;
        default:return 0;
    }
    s->active=0u;++s->instructions;return 1;
}

NHBusStop nh_apu12_power_on(NHApu12 *a, NHBusRuntime *bus,
                            NHScheduler *scheduler) {
    if (a == NULL || bus == NULL || scheduler == NULL || scheduler->bus != bus ||
        bus->memory.verified_rom == NULL || bus->memory.rom_size != NH_ROM_BYTES)
        return NH_BUS_BAD_ARGUMENT;
    memset(a, 0, sizeof(*a));
    a->bus = bus;
    a->scheduler = scheduler;
    a->ipl_rom_enabled = 1u;
    a->static_entry_pc = 0xFFC0u;
    a->spc.pc = 0xFFC0u;
    a->smp_startup_cycles_remaining = 2u;
    a->phase = NH_APU12_IPL_STARTUP;
    for (unsigned port = 0u; port < 4u; ++port) {
        a->cpu_to_smp[port].known_mask = 0xFFu;
        a->smp_to_cpu[port].known_mask = 0xFFu;
    }
    return NH_BUS_OK;
}

NHBusStop nh_apu12_apply_zero_aram_profile(NHApu12 *a) {
    if (!attached(a) || a->sdsp != NULL || a->smp_cycles != 0u ||
        a->scheduler->master_clock != 0u || a->write_sequence != 0u)
        return NH_BUS_BAD_ARGUMENT;
    memset(a->aram, 0, sizeof(a->aram));
    memset(a->aram_known, 0xFF, sizeof(a->aram_known));
    return NH_BUS_OK;
}

NHBusStop nh_apu12_cpu_reset(NHApu12 *a) {
    return attached(a) ? a->bus->failure.reason : NH_BUS_BAD_ARGUMENT;
}

static void finish_cpu_input_latch(NHApu12 *a) {
    unsigned port;
    for (port = 0u; port < 4u; ++port) {
        if ((a->cpu_to_smp_pending_mask & (uint8_t)(1u << port)) != 0u)
            a->cpu_to_smp[port] = a->cpu_to_smp_pending[port];
    }
    a->cpu_to_smp_pending_mask = 0u;
}

NHBusStop nh_apu12_sync(NHApu12 *a, uint64_t target_phase_units) {
    if (!attached(a) || a->sdsp == NULL ||
        target_phase_units + UINT64_C(1) < a->smp_phase_units)
        return NH_BUS_BAD_ARGUMENT;
    if (a->bus->failure.reason != NH_BUS_OK) return a->bus->failure.reason;
    /* Complete a two-phase S-SMP bus event only while its end lies before the
     * current rational target. This preserves the half-phase at which a CPU
     * input latch may still be pending. */
    while (a->smp_phase_units + UINT64_C(1) < target_phase_units) {
        uint8_t executing_ipl = (uint8_t)(a->phase == NH_APU12_IPL_STARTUP);
        if (a->smp_startup_cycles_remaining == 0u && a->spc.active == 0u) {
            int began = executing_ipl ? ipl_begin(a) :
                (a->phase == NH_APU13_STATIC_RUNNING ?
                 nh_spc700_aot_begin(a) : 0);
            if (!began)
                return a->bus->failure.reason != NH_BUS_OK ?
                    a->bus->failure.reason :
                    fail(a, NH_BUS_BAD_STATIC_GUARD, a->spc.pc,
                         (NHBusValue){0u, 0u});
        }
        timer_tick(&a->timer[0], 1u, 128u);
        timer_tick(&a->timer[1], 1u, 128u);
        timer_tick(&a->timer[2], 1u, 16u);
        if (nh_sdsp16_step(a->sdsp) != NH_BUS_OK)
            return a->bus->failure.reason;
        if (a->smp_startup_cycles_remaining != 0u) {
            --a->smp_startup_cycles_remaining;
        } else if (a->phase == NH_APU12_IPL_STARTUP ||
                   a->phase == NH_APU13_STATIC_RUNNING) {
            if (executing_ipl && !ipl_event(a))
                return a->bus->failure.reason != NH_BUS_OK ?
                    a->bus->failure.reason :
                    fail(a, NH_BUS_BAD_STATIC_GUARD, a->spc.active_pc,
                         (NHBusValue){0u, 0u});
            if (!executing_ipl && !nh_spc700_aot_event(a))
                return a->bus->failure.reason != NH_BUS_OK ?
                    a->bus->failure.reason :
                    fail(a, NH_BUS_BAD_STATIC_GUARD, a->spc.active_pc,
                         (NHBusValue){0u, 0u});
            --a->spc.active_cycles_remaining;
            if (a->spc.active_cycles_remaining == 0u) {
                int completed = executing_ipl ? ipl_complete(a) :
                                                nh_spc700_aot_complete(a);
                if (!completed)
                    return a->bus->failure.reason != NH_BUS_OK ?
                        a->bus->failure.reason :
                        fail(a, NH_BUS_BAD_STATIC_GUARD, a->spc.active_pc,
                             (NHBusValue){0u, 0u});
            }
        }
        finish_cpu_input_latch(a);
        a->smp_phase_units += UINT64_C(2);
        ++a->smp_cycles;
    }
    return NH_BUS_OK;
}

static NHBusStop cpu_read(void *opaque, uint16_t reg, NHDrivenByte *out) {
    NHApu12 *a = opaque;
    unsigned port;
    if (!attached(a) || out == NULL || reg < 0x2140u || reg > 0x2143u)
        return NH_BUS_BAD_ARGUMENT;
    if (a->bus->failure.reason != NH_BUS_OK) return a->bus->failure.reason;
    port = reg & 3u;
    ++a->register_reads[port];
    out->value = a->smp_to_cpu[port].value;
    out->known_mask = a->smp_to_cpu[port].known_mask;
    out->driven_mask = 0xFFu;
    return NH_BUS_OK;
}

static NHBusStop cpu_write(void *opaque, uint16_t reg, NHBusValue value) {
    NHApu12 *a = opaque;
    unsigned port;
    if (!attached(a) || reg < 0x2140u || reg > 0x2143u)
        return NH_BUS_BAD_ARGUMENT;
    if (a->bus->failure.reason != NH_BUS_OK) return a->bus->failure.reason;
    if (!exact(value)) return fail(a, NH_BUS_UNKNOWN_BYTE, reg, value);
    if (a->phase == NH_APU12_STATIC_ENTRY_REQUIRED || a->phase == NH_APU12_FAILED)
        return fail(a, NH_BUS_APUIO_UNAVAILABLE, reg, value);
    port = reg & 3u;
    a->cpu_to_smp_pending[port] = value;
    if (a->scheduler->smp.target_phase_units <= a->smp_phase_units) {
        a->cpu_to_smp[port] = value;
        a->cpu_to_smp_pending_mask &= (uint8_t)~(uint8_t)(1u << port);
    } else {
        a->cpu_to_smp_pending_mask |= (uint8_t)(1u << port);
    }
    a->cpu_write_sequence[port] = ++a->write_sequence;
    ++a->register_writes[port];
    return NH_BUS_OK;
}

NHRegisterPort nh_apu12_register_port(NHApu12 *a) {
    const NHRegisterPort port = { a, cpu_read, cpu_write };
    return port;
}

static NHBusStop sync_receiver(void *opaque, NHBusRuntime *bus,
                               uint64_t target) {
    NHApu12 *a = opaque;
    if (!attached(a) || a->bus != bus) return NH_BUS_BAD_ARGUMENT;
    return nh_apu12_sync(a, target);
}

static NHBusStop raster_receiver(void *opaque, NHBusRuntime *bus,
                                 const NHScheduler *scheduler,
                                 NHRasterEvent event) {
    NHApu12 *a = opaque;
    if (!attached(a) || a->bus != bus || a->scheduler != scheduler)
        return NH_BUS_BAD_ARGUMENT;
    return a->downstream.raster_event(a->downstream.opaque, bus, scheduler, event);
}

static NHBusStop boundary_receiver(void *opaque, NHBusRuntime *bus,
                                   const NHScheduler *scheduler, uint8_t kind,
                                   uint32_t address, uint8_t clocks) {
    NHApu12 *a = opaque;
    if (!attached(a) || a->bus != bus || a->scheduler != scheduler)
        return NH_BUS_BAD_ARGUMENT;
    return a->downstream.cpu_boundary(a->downstream.opaque, bus, scheduler,
                                      kind, address, clocks);
}

NHBusStop nh_apu12_bind(NHApu12 *a) {
    if (!attached(a) || a->sdsp == NULL || a->bus->ports.apuio.read != NULL ||
        a->bus->ports.apuio.write != NULL || a->scheduler->advancing != 0u ||
        a->scheduler->master_clock != 0u ||
        a->scheduler->receivers.opaque == a ||
        a->scheduler->receivers.smp_sync == NULL ||
        a->scheduler->receivers.raster_event == NULL ||
        a->scheduler->receivers.cpu_boundary == NULL) return NH_BUS_BAD_ARGUMENT;
    a->downstream = a->scheduler->receivers;
    a->bus->ports.apuio = nh_apu12_register_port(a);
    a->scheduler->receivers.opaque = a;
    a->scheduler->receivers.smp_sync = sync_receiver;
    a->scheduler->receivers.raster_event = raster_receiver;
    a->scheduler->receivers.cpu_boundary = boundary_receiver;
    return NH_BUS_OK;
}

NHBusStop nh_apu12_bind_sdsp(NHApu12 *a, NHSdsp16 *sdsp) {
    if (!attached(a) || sdsp == NULL || sdsp->bus != a->bus ||
        sdsp->aram != a->aram || sdsp->aram_known != a->aram_known ||
        a->sdsp != NULL || a->smp_cycles != 0u ||
        a->scheduler->master_clock != 0u)
        return NH_BUS_BAD_ARGUMENT;
    a->sdsp = sdsp;
    return NH_BUS_OK;
}

NHBusStop nh_apu12_smp_read(NHApu12 *a, uint16_t address, NHBusValue *out) {
    unsigned port;
    if (!attached(a) || out == NULL) return NH_BUS_BAD_ARGUMENT;
    if (a->bus->failure.reason != NH_BUS_OK) return a->bus->failure.reason;
    if (address >= 0xFFC0u && a->ipl_rom_enabled != 0u) {
        *out = (NHBusValue){ nh_ipl_rom[address - 0xFFC0u], 0xFFu };
        return NH_BUS_OK;
    }
    if (address < 0x00F0u || address >= 0x0100u) {
        if (!nh_apu12_aram_known(a, address))
            return fail(a, NH_BUS_UNKNOWN_BYTE, address, (NHBusValue){0u,0u});
        *out = (NHBusValue){ a->aram[address], 0xFFu };
        return NH_BUS_OK;
    }
    if (address >= 0x00F4u && address <= 0x00F7u) {
        *out = a->cpu_to_smp[address & 3u]; return NH_BUS_OK;
    }
    if (address == 0x00F2u) { *out = (NHBusValue){a->dsp_address,0xFFu}; return NH_BUS_OK; }
    if (address == 0x00F3u) {
        if (a->sdsp == NULL)
            return fail(a, NH_BUS_APUIO_UNAVAILABLE, address,
                        (NHBusValue){0u,0u});
        return nh_sdsp16_read(a->sdsp, a->dsp_address, out);
    }
    if (address == 0x00F8u || address == 0x00F9u) {
        *out = (NHBusValue){a->aux[address & 1u],0xFFu}; return NH_BUS_OK;
    }
    if (address >= 0x00FDu) {
        port = address - 0x00FDu;
        *out = (NHBusValue){a->timer[port].output,0xFFu};
        a->timer[port].output = 0u;
        return NH_BUS_OK;
    }
    *out = (NHBusValue){0u,0xFFu};
    return NH_BUS_OK;
}

NHBusStop nh_apu12_smp_write(NHApu12 *a, uint16_t address, NHBusValue value) {
    unsigned index;
    uint8_t enable;
    if (!attached(a)) return NH_BUS_BAD_ARGUMENT;
    if (a->bus->failure.reason != NH_BUS_OK) return a->bus->failure.reason;
    if (!exact(value)) return fail(a, NH_BUS_UNKNOWN_BYTE, address, value);
    if (address < 0x00F0u || address >= 0x0100u) {
        a->aram[address] = value.value; mark_known(a, address); return NH_BUS_OK;
    }
    if (address == 0x00F0u)
        return fail(a, NH_BUS_APUIO_UNAVAILABLE, address, value);
    if (address == 0x00F1u) {
        const uint8_t prior = a->control;
        a->control = value.value;
        if ((value.value & 0x10u) != 0u)
            a->cpu_to_smp[0] = a->cpu_to_smp[1] = (NHBusValue){0u,0xFFu};
        if ((value.value & 0x10u) != 0u) {
            a->cpu_to_smp_pending[0] = a->cpu_to_smp_pending[1] = (NHBusValue){0u,0xFFu};
            a->cpu_to_smp_pending_mask &= 0xFCu;
        }
        if ((value.value & 0x20u) != 0u)
            a->cpu_to_smp[2] = a->cpu_to_smp[3] = (NHBusValue){0u,0xFFu};
        if ((value.value & 0x20u) != 0u) {
            a->cpu_to_smp_pending[2] = a->cpu_to_smp_pending[3] = (NHBusValue){0u,0xFFu};
            a->cpu_to_smp_pending_mask &= 0xF3u;
        }
        a->ipl_rom_enabled = (uint8_t)((value.value >> 7u) & 1u);
        for (index = 0u; index < 3u; ++index) {
            enable = (uint8_t)((value.value >> index) & 1u);
            if (enable != 0u && (prior & (uint8_t)(1u << index)) == 0u) {
                a->timer[index].divider = 0u;
                a->timer[index].stage = 0u;
                a->timer[index].output = 0u;
            }
            a->timer[index].enabled = enable;
        }
        return NH_BUS_OK;
    }
    if (address == 0x00F2u) { a->dsp_address = value.value; return NH_BUS_OK; }
    if (address == 0x00F3u) {
        if (a->sdsp == NULL)
            return fail(a, NH_BUS_APUIO_UNAVAILABLE, address, value);
        return nh_sdsp16_write(a->sdsp, a->dsp_address, value);
    }
    if (address >= 0x00F4u && address <= 0x00F7u) {
        a->smp_to_cpu[address & 3u] = value; return NH_BUS_OK;
    }
    if (address == 0x00F8u || address == 0x00F9u) {
        a->aux[address & 1u] = value.value; return NH_BUS_OK;
    }
    if (address >= 0x00FAu && address <= 0x00FCu) {
        a->timer[address - 0x00FAu].target = value.value; return NH_BUS_OK;
    }
    return NH_BUS_OK;
}
