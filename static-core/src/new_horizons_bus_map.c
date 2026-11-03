#include "new_horizons_bus.h"

#include <stddef.h>

/* Own HiROM/32-KiB SRAM implementation; no foreign game code. These pure
 * classifiers remain outside the sealed 07C allow-list until the 08C gate.
 * Classification must never be mistaken for an implemented receiver. */
int nh_bus_classify(uint32_t address, NHBusRegion *region) {
    uint32_t bank;
    uint32_t local;
    NHBusRegion result = { NH_BUS_OPEN_EXTERNAL, NH_OWNER_BUS_08, 0u, 0u };
    if (address > 0xFFFFFFu || region == NULL) return 0;
    bank = address >> 16u;
    local = address & 0xFFFFu;
    result.offset = local;
    if (bank == 0x7Eu || bank == 0x7Fu) {
        result.kind = NH_BUS_WRAM;
        result.offset = ((bank - 0x7Eu) << 16u) | local;
    } else if ((bank & 0x40u) != 0u || local >= 0x8000u) {
        result.kind = NH_BUS_ROM;
        /* Connected ROM address lines A0..A20, after cartridge selection.
         * This is not an arbitrary modulo mapping of unmapped addresses. */
        result.offset = address & 0x1FFFFFu;
    } else if (local < 0x2000u) {
        result.kind = NH_BUS_WRAM;
    } else if ((bank & 0x20u) != 0u && local >= 0x6000u) {
        result.kind = NH_BUS_SRAM;
        result.offset = ((bank & 3u) << 13u) | (local & 0x1FFFu);
    } else if (local >= 0x2100u && local <= 0x213Fu) {
        result.kind = NH_BUS_PPU;
        result.owner = NH_OWNER_PPU_11;
    } else if (local >= 0x2140u && local <= 0x217Fu) {
        result.kind = NH_BUS_APUIO;
        result.owner = NH_OWNER_APUIO_12;
        result.offset = 0x2140u | (local & 3u);
    } else if (local >= 0x2180u && local <= 0x2183u) {
        result.kind = NH_BUS_WRAM_PORT;
    } else if (local >= 0x4000u && local <= 0x43FFu) {
        result.internal_io = 1u;
        result.kind = NH_BUS_OPEN_INTERNAL;
        if (local == 0x4016u || local == 0x4017u ||
            (local >= 0x4218u && local <= 0x421Fu)) {
            result.kind = NH_BUS_INPUT_IO;
            result.owner = NH_OWNER_INPUT_15;
        } else if (local == 0x4201u ||
                   (local >= 0x4202u && local <= 0x4206u) ||
                   local == 0x420Du || local == 0x4213u ||
                   (local >= 0x4214u && local <= 0x4217u)) {
            result.kind = NH_BUS_CPU_IO;
        } else if (local == 0x4200u ||
                   (local >= 0x4207u && local <= 0x420Au) ||
                   (local >= 0x4210u && local <= 0x4212u)) {
            result.kind = NH_BUS_SCHEDULER_IO;
            result.owner = NH_OWNER_CLOCK_09;
        } else if (local == 0x420Bu || local == 0x420Cu ||
                   (local >= 0x4300u && local <= 0x437Fu)) {
            /* Preserve exact low register bits, including reserved slots;
             * 10C owns their implemented/undefined behavior, not this map. */
            result.kind = NH_BUS_DMA_IO;
            result.owner = NH_OWNER_DMA_10;
        }
    }
    *region = result;
    return 1;
}

int nh_bus_access_clocks(uint32_t address, uint8_t memsel, uint8_t *clocks) {
    uint32_t bank;
    uint32_t local;
    uint8_t result = 8u;
    if (address > 0xFFFFFFu || memsel > 1u || clocks == NULL) return 0;
    bank = address >> 16u;
    local = address & 0xFFFFu;
    if (bank != 0x7Eu && bank != 0x7Fu && (bank & 0x40u) == 0u) {
        if (local >= 0x2000u && local < 0x6000u) {
            result = (local >= 0x4000u && local < 0x4200u) ? 12u : 6u;
        } else if (local >= 0x8000u && bank >= 0x80u && memsel != 0u) {
            result = 6u;
        }
    } else if (bank >= 0xC0u && memsel != 0u) {
        result = 6u;
    }
    *clocks = result;
    return 1;
}
