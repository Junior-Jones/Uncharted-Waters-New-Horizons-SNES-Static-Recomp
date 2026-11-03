#ifndef NEW_HORIZONS_CLOCK_DOMAIN_H
#define NEW_HORIZONS_CLOCK_DOMAIN_H
#include <stdint.h>

/* Exact selected project ratio, not a claim of physically locked oscillators.
 * Only the ONE master timeline supplies elapsed clocks. No wall-clock input,
 * independent timeline or SMP execution is owned by this remainder record. */
enum {
    NH_MASTER_HZ_NUMERATOR = 21477270u,
    NH_MASTER_HZ_DENOMINATOR = 1u,
    NH_SMP_REFERENCE_HZ = 1024000u,
    NH_SMP_RATIO_NUMERATOR = 102400u,
    NH_SMP_RATIO_DENOMINATOR = 2147727u,
    NH_SMP_INITIAL_REMAINDER = 0u,
    NH_NTSC_NORMAL_LINE_CLOCKS = 1364u,
    NH_NTSC_SHORT_LINE_CLOCKS = 1360u,
    NH_NTSC_LINES_PER_FIELD = 262u,
    NH_NTSC_CPU_VERSION_REFERENCE = 2u
};

/* Immutable native metadata for config/timing-profile.json, not a host timing
 * input or a universal physical-crystal/board/initial-phase claim. The future
 * public-core owner exposes this contract rather than inferring it from SDL
 * or a device-negotiated rate. Raster still publishes actual completed fields. */
typedef struct NHTimingProfile {
    const char *name;
    uint32_t master_hz_numerator;
    uint32_t master_hz_denominator;
    uint32_t smp_reference_hz;
    uint32_t smp_ratio_numerator;
    uint32_t smp_ratio_denominator;
    uint32_t smp_initial_remainder;
    uint16_t normal_line_clocks;
    uint16_t short_line_clocks;
    uint16_t noninterlace_lines_per_field;
    uint8_t cpu_version_reference;
} NHTimingProfile;

const NHTimingProfile *nh_timing_profile(void);
typedef struct NHSmpClockJoin {
    uint64_t target_cycles;
    uint32_t remainder;
} NHSmpClockJoin;

/* Cold initialization only. S-CPU reset must not call this. Snapshots retain
 * both members. Reject invalid/overflowed input without changing the record. */
void nh_smp_clock_join_cold(NHSmpClockJoin *);
int nh_smp_clock_join_advance(NHSmpClockJoin *, uint32_t elapsed_master_clocks);
#endif
