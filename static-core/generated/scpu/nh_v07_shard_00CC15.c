/* Generated direct New Horizons S-CPU authority; do not edit. */
#include "nh_v07_generated.h"

NHScpuExecResult nh_v07_shard_00CC15(NHScpuState *cpu, const NHScpuBus *bus) {
    switch (nh_scpu_context_key(cpu)) {
        case 0x0660A800u: {
            static const uint8_t expected_epoch[] = { 0xB7u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1500u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000020u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000021u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_bank = 0u, low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000022u) & 0xFFFFu), &pointer_bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) | ((uint32_t)pointer_high << 8u) | pointer_low) + cpu->y) & 0xFFFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1502u;
            if (nh_scpu_expect_next(cpu, 0x0660A810u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660A810u: {
            static const uint8_t expected_epoch[] = { 0x3Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1502u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1503u;
            if (nh_scpu_expect_next(cpu, 0x0660A818u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660A818u: {
            static const uint8_t expected_epoch[] = { 0x48u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1503u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1504u;
            if (nh_scpu_expect_next(cpu, 0x0660A820u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0660A820u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x96u, 0x16u, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1504u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xCCu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x15u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x07u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0x1696u;
            if (nh_scpu_expect_next(cpu, 0x0608B4B0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x0660A840u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1508u,
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1509u;
            if (nh_scpu_expect_next(cpu, 0x0660A848u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660A848u: {
            static const uint8_t expected_epoch[] = { 0xBAu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1509u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = cpu->s;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x150Au;
            if (nh_scpu_expect_next(cpu, 0x0660A850u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660A850u: {
            static const uint8_t expected_epoch[] = { 0x86u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC150Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000020u) & 0xFFFFu), (uint8_t)cpu->x) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000021u) & 0xFFFFu), (uint8_t)(cpu->x >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x150Cu;
            if (nh_scpu_expect_next(cpu, 0x0660A860u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660A860u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x22u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC150Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000022u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000023u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x150Eu;
            if (nh_scpu_expect_next(cpu, 0x0660A870u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660A870u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x96u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC150Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x0196u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1511u;
            if (nh_scpu_expect_next(cpu, 0x0660A888u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0660A888u: {
            static const uint8_t expected_epoch[] = { 0xB7u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1511u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000020u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000021u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_bank = 0u, low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000022u) & 0xFFFFu), &pointer_bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) | ((uint32_t)pointer_high << 8u) | pointer_low) + cpu->y) & 0xFFFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1513u;
            if (nh_scpu_expect_next(cpu, 0x0660A898u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660A898u: {
            static const uint8_t expected_epoch[] = { 0x48u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1513u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1514u;
            if (nh_scpu_expect_next(cpu, 0x0660A8A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0660A8A0u: {
            static const uint8_t expected_epoch[] = { 0xF4u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1514u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x00u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x00u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1517u;
            if (nh_scpu_expect_next(cpu, 0x0660A8B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660A8B8u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1517u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1518u;
            if (nh_scpu_expect_next(cpu, 0x0660A8C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660A8C0u: {
            static const uint8_t expected_epoch[] = { 0x3Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1518u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = cpu->s;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1519u;
            if (nh_scpu_expect_next(cpu, 0x0660A8C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660A8C8u: {
            static const uint8_t expected_epoch[] = { 0x69u, 0x05u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1519u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0005u;
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x151Cu;
            if (nh_scpu_expect_next(cpu, 0x0660A8E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0660A8E0u: {
            static const uint8_t expected_epoch[] = { 0x48u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC151Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xCCu;
            cpu->pc = 0x151Du;
            if (nh_scpu_expect_next(cpu, 0x0660A8E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0660A8E8u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x89u, 0x09u, 0xCCu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC151Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xCCu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x15u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x20u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xCCu;
            cpu->pc = 0x0989u;
            if (nh_scpu_expect_next(cpu, 0x06604C48u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x0660A908u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1521u,
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1522u;
            if (nh_scpu_expect_next(cpu, 0x0660A910u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660A910u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1522u,
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1523u;
            if (nh_scpu_expect_next(cpu, 0x0660A918u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660A918u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1523u,
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1524u;
            if (nh_scpu_expect_next(cpu, 0x0660A920u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660A920u: {
            static const uint8_t expected_epoch[] = { 0xBAu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1524u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = cpu->s;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1525u;
            if (nh_scpu_expect_next(cpu, 0x0660A928u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660A928u: {
            static const uint8_t expected_epoch[] = { 0x86u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1525u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000020u) & 0xFFFFu), (uint8_t)cpu->x) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000021u) & 0xFFFFu), (uint8_t)(cpu->x >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1527u;
            if (nh_scpu_expect_next(cpu, 0x0660A938u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660A938u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x22u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1527u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000022u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000023u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1529u;
            if (nh_scpu_expect_next(cpu, 0x0660A948u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660A948u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x81u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1529u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x0181u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x152Cu;
            if (nh_scpu_expect_next(cpu, 0x0660A960u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0660A960u: {
            static const uint8_t expected_epoch[] = { 0xB7u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC152Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000020u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000021u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_bank = 0u, low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000022u) & 0xFFFFu), &pointer_bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) | ((uint32_t)pointer_high << 8u) | pointer_low) + cpu->y) & 0xFFFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x152Eu;
            if (nh_scpu_expect_next(cpu, 0x0660A970u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660A970u: {
            static const uint8_t expected_epoch[] = { 0x1Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC152Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x152Fu;
            if (nh_scpu_expect_next(cpu, 0x0660A978u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660A978u: {
            static const uint8_t expected_epoch[] = { 0x97u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC152Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000020u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000021u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000022u) & 0xFFFFu), &pointer_bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) | ((uint32_t)pointer_high << 8u) | pointer_low) + cpu->y) & 0xFFFFFFu;
            if (nh_scpu_write8(cpu, bus, address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFFFu, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1531u;
            if (nh_scpu_expect_next(cpu, 0x0660A988u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660A988u: {
            static const uint8_t expected_epoch[] = { 0x82u, 0x99u, 0xFEu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1531u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x13CDu;
            if (nh_scpu_expect_next(cpu, 0x06609E68u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0660A9A0u: {
            static const uint8_t expected_epoch[] = { 0x3Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1534u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = cpu->s;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1535u;
            if (nh_scpu_expect_next(cpu, 0x0660A9A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660A9A8u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1535u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1536u;
            if (nh_scpu_expect_next(cpu, 0x0660A9B0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660A9B0u: {
            static const uint8_t expected_epoch[] = { 0x69u, 0x86u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1536u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0186u;
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1539u;
            if (nh_scpu_expect_next(cpu, 0x0660A9C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0660A9C8u: {
            static const uint8_t expected_epoch[] = { 0x1Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1539u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = cpu->a;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x153Au;
            if (nh_scpu_expect_next(cpu, 0x0660A9D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660A9D0u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x0Cu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC153Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x000Cu;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x153Du;
            if (nh_scpu_expect_next(cpu, 0x0660A9E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0660A9E8u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x53u, 0xFFu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC153Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xCCu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x15u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x40u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF53u;
            if (nh_scpu_expect_next(cpu, 0x060FFA98u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x0660AA08u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1541u,
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
            if (((return_key != 0x06415CF0u && (return_key != 0x06416100u && return_key != 0x064165A0u)) && (return_key != 0x064AAEB0u && (return_key != 0x064AB028u && return_key != 0x06582CA8u))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0660AA10u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1542u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x08u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1544u;
            if (nh_scpu_expect_next(cpu, 0x0660AA20u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660AA20u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x1Fu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1544u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x001Fu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1547u;
            if (nh_scpu_expect_next(cpu, 0x0660AA38u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0660AA38u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x0Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1547u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Cu) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Du) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1549u;
            if (nh_scpu_expect_next(cpu, 0x0660AA48u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AA48u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1549u,
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x154Bu;
            if (nh_scpu_expect_next(cpu, 0x0660AA58u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660AA58u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC154Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000010u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000011u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x154Du;
            if (nh_scpu_expect_next(cpu, 0x0660AA68u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AA68u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC154Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x06u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x154Fu;
            if (nh_scpu_expect_next(cpu, 0x0660AA78u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660AA78u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x12u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC154Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000012u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000013u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1551u;
            if (nh_scpu_expect_next(cpu, 0x0660AA88u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AA88u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x0Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1551u,
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1553u;
            if (nh_scpu_expect_next(cpu, 0x0660AA98u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AA98u: {
            static const uint8_t expected_epoch[] = { 0x87u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1553u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t lo = 0u, hi = 0u;
            uint32_t address;
            uint8_t bank = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000010u) & 0xFFFFu), &lo) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000011u) & 0xFFFFu), &hi) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000012u) & 0xFFFFu), &bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            address = ((uint32_t)bank << 16) | ((uint32_t)hi << 8) | (uint32_t)lo;
            if (nh_scpu_write8(cpu, bus, address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (address + 1u) & 0x00FFFFFFu, (uint8_t)(cpu->a >> 8)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1555u;
            if (nh_scpu_expect_next(cpu, 0x0660AAA8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AAA8u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1555u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x08u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1557u;
            if (nh_scpu_expect_next(cpu, 0x0660AAB8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660AAB8u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0xE0u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1557u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x03E0u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x155Au;
            if (nh_scpu_expect_next(cpu, 0x0660AAD0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0660AAD0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x0Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC155Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Cu) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Du) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x155Cu;
            if (nh_scpu_expect_next(cpu, 0x0660AAE0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AAE0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x0Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC155Cu,
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x155Eu;
            if (nh_scpu_expect_next(cpu, 0x0660AAF0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AAF0u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC155Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x155Fu;
            if (nh_scpu_expect_next(cpu, 0x0660AAF8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AAF8u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC155Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1560u;
            if (nh_scpu_expect_next(cpu, 0x0660AB00u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AB00u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1560u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1561u;
            if (nh_scpu_expect_next(cpu, 0x0660AB08u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AB08u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1561u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1562u;
            if (nh_scpu_expect_next(cpu, 0x0660AB10u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AB10u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1562u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1563u;
            if (nh_scpu_expect_next(cpu, 0x0660AB18u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AB18u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x0Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1563u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Cu) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Du) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1565u;
            if (nh_scpu_expect_next(cpu, 0x0660AB28u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AB28u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1565u,
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1567u;
            if (nh_scpu_expect_next(cpu, 0x0660AB38u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660AB38u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1567u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000010u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000011u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1569u;
            if (nh_scpu_expect_next(cpu, 0x0660AB48u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AB48u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1569u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x06u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x156Bu;
            if (nh_scpu_expect_next(cpu, 0x0660AB58u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660AB58u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x12u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC156Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000012u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000013u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x156Du;
            if (nh_scpu_expect_next(cpu, 0x0660AB68u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AB68u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x0Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC156Du,
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x156Fu;
            if (nh_scpu_expect_next(cpu, 0x0660AB78u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AB78u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x02u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC156Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x0002u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1572u;
            if (nh_scpu_expect_next(cpu, 0x0660AB90u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0660AB90u: {
            static const uint8_t expected_epoch[] = { 0x97u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1572u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000010u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000011u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000012u) & 0xFFFFu), &pointer_bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) | ((uint32_t)pointer_high << 8u) | pointer_low) + cpu->y) & 0xFFFFFFu;
            if (nh_scpu_write8(cpu, bus, address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFFFu, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1574u;
            if (nh_scpu_expect_next(cpu, 0x0660ABA0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660ABA0u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1574u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x08u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1576u;
            if (nh_scpu_expect_next(cpu, 0x0660ABB0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660ABB0u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x00u, 0x7Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1576u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x7C00u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1579u;
            if (nh_scpu_expect_next(cpu, 0x0660ABC8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0660ABC8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x0Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1579u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Cu) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Du) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x157Bu;
            if (nh_scpu_expect_next(cpu, 0x0660ABD8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660ABD8u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x0Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC157Bu,
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x157Du;
            if (nh_scpu_expect_next(cpu, 0x0660ABE8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660ABE8u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC157Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x157Eu;
            if (nh_scpu_expect_next(cpu, 0x0660ABF0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660ABF0u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC157Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x157Fu;
            if (nh_scpu_expect_next(cpu, 0x0660ABF8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660ABF8u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC157Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1580u;
            if (nh_scpu_expect_next(cpu, 0x0660AC00u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AC00u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1580u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1581u;
            if (nh_scpu_expect_next(cpu, 0x0660AC08u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AC08u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1581u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1582u;
            if (nh_scpu_expect_next(cpu, 0x0660AC10u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AC10u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1582u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1583u;
            if (nh_scpu_expect_next(cpu, 0x0660AC18u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AC18u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1583u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1584u;
            if (nh_scpu_expect_next(cpu, 0x0660AC20u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AC20u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1584u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1585u;
            if (nh_scpu_expect_next(cpu, 0x0660AC28u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AC28u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1585u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1586u;
            if (nh_scpu_expect_next(cpu, 0x0660AC30u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AC30u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1586u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1587u;
            if (nh_scpu_expect_next(cpu, 0x0660AC38u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AC38u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x0Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1587u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Cu) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Du) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1589u;
            if (nh_scpu_expect_next(cpu, 0x0660AC48u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AC48u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1589u,
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x158Bu;
            if (nh_scpu_expect_next(cpu, 0x0660AC58u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660AC58u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC158Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000010u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000011u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x158Du;
            if (nh_scpu_expect_next(cpu, 0x0660AC68u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AC68u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC158Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x06u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x158Fu;
            if (nh_scpu_expect_next(cpu, 0x0660AC78u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660AC78u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x12u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC158Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000012u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000013u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1591u;
            if (nh_scpu_expect_next(cpu, 0x0660AC88u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AC88u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x0Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1591u,
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1593u;
            if (nh_scpu_expect_next(cpu, 0x0660AC98u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AC98u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1593u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1594u;
            if (nh_scpu_expect_next(cpu, 0x0660ACA0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660ACA0u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1594u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1595u;
            if (nh_scpu_expect_next(cpu, 0x0660ACA8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660ACA8u: {
            static const uint8_t expected_epoch[] = { 0x97u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1595u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u, pointer_bank = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000010u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000011u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000012u) & 0xFFFFu), &pointer_bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) | ((uint32_t)pointer_high << 8u) | pointer_low) + cpu->y) & 0xFFFFFFu;
            if (nh_scpu_write8(cpu, bus, address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFFFu, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1597u;
            if (nh_scpu_expect_next(cpu, 0x0660ACB8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660ACB8u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1597u,
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
            if ((return_key != 0x062A62A8u && (return_key != 0x0660AFA0u && return_key != 0x0660B2A0u)))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0660ACC0u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC1598u,
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x159Au;
            if (nh_scpu_expect_next(cpu, 0x0660ACD0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660ACD0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x0Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC159Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Cu) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Du) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x159Cu;
            if (nh_scpu_expect_next(cpu, 0x0660ACE0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660ACE0u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC159Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x06u) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x159Eu;
            if (nh_scpu_expect_next(cpu, 0x0660ACF0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660ACF0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC159Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Eu) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Fu) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15A0u;
            if (nh_scpu_expect_next(cpu, 0x0660AD00u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AD00u: {
            static const uint8_t expected_epoch[] = { 0xA7u, 0x0Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15A0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t lo = 0u, hi = 0u;
            uint32_t address;
            uint8_t bank = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Cu) & 0xFFFFu), &lo) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Du) & 0xFFFFu), &hi) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Eu) & 0xFFFFu), &bank) != NH_SCPU_EXECUTED)
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15A2u;
            if (nh_scpu_expect_next(cpu, 0x0660AD10u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AD10u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x1Fu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15A2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x001Fu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15A5u;
            if (nh_scpu_expect_next(cpu, 0x0660AD28u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0660AD28u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15A5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000010u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000011u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15A7u;
            if (nh_scpu_expect_next(cpu, 0x0660AD38u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AD38u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x02u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15A7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x0002u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15AAu;
            if (nh_scpu_expect_next(cpu, 0x0660AD50u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0660AD50u: {
            static const uint8_t expected_epoch[] = { 0xB7u, 0x0Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15AAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Cu) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Du) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_bank = 0u, low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Eu) & 0xFFFFu), &pointer_bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) | ((uint32_t)pointer_high << 8u) | pointer_low) + cpu->y) & 0xFFFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15ACu;
            if (nh_scpu_expect_next(cpu, 0x0660AD60u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AD60u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x1Fu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15ACu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x001Fu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15AFu;
            if (nh_scpu_expect_next(cpu, 0x0660AD78u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0660AD78u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x14u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15AFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000014u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000015u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15B1u;
            if (nh_scpu_expect_next(cpu, 0x0660AD88u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AD88u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x14u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15B1u,
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15B3u;
            if (nh_scpu_expect_next(cpu, 0x0660AD98u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AD98u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15B3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15B4u;
            if (nh_scpu_expect_next(cpu, 0x0660ADA0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660ADA0u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15B4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15B5u;
            if (nh_scpu_expect_next(cpu, 0x0660ADA8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660ADA8u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15B5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15B6u;
            if (nh_scpu_expect_next(cpu, 0x0660ADB0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660ADB0u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15B6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15B7u;
            if (nh_scpu_expect_next(cpu, 0x0660ADB8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660ADB8u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15B7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15B8u;
            if (nh_scpu_expect_next(cpu, 0x0660ADC0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660ADC0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x14u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15B8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000014u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000015u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15BAu;
            if (nh_scpu_expect_next(cpu, 0x0660ADD0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660ADD0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15BAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000010u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000011u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15BCu;
            if (nh_scpu_expect_next(cpu, 0x0660ADE0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660ADE0u: {
            static const uint8_t expected_epoch[] = { 0x05u, 0x14u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15BCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000014u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000015u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a | (uint16_t)(low | ((uint16_t)high << 8u)));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15BEu;
            if (nh_scpu_expect_next(cpu, 0x0660ADF0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660ADF0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15BEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000010u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000011u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15C0u;
            if (nh_scpu_expect_next(cpu, 0x0660AE00u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AE00u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15C0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15C1u;
            if (nh_scpu_expect_next(cpu, 0x0660AE08u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AE08u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15C1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15C2u;
            if (nh_scpu_expect_next(cpu, 0x0660AE10u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AE10u: {
            static const uint8_t expected_epoch[] = { 0xB7u, 0x0Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15C2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Cu) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Du) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_bank = 0u, low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Eu) & 0xFFFFu), &pointer_bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = ((((uint32_t)pointer_bank << 16u) | ((uint32_t)pointer_high << 8u) | pointer_low) + cpu->y) & 0xFFFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15C4u;
            if (nh_scpu_expect_next(cpu, 0x0660AE20u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AE20u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x1Fu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15C4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x001Fu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15C7u;
            if (nh_scpu_expect_next(cpu, 0x0660AE38u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0660AE38u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x14u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15C7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000014u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000015u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15C9u;
            if (nh_scpu_expect_next(cpu, 0x0660AE48u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AE48u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x14u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15C9u,
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15CBu;
            if (nh_scpu_expect_next(cpu, 0x0660AE58u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AE58u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15CBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15CCu;
            if (nh_scpu_expect_next(cpu, 0x0660AE60u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AE60u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15CCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15CDu;
            if (nh_scpu_expect_next(cpu, 0x0660AE68u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AE68u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15CDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15CEu;
            if (nh_scpu_expect_next(cpu, 0x0660AE70u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AE70u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15CEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15CFu;
            if (nh_scpu_expect_next(cpu, 0x0660AE78u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AE78u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15CFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15D0u;
            if (nh_scpu_expect_next(cpu, 0x0660AE80u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AE80u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15D0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15D1u;
            if (nh_scpu_expect_next(cpu, 0x0660AE88u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AE88u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15D1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15D2u;
            if (nh_scpu_expect_next(cpu, 0x0660AE90u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AE90u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15D2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15D3u;
            if (nh_scpu_expect_next(cpu, 0x0660AE98u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AE98u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15D3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15D4u;
            if (nh_scpu_expect_next(cpu, 0x0660AEA0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AEA0u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15D4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = cpu->a;
            cpu->a = (uint16_t)(value << 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if ((value & 0x8000u) != 0u) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15D5u;
            if (nh_scpu_expect_next(cpu, 0x0660AEA8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AEA8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x14u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15D5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000014u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000015u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15D7u;
            if (nh_scpu_expect_next(cpu, 0x0660AEB8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AEB8u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15D7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000010u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000011u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15D9u;
            if (nh_scpu_expect_next(cpu, 0x0660AEC8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AEC8u: {
            static const uint8_t expected_epoch[] = { 0x05u, 0x14u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15D9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000014u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000015u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a | (uint16_t)(low | ((uint16_t)high << 8u)));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15DBu;
            if (nh_scpu_expect_next(cpu, 0x0660AED8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AED8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15DBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15DDu;
            if (nh_scpu_expect_next(cpu, 0x0660AEE8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0660AEE8u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15DDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u, return_bank = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &return_bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            cpu->pbr = return_bank;
            if (nh_scpu_context_key(cpu) != 0x062A6610u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0660AEF0u: {
            static const uint8_t expected_epoch[] = { 0x3Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15DEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = cpu->s;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15DFu;
            if (nh_scpu_expect_next(cpu, 0x0660AEF8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AEF8u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15DFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15E0u;
            if (nh_scpu_expect_next(cpu, 0x0660AF00u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AF00u: {
            static const uint8_t expected_epoch[] = { 0xE9u, 0x72u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15E0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0072u;
            const uint32_t borrow = (cpu->p & NH_P_C) != 0u ? 0u : 1u;
            const uint16_t result = (uint16_t)((uint32_t)left - (uint32_t)right - borrow);
            cpu->a = result;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if ((uint32_t)left >= (uint32_t)right + borrow) cpu->p |= NH_P_C;
            if (((left ^ right) & (left ^ result) & 0x8000u) != 0u) cpu->p |= NH_P_V;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15E3u;
            if (nh_scpu_expect_next(cpu, 0x0660AF18u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0660AF18u: {
            static const uint8_t expected_epoch[] = { 0x1Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15E3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = cpu->a;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15E4u;
            if (nh_scpu_expect_next(cpu, 0x0660AF20u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AF20u: {
            static const uint8_t expected_epoch[] = { 0xA3u, 0x7Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15E4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t address;
            address = ((uint32_t)cpu->s + 0x7Eu) & 0xFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->a = right;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15E6u;
            if (nh_scpu_expect_next(cpu, 0x0660AF30u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660AF30u: {
            static const uint8_t expected_epoch[] = { 0x48u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15E6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15E7u;
            if (nh_scpu_expect_next(cpu, 0x0660AF38u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0660AF38u: {
            static const uint8_t expected_epoch[] = { 0xF4u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15E7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x00u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x00u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15EAu;
            if (nh_scpu_expect_next(cpu, 0x0660AF50u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660AF50u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15EAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15EBu;
            if (nh_scpu_expect_next(cpu, 0x0660AF58u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AF58u: {
            static const uint8_t expected_epoch[] = { 0x3Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15EBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = cpu->s;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15ECu;
            if (nh_scpu_expect_next(cpu, 0x0660AF60u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0660AF60u: {
            static const uint8_t expected_epoch[] = { 0x69u, 0x65u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15ECu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t right = 0x0065u;
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15EFu;
            if (nh_scpu_expect_next(cpu, 0x0660AF78u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0660AF78u: {
            static const uint8_t expected_epoch[] = { 0x48u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15EFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15F0u;
            if (nh_scpu_expect_next(cpu, 0x0660AF80u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0660AF80u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x42u, 0x15u, 0xCCu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15F0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xCCu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x15u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xF3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1542u;
            if (nh_scpu_expect_next(cpu, 0x0660AA10u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x0660AFA0u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15F4u,
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15F5u;
            if (nh_scpu_expect_next(cpu, 0x0660AFA8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660AFA8u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15F5u,
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15F6u;
            if (nh_scpu_expect_next(cpu, 0x0660AFB0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660AFB0u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15F6u,
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
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15F7u;
            if (nh_scpu_expect_next(cpu, 0x0660AFB8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660AFB8u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15F7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15FAu;
            if (nh_scpu_expect_next(cpu, 0x0660AFD0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0660AFD0u: {
            static const uint8_t expected_epoch[] = { 0x83u, 0x6Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15FAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = ((uint32_t)cpu->s + 0x6Fu) & 0xFFFFu;
            if (nh_scpu_write8(cpu, bus, address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFu, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15FCu;
            if (nh_scpu_expect_next(cpu, 0x0660AFE0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0660AFE0u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x10u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15FCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0010u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x15FFu;
            if (nh_scpu_expect_next(cpu, 0x0660AFF8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0660AFF8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xCC15FFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xCCu;
            cpu->pc = 0x1601u;
            if (nh_scpu_expect_next(cpu, 0x0660B008u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        default: return NH_SCPU_NOT_MINE;
    }
}
