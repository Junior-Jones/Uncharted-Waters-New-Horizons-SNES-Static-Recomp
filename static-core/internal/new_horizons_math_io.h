#ifndef NEW_HORIZONS_MATH_IO_H
#define NEW_HORIZONS_MATH_IO_H
#include "new_horizons_bus_runtime.h"

typedef struct NHMathIO {
    uint8_t multiplicand;
    uint8_t multiplicand_known;
    uint16_t dividend;
    uint16_t dividend_known;
    uint16_t quotient;
    uint16_t quotient_known;
    uint16_t result;
    uint16_t result_known;
    uint32_t shifted;
    uint32_t shifted_known;
    /* Nonzero until the cycle after the final arithmetic pulse begins.
     * Result readiness (remaining==0) is not same-cycle trigger acceptance. */
    uint8_t operation;
    uint8_t pulses_remaining;
} NHMathIO;

void nh_math_power_on(NHMathIO *math);
NHBusStop nh_math_write(NHMathIO *math, uint16_t reg, NHBusValue value);
NHBusStop nh_math_read(const NHMathIO *math, uint16_t reg, NHDrivenByte *value);
/* Arithmetic pulse only. 09C owns when a physical pulse occurs, including
 * stalls/refresh/access sampling; this function owns no independent clock.
 *09 applies the cycle's pulse before its CPU bus commit. Final result is
 * available after8/16 arithmetic pulses; trigger inhibit is released on the
 * following cycle's pulse. That release pulse performs no extra arithmetic. */
void nh_math_pulse(NHMathIO *math);

#endif
