#include "new_horizons_input.h"

#include <string.h>

static int attached(const NHInput15 *in) {
    return in != NULL && in->bus != NULL && in->scheduler != NULL &&
           in->scheduler->bus == in->bus;
}

static uint8_t mouse_axis(int16_t value) {
    uint16_t magnitude;
    if (value < 0) {
        magnitude = (uint16_t)(-(int32_t)value);
        if (magnitude > 0x7Fu) magnitude = 0x7Fu;
        return (uint8_t)(0x80u | magnitude);
    }
    magnitude = (uint16_t)value;
    if (magnitude > 0x7Fu) magnitude = 0x7Fu;
    return (uint8_t)magnitude;
}

static void latch_port(NHInput15 *in, unsigned port) {
    if (in->device[port] == NH_INPUT_DEVICE_SNES_MOUSE) {
        const uint16_t header = (uint16_t)(
            0x0001u | ((uint16_t)in->mouse_sensitivity[port] << 4u) |
            ((uint16_t)(in->live_mouse_buttons[port] & 3u) << 6u));
        in->serial_shift[port] = ((uint32_t)header << 16u) |
            ((uint32_t)mouse_axis(in->live_mouse_y[port]) << 8u) |
            mouse_axis(in->live_mouse_x[port]);
    } else {
        in->serial_shift[port] = ((uint32_t)in->live_pad[port] << 16u) | 0xFFFFu;
    }
}

static void latch(NHInput15 *in) {
    latch_port(in, 0u);
    latch_port(in, 1u);
}

static void update_strobe(NHInput15 *in) {
    in->effective_strobe = (uint8_t)((in->cpu_strobe | in->auto_strobe) & 1u);
    if (in->effective_strobe != 0u) latch(in);
}

static uint8_t serial_bit(NHInput15 *in, unsigned port) {
    uint8_t bit;
    if (in->effective_strobe != 0u) {
        if (in->device[port] == NH_INPUT_DEVICE_SNES_MOUSE)
            in->mouse_sensitivity[port] =
                (uint8_t)((in->mouse_sensitivity[port] + 1u) % 3u);
        latch_port(in, port);
    }
    bit = (uint8_t)((in->serial_shift[port] >> 31u) & 1u);
    if (in->effective_strobe == 0u)
        in->serial_shift[port] = (in->serial_shift[port] << 1u) | 1u;
    ++in->serial_reads[port];
    return bit;
}

NHBusStop nh_input15_power_on(NHInput15 *in, NHBusRuntime *bus,
                              NHScheduler *scheduler) {
    if (in == NULL || bus == NULL || scheduler == NULL || scheduler->bus != bus ||
        bus->memory.verified_rom == NULL || bus->memory.rom_size != NH_ROM_BYTES)
        return NH_BUS_BAD_ARGUMENT;
    memset(in, 0, sizeof(*in));
    in->bus = bus;
    in->scheduler = scheduler;
    latch(in);
    return NH_BUS_OK;
}

NHBusStop nh_input15_cpu_reset(NHInput15 *in) {
    uint16_t live_pad[2];
    int16_t live_mouse_x[2], live_mouse_y[2];
    uint8_t device[2], live_mouse_buttons[2], mouse_sensitivity[2];
    uint64_t sequence;
    NHBusRuntime *bus;
    NHScheduler *scheduler;
    if (!attached(in) || in->scheduler->autojoy_active != 0u)
        return NH_BUS_BAD_ARGUMENT;
    if (in->bus->failure.reason != NH_BUS_OK) return in->bus->failure.reason;
    bus = in->bus;
    scheduler = in->scheduler;
    memcpy(device, in->device, sizeof(device));
    memcpy(live_pad, in->live_pad, sizeof(live_pad));
    memcpy(live_mouse_x, in->live_mouse_x, sizeof(live_mouse_x));
    memcpy(live_mouse_y, in->live_mouse_y, sizeof(live_mouse_y));
    memcpy(live_mouse_buttons, in->live_mouse_buttons,
           sizeof(live_mouse_buttons));
    memcpy(mouse_sensitivity, in->mouse_sensitivity,
           sizeof(mouse_sensitivity));
    sequence = in->report_sequence;
    memset(in, 0, sizeof(*in));
    in->bus = bus;
    in->scheduler = scheduler;
    memcpy(in->device, device, sizeof(device));
    memcpy(in->live_pad, live_pad, sizeof(live_pad));
    memcpy(in->live_mouse_x, live_mouse_x, sizeof(live_mouse_x));
    memcpy(in->live_mouse_y, live_mouse_y, sizeof(live_mouse_y));
    memcpy(in->live_mouse_buttons, live_mouse_buttons,
           sizeof(live_mouse_buttons));
    memcpy(in->mouse_sensitivity, mouse_sensitivity,
           sizeof(mouse_sensitivity));
    in->report_sequence = sequence;
    latch(in);
    return NH_BUS_OK;
}

NHBusStop nh_input15_set_standard_pad(NHInput15 *in, unsigned port,
                                      uint16_t state) {
    if (!attached(in) || port >= 2u) return NH_BUS_BAD_ARGUMENT;
    if (in->bus->failure.reason != NH_BUS_OK) return in->bus->failure.reason;
    in->device[port] = NH_INPUT_DEVICE_STANDARD_PAD;
    in->live_pad[port] = (uint16_t)(state & NH_INPUT_STANDARD_PAD_MASK);
    ++in->report_sequence;
    if (in->effective_strobe != 0u) latch(in);
    return NH_BUS_OK;
}

NHBusStop nh_input15_set_snes_mouse(NHInput15 *in, unsigned port,
                                    uint8_t buttons, int16_t delta_x,
                                    int16_t delta_y) {
    if (!attached(in) || port >= 2u || (buttons & ~3u) != 0u)
        return NH_BUS_BAD_ARGUMENT;
    if (in->bus->failure.reason != NH_BUS_OK) return in->bus->failure.reason;
    in->device[port] = NH_INPUT_DEVICE_SNES_MOUSE;
    in->live_mouse_buttons[port] = buttons;
    in->live_mouse_x[port] = delta_x;
    in->live_mouse_y[port] = delta_y;
    ++in->report_sequence;
    if (in->effective_strobe != 0u) latch_port(in, port);
    return NH_BUS_OK;
}

uint16_t nh_input15_auto_result(const NHInput15 *in, unsigned index) {
    return attached(in) && index < 4u ? in->auto_result[index] : 0u;
}

static NHBusStop read_port(void *opaque, uint16_t reg, NHDrivenByte *byte) {
    NHInput15 *in = opaque;
    if (!attached(in) || byte == NULL) return NH_BUS_BAD_ARGUMENT;
    if (in->bus->failure.reason != NH_BUS_OK) return in->bus->failure.reason;
    if (reg >= 0x4218u && reg <= 0x421Fu) {
        const unsigned index = (unsigned)((reg - 0x4218u) >> 1u);
        const uint16_t result = in->auto_result[index];
        byte->value = (uint8_t)(((reg & 1u) != 0u) ? (result >> 8u) : result);
        byte->driven_mask = 0xFFu;
        byte->known_mask = 0xFFu;
        return NH_BUS_OK;
    }
    if (reg == 0x4016u) {
        byte->value = serial_bit(in, 0u);
        /* Both controller data lines are driven; the selected standard pad
         * occupies data1 and the absent expansion/multitap line reads zero. */
        byte->driven_mask = 0x03u;
        byte->known_mask = 0x03u;
        return NH_BUS_OK;
    }
    if (reg == 0x4017u) {
        /* Port2 serial data drives bit0; bits2..4 are the fixed controller-
         * port status signature. Remaining bits retain the CPU open bus. */
        byte->value = (uint8_t)(0x1Cu | serial_bit(in, 1u));
        byte->driven_mask = 0x1Fu;
        byte->known_mask = 0x1Fu;
        return NH_BUS_OK;
    }
    return NH_BUS_INPUT_UNAVAILABLE;
}

static NHBusStop write_port(void *opaque, uint16_t reg, NHBusValue byte) {
    NHInput15 *in = opaque;
    if (!attached(in)) return NH_BUS_BAD_ARGUMENT;
    if (in->bus->failure.reason != NH_BUS_OK) return in->bus->failure.reason;
    if (reg != 0x4016u) return NH_BUS_INPUT_UNAVAILABLE;
    if ((byte.known_mask & 1u) == 0u) return NH_BUS_UNKNOWN_BYTE;
    in->cpu_strobe = (uint8_t)(byte.value & 1u);
    update_strobe(in);
    return NH_BUS_OK;
}

NHRegisterPort nh_input15_register_port(NHInput15 *in) {
    NHRegisterPort port = { in, read_port, write_port };
    return port;
}

static NHBusStop autojoy_phase(void *opaque, NHBusRuntime *bus,
                               uint64_t master_clock, uint8_t phase,
                               uint8_t enabled) {
    NHInput15 *in = opaque;
    unsigned port;
    (void)master_clock;
    if (!attached(in) || in->bus != bus || phase > 34u)
        return NH_BUS_BAD_ARGUMENT;
    if (enabled == 0u) {
        in->auto_strobe = 0u;
        update_strobe(in);
        return NH_BUS_OK;
    }
    if (phase == 0u) {
        in->auto_strobe = 1u;
        update_strobe(in);
    } else if (phase == 1u) {
        memset(in->auto_result, 0, sizeof(in->auto_result));
        memset(in->sampled_serial, 0, sizeof(in->sampled_serial));
    } else if (phase == 2u) {
        in->auto_strobe = 0u;
        update_strobe(in);
    } else if (phase >= 3u) {
        if ((phase & 1u) != 0u) {
            in->sampled_serial[0] = serial_bit(in, 0u);
            in->sampled_serial[1] = serial_bit(in, 1u);
            in->sampled_serial[2] = 0u;
            in->sampled_serial[3] = 0u;
            ++in->autojoy_samples;
        } else {
            for (port = 0u; port < 4u; ++port)
                in->auto_result[port] = (uint16_t)((in->auto_result[port] << 1u) |
                                                   (in->sampled_serial[port] & 1u));
        }
    }
    return NH_BUS_OK;
}

static NHBusStop autojoy_abort(void *opaque, NHBusRuntime *bus,
                               uint64_t master_clock) {
    NHInput15 *in = opaque;
    (void)master_clock;
    if (!attached(in) || in->bus != bus) return NH_BUS_BAD_ARGUMENT;
    in->auto_strobe = 0u;
    update_strobe(in);
    return NH_BUS_OK;
}

NHAutoJoyPort nh_input15_autojoy_port(NHInput15 *in) {
    NHAutoJoyPort port = { in, autojoy_phase, autojoy_abort };
    return port;
}

NHBusStop nh_input15_bind(NHInput15 *in) {
    NHBusStop status;
    if (!attached(in) || in->bus->failure.reason != NH_BUS_OK ||
        in->scheduler->advancing != 0u || in->scheduler->master_clock != 0u ||
        in->scheduler->autojoy_active != 0u ||
        in->bus->ports.input.read != NULL || in->bus->ports.input.write != NULL ||
        in->scheduler->autojoy.phase != NULL || in->scheduler->autojoy.abort != NULL)
        return NH_BUS_BAD_ARGUMENT;
    status = nh_scheduler_autojoy_bind(in->scheduler, nh_input15_autojoy_port(in));
    if (status != NH_BUS_OK) return status;
    in->bus->ports.input = nh_input15_register_port(in);
    return NH_BUS_OK;
}
