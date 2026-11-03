#include "new_horizons_timing_plan.h"

const NHTimingPlan *nh_timing_plan_lookup(uint32_t context_key) {
    uint32_t bank, first, last;
    if (context_key > 0x07FFFFFFu) return NULL;
    bank = context_key >> 19u;
    first = nh_timing_bank_first[bank];
    last = nh_timing_bank_first[bank + 1u];
    if (first > last || (size_t)last > nh_timing_binding_count) return NULL;
    while (first < last) {
        const uint32_t middle = first + (last - first) / 2u;
        const NHTimingBinding *binding = &nh_timing_bindings[middle];
        if (binding->context_key < context_key) first = middle + 1u;
        else if (binding->context_key > context_key) last = middle;
        else {
            if ((size_t)binding->plan_index >= nh_timing_plan_count) return NULL;
            return &nh_timing_plans[binding->plan_index];
        }
    }
    return NULL;
}
