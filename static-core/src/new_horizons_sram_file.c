#include "new_horizons_sram_file.h"
#include "new_horizons_rom_identity.h"
#include <string.h>

static const uint8_t nh_sram_magic[8] = { 'N','H','S','R','A','M','0','1' };

static void nh_sram_u32_store(uint8_t *bytes, uint32_t value) {
    unsigned index;
    for (index = 0u; index < 4u; ++index)
        bytes[index] = (uint8_t)(value >> (8u * index));
}

static uint32_t nh_sram_u32_load(const uint8_t *bytes) {
    return (uint32_t)bytes[0] | ((uint32_t)bytes[1] << 8u) |
           ((uint32_t)bytes[2] << 16u) | ((uint32_t)bytes[3] << 24u);
}

NHMemoryResult nh_sram_file_encode(const NHMemory *memory, uint8_t *file,
                                   size_t size, uint64_t *generation) {
    NHSramImage image;
    uint8_t rom_digest[32], file_digest[32];
    uint64_t captured_generation;
    NHMemoryResult result;
    if (memory == NULL || file == NULL || generation == NULL)
        return NH_MEMORY_ARGUMENT;
    if (size != NH_SRAM_FILE_BYTES) return NH_MEMORY_INVALID_SRAM_FILE;
    result = nh_memory_export_sram(memory, &image, &captured_generation);
    if (result != NH_MEMORY_OK) return result;
    if (nh_sha256_bytes(memory->verified_rom, memory->rom_size, rom_digest) == 0)
        return NH_MEMORY_INVALID_ROM_BINDING;
    memset(file, 0, NH_SRAM_FILE_HEADER_BYTES);
    memcpy(file, nh_sram_magic, sizeof(nh_sram_magic));
    nh_sram_u32_store(file + 8u, 1u);
    nh_sram_u32_store(file + 12u, NH_SRAM_FILE_PAYLOAD_BYTES);
    memcpy(file + 16u, rom_digest, sizeof(rom_digest));
    memcpy(file + NH_SRAM_FILE_HEADER_BYTES, image.values, sizeof(image.values));
    memcpy(file + NH_SRAM_FILE_HEADER_BYTES + NH_SRAM_BYTES, image.known, sizeof(image.known));
    /* Digest includes the complete header with its digest field zeroed. */
    if (nh_sha256_bytes(file, size, file_digest) == 0) return NH_MEMORY_INVALID_SRAM_FILE;
    memcpy(file + 48u, file_digest, sizeof(file_digest));
    *generation = captured_generation;
    return NH_MEMORY_OK;
}

NHMemoryResult nh_sram_file_decode(NHMemory *memory, const uint8_t *file,
                                   size_t size) {
    uint8_t candidate[NH_SRAM_FILE_BYTES];
    uint8_t rom_digest[32], file_digest[32], expected_digest[32];
    NHSramImage image;
    if (memory == NULL || file == NULL) return NH_MEMORY_ARGUMENT;
    if (size != NH_SRAM_FILE_BYTES) return NH_MEMORY_INVALID_SRAM_FILE;
    if (memory->verified_rom == NULL || memory->rom_size != NH_ROM_BYTES)
        return NH_MEMORY_INVALID_ROM_BINDING;
    if (memory->access_started != 0u) return NH_MEMORY_SRAM_ALREADY_IN_USE;
    /* No live-machine field changes during candidate validation. */
    memcpy(candidate, file, sizeof(candidate));
    if (memcmp(candidate, nh_sram_magic, sizeof(nh_sram_magic)) != 0 ||
        nh_sram_u32_load(candidate + 8u) != 1u ||
        nh_sram_u32_load(candidate + 12u) != NH_SRAM_FILE_PAYLOAD_BYTES)
        return NH_MEMORY_INVALID_SRAM_FILE;
    if (nh_sha256_bytes(memory->verified_rom, memory->rom_size, rom_digest) == 0)
        return NH_MEMORY_INVALID_ROM_BINDING;
    if (memcmp(candidate + 16u, rom_digest, sizeof(rom_digest)) != 0)
        return NH_MEMORY_INVALID_ROM_BINDING;
    memcpy(expected_digest, candidate + 48u, sizeof(expected_digest));
    memset(candidate + 48u, 0, sizeof(expected_digest));
    if (nh_sha256_bytes(candidate, size, file_digest) == 0 ||
        memcmp(file_digest, expected_digest, sizeof(file_digest)) != 0)
        return NH_MEMORY_INVALID_SRAM_FILE;
    memcpy(image.values, candidate + NH_SRAM_FILE_HEADER_BYTES, sizeof(image.values));
    memcpy(image.known, candidate + NH_SRAM_FILE_HEADER_BYTES + NH_SRAM_BYTES, sizeof(image.known));
    return nh_memory_load_sram(memory, &image);
}
