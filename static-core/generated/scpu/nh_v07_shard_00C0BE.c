/* Generated direct New Horizons S-CPU authority; do not edit. */
#include "nh_v07_generated.h"

NHScpuExecResult nh_v07_shard_00C0BE(NHScpuState *cpu, const NHScpuBus *bus) {
    switch (nh_scpu_context_key(cpu)) {
        case 0x0605F013u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x9Cu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE02u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F9Cu) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE05u;
            if (nh_scpu_expect_next(cpu, 0x0605F02Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F02Bu: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0xADu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE05u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FADu) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE08u;
            if (nh_scpu_expect_next(cpu, 0x0605F043u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F043u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x7Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE08u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | ((uint8_t)cpu->a & 0x7Fu));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE0Au;
            if (nh_scpu_expect_next(cpu, 0x0605F053u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F053u: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x32u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE0Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBE3Eu;
                if (nh_scpu_expect_next(cpu, 0x0605F1F3u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE0Cu;
            if (nh_scpu_expect_next(cpu, 0x0605F063u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F063u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xADu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE0Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FADu) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE0Fu;
            if (nh_scpu_expect_next(cpu, 0x0605F07Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F07Bu: {
            static const uint8_t expected_epoch[] = { 0x30u, 0x12u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE0Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBE23u;
                if (nh_scpu_expect_next(cpu, 0x0605F11Bu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE11u;
            if (nh_scpu_expect_next(cpu, 0x0605F08Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F08Bu: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE11u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE12u;
            if (nh_scpu_expect_next(cpu, 0x0605F093u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F093u: {
            static const uint8_t expected_epoch[] = { 0x6Du, 0xA6u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE12u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA6u) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t left = (uint8_t)cpu->a;
            const uint8_t right = (uint8_t)(value);
            uint16_t sum;
            uint8_t result;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            sum = (uint16_t)left + (uint16_t)right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            result = (uint8_t)sum;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (sum > 0x00FFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x80u) != 0u) cpu->p |= NH_P_N;
            if (((uint8_t)(~(left ^ right)) & (uint8_t)(left ^ result) & 0x80u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE15u;
            if (nh_scpu_expect_next(cpu, 0x0605F0ABu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F0ABu: {
            static const uint8_t expected_epoch[] = { 0xB0u, 0x07u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE15u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBE1Eu;
                if (nh_scpu_expect_next(cpu, 0x0605F0F3u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE17u;
            if (nh_scpu_expect_next(cpu, 0x0605F0BBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F0BBu: {
            static const uint8_t expected_epoch[] = { 0xCDu, 0xABu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE17u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FABu) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t result;
            const uint8_t left = (uint8_t)cpu->a;
            result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= value) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x80u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE1Au;
            if (nh_scpu_expect_next(cpu, 0x0605F0D3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F0D3u: {
            static const uint8_t expected_epoch[] = { 0xB0u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE1Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBE1Eu;
                if (nh_scpu_expect_next(cpu, 0x0605F0F3u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE1Cu;
            if (nh_scpu_expect_next(cpu, 0x0605F0E3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F0E3u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x1Du };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE1Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE3Bu;
            if (nh_scpu_expect_next(cpu, 0x0605F1DBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605F0F3u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xABu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE1Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FABu) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE21u;
            if (nh_scpu_expect_next(cpu, 0x0605F10Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F10Bu: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE21u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE3Bu;
            if (nh_scpu_expect_next(cpu, 0x0605F1DBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605F11Bu: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x7Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE23u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | ((uint8_t)cpu->a & 0x7Fu));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE25u;
            if (nh_scpu_expect_next(cpu, 0x0605F12Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F12Bu: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0xADu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE25u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FADu) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE28u;
            if (nh_scpu_expect_next(cpu, 0x0605F143u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F143u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE28u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE29u;
            if (nh_scpu_expect_next(cpu, 0x0605F14Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F14Bu: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xA6u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE29u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA6u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE2Cu;
            if (nh_scpu_expect_next(cpu, 0x0605F163u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F163u: {
            static const uint8_t expected_epoch[] = { 0xEDu, 0xADu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE2Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            uint8_t right = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FADu) & 0xFFFFFFu), &right) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t left = (uint8_t)cpu->a;
            const uint16_t total = (uint16_t)((uint16_t)left - right - ((cpu->p & NH_P_C) != 0u ? 0u : 1u));
            const uint8_t result = (uint8_t)total;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_C | NH_P_V));
            if (total <= 0xFFu) cpu->p |= NH_P_C;
            if (((left ^ right) & (left ^ result) & 0x80u) != 0u) cpu->p |= NH_P_V;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE2Fu;
            if (nh_scpu_expect_next(cpu, 0x0605F17Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F17Bu: {
            static const uint8_t expected_epoch[] = { 0x90u, 0x07u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE2Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBE38u;
                if (nh_scpu_expect_next(cpu, 0x0605F1C3u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE31u;
            if (nh_scpu_expect_next(cpu, 0x0605F18Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F18Bu: {
            static const uint8_t expected_epoch[] = { 0xCDu, 0xA9u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE31u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA9u) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t result;
            const uint8_t left = (uint8_t)cpu->a;
            result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= value) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x80u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE34u;
            if (nh_scpu_expect_next(cpu, 0x0605F1A3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F1A3u: {
            static const uint8_t expected_epoch[] = { 0x90u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE34u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBE38u;
                if (nh_scpu_expect_next(cpu, 0x0605F1C3u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE36u;
            if (nh_scpu_expect_next(cpu, 0x0605F1B3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F1B3u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE36u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE3Bu;
            if (nh_scpu_expect_next(cpu, 0x0605F1DBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605F1C3u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xA9u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE38u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA9u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE3Bu;
            if (nh_scpu_expect_next(cpu, 0x0605F1DBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F1DBu: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0xA6u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE3Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA6u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE3Eu;
            if (nh_scpu_expect_next(cpu, 0x0605F1F3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F1F3u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x9Au, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE3Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F9Au) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE41u;
            if (nh_scpu_expect_next(cpu, 0x0605F20Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F20Bu: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0xADu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE41u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FADu) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE44u;
            if (nh_scpu_expect_next(cpu, 0x0605F223u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F223u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x7Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE44u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | ((uint8_t)cpu->a & 0x7Fu));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE46u;
            if (nh_scpu_expect_next(cpu, 0x0605F233u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F233u: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x32u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE46u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBE7Au;
                if (nh_scpu_expect_next(cpu, 0x0605F3D3u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE48u;
            if (nh_scpu_expect_next(cpu, 0x0605F243u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F243u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xADu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE48u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FADu) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE4Bu;
            if (nh_scpu_expect_next(cpu, 0x0605F25Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F25Bu: {
            static const uint8_t expected_epoch[] = { 0x30u, 0x12u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE4Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBE5Fu;
                if (nh_scpu_expect_next(cpu, 0x0605F2FBu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE4Du;
            if (nh_scpu_expect_next(cpu, 0x0605F26Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F26Bu: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE4Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE4Eu;
            if (nh_scpu_expect_next(cpu, 0x0605F273u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F273u: {
            static const uint8_t expected_epoch[] = { 0x6Du, 0xA7u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE4Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA7u) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t left = (uint8_t)cpu->a;
            const uint8_t right = (uint8_t)(value);
            uint16_t sum;
            uint8_t result;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            sum = (uint16_t)left + (uint16_t)right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            result = (uint8_t)sum;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (sum > 0x00FFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x80u) != 0u) cpu->p |= NH_P_N;
            if (((uint8_t)(~(left ^ right)) & (uint8_t)(left ^ result) & 0x80u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE51u;
            if (nh_scpu_expect_next(cpu, 0x0605F28Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F28Bu: {
            static const uint8_t expected_epoch[] = { 0xB0u, 0x07u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE51u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBE5Au;
                if (nh_scpu_expect_next(cpu, 0x0605F2D3u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE53u;
            if (nh_scpu_expect_next(cpu, 0x0605F29Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F29Bu: {
            static const uint8_t expected_epoch[] = { 0xCDu, 0xACu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE53u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FACu) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t result;
            const uint8_t left = (uint8_t)cpu->a;
            result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= value) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x80u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE56u;
            if (nh_scpu_expect_next(cpu, 0x0605F2B3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F2B3u: {
            static const uint8_t expected_epoch[] = { 0xB0u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE56u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBE5Au;
                if (nh_scpu_expect_next(cpu, 0x0605F2D3u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE58u;
            if (nh_scpu_expect_next(cpu, 0x0605F2C3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F2C3u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x1Du };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE58u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE77u;
            if (nh_scpu_expect_next(cpu, 0x0605F3BBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605F2D3u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xACu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE5Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FACu) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE5Du;
            if (nh_scpu_expect_next(cpu, 0x0605F2EBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F2EBu: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE5Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE77u;
            if (nh_scpu_expect_next(cpu, 0x0605F3BBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605F2FBu: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x7Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE5Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | ((uint8_t)cpu->a & 0x7Fu));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE61u;
            if (nh_scpu_expect_next(cpu, 0x0605F30Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F30Bu: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0xADu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE61u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FADu) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE64u;
            if (nh_scpu_expect_next(cpu, 0x0605F323u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F323u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE64u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE65u;
            if (nh_scpu_expect_next(cpu, 0x0605F32Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F32Bu: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xA7u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE65u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA7u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE68u;
            if (nh_scpu_expect_next(cpu, 0x0605F343u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F343u: {
            static const uint8_t expected_epoch[] = { 0xEDu, 0xADu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE68u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            uint8_t right = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FADu) & 0xFFFFFFu), &right) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t left = (uint8_t)cpu->a;
            const uint16_t total = (uint16_t)((uint16_t)left - right - ((cpu->p & NH_P_C) != 0u ? 0u : 1u));
            const uint8_t result = (uint8_t)total;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_C | NH_P_V));
            if (total <= 0xFFu) cpu->p |= NH_P_C;
            if (((left ^ right) & (left ^ result) & 0x80u) != 0u) cpu->p |= NH_P_V;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE6Bu;
            if (nh_scpu_expect_next(cpu, 0x0605F35Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F35Bu: {
            static const uint8_t expected_epoch[] = { 0x90u, 0x07u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE6Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBE74u;
                if (nh_scpu_expect_next(cpu, 0x0605F3A3u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE6Du;
            if (nh_scpu_expect_next(cpu, 0x0605F36Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F36Bu: {
            static const uint8_t expected_epoch[] = { 0xCDu, 0xAAu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE6Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FAAu) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t result;
            const uint8_t left = (uint8_t)cpu->a;
            result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= value) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x80u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE70u;
            if (nh_scpu_expect_next(cpu, 0x0605F383u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F383u: {
            static const uint8_t expected_epoch[] = { 0x90u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE70u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBE74u;
                if (nh_scpu_expect_next(cpu, 0x0605F3A3u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE72u;
            if (nh_scpu_expect_next(cpu, 0x0605F393u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F393u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE72u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE77u;
            if (nh_scpu_expect_next(cpu, 0x0605F3BBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605F3A3u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xAAu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE74u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FAAu) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE77u;
            if (nh_scpu_expect_next(cpu, 0x0605F3BBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F3BBu: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0xA7u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE77u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA7u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE7Au;
            if (nh_scpu_expect_next(cpu, 0x0605F3D3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F3D3u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x95u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE7Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F95u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE7Du;
            if (nh_scpu_expect_next(cpu, 0x0605F3EBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F3EBu: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE7Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBE82u;
                if (nh_scpu_expect_next(cpu, 0x0605F413u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE7Fu;
            if (nh_scpu_expect_next(cpu, 0x0605F3FBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F3FBu: {
            static const uint8_t expected_epoch[] = { 0x4Cu, 0x03u, 0xBFu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE7Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBF03u;
            if (nh_scpu_expect_next(cpu, 0x0605F81Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605F413u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x9Fu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE82u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F9Fu) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE85u;
            if (nh_scpu_expect_next(cpu, 0x0605F42Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F42Bu: {
            static const uint8_t expected_epoch[] = { 0x0Du, 0xA8u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE85u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA8u) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | ((uint8_t)cpu->a | value));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE88u;
            if (nh_scpu_expect_next(cpu, 0x0605F443u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F443u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0xA8u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE88u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA8u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE8Bu;
            if (nh_scpu_expect_next(cpu, 0x0605F45Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F45Bu: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x9Du, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE8Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F9Du) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE8Eu;
            if (nh_scpu_expect_next(cpu, 0x0605F473u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F473u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0xADu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE8Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FADu) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE91u;
            if (nh_scpu_expect_next(cpu, 0x0605F48Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F48Bu: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x7Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE91u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | ((uint8_t)cpu->a & 0x7Fu));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE93u;
            if (nh_scpu_expect_next(cpu, 0x0605F49Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F49Bu: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x32u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE93u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBEC7u;
                if (nh_scpu_expect_next(cpu, 0x0605F63Bu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE95u;
            if (nh_scpu_expect_next(cpu, 0x0605F4ABu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F4ABu: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xADu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE95u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FADu) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE98u;
            if (nh_scpu_expect_next(cpu, 0x0605F4C3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F4C3u: {
            static const uint8_t expected_epoch[] = { 0x30u, 0x12u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE98u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBEACu;
                if (nh_scpu_expect_next(cpu, 0x0605F563u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE9Au;
            if (nh_scpu_expect_next(cpu, 0x0605F4D3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F4D3u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE9Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE9Bu;
            if (nh_scpu_expect_next(cpu, 0x0605F4DBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F4DBu: {
            static const uint8_t expected_epoch[] = { 0x6Du, 0xA6u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE9Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA6u) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t left = (uint8_t)cpu->a;
            const uint8_t right = (uint8_t)(value);
            uint16_t sum;
            uint8_t result;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            sum = (uint16_t)left + (uint16_t)right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            result = (uint8_t)sum;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (sum > 0x00FFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x80u) != 0u) cpu->p |= NH_P_N;
            if (((uint8_t)(~(left ^ right)) & (uint8_t)(left ^ result) & 0x80u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE9Eu;
            if (nh_scpu_expect_next(cpu, 0x0605F4F3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F4F3u: {
            static const uint8_t expected_epoch[] = { 0xB0u, 0x07u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BE9Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBEA7u;
                if (nh_scpu_expect_next(cpu, 0x0605F53Bu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEA0u;
            if (nh_scpu_expect_next(cpu, 0x0605F503u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F503u: {
            static const uint8_t expected_epoch[] = { 0xCDu, 0xABu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEA0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FABu) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t result;
            const uint8_t left = (uint8_t)cpu->a;
            result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= value) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x80u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEA3u;
            if (nh_scpu_expect_next(cpu, 0x0605F51Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F51Bu: {
            static const uint8_t expected_epoch[] = { 0xB0u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEA3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBEA7u;
                if (nh_scpu_expect_next(cpu, 0x0605F53Bu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEA5u;
            if (nh_scpu_expect_next(cpu, 0x0605F52Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F52Bu: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x1Du };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEA5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEC4u;
            if (nh_scpu_expect_next(cpu, 0x0605F623u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605F53Bu: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xABu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEA7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FABu) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEAAu;
            if (nh_scpu_expect_next(cpu, 0x0605F553u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F553u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEAAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEC4u;
            if (nh_scpu_expect_next(cpu, 0x0605F623u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605F563u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x7Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEACu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | ((uint8_t)cpu->a & 0x7Fu));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEAEu;
            if (nh_scpu_expect_next(cpu, 0x0605F573u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F573u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0xADu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEAEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FADu) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEB1u;
            if (nh_scpu_expect_next(cpu, 0x0605F58Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F58Bu: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEB1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEB2u;
            if (nh_scpu_expect_next(cpu, 0x0605F593u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F593u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xA6u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEB2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA6u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEB5u;
            if (nh_scpu_expect_next(cpu, 0x0605F5ABu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F5ABu: {
            static const uint8_t expected_epoch[] = { 0xEDu, 0xADu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEB5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            uint8_t right = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FADu) & 0xFFFFFFu), &right) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t left = (uint8_t)cpu->a;
            const uint16_t total = (uint16_t)((uint16_t)left - right - ((cpu->p & NH_P_C) != 0u ? 0u : 1u));
            const uint8_t result = (uint8_t)total;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_C | NH_P_V));
            if (total <= 0xFFu) cpu->p |= NH_P_C;
            if (((left ^ right) & (left ^ result) & 0x80u) != 0u) cpu->p |= NH_P_V;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEB8u;
            if (nh_scpu_expect_next(cpu, 0x0605F5C3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F5C3u: {
            static const uint8_t expected_epoch[] = { 0x90u, 0x07u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEB8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBEC1u;
                if (nh_scpu_expect_next(cpu, 0x0605F60Bu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEBAu;
            if (nh_scpu_expect_next(cpu, 0x0605F5D3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F5D3u: {
            static const uint8_t expected_epoch[] = { 0xCDu, 0xA9u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEBAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA9u) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t result;
            const uint8_t left = (uint8_t)cpu->a;
            result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= value) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x80u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEBDu;
            if (nh_scpu_expect_next(cpu, 0x0605F5EBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F5EBu: {
            static const uint8_t expected_epoch[] = { 0x90u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEBDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBEC1u;
                if (nh_scpu_expect_next(cpu, 0x0605F60Bu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEBFu;
            if (nh_scpu_expect_next(cpu, 0x0605F5FBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F5FBu: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEBFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEC4u;
            if (nh_scpu_expect_next(cpu, 0x0605F623u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605F60Bu: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xA9u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEC1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA9u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEC4u;
            if (nh_scpu_expect_next(cpu, 0x0605F623u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F623u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0xA6u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEC4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA6u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEC7u;
            if (nh_scpu_expect_next(cpu, 0x0605F63Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F63Bu: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x9Bu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEC7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F9Bu) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBECAu;
            if (nh_scpu_expect_next(cpu, 0x0605F653u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F653u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0xADu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BECAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FADu) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBECDu;
            if (nh_scpu_expect_next(cpu, 0x0605F66Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F66Bu: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x7Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BECDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | ((uint8_t)cpu->a & 0x7Fu));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBECFu;
            if (nh_scpu_expect_next(cpu, 0x0605F67Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F67Bu: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x32u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BECFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBF03u;
                if (nh_scpu_expect_next(cpu, 0x0605F81Bu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBED1u;
            if (nh_scpu_expect_next(cpu, 0x0605F68Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F68Bu: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xADu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BED1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FADu) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBED4u;
            if (nh_scpu_expect_next(cpu, 0x0605F6A3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F6A3u: {
            static const uint8_t expected_epoch[] = { 0x30u, 0x12u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BED4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBEE8u;
                if (nh_scpu_expect_next(cpu, 0x0605F743u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBED6u;
            if (nh_scpu_expect_next(cpu, 0x0605F6B3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F6B3u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BED6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBED7u;
            if (nh_scpu_expect_next(cpu, 0x0605F6BBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F6BBu: {
            static const uint8_t expected_epoch[] = { 0x6Du, 0xA7u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BED7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA7u) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t left = (uint8_t)cpu->a;
            const uint8_t right = (uint8_t)(value);
            uint16_t sum;
            uint8_t result;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            sum = (uint16_t)left + (uint16_t)right + (((cpu->p & NH_P_C) != 0u) ? 1u : 0u);
            result = (uint8_t)sum;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_V | NH_P_Z | NH_P_C));
            if (sum > 0x00FFu) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x80u) != 0u) cpu->p |= NH_P_N;
            if (((uint8_t)(~(left ^ right)) & (uint8_t)(left ^ result) & 0x80u) != 0u) cpu->p |= NH_P_V;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEDAu;
            if (nh_scpu_expect_next(cpu, 0x0605F6D3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F6D3u: {
            static const uint8_t expected_epoch[] = { 0xB0u, 0x07u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEDAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBEE3u;
                if (nh_scpu_expect_next(cpu, 0x0605F71Bu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEDCu;
            if (nh_scpu_expect_next(cpu, 0x0605F6E3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F6E3u: {
            static const uint8_t expected_epoch[] = { 0xCDu, 0xACu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEDCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FACu) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t result;
            const uint8_t left = (uint8_t)cpu->a;
            result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= value) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x80u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEDFu;
            if (nh_scpu_expect_next(cpu, 0x0605F6FBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F6FBu: {
            static const uint8_t expected_epoch[] = { 0xB0u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEDFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBEE3u;
                if (nh_scpu_expect_next(cpu, 0x0605F71Bu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEE1u;
            if (nh_scpu_expect_next(cpu, 0x0605F70Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F70Bu: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x1Du };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEE1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBF00u;
            if (nh_scpu_expect_next(cpu, 0x0605F803u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605F71Bu: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xACu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEE3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FACu) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEE6u;
            if (nh_scpu_expect_next(cpu, 0x0605F733u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F733u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEE6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBF00u;
            if (nh_scpu_expect_next(cpu, 0x0605F803u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605F743u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x7Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEE8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | ((uint8_t)cpu->a & 0x7Fu));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEEAu;
            if (nh_scpu_expect_next(cpu, 0x0605F753u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F753u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0xADu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEEAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FADu) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEEDu;
            if (nh_scpu_expect_next(cpu, 0x0605F76Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F76Bu: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEEDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEEEu;
            if (nh_scpu_expect_next(cpu, 0x0605F773u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F773u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xA7u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEEEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA7u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEF1u;
            if (nh_scpu_expect_next(cpu, 0x0605F78Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F78Bu: {
            static const uint8_t expected_epoch[] = { 0xEDu, 0xADu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEF1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            uint8_t right = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FADu) & 0xFFFFFFu), &right) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t left = (uint8_t)cpu->a;
            const uint16_t total = (uint16_t)((uint16_t)left - right - ((cpu->p & NH_P_C) != 0u ? 0u : 1u));
            const uint8_t result = (uint8_t)total;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | result);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_C | NH_P_V));
            if (total <= 0xFFu) cpu->p |= NH_P_C;
            if (((left ^ right) & (left ^ result) & 0x80u) != 0u) cpu->p |= NH_P_V;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEF4u;
            if (nh_scpu_expect_next(cpu, 0x0605F7A3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F7A3u: {
            static const uint8_t expected_epoch[] = { 0x90u, 0x07u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEF4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBEFDu;
                if (nh_scpu_expect_next(cpu, 0x0605F7EBu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEF6u;
            if (nh_scpu_expect_next(cpu, 0x0605F7B3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F7B3u: {
            static const uint8_t expected_epoch[] = { 0xCDu, 0xAAu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEF6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FAAu) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t result;
            const uint8_t left = (uint8_t)cpu->a;
            result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= value) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x80u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEF9u;
            if (nh_scpu_expect_next(cpu, 0x0605F7CBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605F7CBu: {
            static const uint8_t expected_epoch[] = { 0x90u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEF9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBEFDu;
                if (nh_scpu_expect_next(cpu, 0x0605F7EBu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBEFBu;
            if (nh_scpu_expect_next(cpu, 0x0605F7DBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605F7DBu: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEFBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBF00u;
            if (nh_scpu_expect_next(cpu, 0x0605F803u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605F7EBu: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xAAu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BEFDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FAAu) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBF00u;
            if (nh_scpu_expect_next(cpu, 0x0605F803u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        default: return NH_SCPU_NOT_MINE;
    }
}
