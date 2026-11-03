#ifndef NEW_HORIZONS_STATIC_RECOMP_FRONTEND_H
#define NEW_HORIZONS_STATIC_RECOMP_FRONTEND_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NEW_HORIZONS_RECOMP_ROM_SIZE 2097152u
#define NEW_HORIZONS_RECOMP_FRAME_WIDTH 256u
#define NEW_HORIZONS_RECOMP_FRAME_HEIGHT 239u
#define NEW_HORIZONS_RECOMP_WIDE_WIDTH 512u
#define NEW_HORIZONS_RECOMP_WIDE_HEIGHT 288u
#define NEW_HORIZONS_RECOMP_AUDIO_SAMPLE_RATE 32000u
#define NEW_HORIZONS_RECOMP_HOST_AUDIO_SAMPLE_RATE 32000u
#define NEW_HORIZONS_RECOMP_AUDIO_CHANNELS 2u
#define NEW_HORIZONS_RECOMP_PRESENTATION_FPS_NUMERATOR 3579545u
#define NEW_HORIZONS_RECOMP_PRESENTATION_FPS_DENOMINATOR 59561u
#define NEW_HORIZONS_RECOMP_SRAM_FILE_SIZE 36944u

enum NewHorizonsRecompInput {
    NEW_HORIZONS_INPUT_B = 0x8000u, NEW_HORIZONS_INPUT_Y = 0x4000u,
    NEW_HORIZONS_INPUT_SELECT = 0x2000u, NEW_HORIZONS_INPUT_START = 0x1000u,
    NEW_HORIZONS_INPUT_UP = 0x0800u, NEW_HORIZONS_INPUT_DOWN = 0x0400u,
    NEW_HORIZONS_INPUT_LEFT = 0x0200u, NEW_HORIZONS_INPUT_RIGHT = 0x0100u,
    NEW_HORIZONS_INPUT_A = 0x0080u, NEW_HORIZONS_INPUT_X = 0x0040u,
    NEW_HORIZONS_INPUT_L = 0x0020u, NEW_HORIZONS_INPUT_R = 0x0010u
};

typedef struct NewHorizonsRecomp NewHorizonsRecomp;
typedef void (*NewHorizonsRecompAudioProgressCallback)(
    NewHorizonsRecomp *instance, void *opaque);
typedef struct NewHorizonsRecompFrameResult {
    uint8_t route_continued;
    uint8_t frame_rendered;
    uint16_t input_mask;
    uint32_t start_frame;
    uint32_t end_frame;
    char renderer_error[192];
} NewHorizonsRecompFrameResult;

int new_horizons_recomp_create(NewHorizonsRecomp **out_instance,
                         const uint8_t *rom, size_t rom_size,
                         char *error, size_t error_capacity);
void new_horizons_recomp_destroy(NewHorizonsRecomp *instance);
int new_horizons_recomp_reset(NewHorizonsRecomp *instance,
                        char *error, size_t error_capacity);
int new_horizons_recomp_advance(NewHorizonsRecomp *instance, uint16_t input_mask,
                          uint32_t frame_count,
                          NewHorizonsRecompFrameResult *result);
int new_horizons_recomp_advance_streamed(
    NewHorizonsRecomp *instance, uint16_t input_mask, uint32_t frame_count,
    NewHorizonsRecompAudioProgressCallback audio_progress, void *opaque,
    NewHorizonsRecompFrameResult *result);
int new_horizons_recomp_advance_headless(NewHorizonsRecomp *instance,
                                   uint16_t input_mask,
                                   uint32_t frame_count,
                                   NewHorizonsRecompFrameResult *result);
const uint32_t *new_horizons_recomp_frame_bgra(const NewHorizonsRecomp *instance);
uint32_t new_horizons_recomp_frame_width(const NewHorizonsRecomp *instance);
uint32_t new_horizons_recomp_frame_height(const NewHorizonsRecomp *instance);
uint32_t new_horizons_recomp_current_frame(const NewHorizonsRecomp *instance);
uint64_t new_horizons_recomp_instruction_count(const NewHorizonsRecomp *instance);
int new_horizons_recomp_failed(const NewHorizonsRecomp *instance);
const char *new_horizons_recomp_last_error(const NewHorizonsRecomp *instance);
size_t new_horizons_recomp_audio_available(const NewHorizonsRecomp *instance);
size_t new_horizons_recomp_audio_read(NewHorizonsRecomp *instance,
                                int16_t *interleaved_stereo,
                                size_t frame_capacity);
size_t new_horizons_recomp_audio_discard(NewHorizonsRecomp *instance);
int new_horizons_recomp_audio_overflowed(const NewHorizonsRecomp *instance);
uint64_t new_horizons_recomp_audio_dropped_frames(
    const NewHorizonsRecomp *instance);
void new_horizons_recomp_audio_clear_overflow(NewHorizonsRecomp *instance);

/* Requested setting; actual scene geometry comes from frame_width/height.
 * Unsupported scenes/restored partial captures intentionally remain native. */
int new_horizons_recomp_widescreen_enabled(const NewHorizonsRecomp *instance);
int new_horizons_recomp_set_widescreen(NewHorizonsRecomp *instance, int enabled,
                                 char *error, size_t error_capacity);
int new_horizons_recomp_snapshot_save(const NewHorizonsRecomp *instance,
                                const char *path,
                                char *error, size_t error_capacity);
int new_horizons_recomp_snapshot_load(NewHorizonsRecomp *instance,
                                const char *path,
                                char *error, size_t error_capacity);
int new_horizons_recomp_sram_copy(const NewHorizonsRecomp *instance,
                            void *destination, size_t capacity);
int new_horizons_recomp_sram_load(NewHorizonsRecomp *instance,
                            const void *source, size_t size,
                            char *error, size_t error_capacity);
int new_horizons_recomp_sram_dirty(const NewHorizonsRecomp *instance);
void new_horizons_recomp_sram_mark_clean(NewHorizonsRecomp *instance);

#ifdef __cplusplus
}
#endif
#endif
