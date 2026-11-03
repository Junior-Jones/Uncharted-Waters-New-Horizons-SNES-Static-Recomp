#ifndef NEW_HORIZONS_FRONTEND_SETTINGS_WIN32_H
#define NEW_HORIZONS_FRONTEND_SETTINGS_WIN32_H

#include <windows.h>
#include <stdint.h>

#include "new_horizons_gamepad_input_win32.h"

#define NEW_HORIZONS_WIN_BINDING_COUNT 12
#define NEW_HORIZONS_INPUT_SOURCE_KEYBOARD 0
#define NEW_HORIZONS_INPUT_SOURCE_GAMEPAD 1

typedef enum NewHorizonsWinBindingAction {
    NEW_HORIZONS_WIN_BIND_UP = 0, NEW_HORIZONS_WIN_BIND_DOWN, NEW_HORIZONS_WIN_BIND_LEFT, NEW_HORIZONS_WIN_BIND_RIGHT,
    NEW_HORIZONS_WIN_BIND_SNES_B, NEW_HORIZONS_WIN_BIND_SNES_A, NEW_HORIZONS_WIN_BIND_SNES_Y,
    NEW_HORIZONS_WIN_BIND_SNES_X, NEW_HORIZONS_WIN_BIND_SNES_L, NEW_HORIZONS_WIN_BIND_SNES_R,
    NEW_HORIZONS_WIN_BIND_START, NEW_HORIZONS_WIN_BIND_SELECT
} NewHorizonsWinBindingAction;

typedef struct NewHorizonsFrontendSettingsWin32 {
    int integer_scale;
    int pause_on_focus_loss;
    int auto_run_on_load;
    int fullscreen_on_play;
    int show_fps_counter;
    int ntsc_frame_lock;
    int widescreen;
    int widescreen_notice_shown;
    int snapshot_slot;
    int input_source;
    int input_source_saved;
    int welcome_shown;
    UINT bindings[NEW_HORIZONS_WIN_BINDING_COUNT];
    int gamepad_bindings[NEW_HORIZONS_WIN_BINDING_COUNT];
} NewHorizonsFrontendSettingsWin32;

void new_horizons_frontend_settings_win32_defaults(NewHorizonsFrontendSettingsWin32 *s);
void new_horizons_frontend_settings_win32_classic(NewHorizonsFrontendSettingsWin32 *s);
void new_horizons_frontend_settings_win32_load(NewHorizonsFrontendSettingsWin32 *s,
                                          const wchar_t *path);
int new_horizons_frontend_settings_win32_save(const NewHorizonsFrontendSettingsWin32 *s,
                                         const wchar_t *path);
uint16_t new_horizons_frontend_settings_win32_input(
    const NewHorizonsFrontendSettingsWin32 *s, UINT virtual_key);
const wchar_t *new_horizons_frontend_settings_win32_action_name(int action);
void new_horizons_frontend_settings_win32_key_name(UINT virtual_key,
                                               wchar_t *text, size_t capacity);
int new_horizons_frontend_settings_win32_dialog(HWND parent, HINSTANCE instance,
                                           NewHorizonsFrontendSettingsWin32 *s);
/* Existing Launcher headless integration check; uses the real Settings proc. */
int new_horizons_frontend_settings_win32_check_widescreen_dialog(HWND parent,
                                                               HINSTANCE instance);
int new_horizons_frontend_controls_win32_dialog(HWND parent, HINSTANCE instance,
                                           NewHorizonsFrontendSettingsWin32 *s,
                                           NewHorizonsGamepadInputWin32 *gamepad);

#endif
