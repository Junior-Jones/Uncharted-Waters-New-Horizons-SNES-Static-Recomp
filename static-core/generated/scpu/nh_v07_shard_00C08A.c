/* Generated direct New Horizons S-CPU authority; do not edit. */
#include "nh_v07_generated.h"

NHScpuExecResult nh_v07_shard_00C08A(NHScpuState *cpu, const NHScpuBus *bus) {
    switch (nh_scpu_context_key(cpu)) {
        case 0x0604500Au: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A01u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A03u;
            if (nh_scpu_expect_next(cpu, 0x0604501Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604501Au: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x01u, 0x43u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A03u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004301u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A06u;
            if (nh_scpu_expect_next(cpu, 0x06045032u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06045032u: {
            static const uint8_t expected_epoch[] = { 0xAEu, 0x5Bu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A06u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F5Bu) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F5Cu) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A09u;
            if (nh_scpu_expect_next(cpu, 0x0604504Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604504Au: {
            static const uint8_t expected_epoch[] = { 0x8Eu, 0x02u, 0x43u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A09u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004302u) & 0xFFFFFFu), (uint8_t)cpu->x) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004303u) & 0xFFFFFFu), (uint8_t)(cpu->x >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A0Cu;
            if (nh_scpu_expect_next(cpu, 0x06045062u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06045062u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x5Du, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A0Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F5Du) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A0Fu;
            if (nh_scpu_expect_next(cpu, 0x0604507Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604507Au: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x04u, 0x43u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A0Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004304u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A12u;
            if (nh_scpu_expect_next(cpu, 0x06045092u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06045092u: {
            static const uint8_t expected_epoch[] = { 0x8Cu, 0x05u, 0x43u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A12u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004305u) & 0xFFFFFFu), (uint8_t)cpu->y) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004306u) & 0xFFFFFFu), (uint8_t)(cpu->y >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A15u;
            if (nh_scpu_expect_next(cpu, 0x060450AAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060450AAu: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A15u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x01u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A17u;
            if (nh_scpu_expect_next(cpu, 0x060450BAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060450BAu: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x0Bu, 0x42u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A17u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x00420Bu) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A1Au;
            if (nh_scpu_expect_next(cpu, 0x060450D2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060450D2u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x50u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A1Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000050u) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A1Cu;
            if (nh_scpu_expect_next(cpu, 0x060450E2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060450E2u: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x32u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A1Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0x8A50u;
                if (nh_scpu_expect_next(cpu, 0x06045282u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A1Eu;
            if (nh_scpu_expect_next(cpu, 0x060450F2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060450F2u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A1Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A20u;
            if (nh_scpu_expect_next(cpu, 0x06045100u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06045100u: {
            static const uint8_t expected_epoch[] = { 0x98u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A20u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A21u;
            if (nh_scpu_expect_next(cpu, 0x06045108u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06045108u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A21u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A22u;
            if (nh_scpu_expect_next(cpu, 0x06045110u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06045110u: {
            static const uint8_t expected_epoch[] = { 0x6Du, 0x57u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A22u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F57u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F58u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t left = cpu->a;
            const uint16_t right = value;
            const uint32_t total = (uint32_t)left + (uint32_t)right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            const uint16_t result = (uint16_t)total;
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (total > 0xFFFFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            if (((uint16_t)(~(left ^ right)) & (uint16_t)(left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A25u;
            if (nh_scpu_expect_next(cpu, 0x06045128u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06045128u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x57u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A25u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F57u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F58u) & 0xFFFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A28u;
            if (nh_scpu_expect_next(cpu, 0x06045140u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06045140u: {
            static const uint8_t expected_epoch[] = { 0x98u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A28u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A29u;
            if (nh_scpu_expect_next(cpu, 0x06045148u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06045148u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A29u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A2Au;
            if (nh_scpu_expect_next(cpu, 0x06045150u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06045150u: {
            static const uint8_t expected_epoch[] = { 0x6Du, 0x5Bu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A2Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F5Bu) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F5Cu) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t left = cpu->a;
            const uint16_t right = value;
            const uint32_t total = (uint32_t)left + (uint32_t)right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            const uint16_t result = (uint16_t)total;
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (total > 0xFFFFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            if (((uint16_t)(~(left ^ right)) & (uint16_t)(left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A2Du;
            if (nh_scpu_expect_next(cpu, 0x06045168u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06045168u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x5Bu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A2Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F5Bu) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F5Cu) & 0xFFFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A30u;
            if (nh_scpu_expect_next(cpu, 0x06045180u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06045180u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A30u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A32u;
            if (nh_scpu_expect_next(cpu, 0x06045192u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06045192u: {
            static const uint8_t expected_epoch[] = { 0xAEu, 0x57u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A32u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F57u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F58u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A35u;
            if (nh_scpu_expect_next(cpu, 0x060451AAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060451AAu: {
            static const uint8_t expected_epoch[] = { 0x8Eu, 0x16u, 0x21u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A35u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x002116u) & 0xFFFFFFu), (uint8_t)cpu->x) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x002117u) & 0xFFFFFFu), (uint8_t)(cpu->x >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A38u;
            if (nh_scpu_expect_next(cpu, 0x060451C2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060451C2u: {
            static const uint8_t expected_epoch[] = { 0xAEu, 0x5Bu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A38u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F5Bu) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F5Cu) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A3Bu;
            if (nh_scpu_expect_next(cpu, 0x060451DAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060451DAu: {
            static const uint8_t expected_epoch[] = { 0x8Eu, 0x02u, 0x43u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A3Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004302u) & 0xFFFFFFu), (uint8_t)cpu->x) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004303u) & 0xFFFFFFu), (uint8_t)(cpu->x >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A3Eu;
            if (nh_scpu_expect_next(cpu, 0x060451F2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060451F2u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x5Du, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A3Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F5Du) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A41u;
            if (nh_scpu_expect_next(cpu, 0x0604520Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604520Au: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x04u, 0x43u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A41u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004304u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A44u;
            if (nh_scpu_expect_next(cpu, 0x06045222u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06045222u: {
            static const uint8_t expected_epoch[] = { 0xA4u, 0x50u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A44u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000050u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000051u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A46u;
            if (nh_scpu_expect_next(cpu, 0x06045232u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06045232u: {
            static const uint8_t expected_epoch[] = { 0x8Cu, 0x05u, 0x43u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A46u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004305u) & 0xFFFFFFu), (uint8_t)cpu->y) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004306u) & 0xFFFFFFu), (uint8_t)(cpu->y >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A49u;
            if (nh_scpu_expect_next(cpu, 0x0604524Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604524Au: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A49u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x01u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A4Bu;
            if (nh_scpu_expect_next(cpu, 0x0604525Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604525Au: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x0Bu, 0x42u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A4Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x00420Bu) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A4Eu;
            if (nh_scpu_expect_next(cpu, 0x06045272u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06045272u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x50u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A4Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000050u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A50u;
            if (nh_scpu_expect_next(cpu, 0x06045282u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06045282u: {
            static const uint8_t expected_epoch[] = { 0xCEu, 0x64u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A50u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F64u) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t result = (uint8_t)(value - 1u);
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F64u) & 0xFFFFFFu), result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A53u;
            if (nh_scpu_expect_next(cpu, 0x0604529Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0604529Au: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x19u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A53u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0x8A6Eu;
                if (nh_scpu_expect_next(cpu, 0x06045372u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A55u;
            if (nh_scpu_expect_next(cpu, 0x060452AAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060452AAu: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A55u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A57u;
            if (nh_scpu_expect_next(cpu, 0x060452B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060452B8u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x5Bu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A57u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F5Bu) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F5Cu) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A5Au;
            if (nh_scpu_expect_next(cpu, 0x060452D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060452D0u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A5Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A5Bu;
            if (nh_scpu_expect_next(cpu, 0x060452D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060452D8u: {
            static const uint8_t expected_epoch[] = { 0x6Du, 0x62u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A5Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F62u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F63u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t left = cpu->a;
            const uint16_t right = value;
            const uint32_t total = (uint32_t)left + (uint32_t)right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            const uint16_t result = (uint16_t)total;
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (total > 0xFFFFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            if (((uint16_t)(~(left ^ right)) & (uint16_t)(left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A5Eu;
            if (nh_scpu_expect_next(cpu, 0x060452F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060452F0u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x5Bu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A5Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F5Bu) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F5Cu) & 0xFFFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A61u;
            if (nh_scpu_expect_next(cpu, 0x06045308u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06045308u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x80u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A61u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0080u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A64u;
            if (nh_scpu_expect_next(cpu, 0x06045320u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06045320u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A64u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A65u;
            if (nh_scpu_expect_next(cpu, 0x06045328u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06045328u: {
            static const uint8_t expected_epoch[] = { 0x6Du, 0x57u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A65u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F57u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F58u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t left = cpu->a;
            const uint16_t right = value;
            const uint32_t total = (uint32_t)left + (uint32_t)right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            const uint16_t result = (uint16_t)total;
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (total > 0xFFFFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            if (((uint16_t)(~(left ^ right)) & (uint16_t)(left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A68u;
            if (nh_scpu_expect_next(cpu, 0x06045340u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06045340u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x57u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A68u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F57u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F58u) & 0xFFFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A6Bu;
            if (nh_scpu_expect_next(cpu, 0x06045358u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06045358u: {
            static const uint8_t expected_epoch[] = { 0x4Cu, 0xD4u, 0x89u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A6Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x89D4u;
            if (nh_scpu_expect_next(cpu, 0x06044EA0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06045372u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A6Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x060426B2u &&
                return_key != 0x06056FDAu)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0604537Au: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A6Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x10u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A71u;
            if (nh_scpu_expect_next(cpu, 0x0604538Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604538Au: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A71u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A73u;
            if (nh_scpu_expect_next(cpu, 0x0604539Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604539Au: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x56u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A73u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F56u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A76u;
            if (nh_scpu_expect_next(cpu, 0x060453B2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060453B2u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A76u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | ((uint8_t)cpu->a & 0x04u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A78u;
            if (nh_scpu_expect_next(cpu, 0x060453C2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060453C2u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A78u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0x8A7Du;
                if (nh_scpu_expect_next(cpu, 0x060453EAu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A7Au;
            if (nh_scpu_expect_next(cpu, 0x060453D2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060453D2u: {
            static const uint8_t expected_epoch[] = { 0x4Cu, 0xC1u, 0x8Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A7Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AC1u;
            if (nh_scpu_expect_next(cpu, 0x0604560Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060453E8u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A7Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A7Fu;
            if (nh_scpu_expect_next(cpu, 0x060453F8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060453EAu: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A7Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A7Fu;
            if (nh_scpu_expect_next(cpu, 0x060453F8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060453F8u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A7Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A82u;
            if (nh_scpu_expect_next(cpu, 0x06045410u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06045410u: {
            static const uint8_t expected_epoch[] = { 0xACu, 0x62u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A82u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F62u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F63u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A85u;
            if (nh_scpu_expect_next(cpu, 0x06045428u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06045428u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A85u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A87u;
            if (nh_scpu_expect_next(cpu, 0x0604543Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604543Au: {
            static const uint8_t expected_epoch[] = { 0x9Cu, 0x15u, 0x21u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A87u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x002115u) & 0xFFFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A8Au;
            if (nh_scpu_expect_next(cpu, 0x06045452u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06045452u: {
            static const uint8_t expected_epoch[] = { 0xAEu, 0x57u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A8Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F57u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F58u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A8Du;
            if (nh_scpu_expect_next(cpu, 0x0604546Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604546Au: {
            static const uint8_t expected_epoch[] = { 0x8Eu, 0x16u, 0x21u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A8Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x002116u) & 0xFFFFFFu), (uint8_t)cpu->x) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x002117u) & 0xFFFFFFu), (uint8_t)(cpu->x >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A90u;
            if (nh_scpu_expect_next(cpu, 0x06045482u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06045482u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A90u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x08u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A92u;
            if (nh_scpu_expect_next(cpu, 0x06045492u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06045492u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x00u, 0x43u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A92u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004300u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A95u;
            if (nh_scpu_expect_next(cpu, 0x060454AAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060454AAu: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A95u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x18u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A97u;
            if (nh_scpu_expect_next(cpu, 0x060454BAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060454BAu: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x01u, 0x43u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A97u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004301u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A9Au;
            if (nh_scpu_expect_next(cpu, 0x060454D2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060454D2u: {
            static const uint8_t expected_epoch[] = { 0xA2u, 0x66u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A9Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = 0x0F66u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A9Du;
            if (nh_scpu_expect_next(cpu, 0x060454EAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060454EAu: {
            static const uint8_t expected_epoch[] = { 0x8Eu, 0x02u, 0x43u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08A9Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004302u) & 0xFFFFFFu), (uint8_t)cpu->x) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004303u) & 0xFFFFFFu), (uint8_t)(cpu->x >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AA0u;
            if (nh_scpu_expect_next(cpu, 0x06045502u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06045502u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AA0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x00u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AA2u;
            if (nh_scpu_expect_next(cpu, 0x06045512u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06045512u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x04u, 0x43u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AA2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004304u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AA5u;
            if (nh_scpu_expect_next(cpu, 0x0604552Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604552Au: {
            static const uint8_t expected_epoch[] = { 0x8Cu, 0x05u, 0x43u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AA5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004305u) & 0xFFFFFFu), (uint8_t)cpu->y) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004306u) & 0xFFFFFFu), (uint8_t)(cpu->y >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AA8u;
            if (nh_scpu_expect_next(cpu, 0x06045542u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06045542u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AA8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x01u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AAAu;
            if (nh_scpu_expect_next(cpu, 0x06045552u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06045552u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x0Bu, 0x42u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AAAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x00420Bu) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AADu;
            if (nh_scpu_expect_next(cpu, 0x0604556Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604556Au: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AADu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AAFu;
            if (nh_scpu_expect_next(cpu, 0x06045578u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06045578u: {
            static const uint8_t expected_epoch[] = { 0xCEu, 0x64u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AAFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F64u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F65u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t result = (uint16_t)(value - 1u);
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F65u) & 0xFFFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F64u) & 0xFFFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AB2u;
            if (nh_scpu_expect_next(cpu, 0x06045590u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x06045590u: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x0Du };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AB2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0x8AC1u;
                if (nh_scpu_expect_next(cpu, 0x06045608u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AB4u;
            if (nh_scpu_expect_next(cpu, 0x060455A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060455A0u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x80u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AB4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0080u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AB7u;
            if (nh_scpu_expect_next(cpu, 0x060455B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060455B8u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AB7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AB8u;
            if (nh_scpu_expect_next(cpu, 0x060455C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060455C0u: {
            static const uint8_t expected_epoch[] = { 0x6Du, 0x57u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AB8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F57u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F58u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t left = cpu->a;
            const uint16_t right = value;
            const uint32_t total = (uint32_t)left + (uint32_t)right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            const uint16_t result = (uint16_t)total;
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (total > 0xFFFFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            if (((uint16_t)(~(left ^ right)) & (uint16_t)(left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8ABBu;
            if (nh_scpu_expect_next(cpu, 0x060455D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060455D8u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x57u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08ABBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F57u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F58u) & 0xFFFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8ABEu;
            if (nh_scpu_expect_next(cpu, 0x060455F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060455F0u: {
            static const uint8_t expected_epoch[] = { 0x4Cu, 0x7Du, 0x8Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC08ABEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8A7Du;
            if (nh_scpu_expect_next(cpu, 0x060453E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06045608u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AC1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x060426C8u &&
                return_key != 0x060572B0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0604560Au: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AC1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x060426CAu &&
                return_key != 0x060572B2u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06045612u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AC2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x10u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AC4u;
            if (nh_scpu_expect_next(cpu, 0x06045622u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06045622u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AC4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AC6u;
            if (nh_scpu_expect_next(cpu, 0x06045632u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06045632u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x6Fu, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AC6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B6Fu) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AC9u;
            if (nh_scpu_expect_next(cpu, 0x0604564Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604564Au: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x0Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AC9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0x8AD7u;
                if (nh_scpu_expect_next(cpu, 0x060456BAu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8ACBu;
            if (nh_scpu_expect_next(cpu, 0x0604565Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604565Au: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x70u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08ACBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B70u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8ACEu;
            if (nh_scpu_expect_next(cpu, 0x06045672u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06045672u: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08ACEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0x8B08u;
                if (nh_scpu_expect_next(cpu, 0x06045842u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AD0u;
            if (nh_scpu_expect_next(cpu, 0x06045682u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06045682u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AD0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x00u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AD2u;
            if (nh_scpu_expect_next(cpu, 0x06045692u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06045692u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x70u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AD2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B70u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AD5u;
            if (nh_scpu_expect_next(cpu, 0x060456AAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060456AAu: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x21u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AD5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AF8u;
            if (nh_scpu_expect_next(cpu, 0x060457C2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060456BAu: {
            static const uint8_t expected_epoch[] = { 0xCEu, 0x79u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AD7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B79u) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t result = (uint8_t)(value - 1u);
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B79u) & 0xFFFFFFu), result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8ADAu;
            if (nh_scpu_expect_next(cpu, 0x060456D2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060456D2u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x2Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08ADAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0x8B08u;
                if (nh_scpu_expect_next(cpu, 0x06045842u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8ADCu;
            if (nh_scpu_expect_next(cpu, 0x060456E2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060456E2u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC08ADCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x0Au);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8ADEu;
            if (nh_scpu_expect_next(cpu, 0x060456F2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060456F2u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x79u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08ADEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B79u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AE1u;
            if (nh_scpu_expect_next(cpu, 0x0604570Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604570Au: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x70u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AE1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B70u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AE4u;
            if (nh_scpu_expect_next(cpu, 0x06045722u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06045722u: {
            static const uint8_t expected_epoch[] = { 0x49u, 0xFFu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AE4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t value = 0xFFu;
            const uint8_t result = (uint8_t)((uint8_t)cpu->a ^ value);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AE6u;
            if (nh_scpu_expect_next(cpu, 0x06045732u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06045732u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x70u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AE6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B70u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AE9u;
            if (nh_scpu_expect_next(cpu, 0x0604574Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604574Au: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x0Du };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AE9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0x8AF8u;
                if (nh_scpu_expect_next(cpu, 0x060457C2u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AEBu;
            if (nh_scpu_expect_next(cpu, 0x0604575Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604575Au: {
            static const uint8_t expected_epoch[] = { 0xAEu, 0x71u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AEBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B71u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B72u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AEEu;
            if (nh_scpu_expect_next(cpu, 0x06045772u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06045772u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x73u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AEEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B73u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AF1u;
            if (nh_scpu_expect_next(cpu, 0x0604578Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604578Au: {
            static const uint8_t expected_epoch[] = { 0x9Du, 0x01u, 0x09u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AF1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint32_t destination_address;
            destination_address = ((((uint32_t)cpu->dbr << 16u) + 0x000901u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_write8(cpu, bus, destination_address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AF4u;
            if (nh_scpu_expect_next(cpu, 0x060457A2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060457A2u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AF4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x01u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AF6u;
            if (nh_scpu_expect_next(cpu, 0x060457B2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060457B2u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AF6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8B02u;
            if (nh_scpu_expect_next(cpu, 0x06045812u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060457C2u: {
            static const uint8_t expected_epoch[] = { 0xAEu, 0x71u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AF8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B71u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B72u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AFBu;
            if (nh_scpu_expect_next(cpu, 0x060457DAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060457DAu: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0xF0u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AFBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0xF0u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8AFDu;
            if (nh_scpu_expect_next(cpu, 0x060457EAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060457EAu: {
            static const uint8_t expected_epoch[] = { 0x9Du, 0x01u, 0x09u };
            if (nh_scpu_guard_code(cpu, bus, 0xC08AFDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint32_t destination_address;
            destination_address = ((((uint32_t)cpu->dbr << 16u) + 0x000901u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_write8(cpu, bus, destination_address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x8B00u;
            if (nh_scpu_expect_next(cpu, 0x06045802u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        default: return NH_SCPU_NOT_MINE;
    }
}
