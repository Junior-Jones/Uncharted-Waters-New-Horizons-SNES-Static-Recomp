#ifndef NEW_HORIZONS_BUS_RUNTIME_H
#define NEW_HORIZONS_BUS_RUNTIME_H

#include "new_horizons_memory.h"
#include "new_horizons_fetch.h"

typedef enum NHBusStop {
    NH_BUS_OK = 0,
    NH_BUS_BAD_ARGUMENT,
    NH_BUS_BAD_ROM,
    NH_BUS_UNKNOWN_BYTE,
    NH_BUS_BAD_STATIC_GUARD,
    NH_BUS_PPU_UNAVAILABLE,
    NH_BUS_APUIO_UNAVAILABLE,
    NH_BUS_DMA_UNAVAILABLE,
    NH_BUS_INPUT_UNAVAILABLE,
    NH_BUS_CLOCK_UNAVAILABLE,
    NH_BUS_CPU_IO_UNAVAILABLE,
    NH_BUS_MEMORY_FAILURE,
    NH_BUS_UNPROVED_REGISTER
} NHBusStop;

typedef struct NHDrivenByte {
    uint8_t value;
    uint8_t driven_mask;
    uint8_t known_mask;
} NHDrivenByte;

typedef struct NHBusValue {
    uint8_t value;
    uint8_t known_mask;
} NHBusValue;

typedef struct NHRegisterPort {
    void *opaque;
    NHBusStop (*read)(void *opaque, uint16_t reg, NHDrivenByte *byte);
    NHBusStop (*write)(void *opaque, uint16_t reg, NHBusValue byte);
} NHRegisterPort;

struct NHBusRuntime;

/* 09C owns the access/internal event sequence. Its implementation must call
 * the one08 raw bus owner at the actual sample/commit point; it may not
 * synthesize values or defer all clocks until instruction completion. */
typedef struct NHClockPort {
    void *opaque;
    NHBusStop (*begin)(void *opaque, struct NHBusRuntime *bus,
                       const NHScpuState *cpu, const NHStaticFetch *fetch,
                       const uint8_t *expected);
    NHBusStop (*read)(void *opaque, struct NHBusRuntime *bus,
                      const NHScpuState *cpu, uint32_t address, uint8_t *value);
    NHBusStop (*write)(void *opaque, struct NHBusRuntime *bus,
                       const NHScpuState *cpu, uint32_t address, uint8_t value);
    NHBusStop (*finish)(void *opaque, struct NHBusRuntime *bus,
                        const NHScpuState *cpu, uint32_t *cycles);
    /* Reset is not an instruction timing plan.09 supplies the real reset
     * sequence and uses the same08 sample/knownness owner at its read event. */
    NHBusStop (*reset_read)(void *opaque, struct NHBusRuntime *bus,
                            uint32_t address, uint8_t *value);
    NHBusStop (*copy8)(void *opaque, struct NHBusRuntime *bus,
                       const NHScpuState *cpu, uint32_t source, uint32_t destination);
} NHClockPort;

typedef struct NHBusPorts {
    NHRegisterPort ppu;
    NHRegisterPort apuio;
    NHRegisterPort dma;
    NHRegisterPort input;
    NHRegisterPort scheduler_registers;
    NHRegisterPort cpu_io;
    NHClockPort clock;
} NHBusPorts;

typedef struct NHBusFailure {
    NHBusStop reason;
    NHBusComponent owner;
    uint32_t address;
    uint8_t value;
    uint8_t known_mask;
} NHBusFailure;

typedef struct NHBusRuntime {
    NHMemory memory;
    NHBusPorts ports;
    NHBusValue mdr;
    NHBusFailure failure;
    uint32_t wram_port_address;
    uint8_t memsel;
} NHBusRuntime;

/* Cold storage/bus initialization only. The caller retains an immutable ROM
 * buffer for this instance's full lifetime. No reset vector, CPU execution,
 * guest clocks or downstream owner reset is performed here. Invalid ROM input
 * leaves the existing bus unchanged. Absent ports remain explicit stops. */
NHBusStop nh_bus_power_on(NHBusRuntime *bus, const uint8_t *rom,
                         size_t rom_size, NHBusPorts ports);
NHBusStop nh_bus_sample_reset_vector(NHBusRuntime *bus, uint16_t *vector);

/* Raw means untimed, not another hardware implementation. Only the owning
 * scheduler and boundary qualification may call these. CPU bodies consume
 * nh_bus_scpu_view, whose callbacks require the typed09C clock owner. */
NHBusStop nh_bus_read_sample(NHBusRuntime *bus, uint32_t address, NHBusValue *value);
NHBusStop nh_bus_write_commit(NHBusRuntime *bus, uint32_t address, NHBusValue value);
NHBusStop nh_bus_require_known(NHBusRuntime *bus, uint32_t address,
                              NHBusValue byte, uint8_t *value);
NHScpuBus nh_bus_scpu_view(NHBusRuntime *bus);

#endif
