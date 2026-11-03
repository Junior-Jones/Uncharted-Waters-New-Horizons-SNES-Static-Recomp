# Uncharted Waters: New Horizons — Windows source 1.0.0

[![Windows CI](https://github.com/Junior-Jones/Uncharted-Waters-New-Horizons-SNES-Static-Recomp/actions/workflows/windows-ci.yml/badge.svg)](https://github.com/Junior-Jones/Uncharted-Waters-New-Horizons-SNES-Static-Recomp/actions/workflows/windows-ci.yml)

Native static recompilation for Windows 10/11 x64. Download the portable app
from [Releases](https://github.com/Junior-Jones/Uncharted-Waters-New-Horizons-SNES-Static-Recomp/releases),
extract the Windows ZIP and run Launcher.exe. Supply your own supported
USA/Canada NTSC ROM; no ROM or original game assets are distributed.
Report ordinary problems through [GitHub Issues](https://github.com/Junior-Jones/Uncharted-Waters-New-Horizons-SNES-Static-Recomp/issues).

Current source for the compacted native Windows application packaged on
2026-11-03. The game ROM and user data are not included. Runtime instructions
are in README.txt; release details and the shipped executable hash are in
VERSION.txt. Widescreen remains experimental and only partially qualified.
See docs/RELEASE-1.0.0.md for the release scope.
See docs/20261103-SNAPSHOT-RESET-FIX.md for the reset and snapshot-load correction.

The app stores settings, in-game battery saves and snapshots beside the EXE.
It does not depend on the original author's drive layout. Public historical
receipt paths are normalized labels, not dependencies required by the build.

## Build the Windows application

Use an x64 MinGW-w64 GCC/G++ toolchain, CMake 3.28 or newer, and Ninja on Windows.
The packaged build used GCC 16.1.0. Add the toolchain's bin directory to PATH.
The exact SDL 3.4.10 source dependency is included under third_party/SDL3; no
download or neighboring recomp project is required. From this Source folder:

```powershell
cmake -S . -B build/release -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DNH_BUILD_WINDOWS_FRONTEND=ON -DNH_SHARED_SOURCE_ROOT="$PWD/compaction" -DNH_SIZE_OPTIMIZED_GENERATED=ON -DNEW_HORIZONS_SDL_SOURCE_DIR="$PWD/third_party/SDL3"
cmake --build build/release --target new-horizons-launcher -j 4
```

The executable is build/release/release/Launcher.exe. SDL and the compiler
runtimes are statically linked; Windows supplies system DLLs. Do not package
your ROM, settings.ini, Saves, Logs, debug symbols or captured screenshots.
The root CMake graph defaults to the original representation unless the
NH_SHARED_SOURCE_ROOT argument above selects the released compacted bodies.

For the existing headless connector, configure additionally with
`-DNH_BUILD_HEADLESS_CONNECTOR=ON`, then build target `new_horizons_headless`.
It produces build/release/NewHorizonsHeadless.exe. This optional development
target is not part of the Windows release. No contract-test executables are
built by default.

## Source layout and authority

- static-core/src, include, internal: target-owned hardware and core API.
- static-core/generated: original exact-context, timing, S-SMP and identity
  inputs. Original S-CPU shards are retained for provenance and CMake's complete
  source-universe validation, not compiled alongside the shared representation.
- static-core/candidate/block-copy-knownness: the selected executable-WRAM
  copy successor; despite its historical directory name, CMake selects it.
- compaction/native: 538 shared native bodies and frozen records preserving
  all 283,586 exact contexts; no runtime decoder or emulator fallback.
- frontend: Jungle Strike-derived frontend port, target connector, one-player
  gamepad adapter, and SDL license/provenance.
- third_party/SDL3: the local SDL source used by the accepted build.
- docs and compaction receipts: selected development evidence. Historical
  public receipts replace private absolute paths with relative provenance
  labels, retain content hashes, and do not assert that
  every later audio/frontend change was present during those earlier checks.

The generated snapshot identity header is included and must not be edited to
force old snapshots to load. The historical identity generator and compaction
qualification scripts need their original workspace evidence; they are not
required for compiling this source export. Changing serialized core behavior
requires a deliberate new compatibility identity and requalification, not
bypassing snapshot checks. In-game battery saves are separate.

This export is source/build inputs, not the multi-gigabyte research workspace.
It deliberately excludes obsolete attempts, build products, ROMs, snapshots,
captured gameplay, emulator/oracle binaries and other games' source code.
SOURCE-MANIFEST.csv records the shipped source files and their SHA-256 hashes.
The final package receipt is delivery evidence, not full cold Pass-B or
exhaustive gameplay/audio certification. See README.txt for limitations.
