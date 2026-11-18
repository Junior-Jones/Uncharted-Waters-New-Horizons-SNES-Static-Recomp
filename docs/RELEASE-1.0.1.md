# Version 1.0.1 — RecompLauncher integration

This update integrates [PR #2](https://github.com/Junior-Jones/Uncharted-Waters-New-Horizons-SNES-Static-Recomp/pull/2)
by Ruben Ripalda (elripalda), retaining its manifest, badge and CMake-copy contribution.

The Windows ZIP includes `recomplauncher.json` beside `Launcher.exe`. RecompLauncher
can install/update the GitHub release, supply the player's ROM using `--game`,
configure fullscreen and Original/Widescreen, and locate `Saves` and `Logs`.
The app verifies the supported ROM; no game files or personal settings are included.

`--game "path"` uses the existing verified loader and starts play even with
Auto-Run off. It bypasses the first-run Welcome window. Normal launches retain
Welcome. Display options combine with other arguments; explicit flags override
saved settings and the last display flag wins. `--no-port-widescreen` selects Original.

No static-core, audio, rendering, timing or snapshot serialization behavior was
changed. The existing core compatibility identity and supported 1.0.0 snapshots
are retained. Experimental widescreen coverage has not expanded in this update.

## Verification

- Complete application build succeeded; the final version update rebuilt only
  affected frontend/resource inputs and linked the existing core.
- Manifest validated against the current official RecompLauncher JSON schema.
- CMake placed an identical manifest beside the built executable.
- GUI combined `--port-widescreen --game` launch used a quoted Unicode ROM path,
  reached running gameplay without a Run click, and persisted Widescreen=1 while
  AutoRunOnLoad=0. No-argument startup displayed Welcome with Version 1.0.1.
- Earlier isolated same-implementation Launcher checks passed: controls (14
  checks), Unicode ROM loading, invalid/missing ROM rejection and headless arity
  rejection. See `20261117-RECOMPLAUNCHER-INTEGRATION.md` for exact scope.
- Release symbol stripping preserved every non-debug section and loader ABI.
- Portable source audit excludes private drive paths, ROMs and personal data.

This is not a new full-game test or an end-to-end RecompLauncher desktop acceptance
test. Developer-account approval and catalogue state are external to the app.

## Packaging

Build using README.md, then use `tools/v18_strip_release.py` to retain detached
symbols privately. `tools/package_release.py` packages the already-stripped
executable from this checkout; it never replaces source from the research tree.
It refreshes release/source manifests, creates versioned Windows/source ZIPs,
checks archive contents and hashes, and updates only release-owned files in
the local Release and Test folders, preserving user saves/settings.
