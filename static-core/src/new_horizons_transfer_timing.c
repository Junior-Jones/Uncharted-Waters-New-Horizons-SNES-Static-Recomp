#include "new_horizons_scheduler.h"

NHBusStop nh_scheduler_dma_alignment(const NHScheduler *scheduler,
                                      uint64_t reset_origin, uint8_t *delay) {
    uint64_t elapsed;
    if (scheduler == NULL || delay == NULL || scheduler->master_clock < reset_origin)
        return NH_BUS_BAD_ARGUMENT;
    elapsed = scheduler->master_clock - reset_origin;
    /* Physical CPU boundaries in this selected phase are even. Do not hide
     * an unqualified odd resume phase by returning a one-clock alignment. */
    if ((elapsed & 1u) != 0u) return NH_BUS_CLOCK_UNAVAILABLE;
    *delay = (uint8_t)(8u - (elapsed & 7u)); /* positive2/4/6/8, neverzero */
    return NH_BUS_OK;
}

NHBusStop nh_scheduler_dma_resume_delay(const NHScheduler *scheduler,
                                         uint64_t pause_clock, uint8_t next_cpu_clocks,
                                         uint8_t *delay) {
    uint64_t elapsed;
    if (scheduler == NULL || delay == NULL || scheduler->master_clock < pause_clock ||
        (next_cpu_clocks != 6u && next_cpu_clocks != 8u && next_cpu_clocks != 12u))
        return NH_BUS_BAD_ARGUMENT;
    elapsed = scheduler->master_clock - pause_clock;
    if ((elapsed & 1u) != 0u) return NH_BUS_CLOCK_UNAVAILABLE;
    *delay = (uint8_t)(next_cpu_clocks - elapsed % next_cpu_clocks);
    return NH_BUS_OK;
}
