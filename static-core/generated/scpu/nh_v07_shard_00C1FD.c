/* Generated direct New Horizons S-CPU authority; do not edit. */
#include "nh_v07_generated.h"

NHScpuExecResult nh_v07_shard_00C1FD(NHScpuState *cpu, const NHScpuBus *bus) {
    switch (nh_scpu_context_key(cpu)) {
        case 0x060FE810u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD02u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000006u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000007u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD04u;
            if (nh_scpu_expect_next(cpu, 0x060FE820u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE820u: {
            static const uint8_t expected_epoch[] = { 0x10u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD04u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFD07u;
                if (nh_scpu_expect_next(cpu, 0x060FE838u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD06u;
            if (nh_scpu_expect_next(cpu, 0x060FE830u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FE830u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD06u,
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
            if ((return_key != 0x06085208u && (return_key != 0x064C4E58u && return_key != 0x064C5398u)))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FE838u: {
            static const uint8_t expected_epoch[] = { 0x46u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD07u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(low | ((uint16_t)high << 8u));
            const uint16_t result = (uint16_t)(value >> 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | ((value & 1u) != 0u ? NH_P_C : 0u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD09u;
            if (nh_scpu_expect_next(cpu, 0x060FE848u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE848u: {
            static const uint8_t expected_epoch[] = { 0x66u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD09u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(low | ((uint16_t)high << 8u));
            const uint16_t result = (uint16_t)((value >> 1u) | ((cpu->p & NH_P_C) != 0u ? 0x8000u : 0u));
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | ((value & 1u) != 0u ? NH_P_C : 0u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD0Bu;
            if (nh_scpu_expect_next(cpu, 0x060FE858u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE858u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0xE8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD0Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCF5u;
            if (nh_scpu_expect_next(cpu, 0x060FE7A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FE920u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD24u,
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
            cpu->pc = 0xFD26u;
            if (nh_scpu_expect_next(cpu, 0x060FE930u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE930u: {
            static const uint8_t expected_epoch[] = { 0x25u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD26u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a & (uint16_t)(low | ((uint16_t)high << 8u)));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD28u;
            if (nh_scpu_expect_next(cpu, 0x060FE940u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE940u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD28u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD2Au;
            if (nh_scpu_expect_next(cpu, 0x060FE950u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE950u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD2Au,
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
            if (((return_key != 0x061141D0u && (return_key != 0x06114300u && return_key != 0x061144C0u)) && (return_key != 0x06114608u && (return_key != 0x064C4800u && return_key != 0x064D40D8u))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FE9C0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD38u,
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
            cpu->pc = 0xFD3Au;
            if (nh_scpu_expect_next(cpu, 0x060FE9D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE9D0u: {
            static const uint8_t expected_epoch[] = { 0x05u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD3Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a | (uint16_t)(low | ((uint16_t)high << 8u)));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD3Cu;
            if (nh_scpu_expect_next(cpu, 0x060FE9E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE9E0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD3Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD3Eu;
            if (nh_scpu_expect_next(cpu, 0x060FE9F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FE9F0u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD3Eu,
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
            if (((((return_key != 0x06091330u && (return_key != 0x06093FA8u && return_key != 0x060E6630u)) && ((return_key != 0x060E67D0u && return_key != 0x060E96B0u) && (return_key != 0x061D5B78u && return_key != 0x061D6520u))) && ((return_key != 0x061D72A8u && (return_key != 0x061D7C50u && return_key != 0x06210978u)) && ((return_key != 0x06240FA8u && return_key != 0x062A2018u) && (return_key != 0x06316B48u && return_key != 0x06319178u)))) && (((return_key != 0x063A5340u && (return_key != 0x063C6F00u && return_key != 0x064078A0u)) && ((return_key != 0x06411D78u && return_key != 0x06421E08u) && (return_key != 0x064C4478u && return_key != 0x064D4390u))) && ((return_key != 0x0660C920u && (return_key != 0x066121A8u && return_key != 0x066148E8u)) && ((return_key != 0x06614960u && return_key != 0x066178F0u) && (return_key != 0x06618108u && return_key != 0x066A0B48u))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FEA60u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD4Cu,
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
            cpu->pc = 0xFD4Eu;
            if (nh_scpu_expect_next(cpu, 0x060FEA70u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEA70u: {
            static const uint8_t expected_epoch[] = { 0x45u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD4Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a ^ (uint16_t)(low | ((uint16_t)high << 8u)));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD50u;
            if (nh_scpu_expect_next(cpu, 0x060FEA80u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEA80u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD50u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD52u;
            if (nh_scpu_expect_next(cpu, 0x060FEA90u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEA90u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD52u,
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
            if ((return_key != 0x0632B700u && (return_key != 0x0632BA08u && return_key != 0x0632BD10u)))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FEB00u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD60u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD61u;
            if (nh_scpu_expect_next(cpu, 0x060FEB08u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FEB08u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD61u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD64u;
            if (nh_scpu_expect_next(cpu, 0x060FEB20u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FEB20u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD64u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
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
            cpu->pc = 0xFD66u;
            if (nh_scpu_expect_next(cpu, 0x060FEB30u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEB30u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD66u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD68u;
            if (nh_scpu_expect_next(cpu, 0x060FEB40u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEB40u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD68u,
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
            if ((((((((((return_key != 0x06080120u && (return_key != 0x060801A8u && return_key != 0x06080230u)) && (return_key != 0x06085350u && (return_key != 0x06086058u && return_key != 0x060860F0u))) && ((return_key != 0x0608FE88u && (return_key != 0x0608FED0u && return_key != 0x0608FFB8u)) && ((return_key != 0x06090000u && return_key != 0x06090788u) && (return_key != 0x06090810u && return_key != 0x060908E0u)))) && (((return_key != 0x06090D70u && (return_key != 0x060911C0u && return_key != 0x060913E0u)) && (return_key != 0x06092B00u && (return_key != 0x06092B48u && return_key != 0x06092C30u))) && ((return_key != 0x06092C78u && (return_key != 0x06093400u && return_key != 0x06093488u)) && ((return_key != 0x06093558u && return_key != 0x060939E8u) && (return_key != 0x06093E38u && return_key != 0x06094058u))))) && ((((return_key != 0x06095E18u && (return_key != 0x06095E60u && return_key != 0x06095FB0u)) && (return_key != 0x06096248u && (return_key != 0x060A0AF0u && return_key != 0x060A0C10u))) && ((return_key != 0x060A0E00u && (return_key != 0x060A0F40u && return_key != 0x060A20A0u)) && ((return_key != 0x060B3180u && return_key != 0x060B31D8u) && (return_key != 0x060B69A8u && return_key != 0x060C14D0u)))) && (((return_key != 0x060C1860u && (return_key != 0x060C1D20u && return_key != 0x060C1DE0u)) && (return_key != 0x060C2420u && (return_key != 0x060C24E0u && return_key != 0x060C5280u))) && ((return_key != 0x060C5390u && (return_key != 0x060C54B8u && return_key != 0x060C5510u)) && ((return_key != 0x060CE978u && return_key != 0x060CEAE0u) && (return_key != 0x060CF110u && return_key != 0x060CF198u)))))) && (((((return_key != 0x060CFEB0u && (return_key != 0x060CFF50u && return_key != 0x060D0888u)) && (return_key != 0x060D0928u && (return_key != 0x060D1340u && return_key != 0x060D13E0u))) && ((return_key != 0x060D1B08u && (return_key != 0x060D1C48u && return_key != 0x060D20D8u)) && ((return_key != 0x060D2240u && return_key != 0x060D2F00u) && (return_key != 0x060D3058u && return_key != 0x060D3638u)))) && (((return_key != 0x060D3758u && (return_key != 0x060D4C80u && return_key != 0x060D4DE8u)) && (return_key != 0x060D5070u && (return_key != 0x060D6B40u && return_key != 0x060D6C40u))) && ((return_key != 0x060D6EC8u && (return_key != 0x060D7170u && return_key != 0x060D7BE8u)) && ((return_key != 0x060D7D50u && return_key != 0x060D7FD8u) && (return_key != 0x060E0D00u && return_key != 0x060E0DA0u))))) && ((((return_key != 0x060E9010u && (return_key != 0x060E9150u && return_key != 0x060EB400u)) && (return_key != 0x060EB568u && (return_key != 0x060EBB70u && return_key != 0x060EBC10u))) && ((return_key != 0x060EC4E8u && (return_key != 0x060EC588u && return_key != 0x060EF828u)) && ((return_key != 0x060F0258u && return_key != 0x061010D8u) && (return_key != 0x06102A00u && return_key != 0x06103AD0u)))) && (((return_key != 0x06104118u && (return_key != 0x06104D50u && return_key != 0x0610CF00u)) && (return_key != 0x0610F638u && (return_key != 0x061108B8u && return_key != 0x06113FB8u))) && ((return_key != 0x06114900u && (return_key != 0x06114BF0u && return_key != 0x06114E08u)) && ((return_key != 0x0612E670u && return_key != 0x0612E738u) && (return_key != 0x06131558u && return_key != 0x061317C0u))))))) && ((((((return_key != 0x06133600u && (return_key != 0x061336E8u && return_key != 0x06133CE8u)) && (return_key != 0x06133DD0u && (return_key != 0x061352C8u && return_key != 0x061364B0u))) && ((return_key != 0x0613E0B0u && (return_key != 0x0613E148u && return_key != 0x0613F108u)) && ((return_key != 0x06141608u && return_key != 0x06143BA8u) && (return_key != 0x061451D8u && return_key != 0x06148388u)))) && (((return_key != 0x06148550u && (return_key != 0x06148718u && return_key != 0x06149B50u)) && (return_key != 0x06149C48u && (return_key != 0x0614B8E0u && return_key != 0x0614BA40u))) && ((return_key != 0x0614BBA0u && (return_key != 0x0614CBA8u && return_key != 0x0614CC30u)) && ((return_key != 0x0614CCD0u && return_key != 0x061581E0u) && (return_key != 0x061808C8u && return_key != 0x061809F0u))))) && ((((return_key != 0x06184070u && (return_key != 0x06184170u && return_key != 0x06185628u)) && (return_key != 0x06185EA8u && (return_key != 0x06185FF8u && return_key != 0x06186278u))) && ((return_key != 0x061863C8u && (return_key != 0x06186BE0u && return_key != 0x061875D8u)) && ((return_key != 0x06187740u && return_key != 0x06187908u) && (return_key != 0x061879F8u && return_key != 0x06188F80u)))) && (((return_key != 0x06189070u && (return_key != 0x0618AF10u && return_key != 0x0618B060u)) && (return_key != 0x0618CB10u && (return_key != 0x0618D970u && return_key != 0x0618DA10u))) && ((return_key != 0x0618E7D0u && (return_key != 0x0618E890u && return_key != 0x0618EE40u)) && ((return_key != 0x0618EF70u && return_key != 0x0618F160u) && (return_key != 0x061952A0u && return_key != 0x06196758u)))))) && (((((return_key != 0x06196AF8u && (return_key != 0x06199A98u && return_key != 0x06199B20u)) && (return_key != 0x0619B1A0u && (return_key != 0x0619B328u && return_key != 0x0619B3E8u))) && ((return_key != 0x0619B7A0u && (return_key != 0x061A0928u && return_key != 0x061A09A0u)) && ((return_key != 0x061A0DC0u && return_key != 0x061A0FB0u) && (return_key != 0x061A12A0u && return_key != 0x061A68A0u)))) && (((return_key != 0x061A6D50u && (return_key != 0x061A71A8u && return_key != 0x061A7658u)) && (return_key != 0x061A7988u && (return_key != 0x061A7A50u && return_key != 0x061A8620u))) && ((return_key != 0x061A92C0u && (return_key != 0x061A9810u && return_key != 0x061AA5D8u)) && ((return_key != 0x061AA6A8u && return_key != 0x061ABBC8u) && (return_key != 0x061ABC80u && return_key != 0x061AD6B8u))))) && ((((return_key != 0x061AE6D0u && (return_key != 0x061AE878u && return_key != 0x061AEA18u)) && (return_key != 0x061AEB30u && (return_key != 0x061AECF8u && return_key != 0x061AF9D0u))) && ((return_key != 0x061AFAA0u && (return_key != 0x061B2890u && return_key != 0x061B4A60u)) && ((return_key != 0x061B4B60u && return_key != 0x061B7C48u) && (return_key != 0x061B9540u && return_key != 0x061B96A0u)))) && (((return_key != 0x061BB770u && (return_key != 0x061C30F0u && return_key != 0x061C3180u)) && (return_key != 0x061C38C0u && (return_key != 0x061C3948u && return_key != 0x061CA8B0u))) && ((return_key != 0x061D3D70u && (return_key != 0x061D3DF8u && return_key != 0x061D84E0u)) && ((return_key != 0x061DABF8u && return_key != 0x061DADC0u) && (return_key != 0x061DAF58u && return_key != 0x061DB330u)))))))) && (((((((return_key != 0x061DC978u && (return_key != 0x061DCD68u && return_key != 0x061DE9E0u)) && (return_key != 0x061DEA68u && (return_key != 0x061E2210u && return_key != 0x061E24A0u))) && ((return_key != 0x061E26D8u && (return_key != 0x061E2968u && return_key != 0x0620DFA8u)) && ((return_key != 0x0620E788u && return_key != 0x0620EAA8u) && (return_key != 0x0620EBF0u && return_key != 0x0623B130u)))) && (((return_key != 0x0623B668u && (return_key != 0x0623BC00u && return_key != 0x06240180u)) && (return_key != 0x062401C8u && (return_key != 0x06240258u && return_key != 0x062403E0u))) && ((return_key != 0x06240428u && (return_key != 0x062405B0u && return_key != 0x062405F8u)) && ((return_key != 0x06240688u && return_key != 0x06240810u) && (return_key != 0x06240858u && return_key != 0x06240B10u))))) && ((((return_key != 0x06240BB0u && (return_key != 0x062433B0u && return_key != 0x062817E8u)) && (return_key != 0x06281888u && (return_key != 0x06282110u && return_key != 0x062833B0u))) && ((return_key != 0x06283660u && (return_key != 0x06283728u && return_key != 0x06283948u)) && ((return_key != 0x06283AB8u && return_key != 0x06284EC8u) && (return_key != 0x06284F68u && return_key != 0x06287B80u)))) && (((return_key != 0x06287BD8u && (return_key != 0x0628A1E8u && return_key != 0x0628EA00u)) && (return_key != 0x06290F60u && (return_key != 0x062911B8u && return_key != 0x06298E88u))) && ((return_key != 0x06299408u && (return_key != 0x06299EF0u && return_key != 0x0629A010u)) && ((return_key != 0x0629A200u && return_key != 0x0629A340u) && (return_key != 0x0629B4F8u && return_key != 0x062A29A8u)))))) && (((((return_key != 0x062A2A80u && (return_key != 0x062A2F60u && return_key != 0x062A3120u)) && (return_key != 0x062A3548u && (return_key != 0x062A3620u && return_key != 0x062A5938u))) && ((return_key != 0x062A5980u && (return_key != 0x062A5A20u && return_key != 0x062A5A68u)) && ((return_key != 0x062A6108u && return_key != 0x062AB1E8u) && (return_key != 0x062AB2B8u && return_key != 0x062AC3A8u)))) && (((return_key != 0x062AC430u && (return_key != 0x062AE7B8u && return_key != 0x062C37A0u)) && (return_key != 0x062C3A58u && (return_key != 0x062C40D0u && return_key != 0x062C43B0u))) && ((return_key != 0x062CE3A8u && (return_key != 0x062CE438u && return_key != 0x062CF208u)) && ((return_key != 0x062D1378u && return_key != 0x062D1430u) && (return_key != 0x062D14D8u && return_key != 0x062D2608u))))) && ((((return_key != 0x062D3570u && (return_key != 0x062D4328u && return_key != 0x062D43C8u)) && (return_key != 0x062D4420u && (return_key != 0x062D44C8u && return_key != 0x062D72F0u))) && ((return_key != 0x062D7348u && (return_key != 0x06307920u && return_key != 0x063079E8u)) && ((return_key != 0x06308088u && return_key != 0x06309B28u) && (return_key != 0x0630BC78u && return_key != 0x0630CF98u)))) && (((return_key != 0x063139E0u && (return_key != 0x063141A8u && return_key != 0x06314688u)) && (return_key != 0x06314808u && (return_key != 0x06314968u && return_key != 0x06318CB0u))) && ((return_key != 0x06319DF8u && (return_key != 0x0631BF10u && return_key != 0x0631F8E8u)) && ((return_key != 0x0631FFC0u && return_key != 0x06325EB0u) && (return_key != 0x06326430u && return_key != 0x06327650u))))))) && ((((((return_key != 0x06329338u && (return_key != 0x0632BDE0u && return_key != 0x06330230u)) && (return_key != 0x06330AF0u && (return_key != 0x06330C50u && return_key != 0x063329D8u))) && ((return_key != 0x06333170u && (return_key != 0x063332B0u && return_key != 0x06333F28u)) && ((return_key != 0x06334010u && return_key != 0x063340F8u) && (return_key != 0x06334DC8u && return_key != 0x06334F58u)))) && (((return_key != 0x06335CC0u && (return_key != 0x06335DA8u && return_key != 0x06335E90u)) && (return_key != 0x06337928u && (return_key != 0x063379B8u && return_key != 0x06337AB8u))) && ((return_key != 0x06337B48u && (return_key != 0x0633D388u && return_key != 0x0633D468u)) && ((return_key != 0x0633D9A0u && return_key != 0x06341D00u) && (return_key != 0x06341DE0u && return_key != 0x06341EF8u))))) && ((((return_key != 0x06343010u && (return_key != 0x06353D90u && return_key != 0x06353E38u)) && (return_key != 0x06359C38u && (return_key != 0x0635A8E0u && return_key != 0x063882D8u))) && ((return_key != 0x06388530u && (return_key != 0x06388770u && return_key != 0x06389828u)) && ((return_key != 0x0638A4C8u && return_key != 0x0638AB50u) && (return_key != 0x0638FE30u && return_key != 0x06390FB0u)))) && (((return_key != 0x06391038u && (return_key != 0x06392108u && return_key != 0x063A61F8u)) && (return_key != 0x063A6240u && (return_key != 0x063A6328u && return_key != 0x063A6370u))) && ((return_key != 0x063B47C8u && (return_key != 0x063B6428u && return_key != 0x063B64C0u)) && ((return_key != 0x063B6580u && return_key != 0x063B7000u) && (return_key != 0x063B70B8u && return_key != 0x063B7160u)))))) && (((((return_key != 0x063B9DA0u && (return_key != 0x063BA388u && return_key != 0x063BAFA8u)) && (return_key != 0x063BB090u && (return_key != 0x063BB138u && return_key != 0x063C0E10u))) && ((return_key != 0x063C1790u && (return_key != 0x063C2A28u && return_key != 0x063C3B80u)) && ((return_key != 0x063C3D90u && return_key != 0x063C4938u) && (return_key != 0x063C7188u && return_key != 0x063CA268u)))) && (((return_key != 0x063D1260u && (return_key != 0x063D3120u && return_key != 0x063D4348u)) && (return_key != 0x063D43F0u && (return_key != 0x063D4720u && return_key != 0x063D4A28u))) && ((return_key != 0x063DE5E0u && (return_key != 0x063DE8D0u && return_key != 0x063DEDA8u)) && ((return_key != 0x063E3678u && return_key != 0x063E36C0u) && (return_key != 0x063E3908u && return_key != 0x063E5AC0u))))) && ((((return_key != 0x063E5D98u && (return_key != 0x063E60B0u && return_key != 0x063EAE60u)) && (return_key != 0x063F0E70u && (return_key != 0x063F4C28u && return_key != 0x063F97A0u))) && ((return_key != 0x064011A0u && (return_key != 0x06401278u && return_key != 0x06402BD8u)) && ((return_key != 0x06403048u && return_key != 0x06403108u) && (return_key != 0x06403608u && return_key != 0x06408188u)))) && (((return_key != 0x06408328u && (return_key != 0x06408558u && return_key != 0x06408710u)) && ((return_key != 0x0640EFF0u && return_key != 0x06410840u) && (return_key != 0x06411F18u && return_key != 0x06416CA0u))) && ((return_key != 0x06416EA0u && (return_key != 0x06418A50u && return_key != 0x0641D658u)) && ((return_key != 0x0641E2A0u && return_key != 0x06420BB8u) && (return_key != 0x0642B7B0u && return_key != 0x0642B9A8u))))))))) && ((((((((return_key != 0x0642BB88u && (return_key != 0x0642D438u && return_key != 0x0642F2B0u)) && (return_key != 0x0642F3C8u && (return_key != 0x064317D0u && return_key != 0x06432088u))) && ((return_key != 0x06432210u && (return_key != 0x06433408u && return_key != 0x064335A8u)) && ((return_key != 0x064335F0u && return_key != 0x06433828u) && (return_key != 0x06433870u && return_key != 0x064361E8u)))) && (((return_key != 0x06436258u && (return_key != 0x06438AC0u && return_key != 0x06438CB8u)) && (return_key != 0x06438E50u && (return_key != 0x06438ED8u && return_key != 0x06439038u))) && ((return_key != 0x0643B7F0u && (return_key != 0x0643B860u && return_key != 0x0643D0C8u)) && ((return_key != 0x0643D138u && return_key != 0x06480098u) && (return_key != 0x06487648u && return_key != 0x06487700u))))) && ((((return_key != 0x06487C00u && (return_key != 0x0648AB40u && return_key != 0x0648B528u)) && (return_key != 0x0648B5D0u && (return_key != 0x0648C3B0u && return_key != 0x0648C458u))) && ((return_key != 0x0648D268u && (return_key != 0x0648D310u && return_key != 0x0648FB80u)) && ((return_key != 0x06490110u && return_key != 0x064916D0u) && (return_key != 0x06494928u && return_key != 0x06494E38u)))) && (((return_key != 0x06495480u && (return_key != 0x06495A30u && return_key != 0x0649F1F0u)) && (return_key != 0x064AF450u && (return_key != 0x064AF520u && return_key != 0x064B1DE0u))) && ((return_key != 0x064B1EB8u && (return_key != 0x064B4D80u && return_key != 0x064B4E70u)) && ((return_key != 0x064B6628u && return_key != 0x064BA598u) && (return_key != 0x064BA6B0u && return_key != 0x064BBC60u)))))) && (((((return_key != 0x064BBCA8u && (return_key != 0x064BBD90u && return_key != 0x064BBDD8u)) && (return_key != 0x064BC8C8u && (return_key != 0x064C41C8u && return_key != 0x064C42E8u))) && ((return_key != 0x064C4550u && (return_key != 0x064C4670u && return_key != 0x064C4F08u)) && ((return_key != 0x064C6860u && return_key != 0x064C7BF8u) && (return_key != 0x064CB7D8u && return_key != 0x064D0858u)))) && (((return_key != 0x064D09B8u && (return_key != 0x064D1090u && return_key != 0x064D2480u)) && (return_key != 0x064D2580u && (return_key != 0x064D3F48u && return_key != 0x064D4200u))) && ((return_key != 0x064D5370u && (return_key != 0x064D5470u && return_key != 0x064D6238u)) && ((return_key != 0x064D6398u && return_key != 0x064D65D8u) && (return_key != 0x064D6738u && return_key != 0x064DFFE0u))))) && ((((return_key != 0x064E0038u && (return_key != 0x064E4400u && return_key != 0x064E74D8u)) && (return_key != 0x064E79A8u && (return_key != 0x064E7E80u && return_key != 0x064EA0D8u))) && ((return_key != 0x064EC348u && (return_key != 0x064ED080u && return_key != 0x064ED160u)) && ((return_key != 0x064EDCA0u && return_key != 0x064EDDF0u) && (return_key != 0x064EE398u && return_key != 0x064EE4A0u)))) && (((return_key != 0x064EE588u && (return_key != 0x064EEA58u && return_key != 0x064EEB60u)) && (return_key != 0x064EEC48u && (return_key != 0x064EF1A0u && return_key != 0x064EF2A8u))) && ((return_key != 0x064EF390u && (return_key != 0x064EF978u && return_key != 0x064EFA80u)) && ((return_key != 0x064EFB68u && return_key != 0x064F0DD0u) && (return_key != 0x064F0ED8u && return_key != 0x064F0FC0u))))))) && ((((((return_key != 0x064F4E28u && (return_key != 0x064F4F90u && return_key != 0x064F51C0u)) && (return_key != 0x064F5208u && (return_key != 0x064F52E0u && return_key != 0x064F5328u))) && ((return_key != 0x065005C0u && (return_key != 0x065011A0u && return_key != 0x06501368u)) && ((return_key != 0x06501860u && return_key != 0x06501960u) && (return_key != 0x06501D08u && return_key != 0x06501D90u)))) && (((return_key != 0x065033D8u && (return_key != 0x06503560u && return_key != 0x06504000u)) && (return_key != 0x065048B8u && (return_key != 0x06504CC0u && return_key != 0x06505968u))) && ((return_key != 0x06506BD0u && (return_key != 0x06506E88u && return_key != 0x06506FE0u)) && ((return_key != 0x06507138u && return_key != 0x06507288u) && (return_key != 0x06507698u && return_key != 0x06507880u))))) && ((((return_key != 0x06508268u && (return_key != 0x0650E638u && return_key != 0x0650E700u)) && (return_key != 0x0650E9F0u && (return_key != 0x0650EAD0u && return_key != 0x0650ECC0u))) && ((return_key != 0x0650EDA0u && (return_key != 0x0650EE80u && return_key != 0x0650EF60u)) && ((return_key != 0x0650F250u && return_key != 0x0650F3D8u) && (return_key != 0x06510760u && return_key != 0x06511198u)))) && (((return_key != 0x06511280u && (return_key != 0x06511DC0u && return_key != 0x065120B8u)) && (return_key != 0x06512198u && (return_key != 0x06512A58u && return_key != 0x06512E50u))) && ((return_key != 0x06513010u && (return_key != 0x065132E0u && return_key != 0x06513A88u)) && ((return_key != 0x06513CB8u && return_key != 0x06513EA0u) && (return_key != 0x06513F28u && return_key != 0x06513FB0u)))))) && (((((return_key != 0x065144C0u && (return_key != 0x065151A8u && return_key != 0x06515230u)) && (return_key != 0x065152B8u && (return_key != 0x06515710u && return_key != 0x065167D0u))) && ((return_key != 0x06516870u && (return_key != 0x06517E60u && return_key != 0x06517F00u)) && ((return_key != 0x06519470u && return_key != 0x065194F8u) && (return_key != 0x06519580u && return_key != 0x06519928u)))) && (((return_key != 0x0651A700u && (return_key != 0x0651A7E0u && return_key != 0x0651A868u)) && (return_key != 0x0651A9E8u && (return_key != 0x0651AAE8u && return_key != 0x0651C0D0u))) && ((return_key != 0x0651C1D0u && (return_key != 0x0651C610u && return_key != 0x0651DC38u)) && ((return_key != 0x0651DCE0u && return_key != 0x0651DE90u) && (return_key != 0x0651E040u && return_key != 0x0651E088u))))) && ((((return_key != 0x0651F050u && (return_key != 0x0651F150u && return_key != 0x0651F3D8u)) && (return_key != 0x0651F540u && (return_key != 0x0651F708u && return_key != 0x0651F7F8u))) && ((return_key != 0x0651FAC0u && (return_key != 0x0651FD68u && return_key != 0x06521AE8u)) && ((return_key != 0x06521BC8u && return_key != 0x06523EE8u) && (return_key != 0x065243C8u && return_key != 0x065244C8u)))) && (((return_key != 0x065248B0u && (return_key != 0x06525110u && return_key != 0x065252A8u)) && (return_key != 0x065252F0u && (return_key != 0x06527658u && return_key != 0x06527738u))) && ((return_key != 0x06529478u && (return_key != 0x06532490u && return_key != 0x065324D8u)) && ((return_key != 0x06532568u && return_key != 0x065325B0u) && (return_key != 0x06535080u && return_key != 0x065351E0u)))))))) && (((((((return_key != 0x06539AE0u && (return_key != 0x065434C8u && return_key != 0x06545820u)) && (return_key != 0x06545868u && (return_key != 0x06545E28u && return_key != 0x06546DC8u))) && ((return_key != 0x06549BD0u && (return_key != 0x0654BE00u && return_key != 0x0654CD48u)) && ((return_key != 0x0654DE48u && return_key != 0x06583038u) && (return_key != 0x06583218u && return_key != 0x065833B0u)))) && (((return_key != 0x0660DCA8u && (return_key != 0x0660DD98u && return_key != 0x0660F5E8u)) && (return_key != 0x0660F738u && (return_key != 0x06610078u && return_key != 0x066107D8u))) && ((return_key != 0x06610898u && (return_key != 0x06610980u && return_key != 0x066127E0u)) && ((return_key != 0x06612918u && return_key != 0x06612A50u) && (return_key != 0x06614050u && return_key != 0x06614180u))))) && ((((return_key != 0x06616350u && (return_key != 0x06616480u && return_key != 0x06616CF8u)) && (return_key != 0x06616D40u && (return_key != 0x06617658u && return_key != 0x06618C80u))) && ((return_key != 0x06618D60u && (return_key != 0x0661A380u && return_key != 0x0661A420u)) && ((return_key != 0x0661AA80u && return_key != 0x0661B0F0u) && (return_key != 0x0661B1B0u && return_key != 0x0661B898u)))) && (((return_key != 0x0661BAB8u && (return_key != 0x0661C830u && return_key != 0x0661D3F8u)) && (return_key != 0x06633C98u && (return_key != 0x06647548u && return_key != 0x06647978u))) && ((return_key != 0x066800A0u && (return_key != 0x06680EB8u && return_key != 0x06683E00u)) && ((return_key != 0x06683EE8u && return_key != 0x066849F0u) && (return_key != 0x066856D0u && return_key != 0x06685AC0u)))))) && (((((return_key != 0x06687018u && (return_key != 0x066870F8u && return_key != 0x06687230u)) && (return_key != 0x0668C7B8u && (return_key != 0x0668C840u && return_key != 0x0668C8C8u))) && ((return_key != 0x0668C950u && (return_key != 0x0668E510u && return_key != 0x0668E650u)) && ((return_key != 0x0668E7B0u && return_key != 0x0668E910u) && (return_key != 0x0668F038u && return_key != 0x0668F118u)))) && (((return_key != 0x0668F720u && (return_key != 0x0668FB58u && return_key != 0x0668FBF8u)) && (return_key != 0x06690608u && (return_key != 0x066906D0u && return_key != 0x06690C88u))) && ((return_key != 0x06691490u && (return_key != 0x06691570u && return_key != 0x06691A28u)) && ((return_key != 0x06691F08u && return_key != 0x06692408u) && (return_key != 0x066924E8u && return_key != 0x06692AC0u))))) && ((((return_key != 0x06692DC8u && (return_key != 0x06692EA8u && return_key != 0x06693480u)) && (return_key != 0x066938F0u && (return_key != 0x06693F50u && return_key != 0x06694030u))) && ((return_key != 0x066945D0u && (return_key != 0x06694FE0u && return_key != 0x066950C0u)) && ((return_key != 0x06695C18u && return_key != 0x06695DD0u) && (return_key != 0x06695E78u && return_key != 0x06695EC0u)))) && (((return_key != 0x066970F0u && (return_key != 0x06697190u && return_key != 0x06697A68u)) && (return_key != 0x06697B08u && (return_key != 0x066984C0u && return_key != 0x06698560u))) && ((return_key != 0x0669B700u && (return_key != 0x0669C1A0u && return_key != 0x0669C218u)) && ((return_key != 0x0669C2F8u && return_key != 0x0669C370u) && (return_key != 0x0669C470u && return_key != 0x0669C4E8u))))))) && ((((((return_key != 0x0669C608u && (return_key != 0x0669C750u && return_key != 0x0669C888u)) && (return_key != 0x0669C9D0u && (return_key != 0x0669E650u && return_key != 0x0669F218u))) && ((return_key != 0x0669F270u && (return_key != 0x0669F818u && return_key != 0x0669F918u)) && ((return_key != 0x0669FC90u && return_key != 0x066A0C98u) && (return_key != 0x066A0D78u && return_key != 0x066A5D98u)))) && (((return_key != 0x066A5FC0u && (return_key != 0x066A6120u && return_key != 0x066A6238u)) && (return_key != 0x066A6280u && (return_key != 0x066A65B8u && return_key != 0x066A66B8u))) && ((return_key != 0x066A67B0u && (return_key != 0x066A67F8u && return_key != 0x066A70E8u)) && ((return_key != 0x066A7170u && return_key != 0x066A72D8u) && (return_key != 0x066A7360u && return_key != 0x066A8488u))))) && ((((return_key != 0x066A8510u && (return_key != 0x066A8678u && return_key != 0x066A8700u)) && (return_key != 0x066A9C10u && (return_key != 0x066A9D10u && return_key != 0x066A9DF0u))) && ((return_key != 0x066A9ED0u && (return_key != 0x066AA150u && return_key != 0x066AA230u)) && ((return_key != 0x066AA358u && return_key != 0x066AA438u) && (return_key != 0x066AA598u && return_key != 0x066AAC70u)))) && (((return_key != 0x066AAD70u && (return_key != 0x066AAEF8u && return_key != 0x066AB080u)) && (return_key != 0x066AB160u && (return_key != 0x066AB2E8u && return_key != 0x066AB898u))) && ((return_key != 0x066AEBE0u && (return_key != 0x066AEDF8u && return_key != 0x066B9550u)) && ((return_key != 0x066B9680u && return_key != 0x066B9C38u) && (return_key != 0x066B9E30u && return_key != 0x066BA468u)))))) && (((((return_key != 0x066BB898u && (return_key != 0x066BBEC8u && return_key != 0x066BC508u)) && (return_key != 0x066BC688u && (return_key != 0x066BCF30u && return_key != 0x066BD0B0u))) && ((return_key != 0x066BEB40u && (return_key != 0x066BFBA8u && return_key != 0x066C8740u)) && ((return_key != 0x066CF3B8u && return_key != 0x066CF950u) && (return_key != 0x066CFA78u && return_key != 0x066CFAE8u)))) && (((return_key != 0x066CFEF8u && (return_key != 0x066D00A8u && return_key != 0x066D0C58u)) && (return_key != 0x066D0CA0u && (return_key != 0x066D10F8u && return_key != 0x066D1140u))) && ((return_key != 0x066D1610u && (return_key != 0x066D1658u && return_key != 0x066D2CD8u)) && ((return_key != 0x066D2FB0u && return_key != 0x066D3298u) && (return_key != 0x066D3450u && return_key != 0x066D3690u))))) && ((((return_key != 0x066D3848u && (return_key != 0x066D3A68u && return_key != 0x066D6498u)) && (return_key != 0x066D6720u && (return_key != 0x066D6810u && return_key != 0x066D81A8u))) && ((return_key != 0x066D9608u && (return_key != 0x066D9680u && return_key != 0x066E09E8u)) && ((return_key != 0x06704E98u && return_key != 0x06708480u) && (return_key != 0x06708510u && return_key != 0x0670A4C8u)))) && (((return_key != 0x0670A558u && (return_key != 0x0670B128u && return_key != 0x0670B1B8u)) && ((return_key != 0x0670B258u && return_key != 0x06715160u) && (return_key != 0x067170C0u && return_key != 0x06717180u))) && ((return_key != 0x06717638u && (return_key != 0x06717700u && return_key != 0x06717AA0u)) && ((return_key != 0x06717B60u && return_key != 0x06717E58u) && (return_key != 0x06717F20u && return_key != 0x0671F970u)))))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FEB48u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD69u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD6Au;
            if (nh_scpu_expect_next(cpu, 0x060FEB50u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FEB50u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD6Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD6Du;
            if (nh_scpu_expect_next(cpu, 0x060FEB68u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FEB68u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD6Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
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
            cpu->pc = 0xFD6Fu;
            if (nh_scpu_expect_next(cpu, 0x060FEB78u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEB78u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD6Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD71u;
            if (nh_scpu_expect_next(cpu, 0x060FEB88u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEB88u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD71u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD74u;
            if (nh_scpu_expect_next(cpu, 0x060FEBA0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FEBA0u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD74u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
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
            cpu->pc = 0xFD76u;
            if (nh_scpu_expect_next(cpu, 0x060FEBB0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEBB0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD76u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD78u;
            if (nh_scpu_expect_next(cpu, 0x060FEBC0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEBC0u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FD78u,
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
            if (((((((return_key != 0x06086580u && (return_key != 0x06086810u && return_key != 0x06086AE0u)) && ((return_key != 0x06086C60u && return_key != 0x06086F88u) && (return_key != 0x06087258u && return_key != 0x0608A818u))) && (((return_key != 0x0608A8D0u && return_key != 0x060A09D0u) && (return_key != 0x060A1828u && return_key != 0x060A23E0u)) && ((return_key != 0x060A2648u && return_key != 0x060A5C20u) && (return_key != 0x060A5DE0u && return_key != 0x060A6ED8u)))) && ((((return_key != 0x060A7098u && return_key != 0x060AEFE8u) && (return_key != 0x060AF1B8u && return_key != 0x060AF6D8u)) && ((return_key != 0x060AF868u && return_key != 0x060C2F48u) && (return_key != 0x060C4A98u && return_key != 0x060C4BD0u))) && (((return_key != 0x060C5188u && return_key != 0x0610FC58u) && (return_key != 0x0610FE08u && return_key != 0x06110298u)) && ((return_key != 0x061103E0u && return_key != 0x061468F8u) && (return_key != 0x06148970u && return_key != 0x06148B00u))))) && (((((return_key != 0x0614D7C0u && return_key != 0x0618E608u) && (return_key != 0x061CB9B8u && return_key != 0x06283510u)) && ((return_key != 0x06287770u && return_key != 0x0628F638u) && (return_key != 0x0628F7E0u && return_key != 0x062923C8u))) && (((return_key != 0x06292868u && return_key != 0x06299DD0u) && (return_key != 0x06305178u && return_key != 0x06312B00u)) && ((return_key != 0x06331428u && return_key != 0x063315D0u) && (return_key != 0x06345B70u && return_key != 0x06345E48u)))) && ((((return_key != 0x06346288u && return_key != 0x0634A938u) && (return_key != 0x0634AA80u && return_key != 0x063AFF98u)) && ((return_key != 0x063B3510u && return_key != 0x063B9AE8u) && (return_key != 0x063D5C60u && return_key != 0x063D5D18u))) && (((return_key != 0x063D94B8u && return_key != 0x063DA438u) && (return_key != 0x063DB930u && return_key != 0x063DCB00u)) && ((return_key != 0x063EB700u && return_key != 0x063FA1D8u) && (return_key != 0x063FA328u && return_key != 0x063FA428u)))))) && (((((return_key != 0x06400348u && (return_key != 0x064005A0u && return_key != 0x06400770u)) && ((return_key != 0x06409950u && return_key != 0x0640CF88u) && (return_key != 0x0640D160u && return_key != 0x0640D538u))) && (((return_key != 0x0640DA08u && return_key != 0x06411848u) && (return_key != 0x064119A0u && return_key != 0x06415848u)) && ((return_key != 0x06480C30u && return_key != 0x064810F0u) && (return_key != 0x06481200u && return_key != 0x064839F8u)))) && ((((return_key != 0x06484020u && return_key != 0x064898D0u) && (return_key != 0x064920B0u && return_key != 0x06492318u)) && ((return_key != 0x06492598u && return_key != 0x064926E0u) && (return_key != 0x06498920u && return_key != 0x064B6410u))) && (((return_key != 0x064C4908u && return_key != 0x064CAE00u) && (return_key != 0x06534470u && return_key != 0x065374C8u)) && ((return_key != 0x06537610u && return_key != 0x0653AEA8u) && (return_key != 0x0653AFF0u && return_key != 0x0654B2C8u))))) && (((((return_key != 0x0654B528u && return_key != 0x0661C970u) && (return_key != 0x06621808u && return_key != 0x06621950u)) && ((return_key != 0x06621C80u && return_key != 0x06621DC8u) && (return_key != 0x066228C0u && return_key != 0x06622A08u))) && (((return_key != 0x06622E00u && return_key != 0x06622F48u) && (return_key != 0x06623340u && return_key != 0x06623488u)) && ((return_key != 0x06628870u && return_key != 0x066289B8u) && (return_key != 0x0662AE00u && return_key != 0x0662AF48u)))) && ((((return_key != 0x0665B598u && return_key != 0x0665B768u) && (return_key != 0x0665FDD8u && return_key != 0x0665FF20u)) && ((return_key != 0x066671F0u && return_key != 0x06667338u) && (return_key != 0x066A6F70u && return_key != 0x066A7E18u))) && (((return_key != 0x066A8310u && return_key != 0x066A91B8u) && (return_key != 0x0670F2E0u && return_key != 0x0670F838u)) && ((return_key != 0x06712190u && return_key != 0x0671AAE8u) && (return_key != 0x0671AEF0u && return_key != 0x0671DFC8u))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FED08u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDA1u,
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
            cpu->pc = 0xFDA3u;
            if (nh_scpu_expect_next(cpu, 0x060FED18u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FED18u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDA3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFDD5u;
                if (nh_scpu_expect_next(cpu, 0x060FEEA8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDA5u;
            if (nh_scpu_expect_next(cpu, 0x060FED28u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FED28u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x48u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDA5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDEFu;
            if (nh_scpu_expect_next(cpu, 0x060FEF78u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FED38u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDA7u,
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
            cpu->pc = 0xFDA9u;
            if (nh_scpu_expect_next(cpu, 0x060FED48u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FED48u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x2Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDA9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFDD5u;
                if (nh_scpu_expect_next(cpu, 0x060FEEA8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDABu;
            if (nh_scpu_expect_next(cpu, 0x060FED58u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FED58u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDABu,
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
            cpu->pc = 0xFDADu;
            if (nh_scpu_expect_next(cpu, 0x060FED68u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FED68u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x26u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDADu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFDD5u;
                if (nh_scpu_expect_next(cpu, 0x060FEEA8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDAFu;
            if (nh_scpu_expect_next(cpu, 0x060FED78u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FED78u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x3Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDAFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDEFu;
            if (nh_scpu_expect_next(cpu, 0x060FEF78u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FED88u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDB1u,
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
            cpu->pc = 0xFDB3u;
            if (nh_scpu_expect_next(cpu, 0x060FED98u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FED98u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x3Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDB3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFDEFu;
                if (nh_scpu_expect_next(cpu, 0x060FEF78u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDB5u;
            if (nh_scpu_expect_next(cpu, 0x060FEDA8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FEDA8u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x1Eu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDB5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDD5u;
            if (nh_scpu_expect_next(cpu, 0x060FEEA8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FEDB8u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDB7u,
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
            cpu->pc = 0xFDB9u;
            if (nh_scpu_expect_next(cpu, 0x060FEDC8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEDC8u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x34u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDB9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFDEFu;
                if (nh_scpu_expect_next(cpu, 0x060FEF78u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDBBu;
            if (nh_scpu_expect_next(cpu, 0x060FEDD8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FEDD8u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDBBu,
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
            cpu->pc = 0xFDBDu;
            if (nh_scpu_expect_next(cpu, 0x060FEDE8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEDE8u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDBDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFDEFu;
                if (nh_scpu_expect_next(cpu, 0x060FEF78u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDBFu;
            if (nh_scpu_expect_next(cpu, 0x060FEDF8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FEDF8u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x14u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDBFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDD5u;
            if (nh_scpu_expect_next(cpu, 0x060FEEA8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FEE08u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDC1u,
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
            cpu->pc = 0xFDC3u;
            if (nh_scpu_expect_next(cpu, 0x060FEE18u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEE18u: {
            static const uint8_t expected_epoch[] = { 0xC5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDC3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            const uint32_t address = (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu);
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            const uint16_t result = (uint16_t)(cpu->a - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if (cpu->a >= right) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDC5u;
            if (nh_scpu_expect_next(cpu, 0x060FEE28u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEE28u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x28u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDC5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFDEFu;
                if (nh_scpu_expect_next(cpu, 0x060FEF78u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDC7u;
            if (nh_scpu_expect_next(cpu, 0x060FEE38u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FEE38u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x0Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDC7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDD5u;
            if (nh_scpu_expect_next(cpu, 0x060FEEA8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FEE48u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDC9u,
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
            cpu->pc = 0xFDCBu;
            if (nh_scpu_expect_next(cpu, 0x060FEE58u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEE58u: {
            static const uint8_t expected_epoch[] = { 0xC5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDCBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            const uint32_t address = (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu);
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            const uint16_t result = (uint16_t)(cpu->a - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if (cpu->a >= right) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDCDu;
            if (nh_scpu_expect_next(cpu, 0x060FEE68u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEE68u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDCDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFDEFu;
                if (nh_scpu_expect_next(cpu, 0x060FEF78u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDCFu;
            if (nh_scpu_expect_next(cpu, 0x060FEE78u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FEE78u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDCFu,
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
            cpu->pc = 0xFDD1u;
            if (nh_scpu_expect_next(cpu, 0x060FEE88u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEE88u: {
            static const uint8_t expected_epoch[] = { 0xC5u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDD1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            const uint32_t address = (uint32_t)((cpu->d + 0x000006u) & 0xFFFFu);
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            const uint16_t result = (uint16_t)(cpu->a - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if (cpu->a >= right) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDD3u;
            if (nh_scpu_expect_next(cpu, 0x060FEE98u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEE98u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x1Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDD3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFDEFu;
                if (nh_scpu_expect_next(cpu, 0x060FEF78u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDD5u;
            if (nh_scpu_expect_next(cpu, 0x060FEEA8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FEEA8u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x01u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDD5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0001u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDD8u;
            if (nh_scpu_expect_next(cpu, 0x060FEEC0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FEEC0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDD8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDDAu;
            if (nh_scpu_expect_next(cpu, 0x060FEED0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEED0u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDDAu,
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
            if (((((((((((return_key != 0x06080250u && return_key != 0x06080330u) && (return_key != 0x06080390u && (return_key != 0x060824F0u && return_key != 0x06082E50u))) && ((return_key != 0x06082EB0u && (return_key != 0x06082FB0u && return_key != 0x060831B0u)) && (return_key != 0x06083588u && (return_key != 0x060835E8u && return_key != 0x06083750u)))) && (((return_key != 0x060837B0u && (return_key != 0x06086620u && return_key != 0x06086D00u)) && (return_key != 0x06088078u && (return_key != 0x060880D8u && return_key != 0x060889E0u))) && ((return_key != 0x06088A68u && (return_key != 0x06089000u && return_key != 0x06089088u)) && (return_key != 0x0608A8F0u && (return_key != 0x0608F7E0u && return_key != 0x0608F858u))))) && ((((return_key != 0x0608F920u && return_key != 0x0608F9B0u) && (return_key != 0x0608FB70u && (return_key != 0x0608FC38u && return_key != 0x060915A0u))) && ((return_key != 0x06091688u && (return_key != 0x060918E8u && return_key != 0x060919B0u)) && (return_key != 0x06091A68u && (return_key != 0x06091DE8u && return_key != 0x06092898u)))) && (((return_key != 0x06092908u && (return_key != 0x060941E0u && return_key != 0x060942C8u)) && (return_key != 0x06094528u && (return_key != 0x060945F0u && return_key != 0x060946A8u))) && ((return_key != 0x06094A28u && (return_key != 0x060954D8u && return_key != 0x06095548u)) && (return_key != 0x060970E8u && (return_key != 0x06097158u && return_key != 0x0609A9F0u)))))) && (((((return_key != 0x0609AB70u && return_key != 0x060A2548u) && (return_key != 0x060A7D58u && (return_key != 0x060A7DE0u && return_key != 0x060A7E68u))) && ((return_key != 0x060A7F18u && (return_key != 0x060AA448u && return_key != 0x060AC7F8u)) && (return_key != 0x060AC8A8u && (return_key != 0x060ACA00u && return_key != 0x060ACAB0u)))) && (((return_key != 0x060AD8E8u && (return_key != 0x060ADA88u && return_key != 0x060ADD70u)) && (return_key != 0x060ADF10u && (return_key != 0x060ADF70u && return_key != 0x060B00A8u))) && ((return_key != 0x060B0130u && (return_key != 0x060B1D90u && return_key != 0x060B1DF0u)) && (return_key != 0x060B2868u && (return_key != 0x060B2C20u && return_key != 0x060B2C90u))))) && ((((return_key != 0x060B2F98u && (return_key != 0x060B3008u && return_key != 0x060B3318u)) && (return_key != 0x060B3420u && (return_key != 0x060B38F0u && return_key != 0x060B3980u))) && ((return_key != 0x060B3D10u && (return_key != 0x060B3E18u && return_key != 0x060B82F8u)) && (return_key != 0x060B8380u && (return_key != 0x060B86E8u && return_key != 0x060B8770u)))) && (((return_key != 0x060BA6F8u && (return_key != 0x060BB760u && return_key != 0x060BB7E8u)) && (return_key != 0x060C0D28u && (return_key != 0x060C0D98u && return_key != 0x060C0E08u))) && ((return_key != 0x060C1268u && (return_key != 0x060C12C8u && return_key != 0x060C1340u)) && (return_key != 0x060C13A0u && (return_key != 0x060C2BD8u && return_key != 0x060C2C38u))))))) && ((((((return_key != 0x060C9248u && return_key != 0x060CD5A0u) && (return_key != 0x060CD628u && (return_key != 0x060CD6B0u && return_key != 0x060CD7A8u))) && ((return_key != 0x060CD850u && (return_key != 0x060CDA88u && return_key != 0x060CDB28u)) && (return_key != 0x060CDBC8u && (return_key != 0x060CEEC0u && return_key != 0x060CEF70u)))) && (((return_key != 0x060CF038u && (return_key != 0x060CFC80u && return_key != 0x060CFD30u)) && (return_key != 0x060CFDF8u && (return_key != 0x060D0658u && return_key != 0x060D0708u))) && ((return_key != 0x060D07D0u && (return_key != 0x060D10F8u && return_key != 0x060D11D8u)) && (return_key != 0x060D1288u && (return_key != 0x060D28E0u && return_key != 0x060D2958u))))) && ((((return_key != 0x060D8B98u && return_key != 0x060D8CA0u) && (return_key != 0x060D9AA8u && (return_key != 0x060DAC08u && return_key != 0x060DC9C0u))) && ((return_key != 0x060DE6C8u && (return_key != 0x060DE778u && return_key != 0x060DE840u)) && (return_key != 0x060DED90u && (return_key != 0x060DEE40u && return_key != 0x060DEF08u)))) && (((return_key != 0x060DF530u && (return_key != 0x060E0AE8u && return_key != 0x060E0B98u)) && (return_key != 0x060E0C60u && (return_key != 0x060E2380u && return_key != 0x060E23E0u))) && ((return_key != 0x060E2478u && (return_key != 0x060E24F8u && return_key != 0x060E2580u)) && (return_key != 0x060E2608u && (return_key != 0x060E2668u && return_key != 0x060E26C8u)))))) && (((((return_key != 0x060E2820u && return_key != 0x060E2880u) && (return_key != 0x060E6430u && (return_key != 0x060E9C20u && return_key != 0x060EA570u))) && ((return_key != 0x060EA8D8u && (return_key != 0x060EB940u && return_key != 0x060EB9F0u)) && (return_key != 0x060EBAB8u && (return_key != 0x060EBD80u && return_key != 0x060EBE88u)))) && (((return_key != 0x060EC2D0u && (return_key != 0x060EC380u && return_key != 0x060EC448u)) && (return_key != 0x060EDA70u && (return_key != 0x060EDBB8u && return_key != 0x060EDCB0u))) && ((return_key != 0x060EDDD8u && (return_key != 0x060EDEF8u && return_key != 0x060EE080u)) && (return_key != 0x06101668u && (return_key != 0x06101798u && return_key != 0x061018C8u))))) && ((((return_key != 0x061019F8u && (return_key != 0x06101B28u && return_key != 0x061056F0u)) && (return_key != 0x06105B00u && (return_key != 0x06105B90u && return_key != 0x061071C0u))) && ((return_key != 0x06107220u && (return_key != 0x0610E900u && return_key != 0x0610E960u)) && (return_key != 0x0610E9E8u && (return_key != 0x0610EA48u && return_key != 0x06111468u)))) && (((return_key != 0x06111500u && (return_key != 0x06115768u && return_key != 0x061157E0u)) && (return_key != 0x06115858u && (return_key != 0x061158F8u && return_key != 0x06115AD0u))) && ((return_key != 0x06115B70u && (return_key != 0x06115C10u && return_key != 0x06115CB0u)) && (return_key != 0x06116570u && (return_key != 0x06116608u && return_key != 0x06116908u)))))))) && (((((((return_key != 0x061169A0u && return_key != 0x06116BF0u) && (return_key != 0x06116CA8u && (return_key != 0x06116D60u && return_key != 0x06116E20u))) && ((return_key != 0x06118178u && (return_key != 0x06118210u && return_key != 0x061182B0u)) && (return_key != 0x06118368u && (return_key != 0x06118478u && return_key != 0x06118570u)))) && (((return_key != 0x06118668u && (return_key != 0x06118728u && return_key != 0x06118C98u)) && (return_key != 0x06118D38u && (return_key != 0x06118DD8u && return_key != 0x06118E78u))) && ((return_key != 0x06119298u && (return_key != 0x061193A8u && return_key != 0x061194A0u)) && (return_key != 0x06119598u && (return_key != 0x06119658u && return_key != 0x0611CB88u))))) && ((((return_key != 0x0611D820u && return_key != 0x0611E000u) && (return_key != 0x0611E060u && (return_key != 0x0611FAA0u && return_key != 0x0611FF10u))) && ((return_key != 0x06121E38u && (return_key != 0x06122048u && return_key != 0x061223F8u)) && (return_key != 0x06131578u && (return_key != 0x061317E0u && return_key != 0x06131888u)))) && (((return_key != 0x06131B78u && (return_key != 0x06131C18u && return_key != 0x06131FB0u)) && (return_key != 0x061321C0u && (return_key != 0x06132260u && return_key != 0x061322E8u))) && ((return_key != 0x06132358u && (return_key != 0x061323E0u && return_key != 0x06132468u)) && (return_key != 0x06132650u && (return_key != 0x061326D8u && return_key != 0x061331A8u)))))) && (((((return_key != 0x06133220u && return_key != 0x06135F78u) && (return_key != 0x06136018u && (return_key != 0x06136DA0u && return_key != 0x06136E40u))) && ((return_key != 0x06136EB0u && (return_key != 0x06136FB0u && return_key != 0x061375D0u)) && (return_key != 0x06137690u && (return_key != 0x061381D8u && return_key != 0x06138258u)))) && (((return_key != 0x0613B250u && (return_key != 0x0613B308u && return_key != 0x0613B3C0u)) && (return_key != 0x0613C1D0u && (return_key != 0x0613C288u && return_key != 0x0613C340u))) && ((return_key != 0x06143730u && (return_key != 0x061437B8u && return_key != 0x061455B0u)) && (return_key != 0x06145638u && (return_key != 0x06147F38u && return_key != 0x06148BA0u))))) && ((((return_key != 0x06149FB8u && (return_key != 0x0614ECB0u && return_key != 0x06151AF0u)) && (return_key != 0x06151BE0u && (return_key != 0x06152110u && return_key != 0x06152200u))) && ((return_key != 0x061574C8u && (return_key != 0x06157538u && return_key != 0x06157938u)) && (return_key != 0x06157998u && (return_key != 0x06157FC0u && return_key != 0x061582A8u)))) && (((return_key != 0x06159188u && (return_key != 0x06159448u && return_key != 0x0615A2C0u)) && (return_key != 0x0615A380u && (return_key != 0x0615A440u && return_key != 0x0615AB18u))) && ((return_key != 0x0615AB78u && (return_key != 0x0615AF48u && return_key != 0x0615AFB8u)) && (return_key != 0x0615B028u && (return_key != 0x0615B560u && return_key != 0x0615B5C0u))))))) && ((((((return_key != 0x06180C18u && return_key != 0x06180C90u) && (return_key != 0x06180CF0u && (return_key != 0x06180D78u && return_key != 0x06180E00u))) && ((return_key != 0x06180FB8u && (return_key != 0x06181340u && return_key != 0x06181710u)) && (return_key != 0x06181AE0u && (return_key != 0x06181EB0u && return_key != 0x06182280u)))) && (((return_key != 0x06182650u && (return_key != 0x06182A20u && return_key != 0x06182DF0u)) && (return_key != 0x061831C0u && (return_key != 0x06183590u && return_key != 0x06183960u))) && ((return_key != 0x06183D30u && (return_key != 0x06185808u && return_key != 0x06185968u)) && (return_key != 0x06186DC0u && (return_key != 0x06186F20u && return_key != 0x06188130u))))) && ((((return_key != 0x06188E60u && (return_key != 0x06189500u && return_key != 0x06189560u)) && (return_key != 0x0618C2F0u && (return_key != 0x0618C3E0u && return_key != 0x0618D8B8u))) && ((return_key != 0x0618E730u && (return_key != 0x0618E7F0u && return_key != 0x06190678u)) && (return_key != 0x06191E60u && (return_key != 0x06193AB0u && return_key != 0x06193B78u)))) && (((return_key != 0x06193C30u && (return_key != 0x06194318u && return_key != 0x06194FA0u)) && (return_key != 0x061988D0u && (return_key != 0x06199130u && return_key != 0x061994E0u))) && ((return_key != 0x06199590u && (return_key != 0x0619A050u && return_key != 0x0619A168u)) && (return_key != 0x0619A308u && (return_key != 0x0619A450u && return_key != 0x0619A548u)))))) && (((((return_key != 0x0619A658u && return_key != 0x0619A708u) && (return_key != 0x0619AB90u && (return_key != 0x0619AC00u && return_key != 0x0619ACC8u))) && ((return_key != 0x0619AD78u && (return_key != 0x0619AE28u && return_key != 0x0619AED8u)) && (return_key != 0x0619AFA0u && (return_key != 0x0619B050u && return_key != 0x0619B348u)))) && (((return_key != 0x0619C228u && (return_key != 0x0619C330u && return_key != 0x0619CC18u)) && (return_key != 0x0619CCF0u && (return_key != 0x0619CEE0u && return_key != 0x0619D7A0u))) && ((return_key != 0x0619D828u && (return_key != 0x0619DDB0u && return_key != 0x0619E020u)) && (return_key != 0x0619E548u && (return_key != 0x0619E958u && return_key != 0x0619F198u))))) && ((((return_key != 0x0619F250u && (return_key != 0x061A1DC0u && return_key != 0x061A1EC8u)) && (return_key != 0x061A2428u && (return_key != 0x061A2530u && return_key != 0x061A2858u))) && ((return_key != 0x061A28D8u && (return_key != 0x061A2998u && return_key != 0x061A2B28u)) && (return_key != 0x061A2C30u && (return_key != 0x061A2F00u && return_key != 0x061A2F80u)))) && (((return_key != 0x061A3030u && (return_key != 0x061A31A0u && return_key != 0x061A32A8u)) && (return_key != 0x061A3538u && (return_key != 0x061A35B8u && return_key != 0x061A3678u))) && ((return_key != 0x061A3848u && (return_key != 0x061A3950u && return_key != 0x061A3CE8u)) && (return_key != 0x061A3DF0u && (return_key != 0x061A7FB8u && return_key != 0x061A8B90u))))))))) && ((((((((return_key != 0x061A8D10u && return_key != 0x061A8FA8u) && (return_key != 0x061A9128u && (return_key != 0x061A94C8u && return_key != 0x061A9548u))) && ((return_key != 0x061A9850u && (return_key != 0x061A99D0u && return_key != 0x061A9EF8u)) && (return_key != 0x061A9F78u && (return_key != 0x061AA3D8u && return_key != 0x061AA538u)))) && (((return_key != 0x061AA780u && (return_key != 0x061AA848u && return_key != 0x061AA8C8u)) && (return_key != 0x061AADC8u && (return_key != 0x061AAE80u && return_key != 0x061AAFE8u))) && ((return_key != 0x061AB068u && (return_key != 0x061AB748u && return_key != 0x061AB7C8u)) && (return_key != 0x061AC030u && (return_key != 0x061AC190u && return_key != 0x061AC6E0u))))) && ((((return_key != 0x061AC7C8u && return_key != 0x061AC8A0u) && (return_key != 0x061AC920u && (return_key != 0x061AD060u && return_key != 0x061AD128u))) && ((return_key != 0x061AD1F0u && (return_key != 0x061AF6F0u && return_key != 0x061AF788u)) && (return_key != 0x061AF868u && (return_key != 0x061AF930u && return_key != 0x061B0190u)))) && (((return_key != 0x061B0258u && (return_key != 0x061B0338u && return_key != 0x061B03D0u)) && (return_key != 0x061B0870u && (return_key != 0x061B0958u && return_key != 0x061B0E60u))) && ((return_key != 0x061B0F28u && (return_key != 0x061B1010u && return_key != 0x061B10C8u)) && (return_key != 0x061B1350u && (return_key != 0x061B13D0u && return_key != 0x061B30A8u)))))) && (((((return_key != 0x061B31C0u && return_key != 0x061B3220u) && (return_key != 0x061B4118u && (return_key != 0x061B41B8u && return_key != 0x061B56C8u))) && ((return_key != 0x061B5808u && (return_key != 0x061B58D0u && return_key != 0x061B5B80u)) && (return_key != 0x061B5BF8u && (return_key != 0x061B6188u && return_key != 0x061B7A10u)))) && (((return_key != 0x061B7B20u && (return_key != 0x061B7BC0u && return_key != 0x061B7C68u)) && (return_key != 0x061B7D88u && (return_key != 0x061B7DE8u && return_key != 0x061B8048u))) && ((return_key != 0x061B8108u && (return_key != 0x061B83E0u && return_key != 0x061B8490u)) && (return_key != 0x061B9560u && (return_key != 0x061B95E8u && return_key != 0x061B96E8u))))) && ((((return_key != 0x061B9770u && (return_key != 0x061B9DE8u && return_key != 0x061B9E68u)) && (return_key != 0x061BA1F0u && (return_key != 0x061BA4D8u && return_key != 0x061BA598u))) && ((return_key != 0x061BB340u && (return_key != 0x061BB5E8u && return_key != 0x061BF5B8u)) && (return_key != 0x061BF638u && (return_key != 0x061BF808u && return_key != 0x061BF890u)))) && (((return_key != 0x061C3CB0u && (return_key != 0x061C3D38u && return_key != 0x061CD160u)) && (return_key != 0x061CD278u && (return_key != 0x061CD430u && return_key != 0x061CD4A0u))) && ((return_key != 0x061CD5C0u && (return_key != 0x061CD620u && return_key != 0x061CD920u)) && (return_key != 0x061CD9A8u && (return_key != 0x061CDA30u && return_key != 0x061CDAB8u))))))) && ((((((return_key != 0x061CDB58u && return_key != 0x061CDD30u) && (return_key != 0x061CDDB0u && (return_key != 0x061CE7D8u && return_key != 0x061CE9A0u))) && ((return_key != 0x061D1080u && (return_key != 0x061D10E0u && return_key != 0x061D11C8u)) && (return_key != 0x061D1228u && (return_key != 0x061D32A0u && return_key != 0x061D3350u)))) && (((return_key != 0x061D33B0u && (return_key != 0x061D35F0u && return_key != 0x061D36C8u)) && (return_key != 0x061D4BF0u && (return_key != 0x061D4C70u && return_key != 0x061D5220u))) && ((return_key != 0x061D5310u && (return_key != 0x061D69B0u && return_key != 0x061D6A48u)) && (return_key != 0x061D6B38u && (return_key != 0x061D82C8u && return_key != 0x061D8C30u))))) && ((((return_key != 0x061D9EB0u && (return_key != 0x061DA460u && return_key != 0x061DA4E0u)) && (return_key != 0x061DC688u && (return_key != 0x061DDB78u && return_key != 0x061DF448u))) && ((return_key != 0x061E0188u && (return_key != 0x061E0AD8u && return_key != 0x061E0BB0u)) && (return_key != 0x061E0D48u && (return_key != 0x061E0DE8u && return_key != 0x061E12E8u)))) && (((return_key != 0x061E13D0u && (return_key != 0x061E2F90u && return_key != 0x061E3190u)) && (return_key != 0x061E3368u && (return_key != 0x061E35B8u && return_key != 0x061E39E8u))) && ((return_key != 0x061E3AA0u && (return_key != 0x061E3DC8u && return_key != 0x061E3E80u)) && (return_key != 0x061E4C30u && (return_key != 0x061E4CE8u && return_key != 0x062015C8u)))))) && (((((return_key != 0x062017A0u && return_key != 0x06202F08u) && (return_key != 0x06203058u && (return_key != 0x062031C0u && return_key != 0x062033E0u))) && ((return_key != 0x06203550u && (return_key != 0x06203608u && return_key != 0x062036C0u)) && (return_key != 0x06203F30u && (return_key != 0x06204098u && return_key != 0x062044B8u)))) && (((return_key != 0x062048A8u && (return_key != 0x06204A10u && return_key != 0x06207998u)) && (return_key != 0x062079F8u && (return_key != 0x06207C70u && return_key != 0x06209978u))) && ((return_key != 0x06209A38u && (return_key != 0x06209A98u && return_key != 0x06209D10u)) && (return_key != 0x0620DA88u && (return_key != 0x06210660u && return_key != 0x062106F0u))))) && ((((return_key != 0x06210F38u && (return_key != 0x06211068u && return_key != 0x06211180u)) && (return_key != 0x06211288u && (return_key != 0x06211310u && return_key != 0x062118F8u))) && ((return_key != 0x06211A28u && (return_key != 0x06211B40u && return_key != 0x06211C48u)) && (return_key != 0x06211CD0u && (return_key != 0x06215F20u && return_key != 0x06216218u)))) && (((return_key != 0x06216E20u && (return_key != 0x06216EC0u && return_key != 0x06216F60u)) && (return_key != 0x06217000u && (return_key != 0x062176C0u && return_key != 0x06217830u))) && ((return_key != 0x06218D88u && (return_key != 0x06218EF8u && return_key != 0x062197A0u)) && (return_key != 0x06219A98u && (return_key != 0x06219B98u && return_key != 0x06219CC0u)))))))) && (((((((return_key != 0x0621A1D0u && return_key != 0x0621A340u) && (return_key != 0x0621E4E8u && (return_key != 0x0621E570u && return_key != 0x06222CB8u))) && ((return_key != 0x06222D40u && (return_key != 0x06224B60u && return_key != 0x06224C28u)) && (return_key != 0x06224CF0u && (return_key != 0x06224F58u && return_key != 0x06225020u)))) && (((return_key != 0x06228208u && (return_key != 0x062282E8u && return_key != 0x06228600u)) && (return_key != 0x062286E0u && (return_key != 0x0622A0E0u && return_key != 0x0622A230u))) && ((return_key != 0x0622A398u && (return_key != 0x0622A5B8u && return_key != 0x0622A728u)) && (return_key != 0x0622A7E0u && (return_key != 0x0622A898u && return_key != 0x0622B0D8u))))) && ((((return_key != 0x0622B240u && return_key != 0x0622B730u) && (return_key != 0x0622B7E0u && (return_key != 0x0622BA38u && return_key != 0x0622BBA0u))) && ((return_key != 0x0622BFB0u && (return_key != 0x0622D8B8u && return_key != 0x0622D948u)) && (return_key != 0x062310A0u && (return_key != 0x06231100u && return_key != 0x06231300u)))) && (((return_key != 0x06231360u && (return_key != 0x0623AD78u && return_key != 0x0623ADD8u)) && (return_key != 0x0623B448u && (return_key != 0x0623B588u && return_key != 0x0623B9E0u))) && ((return_key != 0x0623BB20u && (return_key != 0x0623E550u && return_key != 0x0623E5D8u)) && (return_key != 0x0623FD00u && (return_key != 0x0623FD88u && return_key != 0x0623FE10u)))))) && (((((return_key != 0x062423C0u && return_key != 0x06242508u) && (return_key != 0x06285D90u && (return_key != 0x06286728u && return_key != 0x062867B8u))) && ((return_key != 0x0628AAB8u && (return_key != 0x0628AB90u && return_key != 0x062929C8u)) && (return_key != 0x06294E48u && (return_key != 0x06294F10u && return_key != 0x06294FD8u)))) && (((return_key != 0x0629B8F8u && (return_key != 0x062AF238u && return_key != 0x062AF2B8u)) && (return_key != 0x062AF398u && (return_key != 0x062AF7C8u && return_key != 0x062AF850u))) && ((return_key != 0x062AF940u && (return_key != 0x062AF9C8u && return_key != 0x062AFAB0u)) && (return_key != 0x062AFB38u && (return_key != 0x062B1F60u && return_key != 0x062B2018u))))) && ((((return_key != 0x062B5D08u && (return_key != 0x062B5D90u && return_key != 0x062B74B8u)) && (return_key != 0x062B7528u && (return_key != 0x062B75B0u && return_key != 0x062BE3D0u))) && ((return_key != 0x062C7D20u && (return_key != 0x062C7E80u && return_key != 0x062C8370u)) && (return_key != 0x062C83D0u && (return_key != 0x062C8A90u && return_key != 0x062C8B00u)))) && (((return_key != 0x062C9380u && (return_key != 0x062C94F0u && return_key != 0x062CA078u)) && (return_key != 0x062CA0D8u && (return_key != 0x062CA730u && return_key != 0x062CA8B0u))) && ((return_key != 0x062CAA90u && (return_key != 0x062CAAF0u && return_key != 0x062CD928u)) && (return_key != 0x062CD9F0u && (return_key != 0x062CDAC8u && return_key != 0x062CDD00u))))))) && ((((((return_key != 0x062CDDC0u && return_key != 0x062CE610u) && (return_key != 0x062CE6D0u && (return_key != 0x062CE798u && return_key != 0x062CFEF8u))) && ((return_key != 0x062D35B8u && (return_key != 0x062D3670u && return_key != 0x062D4CB8u)) && (return_key != 0x062D4D50u && (return_key != 0x062D4E10u && return_key != 0x062D85B0u)))) && (((return_key != 0x062D8610u && (return_key != 0x062D9768u && return_key != 0x062D9BA8u)) && (return_key != 0x062DB0E0u && (return_key != 0x062DB1D0u && return_key != 0x06300098u))) && ((return_key != 0x063001C8u && (return_key != 0x06300640u && return_key != 0x063006E0u)) && (return_key != 0x06300780u && (return_key != 0x06300820u && return_key != 0x063008C0u))))) && ((((return_key != 0x06300960u && (return_key != 0x06300A00u && return_key != 0x06300AA0u)) && (return_key != 0x06300B40u && (return_key != 0x06300BE0u && return_key != 0x06303088u))) && ((return_key != 0x06303128u && (return_key != 0x06304318u && return_key != 0x063043E8u)) && (return_key != 0x063044A0u && (return_key != 0x06304558u && return_key != 0x06304610u)))) && (((return_key != 0x063046D0u && (return_key != 0x06304788u && return_key != 0x06304828u)) && (return_key != 0x06304CF0u && (return_key != 0x06305218u && return_key != 0x063090E0u))) && ((return_key != 0x06309140u && (return_key != 0x0630EA08u && return_key != 0x0630EAC0u)) && (return_key != 0x0630EB78u && (return_key != 0x06312790u && return_key != 0x063127F0u)))))) && (((((return_key != 0x06316CA0u && return_key != 0x06316D10u) && (return_key != 0x063251F0u && (return_key != 0x063252A0u && return_key != 0x063280E8u))) && ((return_key != 0x063281F8u && (return_key != 0x063283D0u && return_key != 0x06328458u)) && (return_key != 0x063284B8u && (return_key != 0x06328568u && return_key != 0x06328B80u)))) && (((return_key != 0x0632A5D0u && (return_key != 0x0632A680u && return_key != 0x06331148u)) && (return_key != 0x06332D48u && (return_key != 0x06332E40u && return_key != 0x06332F20u))) && ((return_key != 0x06332FF0u && (return_key != 0x06333F70u && return_key != 0x06334058u)) && (return_key != 0x06334140u && (return_key != 0x063342B0u && return_key != 0x06334388u))))) && ((((return_key != 0x06334470u && (return_key != 0x063344D0u && return_key != 0x063348D0u)) && (return_key != 0x06334A18u && (return_key != 0x06334B10u && return_key != 0x06334C30u))) && ((return_key != 0x06335D08u && (return_key != 0x06335DF0u && return_key != 0x06335ED8u)) && (return_key != 0x06336048u && (return_key != 0x06336120u && return_key != 0x063363C0u)))) && (((return_key != 0x063368E8u && (return_key != 0x06336AD8u && return_key != 0x06337010u)) && (return_key != 0x06337070u && (return_key != 0x06338B50u && return_key != 0x06338BD8u))) && ((return_key != 0x0633BA20u && (return_key != 0x0633E438u && return_key != 0x0633E498u)) && (return_key != 0x0633E4F8u && (return_key != 0x0633E7B8u && return_key != 0x0633E838u)))))))))) && (((((((((return_key != 0x0633F150u && return_key != 0x0633F1B0u) && (return_key != 0x0633F620u && (return_key != 0x0633F6A0u && return_key != 0x06342D68u))) && ((return_key != 0x06344838u && (return_key != 0x06344928u && return_key != 0x06344F38u)) && (return_key != 0x06345068u && (return_key != 0x06345158u && return_key != 0x063467B8u)))) && (((return_key != 0x06346D20u && (return_key != 0x06347D08u && return_key != 0x06347D78u)) && (return_key != 0x06348F78u && (return_key != 0x06349010u && return_key != 0x0634A588u))) && ((return_key != 0x0634A640u && (return_key != 0x0634A7D8u && return_key != 0x06350EA8u)) && (return_key != 0x06351078u && (return_key != 0x06354010u && return_key != 0x063565E0u))))) && ((((return_key != 0x0635DA50u && return_key != 0x0635F0A0u) && (return_key != 0x0635F530u && (return_key != 0x06360348u && return_key != 0x06361848u))) && ((return_key != 0x06362FC8u && (return_key != 0x063630E8u && return_key != 0x06363300u)) && (return_key != 0x063633C8u && (return_key != 0x06380BF8u && return_key != 0x06380CE8u)))) && (((return_key != 0x063810E0u && (return_key != 0x063811D0u && return_key != 0x06382F78u)) && (return_key != 0x06383040u && (return_key != 0x06383130u && return_key != 0x06383228u))) && ((return_key != 0x06383588u && (return_key != 0x06383608u && return_key != 0x063836A0u)) && (return_key != 0x06384C80u && (return_key != 0x06384D48u && return_key != 0x06384E20u)))))) && (((((return_key != 0x06384ED8u && return_key != 0x06384FC8u) && (return_key != 0x06385080u && (return_key != 0x063854F0u && return_key != 0x063855B8u))) && ((return_key != 0x06385690u && (return_key != 0x06385748u && return_key != 0x06385808u)) && (return_key != 0x063858C8u && (return_key != 0x06385980u && return_key != 0x063862E8u)))) && (((return_key != 0x063863B0u && (return_key != 0x06387708u && return_key != 0x06387790u)) && (return_key != 0x063880B8u && (return_key != 0x06388130u && return_key != 0x063883B8u))) && ((return_key != 0x06388CC8u && (return_key != 0x06388D28u && return_key != 0x06389D90u)) && (return_key != 0x0638B4D8u && (return_key != 0x0638B568u && return_key != 0x0638E9F8u))))) && ((((return_key != 0x0638EAF8u && (return_key != 0x06393208u && return_key != 0x06393BB8u)) && (return_key != 0x06393C18u && (return_key != 0x06395D98u && return_key != 0x06395E80u))) && ((return_key != 0x06399C10u && (return_key != 0x06399E50u && return_key != 0x06399ED8u)) && (return_key != 0x0639B480u && (return_key != 0x0639B500u && return_key != 0x0639D508u)))) && (((return_key != 0x0639D690u && (return_key != 0x063A5EA0u && return_key != 0x063A8450u)) && (return_key != 0x063ABA40u && (return_key != 0x063ABB20u && return_key != 0x063AC248u))) && ((return_key != 0x063AC2B8u && (return_key != 0x063ACCA0u && return_key != 0x063ACD40u)) && (return_key != 0x063AE7D8u && (return_key != 0x063B12F0u && return_key != 0x063B15F8u))))))) && ((((((return_key != 0x063B1658u && return_key != 0x063B1E58u) && (return_key != 0x063B25C8u && (return_key != 0x063B39C8u && return_key != 0x063B3A28u))) && ((return_key != 0x063B4438u && (return_key != 0x063B4570u && return_key != 0x063B5C28u)) && (return_key != 0x063B5CC0u && (return_key != 0x063B6198u && return_key != 0x063B6230u)))) && (((return_key != 0x063B62C8u && (return_key != 0x063B6360u && return_key != 0x063B8818u)) && (return_key != 0x063B88D8u && (return_key != 0x063B8CD0u && return_key != 0x063B8D88u))) && ((return_key != 0x063B8E40u && (return_key != 0x063BA058u && return_key != 0x063BA0B8u)) && (return_key != 0x063BD208u && (return_key != 0x063BDFB0u && return_key != 0x063BE080u))))) && ((((return_key != 0x063BE0F0u && (return_key != 0x063BE280u && return_key != 0x063BE350u)) && (return_key != 0x063BE3E8u && (return_key != 0x063BF3B8u && return_key != 0x063BF488u))) && ((return_key != 0x063BF638u && (return_key != 0x063BF708u && return_key != 0x063BF7A0u)) && (return_key != 0x063BFCF8u && (return_key != 0x063BFDC0u && return_key != 0x063C09A8u)))) && (((return_key != 0x063C0A08u && (return_key != 0x063C0B18u && return_key != 0x063C1A30u)) && (return_key != 0x063C1B00u && (return_key != 0x063C1C98u && return_key != 0x063C1D68u))) && ((return_key != 0x063C1E00u && (return_key != 0x063C3270u && return_key != 0x063C3308u)) && (return_key != 0x063C4208u && (return_key != 0x063C42D0u && return_key != 0x063CA170u)))))) && (((((return_key != 0x063CA4C0u && return_key != 0x063CA558u) && (return_key != 0x063CBD58u && (return_key != 0x063CBDF0u && return_key != 0x063CC848u))) && ((return_key != 0x063CCEE8u && (return_key != 0x063CCF80u && return_key != 0x063CD288u)) && (return_key != 0x063CD488u && (return_key != 0x063CE4B8u && return_key != 0x063CE540u)))) && (((return_key != 0x063D01F0u && (return_key != 0x063D0698u && return_key != 0x063D0760u)) && (return_key != 0x063D0828u && (return_key != 0x063D0B40u && return_key != 0x063D0C08u))) && ((return_key != 0x063D0CD0u && (return_key != 0x063D0EC8u && return_key != 0x063D0FC0u)) && (return_key != 0x063D1458u && (return_key != 0x063D1518u && return_key != 0x063D1A98u))))) && ((((return_key != 0x063D1AF8u && (return_key != 0x063D1EE0u && return_key != 0x063D1F50u)) && (return_key != 0x063D36F0u && (return_key != 0x063D3788u && return_key != 0x063D5D38u))) && ((return_key != 0x063D5F50u && (return_key != 0x063D6068u && return_key != 0x063D7A08u)) && (return_key != 0x063D7A78u && (return_key != 0x063D8D60u && return_key != 0x063D91F0u)))) && (((return_key != 0x063D9260u && (return_key != 0x063D9F30u && return_key != 0x063D9FA0u)) && (return_key != 0x063DA2B0u && (return_key != 0x063DB6A8u && return_key != 0x063DB718u))) && ((return_key != 0x063DC6A8u && (return_key != 0x063DC718u && return_key != 0x063DCBA0u)) && (return_key != 0x063DCF08u && (return_key != 0x063DCF78u && return_key != 0x063DD988u)))))))) && (((((((return_key != 0x063DDA50u && return_key != 0x063E78F8u) && (return_key != 0x063EAF88u && (return_key != 0x063EB008u && return_key != 0x063EC180u))) && ((return_key != 0x063EC1F0u && (return_key != 0x063EFB68u && return_key != 0x063EFC08u)) && (return_key != 0x063EFCA8u && (return_key != 0x063F0F58u && return_key != 0x063F1C68u)))) && (((return_key != 0x063F1DA0u && (return_key != 0x063F86E0u && return_key != 0x063F8828u)) && (return_key != 0x063F8EC0u && (return_key != 0x063F9008u && return_key != 0x063FADA0u))) && ((return_key != 0x063FAE30u && (return_key != 0x063FAEE0u && return_key != 0x063FB038u)) && (return_key != 0x063FB710u && (return_key != 0x063FB7D0u && return_key != 0x06406BB8u))))) && ((((return_key != 0x06406F60u && return_key != 0x064079D0u) && (return_key != 0x0640B2B8u && (return_key != 0x0640B3A8u && return_key != 0x0640B950u))) && ((return_key != 0x0640BA40u && (return_key != 0x0640EDF0u && return_key != 0x06410C48u)) && (return_key != 0x0641C248u && (return_key != 0x0641C2B8u && return_key != 0x0641D6D8u)))) && (((return_key != 0x0641E320u && (return_key != 0x06420838u && return_key != 0x064208E8u)) && (return_key != 0x06420DB8u && (return_key != 0x06420E68u && return_key != 0x064213B0u))) && ((return_key != 0x06421428u && (return_key != 0x064214D8u && return_key != 0x06421EE0u)) && (return_key != 0x06421F90u && (return_key != 0x06422040u && return_key != 0x064223B0u)))))) && (((((return_key != 0x06422460u && return_key != 0x06423210u) && (return_key != 0x06423270u && (return_key != 0x06423930u && return_key != 0x06423990u))) && ((return_key != 0x06424B48u && (return_key != 0x06424C08u && return_key != 0x06425018u)) && (return_key != 0x06425140u && (return_key != 0x06425218u && return_key != 0x064252B0u)))) && (((return_key != 0x06425738u && (return_key != 0x06425A28u && return_key != 0x06427B18u)) && (return_key != 0x06427BA0u && (return_key != 0x0642ADE8u && return_key != 0x0642AE88u))) && ((return_key != 0x0642C680u && (return_key != 0x0642C6E0u && return_key != 0x0642CAC0u)) && (return_key != 0x0642CB30u && (return_key != 0x0642CFC0u && return_key != 0x0642D070u))))) && ((((return_key != 0x0642E750u && (return_key != 0x0642E818u && return_key != 0x0642E8E0u)) && (return_key != 0x0642F688u && (return_key != 0x0642F6F8u && return_key != 0x064308C0u))) && ((return_key != 0x06430988u && (return_key != 0x06430A50u && return_key != 0x06432B70u)) && (return_key != 0x06432C38u && (return_key != 0x06433E60u && return_key != 0x06433EE8u)))) && (((return_key != 0x06434538u && (return_key != 0x064345A8u && return_key != 0x064398A8u)) && (return_key != 0x06439918u && (return_key != 0x06485AA8u && return_key != 0x06485B98u))) && ((return_key != 0x06485C80u && (return_key != 0x06485F00u && return_key != 0x06486120u)) && (return_key != 0x064864C0u && (return_key != 0x06486600u && return_key != 0x06486B10u))))))) && ((((((return_key != 0x06488C90u && return_key != 0x06488D58u) && (return_key != 0x0648B830u && (return_key != 0x0648B998u && return_key != 0x0648C6E8u))) && ((return_key != 0x0648C850u && (return_key != 0x0648D5C8u && return_key != 0x0648E8B0u)) && (return_key != 0x0648EA90u && (return_key != 0x06490460u && return_key != 0x06490528u)))) && (((return_key != 0x064905F0u && (return_key != 0x064906A8u && return_key != 0x06490D00u)) && (return_key != 0x06490EB8u && (return_key != 0x06492EC8u && return_key != 0x06492F80u))) && ((return_key != 0x06495178u && (return_key != 0x06495240u && return_key != 0x064952F8u)) && (return_key != 0x064957C0u && (return_key != 0x06496900u && return_key != 0x06497AA0u))))) && ((((return_key != 0x06498320u && (return_key != 0x064987A8u && return_key != 0x06498818u)) && (return_key != 0x06499208u && (return_key != 0x06499278u && return_key != 0x06499B58u))) && ((return_key != 0x06499CF0u && (return_key != 0x0649CCE0u && return_key != 0x0649CE00u)) && (return_key != 0x0649D180u && (return_key != 0x0649D4D0u && return_key != 0x0649DEA0u)))) && (((return_key != 0x0649DF30u && (return_key != 0x0649E0F8u && return_key != 0x0649E2E8u)) && (return_key != 0x0649E668u && (return_key != 0x0649E6C8u && return_key != 0x0649E818u))) && ((return_key != 0x0649E878u && (return_key != 0x0649E8D8u && return_key != 0x0649F0E0u)) && (return_key != 0x0649F168u && (return_key != 0x064A1860u && return_key != 0x064A18E8u)))))) && (((((return_key != 0x064A3388u && return_key != 0x064A3460u) && (return_key != 0x064A3978u && (return_key != 0x064A3A50u && return_key != 0x064A4480u))) && ((return_key != 0x064A4558u && (return_key != 0x064A54E0u && return_key != 0x064A55B8u)) && (return_key != 0x064A5F58u && (return_key != 0x064A5FF0u && return_key != 0x064A6BF8u)))) && (((return_key != 0x064A6E40u && (return_key != 0x064A7C78u && return_key != 0x064AEBF0u)) && (return_key != 0x064AEC88u && (return_key != 0x064AFC10u && return_key != 0x064AFCD8u))) && ((return_key != 0x064B0178u && (return_key != 0x064B0240u && return_key != 0x064B07E0u)) && (return_key != 0x064B08A8u && (return_key != 0x064B10F0u && return_key != 0x064B11B8u))))) && ((((return_key != 0x064B2638u && (return_key != 0x064B2740u && return_key != 0x064B7158u)) && (return_key != 0x064B7270u && (return_key != 0x064B72D0u && return_key != 0x064B7BA8u))) && ((return_key != 0x064B7C48u && (return_key != 0x064B7DD8u && return_key != 0x064B7E60u)) && (return_key != 0x064B8278u && (return_key != 0x064B8658u && return_key != 0x064B8718u)))) && (((return_key != 0x064B87B8u && (return_key != 0x064B9B08u && return_key != 0x064B9C28u)) && (return_key != 0x064BDC90u && (return_key != 0x064BDD28u && return_key != 0x064BDDD0u))) && ((return_key != 0x064BDEF8u && (return_key != 0x064BDFB8u && return_key != 0x064BE6F0u)) && (return_key != 0x064BE7B0u && (return_key != 0x064C15D0u && return_key != 0x064C1670u))))))))) && ((((((((return_key != 0x064C6298u && return_key != 0x064C6388u) && (return_key != 0x064C7630u && (return_key != 0x064C7720u && return_key != 0x064CAAC8u))) && ((return_key != 0x064CF860u && (return_key != 0x064CF918u && return_key != 0x064CF9D0u)) && (return_key != 0x064CFA88u && (return_key != 0x064D1668u && return_key != 0x064D1708u)))) && (((return_key != 0x064D1848u && (return_key != 0x064D18E8u && return_key != 0x064D1960u)) && (return_key != 0x064D1A00u && (return_key != 0x064D1A78u && return_key != 0x064D1B18u))) && ((return_key != 0x064D3888u && (return_key != 0x064D3900u && return_key != 0x064D39A0u)) && (return_key != 0x064D4D90u && (return_key != 0x064D4E30u && return_key != 0x064D4ED0u))))) && ((((return_key != 0x064D5D30u && return_key != 0x064D5DD0u) && (return_key != 0x064D5F10u && (return_key != 0x064D6450u && return_key != 0x064D67F0u))) && ((return_key != 0x064DD030u && (return_key != 0x064DD170u && return_key != 0x064DD220u)) && (return_key != 0x064DD2C0u && (return_key != 0x064DDD10u && return_key != 0x064DDDD0u)))) && (((return_key != 0x064DE418u && (return_key != 0x064DE528u && return_key != 0x064DE5A8u)) && (return_key != 0x064DE630u && (return_key != 0x064DED88u && return_key != 0x064DEE30u))) && ((return_key != 0x064E11B8u && (return_key != 0x064E1218u && return_key != 0x064E1350u)) && (return_key != 0x064E3028u && (return_key != 0x064E3120u && return_key != 0x064E3218u)))))) && (((((return_key != 0x064E4668u && return_key != 0x064E46D8u) && (return_key != 0x064E9FD0u && (return_key != 0x064EA040u && return_key != 0x064F18D0u))) && ((return_key != 0x064F19E0u && (return_key != 0x064F23D8u && return_key != 0x064F24A0u)) && (return_key != 0x064F2908u && (return_key != 0x064F29D0u && return_key != 0x065005E0u)))) && (((return_key != 0x06501B48u && (return_key != 0x06504778u && return_key != 0x06504800u)) && (return_key != 0x065059C8u && (return_key != 0x06505B50u && return_key != 0x06506178u))) && ((return_key != 0x06506258u && (return_key != 0x065062E8u && return_key != 0x065063C8u)) && (return_key != 0x065064B8u && (return_key != 0x06506598u && return_key != 0x06506628u))))) && ((((return_key != 0x06506708u && (return_key != 0x06507E70u && return_key != 0x06507FE8u)) && (return_key != 0x0650A140u && (return_key != 0x0650A1F0u && return_key != 0x0650A288u))) && ((return_key != 0x0650A958u && (return_key != 0x0650AA08u && return_key != 0x0650AAA0u)) && (return_key != 0x0650B1F0u && (return_key != 0x0650BA78u && return_key != 0x0650BB28u)))) && (((return_key != 0x0650BBD8u && (return_key != 0x0650DD98u && return_key != 0x0650DE88u)) && (return_key != 0x0650DF90u && (return_key != 0x065110B0u && return_key != 0x06511650u))) && ((return_key != 0x06514310u && (return_key != 0x065143B0u && return_key != 0x065149F8u)) && (return_key != 0x06514BB0u && (return_key != 0x06515F18u && return_key != 0x06516050u))))))) && ((((((return_key != 0x06516718u && return_key != 0x06517DA8u) && (return_key != 0x06519778u && (return_key != 0x06519818u && return_key != 0x06519DE0u))) && ((return_key != 0x06519F98u && (return_key != 0x0651B198u && return_key != 0x0651B218u)) && (return_key != 0x0651B298u && (return_key != 0x0651B418u && return_key != 0x0651B590u)))) && (((return_key != 0x0651BCB8u && (return_key != 0x0651DA88u && return_key != 0x0651DB28u)) && (return_key != 0x0651E3B0u && (return_key != 0x0651E568u && return_key != 0x06520980u))) && ((return_key != 0x06520A60u && (return_key != 0x06520B78u && return_key != 0x06522528u)) && (return_key != 0x06523868u && (return_key != 0x065238F8u && return_key != 0x06523A18u))))) && ((((return_key != 0x06523BA0u && (return_key != 0x06523D80u && return_key != 0x06526130u)) && (return_key != 0x06526328u && (return_key != 0x06526430u && return_key != 0x065264D8u))) && ((return_key != 0x065265E0u && (return_key != 0x065284C0u && return_key != 0x065298E0u)) && (return_key != 0x0652A678u && (return_key != 0x0652A768u && return_key != 0x0652BBA0u)))) && (((return_key != 0x0652BC58u && (return_key != 0x06533068u && return_key != 0x06533108u)) && (return_key != 0x06534100u && (return_key != 0x06534160u && return_key != 0x065350A0u))) && ((return_key != 0x06535128u && (return_key != 0x06535228u && return_key != 0x065352B0u)) && (return_key != 0x06535D90u && (return_key != 0x06535E10u && return_key != 0x065361B8u)))))) && (((((return_key != 0x065364C0u && return_key != 0x065365A0u) && (return_key != 0x065379B8u && (return_key != 0x06537B60u && return_key != 0x06539168u))) && ((return_key != 0x0653A140u && (return_key != 0x0653A1E0u && return_key != 0x0653A298u)) && (return_key != 0x0653A370u && (return_key != 0x0653A590u && return_key != 0x0653A640u)))) && (((return_key != 0x0653A6F8u && (return_key != 0x0653A800u && return_key != 0x0653A968u)) && (return_key != 0x0653AA08u && (return_key != 0x0653AAC0u && return_key != 0x0653AC38u))) && ((return_key != 0x06542288u && (return_key != 0x06542E50u && return_key != 0x06543038u)) && (return_key != 0x06543B10u && (return_key != 0x06543BE8u && return_key != 0x06546438u))))) && ((((return_key != 0x065465C0u && (return_key != 0x06546660u && return_key != 0x06546700u)) && (return_key != 0x065475F8u && (return_key != 0x06547678u && return_key != 0x065497E8u))) && ((return_key != 0x06549848u && (return_key != 0x0654ACE0u && return_key != 0x0654CFB0u)) && (return_key != 0x0654E2F0u && (return_key != 0x0660C640u && return_key != 0x0660C6C0u)))) && (((return_key != 0x0660F850u && (return_key != 0x0660F8D0u && return_key != 0x066107F8u)) && (return_key != 0x066108E0u && (return_key != 0x06610E38u && return_key != 0x06610F60u))) && ((return_key != 0x06612090u && (return_key != 0x06612938u && return_key != 0x06612C88u)) && (return_key != 0x06613FB0u && (return_key != 0x06614070u && return_key != 0x066140E0u)))))))) && (((((((return_key != 0x066141A0u && return_key != 0x06615C50u) && (return_key != 0x066162B0u && (return_key != 0x06616370u && return_key != 0x066163E0u))) && ((return_key != 0x066164A0u && (return_key != 0x06616E90u && return_key != 0x066171C0u)) && (return_key != 0x06617378u && (return_key != 0x06617A68u && return_key != 0x06617C90u)))) && (((return_key != 0x06617E48u && (return_key != 0x06619728u && return_key != 0x066197E8u)) && (return_key != 0x06619E10u && (return_key != 0x0661B110u && return_key != 0x0661E5F8u))) && ((return_key != 0x0661E668u && (return_key != 0x06634BA8u && return_key != 0x06635290u)) && (return_key != 0x0665FA28u && (return_key != 0x0665FAE0u && return_key != 0x0665FC78u))))) && ((((return_key != 0x06684A10u && return_key != 0x0668A090u) && (return_key != 0x0668A130u && (return_key != 0x0668A1D0u && return_key != 0x0668A4F8u))) && ((return_key != 0x0668A598u && (return_key != 0x0668A638u && return_key != 0x0668A980u)) && (return_key != 0x0668AA20u && (return_key != 0x0668AAC0u && return_key != 0x0668ADE8u)))) && (((return_key != 0x0668AE88u && (return_key != 0x0668AF28u && return_key != 0x0668EE38u)) && (return_key != 0x0668EF40u && (return_key != 0x0668F740u && return_key != 0x0668FAA0u))) && ((return_key != 0x0668FC98u && (return_key != 0x0668FD48u && return_key != 0x0668FE10u)) && (return_key != 0x06690148u && (return_key != 0x066901E8u && return_key != 0x066902D8u)))))) && (((((return_key != 0x066903E0u && return_key != 0x06690CA8u) && (return_key != 0x06691610u && (return_key != 0x06691718u && return_key != 0x06691A48u))) && ((return_key != 0x06691F28u && (return_key != 0x06692588u && return_key != 0x06692690u)) && (return_key != 0x06692AE0u && (return_key != 0x06692F48u && return_key != 0x06693050u)))) && (((return_key != 0x066934A0u && (return_key != 0x06693910u && return_key != 0x066940D0u)) && (return_key != 0x066941D8u && (return_key != 0x066945F0u && return_key != 0x06695160u))) && ((return_key != 0x06695250u && (return_key != 0x06695358u && return_key != 0x066956B0u)) && (return_key != 0x06695820u && (return_key != 0x066958D0u && return_key != 0x06696998u))))) && ((((return_key != 0x06697038u && (return_key != 0x06697230u && return_key != 0x066972E0u)) && (return_key != 0x066973A8u && (return_key != 0x066979B0u && return_key != 0x06697BA8u))) && ((return_key != 0x06697C58u && (return_key != 0x06697D20u && return_key != 0x06698408u)) && (return_key != 0x06698600u && (return_key != 0x066986B0u && return_key != 0x06698778u)))) && (((return_key != 0x0669BB28u && (return_key != 0x0669BB88u && return_key != 0x066A9328u)) && (return_key != 0x066A93D8u && (return_key != 0x066A9F70u && return_key != 0x066AA010u))) && ((return_key != 0x066AAF18u && (return_key != 0x066AB308u && return_key != 0x066AB430u)) && (return_key != 0x066AB4D0u && (return_key != 0x066AC888u && return_key != 0x066AC9B0u))))))) && ((((((return_key != 0x066ACA20u && return_key != 0x066AD6E0u) && (return_key != 0x066AD740u && (return_key != 0x066AD7A0u && return_key != 0x066AD828u))) && ((return_key != 0x066ADE30u && (return_key != 0x066B00C0u && return_key != 0x066B0120u)) && (return_key != 0x066B01A8u && (return_key != 0x066B0208u && return_key != 0x066B1E98u)))) && (((return_key != 0x066B1EF8u && (return_key != 0x066B1F80u && return_key != 0x066B1FE0u)) && (return_key != 0x066B27B8u && (return_key != 0x066B2840u && return_key != 0x066B3CE0u))) && ((return_key != 0x066B3D68u && (return_key != 0x066B4630u && return_key != 0x066B46B8u)) && (return_key != 0x066B73B0u && (return_key != 0x066B7460u && return_key != 0x066B9A40u))))) && ((((return_key != 0x066B9AF0u && (return_key != 0x066B9D78u && return_key != 0x066B9EC0u)) && (return_key != 0x066BA3B0u && (return_key != 0x066BA4F8u && return_key != 0x066BB368u))) && ((return_key != 0x066BB3D8u && (return_key != 0x066BE950u && return_key != 0x066BEA10u)) && (return_key != 0x066BEBB0u && (return_key != 0x066BF4C8u && return_key != 0x066C02C0u)))) && (((return_key != 0x066C0320u && (return_key != 0x066C26D0u && return_key != 0x066C2CB8u)) && (return_key != 0x066C2D48u && (return_key != 0x066D3470u && return_key != 0x066D3868u))) && ((return_key != 0x066D73D8u && (return_key != 0x066DCB88u && return_key != 0x066DCC10u)) && (return_key != 0x066DEBD8u && (return_key != 0x066DEC60u && return_key != 0x066E0960u)))))) && (((((return_key != 0x066E0A08u && return_key != 0x066E1578u) && (return_key != 0x066E1600u && (return_key != 0x066E48C0u && return_key != 0x066E4940u))) && ((return_key != 0x06701C28u && (return_key != 0x06701CF0u && return_key != 0x06701DB8u)) && (return_key != 0x06702A38u && (return_key != 0x06702E70u && return_key != 0x067030E8u)))) && (((return_key != 0x06703198u && (return_key != 0x06703258u && return_key != 0x067036D8u)) && (return_key != 0x06703760u && (return_key != 0x06704A10u && return_key != 0x0670C198u))) && ((return_key != 0x0670C208u && (return_key != 0x0670E518u && return_key != 0x0670EF78u)) && (return_key != 0x06710E10u && (return_key != 0x06710E98u && return_key != 0x06711A88u))))) && ((((return_key != 0x06711AF8u && (return_key != 0x06711EA8u && return_key != 0x06711FD0u)) && (return_key != 0x06713648u && (return_key != 0x067136B8u && return_key != 0x06713A40u))) && ((return_key != 0x06714850u && (return_key != 0x06714E28u && return_key != 0x067159D8u)) && (return_key != 0x06715FD0u && (return_key != 0x067188F0u && return_key != 0x0671F5F0u)))) && (((return_key != 0x0671F6A0u && (return_key != 0x0671FB70u && return_key != 0x0671FC20u)) && (return_key != 0x06720168u && (return_key != 0x067201E0u && return_key != 0x06720290u))) && ((return_key != 0x06720E08u && (return_key != 0x06720E68u && return_key != 0x06723170u)) && (return_key != 0x067231D0u && (return_key != 0x067235B8u && return_key != 0x06723628u))))))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FEED8u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDDBu,
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
            cpu->pc = 0xFDDDu;
            if (nh_scpu_expect_next(cpu, 0x060FEEE8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEEE8u: {
            static const uint8_t expected_epoch[] = { 0xC5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDDDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            const uint32_t address = (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu);
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            const uint16_t result = (uint16_t)(cpu->a - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if (cpu->a >= right) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDDFu;
            if (nh_scpu_expect_next(cpu, 0x060FEEF8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEEF8u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0xF4u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDDFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFDD5u;
                if (nh_scpu_expect_next(cpu, 0x060FEEA8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDE1u;
            if (nh_scpu_expect_next(cpu, 0x060FEF08u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FEF08u: {
            static const uint8_t expected_epoch[] = { 0x80u, 0x0Cu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDE1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDEFu;
            if (nh_scpu_expect_next(cpu, 0x060FEF78u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FEF18u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDE3u,
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
            cpu->pc = 0xFDE5u;
            if (nh_scpu_expect_next(cpu, 0x060FEF28u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEF28u: {
            static const uint8_t expected_epoch[] = { 0xC5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDE5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            const uint32_t address = (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu);
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            const uint16_t result = (uint16_t)(cpu->a - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if (cpu->a >= right) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDE7u;
            if (nh_scpu_expect_next(cpu, 0x060FEF38u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEF38u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0xECu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDE7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFDD5u;
                if (nh_scpu_expect_next(cpu, 0x060FEEA8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDE9u;
            if (nh_scpu_expect_next(cpu, 0x060FEF48u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FEF48u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDE9u,
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
            cpu->pc = 0xFDEBu;
            if (nh_scpu_expect_next(cpu, 0x060FEF58u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEF58u: {
            static const uint8_t expected_epoch[] = { 0xC5u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDEBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            const uint32_t address = (uint32_t)((cpu->d + 0x000006u) & 0xFFFFu);
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t right = (uint16_t)(low | ((uint16_t)high << 8u));
            const uint16_t result = (uint16_t)(cpu->a - right);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            if (cpu->a >= right) cpu->p |= NH_P_C;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDEDu;
            if (nh_scpu_expect_next(cpu, 0x060FEF68u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEF68u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0xE6u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDEDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFDD5u;
                if (nh_scpu_expect_next(cpu, 0x060FEEA8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDEFu;
            if (nh_scpu_expect_next(cpu, 0x060FEF78u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FEF78u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDEFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDF1u;
            if (nh_scpu_expect_next(cpu, 0x060FEF88u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FEF88u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDF1u,
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
            if (((((((((((return_key != 0x06080250u && return_key != 0x06080330u) && (return_key != 0x06080390u && (return_key != 0x060824F0u && return_key != 0x06082E50u))) && ((return_key != 0x06082EB0u && (return_key != 0x06082FB0u && return_key != 0x060831B0u)) && (return_key != 0x06083588u && (return_key != 0x060835E8u && return_key != 0x06083750u)))) && (((return_key != 0x060837B0u && (return_key != 0x06086620u && return_key != 0x06086D00u)) && (return_key != 0x06088078u && (return_key != 0x060880D8u && return_key != 0x060889E0u))) && ((return_key != 0x06088A68u && (return_key != 0x06089000u && return_key != 0x06089088u)) && (return_key != 0x0608A8F0u && (return_key != 0x0608F7E0u && return_key != 0x0608F858u))))) && ((((return_key != 0x0608F920u && return_key != 0x0608F9B0u) && (return_key != 0x0608FB70u && (return_key != 0x0608FC38u && return_key != 0x060915A0u))) && ((return_key != 0x06091688u && (return_key != 0x060918E8u && return_key != 0x060919B0u)) && (return_key != 0x06091A68u && (return_key != 0x06091DE8u && return_key != 0x06092898u)))) && (((return_key != 0x06092908u && (return_key != 0x060941E0u && return_key != 0x060942C8u)) && (return_key != 0x06094528u && (return_key != 0x060945F0u && return_key != 0x060946A8u))) && ((return_key != 0x06094A28u && (return_key != 0x060954D8u && return_key != 0x06095548u)) && (return_key != 0x060970E8u && (return_key != 0x06097158u && return_key != 0x0609A9F0u)))))) && (((((return_key != 0x0609AB70u && return_key != 0x060A2548u) && (return_key != 0x060A7D58u && (return_key != 0x060A7DE0u && return_key != 0x060A7E68u))) && ((return_key != 0x060A7F18u && (return_key != 0x060AA448u && return_key != 0x060AC7F8u)) && (return_key != 0x060AC8A8u && (return_key != 0x060ACA00u && return_key != 0x060ACAB0u)))) && (((return_key != 0x060AD8E8u && (return_key != 0x060ADA88u && return_key != 0x060ADD70u)) && (return_key != 0x060ADF10u && (return_key != 0x060ADF70u && return_key != 0x060B00A8u))) && ((return_key != 0x060B0130u && (return_key != 0x060B1D90u && return_key != 0x060B1DF0u)) && (return_key != 0x060B2868u && (return_key != 0x060B2C20u && return_key != 0x060B2C90u))))) && ((((return_key != 0x060B2F98u && (return_key != 0x060B3008u && return_key != 0x060B3318u)) && (return_key != 0x060B3420u && (return_key != 0x060B38F0u && return_key != 0x060B3980u))) && ((return_key != 0x060B3D10u && (return_key != 0x060B3E18u && return_key != 0x060B82F8u)) && (return_key != 0x060B8380u && (return_key != 0x060B86E8u && return_key != 0x060B8770u)))) && (((return_key != 0x060BA6F8u && (return_key != 0x060BB760u && return_key != 0x060BB7E8u)) && (return_key != 0x060C0D28u && (return_key != 0x060C0D98u && return_key != 0x060C0E08u))) && ((return_key != 0x060C1268u && (return_key != 0x060C12C8u && return_key != 0x060C1340u)) && (return_key != 0x060C13A0u && (return_key != 0x060C2BD8u && return_key != 0x060C2C38u))))))) && ((((((return_key != 0x060C9248u && return_key != 0x060CD5A0u) && (return_key != 0x060CD628u && (return_key != 0x060CD6B0u && return_key != 0x060CD7A8u))) && ((return_key != 0x060CD850u && (return_key != 0x060CDA88u && return_key != 0x060CDB28u)) && (return_key != 0x060CDBC8u && (return_key != 0x060CEEC0u && return_key != 0x060CEF70u)))) && (((return_key != 0x060CF038u && (return_key != 0x060CFC80u && return_key != 0x060CFD30u)) && (return_key != 0x060CFDF8u && (return_key != 0x060D0658u && return_key != 0x060D0708u))) && ((return_key != 0x060D07D0u && (return_key != 0x060D10F8u && return_key != 0x060D11D8u)) && (return_key != 0x060D1288u && (return_key != 0x060D28E0u && return_key != 0x060D2958u))))) && ((((return_key != 0x060D8B98u && return_key != 0x060D8CA0u) && (return_key != 0x060D9AA8u && (return_key != 0x060DAC08u && return_key != 0x060DC9C0u))) && ((return_key != 0x060DE6C8u && (return_key != 0x060DE778u && return_key != 0x060DE840u)) && (return_key != 0x060DED90u && (return_key != 0x060DEE40u && return_key != 0x060DEF08u)))) && (((return_key != 0x060DF530u && (return_key != 0x060E0AE8u && return_key != 0x060E0B98u)) && (return_key != 0x060E0C60u && (return_key != 0x060E2380u && return_key != 0x060E23E0u))) && ((return_key != 0x060E2478u && (return_key != 0x060E24F8u && return_key != 0x060E2580u)) && (return_key != 0x060E2608u && (return_key != 0x060E2668u && return_key != 0x060E26C8u)))))) && (((((return_key != 0x060E2820u && return_key != 0x060E2880u) && (return_key != 0x060E6430u && (return_key != 0x060E9C20u && return_key != 0x060EA570u))) && ((return_key != 0x060EA8D8u && (return_key != 0x060EB940u && return_key != 0x060EB9F0u)) && (return_key != 0x060EBAB8u && (return_key != 0x060EBD80u && return_key != 0x060EBE88u)))) && (((return_key != 0x060EC2D0u && (return_key != 0x060EC380u && return_key != 0x060EC448u)) && (return_key != 0x060EDA70u && (return_key != 0x060EDBB8u && return_key != 0x060EDCB0u))) && ((return_key != 0x060EDDD8u && (return_key != 0x060EDEF8u && return_key != 0x060EE080u)) && (return_key != 0x06101668u && (return_key != 0x06101798u && return_key != 0x061018C8u))))) && ((((return_key != 0x061019F8u && (return_key != 0x06101B28u && return_key != 0x061056F0u)) && (return_key != 0x06105B00u && (return_key != 0x06105B90u && return_key != 0x061071C0u))) && ((return_key != 0x06107220u && (return_key != 0x0610E900u && return_key != 0x0610E960u)) && (return_key != 0x0610E9E8u && (return_key != 0x0610EA48u && return_key != 0x06111468u)))) && (((return_key != 0x06111500u && (return_key != 0x06115768u && return_key != 0x061157E0u)) && (return_key != 0x06115858u && (return_key != 0x061158F8u && return_key != 0x06115AD0u))) && ((return_key != 0x06115B70u && (return_key != 0x06115C10u && return_key != 0x06115CB0u)) && (return_key != 0x06116570u && (return_key != 0x06116608u && return_key != 0x06116908u)))))))) && (((((((return_key != 0x061169A0u && return_key != 0x06116BF0u) && (return_key != 0x06116CA8u && (return_key != 0x06116D60u && return_key != 0x06116E20u))) && ((return_key != 0x06118178u && (return_key != 0x06118210u && return_key != 0x061182B0u)) && (return_key != 0x06118368u && (return_key != 0x06118478u && return_key != 0x06118570u)))) && (((return_key != 0x06118668u && (return_key != 0x06118728u && return_key != 0x06118C98u)) && (return_key != 0x06118D38u && (return_key != 0x06118DD8u && return_key != 0x06118E78u))) && ((return_key != 0x06119298u && (return_key != 0x061193A8u && return_key != 0x061194A0u)) && (return_key != 0x06119598u && (return_key != 0x06119658u && return_key != 0x0611CB88u))))) && ((((return_key != 0x0611D820u && return_key != 0x0611E000u) && (return_key != 0x0611E060u && (return_key != 0x0611FAA0u && return_key != 0x0611FF10u))) && ((return_key != 0x06121E38u && (return_key != 0x06122048u && return_key != 0x061223F8u)) && (return_key != 0x06131578u && (return_key != 0x061317E0u && return_key != 0x06131888u)))) && (((return_key != 0x06131B78u && (return_key != 0x06131C18u && return_key != 0x06131FB0u)) && (return_key != 0x061321C0u && (return_key != 0x06132260u && return_key != 0x061322E8u))) && ((return_key != 0x06132358u && (return_key != 0x061323E0u && return_key != 0x06132468u)) && (return_key != 0x06132650u && (return_key != 0x061326D8u && return_key != 0x061331A8u)))))) && (((((return_key != 0x06133220u && return_key != 0x06135F78u) && (return_key != 0x06136018u && (return_key != 0x06136DA0u && return_key != 0x06136E40u))) && ((return_key != 0x06136EB0u && (return_key != 0x06136FB0u && return_key != 0x061375D0u)) && (return_key != 0x06137690u && (return_key != 0x061381D8u && return_key != 0x06138258u)))) && (((return_key != 0x0613B250u && (return_key != 0x0613B308u && return_key != 0x0613B3C0u)) && (return_key != 0x0613C1D0u && (return_key != 0x0613C288u && return_key != 0x0613C340u))) && ((return_key != 0x06143730u && (return_key != 0x061437B8u && return_key != 0x061455B0u)) && (return_key != 0x06145638u && (return_key != 0x06147F38u && return_key != 0x06148BA0u))))) && ((((return_key != 0x06149FB8u && (return_key != 0x0614ECB0u && return_key != 0x06151AF0u)) && (return_key != 0x06151BE0u && (return_key != 0x06152110u && return_key != 0x06152200u))) && ((return_key != 0x061574C8u && (return_key != 0x06157538u && return_key != 0x06157938u)) && (return_key != 0x06157998u && (return_key != 0x06157FC0u && return_key != 0x061582A8u)))) && (((return_key != 0x06159188u && (return_key != 0x06159448u && return_key != 0x0615A2C0u)) && (return_key != 0x0615A380u && (return_key != 0x0615A440u && return_key != 0x0615AB18u))) && ((return_key != 0x0615AB78u && (return_key != 0x0615AF48u && return_key != 0x0615AFB8u)) && (return_key != 0x0615B028u && (return_key != 0x0615B560u && return_key != 0x0615B5C0u))))))) && ((((((return_key != 0x06180C18u && return_key != 0x06180C90u) && (return_key != 0x06180CF0u && (return_key != 0x06180D78u && return_key != 0x06180E00u))) && ((return_key != 0x06180FB8u && (return_key != 0x06181340u && return_key != 0x06181710u)) && (return_key != 0x06181AE0u && (return_key != 0x06181EB0u && return_key != 0x06182280u)))) && (((return_key != 0x06182650u && (return_key != 0x06182A20u && return_key != 0x06182DF0u)) && (return_key != 0x061831C0u && (return_key != 0x06183590u && return_key != 0x06183960u))) && ((return_key != 0x06183D30u && (return_key != 0x06185808u && return_key != 0x06185968u)) && (return_key != 0x06186DC0u && (return_key != 0x06186F20u && return_key != 0x06188130u))))) && ((((return_key != 0x06188E60u && (return_key != 0x06189500u && return_key != 0x06189560u)) && (return_key != 0x0618C2F0u && (return_key != 0x0618C3E0u && return_key != 0x0618D8B8u))) && ((return_key != 0x0618E730u && (return_key != 0x0618E7F0u && return_key != 0x06190678u)) && (return_key != 0x06191E60u && (return_key != 0x06193AB0u && return_key != 0x06193B78u)))) && (((return_key != 0x06193C30u && (return_key != 0x06194318u && return_key != 0x06194FA0u)) && (return_key != 0x061988D0u && (return_key != 0x06199130u && return_key != 0x061994E0u))) && ((return_key != 0x06199590u && (return_key != 0x0619A050u && return_key != 0x0619A168u)) && (return_key != 0x0619A308u && (return_key != 0x0619A450u && return_key != 0x0619A548u)))))) && (((((return_key != 0x0619A658u && return_key != 0x0619A708u) && (return_key != 0x0619AB90u && (return_key != 0x0619AC00u && return_key != 0x0619ACC8u))) && ((return_key != 0x0619AD78u && (return_key != 0x0619AE28u && return_key != 0x0619AED8u)) && (return_key != 0x0619AFA0u && (return_key != 0x0619B050u && return_key != 0x0619B348u)))) && (((return_key != 0x0619C228u && (return_key != 0x0619C330u && return_key != 0x0619CC18u)) && (return_key != 0x0619CCF0u && (return_key != 0x0619CEE0u && return_key != 0x0619D7A0u))) && ((return_key != 0x0619D828u && (return_key != 0x0619DDB0u && return_key != 0x0619E020u)) && (return_key != 0x0619E548u && (return_key != 0x0619E958u && return_key != 0x0619F198u))))) && ((((return_key != 0x0619F250u && (return_key != 0x061A1DC0u && return_key != 0x061A1EC8u)) && (return_key != 0x061A2428u && (return_key != 0x061A2530u && return_key != 0x061A2858u))) && ((return_key != 0x061A28D8u && (return_key != 0x061A2998u && return_key != 0x061A2B28u)) && (return_key != 0x061A2C30u && (return_key != 0x061A2F00u && return_key != 0x061A2F80u)))) && (((return_key != 0x061A3030u && (return_key != 0x061A31A0u && return_key != 0x061A32A8u)) && (return_key != 0x061A3538u && (return_key != 0x061A35B8u && return_key != 0x061A3678u))) && ((return_key != 0x061A3848u && (return_key != 0x061A3950u && return_key != 0x061A3CE8u)) && (return_key != 0x061A3DF0u && (return_key != 0x061A7FB8u && return_key != 0x061A8B90u))))))))) && ((((((((return_key != 0x061A8D10u && return_key != 0x061A8FA8u) && (return_key != 0x061A9128u && (return_key != 0x061A94C8u && return_key != 0x061A9548u))) && ((return_key != 0x061A9850u && (return_key != 0x061A99D0u && return_key != 0x061A9EF8u)) && (return_key != 0x061A9F78u && (return_key != 0x061AA3D8u && return_key != 0x061AA538u)))) && (((return_key != 0x061AA780u && (return_key != 0x061AA848u && return_key != 0x061AA8C8u)) && (return_key != 0x061AADC8u && (return_key != 0x061AAE80u && return_key != 0x061AAFE8u))) && ((return_key != 0x061AB068u && (return_key != 0x061AB748u && return_key != 0x061AB7C8u)) && (return_key != 0x061AC030u && (return_key != 0x061AC190u && return_key != 0x061AC6E0u))))) && ((((return_key != 0x061AC7C8u && return_key != 0x061AC8A0u) && (return_key != 0x061AC920u && (return_key != 0x061AD060u && return_key != 0x061AD128u))) && ((return_key != 0x061AD1F0u && (return_key != 0x061AF6F0u && return_key != 0x061AF788u)) && (return_key != 0x061AF868u && (return_key != 0x061AF930u && return_key != 0x061B0190u)))) && (((return_key != 0x061B0258u && (return_key != 0x061B0338u && return_key != 0x061B03D0u)) && (return_key != 0x061B0870u && (return_key != 0x061B0958u && return_key != 0x061B0E60u))) && ((return_key != 0x061B0F28u && (return_key != 0x061B1010u && return_key != 0x061B10C8u)) && (return_key != 0x061B1350u && (return_key != 0x061B13D0u && return_key != 0x061B30A8u)))))) && (((((return_key != 0x061B31C0u && return_key != 0x061B3220u) && (return_key != 0x061B4118u && (return_key != 0x061B41B8u && return_key != 0x061B56C8u))) && ((return_key != 0x061B5808u && (return_key != 0x061B58D0u && return_key != 0x061B5B80u)) && (return_key != 0x061B5BF8u && (return_key != 0x061B6188u && return_key != 0x061B7A10u)))) && (((return_key != 0x061B7B20u && (return_key != 0x061B7BC0u && return_key != 0x061B7C68u)) && (return_key != 0x061B7D88u && (return_key != 0x061B7DE8u && return_key != 0x061B8048u))) && ((return_key != 0x061B8108u && (return_key != 0x061B83E0u && return_key != 0x061B8490u)) && (return_key != 0x061B9560u && (return_key != 0x061B95E8u && return_key != 0x061B96E8u))))) && ((((return_key != 0x061B9770u && (return_key != 0x061B9DE8u && return_key != 0x061B9E68u)) && (return_key != 0x061BA1F0u && (return_key != 0x061BA4D8u && return_key != 0x061BA598u))) && ((return_key != 0x061BB340u && (return_key != 0x061BB5E8u && return_key != 0x061BF5B8u)) && (return_key != 0x061BF638u && (return_key != 0x061BF808u && return_key != 0x061BF890u)))) && (((return_key != 0x061C3CB0u && (return_key != 0x061C3D38u && return_key != 0x061CD160u)) && (return_key != 0x061CD278u && (return_key != 0x061CD430u && return_key != 0x061CD4A0u))) && ((return_key != 0x061CD5C0u && (return_key != 0x061CD620u && return_key != 0x061CD920u)) && (return_key != 0x061CD9A8u && (return_key != 0x061CDA30u && return_key != 0x061CDAB8u))))))) && ((((((return_key != 0x061CDB58u && return_key != 0x061CDD30u) && (return_key != 0x061CDDB0u && (return_key != 0x061CE7D8u && return_key != 0x061CE9A0u))) && ((return_key != 0x061D1080u && (return_key != 0x061D10E0u && return_key != 0x061D11C8u)) && (return_key != 0x061D1228u && (return_key != 0x061D32A0u && return_key != 0x061D3350u)))) && (((return_key != 0x061D33B0u && (return_key != 0x061D35F0u && return_key != 0x061D36C8u)) && (return_key != 0x061D4BF0u && (return_key != 0x061D4C70u && return_key != 0x061D5220u))) && ((return_key != 0x061D5310u && (return_key != 0x061D69B0u && return_key != 0x061D6A48u)) && (return_key != 0x061D6B38u && (return_key != 0x061D82C8u && return_key != 0x061D8C30u))))) && ((((return_key != 0x061D9EB0u && (return_key != 0x061DA460u && return_key != 0x061DA4E0u)) && (return_key != 0x061DC688u && (return_key != 0x061DDB78u && return_key != 0x061DF448u))) && ((return_key != 0x061E0188u && (return_key != 0x061E0AD8u && return_key != 0x061E0BB0u)) && (return_key != 0x061E0D48u && (return_key != 0x061E0DE8u && return_key != 0x061E12E8u)))) && (((return_key != 0x061E13D0u && (return_key != 0x061E2F90u && return_key != 0x061E3190u)) && (return_key != 0x061E3368u && (return_key != 0x061E35B8u && return_key != 0x061E39E8u))) && ((return_key != 0x061E3AA0u && (return_key != 0x061E3DC8u && return_key != 0x061E3E80u)) && (return_key != 0x061E4C30u && (return_key != 0x061E4CE8u && return_key != 0x062015C8u)))))) && (((((return_key != 0x062017A0u && return_key != 0x06202F08u) && (return_key != 0x06203058u && (return_key != 0x062031C0u && return_key != 0x062033E0u))) && ((return_key != 0x06203550u && (return_key != 0x06203608u && return_key != 0x062036C0u)) && (return_key != 0x06203F30u && (return_key != 0x06204098u && return_key != 0x062044B8u)))) && (((return_key != 0x062048A8u && (return_key != 0x06204A10u && return_key != 0x06207998u)) && (return_key != 0x062079F8u && (return_key != 0x06207C70u && return_key != 0x06209978u))) && ((return_key != 0x06209A38u && (return_key != 0x06209A98u && return_key != 0x06209D10u)) && (return_key != 0x0620DA88u && (return_key != 0x06210660u && return_key != 0x062106F0u))))) && ((((return_key != 0x06210F38u && (return_key != 0x06211068u && return_key != 0x06211180u)) && (return_key != 0x06211288u && (return_key != 0x06211310u && return_key != 0x062118F8u))) && ((return_key != 0x06211A28u && (return_key != 0x06211B40u && return_key != 0x06211C48u)) && (return_key != 0x06211CD0u && (return_key != 0x06215F20u && return_key != 0x06216218u)))) && (((return_key != 0x06216E20u && (return_key != 0x06216EC0u && return_key != 0x06216F60u)) && (return_key != 0x06217000u && (return_key != 0x062176C0u && return_key != 0x06217830u))) && ((return_key != 0x06218D88u && (return_key != 0x06218EF8u && return_key != 0x062197A0u)) && (return_key != 0x06219A98u && (return_key != 0x06219B98u && return_key != 0x06219CC0u)))))))) && (((((((return_key != 0x0621A1D0u && return_key != 0x0621A340u) && (return_key != 0x0621E4E8u && (return_key != 0x0621E570u && return_key != 0x06222CB8u))) && ((return_key != 0x06222D40u && (return_key != 0x06224B60u && return_key != 0x06224C28u)) && (return_key != 0x06224CF0u && (return_key != 0x06224F58u && return_key != 0x06225020u)))) && (((return_key != 0x06228208u && (return_key != 0x062282E8u && return_key != 0x06228600u)) && (return_key != 0x062286E0u && (return_key != 0x0622A0E0u && return_key != 0x0622A230u))) && ((return_key != 0x0622A398u && (return_key != 0x0622A5B8u && return_key != 0x0622A728u)) && (return_key != 0x0622A7E0u && (return_key != 0x0622A898u && return_key != 0x0622B0D8u))))) && ((((return_key != 0x0622B240u && return_key != 0x0622B730u) && (return_key != 0x0622B7E0u && (return_key != 0x0622BA38u && return_key != 0x0622BBA0u))) && ((return_key != 0x0622BFB0u && (return_key != 0x0622D8B8u && return_key != 0x0622D948u)) && (return_key != 0x062310A0u && (return_key != 0x06231100u && return_key != 0x06231300u)))) && (((return_key != 0x06231360u && (return_key != 0x0623AD78u && return_key != 0x0623ADD8u)) && (return_key != 0x0623B448u && (return_key != 0x0623B588u && return_key != 0x0623B9E0u))) && ((return_key != 0x0623BB20u && (return_key != 0x0623E550u && return_key != 0x0623E5D8u)) && (return_key != 0x0623FD00u && (return_key != 0x0623FD88u && return_key != 0x0623FE10u)))))) && (((((return_key != 0x062423C0u && return_key != 0x06242508u) && (return_key != 0x06285D90u && (return_key != 0x06286728u && return_key != 0x062867B8u))) && ((return_key != 0x0628AAB8u && (return_key != 0x0628AB90u && return_key != 0x062929C8u)) && (return_key != 0x06294E48u && (return_key != 0x06294F10u && return_key != 0x06294FD8u)))) && (((return_key != 0x0629B8F8u && (return_key != 0x062AF238u && return_key != 0x062AF2B8u)) && (return_key != 0x062AF398u && (return_key != 0x062AF7C8u && return_key != 0x062AF850u))) && ((return_key != 0x062AF940u && (return_key != 0x062AF9C8u && return_key != 0x062AFAB0u)) && (return_key != 0x062AFB38u && (return_key != 0x062B1F60u && return_key != 0x062B2018u))))) && ((((return_key != 0x062B5D08u && (return_key != 0x062B5D90u && return_key != 0x062B74B8u)) && (return_key != 0x062B7528u && (return_key != 0x062B75B0u && return_key != 0x062BE3D0u))) && ((return_key != 0x062C7D20u && (return_key != 0x062C7E80u && return_key != 0x062C8370u)) && (return_key != 0x062C83D0u && (return_key != 0x062C8A90u && return_key != 0x062C8B00u)))) && (((return_key != 0x062C9380u && (return_key != 0x062C94F0u && return_key != 0x062CA078u)) && (return_key != 0x062CA0D8u && (return_key != 0x062CA730u && return_key != 0x062CA8B0u))) && ((return_key != 0x062CAA90u && (return_key != 0x062CAAF0u && return_key != 0x062CD928u)) && (return_key != 0x062CD9F0u && (return_key != 0x062CDAC8u && return_key != 0x062CDD00u))))))) && ((((((return_key != 0x062CDDC0u && return_key != 0x062CE610u) && (return_key != 0x062CE6D0u && (return_key != 0x062CE798u && return_key != 0x062CFEF8u))) && ((return_key != 0x062D35B8u && (return_key != 0x062D3670u && return_key != 0x062D4CB8u)) && (return_key != 0x062D4D50u && (return_key != 0x062D4E10u && return_key != 0x062D85B0u)))) && (((return_key != 0x062D8610u && (return_key != 0x062D9768u && return_key != 0x062D9BA8u)) && (return_key != 0x062DB0E0u && (return_key != 0x062DB1D0u && return_key != 0x06300098u))) && ((return_key != 0x063001C8u && (return_key != 0x06300640u && return_key != 0x063006E0u)) && (return_key != 0x06300780u && (return_key != 0x06300820u && return_key != 0x063008C0u))))) && ((((return_key != 0x06300960u && (return_key != 0x06300A00u && return_key != 0x06300AA0u)) && (return_key != 0x06300B40u && (return_key != 0x06300BE0u && return_key != 0x06303088u))) && ((return_key != 0x06303128u && (return_key != 0x06304318u && return_key != 0x063043E8u)) && (return_key != 0x063044A0u && (return_key != 0x06304558u && return_key != 0x06304610u)))) && (((return_key != 0x063046D0u && (return_key != 0x06304788u && return_key != 0x06304828u)) && (return_key != 0x06304CF0u && (return_key != 0x06305218u && return_key != 0x063090E0u))) && ((return_key != 0x06309140u && (return_key != 0x0630EA08u && return_key != 0x0630EAC0u)) && (return_key != 0x0630EB78u && (return_key != 0x06312790u && return_key != 0x063127F0u)))))) && (((((return_key != 0x06316CA0u && return_key != 0x06316D10u) && (return_key != 0x063251F0u && (return_key != 0x063252A0u && return_key != 0x063280E8u))) && ((return_key != 0x063281F8u && (return_key != 0x063283D0u && return_key != 0x06328458u)) && (return_key != 0x063284B8u && (return_key != 0x06328568u && return_key != 0x06328B80u)))) && (((return_key != 0x0632A5D0u && (return_key != 0x0632A680u && return_key != 0x06331148u)) && (return_key != 0x06332D48u && (return_key != 0x06332E40u && return_key != 0x06332F20u))) && ((return_key != 0x06332FF0u && (return_key != 0x06333F70u && return_key != 0x06334058u)) && (return_key != 0x06334140u && (return_key != 0x063342B0u && return_key != 0x06334388u))))) && ((((return_key != 0x06334470u && (return_key != 0x063344D0u && return_key != 0x063348D0u)) && (return_key != 0x06334A18u && (return_key != 0x06334B10u && return_key != 0x06334C30u))) && ((return_key != 0x06335D08u && (return_key != 0x06335DF0u && return_key != 0x06335ED8u)) && (return_key != 0x06336048u && (return_key != 0x06336120u && return_key != 0x063363C0u)))) && (((return_key != 0x063368E8u && (return_key != 0x06336AD8u && return_key != 0x06337010u)) && (return_key != 0x06337070u && (return_key != 0x06338B50u && return_key != 0x06338BD8u))) && ((return_key != 0x0633BA20u && (return_key != 0x0633E438u && return_key != 0x0633E498u)) && (return_key != 0x0633E4F8u && (return_key != 0x0633E7B8u && return_key != 0x0633E838u)))))))))) && (((((((((return_key != 0x0633F150u && return_key != 0x0633F1B0u) && (return_key != 0x0633F620u && (return_key != 0x0633F6A0u && return_key != 0x06342D68u))) && ((return_key != 0x06344838u && (return_key != 0x06344928u && return_key != 0x06344F38u)) && (return_key != 0x06345068u && (return_key != 0x06345158u && return_key != 0x063467B8u)))) && (((return_key != 0x06346D20u && (return_key != 0x06347D08u && return_key != 0x06347D78u)) && (return_key != 0x06348F78u && (return_key != 0x06349010u && return_key != 0x0634A588u))) && ((return_key != 0x0634A640u && (return_key != 0x0634A7D8u && return_key != 0x06350EA8u)) && (return_key != 0x06351078u && (return_key != 0x06354010u && return_key != 0x063565E0u))))) && ((((return_key != 0x0635DA50u && return_key != 0x0635F0A0u) && (return_key != 0x0635F530u && (return_key != 0x06360348u && return_key != 0x06361848u))) && ((return_key != 0x06362FC8u && (return_key != 0x063630E8u && return_key != 0x06363300u)) && (return_key != 0x063633C8u && (return_key != 0x06380BF8u && return_key != 0x06380CE8u)))) && (((return_key != 0x063810E0u && (return_key != 0x063811D0u && return_key != 0x06382F78u)) && (return_key != 0x06383040u && (return_key != 0x06383130u && return_key != 0x06383228u))) && ((return_key != 0x06383588u && (return_key != 0x06383608u && return_key != 0x063836A0u)) && (return_key != 0x06384C80u && (return_key != 0x06384D48u && return_key != 0x06384E20u)))))) && (((((return_key != 0x06384ED8u && return_key != 0x06384FC8u) && (return_key != 0x06385080u && (return_key != 0x063854F0u && return_key != 0x063855B8u))) && ((return_key != 0x06385690u && (return_key != 0x06385748u && return_key != 0x06385808u)) && (return_key != 0x063858C8u && (return_key != 0x06385980u && return_key != 0x063862E8u)))) && (((return_key != 0x063863B0u && (return_key != 0x06387708u && return_key != 0x06387790u)) && (return_key != 0x063880B8u && (return_key != 0x06388130u && return_key != 0x063883B8u))) && ((return_key != 0x06388CC8u && (return_key != 0x06388D28u && return_key != 0x06389D90u)) && (return_key != 0x0638B4D8u && (return_key != 0x0638B568u && return_key != 0x0638E9F8u))))) && ((((return_key != 0x0638EAF8u && (return_key != 0x06393208u && return_key != 0x06393BB8u)) && (return_key != 0x06393C18u && (return_key != 0x06395D98u && return_key != 0x06395E80u))) && ((return_key != 0x06399C10u && (return_key != 0x06399E50u && return_key != 0x06399ED8u)) && (return_key != 0x0639B480u && (return_key != 0x0639B500u && return_key != 0x0639D508u)))) && (((return_key != 0x0639D690u && (return_key != 0x063A5EA0u && return_key != 0x063A8450u)) && (return_key != 0x063ABA40u && (return_key != 0x063ABB20u && return_key != 0x063AC248u))) && ((return_key != 0x063AC2B8u && (return_key != 0x063ACCA0u && return_key != 0x063ACD40u)) && (return_key != 0x063AE7D8u && (return_key != 0x063B12F0u && return_key != 0x063B15F8u))))))) && ((((((return_key != 0x063B1658u && return_key != 0x063B1E58u) && (return_key != 0x063B25C8u && (return_key != 0x063B39C8u && return_key != 0x063B3A28u))) && ((return_key != 0x063B4438u && (return_key != 0x063B4570u && return_key != 0x063B5C28u)) && (return_key != 0x063B5CC0u && (return_key != 0x063B6198u && return_key != 0x063B6230u)))) && (((return_key != 0x063B62C8u && (return_key != 0x063B6360u && return_key != 0x063B8818u)) && (return_key != 0x063B88D8u && (return_key != 0x063B8CD0u && return_key != 0x063B8D88u))) && ((return_key != 0x063B8E40u && (return_key != 0x063BA058u && return_key != 0x063BA0B8u)) && (return_key != 0x063BD208u && (return_key != 0x063BDFB0u && return_key != 0x063BE080u))))) && ((((return_key != 0x063BE0F0u && (return_key != 0x063BE280u && return_key != 0x063BE350u)) && (return_key != 0x063BE3E8u && (return_key != 0x063BF3B8u && return_key != 0x063BF488u))) && ((return_key != 0x063BF638u && (return_key != 0x063BF708u && return_key != 0x063BF7A0u)) && (return_key != 0x063BFCF8u && (return_key != 0x063BFDC0u && return_key != 0x063C09A8u)))) && (((return_key != 0x063C0A08u && (return_key != 0x063C0B18u && return_key != 0x063C1A30u)) && (return_key != 0x063C1B00u && (return_key != 0x063C1C98u && return_key != 0x063C1D68u))) && ((return_key != 0x063C1E00u && (return_key != 0x063C3270u && return_key != 0x063C3308u)) && (return_key != 0x063C4208u && (return_key != 0x063C42D0u && return_key != 0x063CA170u)))))) && (((((return_key != 0x063CA4C0u && return_key != 0x063CA558u) && (return_key != 0x063CBD58u && (return_key != 0x063CBDF0u && return_key != 0x063CC848u))) && ((return_key != 0x063CCEE8u && (return_key != 0x063CCF80u && return_key != 0x063CD288u)) && (return_key != 0x063CD488u && (return_key != 0x063CE4B8u && return_key != 0x063CE540u)))) && (((return_key != 0x063D01F0u && (return_key != 0x063D0698u && return_key != 0x063D0760u)) && (return_key != 0x063D0828u && (return_key != 0x063D0B40u && return_key != 0x063D0C08u))) && ((return_key != 0x063D0CD0u && (return_key != 0x063D0EC8u && return_key != 0x063D0FC0u)) && (return_key != 0x063D1458u && (return_key != 0x063D1518u && return_key != 0x063D1A98u))))) && ((((return_key != 0x063D1AF8u && (return_key != 0x063D1EE0u && return_key != 0x063D1F50u)) && (return_key != 0x063D36F0u && (return_key != 0x063D3788u && return_key != 0x063D5D38u))) && ((return_key != 0x063D5F50u && (return_key != 0x063D6068u && return_key != 0x063D7A08u)) && (return_key != 0x063D7A78u && (return_key != 0x063D8D60u && return_key != 0x063D91F0u)))) && (((return_key != 0x063D9260u && (return_key != 0x063D9F30u && return_key != 0x063D9FA0u)) && (return_key != 0x063DA2B0u && (return_key != 0x063DB6A8u && return_key != 0x063DB718u))) && ((return_key != 0x063DC6A8u && (return_key != 0x063DC718u && return_key != 0x063DCBA0u)) && (return_key != 0x063DCF08u && (return_key != 0x063DCF78u && return_key != 0x063DD988u)))))))) && (((((((return_key != 0x063DDA50u && return_key != 0x063E78F8u) && (return_key != 0x063EAF88u && (return_key != 0x063EB008u && return_key != 0x063EC180u))) && ((return_key != 0x063EC1F0u && (return_key != 0x063EFB68u && return_key != 0x063EFC08u)) && (return_key != 0x063EFCA8u && (return_key != 0x063F0F58u && return_key != 0x063F1C68u)))) && (((return_key != 0x063F1DA0u && (return_key != 0x063F86E0u && return_key != 0x063F8828u)) && (return_key != 0x063F8EC0u && (return_key != 0x063F9008u && return_key != 0x063FADA0u))) && ((return_key != 0x063FAE30u && (return_key != 0x063FAEE0u && return_key != 0x063FB038u)) && (return_key != 0x063FB710u && (return_key != 0x063FB7D0u && return_key != 0x06406BB8u))))) && ((((return_key != 0x06406F60u && return_key != 0x064079D0u) && (return_key != 0x0640B2B8u && (return_key != 0x0640B3A8u && return_key != 0x0640B950u))) && ((return_key != 0x0640BA40u && (return_key != 0x0640EDF0u && return_key != 0x06410C48u)) && (return_key != 0x0641C248u && (return_key != 0x0641C2B8u && return_key != 0x0641D6D8u)))) && (((return_key != 0x0641E320u && (return_key != 0x06420838u && return_key != 0x064208E8u)) && (return_key != 0x06420DB8u && (return_key != 0x06420E68u && return_key != 0x064213B0u))) && ((return_key != 0x06421428u && (return_key != 0x064214D8u && return_key != 0x06421EE0u)) && (return_key != 0x06421F90u && (return_key != 0x06422040u && return_key != 0x064223B0u)))))) && (((((return_key != 0x06422460u && return_key != 0x06423210u) && (return_key != 0x06423270u && (return_key != 0x06423930u && return_key != 0x06423990u))) && ((return_key != 0x06424B48u && (return_key != 0x06424C08u && return_key != 0x06425018u)) && (return_key != 0x06425140u && (return_key != 0x06425218u && return_key != 0x064252B0u)))) && (((return_key != 0x06425738u && (return_key != 0x06425A28u && return_key != 0x06427B18u)) && (return_key != 0x06427BA0u && (return_key != 0x0642ADE8u && return_key != 0x0642AE88u))) && ((return_key != 0x0642C680u && (return_key != 0x0642C6E0u && return_key != 0x0642CAC0u)) && (return_key != 0x0642CB30u && (return_key != 0x0642CFC0u && return_key != 0x0642D070u))))) && ((((return_key != 0x0642E750u && (return_key != 0x0642E818u && return_key != 0x0642E8E0u)) && (return_key != 0x0642F688u && (return_key != 0x0642F6F8u && return_key != 0x064308C0u))) && ((return_key != 0x06430988u && (return_key != 0x06430A50u && return_key != 0x06432B70u)) && (return_key != 0x06432C38u && (return_key != 0x06433E60u && return_key != 0x06433EE8u)))) && (((return_key != 0x06434538u && (return_key != 0x064345A8u && return_key != 0x064398A8u)) && (return_key != 0x06439918u && (return_key != 0x06485AA8u && return_key != 0x06485B98u))) && ((return_key != 0x06485C80u && (return_key != 0x06485F00u && return_key != 0x06486120u)) && (return_key != 0x064864C0u && (return_key != 0x06486600u && return_key != 0x06486B10u))))))) && ((((((return_key != 0x06488C90u && return_key != 0x06488D58u) && (return_key != 0x0648B830u && (return_key != 0x0648B998u && return_key != 0x0648C6E8u))) && ((return_key != 0x0648C850u && (return_key != 0x0648D5C8u && return_key != 0x0648E8B0u)) && (return_key != 0x0648EA90u && (return_key != 0x06490460u && return_key != 0x06490528u)))) && (((return_key != 0x064905F0u && (return_key != 0x064906A8u && return_key != 0x06490D00u)) && (return_key != 0x06490EB8u && (return_key != 0x06492EC8u && return_key != 0x06492F80u))) && ((return_key != 0x06495178u && (return_key != 0x06495240u && return_key != 0x064952F8u)) && (return_key != 0x064957C0u && (return_key != 0x06496900u && return_key != 0x06497AA0u))))) && ((((return_key != 0x06498320u && (return_key != 0x064987A8u && return_key != 0x06498818u)) && (return_key != 0x06499208u && (return_key != 0x06499278u && return_key != 0x06499B58u))) && ((return_key != 0x06499CF0u && (return_key != 0x0649CCE0u && return_key != 0x0649CE00u)) && (return_key != 0x0649D180u && (return_key != 0x0649D4D0u && return_key != 0x0649DEA0u)))) && (((return_key != 0x0649DF30u && (return_key != 0x0649E0F8u && return_key != 0x0649E2E8u)) && (return_key != 0x0649E668u && (return_key != 0x0649E6C8u && return_key != 0x0649E818u))) && ((return_key != 0x0649E878u && (return_key != 0x0649E8D8u && return_key != 0x0649F0E0u)) && (return_key != 0x0649F168u && (return_key != 0x064A1860u && return_key != 0x064A18E8u)))))) && (((((return_key != 0x064A3388u && return_key != 0x064A3460u) && (return_key != 0x064A3978u && (return_key != 0x064A3A50u && return_key != 0x064A4480u))) && ((return_key != 0x064A4558u && (return_key != 0x064A54E0u && return_key != 0x064A55B8u)) && (return_key != 0x064A5F58u && (return_key != 0x064A5FF0u && return_key != 0x064A6BF8u)))) && (((return_key != 0x064A6E40u && (return_key != 0x064A7C78u && return_key != 0x064AEBF0u)) && (return_key != 0x064AEC88u && (return_key != 0x064AFC10u && return_key != 0x064AFCD8u))) && ((return_key != 0x064B0178u && (return_key != 0x064B0240u && return_key != 0x064B07E0u)) && (return_key != 0x064B08A8u && (return_key != 0x064B10F0u && return_key != 0x064B11B8u))))) && ((((return_key != 0x064B2638u && (return_key != 0x064B2740u && return_key != 0x064B7158u)) && (return_key != 0x064B7270u && (return_key != 0x064B72D0u && return_key != 0x064B7BA8u))) && ((return_key != 0x064B7C48u && (return_key != 0x064B7DD8u && return_key != 0x064B7E60u)) && (return_key != 0x064B8278u && (return_key != 0x064B8658u && return_key != 0x064B8718u)))) && (((return_key != 0x064B87B8u && (return_key != 0x064B9B08u && return_key != 0x064B9C28u)) && (return_key != 0x064BDC90u && (return_key != 0x064BDD28u && return_key != 0x064BDDD0u))) && ((return_key != 0x064BDEF8u && (return_key != 0x064BDFB8u && return_key != 0x064BE6F0u)) && (return_key != 0x064BE7B0u && (return_key != 0x064C15D0u && return_key != 0x064C1670u))))))))) && ((((((((return_key != 0x064C6298u && return_key != 0x064C6388u) && (return_key != 0x064C7630u && (return_key != 0x064C7720u && return_key != 0x064CAAC8u))) && ((return_key != 0x064CF860u && (return_key != 0x064CF918u && return_key != 0x064CF9D0u)) && (return_key != 0x064CFA88u && (return_key != 0x064D1668u && return_key != 0x064D1708u)))) && (((return_key != 0x064D1848u && (return_key != 0x064D18E8u && return_key != 0x064D1960u)) && (return_key != 0x064D1A00u && (return_key != 0x064D1A78u && return_key != 0x064D1B18u))) && ((return_key != 0x064D3888u && (return_key != 0x064D3900u && return_key != 0x064D39A0u)) && (return_key != 0x064D4D90u && (return_key != 0x064D4E30u && return_key != 0x064D4ED0u))))) && ((((return_key != 0x064D5D30u && return_key != 0x064D5DD0u) && (return_key != 0x064D5F10u && (return_key != 0x064D6450u && return_key != 0x064D67F0u))) && ((return_key != 0x064DD030u && (return_key != 0x064DD170u && return_key != 0x064DD220u)) && (return_key != 0x064DD2C0u && (return_key != 0x064DDD10u && return_key != 0x064DDDD0u)))) && (((return_key != 0x064DE418u && (return_key != 0x064DE528u && return_key != 0x064DE5A8u)) && (return_key != 0x064DE630u && (return_key != 0x064DED88u && return_key != 0x064DEE30u))) && ((return_key != 0x064E11B8u && (return_key != 0x064E1218u && return_key != 0x064E1350u)) && (return_key != 0x064E3028u && (return_key != 0x064E3120u && return_key != 0x064E3218u)))))) && (((((return_key != 0x064E4668u && return_key != 0x064E46D8u) && (return_key != 0x064E9FD0u && (return_key != 0x064EA040u && return_key != 0x064F18D0u))) && ((return_key != 0x064F19E0u && (return_key != 0x064F23D8u && return_key != 0x064F24A0u)) && (return_key != 0x064F2908u && (return_key != 0x064F29D0u && return_key != 0x065005E0u)))) && (((return_key != 0x06501B48u && (return_key != 0x06504778u && return_key != 0x06504800u)) && (return_key != 0x065059C8u && (return_key != 0x06505B50u && return_key != 0x06506178u))) && ((return_key != 0x06506258u && (return_key != 0x065062E8u && return_key != 0x065063C8u)) && (return_key != 0x065064B8u && (return_key != 0x06506598u && return_key != 0x06506628u))))) && ((((return_key != 0x06506708u && (return_key != 0x06507E70u && return_key != 0x06507FE8u)) && (return_key != 0x0650A140u && (return_key != 0x0650A1F0u && return_key != 0x0650A288u))) && ((return_key != 0x0650A958u && (return_key != 0x0650AA08u && return_key != 0x0650AAA0u)) && (return_key != 0x0650B1F0u && (return_key != 0x0650BA78u && return_key != 0x0650BB28u)))) && (((return_key != 0x0650BBD8u && (return_key != 0x0650DD98u && return_key != 0x0650DE88u)) && (return_key != 0x0650DF90u && (return_key != 0x065110B0u && return_key != 0x06511650u))) && ((return_key != 0x06514310u && (return_key != 0x065143B0u && return_key != 0x065149F8u)) && (return_key != 0x06514BB0u && (return_key != 0x06515F18u && return_key != 0x06516050u))))))) && ((((((return_key != 0x06516718u && return_key != 0x06517DA8u) && (return_key != 0x06519778u && (return_key != 0x06519818u && return_key != 0x06519DE0u))) && ((return_key != 0x06519F98u && (return_key != 0x0651B198u && return_key != 0x0651B218u)) && (return_key != 0x0651B298u && (return_key != 0x0651B418u && return_key != 0x0651B590u)))) && (((return_key != 0x0651BCB8u && (return_key != 0x0651DA88u && return_key != 0x0651DB28u)) && (return_key != 0x0651E3B0u && (return_key != 0x0651E568u && return_key != 0x06520980u))) && ((return_key != 0x06520A60u && (return_key != 0x06520B78u && return_key != 0x06522528u)) && (return_key != 0x06523868u && (return_key != 0x065238F8u && return_key != 0x06523A18u))))) && ((((return_key != 0x06523BA0u && (return_key != 0x06523D80u && return_key != 0x06526130u)) && (return_key != 0x06526328u && (return_key != 0x06526430u && return_key != 0x065264D8u))) && ((return_key != 0x065265E0u && (return_key != 0x065284C0u && return_key != 0x065298E0u)) && (return_key != 0x0652A678u && (return_key != 0x0652A768u && return_key != 0x0652BBA0u)))) && (((return_key != 0x0652BC58u && (return_key != 0x06533068u && return_key != 0x06533108u)) && (return_key != 0x06534100u && (return_key != 0x06534160u && return_key != 0x065350A0u))) && ((return_key != 0x06535128u && (return_key != 0x06535228u && return_key != 0x065352B0u)) && (return_key != 0x06535D90u && (return_key != 0x06535E10u && return_key != 0x065361B8u)))))) && (((((return_key != 0x065364C0u && return_key != 0x065365A0u) && (return_key != 0x065379B8u && (return_key != 0x06537B60u && return_key != 0x06539168u))) && ((return_key != 0x0653A140u && (return_key != 0x0653A1E0u && return_key != 0x0653A298u)) && (return_key != 0x0653A370u && (return_key != 0x0653A590u && return_key != 0x0653A640u)))) && (((return_key != 0x0653A6F8u && (return_key != 0x0653A800u && return_key != 0x0653A968u)) && (return_key != 0x0653AA08u && (return_key != 0x0653AAC0u && return_key != 0x0653AC38u))) && ((return_key != 0x06542288u && (return_key != 0x06542E50u && return_key != 0x06543038u)) && (return_key != 0x06543B10u && (return_key != 0x06543BE8u && return_key != 0x06546438u))))) && ((((return_key != 0x065465C0u && (return_key != 0x06546660u && return_key != 0x06546700u)) && (return_key != 0x065475F8u && (return_key != 0x06547678u && return_key != 0x065497E8u))) && ((return_key != 0x06549848u && (return_key != 0x0654ACE0u && return_key != 0x0654CFB0u)) && (return_key != 0x0654E2F0u && (return_key != 0x0660C640u && return_key != 0x0660C6C0u)))) && (((return_key != 0x0660F850u && (return_key != 0x0660F8D0u && return_key != 0x066107F8u)) && (return_key != 0x066108E0u && (return_key != 0x06610E38u && return_key != 0x06610F60u))) && ((return_key != 0x06612090u && (return_key != 0x06612938u && return_key != 0x06612C88u)) && (return_key != 0x06613FB0u && (return_key != 0x06614070u && return_key != 0x066140E0u)))))))) && (((((((return_key != 0x066141A0u && return_key != 0x06615C50u) && (return_key != 0x066162B0u && (return_key != 0x06616370u && return_key != 0x066163E0u))) && ((return_key != 0x066164A0u && (return_key != 0x06616E90u && return_key != 0x066171C0u)) && (return_key != 0x06617378u && (return_key != 0x06617A68u && return_key != 0x06617C90u)))) && (((return_key != 0x06617E48u && (return_key != 0x06619728u && return_key != 0x066197E8u)) && (return_key != 0x06619E10u && (return_key != 0x0661B110u && return_key != 0x0661E5F8u))) && ((return_key != 0x0661E668u && (return_key != 0x06634BA8u && return_key != 0x06635290u)) && (return_key != 0x0665FA28u && (return_key != 0x0665FAE0u && return_key != 0x0665FC78u))))) && ((((return_key != 0x06684A10u && return_key != 0x0668A090u) && (return_key != 0x0668A130u && (return_key != 0x0668A1D0u && return_key != 0x0668A4F8u))) && ((return_key != 0x0668A598u && (return_key != 0x0668A638u && return_key != 0x0668A980u)) && (return_key != 0x0668AA20u && (return_key != 0x0668AAC0u && return_key != 0x0668ADE8u)))) && (((return_key != 0x0668AE88u && (return_key != 0x0668AF28u && return_key != 0x0668EE38u)) && (return_key != 0x0668EF40u && (return_key != 0x0668F740u && return_key != 0x0668FAA0u))) && ((return_key != 0x0668FC98u && (return_key != 0x0668FD48u && return_key != 0x0668FE10u)) && (return_key != 0x06690148u && (return_key != 0x066901E8u && return_key != 0x066902D8u)))))) && (((((return_key != 0x066903E0u && return_key != 0x06690CA8u) && (return_key != 0x06691610u && (return_key != 0x06691718u && return_key != 0x06691A48u))) && ((return_key != 0x06691F28u && (return_key != 0x06692588u && return_key != 0x06692690u)) && (return_key != 0x06692AE0u && (return_key != 0x06692F48u && return_key != 0x06693050u)))) && (((return_key != 0x066934A0u && (return_key != 0x06693910u && return_key != 0x066940D0u)) && (return_key != 0x066941D8u && (return_key != 0x066945F0u && return_key != 0x06695160u))) && ((return_key != 0x06695250u && (return_key != 0x06695358u && return_key != 0x066956B0u)) && (return_key != 0x06695820u && (return_key != 0x066958D0u && return_key != 0x06696998u))))) && ((((return_key != 0x06697038u && (return_key != 0x06697230u && return_key != 0x066972E0u)) && (return_key != 0x066973A8u && (return_key != 0x066979B0u && return_key != 0x06697BA8u))) && ((return_key != 0x06697C58u && (return_key != 0x06697D20u && return_key != 0x06698408u)) && (return_key != 0x06698600u && (return_key != 0x066986B0u && return_key != 0x06698778u)))) && (((return_key != 0x0669BB28u && (return_key != 0x0669BB88u && return_key != 0x066A9328u)) && (return_key != 0x066A93D8u && (return_key != 0x066A9F70u && return_key != 0x066AA010u))) && ((return_key != 0x066AAF18u && (return_key != 0x066AB308u && return_key != 0x066AB430u)) && (return_key != 0x066AB4D0u && (return_key != 0x066AC888u && return_key != 0x066AC9B0u))))))) && ((((((return_key != 0x066ACA20u && return_key != 0x066AD6E0u) && (return_key != 0x066AD740u && (return_key != 0x066AD7A0u && return_key != 0x066AD828u))) && ((return_key != 0x066ADE30u && (return_key != 0x066B00C0u && return_key != 0x066B0120u)) && (return_key != 0x066B01A8u && (return_key != 0x066B0208u && return_key != 0x066B1E98u)))) && (((return_key != 0x066B1EF8u && (return_key != 0x066B1F80u && return_key != 0x066B1FE0u)) && (return_key != 0x066B27B8u && (return_key != 0x066B2840u && return_key != 0x066B3CE0u))) && ((return_key != 0x066B3D68u && (return_key != 0x066B4630u && return_key != 0x066B46B8u)) && (return_key != 0x066B73B0u && (return_key != 0x066B7460u && return_key != 0x066B9A40u))))) && ((((return_key != 0x066B9AF0u && (return_key != 0x066B9D78u && return_key != 0x066B9EC0u)) && (return_key != 0x066BA3B0u && (return_key != 0x066BA4F8u && return_key != 0x066BB368u))) && ((return_key != 0x066BB3D8u && (return_key != 0x066BE950u && return_key != 0x066BEA10u)) && (return_key != 0x066BEBB0u && (return_key != 0x066BF4C8u && return_key != 0x066C02C0u)))) && (((return_key != 0x066C0320u && (return_key != 0x066C26D0u && return_key != 0x066C2CB8u)) && (return_key != 0x066C2D48u && (return_key != 0x066D3470u && return_key != 0x066D3868u))) && ((return_key != 0x066D73D8u && (return_key != 0x066DCB88u && return_key != 0x066DCC10u)) && (return_key != 0x066DEBD8u && (return_key != 0x066DEC60u && return_key != 0x066E0960u)))))) && (((((return_key != 0x066E0A08u && return_key != 0x066E1578u) && (return_key != 0x066E1600u && (return_key != 0x066E48C0u && return_key != 0x066E4940u))) && ((return_key != 0x06701C28u && (return_key != 0x06701CF0u && return_key != 0x06701DB8u)) && (return_key != 0x06702A38u && (return_key != 0x06702E70u && return_key != 0x067030E8u)))) && (((return_key != 0x06703198u && (return_key != 0x06703258u && return_key != 0x067036D8u)) && (return_key != 0x06703760u && (return_key != 0x06704A10u && return_key != 0x0670C198u))) && ((return_key != 0x0670C208u && (return_key != 0x0670E518u && return_key != 0x0670EF78u)) && (return_key != 0x06710E10u && (return_key != 0x06710E98u && return_key != 0x06711A88u))))) && ((((return_key != 0x06711AF8u && (return_key != 0x06711EA8u && return_key != 0x06711FD0u)) && (return_key != 0x06713648u && (return_key != 0x067136B8u && return_key != 0x06713A40u))) && ((return_key != 0x06714850u && (return_key != 0x06714E28u && return_key != 0x067159D8u)) && (return_key != 0x06715FD0u && (return_key != 0x067188F0u && return_key != 0x0671F5F0u)))) && (((return_key != 0x0671F6A0u && (return_key != 0x0671FB70u && return_key != 0x0671FC20u)) && (return_key != 0x06720168u && (return_key != 0x067201E0u && return_key != 0x06720290u))) && ((return_key != 0x06720E08u && (return_key != 0x06720E68u && return_key != 0x06723170u)) && (return_key != 0x067231D0u && (return_key != 0x067235B8u && return_key != 0x06723628u))))))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FEF90u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0xC2u, 0xFEu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDF2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFDu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xF5u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEC2u;
            if (nh_scpu_expect_next(cpu, 0x060FF610u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060FEFB0u: {
            static const uint8_t expected_epoch[] = { 0x10u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDF6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFDF9u;
                if (nh_scpu_expect_next(cpu, 0x060FEFC8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDF8u;
            if (nh_scpu_expect_next(cpu, 0x060FEFC0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FEFC0u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDF8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDF9u;
            if (nh_scpu_expect_next(cpu, 0x060FEFC8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FEFC8u: {
            static const uint8_t expected_epoch[] = { 0x98u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDF9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDFAu;
            if (nh_scpu_expect_next(cpu, 0x060FEFD0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FEFD0u: {
            static const uint8_t expected_epoch[] = { 0x50u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDFAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_V) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFDFFu;
                if (nh_scpu_expect_next(cpu, 0x060FEFF8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDFCu;
            if (nh_scpu_expect_next(cpu, 0x060FEFE0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FEFE0u: {
            static const uint8_t expected_epoch[] = { 0x49u, 0x01u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDFCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a ^ 0x0001u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFDFFu;
            if (nh_scpu_expect_next(cpu, 0x060FEFF8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FEFF8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FDFFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE01u;
            if (nh_scpu_expect_next(cpu, 0x060FF008u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        default: return NH_SCPU_NOT_MINE;
    }
}
