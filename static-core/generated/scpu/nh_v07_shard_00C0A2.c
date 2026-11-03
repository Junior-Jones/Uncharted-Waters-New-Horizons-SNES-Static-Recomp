/* Generated direct New Horizons S-CPU authority; do not edit. */
#include "nh_v07_generated.h"

NHScpuExecResult nh_v07_shard_00C0A2(NHScpuState *cpu, const NHScpuBus *bus) {
    switch (nh_scpu_context_key(cpu)) {
        case 0x06051263u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A24Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            cpu->x &= 0x00FFu;
            cpu->y &= 0x00FFu;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA24Eu;
            if (nh_scpu_expect_next(cpu, 0x06051273u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051273u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A24Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000010u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA250u;
            if (nh_scpu_expect_next(cpu, 0x06051283u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06051283u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x7Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A250u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x7Fu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA252u;
            if (nh_scpu_expect_next(cpu, 0x06051293u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051293u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x0Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A252u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Cu) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA254u;
            if (nh_scpu_expect_next(cpu, 0x060512A3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060512A3u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x21u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A254u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x21u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA256u;
            if (nh_scpu_expect_next(cpu, 0x060512B1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060512B1u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A256u,
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
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA257u;
            if (nh_scpu_expect_next(cpu, 0x060512B9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060512B9u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x87u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A257u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F87u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F88u) & 0xFFFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA25Au;
            if (nh_scpu_expect_next(cpu, 0x060512D1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060512D1u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A25Au,
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
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA25Bu;
            if (nh_scpu_expect_next(cpu, 0x060512D9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060512D9u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A25Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA25Du;
            if (nh_scpu_expect_next(cpu, 0x060512E9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060512E9u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A25Du,
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
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA25Eu;
            if (nh_scpu_expect_next(cpu, 0x060512F1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060512F1u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A25Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Eu) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Fu) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA260u;
            if (nh_scpu_expect_next(cpu, 0x06051301u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06051301u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x87u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A260u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F87u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F88u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA263u;
            if (nh_scpu_expect_next(cpu, 0x06051319u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06051319u: {
            static const uint8_t expected_epoch[] = { 0x48u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A263u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA264u;
            if (nh_scpu_expect_next(cpu, 0x06051321u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06051321u: {
            static const uint8_t expected_epoch[] = { 0x9Cu, 0x8Bu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A264u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F8Bu) & 0xFFFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F8Cu) & 0xFFFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA267u;
            if (nh_scpu_expect_next(cpu, 0x06051339u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06051339u: {
            static const uint8_t expected_epoch[] = { 0x9Cu, 0x8Du, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A267u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F8Du) & 0xFFFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F8Eu) & 0xFFFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA26Au;
            if (nh_scpu_expect_next(cpu, 0x06051351u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06051351u: {
            static const uint8_t expected_epoch[] = { 0xA2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A26Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = 0x20u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA26Cu;
            if (nh_scpu_expect_next(cpu, 0x06051361u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051361u: {
            static const uint8_t expected_epoch[] = { 0x20u, 0x2Du, 0xA3u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A26Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xA2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x6Eu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA32Du;
            if (nh_scpu_expect_next(cpu, 0x06051969u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06051379u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A26Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA271u;
            if (nh_scpu_expect_next(cpu, 0x0605138Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605138Bu: {
            static const uint8_t expected_epoch[] = { 0xA2u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A271u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = 0x00u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA273u;
            if (nh_scpu_expect_next(cpu, 0x0605139Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605139Bu: {
            static const uint8_t expected_epoch[] = { 0xCAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A273u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint8_t)(cpu->x - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA274u;
            if (nh_scpu_expect_next(cpu, 0x060513A3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060513A3u: {
            static const uint8_t expected_epoch[] = { 0x10u, 0x11u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A274u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA287u;
                if (nh_scpu_expect_next(cpu, 0x0605143Bu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA276u;
            if (nh_scpu_expect_next(cpu, 0x060513B3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060513B3u: {
            static const uint8_t expected_epoch[] = { 0xA2u, 0x07u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A276u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = 0x07u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA278u;
            if (nh_scpu_expect_next(cpu, 0x060513C3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060513C3u: {
            static const uint8_t expected_epoch[] = { 0xA7u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A278u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t lo = 0u, hi = 0u;
            uint32_t address;
            uint8_t bank = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Eu) & 0xFFFFu), &lo) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Fu) & 0xFFFFu), &hi) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000010u) & 0xFFFFu), &bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            address = (uint32_t)lo | ((uint32_t)hi << 8) | ((uint32_t)bank << 16);
            if (nh_scpu_read8(cpu, bus, address, &lo) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = lo;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(right) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(right) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA27Au;
            if (nh_scpu_expect_next(cpu, 0x060513D3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (6u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060513D3u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x91u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A27Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F91u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA27Du;
            if (nh_scpu_expect_next(cpu, 0x060513EBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060513EBu: {
            static const uint8_t expected_epoch[] = { 0xE6u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A27Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Eu) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            value = (uint8_t)(value + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Eu) & 0xFFFFu), value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA27Fu;
            if (nh_scpu_expect_next(cpu, 0x060513FBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (5u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060513FBu: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A27Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA287u;
                if (nh_scpu_expect_next(cpu, 0x0605143Bu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA281u;
            if (nh_scpu_expect_next(cpu, 0x0605140Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605140Bu: {
            static const uint8_t expected_epoch[] = { 0xE6u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A281u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Fu) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            value = (uint8_t)(value + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Fu) & 0xFFFFu), value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA283u;
            if (nh_scpu_expect_next(cpu, 0x0605141Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (5u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0605141Bu: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A283u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA287u;
                if (nh_scpu_expect_next(cpu, 0x0605143Bu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA285u;
            if (nh_scpu_expect_next(cpu, 0x0605142Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605142Bu: {
            static const uint8_t expected_epoch[] = { 0xE6u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A285u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000010u) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            value = (uint8_t)(value + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000010u) & 0xFFFFu), value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA287u;
            if (nh_scpu_expect_next(cpu, 0x0605143Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (5u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0605143Bu: {
            static const uint8_t expected_epoch[] = { 0x0Eu, 0x91u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A287u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = (((uint32_t)cpu->dbr << 16u) + 0x000F91u);
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | ((value >> 7) & 1u));
            value = (uint8_t)(value << 1);
            if (nh_scpu_write8(cpu, bus, address, value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA28Au;
            if (nh_scpu_expect_next(cpu, 0x06051453u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06051453u: {
            static const uint8_t expected_epoch[] = { 0x90u, 0x16u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A28Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA2A2u;
                if (nh_scpu_expect_next(cpu, 0x06051513u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA28Cu;
            if (nh_scpu_expect_next(cpu, 0x06051463u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051463u: {
            static const uint8_t expected_epoch[] = { 0xA7u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A28Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t lo = 0u, hi = 0u;
            uint32_t address;
            uint8_t bank = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Eu) & 0xFFFFu), &lo) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Fu) & 0xFFFFu), &hi) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000010u) & 0xFFFFu), &bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            address = (uint32_t)lo | ((uint32_t)hi << 8) | ((uint32_t)bank << 16);
            if (nh_scpu_read8(cpu, bus, address, &lo) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = lo;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(right) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(right) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA28Eu;
            if (nh_scpu_expect_next(cpu, 0x06051473u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (6u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06051473u: {
            static const uint8_t expected_epoch[] = { 0x87u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A28Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u, bank = 0u;
            uint32_t data_address;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), &high) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Cu) & 0xFFFFu), &bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            data_address = ((uint32_t)bank << 16u) | ((uint32_t)high << 8u) | low;
            if (nh_scpu_write8(cpu, bus, data_address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA290u;
            if (nh_scpu_expect_next(cpu, 0x06051483u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (6u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06051483u: {
            static const uint8_t expected_epoch[] = { 0xE6u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A290u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Eu) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            value = (uint8_t)(value + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Eu) & 0xFFFFu), value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA292u;
            if (nh_scpu_expect_next(cpu, 0x06051493u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (5u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06051493u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A292u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA29Au;
                if (nh_scpu_expect_next(cpu, 0x060514D3u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA294u;
            if (nh_scpu_expect_next(cpu, 0x060514A3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060514A3u: {
            static const uint8_t expected_epoch[] = { 0xE6u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A294u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Fu) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            value = (uint8_t)(value + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Fu) & 0xFFFFu), value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA296u;
            if (nh_scpu_expect_next(cpu, 0x060514B3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (5u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060514B3u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A296u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA29Au;
                if (nh_scpu_expect_next(cpu, 0x060514D3u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA298u;
            if (nh_scpu_expect_next(cpu, 0x060514C3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060514C3u: {
            static const uint8_t expected_epoch[] = { 0xE6u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A298u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000010u) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            value = (uint8_t)(value + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000010u) & 0xFFFFu), value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA29Au;
            if (nh_scpu_expect_next(cpu, 0x060514D3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (5u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060514D3u: {
            static const uint8_t expected_epoch[] = { 0xE6u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A29Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            value = (uint8_t)(value + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA29Cu;
            if (nh_scpu_expect_next(cpu, 0x060514E3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (5u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060514E3u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0xD5u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A29Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA273u;
                if (nh_scpu_expect_next(cpu, 0x0605139Bu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA29Eu;
            if (nh_scpu_expect_next(cpu, 0x060514F3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060514F3u: {
            static const uint8_t expected_epoch[] = { 0xE6u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A29Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            value = (uint8_t)(value + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2A0u;
            if (nh_scpu_expect_next(cpu, 0x06051503u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (5u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06051503u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0xD1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2A0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA273u;
            if (nh_scpu_expect_next(cpu, 0x0605139Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051513u: {
            static const uint8_t expected_epoch[] = { 0xDAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2A2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->x) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2A3u;
            if (nh_scpu_expect_next(cpu, 0x0605151Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605151Bu: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2A3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2A5u;
            if (nh_scpu_expect_next(cpu, 0x06051529u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051529u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x87u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2A5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F87u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F88u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2A8u;
            if (nh_scpu_expect_next(cpu, 0x06051541u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06051541u: {
            static const uint8_t expected_epoch[] = { 0x30u, 0x31u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2A8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA2DBu;
                if (nh_scpu_expect_next(cpu, 0x060516D9u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2AAu;
            if (nh_scpu_expect_next(cpu, 0x06051551u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051551u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2AAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2ABu;
            if (nh_scpu_expect_next(cpu, 0x06051559u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051559u: {
            static const uint8_t expected_epoch[] = { 0xEBu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2ABu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((cpu->a & 0x00FFu) << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2ACu;
            if (nh_scpu_expect_next(cpu, 0x06051561u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051561u: {
            static const uint8_t expected_epoch[] = { 0xA8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2ACu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint8_t)cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2ADu;
            if (nh_scpu_expect_next(cpu, 0x06051569u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051569u: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x0Du };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2ADu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA2BCu;
                if (nh_scpu_expect_next(cpu, 0x060515E1u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2AFu;
            if (nh_scpu_expect_next(cpu, 0x06051579u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051579u: {
            static const uint8_t expected_epoch[] = { 0xC0u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2AFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t result = (uint8_t)(cpu->y - 0x08u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (cpu->y >= 0x08u) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x80u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2B1u;
            if (nh_scpu_expect_next(cpu, 0x06051589u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051589u: {
            static const uint8_t expected_epoch[] = { 0xB0u, 0x17u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2B1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA2CAu;
                if (nh_scpu_expect_next(cpu, 0x06051651u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2B3u;
            if (nh_scpu_expect_next(cpu, 0x06051599u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051599u: {
            static const uint8_t expected_epoch[] = { 0xEBu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2B3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((cpu->a & 0x00FFu) << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2B4u;
            if (nh_scpu_expect_next(cpu, 0x060515A1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060515A1u: {
            static const uint8_t expected_epoch[] = { 0xBEu, 0x6Eu, 0xA1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2B4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = ((((uint32_t)cpu->dbr << 16u) + 0x00A16Eu) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2B7u;
            if (nh_scpu_expect_next(cpu, 0x060515B9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + (((0x6Eu + (uint32_t)cpu->y) > 0xFFu) ? 1u : 0u));
        }

        case 0x060515B9u: {
            static const uint8_t expected_epoch[] = { 0xFCu, 0xE2u, 0xA3u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2B7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->x & 1u) != 0u || cpu->x > 30u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_INDEXED_CALL_DOMAIN");
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xA2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xB9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            uint8_t lo = 0u, hi = 0u;
            const uint32_t pointer = ((uint32_t)cpu->pbr << 16) | ((0xA3E2u + (uint32_t)cpu->x) & 0xFFFFu);
            if (nh_scpu_read8(cpu, bus, pointer, &lo) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (pointer & 0xFF0000u) | ((pointer + 1u) & 0xFFFFu), &hi) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t target_pc = (uint16_t)((uint16_t)lo | ((uint16_t)hi << 8));
            if (!((cpu->x == 0u && target_pc == 0xA429u) || (cpu->x == 2u && target_pc == 0xA428u) || (cpu->x == 4u && target_pc == 0xA427u) || (cpu->x == 6u && target_pc == 0xA426u) || (cpu->x == 8u && target_pc == 0xA425u) || (cpu->x == 10u && target_pc == 0xA424u) || (cpu->x == 12u && target_pc == 0xA423u) || (cpu->x == 14u && target_pc == 0xA422u) || (cpu->x == 16u && target_pc == 0xA41Du) || (cpu->x == 18u && target_pc == 0xA41Cu) || (cpu->x == 20u && target_pc == 0xA41Bu) || (cpu->x == 22u && target_pc == 0xA41Au) || (cpu->x == 24u && target_pc == 0xA419u) || (cpu->x == 26u && target_pc == 0xA411u) || (cpu->x == 28u && target_pc == 0xA40Au) || (cpu->x == 30u && target_pc == 0xA404u)))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "MUTATED_INDEXED_CALL_TABLE");
            cpu->pc = target_pc;
            const uint32_t target_key = nh_scpu_context_key(cpu);
            if (nh_scpu_expect_next(cpu, target_key) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060515D1u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x14u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2BAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2D0u;
            if (nh_scpu_expect_next(cpu, 0x06051681u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060515E1u: {
            static const uint8_t expected_epoch[] = { 0xEBu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2BCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((cpu->a & 0x00FFu) << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2BDu;
            if (nh_scpu_expect_next(cpu, 0x060515E9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060515E9u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2BDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2BEu;
            if (nh_scpu_expect_next(cpu, 0x060515F1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060515F1u: {
            static const uint8_t expected_epoch[] = { 0x09u, 0x80u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2BEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a | 0x0080u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2C1u;
            if (nh_scpu_expect_next(cpu, 0x06051609u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051609u: {
            static const uint8_t expected_epoch[] = { 0xC9u, 0xFFu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2C1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= 0x00FFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2C4u;
            if (nh_scpu_expect_next(cpu, 0x06051621u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051621u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2C4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA2D0u;
                if (nh_scpu_expect_next(cpu, 0x06051681u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2C6u;
            if (nh_scpu_expect_next(cpu, 0x06051631u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051631u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2C6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2C8u;
            if (nh_scpu_expect_next(cpu, 0x06051643u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051643u: {
            static const uint8_t expected_epoch[] = { 0xFAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2C8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_pull8(cpu, bus, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2C9u;
            if (nh_scpu_expect_next(cpu, 0x0605164Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605164Bu: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2C9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            if (nh_scpu_context_key(cpu) != 0x06050693u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06051651u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2CAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2CCu;
            if (nh_scpu_expect_next(cpu, 0x06051661u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051661u: {
            static const uint8_t expected_epoch[] = { 0xBEu, 0xEFu, 0xA0u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2CCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = ((((uint32_t)cpu->dbr << 16u) + 0x00A0EFu) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2CFu;
            if (nh_scpu_expect_next(cpu, 0x06051679u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + (((0xEFu + (uint32_t)cpu->y) > 0xFFu) ? 1u : 0u));
        }

        case 0x06051679u: {
            static const uint8_t expected_epoch[] = { 0x8Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2CFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint8_t)cpu->x;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2D0u;
            if (nh_scpu_expect_next(cpu, 0x06051681u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051681u: {
            static const uint8_t expected_epoch[] = { 0x48u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2D0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2D1u;
            if (nh_scpu_expect_next(cpu, 0x06051689u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06051689u: {
            static const uint8_t expected_epoch[] = { 0xBEu, 0x2Fu, 0xA1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2D1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = ((((uint32_t)cpu->dbr << 16u) + 0x00A12Fu) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2D4u;
            if (nh_scpu_expect_next(cpu, 0x060516A1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + (((0x2Fu + (uint32_t)cpu->y) > 0xFFu) ? 1u : 0u));
        }

        case 0x060516A1u: {
            static const uint8_t expected_epoch[] = { 0x20u, 0x2Du, 0xA3u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2D4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xA2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xD6u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA32Du;
            if (nh_scpu_expect_next(cpu, 0x06051969u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060516B9u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2D7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2D9u;
            if (nh_scpu_expect_next(cpu, 0x060516C9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060516C9u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2D9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2DEu;
            if (nh_scpu_expect_next(cpu, 0x060516F1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060516D9u: {
            static const uint8_t expected_epoch[] = { 0xF4u, 0x01u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2DBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x00u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x01u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2DEu;
            if (nh_scpu_expect_next(cpu, 0x060516F1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060516F1u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2DEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2DFu;
            if (nh_scpu_expect_next(cpu, 0x060516F9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060516F9u: {
            static const uint8_t expected_epoch[] = { 0xC9u, 0x00u, 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2DFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - 0x6000u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= 0x6000u) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2E2u;
            if (nh_scpu_expect_next(cpu, 0x06051711u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051711u: {
            static const uint8_t expected_epoch[] = { 0xB0u, 0x12u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2E2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA2F6u;
                if (nh_scpu_expect_next(cpu, 0x060517B1u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2E4u;
            if (nh_scpu_expect_next(cpu, 0x06051721u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051721u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2E4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2E5u;
            if (nh_scpu_expect_next(cpu, 0x06051729u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051729u: {
            static const uint8_t expected_epoch[] = { 0xEBu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2E5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((cpu->a & 0x00FFu) << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2E6u;
            if (nh_scpu_expect_next(cpu, 0x06051731u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051731u: {
            static const uint8_t expected_epoch[] = { 0xA8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2E6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint8_t)cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2E7u;
            if (nh_scpu_expect_next(cpu, 0x06051739u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051739u: {
            static const uint8_t expected_epoch[] = { 0xBEu, 0x76u, 0xA1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2E7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = ((((uint32_t)cpu->dbr << 16u) + 0x00A176u) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2EAu;
            if (nh_scpu_expect_next(cpu, 0x06051751u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + (((0x76u + (uint32_t)cpu->y) > 0xFFu) ? 1u : 0u));
        }

        case 0x06051751u: {
            static const uint8_t expected_epoch[] = { 0x98u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2EAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint8_t)cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2EBu;
            if (nh_scpu_expect_next(cpu, 0x06051759u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051759u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2EBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2ECu;
            if (nh_scpu_expect_next(cpu, 0x06051761u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051761u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2ECu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2EDu;
            if (nh_scpu_expect_next(cpu, 0x06051769u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051769u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2EDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2EEu;
            if (nh_scpu_expect_next(cpu, 0x06051771u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051771u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2EEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2EFu;
            if (nh_scpu_expect_next(cpu, 0x06051779u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051779u: {
            static const uint8_t expected_epoch[] = { 0xA8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2EFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint8_t)cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2F0u;
            if (nh_scpu_expect_next(cpu, 0x06051781u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051781u: {
            static const uint8_t expected_epoch[] = { 0x8Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2F0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint8_t)cpu->x;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2F1u;
            if (nh_scpu_expect_next(cpu, 0x06051789u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051789u: {
            static const uint8_t expected_epoch[] = { 0xBEu, 0x36u, 0xA2u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2F1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = ((((uint32_t)cpu->dbr << 16u) + 0x00A236u) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2F4u;
            if (nh_scpu_expect_next(cpu, 0x060517A1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + (((0x36u + (uint32_t)cpu->y) > 0xFFu) ? 1u : 0u));
        }

        case 0x060517A1u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x1Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2F4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA310u;
            if (nh_scpu_expect_next(cpu, 0x06051881u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060517B1u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2F6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2F7u;
            if (nh_scpu_expect_next(cpu, 0x060517B9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060517B9u: {
            static const uint8_t expected_epoch[] = { 0x2Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2F7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t old = cpu->a;
            const uint16_t result = (uint16_t)(((uint32_t)old << 1) | (((cpu->p & NH_P_C) != 0u) ? 1u : 0u));
            cpu->a = result;
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | ((old >> 15) & 1u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2F8u;
            if (nh_scpu_expect_next(cpu, 0x060517C1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060517C1u: {
            static const uint8_t expected_epoch[] = { 0x2Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2F8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t old = cpu->a;
            const uint16_t result = (uint16_t)(((uint32_t)old << 1) | (((cpu->p & NH_P_C) != 0u) ? 1u : 0u));
            cpu->a = result;
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | ((old >> 15) & 1u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2F9u;
            if (nh_scpu_expect_next(cpu, 0x060517C9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060517C9u: {
            static const uint8_t expected_epoch[] = { 0x2Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2F9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t old = cpu->a;
            const uint16_t result = (uint16_t)(((uint32_t)old << 1) | (((cpu->p & NH_P_C) != 0u) ? 1u : 0u));
            cpu->a = result;
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | ((old >> 15) & 1u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2FAu;
            if (nh_scpu_expect_next(cpu, 0x060517D1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060517D1u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x07u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2FAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x0007u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2FDu;
            if (nh_scpu_expect_next(cpu, 0x060517E9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060517E9u: {
            static const uint8_t expected_epoch[] = { 0xA8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2FDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint8_t)cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA2FEu;
            if (nh_scpu_expect_next(cpu, 0x060517F1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060517F1u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x87u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A2FEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F87u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F88u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA301u;
            if (nh_scpu_expect_next(cpu, 0x06051809u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        default: return NH_SCPU_NOT_MINE;
    }
}
