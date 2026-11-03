#ifndef NEW_HORIZONS_GAMEPAD_INPUT_WIN32_H
#define NEW_HORIZONS_GAMEPAD_INPUT_WIN32_H

#include <stddef.h>
#include <stdint.h>
#include <windows.h>

#include <SDL3/SDL_gamepad.h>

#define NEW_HORIZONS_GAMEPAD_BINDING_COUNT 12

typedef enum NewHorizonsGamepadControl {
    NEW_HORIZONS_GAMEPAD_DPAD_UP = 1,
    NEW_HORIZONS_GAMEPAD_DPAD_DOWN,
    NEW_HORIZONS_GAMEPAD_DPAD_LEFT,
    NEW_HORIZONS_GAMEPAD_DPAD_RIGHT,
    NEW_HORIZONS_GAMEPAD_LEFT_STICK_UP,
    NEW_HORIZONS_GAMEPAD_LEFT_STICK_DOWN,
    NEW_HORIZONS_GAMEPAD_LEFT_STICK_LEFT,
    NEW_HORIZONS_GAMEPAD_LEFT_STICK_RIGHT,
    NEW_HORIZONS_GAMEPAD_FACE_SOUTH,
    NEW_HORIZONS_GAMEPAD_FACE_EAST,
    NEW_HORIZONS_GAMEPAD_FACE_WEST,
    NEW_HORIZONS_GAMEPAD_FACE_NORTH,
    NEW_HORIZONS_GAMEPAD_LEFT_SHOULDER,
    NEW_HORIZONS_GAMEPAD_RIGHT_SHOULDER,
    NEW_HORIZONS_GAMEPAD_LEFT_TRIGGER,
    NEW_HORIZONS_GAMEPAD_RIGHT_TRIGGER,
    NEW_HORIZONS_GAMEPAD_START,
    NEW_HORIZONS_GAMEPAD_BACK,
    NEW_HORIZONS_GAMEPAD_LEFT_STICK_BUTTON,
    NEW_HORIZONS_GAMEPAD_RIGHT_STICK_BUTTON,
    NEW_HORIZONS_GAMEPAD_CONTROL_LAST = NEW_HORIZONS_GAMEPAD_RIGHT_STICK_BUTTON
} NewHorizonsGamepadControl;

typedef struct NewHorizonsGamepadInputWin32 {
    SDL_Gamepad *handle;
    int initialized;
    int startup_gamepad_found;
    unsigned refresh_countdown;
    wchar_t name[160];
} NewHorizonsGamepadInputWin32;

int new_horizons_gamepad_win32_initialize(NewHorizonsGamepadInputWin32 *input,
                                     const wchar_t *mapping_path);
void new_horizons_gamepad_win32_shutdown(NewHorizonsGamepadInputWin32 *input);
uint16_t new_horizons_gamepad_win32_poll(
    NewHorizonsGamepadInputWin32 *input,
    const int bindings[NEW_HORIZONS_GAMEPAD_BINDING_COUNT]);
int new_horizons_gamepad_win32_connected(const NewHorizonsGamepadInputWin32 *input);
const wchar_t *new_horizons_gamepad_win32_name(const NewHorizonsGamepadInputWin32 *input);
void new_horizons_gamepad_win32_default_bindings(
    int bindings[NEW_HORIZONS_GAMEPAD_BINDING_COUNT]);
const wchar_t *new_horizons_gamepad_win32_control_name(int control);
int new_horizons_gamepad_win32_capture_control(NewHorizonsGamepadInputWin32 *input);
void new_horizons_gamepad_win32_control_display_name(
    const NewHorizonsGamepadInputWin32 *input, int control,
    wchar_t *text, size_t capacity);

#endif
