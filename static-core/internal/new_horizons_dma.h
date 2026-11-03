#ifndef NEW_HORIZONS_DMA_H
#define NEW_HORIZONS_DMA_H
#include "new_horizons_scheduler.h"

/* Register bytes0..B; F aliases B and C..E float. Values/knownness stay
 * together. A byte may be unknown until its bits actually select behavior. */
typedef struct NHDmaChannel10 {
    NHBusValue registers[12];
    uint8_t manual_active;
    uint8_t finished;
    uint8_t transfer_line;
} NHDmaChannel10;

typedef struct NHDma10 {
    NHBusRuntime *bus;
    NHScheduler *scheduler;
    /* Retained SMP/raster receivers only. The replaced CPU transfer callback
     * is NOT delegated to: this controller is the sole DMA boundary owner. */
    NHSchedulerReceivers downstream;
    NHDmaChannel10 channel[8];
    uint64_t completed_bytes;
    uint8_t manual_pending;
    uint8_t hdma_enable;
    uint8_t line_pending;
    uint8_t init_pending;
    uint8_t start_delay;
    uint8_t servicing;
    uint8_t active_channel;
} NHDma10;

/* Cold assembly at stable addresses, after09 construction and before release.
 * Installs the one DMA register receiver and CPU-boundary/raster request joins.
 * Preserves required downstream SMP/PPU receivers; supplies no no-op device.
 * Local mature-reference cold register profile is knownFF, not a claim about
 * arbitrary electrical power-up. Existing live DMA bindings reject unchanged. */
NHBusStop nh_dma10_bind(NHDma10 *, NHBusRuntime *, NHScheduler *);
/* CPU Reset cancels requests/activity, not channel register/table contents,
 * SRAM, the shared master clock or independent-domain phase. Called by the
 * actual assembled device-reset receiver, never as a cold reinitialization. */
NHBusStop nh_dma10_reset(NHDma10 *);
#endif
