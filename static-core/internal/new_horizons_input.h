#ifndef NEW_HORIZONS_INPUT_H
#define NEW_HORIZONS_INPUT_H

#include "new_horizons_scheduler.h"

enum { NH_INPUT_STANDARD_PAD_MASK = 0xFFF0u };

typedef enum NHInputDevice15 {
    NH_INPUT_DEVICE_STANDARD_PAD = 0,
    NH_INPUT_DEVICE_SNES_MOUSE = 1
} NHInputDevice15;

typedef struct NHInput15 {
    NHBusRuntime *bus;
    NHScheduler *scheduler;
    uint8_t device[2];
    uint16_t live_pad[2];
    int16_t live_mouse_x[2];
    int16_t live_mouse_y[2];
    uint8_t live_mouse_buttons[2];
    uint8_t mouse_sensitivity[2];
    uint32_t serial_shift[2];
    uint16_t auto_result[4];
    uint8_t sampled_serial[4];
    uint8_t cpu_strobe;
    uint8_t auto_strobe;
    uint8_t effective_strobe;
    uint64_t serial_reads[2];
    uint64_t autojoy_samples;
    uint64_t report_sequence;
} NHInput15;

/* State uses the native JOY register layout: B at bit15 through R at bit4.
 * This is the host-to-pin boundary only; it does not write guest RAM or JOY
 * result registers immediately. The next hardware latch observes live_pad. */
NHBusStop nh_input15_power_on(NHInput15 *, NHBusRuntime *, NHScheduler *);
NHBusStop nh_input15_bind(NHInput15 *);
NHBusStop nh_input15_cpu_reset(NHInput15 *);
NHBusStop nh_input15_set_standard_pad(NHInput15 *, unsigned port, uint16_t state);
NHBusStop nh_input15_set_snes_mouse(NHInput15 *, unsigned port, uint8_t buttons,
                                    int16_t delta_x, int16_t delta_y);
uint16_t nh_input15_auto_result(const NHInput15 *, unsigned index);
NHRegisterPort nh_input15_register_port(NHInput15 *);
NHAutoJoyPort nh_input15_autojoy_port(NHInput15 *);

#endif
