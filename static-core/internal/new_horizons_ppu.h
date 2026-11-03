#ifndef NEW_HORIZONS_PPU_H
#define NEW_HORIZONS_PPU_H

#include "new_horizons_scheduler.h"

enum { NH_PPU_VRAM_BYTES = 65536u, NH_PPU_CGRAM_BYTES = 512u,
       NH_PPU_OAM_BYTES = 544u, NH_PPU_FRAME_WIDTH = 256u,
       NH_PPU_FRAME_MAX_HEIGHT = 239u,
       NH_PPU_FRAME_PIXELS = NH_PPU_FRAME_WIDTH * NH_PPU_FRAME_MAX_HEIGHT,
       NH_PPU_FRAME_KNOWN_BYTES = (NH_PPU_FRAME_PIXELS + 7u) / 8u };

/* No terrain exists beyond the source world's finite north/south ends.
 * This presentation-only entry is impossible for the qualified Sea tile /
 * palette encoding; it is deliberately cleared, never wrapped or fake sea. */
enum { NH_PPU_SEA_OUTSIDE_WORLD = 0xFFFFu };

typedef struct NHPPUWord {
    uint16_t value;
    uint16_t known_mask;
} NHPPUWord;

/* Host-only semantic UI fragments, captured with the actual native raster
 * source/window decision. No saved-image differencing or guest-state writes.
 * Both buffers and ownership scratch are excluded from machine snapshots. */
typedef struct NHPortUiCapture14 {
    uint16_t pixels[2][256u * 224u];
    /* Low two bits retain Port's 1=BG1,2=BG3,3=non-town OBJ contract.
     * Bit2=selected OBJ, bit3=Combat ship slot80..119; bits4/5=math flags;
     * bit6=source tactical BG1 cell marker or BG3 fleet/index world glyph;
       * bit7=source-qualified tactical cursor/effect OBJ (Mode29), or sailing
       * fleet OBJ (Mode09). In Mode09 bit6 marks unqualified low-rank BG1
       * world/weather, never permission to move it as a menu.
     * Additional provenance is host-only and does not alter native pixels. */
    uint8_t masks[2][256u * 224u];
    uint8_t tiles[2][32u * 28u]; /* Raster-selected source bits per 8px cell. */
    uint8_t object_owner[256];
    uint8_t work, published, valid[2], hud_only[2], dependent_math[2];
      uint8_t frame_mode[2]; /* Mixed09/29 raster frames must not qualify. */
      /* Host-only source camera correspondence, established at actual native
       * C2:0C0F/0EC9 commit boundaries. Never a saved guest/CPU field. */
      int32_t sea_anchor_x, sea_anchor_y;
      uint16_t sea_phase_x, sea_phase_y;
      uint8_t sea_camera_valid;
      uint8_t sea_camera_rebuilding; /* observed0A8D..0AB7, host-only */
      /* C9 discovery writes precede C4 postprocessing/C2 row uploads.
       * Keep the source's old hidden primitive until its row is published.
       * Observational only: not serialized and never a guest-state edit. */
      uint16_t sea_discovery_x, sea_discovery_y;
      uint16_t sea_discovery_map_x, sea_discovery_map_y, sea_discovery_stack;
      uint8_t sea_discovery_rows, sea_discovery_village, sea_discovery_refresh;
      /* C1:95C4 clears anchored world identity before consumed flag hides. */
      uint16_t sea_marker_retired_x, sea_marker_retired_y;
      uint8_t sea_marker_retired_valid;
      /* Last optional Sea presentation refusal; host diagnostics only. */
      uint32_t sea_refusal_stage, sea_refusal_subject;
      uint32_t sea_refusal_expected, sea_refusal_actual;
      /* C2:1658 retires source identity before the consumed OAM disappears.
       * Retain that explicit source witness, not a guessed nearest fleet. */
      uint8_t sea_retired_valid[16], sea_retired_fleet[16], sea_retired_model[16];
      /* A source slot can be reallocated before old consumed OAM retires.
       * Preserve only that exact witnessed pose, until its first change. */
      uint8_t sea_retired_reallocated[16], sea_retired_pose[16][5];
      /* Actual raster-selected BG2 cache obligations. Masked/stale gutters
       * are not native consumers; changed entries/scroll within a field fail. */
      uint16_t sea_bg2_entry[2][1024];
      uint8_t sea_bg2_seen[2][1024];
      uint16_t sea_hofs[2], sea_vofs[2];
      uint8_t sea_scroll_valid[2];
      uint8_t sea_mosaic_valid[2], sea_mosaic[2]; /* consumed uniform fog22/off02 */
      /* Fog samples before native BG3/backdrop masking. A visible world
       * pixel can sample an otherwise masked cache gutter. Keep that actual
       * native fringe, never extend its stale cache word into new margins. */
      uint8_t sea_mosaic_fringe[2][256u * 224u / 8u];
      /* Actual selected Sea world pixels must share one fixed-color style.
       * A mixed raster/window/subscreen effect remains explicitly unsupported. */
      uint8_t sea_color_valid[2], sea_color_control[2], sea_color_brightness[2];
      uint16_t sea_color_fixed[2];
      /* C2:4F8E / command50's finite W2 cell highlight. Capture actual raster
       * rows, not the already-empty post-field window registers. */
      uint8_t sea_rect_valid[2], sea_rect_brightness[2], sea_rect_any[2];
      uint8_t sea_rect_left[2][224], sea_rect_right[2][224];
      uint8_t sea_rect_qualified, sea_marker_qualified;
      /* Source-qualified chart is captured at publication, before later
       * instruction bus commits can replace its map registers. Host-only;
       * same immutable sequence as the native published frame. */
      uint16_t chart_pixels[2][512u * 288u];
      uint8_t chart_work_valid[2], chart_work_kind[2];
      uint64_t chart_sequence;
      uint8_t chart_source_kind, chart_kind, chart_valid;
    uint16_t lines;
    uint64_t sequence;
} NHPortUiCapture14;

typedef struct NHPPU11 {
    NHBusRuntime *bus;
    NHScheduler *scheduler;
    const NHBusValue *wrio;
    NHSchedulerReceivers downstream;
    NHBusValue registers[0x40];
    NHBusValue vram[NH_PPU_VRAM_BYTES];
    NHBusValue cgram[NH_PPU_CGRAM_BYTES];
    NHBusValue oam[NH_PPU_OAM_BYTES];
    NHPPUWord bg_hofs[4], bg_vofs[4], mode7[6];
    NHPPUWord mode7_hofs, mode7_vofs, fixed_color;
    NHBusValue vram_read[2], oam_latch, cgram_latch;
    NHBusValue ppu1_open_bus, ppu2_open_bus;
    uint16_t vram_address, oam_reload_address, oam_address;
    uint16_t latched_hcounter, latched_vcounter;
    uint8_t vram_increment, vram_remap, vram_increment_on_high;
    uint8_t oam_latch_pending, cgram_address, cgram_second;
    uint8_t scroll_latch, scroll_latch_known;
    uint8_t hscroll_latch, hscroll_latch_known;
    uint8_t mode7_latch, mode7_latch_known;
    uint8_t counter_latched, hcounter_second, vcounter_second;
    uint8_t forced_blank, brightness, overscan, interlace;
    uint8_t obj_range_over, obj_time_over;
    uint16_t work_frame[NH_PPU_FRAME_PIXELS];
    uint16_t published_frame[NH_PPU_FRAME_PIXELS];
    uint8_t work_known[NH_PPU_FRAME_KNOWN_BYTES];
    uint8_t published_known[NH_PPU_FRAME_KNOWN_BYTES];
    uint8_t obj_line_palette[NH_PPU_FRAME_WIDTH];
    uint8_t obj_line_rank[NH_PPU_FRAME_WIDTH];
    uint16_t published_height;
    uint8_t frame_ready, frame_published_this_vblank;
    uint8_t render_failure_kind, render_failure_value, render_failure_known_mask;
    uint32_t render_failure_address;
    uint64_t published_sequence, rendered_scanlines, unknown_scanlines;
    uint64_t register_reads[0x40], register_writes[0x40];
    uint64_t storage_reads, storage_writes;
    NHPortUiCapture14 *port_ui; /* Optional host observer; serialized as NULL. */
} NHPPU11;

NHBusStop nh_ppu11_power_on(NHPPU11 *, NHBusRuntime *, NHScheduler *,
                            const NHBusValue *wrio);
NHBusStop nh_ppu11_apply_zero_storage_profile(NHPPU11 *);
NHBusStop nh_ppu11_reset(NHPPU11 *);
/* Bind before nh_dma10_bind. This installs the sole PPU bus port and inserts
 * the PPU raster receiver ahead of the previously supplied machine receivers;
 * Version10 DMA then wraps this receiver chain without creating another PPU
 * path. No clocks or register effects occur while binding. */
NHBusStop nh_ppu11_bind(NHPPU11 *);
NHRegisterPort nh_ppu11_register_port(NHPPU11 *);
NHBusStop nh_ppu11_raster_event(NHPPU11 *, NHBusRuntime *,
                                const NHScheduler *, NHRasterEvent);
/* Native raster consumes Mode0 reset/title transitions and Mode1/Mode7. A
 * returned frame is immutable until the next VBLANK publication. */
NHBusStop nh_ppu14_raster_event(NHPPU11 *, NHBusRuntime *,
                                const NHScheduler *, NHRasterEvent);
int nh_ppu14_read_published_frame(const NHPPU11 *, uint16_t *, uint8_t *,
                                  uint32_t, uint16_t *, uint16_t *, uint64_t *);
int nh_ppu14_read_port_terrain(const NHPPU11 *, unsigned, uint16_t *, uint32_t);
/* Caller supplies source-qualified eight-pixel entries including a one-cell
 * sampling fringe for sub-tile camera phase. Terrain only, no guest mutation. */
int nh_ppu14_read_sea_terrain(const NHPPU11 *, const uint16_t *, unsigned,
                             unsigned, uint16_t *, uint32_t);
typedef struct NHPortObjectPixel14 {
    uint16_t color;
    uint8_t rank, palette, opaque;
} NHPortObjectPixel14;
int nh_ppu14_read_port_object(const NHPPU11 *, unsigned, unsigned, unsigned,
                             NHPortObjectPixel14 *);
int nh_ppu14_object_native_hidden(const NHPPU11 *, unsigned);
int nh_ppu14_sea_marker_object(const NHPPU11 *, unsigned);
int nh_ppu14_sea_mast_object(const NHPPU11 *, unsigned);
int nh_ppu14_sea_destination_object(const NHPPU11 *, unsigned);
  /* Finite foreign-fleet View UI, not an expanded world/cache read. */
  int nh_ppu14_read_fleet_page(const NHPPU11 *, uint16_t *, uint32_t);
/* C5:1479 character information, including separately published construction. */
int nh_ppu14_read_character_card(const NHPPU11 *, uint16_t *, uint32_t);
/* C5:380C own-fleet overview: decorative water, finite same-time ship art. */
int nh_ppu14_read_own_fleet(const NHPPU11 *, uint16_t *, uint32_t);
/* C5:0951 finite Ship Info pictures and independently published stat groups. */
int nh_ppu14_read_ship_info(const NHPPU11 *, uint16_t *, uint32_t);
/* C5:B8A8 Rearrange: finite table and separately anchored bottom controls. */
int nh_ppu14_read_rearrange(const NHPPU11 *, uint16_t *, uint32_t);
/* C5:80B2's selector, not C5:7F89 individual disposal confirmation. */
int nh_ppu14_read_scrap_selector(const NHPPU11 *, uint16_t *, uint32_t);
int nh_ppu14_read_scrap_detail(const NHPPU11 *, uint16_t *, uint32_t);
int nh_ppu14_read_ship_transaction(const NHPPU11 *, uint16_t *, uint32_t);
int nh_ppu14_read_ship_name(const NHPPU11 *, uint16_t *, uint32_t);
/* C5:3D3D's raw01 finite world chart, not an additional terrain mode. */
int nh_ppu14_read_world_chart(const NHPPU11 *, unsigned, uint16_t *, uint32_t);
/* Qualified host projections, in native OAM arbitration order. Source activity
 * and unwrapped coordinates must be proved by the core facade, never inferred
 * by this tile sampler from a hidden OAM sentinel. */
typedef struct NHPortActor14 {
    int16_t world_x, world_y;
    uint8_t tile, attributes, large;
} NHPortActor14;
int nh_ppu14_read_port_world(const NHPPU11 *, unsigned, const NHPortActor14 *,
                            unsigned, uint16_t *, uint32_t);
/* Same bounded Mode1 plane/object arbitration, with Combat's forty slots.
 * Source identity, activity, appearance and order belong to the facade. */
int nh_ppu14_read_combat_world(const NHPPU11 *, unsigned, const NHPortActor14 *,
                              unsigned, uint16_t *, uint32_t);
/* Sailing source fleets supplied in qualified OAM arbitration order. The
 * terrain component is already drawn; all supplied ship poses have Mode1
 * OBJ priority2 over the source's priority0 BG2 terrain. UI/weather are later. */
int nh_ppu14_draw_sea_fleets(const NHPPU11 *, const NHPortActor14 *, const uint8_t *, unsigned,
                            uint16_t *, uint32_t);
int nh_ppu14_sea_world_object(const NHPPU11 *, unsigned);
int nh_ppu14_draw_combat_label(const NHPPU11 *, uint16_t, int, int,
                              uint16_t *, uint32_t);
int nh_ppu14_draw_combat_cell(const NHPPU11 *, unsigned, int, int,
                             uint16_t *, uint32_t);
int nh_ppu14_combat_world_object(const NHPPU11 *, unsigned);
int nh_ppu14_combat_ui_object(const NHPPU11 *, unsigned);
int nh_ppu14_draw_combat_object(const NHPPU11 *, unsigned, int, int,
                               uint16_t *, uint32_t);
int nh_ppu14_draw_combat_pose(const NHPPU11 *, uint16_t, int, int,
                             uint16_t *, uint32_t);

#endif
