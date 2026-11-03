#include "new_horizons_ppu.h"

#include <string.h>

typedef struct NHPixel14 {
    uint16_t color;
    uint16_t tile_entry; /* Local selected-source provenance, never saved state. */
    uint8_t rank;
    uint8_t layer;
    uint8_t palette;
    uint8_t transparent;
} NHPixel14;

typedef struct NHObject14 {
    uint16_t x;
    uint8_t y, tile, name, palette, priority, hflip, vflip, width, height;
} NHObject14;

/* Host-local reuse for one immutable render row. Never retained across a
 * raster callback (HDMA/VRAM/palette changes must be observed on the next row).
 * Tile bytes are validated lazily, in the original plane-read order. */
typedef struct NHTileRow14 {
    uint32_t address;
    uint8_t depth, valid, pixels[8];
} NHTileRow14;

typedef struct NHMode1Row14 {
    NHTileRow14 layer[4];
    /* Mode09 has8x8 tiles on all three layers. A raster callback reads
     * an immutable PPU row, so adjacent pixels can reuse its already-known
     * raw map word. Reset with the row; never cache palette/guest state. */
    struct {
        unsigned x, y;
        uint16_t entry;
        uint8_t valid;
    } sea_map[3];
} NHMode1Row14;

static uint16_t color_math(uint16_t main, uint16_t sub, int subtract, int half);

static int byte_known(NHBusValue byte) { return byte.known_mask == 0xFFu; }

static int missing(NHPPU11 *p, uint8_t kind, uint32_t address, NHBusValue byte) {
    /* NULL is an observational presentation read: fail without guest writes. */
    if (p == NULL) return 0;
    if (p->render_failure_kind == 0u) {
        p->render_failure_kind = kind;
        p->render_failure_address = address;
        p->render_failure_value = byte.value;
        p->render_failure_known_mask = byte.known_mask;
    }
    return 0;
}

static int read_reg8(const NHPPU11 *p, NHPPU11 *error, unsigned index, uint8_t *value) {
    if (index >= 0x34u) return missing(error, 1u, 0x2100u + index,
                                      (NHBusValue){ 0u, 0u });
    if (!byte_known(p->registers[index]))
        return missing(error, 1u, 0x2100u + index, p->registers[index]);
    *value = p->registers[index].value;
    return 1;
}

static int reg8(NHPPU11 *p, unsigned index, uint8_t *value) {
    return read_reg8(p, p, index, value);
}

static int read_vr8(const NHPPU11 *p, NHPPU11 *error, uint32_t address, uint8_t *value) {
    const NHBusValue byte = p->vram[address & 0xFFFFu];
    if (!byte_known(byte)) return missing(error, 2u, address & 0xFFFFu, byte);
    *value = byte.value;
    return 1;
}

static int vr8(NHPPU11 *p, uint32_t address, uint8_t *value) {
    return read_vr8(p, p, address, value);
}

static int read_vr16(const NHPPU11 *p, NHPPU11 *error, uint32_t address, uint16_t *value) {
    uint8_t low, high;
    if (!read_vr8(p, error, address, &low) || !read_vr8(p, error, address + 1u, &high)) return 0;
    *value = (uint16_t)(low | ((uint16_t)high << 8u));
    return 1;
}

static int read_color(const NHPPU11 *p, NHPPU11 *error, unsigned index, uint16_t *value) {
    const unsigned address = (index & 255u) << 1u;
    if (!byte_known(p->cgram[address]))
        return missing(error, 3u, address, p->cgram[address]);
    if (!byte_known(p->cgram[address + 1u]))
        return missing(error, 3u, address + 1u, p->cgram[address + 1u]);
    *value = (uint16_t)((p->cgram[address].value |
             ((uint16_t)p->cgram[address + 1u].value << 8u)) & 0x7FFFu);
    return 1;
}

static int color(NHPPU11 *p, unsigned index, uint16_t *value) {
    return read_color(p, p, index, value);
}

static uint16_t apply_brightness(uint16_t value, unsigned level) {
    const unsigned r = value & 31u, g = (value >> 5u) & 31u, b = (value >> 10u) & 31u;
    return (uint16_t)((r * level / 15u) | ((g * level / 15u) << 5u) |
                      ((b * level / 15u) << 10u));
}

/* Same fixed-color arithmetic as the native raster, BEFORE brightness.
 * The core admits only a constant style witnessed on actual selected world
 * pixels, not a guessed time/weather tint or a flattened screenshot colour. */
static uint16_t sea_presentation_color(const NHPPU11 *p, uint16_t value, unsigned layer_bit,
                                       int x, unsigned y) {
    const NHPortUiCapture14 *ui = p->port_ui;
    unsigned buffer = ui->published, control = ui->sea_color_control[buffer];
    if (ui->sea_rect_qualified) {
        int nx = x - 128, ny = (int)y - 32;
        if (layer_bit == 2u && nx >= 0 && nx < 256 && ny >= 0 && ny < 224 &&
            ui->sea_rect_left[buffer][ny] <= nx && ui->sea_rect_right[buffer][ny] >= nx)
            value = color_math(value, 0x00AFu, 0, 0);
        return apply_brightness(value, ui->sea_rect_brightness[buffer]);
    }
    if (control & layer_bit)
        value = color_math(value, ui->sea_color_fixed[buffer],
            (control & 0x80u) != 0u, (control & 0x40u) != 0u);
    return apply_brightness(value, ui->sea_color_brightness[buffer]);
}

static void sea_capture_color(NHPPU11 *p, NHPortUiCapture14 *ui, unsigned flags) {
    unsigned buffer = ui->work;
    unsigned control = (flags & 8u) ? 0u : p->registers[0x31].value & 0xF2u;
    unsigned fixed = control & 0x32u ? p->fixed_color.value : 0u;
    int supported = !(flags & 4u) &&
        (!(control & 0x32u) || (!(p->registers[0x30].value & 2u) &&
                               p->fixed_color.known_mask == 0x7FFFu));
    if (!(control & 0x32u)) control = 0u;
    if (!supported || (ui->sea_color_valid[buffer] &&
        (ui->sea_color_control[buffer] != control ||
         ui->sea_color_fixed[buffer] != fixed ||
         ui->sea_color_brightness[buffer] != p->brightness))) {
        ui->sea_color_valid[buffer] = 2u;
        return;
    }
    if (!ui->sea_color_valid[buffer]) {
        ui->sea_color_valid[buffer] = 1u;
        ui->sea_color_control[buffer] = (uint8_t)control;
        ui->sea_color_fixed[buffer] = (uint16_t)fixed;
        ui->sea_color_brightness[buffer] = p->brightness;
    }
}

static uint16_t direct_color(uint8_t pixel, uint8_t palette) {
    const unsigned red = ((pixel & 7u) << 2u) | ((palette & 1u) << 1u);
    const unsigned green = (((pixel >> 3u) & 7u) << 2u) |
                           (((palette >> 1u) & 1u) << 1u);
    const unsigned blue = (((pixel >> 6u) & 3u) << 3u) |
                          (((palette >> 2u) & 1u) << 2u);
    return (uint16_t)(red | (green << 5u) | (blue << 10u));
}

static int map_entry(const NHPPU11 *p, NHPPU11 *error, unsigned layer, unsigned world_x,
                     unsigned world_y, unsigned tile_size, uint16_t *entry) {
    uint8_t sc;
    unsigned width, height, tile_x, tile_y, screen;
    uint32_t base, address;
    if (!read_reg8(p, error, 7u + layer, &sc)) return 0;
    width = (sc & 1u) != 0u ? 64u : 32u;
    height = (sc & 2u) != 0u ? 64u : 32u;
    tile_x = (world_x % (width * tile_size)) / tile_size;
    tile_y = (world_y % (height * tile_size)) / tile_size;
    screen = (tile_y >> 5u) * (width == 64u ? 2u : 1u) + (tile_x >> 5u);
    base = (uint32_t)(sc & 0xFCu) << 9u;
    address = base + screen * 0x800u +
              (((tile_y & 31u) * 32u + (tile_x & 31u)) << 1u);
    return read_vr16(p, error, address, entry);
}

static unsigned mode1_rank(uint8_t bgmode, unsigned layer, unsigned high) {
    static const uint8_t mode0[4][2] = {{8u,11u},{7u,10u},{2u,5u},{1u,4u}};
    static const uint8_t normal[3][2] = {{6u,9u},{5u,8u},{1u,3u}};
    if ((bgmode & 7u) == 0u) return mode0[layer][high != 0u];
    if ((bgmode & 8u) != 0u && layer == 2u && high != 0u) return 11u;
    return normal[layer][high != 0u];
}

static unsigned obj_rank(uint8_t bgmode, unsigned priority) {
    static const uint8_t mode0[4] = {3u,6u,9u,12u};
    static const uint8_t mode1[4] = {2u,4u,7u,10u};
    static const uint8_t mode7[4] = {2u,4u,6u,7u};
    return ((bgmode & 7u) == 0u ? mode0 : (bgmode & 7u) == 7u ? mode7 : mode1)[priority & 3u];
}

static int mode1_tile_row(const NHPPU11 *p, NHPPU11 *error, NHTileRow14 *tile,
                          uint32_t row, unsigned depth) {
    uint8_t sources[4];
    unsigned plane, column;
    if (tile->valid && tile->address == row && tile->depth == depth) return 1;
    tile->valid = 0u;
    for (plane = 0u; plane < depth; ++plane) {
        if (!read_vr8(p, error, row + (plane >> 1u) * 16u + (plane & 1u),
                      &sources[plane])) return 0;
    }
    for (column = 0u; column < 8u; ++column) {
        uint8_t sample = 0u;
        for (plane = 0u; plane < depth; ++plane)
            sample |= (uint8_t)(((sources[plane] >> (7u - column)) & 1u) << plane);
        tile->pixels[column] = sample;
    }
    tile->address = row; tile->depth = (uint8_t)depth; tile->valid = 1u;
    return 1;
}

static int mode1_bg_read(const NHPPU11 *p, NHPPU11 *error, NHMode1Row14 *cache,
                    unsigned layer, unsigned x, unsigned y,
                    NHPixel14 *pixel) {
    uint8_t bgmode, mosaic, nba, packed;
    unsigned depth, sample_x = x, sample_y = y, size, world_x, world_y;
    unsigned px, py;
    uint16_t entry, palette_color;
    uint32_t base, row;
    memset(pixel, 0, sizeof(*pixel));
    pixel->transparent = 1u;
    if (!read_reg8(p, error, 5u, &bgmode) || !read_reg8(p, error, 6u, &mosaic)) return 0;
    /* Reset/title re-entry also exposes Mode0: four independent2bpp planes,
     * with32palette entries per BG. Reuse the owned tile/flip/mosaic/window
     * path; never substitute a blank frame for this valid hardware mode. */
    depth = (bgmode & 7u) == 0u ? (layer < 4u ? 2u : 0u) :
            layer < 2u ? 4u : layer == 2u ? 2u : 0u;
    if (depth == 0u) return 1;
    if ((mosaic & (1u << layer)) != 0u && (mosaic >> 4u) != 0u) {
        const unsigned span = (mosaic >> 4u) + 1u;
        sample_x -= sample_x % span;
        sample_y -= sample_y % span;
    }
    size = (bgmode & (uint8_t)(0x10u << layer)) != 0u ? 16u : 8u;
    world_x = sample_x + p->bg_hofs[layer].value;
    world_y = sample_y + p->bg_vofs[layer].value;
    if (p->bg_hofs[layer].known_mask != 0x03FFu ||
        p->bg_vofs[layer].known_mask != 0x03FFu)
        return missing(error, 5u, 0x210Du + layer * 2u,
                       (NHBusValue){ (uint8_t)p->bg_hofs[layer].value,
                                     (uint8_t)p->bg_hofs[layer].known_mask });
    if (bgmode == 0x09u && cache->sea_map[layer].valid &&
        cache->sea_map[layer].x == (world_x >> 3u) &&
        cache->sea_map[layer].y == (world_y >> 3u)) {
        entry = cache->sea_map[layer].entry;
    } else {
        if (!map_entry(p, error, layer, world_x, world_y, size, &entry)) return 0;
        if (bgmode == 0x09u) {
            cache->sea_map[layer].x = world_x >> 3u;
            cache->sea_map[layer].y = world_y >> 3u;
            cache->sea_map[layer].entry = entry;
            cache->sea_map[layer].valid = 1u;
        }
    }
    px = world_x % size; py = world_y % size;
    if ((entry & 0x4000u) != 0u) px = size - 1u - px;
    if ((entry & 0x8000u) != 0u) py = size - 1u - py;
    if (!read_reg8(p, error, 0x0Bu + (layer >> 1u), &nba)) return 0;
    base = (uint32_t)((layer & 1u) != 0u ? nba >> 4u : nba & 15u) << 13u;
    if (size == 16u) {
        entry = (uint16_t)((entry & 0xFC00u) |
                (((entry & 0x03FFu) + (px >> 3u) + ((py >> 3u) << 4u)) & 0x03FFu));
        px &= 7u; py &= 7u;
    }
    row = base + (uint32_t)(entry & 0x03FFu) * (depth * 8u) + py * 2u;
    {
        NHTileRow14 *tile = &cache->layer[layer];
        if (!mode1_tile_row(p, error, tile, row, depth)) return 0;
        packed = tile->pixels[px];
    }
    if (packed == 0u) return 1;
    pixel->palette = depth == 4u ?
        (uint8_t)((((entry >> 10u) & 7u) << 4u) | packed) :
        (uint8_t)((((entry >> 10u) & 7u) << 2u) | packed);
    if ((bgmode & 7u) == 0u) pixel->palette += (uint8_t)(layer * 32u);
    if (!read_color(p, error, pixel->palette, &palette_color)) return 0;
    pixel->color = palette_color;
    pixel->tile_entry = entry;
    pixel->rank = (uint8_t)mode1_rank(bgmode, layer, (entry >> 13u) & 1u);
    pixel->layer = (uint8_t)layer;
    pixel->transparent = 0u;
    return 1;
}

static int mode1_bg(NHPPU11 *p, NHMode1Row14 *cache, unsigned layer, unsigned x, unsigned y,
                    NHPixel14 *pixel) {
    return mode1_bg_read(p, p, cache, layer, x, y, pixel);
}

/* Presentation-only BG2 rectangle. The core facade qualifies the town source;
 * bounded world coordinates here never repeat the plane at its outer edges.
 * No machine copy, register write, error latch or clock/event advancement. */
int nh_ppu14_read_port_terrain(const NHPPU11 *p, unsigned origin_y,
                              uint16_t *pixels, uint32_t capacity) {
    unsigned x, y;
    uint8_t mode, sc, mosaic, nba;
    uint16_t palette[256] = {0};
    uint8_t palette_valid[256] = {0};
    if (p == NULL || pixels == NULL || capacity < 512u * 288u || origin_y > 224u ||
        p->forced_blank || p->overscan || p->interlace ||
        !read_reg8(p, NULL, 5u, &mode) || mode != 0x29u ||
        !read_reg8(p, NULL, 8u, &sc) || (sc & 3u) ||
        !read_reg8(p, NULL, 6u, &mosaic) || ((mosaic & 2u) && (mosaic >> 4u)) ||
        !read_reg8(p, NULL, 0x0Bu, &nba) ||
        p->bg_hofs[1].known_mask != 0x03FFu || p->bg_vofs[1].known_mask != 0x03FFu ||
        !read_color(p, NULL, 0u, &palette[0])) return 0;
    palette[0] = apply_brightness(palette[0], p->brightness);
    palette_valid[0] = 1u;
    /* This qualified BG2 plane is 32x32 sixteen-pixel tiles. Decode each
     * eight-pixel character row once, with lazy palette reads. All inputs
     * remain immutable during this observational call; no guest time runs. */
    for (y = 0u; y < 288u; ++y) {
        NHTileRow14 tile = {0};
        for (x = 0u; x < 512u; x += 8u) {
            uint16_t entry;
            unsigned px = x & 15u, py = (y + origin_y) & 15u, column, palette_base;
            uint32_t row;
            if (!map_entry(p, NULL, 1u, x, y + origin_y, 16u, &entry)) return 0;
            if (entry & 0x4000u) px = 15u - px;
            if (entry & 0x8000u) py = 15u - py;
            palette_base = ((entry >> 10u) & 7u) << 4u;
            row = ((uint32_t)(nba >> 4u) << 13u) +
                (uint32_t)(((entry & 1023u) + (px >> 3u) + ((py >> 3u) << 4u)) & 1023u) * 32u +
                (py & 7u) * 2u;
            if (!mode1_tile_row(p, NULL, &tile, row, 4u)) return 0;
            for (column = 0u; column < 8u; ++column) {
                unsigned sample = tile.pixels[(entry & 0x4000u) ? 7u - column : column];
                unsigned index = sample ? palette_base | sample : 0u;
                if (!palette_valid[index]) {
                    if (!read_color(p, NULL, index, &palette[index])) return 0;
                    palette[index] = apply_brightness(palette[index], p->brightness);
                    palette_valid[index] = 1u;
                }
                pixels[y * 512u + x + column] = palette[index];
            }
        }
    }
    return 1;
}

int nh_ppu14_read_sea_terrain(const NHPPU11 *p, const uint16_t *entries,
                             unsigned phase_x, unsigned phase_y,
                             uint16_t *pixels, uint32_t capacity) {
    uint16_t palette[256] = {0};
    uint8_t valid[256] = {0}, mode, nba, mosaic;
    unsigned y;
    if (!p || !entries || !pixels || capacity < 512u * 288u ||
        !p->port_ui || (p->port_ui->sea_color_valid[p->port_ui->published] != 1u &&
                       !p->port_ui->sea_rect_qualified) ||
        phase_x > 7u || phase_y > 7u || p->forced_blank ||
        p->overscan || p->interlace ||
        !read_reg8(p, NULL, 5u, &mode) || mode != 0x09u ||
        p->port_ui->sea_mosaic_valid[p->port_ui->published] != 1u ||
        !read_reg8(p, NULL, 0x0Bu, &nba)) return 0;
    mosaic = p->port_ui->sea_mosaic[p->port_ui->published];
    if (mosaic != 0u && mosaic != 2u && mosaic != 0x22u) return 0;
    for (y = 0u; y < 288u; ++y) {
        NHTileRow14 tile = {0};
        int sample_y = (int)y - 32;
        unsigned sy, x = 0u;
        if (mosaic == 0x22u) sample_y -= (sample_y % 3 + 3) % 3;
        sy = (unsigned)(sample_y + 32 + 8) + phase_y;
        while (x < 512u) {
            int sample_x = (int)x - 128;
            unsigned sx, px, py = sy & 7u, span, n, base;
            uint16_t entry;
            uint32_t address;
            if (mosaic == 0x22u) sample_x -= (sample_x % 3 + 3) % 3;
            sx = (unsigned)(sample_x + 128 + 8) + phase_x; px = sx & 7u;
            entry = entries[(sy >> 3u) * 66u + (sx >> 3u)];
            span = mosaic == 0x22u ? 1u : 8u - px;
            base = ((entry >> 10u) & 7u) << 4u;
            if (span > 512u - x) span = 512u - x;
            if (entry == NH_PPU_SEA_OUTSIDE_WORLD) {
                memset(pixels + y * 512u + x, 0, span * sizeof(*pixels));
                x += span;
                continue;
            }
            if (entry & 0x8000u) py = 7u - py;
            address = ((uint32_t)(nba >> 4u) << 13u) +
                (uint32_t)(entry & 1023u) * 32u + py * 2u;
            if (!mode1_tile_row(p, NULL, &tile, address, 4u)) return 0;
            for (n = 0u; n < span; ++n) {
                unsigned column = px + n;
                unsigned sample = tile.pixels[(entry & 0x4000u) ? 7u - column : column];
                unsigned index = sample ? base | sample : 0u;
                if (!valid[index]) {
                    if (!read_color(p, NULL, index, &palette[index])) return 0;
                    if (!p->port_ui->sea_rect_qualified)
                        palette[index] = sea_presentation_color(p, palette[index], sample ? 2u : 32u, 0, 0u);
                    valid[index] = 1u;
                }
                pixels[y * 512u + x + n] = p->port_ui->sea_rect_qualified ?
                    sea_presentation_color(p, palette[index], sample ? 2u : 32u, (int)(x + n), y) : palette[index];
            }
            x += span;
        }
    }
    return 1;
}

static int sign13(unsigned value) {
    value &= 0x1FFFu;
    return (int)(value ^ 0x1000u) - 0x1000;
}

static int32_t clip_mode7_offset(int32_t value) {
    return (value & 0x2000) != 0 ? value | ~1023 : value & 1023;
}

static int mode7_bg(NHPPU11 *p, unsigned layer, unsigned x, unsigned y,
                    NHPixel14 *pixel) {
    uint8_t sel, setini, cgwsel, mosaic, tile, sample;
    unsigned sample_x = x, sample_y = y;
    int sx, sy, tx, ty;
    int32_t a, b, c, d, cx, cy, wx, wy;
    uint32_t map_address, pixel_address;
    memset(pixel, 0, sizeof(*pixel)); pixel->transparent = 1u;
    if (!reg8(p, 0x06u, &mosaic) || !reg8(p, 0x1Au, &sel) ||
        !reg8(p, 0x30u, &cgwsel) ||
        !reg8(p, 0x33u, &setini)) return 0;
    if (layer == 1u && (setini & 0x40u) == 0u) return 1;
    if (p->mode7[0].known_mask != 0xFFFFu || p->mode7[1].known_mask != 0xFFFFu ||
        p->mode7[2].known_mask != 0xFFFFu || p->mode7[3].known_mask != 0xFFFFu ||
        p->mode7[4].known_mask != 0xFFFFu || p->mode7[5].known_mask != 0xFFFFu ||
        p->mode7_hofs.known_mask != 0x1FFFu || p->mode7_vofs.known_mask != 0x1FFFu)
        return missing(p, 5u, 0x211Bu, (NHBusValue){ 0u, 0u });
    if ((mosaic & (1u << layer)) != 0u && (mosaic >> 4u) != 0u) {
        const unsigned span = (mosaic >> 4u) + 1u;
        sample_x -= sample_x % span;
        sample_y -= sample_y % span;
    }
    sx = (sel & 1u) != 0u ? 255 - (int)sample_x : (int)sample_x;
    sy = (sel & 2u) != 0u ? 255 - (int)sample_y : (int)sample_y;
    a = (int16_t)p->mode7[0].value; b = (int16_t)p->mode7[1].value;
    c = (int16_t)p->mode7[2].value; d = (int16_t)p->mode7[3].value;
    cx = sign13(p->mode7[4].value); cy = sign13(p->mode7[5].value);
    wx = ((a * clip_mode7_offset(sign13(p->mode7_hofs.value) - cx) & ~63) +
          (b * clip_mode7_offset(sign13(p->mode7_vofs.value) - cy) & ~63) +
          (b * sy & ~63) + cx * 256 + a * sx) >> 8u;
    wy = ((c * clip_mode7_offset(sign13(p->mode7_hofs.value) - cx) & ~63) +
          (d * clip_mode7_offset(sign13(p->mode7_vofs.value) - cy) & ~63) +
          (d * sy & ~63) + cy * 256 + c * sx) >> 8u;
    if ((wx & ~1023) != 0 || (wy & ~1023) != 0) {
        const unsigned over = sel >> 6u;
        if (over == 2u) return 1;
        if (over == 3u) tile = 0u;
        else {
            wx &= 1023; wy &= 1023;
            map_address = (uint32_t)(((wy >> 3u) * 128 + (wx >> 3u)) << 1u);
            if (!vr8(p, map_address, &tile)) return 0;
        }
    } else {
        map_address = (uint32_t)(((wy >> 3u) * 128 + (wx >> 3u)) << 1u);
        if (!vr8(p, map_address, &tile)) return 0;
    }
    tx = wx & 7; ty = wy & 7;
    pixel_address = (((uint32_t)tile * 64u + (unsigned)ty * 8u + (unsigned)tx) << 1u) + 1u;
    if (!vr8(p, pixel_address, &sample)) return 0;
    if (layer == 1u) {
        pixel->rank = (sample & 0x80u) != 0u ? 5u : 1u;
        sample &= 0x7Fu;
    } else pixel->rank = 3u;
    if (sample == 0u) return 1;
    if (layer == 0u && (cgwsel & 1u) != 0u)
        pixel->color = direct_color(sample, 0u);
    else if (!color(p, sample, &pixel->color)) return 0;
    pixel->palette = sample; pixel->layer = (uint8_t)layer;
    pixel->transparent = 0u;
    return 1;
}

static int window_inside(uint8_t select, uint8_t left1, uint8_t right1,
                         uint8_t left2, uint8_t right2, uint8_t logic,
                         unsigned x) {
    int one = x >= left1 && x <= right1;
    int two = x >= left2 && x <= right2;
    const int one_enabled = (select & 2u) != 0u;
    const int two_enabled = (select & 8u) != 0u;
    if ((select & 1u) != 0u) one = !one;
    if ((select & 4u) != 0u) two = !two;
    if (!one_enabled) return two_enabled ? two : 0;
    if (!two_enabled) return one;
    if ((logic & 3u) == 0u) return one || two;
    if ((logic & 3u) == 1u) return one && two;
    if ((logic & 3u) == 2u) return one != two;
    return one == two;
}

static int layer_window(NHPPU11 *p, unsigned layer, unsigned x, int *inside) {
    uint8_t select, left1, right1, left2, right2, logic;
    unsigned select_reg, shift, logic_reg;
    if (layer > 5u) return 0;
    if (layer < 4u) { select_reg = 0x23u + (layer >> 1u); shift = (layer & 1u) * 4u; }
    else { select_reg = 0x25u; shift = (layer - 4u) * 4u; }
    logic_reg = layer < 4u ? 0x2Au : 0x2Bu;
    if (!reg8(p, select_reg, &select)) return 0;
    select = (uint8_t)((select >> shift) & 15u);
    if ((select & 10u) == 0u) { *inside = 0; return 1; }
    left1 = right1 = left2 = right2 = logic = 0u;
    if ((select & 2u) != 0u &&
        (!reg8(p, 0x26u, &left1) || !reg8(p, 0x27u, &right1))) return 0;
    if ((select & 8u) != 0u &&
        (!reg8(p, 0x28u, &left2) || !reg8(p, 0x29u, &right2))) return 0;
    if ((select & 10u) == 10u && !reg8(p, logic_reg, &logic)) return 0;
    logic = (uint8_t)((logic >> ((layer & 3u) * 2u)) & 3u);
    *inside = window_inside(select, left1, right1, left2, right2, logic, x);
    return 1;
}

static int layer_visible(NHPPU11 *p, unsigned layer, unsigned x,
                         uint8_t screen, uint8_t mask, int *visible) {
    int inside;
    *visible = (screen & (1u << layer)) != 0u;
    if (*visible && (mask & (1u << layer)) != 0u) {
        if (!layer_window(p, layer, x, &inside)) return 0;
        *visible = !inside;
    }
    return 1;
}

static void object_sizes(unsigned selector, unsigned large, uint8_t *width,
                         uint8_t *height) {
    static const uint8_t sizes[8][4] = {
        {8u,8u,16u,16u},{8u,8u,32u,32u},{8u,8u,64u,64u},{16u,16u,32u,32u},
        {16u,16u,64u,64u},{32u,32u,64u,64u},{16u,32u,32u,64u},{16u,32u,32u,32u}
    };
    *width = sizes[selector & 7u][large != 0u ? 2u : 0u];
    *height = sizes[selector & 7u][large != 0u ? 3u : 1u];
}

static int decode_object_read(const NHPPU11 *p, NHPPU11 *error,
                               unsigned index, NHObject14 *object) {
    uint8_t x, y, tile, attr, high, obsel;
    unsigned pair;
    if (index >= 128u) return 0;
    if (!byte_known(p->oam[index*4u]))
        return missing(error, 4u, index * 4u, p->oam[index * 4u]);
    if (!byte_known(p->oam[index*4u+1u]))
        return missing(error, 4u, index * 4u + 1u, p->oam[index * 4u + 1u]);
    if (!byte_known(p->oam[index*4u+2u]))
        return missing(error, 4u, index * 4u + 2u, p->oam[index * 4u + 2u]);
    if (!byte_known(p->oam[index*4u+3u]))
        return missing(error, 4u, index * 4u + 3u, p->oam[index * 4u + 3u]);
    if (!byte_known(p->oam[512u+index/4u]))
        return missing(error, 4u, 512u + index / 4u, p->oam[512u + index / 4u]);
    if (!read_reg8(p, error, 1u, &obsel)) return 0;
    x=p->oam[index*4u].value; y=p->oam[index*4u+1u].value;
    tile=p->oam[index*4u+2u].value; attr=p->oam[index*4u+3u].value;
    high=p->oam[512u+index/4u].value;
    pair = (high >> ((index & 3u) * 2u)) & 3u;
    object->x=(uint16_t)(x|((pair&1u)<<8u)); object->y=(uint8_t)(y+1u);
    object->tile=tile; object->name=attr&1u; object->palette=(attr>>1u)&7u;
    object->priority=(attr>>4u)&3u; object->hflip=(attr>>6u)&1u;
    object->vflip=attr>>7u;
    object_sizes(obsel >> 5u, pair >> 1u, &object->width, &object->height);
    return 1;
}

/* Share native OBJ name-table, flip and row decoding with the observational
 * wide compositor. Coordinates/culling belong to the caller: in particular,
 * a hidden town slot is NOT made active by sampling its tile data. */
static int object_row_read(const NHPPU11 *p, NHPPU11 *error,
                            const NHObject14 *object, uint8_t obsel,
                            unsigned line, unsigned tile_x,
                            uint16_t *p01, uint16_t *p23) {
    unsigned logical_x, base, tile;
    uint32_t address;
    if (line >= object->height || tile_x >= (unsigned)object->width / 8u) return 0;
    if (object->vflip) {
        if (object->width == object->height) line = object->height - 1u - line;
        else if (line < object->width) line = object->width - 1u - line;
        else line = object->width * 3u - 1u - line;
    }
    logical_x = object->hflip ? object->width / 8u - 1u - tile_x : tile_x;
    base = (obsel & 7u) << 14u;
    tile = ((object->tile & 0xF0u) + ((line >> 3u) << 4u) +
             ((object->tile + logical_x) & 15u)) & 255u;
    if (object->name) base += (1u + ((obsel >> 3u) & 3u)) << 13u;
    address = (base + tile * 32u + (line & 7u) * 2u) & 0xFFFFu;
    return read_vr16(p, error, address, p01) &&
           read_vr16(p, error, address + 16u, p23);
}

/* Native224-line visibility, using the same OBSEL size/9-bitX/8-bitY domain
 * as prepare_objects. A placeholder can wrap on one axis and still be hidden
 * by the other; do not substitute a fixed X or Y sentinel for this geometry. */
int nh_ppu14_object_native_hidden(const NHPPU11 *p, unsigned index) {
    NHObject14 object;
    unsigned y;
    int visible_x, visible_y;
    if (!p || !decode_object_read(p, NULL, index, &object)) return -1;
    y = (uint8_t)(object.y - 1u);
    visible_x = object.x < 256u || (unsigned)object.x + object.width > 512u;
    visible_y = y < 224u || y + object.height > 256u;
    return !(visible_x && visible_y);
}

/* C1:7BA7 -> 7A37 builds borders in two-column/two-row repeats. Check the
 * COMPLETE native panel, including separate corners, before extending only
 * its decorative repeats. No font, portrait or screenshot is stretched. */
static int fleet_page_panel(const NHPPU11 *p, unsigned top, unsigned height,
                             int tail) {
    unsigned x, r;
    for (r = 0u; r < height; ++r) for (x = 1u; x <= 30u; ++x) {
        uint16_t entry, expected;
        if (!map_entry(p, NULL, 0u, x * 8u, (top + r) * 8u, 8u, &entry)) return 0;
        if (!r) {
            if (x <= 2u) expected = (uint16_t)(0x3A3Fu + x);
            else if (x >= 29u) expected = (uint16_t)(0x3A27u + x);
            else {
                uint16_t first;
                if (!map_entry(p, NULL, 0u, 24u, top * 8u, 8u, &first) ||
                    (first != 0x3A42u && first != 0x3A43u)) return 0;
                expected = (uint16_t)(first ^ ((x - 3u) & 1u));
            }
        } else if (r == height - 1u) {
            if (x <= 2u) expected = (uint16_t)(0x3A4Eu + x);
            else if (x >= 29u) expected = (uint16_t)((tail ? 0x3A3Au : 0x3A36u) + x);
            else {
                uint16_t first;
                if (!map_entry(p, NULL, 0u, 24u, (top + r) * 8u, 8u, &first) ||
                    (first != 0x3A51u && first != 0x3A52u)) return 0;
                /* 51/52 are consecutive, but not an XOR-one pair. */
                if ((x - 3u) & 1u) expected = first == 0x3A51u ? 0x3A52u : 0x3A51u;
                else expected = first;
            }
        } else if (r == 1u) expected = x == 1u ? 0x3A46u : x == 30u ? 0x3A48u : 0x3A47u;
        else if (r == height - 2u) {
            expected = x == 1u ? 0x3A4Du : x == 30u ? (tail ? 0x3A56u : 0x3A4Eu) :
                (tail && x == 29u ? 0x3A55u : 0x3A47u);
        } else expected = x == 1u ? (uint16_t)(0x3A49u + ((r & 1u) * 2u)) :
            x == 30u ? (uint16_t)(0x3A4Au + ((r & 1u) * 2u)) : 0x3A47u;
        if (entry != expected) return 0;
    }
    return 1;
}

int nh_ppu14_read_fleet_page(const NHPPU11 *p, uint16_t *pixels, uint32_t capacity) {
    const NHPortUiCapture14 *ui;
    uint16_t background[256u * 224u];
    uint8_t opaque[256u * 224u];
    unsigned x, y, b, bottom, report, lower = 1u, blue = 1u;
    uint8_t mode, tm, ts, math, mosaic, obsel;
    uint16_t entry;
    if (!p || !pixels || capacity < 512u * 288u || !(ui = p->port_ui) ||
        ui->sequence != p->published_sequence || !ui->valid[ui->published] ||
        ui->frame_mode[ui->published] != 0x09u || ui->dependent_math[ui->published] ||
        !read_reg8(p, NULL, 5u, &mode) || mode != 0x09u ||
        !read_reg8(p, NULL, 0x2Cu, &tm) || tm != 0x15u ||
        !read_reg8(p, NULL, 0x2Du, &ts) || ts != 0x15u ||
        !read_reg8(p, NULL, 0x31u, &math) || math ||
        !read_reg8(p, NULL, 6u, &mosaic) || (mosaic >> 4u) ||
        !read_reg8(p, NULL, 1u, &obsel) || obsel || p->forced_blank || p->brightness != 15u ||
        p->bg_hofs[0].known_mask != 0x3FFu || p->bg_hofs[0].value ||
        p->bg_vofs[0].known_mask != 0x3FFu || p->bg_vofs[0].value ||
        !fleet_page_panel(p, 0u, 10u, 0)) return 0;
    report = 0u; bottom = 112u;
    if (!fleet_page_panel(p, 14u, 14u, 0)) {
        report = 1u; bottom = 136u;
        if (!fleet_page_panel(p, 17u, 10u, 1)) {
            /* Source construction publishes the complete header BEFORE its
             * portrait/icons/lower panel, and report replacement briefly has
             * header+strip only. These are real UI phases, not blank exemptions.
             * The loop below still checks EVERY remaining cell is zero/080F. */
            lower = 0u;
            if (!map_entry(p, NULL, 0u, 16u, 80u, 8u, &entry)) return 0;
            blue = entry == 0x080Fu;
            bottom = 80u;
            if (blue) {
                if (!map_entry(p, NULL, 0u, 16u, 112u, 8u, &entry)) return 0;
                bottom = entry == 0x080Fu ? 136u : 112u;
            }
        }
    }
    /* C5:A3E7 publishes the lower parchment BEFORE the blue-strip producer.
     * That short phase has both panels but an intentionally black gap. */
    if (!map_entry(p, NULL, 0u, 16u, 80u, 8u, &entry)) return 0;
    blue = entry == 0x080Fu;
    /* BG2 still contains covered coast data. Require the exact finite BG1
     * blue strip/black gutters instead of revealing that stale world plane. */
    for (y = 0u; y < 28u; ++y) for (x = 0u; x < 32u; ++x) {
        if (x && x < 31u && (y < 10u || (lower && y >= bottom / 8u && y < (report ? 27u : 28u)))) continue;
        if (!map_entry(p, NULL, 0u, x * 8u, y * 8u, 8u, &entry) ||
            entry != (blue && y >= 10u && y < bottom / 8u && x >= 2u && x < 30u ? 0x080Fu : 0u)) return 0;
    }
    for (x = 0u; x < 128u; ++x) {
        NHObject14 o;
        unsigned word, oy;
        int hidden = nh_ppu14_object_native_hidden(p, x);
        if (hidden < 0) return 0;
        if (hidden) continue;
        if (!decode_object_read(p, NULL, x, &o)) return 0;
        word = o.tile | ((unsigned)p->oam[x * 4u + 3u].value << 8u);
        oy = (uint8_t)(o.y - 1u);
        if (x >= 20u && x < 50u && word == 0x35C0u + x - 20u &&
            o.width == 8u && o.height == 8u &&
            o.x == 40u + ((x - 20u) % 5u) * 8u && oy == 15u + ((x - 20u) / 5u) * 8u) continue;
        /* The existing C0:93DF controller also animates these UI-strip slots:
         * its source-qualified mask0002 yields the two consumed C8/CA poses. */
        else if (x >= 113u && x <= 122u && (word & ~2u) == 0x3AC8u && o.width == 16u &&
                 o.height == 16u && o.x >= 64u && o.x < 192u && oy >= 84u && oy < 96u) continue;
        else if (report && x >= 50u && x < 80u && word == 0x37E0u + x - 50u &&
                 o.width == 8u && o.height == 8u && o.x == 24u + ((x - 50u) % 5u) * 8u &&
                 oy == 151u + ((x - 50u) / 5u) * 8u) continue;
        else if (report && x < 4u && ((word & ~4u) == 0x3200u + x) &&
                 o.width == 8u && o.height == 8u && o.x >= 16u && o.x < 240u &&
                 oy >= 144u && oy < 208u) continue;
        else return 0;
    }
    b = ui->published;
    for (y = 0u; y < 224u; ++y) {
        NHMode1Row14 cache = {0};
        for (x = 0u; x < 256u; ++x) {
            NHPixel14 pixel;
            unsigned at = y * 256u + x, mask = ui->masks[b][at];
            if (!mode1_bg_read(p, NULL, &cache, 0u, x, y, &pixel) || (mask & 0x30u)) return 0;
            background[at] = pixel.transparent ? 0u : pixel.color;
            opaque[at] = (uint8_t)!pixel.transparent;
            /* Rejoin CURRENT decorative tiles to actual raster-selected BG1.
             * A mixed/transient source change cannot be accepted by shape alone. */
            if (!(mask & 4u) && (mask & 3u) == 1u &&
                (pixel.transparent || pixel.color != ui->pixels[b][at])) return 0;
        }
    }
    for (y = 0u; y < 288u; ++y) {
        unsigned sy = y < 80u ? y : y < bottom + 64u ? 80u + ((y - 80u) & 7u) : lower ? y - 64u : 223u;
        for (x = 0u; x < 512u; ++x) {
            unsigned sx = x < 128u ? x : x >= 384u ? x - 256u : 120u + (x & 15u);
            pixels[y * 512u + x] = background[sy * 256u + sx];
        }
    }
    for (y = 0u; y < 224u; ++y) for (x = 0u; x < 256u; ++x) {
        unsigned at = y * 256u + x, mask = ui->masks[b][at], dx, dy;
        if (!(mask & 4u) && (mask & 3u) != 2u) continue;
        /* Do not carry native BG3 black gutter masks into the larger panel. */
        if (!(mask & 4u) && !opaque[at] && !ui->pixels[b][at]) continue;
        dx = x + 128u;
        dy = y < 80u ? y : (y < 112u || (blue && y < bottom)) ? y + 32u : y + 64u;
        if (!report && y >= bottom) dx = x + (x < 128u ? 0u : 256u);
        pixels[dy * 512u + dx] = ui->pixels[b][at];
    }
    return 1;
}

/* C5:137D's icon packets and C5:1479's full-page parchment are structured UI,
 * not additional world cells. Match every source tile before repeating ONLY
 * decorative fill/borders. A construction packet may still contain plain fill
 * where an icon has not been published; final portrait/text are not required. */
static uint16_t character_card_icon(unsigned x, unsigned y) {
    if (x >= 3u && x < 7u && y >= 12u && y < 14u)
        return (uint16_t)(0x3AC0u + (y - 12u) * 4u + x - 3u);
    if (x >= 3u && x < 7u && y >= 15u && y < 17u)
        return (uint16_t)(0x3AC8u + (y - 15u) * 4u + x - 3u);
    if (y >= 18u && y < 21u) {
        if (x >= 4u && x < 7u) return (uint16_t)(0x3AD0u + (y - 18u) * 3u + x - 4u);
        if (x >= 8u && x < 11u) return (uint16_t)(0x3AD9u + (y - 18u) * 3u + x - 8u);
        if (x >= 12u && x < 15u) return (uint16_t)(0x3AE2u + (y - 18u) * 3u + x - 12u);
    }
    if (y >= 22u && y < 25u) {
        if (x >= 6u && x < 9u) return (uint16_t)(0x3AFDu + (y - 22u) * 3u + x - 6u);
        if (x >= 10u && x < 13u) return (uint16_t)(0x3AFDu + (y - 22u) * 3u + x - 10u);
    }
    if (x >= 17u && x < 20u && y >= 12u && y < 23u && (y - 12u) % 3u < 2u)
        return (uint16_t)(0x3B06u + ((y - 12u) / 3u) * 6u + ((y - 12u) % 3u) * 3u + x - 17u);
    if (x >= 24u && x < 27u && y >= 12u && y < 20u && (y - 12u) % 3u < 2u)
        return (uint16_t)(0x3B1Eu + ((y - 12u) / 3u) * 6u + ((y - 12u) % 3u) * 3u + x - 24u);
    return 0u;
}

static uint16_t character_card_border(unsigned x, unsigned y) {
    if (!y) return x < 2u ? (uint16_t)(0x3A40u + x) : x >= 30u ?
        (uint16_t)(0x3A26u + x) : (uint16_t)(0x3A43u - (x & 1u));
    if (y == 27u) return x < 2u ? (uint16_t)(0x3A4Fu + x) : x >= 30u ?
        (uint16_t)(0x3A39u + x) : (uint16_t)(0x3A51u + (x & 1u));
    if (y == 1u) return x == 0u ? 0x3A46u : x == 31u ? 0x3A48u : 0x3A47u;
    if (y == 26u) return x == 0u ? 0x3A4Du : x == 30u ? 0x3A55u : x == 31u ? 0x3A56u : 0x3A47u;
    return x == 0u ? (uint16_t)(0x3A49u + (y & 1u) * 2u) :
        x == 31u ? (uint16_t)(0x3A4Au + (y & 1u) * 2u) : 0x3A47u;
}

int nh_ppu14_read_character_card(const NHPPU11 *p, uint16_t *pixels, uint32_t capacity) {
    const NHPortUiCapture14 *ui;
    uint16_t background[256u * 224u];
    uint8_t icons[32u * 28u] = {0};
    unsigned x, y, b;
    uint8_t value;
    if (!p || !pixels || capacity < 512u * 288u || !(ui = p->port_ui) ||
        ui->sequence != p->published_sequence || !ui->valid[ui->published] ||
        ui->frame_mode[ui->published] != 9u || ui->dependent_math[ui->published] ||
        p->forced_blank || p->brightness != 15u ||
        !read_reg8(p, NULL, 5u, &value) || value != 9u ||
        !read_reg8(p, NULL, 1u, &value) || value ||
        !read_reg8(p, NULL, 6u, &value) || value ||
        !read_reg8(p, NULL, 0x2Cu, &value) || value != 0x15u ||
        !read_reg8(p, NULL, 0x2Du, &value) || value != 0x15u ||
        !read_reg8(p, NULL, 0x31u, &value) || value ||
        p->bg_hofs[0].known_mask != 0x3FFu || p->bg_hofs[0].value ||
        p->bg_vofs[0].known_mask != 0x3FFu || p->bg_vofs[0].value) return 0;
    for (y = 0u; y < 28u; ++y) for (x = 0u; x < 32u; ++x) {
        uint16_t entry, icon = character_card_icon(x, y);
        if (!map_entry(p, NULL, 0u, x * 8u, y * 8u, 8u, &entry)) return 0;
        if (entry == character_card_border(x, y)) continue;
        if (!icon || entry != icon) return 0;
        icons[y * 32u + x] = 1u;
    }
    b = ui->published;
    for (y = 0u; y < 224u; ++y) {
        NHMode1Row14 cache = {0};
        for (x = 0u; x < 256u; ++x) {
            NHPixel14 pixel;
            unsigned at = y * 256u + x, mask = ui->masks[b][at];
            if ((mask & 0xF8u) || !mode1_bg_read(p, NULL, &cache, 0u, x, y, &pixel)) return 0;
            background[at] = pixel.transparent ? 0u : pixel.color;
            if (mask & 4u) {
                NHObject14 object;
                NHPortObjectPixel14 sample;
                unsigned index, ox, oy, word;
                if (x >= 32u && x < 72u && y >= 31u && y < 79u) {
                    index = 50u + ((y - 31u) / 8u) * 5u + (x - 32u) / 8u;
                    ox = 32u + ((index - 50u) % 5u) * 8u;
                    oy = 31u + ((index - 50u) / 5u) * 8u;
                    word = 0x37E0u + index - 50u;
                } else if (x >= 184u && x < 232u && y >= 183u && y < 207u) {
                    index = ((x - 184u) / 24u) * 9u + ((y - 183u) / 8u) * 3u + ((x - 184u) % 24u) / 8u;
                    ox = 184u + (index / 9u) * 24u + (index % 3u) * 8u;
                    oy = 183u + ((index % 9u) / 3u) * 8u;
                    word = 0x3210u + index;
                } else return 0;
                if (!decode_object_read(p, NULL, index, &object) ||
                    object.x != ox || (uint8_t)(object.y - 1u) != oy ||
                    object.width != 8u || object.height != 8u ||
                    (object.tile | ((unsigned)p->oam[index * 4u + 3u].value << 8u)) != word ||
                    !nh_ppu14_read_port_object(p, index, x - ox, y - oy, &sample) ||
                    !sample.opaque || sample.color != ui->pixels[b][at]) return 0;
            } else if ((mask & 3u) == 1u) {
                if (pixel.transparent || pixel.color != ui->pixels[b][at]) return 0;
            } else if ((mask & 3u) == 2u) {
                if (!mode1_bg_read(p, NULL, &cache, 2u, x, y, &pixel) ||
                    pixel.transparent || pixel.color != ui->pixels[b][at]) return 0;
            } else if (mask || ui->pixels[b][at] || background[at]) return 0;
        }
    }
    /* Expand the actual full-page border and its 8px parchment repeat; icons
     * are NOT backing material. Top/bottom corners retain native proportions. */
    for (y = 0u; y < 288u; ++y) for (x = 0u; x < 512u; ++x) {
        unsigned sy = y < 16u ? y : y >= 272u ? y - 64u : 16u + (y & 15u);
        unsigned sx = x < 16u ? x : x >= 496u ? x - 256u : 8u + (x & 7u);
        pixels[y * 512u + x] = background[sy * 256u + sx];
    }
    for (y = 0u; y < 224u; ++y) for (x = 0u; x < 256u; ++x) {
        unsigned at = y * 256u + x, mask = ui->masks[b][at], dx, dy;
        if (!(mask & 4u) && (mask & 3u) != 2u && !icons[(y / 8u) * 32u + x / 8u]) continue;
        /* Header is centred at the original top. Navigation/skills remain a
         * coherent left group; stat columns occupy the new right. The two
         * bottom hands move as one group, never independently of selection. */
        dx = y < 96u ? x + 128u : x + (x < 128u ? 0u : 256u);
        dy = y < 96u ? y : y + ((x < 128u && y >= 144u) ||
                               (x >= 184u && y >= 183u) ? 64u : 32u);
        pixels[dy * 512u + dx] = ui->pixels[b][at];
    }
    return 1;
}

static uint16_t ship_info_entry(unsigned x, unsigned y) {
    /* C5:0951..0FAB -> C1:3CF9/3D4F/3D22 pictures and staged icon
     * packets. Values are tile destinations, not captured picture contents.
     * C1:3CF9 uses the source eight-by-six ship picture, without stretching. */
    static const struct { uint8_t x, y, width, height; uint16_t tile; } groups[] = {
        {4,3,8,6,0x26C0}, {15,2,4,4,0x3EF0}, {22,2,4,4,0x3F00},
        {17,7,3,3,0x3AA5}, {24,8,3,2,0x3A81}, {24,11,3,2,0x3A87},
        {17,12,3,3,0x3AAE}, {24,14,3,2,0x3A8D}, {24,17,3,2,0x3A93},
        {17,17,3,3,0x3B22}, {4,18,3,2,0x3B10}, {8,18,3,2,0x3B16},
        {12,18,3,2,0x3B1C}, {24,20,3,2,0x3A99}, {5,22,3,3,0x3AB7},
        {11,22,3,2,0x3A9F}, {17,22,3,3,0x3B2B}, {24,23,3,2,0x3B34}
    };
    unsigned n;
    for (n = 0u; n < sizeof(groups) / sizeof(groups[0]); ++n)
        if (x >= groups[n].x && x < groups[n].x + groups[n].width &&
            y >= groups[n].y && y < groups[n].y + groups[n].height)
            return (uint16_t)(groups[n].tile + (y - groups[n].y) * groups[n].width + x - groups[n].x);
    return 0u;
}

int nh_ppu14_read_ship_info(const NHPPU11 *p, uint16_t *pixels, uint32_t capacity) {
    const NHPortUiCapture14 *ui;
    uint16_t background[256u * 224u];
    uint8_t content[32u * 28u] = {0};
    unsigned x, y, b;
    uint8_t value, math, control;
    int fixed_math;
    if (!p || !pixels || capacity < 512u * 288u || !(ui = p->port_ui) ||
        ui->sequence != p->published_sequence || !ui->valid[ui->published] ||
        !read_reg8(p, NULL, 0x31u, &math) || !read_reg8(p, NULL, 0x30u, &control)) return 0;
    fixed_math = math == 0x81u && control == 0x10u;
    if ((math && !fixed_math) || (fixed_math && p->fixed_color.known_mask != 0x7FFFu) ||
        ui->frame_mode[ui->published] != 9u || (ui->dependent_math[ui->published] && !fixed_math) ||
        p->forced_blank || !p->brightness ||
        !read_reg8(p, NULL, 5u, &value) || value != 9u ||
        !read_reg8(p, NULL, 1u, &value) || value ||
        !read_reg8(p, NULL, 6u, &value) || value ||
        !read_reg8(p, NULL, 0x2Cu, &value) || value != 0x15u ||
        !read_reg8(p, NULL, 0x2Du, &value) || value != 0x15u ||
        p->bg_hofs[0].known_mask != 0x3FFu || p->bg_hofs[0].value ||
        p->bg_vofs[0].known_mask != 0x3FFu || p->bg_vofs[0].value) return 0;
    for (y = 0u; y < 28u; ++y) for (x = 0u; x < 32u; ++x) {
        uint16_t entry, expected = ship_info_entry(x, y);
        if (!map_entry(p, NULL, 0u, x * 8u, y * 8u, 8u, &entry)) return 0;
        /* Same source full-page parchment as character information. Admit
         * construction fill before each independently uploaded picture/icon. */
        if (entry == character_card_border(x, y)) continue;
        if (!expected || entry != expected) return 0;
        content[y * 32u + x] = 1u;
    }
    b = ui->published;
    for (y = 0u; y < 224u; ++y) {
        NHMode1Row14 cache = {0};
        for (x = 0u; x < 256u; ++x) {
            NHPixel14 sample;
            unsigned at = y * 256u + x, mask = ui->masks[b][at];
            uint16_t expected;
            /* No selected OBJ belongs to this BG1-picture page. Old masked
             * Sea slots remain hidden, not reclassified as ships or icons. */
            if ((mask & (fixed_math ? 0xACu : 0xBCu)) ||
                !mode1_bg_read(p, NULL, &cache, 0u, x, y, &sample)) return 0;
            background[at] = sample.transparent ? 0u : apply_brightness(sample.color, p->brightness);
            if ((mask & 3u) == 1u) {
                expected = background[at];
                if (mask & 16u) expected = apply_brightness(
                    color_math(sample.color, p->fixed_color.value, 1, 0), p->brightness);
                if (sample.transparent || expected != ui->pixels[b][at]) return 0;
            } else if ((mask & 3u) == 2u) {
                if (!mode1_bg_read(p, NULL, &cache, 2u, x, y, &sample) || sample.transparent ||
                    apply_brightness(sample.color, p->brightness) != ui->pixels[b][at]) return 0;
            } else if (mask || ui->pixels[b][at] || background[at]) return 0;
        }
    }
    for (y = 0u; y < 288u; ++y) for (x = 0u; x < 512u; ++x) {
        unsigned sy = y < 16u ? y : y >= 272u ? y - 64u : 16u + (y & 15u);
        unsigned sx = x < 16u ? x : x >= 496u ? x - 256u : 8u + (x & 7u);
        pixels[y * 512u + x] = background[sy * 256u + sx];
    }
    for (y = 0u; y < 224u; ++y) for (x = 0u; x < 256u; ++x) {
        unsigned at = y * 256u + x, mask = ui->masks[b][at], dx, dy;
        unsigned left_caption = x < 120u || (y >= 80u && y < 144u && x < 136u);
        if ((mask & 3u) != 2u && !(mask & 16u) && !content[(y / 8u) * 32u + x / 8u]) continue;
        /* C5:0B52..67's caption packet starts at cell3,row10 and has
         *14columns. Preserve its FULL x24..136 extent, not just the short
         * Rebellion/Catalina strings seen in the first runtime witness.
         * Figurehead at x120,y16 and resource column x136 stay right-owned. */
        dx = x + (left_caption ? 0u : 256u);
        dy = y + (left_caption ? (y >= 144u ? 64u : 0u) : y >= 136u ? 64u : y >= 56u ? 32u : 0u);
        pixels[dy * 512u + dx] = ui->pixels[b][at];
    }
    return 1;
}

static uint16_t scrap_detail_entry(unsigned x, unsigned y) {
    /* C8:080B..0820 -> C1:3CD0 uses fixed destination314, not a
     * model-specific screenshot. Picture content remains live source VRAM.
     * C8:0829..0872 icons; 088F..08A4 figurehead; 08E9 -> C6:06DC
     * caption/armament, and source money fields at row16. */
    static const struct { uint8_t x,y,w,h; uint16_t tile; } groups[] = {
        {3,2,8,6,0x2714}, {12,3,3,2,0x3A81}, {12,6,3,2,0x3A87},
        {19,3,3,2,0x3A8D}, {19,6,3,2,0x3A99}, {15,9,4,4,0x2B54},
        {23,9,4,4,0x2B44}, {3,12,3,3,0x3AB7},
        {4,16,2,2,0x3E70}, {11,16,2,2,0x3E74}
    };
    unsigned n;
    for (n=0u; n<sizeof(groups)/sizeof(groups[0]); ++n)
        if (x>=groups[n].x && x<groups[n].x+groups[n].w &&
            y>=groups[n].y && y<groups[n].y+groups[n].h)
            return (uint16_t)(groups[n].tile+(y-groups[n].y)*groups[n].w+x-groups[n].x);
    return 0u;
}

static int read_management_page(const NHPPU11 *p, uint16_t *pixels, uint32_t capacity, unsigned layout) {
    const NHPortUiCapture14 *ui;
    uint16_t background[256u * 224u];
    uint8_t content[32u * 28u] = {0};
    unsigned x, y, b;
    uint8_t value, math, control, screen;
    int scrap = layout == 1u, detail = layout >= 2u;
    unsigned hand_x = layout == 3u ? 184u : 176u;
    unsigned numeric = 0u, numeric_left = 0u, numeric_top = 0u;
    unsigned name_underline = 0u;
    if (!p || !pixels || capacity < 512u * 288u || !(ui = p->port_ui) ||
        ui->sequence != p->published_sequence || !ui->valid[ui->published] ||
        ui->frame_mode[ui->published] != 0x29u || ui->dependent_math[ui->published] ||
        p->forced_blank || !p->brightness ||
        !read_reg8(p, NULL, 5u, &value) || value != 0x29u ||
        !read_reg8(p, NULL, 1u, &value) || value ||
        !read_reg8(p, NULL, 6u, &value) || value != 2u ||
        !read_reg8(p, NULL, 0x2Cu, &screen) ||
            /* Moor's C17C88 paper field also precedes the TM17->15
             * switch. Reuse the already-qualified full-detail paper path;
             * selected BG2/unknown owners still fail the pixel rejoin below. */
            (screen != 0x15u && !(detail && screen == 0x17u)) ||
        !read_reg8(p, NULL, 0x2Du, &value) || value != screen ||
        !read_reg8(p, NULL, 0x31u, &math) ||
            (math != 0u && math != 1u && !(layout == 4u && math == 3u)) ||
        !read_reg8(p, NULL, 0x30u, &control) || (control != 0x10u && control != 0x30u) ||
        p->fixed_color.known_mask != 0x7FFFu ||
        p->bg_hofs[0].known_mask != 0x3FFu || p->bg_hofs[0].value ||
        p->bg_vofs[0].known_mask != 0x3FFu || p->bg_vofs[0].value) return 0;
    if (layout == 4u) {
        unsigned cell, count = 0u;
        /* C9:429A starts at cell12. Nonempty Next, C9:4363..4389,
         * supplies14+strlen(first part), so the second five-cell field
         * starts15..19. Read only known live map cells; do not manufacture
         * an underline, accept stale joined fields, or infer name bytes. */
        for (cell = 12u; cell < 24u; ++cell) {
            uint16_t entry;
            if (!map_entry(p, NULL, 0u, cell * 8u, 56u, 8u, &entry)) return 0;
            if (entry == 0x3B44u) {
                if (!count) name_underline = cell;
                else if (cell != name_underline + count) return 0;
                ++count;
            }
        }
        if (count && (count != 5u ||
            (name_underline != 12u && (name_underline < 15u || name_underline > 19u)))) return 0;
    }
    /* C5:ACEE -> C1:7C88 full-page paper. C5:ACFD..AD16 sends
     * C1:9373's two 3x2 icons to cells14,2 and17,2. Nothing else on
     * BG1 is table data: names/numbers/captains are actual BG3 glyphs. */
    for (y = 0u; y < 28u; ++y) for (x = 0u; x < 32u; ++x) {
        uint16_t entry, border = character_card_border(x, y), icon = 0u;
        if (y == 27u && x >= 30u) border = (uint16_t)(0x3A39u + x);
        if (y >= 2u && y < 4u && x >= 14u && x < 20u)
            icon = (uint16_t)((x < 17u ? 0x3A99u : 0x3A9Fu) + (y - 2u) * 3u + (x - 14u) % 3u);
        if (scrap) {
            static const unsigned columns[] = {10u,14u,18u,24u};
            static const uint16_t bases[] = {0x3A99u,0x3A9Fu,0x3A93u,0x3A8Du};
            unsigned n;
            icon = 0u;
            /* C5:8071..80AA sends C1:9373 icons4/5/3/2 to these
             * four destinations. Shared paper is not a shared header ID. */
            if (y >= 3u && y < 5u) for (n = 0u; n < 4u; ++n)
                if (x >= columns[n] && x < columns[n] + 3u)
                    icon = (uint16_t)(bases[n] + (y - 3u) * 3u + x - columns[n]);
        }
        if (detail) icon = scrap_detail_entry(x, y);
        /* C9:429A's keyboard keeps only C1:3CD0's finite ship picture.
         * Old transaction icons are not keyboard content. */
        if (layout == 4u && !(x >= 3u && x < 11u && y >= 2u && y < 8u)) icon = 0u;
        /* C9:3FBC..3FD3 fills the source-supplied five-cell name field. */
        if (layout == 4u && name_underline && y == 7u &&
            x >= name_underline && x < name_underline + 5u) icon = 0x3B44u;
        if (!map_entry(p, NULL, 0u, x * 8u, y * 8u, 8u, &entry)) return 0;
        if (entry == border) continue;
        if (!icon || entry != icon) return 0;
        content[y * 32u + x] = 1u;
    }
    /* C1:144C -> 0BC7 -> C7:19E3 owns the numeric cursor. It emits
     * eight small OBJ in a3x3 ring, explicitly skipping central tile3214.
     * Derive its source-supplied live anchor, not a hardcoded digit count.
     * This transaction path keeps the complete ring in the bottom text
     * region; unsupported geometry still refuses rather than moving it. */
    if (layout == 3u) {
        NHObject14 first;
        if (decode_object_read(p, NULL, 0u, &first)) {
            unsigned n;
            numeric_left = first.x; numeric_top = (uint8_t)(first.y - 1u);
            if (numeric_left <= 232u && numeric_top >= 144u && numeric_top <= 184u) {
                numeric = 1u;
                for (n = 0u; n < 8u; ++n) {
                    NHObject14 object;
                    unsigned tile = n + (n >= 4u);
                    if (!decode_object_read(p, NULL, n, &object) ||
                        object.x != numeric_left + (tile % 3u) * 8u ||
                        (uint8_t)(object.y - 1u) != numeric_top + (tile / 3u) * 8u ||
                        object.width != 8u || object.height != 8u ||
                        (object.tile | ((unsigned)p->oam[n * 4u + 3u].value << 8u)) != 0x3210u + tile) {
                        numeric = 0u; break;
                    }
                }
            }
        }
    }
    b = ui->published;
    for (y = 0u; y < 224u; ++y) {
        NHMode1Row14 cache = {0};
        for (x = 0u; x < 256u; ++x) {
            NHPixel14 sample;
            unsigned at = y * 256u + x, mask = ui->masks[b][at];
            uint16_t expected;
            if (!mode1_bg_read(p, NULL, &cache, 0u, x, y, &sample)) return 0;
            background[at] = sample.transparent ? 0u : apply_brightness(sample.color, p->brightness);
            /* The source paper's ragged bottom edge has transparent pixels.
             * Native Port actors can show through them. Rejoin those actual
             * background samples but do NOT promote/move them as menu OBJ. */
            if ((mask & 7u) == 4u && sample.transparent) {
                unsigned index, matched = 0u;
                if ((mask & 0x30u) || y < 208u) return 0;
                for (index = 112u; index <= 121u; ++index) {
                    NHObject14 object;
                    NHPortObjectPixel14 pixel;
                    unsigned oy;
                    if (!decode_object_read(p, NULL, index, &object)) return 0;
                    oy = (uint8_t)(object.y - 1u);
                    if (x < object.x || x >= object.x + object.width || y < oy || y >= oy + object.height) continue;
                    if (nh_ppu14_read_port_object(p, index, x - object.x, y - oy, &pixel) && pixel.opaque &&
                        apply_brightness(pixel.color, p->brightness) == ui->pixels[b][at]) { matched = 1u; break; }
                }
                if (!matched) return 0;
                continue;
            }
            if (mask & 0xE8u) return 0;
            if (mask & 4u) {
                /* C5:BBDB..BBE7 -> C7:255F's two 3x3 hand cursors.
                 * Require actual consumed OBJ pixels, not stale town actors. */
                NHObject14 object;
                NHPortObjectPixel14 pixel;
                unsigned index, ox, oy, hand_y = detail ? 119u : 191u;
                if (scrap) return 0; /* No selected UI OBJ belongs to its table. */
                if (layout == 3u && x >= 152u && x < 184u && y >= 71u && y < 103u) {
                    unsigned local = ((y - 71u) / 8u) * 4u + (x - 152u) / 8u;
                    /* C8:2B59..2B6E -> C1:3D4F (Figurehead), or
                     * C8:2C6F..2C84 -> C1:3D22 (Guns), supplies slot20,
                     * tile3022, pixel(152,71): the selected equipment
                     * preview is live16-OBJ art, not BG1 or a hand cursor.
                     * Admit only consumed known pixels of that exact grid. */
                    index = 20u + local;
                    ox = 152u + (local % 4u) * 8u;
                    oy = 71u + (local / 4u) * 8u;
                    if (!decode_object_read(p, NULL, index, &object) || object.x != ox ||
                        (uint8_t)(object.y - 1u) != oy || object.width != 8u || object.height != 8u ||
                        (object.tile | ((unsigned)p->oam[index * 4u + 3u].value << 8u)) != 0x3022u + local ||
                        !nh_ppu14_read_port_object(p, index, x - ox, y - oy, &pixel) || !pixel.opaque ||
                        apply_brightness(pixel.color, p->brightness) != ui->pixels[b][at]) return 0;
                    continue;
                }
                if (numeric && x >= numeric_left && x < numeric_left + 24u &&
                    y >= numeric_top && y < numeric_top + 24u) {
                    unsigned tile = ((y - numeric_top) / 8u) * 3u + (x - numeric_left) / 8u;
                    if (tile == 4u) return 0; /* No source cursor OBJ in its central hole. */
                    index = tile - (tile > 4u);
                    ox = numeric_left + (tile % 3u) * 8u;
                    oy = numeric_top + (tile / 3u) * 8u;
                    if (!nh_ppu14_read_port_object(p, index, x - ox, y - oy, &pixel) ||
                        !pixel.opaque || apply_brightness(pixel.color, p->brightness) != ui->pixels[b][at]) return 0;
                    continue;
                }
                if (detail && y >= 144u && y < 208u && byte_known(p->oam[2]) &&
                    (p->oam[2].value == 0u || p->oam[2].value == 4u) &&
                    nh_ppu14_combat_ui_object(p,0u) && decode_object_read(p,NULL,0u,&object)) {
                    unsigned left=object.x, top=(uint8_t)(object.y-1u);
                    /* C2:7096 -> 6FA4/6E59 reuses the existing TWO-frame
                     * four-OBJ prompt,3200..3207, for refusal/acknowledgement.
                     * Its whole native group has already been joined above;
                     * sample the consumed pixel and move with the dialogue. */
                    if (x>=left && x<left+16u && y>=top && y<top+16u) {
                        index=((y-top)/8u)*2u+(x-left)/8u;
                        ox=left+(index%2u)*8u; oy=top+(index/2u)*8u;
                        if (!nh_ppu14_read_port_object(p,index,x-ox,y-oy,&pixel) || !pixel.opaque ||
                            apply_brightness(pixel.color,p->brightness)!=ui->pixels[b][at]) return 0;
                        continue;
                    }
                }
                if (detail && x >= 24u && x < 64u && y >= 151u && y < 199u) {
                    unsigned slot, matched = 0u;
                    /* C5:7FF3 -> C1:6B11/6904 dialogue portrait. Source
                     * C1:34F9 alternates its20/50 buffers; qualify the actual
                     * consumed pixel, never activate a hidden portrait. */
                    for (slot=0u; slot<2u; ++slot) {
                        unsigned local=((y-151u)/8u)*5u+(x-24u)/8u;
                        index=(slot ? 50u : 20u)+local;
                        ox=24u+(local%5u)*8u; oy=151u+(local/5u)*8u;
                        if (decode_object_read(p,NULL,index,&object) && object.x==ox &&
                            (uint8_t)(object.y-1u)==oy && object.width==8u && object.height==8u &&
                            (object.tile|((unsigned)p->oam[index*4u+3u].value<<8u))==(slot ? 0x37E0u : 0x35C0u)+local &&
                            nh_ppu14_read_port_object(p,index,x-ox,y-oy,&pixel) && pixel.opaque &&
                            apply_brightness(pixel.color,p->brightness)==ui->pixels[b][at]) { matched=1u; break; }
                    }
                    if (!matched) return 0;
                    continue;
                }
                /* C5:804B supplies cell22 for Scrap, whereas the shared
                 * C8:0009 transaction wrapper supplies cell23. Keep both
                 * source-qualified geometries; do not assume all YesNo
                 * callers put the same18-OBJ group at the same X. */
                if (x < hand_x || x >= hand_x + 48u || y < hand_y || y >= hand_y + 24u) return 0;
                index = ((x - hand_x) / 24u) * 9u + ((y - hand_y) / 8u) * 3u + ((x - hand_x) % 24u) / 8u;
                ox = hand_x + (index / 9u) * 24u + (index % 3u) * 8u;
                oy = hand_y + ((index % 9u) / 3u) * 8u;
                if (!decode_object_read(p, NULL, index, &object) || object.x != ox ||
                    (uint8_t)(object.y - 1u) != oy || object.width != 8u || object.height != 8u ||
                    (object.tile | ((unsigned)p->oam[index * 4u + 3u].value << 8u)) != 0x3210u + index ||
                    !nh_ppu14_read_port_object(p, index, x - ox, y - oy, &pixel) || !pixel.opaque ||
                    apply_brightness(pixel.color, p->brightness) != ui->pixels[b][at]) return 0;
            } else if ((mask & 3u) == 1u) {
                expected = background[at];
                if (mask & 16u) expected = apply_brightness(
                    color_math(sample.color, p->fixed_color.value, 0, 0), p->brightness);
                if (sample.transparent || expected != ui->pixels[b][at]) return 0;
            } else if ((mask & 3u) == 2u) {
                if ((mask & 16u) || !mode1_bg_read(p, NULL, &cache, 2u, x, y, &sample) ||
                    sample.transparent || apply_brightness(sample.color, p->brightness) != ui->pixels[b][at]) return 0;
            } else if (mask || ui->pixels[b][at] || background[at]) return 0;
        }
    }
    /* Repeat only source parchment, retaining finite corners/edge pixels. */
    for (y = 0u; y < 288u; ++y) for (x = 0u; x < 512u; ++x) {
        unsigned sy = y < 16u ? y : y >= 272u ? y - 64u : 16u + (y & 15u);
        unsigned sx = x < 16u ? x : x >= 496u ? x - 256u : 8u + (x & 7u);
        pixels[y * 512u + x] = background[sy * 256u + sx];
    }
    for (y = 0u; y < 224u; ++y) for (x = 0u; x < 256u; ++x) {
        unsigned at = y * 256u + x, mask = ui->masks[b][at], dx, dy;
        if ((mask & 7u) == 4u) continue; /* Qualified background, not menu OBJ. */
        if (!(mask & 4u) && (mask & 3u) != 2u && !(mask & 16u) &&
            !content[(y / 8u) * 32u + x / 8u]) continue;
        /* Keep ten possible table rows/column headings/row highlight one
         * finite group at the original top. The separately produced question
         * is bottom-left; Yes/No's whole 48x24 group is bottom-right. */
        /* Last table glyph row ends at191; hands begin at191 but are
         * separate OBJ. Never cut a ten-ship text row on the hand boundary.
         * Scrap's selector has NO bottom prompt: all its rows stay together. */
        dx = scrap || (!(mask & 4u) && y < 192u) ? x + 128u : x + ((mask & 4u) ? 256u : 0u);
        dy = scrap || (!(mask & 4u) && y < 192u) ? y : y + 64u;
        if (detail) {
            if (layout == 3u && (mask & 4u) && x>=152u && x<184u && y>=71u && y<103u)
                { dx=x+256u; dy=y+32u; }
            else if ((mask & 4u) && y < 144u) { dx=x+256u; dy=y+64u; }
            else if (y >= 128u) { dx=x; dy=y+64u; }
            else {
                /* C8:0923..0938 owns the FULL12-cell caption at3,9.
                 * Preserve long names through x120, not merely B's glyph. */
                unsigned left=x<96u || (y>=72u && y<88u && x<120u);
                dx=x+(left ? 0u : 256u);
                dy=y+((left ? y>=96u : y>=64u) ? 32u : 0u);
            }
        }
        if (layout == 4u) {
            /* C9:3911's entire13x7 key grid includes Next/Done. C9:3345
             * places its window highlight at y78 for the first row, so
             * split ABOVE72, not on the glyph baseline80. Keep highlight,
             * all rows and controls one finite group, centred and down64.
             * Ship picture stays top-left; title/name/arrow stay top-right. */
            dx = y >= 72u ? x + 128u : x + (x >= 96u ? 256u : 0u);
            dy = y >= 72u ? y + 64u : y;
        }
        pixels[dy * 512u + dx] = ui->pixels[b][at];
    }
    return 1;
}

int nh_ppu14_read_rearrange(const NHPPU11 *p, uint16_t *pixels, uint32_t capacity) {
    return read_management_page(p, pixels, capacity, 0u);
}

int nh_ppu14_read_scrap_selector(const NHPPU11 *p, uint16_t *pixels, uint32_t capacity) {
    return read_management_page(p, pixels, capacity, 1u);
}

int nh_ppu14_read_scrap_detail(const NHPPU11 *p, uint16_t *pixels, uint32_t capacity) {
    return read_management_page(p, pixels, capacity, 2u);
}

int nh_ppu14_read_ship_transaction(const NHPPU11 *p, uint16_t *pixels, uint32_t capacity) {
    return read_management_page(p, pixels, capacity, 3u);
}

int nh_ppu14_read_ship_name(const NHPPU11 *p, uint16_t *pixels, uint32_t capacity) {
    return read_management_page(p, pixels, capacity, 4u);
}

/* C5:3E61..4930 draws a finite90x45 four-pixel world chart. The source
 * composition is BG3 main, BG1/2 subscreen, math on backdrop only. Rejoin
 * actual published pixels before projecting the resident chart, never call
 * the mutating native renderer or manufacture unknown geographic cells. */
static int chart_background(const NHPPU11 *p, NHMode1Row14 *cache,
                            unsigned x, unsigned y, uint16_t *color) {
    NHPixel14 main, a, b;
    uint16_t backdrop, sub;
    if (!mode1_bg_read(p, NULL, cache, 2u, x, y, &main)) return 0;
    if (!main.transparent) { *color = apply_brightness(main.color, p->brightness); return 1; }
    if (!read_color(p, NULL, 0u, &backdrop) ||
        !mode1_bg_read(p, NULL, cache, 0u, x, y, &a) ||
        !mode1_bg_read(p, NULL, cache, 1u, x, y, &b)) return 0;
    if (!a.transparent && (b.transparent || a.rank > b.rank)) sub = a.color;
    else if (!b.transparent) sub = b.color;
    else {
        if (p->fixed_color.known_mask != 0x7FFFu) return 0;
        sub = p->fixed_color.value;
    }
    *color = apply_brightness(color_math(backdrop, sub, 0, 0), p->brightness);
    return 1;
}

static int build_world_chart(const NHPPU11 *p, unsigned port_selection,
                             uint16_t *pixels, uint32_t capacity,
                             const uint16_t *native, const uint8_t *known,
                             unsigned native_height) {
    static const unsigned indices[] = {1u,5u,6u,7u,8u,9u,11u,12u,
        0x23u,0x24u,0x25u,0x26u,0x27u,0x28u,0x29u,0x2Au,0x2Bu,
        0x2Cu,0x2Du,0x2Eu,0x2Fu,0x30u,0x31u};
    /* Actual chart window1 covers0..255, window2 is empty255..0. Its
     * inverted masks are false throughout the native viewport; the extended
     * chart projection expands this viewport clip, not geographic data.
     * Require the exact source configuration, never ignore arbitrary windows. */
    static const uint8_t values[] = {0u,1u,0u,0x59u,0x51u,0x79u,0x22u,6u,
        0x33u,1u,3u,0u,255u,255u,0u,0u,0u,
        0x14u,3u,0x17u,0x17u,2u,0x20u};
    uint16_t atlas[392u * 212u], backing;
    NHObject14 markers[2];
    unsigned i, x, y, pan, teardown=0u, marker_count=port_selection ? 2u : 1u;
    if (!p || !pixels || port_selection>1u || capacity < 512u * 288u ||
        native_height != 224u || p->forced_blank || !p->brightness) return 0;
    /* C5:4930 restores the previous page's maps via command4B before
     * command47 switches BGMODE. The last dim field still owns chart OBJ,
     * but no longer owns chart geography. Admit only that exact restored
     * map tuple, brightness1 and a fully rejoined black BG plane. */
    teardown=p->registers[7].known_mask==255u && p->registers[7].value==0x5Cu &&
        p->registers[8].known_mask==255u && p->registers[8].value==0x58u &&
        p->registers[9].known_mask==255u && p->registers[9].value==0x7Cu &&
        p->brightness==1u;
    for (i=0u; i<sizeof(indices)/sizeof(indices[0]); ++i) {
        uint8_t value;
        unsigned expected=values[i];
        if (teardown && indices[i]>=7u && indices[i]<=9u)
            expected=indices[i]==7u ? 0x5Cu : indices[i]==8u ? 0x58u : 0x7Cu;
        if (!read_reg8(p,NULL,indices[i],&value) || value != expected) return 0;
    }
    for (i=0u; i<3u; ++i) {
        if (p->bg_hofs[i].known_mask != 0x3FFu || p->bg_vofs[i].known_mask != 0x3FFu ||
            p->bg_vofs[i].value != (i==1u ? 8u : 0u) ||
            p->bg_hofs[i].value != ((p->bg_hofs[0].value+(i==1u ? 8u : 0u))&1023u)) return 0;
    }
    /* C5:4593 supplies3900 for current ship; C5:4737 supplies3B02
     * for selected port. Actual slots16/17 each have two blinking forms.
     * Equal-priority native OAM ordering gives16 precedence in overlap. */
    for (i=0u; i<marker_count; ++i)
        if (!decode_object_read(p,NULL,16u+i,&markers[i]) || markers[i].width!=8u || markers[i].height!=8u ||
            ((markers[i].tile|((unsigned)p->oam[(16u+i)*4u+3u].value<<8u))&0xFFFEu) != (i ? 0x3B02u : 0x3900u)) return 0;
    for (y=0u; y<224u; ++y) {
        NHMode1Row14 cache={0};
        for (x=0u; x<256u; ++x) {
            unsigned at=y*256u+x;
            uint16_t color;
            if (!(known[at>>3u]&(1u<<(at&7u))) ||
                !chart_background(p,&cache,x,y,&color)) return 0;
            if (teardown && color) return 0;
            for (i=0u; i<marker_count; ++i) {
                unsigned ox=(x-markers[i].x)&511u, oy=(y-(uint8_t)(markers[i].y-1u))&255u;
                if (ox<8u && oy<8u) {
                    NHPortObjectPixel14 sample;
                    if (!nh_ppu14_read_port_object(p,16u+i,ox,oy,&sample)) return 0;
                    if (sample.opaque) { color=apply_brightness(sample.color,p->brightness); break; }
                }
            }
            if (color != native[at]) return 0;
        }
    }
    /* Whole finite chart now fits. Cancel the guest's old256-wide viewport
     * pan in PRESENTATION ONLY; all chart cells/marker keep their source
     * relationship. OFF still displays that exact guest pan. This is a fit-
     * whole-chart layout, not new movement or a widened geographic world. */
    pan=(p->bg_hofs[0].value+16u)&511u;
    if (teardown) {
        memset(pixels,0,512u*288u*sizeof(*pixels));
    } else {
    for (y=0u; y<212u; ++y) {
        NHMode1Row14 cache={0};
        for (x=0u; x<392u; ++x)
            if (!chart_background(p,&cache,(x-pan)&511u,y,&atlas[y*392u+x])) return 0;
    }
    /* C5's uncharted mask uses palette29, also the neutral UI backing.
     * Do not repeat map cells into the added margins. */
    if (!read_color(p,NULL,29u,&backing)) return 0;
    backing=apply_brightness(backing,p->brightness);
    for (y=0u; y<288u; ++y) for (x=0u; x<512u; ++x) {
        unsigned sx=x<24u ? x : x>=488u ? x-120u : 24u+(x&7u);
        unsigned sy=y<24u ? y : y>=264u ? y-76u : 24u+(y&7u);
        /* Ornaments extend sixteen pixels from each8px outer margin.
         * Sample the actual combined main/subscreen frame, not BG3 alone.
         * Never repeat source coordinates inside the geographic rectangle:
         * those belong to the one finite map copy below, not UI backing. */
        pixels[y*512u+x]=(sx>=16u&&sx<376u&&sy>=16u&&sy<196u) ? backing : atlas[sy*392u+sx];
    }
    for (y=16u; y<196u; ++y) for (x=16u; x<376u; ++x)
        pixels[(y+38u)*512u+x+60u]=atlas[y*392u+x];
    }
    for (i=marker_count; i>0u; --i) {
        unsigned n=i-1u, marker_y=(uint8_t)(markers[n].y-1u);
        if (marker_y<224u) {
            unsigned mx=(markers[n].x+pan)&511u;
            if (mx<16u || mx>=376u || marker_y<16u || marker_y>=196u) return 0;
            for (y=0u; y<8u; ++y) for (x=0u; x<8u; ++x) {
                NHPortObjectPixel14 sample;
                if (!nh_ppu14_read_port_object(p,16u+n,x,y,&sample)) return 0;
                if (sample.opaque) pixels[(marker_y+y+38u)*512u+mx+x+60u]=apply_brightness(sample.color,p->brightness);
            }
        }
    }
    return 1;
}

int nh_ppu14_read_world_chart(const NHPPU11 *p, unsigned port_selection,
                            uint16_t *pixels, uint32_t capacity) {
    const NHPortUiCapture14 *ui=p ? p->port_ui : NULL;
    if (!p || !pixels || capacity<512u*288u) return 0;
    if (ui && ui->chart_valid && ui->chart_kind==port_selection &&
        ui->chart_sequence==p->published_sequence) {
        memcpy(pixels,ui->chart_pixels[ui->published],sizeof(ui->chart_pixels[0]));
        return 1;
    }
    /* A restored checkpoint can be queried before its next publication;
     * live rejoin remains available, never use another sequence's cache. */
    return p->frame_ready && build_world_chart(p,port_selection,pixels,capacity,
        p->published_frame,p->published_known,p->published_height);
}

static uint16_t own_fleet_header_icon(unsigned x, unsigned y) {
    if (x >= 8u && x < 12u && y >= 4u && y < 8u)
        return (uint16_t)(0x3B54u + (y - 4u) * 4u + x - 8u);
    if (x >= 17u && x < 20u && y >= 2u && y < 8u)
        return (uint16_t)(0x3A81u + (y - 2u) * 3u + x - 17u);
    if (x >= 23u && x < 26u && y >= 2u && y < 4u)
        return (uint16_t)(0x3A99u + (y - 2u) * 3u + x - 23u);
    if (x >= 23u && x < 26u && y >= 4u && y < 8u)
        return (uint16_t)(0x3B64u + (y - 4u) * 3u + x - 23u);
    return 0u;
}

/* C7:3C25 -> 390D/3973 -> 1A87/1A9B -> C1:7EA5 constructs the
 * six-by-four hollow nine-slice frame in16objects. Its source grid has
 * five columns/two rows; accept intermediate cursor motion within that grid. */
static int own_fleet_selector_pixel(const NHPPU11 *p, unsigned x, unsigned y,
                                     uint16_t actual) {
    static const uint8_t cx[16] = {0,1,2,3,4,5,0,5,0,5,0,1,2,3,4,5};
    static const uint8_t cy[16] = {0,0,0,0,0,0,1,1,2,2,3,3,3,3,3,3};
    static const uint8_t tile[16] = {0,1,1,1,1,2,3,5,3,5,6,7,7,7,7,8};
    NHObject14 first;
    unsigned n, oy, matched = 0u;
    if (!decode_object_read(p, NULL, 0u, &first)) return 0;
    oy = (uint8_t)(first.y - 1u);
    if (first.x < 24u || first.x > 184u || oy < 6u || oy > 30u) return 0;
    for (n = 0u; n < 16u; ++n) {
        NHObject14 object;
        NHPortObjectPixel14 pixel;
        unsigned sx = first.x + cx[n] * 8u, sy = oy + cy[n] * 8u;
        if (!decode_object_read(p, NULL, n, &object) || object.x != sx ||
            (uint8_t)(object.y - 1u) != sy || object.width != 8u || object.height != 8u ||
            (object.tile | ((unsigned)p->oam[n * 4u + 3u].value << 8u)) != 0x3210u + tile[n]) return 0;
        if (x >= sx && x < sx + 8u && y >= sy && y < sy + 8u &&
            nh_ppu14_read_port_object(p, n, x - sx, y - sy, &pixel) && pixel.opaque &&
            apply_brightness(pixel.color, p->brightness) == actual) matched = 1u;
    }
    return (int)matched;
}

int nh_ppu14_read_own_fleet(const NHPPU11 *p, uint16_t *pixels, uint32_t capacity) {
    const NHPortUiCapture14 *ui;
    uint16_t background[256u * 224u];
    uint8_t content[32u * 28u] = {0};
    unsigned x, y, b;
    uint8_t value, math, control;
    int selector;
    if (!p || !pixels || capacity < 512u * 288u || !(ui = p->port_ui) ||
        ui->sequence != p->published_sequence || !ui->valid[ui->published]) return 0;
    b = ui->published;
    /* The source wrapper also owns its genuinely black loading/fade fields.
     * Prove every published pixel black, not a final-register blank guess.
     * This preserves wide geometry during loading, without admitting visible
     * unsupported scenes or advancing the source's own fade timing. */
    for (x = 0u; x < 256u * 224u && !ui->pixels[b][x]; ++x) { }
    if (x == 256u * 224u) { memset(pixels, 0, 512u * 288u * sizeof(*pixels)); return 1; }
    if (!read_reg8(p, NULL, 0x31u, &math) || !read_reg8(p, NULL, 0x30u, &control)) return 0;
    /* Selector backing is actual fixed-colour subtraction, windowed by HDMA.
     * Capture masks retain each pixel's actual math enable. Rejoin that
     * expression to native pixels, then move the FINITE widget coherently;
     * never extrapolate its last scanline window into new screen margins. */
    selector = math == 0x81u && control == 0x10u;
    if ((math && !selector) || (selector && p->fixed_color.known_mask != 0x7FFFu) ||
        ui->frame_mode[b] != 9u || (ui->dependent_math[b] && !selector) || p->forced_blank || !p->brightness ||
        !read_reg8(p, NULL, 5u, &value) || value != 9u ||
        !read_reg8(p, NULL, 1u, &value) || value ||
        !read_reg8(p, NULL, 6u, &value) || value ||
        !read_reg8(p, NULL, 0x2Cu, &value) || value != 0x15u ||
        !read_reg8(p, NULL, 0x2Du, &value) || value != 0x15u ||
        p->bg_hofs[0].known_mask != 0x3FFu || p->bg_hofs[0].value ||
        p->bg_vofs[0].known_mask != 0x3FFu || p->bg_vofs[0].value) return 0;
    for (y = 0u; y < 28u; ++y) for (x = 0u; x < 32u; ++x) {
        uint16_t entry;
        if (!map_entry(p, NULL, 0u, x * 8u, y * 8u, 8u, &entry)) return 0;
        if (y < 8u) {
            if (entry >= 0x273Au && entry <= 0x274Bu) continue;
            if (!own_fleet_header_icon(x, y) || entry != own_fleet_header_icon(x, y)) return 0;
        } else if (y < 10u) {
            if (entry != 0x274Cu + (y - 8u) * 2u + (x & 1u)) return 0;
            continue;
        } else {
            /* C5:2B88..2CAD constructs alternating PAIRS over32x18cells.
             * C5:2E19 -> C1:3CF9 adds finite ship-picture tiles below3F50.
             * The first two water cells are required pristine donors. */
            if (entry == 0x3F50u + (y & 1u) * 2u + (x & 1u)) continue;
            if ((x < 2u && y < 12u) || entry < 0x3C00u || entry >= 0x3F50u) return 0;
        }
        content[y * 32u + x] = 1u;
    }
    for (y = 0u; y < 224u; ++y) {
        NHMode1Row14 cache = {0};
        for (x = 0u; x < 256u; ++x) {
            NHPixel14 sample;
            unsigned at = y * 256u + x, mask = ui->masks[b][at];
            if ((mask & (selector ? 0xA8u : 0xB8u)) || !mode1_bg_read(p, NULL, &cache, 0u, x, y, &sample)) return 0;
            background[at] = sample.transparent ? 0u : apply_brightness(sample.color, p->brightness);
            if (mask & 4u) {
                unsigned slot, matched = 0u;
                if (selector && own_fleet_selector_pixel(p, x, y, ui->pixels[b][at])) continue;
                if (x < 16u || x >= 56u || y < 15u || y >= 63u) return 0;
                /* C1:34F9..3510 chooses slot20 or50 from source E935.
                 * Both consumed buffers are legitimate during publication;
                 * rejoin the actual raster pixel, never activate a hidden one. */
                for (slot = 0u; slot < 2u; ++slot) {
                    NHObject14 object;
                    NHPortObjectPixel14 pixel;
                    unsigned local = ((y - 15u) / 8u) * 5u + (x - 16u) / 8u;
                    unsigned index = (slot ? 50u : 20u) + local;
                    unsigned ox = 16u + (local % 5u) * 8u, oy = 15u + (local / 5u) * 8u;
                    if (decode_object_read(p, NULL, index, &object) && object.x == ox &&
                        (uint8_t)(object.y - 1u) == oy && object.width == 8u && object.height == 8u &&
                        (object.tile | ((unsigned)p->oam[index * 4u + 3u].value << 8u)) ==
                            (slot ? 0x37E0u : 0x35C0u) + local &&
                        nh_ppu14_read_port_object(p, index, x - ox, y - oy, &pixel) && pixel.opaque &&
                        apply_brightness(pixel.color, p->brightness) == ui->pixels[b][at]) { matched = 1u; break; }
                }
                if (!matched) return 0;
            } else if ((mask & 3u) == 1u) {
                uint16_t expected = background[at];
                if (selector && (mask & 16u)) expected = apply_brightness(
                    color_math(sample.color, p->fixed_color.value, 1, 0), p->brightness);
                if (sample.transparent || expected != ui->pixels[b][at]) return 0;
            } else if ((mask & 3u) == 2u) {
                if (!mode1_bg_read(p, NULL, &cache, 2u, x, y, &sample) || sample.transparent ||
                    apply_brightness(sample.color, p->brightness) != ui->pixels[b][at]) return 0;
            } else if (mask || ui->pixels[b][at] || background[at]) return 0;
        }
    }
    for (y = 0u; y < 288u; ++y) for (x = 0u; x < 512u; ++x) {
        unsigned sx = x & 255u, sy = y;
        if (y >= 80u) { sx = x & 15u; sy = 80u + (y & 15u); }
        else if (y >= 64u) sx = x & 15u;
        else if (content[(y / 8u) * 32u + sx / 8u]) sx &= 7u;
        pixels[y * 512u + x] = background[sy * 256u + sx];
    }
    for (y = 0u; y < 224u; ++y) for (x = 0u; x < 256u; ++x) {
        unsigned at = y * 256u + x, mask = ui->masks[b][at], dx, dy;
        if (selector && y < 80u) { pixels[y * 512u + x + 128u] = ui->pixels[b][at]; continue; }
        if (!(mask & 4u) && (mask & 3u) != 2u && !content[(y / 8u) * 32u + x / 8u] &&
            !(selector && (mask & 16u))) continue;
        dx = y < 80u ? x + (x < 128u ? 0u : 256u) : x + 128u;
        dy = y < 80u ? y : y + 32u;
        pixels[dy * 512u + dx] = ui->pixels[b][at];
    }
    return 1;
}

int nh_ppu14_sea_marker_object(const NHPPU11 *p, unsigned index) {
    NHObject14 object;
    unsigned word, base;
    if (!p || index < 108u || index > 111u ||
        p->registers[5].value != 0x09u || !decode_object_read(p, NULL, index, &object)) return 0;
    word = object.tile | ((unsigned)p->oam[index * 4u + 3u].value << 8u);
    base = word - (index - 108u);
    /* C1:948C sequential2008..B; C0:9391 XOR0004 on four slots. */
    return object.width == 8u && object.height == 8u && (base == 0x2008u || base == 0x200Cu);
}

/* C9:4DF5/4E3C/50C0: the mast light is one LARGE object108, word2010,
 * animated by C0:9391 XOR0002 and source-script H/V flips. This is only
 * raster shape provenance; the facade additionally qualifies its actual
 * single-span controller before accepting an expanded frame. */
int nh_ppu14_sea_mast_object(const NHPPU11 *p, unsigned index) {
    NHObject14 object;
    unsigned word;
    if (!p || index != 108u || !byte_known(p->registers[5]) ||
        p->registers[5].value != 0x09u || !byte_known(p->registers[1]) ||
        p->registers[1].value != 0u || !decode_object_read(p, NULL, index, &object)) return 0;
    word = object.tile | ((unsigned)p->oam[index * 4u + 3u].value << 8u);
    return object.width == 16u && object.height == 16u && (word & 0x3FFDu) == 0x2010u;
}

/* C2:8A8A/8B89/8BDE -> C7:1B9D -> C7:19E3. The nine-slice
 * matrix C1:7EA5 supplies0,1,2/3,4,5/6,7,8; C7:1AE9 omits
 * interior4, emitting the hollow4x4 destination frame into slots0..11.
 * This is a view/world cursor, not an edge-anchored command window.
 * Require the whole consumed source shape, not arbitrary3210-family tiles. */
int nh_ppu14_sea_destination_object(const NHPPU11 *p, unsigned index) {
    static const uint8_t column[12] = {0,1,2,3,0,3,0,3,0,1,2,3};
    static const uint8_t row[12] = {0,0,0,0,1,1,2,2,3,3,3,3};
    static const uint8_t tile[12] = {0,1,1,2,3,5,3,5,6,7,7,8};
    unsigned n, b, left, top;
    if (!p || index >= 12u || p->registers[5].known_mask != 255u ||
        p->registers[5].value != 0x09u) return 0;
    if (p->oam[index * 4u + 2u].value != 0x10u + tile[index] ||
        p->oam[index * 4u + 3u].value != 0x32u) return 0;
    left = p->oam[0].value; top = p->oam[1].value;
    if (left > 224u || top < 1u || top > 193u) return 0;
    for (n = 0u; n < 12u; ++n) {
        unsigned pair;
        for (b = 0u; b < 4u; ++b)
            if (p->oam[n * 4u + b].known_mask != 255u) return 0;
        if (p->oam[512u + n / 4u].known_mask != 255u) return 0;
        pair = (p->oam[512u + n / 4u].value >> ((n & 3u) * 2u)) & 3u;
        if (pair || p->oam[n * 4u].value != left + column[n] * 8u ||
            p->oam[n * 4u + 1u].value != top + row[n] * 8u ||
            p->oam[n * 4u + 2u].value != 0x10u + tile[n] ||
            p->oam[n * 4u + 3u].value != 0x32u) return 0;
    }
    return 1;
}

static uint8_t object_sample(uint16_t p01, uint16_t p23, unsigned bit) {
    return (uint8_t)(((p01 >> bit) & 1u) | (((p01 >> (bit + 8u)) & 1u) << 1u) |
                    (((p23 >> bit) & 1u) << 2u) | (((p23 >> (bit + 8u)) & 1u) << 3u));
}

/* Object-local sample only; no native coordinate wrapping, line limits,
 * priority scratch writes, error latch updates or hidden-slot resurrection.
 * The town compositor must qualify source activity and project world position. */
int nh_ppu14_read_port_object(const NHPPU11 *p, unsigned index,
                             unsigned x, unsigned y, NHPortObjectPixel14 *out) {
    NHObject14 object;
    uint8_t obsel, mode, sample;
    uint16_t p01, p23, value;
    unsigned bit;
    if (!p || !out || !decode_object_read(p, NULL, index, &object) ||
        !read_reg8(p, NULL, 1u, &obsel) || !read_reg8(p, NULL, 5u, &mode) ||
        (mode & 7u) != 1u || x >= object.width || y >= object.height ||
        !object_row_read(p, NULL, &object, obsel, y, x >> 3u, &p01, &p23)) return 0;
    bit = object.hflip ? x & 7u : 7u - (x & 7u);
    sample = object_sample(p01, p23, bit);
    memset(out, 0, sizeof(*out));
    if (!sample) return 1;
    out->palette = (uint8_t)(128u + object.palette * 16u + sample);
    if (!read_color(p, NULL, out->palette, &value)) return 0;
    out->color = value; /* Brightness/math applied after composition, not here. */
    out->rank = (uint8_t)obj_rank(mode, object.priority);
    out->opaque = 1u;
    return 1;
}

/* World stage only: source-qualified terrain plus projected actors. UI, window
 * masks and color math are a later composition stage, not silently discarded
 * from an activated frontend mode. Native guest scanline limits are unchanged. */
static int read_projected_world(const NHPPU11 *p, unsigned origin_y,
                                const NHPortActor14 *actors, unsigned count,
                                uint16_t *pixels, uint32_t capacity) {
    NHObject14 objects[40];
    unsigned n, x, y;
    uint8_t mode, obsel, main;
    if (count > 40u || (count && !actors) ||
        !nh_ppu14_read_port_terrain(p, origin_y, pixels, capacity) ||
        !read_reg8(p, NULL, 1u, &obsel) ||
        !read_reg8(p, NULL, 5u, &mode) ||
        !read_reg8(p, NULL, 0x2Cu, &main)) return 0;
    if (!(main & 16u)) return 1;
    memset(objects, 0, sizeof(objects));
    for (n = 0; n < count; ++n) {
        const uint8_t attr = actors[n].attributes;
        NHObject14 *o = &objects[n];
        if (actors[n].large > 1u) return 0;
        o->tile = actors[n].tile; o->name = attr & 1u;
        o->palette = (attr >> 1u) & 7u; o->priority = (attr >> 4u) & 3u;
        o->hflip = (attr >> 6u) & 1u; o->vflip = attr >> 7u;
        object_sizes(obsel >> 5u, actors[n].large, &o->width, &o->height);
    }
    /* Only resample terrain where an actor can overlap. Earlier objects win
     * equal OBJ rank, then the winning OBJ competes with BG2 as in screen_pixel.
     * Do not let a later higher-priority object inherit an earlier one's rank. */
    for (y = 0; y < 288u; ++y) {
        uint8_t ranks[512] = {0};
        NHMode1Row14 cache = {0};
        for (n = 0; n < count; ++n) {
            const NHObject14 *o = &objects[n];
            const int row = (int)(y + origin_y) - actors[n].world_y;
            const unsigned rank = obj_rank(mode, o->priority);
            if (row < 0 || row >= o->height) continue;
            for (x = 0; x < o->width; ++x) {
                const int screen_x = actors[n].world_x + (int)x;
                uint16_t p01, p23, value;
                uint8_t sample;
                unsigned bit;
                NHPixel14 bg;
                if (screen_x < 0 || screen_x >= 512 || rank <= ranks[screen_x]) continue;
                if (!object_row_read(p, NULL, o, obsel, (unsigned)row, x >> 3u,
                                     &p01, &p23)) return 0;
                bit = o->hflip ? x & 7u : 7u - (x & 7u);
                sample = object_sample(p01, p23, bit);
                if (!sample) continue;
                if (!mode1_bg_read(p, NULL, &cache, 1u,
                    ((unsigned)screen_x + 1024u - p->bg_hofs[1].value) & 1023u,
                    (y + origin_y + 1024u - p->bg_vofs[1].value) & 1023u, &bg)) return 0;
                ranks[screen_x] = (uint8_t)rank;
                if (!bg.transparent && bg.rank >= rank) continue;
                if (!read_color(p, NULL, 128u + o->palette * 16u + sample, &value)) return 0;
                pixels[y * 512u + (unsigned)screen_x] = apply_brightness(value, p->brightness);
            }
        }
    }
    return 1;
}

int nh_ppu14_read_port_world(const NHPPU11 *p, unsigned origin_y,
                            const NHPortActor14 *actors, unsigned count,
                            uint16_t *pixels, uint32_t capacity) {
    return count <= 10u && read_projected_world(p, origin_y, actors, count,
                                               pixels, capacity);
}

int nh_ppu14_read_combat_world(const NHPPU11 *p, unsigned origin_y,
                              const NHPortActor14 *actors, unsigned count,
                              uint16_t *pixels, uint32_t capacity) {
    return read_projected_world(p, origin_y, actors, count, pixels, capacity);
}

/* CD:26DA emits priority1 BG3 fleet/index glyphs over ships (Mode1 rank11).
 * Sample that same eight-pixel 2bpp character, including its actual palette,
 * at the facade's source-qualified world position. No glyph/font recreation. */
int nh_ppu14_draw_combat_label(const NHPPU11 *p, uint16_t entry, int left, int top,
                              uint16_t *pixels, uint32_t capacity) {
    uint8_t nba, mode, main;
    unsigned x, y, base, palette;
    if (!p || !pixels || capacity < 512u * 288u ||
        !(((entry & 0xE3FFu) >= 0x2360u && (entry & 0xE3FFu) <= 0x2369u) ||
          ((entry & 0xE3FFu) >= 0x2370u && (entry & 0xE3FFu) <= 0x2379u)) ||
        !read_reg8(p, NULL, 5u, &mode) || mode != 0x29u ||
        !read_reg8(p, NULL, 0x0Cu, &nba) ||
        !read_reg8(p, NULL, 0x2Cu, &main)) return 0;
    if (!(main & 4u)) return 1;
    base = ((unsigned)(nba & 15u) << 13u) + (entry & 1023u) * 16u;
    palette = ((entry >> 10u) & 7u) * 4u;
    for (y = 0u; y < 8u; ++y) {
        uint16_t row;
        int dy = top + (int)y;
        if (dy < 0 || dy >= 288) continue;
        if (!read_vr16(p, NULL, (base + y * 2u) & 65535u, &row)) return 0;
        for (x = 0u; x < 8u; ++x) {
            unsigned bit = 7u - x;
            unsigned sample = ((row >> bit) & 1u) | (((row >> (bit + 8u)) & 1u) << 1u);
            int dx = left + (int)x;
            uint16_t value;
            if (!sample || dx < 0 || dx >= 512) continue;
            if (!read_color(p, NULL, palette + sample, &value)) return 0;
            pixels[(unsigned)dy * 512u + (unsigned)dx] = apply_brightness(value, p->brightness);
        }
    }
    return 1;
}

/* CD:CC65's eleven2x2 BG1 cell-marker groups. The facade must join the
 * source candidate/path state to consumed native BG1 before extending it.
 * BG1 high rank9 is above the source ship rank7; BG3 labels are drawn later. */
int nh_ppu14_draw_combat_cell(const NHPPU11 *p, unsigned group, int left, int top,
                             uint16_t *pixels, uint32_t capacity) {
    unsigned x, y;
    uint8_t nba, main, math;
    NHTileRow14 cache = {0};
    if (!p || !pixels || capacity < 512u * 288u || group >= 11u ||
        !read_reg8(p, NULL, 0x0Bu, &nba) || !read_reg8(p, NULL, 0x2Cu, &main) ||
        !read_reg8(p, NULL, 0x31u, &math) || (math & 1u)) return 0;
    if (!(main & 1u)) return 1;
    for (y = 0u; y < 16u; ++y) {
        int dy = top + (int)y;
        if (dy < 0 || dy >= 288) continue;
        for (x = 0u; x < 16u; ++x) {
            unsigned tile = 0x140u + group * 4u + (y >> 3u) * 2u + (x >> 3u);
            unsigned address = ((unsigned)(nba & 15u) << 13u) + tile * 32u + (y & 7u) * 2u;
            unsigned sample;
            uint16_t value;
            int dx = left + (int)x;
            if (dx < 0 || dx >= 512) continue;
            if (!mode1_tile_row(p, NULL, &cache, address, 4u)) return 0;
            sample = cache.pixels[x & 7u];
            if (!sample) continue;
            if (!read_color(p, NULL, 80u + sample, &value)) return 0;
            pixels[(unsigned)dy * 512u + (unsigned)dx] = apply_brightness(value, p->brightness);
        }
    }
    return 1;
}

/* Positive consumed-pose owners, not a blanket slot0/slot1 exemption.
 * CD:0DEB cursor3240/42; CD:47B2 directional effect3C80+2*n,n<4;
 * CD:4F6E/51E2 moving3C60+2*n,n<=3; CD:57E2 event3E68+2*n.
 * CD:5300..533B is a SEPARATE five-frame impact, slot1/base3C88.
 * CD:4B99 adds2*n and skips the lower sixteen-character half-row:
 * the exact consumed words are3C88,3C8A,3C8C,3C8E,3CA0 (n0..4).
 * CD:544F..555F separately emits six ship-cell effect frames into slot0,
 * base3CA2 through4B99:3CA2/3CA4/3CA6/3CA8/3CAA/3CAC (no row skip).
 * CD:CDAD's eight WORDS are0,1,2,3,1,3,0,2,
 * passed through4B99; those event words do not cross its row adjustment.
 * C0:B99A clears XY without clearing the old word/LARGE bits. */
int nh_ppu14_combat_world_object(const NHPPU11 *p, unsigned index) {
    unsigned b, pair, word;
    if (!p || index > 1u || p->registers[1].known_mask != 255u || p->registers[1].value != 0u)
        return 0;
    for (b = 0u; b < 4u; ++b) if (!byte_known(p->oam[index * 4u + b])) return 0;
    if (!byte_known(p->oam[512])) return 0;
    pair = (p->oam[512].value >> (index * 2u)) & 3u;
    if (!(pair & 2u) || (p->oam[index * 4u].value == 0x80u &&
        p->oam[index * 4u + 1u].value == 0xF0u && (pair & 1u))) return 0;
    word = p->oam[index * 4u + 2u].value | ((unsigned)p->oam[index * 4u + 3u].value << 8u);
    if (index == 0u)
        return word == 0x3240u || word == 0x3242u ||
            (word >= 0x3C60u && word <= 0x3C66u && !(word & 1u)) ||
            (word >= 0x3CA2u && word <= 0x3CACu && !(word & 1u)) ||
            (word >= 0x3E68u && word <= 0x3E6Eu && !(word & 1u));
    return (word >= 0x3C80u && word <= 0x3C8Eu && !(word & 1u)) || word == 0x3CA0u;
}

/* C2:6E8F supplies3200 to C6:032C's TWO four-word dialogue prompt frames,
 *3200..3203 and3204..3207, distinct from the
 * LARGE3240 tactical cell cursor. C2:0F22 supplies portrait slot base50 to
 * command7B; the captured portrait is a complete5x6 SMALL37E0..37FD grid.
 * C7:2321..2382 supplies eighteen3210..3221 words as two adjacent3x3
 * shoulder/rotation instruction icons, emitted into slots0..17.
 * Admit only a joined whole group, not arbitrary sprites in those slots.
 * Retain ordinary OBJ UI provenance so the existing window grouping moves
 * portrait/prompt/text/backing together. These are NOT world effects. */
int nh_ppu14_combat_ui_object(const NHPPU11 *p, unsigned index) {
    unsigned first, count, columns, base, n, left = 0u, top = 0u;
    int hands = 0;
    if (!p || p->registers[1].known_mask != 255u || p->registers[1].value != 0u) return 0;
    if (index < 18u && byte_known(p->oam[2]) && byte_known(p->oam[3]) &&
        p->oam[2].value == 0x10u && p->oam[3].value == 0x32u) {
        first = 0u; count = 18u; columns = 6u; base = 0x3210u; hands = 1;
    } else if (index < 4u) {
        if (!byte_known(p->oam[2]) ||
            (p->oam[2].value != 0u && p->oam[2].value != 4u)) return 0;
        first = 0u; count = 4u; columns = 2u; base = 0x3200u + p->oam[2].value;
    }
    else if (index >= 50u && index < 80u) { first = 50u; count = 30u; columns = 5u; base = 0x37E0u; }
    else return 0;
    for (n = 0u; n < count; ++n) {
        unsigned slot = first + n, b, pair, word;
        for (b = 0u; b < 4u; ++b) if (!byte_known(p->oam[slot * 4u + b])) return 0;
        if (!byte_known(p->oam[512u + slot / 4u])) return 0;
        pair = (p->oam[512u + slot / 4u].value >> ((slot & 3u) * 2u)) & 3u;
        word = p->oam[slot * 4u + 2u].value | ((unsigned)p->oam[slot * 4u + 3u].value << 8u);
        if (pair || word != base + n) return 0;
        if (!n) { left = p->oam[slot * 4u].value; top = p->oam[slot * 4u + 1u].value; }
        if (left + columns * 8u > 256u || top + count / columns * 8u > 224u ||
            p->oam[slot * 4u].value != left +
                (hands ? (n / 9u * 3u + n % 3u) : n % columns) * 8u ||
            p->oam[slot * 4u + 1u].value != top +
                (hands ? n % 9u / 3u : n / columns) * 8u) return 0;
    }
    return 1;
}

/* Rank10 source objects above rank9 BG1 cells and rank7 ships, but below
 * rank11 BG3 labels. Caller draws slots in reverse order for equal OBJ rank.
 * Sample the FULL native16x16 object, including portions beyond old edges. */
int nh_ppu14_draw_combat_object(const NHPPU11 *p, unsigned index, int left, int top,
                               uint16_t *pixels, uint32_t capacity) {
    uint16_t word;
    if (!nh_ppu14_combat_world_object(p, index)) return 0;
    word = (uint16_t)(p->oam[index * 4u + 2u].value |
                     ((unsigned)p->oam[index * 4u + 3u].value << 8u));
    return nh_ppu14_draw_combat_pose(p, word, left, top, pixels, capacity);
}

/* Source-qualified hypothetical pose for an effect whose own native bounds
 * branch cleared OAM. The facade owns activity/position/phase qualification;
 * this sampler never runs source instructions or mutates native OAM. */
int nh_ppu14_draw_combat_pose(const NHPPU11 *p, uint16_t word, int left, int top,
                             uint16_t *pixels, uint32_t capacity) {
    NHObject14 object;
    unsigned x, y;
    uint8_t main, math, obsel;
    if (!p || !pixels || capacity < 512u * 288u ||
        !(word == 0x3240u || word == 0x3242u ||
          (word >= 0x3C60u && word <= 0x3C66u && !(word & 1u)) ||
          (word >= 0x3C80u && word <= 0x3C8Eu && !(word & 1u)) || word == 0x3CA0u ||
          (word >= 0x3CA2u && word <= 0x3CACu && !(word & 1u)) ||
          (word >= 0x3E68u && word <= 0x3E6Eu && !(word & 1u))) ||
        !read_reg8(p, NULL, 1u, &obsel) || obsel != 0u ||
        !read_reg8(p, NULL, 0x2Cu, &main) || !read_reg8(p, NULL, 0x31u, &math) ||
        (math & 16u)) return 0;
    if (!(main & 16u)) return 1;
    memset(&object, 0, sizeof(object));
    object.tile = (uint8_t)word; object.name = (uint8_t)((word >> 8u) & 1u);
    object.palette = (uint8_t)((word >> 9u) & 7u); object.priority = 3u;
    object.hflip = (uint8_t)((word >> 14u) & 1u); object.vflip = (uint8_t)(word >> 15u);
    object.width = 16u; object.height = 16u;
    for (y = 0u; y < 16u; ++y) for (x = 0u; x < 16u; ++x) {
        uint16_t p01, p23, color_value;
        unsigned sample, bit;
        int dx = left + (int)x, dy = top + (int)y;
        if (dx < 0 || dx >= 512 || dy < 0 || dy >= 288) continue;
        if (!object_row_read(p, NULL, &object, obsel, y, x >> 3u, &p01, &p23)) return 0;
        bit = object.hflip ? x & 7u : 7u - (x & 7u);
        sample = object_sample(p01, p23, bit);
        if (sample) {
            if (!read_color(p, NULL, 128u + object.palette * 16u + sample, &color_value)) return 0;
            pixels[(unsigned)dy * 512u + (unsigned)dx] = apply_brightness(color_value, p->brightness);
        }
    }
    return 1;
}

/* C2:0FD7/C1:23CC supplies four models and eight headings, with separate
 * player/other fleet palettes. No hypothetical arbitrary OBJ word is admitted.
 * Ship animation already present in VRAM is sampled without advancing it. */
static int sea_ship_word(unsigned word) {
    unsigned model, heading;
    /* C0:93DF/941F XORs source mask0002 through the Sea113..127 bitmap.
     * The facade certifies that controller; this sampler accepts its two poses. */
    word &= ~2u;
    for (model = 0u; model < 4u; ++model) for (heading = 0u; heading < 8u; ++heading) {
        unsigned tile = 0xC0u + 64u * model + 4u * heading + (heading >= 4u ? 16u : 0u);
        if (word == (0x2800u | tile) || word == (0x2A00u | tile)) return 1;
    }
    return 0;
}

int nh_ppu14_sea_world_object(const NHPPU11 *p, unsigned index) {
    unsigned n, pair, word;
    if (!p || index < 113u || index >= 128u ||
        !byte_known(p->registers[5]) || p->registers[5].value != 0x09u ||
        !byte_known(p->registers[1]) || p->registers[1].value != 0u) return 0;
    for (n = 0u; n < 4u; ++n) if (!byte_known(p->oam[index * 4u + n])) return 0;
    if (!byte_known(p->oam[512u + index / 4u])) return 0;
    pair = (p->oam[512u + index / 4u].value >> ((index & 3u) * 2u)) & 3u;
    word = p->oam[index * 4u + 2u].value | ((unsigned)p->oam[index * 4u + 3u].value << 8u);
    return (pair & 2u) && sea_ship_word(word);
}

int nh_ppu14_draw_sea_fleets(const NHPPU11 *p, const NHPortActor14 *actors,
                            const uint8_t *native_clip, unsigned count,
                            uint16_t *pixels, uint32_t capacity) {
    NHObject14 objects[86];
    unsigned n, y;
    uint8_t mode, obsel, main, math;
    if (!p || !pixels || capacity < 512u * 288u || count > 86u ||
        (count && (!actors || !native_clip)) || !read_reg8(p, NULL, 5u, &mode) || mode != 0x09u ||
        !read_reg8(p, NULL, 1u, &obsel) || obsel != 0u ||
        !read_reg8(p, NULL, 0x2Cu, &main) ||
        !read_reg8(p, NULL, 0x31u, &math) ||
        !p->port_ui || (p->port_ui->sea_color_valid[p->port_ui->published] != 1u &&
                       !p->port_ui->sea_rect_qualified)) return 0;
    if (!(main & 16u)) return 1;
    memset(objects, 0, sizeof(objects));
    for (n = 0u; n < count; ++n) {
        uint16_t word = actors[n].tile | ((uint16_t)actors[n].attributes << 8u);
        NHObject14 *o = &objects[n];
        if (!sea_ship_word(word) || actors[n].large != 1u) return 0;
        o->tile = actors[n].tile; o->name = actors[n].attributes & 1u;
        o->palette = (actors[n].attributes >> 1u) & 7u;
        o->priority = 2u; o->width = 16u; o->height = 16u;
    }
    for (y = 0u; y < 288u; ++y) {
        uint8_t occupied[512] = {0};
        for (n = 0u; n < count; ++n) {
            const NHObject14 *o = &objects[n];
            int row = (int)y - actors[n].world_y;
            unsigned x;
            if (row < 0 || row >= 16) continue;
            for (x = 0u; x < 16u; ++x) {
                int dx = actors[n].world_x + (int)x;
                uint16_t p01, p23, color;
                unsigned sample;
                if (dx < 0 || dx >= 512 || occupied[dx]) continue;
                /* Source-only extra fleets must not pre-empt native allocation,
                 * redraw, line culling or pending OAM inside the original view.
                 * Their actually unavailable native pixels are not invented. */
                if (native_clip[n] == 1u && dx >= 128 && dx < 384 && y >= 32u && y < 256u) continue;
                if (native_clip[n] == 2u && !(dx >= 128 && dx < 384 && y >= 32u && y < 256u)) continue;
                if (!object_row_read(p, NULL, o, obsel, (unsigned)row, x >> 3u, &p01, &p23)) return 0;
                sample = object_sample(p01, p23, 7u - (x & 7u));
                if (!sample) continue;
                if (!read_color(p, NULL, 128u + o->palette * 16u + sample, &color)) return 0;
                pixels[y * 512u + (unsigned)dx] = sea_presentation_color(p, color, 16u, dx, y);
                occupied[dx] = 1u;
            }
        }
    }
    {
        unsigned destination = nh_ppu14_sea_destination_object(p, 0u);
        /* Destination0..11, shore108..111 and mast108 precede fleets113..127.
         * Draw only actual consumed OAM, translated with the native view. */
        for (n = 0u; n <= 111u; ++n) {
            NHObject14 object;
            unsigned x, sy, mast = nh_ppu14_sea_mast_object(p, n);
            if (!(destination && n < 12u) &&
                !(p->port_ui->sea_marker_qualified && n >= 108u) && !mast) continue;
            if (nh_ppu14_object_native_hidden(p, n) == 1) continue;
            if ((n >= 108u && !nh_ppu14_sea_marker_object(p, n) && !mast) ||
                !decode_object_read(p, NULL, n, &object)) return 0;
            for (sy = 0u; sy < object.height; ++sy) for (x = 0u; x < object.width; ++x) {
                NHPortObjectPixel14 sample;
                int ox = object.x < 256u ? (int)object.x : (int)object.x - 512;
                int oy = (int)(uint8_t)(object.y - 1u);
                int dx, dy;
                if (oy > 240) oy -= 256;
                dx = ox + 128 + (int)x; dy = oy + 32 + (int)sy;
                if (!nh_ppu14_read_port_object(p, n, x, sy, &sample)) return 0;
                if (sample.opaque && dx >= 0 && dx < 512 && dy >= 0 && dy < 288)
                    pixels[(unsigned)dy * 512u + (unsigned)dx] =
                        sea_presentation_color(p, sample.color, 0u, dx, (unsigned)dy);
            }
        }
    }
    return 1;
}

static int prepare_objects(NHPPU11 *p, unsigned y, uint8_t bgmode) {
    uint8_t obsel;
    unsigned scan, first = 0u, visible = 0u, tiles = 0u;
    if (!reg8(p, 1u, &obsel)) return 0;
    memset(p->obj_line_palette, 0, sizeof(p->obj_line_palette));
    memset(p->obj_line_rank, 0, sizeof(p->obj_line_rank));
    if (p->port_ui) memset(p->port_ui->object_owner, 255, sizeof(p->port_ui->object_owner));
    if ((p->registers[3].known_mask & 0x80u) == 0u) return 0;
    if ((p->registers[3].value & 0x80u) != 0u) first = (p->oam_address >> 2u) & 127u;
    for (scan=0u; scan<128u; ++scan) {
        NHObject14 object; unsigned index=(first+scan)&127u, line, tile_x, tile_count;
        if (!decode_object_read(p,p,index,&object)) return 0;
        line=(uint8_t)((y+1u-object.y)&255u);
        if (!((object.x<=256u || (uint32_t)object.x+object.width-1u>=512u) && line<object.height)) continue;
        if (++visible > 32u) { p->obj_range_over=1u; break; }
        tile_count=object.width>>3u;
        for(tile_x=0u;tile_x<tile_count;++tile_x){
            unsigned tile_screen_x=(object.x+tile_x*8u)&511u;
            uint16_t p01,p23; unsigned px;
            if(object.x!=256u&&tile_screen_x>=256u&&tile_screen_x+7u<512u)continue;
            if(!object_row_read(p,p,&object,obsel,line,tile_x,&p01,&p23))return 0;
            if(++tiles>34u){p->obj_time_over=1u;return 1;}
            for(px=0u;px<8u;++px){
                unsigned screen_x=(object.x+tile_x*8u+px)&511u;
                unsigned bit=object.hflip?px:7u-px;
                uint8_t sample=object_sample(p01,p23,bit);
                unsigned rank=obj_rank(bgmode,object.priority);
                if(screen_x<NH_PPU_FRAME_WIDTH&&sample!=0u&&
                   rank>p->obj_line_rank[screen_x]){
                    p->obj_line_rank[screen_x]=(uint8_t)rank;
                    p->obj_line_palette[screen_x]=
                        (uint8_t)(128u+object.palette*16u+sample);
                    if (p->port_ui) p->port_ui->object_owner[screen_x] = (uint8_t)index;
                }
            }
        }
    }
    return 1;
}

static int screen_pixel(NHPPU11 *p, NHMode1Row14 *cache, unsigned x, unsigned y,
                        uint8_t screen, uint8_t window_mask, int read_backdrop,
                        NHPixel14 *best) {
    uint8_t bgmode; unsigned layer, layers; int visible;
    memset(best,0,sizeof(*best));best->layer=5u;best->transparent=1u;
    if(!reg8(p,5u,&bgmode))return 0;
    layers=(bgmode&7u)==0u?4u:(bgmode&7u)==7u?2u:3u;
    for(layer=0u;layer<layers;++layer){
        NHPixel14 candidate;
        if(!layer_visible(p,layer,x,screen,window_mask,&visible))return 0;
        if(!visible)continue;
        if((bgmode&7u)==0u||(bgmode&7u)==1u){if(!mode1_bg(p,cache,layer,x,y,&candidate))return 0;}
        else if((bgmode&7u)==7u){if(!mode7_bg(p,layer,x,y,&candidate))return 0;}
        else return missing(p, 6u, 0x2105u, p->registers[5]);
        if(!candidate.transparent&&candidate.rank>best->rank)*best=candidate;
    }
    if(!layer_visible(p,4u,x,screen,window_mask,&visible))return 0;
    if(visible&&p->obj_line_palette[x]!=0u&&p->obj_line_rank[x]>best->rank){
        if(!color(p,p->obj_line_palette[x],&best->color))return 0;
        best->rank=p->obj_line_rank[x];best->layer=4u;
        best->palette=p->obj_line_palette[x];best->transparent=0u;
    }
    if(best->transparent){
        if(read_backdrop&& !color(p,0u,&best->color))return 0;
        if(!read_backdrop)best->color=0u;
        best->layer=5u;best->palette=0u;best->transparent=0u;
    }
    return 1;
}

static unsigned channel(unsigned color_value, unsigned shift) {
    return (color_value >> shift) & 31u;
}

static uint16_t color_math(uint16_t main, uint16_t sub, int subtract, int half) {
    unsigned r1=channel(main,0u),g1=channel(main,5u),b1=channel(main,10u);
    unsigned r2=channel(sub,0u),g2=channel(sub,5u),b2=channel(sub,10u);
    unsigned r,g,b;
    if(subtract){r=r1>r2?r1-r2:0u;g=g1>g2?g1-g2:0u;b=b1>b2?b1-b2:0u;
        if(half){r>>=1u;g>>=1u;b>>=1u;}}
    else{r=r1+r2;g=g1+g2;b=b1+b2;if(half){r>>=1u;g>>=1u;b>>=1u;}
        r=r>31u?31u:r;g=g>31u?31u:g;b=b>31u?31u:b;}
    return (uint16_t)(r|(g<<5u)|(b<<10u));
}

static int render_pixel(NHPPU11 *p,NHMode1Row14 *cache,unsigned x,unsigned y,uint16_t *result,
                        NHPixel14 *source, unsigned *math_flags){
    uint8_t tm,ts,tmw,tsw,cgwsel,cgadsub;NHPixel14 main,sub;int color_inside=0;
    int clip,prevent,math_enabled,half;uint16_t addend;unsigned math_bit;
    if (source) { memset(source, 0, sizeof(*source)); source->layer = 5u; source->transparent = 1u; }
    if (math_flags) *math_flags = 0u;
    if(p->forced_blank!=0u||p->brightness==0u){*result=0u;return 1;}
    if(!reg8(p,0x2Cu,&tm)||!reg8(p,0x2Eu,&tmw)||
       !reg8(p,0x30u,&cgwsel)||!reg8(p,0x31u,&cgadsub))return 0;
    if((((cgwsel>>6u)&3u)==1u||((cgwsel>>6u)&3u)==2u||
        ((cgwsel>>4u)&3u)==1u||((cgwsel>>4u)&3u)==2u)&&
       !layer_window(p,5u,x,&color_inside))return 0;
    clip=((cgwsel>>6u)&3u)==3u||(((cgwsel>>6u)&3u)==1u&&!color_inside)||
         (((cgwsel>>6u)&3u)==2u&&color_inside);
    prevent=((cgwsel>>4u)&3u)==3u||(((cgwsel>>4u)&3u)==1u&&!color_inside)||
            (((cgwsel>>4u)&3u)==2u&&color_inside);
    /* Extra observational flags; existing callers still consume low two bits. */
    if (math_flags) *math_flags |= (clip ? 4u : 0u) | (prevent ? 8u : 0u);
    if(clip&&(prevent||(cgadsub&0x3Fu)==0u)){*result=0u;return 1;}
    if(!screen_pixel(p,cache,x,y,tm,tmw,1,&main))return 0;
    if (source) *source = main;
    if(clip)main.color=0u;
    math_bit=main.layer==5u?5u:main.layer;
    math_enabled=!prevent&&(cgadsub&(1u<<math_bit))!=0u&&
                 !(main.layer==4u&&main.palette<192u);
    if(math_enabled){
        if (math_flags) *math_flags |= 1u;
        half=(cgadsub&0x40u)!=0u&&!clip;
        if((cgwsel&2u)!=0u){
            if(!reg8(p,0x2Du,&ts)||!reg8(p,0x2Fu,&tsw)||
               !screen_pixel(p,cache,x,y,ts,tsw,0,&sub))return 0;
            if(sub.layer!=5u){
                addend=sub.color;
                if (math_flags) *math_flags |= 2u;
            }
            else{
                if(p->fixed_color.known_mask!=0x7FFFu)
                    return missing(p,7u,0x2132u,(NHBusValue){
                        (uint8_t)p->fixed_color.value,
                        (uint8_t)p->fixed_color.known_mask});
                addend=p->fixed_color.value;half=0;
            }
        }else{
            if (p->fixed_color.known_mask != 0x7FFFu) {
                return missing(p, 7u, 0x2132u,
                    (NHBusValue){(uint8_t)p->fixed_color.value,
                                 (uint8_t)p->fixed_color.known_mask});
            }
            addend = p->fixed_color.value;
        }
        main.color=color_math(main.color,addend,(cgadsub&0x80u)!=0u,
                              half);
    }
    *result=apply_brightness(main.color,p->brightness);return 1;
}

static void mark(uint8_t *map,uint32_t offset){map[offset>>3u]|=(uint8_t)(1u<<(offset&7u));}

static NHBusStop render_fail(NHPPU11 *p,uint16_t line){
    ++p->unknown_scanlines;
    if(p->bus->failure.reason==NH_BUS_OK){
        p->bus->failure.reason=NH_BUS_PPU_UNAVAILABLE;p->bus->failure.owner=NH_OWNER_PPU_11;
        p->bus->failure.address=0x2105u;p->bus->failure.value=(uint8_t)line;
        p->bus->failure.known_mask=0u;
    }
    return p->bus->failure.reason;
}

NHBusStop nh_ppu14_raster_event(NHPPU11 *p,NHBusRuntime *bus,
                                const NHScheduler *scheduler,NHRasterEvent event){
    unsigned x,y,height;uint16_t value;uint32_t offset;uint8_t bgmode,tm,ts;
    if(p==NULL||bus==NULL||scheduler==NULL||p->bus!=bus||p->scheduler!=scheduler)
        return NH_BUS_BAD_ARGUMENT;
    if(bus->failure.reason!=NH_BUS_OK)return bus->failure.reason;
    if(event==NH_RASTER_LINE_BEGIN&&scheduler->scanline==0u){
        memset(p->work_known,0,sizeof(p->work_known));
        p->frame_published_this_vblank=0u;
        if (p->port_ui) {
            NHPortUiCapture14 *ui = p->port_ui;
            ui->work = (uint8_t)(ui->published ^ 1u);
            ui->chart_work_valid[ui->work] = 0u;
            ui->valid[ui->work] = 1u;
            ui->hud_only[ui->work] = 1u;
            ui->dependent_math[ui->work] = 0u;
            ui->frame_mode[ui->work] = 255u;
            ui->sea_scroll_valid[ui->work] = 0u;
            ui->sea_mosaic_valid[ui->work] = 0u;
            ui->sea_color_valid[ui->work] = 0u;
            ui->sea_rect_valid[ui->work] = 0u;
            ui->sea_rect_any[ui->work] = 0u;
            memset(ui->sea_bg2_seen[ui->work], 0, sizeof(ui->sea_bg2_seen[ui->work]));
            memset(ui->sea_mosaic_fringe[ui->work], 0, sizeof(ui->sea_mosaic_fringe[ui->work]));
            memset(ui->tiles[ui->work], 0, sizeof(ui->tiles[ui->work]));
            ui->lines = 0u;
        }
    }
    height=p->overscan!=0u?239u:224u;
    if(event==NH_RASTER_HBLANK_BEGIN&&scheduler->scanline>0u&&scheduler->scanline<=height){
        NHMode1Row14 cache = {0};
        unsigned sea_color_seen = 0u;
        y=scheduler->scanline-1u;
        if (p->port_ui) {
            NHPortUiCapture14 *ui = p->port_ui;
            unsigned current_mode = p->registers[5].value;
            if (height != 224u || p->registers[5].known_mask != 255u ||
                (current_mode != 0x29u && current_mode != 0x09u) ||
                (ui->frame_mode[ui->work] != 255u && ui->frame_mode[ui->work] != current_mode))
                ui->valid[ui->work] = 0u;
            ui->frame_mode[ui->work] = (uint8_t)current_mode;
            if (current_mode == 0x09u) {
                unsigned b = ui->work;
                if (p->registers[6].known_mask != 255u ||
                    (ui->sea_mosaic_valid[b] && ui->sea_mosaic[b] != p->registers[6].value))
                    ui->sea_mosaic_valid[b] = 2u;
                else if (!ui->sea_mosaic_valid[b]) {
                    ui->sea_mosaic_valid[b] = 1u; ui->sea_mosaic[b] = p->registers[6].value;
                }
                int rect = p->registers[0x30].value == 0x10u && p->registers[0x31].value == 2u &&
                    (p->registers[0x25].value & 0xF0u) == 0x80u &&
                    p->fixed_color.known_mask == 0x7FFFu && p->fixed_color.value == 0x00AFu &&
                    p->registers[0x28].known_mask == 255u && p->registers[0x29].known_mask == 255u;
                int plain = !(p->registers[0x30].value & 0xC0u) &&
                    (((p->registers[0x30].value >> 4u) & 3u) == 3u ||
                     !(p->registers[0x31].value & 0x32u));
                if ((!rect && !plain) || (ui->sea_rect_valid[b] && ui->sea_rect_brightness[b] != p->brightness))
                    ui->sea_rect_valid[b] = 2u;
                else if (!ui->sea_rect_valid[b]) {
                    ui->sea_rect_valid[b] = 1u; ui->sea_rect_brightness[b] = p->brightness;
                }
                if (rect) ui->sea_rect_any[b] = 1u;
                ui->sea_rect_left[b][y] = rect ? p->registers[0x28].value : 255u;
                ui->sea_rect_right[b][y] = rect ? p->registers[0x29].value : 0u;
                if (p->bg_hofs[1].known_mask != 0x3FFu || p->bg_vofs[1].known_mask != 0x3FFu)
                    ui->sea_scroll_valid[ui->work] = 2u;
                else if (!ui->sea_scroll_valid[ui->work]) {
                    ui->sea_hofs[ui->work] = p->bg_hofs[1].value;
                    ui->sea_vofs[ui->work] = p->bg_vofs[1].value;
                    ui->sea_scroll_valid[ui->work] = 1u;
                } else if (ui->sea_hofs[ui->work] != p->bg_hofs[1].value ||
                           ui->sea_vofs[ui->work] != p->bg_vofs[1].value)
                    ui->sea_scroll_valid[ui->work] = 2u;
            }
            memset(p->port_ui->object_owner, 255, sizeof(p->port_ui->object_owner));
        }
        if(p->forced_blank!=0u||p->brightness==0u){
            memset(p->obj_line_palette,0,sizeof(p->obj_line_palette));
            memset(p->obj_line_rank,0,sizeof(p->obj_line_rank));
        }else{
            if(!reg8(p,5u,&bgmode)||!reg8(p,0x2Cu,&tm)||!reg8(p,0x2Du,&ts))
                return render_fail(p,(uint16_t)y);
            if(((tm|ts)&0x10u)!=0u){
                if(!prepare_objects(p,y,bgmode))return render_fail(p,(uint16_t)y);
            }else{
                memset(p->obj_line_palette,0,sizeof(p->obj_line_palette));
                memset(p->obj_line_rank,0,sizeof(p->obj_line_rank));
            }
        }
        for(x=0u;x<NH_PPU_FRAME_WIDTH;++x){
            NHPixel14 source;
            unsigned math_flags = 0u;
            NHPortUiCapture14 *ui = y < 224u ? p->port_ui : NULL;
            if(!render_pixel(p,&cache,x,y,&value,ui ? &source : NULL,ui ? &math_flags : NULL))
                return render_fail(p,(uint16_t)y);
            offset=y*NH_PPU_FRAME_WIDTH+x;p->work_frame[offset]=value;mark(p->work_known,offset);
            if (ui) {
                uint8_t mask = 0u;
                if (p->registers[5].value == 0x09u && !source.transparent && source.layer == 1u) {
                    unsigned mx = x, my = y, mosaic = p->registers[6].value;
                    unsigned tx, ty, fringe = 0u;
                    if ((mosaic & 2u) && (mosaic >> 4u)) {
                        unsigned span = (mosaic >> 4u) + 1u;
                        mx -= mx % span; my -= my % span;
                    }
                    if (mosaic == 0x22u && (mx != x || my != y)) {
                        unsigned origin = my * 256u + mx;
                        uint8_t covered = ui->masks[ui->work][origin];
                        /* The coarse sample precedes this pixel in raster
                         * order, so its real selected source is already
                         * captured. Qualify ONLY actual black BG3/backdrop
                         * coverage, not an assumed fixed eight-pixel crop.
                         * A3px block can expose an unstreamed gutter word
                         * at its visible edge during sub-tile scrolling. */
                        if ((covered == 0u || covered == 2u) &&
                            ui->pixels[ui->work][origin] == 0u) {
                            fringe = 1u;
                            ui->sea_mosaic_fringe[ui->work][offset >> 3u] |=
                                (uint8_t)(1u << (offset & 7u));
                        }
                    }
                    tx = ((mx + p->bg_hofs[1].value) >> 3u) & 31u;
                    ty = ((my + p->bg_vofs[1].value) >> 3u) & 31u;
                    unsigned cell = ty * 32u + tx;
                    uint8_t *seen = &ui->sea_bg2_seen[ui->work][cell];
                    if (!fringe) {
                        if (*seen && ui->sea_bg2_entry[ui->work][cell] != source.tile_entry) *seen = 2u;
                        else if (!*seen) { *seen = 1u; ui->sea_bg2_entry[ui->work][cell] = source.tile_entry; }
                    }
                }
                if (!source.transparent && source.layer == 0u) mask = 1u;
                else if (!source.transparent && source.layer == 2u) mask = 2u;
                else if (!source.transparent && source.layer == 4u &&
                    (ui->object_owner[x] < 112u || ui->object_owner[x] > 121u)) mask = 3u;
                ui->pixels[ui->work][offset] = value;
                ui->masks[ui->work][offset] = (uint8_t)(mask | ((math_flags & 3u) << 4u));
                if (!source.transparent && source.layer == 4u) {
                    ui->masks[ui->work][offset] |= 4u;
                    if (ui->object_owner[x] >= 80u && ui->object_owner[x] <= 119u)
                        ui->masks[ui->work][offset] |= 8u;
                    if ((p->registers[5].value == 0x29u &&
                         nh_ppu14_combat_world_object(p, ui->object_owner[x])) ||
                        nh_ppu14_sea_world_object(p, ui->object_owner[x]) ||
                        nh_ppu14_sea_marker_object(p, ui->object_owner[x]) ||
                        nh_ppu14_sea_mast_object(p, ui->object_owner[x]) ||
                        nh_ppu14_sea_destination_object(p, ui->object_owner[x]))
                        ui->masks[ui->work][offset] |= 0x80u;
                }
                if (p->registers[5].value == 0x09u && !source.transparent &&
                    (source.layer == 1u || (ui->masks[ui->work][offset] & 0x80u))) {
                    if (source.layer == 1u) ui->masks[ui->work][offset] |= 8u;
                    /* The raster receiver composes this whole line before
                     * guest execution resumes: registers/fixed color and
                     * brightness cannot change within this loop. The color
                     * observer depends on flags4/8 only. Check each actually
                     * selected combination once per line, still including
                     * clipped/subscreen cases and every later scanline. */
                    unsigned color_case = 1u << ((math_flags >> 2u) & 3u);
                    if (!(sea_color_seen & color_case)) {
                        sea_capture_color(p, ui, math_flags);
                        sea_color_seen |= color_case;
                    }
                }
                /* CD:0A7D..0ABA selects a 2x2 tactical-cell marker from the
                 * eleven groups at CD:CC65..CCBC. These BG1 fragments belong
                 * to the WORLD, not to a movable command/menu window. Keep
                 * Port's existing mask semantics unchanged in the low bits. */
                if (p->registers[5].value == 0x29u && !source.transparent && source.layer == 0u &&
                    source.tile_entry >= 0x3540u && source.tile_entry <= 0x356Bu)
                    ui->masks[ui->work][offset] |= 0x40u;
                /* CD:26DA fleet/index glyphs: priority1 BG3 tile360..369,
                 * palette selected by CD:CC34. These follow ships, not menus. */
                if (p->registers[5].value == 0x29u && !source.transparent && source.layer == 2u &&
                    (source.tile_entry & 0xE3FFu) >= 0x2360u &&
                    (source.tile_entry & 0xE3FFu) <= 0x2369u)
                    ui->masks[ui->work][offset] |= 0x40u;
                if (p->registers[5].value == 0x09u && !source.transparent &&
                    source.layer == 0u && !(source.tile_entry & 0x2000u))
                    ui->masks[ui->work][offset] |= 0x40u;
                if (mask) ui->tiles[ui->work][(y >> 3u) * 32u + (x >> 3u)] |=
                    (uint8_t)(1u << (mask - 1u));
                if ((mask && (math_flags & 2u)) || (!mask && (math_flags & 1u)))
                    ui->dependent_math[ui->work] = 1u;
                if (mask && (mask != 2u || x < 192u || (y >= 40u && y < 192u)))
                    ui->hud_only[ui->work] = 0u;
            }
        }
        if (p->port_ui && y < 224u) ++p->port_ui->lines;
        ++p->rendered_scanlines;
        /* Sample chart source at the completed visible raster boundary,
         * before VBLANK code may replace its registers. Double buffering
         * keeps the previous published projection immutable until publish. */
        if (p->port_ui && scheduler->scanline==height) {
            NHPortUiCapture14 *ui=p->port_ui;
            if (ui->chart_source_kind<=1u &&
                build_world_chart(p,ui->chart_source_kind,ui->chart_pixels[ui->work],
                                  512u*288u,p->work_frame,p->work_known,height)) {
                ui->chart_work_kind[ui->work]=ui->chart_source_kind;
                ui->chart_work_valid[ui->work]=1u;
            }
        }
    }
    if(event==NH_RASTER_VBLANK_BEGIN&&p->frame_published_this_vblank==0u){
        const uint32_t pixels=(uint32_t)height*NH_PPU_FRAME_WIDTH;
        memcpy(p->published_frame,p->work_frame,pixels*sizeof(uint16_t));
        memcpy(p->published_known,p->work_known,(pixels+7u)/8u);
        p->published_height=(uint16_t)height;++p->published_sequence;
        p->frame_ready=p->frame_published_this_vblank=1u;
        if (p->port_ui) {
            NHPortUiCapture14 *ui = p->port_ui;
            if (height != 224u || ui->lines != 224u) ui->valid[ui->work] = 0u;
            ui->published = ui->work; ui->sequence = p->published_sequence;
            ui->chart_valid=ui->chart_work_valid[ui->published];
            ui->chart_sequence=p->published_sequence;
            ui->chart_kind=ui->chart_work_kind[ui->published];
        }
    }
    return NH_BUS_OK;
}

int nh_ppu14_read_published_frame(const NHPPU11 *p,uint16_t *pixels,uint8_t *known_map,
                                  uint32_t capacity,uint16_t *width,uint16_t *height,
                                  uint64_t *sequence){
    uint32_t count;
    if(p==NULL||pixels==NULL||known_map==NULL||width==NULL||height==NULL||
       sequence==NULL||p->frame_ready==0u)return 0;
    count=(uint32_t)p->published_height*NH_PPU_FRAME_WIDTH;
    if(capacity<count)return 0;
    memcpy(pixels,p->published_frame,count*sizeof(uint16_t));
    memcpy(known_map,p->published_known,(count+7u)/8u);
    *width=NH_PPU_FRAME_WIDTH;*height=p->published_height;*sequence=p->published_sequence;
    return 1;
}
