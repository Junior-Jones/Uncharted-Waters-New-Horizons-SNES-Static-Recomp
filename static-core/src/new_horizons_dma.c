#include "new_horizons_dma.h"
#include <string.h>

static NHBusStop dma_stop(NHDma10 *dma, NHBusStop reason, uint32_t address,
                           NHBusValue value) {
    if (dma->bus->failure.reason == NH_BUS_OK) {
        dma->bus->failure.reason = reason;
        dma->bus->failure.owner = NH_OWNER_DMA_10;
        dma->bus->failure.address = address;
        dma->bus->failure.value = value.value;
        dma->bus->failure.known_mask = value.known_mask;
    }
    return dma->bus->failure.reason;
}

static int same_machine(const NHDma10 *dma) {
    return dma != NULL && dma->bus != NULL && dma->scheduler != NULL &&
           dma->scheduler->bus == dma->bus;
}

static NHBusStop need(NHDma10 *dma, unsigned channel, unsigned reg, uint8_t bits) {
    const NHBusValue value = dma->channel[channel].registers[reg];
    return (value.known_mask & bits) == bits ? NH_BUS_OK :
        dma_stop(dma, NH_BUS_UNKNOWN_BYTE, 0x4300u + channel * 16u + reg, value);
}

static uint16_t word(const NHDmaChannel10 *channel, unsigned reg) {
    return (uint16_t)(channel->registers[reg].value |
                     ((uint16_t)channel->registers[reg + 1u].value << 8u));
}

static void put_word(NHDmaChannel10 *channel, unsigned reg, uint16_t value) {
    channel->registers[reg].value = (uint8_t)value;
    channel->registers[reg + 1u].value = (uint8_t)(value >> 8u);
    channel->registers[reg].known_mask = 0xFFu;
    channel->registers[reg + 1u].known_mask = 0xFFu;
}

static NHBusStop need_word(NHDma10 *dma, unsigned channel, unsigned reg) {
    NHBusStop status = need(dma, channel, reg, 0xFFu);
    return status == NH_BUS_OK ? need(dma, channel, reg + 1u, 0xFFu) : status;
}

static uint8_t mode_offset(uint8_t mode, unsigned byte) {
    switch (mode & 7u) {
        case 1u: case 5u: return (uint8_t)(byte & 1u);
        case 3u: case 7u: return (uint8_t)((byte >> 1u) & 1u);
        case 4u: return (uint8_t)(byte & 3u);
        default: return 0u;
    }
}

static unsigned mode_bytes(uint8_t mode) {
    mode &= 7u;
    return mode == 0u ? 1u : (mode == 1u || mode == 2u || mode == 6u) ? 2u : 4u;
}

static int forbidden_a(uint32_t address) {
    const unsigned bank = address >> 16u;
    const uint16_t offset = (uint16_t)address;
    return (bank & 0x40u) == 0u &&
        ((offset >= 0x2100u && offset <= 0x21FFu) ||
         offset == 0x420Bu || offset == 0x420Cu ||
         (offset >= 0x4300u && offset <= 0x437Fu));
}

static NHBusStop advance(NHDma10 *dma, uint32_t clocks) {
    return nh_scheduler_transfer_advance(dma->scheduler, clocks);
}

static NHBusStop read_phase(NHDma10 *dma, uint32_t address, int a_bus,
                             NHBusValue *value) {
    const NHBusStop status = advance(dma, 4u);
    if (status != NH_BUS_OK) return status;
    if (a_bus != 0 && forbidden_a(address)) {
        *value = dma->bus->mdr;
        return NH_BUS_OK;
    }
    return nh_bus_read_sample(dma->bus, address, value);
}

static NHBusStop write_phase(NHDma10 *dma, uint32_t address, int a_bus,
                              NHBusValue value) {
    NHBusStop status = advance(dma, 4u);
    if (status != NH_BUS_OK) return status;
    if (a_bus == 0 || !forbidden_a(address))
        status = nh_bus_write_commit(dma->bus, address, value);
    /* The DMA data driver remains visible even on a prohibited A-bus write.
     * Device effects still use08; this is not another mapped bus path. */
    if (status == NH_BUS_OK) dma->bus->mdr = value;
    return status;
}

static NHBusStop copy_byte(NHDma10 *dma, uint32_t a, uint16_t b, uint8_t reverse) {
    NHBusRegion region;
    NHBusValue value;
    NHBusStop status;
    int conflict;
    if (!nh_bus_classify(a, &region)) return NH_BUS_BAD_ARGUMENT;
    conflict = b == 0x2180u && region.kind == NH_BUS_WRAM;
    if (conflict && reverse == 0u) status = advance(dma, 8u);
    else if (conflict) {
        value.value = 0xFFu;
        value.known_mask = 0xFFu;
        status = advance(dma, 4u);
        if (status == NH_BUS_OK) status = write_phase(dma, a, 1, value);
    } else {
        status = read_phase(dma, reverse != 0u ? b : a, reverse == 0u, &value);
        if (status == NH_BUS_OK)
            status = write_phase(dma, reverse != 0u ? a : b, reverse != 0u, value);
    }
    if (status == NH_BUS_OK) ++dma->completed_bytes;
    return status;
}

/* Table reads always occupy eight transfer clocks, even when the caller
 * discards the sample on a non-reload HDMA line. Consuming/incrementing the
 * table pointer is separate from the read itself. */
static NHBusStop table_read(NHDma10 *dma, unsigned index, NHBusValue *value) {
    NHDmaChannel10 *channel = &dma->channel[index];
    NHBusStop status = need(dma, index, 4u, 0xFFu);
    if (status == NH_BUS_OK) status = need_word(dma, index, 8u);
    if (status != NH_BUS_OK) return status;
    status = read_phase(dma, ((uint32_t)channel->registers[4].value << 16u) |
                            word(channel, 8u), 1, value);
    return status == NH_BUS_OK ? advance(dma, 4u) : status;
}

static void next_table(NHDmaChannel10 *channel) {
    put_word(channel, 8u, (uint16_t)(word(channel, 8u) + 1u));
}

static NHBusStop indirect_pointer(NHDma10 *dma, unsigned index, int one_byte) {
    NHDmaChannel10 *channel = &dma->channel[index];
    NHBusValue first, second;
    NHBusStop status = table_read(dma, index, &first);
    if (status != NH_BUS_OK) return status;
    next_table(channel);
    if (one_byte != 0) {
        channel->registers[5].value = 0u;
        channel->registers[5].known_mask = 0xFFu;
        channel->registers[6] = first;
        return NH_BUS_OK;
    }
    channel->registers[5] = first;
    status = table_read(dma, index, &second);
    if (status != NH_BUS_OK) return status;
    next_table(channel);
    channel->registers[6] = second;
    return NH_BUS_OK;
}

static NHBusStop hdma_init(NHDma10 *dma, uint8_t mask) {
    unsigned index;
    for (index = 0u; index < 8u; ++index) {
        dma->channel[index].finished = 0u;
        dma->channel[index].transfer_line = 0u;
    }
    /* Field initialization resets hidden state even with no enabled channel.
     * No table/register reload or transfer clocks belong to that empty case. */
    if (mask == 0u) return NH_BUS_OK;
    for (index = 0u; index < 8u; ++index) {
        NHDmaChannel10 *channel = &dma->channel[index];
        NHBusValue count;
        NHBusStop status;
        channel->transfer_line = 1u;
        if ((mask & (1u << index)) == 0u) continue;
        dma->active_channel = (uint8_t)(0x80u | index);
        channel->manual_active = 0u;
        status = need_word(dma, index, 2u);
        if (status != NH_BUS_OK) return status;
        put_word(channel, 8u, word(channel, 2u));
        status = table_read(dma, index, &count);
        if (status != NH_BUS_OK) return status;
        next_table(channel);
        channel->registers[10] = count;
        status = need(dma, index, 10u, 0xFFu);
        if (status == NH_BUS_OK) status = need(dma, index, 0u, 0x40u);
        if (status != NH_BUS_OK) return status;
        channel->finished = count.value == 0u ? 1u : 0u;
        if ((channel->registers[0].value & 0x40u) != 0u) {
            status = indirect_pointer(dma, index, channel->finished != 0u);
            if (status != NH_BUS_OK) return status;
        }
    }
    return NH_BUS_OK;
}

static int last_active(const NHDma10 *dma, unsigned index, uint8_t mask) {
    for (++index; index < 8u; ++index)
        if ((mask & (1u << index)) != 0u && dma->channel[index].finished == 0u)
            return 0;
    return 1;
}

static NHBusStop hdma_line(NHDma10 *dma, uint8_t mask) {
    unsigned index;
    for (index = 0u; index < 8u; ++index) {
        NHDmaChannel10 *channel = &dma->channel[index];
        NHBusStop status;
        unsigned byte;
        uint8_t control;
        if ((mask & (1u << index)) == 0u || channel->finished != 0u) continue;
        channel->manual_active = 0u;
        if (channel->transfer_line == 0u) continue;
        dma->active_channel = (uint8_t)(0x80u | index);
        status = need(dma, index, 0u, 0xC7u);
        if (status == NH_BUS_OK) status = need(dma, index, 1u, 0xFFu);
        if (status != NH_BUS_OK) return status;
        control = channel->registers[0].value;
        for (byte = 0u; byte < mode_bytes(control); ++byte) {
            const unsigned pointer = (control & 0x40u) != 0u ? 5u : 8u;
            const unsigned bank = (control & 0x40u) != 0u ? 7u : 4u;
            uint32_t address;
            const uint16_t target = (uint16_t)(0x2100u |
                (uint8_t)(channel->registers[1].value + mode_offset(control, byte)));
            status = need_word(dma, index, pointer);
            if (status == NH_BUS_OK) status = need(dma, index, bank, 0xFFu);
            if (status != NH_BUS_OK) return status;
            address = ((uint32_t)channel->registers[bank].value << 16u) | word(channel, pointer);
            status = copy_byte(dma, address, target, control & 0x80u);
            if (status != NH_BUS_OK) return status;
            put_word(channel, pointer, (uint16_t)(word(channel, pointer) + 1u));
        }
    }
    for (index = 0u; index < 8u; ++index) {
        NHDmaChannel10 *channel = &dma->channel[index];
        NHBusValue sampled;
        NHBusStop status;
        if ((mask & (1u << index)) == 0u || channel->finished != 0u) continue;
        dma->active_channel = (uint8_t)(0x80u | index);
        status = need(dma, index, 10u, 0xFFu);
        if (status != NH_BUS_OK) return status;
        --channel->registers[10].value;
        channel->transfer_line = (uint8_t)((channel->registers[10].value >> 7u) & 1u);
        status = table_read(dma, index, &sampled);
        if (status != NH_BUS_OK) return status;
        if ((channel->registers[10].value & 0x7Fu) != 0u) continue;
        next_table(channel);
        channel->registers[10] = sampled;
        status = need(dma, index, 10u, 0xFFu);
        if (status == NH_BUS_OK) status = need(dma, index, 0u, 0x40u);
        if (status != NH_BUS_OK) return status;
        channel->finished = sampled.value == 0u ? 1u : 0u;
        channel->transfer_line = 1u;
        if ((channel->registers[0].value & 0x40u) != 0u) {
            status = indirect_pointer(dma, index,
                sampled.value == 0u && last_active(dma, index, mask));
            if (status != NH_BUS_OK) return status;
        }
    }
    return NH_BUS_OK;
}

static NHBusStop service_hdma(NHDma10 *dma) {
    NHBusStop status;
    const uint8_t saved = dma->active_channel;
    if (dma->start_delay != 0u) {
        --dma->start_delay;
        return NH_BUS_OK;
    }
    if (dma->line_pending != 0u) {
        dma->line_pending = 0u;
        if (dma->hdma_enable == 0u) return NH_BUS_OK;
        status = advance(dma, 8u);
        if (status == NH_BUS_OK) status = hdma_line(dma, dma->hdma_enable);
    } else if (dma->init_pending != 0u) {
        dma->init_pending = 0u;
        if (dma->hdma_enable == 0u) return hdma_init(dma, 0u);
        status = advance(dma, 8u);
        if (status == NH_BUS_OK) status = hdma_init(dma, dma->hdma_enable);
    } else return NH_BUS_OK;
    if (status == NH_BUS_OK) dma->active_channel = saved;
    return status;
}

static NHBusStop manual_dma(NHDma10 *dma, uint8_t mask) {
    unsigned index;
    NHBusStop status = service_hdma(dma);
    if (status != NH_BUS_OK) return status;
    for (index = 0u; index < 8u; ++index) {
        NHDmaChannel10 *channel = &dma->channel[index];
        unsigned phase = 0u;
        if ((mask & (1u << index)) == 0u || channel->manual_active == 0u) continue;
        dma->active_channel = (uint8_t)index;
        status = advance(dma, 8u);
        if (status == NH_BUS_OK) status = service_hdma(dma);
        if (status != NH_BUS_OK) return status;
        if (channel->manual_active == 0u) continue;
        status = need(dma, index, 0u, 0x8Fu);
        if (status == NH_BUS_OK && (channel->registers[0].value & 8u) == 0u)
            status = need(dma, index, 0u, 0x10u);
        if (status == NH_BUS_OK) status = need(dma, index, 1u, 0xFFu);
        if (status == NH_BUS_OK) status = need_word(dma, index, 2u);
        if (status == NH_BUS_OK) status = need(dma, index, 4u, 0xFFu);
        if (status == NH_BUS_OK) status = need_word(dma, index, 5u);
        if (status != NH_BUS_OK) return status;
        do {
            const uint8_t control = channel->registers[0].value;
            const uint32_t source = ((uint32_t)channel->registers[4].value << 16u) | word(channel, 2u);
            const uint16_t target = (uint16_t)(0x2100u |
                (uint8_t)(channel->registers[1].value + mode_offset(control, phase)));
            status = copy_byte(dma, source, target, control & 0x80u);
            if (status != NH_BUS_OK) return status;
            if ((control & 8u) == 0u)
                put_word(channel, 2u, (uint16_t)(word(channel, 2u) +
                    ((control & 0x10u) != 0u ? 0xFFFFu : 1u)));
            put_word(channel, 5u, (uint16_t)(word(channel, 5u) - 1u));
            ++phase;
            /* Commit the completed manual byte before HDMA can reuse DAS or
             * cancel this same channel. The08/09 effects are never rolled back. */
            status = service_hdma(dma);
            if (status != NH_BUS_OK) return status;
        } while (channel->manual_active != 0u && word(channel, 5u) != 0u);
        channel->manual_active = 0u;
    }
    return NH_BUS_OK;
}

static NHBusStop register_read(void *opaque, uint16_t reg, NHDrivenByte *value) {
    NHDma10 *dma = opaque;
    unsigned offset;
    if (!same_machine(dma) || value == NULL) return NH_BUS_BAD_ARGUMENT;
    if (dma->bus->failure.reason != NH_BUS_OK) return dma->bus->failure.reason;
    value->value = value->driven_mask = value->known_mask = 0u;
    if (reg == 0x420Bu || reg == 0x420Cu) return NH_BUS_OK;
    if (reg < 0x4300u || reg > 0x437Fu) return NH_BUS_UNPROVED_REGISTER;
    offset = reg & 15u;
    if (offset == 15u) offset = 11u;
    if (offset < 12u) {
        const NHBusValue stored = dma->channel[(reg >> 4u) & 7u].registers[offset];
        value->value = stored.value;
        value->known_mask = stored.known_mask;
        value->driven_mask = 0xFFu;
    }
    return NH_BUS_OK;
}

static NHBusStop register_write(void *opaque, uint16_t reg, NHBusValue value) {
    NHDma10 *dma = opaque;
    unsigned offset, index;
    if (!same_machine(dma)) return NH_BUS_BAD_ARGUMENT;
    if (dma->bus->failure.reason != NH_BUS_OK) return dma->bus->failure.reason;
    if (reg == 0x420Bu || reg == 0x420Cu) {
        if (value.known_mask != 0xFFu) return dma_stop(dma, NH_BUS_UNKNOWN_BYTE, reg, value);
        if (reg == 0x420Cu) dma->hdma_enable = value.value;
        else if (value.value != 0u) {
            dma->manual_pending |= value.value;
            dma->start_delay = 1u;
            for (index = 0u; index < 8u; ++index)
                if ((value.value & (1u << index)) != 0u) dma->channel[index].manual_active = 1u;
        }
        return NH_BUS_OK;
    }
    if (reg < 0x4300u || reg > 0x437Fu) return NH_BUS_UNPROVED_REGISTER;
    offset = reg & 15u;
    if (offset == 15u) offset = 11u;
    if (offset < 12u) dma->channel[(reg >> 4u) & 7u].registers[offset] = value;
    return NH_BUS_OK;
}

static NHBusStop sync_smp(void *opaque, NHBusRuntime *bus, uint64_t target) {
    NHDma10 *dma = opaque;
    if (!same_machine(dma) || dma->bus != bus) return NH_BUS_BAD_ARGUMENT;
    return dma->downstream.smp_sync(dma->downstream.opaque, bus, target);
}

static NHBusStop raster(void *opaque, NHBusRuntime *bus, const NHScheduler *scheduler,
                         NHRasterEvent event) {
    NHDma10 *dma = opaque;
    if (!same_machine(dma) || dma->bus != bus || dma->scheduler != scheduler) return NH_BUS_BAD_ARGUMENT;
    if (event == NH_RASTER_HDMA_INIT_REQUEST) {
        dma->init_pending = 1u;
        dma->start_delay = 1u;
    } else if (event == NH_RASTER_HDMA_LINE_REQUEST && dma->hdma_enable != 0u) {
        dma->line_pending = 1u;
        dma->start_delay = 1u;
    }
    return dma->downstream.raster_event(dma->downstream.opaque, bus, scheduler, event);
}

static NHBusStop boundary(void *opaque, NHBusRuntime *bus, const NHScheduler *scheduler,
                           uint8_t kind, uint32_t address, uint8_t clocks) {
    NHDma10 *dma = opaque;
    NHBusStop status;
    uint64_t pause;
    uint8_t delay, mask, event;
    const NHBusValue unknown = { 0u, 0u };
    (void)kind;
    (void)address;
    if (!same_machine(dma) || dma->bus != bus || dma->scheduler != scheduler)
        return NH_BUS_BAD_ARGUMENT;
    if (bus->failure.reason != NH_BUS_OK) return bus->failure.reason;
    if (dma->servicing != 0u || scheduler->advancing == 0u ||
        scheduler->transfer_boundary == 0u ||
        (clocks != 6u && clocks != 8u && clocks != 12u))
        return dma_stop(dma, NH_BUS_CLOCK_UNAVAILABLE, address, unknown);
    if (dma->start_delay != 0u) {
        --dma->start_delay;
        return NH_BUS_OK;
    }
    mask = dma->hdma_enable;
    if (dma->line_pending != 0u) { dma->line_pending = 0u; event = 1u; }
    else if (dma->init_pending != 0u) { dma->init_pending = 0u; event = 2u; }
    else if (dma->manual_pending != 0u) {
        event = 0u;
        mask = dma->manual_pending;
        dma->manual_pending = 0u;
    } else return NH_BUS_OK;
    if (event != 0u && mask == 0u)
        return event == 2u ? hdma_init(dma, 0u) : NH_BUS_OK;
    dma->servicing = 1u;
    pause = scheduler->master_clock;
    status = nh_scheduler_dma_alignment(scheduler, 0u, &delay);
    if (status == NH_BUS_OK) status = advance(dma, delay);
    if (status == NH_BUS_OK) status = advance(dma, 8u);
    if (status == NH_BUS_OK)
        status = event == 0u ? manual_dma(dma, mask) :
                 event == 1u ? hdma_line(dma, mask) : hdma_init(dma, mask);
    if (status == NH_BUS_OK) status = nh_scheduler_dma_resume_delay(scheduler, pause, clocks, &delay);
    if (status == NH_BUS_OK) status = advance(dma, delay);
    dma->servicing = 0u;
    if (status == NH_BUS_OK) dma->active_channel = 0xFFu;
    return status;
}

NHBusStop nh_dma10_bind(NHDma10 *dma, NHBusRuntime *bus, NHScheduler *scheduler) {
    NHSchedulerReceivers downstream;
    unsigned index, reg;
    if (dma == NULL || bus == NULL || scheduler == NULL || scheduler->bus != bus ||
        bus->failure.reason != NH_BUS_OK || scheduler->advancing != 0u ||
        scheduler->master_clock != 0u || scheduler->smp_started != 0u ||
        scheduler->receivers.opaque == dma || scheduler->receivers.smp_sync == NULL ||
        scheduler->receivers.raster_event == NULL || bus->ports.dma.read != NULL ||
        bus->ports.dma.write != NULL) return NH_BUS_BAD_ARGUMENT;
    downstream = scheduler->receivers;
    downstream.cpu_boundary = NULL;
    memset(dma, 0, sizeof(*dma));
    dma->bus = bus;
    dma->scheduler = scheduler;
    dma->downstream = downstream;
    dma->active_channel = 0xFFu;
    for (index = 0u; index < 8u; ++index)
        for (reg = 0u; reg < 12u; ++reg) {
            dma->channel[index].registers[reg].value = 0xFFu;
            dma->channel[index].registers[reg].known_mask = 0xFFu;
        }
    bus->ports.dma.opaque = dma;
    bus->ports.dma.read = register_read;
    bus->ports.dma.write = register_write;
    scheduler->receivers.opaque = dma;
    scheduler->receivers.smp_sync = sync_smp;
    scheduler->receivers.raster_event = raster;
    scheduler->receivers.cpu_boundary = boundary;
    return NH_BUS_OK;
}

NHBusStop nh_dma10_reset(NHDma10 *dma) {
    unsigned index;
    if (!same_machine(dma) || dma->servicing != 0u) return NH_BUS_BAD_ARGUMENT;
    dma->manual_pending = dma->hdma_enable = dma->line_pending = dma->init_pending = 0u;
    dma->start_delay = 0u;
    dma->active_channel = 0xFFu;
    for (index = 0u; index < 8u; ++index) dma->channel[index].manual_active = 0u;
    return NH_BUS_OK;
}
