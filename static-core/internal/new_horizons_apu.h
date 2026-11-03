#ifndef NEW_HORIZONS_APU_H
#define NEW_HORIZONS_APU_H

#include "new_horizons_scheduler.h"

struct NHSdsp16;

enum {
    NH_APU_ARAM_BYTES = 65536u,
    NH_APU_UPLOAD_ROM_OFFSET = 0x146D48u,
    NH_APU_UPLOAD_BYTES = 7029u,
    NH_APU_UPLOAD_DESTINATION = 0x0800u,
    NH_APU_STATIC_ENTRY = 0x081Au
};

typedef enum NHApuPhase12 {
    NH_APU12_IPL_STARTUP = 0,
    NH_APU12_WAIT_HEADER,
    NH_APU12_UPLOAD,
    NH_APU12_WAIT_TERMINATOR,
    NH_APU12_STATIC_ENTRY_REQUIRED,
    NH_APU13_STATIC_RUNNING,
    NH_APU12_FAILED
} NHApuPhase12;

typedef struct NHSpc700State13 {
    uint16_t pc;
    uint16_t active_pc;
    uint16_t return_pc[256];
    uint16_t return_depth;
    uint8_t a, x, y, sp, psw;
    uint8_t active_branch_taken;
    uint8_t active;
    uint8_t active_cycle_index;
    uint8_t active_latch_low;
    uint8_t active_latch_high;
    uint8_t active_latch_data;
    uint32_t active_cycles_remaining;
    uint64_t instructions;
} NHSpc700State13;

typedef struct NHApuTimer12 {
    uint16_t divider;
    uint8_t target;
    uint8_t stage;
    uint8_t output;
    uint8_t enabled;
} NHApuTimer12;

typedef struct NHApu12 {
    NHBusRuntime *bus;
    NHScheduler *scheduler;
    NHSchedulerReceivers downstream;
    struct NHSdsp16 *sdsp;
    uint8_t aram[NH_APU_ARAM_BYTES];
    uint8_t aram_known[NH_APU_ARAM_BYTES / 8u];
    NHBusValue cpu_to_smp[4];
    NHBusValue cpu_to_smp_pending[4];
    NHBusValue smp_to_cpu[4];
    uint64_t cpu_write_sequence[4];
    uint64_t write_sequence;
    uint64_t consumed_port0_sequence;
    uint64_t smp_cycles;
    uint64_t smp_phase_units;
    uint32_t uploaded_bytes;
    uint32_t upload_epoch;
    uint16_t upload_address;
    uint16_t static_entry_pc;
    uint8_t expected_token;
    uint8_t last_ack;
    uint8_t control;
    uint8_t dsp_address;
    uint8_t aux[2];
    uint8_t ipl_rom_enabled;
    uint8_t smp_startup_cycles_remaining;
    uint8_t cpu_to_smp_pending_mask;
    NHApuPhase12 phase;
    NHApuTimer12 timer[3];
    NHSpc700State13 spc;
    uint64_t register_reads[4];
    uint64_t register_writes[4];
} NHApu12;

/* Cold owner construction. ARAM starts unknown; the fixed IPL later proves
 * only its actual clear range. S-CPU RESET deliberately leaves this owner and
 * the independent clock phase untouched. */
NHBusStop nh_apu12_power_on(NHApu12 *, NHBusRuntime *, NHScheduler *);
/* Explicit reproducibility profile only. Strict power-on ARAM remains
 * unknown; this helper must run before binding or any guest clock advances. */
NHBusStop nh_apu12_apply_zero_aram_profile(NHApu12 *);
NHBusStop nh_apu12_cpu_reset(NHApu12 *);
/* Bind after PPU and before DMA. This owner replaces the scheduler's SMP-sync
 * receiver and forwards raster/CPU-boundary events to the prior chain. */
NHBusStop nh_apu12_bind(NHApu12 *);
NHBusStop nh_apu12_bind_sdsp(NHApu12 *, struct NHSdsp16 *);
NHRegisterPort nh_apu12_register_port(NHApu12 *);
NHBusStop nh_apu12_sync(NHApu12 *, uint64_t target_phase_units);

/* S-SMP-side memory/MMIO authority for Version13 static bodies. These calls
 * never decode an opcode. Unknown ARAM and the Version16 DSP data port stop. */
NHBusStop nh_apu12_smp_read(NHApu12 *, uint16_t address, NHBusValue *);
NHBusStop nh_apu12_smp_write(NHApu12 *, uint16_t address, NHBusValue);
int nh_apu12_aram_known(const NHApu12 *, uint16_t address);

#endif
