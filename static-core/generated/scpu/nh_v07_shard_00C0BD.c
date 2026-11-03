/* Generated direct New Horizons S-CPU authority; do not edit. */
#include "nh_v07_generated.h"

NHScpuExecResult nh_v07_shard_00C0BD(NHScpuState *cpu, const NHScpuBus *bus) {
    switch (nh_scpu_context_key(cpu)) {
        case 0x0605E803u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xA4u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD00u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA4u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD03u;
            if (nh_scpu_expect_next(cpu, 0x0605E81Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605E81Bu: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD03u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBD0Bu;
                if (nh_scpu_expect_next(cpu, 0x0605E85Bu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD05u;
            if (nh_scpu_expect_next(cpu, 0x0605E82Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605E82Bu: {
            static const uint8_t expected_epoch[] = { 0x20u, 0x6Bu, 0xBDu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD05u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xBDu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x07u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD6Bu;
            if (nh_scpu_expect_next(cpu, 0x0605EB5Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0605E843u: {
            static const uint8_t expected_epoch[] = { 0x9Cu, 0xA4u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD08u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA4u) & 0xFFFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD0Bu;
            if (nh_scpu_expect_next(cpu, 0x0605E85Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605E85Bu: {
            static const uint8_t expected_epoch[] = { 0x28u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD0Bu,
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
            cpu->pc = 0xBD0Cu;
            if (nh_scpu_expect_next(cpu, 0x0605E860u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605E860u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD0Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            if (nh_scpu_context_key(cpu) != 0x0604A990u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0605E86Bu: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x92u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD0Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F92u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD10u;
            if (nh_scpu_expect_next(cpu, 0x0605E883u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605E883u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD10u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | ((uint8_t)cpu->a & 0x0Fu));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD12u;
            if (nh_scpu_expect_next(cpu, 0x0605E893u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605E893u: {
            static const uint8_t expected_epoch[] = { 0xC9u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD12u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t value = 0x01u;
            uint8_t result;
            const uint8_t left = (uint8_t)cpu->a;
            result = (uint8_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= value) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x80u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD14u;
            if (nh_scpu_expect_next(cpu, 0x0605E8A3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605E8A3u: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x13u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD14u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBD29u;
                if (nh_scpu_expect_next(cpu, 0x0605E94Bu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD16u;
            if (nh_scpu_expect_next(cpu, 0x0605E8B3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605E8B3u: {
            static const uint8_t expected_epoch[] = { 0x9Eu, 0x94u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD16u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint32_t destination_address;
            destination_address = ((((uint32_t)cpu->dbr << 16u) + 0x000F94u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_write8(cpu, bus, destination_address, 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD19u;
            if (nh_scpu_expect_next(cpu, 0x0605E8CBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0605E8CBu: {
            static const uint8_t expected_epoch[] = { 0x9Eu, 0x9Cu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD19u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint32_t destination_address;
            destination_address = ((((uint32_t)cpu->dbr << 16u) + 0x000F9Cu) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_write8(cpu, bus, destination_address, 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD1Cu;
            if (nh_scpu_expect_next(cpu, 0x0605E8E3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0605E8E3u: {
            static const uint8_t expected_epoch[] = { 0x9Eu, 0x9Au, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD1Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint32_t destination_address;
            destination_address = ((((uint32_t)cpu->dbr << 16u) + 0x000F9Au) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_write8(cpu, bus, destination_address, 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD1Fu;
            if (nh_scpu_expect_next(cpu, 0x0605E8FBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0605E8FBu: {
            static const uint8_t expected_epoch[] = { 0x9Eu, 0x9Eu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD1Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint32_t destination_address;
            destination_address = ((((uint32_t)cpu->dbr << 16u) + 0x000F9Eu) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_write8(cpu, bus, destination_address, 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD22u;
            if (nh_scpu_expect_next(cpu, 0x0605E913u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0605E913u: {
            static const uint8_t expected_epoch[] = { 0x9Eu, 0xA0u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD22u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint32_t destination_address;
            destination_address = ((((uint32_t)cpu->dbr << 16u) + 0x000FA0u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_write8(cpu, bus, destination_address, 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD25u;
            if (nh_scpu_expect_next(cpu, 0x0605E92Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0605E92Bu: {
            static const uint8_t expected_epoch[] = { 0x9Eu, 0xA2u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD25u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint32_t destination_address;
            destination_address = ((((uint32_t)cpu->dbr << 16u) + 0x000FA2u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_write8(cpu, bus, destination_address, 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD28u;
            if (nh_scpu_expect_next(cpu, 0x0605E943u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0605E943u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD28u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x0605E763u &&
                return_key != 0x0605E803u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0605E94Bu: {
            static const uint8_t expected_epoch[] = { 0xBDu, 0x94u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD29u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            uint32_t cycles;
            uint32_t source_address;
            source_address = ((((uint32_t)cpu->dbr << 16u) + 0x000F94u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_read8(cpu, bus, source_address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD2Cu;
            if (nh_scpu_expect_next(cpu, 0x0605E963u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cycles = 4u + ((((uint32_t)0x94u + (uint32_t)cpu->x) > 0xFFu) ? 1u : 0u);
            return nh_scpu_finish(cpu, bus, cycles);
        }

        case 0x0605E963u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x09u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD2Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBD37u;
                if (nh_scpu_expect_next(cpu, 0x0605E9BBu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD2Eu;
            if (nh_scpu_expect_next(cpu, 0x0605E973u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605E973u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD2Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x01u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD30u;
            if (nh_scpu_expect_next(cpu, 0x0605E983u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605E983u: {
            static const uint8_t expected_epoch[] = { 0x9Du, 0x94u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD30u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint32_t destination_address;
            destination_address = ((((uint32_t)cpu->dbr << 16u) + 0x000F94u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_write8(cpu, bus, destination_address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD33u;
            if (nh_scpu_expect_next(cpu, 0x0605E99Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0605E99Bu: {
            static const uint8_t expected_epoch[] = { 0x9Du, 0xA4u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD33u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint32_t destination_address;
            destination_address = ((((uint32_t)cpu->dbr << 16u) + 0x000FA4u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_write8(cpu, bus, destination_address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD36u;
            if (nh_scpu_expect_next(cpu, 0x0605E9B3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0605E9B3u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD36u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x0605E763u &&
                return_key != 0x0605E803u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0605E9BBu: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD37u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x10u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD39u;
            if (nh_scpu_expect_next(cpu, 0x0605E9CBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605E9CBu: {
            static const uint8_t expected_epoch[] = { 0xBDu, 0x16u, 0x40u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD39u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            uint32_t cycles;
            uint32_t source_address;
            source_address = ((((uint32_t)cpu->dbr << 16u) + 0x004016u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_read8(cpu, bus, source_address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD3Cu;
            if (nh_scpu_expect_next(cpu, 0x0605E9E3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cycles = 4u + ((((uint32_t)0x16u + (uint32_t)cpu->x) > 0xFFu) ? 1u : 0u);
            return nh_scpu_finish(cpu, bus, cycles);
        }

        case 0x0605E9E3u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD3Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = (uint8_t)cpu->a;
            const uint8_t carry = (uint8_t)(value & 0x01u);
            value = (uint8_t)(value >> 1u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (value == 0u) cpu->p |= NH_P_Z;
            if ((value & 0x80u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD3Du;
            if (nh_scpu_expect_next(cpu, 0x0605E9EBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605E9EBu: {
            static const uint8_t expected_epoch[] = { 0x3Eu, 0x9Cu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD3Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = (((((uint32_t)cpu->dbr << 16u) + 0x000F9Cu) + (uint32_t)cpu->x) & 0xFFFFFFu);
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t carry = (uint8_t)(value >> 7u);
            value = (uint8_t)((value << 1u) | ((cpu->p & NH_P_C) != 0u ? 1u : 0u));
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | (carry != 0u ? NH_P_C : 0u));
            if (nh_scpu_write8(cpu, bus, address, value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD40u;
            if (nh_scpu_expect_next(cpu, 0x0605EA03u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u);
        }

        case 0x0605EA03u: {
            static const uint8_t expected_epoch[] = { 0x3Eu, 0x9Au, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD40u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = (((((uint32_t)cpu->dbr << 16u) + 0x000F9Au) + (uint32_t)cpu->x) & 0xFFFFFFu);
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t carry = (uint8_t)(value >> 7u);
            value = (uint8_t)((value << 1u) | ((cpu->p & NH_P_C) != 0u ? 1u : 0u));
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | (carry != 0u ? NH_P_C : 0u));
            if (nh_scpu_write8(cpu, bus, address, value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD43u;
            if (nh_scpu_expect_next(cpu, 0x0605EA1Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u);
        }

        case 0x0605EA1Bu: {
            static const uint8_t expected_epoch[] = { 0x88u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD43u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint8_t)(cpu->y - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD44u;
            if (nh_scpu_expect_next(cpu, 0x0605EA23u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605EA23u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0xF3u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD44u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBD39u;
                if (nh_scpu_expect_next(cpu, 0x0605E9CBu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD46u;
            if (nh_scpu_expect_next(cpu, 0x0605EA33u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605EA33u: {
            static const uint8_t expected_epoch[] = { 0x9Eu, 0x9Eu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD46u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint32_t destination_address;
            destination_address = ((((uint32_t)cpu->dbr << 16u) + 0x000F9Eu) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_write8(cpu, bus, destination_address, 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD49u;
            if (nh_scpu_expect_next(cpu, 0x0605EA4Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0605EA4Bu: {
            static const uint8_t expected_epoch[] = { 0x2Eu, 0x92u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD49u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = (((uint32_t)cpu->dbr << 16u) + 0x000F92u);
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t carry = (uint8_t)(value >> 7u);
            value = (uint8_t)((value << 1u) | ((cpu->p & NH_P_C) != 0u ? 1u : 0u));
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | (carry != 0u ? NH_P_C : 0u));
            if (nh_scpu_write8(cpu, bus, address, value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD4Cu;
            if (nh_scpu_expect_next(cpu, 0x0605EA63u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0605EA63u: {
            static const uint8_t expected_epoch[] = { 0x3Eu, 0x9Eu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD4Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = (((((uint32_t)cpu->dbr << 16u) + 0x000F9Eu) + (uint32_t)cpu->x) & 0xFFFFFFu);
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t carry = (uint8_t)(value >> 7u);
            value = (uint8_t)((value << 1u) | ((cpu->p & NH_P_C) != 0u ? 1u : 0u));
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | (carry != 0u ? NH_P_C : 0u));
            if (nh_scpu_write8(cpu, bus, address, value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD4Fu;
            if (nh_scpu_expect_next(cpu, 0x0605EA7Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u);
        }

        case 0x0605EA7Bu: {
            static const uint8_t expected_epoch[] = { 0x2Eu, 0x92u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD4Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = (((uint32_t)cpu->dbr << 16u) + 0x000F92u);
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t carry = (uint8_t)(value >> 7u);
            value = (uint8_t)((value << 1u) | ((cpu->p & NH_P_C) != 0u ? 1u : 0u));
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | (carry != 0u ? NH_P_C : 0u));
            if (nh_scpu_write8(cpu, bus, address, value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD52u;
            if (nh_scpu_expect_next(cpu, 0x0605EA93u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0605EA93u: {
            static const uint8_t expected_epoch[] = { 0x3Eu, 0x9Eu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD52u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = (((((uint32_t)cpu->dbr << 16u) + 0x000F9Eu) + (uint32_t)cpu->x) & 0xFFFFFFu);
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t carry = (uint8_t)(value >> 7u);
            value = (uint8_t)((value << 1u) | ((cpu->p & NH_P_C) != 0u ? 1u : 0u));
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | (carry != 0u ? NH_P_C : 0u));
            if (nh_scpu_write8(cpu, bus, address, value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD55u;
            if (nh_scpu_expect_next(cpu, 0x0605EAABu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u);
        }

        case 0x0605EAABu: {
            static const uint8_t expected_epoch[] = { 0xBDu, 0x9Eu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD55u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            uint32_t cycles;
            uint32_t source_address;
            source_address = ((((uint32_t)cpu->dbr << 16u) + 0x000F9Eu) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_read8(cpu, bus, source_address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD58u;
            if (nh_scpu_expect_next(cpu, 0x0605EAC3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cycles = 4u + ((((uint32_t)0x9Eu + (uint32_t)cpu->x) > 0xFFu) ? 1u : 0u);
            return nh_scpu_finish(cpu, bus, cycles);
        }

        case 0x0605EAC3u: {
            static const uint8_t expected_epoch[] = { 0x5Du, 0xA2u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD58u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = (((((uint32_t)cpu->dbr << 16u) + 0x000FA2u) + (uint32_t)cpu->x) & 0xFFFFFFu);
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | ((uint8_t)cpu->a ^ value));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD5Bu;
            if (nh_scpu_expect_next(cpu, 0x0605EADBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + (((0xA2u + (uint32_t)cpu->x) > 0xFFu) ? 1u : 0u));
        }

        case 0x0605EADBu: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD5Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBD61u;
                if (nh_scpu_expect_next(cpu, 0x0605EB0Bu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD5Du;
            if (nh_scpu_expect_next(cpu, 0x0605EAEBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605EAEBu: {
            static const uint8_t expected_epoch[] = { 0x9Eu, 0xA0u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD5Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint32_t destination_address;
            destination_address = ((((uint32_t)cpu->dbr << 16u) + 0x000FA0u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_write8(cpu, bus, destination_address, 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD60u;
            if (nh_scpu_expect_next(cpu, 0x0605EB03u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0605EB03u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD60u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x0605E763u &&
                return_key != 0x0605E803u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0605EB0Bu: {
            static const uint8_t expected_epoch[] = { 0xBDu, 0x9Eu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD61u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            uint32_t cycles;
            uint32_t source_address;
            source_address = ((((uint32_t)cpu->dbr << 16u) + 0x000F9Eu) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_read8(cpu, bus, source_address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD64u;
            if (nh_scpu_expect_next(cpu, 0x0605EB23u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cycles = 4u + ((((uint32_t)0x9Eu + (uint32_t)cpu->x) > 0xFFu) ? 1u : 0u);
            return nh_scpu_finish(cpu, bus, cycles);
        }

        case 0x0605EB23u: {
            static const uint8_t expected_epoch[] = { 0x9Du, 0xA0u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD64u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint32_t destination_address;
            destination_address = ((((uint32_t)cpu->dbr << 16u) + 0x000FA0u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_write8(cpu, bus, destination_address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD67u;
            if (nh_scpu_expect_next(cpu, 0x0605EB3Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0605EB3Bu: {
            static const uint8_t expected_epoch[] = { 0x9Du, 0xA2u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD67u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint32_t destination_address;
            destination_address = ((((uint32_t)cpu->dbr << 16u) + 0x000FA2u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_write8(cpu, bus, destination_address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD6Au;
            if (nh_scpu_expect_next(cpu, 0x0605EB53u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0605EB53u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD6Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x0605E763u &&
                return_key != 0x0605E803u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0605EB5Bu: {
            static const uint8_t expected_epoch[] = { 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD6Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, cpu->p) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD6Cu;
            if (nh_scpu_expect_next(cpu, 0x0605EB63u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605EB63u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD6Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            cpu->x &= 0x00FFu;
            cpu->y &= 0x00FFu;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD6Eu;
            if (nh_scpu_expect_next(cpu, 0x0605EB73u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605EB73u: {
            static const uint8_t expected_epoch[] = { 0xBDu, 0x94u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD6Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            uint32_t cycles;
            uint32_t source_address;
            source_address = ((((uint32_t)cpu->dbr << 16u) + 0x000F94u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_read8(cpu, bus, source_address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD71u;
            if (nh_scpu_expect_next(cpu, 0x0605EB8Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cycles = 4u + ((((uint32_t)0x94u + (uint32_t)cpu->x) > 0xFFu) ? 1u : 0u);
            return nh_scpu_finish(cpu, bus, cycles);
        }

        case 0x0605EB8Bu: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x40u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD71u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBDB3u;
                if (nh_scpu_expect_next(cpu, 0x0605ED9Bu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD73u;
            if (nh_scpu_expect_next(cpu, 0x0605EB9Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605EB9Bu: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD73u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x10u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD75u;
            if (nh_scpu_expect_next(cpu, 0x0605EBABu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605EBABu: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x93u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD75u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F93u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD78u;
            if (nh_scpu_expect_next(cpu, 0x0605EBC3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605EBC3u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD78u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x01u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD7Au;
            if (nh_scpu_expect_next(cpu, 0x0605EBD3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605EBD3u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x16u, 0x40u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD7Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004016u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD7Du;
            if (nh_scpu_expect_next(cpu, 0x0605EBEBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605EBEBu: {
            static const uint8_t expected_epoch[] = { 0xBDu, 0x16u, 0x40u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD7Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            uint32_t cycles;
            uint32_t source_address;
            source_address = ((((uint32_t)cpu->dbr << 16u) + 0x004016u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_read8(cpu, bus, source_address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD80u;
            if (nh_scpu_expect_next(cpu, 0x0605EC03u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cycles = 4u + ((((uint32_t)0x16u + (uint32_t)cpu->x) > 0xFFu) ? 1u : 0u);
            return nh_scpu_finish(cpu, bus, cycles);
        }

        case 0x0605EC03u: {
            static const uint8_t expected_epoch[] = { 0x9Cu, 0x16u, 0x40u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD80u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004016u) & 0xFFFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD83u;
            if (nh_scpu_expect_next(cpu, 0x0605EC1Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605EC1Bu: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD83u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x01u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD85u;
            if (nh_scpu_expect_next(cpu, 0x0605EC2Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605EC2Bu: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x16u, 0x40u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD85u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004016u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD88u;
            if (nh_scpu_expect_next(cpu, 0x0605EC43u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605EC43u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD88u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x00u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD8Au;
            if (nh_scpu_expect_next(cpu, 0x0605EC53u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605EC53u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x16u, 0x40u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD8Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004016u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD8Du;
            if (nh_scpu_expect_next(cpu, 0x0605EC6Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605EC6Bu: {
            static const uint8_t expected_epoch[] = { 0x9Du, 0x98u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD8Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint32_t destination_address;
            destination_address = ((((uint32_t)cpu->dbr << 16u) + 0x000F98u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_write8(cpu, bus, destination_address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD90u;
            if (nh_scpu_expect_next(cpu, 0x0605EC83u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0605EC83u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD90u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x0Au;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD92u;
            if (nh_scpu_expect_next(cpu, 0x0605EC93u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605EC93u: {
            static const uint8_t expected_epoch[] = { 0xBDu, 0x16u, 0x40u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD92u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            uint32_t cycles;
            uint32_t source_address;
            source_address = ((((uint32_t)cpu->dbr << 16u) + 0x004016u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_read8(cpu, bus, source_address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD95u;
            if (nh_scpu_expect_next(cpu, 0x0605ECABu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cycles = 4u + ((((uint32_t)0x16u + (uint32_t)cpu->x) > 0xFFu) ? 1u : 0u);
            return nh_scpu_finish(cpu, bus, cycles);
        }

        case 0x0605ECABu: {
            static const uint8_t expected_epoch[] = { 0x88u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD95u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint8_t)(cpu->y - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD96u;
            if (nh_scpu_expect_next(cpu, 0x0605ECB3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605ECB3u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0xFAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD96u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBD92u;
                if (nh_scpu_expect_next(cpu, 0x0605EC93u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD98u;
            if (nh_scpu_expect_next(cpu, 0x0605ECC3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605ECC3u: {
            static const uint8_t expected_epoch[] = { 0xBDu, 0x16u, 0x40u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD98u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            uint32_t cycles;
            uint32_t source_address;
            source_address = ((((uint32_t)cpu->dbr << 16u) + 0x004016u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_read8(cpu, bus, source_address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD9Bu;
            if (nh_scpu_expect_next(cpu, 0x0605ECDBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cycles = 4u + ((((uint32_t)0x16u + (uint32_t)cpu->x) > 0xFFu) ? 1u : 0u);
            return nh_scpu_finish(cpu, bus, cycles);
        }

        case 0x0605ECDBu: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD9Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = (uint8_t)cpu->a;
            const uint8_t carry = (uint8_t)(value & 0x01u);
            value = (uint8_t)(value >> 1u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (value == 0u) cpu->p |= NH_P_Z;
            if ((value & 0x80u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD9Cu;
            if (nh_scpu_expect_next(cpu, 0x0605ECE3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605ECE3u: {
            static const uint8_t expected_epoch[] = { 0x3Eu, 0x98u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD9Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = (((((uint32_t)cpu->dbr << 16u) + 0x000F98u) + (uint32_t)cpu->x) & 0xFFFFFFu);
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t carry = (uint8_t)(value >> 7u);
            value = (uint8_t)((value << 1u) | ((cpu->p & NH_P_C) != 0u ? 1u : 0u));
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | (carry != 0u ? NH_P_C : 0u));
            if (nh_scpu_write8(cpu, bus, address, value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBD9Fu;
            if (nh_scpu_expect_next(cpu, 0x0605ECFBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u);
        }

        case 0x0605ECFBu: {
            static const uint8_t expected_epoch[] = { 0xBDu, 0x16u, 0x40u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BD9Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            uint32_t cycles;
            uint32_t source_address;
            source_address = ((((uint32_t)cpu->dbr << 16u) + 0x004016u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_read8(cpu, bus, source_address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBDA2u;
            if (nh_scpu_expect_next(cpu, 0x0605ED13u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cycles = 4u + ((((uint32_t)0x16u + (uint32_t)cpu->x) > 0xFFu) ? 1u : 0u);
            return nh_scpu_finish(cpu, bus, cycles);
        }

        case 0x0605ED13u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BDA2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = (uint8_t)cpu->a;
            const uint8_t carry = (uint8_t)(value & 0x01u);
            value = (uint8_t)(value >> 1u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (value == 0u) cpu->p |= NH_P_Z;
            if ((value & 0x80u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBDA3u;
            if (nh_scpu_expect_next(cpu, 0x0605ED1Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605ED1Bu: {
            static const uint8_t expected_epoch[] = { 0x3Eu, 0x98u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BDA3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t address = (((((uint32_t)cpu->dbr << 16u) + 0x000F98u) + (uint32_t)cpu->x) & 0xFFFFFFu);
            if (nh_scpu_read8(cpu, bus, address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t carry = (uint8_t)(value >> 7u);
            value = (uint8_t)((value << 1u) | ((cpu->p & NH_P_C) != 0u ? 1u : 0u));
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | (carry != 0u ? NH_P_C : 0u));
            if (nh_scpu_write8(cpu, bus, address, value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBDA6u;
            if (nh_scpu_expect_next(cpu, 0x0605ED33u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u);
        }

        case 0x0605ED33u: {
            static const uint8_t expected_epoch[] = { 0xBDu, 0x98u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BDA6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            uint32_t cycles;
            uint32_t source_address;
            source_address = ((((uint32_t)cpu->dbr << 16u) + 0x000F98u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_read8(cpu, bus, source_address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBDA9u;
            if (nh_scpu_expect_next(cpu, 0x0605ED4Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cycles = 4u + ((((uint32_t)0x98u + (uint32_t)cpu->x) > 0xFFu) ? 1u : 0u);
            return nh_scpu_finish(cpu, bus, cycles);
        }

        case 0x0605ED4Bu: {
            static const uint8_t expected_epoch[] = { 0xDDu, 0x96u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BDA9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t right = 0u;
            const uint32_t address = ((((uint32_t)cpu->dbr << 16u) + 0x000F96u) + (uint32_t)cpu->x) & 0xFFFFFFu;
            if (nh_scpu_read8(cpu, bus, address, &right) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t left = (uint8_t)cpu->a;
            const uint8_t result = (uint8_t)(left - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if (left >= right) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBDACu;
            if (nh_scpu_expect_next(cpu, 0x0605ED63u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u + (((0x96u + (uint32_t)cpu->x) > 0xFFu) ? 1u : 0u));
        }

        case 0x0605ED63u: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BDACu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBDB8u;
                if (nh_scpu_expect_next(cpu, 0x0605EDC3u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBDAEu;
            if (nh_scpu_expect_next(cpu, 0x0605ED73u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605ED73u: {
            static const uint8_t expected_epoch[] = { 0xCEu, 0x93u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BDAEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t right = 0u;
            const uint32_t address = (((uint32_t)cpu->dbr << 16u) + 0x000F93u);
            if (nh_scpu_read8(cpu, bus, address, &right) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t result = (uint8_t)(right - 1u);
            if (nh_scpu_write8(cpu, bus, address, result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBDB1u;
            if (nh_scpu_expect_next(cpu, 0x0605ED8Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0605ED8Bu: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0xC5u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BDB1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBD78u;
                if (nh_scpu_expect_next(cpu, 0x0605EBC3u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBDB3u;
            if (nh_scpu_expect_next(cpu, 0x0605ED9Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605ED9Bu: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x80u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BDB3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x80u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBDB5u;
            if (nh_scpu_expect_next(cpu, 0x0605EDABu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605EDABu: {
            static const uint8_t expected_epoch[] = { 0x9Du, 0x98u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BDB5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint32_t destination_address;
            destination_address = ((((uint32_t)cpu->dbr << 16u) + 0x000F98u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_write8(cpu, bus, destination_address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBDB8u;
            if (nh_scpu_expect_next(cpu, 0x0605EDC3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0605EDC3u: {
            static const uint8_t expected_epoch[] = { 0x28u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BDB8u,
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
            cpu->pc = 0xBDB9u;
            if (nh_scpu_expect_next(cpu, 0x0605EDCBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605EDCBu: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BDB9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x0605E7A3u &&
                return_key != 0x0605E843u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0605EF58u: {
            static const uint8_t expected_epoch[] = { 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BDEBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, cpu->p) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBDECu;
            if (nh_scpu_expect_next(cpu, 0x0605EF60u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605EF60u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BDECu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x30u);
            cpu->x &= 0x00FFu;
            cpu->y &= 0x00FFu;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBDEEu;
            if (nh_scpu_expect_next(cpu, 0x0605EF73u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605EF73u: {
            static const uint8_t expected_epoch[] = { 0x9Cu, 0xA8u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BDEEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA8u) & 0xFFFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBDF1u;
            if (nh_scpu_expect_next(cpu, 0x0605EF8Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605EF8Bu: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x94u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BDF1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F94u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBDF4u;
            if (nh_scpu_expect_next(cpu, 0x0605EFA3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605EFA3u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BDF4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xBDF9u;
                if (nh_scpu_expect_next(cpu, 0x0605EFCBu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBDF6u;
            if (nh_scpu_expect_next(cpu, 0x0605EFB3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605EFB3u: {
            static const uint8_t expected_epoch[] = { 0x4Cu, 0x7Au, 0xBEu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BDF6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE7Au;
            if (nh_scpu_expect_next(cpu, 0x0605F3D3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605EFCBu: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x9Eu, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BDF9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F9Eu) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBDFCu;
            if (nh_scpu_expect_next(cpu, 0x0605EFE3u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605EFE3u: {
            static const uint8_t expected_epoch[] = { 0x0Du, 0xA8u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BDFCu,
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
            cpu->pc = 0xBDFFu;
            if (nh_scpu_expect_next(cpu, 0x0605EFFBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605EFFBu: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0xA8u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0BDFFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA8u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xBE02u;
            if (nh_scpu_expect_next(cpu, 0x0605F013u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        default: return NH_SCPU_NOT_MINE;
    }
}
