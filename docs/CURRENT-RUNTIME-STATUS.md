# Current Windows delivery —2026-10-22

Latest compacted build accepted by the user for title-music listening (no
crackling reported). Final stripped Launcher:25,115,648 bytes, SHA256
fc28411baba8cbb24783559a11c94d001e38c5ed996d9d9b660202d19b9eea93.
Core library:22,528,016 bytes. All283,586 exact contexts retained as538 shared
native bodies. Final audio delivery uses128-native-frame callback batches
and the scheduler skips impossible raster scans, never master-clock ticks.
The final scheduler pair preserved complete1800-field diagnostics/PCM/pixels.
User listening and the short muted frontend checks are finished; no Launcher
is intentionally left running. Snapshot saving from active game/F2 works;
launcher1/F2 rejected without changing snapshots. Welcome/Player1/layout
checked. See20261022-FINAL-FRONTEND-PACKAGE.txt and the audio reference review.
Github Source/Release/Test delivery is complete; the Windows release ZIP is
Uncharted-Waters-New-Horizons-1.0.0-Windows-x64.zip (10,016,897 bytes), SHA256
c0f092ed055e99ec9d2badf10b0a49bc5873bc8118126c472f7279917258579d.
All seven files match ZIP/Release/Test; existing Test runtime hashes unchanged.
Source includes local SDL3.4.10 and configures with the same103 selected units.
Its4946 source/dependency files match the working origins; manifest included.
README/VERSION explicitly retain limitations; no full cold Pass-B certificate.

Everything below is historical, not current artifact/path/acceptance authority.

# Previous shared-native compaction candidate —2026-10-21

Implemented the Rock/Gundam/Jungle exact-key frozen-parameter native-sharing
method, using NH-owned tools/source. All283586 contexts retained as538 shared
native bodies; zero context deletion, decoder or fallback. Two full generations
byte-identical; independent emitted-C verification reconstructs every original
body. Original dispatcher/guards/successors/timing and integer types preserved.

Complete strict build passed. Core library93256022 ->22527256bytes (88.94 ->
21.48MiB,75.84% smaller). Stripped complete app68337664 ->25112064bytes
(65.17 ->23.95MiB,63.25% smaller). Compared with original unstripped app,
72.89 ->23.95MiB is combined67.15% reduction, not body-sharing savings alone.

All14 headless comparisons PASS against original executable/evidence, including
300/600/10000frames,60/120/180guestseconds and eight saved checkpoints. Exact
pixels/native PCM signatures/diagnostics and all machine fields match. Only the
existing documented10-byte ABI-padding exclusion applies to raw snapshots.
All6850 locked inputs and compiled artifacts rechecked. All150 actual core
compiler-read inputs prelocked.21 host-only SDL/C++/generated-PCH dependencies
have post-build inventory only; not a retroactive lock or full cold certificate.

Private candidate: ../V18C-shared-native-20261021/release/Launcher.exe,
SHA2562527ffca27f81bff703d115b124fc4837ae0ad434cb87d83d0fdfb13c038363c.
Detached symbols retained beside it; ship only the EXE once release-qualified.
Github Release/Test remain metadata-stripped original production code below.
No full18C certificate/promotion: headed presentation, whole-core cold Pass B,
cache-invalidation and clean-package/extraction gates remain. See
V18C-shared-native-result.json and V18C-COMPACTION-20261021.md. No additional
gameplay exploration or repeated completed tests is authorized by this result.

# Previous release metadata cleanup —2026-10-21

User-authorized debug/symbol stripping is deployed to Github Release/Test.
Working production code unchanged: Launcher76435573 ->68337664bytes (65.17MiB),
SHA25697135817ad2b385fc15420467952e758532e25a089c843933f47ae4131bd87e3.
Code/data/resources/loader ABI verified against original; runtime logs retained.
Detached symbols and original binaries remain available. All7 other package
files, including settings, unchanged. No compile or new gameplay test performed.

Private compacted candidate is additionally available stripped at sibling
V18C-symbol-stripping-20261021/size-candidate/Launcher.exe:60170752bytes
(57.38MiB), SHA256180453642ee6a82e259bba532a16270b829866f960354049b707ca6810a28c54.
It has NOT replaced current production code. Earlier statements that Github
EXEs are byte-identical to their unstripped originals are historical; only the
metadata-only packaging transform changed them. Full compaction promotion and
certification gates below remain unclaimed. See V18C-release-symbol-cleanup.json.

# Previous update —2026-10-21: compaction candidate headless-qualified

User accepted basic gameplay testing as sufficient and ended exploratory tests.
Next authorized task:18C compaction. See V18C-COMPACTION-20261021.md and
V18C-compaction-result.json for authoritative current sizes and qualification.
Current universe283586 exact keys,965 families,2573 selected core C units.
Private candidate core library93256022 ->81113884bytes; Launcher76435573 ->
68268661bytes. All2545 compacted shard compiler tokens match originals;14
headless comparisons pass including full natural ladder through180guestseconds.
All state fields match; raw snapshot padding nondeterminism is explicitly
localized and documented, not raw snapshot byte identity. Core semantics unchanged.
Github Release/Test remain original working versions. Headed confirmation and
cold whole-core Pass B/package gates are still pending; no final18C certificate.
Do not resume remaining optional menu/village/quest tests without new direction.

Older status below is historical; its counts/identities/integration obligations
predate recent repairs and must not be reused as a current completion certificate.

# Historical runtime status — 2026-10-18

Verified menu-callback repair supersedes earlier build records. The rebuilt
core passes the button-driven former crash point and a natural 180s regression.

- Version 05: 282,237 source contexts, zero frontiers and byte conflicts.
- Production: 282,232 contexts, 963 families, 2,536 generated shards;
  `282237 + 3 executable-memory additions - 8 retired contexts = 282232`.
- New family NH07F963: 500 contexts, 2,671 added edges. Its complete dependency
  cone includes 36 old transfer contexts associated with 31 historical owners.
- Cause: all six synthetic callback sites in C7:1007 incorrectly admitted only
  C7:1DE4. Nine ROM-immediate caller producers prove nine callback destinations.
  C7:4607 supplies C7:4357 using PEA at C7:45F5/45F8.
- Actual failing RTL: C7:1145, entry S=0868, stack 56 43 C7, outer frame
  46 11 C7. Mesen independently selects C7:4357 at master 948083432; static
  stop at 948083474 is exactly six RTL cycles later. Not a master-clock repair.
- Downstream: 108 return edges, 48 synthetic-call edges, both RTI domains;
  selected C09645 copy-support shard explicitly refreshed for C7:445A.
- Qualification: 390 existing offline-model cases cover all 156 new RTL
  relations plus negative targets and stack wrapping; complete current RTI
  domain equality passes. All 500 timing keys reuse existing qualified plans.
- V06 refreshed: no new executable epoch/overlap writer; 193 new disjoint
  stack/DP/exact-WRAM writers. Hardware sidecar records all 500 new contexts;
  literal events are ROM/CPU/WRAM, unresolved classes remain conservative.
- Latest user instruction: paired timed screenshots, saved states and a shot
  log in temp/gameplay; headless execution, guided by the downloaded GameFAQs
  walkthrough. Preserve user Saves/settings/logs during deployment.
- Actual route: cold2490 -> Start eight fields -> 300 successful fields;
  another Start is ignored at character selection, A advances it. Subsequent
  A interactions also run without authority/device stops. Joao's household/cafe
  introduction is complete; Down/Up produce opposite town/map movement with a
  stable neutral interval. Joao first-movement milestone passes; other five
  characters remain untested. State: temp/gameplay/joao-20261018/states/
  step22-wait3.snapshot (frame9992). shots.log describes every retained PNG.
- Natural180s: 10818 fields, master3865934928, 5760039 known PCM frames,
  zero unknown PCM/overflows/render failures. Logs/snapshots are in
  evidence/menu-callback-1145-replay. Gameplay screenshots now live separately
  in temp/gameplay/joao-20261018/screenshots, per the latest user instruction.

Receipts: `V07C-family-963-discovery.json`, `-understanding.json`,
`-return-qualification.json`, `-selected-return-repair.json`, `-hardware.json`,
`V09C-family-963-timing-repair.json`; oracle observation in
`evidence/menu-callback-1145-native.log`.

Version 17 integration/user testing is active. Version 10's completed DMA/HDMA
milestone is historical authority, not the current work queue. No compaction
has been authorized or performed.

## Current production and test build

- S-CPU: 282,232 selected contexts, 963 families; includes NH07F962's CD:D057
  correction and NH07F963's complete menu callback domain and timing joins.
- S-SMP: 3,332 exact PCs, per Version 12/13 post-correction closure receipt.
- Core source selection: the current root CMake target contains 2,564 inputs.
  Older selection receipts describing 2,561 inputs predate the opaque core owner.
- Current Windows executable: `Github/Test/Launcher.exe`, also copied to
  `Github/Release/Launcher.exe`; source in `Github/Source`.
- Current executable SHA-256:
  `3c5bf983f8b84d52d6018ce9ec42bf19f40f854a1fc744058874d90bac8ef3d6`.
- Snapshot build identity:
  `17488abc50696b3ea8c92468fe7d1a5d3b88fd85788b020df97819cd71154c70`.
- Browse, default Rom-folder discovery and help accept `.sfc` and `.smc`.
  The existing loader strips the supported 512-byte copier container and
  validates the exact canonical ROM contents. Older running processes retain
  their old filter until reopened.

## Completed observations

The corrected core completed the 180-second and 300-second natural no-input
title/attract runs. The latter published 18,030 frames, exited 0 with status 0,
produced 9,600,115 known PCM frames, and reported no unknown PCM, FIFO overflow
or rendering failure. See `V17C-300-SECOND-TITLE-TEST-20261017.md`.

Frame 7,952 is a coherent Ernst opening biography/town scene. The late failure
was localized to the source-derived dispatch domain, repaired at Versions 05,
07 and 09, and crossed by both successful long runs. See
`V05C-V09C-C7E6-BF9A-REPAIR.md`.

The complete existing Jungle Strike frontend port compiled and linked against
the corrected core. Release and Test executable hashes match. Windows imports
contain system DLLs only. The initial Test launcher opened and responded;
the subsequent file-filter correction built and was copied successfully.
The user must reopen an old process to use that corrected browser.

## Remaining Version 17 work

Current reconciliation update: `V17C-current-repair-reconciliation.json`
verifies the exact equation `281737 + 3 - 8 = 281732`, all selected generated
body keys, all timing-binding keys, 2,562 selected source hashes, compiler-input
set equality and 2,562 current GCC archive members. Version 06's dependency
summary, union and mutation census were refreshed using its existing generator.
The 46-context family adds 18 bank-00 stack writes and one direct-page write;
no executable-WRAM writer or epoch changed. The three historical predecessors
are recoverable in `archive/2026-10-18-v06-before-family962-refresh` outside temp.

- Refresh Pass A and the global frontier ledger against the repaired Version
  05/06/07/09 universe and current compiled selection. The current incremental
  reconciliation is complete; full cold regeneration remains pending. The older
  ledger's 281,686 context equation and source hashes remain historical.
- Verify the corrected file picker in the visible app and load the external ROM.
- Establish repeatable normal-input routes for all six characters to the first
  player-controlled on-screen D-pad movement milestone, preserving screenshots
  and qualified snapshots before actions as the user requested.
- Qualify in-game save/load, complete-machine snapshot/replay and rejection
  behavior through the actual frontend.
- Qualify visible rendering, physical audio and physical gamepad behavior;
  headless PCM and framebuffer metrics alone do not prove those outcomes.
- Close the remaining global hardware/alias/phase obligations using their
  current owner evidence; no historical milestone claim closes them automatically.

Starter SNES v12 document 89 governs this stage. Theme Park's later timing and
frontend corrections and the seven reference projects provide methods only.
The downloaded GameFAQs guide is private gameplay reference in
`temp/gameplay-guides`; it is excluded from GitHub source/release copies.

Version 18 remains gated on completed gameplay/frontend/save/snapshot testing
and explicit user agreement. The title/attract tests do not satisfy that gate.

