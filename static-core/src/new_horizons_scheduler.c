#include "new_horizons_scheduler.h"
#include <string.h>

static NHBusStop scheduler_fail(NHScheduler *scheduler, NHBusStop reason) {
    if (scheduler->bus->failure.reason == NH_BUS_OK) {
        scheduler->bus->failure.reason = reason;
        scheduler->bus->failure.owner = NH_OWNER_CLOCK_09;
        scheduler->bus->failure.address = 0u;
        scheduler->bus->failure.value = 0u;
        scheduler->bus->failure.known_mask = 0u;
    }
    return scheduler->bus->failure.reason;
}

uint16_t nh_scheduler_line_clocks(const NHScheduler *scheduler) {
    if (scheduler == NULL) return 0u;
    return scheduler->interlace == 0u && scheduler->field != 0u &&
           scheduler->scanline == 240u ? NH_NTSC_SHORT_LINE_CLOCKS : NH_NTSC_NORMAL_LINE_CLOCKS;
}

uint16_t nh_scheduler_dot(const NHScheduler *scheduler) {
    uint16_t h;
    if (scheduler == NULL) return 0u;
    h = scheduler->hclock;
    if (nh_scheduler_line_clocks(scheduler) == NH_NTSC_SHORT_LINE_CLOCKS) return (uint16_t)(h / 4u);
    /* Two six-clock dots,323 and327, not a flat hclock/4 mapping. */
    if (h < 1292u) return (uint16_t)(h / 4u);
    if (h < 1298u) return 323u;
    if (h < 1310u) return (uint16_t)((h - 2u) / 4u);
    if (h < 1316u) return 327u;
    return (uint16_t)((h - 4u) / 4u);
}

static uint16_t vblank_line(const NHScheduler *scheduler) {
    return scheduler->overscan != 0u ? 240u : 225u;
}

NHBusStop nh_scheduler_diagnostic(const NHScheduler *scheduler,
                                   NHSchedulerDiagnostic *diagnostic) {
    if (scheduler == NULL || diagnostic == NULL || scheduler->bus == NULL)
        return NH_BUS_BAD_ARGUMENT;
    diagnostic->profile = nh_timing_profile();
    diagnostic->master_clock = scheduler->master_clock;
    diagnostic->completed_fields = scheduler->completed_fields;
    diagnostic->smp_target_cycles = scheduler->smp.target_cycles;
    diagnostic->smp_remainder = scheduler->smp.remainder;
    diagnostic->scanline = scheduler->scanline;
    diagnostic->hclock = scheduler->hclock;
    diagnostic->dot = nh_scheduler_dot(scheduler);
    diagnostic->field = scheduler->field;
    diagnostic->interlace = scheduler->interlace;
    diagnostic->overscan = scheduler->overscan;
    diagnostic->hblank = scheduler->hblank;
    diagnostic->vblank = scheduler->vblank;
    diagnostic->refreshing = scheduler->refreshing;
    diagnostic->advancing = scheduler->advancing;
    diagnostic->nmi_flag = scheduler->nmi_flag;
    diagnostic->nmi_line = scheduler->nmi_line;
    diagnostic->nmi_edge_latched = scheduler->nmi_edge_latched;
    diagnostic->nmi_pending = scheduler->nmi_pending;
    diagnostic->irq_flag = scheduler->irq_flag;
    diagnostic->irq_flag_known = scheduler->irq_flag_known;
    diagnostic->irq_line = scheduler->irq_line;
    diagnostic->irq_level = scheduler->irq_level;
    diagnostic->irq_wait_ticks = scheduler->irq_wait_ticks;
    diagnostic->irq_phase_valid = scheduler->irq_phase_valid;
    diagnostic->irq_hcounter = scheduler->irq_hcounter;
    diagnostic->irq_vcounter = scheduler->irq_vcounter;
    diagnostic->irq_phase_clock = scheduler->irq_phase_clock;
    diagnostic->external_irq = scheduler->external_irq;
    diagnostic->irq_assert_clock = scheduler->irq_assert_clock;
    diagnostic->poll_valid = scheduler->poll_valid;
    diagnostic->polled_interrupt = scheduler->polled_interrupt;
    diagnostic->poll_context_key = scheduler->poll_context_key;
    diagnostic->autojoy_active = scheduler->autojoy_active;
    diagnostic->autojoy_busy = scheduler->autojoy_busy;
    diagnostic->autojoy_field_claimed = scheduler->autojoy_field_claimed;
    diagnostic->autojoy_step = scheduler->autojoy_step;
    diagnostic->autojoy_effects = scheduler->autojoy_effects;
    diagnostic->autojoy_next_clock = scheduler->autojoy_next_clock;
    diagnostic->autojoy_start_clock = scheduler->autojoy_start_clock;
    diagnostic->autojoy_last_clock = scheduler->autojoy_last_clock;
    diagnostic->autojoy_phase_origin = scheduler->autojoy_phase_origin;
    diagnostic->transfer_boundary = scheduler->transfer_boundary;
    diagnostic->transfer_advancing = scheduler->transfer_advancing;
    diagnostic->bus_failure = scheduler->bus->failure;
    return NH_BUS_OK;
}

/* Anomie measured the first refresh at538, then a global eight-clock phase
 * nearest line+536. Nominal construction recurrence below yields534/538.
 * It is not a universal console-revision or stall-pulse certificate. */
static uint16_t refresh_clock(const NHScheduler *scheduler) {
    const uint64_t origin = scheduler->master_clock - scheduler->hclock;
    const uint8_t residue = (uint8_t)(origin & 7u);
    const uint8_t forward = (uint8_t)((2u + 8u - residue) & 7u);
    return (uint16_t)(forward <= 4u ? 536u + forward : 528u + forward);
}

static NHBusStop notify(NHScheduler *scheduler, NHRasterEvent event) {
    NHBusStop status = scheduler->receivers.raster_event(scheduler->receivers.opaque,
                         scheduler->bus, scheduler, event);
    if (status != NH_BUS_OK) return scheduler_fail(scheduler, status);
    return scheduler->bus->failure.reason;
}

/* The mask is consumed before notifying a receiver. On failure, already
 * elapsed time and earlier side effects remain; sticky failure forbids retry. */
static NHBusStop due_events(NHScheduler *scheduler) {
    NHBusStop status;
    unsigned event;
    const uint16_t hclock = scheduler->hclock;
    /* Like the mature references' due-event dispatch, do not scan every
       raster event on clocks where none can occur. This is only a guard:
       retain the original ordered scan on every possible event boundary.
       refresh_clock() spans533..540 for all eight origin residues; refresh
       end spans573..580. HDMA init spans12..19. Peripheral entry guards below
       preserve every possible state change; wall_span separately proves any
       omitted intermediate boundary has no observable event. */
    if (!(hclock == 0u || hclock == 2u || hclock == 4u || hclock == 6u ||
        (hclock >= 12u && hclock <= 19u) ||
        (hclock >= 533u && hclock <= 540u) ||
        (hclock >= 573u && hclock <= 580u) ||
        hclock == 1096u || hclock == 1104u)) goto peripheral_ticks;
    for (event = 0u; event <= NH_RASTER_HDMA_LINE_REQUEST; ++event) {
        uint16_t at = 0u;
        int applicable = 1;
        const uint16_t bit = (uint16_t)(1u << event);
        if ((scheduler->processed_events & bit) != 0u) continue;
        switch ((NHRasterEvent)event) {
            case NH_RASTER_LINE_BEGIN: break;
            case NH_RASTER_FIELD_TOGGLE: at = 4u; applicable = scheduler->scanline == 0u; break;
            case NH_RASTER_HBLANK_BEGIN: at = 1096u; break;
            case NH_RASTER_HBLANK_END: at = 4u; break;
            case NH_RASTER_VBLANK_BEGIN: applicable = scheduler->scanline == vblank_line(scheduler); break;
            case NH_RASTER_VBLANK_END: applicable = scheduler->scanline == 0u; break;
            case NH_RASTER_NMI_FLAG_SET: at = 2u; applicable = scheduler->scanline == vblank_line(scheduler); break;
            case NH_RASTER_NMI_FLAG_CLEAR: at = 2u; applicable = scheduler->scanline == 0u; break;
            case NH_RASTER_NMI_ASSERT: at = 6u; applicable = scheduler->scanline == vblank_line(scheduler); break;
            case NH_RASTER_REFRESH_BEGIN: at = refresh_clock(scheduler); break;
            case NH_RASTER_REFRESH_END: at = (uint16_t)(refresh_clock(scheduler) + 40u); break;
            case NH_RASTER_IRQ_ASSERT: applicable = 0; break; /* comparator below */
            case NH_RASTER_HDMA_INIT_REQUEST:
                /* Request phase is line-origin aligned; the10 transfer
                 * owner applies its subsequent CPU-boundary start delay. */
                at = (uint16_t)(12u + ((scheduler->master_clock - scheduler->hclock) & 7u));
                applicable = scheduler->scanline == 0u; break;
            case NH_RASTER_HDMA_LINE_REQUEST:
                at = 1104u; applicable = scheduler->scanline < vblank_line(scheduler); break;
        }
        if (!applicable || scheduler->hclock != at) continue;
        scheduler->processed_events |= bit;
        switch ((NHRasterEvent)event) {
            case NH_RASTER_FIELD_TOGGLE: scheduler->field ^= 1u; break;
            case NH_RASTER_HBLANK_BEGIN: scheduler->hblank = 1u; break;
            case NH_RASTER_HBLANK_END: scheduler->hblank = 0u; break;
            case NH_RASTER_VBLANK_BEGIN: scheduler->vblank = 1u; break;
            case NH_RASTER_VBLANK_END:
                scheduler->vblank = 0u;
                scheduler->autojoy_field_claimed = 0u;
                break;
            case NH_RASTER_NMI_FLAG_SET: scheduler->nmi_flag = 1u; break;
            case NH_RASTER_NMI_FLAG_CLEAR: scheduler->nmi_flag = 0u; break;
            case NH_RASTER_NMI_ASSERT:
                /* The ordinary blank edge is later than status visibility.
                 * A status read does not cancel this normal opportunity;
                 * an earlier late-enable edge already holding the line high
                 * must not produce a second captured edge here. */
                if ((scheduler->nmitimen & 0x80u) != 0u && scheduler->nmi_line == 0u) {
                    scheduler->nmi_line = 1u;
                    scheduler->nmi_edge_latched = 1u;
                }
                break;
            case NH_RASTER_REFRESH_BEGIN: scheduler->refreshing = 1u; break;
            case NH_RASTER_REFRESH_END: scheduler->refreshing = 0u; break;
            default: break;
        }
        if (event == NH_RASTER_NMI_FLAG_CLEAR)
            nh_scheduler_update_nmi_line(scheduler);
        status = notify(scheduler, (NHRasterEvent)event);
        if (status != NH_BUS_OK) return status;
    }
peripheral_ticks:
    /* These are exactly the owners' no-op entry conditions, not new device
     * behavior. Avoid external calls on other clocks. Read current state
     * AFTER raster/IRQ callbacks, preserving their effects and order. */
    if ((scheduler->hclock & 3u) == 2u &&
        (!scheduler->irq_phase_valid || scheduler->irq_phase_clock != scheduler->master_clock)) {
        status = nh_scheduler_irq_tick(scheduler);
        if (status != NH_BUS_OK) return scheduler_fail(scheduler, status);
    }
    if ((scheduler->autojoy_active && scheduler->master_clock >= scheduler->autojoy_next_clock) ||
        (!scheduler->autojoy_active && !scheduler->autojoy_field_claimed &&
         scheduler->scanline == vblank_line(scheduler) &&
         scheduler->hclock >= 2u && scheduler->hclock <= 254u &&
         ((scheduler->master_clock - scheduler->autojoy_phase_origin) & 255u) == 126u)) {
        status = nh_scheduler_autojoy_tick(scheduler);
        if (status != NH_BUS_OK) return scheduler_fail(scheduler, status);
    }
    return NH_BUS_OK;
}

/* Only combine a pair whose FIRST (odd) boundary is completely inert.
 * With even line origins all raster events are even; IRQ samples H=2 mod4.
 * Autojoy's126+256n latch phase is even for an even phase origin. An active
 * joy transaction must not be due/past on the omitted boundary. Finally the
 * independent SMP phase must NOT cross there: its callback stays on its exact
 * original timestamp, before raster/IRQ/joy effects, not one clock late.
 * Odd profiles, overflow/error edges and shorter requests use the old path.
 * This is not a frequency/profile change or instruction-total stepping. */
static unsigned wall_span(const NHScheduler *scheduler, uint32_t remaining) {
    if (remaining < 2u || (scheduler->hclock & 1u) ||
        ((scheduler->master_clock - scheduler->hclock) & 1u) ||
        (scheduler->autojoy_phase_origin & 1u) ||
        scheduler->master_clock > UINT64_MAX - 2u ||
        scheduler->smp.target_phase_units == UINT64_MAX ||
        scheduler->smp.remainder >= NH_SMP_RATIO_DENOMINATOR ||
        scheduler->smp.remainder + NH_SMP_PHASE_RATIO_NUMERATOR >= NH_SMP_RATIO_DENOMINATOR ||
        (scheduler->autojoy_active && scheduler->autojoy_next_clock <= scheduler->master_clock + 1u))
        return 1u;
    return 2u;
}

/* Advance one boundary, or the source-proved inert-first pair above. Never
 * cross an observable boundary without invoking its original ordered owner. */
static NHBusStop wall_step(NHScheduler *scheduler, unsigned clocks) {
    NHSmpClockJoin next = scheduler->smp;
    const uint64_t previous_target = next.target_phase_units;
    NHBusStop status;
    uint16_t lines;
    const uint16_t old_line_clocks = nh_scheduler_line_clocks(scheduler);
    if (scheduler->master_clock == UINT64_MAX ||
        !nh_smp_clock_join_advance(&next, clocks))
        return scheduler_fail(scheduler, NH_BUS_CLOCK_UNAVAILABLE);
    scheduler->master_clock += clocks;
    scheduler->hclock = (uint16_t)(scheduler->hclock + clocks);
    scheduler->smp = next;
    if (scheduler->hclock == old_line_clocks) {
        scheduler->previous_line_clocks = old_line_clocks;
        scheduler->hclock = 0u;
        ++scheduler->scanline;
        scheduler->processed_events = 0u;
        lines = (uint16_t)(NH_NTSC_LINES_PER_FIELD +
                           (scheduler->interlace != 0u && scheduler->field == 0u ? 1u : 0u));
        if (scheduler->scanline == lines) {
            if (scheduler->completed_fields == UINT64_MAX)
                return scheduler_fail(scheduler, NH_BUS_CLOCK_UNAVAILABLE);
            scheduler->scanline = 0u;
            ++scheduler->completed_fields;
        }
    }
    /* Deterministic tie: independent-domain progress through this timestamp,
     * then ordered raster state/effects, then the caller's CPU bus effect.
     * Cross-domain concurrent port transients remain12-owned, not certified
     * by the tie convention alone. */
    if (scheduler->smp.target_phase_units != previous_target) {
        status = scheduler->receivers.smp_sync(scheduler->receivers.opaque,
                                               scheduler->bus, scheduler->smp.target_phase_units);
        if (status != NH_BUS_OK) return scheduler_fail(scheduler, status);
    }
    if (scheduler->bus->failure.reason != NH_BUS_OK) return scheduler->bus->failure.reason;
    return due_events(scheduler);
}

static NHBusStop wait_refresh(NHScheduler *scheduler) {
    while (scheduler->refreshing != 0u) {
        const NHBusStop status = wall_step(scheduler, wall_span(scheduler, 2u));
        if (status != NH_BUS_OK) return status;
    }
    return NH_BUS_OK;
}

static NHBusStop prepare_advance(NHScheduler *scheduler) {
    NHBusRuntime *bus = scheduler->bus;
    NHBusStop status;
    if (bus->failure.reason != NH_BUS_OK) return bus->failure.reason;
    if (scheduler->advancing != 0u) return scheduler_fail(scheduler, NH_BUS_CLOCK_UNAVAILABLE);
    scheduler->advancing = 1u;
    status = NH_BUS_OK;
    if (scheduler->smp_started == 0u) {
        status = scheduler->receivers.smp_sync(scheduler->receivers.opaque, bus,
                                               scheduler->smp.target_phase_units);
        if (status != NH_BUS_OK) status = scheduler_fail(scheduler, status);
        if (status == NH_BUS_OK && bus->failure.reason != NH_BUS_OK) status = bus->failure.reason;
        if (status == NH_BUS_OK) scheduler->smp_started = 1u;
    }
    if (status == NH_BUS_OK) status = due_events(scheduler);
    return status;
}

NHBusStop nh_scheduler_advance_wall(NHScheduler *scheduler, uint32_t clocks) {
    NHBusStop status;
    uint32_t elapsed;
    if (scheduler == NULL || scheduler->bus == NULL) return NH_BUS_BAD_ARGUMENT;
    if (scheduler->advancing != 0u) return scheduler_fail(scheduler, NH_BUS_CLOCK_UNAVAILABLE);
    status = prepare_advance(scheduler);
    for (elapsed = 0u; status == NH_BUS_OK && elapsed < clocks;) {
        const unsigned span = wall_span(scheduler, clocks - elapsed);
        status = wall_step(scheduler, span);
        elapsed += span;
    }
    scheduler->advancing = 0u;
    return status;
}

static NHBusStop advance_cpu(void *opaque, NHBusRuntime *bus, uint8_t clocks) {
    NHScheduler *scheduler = opaque;
    NHBusStop status;
    unsigned elapsed;
    if (scheduler == NULL || bus == NULL || scheduler->bus != bus) return NH_BUS_BAD_ARGUMENT;
    if (scheduler->advancing != 0u) return scheduler_fail(scheduler, NH_BUS_CLOCK_UNAVAILABLE);
    status = prepare_advance(scheduler);
    for (elapsed = 0u; status == NH_BUS_OK && elapsed < clocks;) {
        status = wait_refresh(scheduler);
        if (status == NH_BUS_OK) {
            const unsigned span = wall_span(scheduler, clocks - elapsed);
            status = wall_step(scheduler, span);
            elapsed += span;
        }
    }
    /* A refresh at the requested access point delays that bus effect too. */
    if (status == NH_BUS_OK) status = wait_refresh(scheduler);
    scheduler->advancing = 0u;
    return status;
}

static NHBusStop start_cycle(void *opaque, NHBusRuntime *bus, uint8_t kind,
                              uint32_t address, uint8_t clocks) {
    NHScheduler *scheduler = opaque;
    NHBusStop status;
    if (scheduler == NULL || bus == NULL || scheduler->bus != bus) return NH_BUS_BAD_ARGUMENT;
    status = advance_cpu(opaque, bus, 0u);
    if (status != NH_BUS_OK) return status;
    /* A scoped transfer capability, not permission for recursive CPU clocks. */
    scheduler->advancing = 1u;
    scheduler->transfer_boundary = 1u;
    status = scheduler->receivers.cpu_boundary(scheduler->receivers.opaque, bus,
                                               scheduler, kind, address, clocks);
    scheduler->transfer_boundary = 0u;
    scheduler->advancing = 0u;
    if (status != NH_BUS_OK) return scheduler_fail(scheduler, status);
    if (bus->failure.reason != NH_BUS_OK) return bus->failure.reason;
    /* Recognize a captured edge at the resumed CPU cycle boundary, after
     * transfer arbitration, not while wall/raster/SMP time alone advances.
     * An acknowledgement or disable may lower the line but not erase an
     * already captured edge. A failed boundary cannot consume that edge. */
    if (scheduler->nmi_edge_latched != 0u) {
        scheduler->nmi_pending = 1u;
        scheduler->nmi_edge_latched = 0u;
    }
    return NH_BUS_OK;
}

NHBusStop nh_scheduler_transfer_advance(NHScheduler *scheduler, uint32_t clocks) {
    NHBusStop status = NH_BUS_OK;
    uint32_t elapsed;
    if (scheduler == NULL || scheduler->bus == NULL) return NH_BUS_BAD_ARGUMENT;
    if (scheduler->bus->failure.reason != NH_BUS_OK) return scheduler->bus->failure.reason;
    if (scheduler->advancing == 0u || scheduler->transfer_boundary == 0u ||
        scheduler->transfer_advancing != 0u)
        return scheduler_fail(scheduler, NH_BUS_CLOCK_UNAVAILABLE);
    scheduler->transfer_advancing = 1u;
    /* Requested clocks are transfer progress, not elapsed wall time. Refresh
     * suspends the transfer while the same raster/SMP timeline keeps running.
     * Drain a refresh reached at the endpoint before a payload bus effect. */
    for (elapsed = 0u; status == NH_BUS_OK && elapsed < clocks;) {
        status = wait_refresh(scheduler);
        if (status == NH_BUS_OK) {
            const unsigned span = wall_span(scheduler, clocks - elapsed);
            status = wall_step(scheduler, span);
            elapsed += span;
        }
    }
    if (status == NH_BUS_OK) status = wait_refresh(scheduler);
    scheduler->transfer_advancing = 0u;
    return status;
}

NHBusStop nh_scheduler_cold(NHScheduler *scheduler, NHBusRuntime *bus,
                             NHSchedulerReceivers receivers) {
    if (scheduler == NULL || bus == NULL || receivers.smp_sync == NULL ||
        receivers.raster_event == NULL || receivers.cpu_boundary == NULL)
        return NH_BUS_BAD_ARGUMENT;
    memset(scheduler, 0, sizeof(*scheduler));
    scheduler->bus = bus;
    scheduler->receivers = receivers;
    scheduler->hblank = 1u;
    scheduler->previous_line_clocks = NH_NTSC_NORMAL_LINE_CLOCKS;
    /* Anomie's register hardware notes: both timers cold1FF, reset preserves. */
    scheduler->htime = 0x1FFu;
    scheduler->vtime = 0x1FFu;
    scheduler->htime_known = 0x1FFu;
    scheduler->vtime_known = 0x1FFu;
    scheduler->irq_flag_known = 1u;
    nh_smp_clock_join_cold(&scheduler->smp);
    return NH_BUS_OK;
}

NHBusStop nh_scheduler_reset_cpu_latches(NHScheduler *scheduler) {
    NHBusStop status;
    if (scheduler == NULL || scheduler->bus == NULL) return NH_BUS_BAD_ARGUMENT;
    status = nh_scheduler_autojoy_abort(scheduler);
    if (status != NH_BUS_OK) return status;
    scheduler->nmitimen = 0u;
    scheduler->nmi_flag = 0u;
    scheduler->nmi_line = 0u;
    scheduler->nmi_edge_latched = 0u;
    scheduler->nmi_pending = 0u;
    scheduler->irq_flag = 0u;
    scheduler->irq_flag_known = 1u;
    scheduler->irq_line = 0u;
    scheduler->irq_level = 0u;
    scheduler->irq_wait_ticks = 0u;
    scheduler->autojoy_busy = 0u;
    scheduler->poll_valid = 0u;
    scheduler->polled_interrupt = 0u;
    /* Do not clear externalIRQ, timers, monotonic time, raster, SMP phase or
     * invoke cold initialization as a warm reset convenience. */
    return NH_BUS_OK;
}

static NHBusStop interrupt_poll(void *opaque, NHBusRuntime *bus, uint8_t status,
                                 uint32_t context_key) {
    NHScheduler *scheduler = opaque;
    if (scheduler == NULL || bus == NULL || scheduler->bus != bus) return NH_BUS_BAD_ARGUMENT;
    if (bus->failure.reason != NH_BUS_OK) return bus->failure.reason;
    if (scheduler->poll_valid != 0u) return scheduler_fail(scheduler, NH_BUS_CLOCK_UNAVAILABLE);
    scheduler->polled_interrupt = scheduler->nmi_pending != 0u ? 1u :
        ((scheduler->irq_line != 0u || scheduler->external_irq != 0u) &&
         (status & NH_P_I) == 0u) ? 2u : 0u;
    scheduler->poll_valid = 1u;
    scheduler->poll_context_key = context_key;
    return NH_BUS_OK;
}

NHTimelinePort nh_scheduler_timeline(NHScheduler *scheduler) {
    const NHTimelinePort port = { scheduler, start_cycle, advance_cpu, interrupt_poll };
    return port;
}
