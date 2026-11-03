#ifndef NEW_HORIZONS_INPUT_LATCH_H
#define NEW_HORIZONS_INPUT_LATCH_H

#include <stdint.h>

typedef struct NewHorizonsInputLatch {
    uint16_t held;
    uint16_t pending_press;
} NewHorizonsInputLatch;

void new_horizons_input_latch_reset(NewHorizonsInputLatch *latch);
void new_horizons_input_latch_press(NewHorizonsInputLatch *latch, uint16_t mask,
                           uint16_t unsampled_opposite_mask, int repeated);
void new_horizons_input_latch_release(NewHorizonsInputLatch *latch, uint16_t mask);
uint16_t new_horizons_input_latch_sample(const NewHorizonsInputLatch *latch);
void new_horizons_input_latch_consume(NewHorizonsInputLatch *latch, uint16_t sampled_mask);

#endif
