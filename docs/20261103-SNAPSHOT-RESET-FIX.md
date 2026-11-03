# 1.0.0 reset/snapshot correction — 3 November 2026

User reported1(save), Reset,2(load), then PPU failure. Original slot1 and battery
save copied read-only into temp/snapshot-fix-20261103 before any tests. Original
slot1 SHA256307b6e77bd679c3ed31b34e72ba5a135b47a0d2e0eaaca045252b060b33a5628.
No snapshot header/build-ID rewriting was used to make it load.

Direct and repeated live restores of the original frame2472 state continued
300fields without failure. Running180neutral fields AFTER RESET, before any
load, reproduced the PPU stop (Mode0, line218/hclock1096). This establishes a
reset/restart defect; it does not blame a corrupt save file.

Corrections:

* PPU CPU RESET no longer calls the cold-power register initializer. It
  preserves video registers/memory and forces blank, following the inspected
  Jungle Strike v09c_ppu and Rock n Roll Racing v10_2_ppu reset methods.
* Reset's actual Mode0 transition uses the native renderer rather than stopping
  at a Mode1/7-only domain guard. Four2bpp BGs, per-BG32-entry palettes and proper
  BG/OBJ ordering reuse owned tile, scroll, mosaic, flip, window and math paths.
  No generic emulator, blank-frame bypass or new widescreen renderer is added.
* Snapshot loading validates a freshly bound candidate and commits only a valid,
  healthy saved state. It is not dependent on a failed live core being at a
  quiescent instruction boundary. Invalid files leave the live machine intact.
* Original released dc12a23dd4bf5849554e9c9e7642104d75dd27d1a825f0d560288ae6616555d8
  is the only explicitly admitted predecessor identity. Same serialized ABI,
  ROM, version, size and checksum checks remain required; other old builds reject.
* F2's original gameplay-opened save dialog is retained: user confirmed it
  opens during gameplay. F3 remains the load dialog;1/2 are current-slot shortcuts.

Regression uses production Launcher --snapshot-roundtrip-headless, not a new
test EXE: original snapshot, fresh API save, Reset+1800neutral fields, reload,
300neutral fields and repeated reload, with widescreen OFF and ON. All six
continuation hashes equal the original D15C5AB515A820A9, frame2772. Original
direct restore, hot reload and reset-before-load failures remain recorded in
the bounded diagnostic folder, rather than relabelled as passing results.

UI text: GitHub Issues replaces X feedback; Welcome now shows game name,
Version1.0.0, then the grammar-corrected Wide Screen Feature paragraph.
Removed the requested "Select Close to accept..." notice sentence. Notice
acknowledgement remains persistent; no user settings are silently reset.

## Follow-up: frontend Reset must cold restart

The user confirmed snapshot loading worked but Reset did not restart the game.
The earlier regression checked continued execution and restoration after a
hardware reset; it did not establish a return to the opening sequence. That
was insufficient coverage for the frontend button's meaning.

The inspected Jungle Strike jungle_app_core.c explicitly uses power_on for
the frontend Reset command, distinguishing it from the retained-state SNES
hardware reset line. Rock n Roll Racing rnr_app_core.c likewise shuts down and
cold_power_on restarts. New Horizons now creates a fresh deterministic core
from the retained ROM and encoded live battery data, prepares its presentation
capture, then replaces the old core. Audio queues and old published output are
cleared. The public hardware-reset API retains its hardware semantics.

The corrected regression requires frame zero immediately after Reset,
byte-identical battery data, and all 1800 opening frames identical to a separate
fresh cold boot with the same battery data, before testing snapshot reload.
It runs with widescreen OFF and ON. Original dc12... snapshots and the first
3 November release's 261b7500... snapshots are explicitly compatible; unrelated
development identities remain rejected. No snapshot header is rewritten.

Final follow-up receipts: ../release-1.0.0-20261103-reset/ (relative to project
root); the earlier release-1.0.0-20261103 receipts remain historical evidence.
