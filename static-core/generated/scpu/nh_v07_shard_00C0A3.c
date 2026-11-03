/* Generated direct New Horizons S-CPU authority; do not edit. */
#include "nh_v07_generated.h"

NHScpuExecResult nh_v07_shard_00C0A3(NHScpuState *cpu, const NHScpuBus *bus) {
    switch (nh_scpu_context_key(cpu)) {
        case 0x06051809u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0xFFu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A301u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x0FFFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA304u;
            if (nh_scpu_expect_next(cpu, 0x06051821u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051821u: {
            static const uint8_t expected_epoch[] = { 0x09u, 0x00u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A304u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a | 0x1000u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA307u;
            if (nh_scpu_expect_next(cpu, 0x06051839u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051839u: {
            static const uint8_t expected_epoch[] = { 0xBEu, 0x3Fu, 0xA2u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A307u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = ((((uint32_t)cpu->dbr << 16u) + 0x00A23Fu) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA30Au;
            if (nh_scpu_expect_next(cpu, 0x06051851u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + (((0x3Fu + (uint32_t)cpu->y) > 0xFFu) ? 1u : 0u));
        }

        case 0x06051851u: {
            static const uint8_t expected_epoch[] = { 0xFCu, 0xE2u, 0xA3u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A30Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->x & 1u) != 0u || cpu->x > 30u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_INDEXED_CALL_DOMAIN");
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xA3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x0Cu) != NH_SCPU_EXECUTED)
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

        case 0x06051869u: {
            static const uint8_t expected_epoch[] = { 0xBEu, 0x44u, 0xA2u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A30Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = ((((uint32_t)cpu->dbr << 16u) + 0x00A244u) + (uint32_t)cpu->y) & 0xFFFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA310u;
            if (nh_scpu_expect_next(cpu, 0x06051881u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + (((0x44u + (uint32_t)cpu->y) > 0xFFu) ? 1u : 0u));
        }

        case 0x06051881u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x8Fu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A310u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F8Fu) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F90u) & 0xFFFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA313u;
            if (nh_scpu_expect_next(cpu, 0x06051899u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06051899u: {
            static const uint8_t expected_epoch[] = { 0x20u, 0x2Du, 0xA3u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A313u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xA3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x15u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA32Du;
            if (nh_scpu_expect_next(cpu, 0x06051969u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060518B1u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x11u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A316u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x11u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA318u;
            if (nh_scpu_expect_next(cpu, 0x060518C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060518C0u: {
            static const uint8_t expected_epoch[] = { 0xA4u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A318u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->y = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA31Au;
            if (nh_scpu_expect_next(cpu, 0x060518D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060518D0u: {
            static const uint8_t expected_epoch[] = { 0x98u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A31Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA31Bu;
            if (nh_scpu_expect_next(cpu, 0x060518D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060518D8u: {
            static const uint8_t expected_epoch[] = { 0xEDu, 0x8Fu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A31Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F8Fu) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F90u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t left = cpu->a;
            const uint32_t borrow = (cpu->p & NH_P_C) != 0u ? 0u : 1u;
            const uint16_t result = (uint16_t)((uint32_t)left - (uint32_t)right - borrow);
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if ((uint32_t)left >= (uint32_t)right + borrow) cpu->p |= NH_P_C;
            if (((left ^ right) & (left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA31Eu;
            if (nh_scpu_expect_next(cpu, 0x060518F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060518F0u: {
            static const uint8_t expected_epoch[] = { 0xAAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A31Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA31Fu;
            if (nh_scpu_expect_next(cpu, 0x060518F8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060518F8u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A31Fu,
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
            cpu->pc = 0xA320u;
            if (nh_scpu_expect_next(cpu, 0x06051900u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06051900u: {
            static const uint8_t expected_epoch[] = { 0x8Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A320u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, cpu->dbr) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA321u;
            if (nh_scpu_expect_next(cpu, 0x06051908u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051908u: {
            static const uint8_t expected_epoch[] = { 0x54u, 0x7Fu, 0x7Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A321u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t source_address = (0x7Fu << 16u) | (uint32_t)cpu->x;
            const uint32_t destination_address = (0x7Fu << 16u) | (uint32_t)cpu->y;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, source_address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, destination_address, value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->dbr = 0x7Fu;
            cpu->x = (uint16_t)((cpu->x + (1)) & 0xFFFFu);
            cpu->y = (uint16_t)((cpu->y + (1)) & 0xFFFFu);
            cpu->a = (uint16_t)(cpu->a - 1u);
            if (cpu->a != 0xFFFFu) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA321u;
                if (nh_scpu_expect_next(cpu, 0x06051908u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 7u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA324u;
            if (nh_scpu_expect_next(cpu, 0x06051920u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u);
        }

        case 0x06051920u: {
            static const uint8_t expected_epoch[] = { 0xABu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A324u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_pull8(cpu, bus, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->dbr = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA325u;
            if (nh_scpu_expect_next(cpu, 0x06051928u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06051928u: {
            static const uint8_t expected_epoch[] = { 0x84u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A325u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), (uint8_t)cpu->y) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), (uint8_t)(cpu->y >> 8)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA327u;
            if (nh_scpu_expect_next(cpu, 0x06051938u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06051938u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A327u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            cpu->x &= 0x00FFu;
            cpu->y &= 0x00FFu;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA329u;
            if (nh_scpu_expect_next(cpu, 0x0605194Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605194Bu: {
            static const uint8_t expected_epoch[] = { 0xFAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A329u,
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
            cpu->pc = 0xA32Au;
            if (nh_scpu_expect_next(cpu, 0x06051953u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06051953u: {
            static const uint8_t expected_epoch[] = { 0x4Cu, 0x73u, 0xA2u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A32Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA273u;
            if (nh_scpu_expect_next(cpu, 0x0605139Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051969u: {
            static const uint8_t expected_epoch[] = { 0x8Eu, 0x8Du, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A32Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F8Du) & 0xFFFFFFu), (uint8_t)cpu->x) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA330u;
            if (nh_scpu_expect_next(cpu, 0x06051981u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06051981u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x87u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A330u,
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
            cpu->pc = 0xA333u;
            if (nh_scpu_expect_next(cpu, 0x06051999u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06051999u: {
            static const uint8_t expected_epoch[] = { 0xFCu, 0x9Au, 0xA3u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A333u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->x & 1u) != 0u || cpu->x > 32u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_INDEXED_CALL_DOMAIN");
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xA3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x35u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            uint8_t lo = 0u, hi = 0u;
            const uint32_t pointer = ((uint32_t)cpu->pbr << 16) | ((0xA39Au + (uint32_t)cpu->x) & 0xFFFFu);
            if (nh_scpu_read8(cpu, bus, pointer, &lo) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (pointer & 0xFF0000u) | ((pointer + 1u) & 0xFFFFu), &hi) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t target_pc = (uint16_t)((uint16_t)lo | ((uint16_t)hi << 8));
            if (!((cpu->x == 0u && target_pc == 0xA3E1u) || (cpu->x == 2u && target_pc == 0xA3E0u) || (cpu->x == 4u && target_pc == 0xA3DFu) || (cpu->x == 6u && target_pc == 0xA3DEu) || (cpu->x == 8u && target_pc == 0xA3DDu) || (cpu->x == 10u && target_pc == 0xA3DCu) || (cpu->x == 12u && target_pc == 0xA3DBu) || (cpu->x == 14u && target_pc == 0xA3DAu) || (cpu->x == 16u && target_pc == 0xA3D5u) || (cpu->x == 18u && target_pc == 0xA3D4u) || (cpu->x == 20u && target_pc == 0xA3D3u) || (cpu->x == 22u && target_pc == 0xA3D2u) || (cpu->x == 24u && target_pc == 0xA3D1u) || (cpu->x == 26u && target_pc == 0xA3C9u) || (cpu->x == 28u && target_pc == 0xA3C2u) || (cpu->x == 30u && target_pc == 0xA3BCu) || (cpu->x == 32u && target_pc == 0xA42Au)))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "MUTATED_INDEXED_CALL_TABLE");
            cpu->pc = target_pc;
            const uint32_t target_key = nh_scpu_context_key(cpu);
            if (nh_scpu_expect_next(cpu, target_key) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060519B1u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x87u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A336u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F87u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F88u) & 0xFFFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA339u;
            if (nh_scpu_expect_next(cpu, 0x060519C9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060519C9u: {
            static const uint8_t expected_epoch[] = { 0xAEu, 0x8Bu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A339u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t lo = 0u, hi = 0u;
            uint32_t address;
            address = (((uint32_t)cpu->dbr << 16u) + 0x000F8Bu);
            if (nh_scpu_read8(cpu, bus, address, &lo) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = lo;
            cpu->x = (uint8_t)right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(right) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(right) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA33Cu;
            if (nh_scpu_expect_next(cpu, 0x060519E1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060519E1u: {
            static const uint8_t expected_epoch[] = { 0xECu, 0x8Du, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A33Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t lo = 0u, hi = 0u;
            uint32_t address;
            address = (((uint32_t)cpu->dbr << 16u) + 0x000F8Du);
            if (nh_scpu_read8(cpu, bus, address, &lo) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = lo;
            const uint8_t result = (uint8_t)((uint8_t)cpu->x - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (cpu->x >= right) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x80u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA33Fu;
            if (nh_scpu_expect_next(cpu, 0x060519F9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060519F9u: {
            static const uint8_t expected_epoch[] = { 0xB0u, 0x2Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A33Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA36Cu;
                if (nh_scpu_expect_next(cpu, 0x06051B61u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA341u;
            if (nh_scpu_expect_next(cpu, 0x06051A09u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051A09u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x8Du, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A341u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F8Du) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F8Eu) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA344u;
            if (nh_scpu_expect_next(cpu, 0x06051A21u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06051A21u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A344u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA345u;
            if (nh_scpu_expect_next(cpu, 0x06051A29u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051A29u: {
            static const uint8_t expected_epoch[] = { 0xEDu, 0x8Bu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A345u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            uint8_t lo = 0u, hi = 0u;
            uint32_t address;
            address = (((uint32_t)cpu->dbr << 16u) + 0x000F8Bu);
            if (nh_scpu_read8(cpu, bus, address, &lo) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &hi) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)((uint16_t)lo | ((uint16_t)hi << 8));
            const uint16_t left = cpu->a;
            const uint32_t total = (uint32_t)left - (uint32_t)right - (((cpu->p & NH_P_C) != 0u) ? 0u : 1u);
            const uint16_t result = (uint16_t)total;
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (total <= 0xFFFFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            if (((left ^ right) & (left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA348u;
            if (nh_scpu_expect_next(cpu, 0x06051A41u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06051A41u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x8Du, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A348u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F8Du) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F8Eu) & 0xFFFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA34Bu;
            if (nh_scpu_expect_next(cpu, 0x06051A59u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06051A59u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x89u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A34Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F89u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F8Au) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA34Eu;
            if (nh_scpu_expect_next(cpu, 0x06051A71u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06051A71u: {
            static const uint8_t expected_epoch[] = { 0x3Du, 0xD5u, 0xA0u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A34Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t lo = 0u, hi = 0u;
            uint32_t address;
            address = ((((uint32_t)cpu->dbr << 16u) + 0x00A0D5u) + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &lo) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &hi) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)((uint16_t)lo | ((uint16_t)hi << 8));
            cpu->a = (uint16_t)(cpu->a & right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA351u;
            if (nh_scpu_expect_next(cpu, 0x06051A89u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u + (((0xD5u + (uint32_t)cpu->x) > 0xFFu) ? 1u : 0u));
        }

        case 0x06051A89u: {
            static const uint8_t expected_epoch[] = { 0xAEu, 0x8Du, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A351u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t lo = 0u, hi = 0u;
            uint32_t address;
            address = (((uint32_t)cpu->dbr << 16u) + 0x000F8Du);
            if (nh_scpu_read8(cpu, bus, address, &lo) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = lo;
            cpu->x = (uint8_t)right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(right) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(right) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA354u;
            if (nh_scpu_expect_next(cpu, 0x06051AA1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06051AA1u: {
            static const uint8_t expected_epoch[] = { 0xFCu, 0x9Au, 0xA3u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A354u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->x & 1u) != 0u || cpu->x > 32u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_INDEXED_CALL_DOMAIN");
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xA3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x56u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            uint8_t lo = 0u, hi = 0u;
            const uint32_t pointer = ((uint32_t)cpu->pbr << 16) | ((0xA39Au + (uint32_t)cpu->x) & 0xFFFFu);
            if (nh_scpu_read8(cpu, bus, pointer, &lo) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (pointer & 0xFF0000u) | ((pointer + 1u) & 0xFFFFu), &hi) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t target_pc = (uint16_t)((uint16_t)lo | ((uint16_t)hi << 8));
            if (!((cpu->x == 0u && target_pc == 0xA3E1u) || (cpu->x == 2u && target_pc == 0xA3E0u) || (cpu->x == 4u && target_pc == 0xA3DFu) || (cpu->x == 6u && target_pc == 0xA3DEu) || (cpu->x == 8u && target_pc == 0xA3DDu) || (cpu->x == 10u && target_pc == 0xA3DCu) || (cpu->x == 12u && target_pc == 0xA3DBu) || (cpu->x == 14u && target_pc == 0xA3DAu) || (cpu->x == 16u && target_pc == 0xA3D5u) || (cpu->x == 18u && target_pc == 0xA3D4u) || (cpu->x == 20u && target_pc == 0xA3D3u) || (cpu->x == 22u && target_pc == 0xA3D2u) || (cpu->x == 24u && target_pc == 0xA3D1u) || (cpu->x == 26u && target_pc == 0xA3C9u) || (cpu->x == 28u && target_pc == 0xA3C2u) || (cpu->x == 30u && target_pc == 0xA3BCu) || (cpu->x == 32u && target_pc == 0xA42Au)))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "MUTATED_INDEXED_CALL_TABLE");
            cpu->pc = target_pc;
            const uint32_t target_key = nh_scpu_context_key(cpu);
            if (nh_scpu_expect_next(cpu, target_key) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x06051AB9u: {
            static const uint8_t expected_epoch[] = { 0x0Cu, 0x87u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A357u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t lo = 0u, hi = 0u;
            uint32_t address;
            address = (((uint32_t)cpu->dbr << 16u) + 0x000F87u);
            if (nh_scpu_read8(cpu, bus, address, &lo) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &hi) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)((uint16_t)lo | ((uint16_t)hi << 8));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_Z);
            if ((cpu->a & right) == 0u) cpu->p |= NH_P_Z;
            const uint16_t result = (uint16_t)(cpu->a | right);
            if (nh_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFFFu, (uint8_t)(result >> 8)) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, address, (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA35Au;
            if (nh_scpu_expect_next(cpu, 0x06051AD1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x06051AD1u: {
            static const uint8_t expected_epoch[] = { 0xA7u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A35Au,
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
            if (nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &hi) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)((uint16_t)lo | ((uint16_t)hi << 8));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(right) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(right) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA35Cu;
            if (nh_scpu_expect_next(cpu, 0x06051AE1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06051AE1u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x89u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A35Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F89u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F8Au) & 0xFFFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA35Fu;
            if (nh_scpu_expect_next(cpu, 0x06051AF9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06051AF9u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A35Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Eu) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Fu) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA361u;
            if (nh_scpu_expect_next(cpu, 0x06051B09u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06051B09u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A361u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA362u;
            if (nh_scpu_expect_next(cpu, 0x06051B11u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051B11u: {
            static const uint8_t expected_epoch[] = { 0x69u, 0x02u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A362u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            const uint16_t right = 0x0002u;
            const uint16_t left = cpu->a;
            const uint32_t total = (uint32_t)left + (uint32_t)right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            const uint16_t result = (uint16_t)total;
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (total > 0xFFFFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            if (((uint16_t)(~(left ^ right)) & (left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA365u;
            if (nh_scpu_expect_next(cpu, 0x06051B29u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051B29u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A365u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Eu) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Fu) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA367u;
            if (nh_scpu_expect_next(cpu, 0x06051B39u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06051B39u: {
            static const uint8_t expected_epoch[] = { 0xB0u, 0x1Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A367u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA387u;
                if (nh_scpu_expect_next(cpu, 0x06051C39u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA369u;
            if (nh_scpu_expect_next(cpu, 0x06051B49u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051B49u: {
            static const uint8_t expected_epoch[] = { 0xA2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A369u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = 0x20u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA36Bu;
            if (nh_scpu_expect_next(cpu, 0x06051B59u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051B59u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A36Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA36Cu;
            if (nh_scpu_expect_next(cpu, 0x06051B61u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051B61u: {
            static const uint8_t expected_epoch[] = { 0x8Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A36Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint8_t)cpu->x;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA36Du;
            if (nh_scpu_expect_next(cpu, 0x06051B69u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051B69u: {
            static const uint8_t expected_epoch[] = { 0xEDu, 0x8Du, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A36Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            uint8_t lo = 0u, hi = 0u;
            uint32_t address;
            address = (((uint32_t)cpu->dbr << 16u) + 0x000F8Du);
            if (nh_scpu_read8(cpu, bus, address, &lo) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &hi) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)((uint16_t)lo | ((uint16_t)hi << 8));
            const uint16_t left = cpu->a;
            const uint32_t total = (uint32_t)left - (uint32_t)right - (((cpu->p & NH_P_C) != 0u) ? 0u : 1u);
            const uint16_t result = (uint16_t)total;
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (total <= 0xFFFFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            if (((left ^ right) & (left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA370u;
            if (nh_scpu_expect_next(cpu, 0x06051B81u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06051B81u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x8Bu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A370u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F8Bu) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F8Cu) & 0xFFFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA373u;
            if (nh_scpu_expect_next(cpu, 0x06051B99u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06051B99u: {
            static const uint8_t expected_epoch[] = { 0xAAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A373u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint8_t)cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA374u;
            if (nh_scpu_expect_next(cpu, 0x06051BA1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051BA1u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x89u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A374u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F89u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F8Au) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA377u;
            if (nh_scpu_expect_next(cpu, 0x06051BB9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06051BB9u: {
            static const uint8_t expected_epoch[] = { 0xFCu, 0xE2u, 0xA3u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A377u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->x & 1u) != 0u || cpu->x > 30u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_INDEXED_CALL_DOMAIN");
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xA3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x79u) != NH_SCPU_EXECUTED)
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

        case 0x06051BD1u: {
            static const uint8_t expected_epoch[] = { 0xAEu, 0x8Du, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A37Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t lo = 0u, hi = 0u;
            uint32_t address;
            address = (((uint32_t)cpu->dbr << 16u) + 0x000F8Du);
            if (nh_scpu_read8(cpu, bus, address, &lo) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = lo;
            cpu->x = (uint8_t)right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(right) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(right) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA37Du;
            if (nh_scpu_expect_next(cpu, 0x06051BE9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06051BE9u: {
            static const uint8_t expected_epoch[] = { 0x3Du, 0xD5u, 0xA0u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A37Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t lo = 0u, hi = 0u;
            uint32_t address;
            address = ((((uint32_t)cpu->dbr << 16u) + 0x00A0D5u) + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &lo) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &hi) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)((uint16_t)lo | ((uint16_t)hi << 8));
            cpu->a = (uint16_t)(cpu->a & right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA380u;
            if (nh_scpu_expect_next(cpu, 0x06051C01u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u + (((0xD5u + (uint32_t)cpu->x) > 0xFFu) ? 1u : 0u));
        }

        case 0x06051C01u: {
            static const uint8_t expected_epoch[] = { 0x0Du, 0x87u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A380u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t lo = 0u, hi = 0u;
            uint32_t address;
            address = (((uint32_t)cpu->dbr << 16u) + 0x000F87u);
            if (nh_scpu_read8(cpu, bus, address, &lo) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &hi) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)((uint16_t)lo | ((uint16_t)hi << 8));
            cpu->a = (uint16_t)(cpu->a | right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA383u;
            if (nh_scpu_expect_next(cpu, 0x06051C19u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06051C19u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x87u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A383u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F87u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F88u) & 0xFFFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA386u;
            if (nh_scpu_expect_next(cpu, 0x06051C31u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06051C31u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A386u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x06051379u &&
                return_key != 0x060516B9u &&
                return_key != 0x060518B1u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06051C39u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A387u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA389u;
            if (nh_scpu_expect_next(cpu, 0x06051C4Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051C4Bu: {
            static const uint8_t expected_epoch[] = { 0xE6u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A389u,
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
            cpu->pc = 0xA38Bu;
            if (nh_scpu_expect_next(cpu, 0x06051C5Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (5u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06051C5Bu: {
            static const uint8_t expected_epoch[] = { 0xC6u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A38Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t lo = 0u, hi = 0u;
            uint32_t address;
            address = (uint32_t)((cpu->d + 0x00000Eu) & 0xFFFFu);
            if (nh_scpu_read8(cpu, bus, address, &lo) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = lo;
            const uint8_t result = (uint8_t)(right - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            if (nh_scpu_write8(cpu, bus, address, result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA38Du;
            if (nh_scpu_expect_next(cpu, 0x06051C6Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (5u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06051C6Bu: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x05u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A38Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA394u;
                if (nh_scpu_expect_next(cpu, 0x06051CA3u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA38Fu;
            if (nh_scpu_expect_next(cpu, 0x06051C7Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051C7Bu: {
            static const uint8_t expected_epoch[] = { 0xA7u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A38Fu,
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
            cpu->pc = 0xA391u;
            if (nh_scpu_expect_next(cpu, 0x06051C8Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (6u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06051C8Bu: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x8Au, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A391u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F8Au) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA394u;
            if (nh_scpu_expect_next(cpu, 0x06051CA3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x06051CA3u: {
            static const uint8_t expected_epoch[] = { 0xE6u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A394u,
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
            cpu->pc = 0xA396u;
            if (nh_scpu_expect_next(cpu, 0x06051CB3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (5u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06051CB3u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A396u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA398u;
            if (nh_scpu_expect_next(cpu, 0x06051CC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051CC1u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0xCFu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A398u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA369u;
            if (nh_scpu_expect_next(cpu, 0x06051B49u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051DE1u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x01u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3BCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x0001u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA3BFu;
            if (nh_scpu_expect_next(cpu, 0x06051DF9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051DF9u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3BFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA3C0u;
            if (nh_scpu_expect_next(cpu, 0x06051E01u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051E01u: {
            static const uint8_t expected_epoch[] = { 0x6Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3C0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            const uint16_t carry_in = (cpu->p & NH_P_C) != 0u ? 0x8000u : 0u;
            cpu->a = (uint16_t)((value >> 1u) | carry_in);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x0001u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA3C1u;
            if (nh_scpu_expect_next(cpu, 0x06051E09u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051E09u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3C1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x060519B1u &&
                return_key != 0x06051AB9u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06051E11u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x03u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3C2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x0003u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA3C5u;
            if (nh_scpu_expect_next(cpu, 0x06051E29u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051E29u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3C5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA3C6u;
            if (nh_scpu_expect_next(cpu, 0x06051E31u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051E31u: {
            static const uint8_t expected_epoch[] = { 0x6Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3C6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            const uint16_t carry_in = (cpu->p & NH_P_C) != 0u ? 0x8000u : 0u;
            cpu->a = (uint16_t)((value >> 1u) | carry_in);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x0001u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA3C7u;
            if (nh_scpu_expect_next(cpu, 0x06051E39u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051E39u: {
            static const uint8_t expected_epoch[] = { 0x6Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3C7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            const uint16_t carry_in = (cpu->p & NH_P_C) != 0u ? 0x8000u : 0u;
            cpu->a = (uint16_t)((value >> 1u) | carry_in);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x0001u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA3C8u;
            if (nh_scpu_expect_next(cpu, 0x06051E41u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051E41u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3C8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x060519B1u &&
                return_key != 0x06051AB9u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06051E49u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x07u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3C9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x0007u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA3CCu;
            if (nh_scpu_expect_next(cpu, 0x06051E61u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051E61u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3CCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA3CDu;
            if (nh_scpu_expect_next(cpu, 0x06051E69u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051E69u: {
            static const uint8_t expected_epoch[] = { 0x6Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3CDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            const uint16_t carry_in = (cpu->p & NH_P_C) != 0u ? 0x8000u : 0u;
            cpu->a = (uint16_t)((value >> 1u) | carry_in);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x0001u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA3CEu;
            if (nh_scpu_expect_next(cpu, 0x06051E71u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051E71u: {
            static const uint8_t expected_epoch[] = { 0x6Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3CEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            const uint16_t carry_in = (cpu->p & NH_P_C) != 0u ? 0x8000u : 0u;
            cpu->a = (uint16_t)((value >> 1u) | carry_in);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x0001u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA3CFu;
            if (nh_scpu_expect_next(cpu, 0x06051E79u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051E79u: {
            static const uint8_t expected_epoch[] = { 0x6Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3CFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            const uint16_t carry_in = (cpu->p & NH_P_C) != 0u ? 0x8000u : 0u;
            cpu->a = (uint16_t)((value >> 1u) | carry_in);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x0001u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA3D0u;
            if (nh_scpu_expect_next(cpu, 0x06051E81u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051E81u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3D0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x060519B1u &&
                return_key != 0x06051AB9u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06051E89u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3D1u,
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
            cpu->pc = 0xA3D2u;
            if (nh_scpu_expect_next(cpu, 0x06051E91u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051E91u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3D2u,
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
            cpu->pc = 0xA3D3u;
            if (nh_scpu_expect_next(cpu, 0x06051E99u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051E99u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3D3u,
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
            cpu->pc = 0xA3D4u;
            if (nh_scpu_expect_next(cpu, 0x06051EA1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051EA1u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3D4u,
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
            cpu->pc = 0xA3D5u;
            if (nh_scpu_expect_next(cpu, 0x06051EA9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051EA9u: {
            static const uint8_t expected_epoch[] = { 0xEBu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3D5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((cpu->a & 0x00FFu) << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA3D6u;
            if (nh_scpu_expect_next(cpu, 0x06051EB1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051EB1u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x00u, 0xFFu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3D6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0xFF00u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA3D9u;
            if (nh_scpu_expect_next(cpu, 0x06051EC9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06051EC9u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3D9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x060519B1u &&
                return_key != 0x06051AB9u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06051ED1u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3DAu,
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
            cpu->pc = 0xA3DBu;
            if (nh_scpu_expect_next(cpu, 0x06051ED9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051ED9u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3DBu,
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
            cpu->pc = 0xA3DCu;
            if (nh_scpu_expect_next(cpu, 0x06051EE1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051EE1u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3DCu,
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
            cpu->pc = 0xA3DDu;
            if (nh_scpu_expect_next(cpu, 0x06051EE9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051EE9u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3DDu,
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
            cpu->pc = 0xA3DEu;
            if (nh_scpu_expect_next(cpu, 0x06051EF1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051EF1u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3DEu,
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
            cpu->pc = 0xA3DFu;
            if (nh_scpu_expect_next(cpu, 0x06051EF9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051EF9u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3DFu,
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
            cpu->pc = 0xA3E0u;
            if (nh_scpu_expect_next(cpu, 0x06051F01u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051F01u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3E0u,
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
            cpu->pc = 0xA3E1u;
            if (nh_scpu_expect_next(cpu, 0x06051F09u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06051F09u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A3E1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x060519B1u &&
                return_key != 0x06051AB9u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        default: return NH_SCPU_NOT_MINE;
    }
}
