# Local RecompLauncher integration - 17 November 2026

Status: authored and compiled; archive and focused existing headless Launcher
checks passed. GUI runtime acceptance remains incomplete. The AVG-blocked
standalone argument test has not been run again.
Nothing was committed, pushed, merged, published or sent externally. No developer
account was created or claimed. Existing Release/Test deliveries are unchanged.

## Baseline and review

The clean Git checkout was Github/Source at b86db90 (main), with origin
Junior-Jones/Uncharted-Waters-New-Horizons-SNES-Static-Recomp. The separate temp
research tree was inspected for custody context and left unchanged. HANDOFF.md
identifies the released source and excludes further widescreen gameplay work.
No applicable AGENTS.md or .agents/skills was found in the checkout or ancestors;
the user's Codex AGENTS.md browser guidance was read. The local Codex memories
directory was empty. No existing Uncharted Waters build/game process was running.

PR #2 was open and unmerged, head b42e02d29b2f189c8bf8d8203c4706bfc339448b,
with exactly README.md, frontend/frontend/windows/CMakeLists.txt and the manifest.
The author explicitly had not built it. Credit: Ruben Ripalda (elripalda) authored the original manifest, badge and
CMake-copy proposal. The three-file proposal was reviewed,
then adapted to provide actual ROM auto-start and reliable Original selection.

References:

- https://github.com/Junior-Jones/Uncharted-Waters-New-Horizons-SNES-Static-Recomp/pull/2
- https://github.com/elripalda/RecompLauncher/blob/main/docs/DEVELOPERS.md
- https://recomplauncher.com/schema/recomplauncher.json
- https://github.com/elripalda/RecompLauncher/blob/main/docs/recomplauncher.schema.json
- https://github.com/elripalda/RecompLauncher/blob/main/src-tauri/src/profile.rs

The guide and schema support iso/folder/iso_or_folder. profile.rs check_copy
uses a regular-file check for iso, and its tests explicitly handle a SNES .smc.
Thus iso is retained as the supported single-file contract, not changed to an
invented rom enum. The manifest does not claim independent ROM verification:
the application's existing verified loader remains the ROM identity authority.

## Authored behavior

- Root recomplauncher.json and the PR's README badge.
- start.args is [--game, {game}]. config main points to settings.ini and ROM/Path.
- Full screen maps to General/FullScreenOnPlay. Widescreen maps to
  Display/Widescreen=0/1, with Original explicitly writing 0. AutoRunOnLoad is
  neither forced nor changed by the manifest. Saves and logs retain the PR paths.
- A GUI-only parser uses CommandLineToArgvW tokens. Existing headless dispatch
  remains first and unchanged. Quoted Unicode arguments remain wchar_t strings.
- --game is copied to a bounded absolute path before argv is released. Startup
  sets the existing ROM edit control and calls start_rom_load(1); it uses the
  existing worker, ROM verification, load completion, audio and play path.
  Explicit --game bypasses Welcome so a fresh launcher install starts directly.
  Without --game the original Welcome/GUI flow is retained.
- Missing/empty --game operands report an error and return 2. A subsequent flag
  is not consumed as a path. Invalid file/ROM content reaches the existing loader
  rather than silently selecting another saved/adjacent ROM.
- --port-widescreen and --port-wide-canvas enable; --no-port-widescreen disables.
  Explicit flags override persisted settings, last display flag wins. A repeated
  --game uses the last path. Unknown arguments retain the prior ignored behavior.
  Display overrides are saved by normal existing exit/settings behavior.
- CMake copies the manifest beside Launcher.exe and lists it as LINK_DEPENDS,
  so manifest-only changes refresh the executable-adjacent sidecar next build.
  shell32 was already linked; no linker-library addition was required.
- Runtime and source READMEs explain the flags and packaging exclusions.
- tools/new_horizons_launch_options_test.c exercises the actual Windows tokenizer
  and shared production parser in 13 focused cases.

## Verification completed

- git diff --check: PASS.
- tools/check_portable_source.py: PASS (no personal paths/ROMs/runtime data in
  checked source). Frozen release manifests were intentionally not rewritten.
- Manifest: PASS using jsonschema Draft7Validator and the fetched live official
  schema. The schema validator was installed only into the separate task workspace.
- Standalone argument test compiled with GCC 16.1.0, -std=c17 -Wall -Wextra -Werror,
  shell32 and static linkage. Two runs from build/recomplauncher printed all 13
  PASS cases and returned 0 before the AVG notice was received. Cases include no
  arguments, alias, spaces/Unicode, both game/flag orders, three missing-operand
  forms, both on/off conflict orders, duplicate game paths and ignored options.
  This is narrow parser output, not antivirus clearance or GUI acceptance.
- Isolated complete Release configure/build: PASS, all 381 steps, no warnings or
  errors in the captured build log. GCC/G++ 16.1.0, CMake, Ninja, bundled SDL 3.4.10,
  NH_BUILD_WINDOWS_FRONTEND=ON, NH_SHARED_SOURCE_ROOT=compaction,
  NH_SIZE_OPTIMIZED_GENERATED=ON. No source-generation/core behavior changes.
- build/recomplauncher/release/recomplauncher.json matches root SHA-256:
  981234a5c006db4666e120060853edc0a13a4dd65e3d6fb8089b405ddee22c65.
- Compiled Launcher.exe: 27,738,536 bytes; SHA-256:
  6f4c70f72a877a188462afd6a13aacb3785f7f5dd45bcae0197439f1e6ea9127.
- Read-only objdump PE import inspection: Windows system DLLs only; no SDL,
  libgcc, libstdc++ or libwinpthread runtime DLL import.

## AVG event and execution facts

The first test execution attempt used the task-workspace launch-options-test.exe
through PowerShell invocation. It produced no test output while waiting. A second
attempt used Start-Process with redirected stdout/stderr and a bounded wait.
Both task-workspace attempts eventually reported Access is denied. Process
observations included waiting instances of the same test. Before receiving the
AVG notice, the binary was copied into the isolated build/recomplauncher directory
and invoked normally through PowerShell; it printed the 13 PASS lines. It was
invoked there a second time to save the same output into the evidence log.

The parent subsequently reported AVG had sandboxed and terminated the test.
No AVG exception, changed security setting, quarantine restoration, alternate
runner, or disabled protection was used. Before that notice, two observed stalled
task test instances (PIDs 53016 and 69404) were targeted with Stop-Process as task
cleanup. No security process was stopped. At the initial stop, no executable had been rerun since the AVG notice and
Launcher.exe had not yet been executed. Todd subsequently explicitly authorized
focused headless Launcher.exe checks; those later results are recorded below.
The AVG-blocked standalone argument binary has never been rerun since notice.
This report does not determine whether the alert was malware or a false positive.

## Local package

build/recomplauncher/Uncharted-Waters-New-Horizons-RecompLauncher-local-20261117-Windows-x64.zip

ZIP SHA-256:
430c1a113a32fdfaa79af0cb574265505c066d7ad5a0e195d49a4f9868333c3c

Exactly six top-level files: Launcher.exe, recomplauncher.json, README.txt,
VERSION.txt, SDL-LICENSE.txt, THIRD-PARTY-NOTICES.txt. Archive CRC checks, entry
allow-list, embedded executable/manifest identity and embedded manifest schema
all PASS. VERSION.txt and the README prefix identify this as an unreleased local
candidate with incomplete runtime acceptance, not the original released binary.
The package does not contain ROMs, settings.ini, Saves, Logs, screenshots, debug
symbols, test programs or third-party runtime DLLs. package-check.json records
entry hashes. The canonical Github/Release and existing release ZIPs are unchanged.

## Reproducibility of the standalone parser check

The source is tools/new_horizons_launch_options_test.c and directly includes the
production parser. The original compilation/invocation can be reproduced from
the source root with the following commands, but execution is currently ON HOLD
because AVG blocked this standalone test. These commands are documentation only;
the binary was not rerun for this update. Do not bypass AVG to run it.

```powershell
gcc -std=c17 -Wall -Wextra -Werror tools/new_horizons_launch_options_test.c -o build/recomplauncher/launch-options-test.exe -lshell32 -static
.\build\recomplauncher\launch-options-test.exe
```

## Later user-authorized headless Launcher verification

Todd explicitly authorized headless Launcher.exe testing after the original stop,
with isolated settings/saves and no rerun of the blocked test binary or security
changes. The same compiled release/Launcher.exe was launched normally through
Start-Process with WindowStyle Hidden and a bounded ten-second wait per check.
It was not moved, rebuilt, renamed or run through another runner. All seven
checks returned normally within their time limits; no access denial or pending
process was observed. No security setting or exception was changed.

- --presentation-controls-headless: EXIT 0, all 14 existing checks PASS. Checks
  cover hidden window, default Original, toolbar/menu/backend synchronization,
  actual hidden Settings dialog ON/OFF, one-time notice and INI reload at both
  widescreen=1 and widescreen=0, and loading-state control disabling.
- --presentation-headless: EXIT 0 with a Unicode path containing spaces to the
  headered supported .smc, using the same frontend verified ROM loader. Two
  neutral native-profile fields ran; 989 PCM frames were drained. No device
  audio/painting/gameplay acceptance is claimed. A normal same-build checkpoint
  and image were written solely into the isolated presentation evidence folder.
- Missing ROM file: EXIT 1 with the expected 'Unable to open the selected ROM
  file' loader error.
- Invalid short ROM file: EXIT 1 with the expected exact ROM-size loader error.
- Missing operands for --presentation-headless, --presentation-controls-headless,
  and --snapshot-roundtrip-headless each returned EXIT 2 without GUI startup.

Evidence is under build/recomplauncher/verification: controls/controls-result.txt,
presentation/presentation-result.txt, missing-rom/presentation-result.txt,
invalid-rom/presentation-result.txt and headless-results.json. Controls used its
own fresh controls-test.ini. No personal settings or saves were imported. Hashes
of the original ROM, Unicode fixture ROM, and existing Github/Test/settings.ini
were unchanged after the checks. The build release/Saves directory remained
empty and no settings.ini was created beside the tested executable. No Launcher
or test process remained running at the final process check.

## Remaining verification

Actual GUI --game auto-start, no-argument Welcome, GUI error dialogs and startup
CLI/config precedence have NOT been run. Existing headless dispatch returns
before the GUI-only launch parser, so these headless results do not establish
those behaviors. Persisted display ON/OFF is tested through the existing hidden
controls contract; actual GUI launch flag precedence remains source/parser-level
evidence. Full snapshot reset/roundtrip gameplay was not rerun: only its invalid
arity dispatch was checked, because snapshot/core implementation did not change.
No broad gameplay, widescreen qualification or RecompLauncher end-to-end UI test
was performed. The local candidate remains unreleased and not fully runtime
accepted. The standalone parser executable remains blocked from further runs.
