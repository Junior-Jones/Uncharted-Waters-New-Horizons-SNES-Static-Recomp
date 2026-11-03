#include "new_horizons_core.h"

#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SignalMetrics {
    uint64_t pixel_fnv1a64;
    uint64_t pcm_fnv1a64;
    uint64_t pcm_frames;
    uint64_t pcm_nonzero_samples;
    uint64_t pcm_unknown_frames;
    uint32_t nonblack_pixels;
    uint32_t unique_colors;
    uint16_t pcm_peak;
    uint16_t frame_width;
    uint16_t frame_height;
    uint64_t frame_sequence;
} SignalMetrics;

static uint64_t fnv_byte(uint64_t hash, uint8_t byte) {
    return (hash ^ byte) * UINT64_C(1099511628211);
}

static int read_exact_rom(const char *path, uint8_t **out) {
    FILE *file;
    uint8_t *rom;
    long file_size;
    long payload_offset;
    int trailing;
    size_t count;
    *out = NULL;
    file = fopen(path, "rb");
    if (file == NULL) return 0;
    if (fseek(file, 0L, SEEK_END) != 0 ||
        (file_size = ftell(file)) < 0L) {
        fclose(file);
        return 0;
    }
    payload_offset = file_size == (long)NH_CORE_ROM_BYTES ? 0L :
        file_size == (long)NH_CORE_ROM_BYTES + 512L ? 512L : -1L;
    if (payload_offset < 0L || fseek(file, payload_offset, SEEK_SET) != 0) {
        fclose(file);
        return 0;
    }
    rom = (uint8_t *)malloc(NH_CORE_ROM_BYTES);
    if (rom == NULL) {
        fclose(file);
        return 0;
    }
    count = fread(rom, 1u, NH_CORE_ROM_BYTES, file);
    trailing = fgetc(file);
    if (count != NH_CORE_ROM_BYTES || trailing != EOF || ferror(file)) {
        free(rom);
        fclose(file);
        return 0;
    }
    fclose(file);
    *out = rom;
    return 1;
}

static void drain_pcm(NHCore *core, SignalMetrics *metrics) {
    int16_t samples[512u * 2u];
    uint8_t known[512u];
    size_t count, frame;
    while ((count = nh_core_pcm_drain(core, samples, known, 512u)) != 0u) {
        for (frame = 0u; frame < count; ++frame) {
            unsigned channel;
            if (known[frame] == 0u) ++metrics->pcm_unknown_frames;
            for (channel = 0u; channel < 2u; ++channel) {
                const int value = samples[frame * 2u + channel];
                const uint16_t magnitude = (uint16_t)(value < 0 ?
                    -(value + 1) + 1 : value);
                metrics->pcm_fnv1a64 = fnv_byte(metrics->pcm_fnv1a64,
                    (uint8_t)value);
                metrics->pcm_fnv1a64 = fnv_byte(metrics->pcm_fnv1a64,
                    (uint8_t)((uint16_t)value >> 8u));
                if (value != 0) ++metrics->pcm_nonzero_samples;
                if (magnitude > metrics->pcm_peak) metrics->pcm_peak = magnitude;
            }
        }
        metrics->pcm_frames += count;
    }
}

static int inspect_frame(NHCore *core, SignalMetrics *metrics) {
    uint16_t *pixels;
    uint8_t known[NH_CORE_FRAME_KNOWN_BYTES];
    uint8_t seen[65536u / 8u];
    uint32_t index, count;
    pixels = (uint16_t *)malloc(NH_CORE_FRAME_PIXELS * sizeof(*pixels));
    if (pixels == NULL) return 0;
    memset(known, 0, sizeof(known));
    memset(seen, 0, sizeof(seen));
    if (!nh_core_read_published_frame(core, pixels, known, NH_CORE_FRAME_PIXELS,
            &metrics->frame_width, &metrics->frame_height,
            &metrics->frame_sequence)) {
        free(pixels);
        return 0;
    }
    count = (uint32_t)metrics->frame_width * metrics->frame_height;
    for (index = 0u; index < count; ++index) {
        const uint16_t pixel = pixels[index];
        if ((known[index >> 3u] & (uint8_t)(1u << (index & 7u))) == 0u) {
            free(pixels);
            return 0;
        }
        metrics->pixel_fnv1a64 = fnv_byte(metrics->pixel_fnv1a64,
                                           (uint8_t)pixel);
        metrics->pixel_fnv1a64 = fnv_byte(metrics->pixel_fnv1a64,
                                           (uint8_t)(pixel >> 8u));
        if ((pixel & 0x7FFFu) != 0u) ++metrics->nonblack_pixels;
        if ((seen[pixel >> 3u] & (uint8_t)(1u << (pixel & 7u))) == 0u) {
            seen[pixel >> 3u] |= (uint8_t)(1u << (pixel & 7u));
            ++metrics->unique_colors;
        }
    }
    free(pixels);
    return 1;
}

static int write_frame_ppm(NHCore *core, const char *path) {
    uint16_t *pixels;
    uint8_t known[NH_CORE_FRAME_KNOWN_BYTES];
    uint16_t width = 0u, height = 0u;
    uint64_t sequence = 0u;
    uint32_t index, count;
    FILE *file;
    pixels = (uint16_t *)malloc(NH_CORE_FRAME_PIXELS * sizeof(*pixels));
    if (pixels == NULL) return 0;
    memset(known, 0, sizeof(known));
    if (!nh_core_read_published_frame(core, pixels, known, NH_CORE_FRAME_PIXELS,
            &width, &height, &sequence)) {
        free(pixels);
        return 0;
    }
    file = fopen(path, "wb");
    if (file == NULL) {
        free(pixels);
        return 0;
    }
    if (fprintf(file, "P6\n%u %u\n255\n", (unsigned)width,
            (unsigned)height) < 0) {
        fclose(file);
        free(pixels);
        return 0;
    }
    count = (uint32_t)width * height;
    for (index = 0u; index < count; ++index) {
        const uint16_t pixel = pixels[index];
        const uint8_t rgb[3] = {
            (uint8_t)(((pixel >> 0u) & 31u) * 255u / 31u),
            (uint8_t)(((pixel >> 5u) & 31u) * 255u / 31u),
            (uint8_t)(((pixel >> 10u) & 31u) * 255u / 31u)
        };
        if ((known[index >> 3u] & (uint8_t)(1u << (index & 7u))) == 0u ||
            fwrite(rgb, 1u, sizeof(rgb), file) != sizeof(rgb)) {
            fclose(file);
            free(pixels);
            return 0;
        }
    }
    if (fclose(file) != 0) {
        free(pixels);
        return 0;
    }
    free(pixels);
    return 1;
}

static int snapshot_file(NHCore *core, const char *path, int load) {
    const size_t size = nh_core_snapshot_size(core);
    void *data = malloc(size);
    FILE *file;
    int ok = 0;
    if (size == 0u || data == NULL) { free(data); return 0; }
    if (load) {
        file = fopen(path, "rb");
        if (file != NULL) {
            ok = fread(data, 1u, size, file) == size && fgetc(file) == EOF && !ferror(file);
            if (fclose(file) != 0) ok = 0;
            if (ok) ok = nh_core_load_snapshot(core, data, size);
        }
    } else if (nh_core_save_snapshot(core, data, size)) {
        file = fopen(path, "wb");
        if (file != NULL) {
            ok = fwrite(data, 1u, size, file) == size;
            if (fclose(file) != 0) ok = 0;
        }
    }
    free(data);
    return ok;
}

static void print_diagnostic(const NHCoreDiagnostic *d) {
    unsigned dma_reg, stack_index;
    printf("instruction_entry=%06" PRIX32 " instruction_context=%08" PRIX32
           " entry_S=%04X\n", d->scpu_instruction_address,
           d->scpu_instruction_context, (unsigned)d->scpu_instruction_s);
    printf("status=%u owner=%u failure_address=%06" PRIX32
           " failure_value=%02X failure_known=%02X\n",
           (unsigned)d->status, (unsigned)d->failure_owner,
           d->failure_address, (unsigned)d->failure_value,
           (unsigned)d->failure_known_mask);
    printf("scpu=%06" PRIX32 " context=%08" PRIX32
           " A=%04X X=%04X Y=%04X D=%04X S=%04X P=%02X PBR=%02X DBR=%02X E=%u"
           " cpu_cycles=%" PRIu64 " master=%" PRIu64
           " raster=%u:%u dot=%u fields=%" PRIu64 "\n",
           d->scpu_address, d->scpu_context_key,
           (unsigned)d->scpu_a, (unsigned)d->scpu_x, (unsigned)d->scpu_y,
           (unsigned)d->scpu_d, (unsigned)d->scpu_s, (unsigned)d->scpu_p,
           (unsigned)d->scpu_pbr, (unsigned)d->scpu_dbr, (unsigned)d->scpu_e,
           d->completed_cpu_cycles,
           d->master_clock, (unsigned)d->scanline, (unsigned)d->hclock,
           (unsigned)d->dot, d->completed_fields);
    printf("wram[0052]=%04X/%u wram[0068]=%04X/%u wram[006A]=%04X/%u\n",
           (unsigned)d->wram_0052, (unsigned)d->wram_0052_known_mask,
           (unsigned)d->wram_0068, (unsigned)d->wram_0068_known_mask,
           (unsigned)d->wram_006a, (unsigned)d->wram_006a_known_mask);
    printf("stack_window=%04X:", (unsigned)d->scpu_stack_window_base);
    for (stack_index = 0u; stack_index < 32u; ++stack_index)
        printf("%s%02X/%u", stack_index == 0u ? "" : ",",
               (unsigned)d->scpu_stack_window_values[stack_index],
               (unsigned)d->scpu_stack_window_known[stack_index]);
    putchar('\n');
    printf("ssmp_pc=%04X A=%02X X=%02X Y=%02X SP=%02X PSW=%02X"
           " ssmp_cycles=%" PRIu64 " smp_remainder=%" PRIu32
           " ssmp_instructions=%" PRIu64 " apu_phase=%u upload_bytes=%" PRIu32
           " expected_token=%02X last_ack=%02X cpu_ports=%02X/%02X"
           " dsp_frames=%" PRIu64 " voices=%02X fifo=%" PRIu32
           " pcm_known=%" PRIu64 " pcm_unknown=%" PRIu64
           " pcm_overflows=%" PRIu64 "\n",
           (unsigned)d->ssmp_pc, (unsigned)d->ssmp_a, (unsigned)d->ssmp_x,
           (unsigned)d->ssmp_y, (unsigned)d->ssmp_sp, (unsigned)d->ssmp_psw,
           d->smp_cycles, d->smp_remainder,
           d->ssmp_instructions,
           (unsigned)d->apu_phase, d->apu_uploaded_bytes,
           (unsigned)d->apu_expected_token, (unsigned)d->apu_last_ack,
           (unsigned)d->apu_cpu_port0, (unsigned)d->apu_cpu_port1,
           d->dsp_frames,
           (unsigned)d->sdsp_active_voice_mask, d->pcm_fifo_frames,
           d->pcm_known_frames, d->pcm_unknown_frames, d->pcm_overflows);
    printf("aram[21D1]=%02X/%u sdsp_aram_reads=%" PRIu64
           " sdsp_aram_writes=%" PRIu64
           " flg=%02X esa=%02X edl=%02X echo=%04X+%04X/%04X writable=%u\n",
           (unsigned)d->aram_21d1, (unsigned)d->aram_21d1_known,
           d->sdsp_aram_reads, d->sdsp_aram_writes,
           (unsigned)d->sdsp_flg, (unsigned)d->sdsp_esa,
           (unsigned)d->sdsp_edl, (unsigned)d->sdsp_echo_pointer,
           (unsigned)d->sdsp_echo_offset, (unsigned)d->sdsp_echo_length,
           (unsigned)d->sdsp_echo_writable);
    printf("ppu_mode=%u forced_blank=%u brightness=%u main_screen=%02X/%02X"
           " published=%" PRIu64 " terminal_raster=%" PRIu64
           " terminal_cpu=%" PRIu64 "\n",
           (unsigned)d->ppu_mode, (unsigned)d->ppu_forced_blank,
           (unsigned)d->ppu_brightness, (unsigned)d->ppu_main_screen,
           (unsigned)d->ppu_main_screen_known_mask, d->published_frames,
           d->terminal_raster_events, d->terminal_cpu_boundaries);
    printf("power_on_profile=%u hdma_enable=%02X dma_active=%02X dma_regs=",
           (unsigned)d->power_on_profile, (unsigned)d->hdma_enable,
           (unsigned)d->dma_active_channel);
    for (dma_reg = 0u; dma_reg < 12u; ++dma_reg)
        printf("%s%02X/%02X", dma_reg == 0u ? "" : ",",
               (unsigned)d->dma_register_values[dma_reg],
               (unsigned)d->dma_register_known_masks[dma_reg]);
    putchar('\n');
    printf("render_failure_kind=%u address=%06" PRIX32 " value=%02X known=%02X\n",
           (unsigned)d->render_failure_kind, d->render_failure_address,
           (unsigned)d->render_failure_value,
           (unsigned)d->render_failure_known_mask);
    printf("ppu_storage_reads=%" PRIu64 " ppu_storage_writes=%" PRIu64
           " oam_data_writes=%" PRIu64 "\n",
           d->ppu_storage_reads, d->ppu_storage_writes,
           d->ppu_oam_data_writes);
    if (d->scpu_failure_reason[0] != '\0')
        printf("scpu_failure=%s\n", d->scpu_failure_reason);
}

int main(int argc, char **argv) {
    uint8_t *rom;
    NHCore *core;
    NHCoreStatus status;
    NHCoreDiagnostic diagnostic;
    SignalMetrics metrics;
    uint64_t frame = 0u, frames = 1u, total_steps = 0u;
    uint64_t seconds = 0u, start_master = 0u, target_master = 0u;
    uint64_t capture_every = 0u, capture_count = 0u;
    uint64_t next_capture_master = 0u, captured = 0u;
    const char *capture_dir = NULL;
    const char *capture_final = NULL;
    const char *snapshot_in = NULL, *snapshot_out = NULL;
    const char *snapshot_before_pad = NULL, *capture_before_pad = NULL;
    uint64_t pad_frames = 1u, pad_mask = 0u;
    int option_index;
    int duration_mode = 0;
    char *end = NULL;
    /* Optional gameplay controls use only public input/snapshot/frame APIs.
     * Remove them before the existing duration/capture argument parser. */
    for (option_index = 2; option_index < argc;) {
        const char **path_option = NULL;
        uint64_t *number_option = NULL;
        int shift;
        if (strcmp(argv[option_index], "--snapshot-in") == 0) path_option = &snapshot_in;
        else if (strcmp(argv[option_index], "--snapshot-out") == 0) path_option = &snapshot_out;
        else if (strcmp(argv[option_index], "--snapshot-before-pad") == 0) path_option = &snapshot_before_pad;
        else if (strcmp(argv[option_index], "--capture-before-pad") == 0) path_option = &capture_before_pad;
        else if (strcmp(argv[option_index], "--pad-mask") == 0) number_option = &pad_mask;
        else if (strcmp(argv[option_index], "--pad-frames") == 0) number_option = &pad_frames;
        else { ++option_index; continue; }
        if (option_index + 1 >= argc) { fprintf(stderr, "missing gameplay option value\n"); return 2; }
        if (path_option != NULL) *path_option = argv[option_index + 1];
        else {
            char *number_end;
            errno = 0;
            *number_option = strtoull(argv[option_index + 1], &number_end, 0);
            if (errno != 0 || *number_end != '\0' || number_end == argv[option_index + 1]) {
                fprintf(stderr, "invalid gameplay numeric option\n"); return 2;
            }
        }
        for (shift = option_index; shift + 2 < argc; ++shift) argv[shift] = argv[shift + 2];
        argc -= 2;
        argv[argc] = NULL;
    }
    if (pad_mask > 0xFFF0u || (pad_mask & 15u) != 0u || pad_frames == 0u) {
        fprintf(stderr, "invalid native JOY pad mask or hold duration\n"); return 2;
    }
    if (argc < 2 || (argc != 2 && argc != 3 && argc != 4 && argc != 5 && argc != 10) ||
        ((argc == 4 || argc == 10) && strcmp(argv[2], "--seconds") != 0)) {
        fprintf(stderr, "usage: NewHorizonsHeadless <exact-rom-path> [frames]\n"
                        "       [--capture-final <ppm-path>]\n"
                        "   or: NewHorizonsHeadless <exact-rom-path> --seconds <duration>\n"
                        "       [--capture-every <seconds> --capture-count <count> --capture-dir <existing-directory>]\n");
        return 2;
    }
    if (argc == 3 || argc == 4 || argc == 5 || argc == 10) {
        errno = 0;
        if (argc == 4 || argc == 10) {
            duration_mode = 1;
            seconds = strtoull(argv[3], &end, 10);
        } else {
            frames = strtoull(argv[2], &end, 10);
        }
        if (errno != 0 || end == (duration_mode ? argv[3] : argv[2]) ||
            *end != '\0' || (duration_mode ? seconds : frames) == 0u) {
            fprintf(stderr, "invalid positive frame count or duration\n");
            return 2;
        }
    }
    if (argc == 5) {
        if (strcmp(argv[3], "--capture-final") != 0) {
            fprintf(stderr, "invalid final capture arguments\n");
            return 2;
        }
        capture_final = argv[4];
    }
    if (argc == 10) {
        char *capture_end = NULL;
        if (strcmp(argv[4], "--capture-every") != 0 ||
            strcmp(argv[6], "--capture-count") != 0 ||
            strcmp(argv[8], "--capture-dir") != 0) {
            fprintf(stderr, "invalid capture arguments\n");
            return 2;
        }
        errno = 0;
        capture_every = strtoull(argv[5], &capture_end, 10);
        if (errno != 0 || capture_end == argv[5] || *capture_end != '\0' ||
            capture_every == 0u) {
            fprintf(stderr, "invalid positive capture interval\n");
            return 2;
        }
        errno = 0;
        capture_count = strtoull(argv[7], &capture_end, 10);
        if (errno != 0 || capture_end == argv[7] || *capture_end != '\0' ||
            capture_count == 0u) {
            fprintf(stderr, "invalid positive capture count\n");
            return 2;
        }
        capture_dir = argv[9];
    }
    if (!read_exact_rom(argv[1], &rom)) {
        fprintf(stderr, "ROM must be an exact %u-byte external file, optionally with a 512-byte copier header\n",
                (unsigned)NH_CORE_ROM_BYTES);
        return 2;
    }
    core = nh_core_create_profile(rom, NH_CORE_ROM_BYTES, NULL, 0u,
        NH_CORE_POWER_ON_DETERMINISTIC_ZERO_MACHINE_ARAM_V3, &status);
    free(rom);
    if (core == NULL) {
        fprintf(stderr, "core create failed: %u\n", (unsigned)status);
        return 1;
    }
    /* A newly created machine has a pending reset sequence. Snapshot loading
     * requires the same quiescent boundary used by the frontend. This throwaway
     * field is fully replaced by the loaded state, including the PCM FIFO. */
    if (snapshot_in != NULL && nh_core_run_to_next_frame(core,
            UINT64_C(10000000), NULL) != NH_CORE_RUN_FRAME_READY) {
        fprintf(stderr, "snapshot restore boundary unavailable\n");
        nh_core_destroy(core); return 1;
    }
    if ((snapshot_in != NULL && !snapshot_file(core, snapshot_in, 1)) ||
        (capture_before_pad != NULL && !write_frame_ppm(core, capture_before_pad)) ||
        (snapshot_before_pad != NULL && !snapshot_file(core, snapshot_before_pad, 0))) {
        fprintf(stderr, "gameplay snapshot/capture operation failed\n");
        nh_core_destroy(core); return 1;
    }
    if (nh_core_diagnostic(core, &diagnostic) != NH_CORE_OK) {
        fprintf(stderr, "initial diagnostic read failed\n");
        nh_core_destroy(core);
        return 1;
    }
    start_master = diagnostic.master_clock;
    if (duration_mode) {
        const NHCoreTiming *timing = nh_core_timing();
        if (timing == NULL || timing->master_hz_denominator != 1u ||
            seconds > (UINT64_MAX - start_master) / timing->master_hz_numerator) {
            fprintf(stderr, "duration cannot be represented by this timing profile\n");
            nh_core_destroy(core);
            return 2;
        }
        target_master = start_master + seconds * timing->master_hz_numerator;
        if (capture_count != 0u) {
            if (capture_every > (UINT64_MAX - start_master) /
                    timing->master_hz_numerator) {
                fprintf(stderr, "capture interval cannot be represented by this timing profile\n");
                nh_core_destroy(core);
                return 2;
            }
            next_capture_master = start_master +
                capture_every * timing->master_hz_numerator;
        }
    }
    memset(&metrics, 0, sizeof(metrics));
    metrics.pixel_fnv1a64 = metrics.pcm_fnv1a64 =
        UINT64_C(14695981039346656037);
    while (duration_mode ? diagnostic.master_clock < target_master : frame < frames) {
        uint64_t steps = 0u;
        if (nh_core_set_standard_pad(core, 0u,
                (uint16_t)(frame < pad_frames ? pad_mask : 0u)) != NH_CORE_OK) {
            fprintf(stderr, "pad report failed\n"); nh_core_destroy(core); return 1;
        }
        NHCoreRunResult run = nh_core_run_to_next_frame(core,
                                                        UINT64_C(10000000),
                                                        &steps);
        total_steps += steps;
        drain_pcm(core, &metrics);
        if (run != NH_CORE_RUN_FRAME_READY) {
            (void)nh_core_diagnostic(core, &diagnostic);
            fprintf(stderr, "run stopped at requested frame %" PRIu64
                            " with result %u\n", frame + 1u, (unsigned)run);
            print_diagnostic(&diagnostic);
            if (capture_final != NULL) (void)write_frame_ppm(core, capture_final);
            nh_core_destroy(core);
            return 1;
        }
        ++frame;
        if (duration_mode && nh_core_diagnostic(core, &diagnostic) != NH_CORE_OK) {
            fprintf(stderr, "duration diagnostic read failed\n");
            nh_core_destroy(core);
            return 1;
        }
        if (captured < capture_count &&
            diagnostic.master_clock >= next_capture_master) {
            char path[1024];
            const uint64_t capture_second = capture_every * (captured + 1u);
            if (snprintf(path, sizeof(path), "%s/capture-%03" PRIu64 "s.ppm",
                    capture_dir, capture_second) < 0 ||
                !write_frame_ppm(core, path)) {
                fprintf(stderr, "unable to write capture %" PRIu64 " to %s\n",
                        captured + 1u, path);
                nh_core_destroy(core);
                return 1;
            }
            printf("capture=%s master=%" PRIu64 " frame=%" PRIu64 "\n",
                   path, diagnostic.master_clock, frame);
            ++captured;
            next_capture_master += capture_every *
                nh_core_timing()->master_hz_numerator;
        }
    }
    if (!inspect_frame(core, &metrics) ||
        nh_core_diagnostic(core, &diagnostic) != NH_CORE_OK) {
        fprintf(stderr, "published-frame or diagnostic read failed\n");
        nh_core_destroy(core);
        return 1;
    }
    if (capture_final != NULL && !write_frame_ppm(core, capture_final)) {
        fprintf(stderr, "unable to write final capture to %s\n", capture_final);
        nh_core_destroy(core);
        return 1;
    }
    if (snapshot_out != NULL && !snapshot_file(core, snapshot_out, 0)) {
        fprintf(stderr, "unable to save gameplay snapshot\n");
        nh_core_destroy(core); return 1;
    }
    if (capture_final != NULL)
        printf("capture=%s master=%" PRIu64 " frame=%" PRIu64 "\n",
               capture_final, diagnostic.master_clock, frame);
    if (duration_mode)
        printf("requested_seconds=%" PRIu64 " target_master=%" PRIu64
               " natural_frames=%" PRIu64 " dispatch_steps=%" PRIu64 "\n",
               seconds, target_master, frame, total_steps);
    else
        printf("requested_frames=%" PRIu64 " dispatch_steps=%" PRIu64 "\n",
               frames, total_steps);
    printf("frame=%ux%u sequence=%" PRIu64 " nonblack=%" PRIu32
           " unique_colors=%" PRIu32 " pixel_fnv1a64=%016" PRIX64 "\n",
           (unsigned)metrics.frame_width, (unsigned)metrics.frame_height,
           metrics.frame_sequence, metrics.nonblack_pixels,
           metrics.unique_colors, metrics.pixel_fnv1a64);
    printf("pcm_frames=%" PRIu64 " nonzero_samples=%" PRIu64
           " unknown_frames=%" PRIu64 " peak=%u pcm_fnv1a64=%016" PRIX64 "\n",
           metrics.pcm_frames, metrics.pcm_nonzero_samples,
           metrics.pcm_unknown_frames, (unsigned)metrics.pcm_peak,
           metrics.pcm_fnv1a64);
    print_diagnostic(&diagnostic);
    nh_core_destroy(core);
    return diagnostic.status == NH_CORE_OK ? 0 : 1;
}
