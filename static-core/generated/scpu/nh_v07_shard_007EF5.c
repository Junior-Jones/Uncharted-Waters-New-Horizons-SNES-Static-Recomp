/* Generated direct New Horizons S-CPU authority; do not edit. */
#include "nh_v07_generated.h"

NHScpuExecResult nh_v07_shard_007EF5(NHScpuState *cpu, const NHScpuBus *bus) {
    switch (nh_scpu_context_key(cpu)) {
        case 0x03F7AD08u: {
            static const uint8_t expected_epoch[] = { 0x54u, 0x7Eu, 0xC8u, 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0x7EF5A1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t source_address = (0xC8u << 16u) | (uint32_t)cpu->x;
            const uint32_t destination_address = (0x7Eu << 16u) | (uint32_t)cpu->y;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, source_address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, destination_address, value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->dbr = 0x7Eu;
            cpu->x = (uint16_t)((cpu->x + (1)) & 0xFFFFu);
            cpu->y = (uint16_t)((cpu->y + (1)) & 0xFFFFu);
            cpu->a = (uint16_t)(cpu->a - 1u);
            if (cpu->a != 0xFFFFu) {
                cpu->pbr = 0x7Eu;
                cpu->pc = 0xF5A1u;
                if (nh_scpu_expect_next(cpu, 0x03F7AD08u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 7u);
            }
            cpu->pbr = 0x7Eu;
            cpu->pc = 0xF5A4u;
            if (nh_scpu_expect_next(cpu, 0x03F7AD20u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u);
        }

        case 0x03F7AD20u: {
            static const uint8_t expected_epoch[] = { 0x54u, 0x7Eu, 0xC8u, 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0x7EF5A1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u, return_bank = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &return_bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            cpu->pbr = return_bank;
            if (nh_scpu_context_key(cpu) != 0x060F35F0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        default: return NH_SCPU_NOT_MINE;
    }
}
