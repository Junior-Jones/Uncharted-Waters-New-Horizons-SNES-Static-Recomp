/* Explicit Launcher headless mode, through the SAME opaque frontend adapter.
 * No device audio, guest patches, alternate renderer or snapshot migrations. */
static uint64_t nh_present_hash(uint64_t hash, const void *data, size_t count) {
    const unsigned char *bytes = (const unsigned char *)data;
    size_t n;
    for (n = 0u; n < count; ++n) { hash ^= bytes[n]; hash *= UINT64_C(1099511628211); }
    return hash;
}

static int nh_present_ppm(const wchar_t *directory, const wchar_t *name,
                          const uint32_t *pixels, unsigned width, unsigned height) {
    wchar_t path[32768];
    FILE *file;
    unsigned x, y;
    swprintf(path, 32768u, L"%ls\\%ls.ppm", directory, name);
    file = _wfopen(path, L"wb");
    if (!file) return 0;
    fprintf(file, "P6\n%u %u\n255\n", width, height);
    for (y = 0; y < height; ++y) for (x = 0; x < width; ++x) {
        const uint32_t p = pixels[y * width + x];
        const unsigned char rgb[3] = { (unsigned char)(p >> 16u),
            (unsigned char)(p >> 8u), (unsigned char)p };
        if (fwrite(rgb, 1u, 3u, file) != 3u) { fclose(file); return 0; }
    }
    return fclose(file) == 0;
}

static int nh_present_snapshot(NewHorizonsRecomp *game, const wchar_t *directory,
                                const wchar_t *name, FILE *log) {
    wchar_t path[32768];
    char utf8[131072], error[4096];
    swprintf(path, 32768u, L"%ls\\%ls.nhsnap", directory, name);
    if (!wide_to_utf8(path, utf8, sizeof(utf8)) ||
        !new_horizons_recomp_snapshot_save(game, utf8, error, sizeof(error))) {
        fprintf(log, "ERROR saving presentation checkpoint\n"); return 0;
    }
    return 1;
}

static uint32_t nh_present_bgra(uint16_t value) {
    /* Same bit replication as the real frontend adapter, not floor(v*255/31).
     * Otherwise capture-only RGB rounding creates false pixel differences. */
    const unsigned r = value & 31u, g = (value >> 5u) & 31u, b = (value >> 10u) & 31u;
    return (((r << 3u) | (r >> 2u)) << 16u) |
           (((g << 3u) | (g >> 2u)) << 8u) | ((b << 3u) | (b >> 2u));
}

static int nh_present_terrain(NewHorizonsRecomp *game, const wchar_t *directory, FILE *log) {
    uint16_t *terrain = (uint16_t *)malloc(512u * 288u * sizeof(uint16_t));
    uint32_t *bgra = (uint32_t *)malloc(512u * 288u * sizeof(uint32_t));
    unsigned n, origin_y;
    int ok = 0;
    LARGE_INTEGER start, end, frequency;
    if (!terrain || !bgra) goto cleanup;
    if (!nh_present_snapshot(game, directory, L"port-checkpoint", log)) goto cleanup;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
    if (!new_horizons_recomp_read_port_terrain(game, terrain, 512u * 288u, &origin_y)) {
        fprintf(log, "ERROR Port source-map/terrain qualification rejected\n"); goto cleanup;
    }
    QueryPerformanceCounter(&end);
    for (n = 0u; n < 512u * 288u; ++n) bgra[n] = nh_present_bgra(terrain[n]);
    if (!nh_present_ppm(directory, L"port-terrain-only", bgra, 512u, 288u) ||
        !nh_present_snapshot(game, directory, L"port-after-terrain", log)) goto cleanup;
    fprintf(log, "P3 TERRAIN ONLY origin=0,%u geometry=512x288 render_ms=%.3f; actors/UI NOT YET COMPOSED\n",
        origin_y, 1000.0 * (double)(end.QuadPart-start.QuadPart) / (double)frequency.QuadPart);
    QueryPerformanceCounter(&start);
    if (!new_horizons_recomp_read_port_world(game, terrain, 512u * 288u, &origin_y)) {
        fprintf(log, "ERROR Port actor-source/world qualification rejected\n"); goto cleanup;
    }
    QueryPerformanceCounter(&end);
    for (n = 0u; n < 512u * 288u; ++n) bgra[n] = nh_present_bgra(terrain[n]);
    if (!nh_present_ppm(directory, L"port-world-actors", bgra, 512u, 288u) ||
        !nh_present_snapshot(game, directory, L"port-after-world", log)) goto cleanup;
    fprintf(log, "P4 WORLD ACTORS origin=0,%u geometry=512x288 render_ms=%.3f; UI/windows/math NOT YET COMPOSED\n",
        origin_y, 1000.0 * (double)(end.QuadPart-start.QuadPart) / (double)frequency.QuadPart);
    if (!new_horizons_recomp_read_port_frame(game, terrain, 512u * 288u, &origin_y)) {
        fprintf(log, "ERROR Port raster UI/composition qualification rejected\n"); goto cleanup;
    }
    for (n = 0u; n < 512u * 288u; ++n) bgra[n] = nh_present_bgra(terrain[n]);
    if (!nh_present_ppm(directory, L"port-ui-composite", bgra, 512u, 288u) ||
        !nh_present_snapshot(game, directory, L"port-after-ui", log)) goto cleanup;
    fprintf(log, "P5 RASTER UI composite; walking HUD edge-anchored; coherent modal groups top/bottom-anchored or centred by source-cell bounds; dependent world/subscreen math remains unsupported\n");
    ok = 1;
cleanup:
    free(terrain); free(bgra);
    return ok;
}

static int nh_presentation_headless_cli(void) {
    LPWSTR *args;
    int argc, exit_code = 1;
    NewHorizonsRecomp *game = NULL;
    FILE *script = NULL, *log = NULL;
    uint8_t *rom = NULL;
    size_t rom_size = 0u;
    wchar_t rom_error[512];
    char error[4096], line[256];
    wchar_t log_path[32768];
    LARGE_INTEGER host_frequency;
    uint64_t pcm_hash = UINT64_C(14695981039346656037), pcm_frames = 0u;
    unsigned fields = 0u, rows = 0u, step, mask, hold, duration;
    int expect_native_end = 0, expect_combat_end = 0, expect_sea_end = 0;
    int watch_weather = 0, weather_known = 0, stop_script = 0;
    int native_profile = 0;
    uint8_t previous_weather = 0u, previous_mosaic = 0u;
    args = CommandLineToArgvW(GetCommandLineW(), &argc);
    if (!args) return -1;
    if (argc < 2 || wcscmp(args[1], L"--presentation-headless") != 0) {
        LocalFree(args); return -1;
    }
    if (argc != 5 && argc != 6 &&
        !(argc == 7 && !wcscmp(args[5], L"--battery"))) { LocalFree(args); return 2; }
    swprintf(log_path, 32768u, L"%ls\\presentation-result.txt", args[4]);
    log = _wfopen(log_path, L"w");
    if (!log) goto cleanup;
    setvbuf(log, NULL, _IOLBF, 0u);
    if (!QueryPerformanceFrequency(&host_frequency)) goto cleanup;
    if (!read_rom_file(args[2], &rom, &rom_size, rom_error, 512u)) {
        (void)wide_to_utf8(rom_error, error, sizeof(error));
        fprintf(log, "ERROR frontend ROM loader: %s\n", error); goto cleanup;
    }
    if (!new_horizons_recomp_create(&game, rom, rom_size, error, sizeof(error))) {
        fprintf(log, "ERROR create: %s\n", error); goto cleanup;
    }
    free(rom); rom = NULL;
    if (argc == 7) {
        if (GetFileAttributesW(args[6]) == INVALID_FILE_ATTRIBUTES ||
            !load_battery_sram_file_win32(game, args[6], rom_error, 512u)) {
            fprintf(log, "ERROR explicit battery input missing or rejected by normal frontend loader\n");
            goto cleanup;
        }
        fprintf(log, "BATTERY normal validated portable SRAM; cold boot; input file read-only\n");
    }
    if (argc == 6) {
        char checkpoint[131072];
        error[0] = '\0';
        if (!wide_to_utf8(args[5], checkpoint, sizeof(checkpoint)) ||
            !new_horizons_recomp_snapshot_load(game, checkpoint, error, sizeof(error))) {
            fprintf(log, "ERROR qualified checkpoint load: %s\n", error); goto cleanup;
        }
        fprintf(log, "RESUME validated same-build checkpoint; frame=%u\n",
                new_horizons_recomp_current_frame(game));
    }
    if (!new_horizons_recomp_enable_port_ui_capture(game)) {
        fprintf(log, "ERROR allocating observational UI capture\n"); goto cleanup;
    }
    script = _wfopen(args[3], L"r");
    if (!script) goto cleanup;
    fprintf(log, "START natural guest fields; same frontend adapter; no wall-clock pacing/device\n");
    while (fgets(line, sizeof(line), script)) {
        unsigned frame, row_wide = 0u, row_native = 0u;
        unsigned row_native_black = 0u, row_native_visible = 0u, row_native_unavailable = 0u;
        uint64_t row_ticks = 0u, max_frame_ticks = 0u;
        char extra;
        if (!strncmp(line, "#native-profile=1", 17u)) {
            if (fields || rows || new_horizons_recomp_widescreen_enabled(game) ||
                !new_horizons_recomp_disable_port_ui_capture(game)) goto cleanup;
            native_profile = 1;
            fprintf(log, "PROFILE native original display; presentation observation disabled; NOT a widescreen acceptance test\n");
            continue;
        }
        if (!strncmp(line, "#watch-sea-weather=1", 20u)) {
            watch_weather = 1;
            weather_known = new_horizons_recomp_observe_sea_weather(game,
                &previous_weather, &previous_mosaic);
            fprintf(log, "WATCH Sea weather changes; read-only once per natural field; baseline_known=%d flags=%02X mosaic=%02X\n",
                weather_known, previous_weather, previous_mosaic);
            continue;
        }
        if (!strncmp(line, "#expect-final=native", 20u)) {
            expect_native_end = 1;
            expect_combat_end = 0;
            expect_sea_end = 0;
            fprintf(log, "EXPECT final unsupported scene retains original native layout\n");
            continue;
        }
        if (!strncmp(line, "#expect-final=combat", 20u)) {
            expect_native_end = 0;
            expect_combat_end = 1;
            expect_sea_end = 0;
            fprintf(log, "EXPECT final source-qualified Combat512x288\n");
            continue;
        }
        if (!strncmp(line, "#expect-final=sea", 17u)) {
            expect_native_end = expect_combat_end = 0;
            expect_sea_end = 1;
            fprintf(log, "EXPECT final source-qualified Sailing512x288\n");
            continue;
        }
        if (strcmp(line, "#wide=1\n") == 0 || strcmp(line, "#wide=0\n") == 0 ||
            strcmp(line, "#wide=1\r\n") == 0 || strcmp(line, "#wide=0\r\n") == 0) {
            if (native_profile && line[6] == '1') goto cleanup;
            if (!new_horizons_recomp_set_widescreen(game, line[6] == '1', error, sizeof(error))) goto cleanup;
            fprintf(log, "PRESENTATION requested=%d; no guest advancement\n", line[6] == '1');
            continue;
        }
        if (line[0] == '#' || line[0] == '\n' || line[0] == '\r') continue;
        if (++rows > 512u || sscanf(line, "%u,%u,%u,%u %c", &step, &mask,
            &hold, &duration, &extra) != 4 || mask > 0xfff0u || (mask & 15u) ||
            !duration || duration > 3600u || hold > duration) goto cleanup;
        for (frame = 0u; frame < duration; ++frame) {
            NewHorizonsRecompFrameResult result;
            LARGE_INTEGER frame_start, frame_end;
            int16_t samples[2048];
            size_t count;
            QueryPerformanceCounter(&frame_start);
            if (!new_horizons_recomp_advance(game, (uint16_t)(frame < hold ? mask : 0u), 1u, &result)) {
                fprintf(log, "ERROR step=%u field=%u %s\n", step, fields,
                    new_horizons_recomp_last_error(game)); goto cleanup;
            }
            ++fields;
            if (new_horizons_recomp_widescreen_enabled(game)) {
                if (new_horizons_recomp_frame_width(game) == 512u) ++row_wide;
                else {
                    const uint32_t *native_image = new_horizons_recomp_frame_bgra(game);
                    const unsigned native_width = new_horizons_recomp_frame_width(game);
                    const unsigned native_height = new_horizons_recomp_frame_height(game);
                    unsigned visible = 0u;
                    ++row_native;
                    if (!native_image || !native_width || !native_height) ++row_native_unavailable;
                    else {
                        size_t pixel, pixels = (size_t)native_width * native_height;
                        for (pixel=0u; pixel<pixels; ++pixel)
                            if (native_image[pixel] & 0x00FFFFFFu) { visible=1u; break; }
                        if (visible) ++row_native_visible;
                        else ++row_native_black;
                    }
                    /* A first black upload frame must not hide a later
                     * unsupported visible page. Observe completed host RGB
                     * only; no guest input/time/snapshot field is changed. */
                    if (step >= 2100u && (row_native == 1u || (visible && row_native_visible == 1u))) {
                        wchar_t fallback_name[96];
                        swprintf(fallback_name, 96u, L"%ls-step-%u-field-%u",
                            row_native==1u ? L"first-native" : L"first-visible-native", step, frame);
                        if (!nh_present_snapshot(game, args[4], fallback_name, log) ||
                            !nh_present_ppm(args[4], fallback_name, new_horizons_recomp_frame_bgra(game),
                                new_horizons_recomp_frame_width(game), new_horizons_recomp_frame_height(game))) goto cleanup;
                        {
                            wchar_t diagnostic_path[32768];
                            char diagnostic_utf8[131072];
                            swprintf(diagnostic_path, 32768u, L"%ls\\%ls.txt", args[4], fallback_name);
                            if (!wide_to_utf8(diagnostic_path, diagnostic_utf8, sizeof(diagnostic_utf8)) ||
                                !new_horizons_recomp_write_diagnostic_log(game, diagnostic_utf8,
                                    NULL, error, sizeof(error))) goto cleanup;
                        }
                        fprintf(log, "%s step=%u row_field=%u captured for source-gate diagnosis\n",
                            row_native==1u ? "FIRST-NATIVE" : "FIRST-VISIBLE-NATIVE", step, frame);
                    }
                }
            }
            while ((count = new_horizons_recomp_audio_read(game, samples, 1024u)) != 0u) {
                pcm_hash = nh_present_hash(pcm_hash, samples, count * 2u * sizeof(int16_t));
                pcm_frames += count;
            }
            QueryPerformanceCounter(&frame_end);
            {
                uint64_t ticks = (uint64_t)(frame_end.QuadPart - frame_start.QuadPart);
                row_ticks += ticks;
                if (ticks > max_frame_ticks) max_frame_ticks = ticks;
            }
            if (watch_weather) {
                uint8_t weather, mosaic;
                if (new_horizons_recomp_observe_sea_weather(game, &weather, &mosaic)) {
                    int changed = weather_known &&
                        ((weather & 15u) != (previous_weather & 15u) || mosaic != previous_mosaic);
                    previous_weather = weather; previous_mosaic = mosaic; weather_known = 1;
                    if (changed) {
                        fprintf(log, "SEA-WEATHER-CHANGE step=%u field=%u flags=%02X mosaic=%02X; capture this field and end script\n",
                            step, fields, weather, mosaic);
                        /* Stop only the host script. Normal field execution,
                         * input release and PCM drain have already completed.
                         * The normal row-end path captures both images/state. */
                        duration = frame + 1u; stop_script = 1;
                        break;
                    }
                } else weather_known = 0;
            }
        }
        fprintf(log, "STEP %u fields=%u\n", step, fields);
        fprintf(log, "HOST step=%u avg_ms=%.3f max_ms=%.3f unpaced_fps=%.2f target_budget_ms=%.3f (core+adapter+PCM drain; not device/paint acceptance)\n",
            step, 1000.0 * (double)row_ticks / (double)host_frequency.QuadPart / duration,
            1000.0 * (double)max_frame_ticks / (double)host_frequency.QuadPart,
            row_ticks ? (double)duration * (double)host_frequency.QuadPart / (double)row_ticks : 0.0,
            1000.0 * NEW_HORIZONS_RECOMP_PRESENTATION_FPS_DENOMINATOR /
                NEW_HORIZONS_RECOMP_PRESENTATION_FPS_NUMERATOR);
        if (row_wide || row_native)
            fprintf(log, "PRESENTED step=%u expanded=%u native=%u\n", step, row_wide, row_native);
        if (row_native)
            fprintf(log, "NATIVE-FIELDS step=%u black=%u visible=%u unavailable=%u (completed RGB, not a scene-completion claim)\n",
                step, row_native_black, row_native_visible, row_native_unavailable);
        if (native_profile) {
            /* Keep normal native output/state evidence, never silently call
             * the wide qualification/toggle helpers and re-enable capture. */
            if (step >= 2000u) {
                wchar_t name[64];
                swprintf(name, 64u, L"step-%u", step);
                if (!nh_present_snapshot(game, args[4], name, log) ||
                    !nh_present_ppm(args[4], name, new_horizons_recomp_frame_bgra(game),
                        new_horizons_recomp_frame_width(game), new_horizons_recomp_frame_height(game))) goto cleanup;
            }
            if (stop_script) break;
            continue;
        }
        /* Explicit semantic capture IDs, not a picture/snapshot every field.
         * Same published frontend image and normal transactional snapshot API. */
        if (step >= 2000u) {
            wchar_t name[64];
            const int requested = new_horizons_recomp_widescreen_enabled(game);
            const uint32_t *image;
            if (!new_horizons_recomp_set_widescreen(game, 0, error, sizeof(error))) goto cleanup;
            image = new_horizons_recomp_frame_bgra(game);
            swprintf(name, 64u, L"step-%u", step);
            if (!image || !nh_present_ppm(args[4], name, image,
                    new_horizons_recomp_frame_width(game),
                    new_horizons_recomp_frame_height(game)) ||
                !nh_present_snapshot(game, args[4], name, log)) goto cleanup;
            {
                uint16_t *composed = (uint16_t *)malloc(512u * 288u * sizeof(uint16_t));
                uint32_t *bgra = (uint32_t *)malloc(512u * 288u * sizeof(uint32_t));
                unsigned origin, pixel, scene;
                if (!composed || !bgra) { free(composed); free(bgra); goto cleanup; }
                if (new_horizons_recomp_read_presentation_frame(game, composed, 512u * 288u, &origin, &scene)) {
                    swprintf(name, 64u, L"step-%u-wide", step);
                    for (pixel = 0; pixel < 512u * 288u; ++pixel) bgra[pixel] = nh_present_bgra(composed[pixel]);
                    if (!new_horizons_recomp_set_widescreen(game, 1, error, sizeof(error)) ||
                        new_horizons_recomp_frame_width(game) != 512u ||
                        new_horizons_recomp_frame_height(game) != 288u ||
                        memcmp(bgra, new_horizons_recomp_frame_bgra(game), 512u * 288u * sizeof(uint32_t)) ||
                        !nh_present_ppm(args[4], name, new_horizons_recomp_frame_bgra(game), 512u, 288u)) {
                        free(composed); free(bgra); goto cleanup;
                    }
                    fprintf(log, "UI-COMPOSITE step=%u scene=%s connected frontend exact512x288 originY=%d\n",
                        step, scene == 3u ? "Sailing" : scene == 2u ? "Combat" : "Port", (int)(int32_t)origin);
                } else {
                    if (!new_horizons_recomp_set_widescreen(game, 1, error, sizeof(error)) ||
                        new_horizons_recomp_frame_width(game) != 256u ||
                        new_horizons_recomp_frame_height(game) != 239u ||
                        memcmp(image, new_horizons_recomp_frame_bgra(game), 256u * 239u * sizeof(uint32_t))) {
                        free(composed); free(bgra); goto cleanup;
                    }
                    fprintf(log, "UI-COMPOSITE step=%u intentionally native/unchanged; expanded scene not qualified\n", step);
                }
                free(composed); free(bgra);
            }
            if (!new_horizons_recomp_set_widescreen(game, requested, error, sizeof(error))) goto cleanup;
        }
        if (stop_script) break;
    }
    if (ferror(script) || !fields) goto cleanup;
    if (native_profile) {
        if (new_horizons_recomp_widescreen_enabled(game) ||
            new_horizons_recomp_frame_width(game) != 256u ||
            new_horizons_recomp_frame_height(game) != 239u) goto cleanup;
        fprintf(log, "PROFILE ONLY original native output; no widescreen/layout/observer acceptance claimed\n");
        fprintf(log, "fields=%u pcm_frames=%llu pcm_fnv1a64=%016llX\n", fields,
            (unsigned long long)pcm_frames, (unsigned long long)pcm_hash);
        exit_code = 0;
        goto cleanup;
    }
    if (!new_horizons_recomp_set_widescreen(game, 0, error, sizeof(error))) goto cleanup;
    {
        const uint32_t *native = new_horizons_recomp_frame_bgra(game), *wide;
        unsigned x, y, nonzero = 0u;
        uint32_t saved_native[256u * 239u];
        uint32_t frame_before = new_horizons_recomp_current_frame(game);
        uint64_t instructions_before = new_horizons_recomp_instruction_count(game);
        if (!native || new_horizons_recomp_frame_width(game) != 256u ||
            new_horizons_recomp_frame_height(game) != 239u) goto cleanup;
        memcpy(saved_native, native, sizeof(saved_native));
        for (y = 224u; y < 239u; ++y) for (x = 0u; x < 256u; ++x)
            if (saved_native[y * 256u + x] != 0u) {
                fprintf(log, "ERROR expected proved224-line Port frame\n"); goto cleanup;
            }
        if (!nh_present_ppm(args[4], expect_sea_end ? L"sea-native" : expect_combat_end ? L"combat-native" : L"port-native", native, 256u, 239u) ||
            !new_horizons_recomp_set_widescreen(game, 1, error, sizeof(error))) goto cleanup;
        wide = new_horizons_recomp_frame_bgra(game);
        if (expect_native_end) {
            if (!wide || new_horizons_recomp_frame_width(game) != 256u ||
                new_horizons_recomp_frame_height(game) != 239u ||
                memcmp(saved_native, wide, sizeof(saved_native)) ||
                !nh_present_snapshot(game, args[4], L"native-scene-checkpoint", log)) goto cleanup;
        } else {
            if (!wide || new_horizons_recomp_frame_width(game) != 512u ||
                new_horizons_recomp_frame_height(game) != 288u) {
                fprintf(log, "ERROR expected %s512x288, actual%ux%u; source qualification rejected\n",
                    expect_sea_end ? "Sailing" : expect_combat_end ? "Combat" : "Port",
                    new_horizons_recomp_frame_width(game), new_horizons_recomp_frame_height(game));
                goto cleanup;
            }
            for (y = 0u; y < 288u; ++y) for (x = 0u; x < 512u; ++x)
                nonzero += wide[y * 512u + x] != 0u;
            if (!nonzero || !nh_present_ppm(args[4], expect_sea_end ? L"sea-connected-wide" : expect_combat_end ? L"combat-connected-wide" : L"port-connected-wide", wide, 512u, 288u)) goto cleanup;
        }
        if (!new_horizons_recomp_set_widescreen(game, 0, error, sizeof(error)) ||
            memcmp(saved_native, new_horizons_recomp_frame_bgra(game), sizeof(saved_native)) ||
            frame_before != new_horizons_recomp_current_frame(game) ||
            instructions_before != new_horizons_recomp_instruction_count(game) ||
            new_horizons_recomp_frame_width(game) != 256u ||
            new_horizons_recomp_frame_height(game) != 239u) goto cleanup;
        if (expect_native_end)
            fprintf(log, "PASS expected native scene: ON/OFF original256x239 pixels/layout exact; no guest frame/instruction advancement\n");
        else
            fprintf(log, "PASS CONNECTED512x288 nonzero=%u; OFF restores original256x239 pixels/layout; native toggle roundtrip exact; no guest frame/instruction advancement\n", nonzero);
        fprintf(log, "fields=%u pcm_frames=%llu pcm_fnv1a64=%016llX\n", fields,
            (unsigned long long)pcm_frames, (unsigned long long)pcm_hash);
        if (expect_combat_end || expect_sea_end) {
            uint16_t *composite = (uint16_t *)malloc(512u * 288u * sizeof(uint16_t));
            unsigned origin, scene;
            int qualified;
            if (!composite || !nh_present_snapshot(game, args[4], expect_sea_end ? L"sea-before-observer" : L"combat-before-observer", log)) {
                free(composite); goto cleanup;
            }
            qualified = new_horizons_recomp_read_presentation_frame(game, composite,
                512u * 288u, &origin, &scene) && scene == (expect_sea_end ? 3u : 2u);
            free(composite);
            if (!qualified || !nh_present_snapshot(game, args[4], expect_sea_end ? L"sea-after-observer" : L"combat-after-observer", log)) {
                fprintf(log, "ERROR final source-qualified %s composite unavailable\n", expect_sea_end ? "Sailing" : "Combat"); goto cleanup;
            }
            fprintf(log, "%s connected source composite originY=%d; before/after observer snapshots saved for byte comparison\n", expect_sea_end ? "SEA" : "COMBAT", (int)(int32_t)origin);
        } else if (!expect_native_end && !nh_present_terrain(game, args[4], log)) goto cleanup;
        exit_code = 0;
    }
cleanup:
    if (log) { fprintf(log, "EXIT %d\n", exit_code); fclose(log); }
    if (script) fclose(script);
    free(rom);
    new_horizons_recomp_destroy(game);
    LocalFree(args);
    return exit_code;
}

/* Paint through the real GDI drawing owner into a private DIB, not a screen
 * capture or a second renderer. Never shows/activates the hidden window. */
static int nh_presentation_paint_check(const wchar_t *directory, FILE *log) {
    BITMAPINFO bitmap;
    HDC dc = NULL;
    HBITMAP dib = NULL;
    HGDIOBJ old = NULL;
    uint32_t *pixels = NULL, *native = NULL;
    RECT outer = {0,0,1280,800};
    unsigned hidden, scale, x, y;
    int ok = 0;
    uint32_t frame = new_horizons_recomp_current_frame(g_game);
    uint64_t instructions = new_horizons_recomp_instruction_count(g_game);
    wchar_t path[32768], exported[32768];
    memset(&bitmap,0,sizeof(bitmap));
    bitmap.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);
    bitmap.bmiHeader.biWidth=1280;bitmap.bmiHeader.biHeight=-800;
    bitmap.bmiHeader.biPlanes=1;bitmap.bmiHeader.biBitCount=32;
    bitmap.bmiHeader.biCompression=BI_RGB;
    dc=CreateCompatibleDC(NULL);
    if(!dc)goto cleanup;
    dib=CreateDIBSection(dc,&bitmap,DIB_RGB_COLORS,(void**)&pixels,NULL,0);
    native=(uint32_t*)malloc(1280u*800u*4u);
    if(!dib||!native)goto cleanup;
    old=SelectObject(dc,dib);
    AdjustWindowRectEx(&outer,(DWORD)GetWindowLongW(g_window,GWL_STYLE),TRUE,
        (DWORD)GetWindowLongW(g_window,GWL_EXSTYLE));
    SetWindowPos(g_window,NULL,0,0,outer.right-outer.left,outer.bottom-outer.top,
        SWP_NOMOVE|SWP_NOACTIVATE|SWP_NOZORDER);
    if(IsWindowVisible(g_window))goto cleanup;
    for(hidden=0;hidden<2;++hidden)for(scale=0;scale<=4;scale+=2){
        unsigned left=1280,top=800,right=0,bottom=0;
        unsigned width=scale?1024u:1280u,height=scale?576u:720u;
        unsigned expected_x=(1280u-width)/2u;
        unsigned expected_y=(hidden?0u:80u)+((hidden?800u:720u)-height)/2u;
        g_presentation_hidden=(int)hidden;
        g_frontend_settings.integer_scale=(int)scale;
        if(!apply_widescreen_setting(0,0))goto cleanup;
        draw_window_contents(g_window,dc);
        GdiFlush();memcpy(native,pixels,1280u*800u*4u);
        if(!apply_widescreen_setting(1,0)||new_horizons_recomp_frame_width(g_game)!=512u)goto cleanup;
        draw_window_contents(g_window,dc);GdiFlush();
        for(y=0;y<800;++y)for(x=0;x<1280;++x)if(pixels[y*1280u+x]&0xffffffu){
            if(x<left)left=x;
            if(x+1u>right)right=x+1u;
            if(y<top)top=y;
            if(y+1u>bottom)bottom=y+1u;
        }
        if(left!=expected_x||top!=expected_y||right-left!=width||bottom-top!=height){
            fprintf(log,"FAIL paint geometry hidden=%u scale=%u actual=%u,%u %ux%u expected=%u,%u %ux%u\n",
                hidden,scale,left,top,right-left,bottom-top,expected_x,expected_y,width,height);goto cleanup;
        }
        if(!hidden&&!scale){
            swprintf(path,32768u,L"%ls\\wide-window-paint.bmp",directory);
            if(!save_bgra_bmp(path,(const uint8_t*)pixels,1280,800,1280*4))goto cleanup;
            swprintf(path,32768u,L"%ls\\wide-export",directory);
            if(!capture_core_screenshot_to(path,exported,32768u))goto cleanup;
        }
        if(!apply_widescreen_setting(0,0))goto cleanup;
        draw_window_contents(g_window,dc);GdiFlush();
        if(memcmp(native,pixels,1280u*800u*4u)||
            new_horizons_recomp_frame_width(g_game)!=256u||
            new_horizons_recomp_frame_height(g_game)!=239u)goto cleanup;
        if(!hidden&&!scale){
            swprintf(path,32768u,L"%ls\\native-window-paint.bmp",directory);
            if(!save_bgra_bmp(path,(const uint8_t*)pixels,1280,800,1280*4))goto cleanup;
            swprintf(path,32768u,L"%ls\\native-export",directory);
            if(!capture_core_screenshot_to(path,exported,32768u))goto cleanup;
        }
        fprintf(log,"PASS actual GDI paint hidden-toolbar=%u integer-setting=%u wide=%ux%u@%u,%u; OFF original paint exact\n",
            hidden,scale,width,height,left,top);
    }
    if(frame!=new_horizons_recomp_current_frame(g_game)||
       instructions!=new_horizons_recomp_instruction_count(g_game))goto cleanup;
    ok=1;
cleanup:
    g_presentation_hidden=0;g_frontend_settings.integer_scale=0;
    if(old)SelectObject(dc,old);
    if(dib)DeleteObject(dib);
    if(dc)DeleteDC(dc);
    free(native);
    return ok;
}

/* Exercise the actual opaque reset/load paths after a qualified wide frame.
 * No device, guest intervention, alternate executable or compatibility bypass.
 * Keep exact pre-reset native/wide pixels and require the same one-field
 * continuation after normal snapshot load rebuilds host-only capture. */
static int nh_presentation_reset_restore_check(const char *state, FILE *log) {
    const size_t native_count = 256u * 239u, wide_count = 512u * 288u;
    uint32_t *saved = (uint32_t *)malloc((native_count + wide_count) * sizeof(*saved));
    uint32_t frame;
    uint64_t instructions;
    size_t audio;
    int ok = 0;
    char error[4096];
    NewHorizonsRecompFrameResult advanced;
    if (!saved || !apply_widescreen_setting(0, 0)) goto cleanup;
    if (!new_horizons_recomp_frame_bgra(g_game)) goto cleanup;
    memcpy(saved, new_horizons_recomp_frame_bgra(g_game), native_count * sizeof(*saved));
    if (!apply_widescreen_setting(1, 0) || new_horizons_recomp_frame_width(g_game) != 512u)
        goto cleanup;
    memcpy(saved + native_count, new_horizons_recomp_frame_bgra(g_game), wide_count * sizeof(*saved));
    frame = new_horizons_recomp_current_frame(g_game);
    instructions = new_horizons_recomp_instruction_count(g_game);
    audio = new_horizons_recomp_audio_available(g_game);
    if (!new_horizons_recomp_reset(g_game, error, sizeof(error)) ||
        !new_horizons_recomp_widescreen_enabled(g_game) ||
        /* This is the existing hardware/CPU RESET, not a fresh power-on:
         * reset_control preserves published_sequence and machine clocks. */
        new_horizons_recomp_current_frame(g_game) < frame ||
        new_horizons_recomp_frame_bgra(g_game) != NULL ||
        new_horizons_recomp_audio_available(g_game) != 0u) goto cleanup;
    if (!new_horizons_recomp_advance(g_game, 0u, 1u, &advanced) ||
        new_horizons_recomp_frame_width(g_game) != 256u ||
        new_horizons_recomp_frame_height(g_game) != 239u ||
        !new_horizons_recomp_widescreen_enabled(g_game)) goto cleanup;
    fprintf(log, "PASS hardware reset from wide Port preserves requested mode/monotonic frame counter, clears stale frame/audio and presents native reset output\n");
    if (!new_horizons_recomp_snapshot_load(g_game, state, error, sizeof(error)) ||
        !new_horizons_recomp_advance(g_game, 0u, 1u, &advanced) ||
        new_horizons_recomp_frame_width(g_game) != 512u ||
        new_horizons_recomp_frame_height(g_game) != 288u ||
        new_horizons_recomp_current_frame(g_game) != frame ||
        new_horizons_recomp_instruction_count(g_game) != instructions ||
        new_horizons_recomp_audio_available(g_game) != audio ||
        memcmp(saved + native_count, new_horizons_recomp_frame_bgra(g_game), wide_count * sizeof(*saved)))
        goto cleanup;
    if (!apply_widescreen_setting(0, 0) ||
        memcmp(saved, new_horizons_recomp_frame_bgra(g_game), native_count * sizeof(*saved))) goto cleanup;
    fprintf(log, "PASS normal same-build snapshot load rebuilds wide capture; identical native/wide continuation pixels, frame/instruction and PCM queue counts\n");
    ok = 1;
cleanup:
    free(saved);
    return ok;
}

/* ROM-free check of the actual launcher controls and settings backend. No
 * alternate executable, visible window, device audio or user settings paths. */
/* Reproduce the reported real snapshot through the production adapter, both
 * fresh and after advancing the same live instance. No alternate test EXE. */
static void nh_snapshot_drain(NewHorizonsRecomp *game, void *opaque) {
    int16_t pcm[256];
    (void)opaque;
    while (new_horizons_recomp_audio_read(game,pcm,128u)) {}
}

static int nh_snapshot_roundtrip_cli(void) {
    LPWSTR *args; int argc,exit_code=1;
    NewHorizonsRecomp *game=NULL,*cold=NULL;
    uint8_t *rom=NULL;size_t size=0;
    uint8_t reset_sram[NEW_HORIZONS_RECOMP_SRAM_FILE_SIZE],after_sram[NEW_HORIZONS_RECOMP_SRAM_FILE_SIZE];
    char state[131072],fresh[131072],error[4096];wchar_t why[512],path[32768];
    FILE *log=NULL;unsigned wide,pass,field;
    uint64_t baseline=0u;
    args=CommandLineToArgvW(GetCommandLineW(),&argc);
    if(!args)return -1;
    if(argc<2||wcscmp(args[1],L"--snapshot-roundtrip-headless")){LocalFree(args);return -1;}
    if(argc!=5){LocalFree(args);return 2;}
    swprintf(path,32768u,L"%ls\\snapshot-roundtrip.txt",args[4]);
    log=_wfopen(path,L"w");if(!log)goto cleanup;
    setvbuf(log,NULL,_IOLBF,0u);
    if(!read_rom_file(args[2],&rom,&size,why,512u)||
       !wide_to_utf8(args[3],state,sizeof(state)))goto cleanup;
    for(wide=0u;wide<2u;++wide){
        if(!new_horizons_recomp_create(&game,rom,size,error,sizeof(error)))goto failure;
        if(!new_horizons_recomp_enable_port_ui_capture(game)||
           !new_horizons_recomp_set_widescreen(game,(int)wide,error,sizeof(error)))goto failure;
        for(pass=0u;pass<3u;++pass){
            uint64_t hash=UINT64_C(14695981039346656037);
            if(pass==1u){
                if(!new_horizons_recomp_sram_copy(game,reset_sram,sizeof(reset_sram)) ||
                   !new_horizons_recomp_create(&cold,rom,size,error,sizeof(error)) ||
                   !new_horizons_recomp_sram_load(cold,reset_sram,sizeof(reset_sram),error,sizeof(error)) ||
                   !new_horizons_recomp_enable_port_ui_capture(cold) ||
                   !new_horizons_recomp_set_widescreen(cold,(int)wide,error,sizeof(error)))goto failure;
            }
            if(pass && !new_horizons_recomp_reset(game,error,sizeof(error)))goto failure;
            if(pass==1u){
                if(new_horizons_recomp_current_frame(game)!=0u ||
                   !new_horizons_recomp_sram_copy(game,after_sram,sizeof(after_sram)) ||
                   memcmp(reset_sram,after_sram,sizeof(reset_sram))){
                    fprintf(log,"FAIL Reset did not restart at frame zero with identical battery data\n");goto cleanup;
                }
                for(field=0u;field<1800u;++field){
                    NewHorizonsRecompFrameResult result;
                    if(!new_horizons_recomp_advance_streamed(game,0u,1u,nh_snapshot_drain,NULL,&result) ||
                       !new_horizons_recomp_advance_streamed(cold,0u,1u,nh_snapshot_drain,NULL,&result))goto failure;
                    if(new_horizons_recomp_current_frame(game)!=new_horizons_recomp_current_frame(cold) ||
                       new_horizons_recomp_frame_width(game)!=new_horizons_recomp_frame_width(cold) ||
                       new_horizons_recomp_frame_height(game)!=new_horizons_recomp_frame_height(cold) ||
                       memcmp(new_horizons_recomp_frame_bgra(game),new_horizons_recomp_frame_bgra(cold),
                           (size_t)new_horizons_recomp_frame_width(game)*new_horizons_recomp_frame_height(game)*sizeof(uint32_t))){
                        fprintf(log,"FAIL Reset differs from cold boot at field %u\n",field);goto cleanup;
                    }
                }
                fprintf(log,"PASS Reset frame zero, battery unchanged, all1800 opening frames identical to fresh cold boot\n");
                swprintf(path,32768u,L"reset-title-wide%u",wide);
                if(!nh_present_ppm(args[4],path,new_horizons_recomp_frame_bgra(game),
                    new_horizons_recomp_frame_width(game),new_horizons_recomp_frame_height(game)))goto cleanup;
                new_horizons_recomp_destroy(cold);cold=NULL;
            }
            if(!new_horizons_recomp_snapshot_load(game,pass?fresh:state,error,sizeof(error)))goto failure;
            if(!pass){
                swprintf(path,32768u,L"%ls\\saved-wide%u.nhsnap",args[4],wide);
                if(!wide_to_utf8(path,fresh,sizeof(fresh))||
                   !new_horizons_recomp_snapshot_save(game,fresh,error,sizeof(error)))goto failure;
            }
            for(field=0u;field<300u;++field){
                NewHorizonsRecompFrameResult result;
                if(!new_horizons_recomp_advance_streamed(game,0u,1u,nh_snapshot_drain,NULL,&result))goto failure;
                hash=nh_present_hash(hash,new_horizons_recomp_frame_bgra(game),
                    (size_t)new_horizons_recomp_frame_width(game)*new_horizons_recomp_frame_height(game)*sizeof(uint32_t));
            }
            if(!pass)baseline=hash;
            else if(hash!=baseline){snprintf(error,sizeof(error),"Repeated live load changed output");goto failure;}
            swprintf(path,32768u,L"roundtrip-wide%u-pass%u",wide,pass);
            if(!nh_present_snapshot(game,args[4],path,log))goto cleanup;
            fprintf(log,"PASS wide=%u pass=%u frame=%u pixels=%016llX streamed300 neutral fields\n",wide,pass,
                new_horizons_recomp_current_frame(game),(unsigned long long)hash);
        }
        new_horizons_recomp_destroy(game);game=NULL;
    }
    exit_code=0;goto cleanup;
failure:
    fprintf(log,"FAIL %s\n",game?new_horizons_recomp_last_error(game):error);
cleanup:
    if(cold)new_horizons_recomp_destroy(cold);
    if(game)new_horizons_recomp_destroy(game);
    free(rom);LocalFree(args);
    if(log){fprintf(log,"EXIT %d\n",exit_code);fclose(log);}
    return exit_code;
}

static int nh_presentation_controls_cli(void) {
    LPWSTR *args;
    int argc, result = 1;
    FILE *log = NULL;
    wchar_t path[32768];
    WNDCLASSEXW cls;
    NewHorizonsFrontendSettingsWin32 restored;
    RECT client, control;
    args = CommandLineToArgvW(GetCommandLineW(), &argc);
    if (!args) return -1;
    if (argc < 2 || wcscmp(args[1], L"--presentation-controls-headless")) {
        LocalFree(args); return -1;
    }
    if (argc != 3 && argc != 5) { LocalFree(args); return 2; }
    swprintf(path, 32768u, L"%ls\\controls-result.txt", args[2]);
    log = _wfopen(path, L"w");
    if (!log) goto cleanup;
    swprintf(g_settings_ini_path, PATH_CAPACITY, L"%ls\\controls-test.ini", args[2]);
    if (GetFileAttributesW(g_settings_ini_path) != INVALID_FILE_ATTRIBUTES) {
        fprintf(log, "ERROR test INI already exists; use a fresh evidence directory\n"); goto cleanup;
    }
    g_instance = GetModuleHandleW(NULL);
    new_horizons_frontend_settings_win32_defaults(&g_frontend_settings);
    g_settings_saved_on_exit = 1; /* Destruction must not overwrite the test receipt. */
    g_menu = create_menu_bar();
    memset(&cls, 0, sizeof(cls));
    cls.cbSize = sizeof(cls); cls.lpfnWndProc = window_proc;
    cls.hInstance = g_instance; cls.lpszClassName = APP_CLASS_NAME;
    if (!RegisterClassExW(&cls)) goto cleanup;
    cls.lpfnWndProc = info_dialog_proc; cls.lpszClassName = INFO_CLASS_NAME;
    if (!RegisterClassExW(&cls)) goto cleanup;
    g_window = CreateWindowExW(0, APP_CLASS_NAME, LAUNCHER_TITLE,
        WS_OVERLAPPEDWINDOW, 0, 0, 820, 580, NULL, g_menu, g_instance, NULL);
    if (!g_window) goto cleanup;
#define NH_CONTROL_CHECK(condition, label) do { if (!(condition)) { fprintf(log, "FAIL %s\n", label); goto cleanup; } fprintf(log, "PASS %s\n", label); } while (0)
    NH_CONTROL_CHECK(!IsWindowVisible(g_window), "headless launcher remains hidden");
    NH_CONTROL_CHECK(!g_frontend_settings.widescreen &&
        SendMessageW(g_widescreen_checkbox, BM_GETCHECK, 0, 0) == BST_UNCHECKED,
        "default is original layout");
    SendMessageW(g_window, WM_COMMAND, ID_WIDESCREEN, 0);
    NH_CONTROL_CHECK(g_frontend_settings.widescreen &&
        SendMessageW(g_widescreen_checkbox, BM_GETCHECK, 0, 0) == BST_CHECKED &&
        (GetMenuState(g_menu, ID_WIDESCREEN, MF_BYCOMMAND) & MF_CHECKED),
        "menu updates shared setting and toolbar");
    NH_CONTROL_CHECK(IsWindow(g_info_window) && !IsWindowVisible(g_info_window) &&
        g_info_state.widescreen_notice && !g_frontend_settings.widescreen_notice_shown &&
        GetDlgItem(g_info_window, ID_INFO_CLOSE) &&
        (SendMessageW(g_info_window, DM_GETDEFID, 0, 0) & 0xffffu) == ID_INFO_CLOSE,
        "first menu click opens experimental notice with bottom default Close; not accepted before close");
    GetClientRect(g_info_window, &client);
    GetWindowRect(GetDlgItem(g_info_window, ID_INFO_CLOSE), &control);
    MapWindowPoints(NULL, g_info_window, (POINT *)&control, 2);
    NH_CONTROL_CHECK(control.bottom <= client.bottom && control.top >= client.bottom-60 &&
        control.left >= 0 && control.right <= client.right,
        "notice Close button fits at bottom");
    SendMessageW(g_info_window, WM_COMMAND, ID_INFO_CLOSE, 0);
    NH_CONTROL_CHECK(!IsWindow(g_info_window) && g_frontend_settings.widescreen_notice_shown,
        "Close accepts and dismisses notice");
    new_horizons_frontend_settings_win32_load(&restored, g_settings_ini_path);
    NH_CONTROL_CHECK(restored.widescreen == 1 && restored.widescreen_notice_shown,
        "enabled setting and one-time acknowledgement reload from isolated INI");
    SendMessageW(g_widescreen_checkbox, BM_CLICK, 0, 0);
    NH_CONTROL_CHECK(!g_frontend_settings.widescreen &&
        SendMessageW(g_widescreen_checkbox, BM_GETCHECK, 0, 0) == BST_UNCHECKED &&
        !(GetMenuState(g_menu, ID_WIDESCREEN, MF_BYCOMMAND) & MF_CHECKED),
        "toolbar disables and synchronizes menu");
    NH_CONTROL_CHECK(!IsWindow(g_info_window), "subsequent toolbar click does not repeat notice");
    new_horizons_frontend_settings_win32_load(&restored, g_settings_ini_path);
    NH_CONTROL_CHECK(restored.widescreen == 0, "original-layout setting reloads from isolated INI");
    g_frontend_settings=restored;
    SendMessageW(g_window, WM_COMMAND, ID_WIDESCREEN, 0);
    NH_CONTROL_CHECK(!IsWindow(g_info_window) && g_frontend_settings.widescreen,
        "reloaded acknowledgement suppresses notice on next menu enable");
    SendMessageW(g_window, WM_COMMAND, ID_WIDESCREEN, 0);
    NH_CONTROL_CHECK(new_horizons_frontend_settings_win32_check_widescreen_dialog(g_window,g_instance),
        "actual hidden Settings dialog initializes/toggles/applies ON and OFF; checkbox fits; other settings unchanged");
    GetClientRect(g_window, &client);
    GetWindowRect(g_widescreen_checkbox, &control);
    MapWindowPoints(NULL, g_window, (POINT *)&control, 2);
    NH_CONTROL_CHECK(control.left >= 0 && control.right <= client.right &&
        control.top >= 0 && control.bottom <= client.bottom,
        "widescreen control fits820px minimum window");
    InterlockedExchange(&g_loading, 1);
    update_controls();
    NH_CONTROL_CHECK(!IsWindowEnabled(g_widescreen_checkbox) &&
        (GetMenuState(g_menu, ID_WIDESCREEN, MF_BYCOMMAND) & (MF_DISABLED | MF_GRAYED)),
        "loading disables toolbar and menu presentation controls");
    InterlockedExchange(&g_loading, 0);
    update_controls();
    if(argc==5){
        uint8_t *rom=NULL;size_t size=0;wchar_t rom_error[512];char error[4096],state[131072];
        NewHorizonsRecompFrameResult advanced;
        if(!read_rom_file(args[3],&rom,&size,rom_error,512u))goto cleanup;
        if(!new_horizons_recomp_create(&g_game,rom,size,error,sizeof(error))){free(rom);goto cleanup;}
        free(rom);
        if(!wide_to_utf8(args[4],state,sizeof(state))||
           !new_horizons_recomp_snapshot_load(g_game,state,error,sizeof(error))||
           !new_horizons_recomp_enable_port_ui_capture(g_game)||
           !new_horizons_recomp_advance(g_game,0,1,&advanced))goto cleanup;
        NH_CONTROL_CHECK(nh_presentation_paint_check(args[2],log),
            "connected GDI/native restore/scaling/export; no guest advance during display checks");
        NH_CONTROL_CHECK(nh_presentation_reset_restore_check(state,log),
            "connected wide reset and normal snapshot restore rebuild presentation without stale pixels");
    }
    fprintf(log, "Scope: toolbar/menu/backend persistence and actual hidden Settings dialog; live core geometry checked separately.\n");
    result = 0;
#undef NH_CONTROL_CHECK
cleanup:
    InterlockedExchange(&g_loading, 0);
    if (IsWindow(g_info_window)) DestroyWindow(g_info_window);
    if(g_game){new_horizons_recomp_destroy(g_game);g_game=NULL;}
    if (g_window) { DestroyWindow(g_window); g_window = NULL; }
    if (log) { fprintf(log, "EXIT %d\n", result); fclose(log); }
    LocalFree(args);
    return result;
}
