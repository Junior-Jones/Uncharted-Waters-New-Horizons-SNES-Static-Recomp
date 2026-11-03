/* Generated direct New Horizons S-CPU authority; do not edit. */
#include "nh_v07_generated.h"

NHScpuExecResult nh_v07_shard_00D30A(NHScpuState *cpu, const NHScpuBus *bus) {
    switch (nh_scpu_context_key(cpu)) {
        case 0x06985008u: {
            static const uint8_t expected_epoch[] = { 0x28u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A01u,
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
            cpu->pc = 0x0A02u;
            if (nh_scpu_expect_next(cpu, 0x06985012u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06985012u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A02u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            if (nh_scpu_context_key(cpu) != 0x069818AAu)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0698501Au: {
            static const uint8_t expected_epoch[] = { 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A03u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, cpu->p) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A04u;
            if (nh_scpu_expect_next(cpu, 0x06985022u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06985022u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A04u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x30u);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A06u;
            if (nh_scpu_expect_next(cpu, 0x06985030u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06985030u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x04u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A06u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0804u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A09u;
            if (nh_scpu_expect_next(cpu, 0x06985048u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06985048u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x64u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A09u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000064u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000065u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A0Bu;
            if (nh_scpu_expect_next(cpu, 0x06985058u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985058u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x1Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A0Bu,
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
            cpu->pc = 0x0A0Du;
            if (nh_scpu_expect_next(cpu, 0x06985068u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985068u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A0Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000068u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000069u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A0Fu;
            if (nh_scpu_expect_next(cpu, 0x06985078u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985078u: {
            static const uint8_t expected_epoch[] = { 0x20u, 0x67u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A0Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x0Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x11u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0267u;
            if (nh_scpu_expect_next(cpu, 0x06981338u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06985090u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A12u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000020u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000021u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A14u;
            if (nh_scpu_expect_next(cpu, 0x069850A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069850A0u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A14u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xD3u;
                cpu->pc = 0x0A1Au;
                if (nh_scpu_expect_next(cpu, 0x069850D0u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A16u;
            if (nh_scpu_expect_next(cpu, 0x069850B0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069850B0u: {
            static const uint8_t expected_epoch[] = { 0x5Cu, 0xE9u, 0x0Au, 0xD3u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A16u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AE9u;
            if (nh_scpu_expect_next(cpu, 0x06985748u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x069850D0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x4Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A1Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00004Cu) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00004Du) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A1Cu;
            if (nh_scpu_expect_next(cpu, 0x069850E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069850E0u: {
            static const uint8_t expected_epoch[] = { 0x1Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A1Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A1Du;
            if (nh_scpu_expect_next(cpu, 0x069850E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069850E8u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A1Du,
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
            cpu->pc = 0x0A1Eu;
            if (nh_scpu_expect_next(cpu, 0x069850F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069850F0u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A1Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A1Fu;
            if (nh_scpu_expect_next(cpu, 0x069850F8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069850F8u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x1Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A1Fu,
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
            cpu->pc = 0x0A21u;
            if (nh_scpu_expect_next(cpu, 0x06985108u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985108u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A21u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000030u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000031u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A23u;
            if (nh_scpu_expect_next(cpu, 0x06985118u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985118u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x4Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A23u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00004Cu) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00004Du) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A25u;
            if (nh_scpu_expect_next(cpu, 0x06985128u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985128u: {
            static const uint8_t expected_epoch[] = { 0xEBu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A25u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)((uint8_t)cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)((uint8_t)cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A26u;
            if (nh_scpu_expect_next(cpu, 0x06985130u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06985130u: {
            static const uint8_t expected_epoch[] = { 0x20u, 0x49u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A26u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x0Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x28u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0249u;
            if (nh_scpu_expect_next(cpu, 0x06981248u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06985148u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x28u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A29u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000028u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000029u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A2Bu;
            if (nh_scpu_expect_next(cpu, 0x06985158u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985158u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x50u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A2Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000050u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000051u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A2Du;
            if (nh_scpu_expect_next(cpu, 0x06985168u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985168u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x2Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A2Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00002Au) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00002Bu) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A2Fu;
            if (nh_scpu_expect_next(cpu, 0x06985178u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985178u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x52u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A2Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000052u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000053u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A31u;
            if (nh_scpu_expect_next(cpu, 0x06985188u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985188u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x12u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A31u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000012u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000013u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A33u;
            if (nh_scpu_expect_next(cpu, 0x06985198u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985198u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x54u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A33u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000054u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000055u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A35u;
            if (nh_scpu_expect_next(cpu, 0x069851A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069851A8u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x14u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A35u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000014u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000015u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A37u;
            if (nh_scpu_expect_next(cpu, 0x069851B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069851B8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x56u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A37u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000056u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000057u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A39u;
            if (nh_scpu_expect_next(cpu, 0x069851C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069851C8u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x3Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A39u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00003Cu) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00003Du) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A3Bu;
            if (nh_scpu_expect_next(cpu, 0x069851D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069851D8u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A3Bu,
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
            cpu->pc = 0x0A3Du;
            if (nh_scpu_expect_next(cpu, 0x069851E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069851E8u: {
            static const uint8_t expected_epoch[] = { 0x20u, 0x49u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A3Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x0Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x3Fu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0249u;
            if (nh_scpu_expect_next(cpu, 0x06981248u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06985200u: {
            static const uint8_t expected_epoch[] = { 0xA7u, 0x50u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A40u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t lo = 0u, hi = 0u;
            uint32_t address;
            uint8_t bank = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000050u) & 0xFFFFu), &lo) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000051u) & 0xFFFFu), &hi) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000052u) & 0xFFFFu), &bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            address = ((uint32_t)bank << 16) | ((uint32_t)hi << 8) | (uint32_t)lo;
            if (nh_scpu_read8(cpu, bus, address, &lo) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0x00FFFFFFu, &hi) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)((uint16_t)lo | ((uint16_t)hi << 8));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A42u;
            if (nh_scpu_expect_next(cpu, 0x06985210u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985210u: {
            static const uint8_t expected_epoch[] = { 0xE6u, 0x50u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A42u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000050u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000051u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t result = (uint16_t)(value + 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000051u) & 0xFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000050u) & 0xFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A44u;
            if (nh_scpu_expect_next(cpu, 0x06985220u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985220u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A44u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xD3u;
                cpu->pc = 0x0A48u;
                if (nh_scpu_expect_next(cpu, 0x06985240u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A46u;
            if (nh_scpu_expect_next(cpu, 0x06985230u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06985230u: {
            static const uint8_t expected_epoch[] = { 0xE6u, 0x52u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A46u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000052u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000053u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t result = (uint16_t)(value + 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000053u) & 0xFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000052u) & 0xFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A48u;
            if (nh_scpu_expect_next(cpu, 0x06985240u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985240u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0xFFu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A48u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A4Bu;
            if (nh_scpu_expect_next(cpu, 0x06985258u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06985258u: {
            static const uint8_t expected_epoch[] = { 0xAAu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A4Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A4Cu;
            if (nh_scpu_expect_next(cpu, 0x06985260u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06985260u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A4Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A4Eu;
            if (nh_scpu_expect_next(cpu, 0x06985272u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06985272u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x3Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A4Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00003Cu) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A50u;
            if (nh_scpu_expect_next(cpu, 0x06985282u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985282u: {
            static const uint8_t expected_epoch[] = { 0x9Fu, 0x00u, 0x19u, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A50u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = (0x7E1900u + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (nh_scpu_write8(cpu, bus, address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A54u;
            if (nh_scpu_expect_next(cpu, 0x069852A2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x069852A2u: {
            static const uint8_t expected_epoch[] = { 0xE6u, 0x3Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A54u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00003Cu) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            value = (uint8_t)(value + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00003Cu) & 0xFFFFu), value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A56u;
            if (nh_scpu_expect_next(cpu, 0x069852B2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069852B2u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A56u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A58u;
            if (nh_scpu_expect_next(cpu, 0x069852C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x069852C0u: {
            static const uint8_t expected_epoch[] = { 0x8Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A58u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = cpu->x;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A59u;
            if (nh_scpu_expect_next(cpu, 0x069852C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069852C8u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A59u,
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
            cpu->pc = 0x0A5Au;
            if (nh_scpu_expect_next(cpu, 0x069852D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069852D0u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A5Au,
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
            cpu->pc = 0x0A5Bu;
            if (nh_scpu_expect_next(cpu, 0x069852D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069852D8u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A5Bu,
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
            cpu->pc = 0x0A5Cu;
            if (nh_scpu_expect_next(cpu, 0x069852E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069852E0u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A5Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A5Du;
            if (nh_scpu_expect_next(cpu, 0x069852E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069852E8u: {
            static const uint8_t expected_epoch[] = { 0x69u, 0x08u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A5Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0008u;
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
            cpu->pc = 0x0A60u;
            if (nh_scpu_expect_next(cpu, 0x06985300u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06985300u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A60u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A61u;
            if (nh_scpu_expect_next(cpu, 0x06985308u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06985308u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x54u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A61u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint16_t right, result;
            const uint16_t left = cpu->a;
            uint32_t sum;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000054u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000055u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
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
            cpu->pc = 0x0A63u;
            if (nh_scpu_expect_next(cpu, 0x06985318u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985318u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x58u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A63u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000058u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000059u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A65u;
            if (nh_scpu_expect_next(cpu, 0x06985328u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985328u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A65u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A68u;
            if (nh_scpu_expect_next(cpu, 0x06985340u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06985340u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x56u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A68u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint16_t right, result;
            const uint16_t left = cpu->a;
            uint32_t sum;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000056u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000057u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
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
            cpu->pc = 0x0A6Au;
            if (nh_scpu_expect_next(cpu, 0x06985350u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985350u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x5Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A6Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00005Au) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00005Bu) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A6Cu;
            if (nh_scpu_expect_next(cpu, 0x06985360u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985360u: {
            static const uint8_t expected_epoch[] = { 0xA7u, 0x58u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A6Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t lo = 0u, hi = 0u;
            uint32_t address;
            uint8_t bank = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000058u) & 0xFFFFu), &lo) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000059u) & 0xFFFFu), &hi) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00005Au) & 0xFFFFu), &bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            address = ((uint32_t)bank << 16) | ((uint32_t)hi << 8) | (uint32_t)lo;
            if (nh_scpu_read8(cpu, bus, address, &lo) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0x00FFFFFFu, &hi) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)((uint16_t)lo | ((uint16_t)hi << 8));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A6Eu;
            if (nh_scpu_expect_next(cpu, 0x06985370u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985370u: {
            static const uint8_t expected_epoch[] = { 0xEBu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A6Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)((uint8_t)cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)((uint8_t)cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A6Fu;
            if (nh_scpu_expect_next(cpu, 0x06985378u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06985378u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A6Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A70u;
            if (nh_scpu_expect_next(cpu, 0x06985380u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06985380u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A70u,
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
            cpu->pc = 0x0A72u;
            if (nh_scpu_expect_next(cpu, 0x06985390u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985390u: {
            static const uint8_t expected_epoch[] = { 0x1Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A72u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A73u;
            if (nh_scpu_expect_next(cpu, 0x06985398u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06985398u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0xFEu, 0xFFu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A73u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0xFFFEu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A76u;
            if (nh_scpu_expect_next(cpu, 0x069853B0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x069853B0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A76u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000030u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000031u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A78u;
            if (nh_scpu_expect_next(cpu, 0x069853C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069853C0u: {
            static const uint8_t expected_epoch[] = { 0xC6u, 0x4Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A78u,
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
            cpu->pc = 0x0A7Au;
            if (nh_scpu_expect_next(cpu, 0x069853D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069853D0u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0xBFu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A7Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xD3u;
                cpu->pc = 0x0A3Bu;
                if (nh_scpu_expect_next(cpu, 0x069851D8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A7Cu;
            if (nh_scpu_expect_next(cpu, 0x069853E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069853E0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x28u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A7Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000028u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000029u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A7Eu;
            if (nh_scpu_expect_next(cpu, 0x069853F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069853F0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x50u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A7Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000050u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000051u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A80u;
            if (nh_scpu_expect_next(cpu, 0x06985400u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985400u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x2Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A80u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00002Au) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00002Bu) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A82u;
            if (nh_scpu_expect_next(cpu, 0x06985410u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985410u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x52u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A82u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000052u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000053u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A84u;
            if (nh_scpu_expect_next(cpu, 0x06985420u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985420u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A84u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000020u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000021u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A86u;
            if (nh_scpu_expect_next(cpu, 0x06985430u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985430u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x4Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A86u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00004Cu) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00004Du) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A88u;
            if (nh_scpu_expect_next(cpu, 0x06985440u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985440u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x12u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A88u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000012u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000013u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A8Au;
            if (nh_scpu_expect_next(cpu, 0x06985450u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985450u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x54u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A8Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000054u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000055u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A8Cu;
            if (nh_scpu_expect_next(cpu, 0x06985460u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985460u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x14u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A8Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000014u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000015u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A8Eu;
            if (nh_scpu_expect_next(cpu, 0x06985470u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985470u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x56u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A8Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000056u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000057u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A90u;
            if (nh_scpu_expect_next(cpu, 0x06985480u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985480u: {
            static const uint8_t expected_epoch[] = { 0xA7u, 0x50u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A90u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t lo = 0u, hi = 0u;
            uint32_t address;
            uint8_t bank = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000050u) & 0xFFFFu), &lo) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000051u) & 0xFFFFu), &hi) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000052u) & 0xFFFFu), &bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            address = ((uint32_t)bank << 16) | ((uint32_t)hi << 8) | (uint32_t)lo;
            if (nh_scpu_read8(cpu, bus, address, &lo) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0x00FFFFFFu, &hi) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)((uint16_t)lo | ((uint16_t)hi << 8));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A92u;
            if (nh_scpu_expect_next(cpu, 0x06985490u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985490u: {
            static const uint8_t expected_epoch[] = { 0xE6u, 0x50u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A92u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000050u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000051u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t result = (uint16_t)(value + 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000051u) & 0xFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000050u) & 0xFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A94u;
            if (nh_scpu_expect_next(cpu, 0x069854A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069854A0u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A94u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xD3u;
                cpu->pc = 0x0A98u;
                if (nh_scpu_expect_next(cpu, 0x069854C0u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A96u;
            if (nh_scpu_expect_next(cpu, 0x069854B0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069854B0u: {
            static const uint8_t expected_epoch[] = { 0xE6u, 0x52u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A96u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000052u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000053u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t result = (uint16_t)(value + 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000053u) & 0xFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000052u) & 0xFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A98u;
            if (nh_scpu_expect_next(cpu, 0x069854C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069854C0u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0xFFu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A98u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A9Bu;
            if (nh_scpu_expect_next(cpu, 0x069854D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x069854D8u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A9Bu,
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
            cpu->pc = 0x0A9Cu;
            if (nh_scpu_expect_next(cpu, 0x069854E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069854E0u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A9Cu,
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
            cpu->pc = 0x0A9Du;
            if (nh_scpu_expect_next(cpu, 0x069854E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069854E8u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A9Du,
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
            cpu->pc = 0x0A9Eu;
            if (nh_scpu_expect_next(cpu, 0x069854F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069854F0u: {
            static const uint8_t expected_epoch[] = { 0x1Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A9Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0A9Fu;
            if (nh_scpu_expect_next(cpu, 0x069854F8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069854F8u: {
            static const uint8_t expected_epoch[] = { 0x1Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30A9Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AA0u;
            if (nh_scpu_expect_next(cpu, 0x06985500u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06985500u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AA0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AA1u;
            if (nh_scpu_expect_next(cpu, 0x06985508u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06985508u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x54u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AA1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint16_t right, result;
            const uint16_t left = cpu->a;
            uint32_t sum;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000054u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000055u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
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
            cpu->pc = 0x0AA3u;
            if (nh_scpu_expect_next(cpu, 0x06985518u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985518u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x58u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AA3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000058u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000059u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AA5u;
            if (nh_scpu_expect_next(cpu, 0x06985528u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985528u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AA5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AA8u;
            if (nh_scpu_expect_next(cpu, 0x06985540u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06985540u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x56u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AA8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint16_t right, result;
            const uint16_t left = cpu->a;
            uint32_t sum;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000056u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000057u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
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
            cpu->pc = 0x0AAAu;
            if (nh_scpu_expect_next(cpu, 0x06985550u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985550u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x5Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AAAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00005Au) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00005Bu) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AACu;
            if (nh_scpu_expect_next(cpu, 0x06985560u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985560u: {
            static const uint8_t expected_epoch[] = { 0xA7u, 0x58u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AACu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t lo = 0u, hi = 0u;
            uint32_t address;
            uint8_t bank = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000058u) & 0xFFFFu), &lo) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000059u) & 0xFFFFu), &hi) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00005Au) & 0xFFFFu), &bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            address = ((uint32_t)bank << 16) | ((uint32_t)hi << 8) | (uint32_t)lo;
            if (nh_scpu_read8(cpu, bus, address, &lo) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0x00FFFFFFu, &hi) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)((uint16_t)lo | ((uint16_t)hi << 8));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AAEu;
            if (nh_scpu_expect_next(cpu, 0x06985570u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985570u: {
            static const uint8_t expected_epoch[] = { 0xEBu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AAEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)((uint8_t)cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)((uint8_t)cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AAFu;
            if (nh_scpu_expect_next(cpu, 0x06985578u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06985578u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x66u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AAFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000066u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000067u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AB1u;
            if (nh_scpu_expect_next(cpu, 0x06985588u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985588u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x58u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AB1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000058u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000059u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AB3u;
            if (nh_scpu_expect_next(cpu, 0x06985598u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985598u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AB3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AB4u;
            if (nh_scpu_expect_next(cpu, 0x069855A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069855A0u: {
            static const uint8_t expected_epoch[] = { 0x69u, 0x02u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AB4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0002u;
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
            cpu->pc = 0x0AB7u;
            if (nh_scpu_expect_next(cpu, 0x069855B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x069855B8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x58u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AB7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000058u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000059u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AB9u;
            if (nh_scpu_expect_next(cpu, 0x069855C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069855C8u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x5Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AB9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00005Au) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00005Bu) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0ABBu;
            if (nh_scpu_expect_next(cpu, 0x069855D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069855D8u: {
            static const uint8_t expected_epoch[] = { 0x69u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30ABBu,
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
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0ABEu;
            if (nh_scpu_expect_next(cpu, 0x069855F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x069855F0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x5Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30ABEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00005Au) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00005Bu) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AC0u;
            if (nh_scpu_expect_next(cpu, 0x06985600u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985600u: {
            static const uint8_t expected_epoch[] = { 0xA7u, 0x58u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AC0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t lo = 0u, hi = 0u;
            uint32_t address;
            uint8_t bank = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000058u) & 0xFFFFu), &lo) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000059u) & 0xFFFFu), &hi) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00005Au) & 0xFFFFu), &bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            address = ((uint32_t)bank << 16) | ((uint32_t)hi << 8) | (uint32_t)lo;
            if (nh_scpu_read8(cpu, bus, address, &lo) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0x00FFFFFFu, &hi) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)((uint16_t)lo | ((uint16_t)hi << 8));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AC2u;
            if (nh_scpu_expect_next(cpu, 0x06985610u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985610u: {
            static const uint8_t expected_epoch[] = { 0xEBu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AC2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)((uint8_t)cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)((uint8_t)cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AC3u;
            if (nh_scpu_expect_next(cpu, 0x06985618u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06985618u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AC3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AC4u;
            if (nh_scpu_expect_next(cpu, 0x06985620u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06985620u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x54u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AC4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint16_t right, result;
            const uint16_t left = cpu->a;
            uint32_t sum;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000054u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000055u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
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
            cpu->pc = 0x0AC6u;
            if (nh_scpu_expect_next(cpu, 0x06985630u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985630u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x64u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AC6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000064u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000065u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AC8u;
            if (nh_scpu_expect_next(cpu, 0x06985640u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985640u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x66u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AC8u,
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
            cpu->pc = 0x0ACAu;
            if (nh_scpu_expect_next(cpu, 0x06985650u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985650u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x56u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30ACAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint16_t right, result;
            const uint16_t left = cpu->a;
            uint32_t sum;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000056u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000057u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
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
            cpu->pc = 0x0ACCu;
            if (nh_scpu_expect_next(cpu, 0x06985660u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985660u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x66u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30ACCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000066u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000067u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0ACEu;
            if (nh_scpu_expect_next(cpu, 0x06985670u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985670u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x58u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30ACEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000058u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000059u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AD0u;
            if (nh_scpu_expect_next(cpu, 0x06985680u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985680u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AD0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AD1u;
            if (nh_scpu_expect_next(cpu, 0x06985688u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06985688u: {
            static const uint8_t expected_epoch[] = { 0x69u, 0x04u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AD1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0004u;
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
            cpu->pc = 0x0AD4u;
            if (nh_scpu_expect_next(cpu, 0x069856A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x069856A0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x58u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AD4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000058u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000059u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AD6u;
            if (nh_scpu_expect_next(cpu, 0x069856B0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069856B0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x5Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AD6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00005Au) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00005Bu) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AD8u;
            if (nh_scpu_expect_next(cpu, 0x069856C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069856C0u: {
            static const uint8_t expected_epoch[] = { 0x69u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AD8u,
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
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0ADBu;
            if (nh_scpu_expect_next(cpu, 0x069856D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x069856D8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x5Au };
            if (nh_scpu_guard_code(cpu, bus, 0xD30ADBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00005Au) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00005Bu) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0ADDu;
            if (nh_scpu_expect_next(cpu, 0x069856E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069856E8u: {
            static const uint8_t expected_epoch[] = { 0xA7u, 0x58u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30ADDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t lo = 0u, hi = 0u;
            uint32_t address;
            uint8_t bank = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000058u) & 0xFFFFu), &lo) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000059u) & 0xFFFFu), &hi) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00005Au) & 0xFFFFu), &bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            address = ((uint32_t)bank << 16) | ((uint32_t)hi << 8) | (uint32_t)lo;
            if (nh_scpu_read8(cpu, bus, address, &lo) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0x00FFFFFFu, &hi) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)((uint16_t)lo | ((uint16_t)hi << 8));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0ADFu;
            if (nh_scpu_expect_next(cpu, 0x069856F8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069856F8u: {
            static const uint8_t expected_epoch[] = { 0xEBu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30ADFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)((uint8_t)cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)((uint8_t)cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AE0u;
            if (nh_scpu_expect_next(cpu, 0x06985700u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06985700u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AE0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000068u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000069u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AE2u;
            if (nh_scpu_expect_next(cpu, 0x06985710u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985710u: {
            static const uint8_t expected_epoch[] = { 0x20u, 0x81u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AE2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x0Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xE4u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0281u;
            if (nh_scpu_expect_next(cpu, 0x06981408u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06985728u: {
            static const uint8_t expected_epoch[] = { 0xC6u, 0x4Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AE5u,
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
            cpu->pc = 0x0AE7u;
            if (nh_scpu_expect_next(cpu, 0x06985738u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985738u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0xA7u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AE7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xD3u;
                cpu->pc = 0x0A90u;
                if (nh_scpu_expect_next(cpu, 0x06985480u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AE9u;
            if (nh_scpu_expect_next(cpu, 0x06985748u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06985748u: {
            static const uint8_t expected_epoch[] = { 0x28u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AE9u,
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
            cpu->pc = 0x0AEAu;
            if (nh_scpu_expect_next(cpu, 0x06985752u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06985752u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AEAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            if (nh_scpu_context_key(cpu) != 0x069818C2u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0698575Au: {
            static const uint8_t expected_epoch[] = { 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AEBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, cpu->p) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AECu;
            if (nh_scpu_expect_next(cpu, 0x06985762u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06985762u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AECu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x30u);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AEEu;
            if (nh_scpu_expect_next(cpu, 0x06985770u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06985770u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x06u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AEEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0806u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AF1u;
            if (nh_scpu_expect_next(cpu, 0x06985788u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06985788u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x64u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AF1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000064u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000065u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AF3u;
            if (nh_scpu_expect_next(cpu, 0x06985798u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06985798u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x1Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AF3u,
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
            cpu->pc = 0x0AF5u;
            if (nh_scpu_expect_next(cpu, 0x069857A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069857A8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AF5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000068u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000069u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AF7u;
            if (nh_scpu_expect_next(cpu, 0x069857B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069857B8u: {
            static const uint8_t expected_epoch[] = { 0x20u, 0x67u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AF7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x0Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xF9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0267u;
            if (nh_scpu_expect_next(cpu, 0x06981338u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x069857D0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x22u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AFAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000022u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000023u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AFCu;
            if (nh_scpu_expect_next(cpu, 0x069857E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x069857E0u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AFCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xD3u;
                cpu->pc = 0x0B02u;
                if (nh_scpu_expect_next(cpu, 0x06985810u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0AFEu;
            if (nh_scpu_expect_next(cpu, 0x069857F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x069857F0u: {
            static const uint8_t expected_epoch[] = { 0x5Cu, 0xD1u, 0x0Bu, 0xD3u };
            if (nh_scpu_guard_code(cpu, bus, 0xD30AFEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xD3u;
            cpu->pc = 0x0BD1u;
            if (nh_scpu_expect_next(cpu, 0x06985E88u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        default: return NH_SCPU_NOT_MINE;
    }
}
