/* Generated direct New Horizons S-CPU authority; do not edit. */
#include "nh_v07_generated.h"

NHScpuExecResult nh_v07_shard_00C1FE(NHScpuState *cpu, const NHScpuBus *bus) {
    switch (nh_scpu_context_key(cpu)) {
        case 0x060FF008u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE01u,
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
            if ((((((((return_key != 0x0608EE80u && return_key != 0x06090AA8u) && (return_key != 0x06093720u && (return_key != 0x0609D4E8u && return_key != 0x0609D668u))) && ((return_key != 0x060B2E78u && return_key != 0x060D6248u) && (return_key != 0x060E2C00u && (return_key != 0x060E2E20u && return_key != 0x061197F8u)))) && (((return_key != 0x0612AC08u && return_key != 0x06131620u) && (return_key != 0x06131D60u && (return_key != 0x06132030u && return_key != 0x06133508u))) && ((return_key != 0x06142CA0u && (return_key != 0x06157B60u && return_key != 0x06157F40u)) && (return_key != 0x06180908u && (return_key != 0x0618B650u && return_key != 0x06197A80u))))) && ((((return_key != 0x061A6578u && return_key != 0x061A6B98u) && (return_key != 0x061A74A0u && (return_key != 0x061A7E08u && return_key != 0x061A8860u))) && ((return_key != 0x061A96D0u && (return_key != 0x061AA620u && return_key != 0x061B3DA0u)) && (return_key != 0x061B3FD8u && (return_key != 0x061B4D40u && return_key != 0x061B50A8u)))) && (((return_key != 0x061B6018u && return_key != 0x061C0180u) && (return_key != 0x061C0308u && (return_key != 0x061DAA48u && return_key != 0x061E1E70u))) && ((return_key != 0x061E1F68u && (return_key != 0x061E2300u && return_key != 0x061E27C8u)) && (return_key != 0x061E2C48u && (return_key != 0x061E2D40u && return_key != 0x06200490u)))))) && (((((return_key != 0x06201D40u && return_key != 0x06203BE0u) && (return_key != 0x06203CD8u && (return_key != 0x062056F8u && return_key != 0x06205838u))) && ((return_key != 0x0620DB38u && (return_key != 0x0620DDB8u && return_key != 0x06210DB8u)) && (return_key != 0x062114D8u && (return_key != 0x06211E98u && return_key != 0x06216B90u)))) && (((return_key != 0x06216D80u && return_key != 0x062280A0u) && (return_key != 0x0622AD58u && (return_key != 0x0622AE50u && return_key != 0x06238A50u))) && ((return_key != 0x06238C90u && (return_key != 0x06238F58u && return_key != 0x062395F0u)) && (return_key != 0x06239830u && (return_key != 0x06239AF8u && return_key != 0x06241758u))))) && ((((return_key != 0x062420F0u && return_key != 0x062A1330u) && (return_key != 0x062A6BB8u && (return_key != 0x062A6D10u && return_key != 0x062D53D0u))) && ((return_key != 0x062DD540u && (return_key != 0x062E0D20u && return_key != 0x063282A8u)) && (return_key != 0x06334558u && (return_key != 0x06336240u && return_key != 0x06336360u)))) && (((return_key != 0x06338448u && return_key != 0x063399C0u) && (return_key != 0x063466D0u && (return_key != 0x06348888u && return_key != 0x06348AC8u))) && ((return_key != 0x06348D90u && (return_key != 0x06353EC0u && return_key != 0x06393298u)) && (return_key != 0x063A16B8u && (return_key != 0x063A4620u && return_key != 0x063A5F58u))))))) && ((((((return_key != 0x063A6BE8u && return_key != 0x063A6D80u) && (return_key != 0x063B03D0u && (return_key != 0x063BABD0u && return_key != 0x063C4A88u))) && ((return_key != 0x063C51A8u && return_key != 0x063CD9D8u) && (return_key != 0x063CFC60u && (return_key != 0x063D00A8u && return_key != 0x063D3FD8u)))) && (((return_key != 0x063D8818u && return_key != 0x063DAB70u) && (return_key != 0x063DDE28u && (return_key != 0x063E4508u && return_key != 0x063F82F0u))) && ((return_key != 0x063FAF78u && (return_key != 0x06406CC8u && return_key != 0x06407070u)) && (return_key != 0x06421BF0u && (return_key != 0x064257F0u && return_key != 0x0642EA98u))))) && ((((return_key != 0x0642EC60u && return_key != 0x06438268u) && (return_key != 0x06439658u && (return_key != 0x064805B0u && return_key != 0x064853A8u))) && ((return_key != 0x0648B658u && (return_key != 0x0648C4E0u && return_key != 0x0648D398u)) && (return_key != 0x06490DF0u && (return_key != 0x06491EE0u && return_key != 0x06495098u)))) && (((return_key != 0x06495598u && return_key != 0x064A6238u) && (return_key != 0x064AC730u && (return_key != 0x064AE6B8u && return_key != 0x064AE7F8u))) && ((return_key != 0x064B3BA8u && (return_key != 0x064B3D60u && return_key != 0x064B3F00u)) && (return_key != 0x064B4018u && (return_key != 0x064B41C8u && return_key != 0x064B5128u)))))) && (((((return_key != 0x064B53D8u && return_key != 0x064B9110u) && (return_key != 0x064B9370u && (return_key != 0x064B98A0u && return_key != 0x064BA8C0u))) && ((return_key != 0x064BAC78u && (return_key != 0x064BC698u && return_key != 0x064BDBF0u)) && (return_key != 0x064BE628u && (return_key != 0x064D1BB8u && return_key != 0x064D5FB0u)))) && (((return_key != 0x064F0208u && return_key != 0x065038F0u) && (return_key != 0x065039E8u && (return_key != 0x06504390u && return_key != 0x06504488u))) && ((return_key != 0x0650FE48u && (return_key != 0x0650FF40u && return_key != 0x06523F30u)) && (return_key != 0x06529B18u && (return_key != 0x0652C018u && return_key != 0x06532D38u))))) && ((((return_key != 0x06532E30u && return_key != 0x06533940u) && (return_key != 0x06533C08u && (return_key != 0x06600400u && return_key != 0x06684478u))) && ((return_key != 0x06689FF0u && (return_key != 0x0668A458u && return_key != 0x0668A8E0u)) && (return_key != 0x0668AD48u && (return_key != 0x0668E428u && return_key != 0x0668EBB8u)))) && (((return_key != 0x0668ED48u && return_key != 0x066B9C80u) && (return_key != 0x066C2480u && (return_key != 0x066D0EC0u && return_key != 0x066D1380u))) && ((return_key != 0x066D33B8u && (return_key != 0x066D37B0u && return_key != 0x066D94B8u)) && (return_key != 0x06703830u && (return_key != 0x0670EDD8u && return_key != 0x06715D28u)))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FF010u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0xD4u, 0xFEu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE02u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFEu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x05u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFED4u;
            if (nh_scpu_expect_next(cpu, 0x060FF6A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060FF030u: {
            static const uint8_t expected_epoch[] = { 0x10u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE06u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFE09u;
                if (nh_scpu_expect_next(cpu, 0x060FF048u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE08u;
            if (nh_scpu_expect_next(cpu, 0x060FF040u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF040u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE08u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE09u;
            if (nh_scpu_expect_next(cpu, 0x060FF048u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF048u: {
            static const uint8_t expected_epoch[] = { 0x98u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE09u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE0Au;
            if (nh_scpu_expect_next(cpu, 0x060FF050u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF050u: {
            static const uint8_t expected_epoch[] = { 0x50u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE0Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_V) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFE0Fu;
                if (nh_scpu_expect_next(cpu, 0x060FF078u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE0Cu;
            if (nh_scpu_expect_next(cpu, 0x060FF060u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF060u: {
            static const uint8_t expected_epoch[] = { 0x49u, 0x01u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE0Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a ^ 0x0001u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE0Fu;
            if (nh_scpu_expect_next(cpu, 0x060FF078u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FF078u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE0Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE11u;
            if (nh_scpu_expect_next(cpu, 0x060FF088u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF088u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE11u,
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
            if (((((return_key != 0x0610F868u && return_key != 0x0632ABE0u) && (return_key != 0x06336D58u && (return_key != 0x0633C860u && return_key != 0x06345CE0u))) && ((return_key != 0x063B9BC0u && (return_key != 0x063D8BF0u && return_key != 0x063DAEC0u)) && (return_key != 0x063DAFF0u && (return_key != 0x063DBEA0u && return_key != 0x063DC188u)))) && (((return_key != 0x063EBA18u && (return_key != 0x0640DBB8u && return_key != 0x0640DD28u)) && (return_key != 0x0640DEF8u && (return_key != 0x06422E10u && return_key != 0x06437AC0u))) && ((return_key != 0x06480EB8u && (return_key != 0x06481038u && return_key != 0x064CB1A8u)) && (return_key != 0x067116A8u && (return_key != 0x067118A0u && return_key != 0x06720A88u))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FF090u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0xC2u, 0xFEu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE12u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFEu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x15u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEC2u;
            if (nh_scpu_expect_next(cpu, 0x060FF610u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060FF0B0u: {
            static const uint8_t expected_epoch[] = { 0xB0u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE16u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) != 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFE19u;
                if (nh_scpu_expect_next(cpu, 0x060FF0C8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE18u;
            if (nh_scpu_expect_next(cpu, 0x060FF0C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF0C0u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE18u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE19u;
            if (nh_scpu_expect_next(cpu, 0x060FF0C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF0C8u: {
            static const uint8_t expected_epoch[] = { 0x84u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE19u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->y) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->y >> 8)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE1Bu;
            if (nh_scpu_expect_next(cpu, 0x060FF0D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF0D8u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE1Bu,
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
            if (((((((return_key != 0x06098EE8u && (return_key != 0x060D9070u && return_key != 0x06113B60u)) && (return_key != 0x061190B8u && (return_key != 0x061262C0u && return_key != 0x06126C38u))) && ((return_key != 0x06140048u && (return_key != 0x06180A98u && return_key != 0x061AD510u)) && ((return_key != 0x061AE0A0u && return_key != 0x061AFBE0u) && (return_key != 0x061B2E60u && return_key != 0x061B38B0u)))) && (((return_key != 0x061B3A90u && (return_key != 0x061B9A20u && return_key != 0x061CC1A8u)) && (return_key != 0x061CC378u && (return_key != 0x061CC4D8u && return_key != 0x061CC5E0u))) && ((return_key != 0x061D3888u && (return_key != 0x061D3960u && return_key != 0x061D44A0u)) && ((return_key != 0x061D4638u && return_key != 0x06202CC0u) && (return_key != 0x06207A80u && return_key != 0x06207B90u))))) && ((((return_key != 0x06209B20u && (return_key != 0x06209C30u && return_key != 0x06238908u)) && (return_key != 0x06238E10u && (return_key != 0x062394A8u && return_key != 0x062399B0u))) && ((return_key != 0x0623C758u && (return_key != 0x062ABE50u && return_key != 0x062D56F0u)) && ((return_key != 0x0630B258u && return_key != 0x0630B618u) && (return_key != 0x06316430u && return_key != 0x06319948u)))) && (((return_key != 0x06328C78u && (return_key != 0x0633D3D0u && return_key != 0x0633D898u)) && ((return_key != 0x06341D48u && return_key != 0x06343618u) && (return_key != 0x06348740u && return_key != 0x06348C48u))) && ((return_key != 0x06386B10u && (return_key != 0x06387BB0u && return_key != 0x0638A388u)) && ((return_key != 0x0638AA10u && return_key != 0x06393018u) && (return_key != 0x06393188u && return_key != 0x063C33A0u)))))) && (((((return_key != 0x063EC2A0u && (return_key != 0x063EDEB0u && return_key != 0x063EE5B8u)) && (return_key != 0x063EE830u && (return_key != 0x063EEAA8u && return_key != 0x06404430u))) && ((return_key != 0x0641D808u && (return_key != 0x06420F30u && return_key != 0x06422CD0u)) && ((return_key != 0x06436CB0u && return_key != 0x06482D70u) && (return_key != 0x064832B0u && return_key != 0x06483458u)))) && (((return_key != 0x06483618u && (return_key != 0x0648AE18u && return_key != 0x064B6F10u)) && ((return_key != 0x064EDF18u && return_key != 0x06507C60u) && (return_key != 0x06507D58u && return_key != 0x06514C60u))) && ((return_key != 0x065184C8u && (return_key != 0x06518C80u && return_key != 0x0651A048u)) && ((return_key != 0x0651E618u && return_key != 0x065224A8u) && (return_key != 0x06522E70u && return_key != 0x06523238u))))) && ((((return_key != 0x065241A8u && (return_key != 0x06526800u && return_key != 0x06533AC0u)) && (return_key != 0x06535560u && (return_key != 0x06680658u && return_key != 0x06680BC0u))) && ((return_key != 0x06681450u && (return_key != 0x066819B8u && return_key != 0x066A3D00u)) && ((return_key != 0x066A5E20u && return_key != 0x066A6B08u) && (return_key != 0x066A78B0u && return_key != 0x066A7A10u)))) && (((return_key != 0x066A8C50u && (return_key != 0x066A8DB0u && return_key != 0x066B72C8u)) && ((return_key != 0x066BB5E8u && return_key != 0x066C2758u) && (return_key != 0x066C62B8u && return_key != 0x066CBC80u))) && ((return_key != 0x066D08C0u && (return_key != 0x066D21F8u && return_key != 0x066D25B0u)) && ((return_key != 0x066E1338u && return_key != 0x06713750u) && (return_key != 0x0671FCE8u && return_key != 0x06720868u))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FF130u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0xCBu, 0xFEu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE26u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFEu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x29u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFECBu;
            if (nh_scpu_expect_next(cpu, 0x060FF658u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060FF150u: {
            static const uint8_t expected_epoch[] = { 0x10u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE2Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFE2Du;
                if (nh_scpu_expect_next(cpu, 0x060FF168u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE2Cu;
            if (nh_scpu_expect_next(cpu, 0x060FF160u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF160u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE2Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE2Du;
            if (nh_scpu_expect_next(cpu, 0x060FF168u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF168u: {
            static const uint8_t expected_epoch[] = { 0x98u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE2Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE2Eu;
            if (nh_scpu_expect_next(cpu, 0x060FF170u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF170u: {
            static const uint8_t expected_epoch[] = { 0x50u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE2Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_V) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFE33u;
                if (nh_scpu_expect_next(cpu, 0x060FF198u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE30u;
            if (nh_scpu_expect_next(cpu, 0x060FF180u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF180u: {
            static const uint8_t expected_epoch[] = { 0x49u, 0x01u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE30u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a ^ 0x0001u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE33u;
            if (nh_scpu_expect_next(cpu, 0x060FF198u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FF198u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE33u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE35u;
            if (nh_scpu_expect_next(cpu, 0x060FF1A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF1A8u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE35u,
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
            if (((((((return_key != 0x06085418u && (return_key != 0x06091B98u && return_key != 0x06091C20u)) && ((return_key != 0x06091CA8u && return_key != 0x06091D30u) && (return_key != 0x060947D8u && return_key != 0x06094860u))) && ((return_key != 0x060948E8u && (return_key != 0x06094970u && return_key != 0x060E2AF0u)) && ((return_key != 0x060E2D10u && return_key != 0x06119898u) && (return_key != 0x06157E90u && return_key != 0x0618B298u)))) && (((return_key != 0x06198460u && (return_key != 0x061989E0u && return_key != 0x061A7EE0u)) && ((return_key != 0x061A89C8u && return_key != 0x061ABDE0u) && (return_key != 0x061B60D0u && return_key != 0x061BFE70u))) && ((return_key != 0x061BFFF8u && (return_key != 0x061DB730u && return_key != 0x061DBD30u)) && ((return_key != 0x061DE0A8u && return_key != 0x061DE1A0u) && (return_key != 0x06201DE0u && return_key != 0x06203260u))))) && ((((return_key != 0x06204338u && (return_key != 0x062057A8u && return_key != 0x062058E8u)) && ((return_key != 0x06211588u && return_key != 0x06211F48u) && (return_key != 0x0622A438u && return_key != 0x0622BE40u))) && ((return_key != 0x06242260u && (return_key != 0x0625A078u && return_key != 0x062BD7D8u)) && ((return_key != 0x062C87C8u && return_key != 0x062CF290u) && (return_key != 0x062CF318u && return_key != 0x062CF458u)))) && (((return_key != 0x062CF4E0u && (return_key != 0x062CF638u && return_key != 0x062CF6C0u)) && ((return_key != 0x062CF810u && return_key != 0x062CF898u) && (return_key != 0x062D5470u && return_key != 0x063032A0u))) && ((return_key != 0x06303340u && (return_key != 0x06328198u && return_key != 0x063311D0u)) && ((return_key != 0x06362B90u && return_key != 0x063A4F60u) && (return_key != 0x063A5028u && return_key != 0x063C0C00u)))))) && (((((return_key != 0x063DDEC8u && (return_key != 0x063DE3C8u && return_key != 0x063EF020u)) && ((return_key != 0x06407AB0u && return_key != 0x064383C0u) && (return_key != 0x064397B0u && return_key != 0x064806D0u))) && ((return_key != 0x0649E060u && (return_key != 0x064BEC90u && return_key != 0x064E64E0u)) && ((return_key != 0x064E68A8u && return_key != 0x064F5AD0u) && (return_key != 0x064F5B70u && return_key != 0x064F5CF0u)))) && (((return_key != 0x06505010u && (return_key != 0x065056A8u && return_key != 0x06505E78u)) && ((return_key != 0x06529E80u && return_key != 0x066001E0u) && (return_key != 0x0660C250u && return_key != 0x0660C460u))) && ((return_key != 0x06684178u && (return_key != 0x0668EA40u && return_key != 0x066997A0u)) && ((return_key != 0x06699828u && return_key != 0x06699D08u) && (return_key != 0x06699D90u && return_key != 0x0669A320u))))) && ((((return_key != 0x0669A3A8u && (return_key != 0x0669A938u && return_key != 0x0669A9C0u)) && ((return_key != 0x0669AE50u && return_key != 0x0669AEE8u) && (return_key != 0x0669AF98u && return_key != 0x0669B048u))) && ((return_key != 0x066A1410u && (return_key != 0x066A4218u && return_key != 0x066A42A0u)) && ((return_key != 0x066A4310u && return_key != 0x066A4398u) && (return_key != 0x066A7590u && return_key != 0x066A7618u)))) && (((return_key != 0x066A7688u && (return_key != 0x066A7710u && return_key != 0x066A8930u)) && ((return_key != 0x066A89B8u && return_key != 0x066A8A28u) && (return_key != 0x066A8AB0u && return_key != 0x066A9620u))) && ((return_key != 0x066A96A8u && (return_key != 0x066A9718u && return_key != 0x066A97A0u)) && ((return_key != 0x066C3978u && return_key != 0x066CF680u) && (return_key != 0x066CFC28u && return_key != 0x066CFF68u))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FF1B0u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0xE3u, 0xFEu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE36u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFEu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x39u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEE3u;
            if (nh_scpu_expect_next(cpu, 0x060FF718u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060FF1D0u: {
            static const uint8_t expected_epoch[] = { 0x10u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE3Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFE3Du;
                if (nh_scpu_expect_next(cpu, 0x060FF1E8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE3Cu;
            if (nh_scpu_expect_next(cpu, 0x060FF1E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF1E0u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE3Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE3Du;
            if (nh_scpu_expect_next(cpu, 0x060FF1E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF1E8u: {
            static const uint8_t expected_epoch[] = { 0x98u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE3Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE3Eu;
            if (nh_scpu_expect_next(cpu, 0x060FF1F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF1F0u: {
            static const uint8_t expected_epoch[] = { 0x50u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE3Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_V) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFE43u;
                if (nh_scpu_expect_next(cpu, 0x060FF218u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE40u;
            if (nh_scpu_expect_next(cpu, 0x060FF200u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF200u: {
            static const uint8_t expected_epoch[] = { 0x49u, 0x01u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE40u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a ^ 0x0001u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE43u;
            if (nh_scpu_expect_next(cpu, 0x060FF218u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FF218u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE43u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE45u;
            if (nh_scpu_expect_next(cpu, 0x060FF228u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF228u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE45u,
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
            if ((((return_key != 0x061489D0u && (return_key != 0x06343A70u && return_key != 0x06343E10u)) && (return_key != 0x063441B0u && (return_key != 0x06344550u && return_key != 0x063D86A8u))) && ((return_key != 0x063D9930u && (return_key != 0x063DB140u && return_key != 0x064323B8u)) && (return_key != 0x06437F48u && (return_key != 0x06480D88u && return_key != 0x06498CF8u)))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FF230u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0xCBu, 0xFEu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE46u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFEu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x49u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFECBu;
            if (nh_scpu_expect_next(cpu, 0x060FF658u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060FF250u: {
            static const uint8_t expected_epoch[] = { 0xB0u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE4Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) != 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFE4Du;
                if (nh_scpu_expect_next(cpu, 0x060FF268u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE4Cu;
            if (nh_scpu_expect_next(cpu, 0x060FF260u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF260u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE4Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE4Du;
            if (nh_scpu_expect_next(cpu, 0x060FF268u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF268u: {
            static const uint8_t expected_epoch[] = { 0x84u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE4Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->y) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->y >> 8)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE4Fu;
            if (nh_scpu_expect_next(cpu, 0x060FF278u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF278u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE4Fu,
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
            if (((((return_key != 0x06098F70u && (return_key != 0x060A8938u && return_key != 0x060D19B0u)) && ((return_key != 0x060D2D90u && return_key != 0x06119158u) && (return_key != 0x061B2EE8u && return_key != 0x06387C38u))) && ((return_key != 0x06393CF8u && (return_key != 0x063CD580u && return_key != 0x0640ECC8u)) && ((return_key != 0x0640ED50u && return_key != 0x06410E00u) && (return_key != 0x06491AB8u && return_key != 0x064B6F98u)))) && (((return_key != 0x06516E18u && (return_key != 0x06517058u && return_key != 0x06526A08u)) && ((return_key != 0x06546C20u && return_key != 0x06547158u) && (return_key != 0x06547878u && return_key != 0x06609F10u))) && (((return_key != 0x06698CC0u && return_key != 0x0669BEB8u) && (return_key != 0x066B5F60u && return_key != 0x066B5FE8u)) && ((return_key != 0x066C8A70u && return_key != 0x066D42C8u) && (return_key != 0x066DF5C0u && return_key != 0x067161F8u))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FF2D0u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0xCBu, 0xFEu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE5Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFEu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x5Du) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFECBu;
            if (nh_scpu_expect_next(cpu, 0x060FF658u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060FF2F0u: {
            static const uint8_t expected_epoch[] = { 0x30u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE5Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) != 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFE61u;
                if (nh_scpu_expect_next(cpu, 0x060FF308u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE60u;
            if (nh_scpu_expect_next(cpu, 0x060FF300u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF300u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE60u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE61u;
            if (nh_scpu_expect_next(cpu, 0x060FF308u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF308u: {
            static const uint8_t expected_epoch[] = { 0x98u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE61u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE62u;
            if (nh_scpu_expect_next(cpu, 0x060FF310u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF310u: {
            static const uint8_t expected_epoch[] = { 0x50u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE62u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_V) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFE67u;
                if (nh_scpu_expect_next(cpu, 0x060FF338u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE64u;
            if (nh_scpu_expect_next(cpu, 0x060FF320u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF320u: {
            static const uint8_t expected_epoch[] = { 0x49u, 0x01u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE64u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a ^ 0x0001u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE67u;
            if (nh_scpu_expect_next(cpu, 0x060FF338u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FF338u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE67u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE69u;
            if (nh_scpu_expect_next(cpu, 0x060FF348u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF348u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE69u,
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
            if ((((((((return_key != 0x06080790u && return_key != 0x06088170u) && (return_key != 0x06088EB0u && (return_key != 0x06089700u && return_key != 0x06090178u))) && ((return_key != 0x06090310u && return_key != 0x06092DF0u) && (return_key != 0x06092F88u && (return_key != 0x060A1018u && return_key != 0x060A1128u)))) && (((return_key != 0x060A3060u && return_key != 0x060B2B08u) && (return_key != 0x060CC108u && (return_key != 0x060CC660u && return_key != 0x060CDE00u))) && ((return_key != 0x060CE0B8u && return_key != 0x06105778u) && (return_key != 0x061069B8u && (return_key != 0x06107008u && return_key != 0x0611F1A0u))))) && ((((return_key != 0x0611F240u && return_key != 0x06121DD8u) && (return_key != 0x061220B8u && (return_key != 0x06122398u && return_key != 0x0612CDE0u))) && ((return_key != 0x06147100u && return_key != 0x061AD370u) && (return_key != 0x061ADF00u && (return_key != 0x061AF2D0u && return_key != 0x061AFAE8u)))) && (((return_key != 0x061B0698u && return_key != 0x061B8DC0u) && (return_key != 0x061B8F00u && (return_key != 0x061CF158u && return_key != 0x061CF228u))) && ((return_key != 0x061D43E0u && return_key != 0x061DBE40u) && (return_key != 0x061E3230u && (return_key != 0x061E3690u && return_key != 0x062019E0u)))))) && (((((return_key != 0x06201AD8u && return_key != 0x06202158u) && (return_key != 0x06202298u && (return_key != 0x06202930u && return_key != 0x06202A70u))) && ((return_key != 0x06202BB0u && return_key != 0x06204F60u) && (return_key != 0x062113A8u && (return_key != 0x06211778u && return_key != 0x06211D68u)))) && (((return_key != 0x0621B2D0u && return_key != 0x0621B468u) && (return_key != 0x06228498u && (return_key != 0x06285C20u && return_key != 0x06285E48u))) && ((return_key != 0x0629A418u && return_key != 0x0629A508u) && (return_key != 0x062A2B28u && (return_key != 0x062A32E8u && return_key != 0x062A36C8u))))) && ((((return_key != 0x062A39A8u && return_key != 0x062A42F8u) && (return_key != 0x062A5BE0u && (return_key != 0x062A5D78u && return_key != 0x062CFDB8u))) && ((return_key != 0x062CFF98u && return_key != 0x062DD0D0u) && (return_key != 0x06304E30u && (return_key != 0x06305320u && return_key != 0x063053C0u)))) && (((return_key != 0x063059C0u && return_key != 0x06305C28u) && (return_key != 0x063331B8u && (return_key != 0x063332F8u && return_key != 0x06334E10u))) && ((return_key != 0x06334FA0u && (return_key != 0x06336808u && return_key != 0x06336888u)) && (return_key != 0x06336A68u && (return_key != 0x06338C78u && return_key != 0x06338F40u))))))) && ((((((return_key != 0x063390E0u && return_key != 0x06339AA0u) && (return_key != 0x06340CF0u && (return_key != 0x0634E078u && return_key != 0x0634E998u))) && ((return_key != 0x0634FBC8u && return_key != 0x0634FE60u) && (return_key != 0x06350030u && (return_key != 0x06382380u && return_key != 0x063849D8u)))) && (((return_key != 0x06384A58u && return_key != 0x06389C80u) && (return_key != 0x0638A160u && (return_key != 0x06393418u && return_key != 0x06393850u))) && ((return_key != 0x063A64E8u && return_key != 0x063A6680u) && (return_key != 0x063B31C0u && (return_key != 0x063B4678u && return_key != 0x063B4E40u))))) && ((((return_key != 0x063BEFD0u && return_key != 0x063BF070u) && (return_key != 0x063E5BF8u && (return_key != 0x0641D570u && return_key != 0x0641E1B8u))) && ((return_key != 0x0642B8B8u && return_key != 0x064334B8u) && (return_key != 0x06438508u && (return_key != 0x06438BC8u && return_key != 0x06482B68u)))) && (((return_key != 0x06484F98u && return_key != 0x06485D78u) && (return_key != 0x06499AC0u && (return_key != 0x0649D2A0u && return_key != 0x0649D5F0u))) && ((return_key != 0x064B4CD8u && (return_key != 0x064B4F98u && return_key != 0x064B74A0u)) && (return_key != 0x064B8300u && (return_key != 0x064BBF50u && return_key != 0x064BC0E8u)))))) && (((((return_key != 0x064BCAB0u && return_key != 0x064BCB90u) && (return_key != 0x064BCE18u && (return_key != 0x064BCEF8u && return_key != 0x064E7558u))) && ((return_key != 0x064E7A28u && return_key != 0x064E7F00u) && (return_key != 0x064F3CF0u && (return_key != 0x064F45D8u && return_key != 0x064F5460u)))) && (((return_key != 0x064F55B8u && return_key != 0x065024F8u) && (return_key != 0x06502C90u && (return_key != 0x0650FDC0u && return_key != 0x0650FEB8u))) && ((return_key != 0x06524508u && return_key != 0x0652C520u) && (return_key != 0x0652CA08u && (return_key != 0x065326E8u && return_key != 0x06532840u))))) && ((((return_key != 0x065371F0u && return_key != 0x06583128u) && (return_key != 0x066187C8u && (return_key != 0x06618910u && return_key != 0x06618E78u))) && ((return_key != 0x06618FB8u && return_key != 0x06619090u) && (return_key != 0x066191D0u && (return_key != 0x0662E990u && return_key != 0x0668E340u)))) && (((return_key != 0x0668E6C8u && return_key != 0x0668EAD0u) && (return_key != 0x0668EC60u && (return_key != 0x066A1528u && return_key != 0x066BEAB8u))) && ((return_key != 0x066BEC50u && (return_key != 0x066BF570u && return_key != 0x066BF610u)) && (return_key != 0x066C1A08u && (return_key != 0x066D5CF0u && return_key != 0x066DC000u)))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FF350u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0xE3u, 0xFEu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE6Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFEu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x6Du) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEE3u;
            if (nh_scpu_expect_next(cpu, 0x060FF718u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060FF370u: {
            static const uint8_t expected_epoch[] = { 0x30u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE6Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) != 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFE71u;
                if (nh_scpu_expect_next(cpu, 0x060FF388u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE70u;
            if (nh_scpu_expect_next(cpu, 0x060FF380u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF380u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE70u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE71u;
            if (nh_scpu_expect_next(cpu, 0x060FF388u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF388u: {
            static const uint8_t expected_epoch[] = { 0x98u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE71u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE72u;
            if (nh_scpu_expect_next(cpu, 0x060FF390u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF390u: {
            static const uint8_t expected_epoch[] = { 0x50u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE72u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_V) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFE77u;
                if (nh_scpu_expect_next(cpu, 0x060FF3B8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE74u;
            if (nh_scpu_expect_next(cpu, 0x060FF3A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF3A0u: {
            static const uint8_t expected_epoch[] = { 0x49u, 0x01u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE74u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a ^ 0x0001u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE77u;
            if (nh_scpu_expect_next(cpu, 0x060FF3B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FF3B8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE77u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE79u;
            if (nh_scpu_expect_next(cpu, 0x060FF3C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF3C8u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE79u,
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
            if (((((return_key != 0x06085F18u && (return_key != 0x060884E0u && return_key != 0x0608A688u)) && (return_key != 0x0610F798u && (return_key != 0x06282D58u && return_key != 0x06332838u))) && ((return_key != 0x06337238u && (return_key != 0x0633BE38u && return_key != 0x06352370u)) && ((return_key != 0x063AFDB8u && return_key != 0x063D5AD0u) && (return_key != 0x063D9A88u && return_key != 0x063DA0E0u)))) && (((return_key != 0x063DA970u && (return_key != 0x063F5568u && return_key != 0x063F7A50u)) && ((return_key != 0x06409AC8u && return_key != 0x06414FA8u) && (return_key != 0x0641AD90u && return_key != 0x0641C8D0u))) && ((return_key != 0x0641EFA8u && (return_key != 0x0642B2D0u && return_key != 0x064989F8u)) && ((return_key != 0x064C3148u && return_key != 0x064C3640u) && (return_key != 0x0665E1F8u && return_key != 0x067185D8u))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FF3D0u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0xCBu, 0xFEu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE7Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFEu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x7Du) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFECBu;
            if (nh_scpu_expect_next(cpu, 0x060FF658u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060FF3F0u: {
            static const uint8_t expected_epoch[] = { 0x90u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE7Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFE81u;
                if (nh_scpu_expect_next(cpu, 0x060FF408u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE80u;
            if (nh_scpu_expect_next(cpu, 0x060FF400u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF400u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE80u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE81u;
            if (nh_scpu_expect_next(cpu, 0x060FF408u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF408u: {
            static const uint8_t expected_epoch[] = { 0x84u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE81u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->y) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->y >> 8)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE83u;
            if (nh_scpu_expect_next(cpu, 0x060FF418u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF418u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE83u,
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
            if ((((((((return_key != 0x060BF318u && return_key != 0x060C1090u) && (return_key != 0x060C40C0u && return_key != 0x060CD740u)) && ((return_key != 0x060E12A0u && return_key != 0x060F2D28u) && (return_key != 0x060F3708u && (return_key != 0x06100BB0u && return_key != 0x06117BC0u)))) && (((return_key != 0x06118B98u && return_key != 0x0611A998u) && (return_key != 0x0611D968u && return_key != 0x061261B8u)) && ((return_key != 0x061265E8u && return_key != 0x06126AD0u) && (return_key != 0x06132E40u && (return_key != 0x06137A70u && return_key != 0x061443A0u))))) && ((((return_key != 0x0614CE18u && return_key != 0x0614DA38u) && (return_key != 0x061847A0u && return_key != 0x061858B8u)) && ((return_key != 0x06185A18u && return_key != 0x06186FD0u) && (return_key != 0x061881E0u && (return_key != 0x0619CE50u && return_key != 0x0619DA88u)))) && (((return_key != 0x0619DF68u && return_key != 0x0619F300u) && (return_key != 0x0619F850u && return_key != 0x0619F968u)) && ((return_key != 0x061A87D8u && return_key != 0x061A9E08u) && (return_key != 0x061B2130u && (return_key != 0x061BB3D8u && return_key != 0x061BC900u)))))) && (((((return_key != 0x061BCA40u && return_key != 0x061BFDD8u) && (return_key != 0x061BFF60u && return_key != 0x061CB740u)) && ((return_key != 0x061CDF58u && return_key != 0x061DC1B8u) && (return_key != 0x06214578u && (return_key != 0x0621EFF0u && return_key != 0x0621F6C0u)))) && (((return_key != 0x06236AA0u && return_key != 0x062380C0u) && (return_key != 0x0623A5F0u && return_key != 0x06241F68u)) && ((return_key != 0x062877F8u && return_key != 0x062878F0u) && (return_key != 0x062BA300u && (return_key != 0x062BA770u && return_key != 0x062D3A10u))))) && ((((return_key != 0x062E1708u && return_key != 0x06300D18u) && (return_key != 0x063012D8u && return_key != 0x06304F78u)) && ((return_key != 0x0630C478u && return_key != 0x0632B018u) && (return_key != 0x06330670u && (return_key != 0x063339D0u && return_key != 0x06335768u)))) && (((return_key != 0x06362C48u && return_key != 0x0638FF68u) && (return_key != 0x06390260u && return_key != 0x06390D60u)) && ((return_key != 0x06392958u && return_key != 0x063971E8u) && (return_key != 0x06397DD0u && (return_key != 0x0639C3A0u && return_key != 0x063B7D90u))))))) && ((((((return_key != 0x063B9390u && return_key != 0x063BD180u) && (return_key != 0x063BEDC0u && return_key != 0x063C2340u)) && ((return_key != 0x063CA310u && return_key != 0x063EB580u) && (return_key != 0x063F3E90u && (return_key != 0x063F3F38u && return_key != 0x063F98A0u)))) && (((return_key != 0x064047F0u && return_key != 0x06412B78u) && (return_key != 0x0641D3B8u && return_key != 0x0641D470u)) && ((return_key != 0x0641E000u && return_key != 0x0641E0B8u) && (return_key != 0x0642D848u && (return_key != 0x0642E0E0u && return_key != 0x0642E308u))))) && ((((return_key != 0x06432F98u && return_key != 0x064848D8u) && (return_key != 0x06489988u && return_key != 0x06494390u)) && ((return_key != 0x064947D0u && return_key != 0x06495740u) && (return_key != 0x0649B9B8u && (return_key != 0x0649BB50u && return_key != 0x0649CFE0u)))) && (((return_key != 0x0649D208u && return_key != 0x064AF328u) && (return_key != 0x064B5A60u && return_key != 0x064B6CF8u)) && ((return_key != 0x064CA858u && return_key != 0x0650CBA0u) && (return_key != 0x0650CEC8u && (return_key != 0x0650D300u && return_key != 0x0650D590u)))))) && (((((return_key != 0x065115C8u && return_key != 0x065118A8u) && (return_key != 0x06511928u && return_key != 0x06511B88u)) && ((return_key != 0x06511D08u && return_key != 0x0651D510u) && (return_key != 0x0652D478u && (return_key != 0x0653A420u && return_key != 0x06542EE8u)))) && (((return_key != 0x06610350u && return_key != 0x06611378u) && (return_key != 0x0661C5D8u && return_key != 0x06635048u)) && ((return_key != 0x06645B20u && return_key != 0x066894A0u) && (return_key != 0x0669D0E8u && (return_key != 0x0669D4A8u && return_key != 0x066A5C58u))))) && ((((return_key != 0x066A77F0u && return_key != 0x066A7950u) && (return_key != 0x066A8B90u && return_key != 0x066A8CF0u)) && ((return_key != 0x066C6540u && return_key != 0x066C7B50u) && (return_key != 0x066C8858u && (return_key != 0x066D7A28u && return_key != 0x066DAF00u)))) && (((return_key != 0x066E03C0u && return_key != 0x066E1458u) && (return_key != 0x066E1828u && return_key != 0x066E2880u)) && ((return_key != 0x066E29D8u && return_key != 0x0670E8A0u) && (return_key != 0x06715B30u && (return_key != 0x067272F8u && return_key != 0x06727598u)))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FF420u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0xE3u, 0xFEu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE84u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFEu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x87u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEE3u;
            if (nh_scpu_expect_next(cpu, 0x060FF718u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060FF440u: {
            static const uint8_t expected_epoch[] = { 0x90u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE88u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFE8Bu;
                if (nh_scpu_expect_next(cpu, 0x060FF458u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE8Au;
            if (nh_scpu_expect_next(cpu, 0x060FF450u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF450u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE8Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE8Bu;
            if (nh_scpu_expect_next(cpu, 0x060FF458u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF458u: {
            static const uint8_t expected_epoch[] = { 0x84u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE8Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->y) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->y >> 8)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE8Du;
            if (nh_scpu_expect_next(cpu, 0x060FF468u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF468u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE8Du,
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
            if ((((return_key != 0x061BABC0u && return_key != 0x063AFAB0u) && (return_key != 0x065297E8u && return_key != 0x06536BC8u)) && ((return_key != 0x0665BBB0u && return_key != 0x0665C2F8u) && (return_key != 0x0665CA40u && (return_key != 0x0665D188u && return_key != 0x0665D8D0u)))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FF470u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0xC2u, 0xFEu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE8Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFEu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x91u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEC2u;
            if (nh_scpu_expect_next(cpu, 0x060FF610u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060FF490u: {
            static const uint8_t expected_epoch[] = { 0x30u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE92u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) != 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFE95u;
                if (nh_scpu_expect_next(cpu, 0x060FF4A8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE94u;
            if (nh_scpu_expect_next(cpu, 0x060FF4A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF4A0u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE94u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE95u;
            if (nh_scpu_expect_next(cpu, 0x060FF4A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF4A8u: {
            static const uint8_t expected_epoch[] = { 0x98u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE95u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE96u;
            if (nh_scpu_expect_next(cpu, 0x060FF4B0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF4B0u: {
            static const uint8_t expected_epoch[] = { 0x50u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE96u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_V) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFE9Bu;
                if (nh_scpu_expect_next(cpu, 0x060FF4D8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE98u;
            if (nh_scpu_expect_next(cpu, 0x060FF4C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF4C0u: {
            static const uint8_t expected_epoch[] = { 0x49u, 0x01u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE98u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a ^ 0x0001u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE9Bu;
            if (nh_scpu_expect_next(cpu, 0x060FF4D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FF4D8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE9Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFE9Du;
            if (nh_scpu_expect_next(cpu, 0x060FF4E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF4E8u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE9Du,
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
            if ((((((((((return_key != 0x06080950u && (return_key != 0x06080B38u && return_key != 0x06083060u)) && (return_key != 0x06086740u && (return_key != 0x06086E20u && return_key != 0x06086EB8u))) && ((return_key != 0x06087DF8u && (return_key != 0x060894D0u && return_key != 0x06089AA8u)) && (return_key != 0x0608ED08u && (return_key != 0x06090098u && return_key != 0x06090230u)))) && (((return_key != 0x06090998u && (return_key != 0x06090A20u && return_key != 0x06090BC0u)) && (return_key != 0x06091808u && (return_key != 0x06092360u && return_key != 0x06092D10u))) && ((return_key != 0x06092EA8u && (return_key != 0x06093610u && return_key != 0x06093698u)) && (return_key != 0x06093838u && (return_key != 0x06094448u && return_key != 0x06094FA0u))))) && ((((return_key != 0x0609FBF8u && (return_key != 0x060A28D0u && return_key != 0x060A4130u)) && (return_key != 0x060A4300u && (return_key != 0x060A4538u && return_key != 0x060A49B8u))) && ((return_key != 0x060A6020u && (return_key != 0x060A7300u && return_key != 0x060B28F0u)) && (return_key != 0x060B42A0u && (return_key != 0x060B4368u && return_key != 0x060B4940u)))) && (((return_key != 0x060B4A08u && (return_key != 0x060B5110u && return_key != 0x060B51D8u)) && (return_key != 0x060B5A98u && (return_key != 0x060B5B60u && return_key != 0x060C1C40u))) && ((return_key != 0x060C2120u && (return_key != 0x060C2820u && return_key != 0x060CC220u)) && (return_key != 0x060CC778u && (return_key != 0x060CEDB8u && return_key != 0x060D0550u)))))) && (((((return_key != 0x060D0F80u && (return_key != 0x060D25B0u && return_key != 0x060D2738u)) && (return_key != 0x060D6DB8u && (return_key != 0x060DBD68u && return_key != 0x060DCE58u))) && ((return_key != 0x060E0970u && (return_key != 0x060EB838u && return_key != 0x060EE528u)) && (return_key != 0x060EE848u && (return_key != 0x060EE998u && return_key != 0x06100578u)))) && (((return_key != 0x06100670u && (return_key != 0x06100770u && return_key != 0x06100870u)) && (return_key != 0x06106550u && (return_key != 0x061066B8u && return_key != 0x06106BB8u))) && ((return_key != 0x06106D20u && (return_key != 0x061096C0u && return_key != 0x06109748u)) && (return_key != 0x06120010u && (return_key != 0x0612CBC0u && return_key != 0x0612D388u))))) && ((((return_key != 0x0612E5D0u && (return_key != 0x061320C8u && return_key != 0x06133BF0u)) && (return_key != 0x06137DA8u && (return_key != 0x06137E40u && return_key != 0x0613A888u))) && ((return_key != 0x0613BE30u && (return_key != 0x0613CB30u && return_key != 0x0613D818u)) && (return_key != 0x0613DE90u && (return_key != 0x0613EB50u && return_key != 0x0613FB88u)))) && (((return_key != 0x06140408u && (return_key != 0x06146DF8u && return_key != 0x06147078u)) && (return_key != 0x061512C0u && (return_key != 0x061518B0u && return_key != 0x06151F70u))) && ((return_key != 0x06152008u && (return_key != 0x06154030u && return_key != 0x06155060u)) && ((return_key != 0x06155DF0u && return_key != 0x06156B00u) && (return_key != 0x06157C10u && return_key != 0x06158048u))))))) && ((((((return_key != 0x06158398u && (return_key != 0x06158E28u && return_key != 0x06159060u)) && (return_key != 0x06159250u && (return_key != 0x06159568u && return_key != 0x0615A788u))) && ((return_key != 0x0615AD40u && (return_key != 0x061843E8u && return_key != 0x061844B0u)) && (return_key != 0x06184ED8u && (return_key != 0x06184FA0u && return_key != 0x061865B8u)))) && (((return_key != 0x06186680u && (return_key != 0x06187D28u && return_key != 0x06187DF0u)) && (return_key != 0x06189240u && (return_key != 0x061892E0u && return_key != 0x0618A980u))) && ((return_key != 0x0618BE60u && (return_key != 0x0618C1E8u && return_key != 0x0618C6A8u)) && (return_key != 0x0618D080u && (return_key != 0x0618D620u && return_key != 0x0618DED0u))))) && ((((return_key != 0x0618E8D8u && (return_key != 0x0618F4E8u && return_key != 0x0618FC78u)) && (return_key != 0x061904A8u && (return_key != 0x06192040u && return_key != 0x06192860u))) && ((return_key != 0x06194108u && (return_key != 0x061943D0u && return_key != 0x06198FB8u)) && (return_key != 0x06199748u && (return_key != 0x06199818u && return_key != 0x06199EE8u)))) && (((return_key != 0x0619B430u && (return_key != 0x0619C560u && return_key != 0x0619CB10u)) && (return_key != 0x0619D210u && (return_key != 0x0619E178u && return_key != 0x0619E4C0u))) && ((return_key != 0x0619E7B0u && (return_key != 0x0619EA58u && return_key != 0x0619EED8u)) && (return_key != 0x0619F548u && (return_key != 0x0619FDF8u && return_key != 0x061A6618u)))))) && (((((return_key != 0x061A6728u && (return_key != 0x061A6A18u && return_key != 0x061A6EE8u)) && (return_key != 0x061A7030u && (return_key != 0x061A7320u && return_key != 0x061A77F0u))) && ((return_key != 0x061A93E8u && (return_key != 0x061A9618u && return_key != 0x061AA2E8u)) && (return_key != 0x061AA6F0u && (return_key != 0x061ABD30u && return_key != 0x061AEA60u)))) && (((return_key != 0x061AF1F8u && (return_key != 0x061AF598u && return_key != 0x061AFA18u)) && (return_key != 0x061B05C0u && (return_key != 0x061B2288u && return_key != 0x061B3920u))) && ((return_key != 0x061B3B00u && (return_key != 0x061B3CF0u && return_key != 0x061B3F28u)) && (return_key != 0x061B4E88u && (return_key != 0x061B51F0u && return_key != 0x061B7530u))))) && ((((return_key != 0x061B8E60u && (return_key != 0x061C9E50u && return_key != 0x061C9F00u)) && (return_key != 0x061C9FB0u && (return_key != 0x061CA138u && return_key != 0x061CA450u))) && ((return_key != 0x061CA6F8u && (return_key != 0x061CAC18u && return_key != 0x061CACC8u)) && (return_key != 0x061CDCA8u && (return_key != 0x061CEFD0u && return_key != 0x061CF088u)))) && (((return_key != 0x061D40F8u && (return_key != 0x061D4318u && return_key != 0x061D4578u)) && (return_key != 0x061D5668u && (return_key != 0x061D5E90u && return_key != 0x061D65D8u))) && ((return_key != 0x061D6938u && (return_key != 0x061D6E90u && return_key != 0x061D75C0u)) && ((return_key != 0x061D7D08u && return_key != 0x061D8350u) && (return_key != 0x061D8CB8u && return_key != 0x061D91C8u)))))))) && (((((((return_key != 0x061D9DD8u && (return_key != 0x061DDC40u && return_key != 0x061DDF28u)) && (return_key != 0x061DE020u && (return_key != 0x061DE118u && return_key != 0x061DF008u))) && ((return_key != 0x061DF508u && (return_key != 0x061E0248u && return_key != 0x061E0C50u)) && (return_key != 0x061E1DE8u && (return_key != 0x061E1FF0u && return_key != 0x061E20B0u)))) && (((return_key != 0x061E2578u && (return_key != 0x061E2BC0u && return_key != 0x061E2DC8u)) && (return_key != 0x061E3030u && (return_key != 0x061E3440u && return_key != 0x06200408u))) && ((return_key != 0x06201448u && (return_key != 0x06201958u && return_key != 0x06201A50u)) && (return_key != 0x062021F8u && (return_key != 0x062029D0u && return_key != 0x06202B10u))))) && ((((return_key != 0x06202E70u && (return_key != 0x06203B58u && return_key != 0x06203C50u)) && (return_key != 0x06203DC8u && (return_key != 0x06204740u && return_key != 0x0620ED68u))) && ((return_key != 0x0620EF88u && (return_key != 0x06210E68u && return_key != 0x06211218u)) && (return_key != 0x06211440u && (return_key != 0x06211828u && return_key != 0x06211BD8u)))) && (((return_key != 0x06211E00u && (return_key != 0x062132E8u && return_key != 0x06213890u)) && (return_key != 0x06215DB8u && (return_key != 0x06216C88u && return_key != 0x06217410u))) && ((return_key != 0x06217538u && (return_key != 0x06218C00u && return_key != 0x06219828u)) && (return_key != 0x06219D88u && (return_key != 0x0621A048u && return_key != 0x0621B1F0u)))))) && (((((return_key != 0x0621B388u && (return_key != 0x0621BAE0u && return_key != 0x0621C9D0u)) && (return_key != 0x0621E9E8u && (return_key != 0x06221420u && return_key != 0x06224A70u))) && ((return_key != 0x06225188u && (return_key != 0x06225920u && return_key != 0x06226230u)) && (return_key != 0x06228150u && (return_key != 0x06228548u && return_key != 0x0622A048u)))) && (((return_key != 0x0622ACD0u && (return_key != 0x0622ADC8u && return_key != 0x0622AF70u)) && (return_key != 0x0622B8D0u && (return_key != 0x062361D8u && return_key != 0x06237A20u))) && ((return_key != 0x06238320u && (return_key != 0x06240A70u && return_key != 0x06259B08u)) && (return_key != 0x06259D20u && (return_key != 0x0625AE20u && return_key != 0x062827D0u))))) && ((((return_key != 0x06285CD8u && (return_key != 0x06285F00u && return_key != 0x062869F8u)) && (return_key != 0x06286D80u && (return_key != 0x06289710u && return_key != 0x0628A8B0u))) && ((return_key != 0x0628AF08u && (return_key != 0x0628C808u && return_key != 0x0628D0D0u)) && (return_key != 0x0628FB58u && (return_key != 0x0628FF48u && return_key != 0x06290250u)))) && (((return_key != 0x06290380u && (return_key != 0x062916D0u && return_key != 0x06292030u)) && (return_key != 0x06292900u && (return_key != 0x06292CB8u && return_key != 0x06292F60u))) && ((return_key != 0x06293100u && (return_key != 0x062939B8u && return_key != 0x06294D68u)) && ((return_key != 0x06297440u && return_key != 0x062985E0u) && (return_key != 0x0629EC08u && return_key != 0x0629EE48u))))))) && ((((((return_key != 0x0629F278u && (return_key != 0x062A0AE8u && return_key != 0x062A0BB0u)) && (return_key != 0x062A1B98u && (return_key != 0x062A2208u && return_key != 0x062A2BB0u))) && ((return_key != 0x062A3220u && (return_key != 0x062A3750u && return_key != 0x062A38E0u)) && (return_key != 0x062A4550u && (return_key != 0x062A5B00u && return_key != 0x062A5C98u)))) && (((return_key != 0x062A6AF8u && (return_key != 0x062A6C50u && return_key != 0x062A82D0u)) && (return_key != 0x062AA5D8u && (return_key != 0x062B0098u && return_key != 0x062B2170u))) && ((return_key != 0x062B2B50u && (return_key != 0x062B5040u && return_key != 0x062B6568u)) && (return_key != 0x062BD860u && (return_key != 0x062BDAA0u && return_key != 0x062C0EA8u))))) && ((((return_key != 0x062C1810u && (return_key != 0x062C2B18u && return_key != 0x062C4A68u)) && (return_key != 0x062C5498u && (return_key != 0x062C5C18u && return_key != 0x062C5EA8u))) && ((return_key != 0x062C6820u && (return_key != 0x062C73E8u && return_key != 0x062C7B00u)) && (return_key != 0x062CD848u && (return_key != 0x062CDB90u && return_key != 0x062CDC58u)))) && (((return_key != 0x062CE250u && (return_key != 0x062CE550u && return_key != 0x062CFE58u)) && (return_key != 0x062D0038u && (return_key != 0x062D7F28u && return_key != 0x062D8450u))) && ((return_key != 0x062D90F0u && (return_key != 0x062D9808u && return_key != 0x062D9C48u)) && (return_key != 0x062DA9C8u && (return_key != 0x062DABF8u && return_key != 0x062DAFD8u)))))) && (((((return_key != 0x062DB328u && (return_key != 0x062DB700u && return_key != 0x062DBD90u)) && (return_key != 0x062DC640u && (return_key != 0x062DC938u && return_key != 0x062E0A40u))) && ((return_key != 0x06304D90u && (return_key != 0x06305888u && return_key != 0x06305B08u)) && (return_key != 0x063064A0u && (return_key != 0x063068D8u && return_key != 0x0632B140u)))) && (((return_key != 0x0632B358u && (return_key != 0x0632BEA8u && return_key != 0x06330E38u)) && (return_key != 0x06333638u && (return_key != 0x06333700u && return_key != 0x063353D0u))) && ((return_key != 0x06335498u && (return_key != 0x0633D6C8u && return_key != 0x0633DC18u)) && (return_key != 0x0633E008u && (return_key != 0x0633E900u && return_key != 0x0633F768u))))) && ((((return_key != 0x06342730u && (return_key != 0x06342AE0u && return_key != 0x06342CB8u)) && (return_key != 0x06354098u && (return_key != 0x06359B60u && return_key != 0x0635A700u))) && ((return_key != 0x06380130u && (return_key != 0x06380518u && return_key != 0x06380AF0u)) && (return_key != 0x06380FD8u && (return_key != 0x06381618u && return_key != 0x063819A0u)))) && (((return_key != 0x06381DB0u && (return_key != 0x06382100u && return_key != 0x06382EA0u)) && (return_key != 0x06383418u && (return_key != 0x06383A00u && return_key != 0x063840C8u))) && ((return_key != 0x06384BA0u && (return_key != 0x06385410u && return_key != 0x06386078u)) && ((return_key != 0x06386220u && return_key != 0x063866E0u) && (return_key != 0x06386CE8u && return_key != 0x06387090u))))))))) && ((((((((return_key != 0x06387428u && (return_key != 0x06387A20u && return_key != 0x06389E20u)) && (return_key != 0x06389F48u && (return_key != 0x06392E98u && return_key != 0x06392F50u))) && ((return_key != 0x063939B0u && (return_key != 0x06393B20u && return_key != 0x063A0808u)) && (return_key != 0x063A0CA8u && (return_key != 0x063A4570u && return_key != 0x063A4DC0u)))) && (((return_key != 0x063A5770u && (return_key != 0x063A5930u && return_key != 0x063A5CC8u)) && (return_key != 0x063A6408u && (return_key != 0x063A65A0u && return_key != 0x063A6B08u))) && ((return_key != 0x063A6CA0u && (return_key != 0x063AEDF8u && return_key != 0x063B0A50u)) && (return_key != 0x063B2EC0u && (return_key != 0x063B38C0u && return_key != 0x063B42A8u))))) && ((((return_key != 0x063B4C80u && (return_key != 0x063B55A0u && return_key != 0x063B5D88u)) && (return_key != 0x063B7908u && (return_key != 0x063B7C18u && return_key != 0x063B8C38u))) && ((return_key != 0x063BAAE8u && (return_key != 0x063BBDC8u && return_key != 0x063BC620u)) && (return_key != 0x063BEC70u && (return_key != 0x063BFC30u && return_key != 0x063C07C8u)))) && (((return_key != 0x063C1510u && (return_key != 0x063C21F0u && return_key != 0x063C4128u)) && (return_key != 0x063C6528u && (return_key != 0x063CA960u && return_key != 0x063CD350u))) && ((return_key != 0x063CDB20u && (return_key != 0x063CE288u && return_key != 0x063D05A8u)) && (return_key != 0x063D0A50u && (return_key != 0x063D1648u && return_key != 0x063D1778u)))))) && (((((return_key != 0x063D18A8u && (return_key != 0x063D1CC0u && return_key != 0x063D3EF0u)) && (return_key != 0x063D6EF0u && (return_key != 0x063D8910u && return_key != 0x063DF440u))) && ((return_key != 0x063E0590u && (return_key != 0x063E0798u && return_key != 0x063E1308u)) && (return_key != 0x063E1BC0u && (return_key != 0x063E1DC8u && return_key != 0x063E2938u)))) && (((return_key != 0x063E4458u && (return_key != 0x063E4D20u && return_key != 0x063E5018u)) && (return_key != 0x063E8528u && (return_key != 0x063E9200u && return_key != 0x063E9500u))) && ((return_key != 0x063E9FB0u && (return_key != 0x063EA408u && return_key != 0x063EBC78u)) && (return_key != 0x063ECC98u && (return_key != 0x063ED540u && return_key != 0x063F1B88u))))) && ((((return_key != 0x063F2A78u && (return_key != 0x063F3798u && return_key != 0x063F4620u)) && (return_key != 0x063F4C70u && (return_key != 0x063F51A8u && return_key != 0x063F72C0u))) && ((return_key != 0x063F8268u && (return_key != 0x063F8580u && return_key != 0x063F8D60u)) && (return_key != 0x06400C28u && (return_key != 0x06401BB0u && return_key != 0x06406488u)))) && (((return_key != 0x06406B00u && (return_key != 0x06406EA8u && return_key != 0x06407C60u)) && (return_key != 0x06408F70u && (return_key != 0x0640B1B0u && return_key != 0x0640B698u))) && ((return_key != 0x0640F800u && (return_key != 0x06410BA8u && return_key != 0x06412C90u)) && ((return_key != 0x06413318u && return_key != 0x06416C00u) && (return_key != 0x064189B0u && return_key != 0x0641A610u))))))) && ((((((return_key != 0x0641B378u && (return_key != 0x064207C0u && return_key != 0x06420D28u)) && (return_key != 0x06421338u && (return_key != 0x06421A90u && return_key != 0x06424E80u))) && ((return_key != 0x06425AE0u && (return_key != 0x064266B8u && return_key != 0x06426C70u)) && (return_key != 0x06427060u && (return_key != 0x06428608u && return_key != 0x06428E20u)))) && (((return_key != 0x06429228u && (return_key != 0x0642A068u && return_key != 0x0642C8A8u)) && (return_key != 0x0642E000u && (return_key != 0x0642E660u && return_key != 0x064303D8u))) && ((return_key != 0x064307E0u && (return_key != 0x06432A90u && return_key != 0x064330A0u)) && (return_key != 0x06434278u && (return_key != 0x064356F8u && return_key != 0x06435B98u))))) && ((((return_key != 0x06435DD0u && (return_key != 0x06436EE0u && return_key != 0x06436FA8u)) && (return_key != 0x064380F8u && (return_key != 0x064394E8u && return_key != 0x0643AED8u))) && ((return_key != 0x0643C7B0u && (return_key != 0x0643DB50u && return_key != 0x06480478u)) && (return_key != 0x064814D8u && (return_key != 0x06481870u && return_key != 0x06481FD0u)))) && (((return_key != 0x064827B0u && (return_key != 0x064829D0u && return_key != 0x06483C60u)) && (return_key != 0x06483D78u && (return_key != 0x064845D8u && return_key != 0x064852D8u))) && ((return_key != 0x06485CF0u && (return_key != 0x06486760u && return_key != 0x06486B98u)) && (return_key != 0x06489DA8u && (return_key != 0x06489E70u && return_key != 0x0648A8D8u)))))) && (((((return_key != 0x0648B1F0u && (return_key != 0x0648B488u && return_key != 0x0648B8B8u)) && (return_key != 0x0648BA20u && (return_key != 0x0648C310u && return_key != 0x0648C770u))) && ((return_key != 0x0648C8D8u && (return_key != 0x0648D1C8u && return_key != 0x0648D650u)) && (return_key != 0x0648D758u && (return_key != 0x0648E630u && return_key != 0x0648ED08u)))) && (((return_key != 0x0648FD50u && (return_key != 0x064901C0u && return_key != 0x06490360u)) && (return_key != 0x06490880u && (return_key != 0x06490C30u && return_key != 0x06491090u))) && ((return_key != 0x06491630u && (return_key != 0x064918B8u && return_key != 0x06491DB0u)) && (return_key != 0x06492928u && (return_key != 0x06492D28u && return_key != 0x06494170u))))) && ((((return_key != 0x06494F48u && (return_key != 0x064953C8u && return_key != 0x064954C8u)) && (return_key != 0x06495860u && (return_key != 0x06495C20u && return_key != 0x06496538u))) && ((return_key != 0x06496AA8u && (return_key != 0x06496F98u && return_key != 0x064972A0u)) && (return_key != 0x06498278u && (return_key != 0x06499D88u && return_key != 0x0649D338u)))) && (((return_key != 0x0649D688u && (return_key != 0x0649E380u && return_key != 0x064A2C60u)) && (return_key != 0x064A3D18u && (return_key != 0x064A48D0u && return_key != 0x064A4A70u))) && ((return_key != 0x064A4F18u && (return_key != 0x064A9CB0u && return_key != 0x064AA3B0u)) && ((return_key != 0x064AB890u && return_key != 0x064AE608u) && (return_key != 0x064AE748u && return_key != 0x064AF1A8u)))))))) && (((((((return_key != 0x064AF9D8u && (return_key != 0x064AFAD0u && return_key != 0x064B05A8u)) && (return_key != 0x064B06A0u && (return_key != 0x064B2960u && return_key != 0x064B2BE8u))) && ((return_key != 0x064B2FA8u && (return_key != 0x064B34C8u && return_key != 0x064B3C90u)) && (return_key != 0x064B3E48u && (return_key != 0x064B4110u && return_key != 0x064B5C38u)))) && (((return_key != 0x064B9220u && (return_key != 0x064B9488u && return_key != 0x064B97D8u)) && (return_key != 0x064BAA28u && (return_key != 0x064BADE0u && return_key != 0x064BBE70u))) && ((return_key != 0x064BC008u && (return_key != 0x064BC610u && return_key != 0x064BCA40u)) && (return_key != 0x064BCC18u && (return_key != 0x064BCDA8u && return_key != 0x064BCF80u))))) && ((((return_key != 0x064BE090u && (return_key != 0x064BF608u && return_key != 0x064C0F98u)) && (return_key != 0x064C1310u && (return_key != 0x064C2310u && return_key != 0x064C24E0u))) && ((return_key != 0x064C57D0u && (return_key != 0x064C6190u && return_key != 0x064C65F0u)) && (return_key != 0x064C6D30u && (return_key != 0x064C7528u && return_key != 0x064C7988u)))) && (((return_key != 0x064C80C8u && (return_key != 0x064C8738u && return_key != 0x064C9070u)) && (return_key != 0x064D17A8u && (return_key != 0x064D1C58u && return_key != 0x064D5E70u))) && ((return_key != 0x064DD0D0u && (return_key != 0x064E35E0u && return_key != 0x064E8568u)) && (return_key != 0x064ECA70u && (return_key != 0x064ECED0u && return_key != 0x064F0078u)))))) && (((((return_key != 0x064F3C38u && (return_key != 0x064F3FE8u && return_key != 0x064F42E0u)) && (return_key != 0x064F53A0u && (return_key != 0x064F54F8u && return_key != 0x064F5D90u))) && ((return_key != 0x064F5E30u && (return_key != 0x065000C8u && return_key != 0x06500190u)) && (return_key != 0x06501C08u && (return_key != 0x06501F00u && return_key != 0x06502388u)))) && (((return_key != 0x065026A8u && (return_key != 0x06502B20u && return_key != 0x06503868u)) && (return_key != 0x06503960u && (return_key != 0x06503F48u && return_key != 0x06504308u))) && ((return_key != 0x06504400u && (return_key != 0x06505098u && return_key != 0x06505730u)) && (return_key != 0x06505F00u && (return_key != 0x0650A038u && return_key != 0x0650B0E8u))))) && ((((return_key != 0x0650B900u && (return_key != 0x06514278u && return_key != 0x06515600u)) && (return_key != 0x06516610u && (return_key != 0x06517CA0u && return_key != 0x065196E0u))) && ((return_key != 0x0651ABE8u && (return_key != 0x0651BBB0u && return_key != 0x0651C518u)) && (return_key != 0x0651CB38u && (return_key != 0x0651CBD8u && return_key != 0x0651CFD0u)))) && (((return_key != 0x0651D9F0u && (return_key != 0x0651F9B0u && return_key != 0x06520878u)) && (return_key != 0x065211B0u && (return_key != 0x065283B8u && return_key != 0x06528C30u))) && ((return_key != 0x06529A38u && (return_key != 0x0652A1E8u && return_key != 0x0652AA98u)) && ((return_key != 0x0652B8E0u && return_key != 0x0652C1C0u) && (return_key != 0x0652CDF8u && return_key != 0x0652CFF0u))))))) && ((((((return_key != 0x0652D5F0u && (return_key != 0x0652DA28u && return_key != 0x0652E4C0u)) && (return_key != 0x065303C0u && (return_key != 0x06532628u && return_key != 0x06532780u))) && ((return_key != 0x06532AE0u && (return_key != 0x06532CB0u && return_key != 0x06532DA8u)) && (return_key != 0x065372F0u && (return_key != 0x0660BFB8u && return_key != 0x0660C080u)))) && (((return_key != 0x0660DE98u && (return_key != 0x0660DF60u && return_key != 0x0660E508u)) && (return_key != 0x0660E5D0u && (return_key != 0x0660E6E0u && return_key != 0x0660E7F0u))) && ((return_key != 0x0660EC58u && (return_key != 0x0660ED20u && return_key != 0x0660F490u)) && (return_key != 0x0660F548u && (return_key != 0x0660FE48u && return_key != 0x066109C8u))))) && ((((return_key != 0x06610DA8u && (return_key != 0x06612A98u && return_key != 0x06613420u)) && (return_key != 0x06614508u && (return_key != 0x06616030u && return_key != 0x06618448u))) && ((return_key != 0x06618718u && (return_key != 0x06618860u && return_key != 0x066193C0u)) && (return_key != 0x06619BA0u && (return_key != 0x06619F00u && return_key != 0x0661B1F8u)))) && (((return_key != 0x0661D078u && (return_key != 0x0661D248u && return_key != 0x06633C10u)) && (return_key != 0x06647098u && (return_key != 0x06647340u && return_key != 0x0669E918u))) && ((return_key != 0x066AB7F8u && (return_key != 0x066ABAF0u && return_key != 0x066B7668u)) && (return_key != 0x066B7730u && (return_key != 0x066B7868u && return_key != 0x066B78F0u)))))) && (((((return_key != 0x066B9880u && (return_key != 0x066BC8A0u && return_key != 0x066BD2C8u)) && (return_key != 0x066BD600u && (return_key != 0x066BEF70u && return_key != 0x066BF948u))) && ((return_key != 0x066C00C8u && (return_key != 0x066C1D38u && return_key != 0x066C2C00u)) && (return_key != 0x066CF510u && (return_key != 0x066CF810u && return_key != 0x066CFDB8u)))) && (((return_key != 0x066D6638u && (return_key != 0x066D6768u && return_key != 0x06700330u)) && (return_key != 0x067004D0u && (return_key != 0x06707E08u && return_key != 0x067083A0u))) && ((return_key != 0x06709C88u && (return_key != 0x0670A400u && return_key != 0x0670DC28u)) && (return_key != 0x0670DD18u && (return_key != 0x0670E0D0u && return_key != 0x0670E748u))))) && ((((return_key != 0x0670EA80u && (return_key != 0x0670EB48u && return_key != 0x06711D78u)) && (return_key != 0x06712B08u && (return_key != 0x067138A0u && return_key != 0x067146B0u))) && ((return_key != 0x06714C88u && (return_key != 0x06715E30u && return_key != 0x06718750u)) && (return_key != 0x067195F0u && (return_key != 0x06719828u && return_key != 0x06719A58u)))) && (((return_key != 0x06719F48u && (return_key != 0x0671A1F8u && return_key != 0x0671A428u)) && (return_key != 0x0671B788u && (return_key != 0x0671B840u && return_key != 0x0671E7D8u))) && ((return_key != 0x0671F578u && (return_key != 0x0671FAE0u && return_key != 0x067200F0u)) && ((return_key != 0x06721428u && return_key != 0x06722068u) && (return_key != 0x06722AE8u && return_key != 0x06723398u)))))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FF4F0u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0xD4u, 0xFEu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FE9Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFEu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xA1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFED4u;
            if (nh_scpu_expect_next(cpu, 0x060FF6A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060FF510u: {
            static const uint8_t expected_epoch[] = { 0x30u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEA2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) != 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFEA5u;
                if (nh_scpu_expect_next(cpu, 0x060FF528u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEA4u;
            if (nh_scpu_expect_next(cpu, 0x060FF520u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF520u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEA4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEA5u;
            if (nh_scpu_expect_next(cpu, 0x060FF528u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF528u: {
            static const uint8_t expected_epoch[] = { 0x98u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEA5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = cpu->y;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEA6u;
            if (nh_scpu_expect_next(cpu, 0x060FF530u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF530u: {
            static const uint8_t expected_epoch[] = { 0x50u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEA6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_V) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFEABu;
                if (nh_scpu_expect_next(cpu, 0x060FF558u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEA8u;
            if (nh_scpu_expect_next(cpu, 0x060FF540u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF540u: {
            static const uint8_t expected_epoch[] = { 0x49u, 0x01u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEA8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a ^ 0x0001u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEABu;
            if (nh_scpu_expect_next(cpu, 0x060FF558u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FF558u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEABu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEADu;
            if (nh_scpu_expect_next(cpu, 0x060FF568u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF568u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEADu,
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
            if (((((return_key != 0x060885A0u && (return_key != 0x0610FF78u && return_key != 0x0611FBE8u)) && ((return_key != 0x0614D650u && return_key != 0x06332730u) && (return_key != 0x0633B908u && return_key != 0x0633BB10u))) && ((return_key != 0x0633BCB0u && (return_key != 0x0633C118u && return_key != 0x0633CFF8u)) && ((return_key != 0x06352128u && return_key != 0x063AF6D8u) && (return_key != 0x063BC498u && return_key != 0x063BDD90u)))) && (((return_key != 0x063CF858u && (return_key != 0x063DB9E0u && return_key != 0x063DC898u)) && ((return_key != 0x063E9DD0u && return_key != 0x0640E210u) && (return_key != 0x0640E550u && return_key != 0x06429D80u))) && (((return_key != 0x0642FD48u && return_key != 0x06436510u) && (return_key != 0x0643BB18u && return_key != 0x0643D548u)) && ((return_key != 0x064969E0u && return_key != 0x0661CB98u) && (return_key != 0x0661CD78u && return_key != 0x0665DFA0u))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FF570u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0xC2u, 0xFEu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEAEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFEu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xB1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEC2u;
            if (nh_scpu_expect_next(cpu, 0x060FF610u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060FF590u: {
            static const uint8_t expected_epoch[] = { 0x90u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEB2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFEB5u;
                if (nh_scpu_expect_next(cpu, 0x060FF5A8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEB4u;
            if (nh_scpu_expect_next(cpu, 0x060FF5A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF5A0u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEB4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEB5u;
            if (nh_scpu_expect_next(cpu, 0x060FF5A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF5A8u: {
            static const uint8_t expected_epoch[] = { 0x84u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEB5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->y) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->y >> 8)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEB7u;
            if (nh_scpu_expect_next(cpu, 0x060FF5B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF5B8u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEB7u,
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
            if ((((((((((return_key != 0x06082620u && return_key != 0x06083280u) && (return_key != 0x0608F700u && return_key != 0x0609A3D8u)) && ((return_key != 0x0609B670u && return_key != 0x0609C460u) && (return_key != 0x0609EC88u && (return_key != 0x060A12A8u && return_key != 0x060A37E8u)))) && (((return_key != 0x060A3B70u && return_key != 0x060A5868u) && (return_key != 0x060A6B20u && return_key != 0x060A7AB8u)) && ((return_key != 0x060A8480u && return_key != 0x060A8B08u) && (return_key != 0x060A9638u && (return_key != 0x060A9C08u && return_key != 0x060AA640u))))) && ((((return_key != 0x060AAC40u && return_key != 0x060AD008u) && (return_key != 0x060AD730u && return_key != 0x060ADBB8u)) && ((return_key != 0x060BAA50u && return_key != 0x060BAF68u) && (return_key != 0x060BC660u && (return_key != 0x060BD2F8u && return_key != 0x060BD558u)))) && (((return_key != 0x060BD6C0u && return_key != 0x060BDA38u) && (return_key != 0x060BF800u && return_key != 0x060BFAD0u)) && ((return_key != 0x060BFC88u && return_key != 0x060C0090u) && (return_key != 0x060C15D8u && (return_key != 0x060C1968u && return_key != 0x060C1F68u)))))) && (((((return_key != 0x060C2668u && return_key != 0x060C30B8u) && (return_key != 0x060C3970u && return_key != 0x060C4CF0u)) && ((return_key != 0x060C6498u && return_key != 0x060C77C0u) && (return_key != 0x060C9C30u && (return_key != 0x060E41A8u && return_key != 0x060EE3D8u)))) && (((return_key != 0x060EF290u && return_key != 0x060EF350u) && (return_key != 0x060EFCC0u && return_key != 0x060EFD80u)) && ((return_key != 0x060F0588u && return_key != 0x060F0648u) && (return_key != 0x060F1180u && (return_key != 0x060F13D0u && return_key != 0x060F15C8u))))) && ((((return_key != 0x060F1958u && return_key != 0x060F1B50u) && (return_key != 0x060F3B98u && return_key != 0x06101188u)) && ((return_key != 0x06102960u && return_key != 0x06102B10u) && (return_key != 0x06104238u && (return_key != 0x06104B00u && return_key != 0x06107788u)))) && (((return_key != 0x06109AE0u && return_key != 0x0610B9B8u) && (return_key != 0x0610BBC8u && return_key != 0x0610C9C8u)) && ((return_key != 0x0610D9F0u && return_key != 0x0610DB70u) && (return_key != 0x0610EF68u && (return_key != 0x0610F1D0u && return_key != 0x06110518u))))))) && ((((((return_key != 0x06112490u && return_key != 0x06112550u) && (return_key != 0x06112CB8u && return_key != 0x06112D78u)) && ((return_key != 0x06114A00u && return_key != 0x06117100u) && (return_key != 0x0611A638u && (return_key != 0x0611AA70u && return_key != 0x0611DE08u)))) && (((return_key != 0x06125970u && return_key != 0x061273D0u) && (return_key != 0x06127598u && return_key != 0x0612C520u)) && ((return_key != 0x06132CD8u && return_key != 0x06133440u) && (return_key != 0x06133B40u && (return_key != 0x06137730u && return_key != 0x06138AF8u))))) && ((((return_key != 0x06138BD0u && return_key != 0x06138CA8u) && (return_key != 0x0613D0C8u && return_key != 0x0613FAF8u)) && ((return_key != 0x061410B0u && return_key != 0x061440F0u) && (return_key != 0x061464C0u && (return_key != 0x0614AEC0u && return_key != 0x0614C290u)))) && (((return_key != 0x0614C4F0u && return_key != 0x0614C5B8u) && (return_key != 0x0614CEE8u && return_key != 0x0614D1E8u)) && ((return_key != 0x0614EC50u && return_key != 0x0614F6F8u) && (return_key != 0x06150B60u && (return_key != 0x06150EE0u && return_key != 0x06181280u)))))) && (((((return_key != 0x06181650u && return_key != 0x06181A20u) && (return_key != 0x06181DF0u && return_key != 0x061821C0u)) && ((return_key != 0x06182590u && return_key != 0x06182960u) && (return_key != 0x06182D30u && (return_key != 0x06183100u && return_key != 0x061834D0u)))) && (((return_key != 0x061838A0u && return_key != 0x06183C70u) && (return_key != 0x06185740u && return_key != 0x06186CF8u)) && ((return_key != 0x06186E70u && return_key != 0x06188080u) && (return_key != 0x061A0150u && (return_key != 0x061A05D0u && return_key != 0x061A1910u))))) && ((((return_key != 0x061ACC48u && return_key != 0x061AE4E8u) && (return_key != 0x061AEC00u && return_key != 0x061B20A8u)) && ((return_key != 0x061B2C88u && return_key != 0x061B2DB0u) && (return_key != 0x061B3020u && (return_key != 0x061B5760u && return_key != 0x061B7EE0u)))) && (((return_key != 0x061B7F80u && return_key != 0x061B86F0u) && (return_key != 0x061B8778u && (return_key != 0x061B8D08u && return_key != 0x061B9998u))) && ((return_key != 0x061BA350u && return_key != 0x061BA9F0u) && (return_key != 0x061BB1D8u && (return_key != 0x061BC9B0u && return_key != 0x061BCAF0u)))))))) && (((((((return_key != 0x061C00E8u && return_key != 0x061C0270u) && (return_key != 0x061C4480u && return_key != 0x061CC0F8u)) && ((return_key != 0x061CC2C8u && return_key != 0x061CC428u) && (return_key != 0x061CC690u && (return_key != 0x061CC798u && return_key != 0x061CC8A0u)))) && (((return_key != 0x061CE668u && return_key != 0x061DE330u) && (return_key != 0x062000D0u && return_key != 0x06200B48u)) && ((return_key != 0x06202D70u && return_key != 0x06205AF0u) && (return_key != 0x06206E60u && (return_key != 0x06207048u && return_key != 0x06207B08u))))) && ((((return_key != 0x06207CF8u && return_key != 0x06208D88u) && (return_key != 0x06209BA8u && return_key != 0x0620E208u)) && ((return_key != 0x062105D0u && return_key != 0x06213ED0u) && (return_key != 0x062144F0u && (return_key != 0x062151A8u && return_key != 0x06215FA8u)))) && (((return_key != 0x06216890u && return_key != 0x06216958u) && (return_key != 0x0621D408u && return_key != 0x0621DD38u)) && ((return_key != 0x0621E138u && return_key != 0x0621E638u) && (return_key != 0x0621EE28u && (return_key != 0x0621EEC8u && return_key != 0x0621EF68u)))))) && (((((return_key != 0x0621F598u && return_key != 0x0621F638u) && (return_key != 0x06220308u && return_key != 0x06222E08u)) && ((return_key != 0x062236C0u && return_key != 0x06224248u) && (return_key != 0x06224310u && (return_key != 0x0622E260u && return_key != 0x06232510u)))) && (((return_key != 0x06233670u && return_key != 0x06233890u) && (return_key != 0x0623C4E8u && return_key != 0x0623C5B0u)) && ((return_key != 0x0623D168u && return_key != 0x0623D618u) && (return_key != 0x0623D7C8u && (return_key != 0x0623DCF0u && return_key != 0x0623DDE8u))))) && ((((return_key != 0x0623E2A8u && return_key != 0x0623EB10u) && (return_key != 0x0623EBD8u && return_key != 0x0623FB60u)) && ((return_key != 0x0623FC28u && return_key != 0x062414F8u) && (return_key != 0x062487F0u && (return_key != 0x06248AE0u && return_key != 0x0624E250u)))) && (((return_key != 0x0625D588u && return_key != 0x06280A90u) && (return_key != 0x062813B0u && (return_key != 0x06281A28u && return_key != 0x06287498u))) && ((return_key != 0x0628A078u && return_key != 0x0628DE50u) && (return_key != 0x0628EAF8u && (return_key != 0x0628EC68u && return_key != 0x06295E90u))))))) && ((((((return_key != 0x06295F58u && return_key != 0x06296268u) && (return_key != 0x0629B380u && return_key != 0x0629B6B8u)) && ((return_key != 0x0629D938u && return_key != 0x062A6350u) && (return_key != 0x062A66D0u && (return_key != 0x062AAA90u && return_key != 0x062B3AF8u)))) && (((return_key != 0x062B3F10u && return_key != 0x062B4600u) && (return_key != 0x062BBAC8u && return_key != 0x062BC9D0u)) && ((return_key != 0x062BCE90u && return_key != 0x062C97B8u) && (return_key != 0x062C9880u && (return_key != 0x062CC3B8u && return_key != 0x062CC528u))))) && ((((return_key != 0x062D2448u && return_key != 0x062D37E0u) && (return_key != 0x062D3B40u && return_key != 0x062D5640u)) && ((return_key != 0x062D7838u && return_key != 0x062DE8C0u) && (return_key != 0x062DFCE0u && (return_key != 0x06308EC8u && return_key != 0x06308F90u)))) && (((return_key != 0x0630A0F8u && return_key != 0x0630A6A8u) && (return_key != 0x0630A938u && return_key != 0x0630AAF8u)) && ((return_key != 0x0630AD08u && return_key != 0x0630AFA8u) && (return_key != 0x0630B368u && (return_key != 0x0630B848u && return_key != 0x0630C2B0u)))))) && (((((return_key != 0x0630C518u && return_key != 0x0630D048u) && (return_key != 0x0630D470u && return_key != 0x06312F60u)) && ((return_key != 0x06314F98u && return_key != 0x063151E8u) && (return_key != 0x063153E0u && (return_key != 0x063161A8u && return_key != 0x06318598u)))) && (((return_key != 0x06319330u && return_key != 0x06319540u) && (return_key != 0x063197A8u && return_key != 0x0631C378u)) && ((return_key != 0x0631D720u && return_key != 0x0631F708u) && (return_key != 0x063202E8u && (return_key != 0x063208B8u && return_key != 0x06321370u))))) && ((((return_key != 0x06321C88u && return_key != 0x063229E0u) && (return_key != 0x063242C8u && return_key != 0x06324610u)) && ((return_key != 0x06324F98u && return_key != 0x06325CA8u) && (return_key != 0x06326390u && (return_key != 0x0632C290u && return_key != 0x0632C5C0u)))) && (((return_key != 0x0632D698u && return_key != 0x0632DC80u) && (return_key != 0x0632E270u && (return_key != 0x0632E860u && return_key != 0x0632ECB0u))) && ((return_key != 0x0632F118u && return_key != 0x0632F4C0u) && (return_key != 0x0632F830u && (return_key != 0x06330180u && return_key != 0x063303D8u))))))))) && ((((((((return_key != 0x06330720u && return_key != 0x063317C8u) && (return_key != 0x0633A010u && return_key != 0x0633A158u)) && ((return_key != 0x0633A238u && return_key != 0x0633D4B0u) && (return_key != 0x0633D9E8u && (return_key != 0x06341E28u && return_key != 0x06341F40u)))) && (((return_key != 0x06343790u && return_key != 0x06344790u) && (return_key != 0x06344FC0u && return_key != 0x06346BA8u)) && ((return_key != 0x063478D8u && return_key != 0x06349A38u) && (return_key != 0x0634B2B8u && (return_key != 0x0634C478u && return_key != 0x06354720u))))) && ((((return_key != 0x06354BA8u && return_key != 0x06355ED0u) && (return_key != 0x063567E8u && return_key != 0x06356BE0u)) && ((return_key != 0x06356EC8u && return_key != 0x06357260u) && (return_key != 0x06357548u && (return_key != 0x06357670u && return_key != 0x06357A08u)))) && (((return_key != 0x06357CF0u && return_key != 0x06357E18u) && (return_key != 0x06357F40u && return_key != 0x06358068u)) && ((return_key != 0x06358190u && return_key != 0x06358528u) && (return_key != 0x06358830u && (return_key != 0x06358BC8u && return_key != 0x06358F50u)))))) && (((((return_key != 0x06359078u && return_key != 0x063591A0u) && (return_key != 0x063592C8u && return_key != 0x063593F0u)) && ((return_key != 0x06359788u && return_key != 0x0635A358u) && (return_key != 0x06382600u && (return_key != 0x063828F0u && return_key != 0x06386BC0u)))) && (((return_key != 0x06389FE0u && return_key != 0x0638A750u) && (return_key != 0x0638A7E8u && return_key != 0x0638D5D0u)) && ((return_key != 0x0638D690u && return_key != 0x0638E770u) && (return_key != 0x0638FB58u && (return_key != 0x06392080u && return_key != 0x06393648u))))) && ((((return_key != 0x063936D0u && return_key != 0x06394468u) && (return_key != 0x06398320u && return_key != 0x06398DB0u)) && ((return_key != 0x06399CC0u && return_key != 0x0639A778u) && (return_key != 0x0639AE68u && (return_key != 0x0639B588u && return_key != 0x0639F540u)))) && (((return_key != 0x063A1FE0u && return_key != 0x063A49E0u) && (return_key != 0x063A6F78u && (return_key != 0x063AA1F0u && return_key != 0x063AF828u))) && ((return_key != 0x063B44F8u && return_key != 0x063B7FD0u) && (return_key != 0x063B80B0u && (return_key != 0x063B8AE0u && return_key != 0x063C2B18u))))))) && ((((((return_key != 0x063C81D0u && return_key != 0x063CC748u) && (return_key != 0x063CD188u && return_key != 0x063D7BC8u)) && ((return_key != 0x063DEE58u && return_key != 0x063DFA70u) && (return_key != 0x063E6CF8u && (return_key != 0x063E7690u && return_key != 0x063E8260u)))) && (((return_key != 0x063E88B0u && return_key != 0x063EC350u) && (return_key != 0x063EF2F8u && return_key != 0x063F0418u)) && ((return_key != 0x063F3D80u && return_key != 0x06423B58u) && (return_key != 0x06423FD0u && (return_key != 0x06424498u && return_key != 0x06437748u))))) && ((((return_key != 0x0643B1E0u && return_key != 0x0643CAB8u) && (return_key != 0x064840A0u && return_key != 0x06484390u)) && ((return_key != 0x06484B58u && return_key != 0x064856F8u) && (return_key != 0x0648AD78u && (return_key != 0x06495DF0u && return_key != 0x06497418u)))) && (((return_key != 0x0649ABE0u && return_key != 0x0649AEB8u) && (return_key != 0x0649D068u && return_key != 0x0649D558u)) && ((return_key != 0x064A08C8u && return_key != 0x064A5ED8u) && (return_key != 0x064A6950u && (return_key != 0x064A8248u && return_key != 0x064AEB58u)))))) && (((((return_key != 0x064B0D20u && return_key != 0x064B1570u) && (return_key != 0x064B59D8u && return_key != 0x064B6E60u)) && ((return_key != 0x064B70D0u && return_key != 0x064B75E0u) && (return_key != 0x064C9E50u && (return_key != 0x064CA7C0u && return_key != 0x064CE688u)))) && (((return_key != 0x064DE4A0u && return_key != 0x064DE8F8u) && (return_key != 0x064DF420u && return_key != 0x064E1550u)) && ((return_key != 0x064E5B10u && return_key != 0x064E6FA0u) && (return_key != 0x064EA7C8u && (return_key != 0x064F1650u && return_key != 0x064F1718u))))) && ((((return_key != 0x064F17E0u && return_key != 0x06504F88u) && (return_key != 0x06505DF0u && return_key != 0x065077C8u)) && ((return_key != 0x06507BD8u && return_key != 0x06507CD0u) && (return_key != 0x0650E868u && (return_key != 0x065114B8u && return_key != 0x065117E0u)))) && (((return_key != 0x065119A8u && return_key != 0x06511A28u) && (return_key != 0x06511AC0u && (return_key != 0x06511C08u && return_key != 0x06511C88u))) && ((return_key != 0x06520048u && return_key != 0x065291C8u) && (return_key != 0x0652F150u && (return_key != 0x06531068u && return_key != 0x06534660u)))))))) && (((((((return_key != 0x065354D8u && return_key != 0x06536318u) && (return_key != 0x065369F8u && return_key != 0x065376C0u)) && ((return_key != 0x06542CC8u && return_key != 0x0654AB58u) && (return_key != 0x0654D498u && (return_key != 0x0654DFD0u && return_key != 0x0654E130u)))) && (((return_key != 0x06581928u && return_key != 0x06604D70u) && (return_key != 0x06607E78u && return_key != 0x06609440u)) && ((return_key != 0x06609588u && return_key != 0x0660A130u) && (return_key != 0x0660A278u && (return_key != 0x0660B048u && return_key != 0x0660B6B8u))))) && ((((return_key != 0x06611898u && return_key != 0x06611AA8u) && (return_key != 0x06619A40u && return_key != 0x0661B2F0u)) && ((return_key != 0x0661DC98u && return_key != 0x0661FBA8u) && (return_key != 0x06627250u && (return_key != 0x06627458u && return_key != 0x0662FAE8u)))) && (((return_key != 0x0662FFF8u && return_key != 0x06630808u) && (return_key != 0x06631628u && return_key != 0x06634960u)) && ((return_key != 0x06635EA0u && return_key != 0x06637108u) && (return_key != 0x066371D0u && (return_key != 0x0663A118u && return_key != 0x066458F8u)))))) && (((((return_key != 0x06648C68u && return_key != 0x06652758u) && (return_key != 0x0665E8B0u && return_key != 0x0665EB18u)) && ((return_key != 0x0665ED20u && return_key != 0x0665EF28u) && (return_key != 0x066608B8u && (return_key != 0x06661BD8u && return_key != 0x066628C0u)))) && (((return_key != 0x06680390u && return_key != 0x066808B8u) && (return_key != 0x06681188u && return_key != 0x066816B0u)) && ((return_key != 0x066829B0u && return_key != 0x06683128u) && (return_key != 0x066838C8u && (return_key != 0x06689C48u && return_key != 0x06689DF0u))))) && ((((return_key != 0x0668BA28u && return_key != 0x0668BE38u) && (return_key != 0x0668F998u && return_key != 0x066907D0u)) && ((return_key != 0x066955A8u && return_key != 0x06696890u) && (return_key != 0x06696F30u && (return_key != 0x066978A8u && return_key != 0x06698300u)))) && (((return_key != 0x06698C00u && return_key != 0x06698EF8u) && (return_key != 0x06699250u && (return_key != 0x06699610u && return_key != 0x06699B78u))) && ((return_key != 0x0669A118u && return_key != 0x0669A730u) && (return_key != 0x0669ADA0u && (return_key != 0x0669D2A0u && return_key != 0x0669D5C8u))))))) && ((((((return_key != 0x0669DBB8u && return_key != 0x0669DC80u) && (return_key != 0x066A3FD8u && return_key != 0x066A4B50u)) && ((return_key != 0x066A50D0u && return_key != 0x066A9868u) && (return_key != 0x066AA6B0u && (return_key != 0x066ACE48u && return_key != 0x066ADEB8u)))) && (((return_key != 0x066AE688u && return_key != 0x066AF8B8u) && (return_key != 0x066AFF70u && return_key != 0x066B1B08u)) && ((return_key != 0x066B2F48u && return_key != 0x066B3010u) && (return_key != 0x066B5A80u && (return_key != 0x066B5BC0u && return_key != 0x066B7188u))))) && ((((return_key != 0x066BB538u && return_key != 0x066BD820u) && (return_key != 0x066BDB18u && return_key != 0x066BE0D0u)) && ((return_key != 0x066BE3B0u && return_key != 0x066C0908u) && (return_key != 0x066C0D70u && (return_key != 0x066C1980u && return_key != 0x066C2238u)))) && (((return_key != 0x066C2340u && return_key != 0x066C2FC0u) && (return_key != 0x066C3300u && return_key != 0x066C68F0u)) && ((return_key != 0x066C6BC0u && return_key != 0x066C6FC8u) && (return_key != 0x066C7310u && (return_key != 0x066C77A0u && return_key != 0x066C7860u)))))) && (((((return_key != 0x066C7E30u && return_key != 0x066C8C70u) && (return_key != 0x066CAB50u && return_key != 0x066CB368u)) && ((return_key != 0x066CB3F0u && return_key != 0x066CB720u) && (return_key != 0x066CB7E0u && (return_key != 0x066CBF28u && return_key != 0x066CCDB0u)))) && (((return_key != 0x066CDBB0u && return_key != 0x066CDD50u) && (return_key != 0x066CE250u && return_key != 0x066D0B70u)) && ((return_key != 0x066D1010u && return_key != 0x066D1528u) && (return_key != 0x066D1EF0u && (return_key != 0x066D4400u && return_key != 0x066D6410u))))) && ((((return_key != 0x066D7B50u && return_key != 0x066D9018u) && (return_key != 0x066DA818u && return_key != 0x066DC4E8u)) && ((return_key != 0x066DEE08u && return_key != 0x066DF6A8u) && (return_key != 0x066E0810u && (return_key != 0x066E08D0u && return_key != 0x066E1990u)))) && (((return_key != 0x066E2198u && return_key != 0x066E2398u) && (return_key != 0x066E4B70u && (return_key != 0x06701B48u && return_key != 0x067097B0u))) && ((return_key != 0x067166C8u && return_key != 0x06717008u) && (return_key != 0x06726B00u && (return_key != 0x06727040u && return_key != 0x06727A80u)))))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FF5C0u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0xD4u, 0xFEu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEB8u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFEu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xBBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFED4u;
            if (nh_scpu_expect_next(cpu, 0x060FF6A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060FF5E0u: {
            static const uint8_t expected_epoch[] = { 0x90u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEBCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFEBFu;
                if (nh_scpu_expect_next(cpu, 0x060FF5F8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEBEu;
            if (nh_scpu_expect_next(cpu, 0x060FF5F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF5F0u: {
            static const uint8_t expected_epoch[] = { 0xC8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEBEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEBFu;
            if (nh_scpu_expect_next(cpu, 0x060FF5F8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF5F8u: {
            static const uint8_t expected_epoch[] = { 0x84u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEBFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->y) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->y >> 8)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEC1u;
            if (nh_scpu_expect_next(cpu, 0x060FF608u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF608u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEC1u,
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
            if (((((return_key != 0x060FAAC0u && return_key != 0x060FABD0u) && (return_key != 0x061BA8E8u && return_key != 0x062A86C0u)) && ((return_key != 0x062DA428u && return_key != 0x062DA730u) && (return_key != 0x06310488u && return_key != 0x064C3A40u))) && (((return_key != 0x065368F0u && return_key != 0x0662ABB0u) && (return_key != 0x0665BD80u && return_key != 0x0665C4C8u)) && ((return_key != 0x0665CC10u && return_key != 0x0665D358u) && (return_key != 0x0665DAA0u && return_key != 0x06666FA0u)))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FF610u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEC2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEC5u;
            if (nh_scpu_expect_next(cpu, 0x060FF628u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FF628u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEC5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEC6u;
            if (nh_scpu_expect_next(cpu, 0x060FF630u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF630u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEC6u,
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
            cpu->pc = 0xFEC8u;
            if (nh_scpu_expect_next(cpu, 0x060FF640u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF640u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEC8u,
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
            cpu->pc = 0xFECAu;
            if (nh_scpu_expect_next(cpu, 0x060FF650u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF650u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FECAu,
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
            if (((return_key != 0x060FEFB0u && return_key != 0x060FF0B0u) && (return_key != 0x060FF490u && return_key != 0x060FF590u)))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FF658u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FECBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFECEu;
            if (nh_scpu_expect_next(cpu, 0x060FF670u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FF670u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FECEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFECFu;
            if (nh_scpu_expect_next(cpu, 0x060FF678u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF678u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FECFu,
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
            cpu->pc = 0xFED1u;
            if (nh_scpu_expect_next(cpu, 0x060FF688u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF688u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FED1u,
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
            cpu->pc = 0xFED3u;
            if (nh_scpu_expect_next(cpu, 0x060FF698u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF698u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FED3u,
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
            if (((return_key != 0x060FF150u && return_key != 0x060FF250u) && (return_key != 0x060FF2F0u && return_key != 0x060FF3F0u)))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FF6A0u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FED4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFED7u;
            if (nh_scpu_expect_next(cpu, 0x060FF6B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FF6B8u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FED7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFED8u;
            if (nh_scpu_expect_next(cpu, 0x060FF6C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF6C0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FED8u,
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
            cpu->pc = 0xFEDAu;
            if (nh_scpu_expect_next(cpu, 0x060FF6D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF6D0u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEDAu,
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
            cpu->pc = 0xFEDCu;
            if (nh_scpu_expect_next(cpu, 0x060FF6E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF6E0u: {
            static const uint8_t expected_epoch[] = { 0x84u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEDCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->y) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->y >> 8)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEDEu;
            if (nh_scpu_expect_next(cpu, 0x060FF6F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF6F0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEDEu,
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
            cpu->pc = 0xFEE0u;
            if (nh_scpu_expect_next(cpu, 0x060FF700u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF700u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEE0u,
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
            cpu->pc = 0xFEE2u;
            if (nh_scpu_expect_next(cpu, 0x060FF710u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF710u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEE2u,
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
            if ((return_key != 0x060FF030u && (return_key != 0x060FF510u && return_key != 0x060FF5E0u)))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FF718u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEE3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEE6u;
            if (nh_scpu_expect_next(cpu, 0x060FF730u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FF730u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEE6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEE7u;
            if (nh_scpu_expect_next(cpu, 0x060FF738u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF738u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEE7u,
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
            cpu->pc = 0xFEE9u;
            if (nh_scpu_expect_next(cpu, 0x060FF748u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF748u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEE9u,
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
            cpu->pc = 0xFEEBu;
            if (nh_scpu_expect_next(cpu, 0x060FF758u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF758u: {
            static const uint8_t expected_epoch[] = { 0x84u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEEBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->y) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->y >> 8)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEEDu;
            if (nh_scpu_expect_next(cpu, 0x060FF768u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF768u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEEDu,
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
            cpu->pc = 0xFEEFu;
            if (nh_scpu_expect_next(cpu, 0x060FF778u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF778u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEEFu,
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
            cpu->pc = 0xFEF1u;
            if (nh_scpu_expect_next(cpu, 0x060FF788u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF788u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEF1u,
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
            if ((return_key != 0x060FF1D0u && (return_key != 0x060FF370u && return_key != 0x060FF440u)))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FF790u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEF2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEF5u;
            if (nh_scpu_expect_next(cpu, 0x060FF7A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FF7A8u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEF5u,
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
            cpu->pc = 0xFEF7u;
            if (nh_scpu_expect_next(cpu, 0x060FF7B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF7B8u: {
            static const uint8_t expected_epoch[] = { 0x10u, 0x03u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEF7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFEFCu;
                if (nh_scpu_expect_next(cpu, 0x060FF7E0u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEF9u;
            if (nh_scpu_expect_next(cpu, 0x060FF7C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF7C8u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0xFFu, 0xFFu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEF9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0xFFFFu;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEFCu;
            if (nh_scpu_expect_next(cpu, 0x060FF7E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FF7E0u: {
            static const uint8_t expected_epoch[] = { 0x84u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEFCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), (uint8_t)cpu->y) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), (uint8_t)(cpu->y >> 8)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFEFEu;
            if (nh_scpu_expect_next(cpu, 0x060FF7F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF7F0u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FEFEu,
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
            if ((((((((return_key != 0x0608A978u && return_key != 0x060A0568u) && (return_key != 0x060A07D0u && return_key != 0x060A0850u)) && ((return_key != 0x060A0930u && return_key != 0x060A16B0u) && (return_key != 0x060A1788u && return_key != 0x060A2268u))) && (((return_key != 0x060A2340u && return_key != 0x060A25A8u) && (return_key != 0x060C49C0u && return_key != 0x060C4AF8u)) && ((return_key != 0x060C4FF8u && return_key != 0x060C50E8u) && (return_key != 0x0610F738u && (return_key != 0x0610FBB8u && return_key != 0x0610FD68u))))) && ((((return_key != 0x06146840u && return_key != 0x06147E58u) && (return_key != 0x061483A8u && return_key != 0x06148570u)) && ((return_key != 0x06148738u && return_key != 0x06149B70u) && (return_key != 0x06149C68u && return_key != 0x06149D18u))) && (((return_key != 0x06149DC0u && return_key != 0x0618E408u) && (return_key != 0x0618E488u && return_key != 0x0618E568u)) && ((return_key != 0x06283410u && return_key != 0x06292178u) && (return_key != 0x06292310u && (return_key != 0x06292618u && return_key != 0x062927B0u)))))) && (((((return_key != 0x06299BD0u && return_key != 0x06299C50u) && (return_key != 0x06299D30u && return_key != 0x062A7838u)) && ((return_key != 0x062A8668u && return_key != 0x062BD2A8u) && (return_key != 0x062C84B0u && return_key != 0x062C8880u))) && (((return_key != 0x063035D8u && return_key != 0x06336B98u) && (return_key != 0x06337158u && return_key != 0x06337318u)) && ((return_key != 0x063459C0u && return_key != 0x06345A40u) && (return_key != 0x063461D0u && (return_key != 0x0634E220u && return_key != 0x0634E4F0u))))) && ((((return_key != 0x06351FF0u && return_key != 0x063AFA30u) && (return_key != 0x063AFB28u && return_key != 0x063AFC40u)) && ((return_key != 0x063B0848u && return_key != 0x063B0DA8u) && (return_key != 0x063B22C0u && (return_key != 0x063B3238u && return_key != 0x063B3370u)))) && (((return_key != 0x063B3470u && return_key != 0x063B9EF0u) && (return_key != 0x063BD7E0u && return_key != 0x063D5DC0u)) && ((return_key != 0x063D84D8u && return_key != 0x063D8A18u) && (return_key != 0x063D9538u && (return_key != 0x063D9798u && return_key != 0x063DA4B8u))))))) && ((((((return_key != 0x063DA7D8u && return_key != 0x063DBA98u) && (return_key != 0x063DBD08u && return_key != 0x063DCC38u)) && ((return_key != 0x063E97F8u && return_key != 0x063EAE80u) && (return_key != 0x063F5490u && return_key != 0x063F56C8u))) && (((return_key != 0x063F94D0u && return_key != 0x063FA4A8u) && (return_key != 0x06400298u && return_key != 0x064003E0u)) && ((return_key != 0x064004E8u && return_key != 0x0640D480u) && (return_key != 0x0640D950u && (return_key != 0x06411798u && return_key != 0x064118E0u))))) && ((((return_key != 0x06414F28u && return_key != 0x064150B8u) && (return_key != 0x0641C118u && return_key != 0x0641C4C0u)) && ((return_key != 0x0641EF28u && return_key != 0x0641F150u) && (return_key != 0x0642B250u && (return_key != 0x0642B460u && return_key != 0x06431300u)))) && (((return_key != 0x064314E0u && return_key != 0x06437518u) && (return_key != 0x06480958u && return_key != 0x06480B78u)) && ((return_key != 0x06481280u && return_key != 0x06483878u) && (return_key != 0x06483EE8u && (return_key != 0x06484700u && return_key != 0x06489758u)))))) && (((((return_key != 0x06489830u && return_key != 0x06491F58u) && (return_key != 0x064ACD28u && return_key != 0x064ACEC8u)) && ((return_key != 0x064AD0B8u && return_key != 0x064AD2A8u) && (return_key != 0x064B6310u && return_key != 0x064C3018u))) && (((return_key != 0x064C34C8u && return_key != 0x064C39C0u) && (return_key != 0x064C3BE8u && return_key != 0x064C5220u)) && ((return_key != 0x064DC458u && return_key != 0x064DD750u) && (return_key != 0x064E4570u && (return_key != 0x064E9EB8u && return_key != 0x06512858u))))) && ((((return_key != 0x06513110u && return_key != 0x06524028u) && (return_key != 0x066836D8u && return_key != 0x066A6D70u)) && ((return_key != 0x066A6F90u && return_key != 0x066A8110u) && (return_key != 0x066A8330u && (return_key != 0x0670F038u && return_key != 0x0670F228u)))) && (((return_key != 0x0670F4D8u && return_key != 0x0670F780u) && (return_key != 0x067114F8u && return_key != 0x06711590u)) && ((return_key != 0x0671A888u && return_key != 0x0671AA30u) && (return_key != 0x0671AC90u && (return_key != 0x0671AE38u && return_key != 0x0671D920u)))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        default: return NH_SCPU_NOT_MINE;
    }
}
