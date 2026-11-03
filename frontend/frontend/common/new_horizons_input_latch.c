#include "new_horizons_input_latch.h"

#include <stddef.h>

void new_horizons_input_latch_reset(NewHorizonsInputLatch *latch)
{
    if (!latch) return;
    latch->held = 0u;
    latch->pending_press = 0u;
}

void new_horizons_input_latch_press(NewHorizonsInputLatch *latch, uint16_t mask,
                           uint16_t unsampled_opposite_mask, int repeated)
{
    if (!latch || mask == 0u) return;
    latch->held = (uint16_t)(latch->held | mask);
    if (repeated) return;

    /* A new direction supersedes an opposite tap that the guest has not seen.
       Do not clear held state: simultaneously held physical directions remain
       an honest neutral/opposed controller state. */
    latch->pending_press = (uint16_t)(
        latch->pending_press & (uint16_t)~unsampled_opposite_mask);
    latch->pending_press = (uint16_t)(latch->pending_press | mask);
}

void new_horizons_input_latch_release(NewHorizonsInputLatch *latch, uint16_t mask)
{
    if (!latch) return;
    latch->held = (uint16_t)(latch->held & (uint16_t)~mask);
}

uint16_t new_horizons_input_latch_sample(const NewHorizonsInputLatch *latch)
{
    return latch ? (uint16_t)(latch->held | latch->pending_press) : 0u;
}

void new_horizons_input_latch_consume(NewHorizonsInputLatch *latch, uint16_t sampled_mask)
{
    if (!latch) return;
    latch->pending_press = (uint16_t)(
        latch->pending_press & (uint16_t)~sampled_mask);
}
