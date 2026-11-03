#ifndef NEW_HORIZONS_CORE_H
#define NEW_HORIZONS_CORE_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum {
    NH_CORE_ROM_BYTES = 0x200000u,
    NH_CORE_SRAM_FILE_BYTES = 36944u,
    NH_CORE_FRAME_WIDTH = 256u,
    NH_CORE_FRAME_MAX_HEIGHT = 239u,
    NH_CORE_FRAME_PIXELS = NH_CORE_FRAME_WIDTH * NH_CORE_FRAME_MAX_HEIGHT,
    NH_CORE_FRAME_KNOWN_BYTES = (NH_CORE_FRAME_PIXELS + 7u) / 8u,
    NH_CORE_NATIVE_AUDIO_RATE = 32000u
};

typedef enum NHCoreStatus {
    NH_CORE_OK = 0,
    NH_CORE_BAD_ARGUMENT,
    NH_CORE_BAD_ROM,
    NH_CORE_UNKNOWN_BYTE,
    NH_CORE_BAD_STATIC_GUARD,
    NH_CORE_PPU_UNAVAILABLE,
    NH_CORE_APUIO_UNAVAILABLE,
    NH_CORE_DMA_UNAVAILABLE,
    NH_CORE_INPUT_UNAVAILABLE,
    NH_CORE_CLOCK_UNAVAILABLE,
    NH_CORE_CPU_IO_UNAVAILABLE,
    NH_CORE_MEMORY_FAILURE,
    NH_CORE_UNPROVED_REGISTER
} NHCoreStatus;

typedef enum NHCoreRunResult {
    NH_CORE_RUN_FRAME_READY = 0,
    NH_CORE_RUN_STEP_LIMIT,
    NH_CORE_RUN_STOPPED,
    NH_CORE_RUN_BAD_ARGUMENT
} NHCoreRunResult;

/* Strict is the hardware-truth default. Deterministic profiles are explicit
 * project validation/frontend contracts; they are not physical power-on
 * claims for WRAM, PPU storage, or ARAM. */
typedef enum NHCorePowerOnProfile {
    NH_CORE_POWER_ON_STRICT_UNKNOWN = 0,
    NH_CORE_POWER_ON_DETERMINISTIC_ZERO_WRAM_V1 = 1,
    NH_CORE_POWER_ON_DETERMINISTIC_ZERO_MACHINE_V2 = 2,
    NH_CORE_POWER_ON_DETERMINISTIC_ZERO_MACHINE_ARAM_V3 = 3
} NHCorePowerOnProfile;

enum NHCoreInput {
    NH_CORE_INPUT_B = 0x8000u, NH_CORE_INPUT_Y = 0x4000u,
    NH_CORE_INPUT_SELECT = 0x2000u, NH_CORE_INPUT_START = 0x1000u,
    NH_CORE_INPUT_UP = 0x0800u, NH_CORE_INPUT_DOWN = 0x0400u,
    NH_CORE_INPUT_LEFT = 0x0200u, NH_CORE_INPUT_RIGHT = 0x0100u,
    NH_CORE_INPUT_A = 0x0080u, NH_CORE_INPUT_X = 0x0040u,
    NH_CORE_INPUT_L = 0x0020u, NH_CORE_INPUT_R = 0x0010u
};

enum NHCoreMouseButton {
    NH_CORE_MOUSE_LEFT = 0x01u,
    NH_CORE_MOUSE_RIGHT = 0x02u
};

typedef struct NHCore NHCore;

typedef struct NHCoreTiming {
    uint32_t master_hz_numerator;
    uint32_t master_hz_denominator;
    uint32_t smp_hz;
    uint32_t audio_hz;
    uint32_t presentation_hz_numerator;
    uint32_t presentation_hz_denominator;
    uint16_t normal_line_master_clocks;
    uint16_t short_line_master_clocks;
    uint16_t noninterlace_lines_per_field;
    uint32_t smp_ratio_numerator;
    uint32_t smp_ratio_denominator;
    uint32_t smp_initial_remainder;
    uint32_t reset_startup_master_clocks;
} NHCoreTiming;

typedef struct NHCoreDiagnostic {
    uint64_t master_clock;
    uint64_t completed_fields;
    uint64_t completed_cpu_cycles;
    uint64_t smp_cycles;
    uint32_t smp_remainder;
    uint64_t dsp_frames;
    uint64_t published_frames;
    uint64_t terminal_raster_events;
    uint64_t terminal_cpu_boundaries;
    uint64_t ssmp_instructions;
    uint64_t pcm_known_frames;
    uint64_t pcm_unknown_frames;
    uint64_t pcm_overflows;
    uint64_t sdsp_aram_reads;
    uint64_t sdsp_aram_writes;
    uint32_t scpu_address;
    uint32_t scpu_context_key;
    uint32_t failure_address;
    uint32_t pcm_fifo_frames;
    uint32_t apu_uploaded_bytes;
    uint16_t scpu_a;
    uint16_t scpu_x;
    uint16_t scpu_y;
    uint16_t scpu_d;
    uint16_t scpu_s;
    uint16_t wram_0052;
    uint16_t wram_0068;
    uint16_t wram_006a;
    uint16_t scanline;
    uint16_t hclock;
    uint16_t dot;
    uint16_t ssmp_pc;
    uint8_t ssmp_a;
    uint8_t ssmp_x;
    uint8_t ssmp_y;
    uint8_t ssmp_sp;
    uint8_t ssmp_psw;
    uint16_t sdsp_echo_pointer;
    uint16_t sdsp_echo_offset;
    uint16_t sdsp_echo_length;
    uint8_t failure_owner;
    uint8_t failure_value;
    uint8_t failure_known_mask;
    uint8_t scpu_p;
    uint8_t scpu_pbr;
    uint8_t scpu_dbr;
    uint8_t scpu_e;
    uint8_t wram_0052_known_mask;
    uint8_t wram_0068_known_mask;
    uint8_t wram_006a_known_mask;
    uint8_t scpu_failed;
    uint8_t apu_phase;
    uint8_t apu_expected_token;
    uint8_t apu_last_ack;
    uint8_t apu_cpu_port0;
    uint8_t apu_cpu_port1;
    uint8_t aram_21d1;
    uint8_t aram_21d1_known;
    uint8_t sdsp_flg;
    uint8_t sdsp_esa;
    uint8_t sdsp_edl;
    uint8_t sdsp_echo_writable;
    uint8_t ppu_mode;
    uint8_t ppu_forced_blank;
    uint8_t ppu_brightness;
    uint8_t ppu_main_screen;
    uint8_t ppu_main_screen_known_mask;
    uint8_t sdsp_active_voice_mask;
    uint8_t power_on_profile;
    uint8_t dma_active_channel;
    uint8_t hdma_enable;
    uint8_t dma_register_values[12];
    uint8_t dma_register_known_masks[12];
    uint16_t scpu_stack_window_base;
    uint8_t scpu_stack_window_values[32];
    uint8_t scpu_stack_window_known[32];
    uint8_t render_failure_kind;
    uint8_t render_failure_value;
    uint8_t render_failure_known_mask;
    uint32_t render_failure_address;
    uint64_t ppu_storage_reads;
    uint64_t ppu_storage_writes;
    uint64_t ppu_oam_data_writes;
    NHCoreStatus status;
    char scpu_failure_reason[128];
    /* Last guarded instruction entry, distinct from a rejected return target. */
    uint32_t scpu_instruction_address;
    uint32_t scpu_instruction_context;
    uint16_t scpu_instruction_s;
    /* Optional host presentation diagnostics, never serialized machine data. */
    uint32_t sea_refusal_stage, sea_refusal_subject;
    uint32_t sea_refusal_expected, sea_refusal_actual;
} NHCoreDiagnostic;

/* The core copies and owns the exact supported ROM. Optional SRAM is the
 * complete portable in-game save image returned by nh_core_encode_sram.
 * Filesystem paths and the executable-adjacent Saves directory remain host
 * policy; this API performs no file I/O. */
NHCore *nh_core_create(const uint8_t *rom, size_t rom_size,
                       const uint8_t *sram_file, size_t sram_file_size,
                       NHCoreStatus *status);
NHCore *nh_core_create_profile(const uint8_t *rom, size_t rom_size,
                               const uint8_t *sram_file, size_t sram_file_size,
                               NHCorePowerOnProfile profile,
                               NHCoreStatus *status);
void nh_core_destroy(NHCore *core);
NHCoreStatus nh_core_reset(NHCore *core);
NHCoreStatus nh_core_set_standard_pad(NHCore *core, unsigned port,
                                      uint16_t state);
/* Selects the source-reached SNES Mouse on a port. Motion is a native
 * sign/magnitude packet delta; values outside the hardware range saturate. */
NHCoreStatus nh_core_set_snes_mouse(NHCore *core, unsigned port,
                                    uint8_t buttons, int16_t delta_x,
                                    int16_t delta_y);
NHCoreRunResult nh_core_run_to_next_frame(NHCore *core, uint64_t step_limit,
                                          uint64_t *steps);
/* Observational host-output callback, invoked at instruction boundaries when
 * at least 128 native PCM frames are available. It may drain PCM, but must not
 * advance/reset/load the machine, change input, or retain a core callback. */
typedef void (*NHCoreAudioProgressCallback)(NHCore *core, void *opaque);
NHCoreRunResult nh_core_run_to_next_frame_streamed(
    NHCore *core, uint64_t step_limit, uint64_t *steps,
    NHCoreAudioProgressCallback progress, void *opaque);
int nh_core_read_published_frame(const NHCore *core, uint16_t *pixels,
                                 uint8_t *known, uint32_t capacity,
                                 uint16_t *width, uint16_t *height,
                                 uint64_t *sequence);
/* Optional host presentation, not another guest framebuffer. Outdoor-town
 * qualification joins C4:2B85..2E52's complete source map to current BG2.
 * Terrain only: actors, UI, windows and color math are not composed here.
 * A failed read must be discarded (the caller's output may be partial).
 * Both calls are observational; machine/snapshot/PCM state is unchanged. */
typedef struct NHCorePortTerrainInfo {
    uint16_t width, height, world_width, world_height;
    uint16_t origin_x, origin_y;
    int16_t native_scroll_x, native_scroll_y; /* Native camera may be -8 at the left edge. */
} NHCorePortTerrainInfo;
int nh_core_port_terrain_info(const NHCore *core, NHCorePortTerrainInfo *info);
int nh_core_read_port_terrain(const NHCore *core, uint16_t *pixels,
                              uint32_t capacity, NHCorePortTerrainInfo *info);
/* Development sailing World Map terrain. C2:0067/014D/0453 reconstruct
 * eight-pixel cells from the source72x72 region, not the rotating32x32 VRAM
 * cache. Native visible entries must join exactly before expansion.
   * This is NOT a complete frame: ships, UI, weather/math and true global
   * camera-edge semantics remain separate qualification work. Additional
   * region cells use ROM chunks and live port/discovery state, never a
   * repeated VRAM cache. Unqualified world edges fail, not fabricated fill.
 * No guest writes/time advancement. Discard partial output on failure. */
typedef struct NHCoreSeaTerrainInfo {
    uint16_t width, height;
    /* ROM24-cell chunk containing the consumed native origin. Not the
     * asynchronously rebuilt72x72 WRAM staging buffer's reused variables. */
    uint16_t region_column, region_row;
    int32_t origin_x, origin_y;
    int32_t native_origin_x, native_origin_y;
} NHCoreSeaTerrainInfo;
int nh_core_sea_terrain_info(const NHCore *core, NHCoreSeaTerrainInfo *info);
/* Optional read-only test observation; no bus read, state advance or mutation.
 * Returns false outside known Sea mode / unknown weather or MOSAIC. */
int nh_core_observe_sea_weather(const NHCore *core, uint8_t *weather, uint8_t *mosaic);
int nh_core_read_sea_terrain(const NHCore *core, uint16_t *pixels,
                             uint32_t capacity, NHCoreSeaTerrainInfo *info);
  /* Development sailing world component: exact terrain plus source-owned
   * fleets, preserving consumed OAM interpolation for allocated fleet slots.
   * Not a final frame: interface/weather/window/math qualification remains.
   * Observational only; discard output on failure. */
  int nh_core_read_sea_world(const NHCore *core, uint16_t *pixels,
                             uint32_t capacity, NHCoreSeaTerrainInfo *info);
  /* Qualified sailing composite through the same source-selected raster
   * observer as Port/Combat. Unsupported weather/math/objects fail explicitly;
   * this is not certification of all Sea states or global camera edges. */
  int nh_core_read_sea_frame(const NHCore *core, uint16_t *pixels,
                             uint32_t capacity, NHCoreSeaTerrainInfo *info);
/* Development Combat terrain only. CD:3B48's complete EC29 source plane is
 * joined to consumed BG2 using CD:3158's conversion, independently of Port.
 * This is NOT a complete Combat frame/admission contract: ships, selection,
 * effects, windows and color math must be qualified before frontend use.
 * Reads are observational; a failed read may leave partial output. */
typedef struct NHCoreCombatTerrainInfo {
    uint16_t width, height, world_width, world_height;
    uint16_t origin_x, origin_y;
    int16_t native_scroll_x, native_scroll_y;
    uint8_t camera_column, camera_row;
    uint8_t ship_status_mode; /* BG3 join:0 other,1 crew,2 hull,3 consumed mixed stats. */
} NHCoreCombatTerrainInfo;
int nh_core_combat_terrain_info(const NHCore *core, NHCoreCombatTerrainInfo *info);
int nh_core_read_combat_terrain(const NHCore *core, uint16_t *pixels,
                                uint32_t capacity, NHCoreCombatTerrainInfo *info);
/* Source-ship projection, not by itself a publishable Combat composite.
 * The mandatory mask reports slots (OAM80+n) with source-cleared/culled poses:
 * their authoritative model/heading is shown at base pose if no consumed
 * source-cycle reference can be found. Such unfinished results must not be
 * activated in the frontend. Never-emitted ships otherwise synchronize phase
 * with an observed matching fleet/effect group (not hypothetical draw history).
 * Windows, targeting and effects are also not composed by this call. */
int nh_core_read_combat_world(const NHCore *core, uint16_t *pixels,
                              uint32_t capacity, NHCoreCombatTerrainInfo *info,
                              uint64_t *unqualified_pose_slots);
/* Combat composite using the same optional raster observer as Port.
 * Tactical BG1 cell markers follow world coordinates, not window anchors;
 * command/modal fragments move as coherent source groups. The mandatory pose
 * mask remains an explicit unfinished-animation gate. Unqualified active
 * non-ship OBJ effects/cursors return0 until their ownership is established. */
int nh_core_read_combat_frame(const NHCore *core, uint16_t *pixels,
                              uint32_t capacity, NHCoreCombatTerrainInfo *info,
                              uint64_t *unqualified_pose_slots);
/* Development world stage: terrain and source-qualified town actors, not UI,
 * windows or color math. Do not publish as a complete widescreen game frame.
 * Unsupported poses/scenes return0; caller must discard partial output. */
int nh_core_read_port_world(const NHCore *core, uint16_t *pixels,
                            uint32_t capacity, NHCorePortTerrainInfo *info);
/* Optional observational UI raster capture. Enabling does not advance guest
 * time; a complete natural frame is required before captured UI is readable.
 * Reset/snapshot restore invalidate host fragments; they are never serialized.
 * Unsupported dependent color math fails the development composite explicitly. */
int nh_core_enable_port_ui_capture(NHCore *core, int enabled);
int nh_core_read_port_frame(const NHCore *core, uint16_t *pixels,
                            uint32_t capacity, NHCorePortTerrainInfo *info);
size_t nh_core_pcm_available(const NHCore *core);
size_t nh_core_pcm_drain(NHCore *core, int16_t *stereo, uint8_t *known,
                         size_t capacity);
NHCoreStatus nh_core_encode_sram(const NHCore *core, uint8_t *file,
                                 size_t size, uint64_t *generation);
int nh_core_ack_sram_flush(NHCore *core, uint64_t generation);
int nh_core_sram_dirty(const NHCore *core);
/* Complete same-build machine snapshots. The payload is versioned,
 * ROM-identified and pointer-free. Save/load are valid only at a quiescent
 * public API boundary; load validates a temporary image before commit. */
size_t nh_core_snapshot_size(const NHCore *core);
int nh_core_save_snapshot(const NHCore *core, void *destination, size_t size);
int nh_core_load_snapshot(NHCore *core, const void *source, size_t size);
NHCoreStatus nh_core_diagnostic(const NHCore *core, NHCoreDiagnostic *out);
const NHCoreTiming *nh_core_timing(void);

#ifdef __cplusplus
}
#endif
#endif
