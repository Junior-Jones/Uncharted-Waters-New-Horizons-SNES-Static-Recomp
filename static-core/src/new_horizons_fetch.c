#include "new_horizons_fetch.h"
#include "new_horizons_bus.h"

int nh_static_fetch_descriptor(const NHScpuState *cpu, uint32_t guard_address,
                               size_t guard_count, NHStaticFetch *descriptor) {
    NHStaticFetch result;
    NHBusRegion region;
    uint32_t current;
    if (cpu == NULL || descriptor == NULL || nh_scpu_validate_state(cpu) == 0 ||
        guard_address > 0xFFFFFFu || guard_count == 0u || guard_count > 4u)
        return 0;
    current = nh_scpu_address(cpu);
    result.guard_address = guard_address;
    result.guard_count = guard_count;
    result.fetch_address = current;
    result.fetch_count = guard_count;
    result.executable_epoch = 0u;
    result.immutable_byte_mask = (uint8_t)((1u << guard_count) - 1u);
    result.deferred_operand_address = 0u;
    result.deferred_operand_count = 0u;
    if (cpu->pbr == 0x7Eu) {
        /* One source-owned template with immutable54/6B and live bank fields.
         * Metadata spans four bytes; actual MVN/RTL fetches span3/1. */
        if (cpu->e != 0u || (cpu->p & (NH_P_M | NH_P_X)) != 0u ||
            guard_address != 0x7EF5A1u || guard_count != 4u)
            return 0;
        if (current == 0x7EF5A1u) {
            result.fetch_count = 3u;
            result.deferred_operand_address = 0x7EF5A2u;
            result.deferred_operand_count = 2u;
        }
        else if (current == 0x7EF5A4u) result.fetch_count = 1u;
        else return 0;
        result.executable_epoch = 1u;
        result.immutable_byte_mask = 0x09u;
    } else {
        if (current != guard_address || nh_bus_classify(current, &region) == 0 ||
            region.kind != NH_BUS_ROM)
            return 0;
    }
    *descriptor = result;
    return 1;
}
