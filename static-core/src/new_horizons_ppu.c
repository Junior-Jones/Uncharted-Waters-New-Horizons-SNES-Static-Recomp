#include "new_horizons_ppu.h"

#include <string.h>

static int attached(const NHPPU11 *p) {
    return p != NULL && p->bus != NULL && p->scheduler != NULL &&
           p->wrio != NULL && p->scheduler->bus == p->bus;
}

static NHBusStop fail(NHPPU11 *p, NHBusStop reason, uint16_t reg,
                      NHBusValue byte) {
    if (attached(p) && p->bus->failure.reason == NH_BUS_OK) {
        p->bus->failure.reason = reason;
        p->bus->failure.owner = NH_OWNER_PPU_11;
        p->bus->failure.address = reg;
        p->bus->failure.value = byte.value;
        p->bus->failure.known_mask = byte.known_mask;
    }
    return reason;
}

static NHBusStop require_known(NHPPU11 *p, uint16_t reg, NHBusValue byte,
                               uint8_t *value) {
    if (byte.known_mask != 0xFFu) return fail(p, NH_BUS_UNKNOWN_BYTE, reg, byte);
    *value = byte.value;
    return NH_BUS_OK;
}

static int vram_accessible(const NHPPU11 *p) {
    return p->forced_blank != 0u || p->scheduler->vblank != 0u;
}

static int oam_accessible(const NHPPU11 *p) {
    return p->forced_blank != 0u || p->scheduler->vblank != 0u;
}

static int cgram_accessible(const NHPPU11 *p) {
    return p->forced_blank != 0u || p->scheduler->vblank != 0u ||
           p->scheduler->scanline == 0u || p->scheduler->hclock < 88u ||
           p->scheduler->hclock >= 1096u;
}

static NHBusStop latch_enabled(NHPPU11 *p, uint8_t *enabled) {
    const NHBusValue unknown = { 0u, 0u };
    if (p->wrio == NULL || (p->wrio->known_mask & 0x80u) == 0u)
        return fail(p, NH_BUS_UNKNOWN_BYTE, 0x4201u, unknown);
    *enabled = (uint8_t)((p->wrio->value >> 7u) & 1u);
    return NH_BUS_OK;
}

static uint16_t mapped_vram_word(const NHPPU11 *p) {
    const uint16_t a = p->vram_address;
    if (p->vram_remap == 1u)
        return (uint16_t)((a & 0xFF00u) | ((a & 0x001Fu) << 3u) | ((a >> 5u) & 7u));
    if (p->vram_remap == 2u)
        return (uint16_t)((a & 0xFE00u) | ((a & 0x003Fu) << 3u) | ((a >> 6u) & 7u));
    if (p->vram_remap == 3u)
        return (uint16_t)((a & 0xFC00u) | ((a & 0x007Fu) << 3u) | ((a >> 7u) & 7u));
    return a;
}

static void vram_reload(NHPPU11 *p) {
    const uint32_t a = (uint32_t)mapped_vram_word(p) << 1u;
    p->vram_read[0] = p->vram[a];
    p->vram_read[1] = p->vram[(a + 1u) & 0xFFFFu];
}

static void vram_advance(NHPPU11 *p) {
    p->vram_address = (uint16_t)((p->vram_address + p->vram_increment) & 0x7FFFu);
}

static uint16_t physical_oam(uint16_t a) {
    return a < 512u ? a : (uint16_t)(512u + (a & 31u));
}

static NHPPUWord latch_word(uint8_t low, uint8_t low_known, NHBusValue high) {
    NHPPUWord w;
    w.value = (uint16_t)(low | ((uint16_t)high.value << 8u));
    w.known_mask = (uint16_t)(low_known | ((uint16_t)high.known_mask << 8u));
    return w;
}

static void write_scroll(NHPPU11 *p, unsigned layer, int vertical,
                         NHBusValue byte) {
    NHPPUWord *target = vertical ? &p->bg_vofs[layer] : &p->bg_hofs[layer];
    if (vertical) {
        target->value = (uint16_t)((((uint16_t)byte.value << 8u) |
                                    p->scroll_latch) & 0x03FFu);
        target->known_mask = byte.known_mask == 0xFFu &&
                             p->scroll_latch_known == 0xFFu ? 0x03FFu : 0u;
    } else {
        target->value = (uint16_t)((((uint16_t)byte.value << 8u) |
                         (p->scroll_latch & 0xF8u) |
                         (p->hscroll_latch & 7u)) & 0x03FFu);
        target->known_mask = byte.known_mask == 0xFFu &&
                             p->scroll_latch_known == 0xFFu &&
                             p->hscroll_latch_known == 0xFFu ? 0x03FFu : 0u;
        p->hscroll_latch = byte.value;
        p->hscroll_latch_known = byte.known_mask;
    }
    p->scroll_latch = byte.value;
    p->scroll_latch_known = byte.known_mask;
}

static void reset_control(NHPPU11 *p) {
    memset(p->registers, 0, sizeof(p->registers));
    memset(p->bg_hofs, 0, sizeof(p->bg_hofs));
    memset(p->bg_vofs, 0, sizeof(p->bg_vofs));
    memset(p->mode7, 0, sizeof(p->mode7));
    p->mode7_hofs = p->mode7_vofs = (NHPPUWord){ 0u, 0u };
    p->registers[0] = (NHBusValue){ 0x80u, 0xFFu };
    p->forced_blank = 1u;
    p->brightness = 0u;
    p->vram_address = 0u;
    p->vram_increment = 1u;
    p->vram_remap = p->vram_increment_on_high = 0u;
    p->vram_read[0] = p->vram_read[1] = (NHBusValue){ 0u, 0u };
    p->oam_reload_address = p->oam_address = 0u;
    p->oam_latch = p->cgram_latch = (NHBusValue){ 0u, 0u };
    p->oam_latch_pending = p->cgram_address = p->cgram_second = 0u;
    p->scroll_latch = p->hscroll_latch = p->mode7_latch = 0u;
    p->scroll_latch_known = p->hscroll_latch_known = p->mode7_latch_known = 0u;
    p->counter_latched = p->hcounter_second = p->vcounter_second = 0u;
    p->latched_hcounter = p->latched_vcounter = 0u;
    p->ppu1_open_bus = p->ppu2_open_bus = (NHBusValue){ 0u, 0u };
    p->fixed_color = (NHPPUWord){ 0u, 0u };
    p->overscan = p->interlace = 0u;
    p->obj_range_over = p->obj_time_over = 0u;
    p->published_height = 0u;
    p->frame_ready = p->frame_published_this_vblank = 0u;
    memset(p->obj_line_palette, 0, sizeof(p->obj_line_palette));
    memset(p->obj_line_rank, 0, sizeof(p->obj_line_rank));
    p->scheduler->overscan = 0u;
    p->scheduler->interlace = 0u;
}

NHBusStop nh_ppu11_power_on(NHPPU11 *p, NHBusRuntime *bus,
                            NHScheduler *scheduler, const NHBusValue *wrio) {
    if (p == NULL || bus == NULL || scheduler == NULL || scheduler->bus != bus ||
        wrio == NULL)
        return NH_BUS_BAD_ARGUMENT;
    memset(p, 0, sizeof(*p));
    p->bus = bus;
    p->scheduler = scheduler;
    p->wrio = wrio;
    reset_control(p);
    return NH_BUS_OK;
}

NHBusStop nh_ppu11_apply_zero_storage_profile(NHPPU11 *p) {
    unsigned index;
    if (!attached(p) || p->storage_reads != 0u || p->storage_writes != 0u)
        return NH_BUS_BAD_ARGUMENT;
    for (index = 0u; index < NH_PPU_VRAM_BYTES; ++index)
        p->vram[index].known_mask = 0xFFu;
    for (index = 0u; index < NH_PPU_CGRAM_BYTES; ++index)
        p->cgram[index].known_mask = 0xFFu;
    for (index = 0u; index < NH_PPU_OAM_BYTES; ++index)
        p->oam[index].known_mask = 0xFFu;
    return NH_BUS_OK;
}

NHBusStop nh_ppu11_reset(NHPPU11 *p) {
    if (!attached(p)) return NH_BUS_BAD_ARGUMENT;
    /* CPU RESET is not PPU power-on. Like the mature Jungle Strike and
     * Rock n Roll Racing owners, preserve video registers/storage and force
     * blank. Clearing BGMODE/scroll/matrix here disagreed with the game's
     * retained WRAM shadows and produced an unintended Mode0 after restart. */
    p->forced_blank = 1u;
    p->counter_latched = p->hcounter_second = p->vcounter_second = 0u;
    p->frame_ready = 0u;
    p->published_height = 0u;
    p->render_failure_kind = p->render_failure_value = p->render_failure_known_mask = 0u;
    p->render_failure_address = 0u;
    return NH_BUS_OK;
}

static NHBusStop write_port(void *opaque, uint16_t reg, NHBusValue byte) {
    NHPPU11 *p = opaque;
    uint32_t a;
    uint8_t value;
    unsigned index;
    if (!attached(p) || reg < 0x2100u || reg > 0x213Fu) return NH_BUS_BAD_ARGUMENT;
    if (p->bus->failure.reason != NH_BUS_OK) return p->bus->failure.reason;
    ++p->register_writes[reg - 0x2100u];
    if (reg <= 0x2133u) p->registers[reg - 0x2100u] = byte;
    p->ppu1_open_bus = byte;
    switch (reg) {
        case 0x2100u:
            if (require_known(p, reg, byte, &value) != NH_BUS_OK) return p->bus->failure.reason;
            p->forced_blank = value >> 7u; p->brightness = value & 15u; break;
        case 0x2101u: case 0x2105u: case 0x2106u: case 0x2107u:
        case 0x2108u: case 0x2109u: case 0x210Au: case 0x210Bu:
        case 0x210Cu: case 0x2123u: case 0x2124u: case 0x2125u:
        case 0x2126u: case 0x2127u: case 0x2128u: case 0x2129u:
        case 0x212Au: case 0x212Bu: case 0x212Cu: case 0x212Du:
        case 0x212Eu: case 0x212Fu: case 0x2130u: case 0x2131u:
            if (require_known(p, reg, byte, &value) != NH_BUS_OK) return p->bus->failure.reason;
            break;
        case 0x2102u:
            if (require_known(p, reg, byte, &value) != NH_BUS_OK) return p->bus->failure.reason;
            p->oam_reload_address = (uint16_t)((p->oam_reload_address & 0x100u) | value);
            p->oam_address = (uint16_t)(p->oam_reload_address << 1u);
            p->oam_latch_pending = 0u; break;
        case 0x2103u:
            if (require_known(p, reg, byte, &value) != NH_BUS_OK) return p->bus->failure.reason;
            p->oam_reload_address = (uint16_t)((p->oam_reload_address & 0xFFu) |
                                      ((uint16_t)(value & 1u) << 8u));
            p->oam_address = (uint16_t)(p->oam_reload_address << 1u);
            p->oam_latch_pending = 0u; break;
        case 0x2104u:
            if (!oam_accessible(p)) return fail(p, NH_BUS_PPU_UNAVAILABLE, reg, byte);
            a = physical_oam(p->oam_address);
            if (p->oam_address < 512u && (p->oam_address & 1u) == 0u) {
                p->oam_latch = byte; p->oam_latch_pending = 1u;
            } else if (p->oam_address < 512u) {
                p->oam[a - 1u] = p->oam_latch; p->oam[a] = byte;
                p->storage_writes += 2u; p->oam_latch_pending = 0u;
            } else { p->oam[a] = byte; ++p->storage_writes; }
            p->oam_address = (uint16_t)((p->oam_address + 1u) & 0x03FFu); break;
        case 0x210Du: case 0x210Eu:
            {
                NHPPUWord word = latch_word(p->mode7_latch,
                                           p->mode7_latch_known, byte);
                word.value &= 0x1FFFu;
                word.known_mask &= 0x1FFFu;
                if (reg == 0x210Du) p->mode7_hofs = word;
                else p->mode7_vofs = word;
            }
            p->mode7_latch = byte.value; p->mode7_latch_known = byte.known_mask;
            write_scroll(p, 0u, reg == 0x210Eu, byte); break;
        case 0x210Fu: case 0x2110u: case 0x2111u: case 0x2112u:
        case 0x2113u: case 0x2114u:
            write_scroll(p, (unsigned)((reg - 0x210Du) / 2u),
                         (reg & 1u) == 0u, byte); break;
        case 0x2115u:
            if (require_known(p, reg, byte, &value) != NH_BUS_OK) return p->bus->failure.reason;
            p->vram_increment = (value & 3u) == 0u ? 1u :
                                (value & 3u) == 1u ? 32u : 128u;
            p->vram_remap = (uint8_t)((value >> 2u) & 3u);
            p->vram_increment_on_high = value >> 7u; break;
        case 0x2116u: case 0x2117u:
            if (require_known(p, reg, byte, &value) != NH_BUS_OK) return p->bus->failure.reason;
            if (reg == 0x2116u) p->vram_address = (uint16_t)((p->vram_address & 0x7F00u) | value);
            else p->vram_address = (uint16_t)((p->vram_address & 0x00FFu) |
                                      ((uint16_t)(value & 0x7Fu) << 8u));
            vram_reload(p); break;
        case 0x2118u: case 0x2119u:
            if (!vram_accessible(p)) return fail(p, NH_BUS_PPU_UNAVAILABLE, reg, byte);
            a = (((uint32_t)mapped_vram_word(p) << 1u) + (reg & 1u)) & 0xFFFFu;
            p->vram[a] = byte; ++p->storage_writes;
            if ((uint8_t)(reg == 0x2119u) == p->vram_increment_on_high) vram_advance(p);
            break;
        case 0x211Au:
            if (require_known(p, reg, byte, &value) != NH_BUS_OK) return p->bus->failure.reason;
            break;
        case 0x211Bu: case 0x211Cu: case 0x211Du: case 0x211Eu:
        case 0x211Fu: case 0x2120u:
            index = reg - 0x211Bu;
            p->mode7[index] = latch_word(p->mode7_latch, p->mode7_latch_known, byte);
            p->mode7_latch = byte.value; p->mode7_latch_known = byte.known_mask; break;
        case 0x2121u:
            if (require_known(p, reg, byte, &value) != NH_BUS_OK) return p->bus->failure.reason;
            p->cgram_address = value; p->cgram_second = 0u; break;
        case 0x2122u:
            if (p->cgram_second == 0u) { p->cgram_latch = byte; p->cgram_second = 1u; break; }
            if (!cgram_accessible(p)) return fail(p, NH_BUS_PPU_UNAVAILABLE, reg, byte);
            a = (uint32_t)p->cgram_address << 1u;
            p->cgram[a] = p->cgram_latch;
            p->cgram[a + 1u] = byte;
            p->cgram[a + 1u].value &= 0x7Fu;
            p->cgram[a + 1u].known_mask |= 0x80u;
            p->storage_writes += 2u; ++p->cgram_address; p->cgram_second = 0u; break;
        case 0x2132u:
            if (require_known(p, reg, byte, &value) != NH_BUS_OK) return p->bus->failure.reason;
            if ((value & 0x20u) != 0u) {
                p->fixed_color.value = (uint16_t)((p->fixed_color.value & 0x7FE0u) | (value & 0x1Fu));
                p->fixed_color.known_mask |= 0x001Fu;
            }
            if ((value & 0x40u) != 0u) {
                p->fixed_color.value = (uint16_t)((p->fixed_color.value & 0x7C1Fu) |
                                       ((uint16_t)(value & 0x1Fu) << 5u));
                p->fixed_color.known_mask |= 0x03E0u;
            }
            if ((value & 0x80u) != 0u) {
                p->fixed_color.value = (uint16_t)((p->fixed_color.value & 0x03FFu) |
                                       ((uint16_t)(value & 0x1Fu) << 10u));
                p->fixed_color.known_mask |= 0x7C00u;
            }
            break;
        case 0x2133u:
            if (require_known(p, reg, byte, &value) != NH_BUS_OK) return p->bus->failure.reason;
            p->overscan = (uint8_t)((value >> 2u) & 1u); p->interlace = value & 1u;
            p->scheduler->overscan = p->overscan; p->scheduler->interlace = p->interlace; break;
        default: break;
    }
    return NH_BUS_OK;
}

static NHBusStop read_port(void *opaque, uint16_t reg, NHDrivenByte *out) {
    NHPPU11 *p = opaque;
    NHBusValue byte = { 0u, 0u };
    uint32_t a;
    int32_t product;
    uint8_t enable;
    if (!attached(p) || out == NULL || reg < 0x2100u || reg > 0x213Fu)
        return NH_BUS_BAD_ARGUMENT;
    if (p->bus->failure.reason != NH_BUS_OK) return p->bus->failure.reason;
    ++p->register_reads[reg - 0x2100u];
    out->driven_mask = 0xFFu;
    switch (reg) {
        case 0x2134u: case 0x2135u: case 0x2136u:
            if (p->mode7[0].known_mask != 0xFFFFu ||
                (p->mode7[1].known_mask & 0xFF00u) != 0xFF00u)
                return fail(p, NH_BUS_UNKNOWN_BYTE, reg, byte);
            product = (int32_t)(int16_t)p->mode7[0].value *
                      (int32_t)(int8_t)(p->mode7[1].value >> 8u);
            byte.value = (uint8_t)((uint32_t)product >> (8u * (reg - 0x2134u)));
            byte.known_mask = 0xFFu; break;
        case 0x2137u:
            if (latch_enabled(p, &enable) != NH_BUS_OK) return p->bus->failure.reason;
            if (enable != 0u) {
                p->latched_hcounter = nh_scheduler_dot(p->scheduler);
                p->latched_vcounter = p->scheduler->scanline;
                p->counter_latched = 1u;
                p->hcounter_second = p->vcounter_second = 0u;
            }
            byte = p->ppu1_open_bus; out->driven_mask = 0u; break;
        case 0x2138u:
            if (!oam_accessible(p)) return fail(p, NH_BUS_PPU_UNAVAILABLE, reg, byte);
            a = physical_oam(p->oam_address); byte = p->oam[a];
            p->oam_address = (uint16_t)((p->oam_address + 1u) & 0x03FFu);
            ++p->storage_reads; break;
        case 0x2139u: case 0x213Au:
            if (!vram_accessible(p)) return fail(p, NH_BUS_PPU_UNAVAILABLE, reg, byte);
            byte = p->vram_read[reg - 0x2139u];
            if ((uint8_t)(reg == 0x213Au) == p->vram_increment_on_high) {
                /* Refill at the current word before incrementing VMADD.
                 * The target's dummy read then exposes that same word to the
                 * first real low/high read, rather than skipping one word. */
                vram_reload(p); vram_advance(p);
            }
            ++p->storage_reads; break;
        case 0x213Bu:
            if (!cgram_accessible(p)) return fail(p, NH_BUS_PPU_UNAVAILABLE, reg, byte);
            a = ((uint32_t)p->cgram_address << 1u) | p->cgram_second;
            byte = p->cgram[a];
            if (p->cgram_second != 0u) {
                byte.value = (uint8_t)((byte.value & 0x7Fu) | (p->ppu2_open_bus.value & 0x80u));
                byte.known_mask = (uint8_t)((byte.known_mask & 0x7Fu) |
                                  (p->ppu2_open_bus.known_mask & 0x80u));
                ++p->cgram_address;
            }
            p->cgram_second ^= 1u; ++p->storage_reads; break;
        case 0x213Cu:
            if (p->counter_latched == 0u) p->latched_hcounter = nh_scheduler_dot(p->scheduler);
            byte.value = p->hcounter_second == 0u ? (uint8_t)p->latched_hcounter :
                         (uint8_t)(((p->latched_hcounter >> 8u) & 1u) |
                                   (p->ppu2_open_bus.value & 0xFEu));
            byte.known_mask = p->hcounter_second == 0u ? 0xFFu :
                              (uint8_t)(1u | (p->ppu2_open_bus.known_mask & 0xFEu));
            out->driven_mask = 0xFFu; p->hcounter_second ^= 1u; break;
        case 0x213Du:
            if (p->counter_latched == 0u) p->latched_vcounter = p->scheduler->scanline;
            byte.value = p->vcounter_second == 0u ? (uint8_t)p->latched_vcounter :
                         (uint8_t)(((p->latched_vcounter >> 8u) & 1u) |
                                   (p->ppu2_open_bus.value & 0xFEu));
            byte.known_mask = p->vcounter_second == 0u ? 0xFFu :
                              (uint8_t)(1u | (p->ppu2_open_bus.known_mask & 0xFEu));
            out->driven_mask = 0xFFu; p->vcounter_second ^= 1u; break;
        case 0x213Eu:
            byte.value = (uint8_t)(1u | (p->ppu1_open_bus.value & 0x10u) |
                         (p->obj_range_over << 6u) | (p->obj_time_over << 7u));
            byte.known_mask = (uint8_t)(0xC1u | (p->ppu1_open_bus.known_mask & 0x10u));
            out->driven_mask = 0xFFu; break;
        case 0x213Fu:
            byte.value = (uint8_t)(3u | (p->ppu2_open_bus.value & 0x20u) |
                         (p->counter_latched << 6u) | (p->scheduler->field << 7u));
            byte.known_mask = (uint8_t)(0xC3u | (p->ppu2_open_bus.known_mask & 0x20u));
            out->driven_mask = 0xFFu;
            if (latch_enabled(p, &enable) != NH_BUS_OK) return p->bus->failure.reason;
            if (enable != 0u) p->counter_latched = 0u;
            p->hcounter_second = p->vcounter_second = 0u; break;
        default:
            {
                const uint16_t mirror = (uint16_t)(reg & 0x210Fu);
                if ((mirror >= 0x2104u && mirror <= 0x2106u) ||
                    (mirror >= 0x2108u && mirror <= 0x210Au)) {
                    byte = p->ppu1_open_bus;
                    out->driven_mask = 0xFFu;
                } else {
                    byte = (NHBusValue){ 0u, 0u };
                    out->driven_mask = 0u;
                }
            }
            break;
    }
    if (reg <= 0x213Au) p->ppu1_open_bus = byte; else p->ppu2_open_bus = byte;
    out->value = byte.value; out->known_mask = byte.known_mask;
    return NH_BUS_OK;
}

NHRegisterPort nh_ppu11_register_port(NHPPU11 *p) {
    const NHRegisterPort port = { p, read_port, write_port };
    return port;
}

static NHBusStop sync_smp(void *opaque, NHBusRuntime *bus, uint64_t target) {
    NHPPU11 *p = opaque;
    if (!attached(p) || p->bus != bus) return NH_BUS_BAD_ARGUMENT;
    return p->downstream.smp_sync(p->downstream.opaque, bus, target);
}

static NHBusStop raster(void *opaque, NHBusRuntime *bus,
                        const NHScheduler *scheduler, NHRasterEvent event) {
    NHPPU11 *p = opaque;
    NHBusStop status = nh_ppu11_raster_event(p, bus, scheduler, event);
    return status == NH_BUS_OK ?
        p->downstream.raster_event(p->downstream.opaque, bus, scheduler, event) :
        status;
}

static NHBusStop boundary(void *opaque, NHBusRuntime *bus,
                          const NHScheduler *scheduler, uint8_t kind,
                          uint32_t address, uint8_t clocks) {
    NHPPU11 *p = opaque;
    if (!attached(p) || p->bus != bus || p->scheduler != scheduler)
        return NH_BUS_BAD_ARGUMENT;
    return p->downstream.cpu_boundary(p->downstream.opaque, bus, scheduler,
                                      kind, address, clocks);
}

NHBusStop nh_ppu11_bind(NHPPU11 *p) {
    if (!attached(p) || p->bus->ports.ppu.read != NULL ||
        p->bus->ports.ppu.write != NULL || p->scheduler->advancing != 0u ||
        p->scheduler->master_clock != 0u || p->scheduler->receivers.opaque == p ||
        p->scheduler->receivers.smp_sync == NULL ||
        p->scheduler->receivers.raster_event == NULL ||
        p->scheduler->receivers.cpu_boundary == NULL) return NH_BUS_BAD_ARGUMENT;
    p->downstream = p->scheduler->receivers;
    p->bus->ports.ppu = nh_ppu11_register_port(p);
    p->scheduler->receivers.opaque = p;
    p->scheduler->receivers.smp_sync = sync_smp;
    p->scheduler->receivers.raster_event = raster;
    p->scheduler->receivers.cpu_boundary = boundary;
    return NH_BUS_OK;
}

NHBusStop nh_ppu11_raster_event(NHPPU11 *p, NHBusRuntime *bus,
                                const NHScheduler *scheduler,
                                NHRasterEvent event) {
    if (!attached(p) || p->bus != bus || p->scheduler != scheduler)
        return NH_BUS_BAD_ARGUMENT;
    if (bus->failure.reason != NH_BUS_OK) return bus->failure.reason;
    if (event == NH_RASTER_VBLANK_BEGIN && p->forced_blank == 0u) {
        p->oam_address = (uint16_t)(p->oam_reload_address << 1u);
        p->oam_latch_pending = 0u;
    } else if (event == NH_RASTER_VBLANK_END) {
        p->obj_range_over = 0u;
        p->obj_time_over = 0u;
    }
    return nh_ppu14_raster_event(p, bus, scheduler, event);
}
