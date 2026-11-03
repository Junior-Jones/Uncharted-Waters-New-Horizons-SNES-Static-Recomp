/* Generated direct New Horizons S-CPU authority; do not edit. */
#include "nh_v07_generated.h"

NHScpuExecResult nh_v07_shard_00C1FA(NHScpuState *cpu, const NHScpuBus *bus) {
    switch (nh_scpu_context_key(cpu)) {
        case 0x060FD100u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA20u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA22u;
            if (nh_scpu_expect_next(cpu, 0x060FD112u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD112u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA22u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA24u;
            if (nh_scpu_expect_next(cpu, 0x060FD122u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD122u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x02u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA24u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x004202u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA28u;
            if (nh_scpu_expect_next(cpu, 0x060FD142u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FD142u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA28u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA2Au;
            if (nh_scpu_expect_next(cpu, 0x060FD152u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD152u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x03u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA2Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x004203u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA2Eu;
            if (nh_scpu_expect_next(cpu, 0x060FD172u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FD172u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA2Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA2Fu;
            if (nh_scpu_expect_next(cpu, 0x060FD17Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD17Au: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA2Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA30u;
            if (nh_scpu_expect_next(cpu, 0x060FD182u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD182u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA30u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA31u;
            if (nh_scpu_expect_next(cpu, 0x060FD18Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD18Au: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA31u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA33u;
            if (nh_scpu_expect_next(cpu, 0x060FD198u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD198u: {
            static const uint8_t expected_epoch[] = { 0xAFu, 0x16u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA33u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = 0x004216u;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA37u;
            if (nh_scpu_expect_next(cpu, 0x060FD1B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FD1B8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA37u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000008u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA39u;
            if (nh_scpu_expect_next(cpu, 0x060FD1C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD1C8u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA39u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA3Bu;
            if (nh_scpu_expect_next(cpu, 0x060FD1DAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD1DAu: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x05u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA3Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA3Du;
            if (nh_scpu_expect_next(cpu, 0x060FD1EAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD1EAu: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x03u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA3Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x004203u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA41u;
            if (nh_scpu_expect_next(cpu, 0x060FD20Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FD20Au: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA41u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA42u;
            if (nh_scpu_expect_next(cpu, 0x060FD212u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD212u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA42u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA43u;
            if (nh_scpu_expect_next(cpu, 0x060FD21Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD21Au: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA43u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA44u;
            if (nh_scpu_expect_next(cpu, 0x060FD222u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD222u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA44u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA45u;
            if (nh_scpu_expect_next(cpu, 0x060FD22Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD22Au: {
            static const uint8_t expected_epoch[] = { 0xAFu, 0x16u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA45u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, 0x004216u, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA49u;
            if (nh_scpu_expect_next(cpu, 0x060FD24Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FD24Au: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x09u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA49u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t right = 0u;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), &right) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t left = (uint8_t)cpu->a;
            const uint16_t total = (uint16_t)((uint16_t)left + right + ((cpu->p & NH_P_C) != 0u ? 1u : 0u));
            const uint8_t result = (uint8_t)total;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_C | NH_P_V));
            if (total > 0xFFu) cpu->p |= NH_P_C;
            if (((uint8_t)~(left ^ right) & (left ^ result) & 0x80u) != 0u) cpu->p |= NH_P_V;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA4Bu;
            if (nh_scpu_expect_next(cpu, 0x060FD25Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD25Au: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x09u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA4Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA4Du;
            if (nh_scpu_expect_next(cpu, 0x060FD26Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD26Au: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA4Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA4Fu;
            if (nh_scpu_expect_next(cpu, 0x060FD27Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD27Au: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x02u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA4Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x004202u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA53u;
            if (nh_scpu_expect_next(cpu, 0x060FD29Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FD29Au: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA53u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA55u;
            if (nh_scpu_expect_next(cpu, 0x060FD2AAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD2AAu: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x03u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA55u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x004203u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA59u;
            if (nh_scpu_expect_next(cpu, 0x060FD2CAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FD2CAu: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA59u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA5Au;
            if (nh_scpu_expect_next(cpu, 0x060FD2D2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD2D2u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA5Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA5Bu;
            if (nh_scpu_expect_next(cpu, 0x060FD2DAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD2DAu: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA5Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA5Cu;
            if (nh_scpu_expect_next(cpu, 0x060FD2E2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD2E2u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA5Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA5Du;
            if (nh_scpu_expect_next(cpu, 0x060FD2EAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD2EAu: {
            static const uint8_t expected_epoch[] = { 0xAFu, 0x16u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA5Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, 0x004216u, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA61u;
            if (nh_scpu_expect_next(cpu, 0x060FD30Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FD30Au: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x09u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA61u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t right = 0u;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), &right) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t left = (uint8_t)cpu->a;
            const uint16_t total = (uint16_t)((uint16_t)left + right + ((cpu->p & NH_P_C) != 0u ? 1u : 0u));
            const uint8_t result = (uint8_t)total;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_C | NH_P_V));
            if (total > 0xFFu) cpu->p |= NH_P_C;
            if (((uint8_t)~(left ^ right) & (left ^ result) & 0x80u) != 0u) cpu->p |= NH_P_V;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA63u;
            if (nh_scpu_expect_next(cpu, 0x060FD31Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD31Au: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x09u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA63u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA65u;
            if (nh_scpu_expect_next(cpu, 0x060FD32Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD32Au: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA65u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA67u;
            if (nh_scpu_expect_next(cpu, 0x060FD338u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD338u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA67u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000008u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA69u;
            if (nh_scpu_expect_next(cpu, 0x060FD348u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD348u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA69u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA6Bu;
            if (nh_scpu_expect_next(cpu, 0x060FD358u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD358u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA6Bu,
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
            if ((((((((((return_key != 0x0608B580u && return_key != 0x0608BB80u) && (return_key != 0x0608C090u && return_key != 0x0608C3E0u)) && ((return_key != 0x0608C8F0u && return_key != 0x0608D668u) && (return_key != 0x0608D9B8u && (return_key != 0x0608DFE0u && return_key != 0x0608E240u)))) && (((return_key != 0x060903E0u && return_key != 0x060904D0u) && (return_key != 0x06090578u && (return_key != 0x06093058u && return_key != 0x06093148u))) && ((return_key != 0x060931F0u && return_key != 0x06095FF8u) && (return_key != 0x060964B0u && (return_key != 0x06098928u && return_key != 0x06098BA0u))))) && ((((return_key != 0x06099230u && return_key != 0x060997E0u) && (return_key != 0x06099CB0u && (return_key != 0x06099FB0u && return_key != 0x0609DCC8u))) && ((return_key != 0x0609EF30u && return_key != 0x060A0350u) && (return_key != 0x060A0448u && (return_key != 0x060A0770u && return_key != 0x060A0AB0u)))) && (((return_key != 0x060A0BC8u && return_key != 0x060A0CF0u) && (return_key != 0x060A0DB8u && (return_key != 0x060A0EF8u && return_key != 0x060A1228u))) && ((return_key != 0x060A1420u && return_key != 0x060A1518u) && (return_key != 0x060A15F8u && (return_key != 0x060A1A58u && return_key != 0x060A2058u)))))) && (((((return_key != 0x060A5930u && return_key != 0x060A6BE8u) && (return_key != 0x060A8520u && return_key != 0x060A86F8u)) && ((return_key != 0x060A8BA8u && return_key != 0x060A8D80u) && (return_key != 0x060A96D8u && (return_key != 0x060A98B0u && return_key != 0x060A9CA8u)))) && (((return_key != 0x060A9E80u && return_key != 0x060AA6E0u) && (return_key != 0x060AA8B8u && (return_key != 0x060AACE0u && return_key != 0x060AAEB8u))) && ((return_key != 0x060B73D8u && return_key != 0x060B7420u) && (return_key != 0x060BCAA0u && (return_key != 0x060BF5C0u && return_key != 0x060C9CB8u))))) && ((((return_key != 0x060C9DB8u && return_key != 0x060C9E88u) && (return_key != 0x060CA720u && (return_key != 0x060CAAB0u && return_key != 0x060CB670u))) && ((return_key != 0x060CB7C8u && return_key != 0x060CB9D0u) && (return_key != 0x060E4510u && (return_key != 0x060E9238u && return_key != 0x060E99F0u)))) && (((return_key != 0x060FA988u && return_key != 0x061027D8u) && (return_key != 0x06103A30u && (return_key != 0x06103FE8u && return_key != 0x06105F38u))) && ((return_key != 0x06105FB8u && return_key != 0x0610EFF0u) && (return_key != 0x06113990u && (return_key != 0x06113E18u && return_key != 0x0611A088u))))))) && ((((((return_key != 0x0611A488u && return_key != 0x0611A7E8u) && (return_key != 0x0611A8F0u && return_key != 0x0611ABA0u)) && ((return_key != 0x0611DA88u && return_key != 0x0611DF10u) && (return_key != 0x06125040u && (return_key != 0x06125D70u && return_key != 0x06126178u)))) && (((return_key != 0x061265A8u && return_key != 0x06126A90u) && (return_key != 0x06126FA8u && (return_key != 0x06127278u && return_key != 0x0612CF28u))) && ((return_key != 0x0612D1C8u && return_key != 0x0612D430u) && (return_key != 0x0612DA88u && (return_key != 0x0612DC58u && return_key != 0x0612E6B0u))))) && ((((return_key != 0x0612E788u && return_key != 0x06135410u) && (return_key != 0x06135610u && (return_key != 0x06138F20u && return_key != 0x0613B960u))) && ((return_key != 0x0613C820u && return_key != 0x0613CDB8u) && (return_key != 0x0613D508u && (return_key != 0x0613DB80u && return_key != 0x0613EFD8u)))) && (((return_key != 0x0613F1E0u && return_key != 0x06141008u) && (return_key != 0x06141998u && (return_key != 0x06141BE0u && return_key != 0x06142898u))) && ((return_key != 0x06142A60u && return_key != 0x06142D78u) && (return_key != 0x06143DA0u && (return_key != 0x06145258u && return_key != 0x06145330u)))))) && (((((return_key != 0x061453C0u && return_key != 0x06145A50u) && (return_key != 0x06145B28u && return_key != 0x06145BB8u)) && ((return_key != 0x06145DD0u && return_key != 0x06145E60u) && (return_key != 0x06148340u && (return_key != 0x06148508u && return_key != 0x061486D0u)))) && (((return_key != 0x0614B898u && return_key != 0x0614B9F8u) && (return_key != 0x0614BB58u && (return_key != 0x0614C670u && return_key != 0x0614CB60u))) && ((return_key != 0x0614D4D8u && return_key != 0x0614D8C0u) && (return_key != 0x0614E8C8u && (return_key != 0x0614E968u && return_key != 0x0614F960u))))) && ((((return_key != 0x0614FAB0u && return_key != 0x06159C78u) && (return_key != 0x06185458u && (return_key != 0x061854D8u && return_key != 0x06185670u))) && ((return_key != 0x06186A50u && return_key != 0x06186A90u) && (return_key != 0x06186C28u && (return_key != 0x0618F818u && return_key != 0x0618F958u)))) && (((return_key != 0x0618FA78u && return_key != 0x06195B90u) && (return_key != 0x06195C70u && (return_key != 0x06196050u && return_key != 0x06196090u))) && ((return_key != 0x06197778u && return_key != 0x06197C18u) && (return_key != 0x06197F50u && (return_key != 0x061A0BA8u && return_key != 0x061A4670u)))))))) && (((((((return_key != 0x061A6828u && return_key != 0x061A6CD8u) && (return_key != 0x061A7118u && return_key != 0x061A75C8u)) && ((return_key != 0x061AA488u && return_key != 0x061AC0E0u) && (return_key != 0x061B27D8u && (return_key != 0x061B2848u && return_key != 0x061B2910u)))) && (((return_key != 0x061B2A50u && return_key != 0x061B2BC0u) && (return_key != 0x061B32A8u && (return_key != 0x061B3490u && return_key != 0x061B3650u))) && ((return_key != 0x061BBFB0u && return_key != 0x061BD2E8u) && (return_key != 0x061BD7D0u && (return_key != 0x061C1A78u && return_key != 0x061C1CF8u))))) && ((((return_key != 0x061C2720u && return_key != 0x061C2898u) && (return_key != 0x061C2A40u && (return_key != 0x061C2BB8u && return_key != 0x061CB648u))) && ((return_key != 0x061D2478u && return_key != 0x061D3E80u) && (return_key != 0x061D83F0u && (return_key != 0x061DA848u && return_key != 0x061DA8E8u)))) && (((return_key != 0x061DB670u && return_key != 0x061DB6F0u) && (return_key != 0x061DB7D8u && (return_key != 0x061DB9B0u && return_key != 0x061DBCF0u))) && ((return_key != 0x061DBE00u && return_key != 0x061DBF00u) && (return_key != 0x061DC018u && (return_key != 0x061DC2D8u && return_key != 0x061DC3B8u)))))) && (((((return_key != 0x061DD8D0u && return_key != 0x061DD970u) && (return_key != 0x061DF100u && return_key != 0x061DF8A0u)) && ((return_key != 0x061DFE98u && return_key != 0x061E0340u) && (return_key != 0x061E2198u && (return_key != 0x061E2428u && return_key != 0x061E2648u)))) && (((return_key != 0x061E28D8u && return_key != 0x0623B3A8u) && (return_key != 0x0623B4D0u && (return_key != 0x0623B940u && return_key != 0x0623BA68u))) && ((return_key != 0x0623C3C0u && return_key != 0x0623C408u) && (return_key != 0x0623E408u && (return_key != 0x0623E908u && return_key != 0x0623E988u))))) && ((((return_key != 0x0623EA10u && return_key != 0x0623F958u) && (return_key != 0x0623F9D8u && (return_key != 0x0623FA60u && return_key != 0x06240210u))) && ((return_key != 0x06240640u && return_key != 0x062432A8u) && (return_key != 0x06280530u && (return_key != 0x062806C0u && return_key != 0x06280770u)))) && (((return_key != 0x06280B68u && return_key != 0x06280C30u) && (return_key != 0x06280F88u && (return_key != 0x062811B8u && return_key != 0x062820C8u))) && ((return_key != 0x06283368u && return_key != 0x06283608u) && (return_key != 0x062836E0u && (return_key != 0x06283808u && return_key != 0x06283900u))))))) && ((((((return_key != 0x06283A70u && return_key != 0x06286A98u) && (return_key != 0x06286E38u && return_key != 0x06287238u)) && ((return_key != 0x06287330u && return_key != 0x06287FC0u) && (return_key != 0x06289538u && (return_key != 0x062897C8u && return_key != 0x0628A118u)))) && (((return_key != 0x0628A230u && return_key != 0x0628B0F8u) && (return_key != 0x0628C9D0u && (return_key != 0x0628D3A0u && return_key != 0x0628DED8u))) && ((return_key != 0x0628DFA8u && return_key != 0x0628E408u) && (return_key != 0x0628FBE0u && (return_key != 0x062975E8u && return_key != 0x06299150u))))) && ((((return_key != 0x06299248u && return_key != 0x062993C0u) && (return_key != 0x062998A8u && (return_key != 0x06299B70u && return_key != 0x06299EB0u))) && ((return_key != 0x06299FC8u && return_key != 0x0629A0F0u) && (return_key != 0x0629A1B8u && (return_key != 0x0629A2F8u && return_key != 0x0629A6B0u)))) && (((return_key != 0x0629A7A8u && return_key != 0x0629B468u) && (return_key != 0x0629B540u && (return_key != 0x062A5E48u && return_key != 0x062A5F38u))) && ((return_key != 0x062A5FE0u && return_key != 0x062A79F0u) && (return_key != 0x062A7A38u && (return_key != 0x062A7B08u && return_key != 0x062AAB28u)))))) && (((((return_key != 0x062AAEC8u && return_key != 0x062AB100u) && (return_key != 0x062AB478u && (return_key != 0x062AF3E0u && return_key != 0x062B3B98u))) && ((return_key != 0x062B4200u && return_key != 0x062B4878u) && (return_key != 0x062B5698u && (return_key != 0x062B5760u && return_key != 0x062B5850u)))) && (((return_key != 0x062BBD40u && return_key != 0x062BBF10u) && (return_key != 0x062BCA58u && (return_key != 0x062BD500u && return_key != 0x062C6070u))) && ((return_key != 0x062C6220u && return_key != 0x062CF108u) && (return_key != 0x062CF1C8u && (return_key != 0x062D0EF8u && return_key != 0x062D2650u))))) && ((((return_key != 0x062E0F98u && return_key != 0x06309F08u) && (return_key != 0x06309FB0u && (return_key != 0x0630A760u && return_key != 0x06318240u))) && ((return_key != 0x0631AC70u && return_key != 0x0631AF20u) && (return_key != 0x0631B028u && (return_key != 0x0631B208u && return_key != 0x0631B3E0u)))) && (((return_key != 0x0631BA78u && return_key != 0x0631BD48u) && (return_key != 0x0631C0E0u && (return_key != 0x06328758u && return_key != 0x06328820u))) && ((return_key != 0x06328A18u && return_key != 0x0632AFD8u) && (return_key != 0x0632C330u && (return_key != 0x0632CD80u && return_key != 0x06331888u))))))))) && ((((((((return_key != 0x0633B4A0u && return_key != 0x0633D5D0u) && (return_key != 0x0633DB08u && return_key != 0x0633DEF8u)) && ((return_key != 0x0633FFD8u && return_key != 0x06340C18u) && (return_key != 0x06340D78u && (return_key != 0x06340F08u && return_key != 0x063410B0u)))) && (((return_key != 0x063415C8u && return_key != 0x06344C18u) && (return_key != 0x06388258u && (return_key != 0x063885E0u && return_key != 0x063886C8u))) && ((return_key != 0x06388BA0u && return_key != 0x06388C48u) && (return_key != 0x06388E78u && (return_key != 0x0638A310u && return_key != 0x0638A408u))))) && ((((return_key != 0x0638A998u && return_key != 0x0638AA90u) && (return_key != 0x0638B038u && (return_key != 0x0638B0C8u && return_key != 0x0638B1E8u))) && ((return_key != 0x0638CFA0u && return_key != 0x0638D060u) && (return_key != 0x0638E6C8u && (return_key != 0x0638F7B0u && return_key != 0x063910C0u)))) && (((return_key != 0x06391148u && return_key != 0x063912F8u) && (return_key != 0x06392E00u && (return_key != 0x063930E0u && return_key != 0x06393358u))) && ((return_key != 0x063943C0u && return_key != 0x06394550u) && (return_key != 0x06394BC8u && (return_key != 0x06395590u && return_key != 0x063964F8u)))))) && (((((return_key != 0x06396E78u && return_key != 0x06397390u) && (return_key != 0x063973D8u && return_key != 0x06397480u)) && ((return_key != 0x063983A8u && return_key != 0x0639A848u) && (return_key != 0x0639B198u && (return_key != 0x0639BC08u && return_key != 0x0639BE48u)))) && (((return_key != 0x0639C9D0u && return_key != 0x0639CAB8u) && (return_key != 0x063A1BD0u && (return_key != 0x063A6750u && return_key != 0x063A6880u))) && ((return_key != 0x063A6928u && return_key != 0x063B00D8u) && (return_key != 0x063B0F38u && (return_key != 0x063B1870u && return_key != 0x063B92C0u))))) && ((((return_key != 0x063BA1F0u && return_key != 0x063BA340u) && (return_key != 0x063BA4B8u && (return_key != 0x063BD718u && return_key != 0x063BE670u))) && ((return_key != 0x063BE780u && return_key != 0x063BE9A0u) && (return_key != 0x063BE9E8u && (return_key != 0x063C0EB8u && return_key != 0x063C2698u)))) && (((return_key != 0x063C28C8u && return_key != 0x063C29E0u) && (return_key != 0x063C5EC0u && (return_key != 0x063C6020u && return_key != 0x063C6108u))) && ((return_key != 0x063C7108u && return_key != 0x063C8308u) && (return_key != 0x063CD540u && (return_key != 0x063DAA98u && return_key != 0x063DAAE0u))))))) && ((((((return_key != 0x063E3950u && return_key != 0x063E5D38u) && (return_key != 0x063E5E28u && return_key != 0x063E6050u)) && ((return_key != 0x063E6140u && return_key != 0x063ED930u) && (return_key != 0x063F0178u && (return_key != 0x063F7308u && return_key != 0x063F9758u)))) && (((return_key != 0x06401158u && return_key != 0x06403750u) && (return_key != 0x06403900u && (return_key != 0x064053F8u && return_key != 0x06405520u))) && ((return_key != 0x0640EFA8u && return_key != 0x064107F8u) && (return_key != 0x06410DA8u && (return_key != 0x06411ED0u && return_key != 0x06412498u))))) && ((((return_key != 0x06412B20u && return_key != 0x06414D50u) && (return_key != 0x06416EE8u && (return_key != 0x0641AA78u && return_key != 0x0641AAC0u))) && ((return_key != 0x0642AFE0u && return_key != 0x0642B9F0u) && (return_key != 0x0642BBD0u && (return_key != 0x0642D808u && return_key != 0x06432700u)))) && (((return_key != 0x06433168u && return_key != 0x06433348u) && (return_key != 0x06433638u && (return_key != 0x064338B8u && return_key != 0x064362E0u))) && ((return_key != 0x064378E8u && return_key != 0x06438FA8u) && (return_key != 0x06439108u && (return_key != 0x0643B8E8u && return_key != 0x0643D1C0u)))))) && (((((return_key != 0x064823C0u && return_key != 0x0648A5F8u) && (return_key != 0x0648B708u && return_key != 0x0648C590u)) && ((return_key != 0x0648D448u && return_key != 0x06496000u) && (return_key != 0x06497ED8u && (return_key != 0x064983B8u && return_key != 0x06498C48u)))) && (((return_key != 0x06499310u && return_key != 0x06499770u) && (return_key != 0x0649ACC0u && (return_key != 0x0649B010u && return_key != 0x0649C200u))) && ((return_key != 0x064A2728u && return_key != 0x064A93C0u) && (return_key != 0x064A9580u && (return_key != 0x064AA5F0u && return_key != 0x064AA7B0u))))) && ((((return_key != 0x064AB3A0u && return_key != 0x064AF568u) && (return_key != 0x064B1B50u && (return_key != 0x064B3A10u && return_key != 0x064B61F8u))) && ((return_key != 0x064B6268u && return_key != 0x064B64E8u) && (return_key != 0x064B65D0u && (return_key != 0x064B6708u && return_key != 0x064B67D8u)))) && (((return_key != 0x064B68A8u && return_key != 0x064B69F0u) && (return_key != 0x064B6AC0u && (return_key != 0x064B6C30u && return_key != 0x064B7358u))) && ((return_key != 0x064B7A10u && return_key != 0x064B8BA0u) && (return_key != 0x064B8D88u && (return_key != 0x064BC1B8u && return_key != 0x064BC278u)))))))) && (((((((return_key != 0x064BC320u && return_key != 0x064BF228u) && (return_key != 0x064BF340u && return_key != 0x064BF418u)) && ((return_key != 0x064BF4F0u && return_key != 0x064BF6F8u) && (return_key != 0x064BF800u && (return_key != 0x064BF8D8u && return_key != 0x064BF9B0u)))) && (((return_key != 0x064BFA88u && return_key != 0x064BFB60u) && (return_key != 0x064BFC38u && (return_key != 0x064BFD10u && return_key != 0x064BFEF0u))) && ((return_key != 0x064BFFC8u && return_key != 0x064C6818u) && (return_key != 0x064C7BB0u && (return_key != 0x064CCAB0u && return_key != 0x064CD150u))))) && ((((return_key != 0x064D24C8u && return_key != 0x064D30D8u) && (return_key != 0x064D50C8u && (return_key != 0x064E4838u && return_key != 0x064E76D8u))) && ((return_key != 0x064E7BB0u && return_key != 0x064E8088u) && (return_key != 0x064EA158u && (return_key != 0x064ED038u && return_key != 0x064ED118u)))) && (((return_key != 0x064EDC58u && return_key != 0x064EDDA8u) && (return_key != 0x064EE540u && (return_key != 0x064EEC00u && return_key != 0x064EF348u))) && ((return_key != 0x064EFB20u && return_key != 0x064F0A60u) && (return_key != 0x064F0F78u && (return_key != 0x064F27D8u && return_key != 0x064F5698u)))))) && (((((return_key != 0x064F5768u && return_key != 0x064F5938u) && (return_key != 0x06501450u && return_key != 0x06501BC8u)) && ((return_key != 0x06510190u && return_key != 0x065104C8u) && (return_key != 0x06510718u && (return_key != 0x06510878u && return_key != 0x06510AA0u)))) && (((return_key != 0x06510B88u && return_key != 0x06510CD0u) && (return_key != 0x06510E28u && (return_key != 0x06512B10u && return_key != 0x06512FC8u))) && ((return_key != 0x065182E0u && return_key != 0x06518678u) && (return_key != 0x06518A98u && (return_key != 0x06518D60u && return_key != 0x065217C8u))))) && ((((return_key != 0x06522050u && return_key != 0x06529500u) && (return_key != 0x06529CB0u && (return_key != 0x06529CF8u && return_key != 0x0652B570u))) && ((return_key != 0x0652B690u && return_key != 0x0652D420u) && (return_key != 0x065328F0u && (return_key != 0x06532990u && return_key != 0x06532ED0u)))) && (((return_key != 0x065372B0u && return_key != 0x0660A4F0u) && (return_key != 0x0660E018u && (return_key != 0x0660E060u && return_key != 0x06610B70u))) && ((return_key != 0x06613750u && return_key != 0x06613B08u) && (return_key != 0x06613BC8u && (return_key != 0x06613E88u && return_key != 0x06616CB0u))))))) && ((((((return_key != 0x0661B290u && return_key != 0x0661C058u) && (return_key != 0x0661D3B0u && return_key != 0x066831C8u)) && ((return_key != 0x06683E48u && return_key != 0x066857E0u) && (return_key != 0x06689460u && (return_key != 0x0669B6C0u && return_key != 0x066A3598u)))) && (((return_key != 0x066A5C18u && return_key != 0x066A6BA0u) && (return_key != 0x066A7F40u && (return_key != 0x066ABC48u && return_key != 0x066AC708u))) && ((return_key != 0x066BBE80u && return_key != 0x066BC1C0u) && (return_key != 0x066BCC18u && (return_key != 0x066C3280u && return_key != 0x066C35D0u))))) && ((((return_key != 0x066C6500u && return_key != 0x066C7B10u) && (return_key != 0x066C8700u && (return_key != 0x066CBA00u && return_key != 0x066CBAF0u))) && ((return_key != 0x066D0C10u && return_key != 0x066D10B0u) && (return_key != 0x066D15C8u && (return_key != 0x066D1F78u && return_key != 0x066D2058u)))) && (((return_key != 0x066D2F18u && return_key != 0x066D2FF0u) && (return_key != 0x066D3200u && (return_key != 0x066D32D8u && return_key != 0x066D35F8u))) && ((return_key != 0x066D36D0u && return_key != 0x066D39D0u) && (return_key != 0x066D3AA8u && (return_key != 0x066DAEC0u && return_key != 0x066DC8D0u)))))) && (((((return_key != 0x066DCDB0u && return_key != 0x066DCFA8u) && (return_key != 0x066DD390u && (return_key != 0x066DD708u && return_key != 0x066DD9C0u))) && ((return_key != 0x066DDA40u && return_key != 0x066DDC40u) && (return_key != 0x066DDCC0u && (return_key != 0x066DE780u && return_key != 0x066DE800u)))) && (((return_key != 0x066DEA30u && return_key != 0x066DEAB0u) && (return_key != 0x066DFBE8u && (return_key != 0x066E00F0u && return_key != 0x066E0168u))) && ((return_key != 0x066E10F8u && return_key != 0x066E1170u) && (return_key != 0x066E17A0u && (return_key != 0x066E1AB0u && return_key != 0x066E1BF0u))))) && ((((return_key != 0x066E1C70u && return_key != 0x066E1D68u) && (return_key != 0x066E1FE0u && (return_key != 0x066E2B20u && return_key != 0x066E31D0u))) && ((return_key != 0x06708198u && return_key != 0x0670A1F8u) && (return_key != 0x0670B170u && (return_key != 0x0670F950u && return_key != 0x067126D8u)))) && (((return_key != 0x067129B8u && return_key != 0x06713220u) && (return_key != 0x067151A8u && (return_key != 0x06715AC0u && return_key != 0x06716188u))) && ((return_key != 0x067171C8u && return_key != 0x06717748u) && (return_key != 0x06717BA8u && (return_key != 0x06717F68u && return_key != 0x0671E668u)))))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FD360u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA6Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA6Eu;
            if (nh_scpu_expect_next(cpu, 0x060FD370u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD370u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA6Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            cpu->x &= 0x00FFu;
            cpu->y &= 0x00FFu;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA70u;
            if (nh_scpu_expect_next(cpu, 0x060FD383u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD383u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA70u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA72u;
            if (nh_scpu_expect_next(cpu, 0x060FD393u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD393u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x02u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA72u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x004202u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA76u;
            if (nh_scpu_expect_next(cpu, 0x060FD3B3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FD3B3u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA76u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA78u;
            if (nh_scpu_expect_next(cpu, 0x060FD3C3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD3C3u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x03u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA78u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x004203u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA7Cu;
            if (nh_scpu_expect_next(cpu, 0x060FD3E3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FD3E3u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA7Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA7Du;
            if (nh_scpu_expect_next(cpu, 0x060FD3EBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD3EBu: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA7Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA7Eu;
            if (nh_scpu_expect_next(cpu, 0x060FD3F3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD3F3u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA7Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA7Fu;
            if (nh_scpu_expect_next(cpu, 0x060FD3FBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD3FBu: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA7Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA81u;
            if (nh_scpu_expect_next(cpu, 0x060FD409u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD409u: {
            static const uint8_t expected_epoch[] = { 0xAFu, 0x16u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA81u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = 0x004216u;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA85u;
            if (nh_scpu_expect_next(cpu, 0x060FD429u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FD429u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA85u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000008u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA87u;
            if (nh_scpu_expect_next(cpu, 0x060FD439u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD439u: {
            static const uint8_t expected_epoch[] = { 0xA2u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA87u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = 0x00u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA89u;
            if (nh_scpu_expect_next(cpu, 0x060FD449u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD449u: {
            static const uint8_t expected_epoch[] = { 0xDAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA89u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->x) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA8Au;
            if (nh_scpu_expect_next(cpu, 0x060FD451u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD451u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA8Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x01u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA8Cu;
            if (nh_scpu_expect_next(cpu, 0x060FD461u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD461u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA8Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA8Eu;
            if (nh_scpu_expect_next(cpu, 0x060FD473u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD473u: {
            static const uint8_t expected_epoch[] = { 0xBBu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA8Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint8_t)(cpu->y);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA8Fu;
            if (nh_scpu_expect_next(cpu, 0x060FD47Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD47Bu: {
            static const uint8_t expected_epoch[] = { 0xB5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA8Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = ((uint32_t)cpu->d + 0x0000u + cpu->x) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA91u;
            if (nh_scpu_expect_next(cpu, 0x060FD48Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD48Bu: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x02u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA91u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x004202u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA95u;
            if (nh_scpu_expect_next(cpu, 0x060FD4ABu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FD4ABu: {
            static const uint8_t expected_epoch[] = { 0xFAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA95u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_pull8(cpu, bus, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA96u;
            if (nh_scpu_expect_next(cpu, 0x060FD4B3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060FD4B3u: {
            static const uint8_t expected_epoch[] = { 0xB5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA96u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = ((uint32_t)cpu->d + 0x0004u + cpu->x) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA98u;
            if (nh_scpu_expect_next(cpu, 0x060FD4C3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD4C3u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x03u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA98u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x004203u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA9Cu;
            if (nh_scpu_expect_next(cpu, 0x060FD4E3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FD4E3u: {
            static const uint8_t expected_epoch[] = { 0xE8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA9Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint8_t)(cpu->x + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA9Du;
            if (nh_scpu_expect_next(cpu, 0x060FD4EBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD4EBu: {
            static const uint8_t expected_epoch[] = { 0xDAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA9Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->x) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA9Eu;
            if (nh_scpu_expect_next(cpu, 0x060FD4F3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD4F3u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FA9Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAA0u;
            if (nh_scpu_expect_next(cpu, 0x060FD501u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD501u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAA0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAA1u;
            if (nh_scpu_expect_next(cpu, 0x060FD509u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD509u: {
            static const uint8_t expected_epoch[] = { 0xAFu, 0x16u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAA1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = 0x004216u;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAA5u;
            if (nh_scpu_expect_next(cpu, 0x060FD529u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FD529u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x09u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAA5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            const uint32_t sum = (uint32_t)left + right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            const uint16_t result = (uint16_t)sum;
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (sum > 0xFFFFu) cpu->p |= NH_P_C;
            if (((uint16_t)(~(left ^ right)) & (left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAA7u;
            if (nh_scpu_expect_next(cpu, 0x060FD539u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD539u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x09u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAA7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAA9u;
            if (nh_scpu_expect_next(cpu, 0x060FD549u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD549u: {
            static const uint8_t expected_epoch[] = { 0x88u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAA9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint8_t)(cpu->y - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAAAu;
            if (nh_scpu_expect_next(cpu, 0x060FD551u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD551u: {
            static const uint8_t expected_epoch[] = { 0x10u, 0xE0u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAAAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFA8Cu;
                if (nh_scpu_expect_next(cpu, 0x060FD461u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAACu;
            if (nh_scpu_expect_next(cpu, 0x060FD561u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD561u: {
            static const uint8_t expected_epoch[] = { 0xFAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAACu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_pull8(cpu, bus, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAADu;
            if (nh_scpu_expect_next(cpu, 0x060FD569u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060FD569u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAADu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAAFu;
            if (nh_scpu_expect_next(cpu, 0x060FD57Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD57Bu: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAAFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x00u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAB1u;
            if (nh_scpu_expect_next(cpu, 0x060FD58Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD58Bu: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAB1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t right = 0u;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), &right) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t left = (uint8_t)cpu->a;
            const uint16_t total = (uint16_t)((uint16_t)left + right + ((cpu->p & NH_P_C) != 0u ? 1u : 0u));
            const uint8_t result = (uint8_t)total;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_C | NH_P_V));
            if (total > 0xFFu) cpu->p |= NH_P_C;
            if (((uint8_t)~(left ^ right) & (left ^ result) & 0x80u) != 0u) cpu->p |= NH_P_V;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAB3u;
            if (nh_scpu_expect_next(cpu, 0x060FD59Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD59Bu: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAB3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAB5u;
            if (nh_scpu_expect_next(cpu, 0x060FD5ABu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD5ABu: {
            static const uint8_t expected_epoch[] = { 0xA2u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAB5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = 0x00u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAB7u;
            if (nh_scpu_expect_next(cpu, 0x060FD5BBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD5BBu: {
            static const uint8_t expected_epoch[] = { 0xDAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAB7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->x) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAB8u;
            if (nh_scpu_expect_next(cpu, 0x060FD5C3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD5C3u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAB8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x02u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFABAu;
            if (nh_scpu_expect_next(cpu, 0x060FD5D3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD5D1u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FABAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFABCu;
            if (nh_scpu_expect_next(cpu, 0x060FD5E3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD5D3u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FABAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFABCu;
            if (nh_scpu_expect_next(cpu, 0x060FD5E3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD5E3u: {
            static const uint8_t expected_epoch[] = { 0xBBu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FABCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint8_t)(cpu->y);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFABDu;
            if (nh_scpu_expect_next(cpu, 0x060FD5EBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD5EBu: {
            static const uint8_t expected_epoch[] = { 0xB5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FABDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = ((uint32_t)cpu->d + 0x0000u + cpu->x) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFABFu;
            if (nh_scpu_expect_next(cpu, 0x060FD5FBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD5FBu: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x02u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FABFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x004202u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAC3u;
            if (nh_scpu_expect_next(cpu, 0x060FD61Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FD61Bu: {
            static const uint8_t expected_epoch[] = { 0xFAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAC3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_pull8(cpu, bus, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAC4u;
            if (nh_scpu_expect_next(cpu, 0x060FD623u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060FD623u: {
            static const uint8_t expected_epoch[] = { 0xB5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAC4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = ((uint32_t)cpu->d + 0x0004u + cpu->x) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAC6u;
            if (nh_scpu_expect_next(cpu, 0x060FD633u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD633u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x03u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAC6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x004203u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFACAu;
            if (nh_scpu_expect_next(cpu, 0x060FD653u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FD653u: {
            static const uint8_t expected_epoch[] = { 0xE8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FACAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint8_t)(cpu->x + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFACBu;
            if (nh_scpu_expect_next(cpu, 0x060FD65Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD65Bu: {
            static const uint8_t expected_epoch[] = { 0xDAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FACBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->x) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFACCu;
            if (nh_scpu_expect_next(cpu, 0x060FD663u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD663u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FACCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFACEu;
            if (nh_scpu_expect_next(cpu, 0x060FD671u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD671u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FACEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFACFu;
            if (nh_scpu_expect_next(cpu, 0x060FD679u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD679u: {
            static const uint8_t expected_epoch[] = { 0xAFu, 0x16u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FACFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = 0x004216u;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAD3u;
            if (nh_scpu_expect_next(cpu, 0x060FD699u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FD699u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAD3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            const uint32_t sum = (uint32_t)left + right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            const uint16_t result = (uint16_t)sum;
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (sum > 0xFFFFu) cpu->p |= NH_P_C;
            if (((uint16_t)(~(left ^ right)) & (left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAD5u;
            if (nh_scpu_expect_next(cpu, 0x060FD6A9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD6A9u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAD5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAD7u;
            if (nh_scpu_expect_next(cpu, 0x060FD6B9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD6B9u: {
            static const uint8_t expected_epoch[] = { 0x88u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAD7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint8_t)(cpu->y - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAD8u;
            if (nh_scpu_expect_next(cpu, 0x060FD6C1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD6C1u: {
            static const uint8_t expected_epoch[] = { 0x10u, 0xE0u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAD8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFABAu;
                if (nh_scpu_expect_next(cpu, 0x060FD5D1u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFADAu;
            if (nh_scpu_expect_next(cpu, 0x060FD6D1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD6D1u: {
            static const uint8_t expected_epoch[] = { 0xFAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FADAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_pull8(cpu, bus, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFADBu;
            if (nh_scpu_expect_next(cpu, 0x060FD6D9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060FD6D9u: {
            static const uint8_t expected_epoch[] = { 0xA2u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FADBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = 0x00u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFADDu;
            if (nh_scpu_expect_next(cpu, 0x060FD6E9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD6E9u: {
            static const uint8_t expected_epoch[] = { 0xDAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FADDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->x) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFADEu;
            if (nh_scpu_expect_next(cpu, 0x060FD6F1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD6F1u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FADEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x03u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAE0u;
            if (nh_scpu_expect_next(cpu, 0x060FD701u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD701u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAE0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAE2u;
            if (nh_scpu_expect_next(cpu, 0x060FD713u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD713u: {
            static const uint8_t expected_epoch[] = { 0xBBu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAE2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint8_t)(cpu->y);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAE3u;
            if (nh_scpu_expect_next(cpu, 0x060FD71Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD71Bu: {
            static const uint8_t expected_epoch[] = { 0xB5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAE3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = ((uint32_t)cpu->d + 0x0000u + cpu->x) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAE5u;
            if (nh_scpu_expect_next(cpu, 0x060FD72Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD72Bu: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x02u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAE5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x004202u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAE9u;
            if (nh_scpu_expect_next(cpu, 0x060FD74Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FD74Bu: {
            static const uint8_t expected_epoch[] = { 0xFAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAE9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_pull8(cpu, bus, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAEAu;
            if (nh_scpu_expect_next(cpu, 0x060FD753u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060FD753u: {
            static const uint8_t expected_epoch[] = { 0xB5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAEAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = ((uint32_t)cpu->d + 0x0004u + cpu->x) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAECu;
            if (nh_scpu_expect_next(cpu, 0x060FD763u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD763u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x03u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAECu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x004203u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAF0u;
            if (nh_scpu_expect_next(cpu, 0x060FD783u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FD783u: {
            static const uint8_t expected_epoch[] = { 0xE8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAF0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint8_t)(cpu->x + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAF1u;
            if (nh_scpu_expect_next(cpu, 0x060FD78Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD78Bu: {
            static const uint8_t expected_epoch[] = { 0xDAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAF1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->x) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAF2u;
            if (nh_scpu_expect_next(cpu, 0x060FD793u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD793u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAF2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAF3u;
            if (nh_scpu_expect_next(cpu, 0x060FD79Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD79Bu: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAF3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAF4u;
            if (nh_scpu_expect_next(cpu, 0x060FD7A3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD7A3u: {
            static const uint8_t expected_epoch[] = { 0xAFu, 0x16u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAF4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, 0x004216u, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAF8u;
            if (nh_scpu_expect_next(cpu, 0x060FD7C3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FD7C3u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAF8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t right = 0u;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), &right) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t left = (uint8_t)cpu->a;
            const uint16_t total = (uint16_t)((uint16_t)left + right + ((cpu->p & NH_P_C) != 0u ? 1u : 0u));
            const uint8_t result = (uint8_t)total;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_C | NH_P_V));
            if (total > 0xFFu) cpu->p |= NH_P_C;
            if (((uint8_t)~(left ^ right) & (left ^ result) & 0x80u) != 0u) cpu->p |= NH_P_V;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAFAu;
            if (nh_scpu_expect_next(cpu, 0x060FD7D3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD7D3u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAFAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAFCu;
            if (nh_scpu_expect_next(cpu, 0x060FD7E3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD7E3u: {
            static const uint8_t expected_epoch[] = { 0x88u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAFCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint8_t)(cpu->y - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAFDu;
            if (nh_scpu_expect_next(cpu, 0x060FD7EBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD7EBu: {
            static const uint8_t expected_epoch[] = { 0x10u, 0xE3u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAFDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFAE2u;
                if (nh_scpu_expect_next(cpu, 0x060FD713u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFAFFu;
            if (nh_scpu_expect_next(cpu, 0x060FD7FBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD7FBu: {
            static const uint8_t expected_epoch[] = { 0xFAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FAFFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_pull8(cpu, bus, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB00u;
            if (nh_scpu_expect_next(cpu, 0x060FD803u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        default: return NH_SCPU_NOT_MINE;
    }
}
