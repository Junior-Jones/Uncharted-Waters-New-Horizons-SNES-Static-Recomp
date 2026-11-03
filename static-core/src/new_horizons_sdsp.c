#include "new_horizons_sdsp.h"
#include "new_horizons_spc700_aot.h"

#include <limits.h>
#include <string.h>

/* Architectural S-DSP interpolation ROM. The canonical little-endian u16
 * byte stream hashes to 0acd5077942f6cc6676829bc1954a05aeaad51be716f62d9ef4e8e7c94685af2. */
static const uint16_t gaussian[512] = {
0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,
1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,1u,2u,2u,2u,2u,2u,
2u,2u,3u,3u,3u,3u,3u,4u,4u,4u,4u,4u,5u,5u,5u,5u,
6u,6u,6u,6u,7u,7u,7u,8u,8u,8u,9u,9u,9u,10u,10u,10u,
11u,11u,11u,12u,12u,13u,13u,14u,14u,15u,15u,15u,16u,16u,17u,17u,
18u,19u,19u,20u,20u,21u,21u,22u,23u,23u,24u,24u,25u,26u,27u,27u,
28u,29u,29u,30u,31u,32u,32u,33u,34u,35u,36u,36u,37u,38u,39u,40u,
41u,42u,43u,44u,45u,46u,47u,48u,49u,50u,51u,52u,53u,54u,55u,56u,
58u,59u,60u,61u,62u,64u,65u,66u,67u,69u,70u,71u,73u,74u,76u,77u,
78u,80u,81u,83u,84u,86u,87u,89u,90u,92u,94u,95u,97u,99u,100u,102u,
104u,106u,107u,109u,111u,113u,115u,117u,118u,120u,122u,124u,126u,128u,130u,132u,
134u,137u,139u,141u,143u,145u,147u,150u,152u,154u,156u,159u,161u,163u,166u,168u,
171u,173u,175u,178u,180u,183u,186u,188u,191u,193u,196u,199u,201u,204u,207u,210u,
212u,215u,218u,221u,224u,227u,230u,233u,236u,239u,242u,245u,248u,251u,254u,257u,
260u,263u,267u,270u,273u,276u,280u,283u,286u,290u,293u,297u,300u,304u,307u,311u,
314u,318u,321u,325u,328u,332u,336u,339u,343u,347u,351u,354u,358u,362u,366u,370u,
374u,378u,381u,385u,389u,393u,397u,401u,405u,410u,414u,418u,422u,426u,430u,434u,
439u,443u,447u,451u,456u,460u,464u,469u,473u,477u,482u,486u,491u,495u,499u,504u,
508u,513u,517u,522u,527u,531u,536u,540u,545u,550u,554u,559u,563u,568u,573u,577u,
582u,587u,592u,596u,601u,606u,611u,615u,620u,625u,630u,635u,640u,644u,649u,654u,
659u,664u,669u,674u,678u,683u,688u,693u,698u,703u,708u,713u,718u,723u,728u,732u,
737u,742u,747u,752u,757u,762u,767u,772u,777u,782u,787u,792u,797u,802u,806u,811u,
816u,821u,826u,831u,836u,841u,846u,851u,855u,860u,865u,870u,875u,880u,884u,889u,
894u,899u,904u,908u,913u,918u,923u,927u,932u,937u,941u,946u,951u,955u,960u,965u,
969u,974u,978u,983u,988u,992u,997u,1001u,1005u,1010u,1014u,1019u,1023u,1027u,1032u,1036u,
1040u,1045u,1049u,1053u,1057u,1061u,1066u,1070u,1074u,1078u,1082u,1086u,1090u,1094u,1098u,1102u,
1106u,1109u,1113u,1117u,1121u,1125u,1128u,1132u,1136u,1139u,1143u,1146u,1150u,1153u,1157u,1160u,
1164u,1167u,1170u,1174u,1177u,1180u,1183u,1186u,1190u,1193u,1196u,1199u,1202u,1205u,1207u,1210u,
1213u,1216u,1219u,1221u,1224u,1227u,1229u,1232u,1234u,1237u,1239u,1241u,1244u,1246u,1248u,1251u,
1253u,1255u,1257u,1259u,1261u,1263u,1265u,1267u,1269u,1270u,1272u,1274u,1275u,1277u,1279u,1280u,
1282u,1283u,1284u,1286u,1287u,1288u,1290u,1291u,1292u,1293u,1294u,1295u,1296u,1297u,1297u,1298u,
1299u,1300u,1300u,1301u,1302u,1302u,1303u,1303u,1303u,1304u,1304u,1304u,1304u,1304u,1305u,1305u
};

static unsigned bit_known(const uint8_t *map, uint16_t address) {
    return map != NULL && (map[address >> 3u] &
           (uint8_t)(1u << (address & 7u))) != 0u;
}

static void set_known(uint8_t *map, uint16_t address, unsigned known) {
    uint8_t bit;
    if (map == NULL) return;
    bit = (uint8_t)(1u << (address & 7u));
    if (known != 0u) map[address >> 3u] |= bit;
    else map[address >> 3u] &= (uint8_t)~bit;
}

static NHBusStop stop(NHSdsp16 *d, NHBusStop reason, uint32_t address,
                      NHBusValue value) {
    if (d != NULL && d->bus != NULL && d->bus->failure.reason == NH_BUS_OK) {
        d->bus->failure.reason = reason;
        d->bus->failure.owner = NH_OWNER_SDSP_16;
        d->bus->failure.address = address;
        d->bus->failure.value = value.value;
        d->bus->failure.known_mask = value.known_mask;
    }
    return reason;
}

static int16_t clamp16(int32_t value) {
    if (value > INT16_MAX) return INT16_MAX;
    if (value < INT16_MIN) return INT16_MIN;
    return (int16_t)value;
}

static int32_t arithmetic_shift(int32_t value, unsigned count) {
    int64_t magnitude;
    if (count == 0u) return value;
    if (value >= 0) return value >> count;
    magnitude = -(int64_t)value;
    return (int32_t)-((magnitude + (((int64_t)1 << count) - 1)) >> count);
}

static int16_t clamp_even(int32_t value) {
    return (int16_t)((uint16_t)clamp16(value) & UINT16_C(0xFFFE));
}

static uint8_t reg(const NHSdsp16 *d, unsigned address) {
    return d->registers[address & 0x7Fu];
}

static void publish_reg(NHSdsp16 *d, unsigned address, uint8_t value,
                        unsigned known) {
    address &= 0x7Fu;
    d->registers[address] = value;
    set_known(d->register_known, (uint16_t)address, known);
}

static uint8_t aram_read(NHSdsp16 *d, uint16_t address, uint8_t *known) {
    uint8_t k = (uint8_t)bit_known(d->aram_known, address);
    ++d->aram_reads;
    if (known != NULL) *known = k;
    return k != 0u && d->aram != NULL ? d->aram[address] : 0u;
}

static NHBusStop aram_write(NHSdsp16 *d, uint16_t address, uint8_t value,
                            uint8_t known) {
    if (nh_spc700_aot_code_byte(address))
        return stop(d, NH_BUS_BAD_STATIC_GUARD, address,
                    (NHBusValue){value, known != 0u ? 0xFFu : 0u});
    if (d->aram != NULL) d->aram[address] = value;
    set_known(d->aram_known, address, known);
    ++d->aram_writes;
    return NH_BUS_OK;
}

static unsigned rate_pulse(const NHSdsp16 *d, unsigned rate) {
    static const uint16_t period[32] = {
        0u,2048u,1536u,1280u,1024u,768u,640u,512u,
        384u,320u,256u,192u,160u,128u,96u,80u,
        64u,48u,40u,32u,24u,20u,16u,12u,10u,8u,6u,5u,4u,3u,2u,1u
    };
    static const uint16_t offset[32] = {
        0u,0u,1040u,536u,0u,1040u,536u,0u,
        1040u,536u,0u,1040u,536u,0u,1040u,536u,
        0u,1040u,536u,0u,1040u,536u,0u,1040u,
        536u,0u,1040u,536u,0u,1040u,0u,0u
    };
    rate &= 31u;
    return rate != 0u &&
           (uint16_t)(d->rate_counter + offset[rate]) % period[rate] == 0u;
}

static int16_t interpolate(const NHSdspVoice16 *v, uint8_t *known) {
    const unsigned fraction = (v->interpolation >> 4u) & 0xFFu;
    const unsigned base = (v->decode_position + (v->interpolation >> 12u)) % 12u;
    const unsigned sample_index[4] = {base,(base+1u)%12u,(base+2u)%12u,(base+3u)%12u};
    const unsigned coefficient[4] = {255u-fraction,511u-fraction,256u+fraction,fraction};
    int32_t sum = 0;
    uint8_t k = v->interpolation_known;
    unsigned i;
    for (i = 0u; i != 4u; ++i) {
        uint16_t weight = gaussian[coefficient[i]];
        if (weight != 0u && v->decoded_known[sample_index[i]] == 0u) k = 0u;
        sum += arithmetic_shift((int32_t)weight * v->decoded[sample_index[i]], 11u);
        if (i == 2u) sum = (int16_t)sum;
    }
    if (known != NULL) *known = k;
    return clamp_even(sum);
}

static void decode_group(NHSdsp16 *d, NHSdspVoice16 *v) {
    uint8_t following_known = 0u;
    uint8_t following = aram_read(d,
        (uint16_t)(v->brr_address + v->brr_offset + 1u), &following_known);
    uint8_t packed[2] = {d->brr_data, following};
    uint8_t all_known = (uint8_t)(v->brr_address_known &&
        d->brr_header_known && d->brr_data_known && following_known);
    int32_t older = v->decoded[v->decode_position > 1u ?
        v->decode_position - 2u : 10u] / 2;
    int32_t newer = v->decoded[v->decode_position != 0u ?
        v->decode_position - 1u : 11u] / 2;
    uint8_t older_known = v->decoded_known[v->decode_position > 1u ?
        v->decode_position - 2u : 10u];
    uint8_t newer_known = v->decoded_known[v->decode_position != 0u ?
        v->decode_position - 1u : 11u];
    const unsigned shift = d->brr_header >> 4u;
    const unsigned filter = (d->brr_header >> 2u) & 3u;
    unsigned i;
    for (i = 0u; i != 4u; ++i) {
        const uint8_t nibble = (uint8_t)((packed[i >> 1u] >>
            ((i & 1u) != 0u ? 0u : 4u)) & 15u);
        const int32_t signed_nibble = nibble < 8u ? nibble : (int32_t)nibble - 16;
        int32_t decoded = shift <= 12u ?
            signed_nibble * (int32_t)(1u << shift) / 2 :
            (signed_nibble < 0 ? -2048 : 0);
        uint8_t k = all_known;
        if (filter == 1u) {
            decoded += newer + arithmetic_shift(-newer, 4u);
            k &= newer_known;
        } else if (filter == 2u) {
            decoded += newer * 2 + arithmetic_shift(-(newer * 3), 5u) -
                       older + arithmetic_shift(older, 4u);
            k &= (uint8_t)(newer_known && older_known);
        } else if (filter == 3u) {
            decoded += newer * 2 + arithmetic_shift(-(newer * 13), 6u) -
                       older + arithmetic_shift(older * 3, 4u);
            k &= (uint8_t)(newer_known && older_known);
        }
        older = newer;
        older_known = newer_known;
        newer = clamp16(decoded);
        newer_known = k;
        v->decoded[(v->decode_position + i) % 12u] = (int16_t)(newer * 2);
        v->decoded_known[(v->decode_position + i) % 12u] = k;
    }
    v->decode_position = (uint8_t)((v->decode_position + 4u) % 12u);
}

static void update_envelope(NHSdsp16 *d, NHSdspVoice16 *v, unsigned n) {
    const unsigned base = n << 4u;
    int32_t next = v->envelope;
    unsigned rate = 0u;
    if (v->envelope_mode == NH_SDSP16_RELEASE) {
        v->envelope = next > 8 ? next - 8 : 0;
        return;
    }
    if ((d->adsr1_latch & 0x80u) != 0u) {
        uint8_t adsr2 = reg(d, base + 6u);
        if (v->envelope_mode == NH_SDSP16_ATTACK) {
            rate = ((d->adsr1_latch & 15u) << 1u) | 1u;
            next += rate == 31u ? 1024 : 32;
        } else {
            next -= ((next - 1) >> 8u) + 1;
            if (v->envelope_mode == NH_SDSP16_DECAY) {
                rate = ((d->adsr1_latch >> 3u) & 14u) | 16u;
                if ((next >> 8u) == (adsr2 >> 5u))
                    v->envelope_mode = NH_SDSP16_SUSTAIN;
            } else rate = adsr2 & 31u;
        }
    } else {
        uint8_t gain = reg(d, base + 7u);
        if ((gain & 0x80u) == 0u) {
            next = (int32_t)gain << 4u;
            rate = 31u;
        } else {
            rate = gain & 31u;
            switch (gain & 0x60u) {
                case 0x00u: next -= 32; break;
                case 0x20u: next -= ((next - 1) >> 8u) + 1; break;
                case 0x40u: next += 32; break;
                default: next += v->pending_envelope < 0x600 ? 32 : 8; break;
            }
        }
    }
    v->pending_envelope = next;
    if (next < 0) next = 0;
    if (next > 0x7FF) {
        next = 0x7FF;
        if (v->envelope_mode == NH_SDSP16_ATTACK)
            v->envelope_mode = NH_SDSP16_DECAY;
    }
    if (rate_pulse(d, rate) != 0u) v->envelope = next;
}

static void mix_voice(NHSdsp16 *d, unsigned n, unsigned channel) {
    const int8_t volume = (int8_t)reg(d, (n << 4u) + channel);
    const int32_t contribution = arithmetic_shift(
        d->voice_output_latch * volume, 7u);
    const uint8_t known = (uint8_t)(volume == 0 || d->voice_output_known);
    d->dry[channel] = clamp16(d->dry[channel] + contribution);
    d->dry_known[channel] &= known;
    if ((d->eon_latch & (uint8_t)(1u << n)) != 0u) {
        d->echo_input[channel] = clamp16(d->echo_input[channel] + contribution);
        d->echo_input_known[channel] &= known;
    }
}

static void voice_phase1(NHSdsp16 *d, unsigned n) {
    d->directory_address = (uint16_t)(((uint16_t)d->dir_latch << 8u) +
        (uint16_t)d->srcn_latch * 4u);
    d->srcn_latch = reg(d, (n << 4u) + 4u);
}

static void voice_phase2(NHSdsp16 *d, unsigned n) {
    NHSdspVoice16 *v = &d->voice[n];
    uint16_t address = d->directory_address;
    uint8_t lo_known, hi_known, lo, hi;
    if (v->key_delay == 0u) address = (uint16_t)(address + 2u);
    lo = aram_read(d, address, &lo_known);
    hi = aram_read(d, (uint16_t)(address + 1u), &hi_known);
    d->next_brr_address = (uint16_t)(lo | ((uint16_t)hi << 8u));
    d->next_brr_known = (uint8_t)(lo_known && hi_known);
    d->adsr1_latch = reg(d, (n << 4u) + 5u);
    d->pitch_latch = reg(d, (n << 4u) + 2u);
    d->pitch_latch_known = 1u;
}

static void voice_phase3a(NHSdsp16 *d, unsigned n) {
    d->pitch_latch |= (uint16_t)((reg(d, (n << 4u) + 3u) & 0x3Fu) << 8u);
}

static void voice_phase3b(NHSdsp16 *d, unsigned n) {
    NHSdspVoice16 *v = &d->voice[n];
    d->brr_header = aram_read(d, v->brr_address, &d->brr_header_known);
    d->brr_data = aram_read(d, (uint16_t)(v->brr_address + v->brr_offset),
                            &d->brr_data_known);
    d->brr_header_known &= v->brr_address_known;
    d->brr_data_known &= v->brr_address_known;
}

static void voice_phase3c(NHSdsp16 *d, unsigned n) {
    NHSdspVoice16 *v = &d->voice[n];
    const uint8_t bit = (uint8_t)(1u << n);
    uint8_t sample_known;
    int32_t sample;
    if (n != 0u && (d->pmon_latch & bit) != 0u) {
        d->pitch_latch = (uint16_t)((d->pitch_latch +
            arithmetic_shift(arithmetic_shift(d->voice_output_latch, 5u) *
                             d->pitch_latch, 10u)) & 0x7FFFu);
        d->pitch_latch_known &= d->voice_output_known;
    }
    if (v->key_delay != 0u) {
        if (v->key_delay == 5u) {
            v->brr_address = d->next_brr_address;
            v->brr_address_known = d->next_brr_known;
            v->brr_offset = 1u;
            v->decode_position = 0u;
            d->brr_header = 0u;
            d->brr_header_known = 1u;
            v->active = 1u;
        }
        v->envelope = 0;
        v->pending_envelope = 0;
        --v->key_delay;
        v->interpolation = (v->key_delay & 3u) != 0u ? 0x4000u : 0u;
        v->interpolation_known = 1u;
        d->pitch_latch = 0u;
    }
    sample = interpolate(v, &sample_known);
    if ((d->non_latch & bit) != 0u) {
        sample = (int16_t)(d->noise_lfsr * 2u);
        sample_known = 1u;
    }
    d->voice_output_latch = arithmetic_shift(sample * v->envelope, 11u) & ~1;
    d->voice_output_known = (uint8_t)(v->envelope == 0 || sample_known);
    v->output = (int16_t)d->voice_output_latch;
    v->output_known = d->voice_output_known;
    v->envx = (uint8_t)(v->envelope >> 4u);
    if ((reg(d, 0x6Cu) & 0x80u) != 0u ||
        (d->brr_header_known != 0u && (d->brr_header & 3u) == 1u)) {
        v->envelope_mode = NH_SDSP16_RELEASE;
        v->envelope = 0;
    }
    if (d->alternating_sample != 0u) {
        if ((d->koff_latch & bit) != 0u) v->envelope_mode = NH_SDSP16_RELEASE;
        if ((d->kon_latch & bit) != 0u) {
            v->key_delay = 5u;
            v->envelope_mode = NH_SDSP16_ATTACK;
        }
    }
    if (v->key_delay == 0u) update_envelope(d, v, n);
}

static void voice_phase3(NHSdsp16 *d, unsigned n) {
    voice_phase3a(d, n);
    voice_phase3b(d, n);
    voice_phase3c(d, n);
}

static void voice_phase4(NHSdsp16 *d, unsigned n) {
    NHSdspVoice16 *v = &d->voice[n];
    d->end_flags = 0u;
    d->end_flags_known = 1u;
    if (v->active != 0u && v->interpolation >= 0x4000u) {
        decode_group(d, v);
        if (v->brr_offset >= 7u) {
            if (d->brr_header_known != 0u && (d->brr_header & 1u) != 0u) {
                v->brr_address = d->next_brr_address;
                v->brr_address_known = d->next_brr_known;
                d->end_flags = (uint8_t)(1u << n);
            } else {
                v->brr_address = (uint16_t)(v->brr_address + 9u);
                if (d->brr_header_known == 0u) {
                    v->brr_address_known = 0u;
                    d->end_flags_known = 0u;
                }
            }
            v->brr_offset = 1u;
        } else v->brr_offset = (uint16_t)(v->brr_offset + 2u);
    }
    v->interpolation = (v->interpolation & 0x3FFFu) + d->pitch_latch;
    v->interpolation_known &= d->pitch_latch_known;
    if (v->interpolation > 0x7FFFu) v->interpolation = 0x7FFFu;
    mix_voice(d, n, 0u);
}

static void voice_phase5(NHSdsp16 *d, unsigned n) {
    NHSdspVoice16 *v = &d->voice[n];
    const uint8_t bit = (uint8_t)(1u << n);
    mix_voice(d, n, 1u);
    d->endx_latch = (uint8_t)(reg(d, 0x7Cu) | d->end_flags);
    d->endx_latch_known = (uint8_t)(bit_known(d->register_known, 0x7Cu) &&
                                    d->end_flags_known);
    if (v->key_delay == 5u) d->endx_latch &= (uint8_t)~bit;
}

static void voice_phase6(NHSdsp16 *d) {
    d->outx_latch = (uint8_t)((uint32_t)d->voice_output_latch >> 8u);
    d->outx_latch_known = d->voice_output_known;
}

static void voice_phase7(NHSdsp16 *d, unsigned n) {
    publish_reg(d, 0x7Cu, d->endx_latch, d->endx_latch_known);
    d->envx_latch = d->voice[n].envx;
}

static void voice_phase8(NHSdsp16 *d, unsigned n) {
    publish_reg(d, (n << 4u) + 9u, d->outx_latch, d->outx_latch_known);
}

static void voice_phase9(NHSdsp16 *d, unsigned n) {
    publish_reg(d, (n << 4u) + 8u, d->envx_latch, 1u);
}

static int32_t fir_product(NHSdsp16 *d, unsigned tap, unsigned channel,
                           uint8_t *known) {
    const unsigned at = (d->echo_history_index + tap + 1u) & 7u;
    const int8_t coefficient = (int8_t)reg(d, 0x0Fu + tap * 0x10u);
    if (coefficient != 0 && d->echo_history_known[at][channel] == 0u)
        *known = 0u;
    return arithmetic_shift((int32_t)d->echo_history[at][channel] *
                            coefficient, 6u);
}

static void echo_phase22(NHSdsp16 *d) {
    uint8_t lo_known, hi_known, lo, hi;
    d->echo_history_index = (uint8_t)((d->echo_history_index + 1u) & 7u);
    d->echo_pointer = (uint16_t)(((uint16_t)d->esa_latch << 8u) + d->echo_offset);
    lo = aram_read(d, d->echo_pointer, &lo_known);
    hi = aram_read(d, (uint16_t)(d->echo_pointer + 1u), &hi_known);
    d->echo_history[d->echo_history_index][0] =
        (int16_t)arithmetic_shift((int16_t)(lo | ((uint16_t)hi << 8u)), 1u);
    d->echo_history_known[d->echo_history_index][0] =
        (uint8_t)(lo_known && hi_known);
    d->fir_known[0] = d->fir_known[1] = 1u;
    d->fir[0] = fir_product(d, 0u, 0u, &d->fir_known[0]);
    d->fir[1] = fir_product(d, 0u, 1u, &d->fir_known[1]);
}

static void echo_phase23(NHSdsp16 *d) {
    uint8_t lo_known, hi_known, lo, hi;
    lo = aram_read(d, (uint16_t)(d->echo_pointer + 2u), &lo_known);
    hi = aram_read(d, (uint16_t)(d->echo_pointer + 3u), &hi_known);
    d->echo_history[d->echo_history_index][1] =
        (int16_t)arithmetic_shift((int16_t)(lo | ((uint16_t)hi << 8u)), 1u);
    d->echo_history_known[d->echo_history_index][1] =
        (uint8_t)(lo_known && hi_known);
    d->fir[0] += fir_product(d, 1u, 0u, &d->fir_known[0]);
    d->fir[1] += fir_product(d, 1u, 1u, &d->fir_known[1]);
    d->fir[0] += fir_product(d, 2u, 0u, &d->fir_known[0]);
    d->fir[1] += fir_product(d, 2u, 1u, &d->fir_known[1]);
}

static void echo_taps(NHSdsp16 *d, unsigned first, unsigned last) {
    unsigned tap;
    for (tap = first; tap <= last; ++tap) {
        d->fir[0] += fir_product(d, tap, 0u, &d->fir_known[0]);
        d->fir[1] += fir_product(d, tap, 1u, &d->fir_known[1]);
    }
}

static void echo_phase25(NHSdsp16 *d) {
    unsigned channel;
    for (channel = 0u; channel != 2u; ++channel) {
        int16_t accumulated = (int16_t)(d->fir[channel] +
            fir_product(d, 6u, channel, &d->fir_known[channel]));
        int16_t final_tap = (int16_t)fir_product(d, 7u, channel,
            &d->fir_known[channel]);
        d->fir[channel] = clamp_even((int32_t)accumulated + final_tap);
    }
}

static NHBusStop pcm_push(NHSdsp16 *d, int16_t left, int16_t right,
                          uint8_t known) {
    uint16_t sample[2];
    unsigned channel, byte;
    if (d->pcm_count == NH_SDSP16_FIFO_FRAMES) {
        ++d->overflows;
        return stop(d, NH_BUS_MEMORY_FAILURE, 0x53445350u,
                    (NHBusValue){0u,0u});
    }
    d->pcm[d->pcm_write * 2u] = left;
    d->pcm[d->pcm_write * 2u + 1u] = right;
    d->pcm_known[d->pcm_write] = known;
    d->pcm_write = (d->pcm_write + 1u) % NH_SDSP16_FIFO_FRAMES;
    ++d->pcm_count;
    ++d->frames;
    if (known != 0u) ++d->known_frames; else ++d->unknown_frames;
    sample[0] = (uint16_t)left;
    sample[1] = (uint16_t)right;
    for (channel = 0u; channel != 2u; ++channel) {
        for (byte = 0u; byte != 2u; ++byte) {
            d->pcm_fnv1a64 ^= (uint8_t)(sample[channel] >> (byte * 8u));
            d->pcm_fnv1a64 *= UINT64_C(1099511628211);
        }
    }
    return NH_BUS_OK;
}

static void echo_phase26(NHSdsp16 *d) {
    const int8_t feedback = (int8_t)reg(d, 0x0Du);
    unsigned channel;
    for (channel = 0u; channel != 2u; ++channel) {
        d->echo_input[channel] = clamp_even(d->echo_input[channel] +
            arithmetic_shift(d->fir[channel] * feedback, 7u));
        d->echo_input_known[channel] &=
            (uint8_t)(feedback == 0 || d->fir_known[channel]);
    }
    {
        const int8_t master = (int8_t)reg(d, 0x0Cu);
        const int8_t echo_volume = (int8_t)reg(d, 0x2Cu);
        const uint8_t dry_known = (uint8_t)(master == 0 || d->dry_known[0]);
        const uint8_t wet_known = (uint8_t)(echo_volume == 0 || d->fir_known[0]);
        d->dry[0] = clamp16(arithmetic_shift(d->dry[0] * master, 7u) +
                            arithmetic_shift(d->fir[0] * echo_volume, 7u));
        d->dry_known[0] = (uint8_t)(dry_known && wet_known);
    }
}

static NHBusStop echo_phase27(NHSdsp16 *d) {
    const int8_t master = (int8_t)reg(d, 0x1Cu);
    const int8_t echo_volume = (int8_t)reg(d, 0x3Cu);
    uint8_t dry_known = (uint8_t)(master == 0 || d->dry_known[1]);
    uint8_t wet_known = (uint8_t)(echo_volume == 0 || d->fir_known[1]);
    uint8_t known;
    int16_t left, right;
    d->dry[1] = clamp16(arithmetic_shift(d->dry[1] * master, 7u) +
                        arithmetic_shift(d->fir[1] * echo_volume, 7u));
    d->dry_known[1] = (uint8_t)(dry_known && wet_known);
    if ((reg(d, 0x6Cu) & 0x40u) != 0u) {
        left = right = 0;
        known = 1u;
    } else {
        left = clamp16(d->dry[0]);
        right = clamp16(d->dry[1]);
        known = (uint8_t)(d->dry_known[0] && d->dry_known[1]);
    }
    d->dry[0] = d->dry[1] = 0;
    d->dry_known[0] = d->dry_known[1] = 1u;
    return pcm_push(d, left, right, known);
}

static NHBusStop echo_write_word(NHSdsp16 *d, uint16_t address, int32_t value,
                                 uint8_t known) {
    uint16_t high_address = (uint16_t)(address + 1u);
    uint16_t bits = (uint16_t)clamp_even(value);
    NHBusStop result;
    /* Preflight both bytes so a rejected echo word cannot partially mutate
     * the statically lowered S-SMP image. DSP echo is never an admitted
     * writer for the exact S-SMP self-modifying operand family. */
    if (nh_spc700_aot_code_byte(address))
        return stop(d, NH_BUS_BAD_STATIC_GUARD, address,
                    (NHBusValue){(uint8_t)bits,
                                 known != 0u ? 0xFFu : 0u});
    if (nh_spc700_aot_code_byte(high_address))
        return stop(d, NH_BUS_BAD_STATIC_GUARD, high_address,
                    (NHBusValue){(uint8_t)(bits >> 8u),
                                 known != 0u ? 0xFFu : 0u});
    result = aram_write(d, address, (uint8_t)bits, known);
    if (result != NH_BUS_OK) return result;
    return aram_write(d, high_address, (uint8_t)(bits >> 8u), known);
}

static NHBusStop echo_phase29(NHSdsp16 *d) {
    NHBusStop result = NH_BUS_OK;
    if (d->echo_offset == 0u)
        d->echo_length = (uint16_t)((reg(d, 0x7Du) & 15u) << 11u);
    d->echo_offset = (uint16_t)(d->echo_offset + 4u);
    if (d->echo_length == 0u || d->echo_offset >= d->echo_length)
        d->echo_offset = 0u;
    if (d->echo_writable != 0u)
        result = echo_write_word(d, d->echo_pointer, d->echo_input[0],
                                 d->echo_input_known[0]);
    if (result != NH_BUS_OK) return result;
    d->echo_input[0] = 0;
    d->echo_input_known[0] = 1u;
    d->esa_latch = reg(d, 0x6Du);
    d->echo_writable = (uint8_t)((reg(d, 0x6Cu) & 0x20u) == 0u);
    return NH_BUS_OK;
}

static NHBusStop echo_phase30(NHSdsp16 *d) {
    NHBusStop result = NH_BUS_OK;
    if (d->echo_writable != 0u)
        result = echo_write_word(d, (uint16_t)(d->echo_pointer + 2u),
                                 d->echo_input[1], d->echo_input_known[1]);
    if (result != NH_BUS_OK) return result;
    d->echo_input[1] = 0;
    d->echo_input_known[1] = 1u;
    return NH_BUS_OK;
}

NHBusStop nh_sdsp16_power_on(NHSdsp16 *d, NHBusRuntime *bus, uint8_t *aram,
                             uint8_t *aram_known) {
    unsigned n;
    if (d == NULL || bus == NULL || aram == NULL || aram_known == NULL)
        return NH_BUS_BAD_ARGUMENT;
    memset(d, 0, sizeof(*d));
    d->bus = bus;
    d->aram = aram;
    d->aram_known = aram_known;
    memset(d->register_known, 0xFF, sizeof(d->register_known));
    d->registers[0x6Cu] = 0xE0u;
    d->noise_lfsr = 0x4000u;
    d->alternating_sample = 1u;
    d->dry_known[0] = d->dry_known[1] = 1u;
    d->echo_input_known[0] = d->echo_input_known[1] = 1u;
    d->fir_known[0] = d->fir_known[1] = 1u;
    /* These reset-zero latches begin known. Their later voice phases own
     * knownness; echo phase 22 must not erase an unknown voice dependency. */
    d->end_flags_known = 1u;
    d->endx_latch_known = 1u;
    d->outx_latch_known = 1u;
    d->pcm_fnv1a64 = UINT64_C(14695981039346656037);
    for (n = 0u; n != NH_SDSP16_VOICES; ++n) {
        d->voice[n].envelope_mode = NH_SDSP16_RELEASE;
        d->voice[n].interpolation_known = 1u;
    }
    return NH_BUS_OK;
}

NHBusStop nh_sdsp16_read(NHSdsp16 *d, uint8_t address, NHBusValue *out) {
    if (d == NULL || d->bus == NULL || out == NULL) return NH_BUS_BAD_ARGUMENT;
    if (d->bus->failure.reason != NH_BUS_OK) return d->bus->failure.reason;
    address &= 0x7Fu;
    if (bit_known(d->register_known, address) == 0u)
        return stop(d, NH_BUS_UNKNOWN_BYTE, 0xF300u | address,
                    (NHBusValue){d->registers[address],0u});
    *out = (NHBusValue){d->registers[address],0xFFu};
    ++d->register_reads;
    return NH_BUS_OK;
}

NHBusStop nh_sdsp16_write(NHSdsp16 *d, uint8_t address, NHBusValue value) {
    if (d == NULL || d->bus == NULL) return NH_BUS_BAD_ARGUMENT;
    if (d->bus->failure.reason != NH_BUS_OK) return d->bus->failure.reason;
    if (value.known_mask != 0xFFu)
        return stop(d, NH_BUS_UNKNOWN_BYTE, 0xF300u | (address & 0x7Fu), value);
    address &= 0x7Fu;
    publish_reg(d, address, value.value, 1u);
    ++d->register_writes;
    if ((address & 15u) == 8u) d->envx_latch = value.value;
    if ((address & 15u) == 9u) {
        d->outx_latch = value.value;
        d->outx_latch_known = 1u;
    }
    if (address == 0x4Cu) d->kon_pending = value.value;
    if (address == 0x7Cu) {
        d->endx_latch = 0u;
        d->endx_latch_known = 1u;
        publish_reg(d, 0x7Cu, 0u, 1u);
    }
    return NH_BUS_OK;
}

NHBusStop nh_sdsp16_step(NHSdsp16 *d) {
    NHBusStop result = NH_BUS_OK;
    uint8_t phase;
    if (d == NULL || d->bus == NULL) return NH_BUS_BAD_ARGUMENT;
    if (d->bus->failure.reason != NH_BUS_OK) return d->bus->failure.reason;
    phase = d->phase;
    switch (phase) {
        case 0u: voice_phase5(d,0u); voice_phase2(d,1u); break;
        case 1u: voice_phase6(d); voice_phase3(d,1u); break;
        case 2u: voice_phase7(d,0u); voice_phase4(d,1u); voice_phase1(d,3u); break;
        case 3u: voice_phase8(d,0u); voice_phase5(d,1u); voice_phase2(d,2u); break;
        case 4u: voice_phase9(d,0u); voice_phase6(d); voice_phase3(d,2u); break;
        case 5u: voice_phase7(d,1u); voice_phase4(d,2u); voice_phase1(d,4u); break;
        case 6u: voice_phase8(d,1u); voice_phase5(d,2u); voice_phase2(d,3u); break;
        case 7u: voice_phase9(d,1u); voice_phase6(d); voice_phase3(d,3u); break;
        case 8u: voice_phase7(d,2u); voice_phase4(d,3u); voice_phase1(d,5u); break;
        case 9u: voice_phase8(d,2u); voice_phase5(d,3u); voice_phase2(d,4u); break;
        case 10u: voice_phase9(d,2u); voice_phase6(d); voice_phase3(d,4u); break;
        case 11u: voice_phase7(d,3u); voice_phase4(d,4u); voice_phase1(d,6u); break;
        case 12u: voice_phase8(d,3u); voice_phase5(d,4u); voice_phase2(d,5u); break;
        case 13u: voice_phase9(d,3u); voice_phase6(d); voice_phase3(d,5u); break;
        case 14u: voice_phase7(d,4u); voice_phase4(d,5u); voice_phase1(d,7u); break;
        case 15u: voice_phase8(d,4u); voice_phase5(d,5u); voice_phase2(d,6u); break;
        case 16u: voice_phase9(d,4u); voice_phase6(d); voice_phase3(d,6u); break;
        case 17u: voice_phase1(d,0u); voice_phase7(d,5u); voice_phase4(d,6u); break;
        case 18u: voice_phase8(d,5u); voice_phase5(d,6u); voice_phase2(d,7u); break;
        case 19u: voice_phase9(d,5u); voice_phase6(d); voice_phase3(d,7u); break;
        case 20u: voice_phase1(d,1u); voice_phase7(d,6u); voice_phase4(d,7u); break;
        case 21u: voice_phase8(d,6u); voice_phase5(d,7u); voice_phase2(d,0u); break;
        case 22u: voice_phase3a(d,0u); voice_phase9(d,6u); voice_phase6(d); echo_phase22(d); break;
        case 23u: voice_phase7(d,7u); echo_phase23(d); break;
        case 24u: voice_phase8(d,7u); echo_taps(d,3u,5u); break;
        case 25u: voice_phase3b(d,0u); voice_phase9(d,7u); echo_phase25(d); break;
        case 26u: echo_phase26(d); break;
        case 27u:
            d->pmon_latch = (uint8_t)(reg(d,0x2Du) & 0xFEu);
            result = echo_phase27(d);
            break;
        case 28u:
            d->dir_latch = reg(d,0x5Du);
            d->non_latch = reg(d,0x3Du);
            d->eon_latch = reg(d,0x4Du);
            d->echo_writable = (uint8_t)((reg(d,0x6Cu) & 0x20u) == 0u);
            break;
        case 29u:
            d->alternating_sample ^= 1u;
            if (d->alternating_sample != 0u)
                d->kon_pending &= (uint8_t)~d->kon_latch;
            result = echo_phase29(d);
            break;
        case 30u:
            if (d->alternating_sample != 0u) {
                d->kon_latch = d->kon_pending;
                d->koff_latch = reg(d,0x5Cu);
            }
            d->rate_counter = d->rate_counter != 0u ?
                (uint16_t)(d->rate_counter - 1u) : 0x77FFu;
            if (rate_pulse(d, reg(d,0x6Cu) & 31u) != 0u) {
                uint16_t feedback = (uint16_t)(((d->noise_lfsr << 14u) ^
                    (d->noise_lfsr << 13u)) & 0x4000u);
                d->noise_lfsr = (uint16_t)(feedback ^ (d->noise_lfsr >> 1u));
            }
            voice_phase3c(d,0u);
            result = echo_phase30(d);
            break;
        case 31u: voice_phase4(d,0u); voice_phase1(d,2u); break;
        default:
            return stop(d, NH_BUS_BAD_STATIC_GUARD, phase,
                        (NHBusValue){phase,0xFFu});
    }
    if (result != NH_BUS_OK) return result;
    d->phase = (uint8_t)((phase + 1u) & 31u);
    ++d->phase_steps;
    return NH_BUS_OK;
}

size_t nh_sdsp16_pcm_available(const NHSdsp16 *d) {
    return d != NULL ? d->pcm_count : 0u;
}

size_t nh_sdsp16_pcm_drain(NHSdsp16 *d, int16_t *stereo, uint8_t *known,
                           size_t capacity) {
    size_t count = 0u;
    if (d == NULL || stereo == NULL) return 0u;
    while (count != capacity && d->pcm_count != 0u) {
        stereo[count * 2u] = d->pcm[d->pcm_read * 2u];
        stereo[count * 2u + 1u] = d->pcm[d->pcm_read * 2u + 1u];
        if (known != NULL) known[count] = d->pcm_known[d->pcm_read];
        d->pcm_read = (d->pcm_read + 1u) % NH_SDSP16_FIFO_FRAMES;
        --d->pcm_count;
        ++count;
    }
    return count;
}
