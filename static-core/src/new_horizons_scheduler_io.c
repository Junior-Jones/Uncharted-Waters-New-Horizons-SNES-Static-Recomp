#include "new_horizons_scheduler.h"

void nh_scheduler_update_nmi_line(NHScheduler *scheduler) {
    const uint8_t next = (uint8_t)(scheduler->nmi_flag != 0u &&
                                     (scheduler->nmitimen & 0x80u) != 0u);
    if (next != 0u && scheduler->nmi_line == 0u) scheduler->nmi_edge_latched = 1u;
    scheduler->nmi_line = next;
}

NHBusStop nh_scheduler_irq_match(const NHScheduler *scheduler, uint8_t *match) {
    uint8_t mode;
    if (scheduler == NULL || match == NULL) return NH_BUS_BAD_ARGUMENT;
    mode = (uint8_t)((scheduler->nmitimen >> 4u) & 3u);
    *match = 0u;
    if (mode == 0u) return NH_BUS_OK;
    if ((mode & 2u) != 0u) {
        if (scheduler->vtime_known != 0x1FFu) return NH_BUS_UNKNOWN_BYTE;
        if (scheduler->irq_vcounter != scheduler->vtime) return NH_BUS_OK;
    }
    if ((mode & 1u) != 0u) {
        if (scheduler->htime_known != 0x1FFu) return NH_BUS_UNKNOWN_BYTE;
        if (scheduler->irq_hcounter != scheduler->htime) return NH_BUS_OK;
    }
    *match = 1u;
    return NH_BUS_OK;
}

static NHBusStop irq_compare_changed(NHScheduler *scheduler) {
    uint8_t match;
    const NHBusStop status = nh_scheduler_irq_match(scheduler, &match);
    if (status != NH_BUS_OK) return status;
    if (match != 0u && scheduler->irq_level == 0u)
        scheduler->irq_wait_ticks = (uint8_t)(
            (scheduler->nmitimen & 0x10u) != 0u && scheduler->hclock == 6u ? 3u : 2u);
    scheduler->irq_level = match;
    return NH_BUS_OK;
}

NHBusStop nh_scheduler_irq_tick(NHScheduler *scheduler) {
    NHBusStop status;
    if ((scheduler->hclock & 3u) != 2u ||
        (scheduler->irq_phase_valid != 0u &&
         scheduler->irq_phase_clock == scheduler->master_clock)) return NH_BUS_OK;
    scheduler->irq_phase_valid = 1u;
    scheduler->irq_phase_clock = scheduler->master_clock;
    if (scheduler->irq_wait_ticks != 0u) {
        --scheduler->irq_wait_ticks;
        if (scheduler->irq_wait_ticks == 1u) {
            scheduler->irq_flag = 1u;
            scheduler->irq_flag_known = 1u;
            scheduler->irq_assert_clock = scheduler->master_clock;
        } else if (scheduler->irq_wait_ticks == 0u) {
            scheduler->irq_line = scheduler->irq_flag;
            if (scheduler->irq_line != 0u) {
                status = scheduler->receivers.raster_event(scheduler->receivers.opaque,
                    scheduler->bus, scheduler, NH_RASTER_IRQ_ASSERT);
                if (scheduler->bus->failure.reason != NH_BUS_OK)
                    return scheduler->bus->failure.reason;
                if (status != NH_BUS_OK) return status;
            }
        }
    }
    if (scheduler->hclock > 10u)
        scheduler->irq_hcounter = (uint16_t)((scheduler->irq_hcounter + 1u) & 0x1FFu);
    else if (scheduler->hclock == 10u) scheduler->irq_hcounter = 0u;
    else if (scheduler->hclock == 6u) {
        scheduler->irq_hcounter = 0u;
        if (scheduler->scanline != 0u)
            scheduler->irq_vcounter = (uint16_t)((scheduler->irq_vcounter + 1u) & 0x1FFu);
    } else {
        scheduler->irq_hcounter = (uint16_t)((scheduler->irq_hcounter + 1u) & 0x1FFu);
        if (scheduler->scanline == 0u) scheduler->irq_vcounter = 0u;
    }
    return irq_compare_changed(scheduler);
}

static NHBusStop read_register(void *opaque, uint16_t reg, NHDrivenByte *byte) {
    NHScheduler *scheduler = opaque;
    if (scheduler == NULL || byte == NULL) return NH_BUS_BAD_ARGUMENT;
    if (scheduler->bus->failure.reason != NH_BUS_OK) return scheduler->bus->failure.reason;
    byte->value = 0u;
    byte->driven_mask = 0u;
    byte->known_mask = 0u;
    switch (reg) {
        case 0x4210u:
            byte->value = (uint8_t)((scheduler->nmi_flag != 0u ? 0x80u : 0u) | NH_NTSC_CPU_VERSION_REFERENCE);
            byte->driven_mask = 0x8Fu;
            byte->known_mask = 0x8Fu;
            if (scheduler->scanline != (scheduler->overscan != 0u ? 240u : 225u) ||
                scheduler->hclock >= 6u) {
                scheduler->nmi_flag = 0u;
                nh_scheduler_update_nmi_line(scheduler);
            }
            return NH_BUS_OK;
        case 0x4211u: {
            /* TIMEUP reports the on-chip H/V timer, not the combined CPU
             * /IRQ input. Reading it must not report or acknowledge a cart/
             * expansion IRQ; that separate line still participates in poll. */
            byte->value = (uint8_t)(scheduler->irq_flag_known != 0u &&
                                   scheduler->irq_flag != 0u ? 0x80u : 0u);
            byte->driven_mask = 0x80u;
            byte->known_mask = scheduler->irq_flag_known != 0u ? 0x80u : 0u;
            /* Pending delivery stages own acknowledgement hold, not an
             * unrelated guessed elapsed-time interval. */
            if (scheduler->irq_wait_ticks == 0u) {
                scheduler->irq_flag = 0u;
                scheduler->irq_flag_known = 1u;
                scheduler->irq_line = 0u;
            }
            return NH_BUS_OK;
        }
        case 0x4212u:
            byte->value = (uint8_t)((scheduler->vblank != 0u ? 0x80u : 0u) |
                                    (scheduler->hblank != 0u ? 0x40u : 0u) |
                                    (scheduler->autojoy_busy != 0u ? 1u : 0u));
            byte->driven_mask = 0xC1u;
            byte->known_mask = 0xC1u;
            return NH_BUS_OK;
        case 0x4200u: case 0x4207u: case 0x4208u: case 0x4209u: case 0x420Au:
            return NH_BUS_OK; /* write-only: ordinary08 undriven bits */
        default: return NH_BUS_UNPROVED_REGISTER;
    }
}

static NHBusStop write_register(void *opaque, uint16_t reg, NHBusValue byte) {
    NHScheduler *scheduler = opaque;
    uint8_t consumed;
    if (scheduler == NULL) return NH_BUS_BAD_ARGUMENT;
    if (scheduler->bus->failure.reason != NH_BUS_OK) return scheduler->bus->failure.reason;
    consumed = reg == 0x4200u ? 0xB1u : (reg == 0x4208u || reg == 0x420Au) ? 1u : 0xFFu;
    if (reg >= 0x4210u && reg <= 0x4212u) return NH_BUS_OK;
    if (reg != 0x4200u && (reg < 0x4207u || reg > 0x420Au)) return NH_BUS_UNPROVED_REGISTER;
    if ((byte.known_mask & consumed) != consumed) return NH_BUS_UNKNOWN_BYTE;
    switch (reg) {
        case 0x4200u: {
            const uint8_t old_nmi_enable = scheduler->nmitimen & 0x80u;
            scheduler->nmitimen = byte.value & 0xB1u;
            if ((byte.value & 0x30u) == 0u) {
                scheduler->irq_flag = 0u;
                scheduler->irq_flag_known = 1u;
                scheduler->irq_line = 0u;
                scheduler->irq_level = 0u;
                scheduler->irq_wait_ticks = 0u;
            }
            /* Only an enable transition requests the late-enable edge.
             * An unchanged enabled bit before normal H6 is not an edge. */
            if ((scheduler->nmitimen & 0x80u) == 0u || old_nmi_enable == 0u)
                nh_scheduler_update_nmi_line(scheduler);
            /* The scheduled autojoy phase samples the committed enable.
             * A register write is not a fabricated serial-clock event. */
            break;
        }
        case 0x4207u:
            scheduler->htime = (uint16_t)((scheduler->htime & 0x100u) | byte.value);
            scheduler->htime_known |= 0xFFu;
            break;
        case 0x4208u:
            scheduler->htime = (uint16_t)((scheduler->htime & 0xFFu) | ((uint16_t)(byte.value & 1u) << 8u));
            scheduler->htime_known |= 0x100u;
            break;
        case 0x4209u:
            scheduler->vtime = (uint16_t)((scheduler->vtime & 0x100u) | byte.value);
            scheduler->vtime_known |= 0xFFu;
            break;
        case 0x420Au:
            scheduler->vtime = (uint16_t)((scheduler->vtime & 0xFFu) | ((uint16_t)(byte.value & 1u) << 8u));
            scheduler->vtime_known |= 0x100u;
            break;
        default: return NH_BUS_UNPROVED_REGISTER;
    }
    return irq_compare_changed(scheduler);
}

NHRegisterPort nh_scheduler_register_port(NHScheduler *scheduler) {
    const NHRegisterPort port = { scheduler, read_register, write_register };
    return port;
}

NHBusStop nh_scheduler_take_interrupt(NHScheduler *scheduler, uint8_t *interrupt) {
    if (scheduler == NULL || interrupt == NULL) return NH_BUS_BAD_ARGUMENT;
    if (scheduler->bus->failure.reason != NH_BUS_OK) return scheduler->bus->failure.reason;
    if (scheduler->poll_valid == 0u) return NH_BUS_CLOCK_UNAVAILABLE;
    *interrupt = scheduler->polled_interrupt;
    if (*interrupt == 1u) scheduler->nmi_pending = 0u;
    scheduler->poll_valid = 0u;
    scheduler->polled_interrupt = 0u;
    return NH_BUS_OK;
}
