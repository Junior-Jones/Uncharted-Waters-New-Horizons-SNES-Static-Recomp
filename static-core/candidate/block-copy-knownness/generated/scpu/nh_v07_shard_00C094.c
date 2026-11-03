/* Generated direct New Horizons S-CPU authority; do not edit. */
#include "nh_v07_generated.h"

NHScpuExecResult nh_v07_shard_00C094(NHScpuState *cpu, const NHScpuBus *bus) {
    switch (nh_scpu_context_key(cpu)) {
        case 0x0604A000u: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09400u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0x9405u;
                if (nh_scpu_expect_next(cpu, 0x0604A028u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9402u;
            if (nh_scpu_expect_next(cpu, 0x0604A010u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A010u: {
            static const uint8_t expected_epoch[] = { 0xCEu, 0xA3u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09402u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000EA3u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000EA4u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t result = (uint16_t)(value - 1u);
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000EA4u) & 0xFFFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000EA3u) & 0xFFFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9405u;
            if (nh_scpu_expect_next(cpu, 0x0604A028u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x0604A028u: {
            static const uint8_t expected_epoch[] = { 0x9Cu, 0xBBu, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09405u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000EBBu) & 0xFFFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000EBCu) & 0xFFFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9408u;
            if (nh_scpu_expect_next(cpu, 0x0604A040u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604A040u: {
            static const uint8_t expected_epoch[] = { 0xA2u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09408u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x940Bu;
            if (nh_scpu_expect_next(cpu, 0x0604A058u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A058u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0940Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x940Eu;
            if (nh_scpu_expect_next(cpu, 0x0604A070u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A070u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0940Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9410u;
            if (nh_scpu_expect_next(cpu, 0x0604A082u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A082u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x80u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09410u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x80u);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9412u;
            if (nh_scpu_expect_next(cpu, 0x0604A092u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A092u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0xB9u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09412u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000EB9u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9415u;
            if (nh_scpu_expect_next(cpu, 0x0604A0AAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A0AAu: {
            static const uint8_t expected_epoch[] = { 0xB9u, 0xA9u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09415u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            const uint32_t source_address = ((((uint32_t)cpu->dbr << 16u) + 0x000EA9u) + (uint32_t)cpu->y) & 0x00FFFFFFu;
            if (nh_scpu_read8(cpu, bus, source_address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9418u;
            if (nh_scpu_expect_next(cpu, 0x0604A0C2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604A0C2u: {
            static const uint8_t expected_epoch[] = { 0x2Du, 0xB9u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09418u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000EB9u) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | ((uint8_t)cpu->a & value));
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x941Bu;
            if (nh_scpu_expect_next(cpu, 0x0604A0DAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A0DAu: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x0Du };
            if (nh_scpu_guard_code(cpu, bus, 0xC0941Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0x942Au;
                if (nh_scpu_expect_next(cpu, 0x0604A152u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0x941Du;
            if (nh_scpu_expect_next(cpu, 0x0604A0EAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A0EAu: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0941Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x941Fu;
            if (nh_scpu_expect_next(cpu, 0x0604A0F8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A0F8u: {
            static const uint8_t expected_epoch[] = { 0xBDu, 0x02u, 0x09u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0941Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint32_t source_address;
            source_address = ((((uint32_t)cpu->dbr << 16u) + 0x000902u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_read8(cpu, bus, source_address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (source_address + 1u) & 0x00FFFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9422u;
            if (nh_scpu_expect_next(cpu, 0x0604A110u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0604A110u: {
            static const uint8_t expected_epoch[] = { 0x4Du, 0xA7u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09422u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t lo = 0u, hi = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000EA7u) & 0xFFFFFFu), &lo) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000EA8u) & 0xFFFFFFu), &hi) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a ^ ((uint16_t)lo | ((uint16_t)hi << 8)));
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9425u;
            if (nh_scpu_expect_next(cpu, 0x0604A128u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604A128u: {
            static const uint8_t expected_epoch[] = { 0x9Du, 0x02u, 0x09u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09425u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint32_t destination_address;
            destination_address = ((((uint32_t)cpu->dbr << 16u) + 0x000902u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_write8(cpu, bus, destination_address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (destination_address + 1u) & 0x00FFFFFFu, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9428u;
            if (nh_scpu_expect_next(cpu, 0x0604A140u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0604A140u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09428u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x942Au;
            if (nh_scpu_expect_next(cpu, 0x0604A152u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A152u: {
            static const uint8_t expected_epoch[] = { 0xE8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0942Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(cpu->x + 1u);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x942Bu;
            if (nh_scpu_expect_next(cpu, 0x0604A15Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A15Au: {
            static const uint8_t expected_epoch[] = { 0xE8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0942Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(cpu->x + 1u);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x942Cu;
            if (nh_scpu_expect_next(cpu, 0x0604A162u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A162u: {
            static const uint8_t expected_epoch[] = { 0xE8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0942Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(cpu->x + 1u);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x942Du;
            if (nh_scpu_expect_next(cpu, 0x0604A16Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A16Au: {
            static const uint8_t expected_epoch[] = { 0xE8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0942Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(cpu->x + 1u);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x942Eu;
            if (nh_scpu_expect_next(cpu, 0x0604A172u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A172u: {
            static const uint8_t expected_epoch[] = { 0x4Eu, 0xB9u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0942Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000EB9u) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | (value & 1u));
            value = (uint8_t)(value >> 1);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000EB9u) & 0xFFFFFFu), value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9431u;
            if (nh_scpu_expect_next(cpu, 0x0604A18Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0604A18Au: {
            static const uint8_t expected_epoch[] = { 0x90u, 0xE2u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09431u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0x9415u;
                if (nh_scpu_expect_next(cpu, 0x0604A0AAu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9433u;
            if (nh_scpu_expect_next(cpu, 0x0604A19Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A19Au: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x80u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09433u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x80u);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9435u;
            if (nh_scpu_expect_next(cpu, 0x0604A1AAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A1AAu: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0xB9u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09435u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000EB9u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9438u;
            if (nh_scpu_expect_next(cpu, 0x0604A1C2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A1C2u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09438u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9439u;
            if (nh_scpu_expect_next(cpu, 0x0604A1CAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A1CAu: {
            static const uint8_t expected_epoch[] = { 0xC0u, 0x10u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09439u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->y;
            const uint16_t result = (uint16_t)(left - 0x0010u);
            cpu->p = (uint8_t)(cpu->p & 0x7Cu);
            if (left >= 0x0010u) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x943Cu;
            if (nh_scpu_expect_next(cpu, 0x0604A1E2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A1E2u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0xD7u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0943Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0x9415u;
                if (nh_scpu_expect_next(cpu, 0x0604A0AAu) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0x943Eu;
            if (nh_scpu_expect_next(cpu, 0x0604A1F2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A1F2u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0943Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x01u);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9440u;
            if (nh_scpu_expect_next(cpu, 0x0604A202u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A202u: {
            static const uint8_t expected_epoch[] = { 0x0Du, 0x27u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09440u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B27u) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | ((uint8_t)cpu->a | value));
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9443u;
            if (nh_scpu_expect_next(cpu, 0x0604A21Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A21Au: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x27u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09443u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B27u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9446u;
            if (nh_scpu_expect_next(cpu, 0x0604A232u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A230u: {
            static const uint8_t expected_epoch[] = { 0x28u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09446u,
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
            cpu->pc = 0x9447u;
            if (nh_scpu_expect_next(cpu, 0x0604A23Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A232u: {
            static const uint8_t expected_epoch[] = { 0x28u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09446u,
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
            cpu->pc = 0x9447u;
            if (nh_scpu_expect_next(cpu, 0x0604A23Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A23Au: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09447u,
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
            if (return_key != 0x0004B86Au)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0604A242u: {
            static const uint8_t expected_epoch[] = { 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09448u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, cpu->p) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9449u;
            if (nh_scpu_expect_next(cpu, 0x0604A24Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A24Au: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09449u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x944Bu;
            if (nh_scpu_expect_next(cpu, 0x0604A25Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A25Au: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0944Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x944Du;
            if (nh_scpu_expect_next(cpu, 0x0604A26Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A26Au: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xC6u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0944Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000EC6u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9450u;
            if (nh_scpu_expect_next(cpu, 0x0604A282u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A282u: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x2Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09450u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0x947Eu;
                if (nh_scpu_expect_next(cpu, 0x0604A3F2u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9452u;
            if (nh_scpu_expect_next(cpu, 0x0604A292u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A292u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09452u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9454u;
            if (nh_scpu_expect_next(cpu, 0x0604A2A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A2A0u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09454u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0100u;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9457u;
            if (nh_scpu_expect_next(cpu, 0x0604A2B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A2B8u: {
            static const uint8_t expected_epoch[] = { 0x5Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09457u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->d = cpu->a;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->d) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->d) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9458u;
            if (nh_scpu_expect_next(cpu, 0x0604A2C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A2C0u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0xFFu, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09458u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x01FFu;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x945Bu;
            if (nh_scpu_expect_next(cpu, 0x0604A2D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A2D8u: {
            static const uint8_t expected_epoch[] = { 0xA2u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0945Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x945Eu;
            if (nh_scpu_expect_next(cpu, 0x0604A2F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A2F0u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x00u, 0x1Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0945Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x1C00u;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9461u;
            if (nh_scpu_expect_next(cpu, 0x0604A308u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A308u: {
            static const uint8_t expected_epoch[] = { 0x8Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09461u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, cpu->dbr) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9462u;
            if (nh_scpu_expect_next(cpu, 0x0604A310u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A310u: {
            static const uint8_t expected_epoch[] = { 0x54u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09462u,
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
                cpu->pc = 0x9462u;
                if (nh_scpu_expect_next(cpu, 0x0604A310u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 7u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9465u;
            if (nh_scpu_expect_next(cpu, 0x0604A328u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u);
        }

        case 0x0604A328u: {
            static const uint8_t expected_epoch[] = { 0xABu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09465u,
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
            cpu->pc = 0x9466u;
            if (nh_scpu_expect_next(cpu, 0x0604A330u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A330u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x82u, 0x94u, 0xC0u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09466u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x94u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x69u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9482u;
            if (nh_scpu_expect_next(cpu, 0x0604A410u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x0604A350u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0946Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & 0xCFu);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x946Cu;
            if (nh_scpu_expect_next(cpu, 0x0604A360u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A360u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0xFFu, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0946Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x01FFu;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x946Fu;
            if (nh_scpu_expect_next(cpu, 0x0604A378u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A378u: {
            static const uint8_t expected_epoch[] = { 0xA2u, 0x00u, 0x1Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0946Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = 0x1C00u;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9472u;
            if (nh_scpu_expect_next(cpu, 0x0604A390u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A390u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09472u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9475u;
            if (nh_scpu_expect_next(cpu, 0x0604A3A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A3A8u: {
            static const uint8_t expected_epoch[] = { 0x8Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09475u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, cpu->dbr) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9476u;
            if (nh_scpu_expect_next(cpu, 0x0604A3B0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A3B0u: {
            static const uint8_t expected_epoch[] = { 0x54u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09476u,
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
                cpu->pc = 0x9476u;
                if (nh_scpu_expect_next(cpu, 0x0604A3B0u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 7u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9479u;
            if (nh_scpu_expect_next(cpu, 0x0604A3C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 7u);
        }

        case 0x0604A3C8u: {
            static const uint8_t expected_epoch[] = { 0xABu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09479u,
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
            cpu->pc = 0x947Au;
            if (nh_scpu_expect_next(cpu, 0x0604A3D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A3D0u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0947Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x947Du;
            if (nh_scpu_expect_next(cpu, 0x0604A3E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A3E8u: {
            static const uint8_t expected_epoch[] = { 0x5Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0947Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->d = cpu->a;
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->d) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->d) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x947Eu;
            if (nh_scpu_expect_next(cpu, 0x0604A3F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A3F0u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0947Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9480u;
            if (nh_scpu_expect_next(cpu, 0x0604A402u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A3F2u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0947Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9480u;
            if (nh_scpu_expect_next(cpu, 0x0604A402u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A402u: {
            static const uint8_t expected_epoch[] = { 0x28u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09480u,
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
            cpu->pc = 0x9481u;
            if (nh_scpu_expect_next(cpu, 0x0604A40Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A40Au: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09481u,
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
            if (return_key != 0x0004B7EAu)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0604A410u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09482u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9484u;
            if (nh_scpu_expect_next(cpu, 0x0604A420u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A420u: {
            static const uint8_t expected_epoch[] = { 0xDCu, 0xC3u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09484u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u, bank = 0u;
            if (nh_scpu_read8(cpu, bus, 0x0EC3u, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, 0x0EC4u, &high) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, 0x0EC5u, &bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t target_address = (uint32_t)low | ((uint32_t)high << 8u) | ((uint32_t)bank << 16u);
            if (!(target_address == 0xCDA492u || target_address == 0xCDB7E1u))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_INDIRECT_LONG_TARGET");
            cpu->pbr = bank;
            cpu->pc = (uint16_t)(low | ((uint16_t)high << 8u));
            const uint32_t target_key = nh_scpu_context_key(cpu);
            if (nh_scpu_expect_next(cpu, target_key) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0604A442u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09488u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x948Au;
            if (nh_scpu_expect_next(cpu, 0x0604A452u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A452u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xB6u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0948Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FB6u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x948Du;
            if (nh_scpu_expect_next(cpu, 0x0604A46Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A46Au: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x22u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0948Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0x94B1u;
                if (nh_scpu_expect_next(cpu, 0x0604A58Au) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0x948Fu;
            if (nh_scpu_expect_next(cpu, 0x0604A47Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A47Au: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0xFEu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0948Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0xFEu);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9491u;
            if (nh_scpu_expect_next(cpu, 0x0604A48Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A48Au: {
            static const uint8_t expected_epoch[] = { 0x2Du, 0x27u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09491u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B27u) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | ((uint8_t)cpu->a & value));
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9494u;
            if (nh_scpu_expect_next(cpu, 0x0604A4A2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A4A2u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x27u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09494u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B27u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9497u;
            if (nh_scpu_expect_next(cpu, 0x0604A4BAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A4BAu: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xC09497u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9499u;
            if (nh_scpu_expect_next(cpu, 0x0604A4CAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A4CAu: {
            static const uint8_t expected_epoch[] = { 0xAEu, 0xB4u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC09499u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FB4u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FB5u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x949Cu;
            if (nh_scpu_expect_next(cpu, 0x0604A4E2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604A4E2u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xA6u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0949Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA6u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x949Fu;
            if (nh_scpu_expect_next(cpu, 0x0604A4FAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A4FAu: {
            static const uint8_t expected_epoch[] = { 0x9Du, 0x00u, 0x09u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0949Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint32_t destination_address;
            destination_address = ((((uint32_t)cpu->dbr << 16u) + 0x000900u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_write8(cpu, bus, destination_address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94A2u;
            if (nh_scpu_expect_next(cpu, 0x0604A512u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604A512u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xA7u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC094A2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000FA7u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94A5u;
            if (nh_scpu_expect_next(cpu, 0x0604A52Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A52Au: {
            static const uint8_t expected_epoch[] = { 0x3Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC094A5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t low = (uint8_t)cpu->a;
            const uint8_t value = (uint8_t)(low - 1u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94A6u;
            if (nh_scpu_expect_next(cpu, 0x0604A532u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A532u: {
            static const uint8_t expected_epoch[] = { 0x9Du, 0x01u, 0x09u };
            if (nh_scpu_guard_code(cpu, bus, 0xC094A6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint32_t destination_address;
            destination_address = ((((uint32_t)cpu->dbr << 16u) + 0x000901u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_write8(cpu, bus, destination_address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94A9u;
            if (nh_scpu_expect_next(cpu, 0x0604A54Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604A54Au: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC094A9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x01u);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94ABu;
            if (nh_scpu_expect_next(cpu, 0x0604A55Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A55Au: {
            static const uint8_t expected_epoch[] = { 0x0Du, 0x27u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC094ABu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B27u) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | ((uint8_t)cpu->a | value));
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94AEu;
            if (nh_scpu_expect_next(cpu, 0x0604A572u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A572u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x27u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC094AEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B27u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94B1u;
            if (nh_scpu_expect_next(cpu, 0x0604A58Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A58Au: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC094B1u,
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
            if (return_key != 0x0004B88Au)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0604A592u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xC094B2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94B4u;
            if (nh_scpu_expect_next(cpu, 0x0604A5A2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A5A2u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC094B4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94B6u;
            if (nh_scpu_expect_next(cpu, 0x0604A5B2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A5B2u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x3Fu, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC094B6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B3Fu) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94B9u;
            if (nh_scpu_expect_next(cpu, 0x0604A5CAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A5CAu: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x00u, 0x21u };
            if (nh_scpu_guard_code(cpu, bus, 0xC094B9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x002100u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94BCu;
            if (nh_scpu_expect_next(cpu, 0x0604A5E2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A5E2u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC094BCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x0604C33Au &&
                return_key != 0x0604FE32u &&
                return_key != 0x0604FF42u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0604A662u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xC094CCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94CEu;
            if (nh_scpu_expect_next(cpu, 0x0604A672u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A672u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC094CEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94D0u;
            if (nh_scpu_expect_next(cpu, 0x0604A682u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A682u: {
            static const uint8_t expected_epoch[] = { 0x8Eu, 0x04u, 0x42u };
            if (nh_scpu_guard_code(cpu, bus, 0xC094D0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004204u) & 0xFFFFFFu), (uint8_t)cpu->x) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004205u) & 0xFFFFFFu), (uint8_t)(cpu->x >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94D3u;
            if (nh_scpu_expect_next(cpu, 0x0604A69Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604A69Au: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x06u, 0x42u };
            if (nh_scpu_guard_code(cpu, bus, 0xC094D3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004206u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94D6u;
            if (nh_scpu_expect_next(cpu, 0x0604A6B2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A6B2u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC094D6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x03u);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94D8u;
            if (nh_scpu_expect_next(cpu, 0x0604A6C2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A6C2u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC094D8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94D9u;
            if (nh_scpu_expect_next(cpu, 0x0604A6CAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A6CAu: {
            static const uint8_t expected_epoch[] = { 0x3Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC094D9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t low = (uint8_t)cpu->a;
            const uint8_t value = (uint8_t)(low - 1u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94DAu;
            if (nh_scpu_expect_next(cpu, 0x0604A6D2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A6D2u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0xFCu };
            if (nh_scpu_guard_code(cpu, bus, 0xC094DAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0x94D8u;
                if (nh_scpu_expect_next(cpu, 0x0604A6C2u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94DCu;
            if (nh_scpu_expect_next(cpu, 0x0604A6E2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A6E2u: {
            static const uint8_t expected_epoch[] = { 0xAEu, 0x14u, 0x42u };
            if (nh_scpu_guard_code(cpu, bus, 0xC094DCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004214u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004215u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94DFu;
            if (nh_scpu_expect_next(cpu, 0x0604A6FAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604A6FAu: {
            static const uint8_t expected_epoch[] = { 0x8Eu, 0x64u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC094DFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B64u) & 0xFFFFFFu), (uint8_t)cpu->x) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B65u) & 0xFFFFFFu), (uint8_t)(cpu->x >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94E2u;
            if (nh_scpu_expect_next(cpu, 0x0604A712u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604A712u: {
            static const uint8_t expected_epoch[] = { 0xAEu, 0x16u, 0x42u };
            if (nh_scpu_guard_code(cpu, bus, 0xC094E2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004216u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004217u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94E5u;
            if (nh_scpu_expect_next(cpu, 0x0604A72Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604A72Au: {
            static const uint8_t expected_epoch[] = { 0x8Eu, 0x66u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC094E5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B66u) & 0xFFFFFFu), (uint8_t)cpu->x) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B67u) & 0xFFFFFFu), (uint8_t)(cpu->x >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94E8u;
            if (nh_scpu_expect_next(cpu, 0x0604A742u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604A742u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC094E8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x0604E4C2u &&
                return_key != 0x0604ED42u &&
                return_key != 0x0605B07Au &&
                return_key != 0x0605C5BAu &&
                return_key != 0x0605D4C2u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0604A74Au: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xC094E9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & 0xEFu);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94EBu;
            if (nh_scpu_expect_next(cpu, 0x0604A75Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A75Au: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC094EBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94EDu;
            if (nh_scpu_expect_next(cpu, 0x0604A76Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A76Au: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x12u, 0x42u };
            if (nh_scpu_guard_code(cpu, bus, 0xC094EDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004212u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94F0u;
            if (nh_scpu_expect_next(cpu, 0x0604A782u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0604A782u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC094F0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = (uint8_t)cpu->a;
            const uint8_t carry = (uint8_t)(value & 0x01u);
            value = (uint8_t)(value >> 1u);
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & 0x7Cu);
            if (carry != 0u) cpu->p |= NH_P_C;
            if (value == 0u) cpu->p |= NH_P_Z;
            if ((value & 0x80u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94F1u;
            if (nh_scpu_expect_next(cpu, 0x0604A78Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A78Au: {
            static const uint8_t expected_epoch[] = { 0xB0u, 0xFAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC094F1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0x94EDu;
                if (nh_scpu_expect_next(cpu, 0x0604A76Au) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94F3u;
            if (nh_scpu_expect_next(cpu, 0x0604A79Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A79Au: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC094F3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & 0xDFu);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94F5u;
            if (nh_scpu_expect_next(cpu, 0x0604A7A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A7A8u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x18u, 0x42u };
            if (nh_scpu_guard_code(cpu, bus, 0xC094F5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004218u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x004219u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94F8u;
            if (nh_scpu_expect_next(cpu, 0x0604A7C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0604A7C0u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC094F8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & 0x7Cu);
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94F9u;
            if (nh_scpu_expect_next(cpu, 0x0604A7C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A7C8u: {
            static const uint8_t expected_epoch[] = { 0xB0u, 0x14u };
            if (nh_scpu_guard_code(cpu, bus, 0xC094F9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0x950Fu;
                if (nh_scpu_expect_next(cpu, 0x0604A878u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94FBu;
            if (nh_scpu_expect_next(cpu, 0x0604A7D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A7D8u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC094FBu,
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
            cpu->pc = 0x94FCu;
            if (nh_scpu_expect_next(cpu, 0x0604A7E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0604A7E0u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0xF0u, 0xFFu };
            if (nh_scpu_guard_code(cpu, bus, 0xC094FCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0xFFF0u);
            cpu->p = (uint8_t)(cpu->p & 0x7Du);
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x94FFu;
            if (nh_scpu_expect_next(cpu, 0x0604A7F8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0604A7F8u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x56u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC094FFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B56u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B57u) & 0xFFFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9502u;
            if (nh_scpu_expect_next(cpu, 0x0604A810u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        default: return NH_SCPU_NOT_MINE;
    }
}
