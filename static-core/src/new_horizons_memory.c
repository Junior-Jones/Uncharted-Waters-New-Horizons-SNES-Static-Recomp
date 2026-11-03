#include "new_horizons_memory.h"
#include "new_horizons_rom_identity.h"
#include <string.h>

static uint8_t nh_memory_known(const uint8_t *map, uint32_t offset) {
    return (uint8_t)((map[offset >> 3u] >> (offset & 7u)) & 1u);
}

static void nh_memory_set_known(uint8_t *map, uint32_t offset, uint8_t known) {
    const uint8_t mask = (uint8_t)(1u << (offset & 7u));
    const uint8_t inverse = (uint8_t)(0xFFu ^ mask);
    map[offset >> 3u] = (uint8_t)((map[offset >> 3u] & inverse) |
                                 (known != 0u ? mask : 0u));
}

NHMemoryResult nh_memory_power_on(NHMemory *memory, const uint8_t *verified_rom,
                                  size_t rom_size) {
    return nh_memory_power_on_profile(memory, verified_rom, rom_size,
                                      NH_MEMORY_POWER_ON_STRICT_UNKNOWN);
}

NHMemoryResult nh_memory_power_on_profile(NHMemory *memory,
                                          const uint8_t *verified_rom,
                                          size_t rom_size,
                                          NHMemoryPowerOnProfile profile) {
    if (memory == NULL || verified_rom == NULL) return NH_MEMORY_ARGUMENT;
    if (profile != NH_MEMORY_POWER_ON_STRICT_UNKNOWN &&
        profile != NH_MEMORY_POWER_ON_DETERMINISTIC_ZERO_WRAM_V1 &&
        profile != NH_MEMORY_POWER_ON_DETERMINISTIC_ZERO_MACHINE_V2 &&
        profile != NH_MEMORY_POWER_ON_DETERMINISTIC_ZERO_MACHINE_ARAM_V3)
        return NH_MEMORY_ARGUMENT;
    if (rom_size != NH_ROM_BYTES || nh_rom_matches_canonical(verified_rom, rom_size) == 0)
        return NH_MEMORY_INVALID_ROM_BINDING;
    memset(memory, 0, sizeof(*memory));
    memory->verified_rom = verified_rom;
    memory->rom_size = rom_size;
    memory->power_on_profile = (uint8_t)profile;
    /* WRAM remains unknown. Battery SRAM has the explicit deterministic
     * fresh-cartridge profile in config/sram-starting-profile.json. This
     * is a project starting image, not a universal physical power-on claim.
     * A validated persisted image replaces it before actual memory access.
     * Initial profile construction is clean; only guest changes are dirty. */
    memset(memory->sram.values, 0xFF, sizeof(memory->sram.values));
    memset(memory->sram.known, 0xFF, sizeof(memory->sram.known));
    if (profile != NH_MEMORY_POWER_ON_STRICT_UNKNOWN)
        memset(memory->wram_known, 0xFF, sizeof(memory->wram_known));
    return NH_MEMORY_OK;
}

NHMemoryResult nh_memory_warm_reset(NHMemory *memory) {
    if (memory == NULL) return NH_MEMORY_ARGUMENT;
    if (memory->verified_rom == NULL || memory->rom_size != NH_ROM_BYTES)
        return NH_MEMORY_INVALID_ROM_BINDING;
    /* Storage and knownness, save generation and dirty state are preserved.
     * CPU/device reset behavior is owned by the enclosing bus/components. */
    return NH_MEMORY_OK;
}

NHMemoryResult nh_memory_load_sram(NHMemory *memory, const NHSramImage *image) {
    if (memory == NULL || image == NULL) return NH_MEMORY_ARGUMENT;
    if (memory->verified_rom == NULL || memory->rom_size != NH_ROM_BYTES)
        return NH_MEMORY_INVALID_ROM_BINDING;
    if (memory->access_started != 0u) return NH_MEMORY_SRAM_ALREADY_IN_USE;
    memmove(&memory->sram, image, sizeof(memory->sram));
    memory->sram_generation = 0u;
    memory->sram_dirty = 0u;
    return NH_MEMORY_OK;
}

NHMemoryResult nh_memory_peek(const NHMemory *memory, uint32_t address, NHMemoryByte *byte) {
    NHBusRegion region;
    NHMemoryByte result;
    if (memory == NULL || byte == NULL || nh_bus_classify(address, &region) == 0)
        return NH_MEMORY_ARGUMENT;
    if (memory->verified_rom == NULL || memory->rom_size != NH_ROM_BYTES)
        return NH_MEMORY_INVALID_ROM_BINDING;
    if (region.kind == NH_BUS_ROM) {
        if (region.offset >= memory->rom_size) return NH_MEMORY_INVALID_ROM_BINDING;
        result.value = memory->verified_rom[region.offset];
        result.known = 1u;
    } else if (region.kind == NH_BUS_WRAM) {
        result.value = memory->wram[region.offset];
        result.known = nh_memory_known(memory->wram_known, region.offset);
    } else if (region.kind == NH_BUS_SRAM) {
        result.value = memory->sram.values[region.offset];
        result.known = nh_memory_known(memory->sram.known, region.offset);
    } else {
        return NH_MEMORY_NOT_THIS_OWNER;
    }
    *byte = result;
    return NH_MEMORY_OK;
}

NHMemoryResult nh_memory_read(NHMemory *memory, uint32_t address, NHMemoryByte *byte) {
    const NHMemoryResult result = nh_memory_peek(memory, address, byte);
    if (result == NH_MEMORY_OK) memory->access_started = 1u;
    return result;
}

NHMemoryResult nh_memory_write(NHMemory *memory, uint32_t address, NHMemoryByte byte) {
    NHBusRegion region;
    if (memory == NULL || byte.known > 1u || nh_bus_classify(address, &region) == 0)
        return NH_MEMORY_ARGUMENT;
    if (memory->verified_rom == NULL || memory->rom_size != NH_ROM_BYTES)
        return NH_MEMORY_INVALID_ROM_BINDING;
    if (region.kind == NH_BUS_WRAM) {
        memory->wram[region.offset] = byte.value;
        nh_memory_set_known(memory->wram_known, region.offset, byte.known);
    } else if (region.kind == NH_BUS_SRAM) {
        const uint8_t prior_known = nh_memory_known(memory->sram.known, region.offset);
        /* Changing an unknown representative alone changes no semantic byte. */
        const int changed = prior_known != byte.known ||
            (byte.known != 0u && memory->sram.values[region.offset] != byte.value);
        if (changed != 0 && memory->sram_generation == UINT64_MAX)
            return NH_MEMORY_SRAM_GENERATION_OVERFLOW;
        memory->sram.values[region.offset] = byte.value;
        nh_memory_set_known(memory->sram.known, region.offset, byte.known);
        if (changed != 0) {
            ++memory->sram_generation;
            memory->sram_dirty = 1u;
        }
    } else if (region.kind != NH_BUS_ROM) {
        return NH_MEMORY_NOT_THIS_OWNER;
    }
    /* A selected ROM ignores storage writes; MDR/timing remain bus effects. */
    memory->access_started = 1u;
    return NH_MEMORY_OK;
}

NHMemoryResult nh_memory_export_sram(const NHMemory *memory, NHSramImage *image,
                                    uint64_t *generation) {
    if (memory == NULL || image == NULL || generation == NULL)
        return NH_MEMORY_ARGUMENT;
    if (memory->verified_rom == NULL || memory->rom_size != NH_ROM_BYTES)
        return NH_MEMORY_INVALID_ROM_BINDING;
    /* Export explicit knownness; do not turn uninitialized cells into a
     * supposedly exact raw save image. Host filesystem ownership comes later. */
    memmove(image, &memory->sram, sizeof(*image));
    *generation = memory->sram_generation;
    return NH_MEMORY_OK;
}

int nh_memory_ack_sram_flush(NHMemory *memory, uint64_t generation) {
    if (memory == NULL || memory->verified_rom == NULL ||
        memory->rom_size != NH_ROM_BYTES || generation != memory->sram_generation)
        return 0;
    /* A host flush of an older export cannot clear a newer guest write. */
    memory->sram_dirty = 0u;
    return 1;
}
