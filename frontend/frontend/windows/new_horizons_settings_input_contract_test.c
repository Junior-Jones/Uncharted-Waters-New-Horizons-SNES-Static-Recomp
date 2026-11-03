#if !defined(_WIN32)
#error This test requires Windows.
#endif

#include <windows.h>

#include <stdio.h>
#include <string.h>

#include "new_horizons_frontend_settings_win32.h"
#include "new_horizons_static_recomp.h"

#define CHECK(expression) do { \
    if (!(expression)) { \
        fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #expression); \
        return 1; \
    } \
} while (0)

int main(void)
{
    static const UINT accessible_keys[NEW_HORIZONS_WIN_BINDING_COUNT] = {
        VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT,
        'D', 'F', 'A', 'S', 'E', 'R', 'G', 'T'
    };
    static const uint16_t masks[NEW_HORIZONS_WIN_BINDING_COUNT] = {
        NEW_HORIZONS_INPUT_UP, NEW_HORIZONS_INPUT_DOWN, NEW_HORIZONS_INPUT_LEFT,
        NEW_HORIZONS_INPUT_RIGHT, NEW_HORIZONS_INPUT_B, NEW_HORIZONS_INPUT_A,
        NEW_HORIZONS_INPUT_Y, NEW_HORIZONS_INPUT_X, NEW_HORIZONS_INPUT_L,
        NEW_HORIZONS_INPUT_R, NEW_HORIZONS_INPUT_START, NEW_HORIZONS_INPUT_SELECT
    };
    static const int gamepad[NEW_HORIZONS_WIN_BINDING_COUNT] = {
        NEW_HORIZONS_GAMEPAD_DPAD_UP, NEW_HORIZONS_GAMEPAD_DPAD_DOWN,
        NEW_HORIZONS_GAMEPAD_DPAD_LEFT, NEW_HORIZONS_GAMEPAD_DPAD_RIGHT,
        NEW_HORIZONS_GAMEPAD_FACE_SOUTH, NEW_HORIZONS_GAMEPAD_FACE_EAST,
        NEW_HORIZONS_GAMEPAD_FACE_WEST, NEW_HORIZONS_GAMEPAD_FACE_NORTH,
        NEW_HORIZONS_GAMEPAD_LEFT_SHOULDER, NEW_HORIZONS_GAMEPAD_RIGHT_SHOULDER,
        NEW_HORIZONS_GAMEPAD_START, NEW_HORIZONS_GAMEPAD_BACK
    };
    NewHorizonsFrontendSettingsWin32 settings;
    NewHorizonsFrontendSettingsWin32 loaded;
    wchar_t path[MAX_PATH];
    int index;

    CHECK(GetFullPathNameW(L"new-horizons-input-settings-contract.ini", MAX_PATH,
                           path, NULL) > 0u);
    (void)DeleteFileW(path);

    new_horizons_frontend_settings_win32_defaults(&settings);
    CHECK(settings.welcome_shown == 0);
    CHECK(settings.show_fps_counter == 0);
    CHECK(settings.ntsc_frame_lock == 1);
    for (index = 0; index < NEW_HORIZONS_WIN_BINDING_COUNT; ++index) {
        CHECK(settings.bindings[index] == accessible_keys[index]);
        CHECK(settings.gamepad_bindings[index] == gamepad[index]);
        CHECK(new_horizons_frontend_settings_win32_input(
                  &settings, settings.bindings[index]) == masks[index]);
    }
    CHECK(settings.bindings[10] == 'G');
    CHECK(settings.bindings[11] == 'T');

    memset(&loaded, 0xff, sizeof(loaded));
    new_horizons_frontend_settings_win32_load(&loaded, path);
    CHECK(loaded.welcome_shown == 0);

    settings.input_source = NEW_HORIZONS_INPUT_SOURCE_GAMEPAD;
    settings.integer_scale = 3;
    settings.pause_on_focus_loss = 1;
    settings.auto_run_on_load = 1;
    settings.fullscreen_on_play = 1;
    settings.welcome_shown = 1;
    settings.show_fps_counter = 1;
    settings.ntsc_frame_lock = 0;
    settings.snapshot_slot = 4;
    CHECK(new_horizons_frontend_settings_win32_save(&settings, path));
    memset(&loaded, 0, sizeof(loaded));
    new_horizons_frontend_settings_win32_load(&loaded, path);
    CHECK(loaded.input_source == NEW_HORIZONS_INPUT_SOURCE_GAMEPAD);
    CHECK(loaded.integer_scale == 3);
    CHECK(loaded.pause_on_focus_loss == 1);
    CHECK(loaded.auto_run_on_load == 1);
    CHECK(loaded.fullscreen_on_play == 1);
    CHECK(loaded.input_source_saved == 1);
    CHECK(loaded.welcome_shown == 1);
    CHECK(loaded.show_fps_counter == 1);
    CHECK(loaded.ntsc_frame_lock == 0);
    CHECK(loaded.snapshot_slot == 4);
    for (index = 0; index < NEW_HORIZONS_WIN_BINDING_COUNT; ++index) {
        CHECK(loaded.bindings[index] == accessible_keys[index]);
        CHECK(loaded.gamepad_bindings[index] == gamepad[index]);
        CHECK(new_horizons_frontend_settings_win32_input(
                  &loaded, loaded.bindings[index]) == masks[index]);
    }

    CHECK(WritePrivateProfileStringW(L"Input", L"Action10", L"84", path));
    CHECK(WritePrivateProfileStringW(L"Input", L"Action11", L"71", path));
    new_horizons_frontend_settings_win32_load(&loaded, path);
    CHECK(loaded.bindings[10] == 'T');
    CHECK(loaded.bindings[11] == 'G');
    CHECK(new_horizons_frontend_settings_win32_input(&loaded, 'T') ==
          NEW_HORIZONS_INPUT_START);
    CHECK(new_horizons_frontend_settings_win32_input(&loaded, 'G') ==
          NEW_HORIZONS_INPUT_SELECT);

    CHECK(WritePrivateProfileStringW(L"Input", L"Action11", L"84", path));
    new_horizons_frontend_settings_win32_load(&loaded, path);
    CHECK(loaded.bindings[10] == 'G');
    CHECK(loaded.bindings[11] == 'T');
    CHECK(new_horizons_frontend_settings_win32_input(&loaded, 'G') ==
          NEW_HORIZONS_INPUT_START);
    CHECK(new_horizons_frontend_settings_win32_input(&loaded, 'T') ==
          NEW_HORIZONS_INPUT_SELECT);

    CHECK(DeleteFileW(path));
    puts("PASS keyboard/gamepad action order, settings round-trip, and invalid-binding recovery");
    return 0;
}
