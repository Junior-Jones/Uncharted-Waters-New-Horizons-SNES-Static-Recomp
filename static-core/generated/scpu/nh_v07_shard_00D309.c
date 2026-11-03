/* Generated direct New Horizons S-CPU authority; do not edit. */
#include "nh_v07_generated.h"

NHScpuExecResult nh_v07_shard_00D309(NHScpuState *cpu, const NHScpuBus *bus) {
    switch (nh_scpu_context_key(cpu)) {
        case 0x06984818u: {
            static const uint8_t expected_epoch[] = { 0xC6u, 0x4Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30903u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00004Cu) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00004Du) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t result = (uint16_t)(value - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00004Du) & 0xFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00004Cu) & 0xFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0905u;
            if (nh_scpu_expect_next(cpu, 0x06984828u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984828u: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30905u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xD3u;
                cpu->pc = 0x090Bu;
                if (nh_scpu_expect_next(cpu, 0x06984858u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0907u;
            if (nh_scpu_expect_next(cpu, 0x06984838u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984838u: {
            static const uint8_t expected_epoch[] = { 0x5Cu, 0x96u, 0x08u, 0xD3u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30907u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0896u;
            if (nh_scpu_expect_next(cpu, 0x069844B0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06984858u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xD3090Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            cpu->x &= 0x00FFu;
            cpu->y &= 0x00FFu;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x090Du;
            if (nh_scpu_expect_next(cpu, 0x0698486Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0698486Bu: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD3090Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x00u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x090Fu;
            if (nh_scpu_expect_next(cpu, 0x0698487Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0698487Bu: {
            static const uint8_t expected_epoch[] = { 0xBBu };
            if (nh_scpu_guard_code(cpu, bus, 0xD3090Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint8_t)(cpu->y);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0910u;
            if (nh_scpu_expect_next(cpu, 0x06984883u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984883u: {
            static const uint8_t expected_epoch[] = { 0xBFu, 0x00u, 0x1Au, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30910u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = (0x7E1A00u + (uint32_t)(cpu->x & 0x00FFu)) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0914u;
            if (nh_scpu_expect_next(cpu, 0x069848A3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x069848A3u: {
            static const uint8_t expected_epoch[] = { 0xC9u, 0xFFu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30914u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t value = 0xFFu;
            uint8_t result;
            const uint8_t left = (uint8_t)cpu->a;
            result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= value) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x80u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0916u;
            if (nh_scpu_expect_next(cpu, 0x069848B3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069848B3u: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30916u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xD3u;
                cpu->pc = 0x091Eu;
                if (nh_scpu_expect_next(cpu, 0x069848F3u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0918u;
            if (nh_scpu_expect_next(cpu, 0x069848C3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069848C3u: {
            static const uint8_t expected_epoch[] = { 0xAAu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30918u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint8_t)cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0919u;
            if (nh_scpu_expect_next(cpu, 0x069848CBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069848CBu: {
            static const uint8_t expected_epoch[] = { 0x98u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30919u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | (uint8_t)cpu->y);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)((uint8_t)cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)((uint8_t)cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x091Au;
            if (nh_scpu_expect_next(cpu, 0x069848D3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069848D3u: {
            static const uint8_t expected_epoch[] = { 0x9Fu, 0x80u, 0x1Au, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xD3091Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = (0x7E1A80u + (uint32_t)(cpu->x & 0x00FFu)) & 0xFFFFFFu;
            if (nh_scpu_write8(cpu, bus, address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x091Eu;
            if (nh_scpu_expect_next(cpu, 0x069848F3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x069848F3u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xD3091Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint8_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x091Fu;
            if (nh_scpu_expect_next(cpu, 0x069848FBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069848FBu: {
            static const uint8_t expected_epoch[] = { 0xC0u, 0x80u };
            if (nh_scpu_guard_code(cpu, bus, 0xD3091Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t result = (uint8_t)(cpu->y - 0x80u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (cpu->y >= 0x80u) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x80u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0921u;
            if (nh_scpu_expect_next(cpu, 0x0698490Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0698490Bu: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0xECu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30921u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xD3u;
                cpu->pc = 0x090Fu;
                if (nh_scpu_expect_next(cpu, 0x0698487Bu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0923u;
            if (nh_scpu_expect_next(cpu, 0x0698491Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0698491Bu: {
            static const uint8_t expected_epoch[] = { 0x28u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30923u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_pull8(cpu, bus, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = value;
            if ((cpu->p & NH_P_X) != 0u) {
                cpu->x &= 0x00FFu;
                cpu->y &= 0x00FFu;
            }
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0924u;
            if (nh_scpu_expect_next(cpu, 0x06984922u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06984922u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30924u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            if (nh_scpu_context_key(cpu) != 0x06981892u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0698492Au: {
            static const uint8_t expected_epoch[] = { 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30925u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, cpu->p) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0926u;
            if (nh_scpu_expect_next(cpu, 0x06984932u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984932u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30926u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x30u);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0928u;
            if (nh_scpu_expect_next(cpu, 0x06984940u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984940u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x1Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30928u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00001Cu) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00001Du) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x092Au;
            if (nh_scpu_expect_next(cpu, 0x06984950u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984950u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0xFFu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD3092Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x092Du;
            if (nh_scpu_expect_next(cpu, 0x06984968u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984968u: {
            static const uint8_t expected_epoch[] = { 0x49u, 0xFFu, 0xFFu };
            if (nh_scpu_guard_code(cpu, bus, 0xD3092Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a ^ 0xFFFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0930u;
            if (nh_scpu_expect_next(cpu, 0x06984980u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984980u: {
            static const uint8_t expected_epoch[] = { 0x1Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30930u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0931u;
            if (nh_scpu_expect_next(cpu, 0x06984988u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984988u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30931u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0932u;
            if (nh_scpu_expect_next(cpu, 0x06984990u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984990u: {
            static const uint8_t expected_epoch[] = { 0x69u, 0x00u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30932u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0100u;
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
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0935u;
            if (nh_scpu_expect_next(cpu, 0x069849A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x069849A8u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0xFFu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30935u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0938u;
            if (nh_scpu_expect_next(cpu, 0x069849C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x069849C0u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30938u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0939u;
            if (nh_scpu_expect_next(cpu, 0x069849C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069849C8u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x1Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30939u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint16_t right, result;
            const uint16_t left = cpu->a;
            uint32_t sum;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00001Cu) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00001Du) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            right = (uint16_t)(((uint16_t)high << 8u) | low);
            sum = (uint32_t)left + (uint32_t)right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            result = (uint16_t)sum;
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (sum > 0xFFFFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            if (((uint16_t)(~(left ^ right)) & (uint16_t)(left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x093Bu;
            if (nh_scpu_expect_next(cpu, 0x069849D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069849D8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x1Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD3093Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00001Cu) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00001Du) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x093Du;
            if (nh_scpu_expect_next(cpu, 0x069849E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069849E8u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xD3093Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            cpu->x &= 0x00FFu;
            cpu->y &= 0x00FFu;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x093Fu;
            if (nh_scpu_expect_next(cpu, 0x069849FBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x069849FBu: {
            static const uint8_t expected_epoch[] = { 0xA2u, 0x7Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xD3093Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = 0x7Fu;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0941u;
            if (nh_scpu_expect_next(cpu, 0x06984A0Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984A0Bu: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30941u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000030u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0943u;
            if (nh_scpu_expect_next(cpu, 0x06984A1Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984A1Bu: {
            static const uint8_t expected_epoch[] = { 0xBFu, 0x80u, 0x1Au, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30943u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = (0x7E1A80u + (uint32_t)(cpu->x & 0x00FFu)) & 0xFFFFFFu;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0947u;
            if (nh_scpu_expect_next(cpu, 0x06984A3Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06984A3Bu: {
            static const uint8_t expected_epoch[] = { 0xC9u, 0xFFu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30947u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t value = 0xFFu;
            uint8_t result;
            const uint8_t left = (uint8_t)cpu->a;
            result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= value) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x80u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0949u;
            if (nh_scpu_expect_next(cpu, 0x06984A4Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984A4Bu: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30949u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xD3u;
                cpu->pc = 0x094Du;
                if (nh_scpu_expect_next(cpu, 0x06984A6Bu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xD3u;
            cpu->pc = 0x094Bu;
            if (nh_scpu_expect_next(cpu, 0x06984A5Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984A5Bu: {
            static const uint8_t expected_epoch[] = { 0xE6u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xD3094Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000030u) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            value = (uint8_t)(value + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000030u) & 0xFFFFu), value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x094Du;
            if (nh_scpu_expect_next(cpu, 0x06984A6Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984A6Bu: {
            static const uint8_t expected_epoch[] = { 0xCAu };
            if (nh_scpu_guard_code(cpu, bus, 0xD3094Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint8_t)(cpu->x - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x094Eu;
            if (nh_scpu_expect_next(cpu, 0x06984A73u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984A73u: {
            static const uint8_t expected_epoch[] = { 0x10u, 0xF3u };
            if (nh_scpu_guard_code(cpu, bus, 0xD3094Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) == 0u) {
                cpu->pbr = 0xD3u;
                cpu->pc = 0x0943u;
                if (nh_scpu_expect_next(cpu, 0x06984A1Bu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0950u;
            if (nh_scpu_expect_next(cpu, 0x06984A83u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984A83u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30950u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x30u);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0952u;
            if (nh_scpu_expect_next(cpu, 0x06984A90u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984A90u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30952u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000030u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000031u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0954u;
            if (nh_scpu_expect_next(cpu, 0x06984AA0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984AA0u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0xFFu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30954u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0957u;
            if (nh_scpu_expect_next(cpu, 0x06984AB8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984AB8u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30957u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0958u;
            if (nh_scpu_expect_next(cpu, 0x06984AC0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984AC0u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30958u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0959u;
            if (nh_scpu_expect_next(cpu, 0x06984AC8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984AC8u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30959u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x095Au;
            if (nh_scpu_expect_next(cpu, 0x06984AD0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984AD0u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x1Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD3095Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint16_t right, result;
            const uint16_t left = cpu->a;
            uint32_t sum;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00001Cu) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00001Du) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            right = (uint16_t)(((uint16_t)high << 8u) | low);
            sum = (uint32_t)left + (uint32_t)right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            result = (uint16_t)sum;
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (sum > 0xFFFFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            if (((uint16_t)(~(left ^ right)) & (uint16_t)(left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x095Cu;
            if (nh_scpu_expect_next(cpu, 0x06984AE0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984AE0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xD3095Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000030u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000031u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x095Eu;
            if (nh_scpu_expect_next(cpu, 0x06984AF0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984AF0u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x02u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xD3095Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0802u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0961u;
            if (nh_scpu_expect_next(cpu, 0x06984B08u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984B08u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x64u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30961u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000064u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000065u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0963u;
            if (nh_scpu_expect_next(cpu, 0x06984B18u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984B18u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x1Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30963u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00001Cu) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00001Du) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0965u;
            if (nh_scpu_expect_next(cpu, 0x06984B28u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984B28u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30965u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000068u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000069u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0967u;
            if (nh_scpu_expect_next(cpu, 0x06984B38u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984B38u: {
            static const uint8_t expected_epoch[] = { 0x20u, 0x67u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30967u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x09u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x69u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0267u;
            if (nh_scpu_expect_next(cpu, 0x06981338u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06984B50u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD3096Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x096Cu;
            if (nh_scpu_expect_next(cpu, 0x06984B60u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984B60u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x50u };
            if (nh_scpu_guard_code(cpu, bus, 0xD3096Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000050u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000051u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x096Eu;
            if (nh_scpu_expect_next(cpu, 0x06984B70u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984B70u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x0Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD3096Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Cu) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Du) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0970u;
            if (nh_scpu_expect_next(cpu, 0x06984B80u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984B80u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x52u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30970u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000052u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000053u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0972u;
            if (nh_scpu_expect_next(cpu, 0x06984B90u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984B90u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x80u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30972u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0080u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0975u;
            if (nh_scpu_expect_next(cpu, 0x06984BA8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984BA8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x4Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30975u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00004Cu) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00004Du) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0977u;
            if (nh_scpu_expect_next(cpu, 0x06984BB8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984BB8u: {
            static const uint8_t expected_epoch[] = { 0xA2u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30977u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x097Au;
            if (nh_scpu_expect_next(cpu, 0x06984BD0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984BD0u: {
            static const uint8_t expected_epoch[] = { 0xBFu, 0x80u, 0x1Au, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xD3097Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = (0x7E1A80u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x097Eu;
            if (nh_scpu_expect_next(cpu, 0x06984BF0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06984BF0u: {
            static const uint8_t expected_epoch[] = { 0xE8u };
            if (nh_scpu_guard_code(cpu, bus, 0xD3097Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(cpu->x + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x097Fu;
            if (nh_scpu_expect_next(cpu, 0x06984BF8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984BF8u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0xFFu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD3097Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0982u;
            if (nh_scpu_expect_next(cpu, 0x06984C10u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984C10u: {
            static const uint8_t expected_epoch[] = { 0xC9u, 0xFFu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30982u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= 0x00FFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0985u;
            if (nh_scpu_expect_next(cpu, 0x06984C28u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984C28u: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x28u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30985u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xD3u;
                cpu->pc = 0x09AFu;
                if (nh_scpu_expect_next(cpu, 0x06984D78u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0987u;
            if (nh_scpu_expect_next(cpu, 0x06984C38u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984C38u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30987u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0988u;
            if (nh_scpu_expect_next(cpu, 0x06984C40u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984C40u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30988u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0989u;
            if (nh_scpu_expect_next(cpu, 0x06984C48u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984C48u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30989u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x098Au;
            if (nh_scpu_expect_next(cpu, 0x06984C50u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984C50u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xD3098Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x098Bu;
            if (nh_scpu_expect_next(cpu, 0x06984C58u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984C58u: {
            static const uint8_t expected_epoch[] = { 0x69u, 0x06u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD3098Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0006u;
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
            cpu->pbr = 0xD3u;
            cpu->pc = 0x098Eu;
            if (nh_scpu_expect_next(cpu, 0x06984C70u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984C70u: {
            static const uint8_t expected_epoch[] = { 0xA8u };
            if (nh_scpu_guard_code(cpu, bus, 0xD3098Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x098Fu;
            if (nh_scpu_expect_next(cpu, 0x06984C78u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984C78u: {
            static const uint8_t expected_epoch[] = { 0xB7u, 0x50u };
            if (nh_scpu_guard_code(cpu, bus, 0xD3098Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000050u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000051u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_bank = 0u, low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000052u) & 0xFFFFu), &pointer_bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) | ((uint32_t)pointer_high << 8u) | pointer_low) + cpu->y) & 0xFFFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0991u;
            if (nh_scpu_expect_next(cpu, 0x06984C88u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984C88u: {
            static const uint8_t expected_epoch[] = { 0xEBu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30991u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)((uint8_t)cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)((uint8_t)cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0992u;
            if (nh_scpu_expect_next(cpu, 0x06984C90u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984C90u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30992u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0993u;
            if (nh_scpu_expect_next(cpu, 0x06984C98u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984C98u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30993u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint16_t right, result;
            const uint16_t left = cpu->a;
            uint32_t sum;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000030u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000031u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            right = (uint16_t)(((uint16_t)high << 8u) | low);
            sum = (uint32_t)left + (uint32_t)right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            result = (uint16_t)sum;
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (sum > 0xFFFFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            if (((uint16_t)(~(left ^ right)) & (uint16_t)(left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0995u;
            if (nh_scpu_expect_next(cpu, 0x06984CA8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984CA8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x3Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30995u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00003Cu) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00003Du) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0997u;
            if (nh_scpu_expect_next(cpu, 0x06984CB8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984CB8u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30997u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000030u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000031u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0999u;
            if (nh_scpu_expect_next(cpu, 0x06984CC8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984CC8u: {
            static const uint8_t expected_epoch[] = { 0x20u, 0x49u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30999u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x09u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x9Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0249u;
            if (nh_scpu_expect_next(cpu, 0x06981248u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06984CE0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x3Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD3099Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00003Cu) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00003Du) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x099Eu;
            if (nh_scpu_expect_next(cpu, 0x06984CF0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984CF0u: {
            static const uint8_t expected_epoch[] = { 0x20u, 0x49u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xD3099Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x09u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xA0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0249u;
            if (nh_scpu_expect_next(cpu, 0x06981248u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06984D08u: {
            static const uint8_t expected_epoch[] = { 0x88u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309A1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09A2u;
            if (nh_scpu_expect_next(cpu, 0x06984D10u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984D10u: {
            static const uint8_t expected_epoch[] = { 0x88u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309A2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09A3u;
            if (nh_scpu_expect_next(cpu, 0x06984D18u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984D18u: {
            static const uint8_t expected_epoch[] = { 0xB7u, 0x50u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309A3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000050u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000051u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_bank = 0u, low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000052u) & 0xFFFFu), &pointer_bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) | ((uint32_t)pointer_high << 8u) | pointer_low) + cpu->y) & 0xFFFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09A5u;
            if (nh_scpu_expect_next(cpu, 0x06984D28u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984D28u: {
            static const uint8_t expected_epoch[] = { 0xEBu };
            if (nh_scpu_guard_code(cpu, bus, 0xD309A5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)((uint8_t)cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)((uint8_t)cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09A6u;
            if (nh_scpu_expect_next(cpu, 0x06984D30u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984D30u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309A6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09A7u;
            if (nh_scpu_expect_next(cpu, 0x06984D38u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984D38u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309A7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint16_t right, result;
            const uint16_t left = cpu->a;
            uint32_t sum;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000030u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000031u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            right = (uint16_t)(((uint16_t)high << 8u) | low);
            sum = (uint32_t)left + (uint32_t)right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            result = (uint16_t)sum;
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (sum > 0xFFFFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            if (((uint16_t)(~(left ^ right)) & (uint16_t)(left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09A9u;
            if (nh_scpu_expect_next(cpu, 0x06984D48u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984D48u: {
            static const uint8_t expected_epoch[] = { 0x1Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD309A9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09AAu;
            if (nh_scpu_expect_next(cpu, 0x06984D50u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984D50u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0xFEu, 0xFFu };
            if (nh_scpu_guard_code(cpu, bus, 0xD309AAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0xFFFEu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09ADu;
            if (nh_scpu_expect_next(cpu, 0x06984D68u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984D68u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309ADu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000030u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000031u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09AFu;
            if (nh_scpu_expect_next(cpu, 0x06984D78u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984D78u: {
            static const uint8_t expected_epoch[] = { 0xC6u, 0x4Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD309AFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00004Cu) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00004Du) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t result = (uint16_t)(value - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00004Du) & 0xFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00004Cu) & 0xFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09B1u;
            if (nh_scpu_expect_next(cpu, 0x06984D88u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984D88u: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309B1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xD3u;
                cpu->pc = 0x09B7u;
                if (nh_scpu_expect_next(cpu, 0x06984DB8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09B3u;
            if (nh_scpu_expect_next(cpu, 0x06984D98u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984D98u: {
            static const uint8_t expected_epoch[] = { 0x5Cu, 0x7Au, 0x09u, 0xD3u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309B3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x097Au;
            if (nh_scpu_expect_next(cpu, 0x06984BD0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06984DB8u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD309B7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09B9u;
            if (nh_scpu_expect_next(cpu, 0x06984DC8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984DC8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x50u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309B9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000050u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000051u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09BBu;
            if (nh_scpu_expect_next(cpu, 0x06984DD8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984DD8u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x0Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD309BBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Cu) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Du) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09BDu;
            if (nh_scpu_expect_next(cpu, 0x06984DE8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984DE8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x52u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309BDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000052u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000053u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09BFu;
            if (nh_scpu_expect_next(cpu, 0x06984DF8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984DF8u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x80u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309BFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0080u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09C2u;
            if (nh_scpu_expect_next(cpu, 0x06984E10u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984E10u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x4Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD309C2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00004Cu) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00004Du) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09C4u;
            if (nh_scpu_expect_next(cpu, 0x06984E20u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984E20u: {
            static const uint8_t expected_epoch[] = { 0xA2u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309C4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09C7u;
            if (nh_scpu_expect_next(cpu, 0x06984E38u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984E38u: {
            static const uint8_t expected_epoch[] = { 0xBFu, 0x80u, 0x1Au, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xD309C7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = (0x7E1A80u + (uint32_t)cpu->x) & 0xFFFFFFu;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09CBu;
            if (nh_scpu_expect_next(cpu, 0x06984E58u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06984E58u: {
            static const uint8_t expected_epoch[] = { 0xE8u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309CBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(cpu->x + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09CCu;
            if (nh_scpu_expect_next(cpu, 0x06984E60u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984E60u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0xFFu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309CCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09CFu;
            if (nh_scpu_expect_next(cpu, 0x06984E78u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984E78u: {
            static const uint8_t expected_epoch[] = { 0xC9u, 0xFFu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309CFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= 0x00FFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09D2u;
            if (nh_scpu_expect_next(cpu, 0x06984E90u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984E90u: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x25u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309D2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xD3u;
                cpu->pc = 0x09F9u;
                if (nh_scpu_expect_next(cpu, 0x06984FC8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09D4u;
            if (nh_scpu_expect_next(cpu, 0x06984EA0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984EA0u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD309D4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09D5u;
            if (nh_scpu_expect_next(cpu, 0x06984EA8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984EA8u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD309D5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09D6u;
            if (nh_scpu_expect_next(cpu, 0x06984EB0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984EB0u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD309D6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09D7u;
            if (nh_scpu_expect_next(cpu, 0x06984EB8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984EB8u: {
            static const uint8_t expected_epoch[] = { 0xA8u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309D7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09D8u;
            if (nh_scpu_expect_next(cpu, 0x06984EC0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984EC0u: {
            static const uint8_t expected_epoch[] = { 0xB7u, 0x50u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309D8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000050u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000051u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_bank = 0u, low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000052u) & 0xFFFFu), &pointer_bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) | ((uint32_t)pointer_high << 8u) | pointer_low) + cpu->y) & 0xFFFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09DAu;
            if (nh_scpu_expect_next(cpu, 0x06984ED0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984ED0u: {
            static const uint8_t expected_epoch[] = { 0xEBu };
            if (nh_scpu_guard_code(cpu, bus, 0xD309DAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)((uint8_t)cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)((uint8_t)cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09DBu;
            if (nh_scpu_expect_next(cpu, 0x06984ED8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984ED8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x66u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309DBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000066u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000067u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09DDu;
            if (nh_scpu_expect_next(cpu, 0x06984EE8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984EE8u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309DDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09DEu;
            if (nh_scpu_expect_next(cpu, 0x06984EF0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984EF0u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309DEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09DFu;
            if (nh_scpu_expect_next(cpu, 0x06984EF8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984EF8u: {
            static const uint8_t expected_epoch[] = { 0xB7u, 0x50u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309DFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000050u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000051u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_bank = 0u, low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000052u) & 0xFFFFu), &pointer_bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) | ((uint32_t)pointer_high << 8u) | pointer_low) + cpu->y) & 0xFFFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09E1u;
            if (nh_scpu_expect_next(cpu, 0x06984F08u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984F08u: {
            static const uint8_t expected_epoch[] = { 0xEBu };
            if (nh_scpu_guard_code(cpu, bus, 0xD309E1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)((uint8_t)cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)((uint8_t)cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09E2u;
            if (nh_scpu_expect_next(cpu, 0x06984F10u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984F10u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309E2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09E3u;
            if (nh_scpu_expect_next(cpu, 0x06984F18u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984F18u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x50u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309E3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint16_t right, result;
            const uint16_t left = cpu->a;
            uint32_t sum;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000050u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000051u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            right = (uint16_t)(((uint16_t)high << 8u) | low);
            sum = (uint32_t)left + (uint32_t)right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            result = (uint16_t)sum;
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (sum > 0xFFFFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            if (((uint16_t)(~(left ^ right)) & (uint16_t)(left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09E5u;
            if (nh_scpu_expect_next(cpu, 0x06984F28u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984F28u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x64u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309E5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000064u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000065u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09E7u;
            if (nh_scpu_expect_next(cpu, 0x06984F38u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984F38u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x66u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309E7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000066u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000067u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09E9u;
            if (nh_scpu_expect_next(cpu, 0x06984F48u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984F48u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x52u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309E9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint16_t right, result;
            const uint16_t left = cpu->a;
            uint32_t sum;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000052u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000053u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            right = (uint16_t)(((uint16_t)high << 8u) | low);
            sum = (uint32_t)left + (uint32_t)right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            result = (uint16_t)sum;
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (sum > 0xFFFFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            if (((uint16_t)(~(left ^ right)) & (uint16_t)(left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09EBu;
            if (nh_scpu_expect_next(cpu, 0x06984F58u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984F58u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x66u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309EBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000066u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000067u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09EDu;
            if (nh_scpu_expect_next(cpu, 0x06984F68u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984F68u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309EDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09EEu;
            if (nh_scpu_expect_next(cpu, 0x06984F70u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984F70u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309EEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09EFu;
            if (nh_scpu_expect_next(cpu, 0x06984F78u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984F78u: {
            static const uint8_t expected_epoch[] = { 0xB7u, 0x50u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309EFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000050u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000051u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_bank = 0u, low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000052u) & 0xFFFFu), &pointer_bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) | ((uint32_t)pointer_high << 8u) | pointer_low) + cpu->y) & 0xFFFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09F1u;
            if (nh_scpu_expect_next(cpu, 0x06984F88u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984F88u: {
            static const uint8_t expected_epoch[] = { 0xEBu };
            if (nh_scpu_guard_code(cpu, bus, 0xD309F1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)((uint8_t)cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)((uint8_t)cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09F2u;
            if (nh_scpu_expect_next(cpu, 0x06984F90u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06984F90u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309F2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000068u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000069u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09F4u;
            if (nh_scpu_expect_next(cpu, 0x06984FA0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984FA0u: {
            static const uint8_t expected_epoch[] = { 0xDAu };
            if (nh_scpu_guard_code(cpu, bus, 0xD309F4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)(cpu->x >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->x) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09F5u;
            if (nh_scpu_expect_next(cpu, 0x06984FA8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06984FA8u: {
            static const uint8_t expected_epoch[] = { 0x20u, 0x81u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309F5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x09u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xF7u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0281u;
            if (nh_scpu_expect_next(cpu, 0x06981408u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06984FC0u: {
            static const uint8_t expected_epoch[] = { 0xFAu };
            if (nh_scpu_guard_code(cpu, bus, 0xD309F8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09F9u;
            if (nh_scpu_expect_next(cpu, 0x06984FC8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06984FC8u: {
            static const uint8_t expected_epoch[] = { 0xC6u, 0x4Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD309F9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00004Cu) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00004Du) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t result = (uint16_t)(value - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00004Du) & 0xFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00004Cu) & 0xFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09FBu;
            if (nh_scpu_expect_next(cpu, 0x06984FD8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06984FD8u: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309FBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xD3u;
                cpu->pc = 0x0A01u;
                if (nh_scpu_expect_next(cpu, 0x06985008u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09FDu;
            if (nh_scpu_expect_next(cpu, 0x06984FE8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06984FE8u: {
            static const uint8_t expected_epoch[] = { 0x5Cu, 0xC7u, 0x09u, 0xD3u };
            if (nh_scpu_guard_code(cpu, bus, 0xD309FDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x09C7u;
            if (nh_scpu_expect_next(cpu, 0x06984E38u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        default: return NH_SCPU_NOT_MINE;
    }
}
