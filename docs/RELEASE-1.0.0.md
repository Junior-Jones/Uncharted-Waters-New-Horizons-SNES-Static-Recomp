# Windows 1.0.0 release — 26 October 2026

User-directed release of the current core/frontend. Further widescreen layout,
chart, event and whole-game investigation is stopped. Widescreen ships disabled
by default and explicitly experimental; unsupported scenes retain native output.
Do not describe all menus, effects, introductions or endings as widened.

README/VERSION structure follows Theme Park 1.0.0 and Jungle Strike's archived
1.0.0 release, with New Horizons' verified ROM, controls, SRAM and limitations.
Third-party notices and SDL license accompany app and source. The new notice
uses the existing Jungle Strike-derived native information window, not a new
frontend. Its bottom Close accepts the notice and persists the acknowledgement
in Display/WidescreenNoticeShown. Menu, toolbar and Settings share the setting.

Isolated native frontend check uses the actual window procedures in Launcher:
notice creation, default bottom Close geometry, dismissal, INI persistence,
reloaded suppression, shared ON/OFF state and loading interlock. No new test
executable or gameplay playthrough. Source/ZIP manifests and a short packaged
cold boot are delivery checks, not broader gameplay certification.

The original 26 October core identity was dc12a23dd4bf5849554e9c9e7642104d75dd27d1a825f0d560288ae6616555d8.
The 3 November correction has a new source identity recorded in VERSION.txt
and V17C-snapshot-build-identity.json, while explicitly supporting snapshots
from that original released identity. See 20261103-SNAPSHOT-RESET-FIX.md for
the reset/Mode0 renderer correction, transactional snapshot loading and the
follow-up cold-restart fix for the frontend Reset command. The first 3 November
release's 261b7500... snapshots are also explicitly compatible.
The serialized snapshot ABI is unchanged. Feedback now uses GitHub Issues,
and the Welcome window includes the requested experimental widescreen text.
Historical widescreen findings are partial, not release acceptance gates.

Cleanup follows packaging and verified source export. Remove only unneeded
widescreen test captures/replays/binary snapshots and obsolete copied test apps;
preserve production sources, frozen compaction inputs, release verification,
personal user Saves/settings and non-widescreen historical core work.
Deletion receipts record exact targets and bytes; deleted bulky captures are
not claimed recoverable. No further automatic gameplay/widescreen work.
