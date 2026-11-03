#include "new_horizons_scheduler.h"

/* Selected busy phase254 (first cold H298). Latch phase0 precedes busy
 * phase1 by128 clocks.15 owns serial pins, bits and partial results. */
enum { NH_AUTOJOY_LATCH_PHASE = 126u, NH_AUTOJOY_PHASE_CLOCKS = 128u,
       NH_AUTOJOY_LAST_STEP = 34u, NH_AUTOJOY_TOTAL_CLOCKS = 4352u };

static NHBusStop autojoy_status(NHScheduler *scheduler, NHBusStop status) {
    if (scheduler->bus->failure.reason != NH_BUS_OK) return scheduler->bus->failure.reason;
    if (status != NH_BUS_OK) {
        scheduler->bus->failure.reason = status;
        scheduler->bus->failure.owner = status == NH_BUS_CLOCK_UNAVAILABLE ?
                                       NH_OWNER_CLOCK_09 : NH_OWNER_INPUT_15;
        scheduler->bus->failure.address = 0x4218u;
        scheduler->bus->failure.value = 0u;
        scheduler->bus->failure.known_mask = 0u;
    }
    return status;
}

NHBusStop nh_scheduler_autojoy_bind(NHScheduler *scheduler, NHAutoJoyPort port) {
    if (scheduler == NULL || scheduler->bus == NULL || scheduler->advancing != 0u ||
        scheduler->autojoy_active != 0u || port.phase == NULL || port.abort == NULL)
        return NH_BUS_BAD_ARGUMENT;
    if (scheduler->bus->failure.reason != NH_BUS_OK) return scheduler->bus->failure.reason;
    scheduler->autojoy = port;
    return NH_BUS_OK;
}

NHBusStop nh_scheduler_autojoy_abort(NHScheduler *scheduler) {
    NHBusStop status;
    if (scheduler == NULL || scheduler->bus == NULL) return NH_BUS_BAD_ARGUMENT;
    if (scheduler->bus->failure.reason != NH_BUS_OK) return scheduler->bus->failure.reason;
    if (scheduler->autojoy_active == 0u) return NH_BUS_OK;
    if (scheduler->autojoy_effects != 0u) {
        if (scheduler->autojoy.abort == NULL)
            return autojoy_status(scheduler, NH_BUS_INPUT_UNAVAILABLE);
        status = scheduler->autojoy.abort(scheduler->autojoy.opaque,
                                          scheduler->bus, scheduler->master_clock);
        status = autojoy_status(scheduler, status);
        if (status != NH_BUS_OK) return status;
    }
    scheduler->autojoy_active = 0u;
    scheduler->autojoy_busy = 0u;
    scheduler->autojoy_effects = 0u;
    return NH_BUS_OK;
}

NHBusStop nh_scheduler_autojoy_tick(NHScheduler *scheduler) {
    NHBusStop status;
    uint8_t enabled, step;
    if (scheduler == NULL || scheduler->bus == NULL) return NH_BUS_BAD_ARGUMENT;
    if (scheduler->bus->failure.reason != NH_BUS_OK) return scheduler->bus->failure.reason;
    if (scheduler->autojoy_active == 0u) {
        const uint16_t line = scheduler->overscan != 0u ? 240u : 225u;
        if (scheduler->autojoy_field_claimed != 0u || scheduler->scanline != line ||
            scheduler->hclock < 2u || scheduler->hclock > 254u ||
            ((scheduler->master_clock - scheduler->autojoy_phase_origin) & 255u) != NH_AUTOJOY_LATCH_PHASE)
            return NH_BUS_OK;
        if (scheduler->master_clock > UINT64_MAX - NH_AUTOJOY_TOTAL_CLOCKS)
            return autojoy_status(scheduler, NH_BUS_CLOCK_UNAVAILABLE);
        scheduler->autojoy_field_claimed = 1u;
        scheduler->autojoy_start_clock = scheduler->master_clock;
        scheduler->autojoy_next_clock = scheduler->master_clock;
        scheduler->autojoy_step = 0u;
        scheduler->autojoy_effects = 0u;
        scheduler->autojoy_active = 1u;
    }
    if (scheduler->master_clock < scheduler->autojoy_next_clock) return NH_BUS_OK;
    if (scheduler->master_clock != scheduler->autojoy_next_clock)
        return autojoy_status(scheduler, NH_BUS_CLOCK_UNAVAILABLE);
    enabled = scheduler->nmitimen & 1u;
    step = scheduler->autojoy_step;
    if (step != 0u && enabled == 0u) return nh_scheduler_autojoy_abort(scheduler);
    scheduler->autojoy_last_clock = scheduler->master_clock;
    if (step == 1u) scheduler->autojoy_busy = 1u;
    if (enabled != 0u || scheduler->autojoy_effects != 0u) {
        if (scheduler->autojoy.phase == NULL || scheduler->autojoy.abort == NULL)
            return autojoy_status(scheduler, NH_BUS_INPUT_UNAVAILABLE);
        scheduler->autojoy_effects = 1u;
        status = scheduler->autojoy.phase(scheduler->autojoy.opaque, scheduler->bus,
                                         scheduler->master_clock, step, enabled);
        status = autojoy_status(scheduler, status);
        if (status != NH_BUS_OK) return status;
    }
    if (step == NH_AUTOJOY_LAST_STEP) {
        scheduler->autojoy_active = 0u;
        scheduler->autojoy_busy = 0u;
        scheduler->autojoy_effects = 0u;
    } else {
        scheduler->autojoy_step = (uint8_t)(step + 1u);
        scheduler->autojoy_next_clock += NH_AUTOJOY_PHASE_CLOCKS;
    }
    return NH_BUS_OK;
}
