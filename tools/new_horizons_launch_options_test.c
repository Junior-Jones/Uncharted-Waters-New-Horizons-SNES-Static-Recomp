#define UNICODE
#define _UNICODE
#include <windows.h>
#include <shellapi.h>
#include <stdio.h>
#include "../frontend/frontend/windows/new_horizons_launch_options.h"

int main(void) {
    struct Case { const wchar_t *line, *path; int wide, error; } cases[] = {
        {L"Launcher.exe", NULL, -1, 0},
        {L"Launcher.exe --port-widescreen", NULL, 1, 0},
        {L"Launcher.exe --port-wide-canvas", NULL, 1, 0},
        {L"Launcher.exe --game \"C:\\ROM files\\\u822a\u6d77.smc\"", L"C:\\ROM files\\\u822a\u6d77.smc", -1, 0},
        {L"Launcher.exe --game \"C:\\ROM files\\game.sfc\" --port-widescreen", L"C:\\ROM files\\game.sfc", 1, 0},
        {L"Launcher.exe --port-widescreen --game relative.sfc", L"relative.sfc", 1, 0},
        {L"Launcher.exe --game", NULL, -1, 1},
        {L"Launcher.exe --game \"\"", NULL, -1, 1},
        {L"Launcher.exe --game --port-widescreen", NULL, -1, 1},
        {L"Launcher.exe --port-widescreen --no-port-widescreen", NULL, 0, 0},
        {L"Launcher.exe --no-port-widescreen --port-widescreen", NULL, 1, 0},
        {L"Launcher.exe --game one.sfc --game two.smc", L"two.smc", -1, 0},
        {L"Launcher.exe --old-ignored-option", NULL, -1, 0}
    };
    unsigned i;
    for (i=0; i<sizeof(cases)/sizeof(cases[0]); ++i) {
        int argc;
        LPWSTR *argv=CommandLineToArgvW(cases[i].line,&argc);
        NewHorizonsLaunchOptions parsed;
        const wchar_t *error;
        if (!argv) return 1;
        error=new_horizons_parse_launch_options(argc,argv,&parsed);
        if (!!error!=cases[i].error || (!error &&
            (parsed.widescreen!=cases[i].wide ||
             (!!parsed.game_path!=!!cases[i].path) ||
             (parsed.game_path && wcscmp(parsed.game_path,cases[i].path))))) {
            printf("FAIL argument case %u\n",i+1); LocalFree(argv); return 1;
        }
        LocalFree(argv);
        printf("PASS argument case %u\n",i+1);
    }
    puts("PASS 13 real Windows tokenization/parser cases");
    return 0;
}
