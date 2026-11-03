#include "new_horizons_math_io.h"
#include <string.h>

void nh_math_power_on(NHMathIO *math) {
    if (math == NULL) return;
    memset(math, 0, sizeof(*math));
    math->multiplicand = 0xFFu;
    math->multiplicand_known = 0xFFu;
    math->dividend = 0xFFFFu;
    math->dividend_known = 0xFFFFu;
    math->quotient_known = 0xFFFFu;
    /* Initial product/remainder has no established value: zero is not known. */
}

NHBusStop nh_math_write(NHMathIO *math, uint16_t reg, NHBusValue value) {
    if (math == NULL) return NH_BUS_BAD_ARGUMENT;
    switch (reg) {
        case 0x4202u:
            math->multiplicand = value.value;
            math->multiplicand_known = value.known_mask;
            return NH_BUS_OK;
        case 0x4204u:
            math->dividend = (uint16_t)((math->dividend & 0xFF00u) | value.value);
            math->dividend_known = (uint16_t)((math->dividend_known & 0xFF00u) | value.known_mask);
            return NH_BUS_OK;
        case 0x4205u:
            math->dividend = (uint16_t)((math->dividend & 0x00FFu) | ((uint16_t)value.value << 8u));
            math->dividend_known = (uint16_t)((math->dividend_known & 0x00FFu) |
                                              ((uint16_t)value.known_mask << 8u));
            return NH_BUS_OK;
        case 0x4203u:
            math->result = 0u;
            math->result_known = 0xFFFFu;
            if (math->operation == 0u) {
                math->quotient = (uint16_t)(((uint16_t)value.value << 8u) | math->multiplicand);
                math->quotient_known = (uint16_t)(((uint16_t)value.known_mask << 8u) |
                                                 math->multiplicand_known);
                math->shifted = value.value;
                math->shifted_known = 0xFFFFFF00u | value.known_mask;
                math->operation = 1u;
                math->pulses_remaining = 8u;
            }
            return NH_BUS_OK;
        case 0x4206u:
            math->result = math->dividend;
            math->result_known = math->dividend_known;
            if (math->operation == 0u) {
                math->shifted = (uint32_t)value.value << 16u;
                math->shifted_known = 0xFF00FFFFu | ((uint32_t)value.known_mask << 16u);
                math->operation = 2u;
                math->pulses_remaining = 16u;
            }
            return NH_BUS_OK;
        default: return NH_BUS_UNPROVED_REGISTER;
    }
}

NHBusStop nh_math_read(const NHMathIO *math, uint16_t reg, NHDrivenByte *value) {
    uint16_t word, known;
    const unsigned shift = (reg & 1u) != 0u ? 8u : 0u;
    if (math == NULL || value == NULL) return NH_BUS_BAD_ARGUMENT;
    if (reg == 0x4214u || reg == 0x4215u) {
        word = math->quotient; known = math->quotient_known;
    } else if (reg == 0x4216u || reg == 0x4217u) {
        word = math->result; known = math->result_known;
    } else return NH_BUS_UNPROVED_REGISTER;
    value->value = (uint8_t)(word >> shift);
    value->known_mask = (uint8_t)(known >> shift);
    value->driven_mask = 0xFFu;
    return NH_BUS_OK;
}

void nh_math_pulse(NHMathIO *math) {
    if (math == NULL) return;
    if (math->pulses_remaining == 0u) {
        /* Retire the prior cycle's trigger inhibit, not another arithmetic
         * step. A write after the final calculation but in that same cycle
         * still clears the latch without starting a replacement operation. */
        math->operation = 0u;
        return;
    }
    if (math->operation == 1u) {
        const int bit_known = (math->quotient_known & 1u) != 0u;
        const int selected = (math->quotient & 1u) != 0u;
        const int shifted_zero = (math->shifted_known & 0xFFFFu) == 0xFFFFu &&
                                  (math->shifted & 0xFFFFu) == 0u;
        if (bit_known == 0 && shifted_zero == 0) math->result_known = 0u;
        if (selected != 0) {
            if (shifted_zero == 0 && (math->result_known != 0xFFFFu ||
                                     (math->shifted_known & 0xFFFFu) != 0xFFFFu))
                math->result_known = 0u;
            math->result = (uint16_t)(math->result + (uint16_t)math->shifted);
        }
        math->shifted <<= 1u;
        math->shifted_known = (math->shifted_known << 1u) | 1u;
        math->quotient >>= 1u;
        math->quotient_known = (uint16_t)((math->quotient_known >> 1u) | 0x8000u);
    } else if (math->operation == 2u) {
        int condition_known;
        int selected;
        math->shifted >>= 1u;
        math->shifted_known = (math->shifted_known >> 1u) | 0x80000000u;
        selected = (uint32_t)math->result >= math->shifted;
        condition_known = (math->result_known == 0xFFFFu && math->shifted_known == UINT32_MAX) ||
            (math->shifted_known == UINT32_MAX && math->shifted == 0u) ||
            ((math->shifted & math->shifted_known & 0xFFFF0000u) != 0u);
        if (condition_known == 0) {
            /* For unsigned zero dividend, either a zero trial subtraction
             * succeeds or the trial is rejected; the remainder remains zero. */
            if (math->result_known != 0xFFFFu || math->result != 0u)
                math->result_known = 0u;
        } else if (selected != 0 && math->shifted_known != UINT32_MAX) {
            math->result_known = 0u;
        }
        math->quotient = (uint16_t)((math->quotient << 1u) | (selected != 0 ? 1u : 0u));
        math->quotient_known = (uint16_t)((math->quotient_known << 1u) |
                                         (condition_known != 0 ? 1u : 0u));
        if (selected != 0) math->result = (uint16_t)((uint32_t)math->result - math->shifted);
    }
    --math->pulses_remaining;
}
