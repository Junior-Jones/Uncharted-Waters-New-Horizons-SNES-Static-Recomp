/* Generated direct New Horizons S-CPU authority; do not edit. */
#include "nh_v07_generated.h"

NHScpuExecResult nh_v07_shard_00C6AA(NHScpuState *cpu, const NHScpuBus *bus) {
    switch (nh_scpu_context_key(cpu)) {
        case 0x06355008u: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA01u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC6u;
                cpu->pc = 0xAA05u;
                if (nh_scpu_expect_next(cpu, 0x06355028u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA03u;
            if (nh_scpu_expect_next(cpu, 0x06355018u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06355018u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0xF2u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA03u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xA9F7u;
            if (nh_scpu_expect_next(cpu, 0x06354FB8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06355028u: {
            static const uint8_t expected_epoch[] = { 0x82u, 0x60u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA05u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA68u;
            if (nh_scpu_expect_next(cpu, 0x06355340u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06355040u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA08u,
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
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA09u;
            if (nh_scpu_expect_next(cpu, 0x06355048u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355048u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA09u,
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
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA0Au;
            if (nh_scpu_expect_next(cpu, 0x06355050u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355050u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA0Au,
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
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA0Bu;
            if (nh_scpu_expect_next(cpu, 0x06355058u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355058u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA0Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u, return_bank = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &return_bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            cpu->pbr = return_bank;
            if (nh_scpu_context_key(cpu) != 0x06356320u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06355060u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA0Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x01u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA0Eu;
            if (nh_scpu_expect_next(cpu, 0x06355070u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355070u: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x07u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA0Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC6u;
                cpu->pc = 0xAA17u;
                if (nh_scpu_expect_next(cpu, 0x063550B8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA10u;
            if (nh_scpu_expect_next(cpu, 0x06355080u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06355080u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA10u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x01u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA12u;
            if (nh_scpu_expect_next(cpu, 0x06355090u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355090u: {
            static const uint8_t expected_epoch[] = { 0x3Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA12u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA13u;
            if (nh_scpu_expect_next(cpu, 0x06355098u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06355098u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA13u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA15u;
            if (nh_scpu_expect_next(cpu, 0x063550A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x063550A8u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x05u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA15u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA1Cu;
            if (nh_scpu_expect_next(cpu, 0x063550E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x063550B8u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x0Fu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA17u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x000Fu;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA1Au;
            if (nh_scpu_expect_next(cpu, 0x063550D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x063550D0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA1Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA1Cu;
            if (nh_scpu_expect_next(cpu, 0x063550E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x063550E0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA1Cu,
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
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA1Eu;
            if (nh_scpu_expect_next(cpu, 0x063550F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x063550F0u: {
            static const uint8_t expected_epoch[] = { 0x83u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA1Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = ((uint32_t)cpu->s + 0x01u) & 0xFFFFu;
            if (nh_scpu_write8(cpu, bus, address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFu, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA20u;
            if (nh_scpu_expect_next(cpu, 0x06355100u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355100u: {
            static const uint8_t expected_epoch[] = { 0x82u, 0x76u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA20u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA99u;
            if (nh_scpu_expect_next(cpu, 0x063554C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06355118u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA23u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x01u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA25u;
            if (nh_scpu_expect_next(cpu, 0x06355128u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355128u: {
            static const uint8_t expected_epoch[] = { 0xC9u, 0x0Fu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA25u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - 0x000Fu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= 0x000Fu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA28u;
            if (nh_scpu_expect_next(cpu, 0x06355140u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06355140u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA28u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC6u;
                cpu->pc = 0xAA2Eu;
                if (nh_scpu_expect_next(cpu, 0x06355170u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA2Au;
            if (nh_scpu_expect_next(cpu, 0x06355150u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06355150u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA2Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA2Cu;
            if (nh_scpu_expect_next(cpu, 0x06355160u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06355160u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x05u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA2Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA33u;
            if (nh_scpu_expect_next(cpu, 0x06355198u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06355170u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA2Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x01u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA30u;
            if (nh_scpu_expect_next(cpu, 0x06355180u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355180u: {
            static const uint8_t expected_epoch[] = { 0x1Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA30u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA31u;
            if (nh_scpu_expect_next(cpu, 0x06355188u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06355188u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA31u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA33u;
            if (nh_scpu_expect_next(cpu, 0x06355198u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06355198u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA33u,
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
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA35u;
            if (nh_scpu_expect_next(cpu, 0x063551A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x063551A8u: {
            static const uint8_t expected_epoch[] = { 0x83u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA35u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = ((uint32_t)cpu->s + 0x01u) & 0xFFFFu;
            if (nh_scpu_write8(cpu, bus, address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFu, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA37u;
            if (nh_scpu_expect_next(cpu, 0x063551B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x063551B8u: {
            static const uint8_t expected_epoch[] = { 0x82u, 0x5Fu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA37u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA99u;
            if (nh_scpu_expect_next(cpu, 0x063554C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x063551D0u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA3Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x03u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA3Cu;
            if (nh_scpu_expect_next(cpu, 0x063551E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x063551E0u: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x07u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA3Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC6u;
                cpu->pc = 0xAA45u;
                if (nh_scpu_expect_next(cpu, 0x06355228u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA3Eu;
            if (nh_scpu_expect_next(cpu, 0x063551F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x063551F0u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA3Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x03u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA40u;
            if (nh_scpu_expect_next(cpu, 0x06355200u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355200u: {
            static const uint8_t expected_epoch[] = { 0x3Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA40u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA41u;
            if (nh_scpu_expect_next(cpu, 0x06355208u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06355208u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA41u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA43u;
            if (nh_scpu_expect_next(cpu, 0x06355218u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06355218u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x05u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA43u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA4Au;
            if (nh_scpu_expect_next(cpu, 0x06355250u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06355228u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x0Du, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA45u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x000Du;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA48u;
            if (nh_scpu_expect_next(cpu, 0x06355240u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06355240u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA48u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA4Au;
            if (nh_scpu_expect_next(cpu, 0x06355250u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06355250u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA4Au,
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
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA4Cu;
            if (nh_scpu_expect_next(cpu, 0x06355260u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06355260u: {
            static const uint8_t expected_epoch[] = { 0x83u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA4Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = ((uint32_t)cpu->s + 0x03u) & 0xFFFFu;
            if (nh_scpu_write8(cpu, bus, address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFu, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA4Eu;
            if (nh_scpu_expect_next(cpu, 0x06355270u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355270u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x49u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA4Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA99u;
            if (nh_scpu_expect_next(cpu, 0x063554C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06355280u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA50u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x03u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA52u;
            if (nh_scpu_expect_next(cpu, 0x06355290u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355290u: {
            static const uint8_t expected_epoch[] = { 0xC9u, 0x0Du, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA52u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - 0x000Du);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= 0x000Du) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA55u;
            if (nh_scpu_expect_next(cpu, 0x063552A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x063552A8u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA55u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC6u;
                cpu->pc = 0xAA5Bu;
                if (nh_scpu_expect_next(cpu, 0x063552D8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA57u;
            if (nh_scpu_expect_next(cpu, 0x063552B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x063552B8u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA57u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA59u;
            if (nh_scpu_expect_next(cpu, 0x063552C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x063552C8u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x05u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA59u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA60u;
            if (nh_scpu_expect_next(cpu, 0x06355300u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x063552D8u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA5Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x03u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA5Du;
            if (nh_scpu_expect_next(cpu, 0x063552E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x063552E8u: {
            static const uint8_t expected_epoch[] = { 0x1Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA5Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA5Eu;
            if (nh_scpu_expect_next(cpu, 0x063552F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x063552F0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA5Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA60u;
            if (nh_scpu_expect_next(cpu, 0x06355300u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06355300u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA60u,
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
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA62u;
            if (nh_scpu_expect_next(cpu, 0x06355310u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06355310u: {
            static const uint8_t expected_epoch[] = { 0x83u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA62u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = ((uint32_t)cpu->s + 0x03u) & 0xFFFFu;
            if (nh_scpu_write8(cpu, bus, address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFu, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA64u;
            if (nh_scpu_expect_next(cpu, 0x06355320u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355320u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x33u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA64u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA99u;
            if (nh_scpu_expect_next(cpu, 0x063554C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06355330u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x31u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA66u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA99u;
            if (nh_scpu_expect_next(cpu, 0x063554C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06355340u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x05u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA68u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x05u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA6Au;
            if (nh_scpu_expect_next(cpu, 0x06355350u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355350u: {
            static const uint8_t expected_epoch[] = { 0xC9u, 0x00u, 0x80u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA6Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - 0x8000u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= 0x8000u) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA6Du;
            if (nh_scpu_expect_next(cpu, 0x06355368u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06355368u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA6Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC6u;
                cpu->pc = 0xAA72u;
                if (nh_scpu_expect_next(cpu, 0x06355390u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA6Fu;
            if (nh_scpu_expect_next(cpu, 0x06355378u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06355378u: {
            static const uint8_t expected_epoch[] = { 0x82u, 0x96u, 0xFFu };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA6Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA08u;
            if (nh_scpu_expect_next(cpu, 0x06355040u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06355390u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x05u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA72u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x05u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA74u;
            if (nh_scpu_expect_next(cpu, 0x063553A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x063553A0u: {
            static const uint8_t expected_epoch[] = { 0xC9u, 0x00u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA74u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - 0x0200u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= 0x0200u) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA77u;
            if (nh_scpu_expect_next(cpu, 0x063553B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x063553B8u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA77u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC6u;
                cpu->pc = 0xAA7Cu;
                if (nh_scpu_expect_next(cpu, 0x063553E0u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA79u;
            if (nh_scpu_expect_next(cpu, 0x063553C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x063553C8u: {
            static const uint8_t expected_epoch[] = { 0x82u, 0x90u, 0xFFu };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA79u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA0Cu;
            if (nh_scpu_expect_next(cpu, 0x06355060u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x063553E0u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x05u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA7Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x05u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA7Eu;
            if (nh_scpu_expect_next(cpu, 0x063553F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x063553F0u: {
            static const uint8_t expected_epoch[] = { 0xC9u, 0x00u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA7Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - 0x0100u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= 0x0100u) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA81u;
            if (nh_scpu_expect_next(cpu, 0x06355408u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06355408u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA81u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC6u;
                cpu->pc = 0xAA86u;
                if (nh_scpu_expect_next(cpu, 0x06355430u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA83u;
            if (nh_scpu_expect_next(cpu, 0x06355418u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06355418u: {
            static const uint8_t expected_epoch[] = { 0x82u, 0x9Du, 0xFFu };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA83u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA23u;
            if (nh_scpu_expect_next(cpu, 0x06355118u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06355430u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x05u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA86u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x05u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA88u;
            if (nh_scpu_expect_next(cpu, 0x06355440u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355440u: {
            static const uint8_t expected_epoch[] = { 0xC9u, 0x00u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA88u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - 0x0800u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= 0x0800u) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA8Bu;
            if (nh_scpu_expect_next(cpu, 0x06355458u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06355458u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA8Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC6u;
                cpu->pc = 0xAA90u;
                if (nh_scpu_expect_next(cpu, 0x06355480u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA8Du;
            if (nh_scpu_expect_next(cpu, 0x06355468u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06355468u: {
            static const uint8_t expected_epoch[] = { 0x82u, 0xAAu, 0xFFu };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA8Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA3Au;
            if (nh_scpu_expect_next(cpu, 0x063551D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06355480u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x05u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA90u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x05u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA92u;
            if (nh_scpu_expect_next(cpu, 0x06355490u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355490u: {
            static const uint8_t expected_epoch[] = { 0xC9u, 0x00u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA92u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - 0x0400u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= 0x0400u) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA95u;
            if (nh_scpu_expect_next(cpu, 0x063554A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x063554A8u: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0xB9u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA95u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC6u;
                cpu->pc = 0xAA50u;
                if (nh_scpu_expect_next(cpu, 0x06355280u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA97u;
            if (nh_scpu_expect_next(cpu, 0x063554B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x063554B8u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0xCDu };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA97u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAA66u;
            if (nh_scpu_expect_next(cpu, 0x06355330u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x063554C8u: {
            static const uint8_t expected_epoch[] = { 0x82u, 0x15u, 0xFFu };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AA99u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xA9B1u;
            if (nh_scpu_expect_next(cpu, 0x06354D88u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06355500u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAA0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAA2u;
            if (nh_scpu_expect_next(cpu, 0x06355512u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06355512u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAA2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x02u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAA4u;
            if (nh_scpu_expect_next(cpu, 0x06355522u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06355522u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x16u, 0x20u, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAA4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x7E2016u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAA8u;
            if (nh_scpu_expect_next(cpu, 0x06355542u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355542u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAA8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAAAu;
            if (nh_scpu_expect_next(cpu, 0x06355550u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06355550u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x02u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAAAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0002u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAADu;
            if (nh_scpu_expect_next(cpu, 0x06355568u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06355568u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x66u, 0xFCu, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAADu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x7EFC66u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, 0x7EFC67u, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAB1u;
            if (nh_scpu_expect_next(cpu, 0x06355588u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06355588u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAB1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAB4u;
            if (nh_scpu_expect_next(cpu, 0x063555A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x063555A0u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x70u, 0xFCu, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAB4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x7EFC70u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, 0x7EFC71u, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAB8u;
            if (nh_scpu_expect_next(cpu, 0x063555C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x063555C0u: {
            static const uint8_t expected_epoch[] = { 0xF4u, 0x0Au, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAB8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x00u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x0Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAABBu;
            if (nh_scpu_expect_next(cpu, 0x063555D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x063555D8u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x17u, 0xBEu, 0xCCu };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AABBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC6u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xAAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xBEu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xCCu;
            cpu->pc = 0xBE17u;
            if (nh_scpu_expect_next(cpu, 0x0665F0B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x063555F8u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AABFu,
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
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAC0u;
            if (nh_scpu_expect_next(cpu, 0x06355600u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355600u: {
            static const uint8_t expected_epoch[] = { 0xF4u, 0x0Bu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAC0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x00u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x0Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAC3u;
            if (nh_scpu_expect_next(cpu, 0x06355618u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355618u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x17u, 0xBEu, 0xCCu };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAC3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC6u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xAAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC6u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xCCu;
            cpu->pc = 0xBE17u;
            if (nh_scpu_expect_next(cpu, 0x0665F0B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x06355638u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAC7u,
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
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAC8u;
            if (nh_scpu_expect_next(cpu, 0x06355640u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355640u: {
            static const uint8_t expected_epoch[] = { 0xF4u, 0x0Cu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAC8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x00u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x0Cu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAACBu;
            if (nh_scpu_expect_next(cpu, 0x06355658u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355658u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x17u, 0xBEu, 0xCCu };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AACBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC6u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xAAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xCEu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xCCu;
            cpu->pc = 0xBE17u;
            if (nh_scpu_expect_next(cpu, 0x0665F0B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x06355678u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AACFu,
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
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAD0u;
            if (nh_scpu_expect_next(cpu, 0x06355680u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355680u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x68u, 0x00u, 0xCCu };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAD0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC6u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xAAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xD3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xCCu;
            cpu->pc = 0x0068u;
            if (nh_scpu_expect_next(cpu, 0x06600340u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x063556A0u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAD4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAD6u;
            if (nh_scpu_expect_next(cpu, 0x063556B2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x063556B2u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAD6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x02u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAD8u;
            if (nh_scpu_expect_next(cpu, 0x063556C2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x063556C2u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x16u, 0x20u, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAD8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x7E2016u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAADCu;
            if (nh_scpu_expect_next(cpu, 0x063556E2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x063556E2u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AADCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAADEu;
            if (nh_scpu_expect_next(cpu, 0x063556F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x063556F0u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x01u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AADEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0001u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAE1u;
            if (nh_scpu_expect_next(cpu, 0x06355708u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06355708u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x66u, 0xFCu, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAE1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x7EFC66u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, 0x7EFC67u, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAE5u;
            if (nh_scpu_expect_next(cpu, 0x06355728u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06355728u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAE5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAE8u;
            if (nh_scpu_expect_next(cpu, 0x06355740u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06355740u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x70u, 0xFCu, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAE8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x7EFC70u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, 0x7EFC71u, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAECu;
            if (nh_scpu_expect_next(cpu, 0x06355760u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06355760u: {
            static const uint8_t expected_epoch[] = { 0xF4u, 0x02u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAECu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x00u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x02u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAEFu;
            if (nh_scpu_expect_next(cpu, 0x06355778u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06355778u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x17u, 0xBEu, 0xCCu };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAEFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC6u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xAAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xF2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xCCu;
            cpu->pc = 0xBE17u;
            if (nh_scpu_expect_next(cpu, 0x0665F0B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x06355798u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAF3u,
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
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAF4u;
            if (nh_scpu_expect_next(cpu, 0x063557A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x063557A0u: {
            static const uint8_t expected_epoch[] = { 0xF4u, 0x78u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAF4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x00u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x78u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAF7u;
            if (nh_scpu_expect_next(cpu, 0x063557B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x063557B8u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x17u, 0xBEu, 0xCCu };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAF7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC6u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xAAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xCCu;
            cpu->pc = 0xBE17u;
            if (nh_scpu_expect_next(cpu, 0x0665F0B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x063557D8u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAFBu,
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
            cpu->pbr = 0xC6u;
            cpu->pc = 0xAAFCu;
            if (nh_scpu_expect_next(cpu, 0x063557E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x063557E0u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x68u, 0x00u, 0xCCu };
            if (nh_scpu_guard_code(cpu, bus, 0xC6AAFCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC6u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xAAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFFu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xCCu;
            cpu->pc = 0x0068u;
            if (nh_scpu_expect_next(cpu, 0x06600340u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        default: return NH_SCPU_NOT_MINE;
    }
}
