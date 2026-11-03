/* Generated direct New Horizons S-CPU authority; do not edit. */
#include "nh_v07_generated.h"

NHScpuExecResult nh_v07_shard_00C1FC(NHScpuState *cpu, const NHScpuBus *bus) {
    switch (nh_scpu_context_key(cpu)) {
        case 0x060FE002u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC00u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC01u;
            if (nh_scpu_expect_next(cpu, 0x060FE00Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE00Au: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC01u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC02u;
            if (nh_scpu_expect_next(cpu, 0x060FE012u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE012u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC02u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC04u;
            if (nh_scpu_expect_next(cpu, 0x060FE020u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FE020u: {
            static const uint8_t expected_epoch[] = { 0xAFu, 0x14u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC04u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = 0x004214u;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC08u;
            if (nh_scpu_expect_next(cpu, 0x060FE040u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FE040u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC08u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC0Au;
            if (nh_scpu_expect_next(cpu, 0x060FE050u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE050u: {
            static const uint8_t expected_epoch[] = { 0xAFu, 0x16u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC0Au,
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
            cpu->pc = 0xFC0Eu;
            if (nh_scpu_expect_next(cpu, 0x060FE070u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FE070u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC0Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC10u;
            if (nh_scpu_expect_next(cpu, 0x060FE080u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE080u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x09u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC10u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC12u;
            if (nh_scpu_expect_next(cpu, 0x060FE090u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE090u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x04u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC12u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x004204u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, 0x004205u, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC16u;
            if (nh_scpu_expect_next(cpu, 0x060FE0B0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FE0B0u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC16u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC18u;
            if (nh_scpu_expect_next(cpu, 0x060FE0C2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FE0C2u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC18u,
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
            cpu->pc = 0xFC1Au;
            if (nh_scpu_expect_next(cpu, 0x060FE0D2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE0D2u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x06u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC1Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x004206u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC1Eu;
            if (nh_scpu_expect_next(cpu, 0x060FE0F2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FE0F2u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC1Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC1Fu;
            if (nh_scpu_expect_next(cpu, 0x060FE0FAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE0FAu: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC1Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC20u;
            if (nh_scpu_expect_next(cpu, 0x060FE102u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE102u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC20u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC21u;
            if (nh_scpu_expect_next(cpu, 0x060FE10Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE10Au: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC21u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC22u;
            if (nh_scpu_expect_next(cpu, 0x060FE112u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE112u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC22u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC23u;
            if (nh_scpu_expect_next(cpu, 0x060FE11Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE11Au: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC23u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC24u;
            if (nh_scpu_expect_next(cpu, 0x060FE122u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE122u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC24u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC25u;
            if (nh_scpu_expect_next(cpu, 0x060FE12Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE12Au: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC25u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC26u;
            if (nh_scpu_expect_next(cpu, 0x060FE132u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE132u: {
            static const uint8_t expected_epoch[] = { 0xAFu, 0x14u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC26u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, 0x004214u, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC2Au;
            if (nh_scpu_expect_next(cpu, 0x060FE152u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FE152u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC2Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC2Cu;
            if (nh_scpu_expect_next(cpu, 0x060FE162u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE162u: {
            static const uint8_t expected_epoch[] = { 0xAFu, 0x16u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC2Cu,
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
            cpu->pc = 0xFC30u;
            if (nh_scpu_expect_next(cpu, 0x060FE182u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FE182u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x09u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC30u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC32u;
            if (nh_scpu_expect_next(cpu, 0x060FE192u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE192u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC32u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC34u;
            if (nh_scpu_expect_next(cpu, 0x060FE1A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FE1A0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC34u,
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
            cpu->pc = 0xFC36u;
            if (nh_scpu_expect_next(cpu, 0x060FE1B0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE1B0u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x04u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC36u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x004204u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, 0x004205u, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC3Au;
            if (nh_scpu_expect_next(cpu, 0x060FE1D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FE1D0u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC3Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC3Cu;
            if (nh_scpu_expect_next(cpu, 0x060FE1E2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FE1E2u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC3Cu,
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
            cpu->pc = 0xFC3Eu;
            if (nh_scpu_expect_next(cpu, 0x060FE1F2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE1F2u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x06u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC3Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x004206u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC42u;
            if (nh_scpu_expect_next(cpu, 0x060FE212u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FE212u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC42u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC43u;
            if (nh_scpu_expect_next(cpu, 0x060FE21Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE21Au: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC43u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC44u;
            if (nh_scpu_expect_next(cpu, 0x060FE222u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE222u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC44u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC45u;
            if (nh_scpu_expect_next(cpu, 0x060FE22Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE22Au: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC45u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC46u;
            if (nh_scpu_expect_next(cpu, 0x060FE232u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE232u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC46u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC47u;
            if (nh_scpu_expect_next(cpu, 0x060FE23Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE23Au: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC47u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC48u;
            if (nh_scpu_expect_next(cpu, 0x060FE242u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE242u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC48u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC49u;
            if (nh_scpu_expect_next(cpu, 0x060FE24Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE24Au: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC49u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC4Au;
            if (nh_scpu_expect_next(cpu, 0x060FE252u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE252u: {
            static const uint8_t expected_epoch[] = { 0xAFu, 0x14u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC4Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, 0x004214u, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC4Eu;
            if (nh_scpu_expect_next(cpu, 0x060FE272u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FE272u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC4Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC50u;
            if (nh_scpu_expect_next(cpu, 0x060FE282u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE282u: {
            static const uint8_t expected_epoch[] = { 0xAFu, 0x16u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC50u,
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
            cpu->pc = 0xFC54u;
            if (nh_scpu_expect_next(cpu, 0x060FE2A2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FE2A2u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC54u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000008u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC56u;
            if (nh_scpu_expect_next(cpu, 0x060FE2B2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE2B2u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x09u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC56u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC58u;
            if (nh_scpu_expect_next(cpu, 0x060FE2C2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE2C2u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC58u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC5Au;
            if (nh_scpu_expect_next(cpu, 0x060FE2D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FE2D0u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC5Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC5Cu;
            if (nh_scpu_expect_next(cpu, 0x060FE2E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE2E0u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC5Cu,
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
            if (((((return_key != 0x060FDBF8u && return_key != 0x060FE458u) && (return_key != 0x062BA5B8u && return_key != 0x062BAA88u)) && ((return_key != 0x063B0908u && return_key != 0x065127F0u) && (return_key != 0x06512970u && (return_key != 0x06513228u && return_key != 0x065135A0u)))) && (((return_key != 0x06513730u && return_key != 0x06513850u) && (return_key != 0x06513978u && (return_key != 0x06513BC8u && return_key != 0x06524160u))) && ((return_key != 0x066A6C28u && return_key != 0x066A6CF0u) && (return_key != 0x066A7FC8u && (return_key != 0x066A8090u && return_key != 0x067113D0u))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FE2E8u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x38u, 0xFBu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC5Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFCu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x60u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB38u;
            if (nh_scpu_expect_next(cpu, 0x060FD9C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060FE308u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC61u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC63u;
            if (nh_scpu_expect_next(cpu, 0x060FE318u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE318u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC63u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC69u;
            if (nh_scpu_expect_next(cpu, 0x060FE348u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FE328u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x18u, 0xFBu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC65u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFCu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x68u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB18u;
            if (nh_scpu_expect_next(cpu, 0x060FD8C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060FE348u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC69u,
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
            cpu->pc = 0xFC6Bu;
            if (nh_scpu_expect_next(cpu, 0x060FE358u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE358u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC6Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC6Du;
            if (nh_scpu_expect_next(cpu, 0x060FE368u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE368u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC6Du,
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
            cpu->pc = 0xFC6Fu;
            if (nh_scpu_expect_next(cpu, 0x060FE378u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE378u: {
            static const uint8_t expected_epoch[] = { 0x30u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC6Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) != 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFC72u;
                if (nh_scpu_expect_next(cpu, 0x060FE390u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC71u;
            if (nh_scpu_expect_next(cpu, 0x060FE388u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE388u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC71u,
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
            if (((((((((return_key != 0x06080120u && return_key != 0x060801A8u) && (return_key != 0x06080230u && (return_key != 0x06085350u && return_key != 0x06086058u))) && ((return_key != 0x060860F0u && (return_key != 0x0608FED0u && return_key != 0x06090000u)) && (return_key != 0x06090810u && (return_key != 0x060913E0u && return_key != 0x06092B48u)))) && (((return_key != 0x06092C78u && (return_key != 0x06093488u && return_key != 0x06094058u)) && (return_key != 0x06095E60u && (return_key != 0x06095FB0u && return_key != 0x06096248u))) && ((return_key != 0x060CE978u && (return_key != 0x060CF110u && return_key != 0x060CFEB0u)) && (return_key != 0x060D0888u && (return_key != 0x060D1340u && return_key != 0x060D1B08u))))) && ((((return_key != 0x060D20D8u && (return_key != 0x060D2F00u && return_key != 0x060D3638u)) && (return_key != 0x060D4C80u && (return_key != 0x060D5070u && return_key != 0x060D6B40u))) && ((return_key != 0x060D6EC8u && (return_key != 0x060D7170u && return_key != 0x060D7BE8u)) && (return_key != 0x060D7FD8u && (return_key != 0x060E0D00u && return_key != 0x060E9010u)))) && (((return_key != 0x060EB400u && (return_key != 0x060EBB70u && return_key != 0x060EC4E8u)) && (return_key != 0x060EF828u && (return_key != 0x060F0258u && return_key != 0x0610CF00u))) && ((return_key != 0x0610F638u && (return_key != 0x061108B8u && return_key != 0x06113FB8u)) && (return_key != 0x06114900u && (return_key != 0x06114BF0u && return_key != 0x06114E08u)))))) && (((((return_key != 0x0612E670u && return_key != 0x06131558u) && (return_key != 0x061317C0u && (return_key != 0x06133600u && return_key != 0x06133CE8u))) && ((return_key != 0x061352C8u && (return_key != 0x061364B0u && return_key != 0x0613F108u)) && (return_key != 0x06141608u && (return_key != 0x06143BA8u && return_key != 0x06184070u)))) && (((return_key != 0x06185EA8u && (return_key != 0x06186278u && return_key != 0x061875D8u)) && (return_key != 0x06187908u && (return_key != 0x06189070u && return_key != 0x0618D970u))) && ((return_key != 0x0618E7D0u && (return_key != 0x0618E890u && return_key != 0x06196758u)) && (return_key != 0x06199A98u && (return_key != 0x0619B328u && return_key != 0x0619B3E8u))))) && ((((return_key != 0x061A7988u && (return_key != 0x061A7A50u && return_key != 0x061A8620u)) && (return_key != 0x061A92C0u && (return_key != 0x061AA5D8u && return_key != 0x061AA6A8u))) && ((return_key != 0x061AF9D0u && (return_key != 0x061AFAA0u && return_key != 0x061B4A60u)) && (return_key != 0x061B4B60u && (return_key != 0x061B7C48u && return_key != 0x061B9540u)))) && (((return_key != 0x061B96A0u && (return_key != 0x061BB770u && return_key != 0x061DE9E0u)) && (return_key != 0x0620DFA8u && (return_key != 0x0620E788u && return_key != 0x0620EAA8u))) && ((return_key != 0x0620EBF0u && (return_key != 0x0623B130u && return_key != 0x0623B668u)) && (return_key != 0x0623BC00u && (return_key != 0x0628A1E8u && return_key != 0x0628EA00u))))))) && ((((((return_key != 0x0629B4F8u && return_key != 0x062A5980u) && (return_key != 0x062A5A68u && (return_key != 0x062A6108u && return_key != 0x062AB1E8u))) && ((return_key != 0x062AB2B8u && (return_key != 0x062AC3A8u && return_key != 0x062AC430u)) && (return_key != 0x062AE7B8u && (return_key != 0x062CE3A8u && return_key != 0x062D1378u)))) && (((return_key != 0x062D1430u && (return_key != 0x062D2608u && return_key != 0x062D44C8u)) && (return_key != 0x06307920u && (return_key != 0x06309B28u && return_key != 0x0630BC78u))) && ((return_key != 0x0630CF98u && (return_key != 0x063139E0u && return_key != 0x063141A8u)) && (return_key != 0x06314688u && (return_key != 0x06314808u && return_key != 0x06314968u))))) && ((((return_key != 0x06318CB0u && (return_key != 0x06319DF8u && return_key != 0x0631BF10u)) && (return_key != 0x0631F8E8u && (return_key != 0x0631FFC0u && return_key != 0x06325EB0u))) && ((return_key != 0x06326430u && (return_key != 0x06327650u && return_key != 0x06329338u)) && (return_key != 0x0632BDE0u && (return_key != 0x06330230u && return_key != 0x06330AF0u)))) && (((return_key != 0x06330C50u && (return_key != 0x063329D8u && return_key != 0x06333170u)) && (return_key != 0x063332B0u && (return_key != 0x06333F28u && return_key != 0x06334010u))) && ((return_key != 0x063340F8u && (return_key != 0x06334DC8u && return_key != 0x06334F58u)) && (return_key != 0x06335CC0u && (return_key != 0x06335DA8u && return_key != 0x06335E90u)))))) && (((((return_key != 0x063379B8u && (return_key != 0x06337B48u && return_key != 0x0633D388u)) && (return_key != 0x0633D468u && (return_key != 0x0633D9A0u && return_key != 0x06341D00u))) && ((return_key != 0x06341DE0u && (return_key != 0x06341EF8u && return_key != 0x06359C38u)) && (return_key != 0x063882D8u && (return_key != 0x06388770u && return_key != 0x06389828u)))) && (((return_key != 0x0638A4C8u && (return_key != 0x0638AB50u && return_key != 0x0638FE30u)) && (return_key != 0x06390FB0u && (return_key != 0x06391038u && return_key != 0x06392108u))) && ((return_key != 0x063A6240u && (return_key != 0x063A6370u && return_key != 0x063B6428u)) && (return_key != 0x063B64C0u && (return_key != 0x063B6580u && return_key != 0x063B70B8u))))) && ((((return_key != 0x063BB090u && (return_key != 0x063D4348u && return_key != 0x063DEDA8u)) && (return_key != 0x063E36C0u && (return_key != 0x063E3908u && return_key != 0x063E5AC0u))) && ((return_key != 0x063F0E70u && (return_key != 0x063F4C28u && return_key != 0x06416CA0u)) && (return_key != 0x06418A50u && (return_key != 0x06420BB8u && return_key != 0x0642B7B0u)))) && (((return_key != 0x06433408u && (return_key != 0x06438AC0u && return_key != 0x06480098u)) && (return_key != 0x064916D0u && (return_key != 0x06495480u && return_key != 0x06495A30u))) && ((return_key != 0x064B1DE0u && (return_key != 0x064BA598u && return_key != 0x064BA6B0u)) && (return_key != 0x064BBCA8u && (return_key != 0x064BBDD8u && return_key != 0x064BC8C8u)))))))) && (((((((return_key != 0x064C41C8u && return_key != 0x064C4550u) && (return_key != 0x064C4F08u && (return_key != 0x064CB7D8u && return_key != 0x064D09B8u))) && ((return_key != 0x064D1090u && (return_key != 0x064D5370u && return_key != 0x064D5470u)) && (return_key != 0x064D6398u && (return_key != 0x064D6738u && return_key != 0x064F5208u)))) && (((return_key != 0x064F5328u && (return_key != 0x065005C0u && return_key != 0x065011A0u)) && (return_key != 0x06501860u && (return_key != 0x06501D08u && return_key != 0x065033D8u))) && ((return_key != 0x06503560u && (return_key != 0x06504000u && return_key != 0x065048B8u)) && (return_key != 0x06504CC0u && (return_key != 0x06505968u && return_key != 0x06506BD0u))))) && ((((return_key != 0x06506E88u && (return_key != 0x06506FE0u && return_key != 0x06507138u)) && (return_key != 0x06507288u && (return_key != 0x06507698u && return_key != 0x06507880u))) && ((return_key != 0x06508268u && (return_key != 0x0650E638u && return_key != 0x0650E700u)) && (return_key != 0x0650E9F0u && (return_key != 0x0650ECC0u && return_key != 0x0650EE80u)))) && (((return_key != 0x0650F250u && (return_key != 0x0650F3D8u && return_key != 0x06511198u)) && (return_key != 0x06511280u && (return_key != 0x06511DC0u && return_key != 0x065120B8u))) && ((return_key != 0x06513EA0u && (return_key != 0x06513FB0u && return_key != 0x065144C0u)) && (return_key != 0x065151A8u && (return_key != 0x065152B8u && return_key != 0x06515710u)))))) && (((((return_key != 0x065167D0u && (return_key != 0x06517E60u && return_key != 0x06519470u)) && (return_key != 0x06519580u && (return_key != 0x06519928u && return_key != 0x0651A700u))) && ((return_key != 0x0651A868u && (return_key != 0x0651A9E8u && return_key != 0x0651C0D0u)) && (return_key != 0x0651C610u && (return_key != 0x0651DC38u && return_key != 0x0651DCE0u)))) && (((return_key != 0x0651E040u && (return_key != 0x0651E088u && return_key != 0x0651F050u)) && (return_key != 0x0651F3D8u && (return_key != 0x0651F708u && return_key != 0x0651FAC0u))) && ((return_key != 0x0651FD68u && (return_key != 0x06521AE8u && return_key != 0x065243C8u)) && (return_key != 0x065244C8u && (return_key != 0x065252A8u && return_key != 0x065252F0u))))) && ((((return_key != 0x06527658u && (return_key != 0x065324D8u && return_key != 0x065325B0u)) && (return_key != 0x06535080u && (return_key != 0x065351E0u && return_key != 0x06539AE0u))) && ((return_key != 0x065434C8u && (return_key != 0x06545868u && return_key != 0x06545E28u)) && (return_key != 0x06546DC8u && (return_key != 0x06549BD0u && return_key != 0x0654BE00u)))) && (((return_key != 0x0654CD48u && (return_key != 0x0654DE48u && return_key != 0x06583038u)) && (return_key != 0x0660DCA8u && (return_key != 0x0660DD98u && return_key != 0x06610078u))) && ((return_key != 0x066107D8u && (return_key != 0x06610980u && return_key != 0x06612918u)) && (return_key != 0x06612A50u && (return_key != 0x06614050u && return_key != 0x06614180u))))))) && ((((((return_key != 0x06616350u && return_key != 0x06616480u) && (return_key != 0x06616D40u && (return_key != 0x06617658u && return_key != 0x06618C80u))) && ((return_key != 0x0661A380u && (return_key != 0x0661B0F0u && return_key != 0x0661B1B0u)) && (return_key != 0x06633C98u && (return_key != 0x066800A0u && return_key != 0x06680EB8u)))) && (((return_key != 0x06683E00u && (return_key != 0x066849F0u && return_key != 0x066856D0u)) && (return_key != 0x06685AC0u && (return_key != 0x06687018u && return_key != 0x06687230u))) && ((return_key != 0x0668C8C8u && (return_key != 0x0668C950u && return_key != 0x0668E510u)) && (return_key != 0x0668E650u && (return_key != 0x0668E7B0u && return_key != 0x0668E910u))))) && ((((return_key != 0x0668F038u && (return_key != 0x0668F720u && return_key != 0x0668FB58u)) && (return_key != 0x06690608u && (return_key != 0x066906D0u && return_key != 0x06690C88u))) && ((return_key != 0x06691490u && (return_key != 0x06691A28u && return_key != 0x06691F08u)) && (return_key != 0x06692408u && (return_key != 0x06692AC0u && return_key != 0x06692DC8u)))) && (((return_key != 0x06693480u && (return_key != 0x066938F0u && return_key != 0x06693F50u)) && (return_key != 0x066945D0u && (return_key != 0x06694FE0u && return_key != 0x06695C18u))) && ((return_key != 0x06695E78u && (return_key != 0x06695EC0u && return_key != 0x066970F0u)) && (return_key != 0x06697A68u && (return_key != 0x066984C0u && return_key != 0x0669C608u)))))) && (((((return_key != 0x0669C750u && (return_key != 0x0669C888u && return_key != 0x0669C9D0u)) && (return_key != 0x0669E650u && (return_key != 0x0669F818u && return_key != 0x0669FC90u))) && ((return_key != 0x066A0C98u && (return_key != 0x066A5D98u && return_key != 0x066A5FC0u)) && (return_key != 0x066A6238u && (return_key != 0x066A6280u && return_key != 0x066A65B8u)))) && (((return_key != 0x066A67B0u && (return_key != 0x066A67F8u && return_key != 0x066A9C10u)) && (return_key != 0x066A9DF0u && (return_key != 0x066AA150u && return_key != 0x066AA358u))) && ((return_key != 0x066AA598u && (return_key != 0x066AAC70u && return_key != 0x066AAEF8u)) && (return_key != 0x066AB080u && (return_key != 0x066AB2E8u && return_key != 0x066AB898u))))) && ((((return_key != 0x066AEBE0u && (return_key != 0x066AEDF8u && return_key != 0x066B9C38u)) && (return_key != 0x066CF3B8u && (return_key != 0x066CFAE8u && return_key != 0x066D2CD8u))) && ((return_key != 0x066D2FB0u && (return_key != 0x066D3298u && return_key != 0x066D3450u)) && (return_key != 0x066D3690u && (return_key != 0x066D3848u && return_key != 0x066D3A68u)))) && (((return_key != 0x066D6498u && (return_key != 0x066D81A8u && return_key != 0x066E09E8u)) && (return_key != 0x06708480u && (return_key != 0x0670A4C8u && return_key != 0x0670B128u))) && ((return_key != 0x06715160u && (return_key != 0x06717180u && return_key != 0x06717700u)) && (return_key != 0x06717B60u && (return_key != 0x06717F20u && return_key != 0x0671F970u))))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FE390u: {
            static const uint8_t expected_epoch[] = { 0x5Cu, 0x60u, 0xFDu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC72u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD60u;
            if (nh_scpu_expect_next(cpu, 0x060FEB00u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060FE428u: {
            static const uint8_t expected_epoch[] = { 0xD4u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC85u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC87u;
            if (nh_scpu_expect_next(cpu, 0x060FE438u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (6u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE438u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x88u, 0xFBu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC87u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFCu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x8Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB88u;
            if (nh_scpu_expect_next(cpu, 0x060FDC40u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060FE458u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC8Bu,
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
            cpu->pc = 0xFC8Du;
            if (nh_scpu_expect_next(cpu, 0x060FE468u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE468u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC8Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC8Fu;
            if (nh_scpu_expect_next(cpu, 0x060FE478u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE478u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC8Fu,
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
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC91u;
            if (nh_scpu_expect_next(cpu, 0x060FE488u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE488u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC91u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC93u;
            if (nh_scpu_expect_next(cpu, 0x060FE498u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE498u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC93u,
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
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC94u;
            if (nh_scpu_expect_next(cpu, 0x060FE4A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FE4A0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC94u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000006u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000007u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC96u;
            if (nh_scpu_expect_next(cpu, 0x060FE4B0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE4B0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC96u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000006u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000007u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC98u;
            if (nh_scpu_expect_next(cpu, 0x060FE4C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE4C0u: {
            static const uint8_t expected_epoch[] = { 0x30u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC98u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) != 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFC9Bu;
                if (nh_scpu_expect_next(cpu, 0x060FE4D8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC9Au;
            if (nh_scpu_expect_next(cpu, 0x060FE4D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE4D0u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC9Au,
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
            if (((((return_key != 0x06086810u && (return_key != 0x06086F88u && return_key != 0x0608A818u)) && ((return_key != 0x0608A8D0u && return_key != 0x060A5C20u) && (return_key != 0x060A6ED8u && return_key != 0x060AEFE8u))) && ((return_key != 0x060AF6D8u && (return_key != 0x0610FE08u && return_key != 0x061103E0u)) && ((return_key != 0x0628F638u && return_key != 0x06331428u) && (return_key != 0x0634A938u && return_key != 0x063B9AE8u)))) && (((return_key != 0x063D5C60u && (return_key != 0x063D5D18u && return_key != 0x065374C8u)) && ((return_key != 0x0653AEA8u && return_key != 0x0654B2C8u) && (return_key != 0x06621808u && return_key != 0x06621C80u))) && (((return_key != 0x066228C0u && return_key != 0x06622E00u) && (return_key != 0x06623340u && return_key != 0x06628870u)) && ((return_key != 0x0662AE00u && return_key != 0x0665B598u) && (return_key != 0x0665FDD8u && return_key != 0x066671F0u))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FE4D8u: {
            static const uint8_t expected_epoch[] = { 0x5Cu, 0x69u, 0xFDu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC9Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD69u;
            if (nh_scpu_expect_next(cpu, 0x060FEB48u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060FE4F8u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FC9Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCA0u;
            if (nh_scpu_expect_next(cpu, 0x060FE500u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE500u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCA0u,
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
            cpu->pc = 0xFCA2u;
            if (nh_scpu_expect_next(cpu, 0x060FE510u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE510u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCA2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint16_t right, result;
            const uint16_t left = cpu->a;
            uint32_t sum;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
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
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCA4u;
            if (nh_scpu_expect_next(cpu, 0x060FE520u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE520u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCA4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCA6u;
            if (nh_scpu_expect_next(cpu, 0x060FE530u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE530u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCA6u,
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
            if ((((((return_key != 0x060D6E80u && (return_key != 0x060F3C60u && return_key != 0x060F3DA8u)) && (return_key != 0x06106170u && (return_key != 0x06106370u && return_key != 0x061B71E8u))) && ((return_key != 0x061C21B0u && (return_key != 0x061C24C8u && return_key != 0x06200C28u)) && (return_key != 0x06200D28u && (return_key != 0x06234AC0u && return_key != 0x06234CF8u)))) && (((return_key != 0x06234FF8u && (return_key != 0x062BDF38u && return_key != 0x06344DD8u)) && (return_key != 0x06346150u && (return_key != 0x063B4630u && return_key != 0x063BF908u))) && ((return_key != 0x063C2658u && (return_key != 0x063C2888u && return_key != 0x063C4E70u)) && ((return_key != 0x063C6378u && return_key != 0x063CC698u) && (return_key != 0x063CD0D8u && return_key != 0x0641CC48u))))) && ((((return_key != 0x06420500u && (return_key != 0x06421118u && return_key != 0x06481B70u)) && (return_key != 0x06489488u && (return_key != 0x06492158u && return_key != 0x064923C0u))) && ((return_key != 0x064927C8u && (return_key != 0x06494620u && return_key != 0x06494A88u)) && (return_key != 0x064A4188u && (return_key != 0x064C9660u && return_key != 0x06514478u)))) && (((return_key != 0x065156C8u && (return_key != 0x06516228u && return_key != 0x065163A8u)) && (return_key != 0x065198E0u && (return_key != 0x0651C5C8u && return_key != 0x0651DBF0u))) && ((return_key != 0x0651FA78u && (return_key != 0x0652A490u && return_key != 0x0652AF40u)) && ((return_key != 0x0661C598u && return_key != 0x066C2008u) && (return_key != 0x0671F2D0u && return_key != 0x0671FED0u)))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FE538u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCA7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCA8u;
            if (nh_scpu_expect_next(cpu, 0x060FE540u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE540u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCA8u,
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
            cpu->pc = 0xFCAAu;
            if (nh_scpu_expect_next(cpu, 0x060FE550u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE550u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCAAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint16_t right, result;
            const uint16_t left = cpu->a;
            uint32_t sum;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
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
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCACu;
            if (nh_scpu_expect_next(cpu, 0x060FE560u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE560u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCACu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCAEu;
            if (nh_scpu_expect_next(cpu, 0x060FE570u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE570u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCAEu,
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
            cpu->pc = 0xFCB0u;
            if (nh_scpu_expect_next(cpu, 0x060FE580u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE580u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCB0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint16_t right, result;
            const uint16_t left = cpu->a;
            uint32_t sum;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000006u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000007u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
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
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCB2u;
            if (nh_scpu_expect_next(cpu, 0x060FE590u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE590u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCB2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCB4u;
            if (nh_scpu_expect_next(cpu, 0x060FE5A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE5A0u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCB4u,
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
            if ((((((((((return_key != 0x06086A08u && return_key != 0x06087180u) && (return_key != 0x06087360u && (return_key != 0x06087498u && return_key != 0x06087570u))) && ((return_key != 0x06087760u && (return_key != 0x060887C0u && return_key != 0x06088BD8u)) && (return_key != 0x06088D50u && (return_key != 0x06088E30u && return_key != 0x06088F68u)))) && (((return_key != 0x060891F8u && return_key != 0x06089370u) && (return_key != 0x06089450u && (return_key != 0x06089588u && return_key != 0x0608BDF0u))) && ((return_key != 0x0608C300u && (return_key != 0x0608D8D8u && return_key != 0x06090DF8u)) && (return_key != 0x06091248u && (return_key != 0x06093A70u && return_key != 0x06093EC0u))))) && ((((return_key != 0x06095728u && return_key != 0x06096380u) && (return_key != 0x06097EF8u && (return_key != 0x06098448u && return_key != 0x06098E60u))) && ((return_key != 0x06099160u && (return_key != 0x060994E8u && return_key != 0x06099710u)) && (return_key != 0x06099B78u && (return_key != 0x0609B3D8u && return_key != 0x0609C0F8u)))) && (((return_key != 0x0609E258u && return_key != 0x0609F628u) && (return_key != 0x060A06D8u && (return_key != 0x060A3948u && return_key != 0x060A5418u))) && ((return_key != 0x060A7C18u && (return_key != 0x060AC2C8u && return_key != 0x060AC538u)) && (return_key != 0x060AD8A8u && (return_key != 0x060ADA48u && return_key != 0x060ADD30u)))))) && (((((return_key != 0x060ADED0u && return_key != 0x060AE0E8u) && (return_key != 0x060B1328u && (return_key != 0x060B14C0u && return_key != 0x060B16B8u))) && ((return_key != 0x060B18D0u && (return_key != 0x060B2308u && return_key != 0x060B46A8u)) && (return_key != 0x060B4D48u && (return_key != 0x060BB5B8u && return_key != 0x060BBDA8u)))) && (((return_key != 0x060BC458u && return_key != 0x060BC7C0u) && (return_key != 0x060C6C18u && (return_key != 0x060C6DC8u && return_key != 0x060C6FD8u))) && ((return_key != 0x060C7188u && (return_key != 0x060C7338u && return_key != 0x060C74D0u)) && (return_key != 0x060C7D18u && (return_key != 0x060C8658u && return_key != 0x060C8C28u))))) && ((((return_key != 0x060C90D0u && return_key != 0x060C93E8u) && (return_key != 0x060CB2E0u && (return_key != 0x060CB4E0u && return_key != 0x060CB740u))) && ((return_key != 0x060CF4D0u && (return_key != 0x060CF7E8u && return_key != 0x060D0150u)) && (return_key != 0x060D0B28u && (return_key != 0x060D15E0u && return_key != 0x060D2438u)))) && (((return_key != 0x060D40E8u && return_key != 0x060D42D8u) && (return_key != 0x060D5198u && (return_key != 0x060D5BB8u && return_key != 0x060D5FE0u))) && ((return_key != 0x060D7298u && (return_key != 0x060D74A8u && return_key != 0x060D8100u)) && (return_key != 0x060D9BF0u && (return_key != 0x060EF6A0u && return_key != 0x060F00D0u))))))) && ((((((return_key != 0x060F08C0u && return_key != 0x06102398u) && (return_key != 0x061023E8u && (return_key != 0x061123C8u && return_key != 0x061127C8u))) && ((return_key != 0x06112BB0u && (return_key != 0x061130C8u && return_key != 0x06114FD0u)) && (return_key != 0x061154C0u && (return_key != 0x061177D0u && return_key != 0x0611A128u)))) && (((return_key != 0x0611A528u && return_key != 0x0611C838u) && (return_key != 0x0611D760u && (return_key != 0x06121CE0u && return_key != 0x06122708u))) && ((return_key != 0x061244E8u && (return_key != 0x06133830u && return_key != 0x06133880u)) && (return_key != 0x06133F18u && (return_key != 0x06133F68u && return_key != 0x061446F8u))))) && ((((return_key != 0x06180F28u && return_key != 0x06188C80u) && (return_key != 0x0618FE00u && (return_key != 0x061A5720u && return_key != 0x061B2760u))) && ((return_key != 0x061B35F0u && (return_key != 0x061B4350u && return_key != 0x061BC038u)) && (return_key != 0x061BD370u && (return_key != 0x061BD858u && return_key != 0x061D4250u)))) && (((return_key != 0x061D5118u && return_key != 0x061D5480u) && (return_key != 0x061D5A30u && (return_key != 0x061D5E40u && return_key != 0x061D6020u))) && ((return_key != 0x061D62F8u && (return_key != 0x061D6450u && return_key != 0x061D6CA8u)) && (return_key != 0x061D7160u && (return_key != 0x061D7570u && return_key != 0x061D7750u)))))) && (((((return_key != 0x061D7A28u && return_key != 0x061D7B80u) && (return_key != 0x061D8138u && (return_key != 0x061D8568u && return_key != 0x061D88B8u))) && ((return_key != 0x061D8A28u && (return_key != 0x061D8B80u && return_key != 0x061D8E00u)) && (return_key != 0x061D8F58u && (return_key != 0x061D90D0u && return_key != 0x061D9368u)))) && (((return_key != 0x061D94D0u && return_key != 0x061D95E0u) && (return_key != 0x061D9738u && (return_key != 0x061D9960u && return_key != 0x061D9AB8u))) && ((return_key != 0x061DECA0u && (return_key != 0x061E1AF8u && return_key != 0x061E3D08u)) && (return_key != 0x061E4B70u && (return_key != 0x06201248u && return_key != 0x06201C80u))))) && ((((return_key != 0x06202098u && return_key != 0x0620EE30u) && (return_key != 0x0620F068u && (return_key != 0x0620F1F0u && return_key != 0x06214710u))) && ((return_key != 0x06214BC8u && (return_key != 0x06214FC0u && return_key != 0x06215480u)) && (return_key != 0x062157C0u && (return_key != 0x06215BD0u && return_key != 0x06216608u)))) && (((return_key != 0x0621DF88u && return_key != 0x0621E3B0u) && (return_key != 0x0621F480u && (return_key != 0x0621FB28u && return_key != 0x0621FDE8u))) && ((return_key != 0x062201F0u && (return_key != 0x062207E0u && return_key != 0x06220DC0u)) && (return_key != 0x062211D0u && (return_key != 0x06222358u && return_key != 0x06222728u)))))))) && (((((((return_key != 0x06222B20u && return_key != 0x06222FA0u) && (return_key != 0x062233E0u && (return_key != 0x06223800u && return_key != 0x06223E00u))) && ((return_key != 0x06224608u && (return_key != 0x06225338u && return_key != 0x06225600u)) && (return_key != 0x06227B60u && (return_key != 0x0622B6B0u && return_key != 0x0623B290u)))) && (((return_key != 0x0623B810u && return_key != 0x0623C888u) && (return_key != 0x0623C908u && (return_key != 0x06240300u && return_key != 0x062404B0u))) && ((return_key != 0x06240730u && (return_key != 0x062408E0u && return_key != 0x06240CD0u)) && (return_key != 0x06241D50u && (return_key != 0x06241E68u && return_key != 0x06242070u))))) && ((((return_key != 0x062421E0u && return_key != 0x06242340u) && (return_key != 0x06242488u && (return_key != 0x06280300u && return_key != 0x0628DC80u))) && ((return_key != 0x062925D8u && (return_key != 0x062955F0u && return_key != 0x06295788u)) && (return_key != 0x06295AC8u && (return_key != 0x06299AD8u && return_key != 0x0629FA00u)))) && (((return_key != 0x0629FC70u && return_key != 0x0629FEE0u) && (return_key != 0x062A1F18u && (return_key != 0x062A25E8u && return_key != 0x062A7210u))) && ((return_key != 0x062A7920u && (return_key != 0x062A8EB0u && return_key != 0x062A9048u)) && (return_key != 0x062A9A90u && (return_key != 0x062A9C28u && return_key != 0x062A9F68u)))))) && (((((return_key != 0x062AAC98u && return_key != 0x062ABFA0u) && (return_key != 0x062AC2F8u && (return_key != 0x062AC5C8u && return_key != 0x062BCB80u))) && ((return_key != 0x062BCF58u && (return_key != 0x062BDCC0u && return_key != 0x062C0F88u)) && (return_key != 0x062C10D0u && (return_key != 0x062C1220u && return_key != 0x062C13F0u)))) && (((return_key != 0x062C1540u && return_key != 0x062C18E0u) && (return_key != 0x062C1A00u && (return_key != 0x062C1B28u && return_key != 0x062C1D30u))) && ((return_key != 0x062C2248u && (return_key != 0x062C2348u && return_key != 0x062C25C8u)) && (return_key != 0x062C4028u && (return_key != 0x062C4228u && return_key != 0x062C42F0u))))) && ((((return_key != 0x062C4508u && return_key != 0x062C45D0u) && (return_key != 0x062C4748u && (return_key != 0x062C4828u && return_key != 0x062C49A0u))) && ((return_key != 0x062C5170u && (return_key != 0x062C5388u && return_key != 0x062C55C8u)) && (return_key != 0x062C6008u && (return_key != 0x062C61B8u && return_key != 0x062C6380u)))) && (((return_key != 0x062C64E0u && return_key != 0x062C67A0u) && (return_key != 0x062C6900u && (return_key != 0x062C6AC8u && return_key != 0x062C6E38u))) && ((return_key != 0x062C74E0u && (return_key != 0x062C7678u && return_key != 0x062C7A00u)) && (return_key != 0x062C7BF8u && (return_key != 0x062C7E00u && return_key != 0x062C8088u))))))) && ((((((return_key != 0x062C81E0u && return_key != 0x062C8CE8u) && (return_key != 0x062C8E48u && (return_key != 0x062C8F40u && return_key != 0x062C90E0u))) && ((return_key != 0x062C91C0u && (return_key != 0x062C9340u && return_key != 0x062C9460u)) && (return_key != 0x062C95D0u && (return_key != 0x062CA870u && return_key != 0x062D7918u)))) && (((return_key != 0x062D7A30u && return_key != 0x062D7FF0u) && (return_key != 0x062D8530u && (return_key != 0x062D91D0u && return_key != 0x062D9328u))) && ((return_key != 0x062D96E8u && (return_key != 0x062D9900u && return_key != 0x062D9B28u)) && (return_key != 0x062D9D40u && (return_key != 0x062D9E58u && return_key != 0x062DB7F8u))))) && ((((return_key != 0x062DB940u && return_key != 0x062DBA58u) && (return_key != 0x062DBB80u && (return_key != 0x062DBC70u && return_key != 0x062DBE88u))) && ((return_key != 0x062DBFA0u && (return_key != 0x062DC0C8u && return_key != 0x062DC1E0u)) && (return_key != 0x062DC2E0u && (return_key != 0x062DC3F8u && return_key != 0x062DC710u)))) && (((return_key != 0x062DC898u && return_key != 0x062DCAF8u) && (return_key != 0x062DCD18u && (return_key != 0x062DD698u && return_key != 0x062DD8A8u))) && ((return_key != 0x062DF780u && (return_key != 0x06300EB8u && return_key != 0x06300FC0u)) && (return_key != 0x06309E10u && (return_key != 0x0630D3A0u && return_key != 0x0630D670u)))))) && (((((return_key != 0x06315110u && return_key != 0x06315360u) && (return_key != 0x063155F8u && (return_key != 0x06315758u && return_key != 0x06315948u))) && ((return_key != 0x06315AA8u && (return_key != 0x06315C08u && return_key != 0x06315D68u)) && (return_key != 0x06315F58u && (return_key != 0x063160B8u && return_key != 0x06316308u)))) && (((return_key != 0x06316608u && return_key != 0x06316830u) && (return_key != 0x06316A48u && (return_key != 0x0631AEC0u && return_key != 0x0631B628u))) && ((return_key != 0x0631BC90u && (return_key != 0x0631DA58u && return_key != 0x0631DB90u)) && (return_key != 0x0631E9A0u && (return_key != 0x0631F2E8u && return_key != 0x06320550u))))) && ((((return_key != 0x06320B20u && return_key != 0x06322358u) && (return_key != 0x063226A0u && (return_key != 0x063228A0u && return_key != 0x06322D78u))) && ((return_key != 0x06322F60u && (return_key != 0x063238D8u && return_key != 0x06323C20u)) && (return_key != 0x06323E20u && (return_key != 0x0632A270u && return_key != 0x0632B230u)))) && (((return_key != 0x0632B4D0u && return_key != 0x0632B618u) && (return_key != 0x0632B7D8u && (return_key != 0x0632B920u && return_key != 0x0632BAE0u))) && ((return_key != 0x0632BC28u && (return_key != 0x0632BF60u && return_key != 0x0632C060u)) && (return_key != 0x06330F18u && (return_key != 0x06331058u && return_key != 0x063337D0u))))))))) && ((((((((return_key != 0x06333940u && return_key != 0x06333AA0u) && (return_key != 0x06333BA0u && (return_key != 0x06333CE8u && return_key != 0x06333DE8u))) && ((return_key != 0x06334998u && (return_key != 0x06334BD8u && return_key != 0x06334ED8u)) && (return_key != 0x063351F0u && (return_key != 0x06335300u && return_key != 0x06335568u)))) && (((return_key != 0x063356D8u && return_key != 0x06335838u) && (return_key != 0x06335938u && (return_key != 0x06335A80u && return_key != 0x06335B80u))) && ((return_key != 0x06337550u && (return_key != 0x06337E48u && return_key != 0x06338010u)) && (return_key != 0x06338130u && (return_key != 0x06338308u && return_key != 0x06338650u))))) && ((((return_key != 0x06338818u && return_key != 0x06339430u) && (return_key != 0x06339508u && (return_key != 0x06339678u && return_key != 0x06339840u))) && ((return_key != 0x0633B390u && (return_key != 0x06345980u && return_key != 0x0634D4E0u)) && (return_key != 0x0634D7E0u && (return_key != 0x0638D380u && return_key != 0x0638ED00u)))) && (((return_key != 0x0638FD18u && return_key != 0x06391670u) && (return_key != 0x063948B0u && (return_key != 0x06396B88u && return_key != 0x0639A9C0u))) && ((return_key != 0x0639F0B8u && (return_key != 0x063A2548u && return_key != 0x063A2720u)) && (return_key != 0x063A4128u && (return_key != 0x063A4340u && return_key != 0x063A44B8u)))))) && (((((return_key != 0x063A4710u && return_key != 0x063A4898u) && (return_key != 0x063A5258u && (return_key != 0x063AEF40u && return_key != 0x063AF230u))) && ((return_key != 0x063AF360u && (return_key != 0x063B0B98u && return_key != 0x063B4DE0u)) && (return_key != 0x063B4FE8u && (return_key != 0x063B72D0u && return_key != 0x063B8388u)))) && (((return_key != 0x063BB4B8u && return_key != 0x063BB840u) && (return_key != 0x063C7AA0u && (return_key != 0x063C7D58u && return_key != 0x063CDC08u))) && ((return_key != 0x063CEC60u && (return_key != 0x063CEF18u && return_key != 0x063CF1D0u)) && (return_key != 0x063CF488u && (return_key != 0x063CFBE0u && return_key != 0x063CFD58u))))) && ((((return_key != 0x063D0028u && return_key != 0x063D4610u) && (return_key != 0x063D4C08u && (return_key != 0x063E0660u && return_key != 0x063E13F0u))) && ((return_key != 0x063E1510u && (return_key != 0x063E1C90u && return_key != 0x063E2A20u)) && (return_key != 0x063E2B40u && (return_key != 0x063ED798u && return_key != 0x063EDAE8u)))) && (((return_key != 0x063EDE48u && return_key != 0x063EE138u) && (return_key != 0x063EED30u && (return_key != 0x063EF290u && return_key != 0x063EF608u))) && ((return_key != 0x06408280u && (return_key != 0x064084B8u && return_key != 0x06408650u)) && (return_key != 0x064088A0u && (return_key != 0x064089D0u && return_key != 0x06408B80u))))))) && ((((((return_key != 0x06408CC8u && return_key != 0x06408E78u) && (return_key != 0x06409250u && (return_key != 0x064094B8u && return_key != 0x064143F0u))) && ((return_key != 0x06427250u && (return_key != 0x06427340u && return_key != 0x064277C8u)) && (return_key != 0x0642BDB0u && (return_key != 0x0642BF10u && return_key != 0x06433A38u)))) && (((return_key != 0x06433B98u && return_key != 0x06435F08u) && (return_key != 0x064370D0u && (return_key != 0x06437250u && return_key != 0x064801E0u))) && ((return_key != 0x06480358u && (return_key != 0x06482228u && return_key != 0x06482578u)) && (return_key != 0x06482D08u && (return_key != 0x06482F10u && return_key != 0x06487E88u))))) && ((((return_key != 0x06487ED8u && return_key != 0x0648BD20u) && (return_key != 0x0648CBD8u && (return_key != 0x0648DA58u && return_key != 0x0649B258u))) && ((return_key != 0x0649C448u && (return_key != 0x0649C7D0u && return_key != 0x0649FB88u)) && (return_key != 0x064A0CD8u && (return_key != 0x064A0DB0u && return_key != 0x064A0EE0u)))) && (((return_key != 0x064A0FE0u && return_key != 0x064A1170u) && (return_key != 0x064A1270u && (return_key != 0x064A1370u && return_key != 0x064AC530u))) && ((return_key != 0x064ACBF0u && (return_key != 0x064B3AE8u && return_key != 0x064B49B0u)) && (return_key != 0x064B5698u && (return_key != 0x064B6180u && return_key != 0x064B7AE8u)))))) && (((((return_key != 0x064B8D00u && return_key != 0x064BEBC0u) && (return_key != 0x064C0A08u && (return_key != 0x064C0C70u && return_key != 0x064C0DF8u))) && ((return_key != 0x064C1E78u && (return_key != 0x064C2000u && return_key != 0x064C2168u)) && (return_key != 0x064C2CB8u && (return_key != 0x064C2FD8u && return_key != 0x064C3488u)))) && (((return_key != 0x064C3980u && return_key != 0x064C3BA8u) && (return_key != 0x064C4390u && (return_key != 0x064C4718u && return_key != 0x064C4A70u))) && ((return_key != 0x064C4C08u && (return_key != 0x064C5070u && return_key != 0x064C51E0u)) && (return_key != 0x064C5500u && (return_key != 0x064C5688u && return_key != 0x064C5B90u))))) && ((((return_key != 0x064C9D50u && return_key != 0x064CA0E0u) && (return_key != 0x064CA3E8u && (return_key != 0x064CA650u && return_key != 0x064CAC28u))) && ((return_key != 0x064CAC88u && (return_key != 0x064CCDA0u && return_key != 0x064CD4C8u)) && (return_key != 0x064CE938u && (return_key != 0x064CEC60u && return_key != 0x064CEFF0u)))) && (((return_key != 0x064CF168u && return_key != 0x064CF2E0u) && (return_key != 0x064CF7A0u && (return_key != 0x064CFFC8u && return_key != 0x064D00A0u))) && ((return_key != 0x064D02D8u && (return_key != 0x064D0368u && return_key != 0x064D0620u)) && (return_key != 0x064D07A0u && (return_key != 0x064D0900u && return_key != 0x064D0E60u)))))))) && (((((((return_key != 0x064D0FE0u && return_key != 0x064D21A0u) && (return_key != 0x064D2700u && (return_key != 0x064D28C8u && return_key != 0x064D2A90u))) && ((return_key != 0x064D2C58u && (return_key != 0x064D2E20u && return_key != 0x064D2FE8u)) && (return_key != 0x064D3240u && (return_key != 0x064D3FF0u && return_key != 0x064D42A8u)))) && (((return_key != 0x064D62E0u && return_key != 0x064D6680u) && (return_key != 0x064D7F18u && (return_key != 0x064D84D8u && return_key != 0x064D87A8u))) && ((return_key != 0x064F5A10u && (return_key != 0x065037E0u && return_key != 0x06503B68u)) && (return_key != 0x06504280u && (return_key != 0x06504600u && return_key != 0x06504B78u))))) && ((((return_key != 0x06505180u && return_key != 0x06505818u) && (return_key != 0x06505FE8u && (return_key != 0x06507B50u && return_key != 0x06507F58u))) && ((return_key != 0x06509E10u && (return_key != 0x0650A770u && return_key != 0x0650AEC0u)) && (return_key != 0x0650B748u && (return_key != 0x06513470u && return_key != 0x06514790u)))) && (((return_key != 0x06514B20u && return_key != 0x06514D60u) && (return_key != 0x06515420u && (return_key != 0x065159E0u && return_key != 0x06515B60u))) && ((return_key != 0x06515CB8u && (return_key != 0x06516158u && return_key != 0x06516F98u)) && (return_key != 0x06518250u && (return_key != 0x065183E0u && return_key != 0x065185E8u)))))) && (((((return_key != 0x06518778u && return_key != 0x06518928u) && (return_key != 0x06518B98u && (return_key != 0x06518E60u && return_key != 0x06519010u))) && ((return_key != 0x06519BF8u && (return_key != 0x06519F08u && return_key != 0x0651A1E0u)) && (return_key != 0x0651AEB0u && (return_key != 0x0651B108u && return_key != 0x0651B500u)))) && (((return_key != 0x0651B678u && return_key != 0x0651B850u) && (return_key != 0x0651B9A8u && (return_key != 0x0651C3E8u && return_key != 0x0651D350u))) && ((return_key != 0x0651E1B0u && (return_key != 0x0651E4D8u && return_key != 0x0651EC90u)) && (return_key != 0x0651EE60u && (return_key != 0x0651FE90u && return_key != 0x06521CF0u))))) && ((((return_key != 0x06521E48u && return_key != 0x0652D160u) && (return_key != 0x0652D348u && (return_key != 0x0652D838u && return_key != 0x06532FA8u))) && ((return_key != 0x06534E50u && (return_key != 0x06535780u && return_key != 0x06608028u)) && (return_key != 0x06608330u && (return_key != 0x06608698u && return_key != 0x06608A28u)))) && (((return_key != 0x06608D30u && return_key != 0x06609098u) && (return_key != 0x066097A8u && (return_key != 0x066099E8u && return_key != 0x06609C08u))) && ((return_key != 0x0660B190u && (return_key != 0x0660BDF0u && return_key != 0x0660C800u)) && (return_key != 0x0660E170u && (return_key != 0x0660E3B8u && return_key != 0x0660E928u))))))) && ((((((return_key != 0x0660EA88u && return_key != 0x0660EE58u) && (return_key != 0x0660F7C0u && (return_key != 0x0660FA78u && return_key != 0x066110B0u))) && ((return_key != 0x06611668u && (return_key != 0x06611980u && return_key != 0x06611BF8u)) && (return_key != 0x06611D30u && (return_key != 0x066136D8u && return_key != 0x06613868u)))) && (((return_key != 0x066172E8u && return_key != 0x06617808u) && (return_key != 0x06617DB8u && (return_key != 0x06618020u && return_key != 0x0661A548u))) && ((return_key != 0x06621438u && (return_key != 0x066224F0u && return_key != 0x06636300u)) && (return_key != 0x06637320u && (return_key != 0x06681E68u && return_key != 0x066862C0u))))) && ((((return_key != 0x066864A8u && return_key != 0x06689F30u) && (return_key != 0x0668CE38u && (return_key != 0x066961E0u && return_key != 0x06696468u))) && ((return_key != 0x0669FDB8u && (return_key != 0x066A05F8u && return_key != 0x066A07B0u)) && (return_key != 0x066A0908u && (return_key != 0x066A0A60u && return_key != 0x066A1250u)))) && (((return_key != 0x066A16E8u && return_key != 0x066A1A00u) && (return_key != 0x066A1DB0u && (return_key != 0x066A20C8u && return_key != 0x066A2498u))) && ((return_key != 0x066A27B0u && (return_key != 0x066A2AE8u && return_key != 0x066A2E00u)) && (return_key != 0x066A33C0u && (return_key != 0x066ADAE0u && return_key != 0x066AE918u)))))) && (((((return_key != 0x066B26E0u && return_key != 0x066B2BA0u) && (return_key != 0x066B3628u && (return_key != 0x066B3A18u && return_key != 0x066B3BD0u))) && ((return_key != 0x066B42A8u && (return_key != 0x066B4498u && return_key != 0x066B4900u)) && (return_key != 0x066B4AF8u && (return_key != 0x066B6B90u && return_key != 0x066C4068u)))) && (((return_key != 0x066C4378u && return_key != 0x066C8E08u) && (return_key != 0x066C8FB8u && (return_key != 0x066C91B0u && return_key != 0x066C93D0u))) && ((return_key != 0x066C9580u && (return_key != 0x066C9778u && return_key != 0x066DAAB8u)) && (return_key != 0x066DC628u && (return_key != 0x066E42E0u && return_key != 0x066E4468u))))) && ((((return_key != 0x0670EEF8u && return_key != 0x0670F498u) && (return_key != 0x0670F658u && (return_key != 0x067139C0u && return_key != 0x06713BF0u))) && ((return_key != 0x067147D0u && (return_key != 0x06714A00u && return_key != 0x06714DA8u)) && (return_key != 0x06714FD8u && (return_key != 0x06715F50u && return_key != 0x06716108u)))) && (((return_key != 0x06716330u && (return_key != 0x067164A0u && return_key != 0x06717370u)) && (return_key != 0x06717430u && (return_key != 0x06717860u && return_key != 0x06718080u))) && ((return_key != 0x067184A0u && (return_key != 0x06718870u && return_key != 0x06718AA0u)) && (return_key != 0x0671AC50u && (return_key != 0x06721530u && return_key != 0x06726258u)))))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FE5A8u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCB5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCB6u;
            if (nh_scpu_expect_next(cpu, 0x060FE5B0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE5B0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCB6u,
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
            cpu->pc = 0xFCB8u;
            if (nh_scpu_expect_next(cpu, 0x060FE5C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE5C0u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCB8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t left = cpu->a;
            const uint16_t right = value;
            const uint32_t borrow = ((cpu->p & NH_P_C) != 0u) ? 0u : 1u;
            const uint16_t result = (uint16_t)((uint32_t)left - (uint32_t)right - borrow);
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if ((uint32_t)left >= (uint32_t)right + borrow) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            if (((uint16_t)(left ^ right) & (uint16_t)(left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCBAu;
            if (nh_scpu_expect_next(cpu, 0x060FE5D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE5D0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCBAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCBCu;
            if (nh_scpu_expect_next(cpu, 0x060FE5E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE5E0u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCBCu,
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
            if (((((((return_key != 0x060D49C0u && return_key != 0x060D5E88u) && (return_key != 0x060F39E8u && return_key != 0x060F3AD0u)) && ((return_key != 0x06196EE8u && return_key != 0x06197900u) && (return_key != 0x06198090u && return_key != 0x06198330u))) && (((return_key != 0x061A0D00u && return_key != 0x061A0EF0u) && (return_key != 0x061A10E0u && return_key != 0x061ADB58u)) && ((return_key != 0x061AE268u && return_key != 0x061AE940u) && (return_key != 0x061AF078u && return_key != 0x06300440u)))) && ((((return_key != 0x06324DE0u && return_key != 0x06342970u) && (return_key != 0x063BFB00u && return_key != 0x063C86D8u)) && ((return_key != 0x063F7398u && return_key != 0x06401320u) && (return_key != 0x06403198u && return_key != 0x06414A70u))) && (((return_key != 0x06414B48u && return_key != 0x06414C38u) && (return_key != 0x06420FE0u && return_key != 0x064210C0u)) && ((return_key != 0x064222E0u && return_key != 0x064944A0u) && (return_key != 0x064948E0u && (return_key != 0x06497618u && return_key != 0x064A3090u)))))) && (((((return_key != 0x064A5148u && return_key != 0x064A5998u) && (return_key != 0x064DF770u && return_key != 0x064DF860u)) && ((return_key != 0x064DF950u && return_key != 0x064E1A38u) && (return_key != 0x064E1B48u && return_key != 0x064E1C58u))) && (((return_key != 0x064E3E78u && return_key != 0x064E3F68u) && (return_key != 0x064E4058u && return_key != 0x064E5FC0u)) && ((return_key != 0x064E60B0u && return_key != 0x064E61A0u) && (return_key != 0x064E7450u && (return_key != 0x064E7920u && return_key != 0x064E7DF8u))))) && ((((return_key != 0x064F12C8u && return_key != 0x064F14A8u) && (return_key != 0x06514F00u && return_key != 0x0651A380u)) && ((return_key != 0x0651E8C0u && return_key != 0x065233D0u) && (return_key != 0x06524BA8u && return_key != 0x06524E60u))) && (((return_key != 0x065450B8u && return_key != 0x06545278u) && (return_key != 0x066BD528u && return_key != 0x066C2988u)) && ((return_key != 0x066C3A18u && return_key != 0x0671E4D0u) && (return_key != 0x0671EA40u && (return_key != 0x0671FD98u && return_key != 0x0671FE78u))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FE5E8u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCBDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCBEu;
            if (nh_scpu_expect_next(cpu, 0x060FE5F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE5F0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCBEu,
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
            cpu->pc = 0xFCC0u;
            if (nh_scpu_expect_next(cpu, 0x060FE600u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE600u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCC0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t left = cpu->a;
            const uint16_t right = value;
            const uint32_t borrow = ((cpu->p & NH_P_C) != 0u) ? 0u : 1u;
            const uint16_t result = (uint16_t)((uint32_t)left - (uint32_t)right - borrow);
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if ((uint32_t)left >= (uint32_t)right + borrow) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            if (((uint16_t)(left ^ right) & (uint16_t)(left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCC2u;
            if (nh_scpu_expect_next(cpu, 0x060FE610u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE610u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCC2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCC4u;
            if (nh_scpu_expect_next(cpu, 0x060FE620u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE620u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCC4u,
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
            cpu->pc = 0xFCC6u;
            if (nh_scpu_expect_next(cpu, 0x060FE630u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE630u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCC6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000006u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000007u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t left = cpu->a;
            const uint16_t right = value;
            const uint32_t borrow = ((cpu->p & NH_P_C) != 0u) ? 0u : 1u;
            const uint16_t result = (uint16_t)((uint32_t)left - (uint32_t)right - borrow);
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if ((uint32_t)left >= (uint32_t)right + borrow) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            if (((uint16_t)(left ^ right) & (uint16_t)(left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCC8u;
            if (nh_scpu_expect_next(cpu, 0x060FE640u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE640u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCC8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCCAu;
            if (nh_scpu_expect_next(cpu, 0x060FE650u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE650u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCCAu,
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
            if (((return_key != 0x0608C650u && return_key != 0x0608CB60u) && (return_key != 0x0608DC28u && (return_key != 0x0608E0E8u && return_key != 0x0608E4B0u))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FE658u: {
            static const uint8_t expected_epoch[] = { 0xC6u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCCBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t result = (uint16_t)(value - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCCDu;
            if (nh_scpu_expect_next(cpu, 0x060FE668u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE668u: {
            static const uint8_t expected_epoch[] = { 0x10u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCCDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFCD0u;
                if (nh_scpu_expect_next(cpu, 0x060FE680u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCCFu;
            if (nh_scpu_expect_next(cpu, 0x060FE678u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE678u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCCFu,
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
            if (((((return_key != 0x06113C40u && return_key != 0x06113D88u) && (return_key != 0x0612D520u && (return_key != 0x0612E810u && return_key != 0x06132160u))) && ((return_key != 0x06136F50u && (return_key != 0x061CEA28u && return_key != 0x0638EA98u)) && (return_key != 0x063908C0u && (return_key != 0x06394668u && return_key != 0x06394FB0u)))) && (((return_key != 0x06395E20u && return_key != 0x064C4230u) && (return_key != 0x064C45B8u && (return_key != 0x064D0A20u && return_key != 0x064D10F8u))) && ((return_key != 0x064D54D0u && (return_key != 0x064D6400u && return_key != 0x064D67A0u)) && (return_key != 0x066176C0u && (return_key != 0x066A4C10u && return_key != 0x066A4CD0u))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FE680u: {
            static const uint8_t expected_epoch[] = { 0x06u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCD0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t old = (uint16_t)(low | ((uint16_t)high << 8u));
            const uint16_t result = (uint16_t)(((uint32_t)old << 1u) | 0u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | ((old >> 15u) & 1u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCD2u;
            if (nh_scpu_expect_next(cpu, 0x060FE690u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE690u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0xF7u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCD2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCCBu;
            if (nh_scpu_expect_next(cpu, 0x060FE658u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FE6A0u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCD4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCD5u;
            if (nh_scpu_expect_next(cpu, 0x060FE6A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE6A8u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCD5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCD7u;
            if (nh_scpu_expect_next(cpu, 0x060FE6B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE6B8u: {
            static const uint8_t expected_epoch[] = { 0xE9u, 0x01u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCD7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0001u;
            const uint32_t borrow = (cpu->p & NH_P_C) != 0u ? 0u : 1u;
            const uint16_t result = (uint16_t)((uint32_t)left - (uint32_t)right - borrow);
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if ((uint32_t)left >= (uint32_t)right + borrow) cpu->p |= NH_P_C;
            if (((left ^ right) & (left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCDAu;
            if (nh_scpu_expect_next(cpu, 0x060FE6D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FE6D0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCDAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCDCu;
            if (nh_scpu_expect_next(cpu, 0x060FE6E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE6E0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCDCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000006u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000007u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCDEu;
            if (nh_scpu_expect_next(cpu, 0x060FE6F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE6F0u: {
            static const uint8_t expected_epoch[] = { 0xE9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCDEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
            const uint32_t borrow = (cpu->p & NH_P_C) != 0u ? 0u : 1u;
            const uint16_t result = (uint16_t)((uint32_t)left - (uint32_t)right - borrow);
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if ((uint32_t)left >= (uint32_t)right + borrow) cpu->p |= NH_P_C;
            if (((left ^ right) & (left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCE1u;
            if (nh_scpu_expect_next(cpu, 0x060FE708u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FE708u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCE1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000006u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000007u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCE3u;
            if (nh_scpu_expect_next(cpu, 0x060FE718u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE718u: {
            static const uint8_t expected_epoch[] = { 0x10u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCE3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFCE6u;
                if (nh_scpu_expect_next(cpu, 0x060FE730u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCE5u;
            if (nh_scpu_expect_next(cpu, 0x060FE728u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE728u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCE5u,
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
            if ((((((return_key != 0x060FF960u && return_key != 0x061A5688u) && (return_key != 0x061B9320u && return_key != 0x061D41B8u)) && ((return_key != 0x061D53E8u && return_key != 0x061D5998u) && (return_key != 0x061D6C10u && return_key != 0x061D70C8u))) && (((return_key != 0x061D8820u && return_key != 0x061D9038u) && (return_key != 0x061E1A60u && return_key != 0x061E3C70u)) && ((return_key != 0x061E4AD8u && return_key != 0x062ACA40u) && (return_key != 0x06322628u && return_key != 0x06322828u)))) && ((((return_key != 0x06322D00u && return_key != 0x06322EE8u) && (return_key != 0x06323BA8u && return_key != 0x06323DA8u)) && ((return_key != 0x063FA2D0u && return_key != 0x064002F0u) && (return_key != 0x064117F0u && return_key != 0x064B4918u))) && (((return_key != 0x064C5278u && return_key != 0x064CAEE8u) && (return_key != 0x064CF728u && return_key != 0x064CFBE8u)) && ((return_key != 0x064CFD08u && return_key != 0x064CFE28u) && (return_key != 0x064DC638u && return_key != 0x064DD9F0u))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FE730u: {
            static const uint8_t expected_epoch[] = { 0x06u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCE6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t old = (uint16_t)(low | ((uint16_t)high << 8u));
            const uint16_t result = (uint16_t)(((uint32_t)old << 1u) | 0u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | ((old >> 15u) & 1u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCE8u;
            if (nh_scpu_expect_next(cpu, 0x060FE740u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE740u: {
            static const uint8_t expected_epoch[] = { 0x26u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCE8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t old = (uint16_t)(low | ((uint16_t)high << 8u));
            const uint16_t result = (uint16_t)(((uint32_t)old << 1u) | ((cpu->p & NH_P_C) != 0u ? 1u : 0u));
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | ((old >> 15u) & 1u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCEAu;
            if (nh_scpu_expect_next(cpu, 0x060FE750u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE750u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0xE8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCEAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCD4u;
            if (nh_scpu_expect_next(cpu, 0x060FE6A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FE760u: {
            static const uint8_t expected_epoch[] = { 0xC6u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCECu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t result = (uint16_t)(value - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCEEu;
            if (nh_scpu_expect_next(cpu, 0x060FE770u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE770u: {
            static const uint8_t expected_epoch[] = { 0x10u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCEEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFCF1u;
                if (nh_scpu_expect_next(cpu, 0x060FE788u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCF0u;
            if (nh_scpu_expect_next(cpu, 0x060FE780u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE780u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCF0u,
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
            if (((((return_key != 0x06090EB0u && (return_key != 0x06091010u && return_key != 0x06093B28u)) && (return_key != 0x06093C88u && (return_key != 0x060A46E8u && return_key != 0x06117208u))) && ((return_key != 0x061D8650u && (return_key != 0x061D8778u && return_key != 0x062107E8u)) && (return_key != 0x06240D88u && (return_key != 0x06240E58u && return_key != 0x0628B010u)))) && (((return_key != 0x062A0D38u && (return_key != 0x062A0ED8u && return_key != 0x062A10A0u)) && (return_key != 0x062A1240u && (return_key != 0x06342108u && return_key != 0x06354388u))) && ((return_key != 0x063A50E0u && (return_key != 0x0648BDC8u && return_key != 0x0648CC80u)) && ((return_key != 0x0648DB00u && return_key != 0x064961A0u) && (return_key != 0x064B3678u && return_key != 0x064D53D0u))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FE788u: {
            static const uint8_t expected_epoch[] = { 0x46u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCF1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(low | ((uint16_t)high << 8u));
            const uint16_t result = (uint16_t)(value >> 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | ((value & 1u) != 0u ? NH_P_C : 0u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCF3u;
            if (nh_scpu_expect_next(cpu, 0x060FE798u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE798u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0xF7u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCF3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCECu;
            if (nh_scpu_expect_next(cpu, 0x060FE760u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FE7A8u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCF5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCF6u;
            if (nh_scpu_expect_next(cpu, 0x060FE7B0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE7B0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCF6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCF8u;
            if (nh_scpu_expect_next(cpu, 0x060FE7C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE7C0u: {
            static const uint8_t expected_epoch[] = { 0xE9u, 0x01u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCF8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0001u;
            const uint32_t borrow = (cpu->p & NH_P_C) != 0u ? 0u : 1u;
            const uint16_t result = (uint16_t)((uint32_t)left - (uint32_t)right - borrow);
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if ((uint32_t)left >= (uint32_t)right + borrow) cpu->p |= NH_P_C;
            if (((left ^ right) & (left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCFBu;
            if (nh_scpu_expect_next(cpu, 0x060FE7D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FE7D8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCFBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCFDu;
            if (nh_scpu_expect_next(cpu, 0x060FE7E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE7E8u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCFDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000006u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000007u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCFFu;
            if (nh_scpu_expect_next(cpu, 0x060FE7F8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE7F8u: {
            static const uint8_t expected_epoch[] = { 0xE9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FCFFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0000u;
            const uint32_t borrow = (cpu->p & NH_P_C) != 0u ? 0u : 1u;
            const uint16_t result = (uint16_t)((uint32_t)left - (uint32_t)right - borrow);
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if ((uint32_t)left >= (uint32_t)right + borrow) cpu->p |= NH_P_C;
            if (((left ^ right) & (left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD02u;
            if (nh_scpu_expect_next(cpu, 0x060FE810u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        default: return NH_SCPU_NOT_MINE;
    }
}
