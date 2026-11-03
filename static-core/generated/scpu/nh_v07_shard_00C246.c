/* Generated direct New Horizons S-CPU authority; do not edit. */
#include "nh_v07_generated.h"

NHScpuExecResult nh_v07_shard_00C246(NHScpuState *cpu, const NHScpuBus *bus) {
    switch (nh_scpu_context_key(cpu)) {
        case 0x06123000u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x22u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24600u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000022u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000023u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4602u;
            if (nh_scpu_expect_next(cpu, 0x06123010u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06123010u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x2Bu, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24602u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x012Bu;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4605u;
            if (nh_scpu_expect_next(cpu, 0x06123028u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06123028u: {
            static const uint8_t expected_epoch[] = { 0xB7u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24605u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000020u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000021u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_bank = 0u, low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000022u) & 0xFFFFu), &pointer_bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) | ((uint32_t)pointer_high << 8u) | pointer_low) + cpu->y) & 0xFFFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4607u;
            if (nh_scpu_expect_next(cpu, 0x06123038u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06123038u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x31u, 0xA2u, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC24607u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x7EA231u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, 0x7EA232u, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x460Bu;
            if (nh_scpu_expect_next(cpu, 0x06123058u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06123058u: {
            static const uint8_t expected_epoch[] = { 0x3Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC2460Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = cpu->s;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x460Cu;
            if (nh_scpu_expect_next(cpu, 0x06123060u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06123060u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2460Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC2u;
            cpu->pc = 0x460Du;
            if (nh_scpu_expect_next(cpu, 0x06123068u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06123068u: {
            static const uint8_t expected_epoch[] = { 0x69u, 0x2Eu, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2460Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t right = 0x012Eu;
            uint32_t sum;
            uint16_t result;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            sum = (uint32_t)left + (uint32_t)right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            result = (uint16_t)sum;
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (sum > 0xFFFFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            if (((uint16_t)(~(left ^ right)) & (uint16_t)(left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4610u;
            if (nh_scpu_expect_next(cpu, 0x06123080u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06123080u: {
            static const uint8_t expected_epoch[] = { 0x1Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC24610u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = cpu->a;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4611u;
            if (nh_scpu_expect_next(cpu, 0x06123088u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06123088u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x08u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24611u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x0008u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4614u;
            if (nh_scpu_expect_next(cpu, 0x061230A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x061230A0u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x53u, 0xFFu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24614u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x46u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x17u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF53u;
            if (nh_scpu_expect_next(cpu, 0x060FFA98u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x061230C0u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC24618u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u, return_bank = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &return_bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            cpu->pbr = return_bank;
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if ((((return_key != 0x060BABF0u && (return_key != 0x060BADC8u && return_key != 0x060BB0F0u)) && (return_key != 0x060BB2B0u && (return_key != 0x061231C0u && return_key != 0x06123398u))) && ((return_key != 0x0639F6E0u && (return_key != 0x0639F8B8u && return_key != 0x063AA390u)) && (return_key != 0x063AA568u && (return_key != 0x064DEA80u && return_key != 0x064DEC40u)))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x061230C8u: {
            static const uint8_t expected_epoch[] = { 0xD4u, 0x26u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24619u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000026u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000027u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC2u;
            cpu->pc = 0x461Bu;
            if (nh_scpu_expect_next(cpu, 0x061230D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (6u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x061230D8u: {
            static const uint8_t expected_epoch[] = { 0xD4u, 0x24u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2461Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000024u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000025u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC2u;
            cpu->pc = 0x461Du;
            if (nh_scpu_expect_next(cpu, 0x061230E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (6u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x061230E8u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2461Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC2u;
            cpu->pc = 0x461Eu;
            if (nh_scpu_expect_next(cpu, 0x061230F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x061230F0u: {
            static const uint8_t expected_epoch[] = { 0x3Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC2461Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = cpu->s;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x461Fu;
            if (nh_scpu_expect_next(cpu, 0x061230F8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x061230F8u: {
            static const uint8_t expected_epoch[] = { 0x69u, 0x0Cu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2461Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t right = 0x000Cu;
            uint32_t sum;
            uint16_t result;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            sum = (uint32_t)left + (uint32_t)right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            result = (uint16_t)sum;
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (sum > 0xFFFFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            if (((uint16_t)(~(left ^ right)) & (uint16_t)(left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4622u;
            if (nh_scpu_expect_next(cpu, 0x06123110u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06123110u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x24u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24622u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000024u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000025u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4624u;
            if (nh_scpu_expect_next(cpu, 0x06123120u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06123120u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x26u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24624u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000026u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000027u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4626u;
            if (nh_scpu_expect_next(cpu, 0x06123130u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06123130u: {
            static const uint8_t expected_epoch[] = { 0xF4u, 0x01u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24626u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x00u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x01u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4629u;
            if (nh_scpu_expect_next(cpu, 0x06123148u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06123148u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x26u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24629u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000026u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000027u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x462Bu;
            if (nh_scpu_expect_next(cpu, 0x06123158u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06123158u: {
            static const uint8_t expected_epoch[] = { 0x48u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2462Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC2u;
            cpu->pc = 0x462Cu;
            if (nh_scpu_expect_next(cpu, 0x06123160u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06123160u: {
            static const uint8_t expected_epoch[] = { 0xD4u, 0x24u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2462Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000024u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000025u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC2u;
            cpu->pc = 0x462Eu;
            if (nh_scpu_expect_next(cpu, 0x06123170u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (6u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06123170u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2462Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x10u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4630u;
            if (nh_scpu_expect_next(cpu, 0x06123180u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06123180u: {
            static const uint8_t expected_epoch[] = { 0x48u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24630u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4631u;
            if (nh_scpu_expect_next(cpu, 0x06123188u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06123188u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24631u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x10u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4633u;
            if (nh_scpu_expect_next(cpu, 0x06123198u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06123198u: {
            static const uint8_t expected_epoch[] = { 0x48u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24633u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4634u;
            if (nh_scpu_expect_next(cpu, 0x061231A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x061231A0u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x17u, 0x3Du, 0xC2u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24634u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x46u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x37u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC2u;
            cpu->pc = 0x3D17u;
            if (nh_scpu_expect_next(cpu, 0x0611E8B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x061231C0u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24638u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4639u;
            if (nh_scpu_expect_next(cpu, 0x061231C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x061231C8u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24639u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x463Au;
            if (nh_scpu_expect_next(cpu, 0x061231D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x061231D0u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2463Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x463Bu;
            if (nh_scpu_expect_next(cpu, 0x061231D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x061231D8u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2463Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x463Cu;
            if (nh_scpu_expect_next(cpu, 0x061231E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x061231E0u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2463Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x463Du;
            if (nh_scpu_expect_next(cpu, 0x061231E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x061231E8u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2463Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x463Eu;
            if (nh_scpu_expect_next(cpu, 0x061231F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x061231F0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x24u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2463Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000024u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000025u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4640u;
            if (nh_scpu_expect_next(cpu, 0x06123200u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06123200u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24640u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4641u;
            if (nh_scpu_expect_next(cpu, 0x06123208u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06123208u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x26u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24641u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000026u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000027u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4643u;
            if (nh_scpu_expect_next(cpu, 0x06123218u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06123218u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC24643u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u, return_bank = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &return_bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            cpu->pbr = return_bank;
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if ((((((((((return_key != 0x0608AD60u && return_key != 0x060960F8u) && (return_key != 0x06096B20u && (return_key != 0x06096C70u && return_key != 0x0609D250u))) && ((return_key != 0x0609D398u && return_key != 0x060A2CB8u) && (return_key != 0x060A2DF8u && (return_key != 0x060A3190u && return_key != 0x060A3428u)))) && (((return_key != 0x060A5A80u && return_key != 0x060A5C80u) && (return_key != 0x060A5E40u && (return_key != 0x060A6248u && return_key != 0x060A63D0u))) && ((return_key != 0x060A6528u && return_key != 0x060A6D38u) && (return_key != 0x060A6F38u && (return_key != 0x060A70F8u && return_key != 0x060A7528u))))) && ((((return_key != 0x060A76B0u && return_key != 0x060A7808u) && (return_key != 0x060AF048u && (return_key != 0x060AF218u && return_key != 0x060AF738u))) && ((return_key != 0x060AF8C8u && return_key != 0x060B0FD0u) && (return_key != 0x060B6ED8u && (return_key != 0x060C44A8u && return_key != 0x060C4800u)))) && (((return_key != 0x060C48A0u && return_key != 0x060C4950u) && (return_key != 0x060C4DD8u && (return_key != 0x060C4ED0u && return_key != 0x060C4F68u))) && ((return_key != 0x060C51E8u && return_key != 0x060C52E0u) && (return_key != 0x060C53F0u && (return_key != 0x060C5570u && return_key != 0x060C5638u)))))) && (((((return_key != 0x060C5700u && return_key != 0x060C57D0u) && (return_key != 0x060C5880u && (return_key != 0x060C5930u && return_key != 0x060C59E0u))) && ((return_key != 0x060C5BD8u && return_key != 0x060CC3F0u) && (return_key != 0x060CC568u && (return_key != 0x060CC948u && return_key != 0x060CCAC0u)))) && (((return_key != 0x060CCD98u && return_key != 0x060CCF00u) && (return_key != 0x060CCF70u && (return_key != 0x060CD0C8u && return_key != 0x060CD138u))) && ((return_key != 0x060DD338u && return_key != 0x060DD3A8u) && (return_key != 0x060DD550u && (return_key != 0x060DD5C0u && return_key != 0x060DD768u))))) && ((((return_key != 0x060DD7D8u && return_key != 0x060DD990u) && (return_key != 0x060DDA00u && (return_key != 0x060DDBA8u && return_key != 0x060DDC18u))) && ((return_key != 0x060DDF28u && return_key != 0x060DDF98u) && (return_key != 0x060DE1B0u && (return_key != 0x060DE480u && return_key != 0x060DE508u)))) && (((return_key != 0x060DF270u && return_key != 0x060E4E18u) && (return_key != 0x060E5570u && (return_key != 0x060E55E0u && return_key != 0x060E5860u))) && ((return_key != 0x060E58D0u && return_key != 0x060E5B50u) && (return_key != 0x060E5BC0u && (return_key != 0x060E7260u && return_key != 0x060E7528u))))))) && ((((((return_key != 0x060E7CE0u && return_key != 0x060E7D50u) && (return_key != 0x060E7FB0u && (return_key != 0x060E8020u && return_key != 0x060E8428u))) && ((return_key != 0x060E8498u && return_key != 0x060E8778u) && (return_key != 0x060E87F8u && (return_key != 0x06138840u && return_key != 0x06138E68u)))) && (((return_key != 0x06139718u && return_key != 0x06139970u) && (return_key != 0x06139B68u && (return_key != 0x06139ED0u && return_key != 0x0613A0A8u))) && ((return_key != 0x0613A528u && return_key != 0x0613AF08u) && (return_key != 0x0613B060u && (return_key != 0x0613B760u && return_key != 0x0613BA88u))))) && ((((return_key != 0x0613C028u && return_key != 0x0613C948u) && (return_key != 0x0613CE18u && (return_key != 0x0613D3C8u && return_key != 0x0613D968u))) && ((return_key != 0x0613E1A8u && return_key != 0x0613E9B8u) && (return_key != 0x0613EAD0u && (return_key != 0x0613EC30u && return_key != 0x06140640u)))) && (((return_key != 0x06144490u && return_key != 0x0614A310u) && (return_key != 0x0614BC00u && (return_key != 0x0614BE30u && return_key != 0x0614BFE8u))) && ((return_key != 0x0614C1A0u && return_key != 0x0620F128u) && (return_key != 0x06242FE8u && (return_key != 0x06243470u && return_key != 0x06243700u)))))) && (((((return_key != 0x06243760u && return_key != 0x062437C0u) && (return_key != 0x06243820u && (return_key != 0x06243880u && return_key != 0x062438E0u))) && ((return_key != 0x06243940u && return_key != 0x06243B60u) && (return_key != 0x06243CE0u && (return_key != 0x06243E50u && return_key != 0x06244010u)))) && (((return_key != 0x06244180u && return_key != 0x06244400u) && (return_key != 0x062445B0u && (return_key != 0x062446F0u && return_key != 0x06244750u))) && ((return_key != 0x062447B0u && return_key != 0x06244810u) && (return_key != 0x06244870u && (return_key != 0x06244D10u && return_key != 0x062451E0u))))) && ((((return_key != 0x06245360u && return_key != 0x06245460u) && (return_key != 0x062455D0u && (return_key != 0x06245850u && return_key != 0x062458B0u))) && ((return_key != 0x06245910u && return_key != 0x06245C70u) && (return_key != 0x06245E50u && (return_key != 0x06246070u && return_key != 0x06246510u)))) && (((return_key != 0x062466C0u && return_key != 0x06246940u) && (return_key != 0x062469A0u && (return_key != 0x06246A00u && return_key != 0x06246A60u))) && ((return_key != 0x06246AC0u && (return_key != 0x06247280u && return_key != 0x062475D0u)) && (return_key != 0x06247850u && (return_key != 0x06247A60u && return_key != 0x06247AC0u)))))))) && (((((((return_key != 0x06247B20u && return_key != 0x06247B80u) && (return_key != 0x062483B0u && (return_key != 0x06248430u && return_key != 0x06248560u))) && ((return_key != 0x06248D60u && return_key != 0x06248EE8u) && (return_key != 0x06248FC8u && (return_key != 0x06249178u && return_key != 0x062492B8u)))) && (((return_key != 0x06249440u && return_key != 0x06249570u) && (return_key != 0x06249630u && (return_key != 0x062496F0u && return_key != 0x062497B0u))) && ((return_key != 0x06249890u && return_key != 0x06249A18u) && (return_key != 0x06249AD8u && (return_key != 0x06249B98u && return_key != 0x06249CC8u))))) && ((((return_key != 0x06249E18u && return_key != 0x06249EF8u) && (return_key != 0x0624A098u && (return_key != 0x0624A0F8u && return_key != 0x0624A158u))) && ((return_key != 0x0624A1B8u && return_key != 0x0624A218u) && (return_key != 0x0624A278u && (return_key != 0x0624A5D8u && return_key != 0x0624A788u)))) && (((return_key != 0x0624A8C8u && return_key != 0x0624A928u) && (return_key != 0x0624A988u && (return_key != 0x0624A9E8u && return_key != 0x0624ADC8u))) && ((return_key != 0x0624AF88u && return_key != 0x0624B128u) && (return_key != 0x0624B188u && (return_key != 0x0624B1E8u && return_key != 0x0624B248u)))))) && (((((return_key != 0x0624B2A8u && return_key != 0x0624B548u) && (return_key != 0x0624B6C0u && (return_key != 0x0624B940u && return_key != 0x0624B9A0u))) && ((return_key != 0x0624BA00u && return_key != 0x0624BA60u) && (return_key != 0x0624BFC0u && (return_key != 0x0624C160u && return_key != 0x0624C480u)))) && (((return_key != 0x0624C4E0u && return_key != 0x0624C540u) && (return_key != 0x0624C5A0u && (return_key != 0x0624CAC8u && return_key != 0x0624CBD8u))) && ((return_key != 0x0624CD60u && return_key != 0x0624CEA0u) && (return_key != 0x0624CFE0u && (return_key != 0x0624D110u && return_key != 0x0624D1D0u))))) && ((((return_key != 0x0624D310u && return_key != 0x0624D440u) && (return_key != 0x0624D500u && (return_key != 0x0624D640u && return_key != 0x0624DAB8u))) && ((return_key != 0x0624E010u && return_key != 0x0624E150u) && (return_key != 0x0624E6A8u && (return_key != 0x0624E7E8u && return_key != 0x0624E918u)))) && (((return_key != 0x0624EA68u && return_key != 0x0624EB48u) && (return_key != 0x0624ECC8u && (return_key != 0x0624ED28u && return_key != 0x0624ED88u))) && ((return_key != 0x0624EDE8u && return_key != 0x0624EE48u) && (return_key != 0x0624EEA8u && (return_key != 0x0624EF08u && return_key != 0x0624F208u))))))) && ((((((return_key != 0x0624F268u && return_key != 0x0624F2C8u) && (return_key != 0x0624F328u && (return_key != 0x0624F388u && return_key != 0x0624F3E8u))) && ((return_key != 0x0624F720u && return_key != 0x0624F8B0u) && (return_key != 0x0624F910u && (return_key != 0x0624F970u && return_key != 0x0624F9D0u)))) && (((return_key != 0x0624FA30u && return_key != 0x0624FA90u) && (return_key != 0x0624FAF0u && (return_key != 0x0624FDD0u && return_key != 0x0624FF10u))) && ((return_key != 0x0624FF70u && return_key != 0x0624FFD0u) && (return_key != 0x06250030u && (return_key != 0x06250090u && return_key != 0x06250308u))))) && ((((return_key != 0x06250478u && return_key != 0x06250610u) && (return_key != 0x062509A0u && (return_key != 0x06250B20u && return_key != 0x06250D00u))) && ((return_key != 0x06250D60u && return_key != 0x06250DC0u) && (return_key != 0x06250E20u && (return_key != 0x06250E80u && return_key != 0x06251410u)))) && (((return_key != 0x06251578u && return_key != 0x062516B8u) && (return_key != 0x062517F8u && (return_key != 0x06251928u && return_key != 0x06251A68u))) && ((return_key != 0x06251B98u && return_key != 0x06251CD8u) && (return_key != 0x06251E08u && (return_key != 0x06251F48u && return_key != 0x06252098u)))))) && (((((return_key != 0x06252178u && return_key != 0x062522F8u) && (return_key != 0x06252358u && (return_key != 0x062523B8u && return_key != 0x06252418u))) && ((return_key != 0x06252478u && return_key != 0x062524D8u) && (return_key != 0x062527B8u && (return_key != 0x06252998u && return_key != 0x062529F8u)))) && (((return_key != 0x06252A58u && return_key != 0x06252AB8u) && (return_key != 0x06252B18u && (return_key != 0x06252B78u && return_key != 0x06252EF8u))) && ((return_key != 0x06253078u && return_key != 0x062531F8u) && (return_key != 0x06253378u && (return_key != 0x062534F8u && return_key != 0x062535F8u))))) && ((((return_key != 0x062537F8u && return_key != 0x062539F8u) && (return_key != 0x06253A58u && (return_key != 0x06253AB8u && return_key != 0x06253B18u))) && ((return_key != 0x06253B78u && return_key != 0x06253ED8u) && (return_key != 0x06254058u && (return_key != 0x062541D8u && return_key != 0x06254498u)))) && (((return_key != 0x062544F8u && return_key != 0x06254558u) && (return_key != 0x062545B8u && (return_key != 0x06254618u && return_key != 0x06254918u))) && ((return_key != 0x06254D38u && (return_key != 0x06254D98u && return_key != 0x06254DF8u)) && (return_key != 0x06254E58u && (return_key != 0x06254EB8u && return_key != 0x062552A0u))))))))) && ((((((((return_key != 0x06255300u && return_key != 0x06255360u) && (return_key != 0x062553C0u && (return_key != 0x06255420u && return_key != 0x06255480u))) && ((return_key != 0x062557E0u && return_key != 0x06255950u) && (return_key != 0x06255AF0u && (return_key != 0x06255B50u && return_key != 0x06255BB0u)))) && (((return_key != 0x06255C10u && return_key != 0x06255E30u) && (return_key != 0x06255FE0u && (return_key != 0x06256120u && return_key != 0x06256180u))) && ((return_key != 0x062561E0u && return_key != 0x06256240u) && (return_key != 0x06256540u && (return_key != 0x062566E0u && return_key != 0x06256860u))))) && ((((return_key != 0x062568C0u && return_key != 0x06256920u) && (return_key != 0x06256980u && (return_key != 0x062569E0u && return_key != 0x06256D90u))) && ((return_key != 0x06257100u && return_key != 0x06257280u) && (return_key != 0x062573F0u && (return_key != 0x06257598u && return_key != 0x06259C48u)))) && (((return_key != 0x06259E60u && return_key != 0x062860B0u) && (return_key != 0x06286210u && (return_key != 0x062865B8u && return_key != 0x06286918u))) && ((return_key != 0x06286C48u && return_key != 0x062870C8u) && (return_key != 0x06287580u && (return_key != 0x06287678u && return_key != 0x06287A50u)))))) && (((((return_key != 0x06287C38u && return_key != 0x06288C68u) && (return_key != 0x06288F90u && (return_key != 0x06289168u && return_key != 0x06289628u))) && ((return_key != 0x06289A58u && return_key != 0x0628C3D8u) && (return_key != 0x0628CB90u && (return_key != 0x0628CF88u && return_key != 0x0628D628u)))) && (((return_key != 0x0628D748u && return_key != 0x0628D960u) && (return_key != 0x0628DA68u && (return_key != 0x0628F430u && return_key != 0x0628F6A8u))) && ((return_key != 0x0628F850u && return_key != 0x0628FD28u) && (return_key != 0x062905F8u && (return_key != 0x06290FC0u && return_key != 0x06291218u))))) && ((((return_key != 0x06291410u && return_key != 0x06291608u) && (return_key != 0x06291AA0u && (return_key != 0x06291CA0u && return_key != 0x06297FB8u))) && ((return_key != 0x062980C8u && return_key != 0x0629A958u) && (return_key != 0x0629AA38u && (return_key != 0x0629AB48u && return_key != 0x0629AC28u)))) && (((return_key != 0x0629AD08u && return_key != 0x0629ADE8u) && (return_key != 0x0629F0A8u && (return_key != 0x062AB078u && return_key != 0x062AB328u))) && ((return_key != 0x062B4440u && return_key != 0x062B8528u) && (return_key != 0x062B8FE8u && (return_key != 0x062B9168u && return_key != 0x062B9440u))))))) && ((((((return_key != 0x062BC920u && return_key != 0x062BCC00u) && (return_key != 0x062BD190u && (return_key != 0x062BD230u && return_key != 0x062BD608u))) && ((return_key != 0x062BE2B0u && return_key != 0x062C1F88u) && (return_key != 0x062C2198u && (return_key != 0x062C3270u && return_key != 0x062C3688u)))) && (((return_key != 0x062C3800u && return_key != 0x062C3928u) && (return_key != 0x062C3AB8u && (return_key != 0x062C3BE0u && return_key != 0x062C3D10u))) && ((return_key != 0x062C3E38u && return_key != 0x062C3F68u) && (return_key != 0x062C4E38u && (return_key != 0x062C5038u && return_key != 0x062C5A00u))))) && ((((return_key != 0x062CE8F8u && return_key != 0x062D1AE8u) && (return_key != 0x062D1D98u && (return_key != 0x062D2A10u && return_key != 0x062D46C8u))) && ((return_key != 0x062D4828u && return_key != 0x062D70C0u) && (return_key != 0x062D73C0u && (return_key != 0x062D7720u && return_key != 0x062DD3A8u)))) && (((return_key != 0x062DE418u && return_key != 0x062DE5B8u) && (return_key != 0x062DF4B0u && (return_key != 0x062DFF08u && return_key != 0x062E1280u))) && ((return_key != 0x0630F0B0u && return_key != 0x06311038u) && (return_key != 0x06311430u && (return_key != 0x06313C88u && return_key != 0x063142D8u)))))) && (((((return_key != 0x06329818u && return_key != 0x06331498u) && (return_key != 0x06331640u && (return_key != 0x06332268u && return_key != 0x06332628u))) && ((return_key != 0x06338AD0u && return_key != 0x06353C00u) && (return_key != 0x06354F08u && (return_key != 0x06356710u && return_key != 0x0635B0B8u)))) && (((return_key != 0x0635B138u && return_key != 0x0635B268u) && (return_key != 0x0635B2E8u && (return_key != 0x0635B348u && return_key != 0x0635B3E8u))) && ((return_key != 0x0635B488u && return_key != 0x0635B528u) && (return_key != 0x0635B5C8u && (return_key != 0x0635B628u && return_key != 0x0635B788u))))) && ((((return_key != 0x0635B858u && return_key != 0x0635BB10u) && (return_key != 0x0635BBC8u && (return_key != 0x0635BFF8u && return_key != 0x0635C128u))) && ((return_key != 0x0635C188u && return_key != 0x0635C248u) && (return_key != 0x0635C308u && (return_key != 0x0635C548u && return_key != 0x0635C5C8u)))) && (((return_key != 0x0635C6F8u && return_key != 0x0635C858u) && (return_key != 0x0635C908u && (return_key != 0x0635C9C8u && return_key != 0x0635CB28u))) && ((return_key != 0x0635CC18u && (return_key != 0x0635CCC0u && return_key != 0x0635CD80u)) && (return_key != 0x0635CE20u && (return_key != 0x0635CEC0u && return_key != 0x0635CF20u)))))))) && (((((((return_key != 0x0635CF80u && return_key != 0x0635D020u) && (return_key != 0x0635D450u && (return_key != 0x0635D580u && return_key != 0x0635D640u))) && ((return_key != 0x0635D880u && return_key != 0x0635D940u) && (return_key != 0x0635DB80u && (return_key != 0x0635DCC0u && return_key != 0x0635DDC0u)))) && (((return_key != 0x0635DE20u && return_key != 0x0635DEC0u) && (return_key != 0x0635DF20u && (return_key != 0x0635DFC0u && return_key != 0x0635E080u))) && ((return_key != 0x0635E278u && return_key != 0x0635E328u) && (return_key != 0x0635E388u && (return_key != 0x0635E428u && return_key != 0x0635E4C8u))))) && ((((return_key != 0x0635E8F8u && return_key != 0x0635EA28u) && (return_key != 0x0635EAE8u && (return_key != 0x0635ECE0u && return_key != 0x0635EDB0u))) && ((return_key != 0x0635F1D0u && return_key != 0x0635F380u) && (return_key != 0x0635F420u && (return_key != 0x0635F660u && return_key != 0x0635F710u)))) && (((return_key != 0x0635F7B0u && return_key != 0x0635FBE0u) && (return_key != 0x0635FD10u && (return_key != 0x063600C0u && return_key != 0x06360238u))) && ((return_key != 0x06360478u && return_key != 0x06360838u) && (return_key != 0x063608D8u && (return_key != 0x06360958u && return_key != 0x063609F8u)))))) && (((((return_key != 0x06360A98u && return_key != 0x06360B38u) && (return_key != 0x06360C48u && (return_key != 0x06360CF8u && return_key != 0x06360DA8u))) && ((return_key != 0x06360E78u && return_key != 0x06360ED8u) && (return_key != 0x06361308u && (return_key != 0x06361438u && return_key != 0x063614F8u)))) && (((return_key != 0x06361738u && return_key != 0x06361978u) && (return_key != 0x06361B08u && (return_key != 0x06361C48u && return_key != 0x06361D48u))) && ((return_key != 0x06361DE8u && return_key != 0x06361E88u) && (return_key != 0x06361EE8u && (return_key != 0x06362028u && return_key != 0x063620D0u))))) && ((((return_key != 0x06362130u && return_key != 0x063621D0u) && (return_key != 0x06362600u && (return_key != 0x06362730u && return_key != 0x0638E988u))) && ((return_key != 0x0639AA58u && return_key != 0x0639DE98u) && (return_key != 0x063A19E0u && (return_key != 0x063B0D30u && return_key != 0x063B8F98u)))) && (((return_key != 0x063B9E80u && return_key != 0x063D6C08u) && (return_key != 0x063D71C8u && (return_key != 0x063D73B8u && return_key != 0x063D78D0u))) && ((return_key != 0x063DDF38u && (return_key != 0x063E1A18u && return_key != 0x063E3A50u)) && (return_key != 0x063E9B38u && (return_key != 0x063F06E8u && return_key != 0x063F0988u))))))) && ((((((return_key != 0x063F13D8u && return_key != 0x06402078u) && (return_key != 0x064022D0u && (return_key != 0x06402610u && return_key != 0x06402808u))) && ((return_key != 0x06404BE8u && return_key != 0x06404CE0u) && (return_key != 0x06405B08u && (return_key != 0x06405FF0u && return_key != 0x0640DE18u)))) && (((return_key != 0x0640FAA0u && return_key != 0x0641C018u) && (return_key != 0x0641C0A8u && (return_key != 0x0641D008u && return_key != 0x064230C8u))) && ((return_key != 0x064280A0u && return_key != 0x064283F8u) && (return_key != 0x06428878u && (return_key != 0x064290C8u && return_key != 0x064294E0u))))) && ((((return_key != 0x06439360u && return_key != 0x064985C8u) && (return_key != 0x0649F588u && (return_key != 0x0649F8C8u && return_key != 0x064A25A8u))) && ((return_key != 0x064B1970u && return_key != 0x064DFE70u) && (return_key != 0x064E0998u && (return_key != 0x064E1FC0u && return_key != 0x064E2128u)))) && (((return_key != 0x064E2610u && return_key != 0x064E2928u) && (return_key != 0x064E2BB8u && (return_key != 0x064E2E48u && return_key != 0x064EBB68u))) && ((return_key != 0x064EBFF8u && return_key != 0x064EC6F8u) && (return_key != 0x0652A988u && (return_key != 0x0652AE18u && return_key != 0x065836F8u)))))) && (((((return_key != 0x0662E8A8u && return_key != 0x06647B00u) && (return_key != 0x0665B5F8u && (return_key != 0x0665B7C8u && return_key != 0x06683F48u))) && ((return_key != 0x06692158u && return_key != 0x066922E0u) && (return_key != 0x06692CB0u && (return_key != 0x06693688u && return_key != 0x0669EE30u)))) && (((return_key != 0x0669F2D0u && return_key != 0x0669F400u) && (return_key != 0x0669F500u && (return_key != 0x0669F618u && return_key != 0x06706B10u))) && ((return_key != 0x06707070u && return_key != 0x06707698u) && (return_key != 0x067077C0u && (return_key != 0x06707BD0u && return_key != 0x0670A858u))))) && ((((return_key != 0x0670ABE0u && return_key != 0x0670B2B8u) && (return_key != 0x0670BB10u && (return_key != 0x0670FC90u && return_key != 0x067103D0u))) && ((return_key != 0x067107C0u && return_key != 0x067117C8u) && (return_key != 0x06717598u && (return_key != 0x06717918u && return_key != 0x06717DB8u)))) && (((return_key != 0x06718138u && return_key != 0x0671B2D0u) && (return_key != 0x0671BA98u && (return_key != 0x0671BCD0u && return_key != 0x0671D7E8u))) && ((return_key != 0x06720C60u && (return_key != 0x067222B0u && return_key != 0x067225B0u)) && (return_key != 0x06722700u && (return_key != 0x06722878u && return_key != 0x06722E58u)))))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06123220u: {
            static const uint8_t expected_epoch[] = { 0xD4u, 0x26u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24644u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000026u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000027u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4646u;
            if (nh_scpu_expect_next(cpu, 0x06123230u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (6u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06123230u: {
            static const uint8_t expected_epoch[] = { 0xD4u, 0x24u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24646u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000024u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000025u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4648u;
            if (nh_scpu_expect_next(cpu, 0x06123240u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (6u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06123240u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24648u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x08u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x464Au;
            if (nh_scpu_expect_next(cpu, 0x06123250u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06123250u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x40u, 0xA2u, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC2464Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x7EA240u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, 0x7EA241u, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x464Eu;
            if (nh_scpu_expect_next(cpu, 0x06123270u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06123270u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2464Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4650u;
            if (nh_scpu_expect_next(cpu, 0x06123282u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06123282u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC24650u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = ((uint32_t)cpu->s + 0x0Au) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4652u;
            if (nh_scpu_expect_next(cpu, 0x06123292u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06123292u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x42u, 0xA2u, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC24652u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x7EA242u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4656u;
            if (nh_scpu_expect_next(cpu, 0x061232B2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x061232B2u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24656u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4657u;
            if (nh_scpu_expect_next(cpu, 0x061232BAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x061232BAu: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24657u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4659u;
            if (nh_scpu_expect_next(cpu, 0x061232C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x061232C8u: {
            static const uint8_t expected_epoch[] = { 0x3Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC24659u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = cpu->s;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x465Au;
            if (nh_scpu_expect_next(cpu, 0x061232D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x061232D0u: {
            static const uint8_t expected_epoch[] = { 0x69u, 0x10u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2465Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0010u;
            uint32_t sum;
            uint16_t result;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            sum = (uint32_t)left + (uint32_t)right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            result = (uint16_t)sum;
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (sum > 0xFFFFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            if (((uint16_t)(~(left ^ right)) & (uint16_t)(left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x465Du;
            if (nh_scpu_expect_next(cpu, 0x061232E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x061232E8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x24u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2465Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000024u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000025u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x465Fu;
            if (nh_scpu_expect_next(cpu, 0x061232F8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x061232F8u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x26u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2465Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000026u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000027u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4661u;
            if (nh_scpu_expect_next(cpu, 0x06123308u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06123308u: {
            static const uint8_t expected_epoch[] = { 0xF4u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24661u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x00u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x00u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4664u;
            if (nh_scpu_expect_next(cpu, 0x06123320u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06123320u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x26u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24664u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000026u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000027u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4666u;
            if (nh_scpu_expect_next(cpu, 0x06123330u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06123330u: {
            static const uint8_t expected_epoch[] = { 0x48u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24666u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4667u;
            if (nh_scpu_expect_next(cpu, 0x06123338u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06123338u: {
            static const uint8_t expected_epoch[] = { 0xD4u, 0x24u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24667u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000024u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000025u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4669u;
            if (nh_scpu_expect_next(cpu, 0x06123348u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (6u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06123348u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x14u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24669u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x14u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x466Bu;
            if (nh_scpu_expect_next(cpu, 0x06123358u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06123358u: {
            static const uint8_t expected_epoch[] = { 0x48u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2466Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC2u;
            cpu->pc = 0x466Cu;
            if (nh_scpu_expect_next(cpu, 0x06123360u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06123360u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x14u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2466Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x14u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x466Eu;
            if (nh_scpu_expect_next(cpu, 0x06123370u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06123370u: {
            static const uint8_t expected_epoch[] = { 0x48u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2466Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC2u;
            cpu->pc = 0x466Fu;
            if (nh_scpu_expect_next(cpu, 0x06123378u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06123378u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x17u, 0x3Du, 0xC2u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2466Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x46u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x72u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC2u;
            cpu->pc = 0x3D17u;
            if (nh_scpu_expect_next(cpu, 0x0611E8B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x06123398u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24673u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4674u;
            if (nh_scpu_expect_next(cpu, 0x061233A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x061233A0u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24674u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4675u;
            if (nh_scpu_expect_next(cpu, 0x061233A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x061233A8u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24675u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4676u;
            if (nh_scpu_expect_next(cpu, 0x061233B0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x061233B0u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24676u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4677u;
            if (nh_scpu_expect_next(cpu, 0x061233B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x061233B8u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24677u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4678u;
            if (nh_scpu_expect_next(cpu, 0x061233C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x061233C0u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24678u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x4679u;
            if (nh_scpu_expect_next(cpu, 0x061233C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x061233C8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x24u };
            if (nh_scpu_guard_code(cpu, bus, 0xC24679u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000024u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000025u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x467Bu;
            if (nh_scpu_expect_next(cpu, 0x061233D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x061233D8u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2467Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x467Cu;
            if (nh_scpu_expect_next(cpu, 0x061233E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x061233E0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x26u };
            if (nh_scpu_guard_code(cpu, bus, 0xC2467Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000026u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000027u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC2u;
            cpu->pc = 0x467Eu;
            if (nh_scpu_expect_next(cpu, 0x061233F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x061233F0u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC2467Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u, return_bank = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &return_bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            cpu->pbr = return_bank;
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (((((return_key != 0x0634E458u && return_key != 0x0634E700u) && (return_key != 0x0634E8D8u && return_key != 0x0634ECA8u)) && ((return_key != 0x0634EEA8u && return_key != 0x0634F0A8u) && (return_key != 0x0634F2A8u && (return_key != 0x0634F480u && return_key != 0x0634F658u)))) && (((return_key != 0x0634F830u && return_key != 0x0634FA20u) && (return_key != 0x0634FAE8u && (return_key != 0x0634FDA0u && return_key != 0x06350208u))) && ((return_key != 0x06350528u && return_key != 0x06350848u) && (return_key != 0x06351250u && (return_key != 0x063CC9F0u && return_key != 0x065835B0u))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        default: return NH_SCPU_NOT_MINE;
    }
}
