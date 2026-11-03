#include "new_horizons_clock_domain.h"
#include <stddef.h>

_Static_assert((uint64_t)NH_MASTER_HZ_NUMERATOR * NH_SMP_RATIO_NUMERATOR ==
               (uint64_t)NH_SMP_REFERENCE_HZ * NH_MASTER_HZ_DENOMINATOR * NH_SMP_RATIO_DENOMINATOR,
               "Native SMP ratio must match the declared master/reference frequencies");

const NHTimingProfile *nh_timing_profile(void) {
    static const NHTimingProfile profile = {
        "NH_NTSC_21477270_SMP1024000_PHASE0",
        NH_MASTER_HZ_NUMERATOR, NH_MASTER_HZ_DENOMINATOR,
        NH_SMP_REFERENCE_HZ, NH_SMP_RATIO_NUMERATOR, NH_SMP_RATIO_DENOMINATOR,
        NH_SMP_INITIAL_REMAINDER, NH_NTSC_NORMAL_LINE_CLOCKS,
        NH_NTSC_SHORT_LINE_CLOCKS, NH_NTSC_LINES_PER_FIELD,
        NH_NTSC_CPU_VERSION_REFERENCE
    };
    return &profile;
}

void nh_smp_clock_join_cold(NHSmpClockJoin *join) {
    if (join != NULL) {
        join->target_phase_units = 0u;
        join->target_cycles = 0u;
        join->remainder = NH_SMP_INITIAL_REMAINDER;
    }
}

int nh_smp_clock_join_advance(NHSmpClockJoin *join, uint32_t elapsed_master_clocks) {
    uint64_t scaled, phase_units;
    if (join == NULL || join->remainder >= NH_SMP_RATIO_DENOMINATOR) return 0;
    /* u32 elapsed * u32 fixed numerator + bounded remainder fits u64. */
    scaled = (uint64_t)elapsed_master_clocks * NH_SMP_PHASE_RATIO_NUMERATOR + join->remainder;
    phase_units = scaled / NH_SMP_RATIO_DENOMINATOR;
    if (phase_units > UINT64_MAX - join->target_phase_units) return 0;
    join->target_phase_units += phase_units;
    join->target_cycles = join->target_phase_units / 2u;
    join->remainder = (uint32_t)(scaled % NH_SMP_RATIO_DENOMINATOR);
    return 1;
}
