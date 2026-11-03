/* Generated direct New Horizons S-CPU authority; do not edit. */
#include "nh_v07_generated.h"

NHScpuExecResult nh_v07_shard_00C096(NHScpuState *cpu, const NHScpuBus *bus) {
    switch (nh_scpu_context_key(cpu)) {
        case 0x0604B00Au: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09601u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x00u);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9603u;
            if (nh_scpu_expect_next(cpu, 0x0604B01Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604B01Au: {
            static const uint8_t expected_epoch[] = { 0x48u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09603u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9604u;
            if (nh_scpu_expect_next(cpu, 0x0604B022u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604B022u: {
            static const uint8_t expected_epoch[] = { 0xABu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09604u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_pull8(cpu, bus, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->dbr = value;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9605u;
            if (nh_scpu_expect_next(cpu, 0x0604B02Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604B02Au: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09605u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9607u;
            if (nh_scpu_expect_next(cpu, 0x0604B038u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604B038u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09607u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x960Au;
            if (nh_scpu_expect_next(cpu, 0x0604B050u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604B050u: {
            static const uint8_t expected_epoch[] = { 0x5Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0960Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->d = cpu->a;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->d) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->d) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x960Bu;
            if (nh_scpu_expect_next(cpu, 0x0604B058u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604B058u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0960Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x960Eu;
            if (nh_scpu_expect_next(cpu, 0x0604B070u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604B070u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0960Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000068u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000069u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9610u;
            if (nh_scpu_expect_next(cpu, 0x0604B080u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0604B080u: {
            static const uint8_t expected_epoch[] = { 0x3Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09610u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = cpu->s;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9611u;
            if (nh_scpu_expect_next(cpu, 0x0604B088u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604B088u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09611u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9612u;
            if (nh_scpu_expect_next(cpu, 0x0604B090u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604B090u: {
            static const uint8_t expected_epoch[] = { 0x69u, 0x0Eu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09612u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t right = 0x000Eu;
            uint32_t sum;
            uint16_t result;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            sum = (uint32_t)left + (uint32_t)right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            result = (uint16_t)sum;
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & 0x3Cu);
            if (sum > 0xFFFFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            if (((uint16_t)(~(left ^ right)) & (uint16_t)(left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9615u;
            if (nh_scpu_expect_next(cpu, 0x0604B0A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604B0A8u: {
            static const uint8_t expected_epoch[] = { 0xAAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09615u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9616u;
            if (nh_scpu_expect_next(cpu, 0x0604B0B0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604B0B0u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x01u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09616u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0001u;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9619u;
            if (nh_scpu_expect_next(cpu, 0x0604B0C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604B0C8u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x52u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09619u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x0052u;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x961Cu;
            if (nh_scpu_expect_next(cpu, 0x0604B0E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604B0E0u: {
            static const uint8_t expected_epoch[] = { 0x54u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0961Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t source_address = (0x00u << 16u) | (uint32_t)cpu->x;
            const uint32_t destination_address = (0x00u << 16u) | (uint32_t)cpu->y;
            if (nh_scpu_copy8(cpu, bus, source_address, destination_address) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->dbr = 0x00u;
            cpu->x = (uint16_t)((cpu->x + (1)) & 0xFFFFu);
            cpu->y = (uint16_t)((cpu->y + (1)) & 0xFFFFu);
            cpu->a = (uint16_t)(cpu->a - 1u);
            if (cpu->a != 0xFFFFu) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0x961Cu;
                if (nh_scpu_expect_next(cpu, 0x0604B0E0u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 7u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0x961Fu;
            if (nh_scpu_expect_next(cpu, 0x0604B0F8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u);
        }

        case 0x0604B0F8u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x13u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0961Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0013u;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9622u;
            if (nh_scpu_expect_next(cpu, 0x0604B110u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604B110u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x54u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09622u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x0054u;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9625u;
            if (nh_scpu_expect_next(cpu, 0x0604B128u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604B128u: {
            static const uint8_t expected_epoch[] = { 0x54u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09625u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t source_address = (0x00u << 16u) | (uint32_t)cpu->x;
            const uint32_t destination_address = (0x00u << 16u) | (uint32_t)cpu->y;
            if (nh_scpu_copy8(cpu, bus, source_address, destination_address) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->dbr = 0x00u;
            cpu->x = (uint16_t)((cpu->x + (1)) & 0xFFFFu);
            cpu->y = (uint16_t)((cpu->y + (1)) & 0xFFFFu);
            cpu->a = (uint16_t)(cpu->a - 1u);
            if (cpu->a != 0xFFFFu) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0x9625u;
                if (nh_scpu_expect_next(cpu, 0x0604B128u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 7u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9628u;
            if (nh_scpu_expect_next(cpu, 0x0604B140u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u);
        }

        case 0x0604B140u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x52u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09628u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000052u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000053u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x962Bu;
            if (nh_scpu_expect_next(cpu, 0x0604B158u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604B158u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0xFFu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0962Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x962Eu;
            if (nh_scpu_expect_next(cpu, 0x0604B170u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604B170u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0962Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x962Fu;
            if (nh_scpu_expect_next(cpu, 0x0604B178u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604B178u: {
            static const uint8_t expected_epoch[] = { 0xAAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0962Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9630u;
            if (nh_scpu_expect_next(cpu, 0x0604B180u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604B180u: {
            static const uint8_t expected_epoch[] = { 0xFCu, 0x38u, 0x97u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09630u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (!(cpu->x == 0u || cpu->x == 2u || cpu->x == 6u || cpu->x == 8u || cpu->x == 10u || cpu->x == 12u || cpu->x == 14u || cpu->x == 16u || cpu->x == 18u || cpu->x == 22u || cpu->x == 24u || cpu->x == 26u || cpu->x == 28u || cpu->x == 30u || cpu->x == 32u || cpu->x == 34u || cpu->x == 36u || cpu->x == 38u || cpu->x == 40u || cpu->x == 42u || cpu->x == 44u || cpu->x == 68u || cpu->x == 70u || cpu->x == 72u || cpu->x == 74u || cpu->x == 76u || cpu->x == 78u || cpu->x == 82u || cpu->x == 84u || cpu->x == 86u || cpu->x == 92u || cpu->x == 94u || cpu->x == 96u || cpu->x == 104u || cpu->x == 110u || cpu->x == 112u || cpu->x == 114u || cpu->x == 116u || cpu->x == 138u || cpu->x == 140u || cpu->x == 142u || cpu->x == 144u || cpu->x == 150u || cpu->x == 152u || cpu->x == 156u || cpu->x == 160u || cpu->x == 162u || cpu->x == 164u || cpu->x == 168u || cpu->x == 170u || cpu->x == 174u || cpu->x == 180u || cpu->x == 184u || cpu->x == 206u || cpu->x == 208u || cpu->x == 210u || cpu->x == 214u || cpu->x == 216u || cpu->x == 222u || cpu->x == 224u || cpu->x == 226u || cpu->x == 228u || cpu->x == 230u || cpu->x == 232u || cpu->x == 234u || cpu->x == 244u || cpu->x == 246u))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_INDEXED_CALL_DOMAIN");
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x96u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x32u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            uint8_t low = 0u, high = 0u;
            const uint32_t pointer = ((uint32_t)cpu->pbr << 16u) | ((0x9738u + (uint32_t)cpu->x) & 0xFFFFu);
            if (nh_scpu_read8(cpu, bus, pointer, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (pointer & 0xFF0000u) | ((pointer + 1u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t target_pc = (uint16_t)(low | ((uint16_t)high << 8u));
            if (!((cpu->x == 0u && target_pc == 0x8010u) || (cpu->x == 2u && target_pc == 0x985Du) || (cpu->x == 6u && target_pc == 0x9ADCu) || (cpu->x == 8u && target_pc == 0x9B14u) || (cpu->x == 10u && target_pc == 0x9BB1u) || (cpu->x == 12u && target_pc == 0x9C08u) || (cpu->x == 14u && target_pc == 0x9C33u) || (cpu->x == 16u && target_pc == 0x9C5Eu) || (cpu->x == 18u && target_pc == 0x9C8Cu) || (cpu->x == 22u && target_pc == 0x9E4Cu) || (cpu->x == 24u && target_pc == 0x9E9Bu) || (cpu->x == 26u && target_pc == 0x9EEAu) || (cpu->x == 28u && target_pc == 0x9F15u) || (cpu->x == 30u && target_pc == 0x9F40u) || (cpu->x == 32u && target_pc == 0x9F4Cu) || (cpu->x == 34u && target_pc == 0x9F68u) || (cpu->x == 36u && target_pc == 0xB597u) || (cpu->x == 38u && target_pc == 0x9F8Fu) || (cpu->x == 40u && target_pc == 0x9FA7u) || (cpu->x == 42u && target_pc == 0xA938u) || (cpu->x == 44u && target_pc == 0x9FB4u) || (cpu->x == 68u && target_pc == 0x9FBCu) || (cpu->x == 70u && target_pc == 0x9FDEu) || (cpu->x == 72u && target_pc == 0xA954u) || (cpu->x == 74u && target_pc == 0xA96Eu) || (cpu->x == 76u && target_pc == 0xA9AEu) || (cpu->x == 78u && target_pc == 0xABAAu) || (cpu->x == 82u && target_pc == 0xAE65u) || (cpu->x == 84u && target_pc == 0xAD65u) || (cpu->x == 86u && target_pc == 0xADAAu) || (cpu->x == 92u && target_pc == 0xAEC0u) || (cpu->x == 94u && target_pc == 0xAED2u) || (cpu->x == 96u && target_pc == 0xAF0Cu) || (cpu->x == 104u && target_pc == 0xB49Du) || (cpu->x == 110u && target_pc == 0xB70Du) || (cpu->x == 112u && target_pc == 0xB889u) || (cpu->x == 114u && target_pc == 0xB8ABu) || (cpu->x == 116u && target_pc == 0xB99Au) || (cpu->x == 138u && target_pc == 0xA010u) || (cpu->x == 140u && target_pc == 0xA05Du) || (cpu->x == 142u && target_pc == 0xA09Du) || (cpu->x == 144u && target_pc == 0xBA6Eu) || (cpu->x == 150u && target_pc == 0xA0A5u) || (cpu->x == 152u && target_pc == 0xA0BEu) || (cpu->x == 156u && target_pc == 0xBB34u) || (cpu->x == 160u && target_pc == 0xAAACu) || (cpu->x == 162u && target_pc == 0xABD0u) || (cpu->x == 164u && target_pc == 0xA42Eu) || (cpu->x == 168u && target_pc == 0xA490u) || (cpu->x == 170u && target_pc == 0xBBEBu) || (cpu->x == 174u && target_pc == 0xA658u) || (cpu->x == 180u && target_pc == 0xBC51u) || (cpu->x == 184u && target_pc == 0xA56Fu) || (cpu->x == 206u && target_pc == 0xA67Cu) || (cpu->x == 208u && target_pc == 0xAE0Au) || (cpu->x == 210u && target_pc == 0xAF85u) || (cpu->x == 214u && target_pc == 0xAF28u) || (cpu->x == 216u && target_pc == 0xAF62u) || (cpu->x == 222u && target_pc == 0xC0D1u) || (cpu->x == 224u && target_pc == 0xC0FAu) || (cpu->x == 226u && target_pc == 0xC113u) || (cpu->x == 228u && target_pc == 0xC12Au) || (cpu->x == 230u && target_pc == 0xC143u) || (cpu->x == 232u && target_pc == 0xC15Au) || (cpu->x == 234u && target_pc == 0xC171u) || (cpu->x == 244u && target_pc == 0xA978u) || (cpu->x == 246u && target_pc == 0xBC7Fu)))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "MUTATED_INDEXED_CALL_TABLE");
            cpu->pc = target_pc;
            const uint32_t target_key = nh_scpu_context_key(cpu);
            if (nh_scpu_expect_next(cpu, target_key) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x0604B198u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09633u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9635u;
            if (nh_scpu_expect_next(cpu, 0x0604B1A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604B199u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09633u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9635u;
            if (nh_scpu_expect_next(cpu, 0x0604B1A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604B19Au: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09633u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9635u;
            if (nh_scpu_expect_next(cpu, 0x0604B1A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604B19Bu: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09633u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9635u;
            if (nh_scpu_expect_next(cpu, 0x0604B1A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604B1A8u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09635u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000068u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000069u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9637u;
            if (nh_scpu_expect_next(cpu, 0x0604B1B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0604B1B8u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x00u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09637u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000100u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000101u) & 0xFFFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x963Au;
            if (nh_scpu_expect_next(cpu, 0x0604B1D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604B1D0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x6Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0963Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00006Au) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00006Bu) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x963Cu;
            if (nh_scpu_expect_next(cpu, 0x0604B1E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0604B1E0u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x02u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0963Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000102u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000103u) & 0xFFFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x963Fu;
            if (nh_scpu_expect_next(cpu, 0x0604B1F8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604B1F8u: {
            static const uint8_t expected_epoch[] = { 0xABu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0963Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_pull8(cpu, bus, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->dbr = value;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9640u;
            if (nh_scpu_expect_next(cpu, 0x0604B200u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604B200u: {
            static const uint8_t expected_epoch[] = { 0x7Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC09640u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9641u;
            if (nh_scpu_expect_next(cpu, 0x0604B208u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604B208u: {
            static const uint8_t expected_epoch[] = { 0xFAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09641u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9642u;
            if (nh_scpu_expect_next(cpu, 0x0604B210u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604B210u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09642u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9643u;
            if (nh_scpu_expect_next(cpu, 0x0604B218u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604B218u: {
            static const uint8_t expected_epoch[] = { 0x2Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09643u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (nh_scpu_read8(cpu, bus, (uint32_t)cpu->s, &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s + 1u);
            if (nh_scpu_read8(cpu, bus, (uint32_t)cpu->s, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->d = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->d) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->d) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9644u;
            if (nh_scpu_expect_next(cpu, 0x0604B220u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604B220u: {
            static const uint8_t expected_epoch[] = { 0x28u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09644u,
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
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9645u;
            const uint32_t restored_key = nh_scpu_context_key(cpu);
            if (restored_key != 0x0604B228u && restored_key != 0x0604B22Au)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_SUCCESSOR_CONTEXT");
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604B228u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09645u,
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
            if (((((((((((return_key != 0x06080EC8u && (return_key != 0x06080FB8u && return_key != 0x06081060u)) && (return_key != 0x06081118u && (return_key != 0x060811F8u && return_key != 0x060812D8u))) && ((return_key != 0x060813B8u && (return_key != 0x06081498u && return_key != 0x06081578u)) && ((return_key != 0x06081670u && return_key != 0x06081768u) && (return_key != 0x06081860u && return_key != 0x060818F8u)))) && (((return_key != 0x06081990u && (return_key != 0x06081A30u && return_key != 0x06081AD0u)) && (return_key != 0x06081BF0u && (return_key != 0x06081CB0u && return_key != 0x06081D70u))) && ((return_key != 0x06081DD0u && (return_key != 0x06082848u && return_key != 0x06082968u)) && ((return_key != 0x060829A8u && return_key != 0x06082A00u) && (return_key != 0x06082D08u && return_key != 0x060833E0u))))) && ((((return_key != 0x06083978u && (return_key != 0x06088000u && return_key != 0x06088260u)) && (return_key != 0x06088850u && (return_key != 0x0608B500u && return_key != 0x060957A0u))) && ((return_key != 0x06095A38u && (return_key != 0x060963F8u && return_key != 0x06096648u)) && ((return_key != 0x06097390u && return_key != 0x060975B8u) && (return_key != 0x060984C0u && return_key != 0x06098768u)))) && (((return_key != 0x0609A248u && (return_key != 0x0609A8A0u && return_key != 0x0609B158u)) && ((return_key != 0x0609B490u && return_key != 0x0609B560u) && (return_key != 0x0609B8F8u && return_key != 0x0609BA30u))) && ((return_key != 0x0609BBA8u && (return_key != 0x0609BE78u && return_key != 0x0609C1B0u)) && ((return_key != 0x0609C308u && return_key != 0x0609C778u) && (return_key != 0x0609DFC0u && return_key != 0x0609E4F8u)))))) && (((((return_key != 0x060A4D68u && (return_key != 0x060A5178u && return_key != 0x060A51E8u)) && (return_key != 0x060AC930u && (return_key != 0x060ACC48u && return_key != 0x060B1538u))) && ((return_key != 0x060B19F8u && (return_key != 0x060B2380u && return_key != 0x060B2520u)) && ((return_key != 0x060B27C8u && return_key != 0x060B2A88u) && (return_key != 0x060B6C40u && return_key != 0x060B81E8u)))) && (((return_key != 0x060B8260u && (return_key != 0x060BE4E0u && return_key != 0x060BE5E8u)) && (return_key != 0x060BE750u && (return_key != 0x060BE7E8u && return_key != 0x060BE888u))) && ((return_key != 0x060BE910u && (return_key != 0x060BEA28u && return_key != 0x060BEB30u)) && ((return_key != 0x060BEC58u && return_key != 0x060BED50u) && (return_key != 0x060BEDF0u && return_key != 0x060BEE78u))))) && ((((return_key != 0x060BEF58u && (return_key != 0x060BEFF0u && return_key != 0x060BF090u)) && (return_key != 0x060BF1B0u && (return_key != 0x060BF4F0u && return_key != 0x060C1690u))) && ((return_key != 0x060C1A20u && (return_key != 0x060C20A8u && return_key != 0x060C2248u)) && ((return_key != 0x060C27A8u && return_key != 0x060C2948u) && (return_key != 0x060C2B30u && return_key != 0x060C3498u)))) && (((return_key != 0x060C7548u && (return_key != 0x060C7600u && return_key != 0x060C83F8u)) && ((return_key != 0x060C87F0u && return_key != 0x060C8AE8u) && (return_key != 0x060C8DF8u && return_key != 0x060C8F48u))) && ((return_key != 0x060C9528u && (return_key != 0x060C9668u && return_key != 0x060C97A8u)) && ((return_key != 0x060C98E8u && return_key != 0x060C9A28u) && (return_key != 0x060C9B68u && return_key != 0x060CA438u))))))) && ((((((return_key != 0x060CA628u && (return_key != 0x060CA848u && return_key != 0x060CAC38u)) && (return_key != 0x060CACE8u && (return_key != 0x060CADD8u && return_key != 0x060CB828u))) && ((return_key != 0x060CBC80u && (return_key != 0x060CBCF0u && return_key != 0x060CBD90u)) && ((return_key != 0x060CBF70u && return_key != 0x060CC328u) && (return_key != 0x060CC4A8u && return_key != 0x060CC880u)))) && (((return_key != 0x060CCA00u && (return_key != 0x060CCBB8u && return_key != 0x060CCCA8u)) && (return_key != 0x060CCE50u && (return_key != 0x060CD018u && return_key != 0x060CD998u))) && ((return_key != 0x060CDEB8u && (return_key != 0x060CDF90u && return_key != 0x060CDFE0u)) && ((return_key != 0x060CE190u && return_key != 0x060CE280u) && (return_key != 0x060CE3B0u && return_key != 0x060CE400u))))) && ((((return_key != 0x060DA810u && (return_key != 0x060DB2C8u && return_key != 0x060DC1E0u)) && (return_key != 0x060E11B8u && (return_key != 0x060E19C8u && return_key != 0x060E1AB0u))) && ((return_key != 0x060E1F10u && (return_key != 0x060E1FB0u && return_key != 0x060E2920u)) && ((return_key != 0x060E3DC0u && return_key != 0x060EABD0u) && (return_key != 0x060ECFB0u && return_key != 0x060ED050u)))) && (((return_key != 0x060ED4E0u && (return_key != 0x060ED580u && return_key != 0x060EEE90u)) && ((return_key != 0x060EEF48u && return_key != 0x060EF020u) && (return_key != 0x060EF108u && return_key != 0x060EF940u))) && ((return_key != 0x060EFB30u && (return_key != 0x060F0370u && return_key != 0x060F0AF0u)) && ((return_key != 0x060F0CC0u && return_key != 0x060F1EF8u) && (return_key != 0x060F1FB0u && return_key != 0x060F2050u)))))) && (((((return_key != 0x060F2238u && (return_key != 0x060F22D8u && return_key != 0x060F2378u)) && (return_key != 0x060F2618u && (return_key != 0x060F2A20u && return_key != 0x060F2B88u))) && ((return_key != 0x060F2EA0u && (return_key != 0x060F3108u && return_key != 0x060F31B8u)) && ((return_key != 0x060F3258u && return_key != 0x060F32F8u) && (return_key != 0x06101C78u && return_key != 0x06101D60u)))) && (((return_key != 0x06101EA0u && (return_key != 0x06101F88u && return_key != 0x06102DC8u)) && (return_key != 0x06102EA8u && (return_key != 0x06102FA8u && return_key != 0x06103070u))) && ((return_key != 0x06103D60u && (return_key != 0x061048F0u && return_key != 0x06104A28u)) && ((return_key != 0x061052B0u && return_key != 0x061053E8u) && (return_key != 0x06105890u && return_key != 0x06105A48u))))) && ((((return_key != 0x06105E00u && (return_key != 0x06106048u && return_key != 0x061079D8u)) && (return_key != 0x06108D50u && (return_key != 0x06109158u && return_key != 0x0610A808u))) && ((return_key != 0x0610AB90u && (return_key != 0x0610AD70u && return_key != 0x0610AF18u)) && ((return_key != 0x0610B040u && return_key != 0x0610B8E0u) && (return_key != 0x0610BF00u && return_key != 0x0610C048u)))) && (((return_key != 0x0610C1A0u && (return_key != 0x0610C348u && return_key != 0x0610C4F0u)) && ((return_key != 0x0610C680u && return_key != 0x0610C7C0u) && (return_key != 0x0610CE20u && return_key != 0x0610CF48u))) && ((return_key != 0x0610D050u && (return_key != 0x0610D0D8u && return_key != 0x0610D1E0u)) && ((return_key != 0x0610D238u && return_key != 0x0610D360u) && (return_key != 0x0610D870u && return_key != 0x0610DA60u)))))))) && (((((((return_key != 0x0610DE40u && (return_key != 0x0610EAD8u && return_key != 0x0610EC80u)) && (return_key != 0x0610ED38u && (return_key != 0x061113C8u && return_key != 0x06113298u))) && ((return_key != 0x06113438u && (return_key != 0x061136F0u && return_key != 0x06113A00u)) && ((return_key != 0x0611ACD8u && return_key != 0x0611D4F0u) && (return_key != 0x0611DAF8u && return_key != 0x0611DF80u)))) && (((return_key != 0x0611E158u && (return_key != 0x061239E0u && return_key != 0x06124560u)) && (return_key != 0x06124700u && (return_key != 0x061250B0u && return_key != 0x06125528u))) && ((return_key != 0x06125640u && (return_key != 0x06125E70u && return_key != 0x06126860u)) && ((return_key != 0x061274B0u && return_key != 0x06127678u) && (return_key != 0x06127918u && return_key != 0x06127A10u))))) && ((((return_key != 0x06127AB8u && (return_key != 0x061280E8u && return_key != 0x061281E0u)) && (return_key != 0x06128310u && (return_key != 0x06128408u && return_key != 0x06128518u))) && ((return_key != 0x06128610u && (return_key != 0x061287A8u && return_key != 0x06128818u)) && ((return_key != 0x06130268u && return_key != 0x06137438u) && (return_key != 0x06137860u && return_key != 0x061379B0u)))) && (((return_key != 0x06137BE8u && (return_key != 0x06137C70u && return_key != 0x061383A8u)) && ((return_key != 0x0614B708u && return_key != 0x0614F400u) && (return_key != 0x0614FB90u && return_key != 0x0618D3D8u))) && ((return_key != 0x06190108u && (return_key != 0x06191858u && return_key != 0x061918F8u)) && ((return_key != 0x06192DD0u && return_key != 0x06192E28u) && (return_key != 0x06193068u && return_key != 0x06193160u)))))) && (((((return_key != 0x06193548u && (return_key != 0x061935E8u && return_key != 0x06198518u)) && (return_key != 0x06198570u && (return_key != 0x06198A98u && return_key != 0x06198AF0u))) && ((return_key != 0x0619B690u && (return_key != 0x061A3488u && return_key != 0x061A3790u)) && ((return_key != 0x061AC3E8u && return_key != 0x061AC608u) && (return_key != 0x061BBC40u && return_key != 0x061BCBC0u)))) && (((return_key != 0x061BCD78u && (return_key != 0x061BD598u && return_key != 0x061BE628u)) && (return_key != 0x061C1178u && (return_key != 0x061C12A0u && return_key != 0x061C1398u))) && ((return_key != 0x061C14D0u && (return_key != 0x061C15C8u && return_key != 0x061C2FF8u)) && ((return_key != 0x061C3230u && return_key != 0x061C3358u) && (return_key != 0x061C34A8u && return_key != 0x061C3608u))))) && ((((return_key != 0x061C3730u && (return_key != 0x061C3828u && return_key != 0x061C4608u)) && (return_key != 0x061C4810u && (return_key != 0x061C49E0u && return_key != 0x061C4A50u))) && ((return_key != 0x061C51D0u && (return_key != 0x061C5290u && return_key != 0x061C5350u)) && ((return_key != 0x061C54B0u && return_key != 0x061C6088u) && (return_key != 0x061C6480u && return_key != 0x061C64F0u)))) && (((return_key != 0x061C6A88u && (return_key != 0x061C6CF8u && return_key != 0x061C7E20u)) && ((return_key != 0x061D0910u && return_key != 0x061D0AC0u) && (return_key != 0x061D0B30u && return_key != 0x061D0C30u))) && ((return_key != 0x061D0D50u && (return_key != 0x061D0FD0u && return_key != 0x061D1A20u)) && ((return_key != 0x061D1B18u && return_key != 0x061D26F8u) && (return_key != 0x061D27F0u && return_key != 0x061D29D8u))))))) && ((((((return_key != 0x061D2BA0u && (return_key != 0x061D2CB0u && return_key != 0x061D2DC0u)) && (return_key != 0x061D2F88u && (return_key != 0x061D3098u && return_key != 0x061DB3F8u))) && ((return_key != 0x061DC8D0u && (return_key != 0x061DCCC0u && return_key != 0x062041C8u)) && ((return_key != 0x0620D220u && return_key != 0x06212748u) && (return_key != 0x06212840u && return_key != 0x06212A28u)))) && (((return_key != 0x06212C70u && (return_key != 0x06212D80u && return_key != 0x06212E90u)) && (return_key != 0x062130C8u && (return_key != 0x062131D8u && return_key != 0x06213E40u))) && ((return_key != 0x062140E0u && (return_key != 0x062142D8u && return_key != 0x062143A0u)) && ((return_key != 0x06214460u && return_key != 0x06214788u) && (return_key != 0x06214858u && return_key != 0x06214C40u))))) && ((((return_key != 0x06214D10u && (return_key != 0x06215038u && return_key != 0x062150F0u)) && (return_key != 0x062155A8u && (return_key != 0x062156A0u && return_key != 0x06215838u))) && ((return_key != 0x062158F0u && (return_key != 0x06215968u && return_key != 0x06215C48u)) && ((return_key != 0x06216680u && return_key != 0x06216738u) && (return_key != 0x062172B0u && return_key != 0x0621AC48u)))) && (((return_key != 0x0621B9B0u && (return_key != 0x0621BD98u && return_key != 0x0621C6B0u)) && ((return_key != 0x0621C7F0u && return_key != 0x0621D088u) && (return_key != 0x0621D378u && return_key != 0x0621D618u))) && ((return_key != 0x0621D810u && (return_key != 0x0621D8D8u && return_key != 0x0621D998u)) && ((return_key != 0x0621F4F8u && return_key != 0x0621FBA0u) && (return_key != 0x0621FE60u && return_key != 0x06220268u)))))) && (((((return_key != 0x06220858u && (return_key != 0x06220E38u && return_key != 0x06221248u)) && (return_key != 0x06221370u && (return_key != 0x06221D90u && return_key != 0x06222050u))) && ((return_key != 0x06222170u && (return_key != 0x06222238u && return_key != 0x062223D0u)) && ((return_key != 0x062224A0u && return_key != 0x062227A0u) && (return_key != 0x06222870u && return_key != 0x06222B98u)))) && (((return_key != 0x06222C50u && (return_key != 0x06223280u && return_key != 0x06223458u)) && ((return_key != 0x06223510u && return_key != 0x062235E8u) && (return_key != 0x06223AE0u && return_key != 0x06223B98u))) && ((return_key != 0x06223E78u && (return_key != 0x062240F8u && return_key != 0x06225D38u)) && ((return_key != 0x06225EE8u && return_key != 0x06226100u) && (return_key != 0x062271E0u && return_key != 0x06227920u))))) && ((((return_key != 0x06228BE0u && (return_key != 0x06228CD8u && return_key != 0x06228EA8u)) && (return_key != 0x06229060u && (return_key != 0x06229168u && return_key != 0x06229320u))) && ((return_key != 0x0622B370u && (return_key != 0x0622BCD0u && return_key != 0x0622F908u)) && ((return_key != 0x062307B0u && return_key != 0x062309E8u) && (return_key != 0x06230B98u && return_key != 0x06230C08u)))) && (((return_key != 0x06230D08u && (return_key != 0x06230E28u && return_key != 0x06230FF0u)) && ((return_key != 0x06231CB0u && return_key != 0x06231DA8u) && (return_key != 0x06231F78u && return_key != 0x06232130u))) && ((return_key != 0x06232238u && (return_key != 0x062323F0u && return_key != 0x06232DB0u)) && ((return_key != 0x06232EA8u && return_key != 0x06233078u) && (return_key != 0x06233188u && return_key != 0x06233290u))))))))) && ((((((((return_key != 0x062333A0u && (return_key != 0x062334D8u && return_key != 0x06235928u)) && (return_key != 0x06235A20u && (return_key != 0x06235BF0u && return_key != 0x06235D00u))) && ((return_key != 0x06235E08u && (return_key != 0x06235F18u && return_key != 0x06236050u)) && ((return_key != 0x06237308u && return_key != 0x06237400u) && (return_key != 0x062375D0u && return_key != 0x062376E0u)))) && (((return_key != 0x062377E8u && (return_key != 0x062378F8u && return_key != 0x0623BE58u)) && (return_key != 0x0623D490u && (return_key != 0x0623E128u && return_key != 0x0623E1A8u))) && ((return_key != 0x0623E6E8u && (return_key != 0x06241568u && return_key != 0x062415C8u)) && ((return_key != 0x062417C8u && return_key != 0x06241828u) && (return_key != 0x062419E8u && return_key != 0x06243BC0u))))) && ((((return_key != 0x06243D40u && (return_key != 0x06243EB0u && return_key != 0x06244070u)) && (return_key != 0x062441E0u && (return_key != 0x062444A0u && return_key != 0x06244610u))) && ((return_key != 0x06244A10u && (return_key != 0x06244AB0u && return_key != 0x06244B90u)) && ((return_key != 0x06244C30u && return_key != 0x06244D70u) && (return_key != 0x06244E50u && return_key != 0x06244EF0u)))) && (((return_key != 0x06244F90u && (return_key != 0x06245030u && return_key != 0x062450D0u)) && ((return_key != 0x06245240u && return_key != 0x062453C0u) && (return_key != 0x062454C0u && return_key != 0x06245630u))) && ((return_key != 0x06245710u && (return_key != 0x062457B0u && return_key != 0x06245CD0u)) && ((return_key != 0x06245EB0u && return_key != 0x062460D0u) && (return_key != 0x06246570u && return_key != 0x06246720u)))))) && (((((return_key != 0x06246FE0u && (return_key != 0x062472E0u && return_key != 0x06247480u)) && (return_key != 0x06247630u && (return_key != 0x062478C0u && return_key != 0x06247EA8u))) && ((return_key != 0x062486E8u && (return_key != 0x06248938u && return_key != 0x062489B8u)) && ((return_key != 0x06248C28u && return_key != 0x06248CA8u) && (return_key != 0x0624A638u && return_key != 0x0624A7E8u)))) && (((return_key != 0x0624AE28u && (return_key != 0x0624B008u && return_key != 0x0624B720u)) && (return_key != 0x0624BC40u && (return_key != 0x0624BCE0u && return_key != 0x0624C020u))) && ((return_key != 0x0624C1C0u && (return_key != 0x0624C2A0u && return_key != 0x0624C340u)) && ((return_key != 0x0624C3E0u && return_key != 0x0624DC00u) && (return_key != 0x0624DD40u && return_key != 0x0624E3B0u))))) && ((((return_key != 0x0624E508u && (return_key != 0x0624E588u && return_key != 0x0624F0E8u)) && (return_key != 0x0624F790u && (return_key != 0x0624FE30u && return_key != 0x06250368u))) && ((return_key != 0x062504D8u && (return_key != 0x06250670u && return_key != 0x06250A00u)) && ((return_key != 0x06250B80u && return_key != 0x06250C60u) && (return_key != 0x06252818u && return_key != 0x062528F8u)))) && (((return_key != 0x06252DD8u && (return_key != 0x06252F58u && return_key != 0x062530D8u)) && ((return_key != 0x06253258u && return_key != 0x062533D8u) && (return_key != 0x06253558u && return_key != 0x06253658u))) && ((return_key != 0x06253858u && (return_key != 0x06253F38u && return_key != 0x062540B8u)) && ((return_key != 0x06254238u && return_key != 0x062547B8u) && (return_key != 0x06254978u && return_key != 0x06254B18u))))))) && ((((((return_key != 0x06254BF8u && (return_key != 0x06254C98u && return_key != 0x06255620u)) && (return_key != 0x062556C0u && (return_key != 0x06255840u && return_key != 0x062559B0u))) && ((return_key != 0x06255A50u && (return_key != 0x06255E90u && return_key != 0x06256040u)) && ((return_key != 0x062563E0u && return_key != 0x062565C0u) && (return_key != 0x06256740u && return_key != 0x06256B80u)))) && (((return_key != 0x06256C20u && (return_key != 0x06256CC0u && return_key != 0x06256DF0u)) && (return_key != 0x06256FF0u && (return_key != 0x06257160u && return_key != 0x062572E0u))) && ((return_key != 0x06257450u && (return_key != 0x06257608u && return_key != 0x06257830u)) && ((return_key != 0x06257A10u && return_key != 0x06257AB8u) && (return_key != 0x06257B88u && return_key != 0x06257CE8u))))) && ((((return_key != 0x06257DF0u && (return_key != 0x06257E48u && return_key != 0x06257EC0u)) && (return_key != 0x06257F58u && (return_key != 0x06258058u && return_key != 0x06258150u))) && ((return_key != 0x06258248u && (return_key != 0x062582F8u && return_key != 0x06258398u)) && ((return_key != 0x06258438u && return_key != 0x062584D8u) && (return_key != 0x06258578u && return_key != 0x062588E0u)))) && (((return_key != 0x06258988u && (return_key != 0x06258B38u && return_key != 0x06258EA8u)) && ((return_key != 0x06258F80u && return_key != 0x06259018u) && (return_key != 0x062590F8u && return_key != 0x062591C0u))) && ((return_key != 0x06259368u && (return_key != 0x06259438u && return_key != 0x062596C0u)) && ((return_key != 0x06259EE0u && return_key != 0x06259F20u) && (return_key != 0x06259FD8u && return_key != 0x0625A0E8u)))))) && (((((return_key != 0x0625A178u && (return_key != 0x0625A220u && return_key != 0x0625A340u)) && (return_key != 0x0625A3D8u && (return_key != 0x0625A470u && return_key != 0x0625A510u))) && ((return_key != 0x0625A5B0u && (return_key != 0x0625A608u && return_key != 0x0625A648u)) && ((return_key != 0x0625A6C0u && return_key != 0x0625A968u) && (return_key != 0x0625AA10u && return_key != 0x0625AAC8u)))) && (((return_key != 0x0625AB88u && (return_key != 0x0625AC30u && return_key != 0x0625AD00u)) && (return_key != 0x0625B270u && (return_key != 0x0625B2F0u && return_key != 0x0625B3F0u))) && ((return_key != 0x0625B438u && (return_key != 0x0625B490u && return_key != 0x0625B538u)) && ((return_key != 0x0625B578u && return_key != 0x0625B600u) && (return_key != 0x0625B6A0u && return_key != 0x0625B740u))))) && ((((return_key != 0x0625B798u && (return_key != 0x0625B820u && return_key != 0x0625D1D8u)) && (return_key != 0x0625D6D0u && (return_key != 0x0625D750u && return_key != 0x0625DBE8u))) && ((return_key != 0x0625DEF8u && (return_key != 0x0625E160u && return_key != 0x0625E240u)) && ((return_key != 0x0625E498u && return_key != 0x0625E578u) && (return_key != 0x0625E658u && return_key != 0x0625EBA8u)))) && (((return_key != 0x0625EC88u && (return_key != 0x0625ED68u && return_key != 0x0625EF48u)) && ((return_key != 0x0625F3C0u && return_key != 0x0625F4A0u) && (return_key != 0x0625FB38u && return_key != 0x0625FC88u))) && ((return_key != 0x06295800u && (return_key != 0x062959A0u && return_key != 0x06295B40u)) && ((return_key != 0x06295C10u && return_key != 0x06295D48u) && (return_key != 0x06296648u && return_key != 0x0629AFF0u)))))))) && (((((((return_key != 0x0629B0E8u && (return_key != 0x0629BE20u && return_key != 0x0629C168u)) && (return_key != 0x0629C980u && (return_key != 0x0629EB20u && return_key != 0x0629F360u))) && ((return_key != 0x0629F3D0u && (return_key != 0x0629F450u && return_key != 0x0629F4D0u)) && ((return_key != 0x0629F538u && return_key != 0x0629F5C8u) && (return_key != 0x0629F668u && return_key != 0x0629F708u)))) && (((return_key != 0x0629F7A8u && (return_key != 0x0629F848u && return_key != 0x0629F8E8u)) && (return_key != 0x0629FA78u && (return_key != 0x0629FB48u && return_key != 0x0629FCE8u))) && ((return_key != 0x0629FDB8u && (return_key != 0x0629FF58u && return_key != 0x062A0028u)) && ((return_key != 0x062A00F0u && return_key != 0x062A01F8u) && (return_key != 0x062A03B8u && return_key != 0x062A04F8u))))) && ((((return_key != 0x062A05B8u && (return_key != 0x062A0678u && return_key != 0x062A0798u)) && (return_key != 0x062A0800u && (return_key != 0x062A0888u && return_key != 0x062A0928u))) && ((return_key != 0x062A17B0u && (return_key != 0x062A27A0u && return_key != 0x062A2D88u)) && ((return_key != 0x062A3420u && return_key != 0x062A3AE0u) && (return_key != 0x062A3BD8u && return_key != 0x062A3CA8u)))) && (((return_key != 0x062A3D48u && (return_key != 0x062A3E08u && return_key != 0x062A3F18u)) && ((return_key != 0x062A3FE0u && return_key != 0x062A4048u) && (return_key != 0x062A4118u && return_key != 0x062A4468u))) && ((return_key != 0x062A46C0u && (return_key != 0x062A4788u && return_key != 0x062A4828u)) && ((return_key != 0x062A48E8u && return_key != 0x062A4958u) && (return_key != 0x062A4A50u && return_key != 0x062A4AE8u)))))) && (((((return_key != 0x062A4BC8u && (return_key != 0x062A4C60u && return_key != 0x062A4CE0u)) && (return_key != 0x062A4D60u && (return_key != 0x062A4DC8u && return_key != 0x062A4E58u))) && ((return_key != 0x062A4EF8u && (return_key != 0x062A4F50u && return_key != 0x062A4FD8u)) && ((return_key != 0x062A5078u && return_key != 0x062A5118u) && (return_key != 0x062A5260u && return_key != 0x062A5388u)))) && (((return_key != 0x062A55E0u && (return_key != 0x062A5630u && return_key != 0x062A5728u)) && (return_key != 0x062A69C0u && (return_key != 0x062A7288u && return_key != 0x062A7358u))) && ((return_key != 0x062A7590u && (return_key != 0x062A7688u && return_key != 0x062A8B08u)) && ((return_key != 0x062A8C38u && return_key != 0x062A8D78u) && (return_key != 0x062A90C0u && return_key != 0x062A9260u))))) && ((((return_key != 0x062A9308u && (return_key != 0x062A9508u && return_key != 0x062A95C8u)) && (return_key != 0x062A96E8u && (return_key != 0x062A9818u && return_key != 0x062A9958u))) && ((return_key != 0x062A9CA0u && (return_key != 0x062A9E40u && return_key != 0x062A9FE0u)) && ((return_key != 0x062AA0B0u && return_key != 0x062AA338u) && (return_key != 0x062AA3F8u && return_key != 0x062B58F0u)))) && (((return_key != 0x062B5C98u && (return_key != 0x062C8A20u && return_key != 0x062CC300u)) && ((return_key != 0x062CC488u && return_key != 0x062CC6C8u) && (return_key != 0x062D15D0u && return_key != 0x062D49B0u))) && ((return_key != 0x062DF888u && (return_key != 0x06307420u && return_key != 0x063074D8u)) && ((return_key != 0x063088F0u && return_key != 0x063089A8u) && (return_key != 0x06308C78u && return_key != 0x06308D30u))))))) && ((((((return_key != 0x063095F8u && (return_key != 0x06309878u && return_key != 0x06309930u)) && (return_key != 0x0630A578u && (return_key != 0x0630BFB8u && return_key != 0x0630C8F0u))) && ((return_key != 0x0630CBB8u && (return_key != 0x0630CD48u && return_key != 0x0630CEC8u)) && ((return_key != 0x0630D928u && return_key != 0x0630DAB0u) && (return_key != 0x0630DB68u && return_key != 0x0630DC00u)))) && (((return_key != 0x0630DD38u && (return_key != 0x0630DE78u && return_key != 0x0630E0A8u)) && (return_key != 0x0630E168u && (return_key != 0x0630E2A8u && return_key != 0x0630E368u))) && ((return_key != 0x0630E428u && (return_key != 0x0630E568u && return_key != 0x0630E6A8u)) && ((return_key != 0x0630E7E8u && return_key != 0x0630F158u) && (return_key != 0x0630F2A8u && return_key != 0x0630F348u))))) && ((((return_key != 0x0630F3E8u && (return_key != 0x0630F488u && return_key != 0x0630F4E0u)) && (return_key != 0x0630FA40u && (return_key != 0x0630FB10u && return_key != 0x0630FC20u))) && ((return_key != 0x0630FD60u && (return_key != 0x0630FE30u && return_key != 0x0630FF40u)) && ((return_key != 0x06310070u && return_key != 0x06310140u) && (return_key != 0x06310250u && return_key != 0x06310380u)))) && (((return_key != 0x063107E0u && (return_key != 0x063108B0u && return_key != 0x063109E0u)) && ((return_key != 0x06310AB0u && return_key != 0x06312348u) && (return_key != 0x06312430u && return_key != 0x06312630u))) && ((return_key != 0x063126F0u && (return_key != 0x06312C88u && return_key != 0x06312D80u)) && ((return_key != 0x06313018u && return_key != 0x06313330u) && (return_key != 0x063133B0u && return_key != 0x06313520u)))))) && (((((return_key != 0x06313698u && (return_key != 0x06313DF0u && return_key != 0x06316E68u)) && (return_key != 0x06317238u && (return_key != 0x06317448u && return_key != 0x06317FE8u))) && ((return_key != 0x06318388u && (return_key != 0x063184B0u && return_key != 0x06318780u)) && ((return_key != 0x06318860u && return_key != 0x063189B8u) && (return_key != 0x06318F30u && return_key != 0x06318FC8u)))) && (((return_key != 0x0631A078u && (return_key != 0x0631C868u && return_key != 0x0631C998u)) && ((return_key != 0x0631CAE8u && return_key != 0x0631CC98u) && (return_key != 0x0631CD18u && return_key != 0x0631CE80u))) && ((return_key != 0x0631D030u && (return_key != 0x0631D178u && return_key != 0x0631D328u)) && ((return_key != 0x0631DDE0u && return_key != 0x0631DFE0u) && (return_key != 0x0631E140u && return_key != 0x0631E340u))))) && ((((return_key != 0x0631E3C0u && (return_key != 0x0631E638u && return_key != 0x0631E7D0u)) && (return_key != 0x0631EA98u && (return_key != 0x0631EC30u && return_key != 0x0631ECB0u))) && ((return_key != 0x0631EF38u && (return_key != 0x0631F0F0u && return_key != 0x0631F3E8u)) && ((return_key != 0x0631F5A0u && return_key != 0x0631F9A0u) && (return_key != 0x0631FA20u && return_key != 0x06320E68u)))) && (((return_key != 0x06320FE8u && (return_key != 0x06321130u && return_key != 0x063212B0u)) && ((return_key != 0x06321428u && return_key != 0x063214E8u) && (return_key != 0x06321858u && return_key != 0x06321BC8u))) && ((return_key != 0x06321D40u && (return_key != 0x06321DB8u && return_key != 0x06322450u)) && ((return_key != 0x06322920u && return_key != 0x06322A98u) && (return_key != 0x06322B10u && return_key != 0x06323370u)))))))))) && (((((((((return_key != 0x063236E0u && (return_key != 0x063239D0u && return_key != 0x06323EA0u)) && (return_key != 0x06323FD0u && (return_key != 0x06324050u && return_key != 0x063241B0u))) && ((return_key != 0x06324228u && (return_key != 0x06324470u && return_key != 0x06324898u)) && ((return_key != 0x06324918u && return_key != 0x063249D0u) && (return_key != 0x06324B00u && return_key != 0x063253A8u)))) && (((return_key != 0x06325428u && (return_key != 0x06325508u && return_key != 0x063257B0u)) && (return_key != 0x06325928u && (return_key != 0x06325A70u && return_key != 0x06325BE8u))) && ((return_key != 0x06325D60u && (return_key != 0x06325E20u && return_key != 0x06325F20u)) && ((return_key != 0x06325FC0u && return_key != 0x06326038u) && (return_key != 0x063260B8u && return_key != 0x06326198u))))) && ((((return_key != 0x06326B40u && (return_key != 0x06326CF8u && return_key != 0x06326DA8u)) && (return_key != 0x06326E48u && (return_key != 0x06326EE8u && return_key != 0x06326F88u))) && ((return_key != 0x06326FE0u && (return_key != 0x06327098u && return_key != 0x06327178u)) && ((return_key != 0x06327258u && return_key != 0x06327338u) && (return_key != 0x06327418u && return_key != 0x063274F8u)))) && (((return_key != 0x06327B00u && (return_key != 0x06327BA0u && return_key != 0x06327C40u)) && ((return_key != 0x06328040u && return_key != 0x06328098u) && (return_key != 0x06329DA0u && return_key != 0x06329E88u))) && ((return_key != 0x06329EF0u && (return_key != 0x06329F78u && return_key != 0x0632A018u)) && ((return_key != 0x0632A0B8u && return_key != 0x0632A130u) && (return_key != 0x0632A2E8u && return_key != 0x0632A3A0u)))))) && (((((return_key != 0x0632A500u && (return_key != 0x0632AB10u && return_key != 0x0632AD78u)) && (return_key != 0x0632CC00u && (return_key != 0x0632D460u && return_key != 0x0632D9E0u))) && ((return_key != 0x0632DBC0u && (return_key != 0x0632DD78u && return_key != 0x0632DE38u)) && ((return_key != 0x0632E008u && return_key != 0x0632E1B0u) && (return_key != 0x0632E368u && return_key != 0x0632E428u)))) && (((return_key != 0x0632E5F8u && (return_key != 0x0632E7A0u && return_key != 0x0632E958u)) && (return_key != 0x0632EA18u && (return_key != 0x0632EAD8u && return_key != 0x0632EDA8u))) && ((return_key != 0x0632EE68u && (return_key != 0x0632EF28u && return_key != 0x0632EFF0u)) && ((return_key != 0x0632F070u && return_key != 0x0632F210u) && (return_key != 0x0632F2D0u && return_key != 0x0632F398u))))) && ((((return_key != 0x0632F418u && (return_key != 0x0632F5B8u && return_key != 0x0632F678u)) && (return_key != 0x0632F740u && (return_key != 0x0632FAD8u && return_key != 0x0632FC80u))) && ((return_key != 0x0632FE30u && (return_key != 0x0632FFE0u && return_key != 0x06330318u)) && ((return_key != 0x063304D0u && return_key != 0x06330818u) && (return_key != 0x06330D38u && return_key != 0x06331B48u)))) && (((return_key != 0x06331D58u && (return_key != 0x06332518u && return_key != 0x063375C8u)) && ((return_key != 0x06337698u && return_key != 0x063377F8u) && (return_key != 0x06337C30u && return_key != 0x06338240u))) && ((return_key != 0x06338540u && (return_key != 0x06339038u && return_key != 0x063391D8u)) && ((return_key != 0x06339E00u && return_key != 0x06339ED0u) && (return_key != 0x0633A768u && return_key != 0x0633A8E8u))))))) && ((((((return_key != 0x0633AA28u && (return_key != 0x0633AB68u && return_key != 0x0633ACA8u)) && (return_key != 0x0633AD68u && (return_key != 0x0633ADF0u && return_key != 0x0633B408u))) && ((return_key != 0x0633B5E0u && (return_key != 0x0633B748u && return_key != 0x063492C8u)) && ((return_key != 0x0634B610u && return_key != 0x0634B690u) && (return_key != 0x0634C7D0u && return_key != 0x0634C850u)))) && (((return_key != 0x0634C928u && (return_key != 0x06356858u && return_key != 0x06356AD8u)) && (return_key != 0x06356D08u && (return_key != 0x06356D88u && return_key != 0x06357158u))) && ((return_key != 0x06357388u && (return_key != 0x06357408u && return_key != 0x06357900u)) && ((return_key != 0x06357B30u && return_key != 0x06357BB0u) && (return_key != 0x06358420u && return_key != 0x06358670u))))) && ((((return_key != 0x063586F0u && (return_key != 0x06358AC0u && return_key != 0x06358CF0u)) && (return_key != 0x06358D70u && (return_key != 0x06358E68u && return_key != 0x06359680u))) && ((return_key != 0x063598B0u && (return_key != 0x06359930u && return_key != 0x06359DA8u)) && ((return_key != 0x0635A4D8u && return_key != 0x0635A640u) && (return_key != 0x0635AA78u && return_key != 0x0638C368u)))) && (((return_key != 0x0638C468u && (return_key != 0x0638C578u && return_key != 0x0638C5F0u)) && ((return_key != 0x0638D118u && return_key != 0x0638D248u) && (return_key != 0x0638D910u && return_key != 0x0638DAF8u))) && ((return_key != 0x06391368u && (return_key != 0x063916E8u && return_key != 0x06391820u)) && ((return_key != 0x06391AD0u && return_key != 0x06391C30u) && (return_key != 0x06391E10u && return_key != 0x06392240u)))))) && (((((return_key != 0x063924A8u && (return_key != 0x06396D50u && return_key != 0x06397080u)) && (return_key != 0x06397680u && (return_key != 0x06397868u && return_key != 0x06397908u))) && ((return_key != 0x06398850u && (return_key != 0x06398A68u && return_key != 0x06398C90u)) && ((return_key != 0x0639A190u && return_key != 0x0639A468u) && (return_key != 0x0639B5F8u && return_key != 0x0639B980u)))) && (((return_key != 0x0639BD38u && (return_key != 0x0639C178u && return_key != 0x0639C238u)) && (return_key != 0x0639C670u && (return_key != 0x0639C838u && return_key != 0x0639DC70u))) && ((return_key != 0x0639DF78u && (return_key != 0x0639EDB0u && return_key != 0x0639EF80u)) && ((return_key != 0x063A12E8u && return_key != 0x063A22D0u) && (return_key != 0x063A2410u && return_key != 0x063A2798u))))) && ((((return_key != 0x063A2978u && (return_key != 0x063A2BE8u && return_key != 0x063A2C88u)) && (return_key != 0x063A3168u && (return_key != 0x063A8A50u && return_key != 0x063AD5F8u))) && ((return_key != 0x063D63C0u && (return_key != 0x063D6418u && return_key != 0x063D6768u)) && ((return_key != 0x06415AA0u && return_key != 0x06415FA8u) && (return_key != 0x06416198u && return_key != 0x06416350u)))) && (((return_key != 0x06416858u && (return_key != 0x0649A4E0u && return_key != 0x0649A678u)) && ((return_key != 0x0649A6F0u && return_key != 0x0649A740u) && (return_key != 0x0649FC00u && return_key != 0x0649FCD0u))) && ((return_key != 0x0649FDB0u && (return_key != 0x0649FEB8u && return_key != 0x064A70B8u)) && ((return_key != 0x064A71B0u && return_key != 0x064A72A8u) && (return_key != 0x064A7400u && return_key != 0x064A7568u)))))))) && (((((((return_key != 0x064A7600u && (return_key != 0x064A76E0u && return_key != 0x064A8190u)) && (return_key != 0x064A8318u && (return_key != 0x064A8398u && return_key != 0x064A9B08u))) && ((return_key != 0x064A9C08u && (return_key != 0x064A9DC0u && return_key != 0x064A9EC0u)) && ((return_key != 0x064AA858u && return_key != 0x064AAB28u) && (return_key != 0x064AABD8u && return_key != 0x064AACB0u)))) && (((return_key != 0x064AB1B0u && (return_key != 0x064AB240u && return_key != 0x064AB2E8u)) && (return_key != 0x064AB3E8u && (return_key != 0x064AB6E8u && return_key != 0x064AB7E8u))) && ((return_key != 0x064AB9A0u && (return_key != 0x064ABAA0u && return_key != 0x064AC800u)) && ((return_key != 0x064AC880u && return_key != 0x064AC900u) && (return_key != 0x064ACA08u && return_key != 0x064ACC68u))))) && ((((return_key != 0x064ACE10u && (return_key != 0x064ACFB0u && return_key != 0x064AD1A0u)) && (return_key != 0x064AD390u && (return_key != 0x064AD4D0u && return_key != 0x064AEF48u))) && ((return_key != 0x064B8180u && (return_key != 0x064CA158u && return_key != 0x064CA460u)) && ((return_key != 0x064CE9B0u && return_key != 0x064CECD8u) && (return_key != 0x064EEE18u && return_key != 0x0652B438u)))) && (((return_key != 0x065302D0u && (return_key != 0x06530328u && return_key != 0x06533DC8u)) && ((return_key != 0x065384C8u && return_key != 0x0653E0C0u) && (return_key != 0x06545B30u && return_key != 0x06548BD0u))) && ((return_key != 0x06549CD0u && (return_key != 0x0654C0C8u && return_key != 0x0654CDB8u)) && ((return_key != 0x0654DDB8u && return_key != 0x0654E810u) && (return_key != 0x0654E8C8u && return_key != 0x0654E960u)))))) && (((((return_key != 0x0654E9F8u && (return_key != 0x0654EA98u && return_key != 0x0654EB38u)) && (return_key != 0x0654EC38u && (return_key != 0x0654ED30u && return_key != 0x0654EE28u))) && ((return_key != 0x0654EEA8u && (return_key != 0x0654EF38u && return_key != 0x0654EFD8u)) && ((return_key != 0x0654F078u && return_key != 0x0654F0D0u) && (return_key != 0x0654F110u && return_key != 0x0654F7D0u)))) && (((return_key != 0x0654F858u && (return_key != 0x0654F8F8u && return_key != 0x0654FB10u)) && (return_key != 0x06580238u && (return_key != 0x06580300u && return_key != 0x06580388u))) && ((return_key != 0x06580428u && (return_key != 0x06581608u && return_key != 0x06581818u)) && ((return_key != 0x06581B68u && return_key != 0x06582BF0u) && (return_key != 0x06582DF0u && return_key != 0x06582E78u))))) && ((((return_key != 0x06600250u && (return_key != 0x066002B0u && return_key != 0x06600470u)) && (return_key != 0x066004D0u && (return_key != 0x06600640u && return_key != 0x066053F0u))) && ((return_key != 0x0661C318u && (return_key != 0x0661C3B8u && return_key != 0x0661E780u)) && ((return_key != 0x0661FC60u && return_key != 0x0661FCD8u) && (return_key != 0x06621260u && return_key != 0x06623E38u)))) && (((return_key != 0x06627308u && (return_key != 0x06627380u && return_key != 0x06627510u)) && ((return_key != 0x06627588u && return_key != 0x066276D8u) && (return_key != 0x06629A80u && return_key != 0x06629EC0u))) && ((return_key != 0x0662A260u && (return_key != 0x0662B8F8u && return_key != 0x0662BBD8u)) && ((return_key != 0x0662C408u && return_key != 0x066318A0u) && (return_key != 0x06631918u && return_key != 0x06632120u))))))) && ((((((return_key != 0x06632330u && (return_key != 0x06632420u && return_key != 0x066324F8u)) && (return_key != 0x06632728u && (return_key != 0x06632820u && return_key != 0x06632948u))) && ((return_key != 0x06632BA0u && (return_key != 0x06632D00u && return_key != 0x06632D80u)) && ((return_key != 0x06632E58u && return_key != 0x06632FB8u) && (return_key != 0x066330B0u && return_key != 0x066331D8u)))) && (((return_key != 0x06633980u && (return_key != 0x06633D50u && return_key != 0x066384F8u)) && (return_key != 0x06638768u && (return_key != 0x06639420u && return_key != 0x066395D8u))) && ((return_key != 0x06639658u && (return_key != 0x066396D8u && return_key != 0x0663A1D0u)) && ((return_key != 0x0663A290u && return_key != 0x0663A308u) && (return_key != 0x0663AEC8u && return_key != 0x0663B210u))))) && ((((return_key != 0x0663B688u && (return_key != 0x0663B838u && return_key != 0x0663BA18u)) && (return_key != 0x0663C240u && (return_key != 0x0663DA10u && return_key != 0x0663DF58u))) && ((return_key != 0x0663E1A8u && (return_key != 0x0663E518u && return_key != 0x0663E9A8u)) && ((return_key != 0x0663EC28u && return_key != 0x0663F690u) && (return_key != 0x0663FAC8u && return_key != 0x066403E8u)))) && (((return_key != 0x06640700u && (return_key != 0x066413B8u && return_key != 0x06641A78u)) && ((return_key != 0x06641F10u && return_key != 0x06642218u) && (return_key != 0x066425E0u && return_key != 0x066434C0u))) && ((return_key != 0x06644260u && (return_key != 0x066444D8u && return_key != 0x06644558u)) && ((return_key != 0x06644BA8u && return_key != 0x06645E70u) && (return_key != 0x06646BA0u && return_key != 0x06648D40u)))))) && (((((return_key != 0x06648DB8u && (return_key != 0x06649320u && return_key != 0x066499F8u)) && (return_key != 0x0664A7A8u && (return_key != 0x0664AD68u && return_key != 0x0664AF48u))) && ((return_key != 0x0664B328u && (return_key != 0x0664B390u && return_key != 0x0664B410u)) && ((return_key != 0x0664B450u && return_key != 0x0664B518u) && (return_key != 0x0664B568u && return_key != 0x0664B848u)))) && (((return_key != 0x0664B9B8u && (return_key != 0x0664BA10u && return_key != 0x0664BAE0u)) && ((return_key != 0x0664BB50u && return_key != 0x0664C220u) && (return_key != 0x0664C808u && return_key != 0x0664C9A8u))) && ((return_key != 0x0664CAF8u && (return_key != 0x0664CFF0u && return_key != 0x0664F190u)) && ((return_key != 0x0664F2F0u && return_key != 0x0664F370u) && (return_key != 0x0664F448u && return_key != 0x0664F5A8u))))) && ((((return_key != 0x0664F6A0u && (return_key != 0x0664F7C8u && return_key != 0x06651570u)) && (return_key != 0x066544C8u && (return_key != 0x066570C0u && return_key != 0x06657910u))) && ((return_key != 0x06657D58u && (return_key != 0x06659900u && return_key != 0x06659968u)) && ((return_key != 0x06659B08u && return_key != 0x06659C38u) && (return_key != 0x0665A3B8u && return_key != 0x0665E968u)))) && (((return_key != 0x0665E9E0u && (return_key != 0x0665EA78u && return_key != 0x0665EBD0u)) && ((return_key != 0x0665EC48u && return_key != 0x0665EDD8u) && (return_key != 0x0665EE50u && return_key != 0x0665EFE0u))) && ((return_key != 0x0665F058u && (return_key != 0x06660C10u && return_key != 0x06660C90u)) && ((return_key != 0x06661F30u && return_key != 0x06661FB0u) && (return_key != 0x06662088u && return_key != 0x066621A0u))))))))) && ((((((((return_key != 0x06662300u && (return_key != 0x06662380u && return_key != 0x06662458u)) && (return_key != 0x066625B8u && (return_key != 0x066626B0u && return_key != 0x066627D8u))) && ((return_key != 0x06662930u && (return_key != 0x066629A0u && return_key != 0x06663418u)) && ((return_key != 0x06663DB8u && return_key != 0x06667588u) && (return_key != 0x06667C38u && return_key != 0x066684D0u)))) && (((return_key != 0x06668DD8u && (return_key != 0x06668E58u && return_key != 0x06668ED8u)) && (return_key != 0x066691A8u && (return_key != 0x066694A0u && return_key != 0x06669520u))) && ((return_key != 0x066695A0u && (return_key != 0x06669870u && return_key != 0x06669958u)) && ((return_key != 0x0666A4F0u && return_key != 0x066802D0u) && (return_key != 0x06680458u && return_key != 0x066805A8u))))) && ((((return_key != 0x06680998u && (return_key != 0x06680B08u && return_key != 0x06681250u)) && (return_key != 0x066813A0u && (return_key != 0x06681790u && return_key != 0x06681900u))) && ((return_key != 0x06681F20u && (return_key != 0x06682000u && return_key != 0x066820E0u)) && ((return_key != 0x066821C0u && return_key != 0x066824B8u) && (return_key != 0x06682578u && return_key != 0x06682638u)))) && (((return_key != 0x066826F8u && (return_key != 0x06683608u && return_key != 0x066837C0u)) && ((return_key != 0x066841E8u && return_key != 0x06684248u) && (return_key != 0x066844E8u && return_key != 0x06684548u))) && ((return_key != 0x06684648u && (return_key != 0x06684710u && return_key != 0x06684810u)) && ((return_key != 0x06686110u && return_key != 0x06686A00u) && (return_key != 0x06686D08u && return_key != 0x06686E78u)))))) && (((((return_key != 0x06686F10u && (return_key != 0x06687750u && return_key != 0x06687860u)) && (return_key != 0x06687A48u && (return_key != 0x06687B00u && return_key != 0x06688180u))) && ((return_key != 0x06688268u && (return_key != 0x066883F0u && return_key != 0x066884F8u)) && ((return_key != 0x066885D8u && return_key != 0x06688668u) && (return_key != 0x06688AC0u && return_key != 0x06688C18u)))) && (((return_key != 0x06689068u && (return_key != 0x06689108u && return_key != 0x06689178u)) && (return_key != 0x06689288u && (return_key != 0x06689328u && return_key != 0x066896E8u))) && ((return_key != 0x06689790u && (return_key != 0x0668C3C0u && return_key != 0x0668CAF0u)) && ((return_key != 0x0668D150u && return_key != 0x0668D558u) && (return_key != 0x0668E220u && return_key != 0x066908B8u))))) && ((((return_key != 0x06690A30u && (return_key != 0x06691CA0u && return_key != 0x06692858u)) && (return_key != 0x06693218u && (return_key != 0x06693DE8u && return_key != 0x06694E70u))) && ((return_key != 0x06699008u && (return_key != 0x06699360u && return_key != 0x0669B808u)) && ((return_key != 0x0669B960u && return_key != 0x0669CB60u) && (return_key != 0x0669CD08u && return_key != 0x0669D828u)))) && (((return_key != 0x0669E030u && (return_key != 0x0669E180u && return_key != 0x0669E2D0u)) && ((return_key != 0x066A03C8u && return_key != 0x066A1018u) && (return_key != 0x066A10B0u && return_key != 0x066A3920u))) && ((return_key != 0x066A3A18u && (return_key != 0x066A3B20u && return_key != 0x066A44B0u)) && ((return_key != 0x066A4558u && return_key != 0x066A46E0u) && (return_key != 0x066A47D8u && return_key != 0x066A48B8u))))))) && ((((((return_key != 0x066A4F80u && (return_key != 0x066A5A58u && return_key != 0x066A7B90u)) && (return_key != 0x066A8F30u && (return_key != 0x066A92D0u && return_key != 0x066A9990u))) && ((return_key != 0x066A9AA0u && (return_key != 0x066AA9A8u && return_key != 0x066AAAC0u)) && ((return_key != 0x066ABF30u && return_key != 0x066AC0A8u) && (return_key != 0x066ACCC0u && return_key != 0x066AD008u)))) && (((return_key != 0x066AD130u && (return_key != 0x066ADB58u && return_key != 0x066ADC48u)) && (return_key != 0x066AE0E0u && (return_key != 0x066AE280u && return_key != 0x066AE990u))) && ((return_key != 0x066AF2C0u && (return_key != 0x066AF460u && return_key != 0x066AF600u)) && ((return_key != 0x066AF7F8u && return_key != 0x066AFE08u) && (return_key != 0x066B07B8u && return_key != 0x066B0C48u))))) && ((((return_key != 0x066B0D40u && (return_key != 0x066B0ED0u && return_key != 0x066B1040u)) && (return_key != 0x066B13C0u && (return_key != 0x066B14B8u && return_key != 0x066B1648u))) && ((return_key != 0x066B17B8u && (return_key != 0x066B18F8u && return_key != 0x066B2160u)) && ((return_key != 0x066B22D8u && return_key != 0x066B2438u) && (return_key != 0x066B2C18u && return_key != 0x066B4558u)))) && (((return_key != 0x066B4BB8u && (return_key != 0x066B4EB0u && return_key != 0x066B50E0u)) && ((return_key != 0x066B5208u && return_key != 0x066B5618u) && (return_key != 0x066B6230u && return_key != 0x066B6298u))) && ((return_key != 0x066B65C0u && (return_key != 0x066B6848u && return_key != 0x066B6910u)) && ((return_key != 0x066B6C08u && return_key != 0x066B6CD8u) && (return_key != 0x066B6FA8u && return_key != 0x066B7038u)))))) && (((((return_key != 0x066B70D8u && (return_key != 0x066B8228u && return_key != 0x066B8468u)) && (return_key != 0x066BA9D0u && (return_key != 0x066BAA30u && return_key != 0x066BAB28u))) && ((return_key != 0x066BABE8u && (return_key != 0x066BAC40u && return_key != 0x066C40E0u)) && ((return_key != 0x066C4470u && return_key != 0x066C4500u) && (return_key != 0x066C45C0u && return_key != 0x066C4658u)))) && (((return_key != 0x066C46B0u && (return_key != 0x066C4740u && return_key != 0x066C47D0u)) && (return_key != 0x066C4820u && (return_key != 0x066C48D8u && return_key != 0x066C49B8u))) && ((return_key != 0x066C4A68u && (return_key != 0x066C4B08u && return_key != 0x066C4BA8u)) && ((return_key != 0x066C4CC0u && return_key != 0x066C4D70u) && (return_key != 0x066C4E10u && return_key != 0x066C4EB0u))))) && ((((return_key != 0x066C4F98u && (return_key != 0x066C5000u && return_key != 0x066C5040u)) && (return_key != 0x066C5080u && (return_key != 0x066C5170u && return_key != 0x066C5208u))) && ((return_key != 0x066C5260u && (return_key != 0x066C52D0u && return_key != 0x066C5320u)) && ((return_key != 0x066C53D8u && return_key != 0x066C54B8u) && (return_key != 0x066C5568u && return_key != 0x066C5608u)))) && (((return_key != 0x066C56A8u && (return_key != 0x066C57C0u && return_key != 0x066C5870u)) && ((return_key != 0x066C5910u && return_key != 0x066C59B0u) && (return_key != 0x066C5A98u && return_key != 0x066C5B00u))) && ((return_key != 0x066C5B40u && (return_key != 0x066C5B80u && return_key != 0x066C5BF8u)) && ((return_key != 0x066C5CA0u && return_key != 0x066C5D00u) && (return_key != 0x066C5DA8u && return_key != 0x066C5E80u)))))))) && (((((((return_key != 0x066C5EE8u && (return_key != 0x066C5F28u && return_key != 0x066C5F68u)) && (return_key != 0x066C6208u && (return_key != 0x066C6768u && return_key != 0x066C82A8u))) && ((return_key != 0x066C83F8u && (return_key != 0x066C84C0u && return_key != 0x066C8650u)) && ((return_key != 0x066CA118u && return_key != 0x066CA200u) && (return_key != 0x066CA240u && return_key != 0x066CA2C8u)))) && (((return_key != 0x066CA400u && (return_key != 0x066CA730u && return_key != 0x066CA7B0u)) && (return_key != 0x066CA7F8u && (return_key != 0x066CA838u && return_key != 0x066CA8C0u))) && ((return_key != 0x066CA960u && (return_key != 0x066CAA00u && return_key != 0x066CAA98u)) && ((return_key != 0x066CACA8u && return_key != 0x066CADA8u) && (return_key != 0x066CAE40u && return_key != 0x066CB170u))))) && ((((return_key != 0x066CB2B0u && (return_key != 0x066CB4F8u && return_key != 0x066CB648u)) && (return_key != 0x066CBBE8u && (return_key != 0x066CBE80u && return_key != 0x066CC080u))) && ((return_key != 0x066CC3F0u && (return_key != 0x066CC5D0u && return_key != 0x066CC8A8u)) && ((return_key != 0x066CCAB0u && return_key != 0x066CCB78u) && (return_key != 0x066CCC30u && return_key != 0x066CCCF0u)))) && (((return_key != 0x066CCE80u && (return_key != 0x066CCF00u && return_key != 0x066CCF80u)) && ((return_key != 0x066CD0B8u && return_key != 0x066CD178u) && (return_key != 0x066CD598u && return_key != 0x066CD730u))) && ((return_key != 0x066CD870u && (return_key != 0x066CE0F8u && return_key != 0x066CE3A8u)) && ((return_key != 0x066CE460u && return_key != 0x066D1878u) && (return_key != 0x066D1B40u && return_key != 0x066D1E30u)))))) && (((((return_key != 0x066D2A30u && (return_key != 0x066D2B58u && return_key != 0x066D2BD8u)) && (return_key != 0x066D2C50u && (return_key != 0x066D51F0u && return_key != 0x066D5580u))) && ((return_key != 0x066D5600u && (return_key != 0x066D5670u && return_key != 0x066D57B0u)) && ((return_key != 0x066D5A28u && return_key != 0x066D5BD8u) && (return_key != 0x066D5EF8u && return_key != 0x066D60A8u)))) && (((return_key != 0x066D6108u && (return_key != 0x066D6918u && return_key != 0x066D6AC8u)) && (return_key != 0x066D6C80u && (return_key != 0x066D6DE8u && return_key != 0x066D6F28u))) && ((return_key != 0x066D7348u && (return_key != 0x066D7608u && return_key != 0x066D7818u)) && ((return_key != 0x066D8398u && return_key != 0x066D85C8u) && (return_key != 0x066D8640u && return_key != 0x066D8760u))))) && ((((return_key != 0x066D87E8u && (return_key != 0x066D8888u && return_key != 0x066D8928u)) && (return_key != 0x066D89C8u && (return_key != 0x066D8A68u && return_key != 0x066D8BF0u))) && ((return_key != 0x066D8E38u && (return_key != 0x066D8F80u && return_key != 0x066D9178u)) && ((return_key != 0x066D9240u && return_key != 0x066D9310u) && (return_key != 0x066D9408u && return_key != 0x066D96E0u)))) && (((return_key != 0x066D97A8u && (return_key != 0x066D9A98u && return_key != 0x066D9B88u)) && ((return_key != 0x066D9C98u && return_key != 0x066D9E08u) && (return_key != 0x066DA368u && return_key != 0x066DA470u))) && ((return_key != 0x066DA5F8u && (return_key != 0x066DA708u && return_key != 0x066DAD68u)) && ((return_key != 0x066DB530u && return_key != 0x066DB750u) && (return_key != 0x066DB848u && return_key != 0x066DB9C8u))))))) && ((((((return_key != 0x066DBAC0u && (return_key != 0x066DBCB8u && return_key != 0x066DBDC8u)) && (return_key != 0x066DBEC0u && (return_key != 0x066DC2B0u && return_key != 0x066DC360u))) && ((return_key != 0x066DC430u && (return_key != 0x066DD3F8u && return_key != 0x066DD770u)) && ((return_key != 0x066DDD28u && return_key != 0x066DDF08u) && (return_key != 0x066DE0A8u && return_key != 0x066DE1D0u)))) && (((return_key != 0x066DE5E8u && (return_key != 0x066E01D0u && return_key != 0x066E11D0u)) && (return_key != 0x066E1CD8u && (return_key != 0x066E1EC8u && return_key != 0x066E3038u))) && ((return_key != 0x066E3238u && (return_key != 0x066E33B8u && return_key != 0x066E3640u)) && ((return_key != 0x066E37E8u && return_key != 0x066E38C8u) && (return_key != 0x066E4098u && return_key != 0x066E4620u))))) && ((((return_key != 0x066E4748u && (return_key != 0x066E47F8u && return_key != 0x066E4EB0u)) && (return_key != 0x066E4FA8u && (return_key != 0x066E5708u && return_key != 0x066E5EC0u))) && ((return_key != 0x066E5F30u && (return_key != 0x06703FD8u && return_key != 0x06704110u)) && ((return_key != 0x06704210u && return_key != 0x06704A58u) && (return_key != 0x06724000u && return_key != 0x06724070u)))) && (((return_key != 0x067240C0u && (return_key != 0x06724120u && return_key != 0x067241F8u)) && ((return_key != 0x06724320u && return_key != 0x067243D0u) && (return_key != 0x06724470u && return_key != 0x06724510u))) && ((return_key != 0x06724598u && (return_key != 0x06724630u && return_key != 0x067246A8u)) && ((return_key != 0x067246E8u && return_key != 0x067247C0u) && (return_key != 0x067248A0u && return_key != 0x06724950u)))))) && (((((return_key != 0x067249F0u && (return_key != 0x06724A90u && return_key != 0x06724AE8u)) && (return_key != 0x06724B58u && (return_key != 0x06724BC0u && return_key != 0x06724F28u))) && ((return_key != 0x06725010u && (return_key != 0x067250F0u && return_key != 0x067251D0u)) && ((return_key != 0x06725280u && return_key != 0x06725320u) && (return_key != 0x067253C0u && return_key != 0x067254C0u)))) && (((return_key != 0x06725528u && (return_key != 0x06725598u && return_key != 0x067259D0u)) && ((return_key != 0x06725AC0u && return_key != 0x06725B40u) && (return_key != 0x06725BA0u && return_key != 0x06725C90u))) && ((return_key != 0x06725D00u && (return_key != 0x06725DF0u && return_key != 0x06725ED0u)) && ((return_key != 0x06725FC0u && return_key != 0x06726040u) && (return_key != 0x06726130u && return_key != 0x067262D0u))))) && ((((return_key != 0x06726388u && (return_key != 0x067263E8u && return_key != 0x067264A0u)) && (return_key != 0x06726508u && (return_key != 0x067265C0u && return_key != 0x06726708u))) && ((return_key != 0x06726878u && (return_key != 0x067268F8u && return_key != 0x06726A50u)) && ((return_key != 0x06726C80u && return_key != 0x067271A8u) && (return_key != 0x06727220u && return_key != 0x06727460u)))) && (((return_key != 0x067274D8u && (return_key != 0x06727700u && return_key != 0x06727778u)) && ((return_key != 0x067278A0u && return_key != 0x06727968u) && (return_key != 0x067279E0u && return_key != 0x06727BE8u))) && ((return_key != 0x06727C60u && (return_key != 0x06727DC0u && return_key != 0x06727EE0u)) && ((return_key != 0x06727F60u && return_key != 0x06728008u) && (return_key != 0x06728110u && return_key != 0x06728190u))))))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0604B22Au: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09645u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t lo = 0u, hi = 0u, bank = 0u;
            if (nh_scpu_pull8(cpu, bus, &lo) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &hi) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)hi << 8) | (uint16_t)lo) + 1u);
            cpu->pbr = bank;
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x06048D12u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        default: return NH_SCPU_NOT_MINE;
    }
}
