#ifndef NEW_HORIZONS_SCHEDULER_H
#define NEW_HORIZONS_SCHEDULER_H

#include "new_horizons_clock_port.h"
#include "new_horizons_clock_domain.h"

typedef enum NHRasterEvent {
    NH_RASTER_LINE_BEGIN,
    NH_RASTER_FIELD_TOGGLE,
    NH_RASTER_HBLANK_BEGIN,
    NH_RASTER_HBLANK_END,
    NH_RASTER_VBLANK_BEGIN,
    NH_RASTER_VBLANK_END,
    NH_RASTER_NMI_FLAG_SET,
    NH_RASTER_NMI_FLAG_CLEAR,
    NH_RASTER_NMI_ASSERT,
    NH_RASTER_REFRESH_BEGIN,
    NH_RASTER_REFRESH_END,
    NH_RASTER_IRQ_ASSERT,
    NH_RASTER_HDMA_INIT_REQUEST,
    NH_RASTER_HDMA_LINE_REQUEST
} NHRasterEvent;

struct NHScheduler;
typedef struct NHAutoJoyPort {
    void *opaque;
    /*0=latch opportunity,1=enable/busy sample,2=latch release,3..33=serial
     * phases,34=completion.15 owns actual pin/result effects.09 supplies the
     * enable sampled at this phase; register writes do not synthesize clocks. */
    NHBusStop (*phase)(void *, NHBusRuntime *, uint64_t master_clock,
                       uint8_t step, uint8_t enabled);
    NHBusStop (*abort)(void *, NHBusRuntime *, uint64_t master_clock);
} NHAutoJoyPort;

typedef struct NHSchedulerReceivers {
    void *opaque;
    /* Advance the static SMP owner to this absolute full-cycle target before
     * any bus effect at this master clock; never substitute host audio time. */
    NHBusStop (*smp_sync)(void *, NHBusRuntime *, uint64_t target_cycles);
    /* The PPU/machine receiver owns downstream effects, not a second raster.
     * Refresh notifications MUST join stalled arithmetic/device phases;
     * those physical phases are not yet qualified by this source candidate. */
    NHBusStop (*raster_event)(void *, NHBusRuntime *, const struct NHScheduler *, NHRasterEvent);
    /* DMA/HDMA rendezvous at the declared CPU boundary. Only the explicit
     * transfer_advance capability may advance inside this callback. Recursive
     * CPU/wall advancement and callback-nested transfer advance are rejected.
     *10 owns channels, the post420B one-CPU-cycle delay and transfer priority. */
    NHBusStop (*cpu_boundary)(void *, NHBusRuntime *, const struct NHScheduler *,
                              uint8_t kind, uint32_t address, uint8_t clocks);
} NHSchedulerReceivers;

typedef struct NHScheduler {
    NHBusRuntime *bus;
    NHSchedulerReceivers receivers;
    NHSmpClockJoin smp;
    uint64_t master_clock;
    uint64_t completed_fields;
    uint16_t hclock;
    uint16_t scanline;
    uint16_t processed_events;
    uint8_t field;
    uint8_t interlace;
    uint8_t overscan;
    uint8_t hblank;
    uint8_t vblank;
    uint8_t nmi_flag;
    uint8_t refreshing;
    uint8_t advancing;
    uint8_t smp_started;
    uint16_t htime;
    uint16_t vtime;
    uint16_t htime_known;
    uint16_t vtime_known;
    uint16_t previous_line_clocks;
    uint8_t nmitimen;
    uint8_t nmi_line;
    /* A line edge awaits CPU recognition; wall/DMA progress alone cannot
     * turn it into an accepted CPU request. Preserve until a CPU boundary. */
    uint8_t nmi_edge_latched;
    uint8_t nmi_pending;
    uint8_t irq_flag;
    /* Knownness of the on-chip timer latch, NOT external /IRQ. An unresolved
     * TIMEUP hold/clear outcome may leave this unknown while its read bit was
     * known. Never use irq_flag's representative value as service authority. */
    uint8_t irq_flag_known;
    uint8_t irq_line;
    uint8_t irq_level;
    uint8_t irq_wait_ticks;
    uint8_t irq_phase_valid;
    uint16_t irq_hcounter;
    uint16_t irq_vcounter;
    uint64_t irq_phase_clock;
    uint8_t external_irq;
    uint8_t autojoy_busy;
    uint8_t poll_valid;
    uint8_t polled_interrupt;
    uint32_t poll_context_key;
    uint64_t irq_assert_clock;
    NHAutoJoyPort autojoy;
    uint64_t autojoy_start_clock;
    uint64_t autojoy_last_clock;
    uint64_t autojoy_phase_origin;
    uint8_t autojoy_active;
    uint8_t autojoy_field_claimed;
    uint8_t autojoy_step;
    uint8_t autojoy_effects;
    uint64_t autojoy_next_clock;
    uint8_t transfer_boundary;
    uint8_t transfer_advancing;
} NHScheduler;

/* Read-only diagnostic value, not a resumable machine snapshot or another
 * clock owner. Capture on the machine's execution thread, including at a
 * stopped failure boundary. Profile storage is immutable; all other members
 * are copied values. A cleared validity/active tag means its associated key
 * or timestamp is historical, not a currently pending event. */
typedef struct NHSchedulerDiagnostic {
    const NHTimingProfile *profile;
    uint64_t master_clock;
    uint64_t completed_fields;
    uint64_t smp_target_cycles;
    uint32_t smp_remainder;
    uint16_t scanline;
    uint16_t hclock;
    uint16_t dot;
    uint8_t field;
    uint8_t interlace;
    uint8_t overscan;
    uint8_t hblank;
    uint8_t vblank;
    uint8_t refreshing;
    uint8_t advancing;
    uint8_t nmi_flag;
    uint8_t nmi_line;
    uint8_t nmi_edge_latched;
    uint8_t nmi_pending;
    uint8_t irq_flag;
    uint8_t irq_flag_known;
    uint8_t irq_line;
    uint8_t irq_level;
    uint8_t irq_wait_ticks;
    uint8_t irq_phase_valid;
    uint16_t irq_hcounter;
    uint16_t irq_vcounter;
    uint64_t irq_phase_clock;
    uint8_t external_irq;
    uint64_t irq_assert_clock;
    uint8_t poll_valid;
    uint8_t polled_interrupt;
    uint32_t poll_context_key;
    uint8_t autojoy_active;
    uint8_t autojoy_busy;
    uint8_t autojoy_field_claimed;
    uint8_t autojoy_step;
    uint8_t autojoy_effects;
    uint64_t autojoy_next_clock;
    uint64_t autojoy_start_clock;
    uint64_t autojoy_last_clock;
    uint64_t autojoy_phase_origin;
    uint8_t transfer_boundary;
    uint8_t transfer_advancing;
    NHBusFailure bus_failure;
} NHSchedulerDiagnostic;

/* Does not advance/synchronize domains, invoke receivers, clear a fault or
 * acknowledge an interrupt. The return reports capture success, NOT the
 * health of the machine; inspect bus_failure. Invalid pointers leave output
 * untouched. Scheduler must be constructed; output must not alias its state. */
NHBusStop nh_scheduler_diagnostic(const NHScheduler *, NHSchedulerDiagnostic *);

/* Cold state only: no guest reset sequence, bus accesses or CPU mutation.
 * Project cold phase0; mandatory missing receivers reject before mutation. */
NHBusStop nh_scheduler_cold(NHScheduler *, NHBusRuntime *, NHSchedulerReceivers);
NHTimelinePort nh_scheduler_timeline(NHScheduler *);
/* Elapsed wall-master clocks with S-CPU suspended. Uses the same raster/SMP
 * owner, without inventing CPU cycles or adding CPU refresh wait clocks. */
NHBusStop nh_scheduler_advance_wall(NHScheduler *, uint32_t clocks);
/*10-only capability while servicing cpu_boundary: same wall/raster/SMP owner.
 * Split advances at actual transfer sample/commit events. No CPU access-speed
 * scaling, CPU cycles, payload copy or initiator-specific MDR rule is invented.
 * Raster HDMA requests may queue during this advance;10 preempts at a legal
 * transfer boundary rather than recursively executing from a raster callback. */
NHBusStop nh_scheduler_transfer_advance(NHScheduler *, uint32_t clocks);
NHBusStop nh_scheduler_dma_alignment(const NHScheduler *, uint64_t reset_origin, uint8_t *delay);
NHBusStop nh_scheduler_dma_resume_delay(const NHScheduler *, uint64_t pause_clock,
                                       uint8_t next_cpu_clocks, uint8_t *delay);
/* Scheduler CPU-register reset boundary only: preserve timer values, master
 * time, raster geometry and independent-domain remainder. Full beam/device
 * assertion reset remains the separate machine reset-phase obligation. */
NHBusStop nh_scheduler_reset_cpu_latches(NHScheduler *);
NHBusStop nh_scheduler_autojoy_bind(NHScheduler *, NHAutoJoyPort);
/* Called by the ONE scheduler at every crossed master boundary.09 schedules
 *128-clock phases0..34;15 receives absolute timestamps and sampled enable,
 * owning controller lines/result transients. No instant host-button packet. */
NHBusStop nh_scheduler_autojoy_tick(NHScheduler *);
NHBusStop nh_scheduler_autojoy_abort(NHScheduler *);
uint16_t nh_scheduler_line_clocks(const NHScheduler *);
uint16_t nh_scheduler_dot(const NHScheduler *);
NHRegisterPort nh_scheduler_register_port(NHScheduler *);
/* Live counter comparison; unknown enabled timer inputs stop. */
NHBusStop nh_scheduler_irq_match(const NHScheduler *, uint8_t *match);
NHBusStop nh_scheduler_irq_tick(NHScheduler *);
void nh_scheduler_update_nmi_line(NHScheduler *);
/* Returns the staged decision, not vector/stack entry. The machine must call
 * this only when accepting retirement, then execute the actual entry sequence.
 * 0=none,1=NMI,2=IRQ; pending edges after the poll are not finish-time repolls. */
NHBusStop nh_scheduler_take_interrupt(NHScheduler *, uint8_t *interrupt);

/* Geometry is carried by this owner, but the future11 PPU must supply the
 * actual latch/write transition through a qualified join. No host option may
 * change these fields to pace a frontend. No generic geometry setter exists. */
#endif
