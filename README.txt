Uncharted Waters: New Horizons (SNES) Static Recompilation
Version 1.0.0

Running the application
-----------------------
Extract the complete release into a writable folder on 64-bit Windows 10 or
Windows 11 and run Launcher.exe. Close Welcome to continue to Launcher.
Select your own ROM with Browse ROM, or place it in the Rom folder.
No ROM or emulator is included. You must supply the supported ROM.
No emulator or separate SDL DLL is required.

Supported ROM
-------------
Uncharted Waters: New Horizons, USA/Canada NTSC.
Canonical size: 2,097,152 bytes. Accepted extensions: .sfc and .smc.
A 512-byte copier header is accepted and removed before identity checking.
SHA-256 of the canonical, unheadered ROM:
64bc4707f422661a66618088887e2363a5f896ea683c58984fffd96dd21ab5f0
The filename may differ; the application verifies the complete ROM identity.

Controls and shortcuts
----------------------
One-player keyboard and SDL3 gamepad input can be configured in Controller
Bindings (F5). Default keyboard controls: arrows move, F = A, D = B, S = X,
A = Y, E = L, R = R, G = Start and T = Select.

Escape  Switch between gameplay and Launcher / pause or resume
F1      Welcome and shortcut help
F2/F3   Save / Load Snapshot window
F4      Settings
F5      Controller Bindings
F6      Audio Settings
F7      Run the selected ROM
F8      Screenshot
1/2     Save / load the selected snapshot slot

Saves, snapshots and settings
-----------------------------
The game's own Save/Continue feature stores battery data in:
  Saves\uncharted-waters-new-horizons.sav
Five complete-machine snapshot slots use Saves\snapshot-slot-N.nhsnap.
Snapshots are separate from in-game saving and require a compatible core
build and the supported ROM. Older development snapshots can be incompatible.
Snapshots from the initial 1.0.0 release remain supported by this correction.
Do not bypass validation or replace battery data with arbitrary emulator SRAM.
Snapshot saving is available from active gameplay, not the Launcher screen.

settings.ini beside Launcher.exe stores display, audio, controls, snapshot
slot, Welcome and widescreen-notice preferences. Screenshots go in Screenshots;
failure reports go in Logs. The clean release contains no personal settings,
ROM paths, saves, snapshots, logs or captured images.

Display and experimental widescreen
-----------------------------------
Original presentation is the default. Full screen, integer scaling, natural
NTSC frame lock and optional title-bar FPS are available. Natural game speed
is approximately 60.0988 frames per second, not forced 60.000 FPS.

The toolbar checkbox and Settings menu share the optional Widescreen setting.
Widescreen is experimental: supported scenes use an expanded 512 x 288 image
and repositioned interface groups; some scenes retain the original layout.
Not every menu, effect or story scene has been qualified for widescreen.
Turn it off to restore the original image and layout without resetting play.

The first use displays a Widescreen Notice with a Close button. Closing it
dismisses the notice; settings.ini remembers Display/WidescreenNoticeShown=1.
It does not appear again unless that preference or settings file is reset.

Static core and audio
---------------------
Game S-CPU and SPC700/S-SMP instructions execute through ahead-of-time native
code. There is no runtime CPU interpreter, JIT, learning or emulator fallback.
Graphics and audio are computed live, not prerecorded. The core owns SNES
NTSC timing, cartridge memory, DMA/HDMA, input, PPU and S-DSP behavior.
The frontend streams native stereo PCM to DirectSound with resampling and
configurable Audio Settings. SDL3 is statically linked for gamepad support.

Known limitations and reports
-----------------------------
Widescreen remains experimental. Previous gameplay checks do not certify
every possible branch, effect, audio device or physical controller.
Unsupported static execution stops and records a detailed text report in
Logs; closing the error window does not activate an emulator fallback.
Audio transport faults also produce diagnostic logs without a popup.

Please report issues using the Issues tab on this project's GitHub repository.
Include version 1.0.0, steps to reproduce, whether widescreen was enabled,
and a screenshot or failure log where possible. Do not share the game ROM.

Build from source
-----------------
The separate Source folder contains build instructions, the target core,
frontend and bundled SDL3 source. Use Windows x64, MinGW-w64 GCC/G++, Ninja
and CMake 3.28 or newer. See Source/README.md for the exact build commands.

Package contents
----------------
Launcher.exe, README.txt, VERSION.txt, SDL-LICENSE.txt,
THIRD-PARTY-NOTICES.txt, and Rom / Screenshots instruction folders.
No ROM, user data, development executables or debug symbols are distributed.
Uncharted Waters: New Horizons and its original assets belong to their
respective rights holders and are not included.
