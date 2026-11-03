/* Generated direct New Horizons S-CPU authority; do not edit. */
#include "nh_v07_generated.h"

NHScpuExecResult nh_v07_shard_00C0A4(NHScpuState *cpu, const NHScpuBus *bus) {
    switch (nh_scpu_context_key(cpu)) {
        case 0x06052021u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x00u, 0x80u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A404u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x8000u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA407u;
            if (nh_scpu_expect_next(cpu, 0x06052039u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06052039u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A407u,
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
            cpu->pc = 0xA408u;
            if (nh_scpu_expect_next(cpu, 0x06052041u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06052041u: {
            static const uint8_t expected_epoch[] = { 0x2Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A408u,
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
            cpu->pc = 0xA409u;
            if (nh_scpu_expect_next(cpu, 0x06052049u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06052049u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A409u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x060515D1u &&
                return_key != 0x06051869u &&
                return_key != 0x06051BD1u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06052051u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x00u, 0xC0u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A40Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0xC000u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA40Du;
            if (nh_scpu_expect_next(cpu, 0x06052069u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06052069u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A40Du,
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
            cpu->pc = 0xA40Eu;
            if (nh_scpu_expect_next(cpu, 0x06052071u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06052071u: {
            static const uint8_t expected_epoch[] = { 0x2Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A40Eu,
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
            cpu->pc = 0xA40Fu;
            if (nh_scpu_expect_next(cpu, 0x06052079u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06052079u: {
            static const uint8_t expected_epoch[] = { 0x2Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A40Fu,
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
            cpu->pc = 0xA410u;
            if (nh_scpu_expect_next(cpu, 0x06052081u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06052081u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A410u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x060515D1u &&
                return_key != 0x06051869u &&
                return_key != 0x06051BD1u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06052089u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0x00u, 0xE0u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A411u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0xE000u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA414u;
            if (nh_scpu_expect_next(cpu, 0x060520A1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060520A1u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A414u,
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
            cpu->pc = 0xA415u;
            if (nh_scpu_expect_next(cpu, 0x060520A9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060520A9u: {
            static const uint8_t expected_epoch[] = { 0x2Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A415u,
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
            cpu->pc = 0xA416u;
            if (nh_scpu_expect_next(cpu, 0x060520B1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060520B1u: {
            static const uint8_t expected_epoch[] = { 0x2Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A416u,
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
            cpu->pc = 0xA417u;
            if (nh_scpu_expect_next(cpu, 0x060520B9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060520B9u: {
            static const uint8_t expected_epoch[] = { 0x2Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A417u,
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
            cpu->pc = 0xA418u;
            if (nh_scpu_expect_next(cpu, 0x060520C1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060520C1u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A418u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x060515D1u &&
                return_key != 0x06051869u &&
                return_key != 0x06051BD1u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060520C9u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A419u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA41Au;
            if (nh_scpu_expect_next(cpu, 0x060520D1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060520D1u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A41Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA41Bu;
            if (nh_scpu_expect_next(cpu, 0x060520D9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060520D9u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A41Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA41Cu;
            if (nh_scpu_expect_next(cpu, 0x060520E1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060520E1u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A41Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA41Du;
            if (nh_scpu_expect_next(cpu, 0x060520E9u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060520E9u: {
            static const uint8_t expected_epoch[] = { 0xEBu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A41Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((cpu->a & 0x00FFu) << 8u) | (cpu->a >> 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA41Eu;
            if (nh_scpu_expect_next(cpu, 0x060520F1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060520F1u: {
            static const uint8_t expected_epoch[] = { 0x29u, 0xFFu, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A41Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & 0x00FFu);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA421u;
            if (nh_scpu_expect_next(cpu, 0x06052109u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06052109u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A421u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x060515D1u &&
                return_key != 0x06051869u &&
                return_key != 0x06051BD1u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06052111u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A422u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA423u;
            if (nh_scpu_expect_next(cpu, 0x06052119u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06052119u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A423u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA424u;
            if (nh_scpu_expect_next(cpu, 0x06052121u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06052121u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A424u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA425u;
            if (nh_scpu_expect_next(cpu, 0x06052129u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06052129u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A425u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA426u;
            if (nh_scpu_expect_next(cpu, 0x06052131u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06052131u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A426u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA427u;
            if (nh_scpu_expect_next(cpu, 0x06052139u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06052139u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A427u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA428u;
            if (nh_scpu_expect_next(cpu, 0x06052141u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06052141u: {
            static const uint8_t expected_epoch[] = { 0x4Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A428u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t carry = cpu->a & 0x0001u;
            cpu->a = (uint16_t)(cpu->a >> 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (carry != 0u) cpu->p |= NH_P_C;
            if (cpu->a == 0u) cpu->p |= NH_P_Z;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA429u;
            if (nh_scpu_expect_next(cpu, 0x06052149u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06052149u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A429u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            const uint32_t return_key = nh_scpu_context_key(cpu);
            if (return_key != 0x060515D1u &&
                return_key != 0x06051869u &&
                return_key != 0x06051BD1u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06052151u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A42Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA42Du;
            if (nh_scpu_expect_next(cpu, 0x06052169u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06052169u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A42Du,
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

        case 0x06052170u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A42Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA430u;
            if (nh_scpu_expect_next(cpu, 0x06052180u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06052180u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x54u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A430u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000054u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000055u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA432u;
            if (nh_scpu_expect_next(cpu, 0x06052190u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06052190u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A432u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA437u;
                if (nh_scpu_expect_next(cpu, 0x060521B8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA434u;
            if (nh_scpu_expect_next(cpu, 0x060521A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060521A0u: {
            static const uint8_t expected_epoch[] = { 0x9Cu, 0xA4u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A434u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000BA4u) & 0xFFFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000BA5u) & 0xFFFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA437u;
            if (nh_scpu_expect_next(cpu, 0x060521B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060521B8u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xA4u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A437u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000BA4u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000BA5u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA43Au;
            if (nh_scpu_expect_next(cpu, 0x060521D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060521D0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A43Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000068u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000069u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA43Cu;
            if (nh_scpu_expect_next(cpu, 0x060521E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060521E0u: {
            static const uint8_t expected_epoch[] = { 0x60u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A43Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_pull8(cpu, bus, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_pull8(cpu, bus, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pc = (uint16_t)((((uint16_t)high << 8u) | low) + 1u);
            if (nh_scpu_context_key(cpu) != 0x0604B198u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTS_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06052480u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x10u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A490u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x10u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA492u;
            if (nh_scpu_expect_next(cpu, 0x06052490u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06052490u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A492u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA494u;
            if (nh_scpu_expect_next(cpu, 0x060524A2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060524A2u: {
            static const uint8_t expected_epoch[] = { 0xA6u, 0x58u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A494u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000058u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000059u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA496u;
            if (nh_scpu_expect_next(cpu, 0x060524B2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060524B2u: {
            static const uint8_t expected_epoch[] = { 0x86u, 0x3Du };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A496u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00003Du) & 0xFFFFu), (uint8_t)cpu->x) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00003Eu) & 0xFFFFu), (uint8_t)(cpu->x >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA498u;
            if (nh_scpu_expect_next(cpu, 0x060524C2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060524C2u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x5Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A498u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00005Au) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA49Au;
            if (nh_scpu_expect_next(cpu, 0x060524D2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060524D2u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x3Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A49Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00003Fu) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA49Cu;
            if (nh_scpu_expect_next(cpu, 0x060524E2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060524E2u: {
            static const uint8_t expected_epoch[] = { 0xA6u, 0x56u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A49Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000056u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000057u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA49Eu;
            if (nh_scpu_expect_next(cpu, 0x060524F2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060524F2u: {
            static const uint8_t expected_epoch[] = { 0x8Eu, 0x68u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A49Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B68u) & 0xFFFFFFu), (uint8_t)cpu->x) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B69u) & 0xFFFFFFu), (uint8_t)(cpu->x >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4A1u;
            if (nh_scpu_expect_next(cpu, 0x0605250Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x0605250Au: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4A1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4A3u;
            if (nh_scpu_expect_next(cpu, 0x06052518u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06052518u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x54u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4A3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000054u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000055u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4A5u;
            if (nh_scpu_expect_next(cpu, 0x06052528u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06052528u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4A5u,
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
            cpu->pc = 0xA4A6u;
            if (nh_scpu_expect_next(cpu, 0x06052530u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06052530u: {
            static const uint8_t expected_epoch[] = { 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4A6u,
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
            cpu->pc = 0xA4A7u;
            if (nh_scpu_expect_next(cpu, 0x06052538u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06052538u: {
            static const uint8_t expected_epoch[] = { 0xAAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4A7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = cpu->a;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4A8u;
            if (nh_scpu_expect_next(cpu, 0x06052540u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06052540u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4A8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4ABu;
            if (nh_scpu_expect_next(cpu, 0x06052558u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x06052558u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4ABu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4ACu;
            if (nh_scpu_expect_next(cpu, 0x06052560u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06052560u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x3Du };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4ACu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00003Du) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00003Eu) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
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
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4AEu;
            if (nh_scpu_expect_next(cpu, 0x06052570u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x06052570u: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x53u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4AEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F53u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F54u) & 0xFFFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4B1u;
            if (nh_scpu_expect_next(cpu, 0x06052588u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06052588u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4B1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4B4u;
            if (nh_scpu_expect_next(cpu, 0x060525A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060525A0u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4B4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4B6u;
            if (nh_scpu_expect_next(cpu, 0x060525B2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060525B2u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0x27u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4B6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B27u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4B9u;
            if (nh_scpu_expect_next(cpu, 0x060525CAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060525CAu: {
            static const uint8_t expected_epoch[] = { 0x29u, 0xFEu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4B9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | ((uint8_t)cpu->a & 0xFEu));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4BBu;
            if (nh_scpu_expect_next(cpu, 0x060525DAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060525DAu: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x27u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4BBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B27u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4BEu;
            if (nh_scpu_expect_next(cpu, 0x060525F2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060525F2u: {
            static const uint8_t expected_epoch[] = { 0xCEu, 0x68u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4BEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B68u) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t result = (uint8_t)(value - 1u);
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B68u) & 0xFFFFFFu), result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4C1u;
            if (nh_scpu_expect_next(cpu, 0x0605260Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x0605260Au: {
            static const uint8_t expected_epoch[] = { 0x30u, 0x26u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4C1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA4E9u;
                if (nh_scpu_expect_next(cpu, 0x0605274Au) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4C3u;
            if (nh_scpu_expect_next(cpu, 0x0605261Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605261Au: {
            static const uint8_t expected_epoch[] = { 0xB7u, 0x3Du };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4C3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u, bank = 0u, value = 0u;
            uint32_t source_address;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00003Du) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00003Eu) & 0xFFFFu), &high) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00003Fu) & 0xFFFFu), &bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            source_address = ((((uint32_t)bank << 16u) | ((uint32_t)high << 8u) | low) + (uint32_t)cpu->y) & 0x00FFFFFFu;
            if (nh_scpu_read8(cpu, bus, source_address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4C5u;
            if (nh_scpu_expect_next(cpu, 0x0605262Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (6u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x0605262Au: {
            static const uint8_t expected_epoch[] = { 0x9Du, 0x02u, 0x09u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4C5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint32_t destination_address;
            destination_address = ((((uint32_t)cpu->dbr << 16u) + 0x000902u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_write8(cpu, bus, destination_address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4C8u;
            if (nh_scpu_expect_next(cpu, 0x06052642u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06052642u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4C8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4C9u;
            if (nh_scpu_expect_next(cpu, 0x0605264Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605264Au: {
            static const uint8_t expected_epoch[] = { 0xCCu, 0x53u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4C9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F53u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F54u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t left = cpu->y;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= value) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4CCu;
            if (nh_scpu_expect_next(cpu, 0x06052662u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x06052662u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x05u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4CCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA4D3u;
                if (nh_scpu_expect_next(cpu, 0x0605269Au) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4CEu;
            if (nh_scpu_expect_next(cpu, 0x06052672u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06052672u: {
            static const uint8_t expected_epoch[] = { 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4CEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, cpu->p) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4CFu;
            if (nh_scpu_expect_next(cpu, 0x0605267Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605267Au: {
            static const uint8_t expected_epoch[] = { 0x20u, 0x20u, 0x97u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4CFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xA4u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xD1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9720u;
            if (nh_scpu_expect_next(cpu, 0x0604B902u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06052690u: {
            static const uint8_t expected_epoch[] = { 0x28u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4D2u,
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
            cpu->pc = 0xA4D3u;
            if (nh_scpu_expect_next(cpu, 0x0605269Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605269Au: {
            static const uint8_t expected_epoch[] = { 0xB7u, 0x3Du };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4D3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u, bank = 0u, value = 0u;
            uint32_t source_address;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00003Du) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00003Eu) & 0xFFFFu), &high) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00003Fu) & 0xFFFFu), &bank) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            source_address = ((((uint32_t)bank << 16u) | ((uint32_t)high << 8u) | low) + (uint32_t)cpu->y) & 0x00FFFFFFu;
            if (nh_scpu_read8(cpu, bus, source_address, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4D5u;
            if (nh_scpu_expect_next(cpu, 0x060526AAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (6u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060526AAu: {
            static const uint8_t expected_epoch[] = { 0x9Du, 0x03u, 0x09u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4D5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint32_t destination_address;
            destination_address = ((((uint32_t)cpu->dbr << 16u) + 0x000903u) + (uint32_t)cpu->x) & 0x00FFFFFFu;
            if (nh_scpu_write8(cpu, bus, destination_address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4D8u;
            if (nh_scpu_expect_next(cpu, 0x060526C2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060526C2u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4D8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4D9u;
            if (nh_scpu_expect_next(cpu, 0x060526CAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060526CAu: {
            static const uint8_t expected_epoch[] = { 0xCCu, 0x53u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4D9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F53u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000F54u) & 0xFFFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t left = cpu->y;
            const uint16_t result = (uint16_t)(left - value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= value) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4DCu;
            if (nh_scpu_expect_next(cpu, 0x060526E2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060526E2u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x05u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4DCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA4E3u;
                if (nh_scpu_expect_next(cpu, 0x0605271Au) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4DEu;
            if (nh_scpu_expect_next(cpu, 0x060526F2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060526F2u: {
            static const uint8_t expected_epoch[] = { 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4DEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, cpu->p) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4DFu;
            if (nh_scpu_expect_next(cpu, 0x060526FAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060526FAu: {
            static const uint8_t expected_epoch[] = { 0x20u, 0x20u, 0x97u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4DFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xA4u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xE1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9720u;
            if (nh_scpu_expect_next(cpu, 0x0604B902u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06052710u: {
            static const uint8_t expected_epoch[] = { 0x28u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4E2u,
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
            cpu->pc = 0xA4E3u;
            if (nh_scpu_expect_next(cpu, 0x0605271Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605271Au: {
            static const uint8_t expected_epoch[] = { 0xE8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4E3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(cpu->x + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4E4u;
            if (nh_scpu_expect_next(cpu, 0x06052722u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06052722u: {
            static const uint8_t expected_epoch[] = { 0xE8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4E4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(cpu->x + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4E5u;
            if (nh_scpu_expect_next(cpu, 0x0605272Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605272Au: {
            static const uint8_t expected_epoch[] = { 0xE8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4E5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(cpu->x + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4E6u;
            if (nh_scpu_expect_next(cpu, 0x06052732u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06052732u: {
            static const uint8_t expected_epoch[] = { 0xE8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4E6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(cpu->x + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4E7u;
            if (nh_scpu_expect_next(cpu, 0x0605273Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x0605273Au: {
            static const uint8_t expected_epoch[] = { 0x80u, 0xD5u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4E7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4BEu;
            if (nh_scpu_expect_next(cpu, 0x060525F2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x0605274Au: {
            static const uint8_t expected_epoch[] = { 0xCEu, 0x68u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4E9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B68u) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint8_t result = (uint8_t)(value - 1u);
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B68u) & 0xFFFFFFu), result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4ECu;
            if (nh_scpu_expect_next(cpu, 0x06052762u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x06052762u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0xFBu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4ECu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA4E9u;
                if (nh_scpu_expect_next(cpu, 0x0605274Au) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4EEu;
            if (nh_scpu_expect_next(cpu, 0x06052772u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06052772u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4EEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | 0x01u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4F0u;
            if (nh_scpu_expect_next(cpu, 0x06052782u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x06052782u: {
            static const uint8_t expected_epoch[] = { 0x0Du, 0x27u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4F0u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B27u) & 0xFFFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | ((uint8_t)cpu->a | value));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4F3u;
            if (nh_scpu_expect_next(cpu, 0x0605279Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x0605279Au: {
            static const uint8_t expected_epoch[] = { 0x8Du, 0x27u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4F3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B27u) & 0xFFFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4F6u;
            if (nh_scpu_expect_next(cpu, 0x060527B2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060527B2u: {
            static const uint8_t expected_epoch[] = { 0xADu, 0xC7u, 0x0Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4F6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u;
            if (nh_scpu_read8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000EC7u) & 0xFFFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | low);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4F9u;
            if (nh_scpu_expect_next(cpu, 0x060527CAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060527CAu: {
            static const uint8_t expected_epoch[] = { 0xF0u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4F9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) != 0u) {
                cpu->pbr = 0xC0u;
                cpu->pc = 0xA501u;
                if (nh_scpu_expect_next(cpu, 0x0605280Au) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA4FBu;
            if (nh_scpu_expect_next(cpu, 0x060527DAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060527DAu: {
            static const uint8_t expected_epoch[] = { 0x20u, 0x38u, 0x95u };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4FBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xA4u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFDu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC0u;
            cpu->pc = 0x9538u;
            if (nh_scpu_expect_next(cpu, 0x0604A9C2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060527F2u: {
            static const uint8_t expected_epoch[] = { 0x9Cu, 0x27u, 0x0Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC0A4FEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, ((((uint32_t)cpu->dbr << 16u) + 0x000B27u) & 0xFFFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC0u;
            cpu->pc = 0xA501u;
            if (nh_scpu_expect_next(cpu, 0x0605280Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        default: return NH_SCPU_NOT_MINE;
    }
}
