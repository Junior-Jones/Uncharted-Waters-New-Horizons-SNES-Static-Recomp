#ifndef NEW_HORIZONS_SPC700_H
#define NEW_HORIZONS_SPC700_H

#include "new_horizons_apu.h"

enum {
    NH_SPC_C = 0x01u, NH_SPC_Z = 0x02u, NH_SPC_I = 0x04u,
    NH_SPC_H = 0x08u, NH_SPC_B = 0x10u, NH_SPC_P = 0x20u,
    NH_SPC_V = 0x40u, NH_SPC_N = 0x80u
};

int nh_spc_fail(NHApu12 *);
int nh_spc_guard(NHApu12 *, uint16_t, const uint8_t *, unsigned);
int nh_spc_known_guard(NHApu12 *, uint16_t, unsigned);
uint16_t nh_spc_dp(const NHApu12 *, uint8_t);
int nh_spc_read(NHApu12 *, uint16_t, uint8_t *);
int nh_spc_write(NHApu12 *, uint16_t, uint8_t);
int nh_spc_read_dp_word(NHApu12 *, uint8_t, uint16_t *);
int nh_spc_push(NHApu12 *, uint8_t);
int nh_spc_pop(NHApu12 *, uint8_t *);
void nh_spc_nz8(NHApu12 *, uint8_t);
void nh_spc_nz16(NHApu12 *, uint16_t);
void nh_spc_cmp8(NHApu12 *, uint8_t, uint8_t);
uint8_t nh_spc_adc8(NHApu12 *, uint8_t, uint8_t);
uint8_t nh_spc_sbc8(NHApu12 *, uint8_t, uint8_t);
uint16_t nh_spc_addw(NHApu12 *, uint16_t, uint16_t);
uint16_t nh_spc_subw(NHApu12 *, uint16_t, uint16_t);
uint8_t nh_spc_asl8(NHApu12 *, uint8_t);
uint8_t nh_spc_lsr8(NHApu12 *, uint8_t);
uint8_t nh_spc_rol8(NHApu12 *, uint8_t);
uint8_t nh_spc_ror8(NHApu12 *, uint8_t);

int nh_spc700_aot_begin(NHApu12 *);
int nh_spc700_aot_complete(NHApu12 *);
int nh_spc700_aot_code_byte(uint16_t);
int nh_spc700_aot_mutation_write_allowed(uint16_t, uint16_t);

#endif
