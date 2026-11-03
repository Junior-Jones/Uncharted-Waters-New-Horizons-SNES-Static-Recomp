#include "new_horizons_rom_identity.h"
#include "new_horizons_bus.h"
#include <string.h>

/* Mathematical constants/algorithm: NIST FIPS180-4 sections4.1.2,4.2.2,
 * 5.1.1,5.3.3,6.2.2. Implementation authored here, not foreign-game code. */
static const uint32_t nh_sha_k[64] = {
    0x428a2f98u,0x71374491u,0xb5c0fbcfu,0xe9b5dba5u,0x3956c25bu,0x59f111f1u,0x923f82a4u,0xab1c5ed5u,
    0xd807aa98u,0x12835b01u,0x243185beu,0x550c7dc3u,0x72be5d74u,0x80deb1feu,0x9bdc06a7u,0xc19bf174u,
    0xe49b69c1u,0xefbe4786u,0x0fc19dc6u,0x240ca1ccu,0x2de92c6fu,0x4a7484aau,0x5cb0a9dcu,0x76f988dau,
    0x983e5152u,0xa831c66du,0xb00327c8u,0xbf597fc7u,0xc6e00bf3u,0xd5a79147u,0x06ca6351u,0x14292967u,
    0x27b70a85u,0x2e1b2138u,0x4d2c6dfcu,0x53380d13u,0x650a7354u,0x766a0abbu,0x81c2c92eu,0x92722c85u,
    0xa2bfe8a1u,0xa81a664bu,0xc24b8b70u,0xc76c51a3u,0xd192e819u,0xd6990624u,0xf40e3585u,0x106aa070u,
    0x19a4c116u,0x1e376c08u,0x2748774cu,0x34b0bcb5u,0x391c0cb3u,0x4ed8aa4au,0x5b9cca4fu,0x682e6ff3u,
    0x748f82eeu,0x78a5636fu,0x84c87814u,0x8cc70208u,0x90befffau,0xa4506cebu,0xbef9a3f7u,0xc67178f2u
};

static uint32_t nh_rotr32(uint32_t value, unsigned count) {
    return (value >> count) | (value << (32u - count));
}

static void nh_sha_block(uint32_t state[8], const uint8_t block[64]) {
    uint32_t words[64];
    uint32_t work[8];
    unsigned index;
    for (index = 0u; index < 16u; ++index) {
        const unsigned byte = index * 4u;
        words[index] = ((uint32_t)block[byte] << 24u) |
                        ((uint32_t)block[byte + 1u] << 16u) |
                        ((uint32_t)block[byte + 2u] << 8u) | block[byte + 3u];
    }
    for (index = 16u; index < 64u; ++index) {
        const uint32_t x = words[index - 15u], y = words[index - 2u];
        const uint32_t s0 = nh_rotr32(x,7u) ^ nh_rotr32(x,18u) ^ (x >> 3u);
        const uint32_t s1 = nh_rotr32(y,17u) ^ nh_rotr32(y,19u) ^ (y >> 10u);
        words[index] = words[index - 16u] + s0 + words[index - 7u] + s1;
    }
    for (index = 0u; index < 8u; ++index) work[index] = state[index];
    for (index = 0u; index < 64u; ++index) {
        const uint32_t e = work[4], a = work[0];
        const uint32_t choose = (e & work[5]) ^ ((~e) & work[6]);
        const uint32_t majority = (a & work[1]) ^ (a & work[2]) ^ (work[1] & work[2]);
        const uint32_t first = work[7] + (nh_rotr32(e,6u) ^ nh_rotr32(e,11u) ^ nh_rotr32(e,25u)) +
                                choose + nh_sha_k[index] + words[index];
        const uint32_t second = (nh_rotr32(a,2u) ^ nh_rotr32(a,13u) ^ nh_rotr32(a,22u)) + majority;
        work[7] = work[6]; work[6] = work[5]; work[5] = e;
        work[4] = work[3] + first; work[3] = work[2];
        work[2] = work[1]; work[1] = a; work[0] = first + second;
    }
    for (index = 0u; index < 8u; ++index) state[index] += work[index];
}

int nh_sha256_bytes(const uint8_t *bytes, size_t length, uint8_t digest[32]) {
    uint32_t state[8] = { 0x6a09e667u,0xbb67ae85u,0x3c6ef372u,0xa54ff53au,
                          0x510e527fu,0x9b05688cu,0x1f83d9abu,0x5be0cd19u };
    uint8_t tail[128] = { 0u };
    size_t offset = 0u, remaining, padded;
    uint64_t bits;
    unsigned index;
    _Static_assert(sizeof(size_t) <= sizeof(uint64_t), "unsupported message length type");
    if (digest == NULL || (bytes == NULL && length != 0u) ||
        (uint64_t)length > UINT64_MAX / 8u) return 0;
    bits = (uint64_t)length * 8u;
    while (length - offset >= 64u) {
        nh_sha_block(state, bytes + offset);
        offset += 64u;
    }
    remaining = length - offset;
    if (remaining != 0u) memcpy(tail, bytes + offset, remaining);
    tail[remaining] = 0x80u;
    padded = remaining < 56u ? 64u : 128u;
    for (index = 0u; index < 8u; ++index)
        tail[padded - 1u - index] = (uint8_t)(bits >> (index * 8u));
    nh_sha_block(state, tail);
    if (padded == 128u) nh_sha_block(state, tail + 64u);
    for (index = 0u; index < 32u; ++index)
        digest[index] = (uint8_t)(state[index / 4u] >> ((3u - (index & 3u)) * 8u));
    return 1;
}

int nh_rom_matches_canonical(const uint8_t *bytes, size_t length) {
    static const char expected[] =
        "64bc4707f422661a66618088887e2363a5f896ea683c58984fffd96dd21ab5f0";
    static const char hex[] = "0123456789abcdef";
    uint8_t digest[32];
    unsigned index;
    _Static_assert(sizeof(expected) == 65u, "invalid01C cartridge digest");
    if (bytes == NULL || length != NH_ROM_BYTES || nh_sha256_bytes(bytes, length, digest) == 0)
        return 0;
    for (index = 0u; index < 32u; ++index) {
        if (hex[digest[index] >> 4u] != expected[index * 2u] ||
            hex[digest[index] & 15u] != expected[index * 2u + 1u]) return 0;
    }
    return 1;
}
