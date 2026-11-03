#ifndef NEW_HORIZONS_CPU_IO_H
#define NEW_HORIZONS_CPU_IO_H
#include "new_horizons_math_io.h"

typedef struct NHPinPort {
    void *opaque;
    NHBusStop (*sample)(void *opaque, NHBusValue *pins);
    NHBusStop (*drive)(void *opaque, NHBusValue prior, NHBusValue next);
} NHPinPort;

typedef struct NHCPU_IO {
    NHBusRuntime *bus;
    NHMathIO math;
    NHBusValue wrio;
    NHPinPort pins;
} NHCPU_IO;

/* One composed08 owner, not a second mapping or memory implementation.
 * Final09 machine may embed this structure and supply its own typed ports. */
typedef struct NHBusMachine08 {
    NHBusRuntime bus;
    NHCPU_IO cpu_io;
} NHBusMachine08;

NHBusStop nh_bus_machine08_power_on(NHBusMachine08 *machine,
                                   const uint8_t *rom, size_t rom_size,
                                   NHBusPorts ports, NHPinPort pins);
/* Reset-line latch effects for08 only. Preserve RAM/save state and math
 * latches.09 owns reset cycles, vectors and all downstream reset sequencing.
 * This is not cold frontend Reset (which creates a fresh whole machine). */
NHBusStop nh_bus_machine08_reset_latches(NHBusMachine08 *machine);

void nh_cpu_io_power_on(NHCPU_IO *io, NHBusRuntime *bus, NHPinPort pins);
NHRegisterPort nh_cpu_io_port(NHCPU_IO *io);

#endif
