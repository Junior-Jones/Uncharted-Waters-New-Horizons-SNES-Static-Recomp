/* Generated direct New Horizons S-CPU authority; do not edit. */
#include "nh_v07_generated.h"

NHScpuExecResult nh_v07_shard_00C10A(NHScpuState *cpu, const NHScpuBus *bus) {
    switch (nh_scpu_context_key(cpu)) {
        case 0x06085000u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A00u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A02u;
            if (nh_scpu_expect_next(cpu, 0x06085010u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06085010u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0xC6u, 0x41u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A02u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x41C6u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A05u;
            if (nh_scpu_expect_next(cpu, 0x06085028u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06085028u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A05u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000006u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000007u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A07u;
            if (nh_scpu_expect_next(cpu, 0x06085038u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06085038u: {
            static const uint8_t expected_epoch[] = { 0xAFu, 0x0Au, 0xEBu, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A07u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = 0x7EEB0Au;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A0Bu;
            if (nh_scpu_expect_next(cpu, 0x06085058u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06085058u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A0Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A0Du;
            if (nh_scpu_expect_next(cpu, 0x06085068u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06085068u: {
            static const uint8_t expected_epoch[] = { 0xAFu, 0x0Cu, 0xEBu, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A0Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = 0x7EEB0Cu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A11u;
            if (nh_scpu_expect_next(cpu, 0x06085088u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06085088u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A11u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A13u;
            if (nh_scpu_expect_next(cpu, 0x06085098u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06085098u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x6Cu, 0xFAu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A13u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x0Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x16u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA6Cu;
            if (nh_scpu_expect_next(cpu, 0x060FD360u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060850B8u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A17u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A18u;
            if (nh_scpu_expect_next(cpu, 0x060850C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060850C0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A18u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A1Au;
            if (nh_scpu_expect_next(cpu, 0x060850D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060850D0u: {
            static const uint8_t expected_epoch[] = { 0x69u, 0x39u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A1Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t right = 0x3039u;
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
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A1Du;
            if (nh_scpu_expect_next(cpu, 0x060850E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060850E8u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x0Au, 0xEBu, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A1Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x7EEB0Au, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, 0x7EEB0Bu, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A21u;
            if (nh_scpu_expect_next(cpu, 0x06085108u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06085108u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A21u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A23u;
            if (nh_scpu_expect_next(cpu, 0x06085118u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06085118u: {
            static const uint8_t expected_epoch[] = { 0x69u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A23u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
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
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A26u;
            if (nh_scpu_expect_next(cpu, 0x06085130u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06085130u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x0Cu, 0xEBu, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A26u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x7EEB0Cu, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, 0x7EEB0Du, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A2Au;
            if (nh_scpu_expect_next(cpu, 0x06085150u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06085150u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x10u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A2Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0010u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A2Du;
            if (nh_scpu_expect_next(cpu, 0x06085168u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06085168u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A2Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A2Fu;
            if (nh_scpu_expect_next(cpu, 0x06085178u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06085178u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A2Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000006u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000007u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A31u;
            if (nh_scpu_expect_next(cpu, 0x06085188u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06085188u: {
            static const uint8_t expected_epoch[] = { 0xAFu, 0x0Au, 0xEBu, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A31u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = 0x7EEB0Au;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A35u;
            if (nh_scpu_expect_next(cpu, 0x060851A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060851A8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A35u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A37u;
            if (nh_scpu_expect_next(cpu, 0x060851B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060851B8u: {
            static const uint8_t expected_epoch[] = { 0xAFu, 0x0Cu, 0xEBu, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A37u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = 0x7EEB0Cu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A3Bu;
            if (nh_scpu_expect_next(cpu, 0x060851D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060851D8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A3Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A3Du;
            if (nh_scpu_expect_next(cpu, 0x060851E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060851E8u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0xF5u, 0xFCu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A3Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x0Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x40u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCF5u;
            if (nh_scpu_expect_next(cpu, 0x060FE7A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x06085208u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A41u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A43u;
            if (nh_scpu_expect_next(cpu, 0x06085218u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06085218u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0xFFu, 0x7Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A43u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x7FFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A46u;
            if (nh_scpu_expect_next(cpu, 0x06085230u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06085230u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A46u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A48u;
            if (nh_scpu_expect_next(cpu, 0x06085240u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06085240u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A48u,
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
            if ((return_key != 0x06085310u && (return_key != 0x0610CE70u && return_key != 0x06359BF0u)))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060852B8u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A57u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x04u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A59u;
            if (nh_scpu_expect_next(cpu, 0x060852C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060852C8u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A59u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0x0A5Eu;
                if (nh_scpu_expect_next(cpu, 0x060852F0u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A5Bu;
            if (nh_scpu_expect_next(cpu, 0x060852D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060852D8u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A5Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A5Du;
            if (nh_scpu_expect_next(cpu, 0x060852E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060852E8u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A5Du,
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
            if (((((((((return_key != 0x0609CDF8u && return_key != 0x0609CF18u) && (return_key != 0x060D8FB0u && return_key != 0x06128CC8u)) && ((return_key != 0x06157F98u && return_key != 0x06159160u) && (return_key != 0x0618BC28u && return_key != 0x0618E708u))) && (((return_key != 0x0618E9F8u && return_key != 0x0618EA58u) && (return_key != 0x0618EBF8u && return_key != 0x0618F790u)) && ((return_key != 0x0618F8D0u && return_key != 0x0618FA10u) && (return_key != 0x06196D40u && return_key != 0x061976F0u)))) && ((((return_key != 0x06197B90u && return_key != 0x06197EC8u) && (return_key != 0x061981C0u && return_key != 0x0619CDD8u)) && ((return_key != 0x0619DF20u && return_key != 0x0619E3E0u) && (return_key != 0x0619E5C0u && return_key != 0x0619E708u))) && (((return_key != 0x0619E828u && return_key != 0x0619E930u) && (return_key != 0x0619E9B0u && return_key != 0x0619EAD0u)) && ((return_key != 0x0619F808u && return_key != 0x0619F920u) && (return_key != 0x061A0098u && return_key != 0x061A0208u))))) && (((((return_key != 0x061A03C8u && return_key != 0x061A0A50u) && (return_key != 0x061A28B0u && return_key != 0x061A2F58u)) && ((return_key != 0x061A3590u && return_key != 0x061A45B0u) && (return_key != 0x061A4618u && return_key != 0x061A47B0u))) && (((return_key != 0x061A6108u && return_key != 0x061A7C40u) && (return_key != 0x061A8CE8u && return_key != 0x061A9100u)) && ((return_key != 0x061A99A8u && return_key != 0x061AA198u) && (return_key != 0x061AAAC0u && return_key != 0x061AB040u)))) && ((((return_key != 0x061AB7A0u && return_key != 0x061AB820u) && (return_key != 0x061AC8F8u && return_key != 0x061ACB98u)) && ((return_key != 0x061AE5C8u && return_key != 0x061AEE48u) && (return_key != 0x061CB6F8u && return_key != 0x061CCDA8u))) && (((return_key != 0x061CDD88u && return_key != 0x061CDE08u) && (return_key != 0x06209480u && return_key != 0x062094E0u)) && ((return_key != 0x06209658u && return_key != 0x0620A850u) && (return_key != 0x06220918u && return_key != 0x062D2A88u)))))) && ((((((return_key != 0x062D2C10u && return_key != 0x062D3AF8u) && (return_key != 0x0630A990u && return_key != 0x0630AD60u)) && ((return_key != 0x0630B2B0u && return_key != 0x0630B670u) && (return_key != 0x0630B8A0u && return_key != 0x0630B900u))) && (((return_key != 0x063148A0u && return_key != 0x06316670u) && (return_key != 0x06316888u && return_key != 0x063199A0u)) && ((return_key != 0x06319BC0u && return_key != 0x0631B738u) && (return_key != 0x0631B8F0u && return_key != 0x0631BE28u)))) && ((((return_key != 0x063246F8u && return_key != 0x063247F0u) && (return_key != 0x06328D60u && return_key != 0x06328F60u)) && ((return_key != 0x0632B3C8u && return_key != 0x0633B220u) && (return_key != 0x0633CB60u && return_key != 0x06340DC0u))) && (((return_key != 0x06340F60u && return_key != 0x06341120u) && (return_key != 0x06341240u && return_key != 0x06341620u)) && ((return_key != 0x063427A0u && return_key != 0x06342D40u) && (return_key != 0x06342E30u && return_key != 0x06343068u))))) && (((((return_key != 0x063456E8u && return_key != 0x06345FE0u) && (return_key != 0x063541E0u && return_key != 0x063549A0u)) && ((return_key != 0x06362BE8u && return_key != 0x063A5988u) && (return_key != 0x063A5D38u && return_key != 0x063A7210u))) && (((return_key != 0x063AA700u && return_key != 0x063AA9B8u) && (return_key != 0x063B4318u && return_key != 0x063B4398u)) && ((return_key != 0x063B4E98u && return_key != 0x063B5610u) && (return_key != 0x063B5700u && return_key != 0x063B8A38u)))) && ((((return_key != 0x063B8CA8u && return_key != 0x063B9318u) && (return_key != 0x063BA7D0u && return_key != 0x063BAC28u)) && ((return_key != 0x063BD0B0u && return_key != 0x063BD1E0u) && (return_key != 0x063BD490u && return_key != 0x063BD4E0u))) && (((return_key != 0x063BF860u && return_key != 0x063BFA28u) && (return_key != 0x063C0D78u && return_key != 0x063C2A98u)) && ((return_key != 0x063C71D0u && return_key != 0x063CC700u) && (return_key != 0x063CD140u && (return_key != 0x063D3008u && return_key != 0x063D3CC8u)))))))) && (((((((return_key != 0x063D4030u && return_key != 0x063D81D0u) && (return_key != 0x063E4700u && return_key != 0x063E59D8u)) && ((return_key != 0x063EB4D8u && return_key != 0x063F9808u) && (return_key != 0x0640D830u && return_key != 0x0640E268u))) && (((return_key != 0x0641D6B0u && return_key != 0x0641D7B8u) && (return_key != 0x0641E2F8u && return_key != 0x06425368u)) && ((return_key != 0x06425510u && return_key != 0x06425588u) && (return_key != 0x06425878u && return_key != 0x06432EC8u)))) && ((((return_key != 0x06433010u && return_key != 0x064331C0u) && (return_key != 0x06438F20u && return_key != 0x06439080u)) && ((return_key != 0x064818E0u && return_key != 0x06484308u) && (return_key != 0x06484AD0u && return_key != 0x064850F8u))) && (((return_key != 0x06485680u && return_key != 0x06486E10u) && (return_key != 0x06487F68u && return_key != 0x06488078u)) && ((return_key != 0x06488188u && return_key != 0x064882D8u) && (return_key != 0x06488EC0u && return_key != 0x06489340u))))) && (((((return_key != 0x064896C8u && return_key != 0x0648A548u) && (return_key != 0x0648BB68u && return_key != 0x0648CA20u)) && ((return_key != 0x0648D8A0u && return_key != 0x0648E048u) && (return_key != 0x0648E2E8u && return_key != 0x0648EBD8u))) && (((return_key != 0x0648ED60u && return_key != 0x0648EF20u) && (return_key != 0x0648F010u && return_key != 0x0648F180u)) && ((return_key != 0x0648F270u && return_key != 0x0648F438u) && (return_key != 0x0648F548u && return_key != 0x0648F6D8u)))) && ((((return_key != 0x0648FBD8u && return_key != 0x0648FF08u) && (return_key != 0x06490230u && return_key != 0x06490980u)) && ((return_key != 0x06490B00u && return_key != 0x064911A8u) && (return_key != 0x06491A30u && return_key != 0x06493090u))) && (((return_key != 0x06493168u && return_key != 0x06493338u) && (return_key != 0x06493398u && return_key != 0x064933E8u)) && ((return_key != 0x06493488u && return_key != 0x06493718u) && (return_key != 0x064938C8u && return_key != 0x06493A30u)))))) && ((((((return_key != 0x06493BC0u && return_key != 0x06493D28u) && (return_key != 0x06493E90u && return_key != 0x06494508u)) && ((return_key != 0x06494970u && return_key != 0x06495798u) && (return_key != 0x06498018u && return_key != 0x064982D0u))) && (((return_key != 0x06498BF8u && return_key != 0x064A91C0u) && (return_key != 0x064A9258u && return_key != 0x064ADF28u)) && ((return_key != 0x064B0CD8u && return_key != 0x064B1528u) && (return_key != 0x064EE908u && return_key != 0x064EF050u)))) && ((((return_key != 0x064EF828u && return_key != 0x064F09F0u) && (return_key != 0x064F0C58u && return_key != 0x064F26C0u)) && ((return_key != 0x06512668u && return_key != 0x06512A88u) && (return_key != 0x06513AB8u && return_key != 0x06513CE8u))) && (((return_key != 0x06521288u && return_key != 0x06521468u) && (return_key != 0x06522500u && return_key != 0x06522810u)) && ((return_key != 0x06523040u && return_key != 0x06523578u) && (return_key != 0x06524A30u && return_key != 0x06524CE8u))))) && (((((return_key != 0x06526720u && return_key != 0x065269C0u) && (return_key != 0x06528FE8u && return_key != 0x0652A258u)) && ((return_key != 0x0652AB08u && return_key != 0x0652D770u) && (return_key != 0x0652DB48u && return_key != 0x0654A908u))) && (((return_key != 0x0660F8A8u && return_key != 0x0660FC90u) && (return_key != 0x0660FD30u && return_key != 0x06610280u)) && ((return_key != 0x06612E38u && return_key != 0x066173D0u) && (return_key != 0x06617488u && return_key != 0x06617AD8u)))) && ((((return_key != 0x06617B90u && return_key != 0x0661C460u) && (return_key != 0x06629270u && return_key != 0x06647418u)) && ((return_key != 0x06647848u && return_key != 0x066A4BC0u) && (return_key != 0x066A4C80u && return_key != 0x066ADF40u))) && (((return_key != 0x066AE170u && return_key != 0x066AF350u) && (return_key != 0x066AF4F0u && return_key != 0x066AF928u)) && ((return_key != 0x066BEB88u && return_key != 0x066BEC08u) && (return_key != 0x066BF5C8u && (return_key != 0x066BFBF0u && return_key != 0x066C1DA8u))))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060852F0u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0xFDu, 0x09u, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A5Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x0Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x61u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0x09FDu;
            if (nh_scpu_expect_next(cpu, 0x06084FE8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x06085310u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A62u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x04u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A64u;
            if (nh_scpu_expect_next(cpu, 0x06085320u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06085320u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A64u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A66u;
            if (nh_scpu_expect_next(cpu, 0x06085330u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06085330u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x5Du, 0xFCu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A66u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x0Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x69u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC5Du;
            if (nh_scpu_expect_next(cpu, 0x060FE2E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x06085350u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A6Au,
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
            if (((((((((return_key != 0x0609CDF8u && return_key != 0x0609CF18u) && (return_key != 0x060D8FB0u && return_key != 0x06128CC8u)) && ((return_key != 0x06157F98u && return_key != 0x06159160u) && (return_key != 0x0618BC28u && return_key != 0x0618E708u))) && (((return_key != 0x0618E9F8u && return_key != 0x0618EA58u) && (return_key != 0x0618EBF8u && return_key != 0x0618F790u)) && ((return_key != 0x0618F8D0u && return_key != 0x0618FA10u) && (return_key != 0x06196D40u && return_key != 0x061976F0u)))) && ((((return_key != 0x06197B90u && return_key != 0x06197EC8u) && (return_key != 0x061981C0u && return_key != 0x0619CDD8u)) && ((return_key != 0x0619DF20u && return_key != 0x0619E3E0u) && (return_key != 0x0619E5C0u && return_key != 0x0619E708u))) && (((return_key != 0x0619E828u && return_key != 0x0619E930u) && (return_key != 0x0619E9B0u && return_key != 0x0619EAD0u)) && ((return_key != 0x0619F808u && return_key != 0x0619F920u) && (return_key != 0x061A0098u && return_key != 0x061A0208u))))) && (((((return_key != 0x061A03C8u && return_key != 0x061A0A50u) && (return_key != 0x061A28B0u && return_key != 0x061A2F58u)) && ((return_key != 0x061A3590u && return_key != 0x061A45B0u) && (return_key != 0x061A4618u && return_key != 0x061A47B0u))) && (((return_key != 0x061A6108u && return_key != 0x061A7C40u) && (return_key != 0x061A8CE8u && return_key != 0x061A9100u)) && ((return_key != 0x061A99A8u && return_key != 0x061AA198u) && (return_key != 0x061AAAC0u && return_key != 0x061AB040u)))) && ((((return_key != 0x061AB7A0u && return_key != 0x061AB820u) && (return_key != 0x061AC8F8u && return_key != 0x061ACB98u)) && ((return_key != 0x061AE5C8u && return_key != 0x061AEE48u) && (return_key != 0x061CB6F8u && return_key != 0x061CCDA8u))) && (((return_key != 0x061CDD88u && return_key != 0x061CDE08u) && (return_key != 0x06209480u && return_key != 0x062094E0u)) && ((return_key != 0x06209658u && return_key != 0x0620A850u) && (return_key != 0x06220918u && return_key != 0x062D2A88u)))))) && ((((((return_key != 0x062D2C10u && return_key != 0x062D3AF8u) && (return_key != 0x0630A990u && return_key != 0x0630AD60u)) && ((return_key != 0x0630B2B0u && return_key != 0x0630B670u) && (return_key != 0x0630B8A0u && return_key != 0x0630B900u))) && (((return_key != 0x063148A0u && return_key != 0x06316670u) && (return_key != 0x06316888u && return_key != 0x063199A0u)) && ((return_key != 0x06319BC0u && return_key != 0x0631B738u) && (return_key != 0x0631B8F0u && return_key != 0x0631BE28u)))) && ((((return_key != 0x063246F8u && return_key != 0x063247F0u) && (return_key != 0x06328D60u && return_key != 0x06328F60u)) && ((return_key != 0x0632B3C8u && return_key != 0x0633B220u) && (return_key != 0x0633CB60u && return_key != 0x06340DC0u))) && (((return_key != 0x06340F60u && return_key != 0x06341120u) && (return_key != 0x06341240u && return_key != 0x06341620u)) && ((return_key != 0x063427A0u && return_key != 0x06342D40u) && (return_key != 0x06342E30u && return_key != 0x06343068u))))) && (((((return_key != 0x063456E8u && return_key != 0x06345FE0u) && (return_key != 0x063541E0u && return_key != 0x063549A0u)) && ((return_key != 0x06362BE8u && return_key != 0x063A5988u) && (return_key != 0x063A5D38u && return_key != 0x063A7210u))) && (((return_key != 0x063AA700u && return_key != 0x063AA9B8u) && (return_key != 0x063B4318u && return_key != 0x063B4398u)) && ((return_key != 0x063B4E98u && return_key != 0x063B5610u) && (return_key != 0x063B5700u && return_key != 0x063B8A38u)))) && ((((return_key != 0x063B8CA8u && return_key != 0x063B9318u) && (return_key != 0x063BA7D0u && return_key != 0x063BAC28u)) && ((return_key != 0x063BD0B0u && return_key != 0x063BD1E0u) && (return_key != 0x063BD490u && return_key != 0x063BD4E0u))) && (((return_key != 0x063BF860u && return_key != 0x063BFA28u) && (return_key != 0x063C0D78u && return_key != 0x063C2A98u)) && ((return_key != 0x063C71D0u && return_key != 0x063CC700u) && (return_key != 0x063CD140u && (return_key != 0x063D3008u && return_key != 0x063D3CC8u)))))))) && (((((((return_key != 0x063D4030u && return_key != 0x063D81D0u) && (return_key != 0x063E4700u && return_key != 0x063E59D8u)) && ((return_key != 0x063EB4D8u && return_key != 0x063F9808u) && (return_key != 0x0640D830u && return_key != 0x0640E268u))) && (((return_key != 0x0641D6B0u && return_key != 0x0641D7B8u) && (return_key != 0x0641E2F8u && return_key != 0x06425368u)) && ((return_key != 0x06425510u && return_key != 0x06425588u) && (return_key != 0x06425878u && return_key != 0x06432EC8u)))) && ((((return_key != 0x06433010u && return_key != 0x064331C0u) && (return_key != 0x06438F20u && return_key != 0x06439080u)) && ((return_key != 0x064818E0u && return_key != 0x06484308u) && (return_key != 0x06484AD0u && return_key != 0x064850F8u))) && (((return_key != 0x06485680u && return_key != 0x06486E10u) && (return_key != 0x06487F68u && return_key != 0x06488078u)) && ((return_key != 0x06488188u && return_key != 0x064882D8u) && (return_key != 0x06488EC0u && return_key != 0x06489340u))))) && (((((return_key != 0x064896C8u && return_key != 0x0648A548u) && (return_key != 0x0648BB68u && return_key != 0x0648CA20u)) && ((return_key != 0x0648D8A0u && return_key != 0x0648E048u) && (return_key != 0x0648E2E8u && return_key != 0x0648EBD8u))) && (((return_key != 0x0648ED60u && return_key != 0x0648EF20u) && (return_key != 0x0648F010u && return_key != 0x0648F180u)) && ((return_key != 0x0648F270u && return_key != 0x0648F438u) && (return_key != 0x0648F548u && return_key != 0x0648F6D8u)))) && ((((return_key != 0x0648FBD8u && return_key != 0x0648FF08u) && (return_key != 0x06490230u && return_key != 0x06490980u)) && ((return_key != 0x06490B00u && return_key != 0x064911A8u) && (return_key != 0x06491A30u && return_key != 0x06493090u))) && (((return_key != 0x06493168u && return_key != 0x06493338u) && (return_key != 0x06493398u && return_key != 0x064933E8u)) && ((return_key != 0x06493488u && return_key != 0x06493718u) && (return_key != 0x064938C8u && return_key != 0x06493A30u)))))) && ((((((return_key != 0x06493BC0u && return_key != 0x06493D28u) && (return_key != 0x06493E90u && return_key != 0x06494508u)) && ((return_key != 0x06494970u && return_key != 0x06495798u) && (return_key != 0x06498018u && return_key != 0x064982D0u))) && (((return_key != 0x06498BF8u && return_key != 0x064A91C0u) && (return_key != 0x064A9258u && return_key != 0x064ADF28u)) && ((return_key != 0x064B0CD8u && return_key != 0x064B1528u) && (return_key != 0x064EE908u && return_key != 0x064EF050u)))) && ((((return_key != 0x064EF828u && return_key != 0x064F09F0u) && (return_key != 0x064F0C58u && return_key != 0x064F26C0u)) && ((return_key != 0x06512668u && return_key != 0x06512A88u) && (return_key != 0x06513AB8u && return_key != 0x06513CE8u))) && (((return_key != 0x06521288u && return_key != 0x06521468u) && (return_key != 0x06522500u && return_key != 0x06522810u)) && ((return_key != 0x06523040u && return_key != 0x06523578u) && (return_key != 0x06524A30u && return_key != 0x06524CE8u))))) && (((((return_key != 0x06526720u && return_key != 0x065269C0u) && (return_key != 0x06528FE8u && return_key != 0x0652A258u)) && ((return_key != 0x0652AB08u && return_key != 0x0652D770u) && (return_key != 0x0652DB48u && return_key != 0x0654A908u))) && (((return_key != 0x0660F8A8u && return_key != 0x0660FC90u) && (return_key != 0x0660FD30u && return_key != 0x06610280u)) && ((return_key != 0x06612E38u && return_key != 0x066173D0u) && (return_key != 0x06617488u && return_key != 0x06617AD8u)))) && ((((return_key != 0x06617B90u && return_key != 0x0661C460u) && (return_key != 0x06629270u && return_key != 0x06647418u)) && ((return_key != 0x06647848u && return_key != 0x066A4BC0u) && (return_key != 0x066A4C80u && return_key != 0x066ADF40u))) && (((return_key != 0x066AE170u && return_key != 0x066AF350u) && (return_key != 0x066AF4F0u && return_key != 0x066AF928u)) && ((return_key != 0x066BEB88u && return_key != 0x066BEC08u) && (return_key != 0x066BF5C8u && (return_key != 0x066BFBF0u && return_key != 0x066C1DA8u))))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06085358u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A6Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x04u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A6Du;
            if (nh_scpu_expect_next(cpu, 0x06085368u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06085368u: {
            static const uint8_t expected_epoch[] = { 0xC9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A6Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - 0x0000u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A70u;
            if (nh_scpu_expect_next(cpu, 0x06085380u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06085380u: {
            static const uint8_t expected_epoch[] = { 0x10u, 0x07u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A70u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0x0A79u;
                if (nh_scpu_expect_next(cpu, 0x060853C8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A72u;
            if (nh_scpu_expect_next(cpu, 0x06085390u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06085390u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0xFFu, 0xFFu };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A72u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0xFFFFu;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A75u;
            if (nh_scpu_expect_next(cpu, 0x060853A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060853A8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A75u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A77u;
            if (nh_scpu_expect_next(cpu, 0x060853B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060853B8u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A77u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A83u;
            if (nh_scpu_expect_next(cpu, 0x06085418u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060853C8u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A79u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A7Bu;
            if (nh_scpu_expect_next(cpu, 0x060853D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060853D8u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A7Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x04u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A7Du;
            if (nh_scpu_expect_next(cpu, 0x060853E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060853E8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A7Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0x0A7Fu;
            if (nh_scpu_expect_next(cpu, 0x060853F8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060853F8u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x26u, 0xFEu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A7Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x0Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x82u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE26u;
            if (nh_scpu_expect_next(cpu, 0x060FF130u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x06085418u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC10A83u,
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
            if ((((return_key != 0x061B3DF8u && return_key != 0x061B4070u) && (return_key != 0x062AA728u && (return_key != 0x064B5020u && return_key != 0x064B5208u))) && ((return_key != 0x064B52D0u && return_key != 0x064B54B8u) && (return_key != 0x064B98F8u && (return_key != 0x064B9DF8u && return_key != 0x064B9EE8u)))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        default: return NH_SCPU_NOT_MINE;
    }
}
