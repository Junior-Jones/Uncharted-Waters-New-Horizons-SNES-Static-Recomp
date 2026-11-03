# Current hardware checklist — Version07 baseline carried forward

LateNMI input15/source overlay:200ROM starts;0FBA0normal852Acallreturns
immediately;NMIepilogue doesnotwrite420B/C/43xx. Only2literalwriters seed
0FBA/BB0cold;nonliteralaliases/nonzerorecord-replay modesremain.
V10C-NMI-post-restore-normal-tail.json keeps8548B1/2100effects andpostRTI
initlifetimeopen. No forcedcontrollerprofile orC/build.

NMI timing/source overlay:533ROM starts;NON01IDs/actualbusy1->0/normal
225-lineNTSC tail24424CPU+800refresh gives20298prefieldrestoremargin.
V10C-NMI-post-busy-restore-bound.json. ID01/alreadyidle/overscan/postrestore
mask-config/input15receiver/alias historiesremain. Both4212gates testbit0,
notVBlank(V10C-NMI-autojoy-gate-ownership.json). NoC/build/deviceoverride.

IRQentryoverlay:53ROM startsplusselected09showTIMEUPread96F1/NMITIMEN01
96F6 beforecallbacks,clearingtimerpipeline butnotoldacceptedIRQage,captured
NMI,externalIRQorA2A. V10C-IRQ-entry-ack-mask-boundary.json keeps111cases
andactualsourcehistoryopen;noC/build.

Stackfillboundary:15calls/17profiles shareconditionalS<=0CB4 exclusionof
namedDMA/HDMAcontrols/MMIO. ColdsourceS08FC ->maxpayloadend0B0A;global
stackbound remainsopen. V10C-stack-fill-alias-boundary.json;noC/build/clamp.

Wrapperpointer successor:1052ROM startsqualifyC3A9EB fixed7FB780..BD7FFF
andbothC8sites'bank00stackptrs fromall2parents. Wrapper24=11fixedWRAM+13
stack/zero unnamedorigins underpreservedframes;MMIO2180/globalalias/sample
historyremains. V10C-fill-wrapper-pointer-origins.json;noC/build/newCPU.

Indexedfilldomain successor:2399ROM startsjoinshared0..6 loopandspecial7
route;bothfamiliesdomain0..7 undermatchedpreservedframe/noaliascontracts.
V10C-indexed-fill-dispatch-bounds.json:CA6E13union7EFE67..FF06(noFF10),
CA6978union7FC400..CBFF. Actualalias/samplehistoryremains;noC/build/newCPU.

Indexedfilloverlay:7/8CA6B6A parentssupply7;conditionalCA6978 fillCB00..CBFF
bank7F,FF256.103ROM starts.V10C-indexed-fill-parent-domains.json leavesone
liveindexsharedwithCA7635/CA6DF1 andactualalias/lifetimeconditionsopen.
NotnewCPU/fixedengineparents;noC/build.

Wrapperoverlay:24/24argument schemas named(10fixedWRAM,11stack,3liveptr),
124ROMstarts/current07prefixchecks.V10C-fill-wrapper-mixed-argument-schemas.json.
Zero unnamedarguments isNOTzero aliases;stackwrap/MMIO/2180/livepointer/
actualHDMAsample histories remainopen. No newCPU/C/build;copy30/25/5unchanged.

Fillargument overlay:all40parentsnamed=35fixedWRAM+2stack+2indexed+1wrapper;
151ROM startschecked. CA9C01'sboundedresetendsFF06,notFF10. Otherindexed/
stack/aliashistories remainopen. V10C-fill-engine-mixed-argument-schemas.json
preservescount1seed-only path andoriginalcopy30/25/5counts;noC/build.

Fillengine overlay:40directcalls=30qualifiedliteral+10mixed/live;fixedcalls
share11WRAM profiles,19reuses(notCPUcounts).160ROM startschecked in
V10C-fill-engine-literal-destination-family.json. A6A7notseededbyA3A7fill;
actualmixedaliases/samplehistory remain. No productionchange/compile.

Generic3..5 publisher refinement:completednonreentrant/no-alias writerhistory
hasDsubsetE(108symbolicmaskstates,notSCPUcontexts). Threeincomingbitpairs
leave24publicationcases;in-flight108/aliases retainunrestricted32.
Receipt:V10C-enable-dirty-completed-writer-invariant.json. Actualcase/initopen.

FF10first-enable overlay:2465ROM starts,oneenableparentCDCACF/fourdisable
parents. Earlierresume35 conditionallyleavesforegroundB1,notNMIquiescent.
V10C-FF10-enable-ancestry-and-NMI-window.json retainsactualretainedprofile/
dirty/init/alias histories;no newCPU/productionchange.

IRQcallback overlay:allfourcommand103 callers,twocurrent9484targets and
sevenliteralEC3..EC6 mutations covered(88ROM starts). Callbackpublication
isnotTIMEUPack/phasegate. V10C-IRQ-callback-publication-and-ack-boundary.json
retainsactualpendingIRQ/alias/reentrantobligations;no newCPU/lowering.

IRQ/HDMA subgate:steadyservicecadence/deadline source-derived in
V10C-HDMA-steady-service-deadline.json:580line/324initwallclocks,21184
normalIRQmargin. Actualsourceenabled-init/continuoushistory/staleIRQ and
aliases remainopen. No controllerchange,newfixture orcompile.

NMI/cursor overlay:1729-context interval matchesCURRENT07;two420Cwriters
definephysicalmask0 between84BE/90BE. V10C-NMI-cursor-epoch-join.json joins
thatinterval toexistingqualifiedinit states,withoutassuming actualraster
history. Wholemask0 differsfromdisabledchannelwithotherchannelenabled.
No productionchange,newtest or10closure.

Mapguard overlay:460ROM starts nameCA3129/3206 bit80 publishers. C311A3
tests live7F7000mapdata,not a provedviewportgate. BothCA2EAE parents covered;
otheraliases andactualsamples remainopen. ReuseV10C-scroll-map-flag-publishers.json
andreturntoHDMAcontrol/init/cursor histories;no newCPU/lowering claim.

Worker/viewport overlay:110ROM starts showselectorpath isnot the matching-
tag/equalprimary workerbranch. Viewportrefresh uses matchingprimaryslots,
0..4calls. Actualactive/refreshedobject relation remainsopen;do notinfer
it frominitialslotcopy. Receipt:V10C-scroll-worker-viewport-epoch.json.

Selectorgeometry overlay:486+55 sourcecheckedROM starts giveconditional
rowdifference<=objectrange andtwo realrangepublishers withvalues{0,2,3}.
Preserved SAME-activeobject boundedcoordinate/freshoffset impliesH<=223,
nonrepeat. Actualobject/range/offset history remainsopen,notallscrollclosure.
Receipts:V10C-scroll-selector-range-bound.json,V10C-scroll-range-publishers.json.

Caller-order overlay:V10C-scroll-selector-caller-order.json checks106 ROM
starts. Selector-driven scroll has prior0Ffillcall inordinary ancestry under
matchedreturns;latestwriter/HDMAsample andinterveningcallee aliases remain
open. No newCPU orproductionlowering isclaimed.

Pointer/header overlay:V10C-scroll-saved-pointer-header-provenance.json checks
128 existingROM starts. Both ordinarysavedpointer publishers are named;
F536 offsethighbyte andF537 bank mustnot be treated aspadding. Sevenliteral
mutations touchF535..F538;nonliteralaliases/actualsamplelifetime remainopen.

Latest10 source interval:V10C-CA-first-scroll-selector-lifetime.json covers
6546 existing contexts. F52A selector bytes are inherited before first scroll
under explicit alias conditions;no known selector fill occurs in that cut.
Actual last writer/header value and general alias history remain unresolved.
No new CPU count,production lowering or hardware-completion claim.

Updated2026-10-15. This is a progress overlay, not a rewrite of the sealed07
checklist or evidence of completed hardware reachability. The original full
per-family/per-feature checklist and sidecar remain authoritative discovery
inputs: docs/V07C-hardware-checklist.csv, docs/V07C-hardware-intelligence.csv and
its summary. Baseline checklist SHA256:
8db47c97e6632986cc0a4923e5440bb1a6eaec5050bce9ab2352f56ba032a6be.

Latest10 overlay:all14 display-resume cuts have conditional direct-mask
preservation equations. Audio97AE adds1708 current07 route contexts,not new
CPU admissions;actual masks/init/phase/alias histories remain open. Cold reset
D0/800C clears0070;restart store1 is skipped by the cold branch. This is not
audio bypass or global flag lifetime proof;12/13 receiver/elapsed wait remain.

Channel3 source overlay:FF2E's initial pointers are later mutated by the
foreground atCDA3FA/A416 (FF2F/30 andFF32/33). Conditional loop/math contracts
give32 coherent/53 byte-sampling values perfield;actual phase/math/alias
history remains open. Selected CPU has allfour real byte stores already.
The six A300 parents narrow to2 possible parents perenable variant;these
are source-route counts,not newly discovered contexts or reached hardware.

Fullfixedtable literal mutation overlay:40 bytes/4tables,5 wordwriters/10
pointerbytes;no literalheader/terminator mutation. FF24's FF25/26 andFF28/29
are live too. Completedbuilders plus namedknown-byte stores preserve control
knownness even during splitwords;actualretained cursors/liveheaders/aliases
remainopen. AD09's guarded equaldivision narrows activation at conditional
nointerference scope only;conservativeparent lists remain intact.

Live-scroll overlay:28 of44 followingheader domains have a scoped normal
constructed-record bound15/18 (476 offline layout/position combinations,
not actual-C/native tests). Sixteenrepeat domains andactualselection/cursor/
init/alias histories remainopen. No24bytespacing assumption or runtimeclamp.

Fullrepeat overlay:all16repeatheaders/bothbuffers now have named control-read
frontiers. Two buffer0 schemas terminate on siblingconstructedzero;30others
need sourcewriter/lifetime or selectionexclusion across57distinct addresses.
These544 offline position equations are not contexts/tests/naturalreach or
proof RAMisunknown. Payloadknownness andactualinit/cursor/aliases remainopen.

SurroundingCD sourcegate now narrows repeatselection:visiblecomponents are
-1or0..24;anynonnegativevisible endpoint orbothvisible endpoints excludes
repeat under existing geometry/helper/frame/noalias contracts. RemainingCD
case is the oddtopedge-1 endpoint paired withnonvisiblepositive>=29. CApaths
andactualinit/cursor/alias histories remainopen;467 existingstarts reviewed.

Fillproducer overlay:24 C60314 callers checked,10 literalprofiles joined,
14mixed/live prefixes retained. F52A..F533 has0F/00 sourcefills usingreal
overlapcopy;latestwriter isnotproved. Conditionalzero terminatesrepeat8B/
buffer1,conditional0F leadsnexttoF536. No extraCPU/native/controllertestcount.

The table reads only Family=ALL / Feature_or_Register=AREA_COMPLETENESS.
Feature subrows are not summed again. Exact07 counts are conditional source
facts, not runtime reach; deferred counts are overlapping conservative address
class intersections, NOT distinct S-CPU contexts or proved hardware uses.
Do not subtract a direct-operand harvest from them as though it were a complete
byte/address/value reconciliation. Their detailed unresolved rows remain retained.

| Area | 07 exact / deferred | Current implementation/evidence | Still to understand/join/certify |
|---|---:|---|---|
| CARTRIDGE | 0 / 0 | 01 identity/profile;08 mapped bus/SRAM owners | Physical PCB identity not claimed; preserve target contract |
| CPU | 281686 / 0 | 07 static source/libraries;09 timing bindings | Whole-core source/hardware and natural reconciliation remain |
| MEMORY | 16782 / 819380 | 08 WRAM/SRAM/knownness/fetch and executable-copy successor; final boundary selected | Later whole-core lifetime joins; no universal physical PCB claim |
| MATH_IO | 30 / 200686 | 08 arithmetic source;09 shared CPU-event pulse join; target runtime contract closed | Later whole-core interference reconciliation; no universal die-waveform claim |
| TIMING | 0 / 200701 | 09 selected NTSC event-order scheduler handoff | Actual downstream device joins and global phase/source reconciliation |
| DMA_HDMA | 0 / 401442 | 10 general controller and all23 direct trigger/configuration owner sets;root selected | Conservative alias/phase/coherence rows retained for17 global reconciliation |
| PPU_STORAGE | 0 / 200738 | 11 sole register/storage/latch/knownness owner;219 direct sites plus10 DMA/HDMA routes joined | 14 raster rendering and later natural certification |
| BACKGROUNDS | 0 / 200748 | 11 BG/mode/tile/scroll state reached through the one PPU owner | 14 causal pixels for source-reached modes and raster changes |
| OBJECTS | 0 / 200677 | 11 OAM/OBJ register/storage/overflow state owner | 14 OBJ evaluation/priority/pixels |
| COMPOSITION | 0 / 200716 | 11 main/subscreen/window/color/brightness state owner | 14 causal compositor and pixel certification |
| DISPLAY | 0 / 200689 | 09 raster timing plus11 geometry/blanking state and receiver join | 14 completed-frame publication and later natural certification |
| INPUT | 29 / 401380 | 09 phased autojoy timing only | 15 serial pins/results/manual reads/reset and source lifetimes |
| AUDIO_IO | 52 / 200675 | 12 sole directional APUIO owner;52 exact events/48 contexts joined and static-library qualified | 13 command execution and16 DSP/audio |
| S_SMP | 0 / 0 | 09 rational phase accumulator plus12 fixed IPL/timers and one7029-byte ARAM epoch to entry081A;qualified | 13 exact-PC static SPC700 code |
| S_DSP | 0 / 0 | No DSP owner claimed | 16 BRR/envelopes/mix/echo/PCM and SMP phase/reset joins |
| PERSISTENCE | 0 / 9781 | 08 SRAM storage/codec/fresh profile | 15 persistence transition and later natural in-game save/load |

## Version10 connection

The final three scene-tail direct mask effects are batch-joined using current
07 control authority:4553 ROM+2 WRAM contexts reviewed;1635 overlapping scene
review memberships retained separately. Current partition13 preservation+
1audio=14;no concrete mask/actual phase/global alias claim. Production's
95F6->9633 outer-frame return is already correct;four old05 targets are
retired analysis history,not missing S-CPU or a new core defect.

The19040-byte character transfer beforeCE4C9D now has a bank-safe source/
destination schema and tenth scoped EC8-preservation relation (200 contexts).
Seven direct B63 writers establish00/01/81 under their stated contract;
command11 OR01 preserves an old readback bit. Synchronous versus NMI source
metadata and timing differ and remain literal. Actual direction/mask/phase
is not inferred. Current resume partition10+1audio+3unclassified=14.

Three full-BG-clear profiles are source-joined beforeCA9E16:1024 zero words
per layer1/2/3 (138 ROM contexts). CPU direct stores and NMI fixed-source
DMA are distinct paths;request04 selects full-fill F068,not row-fill F069.
The ninth scoped mask relation is recorded. Current partition9+1audio+
4unclassified=14;all actual resume phases/11 VRAM semantics remain open.

OAM/color leaf source effects add two resume-mask relations (66 ROM contexts).
OAM staging:128 Y bytes=F0,32 high bytes=55,upload request0B27 OR01. Color
shadows feed normal NMI's CGWSEL2130,CGADSUB2131,and three COLDATA2132 writes.
No universal OBJ invisibility,atomic publication or implemented renderer is
claimed. Current partition8 preservation+1 audio+5 unclassified=14;all actual
resume phases remain open. See V10C-resume-OAM-color-leaf-effects.json.

The graphics family's literal descriptor is now bank/split reconciled:
8500..8CFF,one2048-byte launch each direction,no CPU repair branch.79 extra
descriptor contexts checked. This supplies the sixth scoped resume mask
equation,not a concrete mask,actual phase or PPU implementation. Seven other
resume routes plus the conditional audio route remain without that join.

The32x32 BG tilemap route beforeC4AF99 is now source-joined across488
existing contexts:2048-byte VRAM readback,1024-word ROM-to7F8500 patch,then
2048-byte VRAM upload. Ports2139/3A (including dummy213A) and2118/19,live BG2
start0B31,and real transfer timing remain required11 ownership. No PPU or
new CPU implementation is claimed. Actual D/scratch/EC8/phase stays explicit.

Audio-related source dependency before resumeC197AE is now explicit:
command111 installsD3:0000 and enabled command16 reaches the2140/2141 IPL
AA/BB handshake (113 existing ROM contexts). This reuses admitted S-CPU code;
it does not add new07 events or implement12/13. Driver D1800/DBR7E differs
from caller D0/DBR0. Actual port/boot timing and enable-bypass history remain
open;do not use the audio wait as a VBlank phase proof.

Five resume/reset routes now have explicit inherited0EC8 mask equations,not
zero-mask assumptions (220 ROM contexts plus ordinary-entry audit). Their
hardware420C disable does not clear softwareEC8. Shared source also names11
later11 PPU ports:brightness/blanking,OBJSEL,BG maps/tile bases,TM/TS,SETINI.
No PPU implementation or new native product is claimed. Nine other resume
routes and all14 actual call phases remain open.

Seven direct HDMA enable-mask writers and14 resume35 callers now have a
complete scoped source join (136 ROM contexts). Direct-producer domain only
sets channels3..7;generic hardware remains all eight. Resume's94B2 helper
has no wait/cursor init. Actual call masks/phases and aliases remain open;
see V10C-HDMA-enable-mask-source-origins.json. No C or native product changed.

IRQ/HDMA source timing now has an explicit normal timer/setup cut and finite
conditional service budget;see V10C-IRQ-HDMA-steady-field-phase-cut.json and
V10C-IRQ-HDMA-STEADY-FIELD-SERVICE-BOUND.md. Actual enabled-init/continuous
history remains open;the111 conservative pointer candidates are not retired.

Generic CPU copy payload knownness is production-selected for seven MVNs;
27 actual-C fixture cases and dual native qualification are joined by
V10C-block-copy-current-selection.json.24 units percompiler rebuilt,2530
objects reused,2554 members/2620 unique providers. Ordinary control/address
reads stay strict. Actual stack placement/source lifetime remains open.

V10C-dispatch-stack-source-domains.json names both exact native stack source
ranges,entryS+4..5 and+6..25,with all1696 trampoline and one direct caller
reconciled.34 existing ROM contexts checked;no production change or build.
Actual stack placement remains open;do not infer a global bound from cold
TXS08FC or initialize unpassed copied arguments as zero.

All three B400 source bank80 candidates are now retired under the complete
ordinary direct-parent contract. V10C-B400-byte-parent-source-closure.json
checks all three612E byte-masked inputs,restricting6166 quotient to0..19 and
both patch sources to7F. Bulk remainder13 was already proved. Earlier word-
width carry candidates below are historical,not current frontier entries.
No payload/global lifetime or extra CPU lowering is claimed.

V10C-B400-div13-source-domains.json retires the bulk-copy bank80 source
candidate using both parent remainder13 paths. Both patches also stay7F on
the byte-parent path;two word-parent patch source/read cases remain.254 reused
contexts checked;destination total25/30 is unchanged. The source's actual math
register protocol is retained,not replaced with a host division or fixture.

V10C-HDMA-cursor-source-qualification.json adds eight current-C retained/fresh
cursor cases to the unchanged64 baseline,without native rebuilding. The four
open10 source-control/lifetime/address groups are now named in the workflow
config. Controller behaviour and the game's actual phase claims remain separate.

V10C-live-copy-argument-schemas.json completes names/argument meanings for all
30 direct helper calls,withzero unnamed schemas. Destination exclusions stay25;
five live alias/stack domains remain.287 reused contexts checked;no CPU lowering,
MMIO exclusion or payload-knownness is inferred merely from naming a schema.

Latest scoped CPU-copy destination total25/30,five remaining,from
V10C-9E00-record-copy-ownership.json. Six shared record copies use root7F9E00,
bounded ROM tables/type/mask domains;1120 existing contexts checked,including
40 service families. No new CPU lowering,initialized-payload or global phase
claim. Earlier totals below are predecessor receipts only.

Current CPU-copy destination count is19/30,11 remaining,using
V10C-B400-copy-destination-ownership.json over earlier overlays. Three fixed7F
destinations are joined in195 reused contexts. Their source banks may be7F/80;
no source-MMIO exclusion or extra hardware-DMA transfer is inferred.

V10C-table-cursor-phase-ownership.json names the actual table-switch gate:
source configuration/NMI acknowledgement is not A2A initialization. Enabled
field-init loads A1T;disabled init only resets hidden flags. Four event histories
and ten reused contexts clarify remaining live-buffer/cursor lifetime work,
not new CPU lowerings or a natural phase certificate.

The zero-mask field-init correction is implemented,qualified in64 scoped C
cases and present in both refreshed native libraries (one unit percompiler,
2553 objects reused). Current selection/dependency authority is
V10C-zero-mask-current-selection.json.420C remains mask-only;no table/payload
or natural-phase completion claim follows from this controller fix.

V10C-window-request-lifetime.json joins both window source-table handshakes:
clear before edits,publish1 after construction,NMI copies only1. Twelve direct
writers give conditional request domain0or1;268 existing contexts checked.
This resolves in-progress source-copy concerns under the named no-alias/native
contracts. It does not resolve the distinct retained-register first-enable gap,
remove alternate source branches or certify11 window semantics.

V10C-cold-DMA-interrupt-lifetime.json resolves the cold841C/844D register/
interrupt-lifetime join under the declared reset/boot contract.385 existing
contexts checked;NMITIMEN0,Iset,HDMA0 and synchronous CPU suspension protect
the named fields. A set NMI flag is not an enabled edge. No full-transfer,
PPU phase,F007/global phase or native execution claim is added.

V10C-record-copy-loop-ownership.json adds one bounded CPU-copy caller to the
destination ownership total:16/30,14 remaining. Counter1..8 copies288bytes from
7F9400..951F to7F9520..9E1F.143 existing contexts checked;no new lowering or
hardware-DMA transfer. Frame/math/alias conditions and payload knownness remain
separate. Older15/15 counts below identify the predecessor receipt only.

V10C-transfer-receiver-routes.json joins28 fixed profiles/2 live-mode schemas
to the one08->11 PPU authority.15 fixed-envelope ports includeBG scroll,window,
BGMODE/mosaic andstorage/readback;four extra ports are only conservative live
mode possibilities. This adds receiving-owner meaning,not a new graphics mode,
PPU implementation or natural certification. Actual11 latches/storage/access
rules and14 rendering remain outstanding.

V10C-masked-copy-source-domains.json joins three source ranges through the
actual hardware-multiplier helper (209 reused contexts checked). Their source
bank is7F under masked-input/normal-completion contracts;destinations remain
live. This is not NH08-MATH-BUSY/phase closure or three new contexts/lowerings.
The overlap-fill helper remains literal CPU bus writes/copies,not host memset.

V10C-copy-caller-destination-ownership.json accounts for30 direct live-copy
helper calls.15 destination ranges exclude DMA writes under named source/
frame contracts;15 address domains remain. This reuses eight SRAM frames,
not a claim of working saves or full persistence completion. Actual incoming
D and DBR contracts stay intact;no forcedD0 or historical fixed-bank guard.

V10C-indexed-and-blockmove-address-ownership.json accounts for seven CPU MVN
starts. Six fixed destinations exclude DMA-register writes;two stack-source
read domains and the mutable template's live-bank domain remain open. The six
literal indexed register-window hits reuseF205 authority. No extra contexts,
new DMA request or broad conservative-ledger reduction is claimed.

V10C-fixed-indirect-control-knownness.json names all10 initial causal control
bytes for each of four fixed indirect profiles under their completed-builder
contracts. Trailing terminator-pointer samples remain real but are not payload
dependencies of the finished channel;no guessed padding is added. Low-WRAM
reset writers are not a high-WRAM zero-fill authority. Actual source phase,
alias/payload knownness and11 receiving semantics remain open.

V10C-live-table-byte-ownership.json records selected source inspection:CPU
table producers andHDMA samples share08 live WRAM/knownness through09 timing.
No frozen host table or synthetic atomic packet is required. This resolves
the mechanism-owner question,not actual sampled-byte knownness/phase/address
closure. The reconciled open10 list is in the configuration-lifetime boundary;
do not redo completed inventories or turn all gameplay data into constants.

V10C-scroll-slot-pointer-protocol.json joins the four-slot primary-to-working
pointer snapshot and object-link advancement (207 reused contexts ROM checked).
Viewport/active-pointer equality is phase-dependent. Finite counter/helper
conditions remain explicit;raw graph dominance is not claimed. No fabricated
atomic commit,permanent alias invariant or new native lowering was added.

V10C-scroll-guarded-coordinate-writers.json bounds two object-field producer
families to0..991 after their exact source guard (325 reused contexts checked).
A SAME-object/fresh-offset premise would exclude repeat headers,but pointer
ownership review shows viewport slot+0 versus C1DD active slot+3. That identity
is not assumed. Six direct active-pointer writers/112 contexts are documented
in V10C-ACTIVE-OBJECT-POINTER-OWNERS.md. No global geometry/alias or runtime claim.

V10C-scroll-offset-writer-protocols.json names16 directABSL offset-byte writers.
The source has a scopedX<=17/Y<=19 update,but temporary callers restore old
bytes and other writers accept live arguments. It is not a global geometry
invariant.173 reused contexts were ROM checked;indirect/indexed aliases and
actual object-field lifetime are still open. No new lowering/runtime claim.

V10C-scroll-geometry-source-domains.json joins the scroll height's real SNES
divider protocol (4204/5,4206,4214..17) and live object-field/offset arithmetic.
296 reused contexts are ROM checked,not newly discovered/lowered. Under normal
math completion/no-alias,positive CD heights<=16375 andCA<=16367,still allowing
repeat headers. Actual object writers and math/interrupt interference remain
open;this does not close NH08-MATH-BUSY or certify raster/PPU behavior.

V10C-scroll-header-residue-domains.json narrows the conditional four-caller
following-header envelope to44 values. Saved-local/frame/no-alias contracts
exclude00/80,not repeat headers such asFB. No actual gameplay geometry bound,
table-knownness closure or new lowering is claimed. Reuse these caller joins;
continue upstream geometry/helper and saved-local lifetime work.

Native candidate checkpoint is complete: V10C-controller-native-candidate.json
records one compiled DMA unit plus2553 reused objects per compiler,2554 byte-
verified members and resolved project references. Root source selection now
contains2554 sources via V10C-current-source-selection.json;10 source/lifetime closure and actual11 receivers
remain open. No EXE,natural execution or completed hardware certification.

Fifth profile: V10C-live-scroll-hdma-buffer-protocol.json resolves its finite
double-buffer/animation/record-writing protocol,conditional on original helper
completion. Current branch-aware layout has one/two prefix records;the earlier
fixed-two-prefix receipt was archived and replaced,without production C changes.
Preserve the position0 zero-header termination and actual08/09
multiplier dependency. Prefix/read/interrupt/payload lifetimes remain open;
this does not certify rendered scroll motion or change the07 context total.

Four fixed indirect tables are now derived from original ROM-backed builder
calls in V10C-indirect-hdma-table-builder-configurations.json (10 bytes each,
224 logical service lines). One table joins conditionally to mode7/1 payload
words, requiring foreground DBR7E and preserved data, not NMI DBR00. Do not mark
mode rendering certified. The fifth pointer path also exposes actual08 math-I/O
multiplier dependence through F532; retain this cross-owner source obligation.

Newest scoped HDMA source evidence: V10C-window-table-publication-protocols.json
joins16-byte producer bounds to18-byte copies with explicit cold source seeds.
V10C-hdma-command107-caller-configurations.json resolves selector/control/BBAD
for five admitted dispatcher paths (selectors2/3/4;channels5/4/3). Destinations
include scroll registers and2105/2106 BGMODE/mosaic. This advances BACKGROUNDS/
DISPLAY/DMA source meaning, not implemented11/14 behavior or proved mode values.
The earlier generic F229 selector/BBAD caveat remains for arbitrary entries,
but is no longer a reason to rescan these five completed caller slices.

Additional source intelligence retained while visiting the producers:
F226/F227 window-table requests have different wait/service behavior from the
VRAM producers; their ordering remains open. F208 publishes paired X8/Y8
writes to each Mode7 matrix/centre register211B..2120. Carry these exact ordered
writes to11, without claiming BGMODE7 is used or rendered. Details and remaining
obligations are in V10C-LIVE-TRANSFER-HARDWARE-JOINS.md.

VRAM stream/producer joins: V10C-vram-stream-writer-configurations.json names
five remaining direct stream configurations; V10C-vram-producer-protocols.json
connects three parameter-publication/direct-or-NMI-service protocols. Preserve
their live counts/payloads, distinct8/16-bit row counters and literal source
arithmetic. These source joins do not certify11 storage/graphics or new CPU
lowering; caller, argument, alias and payload lifetime obligations remain.

Indexed HDMA source seam: V10C-indexed-hdma-writer-configurations.json names
six existing F205 writer instructions/36 conditional byte expansions for
channels7..2, plus F229 parameter writers. These are not36 new CPU contexts
or proved executions. Live BBAD/selector/table domains remain open, including
possible non-PPU B-bus destinations; retain receiving-owner classification.

NMI service bank scope: V10C-nmi-transfer-bank-interval.json checks all four
entry prologues and preserves their D0/DBR0 setup through the pre852A interval
(1729 admitted contexts in a conservative offline call/mode graph;12 direct
trigger sites). This joins scoped MEMORY/DMA address meaning, not arbitrary
caller or payload lifetimes, new reached contexts, or hardware certification.

Descriptor writer reconciliation now has named local DP38/39 joins for all12
direct call sites in the existing graph, covering channel0/1. Ten masks are
local; two inherited masks join to their named NMI parent writers (01/02).
Evidence: V10C-descriptor-caller-writers.json and
V10C-descriptor-nmi-mask-writers.json. Actual caller banks, stack/interrupt and
payload lifetimes remain conditional; this does not reduce deferred totals.
F068/F069's four conditional VRAM writer configurations are now byte-expanded
in V10C-tile-fill-writer-configurations.json; source payload and actual11 PPU
consumption remain open. No new contexts or native selection are claimed.

Current source-inspection handoff: V10C-LIVE-TRANSFER-HARDWARE-JOINS.md records
F068/F069 paired VRAM fills and F205 indexed HDMA writers plus BGMODE/window/
composition writes. Caller banks, producer values and lifetimes remain explicit;
these conditional findings do not close the baseline deferred classes or prove
which graphics modes are used. Carry the receiving register facts into11/14.

- [x] Revisit and hash-check the07 baseline;retain all16 areas and their feature rows.
- [x] Implement the general DMA/HDMA controller source through08/09; scoped source
  gate59 cases passes;dual-compiler native candidate now built with one unit
  each. Selected into the root graph by exact source/native-product identity.
- [ ] Reconcile the07 DMA_HDMA obligations with exact banks, byte widths,
  producer values, writer/table lifetimes and receiving owners. Current direct
  harvest is92 existing contexts/118 byte overlaps/23 trigger bytes, all ABS
  with bank joins open; not a complete replacement for401442 deferred entries.
  The subsequent F004/F005 startup receipt joins two configurations and41
  existing contexts under their sealed cold-entry contracts. It does not
  subtract401442 entries, certify arbitrary callers, or erase the initial
  harvest's limitations. See V10C-startup-dma-configurations.json.
- [ ] Keep implemented, source-reached and certified states separate while10
  configurations close; carry remaining areas to their named Starter owners.
- [ ] Review this baseline/overlay at each subsequent milestone and at17/18
  whole-core reconciliation. Zero07 SMP/DSP hits is not absence of audio.

IRQ/DMA lifetime update: V10C-irq-scroll-table-mutation.json joins command103
guarded callback publication and the live7E:FF17/18 indirect-pointer mutation.
Preserve its two byte writes and actual pre-callback512-byte MVN time; the
21504-master-clock copy lower bound is not an exact callback raster timestamp.
The sibling callback has a6-call counter period/528-call disable protocol,
not a6-frame/528-frame certificate (V10C-irq-sibling-timer-protocol.json).
Current09/10 byte arbitration already retains these dependencies. Exact
IRQ/header phase, external aliases and table lifetime remain open; carry the
scroll-register/raster consequences into11/14. No new CPU contexts or decrement
of conservative07 classes is claimed.

Scroll height caller update: V10C-live-scroll-height-callers.json joins all
four direct callers and the callee's H-9 transformation. The two CD caller
equations exclude a zero following prefix header but do not exclude its repeat
bit without upstream helper bounds. The two CA arguments remain live DP/stack
values. These bounds/lifetimes remain10 source obligations, not new contexts
or a replacement for the later11/14 register/raster owners.
V10C-scroll-publication-service-protocol.json adds the ordered channel5 packet
and dirty/enable service join, conditional0B62 wait and literal whole0F1C clear
on command108. Input result4000/0EC7!=0 can skip the wait: do not invent a
frame-paced atomic publication or claim safe buffer reuse on those paths.
The height helper is unsigned min,not an inherent geometry cap. Remaining
upstream argument bounds and interrupt-overlap/read lifetimes stay explicit.
Display transition update: V10C-display-suspend-resume-transfers.json joins
commands1/34/35. Resume reuses channel registers and retains CMP4211's IRQ
acknowledgement; it is not a reset or channel rebuild. Source mask update:
V10C-hdma-direct-mask-writer-closure.json joins seven direct ABS writers and
the conditional zero-seeded F8-bit closure (32 possible masks,channels3..7).
Do not promote it to global alias closure or32 proved executions. Generic10
still implements all eight channels. Carry blank/main/subscreen meanings to11.

Direct bank reconciliation is now complete at named-scope level: all118 initial
operand-byte rows are covered (93NMI,22cold,3dispatcher;zero unassigned),per
V10C-direct-operand-bank-reconciliation.json. Arbitrary-entry/global aliases and
conservative07 classes are NOT certified by this join. Descriptor packet cohort:
V10C-descriptor-packet-configurations.json names all12 callers' OAM/CGRAM/VRAM/
readback fields and70 writer instructions (659 reused contexts). Preserve the
wide bank-byte overlap,F172/F030 direction-dependent BBAD18/39 and F011 CPU
repair latch/read-buffer traffic. Their11 receiving semantics remain unfinished.
V10C-current-trigger-reconciliation.json now indexes every direct trigger:
9 disable-only/14 nonzero-capable,zero unnamed scoped bank/mask/payload-owner
sets. This does not close actual payload/interrupt lifetimes or conservative
address classes. Context totals remain281686;no new discovery/lowering claimed.

Palette source lifetime update: V10C-palette-publication-service-protocol.json
joins119 command3 callsites to ordered parameter publication and NMI/direct
service. V10C-palette-command3-stack-arguments.json resolves31 complete literal
argument chains and leaves88 partial/live slices named. The31 literal callers'
22 immutable cartridge payload spans are bounded/hashed in
V10C-palette-literal-ROM-payloads.json;no source-bank crossing or CGRAM-index
wrap in that subset. This closes immutable source-data identity,not all caller
interference or11 CGRAM storage/latches/pixels. No palette fixtures substituted.
Current extension: V10C-palette-command3-producer-slices.json joins72 of the
initial88 partial caller chains,including49 newly constant ones. The119-caller
split is now80 constant/23 complete-live/16 partial. FF20 is paired shift/add,
not multiplication;runtime code was not replaced. Current ROM source receipt
V10C-palette-current-ROM-payloads.json covers80 callers/55 immutable spans,
reusing the old31 rather than redoing their individual payload checks. Remaining
live origins,16 boundary reasons and external parameter lifetimes stay named.
Subsequent source-origin joins now resolve those16 boundaries: five stack-backed
palettes/one live-index producer plus10 branch cases with20 finite paths.
Evidence: V10C-palette-stack-and-live-index-origins.json and
V10C-palette-branch-argument-origins.json. Current partition is80 constant,
39 complete-live-or-branch,0 unnamed argument chains. Two one-colour stack
payloads have explicit7FFF/33EA seeds. This is source ownership,not permission
to seed all palette RAM or claim alias/interruption/CGRAM/pixel completion.
V10C-palette-branch-ROM-payloads.json adds bounded immutable source domains for
six branch/live-CGADD callers.86/119 payload-source domains are now ROM-backed;
33 remain RAM/stack/unbounded-index cases. Possible256 table indices are not
256 reached configurations. Live CGADD wrap remains11-owned,not optimized away.

HDMA ownership update: V10C-hdma-dirty-register-ownership.json confines named
generic dirty channels to3..5,not special window6/7,under the zero-seed/caller/
no-alias contract. No runtime channel restriction or synthetic420C init added.
V10C-window-HDMA-header-read-bounds.json proves both window tables emit only
00..80 headers and consume at most16 bytes inside the18-byte copy. Header80
does not repeatedly consume payload;the previous overread warning is resolved.
Actual enable/dirty/retained-table lifetimes remain10-owned,PPU windows11-owned.
V10C-HDMA-publication-interleaving-ownership.json names retained-register versus
shadow-copy ownership across32 symbolic source-stage cases. Enable-before-dirty
can retain the old profile;it is not an atomic-packet guarantee. Actual natural
case occurrence and global aliases remain unproved. No extra wait/barrier or
synthetic register initialization was introduced.
V10C-HDMA-table-and-payload-read-domains.json joins four fixed indirect tables'
real12-byte maximum fetch extent,including post-terminator pointer samples.
V10C-IRQ-HDMA-pointer-byte-snapshots.json includes partial CPU-word-store
visibility:111 candidate pointer states and payload bound7E:BB28,not merely
the coherent-word bound. Live scroll still needs an actual height/header bound:
candidate transformed height351 can exceed24 written bytes;its gameplay
reachability is unproved. Mapped WRAM is not proof of written/known payload.

Configuration lifetime update: V10C-nmi-manual-configuration-lifetime.json
joins all10 NMI manual launches to the disable/re-enable cut;the descriptor's
seven register writers dominate86C0 perV10C-descriptor-register-writer-lifetime.json.
Use V10C-CONFIGURATION-LIFETIME-BOUNDARY.md to distinguish required DMA register
fields from live palette/tile data. Remaining synchronous/HDMA enable/header
work stays10-owned;PPU consumption is11-owned. No full10 or global phase proof.

Natural gameplay/PPU pixels/audio PCM/controls/save-load are not certified by
any check mark here. Current09 evidence is V09C-MILESTONE.md; current10 state is
config/v10-workflow.json and V10C-WORKFLOW.md.

# Version 13 correction and audit reopening (2026-10-16)

Version 13 has been corrected and reopened for an independent owner audit. The sole
Version 12 ARAM epoch enters static SPC700 execution at `$081A`. The source-only
graph contains 3,332 exact PCs, 6,574 instruction bytes, 3,623 edges and 122
used opcode forms. Six computed dispatches are finite and source-proved; zero
frontiers and zero byte overlaps remain. Exact bodies validate instruction
opcodes and protect 6,840 instruction/table bytes. Fifteen fixed-form bodies
consume source-proved live operands after 28 exact executable-ARAM mutation
pairs; every unproved protected write fails closed. Unknown PCs, changed
opcodes and unknown data also fail closed. No runtime decoder, interpreter,
fallback, learning or oracle/trace promotion is selected. The former blanket
write barrier and four-entry `$1C84` table proof were incorrect.

The Version 14 full re-read is closed after correcting renderer priority,
Mode 7 affine/mosaic, OBJ addressing/flips/frame-latched overflow, color math,
causal dependency and source-domain defects. The selected graph now contains
2,562 sources; both GCC and Clang warnings-as-errors static archives contain
2,562 members. The deterministic source join proves Modes 1/7, all six fixed
descriptors and SETINI `$00`; modes 2–6, EXTBG, overscan, interlace and
pseudo-hires are explicitly unreachable. No executable, natural run or oracle
promotion was used for this Version 14 closure. See `docs/V14C-MILESTONE.md`.

# Version 17 current whole-core state (2026-10-16)

This section supersedes the older active-version statements above without
deleting their source-history detail. Version 13 is reopened as described
above; other historical source/static-library gates retain their recorded
state. The selected production universe contains 281,686 S-CPU contexts and
3,332 exact S-SMP PCs. The corrected graph has zero byte conflicts and zero
flow frontiers, while its wider owner audit remains open.

| Area | Current production owner | Remaining Version 17 evidence |
|---|---|---|
| S-CPU / memory / math | Exact 07C static context universe through the 08C bus and 09C cycle plan | Natural route must add no unknown context, guard or knownness failure |
| Master timing / IRQ / refresh | One monotonic NTSC scheduler; exact field rational, short line, reset hold, NMI/IRQ, refresh and arithmetic pulse joins | Headless ladder and gameplay route must confirm continuous progress and no owner fault |
| DMA / HDMA | 10C controller bound last at every CPU-cycle boundary and advanced by the same scheduler | Natural route must qualify reached transfer configurations and signal consequences |
| PPU / BG / OBJ / composition | 11C storage plus 14C renderer on scheduler raster events; modes 0-7 contract present, target source-reached modes retained | Qualify nonblank/variable completed frames on actual program checkpoints |
| Input / autojoy | Corrected 15C standard-pad plus source-proved SNES Mouse serial owner; 33 exact input/control contexts joined to the 09C scheduler | Replay deterministic six-character movement routes in headless and visible frontend; later expose host mouse binding only if required by release scope |
| APUIO / S-SMP | 12C directional ports and timers plus 13C exact-PC static SPC700 owner | Natural command/upload route must remain inside the admitted graph |
| S-DSP / PCM | 16C 32-phase DSP; selected 1,024,000-Hz S-SMP profile yields 32,000 native PCM frames/s | Qualify known, expected nonzero PCM at a program point that requests music/SFX |
| Persistence | 08C portable SRAM codec plus frontend atomic executable-adjacent `Saves` policy | Perform in-game save/load and verify persistence across restart |
| Snapshots | Complete pointer-free Version 17 machine image with ROM/build/ABI/hash validation-before-commit | Fixed continuation, fresh-instance restore and rejection-without-mutation routes |
| Frontend | Complete target-renamed Starter v12 Jungle Strike frontend structure through the opaque API | Build once after source gate, wait for AVG, then identical visible route |

The selected clock-domain proof and receiver-chain audit is
`docs/V17C-TIMING-AUDIO-JOIN-AUDIT.md`. The only global ledger blocker is now
connected natural signal qualification. Compaction is forbidden until the full
headless ladder, gameplay, save/load, snapshot and visible-frontend testing are
finished and the user explicitly agrees testing is complete.

