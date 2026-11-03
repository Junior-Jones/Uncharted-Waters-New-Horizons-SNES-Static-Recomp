#include "new_horizons_app_core.h"
#include "new_horizons_core.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define NH_FRONTEND_AUDIO_FIFO_FRAMES 8192u
#define NH_FRONTEND_STEP_LIMIT UINT64_C(10000000)

struct NewHorizonsRecomp {
    NHCore *core;
    uint8_t *rom;
    uint32_t frame_pixels[NEW_HORIZONS_RECOMP_FRAME_WIDTH * NEW_HORIZONS_RECOMP_FRAME_HEIGHT];
    /* Host presentation is separate from the untouched native framebuffer. */
    uint32_t wide_pixels[NEW_HORIZONS_RECOMP_WIDE_WIDTH * NEW_HORIZONS_RECOMP_WIDE_HEIGHT];
    uint16_t published_height;
    uint16_t wide_native_pixels[NEW_HORIZONS_RECOMP_WIDE_WIDTH * NEW_HORIZONS_RECOMP_WIDE_HEIGHT];
    int widescreen_requested, wide_active, ui_capture_requested;
    uint16_t native_pixels[NH_CORE_FRAME_PIXELS];
    uint8_t native_known[NH_CORE_FRAME_KNOWN_BYTES];
    int16_t audio_samples[NH_FRONTEND_AUDIO_FIFO_FRAMES * 2u];
    size_t audio_read_index, audio_write_index, audio_frames;
    uint32_t current_frame;
    uint64_t instruction_count, last_sram_generation, audio_frames_dropped;
    int frame_ready, failed, audio_overflowed;
    char last_error[4096];
};

_Static_assert(NEW_HORIZONS_RECOMP_WIDE_WIDTH * 9u ==
               NEW_HORIZONS_RECOMP_WIDE_HEIGHT * 16u, "Exact 16:9 canvas");

static uint32_t bgra_from_snes(uint16_t value);

int new_horizons_recomp_observe_sea_weather(const NewHorizonsRecomp *i,
    uint8_t *weather, uint8_t *mosaic) {
    return i && nh_core_observe_sea_weather(i->core, weather, mosaic);
}

static void compose_port_presentation(NewHorizonsRecomp *i) {
    unsigned pixel;
    i->wide_active = 0;
    if (!i->widescreen_requested ||
        !new_horizons_recomp_read_presentation_frame(i, i->wide_native_pixels,
            NEW_HORIZONS_RECOMP_WIDE_WIDTH * NEW_HORIZONS_RECOMP_WIDE_HEIGHT, NULL, NULL)) return;
    for (pixel = 0u; pixel < NEW_HORIZONS_RECOMP_WIDE_WIDTH * NEW_HORIZONS_RECOMP_WIDE_HEIGHT; ++pixel)
        i->wide_pixels[pixel] = bgra_from_snes(i->wide_native_pixels[pixel]);
    i->wide_active = 1;
}

static void set_error(char *dst, size_t capacity, const char *message) {
    if (dst == NULL || capacity == 0u) return;
    (void)snprintf(dst, capacity, "%s", message != NULL ? message : "");
    dst[capacity - 1u] = '\0';
}

static void set_instance_error(NewHorizonsRecomp *instance, const char *message) {
    if (instance != NULL) set_error(instance->last_error, sizeof(instance->last_error), message);
}

static FILE *open_utf8_file(const char *path, const char *mode) {
#ifdef _WIN32
    wchar_t *wide_path = NULL, *wide_mode = NULL;
    FILE *file = NULL;
    int path_length, mode_length;
    if (path == NULL || mode == NULL) return NULL;
    path_length = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, path, -1, NULL, 0);
    mode_length = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, mode, -1, NULL, 0);
    if (path_length <= 0 || mode_length <= 0) return NULL;
    wide_path = (wchar_t *)malloc((size_t)path_length * sizeof(*wide_path));
    wide_mode = (wchar_t *)malloc((size_t)mode_length * sizeof(*wide_mode));
    if (wide_path != NULL && wide_mode != NULL &&
        MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, path, -1,
                            wide_path, path_length) != 0 &&
        MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, mode, -1,
                            wide_mode, mode_length) != 0)
        file = _wfopen(wide_path, wide_mode);
    free(wide_mode);
    free(wide_path);
    return file;
#else
    return fopen(path, mode);
#endif
}

static int remove_utf8_file(const char *path) {
#ifdef _WIN32
    wchar_t *wide_path;
    int length, result = -1;
    if (path == NULL) return -1;
    length = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, path, -1, NULL, 0);
    if (length <= 0) return -1;
    wide_path = (wchar_t *)malloc((size_t)length * sizeof(*wide_path));
    if (wide_path != NULL && MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS,
            path, -1, wide_path, length) != 0) result = _wremove(wide_path);
    free(wide_path);
    return result;
#else
    return remove(path);
#endif
}

static int replace_utf8_file(const char *source, const char *destination) {
#ifdef _WIN32
    wchar_t *wide_source = NULL, *wide_destination = NULL;
    int source_length, destination_length, result = 0;
    source_length = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS,
                                        source, -1, NULL, 0);
    destination_length = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS,
                                             destination, -1, NULL, 0);
    if (source_length <= 0 || destination_length <= 0) return 0;
    wide_source = (wchar_t *)malloc((size_t)source_length * sizeof(*wide_source));
    wide_destination = (wchar_t *)malloc((size_t)destination_length * sizeof(*wide_destination));
    if (wide_source != NULL && wide_destination != NULL &&
        MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, source, -1,
                            wide_source, source_length) != 0 &&
        MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, destination, -1,
                            wide_destination, destination_length) != 0)
        result = MoveFileExW(wide_source, wide_destination,
                             MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH) != 0;
    free(wide_destination);
    free(wide_source);
    return result;
#else
    return rename(source, destination) == 0;
#endif
}

static uint8_t expand5(uint16_t value) {
    return (uint8_t)((value << 3u) | (value >> 2u));
}

static uint32_t bgra_from_snes(uint16_t value) {
    uint32_t red = expand5(value & 0x1Fu);
    uint32_t green = expand5((value >> 5u) & 0x1Fu);
    uint32_t blue = expand5((value >> 10u) & 0x1Fu);
    return (red << 16u) | (green << 8u) | blue;
}

static int refresh_status(NewHorizonsRecomp *instance, int copy_frame) {
    NHCoreDiagnostic d;
    uint16_t width = 0u, height = 0u;
    uint64_t sequence = 0u;
    uint32_t index;
    if (nh_core_diagnostic(instance->core, &d) != NH_CORE_OK) {
        instance->failed = 1;
        set_instance_error(instance, "Unable to read the static-core diagnostic state.");
        return 0;
    }
    instance->current_frame = (uint32_t)d.published_frames;
    instance->instruction_count = d.terminal_cpu_boundaries;
    if (d.status != NH_CORE_OK || d.scpu_failed != 0u) {
        (void)snprintf(instance->last_error, sizeof(instance->last_error),
            "Static core stopped. status=%u S-CPU=$%06X context=$%06X "
            "master_clock=%llu scanline=%u hclock=%u APU_PC=$%04X SMP_remainder=%u "
            "PPU_mode=%u forced_blank=%u failure_address=$%06X "
            "owner=%u value=$%02X known=$%02X reason=%s",
            (unsigned)d.status, (unsigned)d.scpu_address,
            (unsigned)d.scpu_context_key, (unsigned long long)d.master_clock,
            (unsigned)d.scanline, (unsigned)d.hclock, (unsigned)d.ssmp_pc,
            (unsigned)d.smp_remainder,
            (unsigned)d.ppu_mode, (unsigned)d.ppu_forced_blank,
            (unsigned)d.failure_address, (unsigned)d.failure_owner,
            (unsigned)d.failure_value, (unsigned)d.failure_known_mask,
            d.scpu_failure_reason[0] != '\0' ? d.scpu_failure_reason : "none supplied");
        instance->failed = 1;
        return 0;
    }
    if (!copy_frame) return 1;
    if (!nh_core_read_published_frame(instance->core, instance->native_pixels,
            instance->native_known, NH_CORE_FRAME_PIXELS, &width, &height, &sequence)) {
        set_instance_error(instance, "The static core did not publish a video frame.");
        return 0;
    }
    if (width != NEW_HORIZONS_RECOMP_FRAME_WIDTH || height > NEW_HORIZONS_RECOMP_FRAME_HEIGHT) {
        set_instance_error(instance, "The static core published unsupported video geometry.");
        instance->failed = 1;
        return 0;
    }
    memset(instance->frame_pixels, 0, sizeof(instance->frame_pixels));
    for (index = 0u; index < (uint32_t)width * height; ++index)
        if ((instance->native_known[index >> 3u] & (uint8_t)(1u << (index & 7u))) != 0u)
            instance->frame_pixels[index] = bgra_from_snes(instance->native_pixels[index]);
    instance->published_height = height;
    compose_port_presentation(instance);
    instance->frame_ready = 1;
    (void)sequence;
    return 1;
}

static void append_audio(NewHorizonsRecomp *instance) {
    int16_t samples[1024u * 2u];
    uint8_t known[1024u];
    size_t frames;
    while ((frames = nh_core_pcm_drain(instance->core, samples, known, 1024u)) != 0u) {
        size_t source = 0u, free_frames = NH_FRONTEND_AUDIO_FIFO_FRAMES - instance->audio_frames;
        size_t first, index;
        for (index = 0u; index < frames; ++index) if (known[index] == 0u)
            samples[index * 2u] = samples[index * 2u + 1u] = 0;
        if (frames >= NH_FRONTEND_AUDIO_FIFO_FRAMES) {
            size_t dropped = instance->audio_frames + frames - NH_FRONTEND_AUDIO_FIFO_FRAMES;
            source = frames - NH_FRONTEND_AUDIO_FIFO_FRAMES;
            frames = NH_FRONTEND_AUDIO_FIFO_FRAMES;
            instance->audio_read_index = instance->audio_write_index = instance->audio_frames = 0u;
            instance->audio_frames_dropped += dropped;
            instance->audio_overflowed = dropped != 0u;
        } else if (frames > free_frames) {
            size_t dropped = frames - free_frames;
            instance->audio_read_index = (instance->audio_read_index + dropped) % NH_FRONTEND_AUDIO_FIFO_FRAMES;
            instance->audio_frames -= dropped;
            instance->audio_frames_dropped += dropped;
            instance->audio_overflowed = 1;
        }
        first = NH_FRONTEND_AUDIO_FIFO_FRAMES - instance->audio_write_index;
        if (first > frames) first = frames;
        memcpy(instance->audio_samples + instance->audio_write_index * 2u,
               samples + source * 2u, first * 2u * sizeof(int16_t));
        if (frames > first) memcpy(instance->audio_samples, samples + (source + first) * 2u,
                                   (frames - first) * 2u * sizeof(int16_t));
        instance->audio_write_index = (instance->audio_write_index + frames) % NH_FRONTEND_AUDIO_FIFO_FRAMES;
        instance->audio_frames += frames;
    }
}

typedef struct NHAudioProgress {
    NewHorizonsRecomp *instance;
    NewHorizonsRecompAudioProgressCallback callback;
    void *opaque;
} NHAudioProgress;

static void stream_core_audio(NHCore *core, void *opaque) {
    NHAudioProgress *progress = (NHAudioProgress *)opaque;
    (void)core;
    append_audio(progress->instance);
    progress->callback(progress->instance, progress->opaque);
}

static NHCore *create_core(const uint8_t *rom, const uint8_t *sram, size_t sram_size,
                           char *error, size_t error_capacity) {
    NHCoreStatus status = NH_CORE_BAD_ARGUMENT;
    NHCore *core = nh_core_create_profile(rom, NH_CORE_ROM_BYTES, sram, sram_size,
        NH_CORE_POWER_ON_DETERMINISTIC_ZERO_MACHINE_ARAM_V3, &status);
    if (core == NULL) {
        char detail[128];
        (void)snprintf(detail, sizeof(detail), "The static core could not start (status %u).", (unsigned)status);
        set_error(error, error_capacity, detail);
    }
    return core;
}

int new_horizons_recomp_create(NewHorizonsRecomp **out_instance, const uint8_t *rom,
        size_t rom_size, char *error, size_t error_capacity) {
    NewHorizonsRecomp *instance;
    if (out_instance != NULL) *out_instance = NULL;
    if (out_instance == NULL || rom == NULL || rom_size != NH_CORE_ROM_BYTES) {
        set_error(error, error_capacity, "Select the exact supported 2 MiB Uncharted Waters: New Horizons ROM.");
        return 0;
    }
    instance = (NewHorizonsRecomp *)calloc(1u, sizeof(*instance));
    if (instance == NULL) { set_error(error, error_capacity, "Out of memory creating the static core."); return 0; }
    instance->rom = (uint8_t *)malloc(NH_CORE_ROM_BYTES);
    if (instance->rom == NULL) { free(instance); set_error(error, error_capacity, "Out of memory retaining the selected ROM."); return 0; }
    memcpy(instance->rom, rom, NH_CORE_ROM_BYTES);
    instance->core = create_core(instance->rom, NULL, 0u, error, error_capacity);
    if (instance->core == NULL) { new_horizons_recomp_destroy(instance); return 0; }
    set_instance_error(instance, "");
    if (!refresh_status(instance, 0)) {
        set_error(error, error_capacity, instance->last_error);
        new_horizons_recomp_destroy(instance);
        return 0;
    }
    *out_instance = instance;
    set_error(error, error_capacity, "");
    return 1;
}

void new_horizons_recomp_destroy(NewHorizonsRecomp *instance) {
    if (instance == NULL) return;
    nh_core_destroy(instance->core);
    free(instance->rom);
    free(instance);
}

int new_horizons_recomp_reset(NewHorizonsRecomp *instance, char *error, size_t error_capacity) {
    NHCore *replacement;
    uint8_t sram[NH_CORE_SRAM_FILE_BYTES];
    uint64_t generation;
    if (instance == NULL || instance->core == NULL) {
        set_error(error, error_capacity, "A loaded game is required to reset."); return 0;
    }
    /* The frontend's Reset command restarts the console, as in Jungle Strike
     * and Rock n Roll Racing. The hardware reset line intentionally retains
     * machine state and is not a cold restart. Preserve cartridge battery
     * data, and prepare the replacement before discarding the live core. */
    if (nh_core_encode_sram(instance->core,sram,sizeof(sram),&generation)!=NH_CORE_OK) {
        set_error(error,error_capacity,"Unable to preserve in-game saves for reset."); return 0;
    }
    replacement=create_core(instance->rom,sram,sizeof(sram),error,error_capacity);
    if(!replacement)return 0;
    if((instance->widescreen_requested || instance->ui_capture_requested) &&
       !nh_core_enable_port_ui_capture(replacement,1)) {
        nh_core_destroy(replacement);
        set_error(error,error_capacity,"Unable to allocate reset presentation capture."); return 0;
    }
    nh_core_destroy(instance->core);instance->core=replacement;
    instance->audio_read_index = instance->audio_write_index = instance->audio_frames = 0u;
    instance->audio_overflowed = 0; instance->audio_frames_dropped = 0u;
    instance->last_sram_generation = 0u;
    instance->published_height = 0u;
    instance->wide_active = 0;
    memset(instance->frame_pixels,0,sizeof(instance->frame_pixels));
    instance->frame_ready = 0; instance->failed = 0; set_instance_error(instance, "");
    if (!refresh_status(instance, 0)) { set_error(error, error_capacity, instance->last_error); return 0; }
    set_error(error, error_capacity, ""); return 1;
}

static int advance_frames(NewHorizonsRecomp *instance, uint16_t input_mask,
        uint32_t frame_count, int render, NewHorizonsRecompAudioProgressCallback callback,
        void *opaque, NewHorizonsRecompFrameResult *result) {
    uint32_t start, index;
    if (result != NULL) memset(result, 0, sizeof(*result));
    if (instance == NULL || instance->core == NULL || instance->failed) return 0;
    start = instance->current_frame;
    for (index = 0u; index < frame_count; ++index) {
        uint64_t steps = 0u;
        NHCoreRunResult run;
        if (nh_core_set_standard_pad(instance->core, 0u, input_mask) != NH_CORE_OK) {
            set_instance_error(instance, "The static core rejected controller input."); instance->failed = 1; return 0;
        }
        if (callback != NULL) {
            NHAudioProgress progress = { instance, callback, opaque };
            run = nh_core_run_to_next_frame_streamed(instance->core,
                NH_FRONTEND_STEP_LIMIT, &steps, stream_core_audio, &progress);
        } else {
            run = nh_core_run_to_next_frame(instance->core,
                NH_FRONTEND_STEP_LIMIT, &steps);
        }
        if (run != NH_CORE_RUN_FRAME_READY) {
            (void)refresh_status(instance, 0);
            if (!instance->failed) {
                char detail[160];
                (void)snprintf(detail, sizeof(detail), "The static core stopped before the next frame (result %u, steps %llu).",
                               (unsigned)run, (unsigned long long)steps);
                set_instance_error(instance, detail); instance->failed = 1;
            }
            return 0;
        }
        append_audio(instance);
        if (!refresh_status(instance, render)) return 0;
        if (callback != NULL) callback(instance, opaque);
    }
    if (result != NULL) {
        result->route_continued = 1u;
        result->frame_rendered = (uint8_t)(render && instance->frame_ready);
        result->input_mask = input_mask; result->start_frame = start; result->end_frame = instance->current_frame;
    }
    return 1;
}

int new_horizons_recomp_advance(NewHorizonsRecomp *i, uint16_t p, uint32_t n, NewHorizonsRecompFrameResult *r) { return advance_frames(i,p,n,1,NULL,NULL,r); }
int new_horizons_recomp_advance_streamed(NewHorizonsRecomp *i, uint16_t p, uint32_t n, NewHorizonsRecompAudioProgressCallback c, void *o, NewHorizonsRecompFrameResult *r) { return advance_frames(i,p,n,1,c,o,r); }
int new_horizons_recomp_advance_headless(NewHorizonsRecomp *i, uint16_t p, uint32_t n, NewHorizonsRecompFrameResult *r) { return advance_frames(i,p,n,0,NULL,NULL,r); }
const uint32_t *new_horizons_recomp_frame_bgra(const NewHorizonsRecomp *i) { return i != NULL && i->frame_ready ? (i->wide_active ? i->wide_pixels : i->frame_pixels) : NULL; }
uint32_t new_horizons_recomp_frame_width(const NewHorizonsRecomp *i) { return i && i->wide_active ? NEW_HORIZONS_RECOMP_WIDE_WIDTH : NEW_HORIZONS_RECOMP_FRAME_WIDTH; }
uint32_t new_horizons_recomp_frame_height(const NewHorizonsRecomp *i) { return i && i->wide_active ? NEW_HORIZONS_RECOMP_WIDE_HEIGHT : NEW_HORIZONS_RECOMP_FRAME_HEIGHT; }
uint32_t new_horizons_recomp_current_frame(const NewHorizonsRecomp *i) { return i != NULL ? i->current_frame : 0u; }
uint64_t new_horizons_recomp_instruction_count(const NewHorizonsRecomp *i) { return i != NULL ? i->instruction_count : 0u; }
int new_horizons_recomp_failed(const NewHorizonsRecomp *i) { return i == NULL || i->failed; }
int new_horizons_recomp_read_port_terrain(const NewHorizonsRecomp *i,
    uint16_t *bgr555, uint32_t capacity, unsigned *origin_y) {
    NHCorePortTerrainInfo scene;
    if (i == NULL || !nh_core_read_port_terrain(i->core, bgr555, capacity, &scene)) return 0;
    if (origin_y != NULL) *origin_y = scene.origin_y;
    return 1;
}
int new_horizons_recomp_read_port_world(const NewHorizonsRecomp *i,
    uint16_t *bgr555, uint32_t capacity, unsigned *origin_y) {
    NHCorePortTerrainInfo scene;
    if (i == NULL || !nh_core_read_port_world(i->core, bgr555, capacity, &scene)) return 0;
    if (origin_y != NULL) *origin_y = scene.origin_y;
    return 1;
}
int new_horizons_recomp_enable_port_ui_capture(NewHorizonsRecomp *i) {
    if(!i || !nh_core_enable_port_ui_capture(i->core,1))return 0;
    i->ui_capture_requested=1;return 1;
}
int new_horizons_recomp_disable_port_ui_capture(NewHorizonsRecomp *i) {
    if(!i || i->widescreen_requested || !nh_core_enable_port_ui_capture(i->core,0))return 0;
    i->ui_capture_requested=0;return 1;
}
int new_horizons_recomp_read_port_frame(const NewHorizonsRecomp *i,
    uint16_t *bgr555, uint32_t capacity, unsigned *origin_y) {
    NHCorePortTerrainInfo scene;
    if (!i || !nh_core_read_port_frame(i->core, bgr555, capacity, &scene)) return 0;
    if (origin_y) *origin_y = scene.origin_y;
    return 1;
}
int new_horizons_recomp_read_presentation_frame(const NewHorizonsRecomp *i,
    uint16_t *bgr555, uint32_t capacity, unsigned *origin_y, unsigned *scene) {
    NHCorePortTerrainInfo port;
    NHCoreCombatTerrainInfo combat;
    NHCoreSeaTerrainInfo sea;
    uint64_t pending;
    if (!i) return 0;
    if (nh_core_read_port_frame(i->core, bgr555, capacity, &port)) {
        if (origin_y) *origin_y = port.origin_y;
        if (scene) *scene = 1u;
        return 1;
    }
    if (nh_core_read_sea_frame(i->core, bgr555, capacity, &sea)) {
        if (origin_y) *origin_y = (unsigned)sea.origin_y;
        if (scene) *scene = 3u;
        return 1;
    }
    if (!nh_core_read_combat_frame(i->core, bgr555, capacity, &combat, &pending) || pending)
        return 0;
    if (origin_y) *origin_y = combat.origin_y;
    if (scene) *scene = 2u;
    return 1;
}
const char *new_horizons_recomp_last_error(const NewHorizonsRecomp *i) { return i != NULL ? i->last_error : "No static core is loaded."; }
size_t new_horizons_recomp_audio_available(const NewHorizonsRecomp *i) { return i != NULL ? i->audio_frames : 0u; }

size_t new_horizons_recomp_audio_read(NewHorizonsRecomp *i, int16_t *stereo, size_t capacity) {
    size_t frames, first;
    if (i == NULL || stereo == NULL || capacity == 0u) return 0u;
    frames = i->audio_frames < capacity ? i->audio_frames : capacity;
    first = NH_FRONTEND_AUDIO_FIFO_FRAMES - i->audio_read_index;
    if (first > frames) first = frames;
    memcpy(stereo, i->audio_samples + i->audio_read_index * 2u, first * 2u * sizeof(int16_t));
    if (frames > first) memcpy(stereo + first * 2u, i->audio_samples, (frames - first) * 2u * sizeof(int16_t));
    i->audio_read_index = (i->audio_read_index + frames) % NH_FRONTEND_AUDIO_FIFO_FRAMES;
    i->audio_frames -= frames;
    if (i->audio_frames == 0u) i->audio_write_index = i->audio_read_index;
    return frames;
}

size_t new_horizons_recomp_audio_discard(NewHorizonsRecomp *i) { size_t n=i?i->audio_frames:0u; if(i){i->audio_frames=0u;i->audio_read_index=i->audio_write_index=0u;} return n; }
int new_horizons_recomp_audio_overflowed(const NewHorizonsRecomp *i) { return i != NULL && i->audio_overflowed; }
uint64_t new_horizons_recomp_audio_dropped_frames(const NewHorizonsRecomp *i) { return i != NULL ? i->audio_frames_dropped : 0u; }
void new_horizons_recomp_audio_clear_overflow(NewHorizonsRecomp *i) { if(i) i->audio_overflowed=0; }
int new_horizons_recomp_widescreen_enabled(const NewHorizonsRecomp *i) { return i && i->widescreen_requested; }
int new_horizons_recomp_set_widescreen(NewHorizonsRecomp *i, int enabled, char *error, size_t capacity) {
    if (!i) { set_error(error, capacity, "Load the core before changing presentation."); return 0; }
    if (enabled && !nh_core_enable_port_ui_capture(i->core, 1)) {
        set_error(error, capacity, "Unable to allocate Port presentation capture."); return 0;
    }
    i->widescreen_requested = enabled != 0;
    /* Keep the bounded UI observation cache for immediate paused toggling.
     * OFF performs no expanded-world rendering and always exposes native pixels. */
    compose_port_presentation(i);
    set_error(error, capacity, "");
    return 1;
}

int new_horizons_recomp_snapshot_save(const NewHorizonsRecomp *i, const char *path,
                                      char *error, size_t capacity) {
    size_t size, path_length;
    uint8_t *buffer = NULL;
    char *temporary = NULL;
    FILE *file = NULL;
    int ok = 0;
    if (i == NULL || i->core == NULL || path == NULL || path[0] == '\0') {
        set_error(error, capacity, "A running game and snapshot path are required.");
        return 0;
    }
    size = nh_core_snapshot_size(i->core);
    path_length = strlen(path);
    if (size == 0u || path_length > SIZE_MAX - 16u) {
        set_error(error, capacity, "The core is not at a valid snapshot boundary.");
        return 0;
    }
    buffer = (uint8_t *)malloc(size);
    temporary = (char *)malloc(path_length + 16u);
    if (buffer == NULL || temporary == NULL) {
        set_error(error, capacity, "Not enough memory to create the snapshot.");
        goto cleanup;
    }
    if (!nh_core_save_snapshot(i->core, buffer, size)) {
        set_error(error, capacity, "The complete machine state could not be captured.");
        goto cleanup;
    }
    (void)snprintf(temporary, path_length + 16u, "%s.writing", path);
    file = open_utf8_file(temporary, "wb");
    if (file == NULL) {
        (void)remove_utf8_file(temporary);
        set_error(error, capacity, "Unable to open the complete snapshot file.");
        goto cleanup;
    }
    if (fwrite(buffer, 1u, size, file) != size || fflush(file) != 0) {
        (void)fclose(file);
        file = NULL;
        (void)remove_utf8_file(temporary);
        set_error(error, capacity, "Unable to write the complete snapshot file.");
        goto cleanup;
    }
    if (fclose(file) != 0) {
        file = NULL;
        (void)remove_utf8_file(temporary);
        set_error(error, capacity, "Unable to finish the complete snapshot file.");
        goto cleanup;
    }
    file = NULL;
    if (!replace_utf8_file(temporary, path)) {
        (void)remove_utf8_file(temporary);
        set_error(error, capacity, "Unable to atomically replace the snapshot file.");
        goto cleanup;
    }
    set_error(error, capacity, "");
    ok = 1;
cleanup:
    if (file != NULL) (void)fclose(file);
    free(temporary);
    free(buffer);
    return ok;
}

int new_horizons_recomp_snapshot_load(NewHorizonsRecomp *i, const char *path,
                                      char *error, size_t capacity) {
    NHCore *replacement=NULL;
    size_t expected;
    long length;
    uint8_t *buffer = NULL;
    FILE *file = NULL;
    int trailing, ok = 0;
    if (i == NULL || i->core == NULL || path == NULL || path[0] == '\0') {
        set_error(error, capacity, "A running game and snapshot path are required.");
        return 0;
    }
    /* Validate against a freshly bound candidate, not the possibly failed
     * live core. A renderer stop can leave a timed instruction in flight;
     * rejecting every load from that state made recovery impossible. The
     * saved deterministic state replaces the candidate in full, not a reset
     * approximation. Commit only after validation succeeds. */
    replacement=create_core(i->rom,NULL,0u,error,capacity);
    if(!replacement)return 0;
    expected = nh_core_snapshot_size(replacement);
    if (expected == 0u) {
        set_error(error, capacity, "The core is not at a valid snapshot boundary.");
        goto cleanup;
    }
    file = open_utf8_file(path, "rb");
    if (file == NULL || fseek(file, 0, SEEK_END) != 0 ||
        (length = ftell(file)) < 0 || (size_t)length != expected ||
        fseek(file, 0, SEEK_SET) != 0) {
        set_error(error, capacity, "The snapshot is invalid or belongs to another build.");
        goto cleanup;
    }
    buffer = (uint8_t *)malloc(expected);
    if (buffer == NULL) {
        set_error(error, capacity, "Not enough memory to load the snapshot.");
        goto cleanup;
    }
    if (fread(buffer, 1u, expected, file) != expected) {
        set_error(error, capacity, "The snapshot file is truncated.");
        goto cleanup;
    }
    trailing = fgetc(file);
    if (ferror(file) || trailing != EOF || fclose(file) != 0) {
        file = NULL;
        set_error(error, capacity, "Unable to finish reading the snapshot file.");
        goto cleanup;
    }
    file = NULL;
    if (!nh_core_load_snapshot(replacement, buffer, expected)) {
        set_error(error, capacity, "The snapshot is corrupt or belongs to another ROM/build.");
        goto cleanup;
    }
    {
        NHCoreDiagnostic diagnostic;
        uint16_t width,height;uint64_t sequence;
        if(nh_core_diagnostic(replacement,&diagnostic)!=NH_CORE_OK ||
           diagnostic.status!=NH_CORE_OK || diagnostic.scpu_failed ||
           !nh_core_read_published_frame(replacement,i->native_pixels,i->native_known,
               NH_CORE_FRAME_PIXELS,&width,&height,&sequence) ||
           width!=NEW_HORIZONS_RECOMP_FRAME_WIDTH || height>NEW_HORIZONS_RECOMP_FRAME_HEIGHT){
            set_error(error,capacity,"The snapshot does not contain a healthy published game state.");
            goto cleanup;
        }
    }
    if((i->widescreen_requested || i->ui_capture_requested) &&
       !nh_core_enable_port_ui_capture(replacement,1)){
        set_error(error,capacity,"Unable to allocate restored presentation capture.");goto cleanup;
    }
    nh_core_destroy(i->core);i->core=replacement;replacement=NULL;
    i->audio_read_index = i->audio_write_index = i->audio_frames = 0u;
    i->audio_overflowed = 0;
    i->audio_frames_dropped = 0u;
    i->failed = 0;
    i->frame_ready = 0;
    set_instance_error(i, "");
    if (!refresh_status(i, 1)) {
        set_error(error, capacity, i->last_error);
        goto cleanup;
    }
    set_error(error, capacity, "");
    ok = 1;
cleanup:
    if (file != NULL) (void)fclose(file);
    free(buffer);
    nh_core_destroy(replacement);
    return ok;
}

int new_horizons_recomp_sram_copy(const NewHorizonsRecomp *constant_instance, void *destination, size_t capacity) {
    NewHorizonsRecomp *i = (NewHorizonsRecomp *)constant_instance;
    uint64_t generation = 0u;
    if (i == NULL || destination == NULL || capacity != NH_CORE_SRAM_FILE_BYTES ||
        nh_core_encode_sram(i->core, (uint8_t *)destination, capacity, &generation) != NH_CORE_OK) return 0;
    i->last_sram_generation = generation; return 1;
}

int new_horizons_recomp_sram_load(NewHorizonsRecomp *i, const void *source, size_t size, char *error, size_t capacity) {
    NHCore *replacement;
    if (i == NULL || source == NULL || size != NH_CORE_SRAM_FILE_BYTES) { set_error(error,capacity,"The in-game save file has an invalid size."); return 0; }
    replacement = create_core(i->rom, (const uint8_t *)source, size, error, capacity);
    if (replacement == NULL) return 0;
    if (i->widescreen_requested && !nh_core_enable_port_ui_capture(replacement, 1)) {
        nh_core_destroy(replacement);
        set_error(error, capacity, "Unable to allocate Port presentation capture."); return 0;
    }
    nh_core_destroy(i->core); i->core = replacement;
    i->audio_read_index=i->audio_write_index=i->audio_frames=0u; i->frame_ready=0; i->failed=0; i->last_sram_generation=0u;
    set_instance_error(i, "");
    if (!refresh_status(i,0)) { set_error(error,capacity,i->last_error); return 0; }
    set_error(error,capacity,""); return 1;
}
int new_horizons_recomp_sram_dirty(const NewHorizonsRecomp *i) { return i != NULL && nh_core_sram_dirty(i->core); }
void new_horizons_recomp_sram_mark_clean(NewHorizonsRecomp *i) { if(i && i->last_sram_generation && nh_core_ack_sram_flush(i->core,i->last_sram_generation)) i->last_sram_generation=0u; }

static int write_diagnostic(FILE *file, const NewHorizonsRecomp *i, const char *title, const char *screenshot) {
    NHCoreDiagnostic d;
    unsigned index;
    if (nh_core_diagnostic(i->core,&d)!=NH_CORE_OK) return 0;
    if (fprintf(file, "Sea_presentation_refusal stage=%u subject=%u expected=$%08X actual=$%08X\n",
        (unsigned)d.sea_refusal_stage, (unsigned)d.sea_refusal_subject,
        (unsigned)d.sea_refusal_expected, (unsigned)d.sea_refusal_actual) < 0) return 0;
    if (fprintf(file,
        "%s\nframe=%u master_clock=%llu cpu_cycles=%llu S-CPU=$%06X context=$%06X\n"
        "scanline=%u hclock=%u dot=%u PPU_mode=%u forced_blank=%u brightness=%u main_screen=$%02X known=$%02X\n"
        "SMP_PC=$%04X SMP_cycles=%llu SMP_remainder=%u SMP_instructions=%llu APU_phase=%u DSP_frames=%llu DSP_active_voices=$%02X PCM_known=%llu PCM_unknown=%llu PCM_overflows=%llu\n"
        "status=%u failure_address=$%06X owner=%u value=$%02X known=$%02X reason=%s\nscreenshot=%s\n",
        title?title:"Uncharted Waters: New Horizons diagnostic",i->current_frame,(unsigned long long)d.master_clock,
        (unsigned long long)d.completed_cpu_cycles,(unsigned)d.scpu_address,(unsigned)d.scpu_context_key,
        (unsigned)d.scanline,(unsigned)d.hclock,(unsigned)d.dot,(unsigned)d.ppu_mode,(unsigned)d.ppu_forced_blank,
        (unsigned)d.ppu_brightness,(unsigned)d.ppu_main_screen,(unsigned)d.ppu_main_screen_known_mask,
        (unsigned)d.ssmp_pc,(unsigned long long)d.smp_cycles,(unsigned)d.smp_remainder,
        (unsigned long long)d.ssmp_instructions,(unsigned)d.apu_phase,(unsigned long long)d.dsp_frames,
        (unsigned)d.sdsp_active_voice_mask,(unsigned long long)d.pcm_known_frames,(unsigned long long)d.pcm_unknown_frames,
        (unsigned long long)d.pcm_overflows,(unsigned)d.status,(unsigned)d.failure_address,(unsigned)d.failure_owner,
        (unsigned)d.failure_value,(unsigned)d.failure_known_mask,d.scpu_failure_reason[0]?d.scpu_failure_reason:"none",
        screenshot?screenshot:"none") < 0) return 0;
    if (fprintf(file,
        "instruction_entry=$%06X instruction_context=$%08X entry_S=$%04X\n"
        "A=$%04X X=$%04X Y=$%04X D=$%04X S=$%04X P=$%02X PBR=$%02X DBR=$%02X E=%u\nstack_window=$%04X:",
        (unsigned)d.scpu_instruction_address,(unsigned)d.scpu_instruction_context,
        (unsigned)d.scpu_instruction_s,(unsigned)d.scpu_a,(unsigned)d.scpu_x,
        (unsigned)d.scpu_y,(unsigned)d.scpu_d,(unsigned)d.scpu_s,(unsigned)d.scpu_p,
        (unsigned)d.scpu_pbr,(unsigned)d.scpu_dbr,(unsigned)d.scpu_e,
        (unsigned)d.scpu_stack_window_base) < 0) return 0;
    for (index=0u;index<32u;++index)
        if (fprintf(file,"%s%02X/%u",index?",":"",
            (unsigned)d.scpu_stack_window_values[index],
            (unsigned)d.scpu_stack_window_known[index]) < 0) return 0;
    return fputc('\n',file) != EOF;
}

int new_horizons_recomp_write_diagnostic_log(const NewHorizonsRecomp *i, const char *path, const char *screenshot, char *error, size_t capacity) {
    FILE *file; int ok, closed;
    if(!i||!i->core||!path){set_error(error,capacity,"A loaded core and log path are required.");return 0;}
    file=open_utf8_file(path,"wb"); if(!file){set_error(error,capacity,"Unable to create the diagnostic log.");return 0;}
    ok=write_diagnostic(file,i,"Uncharted Waters: New Horizons diagnostic",screenshot);
    closed=fclose(file)==0;
    ok=ok&&closed;
    set_error(error,capacity,ok?"":"Unable to finish the diagnostic log."); return ok;
}

int new_horizons_recomp_append_diagnostic_log(const NewHorizonsRecomp *i, const char *path, const char *title, char *error, size_t capacity) {
    FILE *file; int ok, closed;
    if(!i||!i->core||!path){set_error(error,capacity,"A loaded core and log path are required.");return 0;}
    file=open_utf8_file(path,"ab"); if(!file){set_error(error,capacity,"Unable to open the diagnostic log.");return 0;}
    ok=fputs("\n",file)>=0&&write_diagnostic(file,i,title,NULL);
    closed=fclose(file)==0;
    ok=ok&&closed;
    set_error(error,capacity,ok?"":"Unable to finish the diagnostic log."); return ok;
}
