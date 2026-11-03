#ifndef NEW_HORIZONS_SPC700_AOT_H
#define NEW_HORIZONS_SPC700_AOT_H
#include "new_horizons_apu.h"
int nh_spc700_aot_begin(NHApu12 *);
int nh_spc700_aot_event(NHApu12 *);
int nh_spc700_aot_complete(NHApu12 *);
int nh_spc700_aot_code_byte(uint16_t);
int nh_spc700_aot_mutation_write_allowed(uint16_t,uint16_t);
#endif
