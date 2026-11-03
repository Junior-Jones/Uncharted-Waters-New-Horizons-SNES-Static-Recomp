#ifndef NEW_HORIZONS_SDSP_H
#define NEW_HORIZONS_SDSP_H

#include "new_horizons_bus_runtime.h"
#include <stddef.h>
#include <stdint.h>

enum {
    NH_SDSP16_REGISTERS = 128u,
    NH_SDSP16_VOICES = 8u,
    NH_SDSP16_PHASES = 32u,
    NH_SDSP16_NATIVE_RATE_HZ = 32000u,
    NH_SDSP16_FIFO_FRAMES = 8192u
};

typedef enum NHSdspEnvelope16 {
    NH_SDSP16_RELEASE = 0,
    NH_SDSP16_ATTACK,
    NH_SDSP16_DECAY,
    NH_SDSP16_SUSTAIN
} NHSdspEnvelope16;

typedef struct NHSdspVoice16 {
    int16_t decoded[12];
    uint8_t decoded_known[12];
    uint16_t brr_address;
    uint16_t brr_offset;
    uint8_t brr_address_known;
    uint32_t interpolation;
    uint8_t interpolation_known;
    int32_t envelope;
    int32_t pending_envelope;
    int16_t output;
    uint8_t output_known;
    uint8_t decode_position;
    uint8_t key_delay;
    uint8_t envelope_mode;
    uint8_t active;
    uint8_t envx;
} NHSdspVoice16;

typedef struct NHSdsp16 {
    NHBusRuntime *bus;
    uint8_t *aram;
    uint8_t *aram_known;
    uint8_t registers[NH_SDSP16_REGISTERS];
    uint8_t register_known[NH_SDSP16_REGISTERS / 8u];
    NHSdspVoice16 voice[NH_SDSP16_VOICES];

    uint8_t phase;
    uint8_t alternating_sample;
    uint8_t kon_latch;
    uint8_t kon_pending;
    uint8_t koff_latch;
    uint8_t pmon_latch;
    uint8_t non_latch;
    uint8_t eon_latch;
    uint8_t dir_latch;
    uint8_t esa_latch;
    uint8_t echo_writable;
    uint8_t srcn_latch;
    uint8_t adsr1_latch;
    uint8_t brr_header;
    uint8_t brr_header_known;
    uint8_t brr_data;
    uint8_t brr_data_known;
    uint8_t end_flags;
    uint8_t end_flags_known;
    uint8_t endx_latch;
    uint8_t endx_latch_known;
    uint8_t envx_latch;
    uint8_t outx_latch;
    uint8_t outx_latch_known;

    uint16_t rate_counter;
    uint16_t noise_lfsr;
    uint16_t directory_address;
    uint16_t next_brr_address;
    uint8_t next_brr_known;
    uint16_t pitch_latch;
    uint8_t pitch_latch_known;
    int32_t voice_output_latch;
    uint8_t voice_output_known;

    int32_t dry[2];
    uint8_t dry_known[2];
    int32_t echo_input[2];
    uint8_t echo_input_known[2];
    int16_t echo_history[8][2];
    uint8_t echo_history_known[8][2];
    uint8_t echo_history_index;
    int32_t fir[2];
    uint8_t fir_known[2];
    uint16_t echo_pointer;
    uint16_t echo_offset;
    uint16_t echo_length;

    int16_t pcm[NH_SDSP16_FIFO_FRAMES * 2u];
    uint8_t pcm_known[NH_SDSP16_FIFO_FRAMES];
    size_t pcm_read;
    size_t pcm_write;
    size_t pcm_count;
    uint64_t phase_steps;
    uint64_t frames;
    uint64_t known_frames;
    uint64_t unknown_frames;
    uint64_t overflows;
    uint64_t register_reads;
    uint64_t register_writes;
    uint64_t aram_reads;
    uint64_t aram_writes;
    uint64_t pcm_fnv1a64;
} NHSdsp16;

NHBusStop nh_sdsp16_power_on(NHSdsp16 *, NHBusRuntime *, uint8_t *aram,
                             uint8_t *aram_known);
NHBusStop nh_sdsp16_read(NHSdsp16 *, uint8_t address, NHBusValue *);
NHBusStop nh_sdsp16_write(NHSdsp16 *, uint8_t address, NHBusValue);
NHBusStop nh_sdsp16_step(NHSdsp16 *);
size_t nh_sdsp16_pcm_available(const NHSdsp16 *);
size_t nh_sdsp16_pcm_drain(NHSdsp16 *, int16_t *stereo, uint8_t *known,
                           size_t capacity);

#endif
