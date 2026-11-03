# Uncharted Waters: New Horizons Windows frontend port

This directory is the target-owned port of the complete Jungle Strike 1.0.0 Windows frontend supplied by Starter SNES v12. It preserves the launcher, welcome window, menus and toolbar, settings, input latching, SDL3 gamepad input, DirectSound transport, resampling, screenshots, snapshot UI, diagnostics, and accessibility behavior.

The target adapter is `frontend/windows/new_horizons_app_core.c`. It uses only the public opaque interface in `static-core/include/new_horizons_core.h`; no Jungle Strike runtime or static-core code is linked. Target constants are 2 MiB ROM, 256x239 maximum native frame, 32,000 Hz stereo PCM, and the core's exact NTSC presentation ratio 3579545/59561.

`Launcher.exe` creates `Rom`, `Saves`, and `Screenshots` beside itself. In-game SRAM is encoded by the core and atomically stored as `Saves/uncharted-waters-new-horizons.sav`. Snapshot slot paths also live in `Saves`.

The default build creates only `Launcher.exe`. Copied contract executables are retained as source references and require `NH_FRONTEND_BUILD_CONTRACT_TESTS=ON`. SDL is never downloaded: configure `NEW_HORIZONS_SDL_SOURCE_DIR` with an existing local SDL 3 source tree.

Complete-machine snapshots use the target-specific `.nhsnap` extension. The core payload is versioned, canonical-ROM and exact-build identified, bounds-checked, pointer-free, checksummed, and validated before commit. Snapshot files are written atomically. Rejected loads preserve the live machine and queued host output; stale host audio is discarded only after a successful restore.

The immutable manifest of the original copied reference is archived at `archive/jungle-strike-frontend-reference-manifest.json`. `SOURCE-RECEIPT.txt` records its provenance.
