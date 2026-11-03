#include <stdio.h>

#include "new_horizons_core.h"
#include "new_horizons_input_latch.h"
#include "new_horizons_static_recomp.h"

#define CHECK(expression) do { \
    if (!(expression)) { \
        fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #expression); \
        return 1; \
    } \
} while (0)

int main(void)
{
    static const uint16_t frontend[] = {
        NEW_HORIZONS_INPUT_B, NEW_HORIZONS_INPUT_Y, NEW_HORIZONS_INPUT_SELECT,
        NEW_HORIZONS_INPUT_START, NEW_HORIZONS_INPUT_UP, NEW_HORIZONS_INPUT_DOWN,
        NEW_HORIZONS_INPUT_LEFT, NEW_HORIZONS_INPUT_RIGHT, NEW_HORIZONS_INPUT_A,
        NEW_HORIZONS_INPUT_X, NEW_HORIZONS_INPUT_L, NEW_HORIZONS_INPUT_R
    };
    static const uint16_t core[] = {
        NH_CORE_INPUT_B, NH_CORE_INPUT_Y, NH_CORE_INPUT_SELECT,
        NH_CORE_INPUT_START, NH_CORE_INPUT_UP, NH_CORE_INPUT_DOWN,
        NH_CORE_INPUT_LEFT, NH_CORE_INPUT_RIGHT, NH_CORE_INPUT_A,
        NH_CORE_INPUT_X, NH_CORE_INPUT_L, NH_CORE_INPUT_R
    };
    NewHorizonsInputLatch latch = { 0u, 0u };
    size_t index;

    for (index = 0u; index < sizeof(frontend) / sizeof(frontend[0]); ++index) {
        CHECK(frontend[index] == core[index]);
        new_horizons_input_latch_reset(&latch);
        new_horizons_input_latch_press(&latch, frontend[index], 0u, 0);
        CHECK(new_horizons_input_latch_sample(&latch) == frontend[index]);
        new_horizons_input_latch_release(&latch, frontend[index]);
        CHECK(new_horizons_input_latch_sample(&latch) == frontend[index]);
        new_horizons_input_latch_consume(&latch, frontend[index]);
        CHECK(new_horizons_input_latch_sample(&latch) == 0u);
    }

    new_horizons_input_latch_press(&latch, NEW_HORIZONS_INPUT_LEFT,
                             NEW_HORIZONS_INPUT_RIGHT, 0);
    new_horizons_input_latch_press(&latch, NEW_HORIZONS_INPUT_RIGHT,
                             NEW_HORIZONS_INPUT_LEFT, 0);
    CHECK((latch.held & (NEW_HORIZONS_INPUT_LEFT | NEW_HORIZONS_INPUT_RIGHT)) ==
          (NEW_HORIZONS_INPUT_LEFT | NEW_HORIZONS_INPUT_RIGHT));
    CHECK(latch.pending_press == NEW_HORIZONS_INPUT_RIGHT);
    new_horizons_input_latch_reset(&latch);
    CHECK(new_horizons_input_latch_sample(&latch) == 0u);

    puts("PASS all frontend/core button constants and keyboard press/release latch routes");
    return 0;
}
