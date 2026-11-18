#ifndef NEW_HORIZONS_LAUNCH_OPTIONS_H
#define NEW_HORIZONS_LAUNCH_OPTIONS_H

#include <stddef.h>
#include <wchar.h>

/* Headless commands are dispatched before this GUI-only parser. Unknown
   options retain the previous GUI behavior. Repeated options use the last. */
typedef struct NewHorizonsLaunchOptions {
    const wchar_t *game_path;
    int widescreen; /* -1: persisted setting, 0: Original, 1: widescreen */
} NewHorizonsLaunchOptions;

static const wchar_t *new_horizons_parse_launch_options(
    int argc, wchar_t *const *argv, NewHorizonsLaunchOptions *options) {
    int i;
    options->game_path = NULL;
    options->widescreen = -1;
    for (i = 1; i < argc; ++i) {
        if (!wcscmp(argv[i], L"--game")) {
            if (++i >= argc || !argv[i][0] || !wcsncmp(argv[i], L"--", 2u))
                return L"--game requires a ROM path. Quote paths containing spaces.";
            options->game_path = argv[i];
        } else if (!wcscmp(argv[i], L"--port-widescreen") ||
                   !wcscmp(argv[i], L"--port-wide-canvas")) {
            options->widescreen = 1;
        } else if (!wcscmp(argv[i], L"--no-port-widescreen")) {
            options->widescreen = 0;
        }
    }
    return NULL;
}
#endif
