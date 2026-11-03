#ifndef NEW_HORIZONS_MACHINE_H
#define NEW_HORIZONS_MACHINE_H
#include "new_horizons_scheduler.h"

typedef enum NHCPUResetPhase {
    NH_CPU_RESET_NONE,
    NH_CPU_RESET_HELD,
    NH_CPU_RESET_RELEASING,
    NH_CPU_RESET_FAILED
} NHCPUResetPhase;
enum { NH_RESET_STARTUP_MASTER_CLOCKS = 186u };

/* Binding view, not duplicate storage/CPU/scheduler ownership. All four
 * component instances must remain at stable addresses for this view's life. */
typedef struct NHMachine09 {
    NHBusMachine08 *storage;
    NHScheduler *scheduler;
    NHClockRuntime *clock;
    NHScpuState *cpu;
    NHCPUResetPhase cpu_reset_phase;
    uint64_t cpu_reset_assert_clock;
    uint64_t cpu_reset_release_clock;
} NHMachine09;

typedef enum NHDeviceResetPhase {
    NH_DEVICE_RESET_PREFLIGHT,
    NH_DEVICE_RESET_ASSERT,
    NH_DEVICE_RESET_RELEASE
} NHDeviceResetPhase;

/* Static assembled-device receiver, not a frontend/plugin policy callback.
 * PREFLIGHT validates the source-qualified affected-device/beam/hold contract
 * without mutating devices. ASSERT/RELEASE apply that complete contract through
 * the existing10/11/12/15/16 owners. No clocks or CPU dispatch from the callback;
 * independent-domain phase is separate from device semantic reset. A missing
 * receiver or unqualified policy rejects; no no-op fallback is supplied here. */
typedef struct NHDeviceResetPort {
    void *opaque;
    NHBusStop (*apply)(void *, NHBusRuntime *, const NHScheduler *,
                       NHDeviceResetPhase, uint32_t hold_master_clocks);
} NHDeviceResetPort;

/* One machine reset sequence, with explicit qualified device contract and hold
 * duration. Not a selected frontend Reset until its actual receiver/physical
 * profile is qualified. Uses CPU assertion, shared wall hold, device release,
 * ordered CPU release; never cold-initializes storage or rewinds master time.
 * Failure retains completed effects and blocks dispatch until fresh assertion. */
NHBusStop nh_machine09_reset_with_devices(NHMachine09 *, NHDeviceResetPort,
                                          uint32_t hold_master_clocks);

/* Assemble cold08 storage, the09 scheduler, its ordered clock port and this
 * machine view at their final stable addresses. No time or device callbacks
 * run during construction. ROM validation precedes storage mutation; rejected
 * arguments/missing mandatory scheduler receivers leave all outputs untouched.
 * CPU is caller-supplied, valid initial register state under the project's
 * explicit power-on contract: this API does not fill hardware-uninitialized
 * registers with convenient zeroes. After binding, the existing CPU reset
 * assertion owner applies its forced state and leaves the CPU HELD; dispatch
 * cannot run before explicit hold/release. Unforced register state is preserved.
 * No vector sampling, release cycles or startup padding run here. Supplied device/pin ports
 * are retained;08 CPU IO and09 clock/status slots are replaced by their sole
 * owners.15 binds its autojoy receiver before guest execution needs it.
 * This is cold construction ONLY, never a warm Reset or SRAM reload shortcut.
 * Missing later devices remain their existing explicit bus/receiver stops. */
NHBusStop nh_machine09_construct(NHMachine09 *, NHBusMachine08 *, NHScheduler *,
                                 NHClockRuntime *, NHScpuState *, const uint8_t *rom,
                                 size_t rom_size, NHBusPorts, NHPinPort,
                                 NHSchedulerReceivers);
NHBusStop nh_machine09_construct_profile(NHMachine09 *, NHBusMachine08 *, NHScheduler *,
                                         NHClockRuntime *, NHScpuState *,
                                         const uint8_t *rom, size_t rom_size,
                                         NHBusPorts, NHPinPort,
                                         NHSchedulerReceivers,
                                         NHMemoryPowerOnProfile);
NHBusStop nh_machine09_bind(NHMachine09 *, NHBusMachine08 *, NHScheduler *, NHClockRuntime *, NHScpuState *);
NHBusStop nh_machine09_interrupt_entry(NHMachine09 *, uint8_t interrupt);
NHBusStop nh_machine09_retire(NHMachine09 *);
NHScpuExecResult nh_machine09_step(NHMachine09 *);
/* S-CPU reset-line owner, NOT a console-wide Reset API. Assertion blocks CPU
 * dispatch/retirement/wake, resets its forced state and08/09 register latches,
 * and preserves memory, raster, monotonic time and independent SMP phase.
 * Holding advances the existing wall/raster/SMP owner without CPU cycles.
 * Console11/12/16 device assertions/beam phase and physical minimum hold are
 * separate obligations, not supplied by an arbitrary hold-duration constant. */
NHBusStop nh_machine09_cpu_reset_assert(NHMachine09 *);
NHBusStop nh_machine09_cpu_reset_hold(NHMachine09 *, uint32_t wall_clocks);
/* CPU release after the explicit assertion/hold owner: untimed vector sample
 * followed by the local reference method's186-clock startup on the same
 * scheduler. Functional/event-order contract, not physical reset microcycles.
 * Not yet a complete frontend Reset API:09 still owes assertion/hold/beam
 * and downstream reset joins. Preserve A, lowX/Y/S and unforced status bits. */
NHBusStop nh_machine09_reset_release_cpu(NHMachine09 *);
/* Advance a suspended machine by at most this wall-clock budget until wake.
 * STP ignores IRQ/NMI; WAI wakes on masked IRQ too, with two internal cycles
 * before retirement poll/service. resumed is0 for still suspended,1 for wake.
 * No new WAI/STP opcode/context is admitted by this machine-state API. */
NHBusStop nh_machine09_advance_terminal(NHMachine09 *, uint32_t wall_clocks, uint8_t *resumed);

/* Full console reset assertion/hold/release is still a separate09 obligation. No API
 * silently constructs a reset by changing PC or treating a guest JML as one.
 * WAI/STP wake sequencing is likewise not approximated by normal stepping. */
#endif
