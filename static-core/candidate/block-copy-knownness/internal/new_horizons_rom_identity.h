#ifndef NEW_HORIZONS_ROM_IDENTITY_H
#define NEW_HORIZONS_ROM_IDENTITY_H
#include <stddef.h>
#include <stdint.h>

/* Own portable implementation of the standard SHA-256 arithmetic, for
 * cartridge/save identity; no guest code/data execution or native dependency. */
int nh_sha256_bytes(const uint8_t *bytes, size_t length, uint8_t digest[32]);
int nh_rom_matches_canonical(const uint8_t *bytes, size_t length);

#endif
