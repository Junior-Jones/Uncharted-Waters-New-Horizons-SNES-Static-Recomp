#include "new_horizons_spc700.h"

static void clear_flags(NHApu12 *a, uint8_t flags) {
    a->spc.psw &= (uint8_t)~flags;
}

int nh_spc_fail(NHApu12 *a) {
    if (a != NULL) {
        a->phase = NH_APU12_FAILED;
        if (a->bus != NULL && a->bus->failure.reason == NH_BUS_OK) {
            a->bus->failure.reason = NH_BUS_APUIO_UNAVAILABLE;
            a->bus->failure.owner = NH_OWNER_APUIO_12;
            a->bus->failure.address = a->spc.pc;
        }
    }
    return 0;
}

int nh_spc_guard(NHApu12 *a, uint16_t pc, const uint8_t *expected,
                 unsigned length) {
    unsigned offset;
    if (a == NULL || expected == NULL || length == 0u) return nh_spc_fail(a);
    for (offset = 0u; offset < length; ++offset) {
        uint16_t address = (uint16_t)(pc + offset);
        uint8_t known = nh_apu12_aram_known(a, address);
        if (!known || a->aram[address] != expected[offset]) {
            nh_spc_fail(a);
            if (a->bus != NULL) {
                a->bus->failure.address = address;
                a->bus->failure.value = a->aram[address];
                a->bus->failure.known_mask = known != 0u ? 0xFFu : 0u;
            }
            return 0;
        }
    }
    return 1;
}

int nh_spc_known_guard(NHApu12 *a, uint16_t address, unsigned length) {
    unsigned offset;
    if (a == NULL || length == 0u) return nh_spc_fail(a);
    for (offset = 0u; offset < length; ++offset) {
        uint16_t current = (uint16_t)(address + offset);
        if (!nh_apu12_aram_known(a, current)) {
            nh_spc_fail(a);
            if (a->bus != NULL) {
                a->bus->failure.address = current;
                a->bus->failure.value = a->aram[current];
                a->bus->failure.known_mask = 0u;
            }
            return 0;
        }
    }
    return 1;
}

uint16_t nh_spc_dp(const NHApu12 *a, uint8_t address) {
    return (uint16_t)(address | ((a->spc.psw & NH_SPC_P) != 0u ? 0x0100u : 0u));
}

int nh_spc_read(NHApu12 *a, uint16_t address, uint8_t *value) {
    NHBusValue bus_value;
    if (value == NULL || nh_apu12_smp_read(a, address, &bus_value) != NH_BUS_OK ||
        bus_value.known_mask != 0xFFu) return nh_spc_fail(a);
    *value = bus_value.value;
    return 1;
}

int nh_spc_write(NHApu12 *a, uint16_t address, uint8_t value) {
    if (nh_spc700_aot_code_byte(address) &&
        !nh_spc700_aot_mutation_write_allowed(a->spc.active_pc, address))
        return nh_spc_fail(a);
    return nh_apu12_smp_write(a, address, (NHBusValue){value, 0xFFu}) == NH_BUS_OK
        ? 1 : nh_spc_fail(a);
}

int nh_spc_read_dp_word(NHApu12 *a, uint8_t address, uint16_t *value) {
    uint8_t low, high;
    if (value == NULL || !nh_spc_read(a, nh_spc_dp(a, address), &low) ||
        !nh_spc_read(a, nh_spc_dp(a, (uint8_t)(address + 1u)), &high))
        return nh_spc_fail(a);
    *value = (uint16_t)(low | (uint16_t)high << 8u);
    return 1;
}

int nh_spc_push(NHApu12 *a, uint8_t value) {
    if (!nh_spc_write(a, (uint16_t)(0x0100u | a->spc.sp), value)) return 0;
    --a->spc.sp;
    return 1;
}

int nh_spc_pop(NHApu12 *a, uint8_t *value) {
    ++a->spc.sp;
    return nh_spc_read(a, (uint16_t)(0x0100u | a->spc.sp), value);
}

void nh_spc_nz8(NHApu12 *a, uint8_t value) {
    clear_flags(a, (uint8_t)(NH_SPC_N | NH_SPC_Z));
    if (value == 0u) a->spc.psw |= NH_SPC_Z;
    if ((value & 0x80u) != 0u) a->spc.psw |= NH_SPC_N;
}

void nh_spc_nz16(NHApu12 *a, uint16_t value) {
    clear_flags(a, (uint8_t)(NH_SPC_N | NH_SPC_Z));
    if (value == 0u) a->spc.psw |= NH_SPC_Z;
    if ((value & 0x8000u) != 0u) a->spc.psw |= NH_SPC_N;
}

void nh_spc_cmp8(NHApu12 *a, uint8_t left, uint8_t right) {
    clear_flags(a, NH_SPC_C);
    if (left >= right) a->spc.psw |= NH_SPC_C;
    nh_spc_nz8(a, (uint8_t)(left - right));
}

uint8_t nh_spc_adc8(NHApu12 *a, uint8_t left, uint8_t right) {
    uint8_t carry = (uint8_t)((a->spc.psw & NH_SPC_C) != 0u);
    uint16_t sum = (uint16_t)left + right + carry;
    uint8_t result = (uint8_t)sum;
    clear_flags(a, (uint8_t)(NH_SPC_C | NH_SPC_H | NH_SPC_V));
    if (sum > 0xFFu) a->spc.psw |= NH_SPC_C;
    if ((left & 15u) + (right & 15u) + carry > 15u) a->spc.psw |= NH_SPC_H;
    if (((uint8_t)~(left ^ right) & (left ^ result) & 0x80u) != 0u) a->spc.psw |= NH_SPC_V;
    nh_spc_nz8(a, result);
    return result;
}

uint8_t nh_spc_sbc8(NHApu12 *a, uint8_t left, uint8_t right) {
    uint8_t borrow = (uint8_t)((a->spc.psw & NH_SPC_C) == 0u);
    int difference = (int)left - (int)right - borrow;
    uint8_t result = (uint8_t)difference;
    clear_flags(a, (uint8_t)(NH_SPC_C | NH_SPC_H | NH_SPC_V));
    if (difference >= 0) a->spc.psw |= NH_SPC_C;
    if ((int)(left & 15u) - (int)(right & 15u) - borrow >= 0) a->spc.psw |= NH_SPC_H;
    if (((left ^ right) & (left ^ result) & 0x80u) != 0u) a->spc.psw |= NH_SPC_V;
    nh_spc_nz8(a, result);
    return result;
}

uint16_t nh_spc_addw(NHApu12 *a, uint16_t left, uint16_t right) {
    uint32_t sum = (uint32_t)left + right;
    uint16_t result = (uint16_t)sum;
    clear_flags(a, (uint8_t)(NH_SPC_C | NH_SPC_H | NH_SPC_V));
    if (sum > 0xFFFFu) a->spc.psw |= NH_SPC_C;
    if ((left & 0x0FFFu) + (right & 0x0FFFu) > 0x0FFFu) a->spc.psw |= NH_SPC_H;
    if (((uint16_t)~(left ^ right) & (left ^ result) & 0x8000u) != 0u) a->spc.psw |= NH_SPC_V;
    nh_spc_nz16(a, result);
    return result;
}

uint16_t nh_spc_subw(NHApu12 *a, uint16_t left, uint16_t right) {
    uint32_t result32 = (uint32_t)left - right;
    uint16_t result = (uint16_t)result32;
    clear_flags(a, (uint8_t)(NH_SPC_C | NH_SPC_H | NH_SPC_V));
    if (left >= right) a->spc.psw |= NH_SPC_C;
    if ((left & 0x0FFFu) >= (right & 0x0FFFu)) a->spc.psw |= NH_SPC_H;
    if (((left ^ right) & (left ^ result) & 0x8000u) != 0u) a->spc.psw |= NH_SPC_V;
    nh_spc_nz16(a, result);
    return result;
}

uint8_t nh_spc_asl8(NHApu12 *a, uint8_t value) {
    clear_flags(a, NH_SPC_C); if (value & 0x80u) a->spc.psw |= NH_SPC_C;
    value = (uint8_t)(value << 1u); nh_spc_nz8(a, value); return value;
}
uint8_t nh_spc_lsr8(NHApu12 *a, uint8_t value) {
    clear_flags(a, NH_SPC_C); if (value & 1u) a->spc.psw |= NH_SPC_C;
    value >>= 1u; nh_spc_nz8(a, value); return value;
}
uint8_t nh_spc_rol8(NHApu12 *a, uint8_t value) {
    uint8_t carry = (uint8_t)((a->spc.psw & NH_SPC_C) != 0u);
    clear_flags(a, NH_SPC_C); if (value & 0x80u) a->spc.psw |= NH_SPC_C;
    value = (uint8_t)(value << 1u | carry); nh_spc_nz8(a, value); return value;
}
uint8_t nh_spc_ror8(NHApu12 *a, uint8_t value) {
    uint8_t carry = (uint8_t)((a->spc.psw & NH_SPC_C) != 0u);
    clear_flags(a, NH_SPC_C); if (value & 1u) a->spc.psw |= NH_SPC_C;
    value = (uint8_t)(value >> 1u | carry << 7u); nh_spc_nz8(a, value); return value;
}
