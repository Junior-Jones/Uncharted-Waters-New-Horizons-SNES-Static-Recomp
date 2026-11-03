#ifndef NEW_HORIZONS_CLOCK_PORT_H
#define NEW_HORIZONS_CLOCK_PORT_H

#include "new_horizons_cpu_io.h"
#include "new_horizons_timing_plan.h"

/* Construction interface to the ONE machine timeline, not a second clock.
 * start_cycle owns boundary rendezvous/stalls before the CPU cycle begins.
 * advance owns every crossed raster/independent-domain event, including ties.
 * No default/no-op implementation is provided. Math pulses during stalls are
 * timeline-owned; this port supplies the pulse of the actual CPU cycle only.
 * Reset/interrupt sequences are separate machine-owned sequences. */
typedef struct NHTimelinePort {
    void *opaque;
    NHBusStop (*start_cycle)(void *, NHBusRuntime *, uint8_t kind,
                             uint32_t address, uint8_t clocks);
    NHBusStop (*advance)(void *, NHBusRuntime *, uint8_t clocks);
    NHBusStop (*interrupt_poll)(void *, NHBusRuntime *, uint8_t status, uint32_t context_key);
} NHTimelinePort;

typedef struct NHClockRuntime {
    NHBusRuntime *bus;
    NHMathIO *math;
    NHTimelinePort timeline;
    NHScpuState entry;
    NHStaticFetch fetch;
    const NHTimingPlan *plan;
    uint32_t context_key;
    uint32_t cycles;
    uint8_t expected[4];
    uint8_t operands[4];
    uint8_t fetched_mask;
    uint8_t pointer_low;
    uint8_t pointer_low_valid;
    uint8_t cursor;
    uint8_t active;
    uint8_t irq_status;
    uint8_t irq_status_valid;
    uint8_t interrupt_polled;
    uint8_t reset_vector_phase;
    NHScpuState *reset_cpu;
    uint8_t machine_cycle_completed;
} NHClockRuntime;

/* Not a power/reset API. Binding does not advance time or alter bus/math.
 * The timeline and arithmetic owners must outlive the returned clock port.
 * This source candidate is not selected/phase-qualified yet. */
NHBusStop nh_clock_bind(NHClockRuntime *, NHBusRuntime *, NHCPU_IO *, NHTimelinePort);
NHClockPort nh_clock_port(NHClockRuntime *);

typedef enum NHMachineCycle {
    NH_MACHINE_INTERNAL, NH_MACHINE_FETCH_DISCARD, NH_MACHINE_READ_DISCARD,
    NH_MACHINE_READ, NH_MACHINE_WRITE
} NHMachineCycle;
/* Reset/interrupt/wake sequences use the SAME timed cycle primitive without
 * selecting an instruction plan or polling during entry. Discard reads still
 * sample the08 bus/MDR but do not require ignored bits to be known. */
NHBusStop nh_clock_machine_cycle(NHClockRuntime *, NHMachineCycle, uint32_t address, uint8_t *byte);
NHBusStop nh_clock_reset_vector_begin(NHClockRuntime *, NHScpuState *);

#endif
