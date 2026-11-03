#ifndef NEW_HORIZONS_BUS_H
#define NEW_HORIZONS_BUS_H

#include <stdint.h>

enum { NH_ROM_BYTES = 0x200000u, NH_WRAM_BYTES = 0x20000u,
       NH_SRAM_BYTES = 0x8000u };

typedef enum NHBusKind {
    NH_BUS_OPEN_EXTERNAL = 0,
    NH_BUS_ROM,
    NH_BUS_WRAM,
    NH_BUS_SRAM,
    NH_BUS_PPU,
    NH_BUS_APUIO,
    NH_BUS_WRAM_PORT,
    NH_BUS_CPU_IO,
    NH_BUS_SCHEDULER_IO,
    NH_BUS_DMA_IO,
    NH_BUS_INPUT_IO,
    NH_BUS_OPEN_INTERNAL
} NHBusKind;

typedef enum NHBusComponent {
    NH_OWNER_BUS_08 = 8,
    NH_OWNER_CLOCK_09 = 9,
    NH_OWNER_DMA_10 = 10,
    NH_OWNER_PPU_11 = 11,
    NH_OWNER_APUIO_12 = 12,
    NH_OWNER_INPUT_15 = 15
} NHBusComponent;

typedef struct NHBusRegion {
    NHBusKind kind;
    NHBusComponent owner;
    uint32_t offset;
    uint8_t internal_io;
} NHBusRegion;

/* Pure classification, not device implementation or a guest access.
 * Reject addresses wider than 24 bits rather than silently wrapping them.
 * The fixed cartridge model and alias proof are owned by 08C. */
int nh_bus_classify(uint32_t address, NHBusRegion *region);
int nh_bus_access_clocks(uint32_t address, uint8_t memsel, uint8_t *clocks);

#endif
