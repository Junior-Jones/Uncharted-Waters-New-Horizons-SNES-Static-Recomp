#ifndef NEW_HORIZONS_AUDIO_RESAMPLER_H
#define NEW_HORIZONS_AUDIO_RESAMPLER_H

#include <stddef.h>
#include <stdint.h>

typedef enum NewHorizonsAudioResamplerMode {
    NEW_HORIZONS_AUDIO_RESAMPLER_HERMITE = 0,
    NEW_HORIZONS_AUDIO_RESAMPLER_LINEAR = 1,
    NEW_HORIZONS_AUDIO_RESAMPLER_NEAREST = 2
} NewHorizonsAudioResamplerMode;

#define NEW_HORIZONS_AUDIO_RESAMPLER_PENDING_FRAMES 16384u

typedef struct NewHorizonsAudioHermiteResampler {
    double previous_left[4];
    double previous_right[4];
    double rate_ratio;
    double fraction;
    int16_t last_left;
    int16_t last_right;
    int mode;
    int16_t pending_samples[NEW_HORIZONS_AUDIO_RESAMPLER_PENDING_FRAMES * 2u];
    size_t pending_frames;
} NewHorizonsAudioHermiteResampler;

void new_horizons_audio_resampler_reset(NewHorizonsAudioHermiteResampler *resampler);
void new_horizons_audio_resampler_set_rates(NewHorizonsAudioHermiteResampler *resampler,
                                      double source_rate,
                                      double destination_rate);
void new_horizons_audio_resampler_set_mode(NewHorizonsAudioHermiteResampler *resampler,
                                     int mode);

/* The caller must supply enough output storage.  For the Uncharted Waters: New Horizons
   32,000 Hz to 48,000 Hz path, twice input_frames is always sufficient. */
size_t new_horizons_audio_resampler_process(NewHorizonsAudioHermiteResampler *resampler,
                                      const int16_t *input,
                                      size_t input_frames,
                                      int16_t *output,
                                      size_t output_capacity_frames);

#endif
