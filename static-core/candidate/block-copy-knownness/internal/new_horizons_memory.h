#ifndef NEW_HORIZONS_MEMORY_H
#define NEW_HORIZONS_MEMORY_H

#include "new_horizons_bus.h"
#include <stddef.h>

typedef struct NHMemoryByte {
    uint8_t value;
    uint8_t known;
} NHMemoryByte;

typedef struct NHSramImage {
    uint8_t values[NH_SRAM_BYTES];
    uint8_t known[NH_SRAM_BYTES / 8u];
} NHSramImage;

typedef enum NHMemoryResult {
    NH_MEMORY_OK = 0,
    NH_MEMORY_ARGUMENT,
    NH_MEMORY_NOT_THIS_OWNER,
    NH_MEMORY_INVALID_ROM_BINDING,
    NH_MEMORY_SRAM_ALREADY_IN_USE,
    NH_MEMORY_SRAM_GENERATION_OVERFLOW,
    NH_MEMORY_INVALID_SRAM_FILE
} NHMemoryResult;

typedef struct NHMemory {
    const uint8_t *verified_rom;
    size_t rom_size;
    uint8_t wram[NH_WRAM_BYTES];
    uint8_t wram_known[NH_WRAM_BYTES / 8u];
    NHSramImage sram;
    uint64_t sram_generation;
    uint8_t sram_dirty;
    uint8_t access_started;
} NHMemory;

/* Storage component only: the one bus owner supplies timing/MDR/ports.
 * Power-on verifies actual canonical ROM bytes by01C SHA-256, not a supplied
 * digest or size alone. The bound input buffer must remain immutable. */
NHMemoryResult nh_memory_power_on(NHMemory *memory, const uint8_t *verified_rom,
                                  size_t rom_size);
NHMemoryResult nh_memory_warm_reset(NHMemory *memory);
NHMemoryResult nh_memory_load_sram(NHMemory *memory, const NHSramImage *image);
/* Observational storage lookup: no timing, MDR, device or access-state change.
 * Normal instruction fetches must NOT substitute this for the actual bus. */
NHMemoryResult nh_memory_peek(const NHMemory *memory, uint32_t address, NHMemoryByte *byte);
NHMemoryResult nh_memory_read(NHMemory *memory, uint32_t address, NHMemoryByte *byte);
NHMemoryResult nh_memory_write(NHMemory *memory, uint32_t address, NHMemoryByte byte);
NHMemoryResult nh_memory_export_sram(const NHMemory *memory, NHSramImage *image,
                                    uint64_t *generation);
int nh_memory_ack_sram_flush(NHMemory *memory, uint64_t generation);

#endif
