/* Generated direct New Horizons S-CPU authority; do not edit. */
#include "nh_v07_generated.h"

NHScpuExecResult nh_v07_shard_00C1FF(NHScpuState *cpu, const NHScpuBus *bus) {
    switch (nh_scpu_context_key(cpu)) {
        case 0x060FF840u: {
            static const uint8_t expected_epoch[] = { 0xD4u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF08u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF0Au;
            if (nh_scpu_expect_next(cpu, 0x060FF850u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (6u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF850u: {
            static const uint8_t expected_epoch[] = { 0xD4u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF0Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000008u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF0Cu;
            if (nh_scpu_expect_next(cpu, 0x060FF860u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (6u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF860u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF0Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF0Eu;
            if (nh_scpu_expect_next(cpu, 0x060FF870u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF870u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF0Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000006u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000007u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF10u;
            if (nh_scpu_expect_next(cpu, 0x060FF880u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF880u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x6Cu, 0xFAu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF10u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFFu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x13u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFA6Cu;
            if (nh_scpu_expect_next(cpu, 0x060FD360u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060FF8A0u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF14u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF15u;
            if (nh_scpu_expect_next(cpu, 0x060FF8A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF8A8u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF15u,
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
            cpu->pc = 0xFF16u;
            if (nh_scpu_expect_next(cpu, 0x060FF8B0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FF8B0u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF16u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint16_t right, result;
            const uint16_t left = cpu->a;
            uint32_t sum;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
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
            cpu->pc = 0xFF18u;
            if (nh_scpu_expect_next(cpu, 0x060FF8C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF8C0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF18u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF1Au;
            if (nh_scpu_expect_next(cpu, 0x060FF8D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF8D0u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF1Au,
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
            cpu->pc = 0xFF1Bu;
            if (nh_scpu_expect_next(cpu, 0x060FF8D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FF8D8u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF1Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint16_t right, result;
            const uint16_t left = cpu->a;
            uint32_t sum;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
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
            cpu->pc = 0xFF1Du;
            if (nh_scpu_expect_next(cpu, 0x060FF8E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF8E8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF1Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF1Fu;
            if (nh_scpu_expect_next(cpu, 0x060FF8F8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF8F8u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF1Fu,
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
            if ((((((((((return_key != 0x060826F8u && (return_key != 0x0608BA10u && return_key != 0x0608BCB0u)) && ((return_key != 0x0608BF20u && return_key != 0x0608C1C0u) && (return_key != 0x0608C510u && return_key != 0x0608C780u))) && ((return_key != 0x0608CA20u && (return_key != 0x0608CC90u && return_key != 0x0608D4F8u)) && ((return_key != 0x0608D798u && return_key != 0x0608DAE8u) && (return_key != 0x0608DD58u && return_key != 0x0608DF28u)))) && (((return_key != 0x0608E370u && (return_key != 0x06090CB0u && return_key != 0x06091100u)) && ((return_key != 0x06093928u && return_key != 0x06093D78u) && (return_key != 0x06098308u && return_key != 0x0609AD70u))) && ((return_key != 0x0609B298u && (return_key != 0x0609BC78u && return_key != 0x0609BFB8u)) && ((return_key != 0x0609E118u && return_key != 0x060A5568u) && (return_key != 0x060A5640u && return_key != 0x060A8040u))))) && ((((return_key != 0x060A90A0u && (return_key != 0x060AA270u && return_key != 0x060AC3B8u)) && ((return_key != 0x060B8490u && return_key != 0x060B8880u) && (return_key != 0x060B8B28u && return_key != 0x060B8F20u))) && ((return_key != 0x060B9500u && (return_key != 0x060B97C0u && return_key != 0x060B9A80u)) && ((return_key != 0x060B9CE8u && return_key != 0x060B9F78u) && (return_key != 0x060BA138u && return_key != 0x060BA508u)))) && (((return_key != 0x060BAB88u && (return_key != 0x060BAD60u && return_key != 0x060BB088u)) && ((return_key != 0x060BB248u && return_key != 0x060BB438u) && (return_key != 0x060BB9F8u && return_key != 0x060BBC28u))) && (((return_key != 0x060BC2D8u && return_key != 0x060D4ED8u) && (return_key != 0x060D4FE0u && return_key != 0x060D6FD8u)) && ((return_key != 0x060D70E0u && return_key != 0x060D7E40u) && (return_key != 0x060D7F48u && return_key != 0x060DCB70u)))))) && (((((return_key != 0x060E1810u && (return_key != 0x060E36D8u && return_key != 0x060E3920u)) && ((return_key != 0x060E3F38u && return_key != 0x060E71C8u) && (return_key != 0x060E86E0u && return_key != 0x060EAD48u))) && ((return_key != 0x060ED6A0u && (return_key != 0x06101548u && return_key != 0x06107FF0u)) && ((return_key != 0x06108370u && return_key != 0x06108C60u) && (return_key != 0x06108E88u && return_key != 0x061092A8u)))) && (((return_key != 0x0610A6E0u && (return_key != 0x0610B268u && return_key != 0x0610BA90u)) && ((return_key != 0x0610BCA0u && return_key != 0x0610CAA0u) && (return_key != 0x061153F8u && return_key != 0x06119FC0u))) && ((return_key != 0x0611A3C0u && (return_key != 0x0612C6E8u && return_key != 0x0612F3C8u)) && ((return_key != 0x0612F4B8u && return_key != 0x06130350u) && (return_key != 0x06130440u && return_key != 0x06135560u))))) && ((((return_key != 0x06135720u && (return_key != 0x06135828u && return_key != 0x061359B0u)) && ((return_key != 0x06135AA0u && return_key != 0x06135C28u) && (return_key != 0x06135D30u && return_key != 0x06136658u))) && ((return_key != 0x06136748u && (return_key != 0x06136858u && return_key != 0x06136968u)) && ((return_key != 0x06136A78u && return_key != 0x061398D8u) && (return_key != 0x0613B550u && return_key != 0x0613C4D0u)))) && (((return_key != 0x0613E2D8u && (return_key != 0x0613E648u && return_key != 0x0613E798u)) && ((return_key != 0x0613E8D0u && return_key != 0x0613FCE8u) && (return_key != 0x06142640u && return_key != 0x06155A60u))) && (((return_key != 0x06157748u && return_key != 0x06158638u) && (return_key != 0x06158890u && return_key != 0x061589F8u)) && ((return_key != 0x06158B78u && return_key != 0x06158C90u) && (return_key != 0x0615B370u && return_key != 0x061886B8u))))))) && ((((((return_key != 0x0618D6F0u && (return_key != 0x0618DC18u && return_key != 0x0618DFA0u)) && ((return_key != 0x0618F5D0u && return_key != 0x06190590u) && (return_key != 0x06190760u && return_key != 0x06190868u))) && ((return_key != 0x06190998u && (return_key != 0x06190AC0u && return_key != 0x06190CB0u)) && ((return_key != 0x06191720u && return_key != 0x061924B8u) && (return_key != 0x061925D0u && return_key != 0x06194CA0u)))) && (((return_key != 0x06195338u && (return_key != 0x06195750u && return_key != 0x061BBB50u)) && ((return_key != 0x061BC4A8u && return_key != 0x061BC588u) && (return_key != 0x061BC678u && return_key != 0x061BC768u))) && ((return_key != 0x061BC858u && (return_key != 0x061BCCA0u && return_key != 0x061BCE48u)) && ((return_key != 0x061BCFA8u && return_key != 0x061BD678u) && (return_key != 0x061BDCD8u && return_key != 0x061BDEB8u))))) && ((((return_key != 0x061BDFA8u && (return_key != 0x061BE1A0u && return_key != 0x061BE290u)) && ((return_key != 0x061BE778u && return_key != 0x061BE888u) && (return_key != 0x061BEB40u && return_key != 0x061BED58u))) && ((return_key != 0x061BF980u && (return_key != 0x061BFA68u && return_key != 0x061BFB70u)) && ((return_key != 0x061BFC78u && return_key != 0x061C1908u) && (return_key != 0x061CE0E8u && return_key != 0x061DEBE0u)))) && (((return_key != 0x06200620u && (return_key != 0x06202FE0u && return_key != 0x06203130u)) && ((return_key != 0x06203338u && return_key != 0x06203EB8u) && (return_key != 0x06204008u && return_key != 0x06204410u))) && (((return_key != 0x06204830u && return_key != 0x06204980u) && (return_key != 0x06204B00u && return_key != 0x06204C78u)) && ((return_key != 0x06204DB0u && return_key != 0x06204EC8u) && (return_key != 0x06205088u && return_key != 0x06205198u)))))) && (((((return_key != 0x062052E8u && (return_key != 0x06205460u && return_key != 0x06205558u)) && ((return_key != 0x06205BE0u && return_key != 0x06205CD8u) && (return_key != 0x06205ED0u && return_key != 0x06206010u))) && ((return_key != 0x06206F50u && (return_key != 0x06207138u && return_key != 0x06207268u)) && ((return_key != 0x06207398u && return_key != 0x06208C00u) && (return_key != 0x06208E78u && return_key != 0x06208F80u)))) && (((return_key != 0x062090A8u && (return_key != 0x06209220u && return_key != 0x06209350u)) && ((return_key != 0x062095B0u && return_key != 0x0620A7B0u) && (return_key != 0x0620A9A0u && return_key != 0x0620BB08u))) && ((return_key != 0x0620BC30u && (return_key != 0x0620BD28u && return_key != 0x0620BF20u)) && ((return_key != 0x0620C798u && return_key != 0x0620C890u) && (return_key != 0x0620C9C0u && return_key != 0x0620D5C8u))))) && ((((return_key != 0x0620D798u && (return_key != 0x0620D8F0u && return_key != 0x0620E5B0u)) && ((return_key != 0x0620E958u && return_key != 0x06213430u) && (return_key != 0x06213720u && return_key != 0x06214A88u))) && ((return_key != 0x06214E80u && (return_key != 0x06215340u && return_key != 0x06215A90u)) && ((return_key != 0x062164C8u && return_key != 0x06217A68u) && (return_key != 0x06217CE0u && return_key != 0x06217F48u)))) && (((return_key != 0x062181B8u && (return_key != 0x062183F8u && return_key != 0x062184F0u)) && ((return_key != 0x06218750u && return_key != 0x062188A0u) && (return_key != 0x06218B30u && return_key != 0x06219130u))) && (((return_key != 0x06219390u && return_key != 0x062194C0u) && (return_key != 0x062195D8u && return_key != 0x06219F78u)) && ((return_key != 0x0621A518u && return_key != 0x0621A730u) && (return_key != 0x0621A880u && return_key != 0x0621AA00u)))))))) && (((((((return_key != 0x0621AB40u && (return_key != 0x0621DF38u && return_key != 0x0621E360u)) && ((return_key != 0x0621F340u && return_key != 0x0621F9E8u) && (return_key != 0x062200B0u && return_key != 0x062206A0u))) && ((return_key != 0x06220C80u && (return_key != 0x06221090u && return_key != 0x062225E8u)) && ((return_key != 0x062229E0u && return_key != 0x06222F50u) && (return_key != 0x062237B0u && return_key != 0x06223CC0u)))) && (((return_key != 0x06225448u && (return_key != 0x06225710u && return_key != 0x06225820u)) && ((return_key != 0x06225A10u && return_key != 0x06225B08u) && (return_key != 0x06225C18u && return_key != 0x0622A1B8u))) && ((return_key != 0x0622A308u && (return_key != 0x0622A510u && return_key != 0x0622B060u)) && ((return_key != 0x0622B1B0u && return_key != 0x0622B9C0u) && (return_key != 0x0622BB10u && return_key != 0x0622BF18u))))) && ((((return_key != 0x0622C878u && (return_key != 0x0622E350u && return_key != 0x0622E440u)) && ((return_key != 0x0622F148u && return_key != 0x0622F240u) && (return_key != 0x0622FCE8u && return_key != 0x06234798u))) && ((return_key != 0x06234890u && (return_key != 0x062349D8u && return_key != 0x06234BF8u)) && ((return_key != 0x06234EF8u && return_key != 0x0623A750u) && (return_key != 0x0623BD08u && return_key != 0x06240C48u)))) && (((return_key != 0x06258678u && (return_key != 0x06258C48u && return_key != 0x06259BE0u)) && ((return_key != 0x06259DF8u && return_key != 0x0625B198u) && (return_key != 0x062800E8u && return_key != 0x06288EF8u))) && (((return_key != 0x062890D0u && return_key != 0x0628BC48u) && (return_key != 0x0628C510u && return_key != 0x062900C8u)) && ((return_key != 0x06291A08u && return_key != 0x06294508u) && (return_key != 0x06294690u && return_key != 0x06294918u)))))) && (((((return_key != 0x0629BB88u && (return_key != 0x062A6820u && return_key != 0x062AC118u)) && ((return_key != 0x062AC710u && return_key != 0x062ACBB0u) && (return_key != 0x062AD910u && return_key != 0x062ADCD8u))) && ((return_key != 0x062ADEA0u && (return_key != 0x062AE0D0u && return_key != 0x062AE2A0u)) && ((return_key != 0x062AE420u && return_key != 0x062AE688u) && (return_key != 0x062AE850u && return_key != 0x062B3CE8u)))) && (((return_key != 0x062BD0F8u && (return_key != 0x062C1C30u && return_key != 0x062C1E00u)) && ((return_key != 0x062C4DA0u && return_key != 0x062D1950u) && (return_key != 0x062D1A50u && return_key != 0x062D3C50u))) && ((return_key != 0x062D3D50u && (return_key != 0x062D4560u && return_key != 0x062D5140u)) && ((return_key != 0x062D5ED0u && return_key != 0x062D8A48u) && (return_key != 0x062DD310u && return_key != 0x062DFE70u))))) && ((((return_key != 0x06305E20u && (return_key != 0x06305F48u && return_key != 0x063060E8u)) && ((return_key != 0x06306210u && return_key != 0x06306398u) && (return_key != 0x063069E0u && return_key != 0x06306AF0u))) && ((return_key != 0x06306C68u && (return_key != 0x06306DF8u && return_key != 0x06306F70u)) && ((return_key != 0x063070F0u && return_key != 0x06307B40u) && (return_key != 0x06307C50u && return_key != 0x06307E58u)))) && (((return_key != 0x06307FD0u && (return_key != 0x063081E0u && return_key != 0x06308308u)) && ((return_key != 0x063084B8u && return_key != 0x063085C0u) && (return_key != 0x06309C60u && return_key != 0x0630D138u))) && (((return_key != 0x0630EE00u && return_key != 0x0630F018u) && (return_key != 0x063116C8u && return_key != 0x06311820u)) && ((return_key != 0x063119A0u && return_key != 0x06311B10u) && (return_key != 0x06311D18u && return_key != 0x06311E50u))))))) && ((((((return_key != 0x06311FB0u && (return_key != 0x06312100u && return_key != 0x06313BF0u)) && ((return_key != 0x06314240u && return_key != 0x06317D88u) && (return_key != 0x0631A5A8u && return_key != 0x0631A6C8u))) && ((return_key != 0x0631A7C8u && (return_key != 0x0631A8E8u && return_key != 0x0631A9E8u)) && ((return_key != 0x0631AB20u && return_key != 0x0631ADF0u) && (return_key != 0x0631B558u && return_key != 0x0631BBC0u)))) && (((return_key != 0x0631E540u && (return_key != 0x0631EE38u && return_key != 0x06321760u)) && ((return_key != 0x06323278u && return_key != 0x063469A0u) && (return_key != 0x06346CA0u && return_key != 0x06346DF8u))) && ((return_key != 0x06346F58u && (return_key != 0x06347050u && return_key != 0x06347188u)) && ((return_key != 0x06347280u && return_key != 0x063473D0u) && (return_key != 0x063474C8u && return_key != 0x063476C0u))))) && ((((return_key != 0x063477B0u && (return_key != 0x063493A8u && return_key != 0x06349510u)) && ((return_key != 0x06349648u && return_key != 0x06349780u) && (return_key != 0x06349870u && return_key != 0x06349968u))) && ((return_key != 0x06349B10u && (return_key != 0x06349BF8u && return_key != 0x06349D50u)) && ((return_key != 0x0634A1D8u && return_key != 0x0634A2C8u) && (return_key != 0x0634AB98u && return_key != 0x0634AC88u)))) && (((return_key != 0x0634AD78u && (return_key != 0x0634B008u && return_key != 0x0634B7B0u)) && ((return_key != 0x0634B898u && return_key != 0x0634BA78u) && (return_key != 0x0634BB68u && return_key != 0x0634BC88u))) && (((return_key != 0x0634BDA8u && return_key != 0x0634BF58u) && (return_key != 0x0634C1C8u && return_key != 0x0634C9F8u)) && ((return_key != 0x0634E110u && return_key != 0x0634E368u) && (return_key != 0x0634E638u && return_key != 0x0634E810u)))))) && (((((return_key != 0x0634EA30u && (return_key != 0x0634EBB8u && return_key != 0x0634EDB8u)) && ((return_key != 0x0634EFB8u && return_key != 0x0634F1B8u) && (return_key != 0x0634F3B8u && return_key != 0x0634F590u))) && ((return_key != 0x0634F768u && (return_key != 0x0634FC60u && return_key != 0x0634FEF8u)) && ((return_key != 0x063500C8u && return_key != 0x06350318u) && (return_key != 0x06350638u && return_key != 0x06350F40u)))) && (((return_key != 0x06351110u && (return_key != 0x06353878u && return_key != 0x06356678u)) && ((return_key != 0x0635BE00u && return_key != 0x0635D258u) && (return_key != 0x0635DAE8u && return_key != 0x0635E1E0u))) && (((return_key != 0x0635E700u && return_key != 0x0635EC48u) && (return_key != 0x0635F138u && return_key != 0x0635F5C8u)) && ((return_key != 0x0635F9E8u && return_key != 0x063603E0u) && (return_key != 0x06361110u && return_key != 0x063618E0u))))) && ((((return_key != 0x06362408u && (return_key != 0x06396AA0u && return_key != 0x0639F678u)) && ((return_key != 0x0639F850u && return_key != 0x063A3698u) && (return_key != 0x063A37A0u && return_key != 0x063A4AD0u))) && ((return_key != 0x063A4BE0u && (return_key != 0x063A51D0u && return_key != 0x063AA328u)) && ((return_key != 0x063AA500u && return_key != 0x063AB628u) && (return_key != 0x063AB828u && return_key != 0x063AD960u)))) && (((return_key != 0x063ADD90u && (return_key != 0x063B4058u && return_key != 0x063B5210u)) && ((return_key != 0x063B53B8u && return_key != 0x063B73D0u) && (return_key != 0x063B9088u && return_key != 0x063B9968u))) && (((return_key != 0x063BB370u && return_key != 0x063BB6F8u) && (return_key != 0x063BBA78u && return_key != 0x063BC160u)) && ((return_key != 0x063BF1A8u && return_key != 0x063C00B8u) && (return_key != 0x063C2F88u && return_key != 0x063C7880u))))))))) && ((((((((return_key != 0x063C99E0u && (return_key != 0x063CAD50u && return_key != 0x063CB1D8u)) && ((return_key != 0x063CC010u && return_key != 0x063CCC08u) && (return_key != 0x063CD858u && return_key != 0x063CDE40u))) && ((return_key != 0x063CDFD0u && (return_key != 0x063CE810u && return_key != 0x063CEDD0u)) && ((return_key != 0x063CF088u && return_key != 0x063CF340u) && (return_key != 0x063CF5F8u && return_key != 0x063CFE28u)))) && (((return_key != 0x063D2208u && (return_key != 0x063D24D8u && return_key != 0x063D2900u)) && ((return_key != 0x063D2CF0u && return_key != 0x063D32B8u) && (return_key != 0x063D47B8u && return_key != 0x063D4AC0u))) && ((return_key != 0x063D4E40u && (return_key != 0x063D51B0u && return_key != 0x063D7130u)) && ((return_key != 0x063D7838u && return_key != 0x063D7EC0u) && (return_key != 0x063D82E8u && return_key != 0x063DD3A0u))))) && ((((return_key != 0x063DDC10u && (return_key != 0x063DE078u && return_key != 0x063DEB10u)) && ((return_key != 0x063DFB88u && return_key != 0x063DFD80u) && (return_key != 0x063E9A00u && return_key != 0x063EB1F0u))) && ((return_key != 0x063EC5B0u && (return_key != 0x063EC9C8u && return_key != 0x063ED188u)) && ((return_key != 0x063EFDD8u && return_key != 0x063EFFB0u) && (return_key != 0x063F2198u && return_key != 0x063F6380u)))) && (((return_key != 0x063F9D50u && (return_key != 0x063FB4A8u && return_key != 0x0640FA08u)) && ((return_key != 0x0640FEA8u && return_key != 0x06417950u) && (return_key != 0x06419748u && return_key != 0x0641BE98u))) && (((return_key != 0x0641C660u && return_key != 0x0641FDB0u) && (return_key != 0x06422A18u && return_key != 0x064240C0u)) && ((return_key != 0x064241C8u && return_key != 0x06424958u) && (return_key != 0x06425CD8u && return_key != 0x064261F0u)))))) && (((((return_key != 0x06426E38u && (return_key != 0x06427410u && return_key != 0x06427550u)) && ((return_key != 0x06428008u && return_key != 0x06429030u) && (return_key != 0x0642A210u && return_key != 0x0642A3D8u))) && ((return_key != 0x0642A4D8u && (return_key != 0x0642A648u && return_key != 0x0642CD40u)) && ((return_key != 0x0642DA08u && return_key != 0x0642FF98u) && (return_key != 0x064316B8u && return_key != 0x06431978u)))) && (((return_key != 0x06431DB8u && (return_key != 0x06434048u && return_key != 0x06434708u)) && ((return_key != 0x06434F00u && return_key != 0x06435038u) && (return_key != 0x06437080u && return_key != 0x06437200u))) && ((return_key != 0x06439A78u && (return_key != 0x0643A540u && return_key != 0x0643A678u)) && ((return_key != 0x0643A9D0u && return_key != 0x0643B3A8u) && (return_key != 0x0643C328u && return_key != 0x0643CC80u))))) && ((((return_key != 0x0643DD90u && (return_key != 0x064869B0u && return_key != 0x06487CD8u)) && ((return_key != 0x0648BC68u && return_key != 0x0648CB20u) && (return_key != 0x0648D9A0u && return_key != 0x0648E130u))) && ((return_key != 0x0648E3E0u && (return_key != 0x06499520u && return_key != 0x0649AD58u)) && ((return_key != 0x0649B0A8u && return_key != 0x0649C298u) && (return_key != 0x064A5AF8u && return_key != 0x064A6388u)))) && (((return_key != 0x064A6598u && (return_key != 0x064A67C0u && return_key != 0x064A7B10u)) && ((return_key != 0x064AD5C0u && return_key != 0x064AD8C8u) && (return_key != 0x064B55D8u && return_key != 0x064C01C8u))) && (((return_key != 0x064C9FA0u && return_key != 0x064CA2A8u) && (return_key != 0x064CE0B8u && return_key != 0x064CE410u)) && ((return_key != 0x064CE7F8u && return_key != 0x064CEB20u) && (return_key != 0x064CEEB0u && return_key != 0x064D8DB8u))))))) && ((((((return_key != 0x064DEA18u && (return_key != 0x064DEBD8u && return_key != 0x064EA620u)) && ((return_key != 0x064EAF10u && return_key != 0x064EB1C0u) && (return_key != 0x064EBAD0u && return_key != 0x064EBF60u))) && ((return_key != 0x064EC660u && (return_key != 0x064EE208u && return_key != 0x064EE7F8u)) && ((return_key != 0x064EEF00u && return_key != 0x064EF638u) && (return_key != 0x06503638u && return_key != 0x06503728u)))) && (((return_key != 0x065040D8u && (return_key != 0x065041C8u && return_key != 0x06504990u)) && ((return_key != 0x06504AC0u && return_key != 0x065079A8u) && (return_key != 0x06507A98u && return_key != 0x0650F328u))) && ((return_key != 0x0650F470u && (return_key != 0x065145D0u && return_key != 0x065146D8u)) && ((return_key != 0x06515820u && return_key != 0x06515928u) && (return_key != 0x06519A38u && return_key != 0x06519B40u))))) && ((((return_key != 0x0651ACF0u && (return_key != 0x0651ADF8u && return_key != 0x0651DDF0u)) && ((return_key != 0x0651DFA0u && return_key != 0x0651FBD0u) && (return_key != 0x0651FCD8u && return_key != 0x0652AD80u))) && ((return_key != 0x0652E9E0u && (return_key != 0x0652EF10u && return_key != 0x0652F2E0u)) && ((return_key != 0x065308F8u && return_key != 0x06530E28u) && (return_key != 0x065311F8u && return_key != 0x06534B78u)))) && (((return_key != 0x06534CC0u && (return_key != 0x06534F70u && return_key != 0x06535668u)) && ((return_key != 0x065359C0u && return_key != 0x06537070u) && (return_key != 0x065377F8u && return_key != 0x065378E8u))) && (((return_key != 0x06537A90u && return_key != 0x06538008u) && (return_key != 0x065385A8u && return_key != 0x06538688u)) && ((return_key != 0x06538778u && return_key != 0x06538868u) && (return_key != 0x06538A20u && return_key != 0x06538BC8u)))))) && (((((return_key != 0x06538CB8u && (return_key != 0x06539258u && return_key != 0x06539360u)) && ((return_key != 0x06539488u && return_key != 0x065395B0u) && (return_key != 0x06539820u && return_key != 0x06539928u))) && ((return_key != 0x06539A50u && (return_key != 0x0653B288u && return_key != 0x0653B488u)) && ((return_key != 0x0653B5D0u && return_key != 0x0653B718u) && (return_key != 0x0653B860u && return_key != 0x0653B9A8u)))) && (((return_key != 0x0653BAF0u && (return_key != 0x0653BC38u && return_key != 0x0653BD80u)) && ((return_key != 0x0653BF98u && return_key != 0x0653C0A8u) && (return_key != 0x0653C268u && return_key != 0x0653C898u))) && (((return_key != 0x0653C990u && return_key != 0x0653CAA0u) && (return_key != 0x0653CBB0u && return_key != 0x0653CCC0u)) && ((return_key != 0x0653CDD0u && return_key != 0x0653CF60u) && (return_key != 0x0653D248u && return_key != 0x0653D330u))))) && ((((return_key != 0x0653D4D0u && (return_key != 0x0653D6B8u && return_key != 0x0653D7B0u)) && ((return_key != 0x0653D9B8u && return_key != 0x0653DAC8u) && (return_key != 0x0653DCD0u && return_key != 0x0653DDE0u))) && ((return_key != 0x0653DF48u && (return_key != 0x0653E190u && return_key != 0x0653E2F8u)) && ((return_key != 0x0653E6F0u && return_key != 0x0653E800u) && (return_key != 0x0653EA68u && return_key != 0x0653EB58u)))) && (((return_key != 0x0653F078u && (return_key != 0x0653F170u && return_key != 0x0653F2B8u)) && ((return_key != 0x0653F400u && return_key != 0x0653F548u) && (return_key != 0x0653F690u && return_key != 0x0653F7D8u))) && (((return_key != 0x0653F920u && return_key != 0x0653FB38u) && (return_key != 0x0653FC48u && return_key != 0x0653FDF8u)) && ((return_key != 0x06540358u && return_key != 0x06540450u) && (return_key != 0x06540598u && return_key != 0x065406A8u)))))))) && (((((((return_key != 0x065407B8u && (return_key != 0x06540900u && return_key != 0x06540A48u)) && ((return_key != 0x06540B90u && return_key != 0x06540CA0u) && (return_key != 0x06540E40u && return_key != 0x06541238u))) && ((return_key != 0x06541328u && (return_key != 0x06541458u && return_key != 0x06541550u)) && ((return_key != 0x06541698u && return_key != 0x065417E0u) && (return_key != 0x06541928u && return_key != 0x06541A70u)))) && (((return_key != 0x06541B80u && (return_key != 0x06541CC8u && return_key != 0x06541DD8u)) && ((return_key != 0x06541F20u && return_key != 0x06542030u) && (return_key != 0x065421B8u && return_key != 0x06543128u))) && ((return_key != 0x06543290u && (return_key != 0x06543710u && return_key != 0x065438F8u)) && ((return_key != 0x06543A30u && return_key != 0x06543D60u) && (return_key != 0x06544330u && return_key != 0x06544480u))))) && ((((return_key != 0x065445D0u && (return_key != 0x06544720u && return_key != 0x06544AA8u)) && ((return_key != 0x06544BB8u && return_key != 0x06545530u) && (return_key != 0x06545C10u && return_key != 0x06545D28u))) && ((return_key != 0x06545F70u && (return_key != 0x06546120u && return_key != 0x06546368u)) && ((return_key != 0x06546568u && return_key != 0x06546A80u) && (return_key != 0x06546F10u && return_key != 0x06546FF8u)))) && (((return_key != 0x065473C8u && (return_key != 0x06547750u && return_key != 0x06547968u)) && ((return_key != 0x06547A48u && return_key != 0x06547B38u) && (return_key != 0x06547C28u && return_key != 0x065487A8u))) && (((return_key != 0x06548D30u && return_key != 0x06548E50u) && (return_key != 0x06548F80u && return_key != 0x06549070u)) && ((return_key != 0x06549218u && return_key != 0x06549578u) && (return_key != 0x06549660u && return_key != 0x06549950u)))))) && (((((return_key != 0x06549A38u && (return_key != 0x06549FA8u && return_key != 0x0654A090u)) && ((return_key != 0x0654A488u && return_key != 0x0654B198u) && (return_key != 0x0654B3F8u && return_key != 0x0654BB68u))) && ((return_key != 0x0654C3E8u && (return_key != 0x0654C4D8u && return_key != 0x0654C5C8u)) && ((return_key != 0x0654C750u && return_key != 0x0654CAC8u) && (return_key != 0x0654CEE0u && return_key != 0x0654D588u)))) && (((return_key != 0x0654E220u && (return_key != 0x0654E450u && return_key != 0x0654E5C8u)) && ((return_key != 0x0654F3F0u && return_key != 0x0654F610u) && (return_key != 0x0654FBD8u && return_key != 0x065822F0u))) && ((return_key != 0x06582878u && (return_key != 0x06583500u && return_key != 0x06608198u)) && ((return_key != 0x066084E8u && return_key != 0x06608878u) && (return_key != 0x06608B98u && return_key != 0x06608EE8u))))) && ((((return_key != 0x06609278u && (return_key != 0x066096B0u && return_key != 0x066098F0u)) && ((return_key != 0x06609B10u && return_key != 0x0660B258u) && (return_key != 0x0660B368u && return_key != 0x0660B470u))) && ((return_key != 0x0660B570u && (return_key != 0x06610C08u && return_key != 0x06613670u)) && ((return_key != 0x06613F20u && return_key != 0x0661BB50u) && (return_key != 0x0661BE38u && return_key != 0x06620770u)))) && (((return_key != 0x06620878u && (return_key != 0x06620980u && return_key != 0x06620A70u)) && ((return_key != 0x06620B60u && return_key != 0x06620C50u) && (return_key != 0x0662E810u && return_key != 0x0662EA88u))) && (((return_key != 0x0662FC00u && return_key != 0x0662FD38u) && (return_key != 0x06630158u && return_key != 0x06630290u)) && ((return_key != 0x066308E0u && return_key != 0x066309C8u) && (return_key != 0x06630B20u && return_key != 0x06631CB0u))))))) && ((((((return_key != 0x06631D98u && (return_key != 0x06631E80u && return_key != 0x06631F68u)) && ((return_key != 0x066332E0u && return_key != 0x066333C8u) && (return_key != 0x06633508u && return_key != 0x06633688u))) && ((return_key != 0x06633780u && (return_key != 0x06633868u && return_key != 0x06633A50u)) && ((return_key != 0x06633B48u && return_key != 0x06633ED0u) && (return_key != 0x06633FB8u && return_key != 0x066340A0u)))) && (((return_key != 0x06634188u && (return_key != 0x06634348u && return_key != 0x06634430u)) && ((return_key != 0x06634518u && return_key != 0x06634600u) && (return_key != 0x066347D8u && return_key != 0x066348E8u))) && ((return_key != 0x06634A38u && (return_key != 0x06634B20u && return_key != 0x06634C98u)) && ((return_key != 0x06634D80u && return_key != 0x06634EC0u) && (return_key != 0x06634FD0u && return_key != 0x06635120u))))) && ((((return_key != 0x06635208u && (return_key != 0x06635380u && return_key != 0x06635468u)) && ((return_key != 0x066355A8u && return_key != 0x06635698u) && (return_key != 0x066357E8u && return_key != 0x066358D8u))) && ((return_key != 0x06635A20u && (return_key != 0x06635B10u && return_key != 0x06646D20u)) && ((return_key != 0x06647DA8u && return_key != 0x066488A0u) && (return_key != 0x066489A8u && return_key != 0x06648A98u)))) && (((return_key != 0x06648BA0u && (return_key != 0x0664EAF0u && return_key != 0x06652E70u)) && ((return_key != 0x06655DD0u && return_key != 0x0665F188u) && (return_key != 0x0665F438u && return_key != 0x0665F520u))) && (((return_key != 0x0665F678u && return_key != 0x0665F768u) && (return_key != 0x06660038u && return_key != 0x06660128u)) && ((return_key != 0x06660218u && return_key != 0x06660308u) && (return_key != 0x06660430u && return_key != 0x06660608u)))))) && (((((return_key != 0x06660DB0u && (return_key != 0x06660E98u && return_key != 0x06661078u)) && ((return_key != 0x06661168u && return_key != 0x06661258u) && (return_key != 0x06661348u && return_key != 0x06661438u))) && ((return_key != 0x06661528u && (return_key != 0x066616D8u && return_key != 0x06661928u)) && ((return_key != 0x0666A5E0u && return_key != 0x06681D28u) && (return_key != 0x0669FAF8u && return_key != 0x0669FC00u)))) && (((return_key != 0x066A1838u && (return_key != 0x066A1B50u && return_key != 0x066A1F00u)) && ((return_key != 0x066A2218u && return_key != 0x066A25E8u) && (return_key != 0x066A2900u && return_key != 0x066A2C38u))) && (((return_key != 0x066A2F50u && return_key != 0x066A3210u) && (return_key != 0x066A3878u && return_key != 0x066AD9A0u)) && ((return_key != 0x066AE7D8u && return_key != 0x066B2A60u) && (return_key != 0x066B6A50u && return_key != 0x066C14B0u))))) && ((((return_key != 0x066C3F28u && (return_key != 0x066C4238u && return_key != 0x066D9EF0u)) && ((return_key != 0x066DA908u && return_key != 0x066DC5D8u) && (return_key != 0x066E3C08u && return_key != 0x066E4160u))) && ((return_key != 0x06700F08u && (return_key != 0x067013E0u && return_key != 0x06701820u)) && ((return_key != 0x06702260u && return_key != 0x06702720u) && (return_key != 0x06706A78u && return_key != 0x06707600u)))) && (((return_key != 0x06707F38u && (return_key != 0x06710728u && return_key != 0x06711210u)) && ((return_key != 0x06716AD8u && return_key != 0x06716CA8u) && (return_key != 0x06717500u && return_key != 0x06717D20u))) && (((return_key != 0x067190C0u && return_key != 0x0671BA00u) && (return_key != 0x0671D750u && return_key != 0x067205B0u)) && ((return_key != 0x06721800u && return_key != 0x06722218u) && (return_key != 0x06723DD8u && return_key != 0x06726D68u)))))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FF900u: {
            static const uint8_t expected_epoch[] = { 0xD4u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF20u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF22u;
            if (nh_scpu_expect_next(cpu, 0x060FF910u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (6u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF910u: {
            static const uint8_t expected_epoch[] = { 0xD4u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF22u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000008u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF24u;
            if (nh_scpu_expect_next(cpu, 0x060FF920u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (6u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF920u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF24u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF26u;
            if (nh_scpu_expect_next(cpu, 0x060FF930u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF930u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF26u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000006u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000007u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF28u;
            if (nh_scpu_expect_next(cpu, 0x060FF940u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF940u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0xD4u, 0xFCu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF28u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFFu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x2Bu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFCD4u;
            if (nh_scpu_expect_next(cpu, 0x060FE6A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060FF960u: {
            static const uint8_t expected_epoch[] = { 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF2Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~NH_P_C);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF2Du;
            if (nh_scpu_expect_next(cpu, 0x060FF968u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FF968u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF2Du,
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
            cpu->pc = 0xFF2Eu;
            if (nh_scpu_expect_next(cpu, 0x060FF970u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FF970u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF2Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint16_t right, result;
            const uint16_t left = cpu->a;
            uint32_t sum;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
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
            cpu->pc = 0xFF30u;
            if (nh_scpu_expect_next(cpu, 0x060FF980u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF980u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF30u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF32u;
            if (nh_scpu_expect_next(cpu, 0x060FF990u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF990u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF32u,
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
            cpu->pc = 0xFF33u;
            if (nh_scpu_expect_next(cpu, 0x060FF998u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FF998u: {
            static const uint8_t expected_epoch[] = { 0x65u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF33u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            uint16_t right, result;
            const uint16_t left = cpu->a;
            uint32_t sum;
            if ((cpu->p & NH_P_D) != 0u)
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_DECIMAL_MODE");
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
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
            cpu->pc = 0xFF35u;
            if (nh_scpu_expect_next(cpu, 0x060FF9A8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF9A8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF35u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF37u;
            if (nh_scpu_expect_next(cpu, 0x060FF9B8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF9B8u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF37u,
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
            if ((((((((((return_key != 0x0608E608u && (return_key != 0x06098708u && return_key != 0x06099A10u)) && ((return_key != 0x0609A670u && return_key != 0x0609B0F8u) && (return_key != 0x0609B7A8u && return_key != 0x0609C598u))) && (((return_key != 0x0609DF60u && return_key != 0x0609FA88u) && (return_key != 0x060B19A8u && return_key != 0x060B1C30u)) && ((return_key != 0x060BCBA0u && return_key != 0x060C3B30u) && (return_key != 0x060C6588u && return_key != 0x060C6668u)))) && (((return_key != 0x060C67F8u && (return_key != 0x060C68E8u && return_key != 0x060C69F8u)) && ((return_key != 0x060CB3F0u && return_key != 0x060CB5D8u) && (return_key != 0x060CE910u && return_key != 0x060CEA78u))) && (((return_key != 0x060D1AA0u && return_key != 0x060D1BE0u) && (return_key != 0x060D2070u && return_key != 0x060D21D8u)) && ((return_key != 0x060D2E98u && return_key != 0x060D2FF0u) && (return_key != 0x060D3BC0u && return_key != 0x060D3EF8u))))) && ((((return_key != 0x060D4200u && (return_key != 0x060D44E8u && return_key != 0x060D4C18u)) && ((return_key != 0x060D4D80u && return_key != 0x060D5368u) && (return_key != 0x060D56C8u && return_key != 0x060D57E0u))) && (((return_key != 0x060D5AD8u && return_key != 0x060D6478u) && (return_key != 0x060D67E0u && return_key != 0x060D7B80u)) && ((return_key != 0x060D7CE8u && return_key != 0x060D82D0u) && (return_key != 0x060D96A8u && return_key != 0x060DA928u)))) && ((((return_key != 0x060DAE60u && return_key != 0x060DB1A0u) && (return_key != 0x060DBFC8u && return_key != 0x060DC560u)) && ((return_key != 0x060E4298u && return_key != 0x060E4378u) && (return_key != 0x060E4470u && return_key != 0x060E4640u))) && (((return_key != 0x060E4730u && return_key != 0x060E4840u) && (return_key != 0x060EB398u && return_key != 0x060EB500u)) && ((return_key != 0x060ECC48u && return_key != 0x060F24C0u) && (return_key != 0x060F25A0u && return_key != 0x060F2760u)))))) && (((((return_key != 0x060F28C0u && (return_key != 0x060F29A8u && return_key != 0x060F2AE8u)) && ((return_key != 0x060F2C70u && return_key != 0x060F2E28u) && (return_key != 0x060F2F68u && return_key != 0x06100B28u))) && (((return_key != 0x06100D30u && return_key != 0x06100E58u) && (return_key != 0x06100FE0u && return_key != 0x06101338u)) && ((return_key != 0x06101408u && return_key != 0x061043C8u) && (return_key != 0x06104498u && return_key != 0x061045A8u)))) && (((return_key != 0x06104818u && (return_key != 0x06104C60u && return_key != 0x06104E58u)) && ((return_key != 0x06104F68u && return_key != 0x061051D8u) && (return_key != 0x061094D0u && return_key != 0x06109600u))) && (((return_key != 0x0610A068u && return_key != 0x0610A160u) && (return_key != 0x0610A4C8u && return_key != 0x0610A5C0u)) && ((return_key != 0x0610B588u && return_key != 0x0610B680u) && (return_key != 0x061122E8u && return_key != 0x06112AD0u))))) && ((((return_key != 0x06113D08u && (return_key != 0x06115340u && return_key != 0x061176E0u)) && ((return_key != 0x0611C748u && return_key != 0x0611D670u) && (return_key != 0x061277B8u && return_key != 0x06127DA8u))) && (((return_key != 0x0612A8D8u && return_key != 0x0612A9F0u) && (return_key != 0x0612ADD0u && return_key != 0x0612AEE8u)) && ((return_key != 0x0612D858u && return_key != 0x0612D9E0u) && (return_key != 0x0612DBB0u && return_key != 0x0612DD70u)))) && ((((return_key != 0x0612E0F0u && return_key != 0x0612E248u) && (return_key != 0x0612E380u && return_key != 0x0612E500u)) && ((return_key != 0x0612ECA0u && return_key != 0x0612EE20u) && (return_key != 0x0612EF80u && return_key != 0x0612F128u))) && (((return_key != 0x0612F8C8u && return_key != 0x0612FA10u) && (return_key != 0x0612FAF8u && return_key != 0x0612FC40u)) && ((return_key != 0x0612FD40u && return_key != 0x0612FE88u) && (return_key != 0x0612FF88u && return_key != 0x061300D0u))))))) && ((((((return_key != 0x06130858u && (return_key != 0x061309A0u && return_key != 0x06130A88u)) && ((return_key != 0x06130BD0u && return_key != 0x06130CD0u) && (return_key != 0x06130E18u && return_key != 0x06130F18u))) && (((return_key != 0x06131060u && return_key != 0x06139B00u) && (return_key != 0x0613FA78u && return_key != 0x0613FDE8u)) && ((return_key != 0x06141CC8u && return_key != 0x06141E98u) && (return_key != 0x06142980u && return_key != 0x06142B48u)))) && (((return_key != 0x06142C30u && (return_key != 0x06142E60u && return_key != 0x06142F48u)) && ((return_key != 0x06143170u && return_key != 0x061432A0u) && (return_key != 0x06143890u && return_key != 0x061442B8u))) && (((return_key != 0x061465B0u && return_key != 0x061481B8u) && (return_key != 0x06148E18u && return_key != 0x0614C3B0u)) && ((return_key != 0x0614EDA0u && return_key != 0x0614EEE8u) && (return_key != 0x0614EFC0u && return_key != 0x0614F120u))))) && ((((return_key != 0x0614F208u && (return_key != 0x0614F7E8u && return_key != 0x0614F8F8u)) && ((return_key != 0x0614FA48u && return_key != 0x06150950u) && (return_key != 0x06150CA8u && return_key != 0x06150E08u))) && (((return_key != 0x06151008u && return_key != 0x06151478u) && (return_key != 0x061529D8u && return_key != 0x06153B90u)) && ((return_key != 0x06154B48u && return_key != 0x06154E88u) && (return_key != 0x06158500u && return_key != 0x06158748u)))) && ((((return_key != 0x06158F18u && return_key != 0x061593B8u) && (return_key != 0x06159658u && return_key != 0x06159828u)) && ((return_key != 0x06159AC0u && return_key != 0x06159F98u) && (return_key != 0x0615A118u && return_key != 0x06180ED8u))) && (((return_key != 0x0618FD48u && return_key != 0x06190BC8u) && (return_key != 0x06190E30u && return_key != 0x06191088u)) && ((return_key != 0x06191278u && return_key != 0x06191628u) && (return_key != 0x0619B878u && return_key != 0x061AA9E8u)))))) && (((((return_key != 0x061AAB60u && (return_key != 0x061B2000u && return_key != 0x061B3430u)) && ((return_key != 0x061B4470u && return_key != 0x061B98B8u) && (return_key != 0x061BD988u && return_key != 0x061BDB48u))) && (((return_key != 0x061BDDC8u && return_key != 0x061BE098u) && (return_key != 0x061BEC50u && return_key != 0x061BEE68u)) && ((return_key != 0x061BEFA0u && return_key != 0x061BF090u) && (return_key != 0x061C05E0u && return_key != 0x061C06C8u)))) && ((((return_key != 0x061C07C0u && return_key != 0x061C08C0u) && (return_key != 0x061C0A80u && return_key != 0x061C0B90u)) && ((return_key != 0x061C0CB8u && return_key != 0x061C0DC0u) && (return_key != 0x061C0EB8u && return_key != 0x061C0FD8u))) && (((return_key != 0x061C1A10u && return_key != 0x061C1B80u) && (return_key != 0x061C1C78u && return_key != 0x061C1E00u)) && ((return_key != 0x061C1FC0u && return_key != 0x061C20C8u) && (return_key != 0x061C22A8u && return_key != 0x061C23C8u))))) && ((((return_key != 0x061C26B8u && (return_key != 0x061C2818u && return_key != 0x061C29D8u)) && ((return_key != 0x061C2B38u && return_key != 0x061C2D50u) && (return_key != 0x061C2E90u && return_key != 0x061C3F98u))) && (((return_key != 0x061C40E0u && return_key != 0x061C4268u) && (return_key != 0x061C4368u && return_key != 0x061C4558u)) && ((return_key != 0x061CE758u && return_key != 0x061CE8B0u) && (return_key != 0x061CED68u && return_key != 0x061CEE58u)))) && ((((return_key != 0x061D3F50u && return_key != 0x061D4008u) && (return_key != 0x061D68E8u && return_key != 0x061D8248u)) && ((return_key != 0x061D9C38u && return_key != 0x061D9FA0u) && (return_key != 0x061DE5F0u && return_key != 0x061DE760u))) && (((return_key != 0x061DE838u && return_key != 0x061DE928u) && (return_key != 0x061DEDB8u && return_key != 0x061DEEE0u)) && ((return_key != 0x061DF260u && return_key != 0x061DF698u) && (return_key != 0x061DF7C0u && return_key != 0x061DFA00u)))))))) && (((((((return_key != 0x061DFC90u && (return_key != 0x061DFDB8u && return_key != 0x061DFFF8u)) && ((return_key != 0x061E04A0u && return_key != 0x061E0898u) && (return_key != 0x061E09E8u && return_key != 0x061E3F70u))) && (((return_key != 0x061E4EA0u && return_key != 0x06200A58u) && (return_key != 0x06201538u && return_key != 0x062016A0u)) && ((return_key != 0x06206210u && return_key != 0x06206368u) && (return_key != 0x06206858u && return_key != 0x06206958u)))) && (((return_key != 0x06207EB8u && (return_key != 0x06208010u && return_key != 0x06208658u)) && ((return_key != 0x062087B8u && return_key != 0x06208920u) && (return_key != 0x06208A58u && return_key != 0x06209F00u))) && (((return_key != 0x0620A058u && return_key != 0x0620A548u) && (return_key != 0x0620A648u && return_key != 0x0620AB98u)) && ((return_key != 0x0620ACF0u && return_key != 0x0620B338u) && (return_key != 0x0620B498u && return_key != 0x0620B600u))))) && ((((return_key != 0x0620B738u && (return_key != 0x0620B860u && return_key != 0x0620B960u)) && ((return_key != 0x0620C488u && return_key != 0x0620C588u) && (return_key != 0x0620CBC0u && return_key != 0x0620CD18u))) && (((return_key != 0x0620D3B8u && return_key != 0x0620D4B8u) && (return_key != 0x0620E330u && return_key != 0x06213B70u)) && ((return_key != 0x06213DE0u && return_key != 0x06214080u) && (return_key != 0x062141E8u && return_key != 0x062163F0u)))) && ((((return_key != 0x06217938u && return_key != 0x06217B90u) && (return_key != 0x06217E20u && return_key != 0x06218070u)) && ((return_key != 0x062182E0u && return_key != 0x06218618u) && (return_key != 0x06218A18u && return_key != 0x06219000u))) && (((return_key != 0x06219268u && return_key != 0x0621AFB0u) && (return_key != 0x0621B0F0u && return_key != 0x0621B578u)) && ((return_key != 0x0621B6C0u && return_key != 0x0621CDB0u) && (return_key != 0x0621CE88u && return_key != 0x0621CF70u)))))) && (((((return_key != 0x0621D028u && (return_key != 0x0621D318u && return_key != 0x0621D5B8u)) && ((return_key != 0x0621D720u && return_key != 0x0621E728u) && (return_key != 0x0621E840u && return_key != 0x0621ECC8u))) && (((return_key != 0x0621F0C8u && return_key != 0x0621F1B8u) && (return_key != 0x0621F798u && return_key != 0x0621F888u)) && ((return_key != 0x0621FCC8u && return_key != 0x0621FF50u) && (return_key != 0x06220548u && return_key != 0x06220B48u)))) && (((return_key != 0x06220F28u && (return_key != 0x062217B8u && return_key != 0x06221890u)) && ((return_key != 0x062219A0u && return_key != 0x06221AB8u) && (return_key != 0x06221B90u && return_key != 0x06221C78u))) && (((return_key != 0x06221D30u && return_key != 0x06221EA8u) && (return_key != 0x06221F60u && return_key != 0x062230C8u)) && ((return_key != 0x06223928u && return_key != 0x06224538u) && (return_key != 0x06225278u && return_key != 0x06225540u))))) && ((((return_key != 0x062265C8u && (return_key != 0x062266D8u && return_key != 0x06226858u)) && ((return_key != 0x06226958u && return_key != 0x06226AA8u) && (return_key != 0x06226BA8u && return_key != 0x06226CC0u))) && (((return_key != 0x06226DC0u && return_key != 0x0622E590u) && (return_key != 0x0622EB70u && return_key != 0x0622ECD0u)) && ((return_key != 0x0622EE38u && return_key != 0x0622EF70u) && (return_key != 0x0622F370u && return_key != 0x0622FAA0u)))) && ((((return_key != 0x0622FBA0u && return_key != 0x06230318u) && (return_key != 0x06233B58u && return_key != 0x06233C70u)) && ((return_key != 0x06233D78u && return_key != 0x06233EF0u) && (return_key != 0x06234038u && return_key != 0x06234230u))) && (((return_key != 0x06234338u && return_key != 0x062344F0u) && (return_key != 0x06234E00u && return_key != 0x06235260u)) && ((return_key != 0x062353B8u && return_key != 0x06235518u) && (return_key != 0x06235648u && return_key != 0x06236570u))))))) && ((((((return_key != 0x06236680u && (return_key != 0x06236770u && return_key != 0x062368D8u)) && ((return_key != 0x062369F0u && return_key != 0x06237DB8u) && (return_key != 0x06237EC8u && return_key != 0x06237FB8u))) && (((return_key != 0x0623BF90u && return_key != 0x0623C188u) && (return_key != 0x0623DAA0u && return_key != 0x0623DB78u)) && ((return_key != 0x0623DED0u && return_key != 0x0623DFB8u) && (return_key != 0x06241290u && return_key != 0x06243158u)))) && (((return_key != 0x0624DF28u && (return_key != 0x06258880u && return_key != 0x06258AD0u)) && ((return_key != 0x06258E48u && return_key != 0x062595C0u) && (return_key != 0x062598A0u && return_key != 0x06259A30u))) && (((return_key != 0x0625AF10u && return_key != 0x0625AFE0u) && (return_key != 0x0625B0E0u && return_key != 0x0625C880u)) && ((return_key != 0x0625CC88u && return_key != 0x0625E370u) && (return_key != 0x062804A0u && return_key != 0x06280630u))))) && ((((return_key != 0x06280870u && (return_key != 0x06280950u && return_key != 0x06280D38u)) && ((return_key != 0x06280E18u && return_key != 0x06280EF8u) && (return_key != 0x06281088u && return_key != 0x06281148u))) && (((return_key != 0x062812B8u && return_key != 0x06282010u) && (return_key != 0x06286BE0u && return_key != 0x06286F80u)) && ((return_key != 0x06287060u && return_key != 0x062894A8u) && (return_key != 0x06289910u && return_key != 0x062899F0u)))) && ((((return_key != 0x0628B230u && return_key != 0x0628B318u) && (return_key != 0x0628B4C0u && return_key != 0x0628B5A8u)) && ((return_key != 0x0628E298u && return_key != 0x0628E3A8u) && (return_key != 0x0628E4D0u && return_key != 0x0628E690u))) && (((return_key != 0x0628E760u && return_key != 0x0628EC08u) && (return_key != 0x0628EDC0u && return_key != 0x06292D90u)) && ((return_key != 0x06293310u && return_key != 0x06293430u) && (return_key != 0x062935C8u && return_key != 0x062942C8u)))))) && (((((return_key != 0x062950F8u && (return_key != 0x06295360u && return_key != 0x062977C0u)) && ((return_key != 0x062978D8u && return_key != 0x06298458u) && (return_key != 0x06299670u && return_key != 0x06299808u))) && (((return_key != 0x0629B790u && return_key != 0x0629C7C0u) && (return_key != 0x0629D188u && return_key != 0x0629DA28u)) && ((return_key != 0x0629DB08u && return_key != 0x0629DCA0u) && (return_key != 0x0629DD90u && return_key != 0x0629DEA0u)))) && ((((return_key != 0x0629E770u && return_key != 0x0629ECE0u) && (return_key != 0x062A1D48u && return_key != 0x062A1E58u)) && ((return_key != 0x062A2348u && return_key != 0x062A24D8u) && (return_key != 0x062A2EB8u && return_key != 0x062A3040u))) && (((return_key != 0x062A6420u && return_key != 0x062A6548u) && (return_key != 0x062B31B8u && return_key != 0x062B3300u)) && ((return_key != 0x062B3788u && return_key != 0x062B46F0u) && (return_key != 0x062B47D0u && return_key != 0x062B4988u))))) && ((((return_key != 0x062B4A78u && (return_key != 0x062B4B88u && return_key != 0x062B5F40u)) && ((return_key != 0x062B6138u && return_key != 0x062B7858u) && (return_key != 0x062BB918u && return_key != 0x062BBBB8u))) && (((return_key != 0x062BBC98u && return_key != 0x062BBE70u) && (return_key != 0x062BC040u && return_key != 0x062BEFC8u)) && ((return_key != 0x062C0AE8u && return_key != 0x062C1328u) && (return_key != 0x062C2130u && return_key != 0x062C2438u)))) && ((((return_key != 0x062CD3E8u && return_key != 0x062CEEC0u) && (return_key != 0x062D38D0u && return_key != 0x062D7C48u)) && ((return_key != 0x062D94F0u && return_key != 0x062D9A08u) && (return_key != 0x062D9F78u && return_key != 0x062DA0D0u))) && (((return_key != 0x062DCA28u && return_key != 0x062DCC70u) && (return_key != 0x062DD7A0u && return_key != 0x062DE9B0u)) && ((return_key != 0x062DEA90u && return_key != 0x062DEC30u) && (return_key != 0x062DED20u && return_key != 0x062DEE30u))))))))) && ((((((((return_key != 0x062E00B8u && (return_key != 0x062E0258u && return_key != 0x062E0398u)) && ((return_key != 0x062E1F38u && return_key != 0x062E2528u) && (return_key != 0x063071D8u && return_key != 0x06307328u))) && (((return_key != 0x063086A8u && return_key != 0x063087F8u) && (return_key != 0x06308B80u && return_key != 0x06309780u)) && ((return_key != 0x06309A68u && return_key != 0x0630A1D0u) && (return_key != 0x0630A3A8u && return_key != 0x0630A460u)))) && (((return_key != 0x0630ABC8u && (return_key != 0x0630AE38u && return_key != 0x0630B078u)) && ((return_key != 0x0630B178u && return_key != 0x0630B438u) && (return_key != 0x0630B538u && return_key != 0x0630BDA8u))) && (((return_key != 0x0630C380u && return_key != 0x0630C668u) && (return_key != 0x0630C750u && return_key != 0x0630D248u)) && ((return_key != 0x0630D560u && return_key != 0x0630E048u) && (return_key != 0x06313B20u && return_key != 0x06314A58u))))) && ((((return_key != 0x06314B60u && (return_key != 0x06314D18u && return_key != 0x06314E20u)) && ((return_key != 0x06317ED0u && return_key != 0x06318680u) && (return_key != 0x06318B18u && return_key != 0x06318BE8u))) && (((return_key != 0x063190E8u && return_key != 0x06319270u) && (return_key != 0x06319400u && return_key != 0x06319640u)) && ((return_key != 0x06319878u && return_key != 0x06319A80u) && (return_key != 0x06319B68u && return_key != 0x06319CA0u)))) && ((((return_key != 0x0631D810u && return_key != 0x0631D8F8u) && (return_key != 0x063203D8u && return_key != 0x063209A8u)) && ((return_key != 0x063219F8u && return_key != 0x06321B48u) && (return_key != 0x06321F70u && return_key != 0x063220A8u))) && (((return_key != 0x06323510u && return_key != 0x06323660u) && (return_key != 0x0632C4D0u && return_key != 0x0632C840u)) && ((return_key != 0x0632CAA8u && return_key != 0x0632D7E0u) && (return_key != 0x0632F940u && return_key != 0x063319F0u)))))) && (((((return_key != 0x0633A550u && (return_key != 0x063420A8u && return_key != 0x063475B0u)) && ((return_key != 0x063479B0u && return_key != 0x06347BD0u) && (return_key != 0x0634D368u && return_key != 0x0634D648u))) && (((return_key != 0x063542E0u && return_key != 0x063569F0u) && (return_key != 0x06357070u && return_key != 0x06357818u)) && ((return_key != 0x06358338u && return_key != 0x063589D8u) && (return_key != 0x06359598u && return_key != 0x06359E90u)))) && (((return_key != 0x0635A098u && (return_key != 0x0635A168u && return_key != 0x0635A270u)) && ((return_key != 0x0635A7E8u && return_key != 0x0635A9C8u) && (return_key != 0x0635AFD0u && return_key != 0x0635C460u))) && (((return_key != 0x0635D798u && return_key != 0x0635EF08u) && (return_key != 0x0635FE20u && return_key != 0x0635FF98u)) && ((return_key != 0x06360598u && return_key != 0x06360710u) && (return_key != 0x06361650u && return_key != 0x06380328u))))) && ((((return_key != 0x06380608u && (return_key != 0x063807C8u && return_key != 0x06380920u)) && ((return_key != 0x06380E48u && return_key != 0x063812F0u) && (return_key != 0x06381568u && return_key != 0x06381838u))) && (((return_key != 0x06381BC0u && return_key != 0x06382050u) && (return_key != 0x063824A0u && return_key != 0x063826E0u)) && ((return_key != 0x063827F0u && return_key != 0x063829C8u) && (return_key != 0x06383348u && return_key != 0x063837C0u)))) && ((((return_key != 0x06383AF0u && return_key != 0x06383CF8u) && (return_key != 0x06383E50u && return_key != 0x063841B8u)) && ((return_key != 0x063843C0u && return_key != 0x06384518u) && (return_key != 0x063851F0u && return_key != 0x06385AF0u))) && (((return_key != 0x063864D0u && return_key != 0x063868C0u) && (return_key != 0x06386F08u && return_key != 0x063872B8u)) && ((return_key != 0x063878B0u && return_key != 0x06387D58u) && (return_key != 0x063965D0u && return_key != 0x06396700u))))))) && ((((((return_key != 0x06397808u && (return_key != 0x06398500u && return_key != 0x06398618u)) && ((return_key != 0x06398708u && return_key != 0x0639A010u) && (return_key != 0x0639A110u && return_key != 0x0639AF38u))) && (((return_key != 0x0639C610u && return_key != 0x0639C7D8u) && (return_key != 0x0639CE60u && return_key != 0x0639CF70u)) && ((return_key != 0x0639D140u && return_key != 0x0639D250u) && (return_key != 0x0639D458u && return_key != 0x0639D5F0u)))) && (((return_key != 0x0639D878u && (return_key != 0x0639D988u && return_key != 0x0639DD68u)) && ((return_key != 0x063A14F0u && return_key != 0x063A15D8u) && (return_key != 0x063A17C0u && return_key != 0x063A18A8u))) && (((return_key != 0x063A1D28u && return_key != 0x063A1E00u) && (return_key != 0x063A2110u && return_key != 0x063A2210u)) && ((return_key != 0x063A33D8u && return_key != 0x063A3500u) && (return_key != 0x063B1978u && return_key != 0x063B1BB0u))))) && ((((return_key != 0x063B3110u && (return_key != 0x063C3718u && return_key != 0x063C43F0u)) && ((return_key != 0x063C4790u && return_key != 0x063C4C10u) && (return_key != 0x063C5928u && return_key != 0x063D3D68u))) && (((return_key != 0x063D5618u && return_key != 0x063D5728u) && (return_key != 0x063E5108u && return_key != 0x063E6A90u)) && ((return_key != 0x063E6BA8u && return_key != 0x063E6DE0u) && (return_key != 0x063E6FB0u && return_key != 0x063E7428u)))) && ((((return_key != 0x063E7540u && return_key != 0x063E7778u) && (return_key != 0x063E8100u && return_key != 0x063E83D0u)) && ((return_key != 0x063E8708u && return_key != 0x063E8A90u) && (return_key != 0x063E9058u && return_key != 0x063E93A8u))) && (((return_key != 0x063E9700u && return_key != 0x063E9948u) && (return_key != 0x063EA1E0u && return_key != 0x063EA658u)) && ((return_key != 0x063EABD8u && return_key != 0x063EAD30u) && (return_key != 0x063EB138u && return_key != 0x063EBE20u)))))) && (((((return_key != 0x063ECD70u && (return_key != 0x063ECFF8u && return_key != 0x063ED6B0u)) && ((return_key != 0x063EDA00u && return_key != 0x063EDD78u) && (return_key != 0x063EE068u && return_key != 0x063EE4E0u))) && (((return_key != 0x063EE758u && return_key != 0x063EE9D0u) && (return_key != 0x063EEC60u && return_key != 0x063EF1D8u)) && ((return_key != 0x063EF538u && return_key != 0x063F0210u) && (return_key != 0x063F1F30u && return_key != 0x06409ED8u)))) && ((((return_key != 0x0640A7B0u && return_key != 0x0640F908u) && (return_key != 0x0640FB78u && return_key != 0x0640FCA8u)) && ((return_key != 0x0640FD80u && return_key != 0x064100C0u) && (return_key != 0x064101C0u && return_key != 0x064102B8u))) && (((return_key != 0x064103C8u && return_key != 0x06410AB8u) && (return_key != 0x06410F98u && return_key != 0x064112A0u)) && ((return_key != 0x064114E8u && return_key != 0x064129F8u) && (return_key != 0x06413400u && return_key != 0x06413598u))))) && ((((return_key != 0x06413768u && (return_key != 0x06413BE0u && return_key != 0x06413E28u)) && ((return_key != 0x06414348u && return_key != 0x06414810u) && (return_key != 0x06416DB8u && return_key != 0x06417118u))) && (((return_key != 0x064171F8u && return_key != 0x06417308u) && (return_key != 0x06417470u && return_key != 0x064175A8u)) && ((return_key != 0x06417698u && return_key != 0x064177A8u) && (return_key != 0x06417898u && return_key != 0x06418BC8u)))) && ((((return_key != 0x06418E78u && return_key != 0x06418F50u) && (return_key != 0x064190C0u && return_key != 0x06419228u)) && ((return_key != 0x06419360u && return_key != 0x06419450u) && (return_key != 0x06419560u && return_key != 0x06419690u))) && (((return_key != 0x06419A60u && return_key != 0x06419B38u) && (return_key != 0x06419CB0u && return_key != 0x06419DE8u)) && ((return_key != 0x06419ED8u && return_key != 0x06419FE8u) && (return_key != 0x0641A710u && return_key != 0x0641A9A8u)))))))) && (((((((return_key != 0x0641B478u && (return_key != 0x0641B710u && return_key != 0x0641BFB0u)) && ((return_key != 0x0641C480u && return_key != 0x0641DAB8u) && (return_key != 0x0641E5D0u && return_key != 0x0641EB20u))) && (((return_key != 0x0641F520u && return_key != 0x06427168u) && (return_key != 0x06427908u && return_key != 0x0642AC80u)) && ((return_key != 0x0642B5C0u && return_key != 0x0642D258u) && (return_key != 0x0642D7A0u && return_key != 0x0642E2A8u)))) && (((return_key != 0x0642E410u && (return_key != 0x0642F168u && return_key != 0x06430B70u)) && ((return_key != 0x06430FE0u && return_key != 0x064310D8u) && (return_key != 0x064318C0u && return_key != 0x06431A78u))) && (((return_key != 0x06431D00u && return_key != 0x06431EB8u) && (return_key != 0x06482140u && return_key != 0x06482490u)) && ((return_key != 0x06482898u && return_key != 0x06482C50u) && (return_key != 0x06482E58u && return_key != 0x064831D8u))))) && ((((return_key != 0x06483380u && (return_key != 0x06483540u && return_key != 0x064836E8u)) && ((return_key != 0x064A2D68u && return_key != 0x064A2F38u) && (return_key != 0x064A3E08u && return_key != 0x064A4030u))) && (((return_key != 0x064A6498u && return_key != 0x064A66A8u) && (return_key != 0x064A6A88u && return_key != 0x064A6B98u)) && ((return_key != 0x064A6CD0u && return_key != 0x064A6DE0u) && (return_key != 0x064A80A8u && return_key != 0x064A9360u)))) && ((((return_key != 0x064A94B0u && return_key != 0x064A96B0u) && (return_key != 0x064A97A0u && return_key != 0x064AA590u)) && ((return_key != 0x064AA6E0u && return_key != 0x064ACAD8u) && (return_key != 0x064ADCC0u && return_key != 0x064ADFC8u))) && (((return_key != 0x064AF658u && return_key != 0x064AF7A0u) && (return_key != 0x064AF858u && return_key != 0x064B2A80u)) && ((return_key != 0x064B30F8u && return_key != 0x064B5930u) && (return_key != 0x064B7790u && return_key != 0x064B7958u)))))) && (((((return_key != 0x064B8B18u && (return_key != 0x064BFE38u && return_key != 0x064CF418u)) && ((return_key != 0x064DF510u && return_key != 0x064DFC78u) && (return_key != 0x064DFF48u && return_key != 0x064E12F8u))) && (((return_key != 0x064E4158u && return_key != 0x064E4378u) && (return_key != 0x064E5C00u && return_key != 0x064E5D28u)) && ((return_key != 0x064E7090u && return_key != 0x064E71B8u) && (return_key != 0x064E87B0u && return_key != 0x064E90B8u)))) && (((return_key != 0x064E9A40u && (return_key != 0x064F30D0u && return_key != 0x064F31E8u)) && ((return_key != 0x064F32D8u && return_key != 0x064F3408u) && (return_key != 0x064F3578u && return_key != 0x064F36F0u))) && (((return_key != 0x064F37F8u && return_key != 0x064F38D0u) && (return_key != 0x064F3DC8u && return_key != 0x064F3E98u)) && ((return_key != 0x064F40C0u && return_key != 0x064F4190u) && (return_key != 0x064F43B8u && return_key != 0x064F4488u))))) && ((((return_key != 0x064F46B0u && (return_key != 0x064F4780u && return_key != 0x064F4DC0u)) && ((return_key != 0x064F4F28u && return_key != 0x065002C8u) && (return_key != 0x065003A0u && return_key != 0x06500498u))) && (((return_key != 0x065006F0u && return_key != 0x065007E0u) && (return_key != 0x065008F0u && return_key != 0x06500A88u)) && ((return_key != 0x06500B68u && return_key != 0x06500C60u) && (return_key != 0x06500D50u && return_key != 0x06500E48u)))) && ((((return_key != 0x06500F58u && return_key != 0x06501138u) && (return_key != 0x06501300u && return_key != 0x065081E0u)) && ((return_key != 0x06514AD0u && return_key != 0x06519EB8u) && (return_key != 0x0651B0B8u && return_key != 0x0651E488u))) && (((return_key != 0x06521CA0u && return_key != 0x06521DF8u) && (return_key != 0x06529598u && return_key != 0x0652C2B0u)) && ((return_key != 0x0652C3F8u && return_key != 0x0652C618u) && (return_key != 0x0652C728u && return_key != 0x0652CB00u))))))) && ((((((return_key != 0x0652CC10u && (return_key != 0x0652D110u && return_key != 0x0652D2F8u)) && ((return_key != 0x0652D710u && return_key != 0x065353F8u) && (return_key != 0x06549E30u && return_key != 0x0654A9E8u))) && (((return_key != 0x0654AEC8u && return_key != 0x0660B7A0u) && (return_key != 0x0660B888u && return_key != 0x0660B958u)) && ((return_key != 0x0660BA78u && return_key != 0x0660BB68u) && (return_key != 0x0660C7B0u && return_key != 0x0660E368u)))) && (((return_key != 0x0660E8D8u && (return_key != 0x0660EA38u && return_key != 0x0660EE08u)) && ((return_key != 0x0660F678u && return_key != 0x0660FA28u) && (return_key != 0x06613208u && return_key != 0x06613528u))) && (((return_key != 0x06617298u && return_key != 0x066177B8u) && (return_key != 0x06617D68u && return_key != 0x06617FD0u)) && ((return_key != 0x0661A4F8u && return_key != 0x06631718u) && (return_key != 0x06631800u && return_key != 0x06631A38u))))) && ((((return_key != 0x06631B48u && (return_key != 0x06632238u && return_key != 0x06632630u)) && ((return_key != 0x06647188u && return_key != 0x066854B0u) && (return_key != 0x06689EE0u && return_key != 0x0668DBE8u))) && (((return_key != 0x066959C0u && return_key != 0x06695B28u) && (return_key != 0x06695D10u && return_key != 0x06695FE8u)) && ((return_key != 0x066A05A8u && return_key != 0x066A0760u) && (return_key != 0x066A08B8u && return_key != 0x066A0A10u)))) && ((((return_key != 0x066A1200u && return_key != 0x066ABBE0u) && (return_key != 0x066ABD90u && return_key != 0x066AF010u)) && ((return_key != 0x066AF158u && return_key != 0x066AFAB8u) && (return_key != 0x066B0060u && return_key != 0x066B0580u))) && (((return_key != 0x066B2628u && return_key != 0x066B3960u) && (return_key != 0x066B3B18u && return_key != 0x066B41F0u)) && ((return_key != 0x066B43E0u && return_key != 0x066B4848u) && (return_key != 0x066B4A40u && return_key != 0x066B60E0u)))))) && (((((return_key != 0x066B63C0u && (return_key != 0x066B64A8u && return_key != 0x066B6560u)) && ((return_key != 0x066B66A0u && return_key != 0x066B6758u) && (return_key != 0x066B6E10u && return_key != 0x066B6F20u))) && (((return_key != 0x066B7A28u && return_key != 0x066B7C20u) && (return_key != 0x066B7E40u && return_key != 0x066B7FE8u)) && ((return_key != 0x066B91A0u && return_key != 0x066B9378u) && (return_key != 0x066B9970u && return_key != 0x066C9F98u)))) && ((((return_key != 0x066CDCA0u && return_key != 0x066D44E8u) && (return_key != 0x066D45D0u && return_key != 0x066D4700u)) && ((return_key != 0x066D4858u && return_key != 0x066D4940u) && (return_key != 0x066D4A70u && return_key != 0x066D75A8u))) && (((return_key != 0x066D77B8u && return_key != 0x066D8568u) && (return_key != 0x066D9A38u && return_key != 0x066DA308u)) && ((return_key != 0x06709AD0u && return_key != 0x06709DA0u) && (return_key != 0x0670A030u && return_key != 0x06710CF0u))))) && ((((return_key != 0x06711C38u && (return_key != 0x06715310u && return_key != 0x067153E8u)) && ((return_key != 0x067154E0u && return_key != 0x06715658u) && (return_key != 0x06715748u && return_key != 0x06715858u))) && (((return_key != 0x06716820u && return_key != 0x06719918u) && (return_key != 0x06719C48u && return_key != 0x06719DA0u)) && ((return_key != 0x0671A2E8u && return_key != 0x0671A600u) && (return_key != 0x0671BDA8u && return_key != 0x0671BE88u)))) && ((((return_key != 0x0671BF80u && return_key != 0x0671C110u) && (return_key != 0x0671C200u && return_key != 0x0671C310u)) && ((return_key != 0x0671C448u && return_key != 0x0671CB50u) && (return_key != 0x0671CC60u && return_key != 0x0671CD78u))) && (((return_key != 0x0671CEE0u && return_key != 0x0671D480u) && (return_key != 0x06722BC0u && return_key != 0x06726C20u)) && ((return_key != 0x06727148u && return_key != 0x06727400u) && (return_key != 0x067276A0u && return_key != 0x06727B88u)))))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FF9C0u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF38u,
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
            cpu->pc = 0xFF39u;
            if (nh_scpu_expect_next(cpu, 0x060FF9C8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FF9C8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF39u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF3Bu;
            if (nh_scpu_expect_next(cpu, 0x060FF9D8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FF9D8u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF3Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF3Du;
            if (nh_scpu_expect_next(cpu, 0x060FF9EAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FF9EAu: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF3Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_pull8(cpu, bus, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF3Eu;
            if (nh_scpu_expect_next(cpu, 0x060FF9F2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060FF9F2u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF3Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000006u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF40u;
            if (nh_scpu_expect_next(cpu, 0x060FFA02u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FFA02u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF40u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF42u;
            if (nh_scpu_expect_next(cpu, 0x060FFA10u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FFA10u: {
            static const uint8_t expected_epoch[] = { 0xB5u, 0x22u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF42u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = ((uint32_t)cpu->d + 0x0022u + cpu->x) & 0xFFFFu;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, address, &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (address + 1u) & 0xFFFFu, &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(low | ((uint16_t)high << 8u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF44u;
            if (nh_scpu_expect_next(cpu, 0x060FFA20u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (5u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FFA20u: {
            static const uint8_t expected_epoch[] = { 0x48u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF44u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF45u;
            if (nh_scpu_expect_next(cpu, 0x060FFA28u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060FFA28u: {
            static const uint8_t expected_epoch[] = { 0xCAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF45u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(cpu->x - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF46u;
            if (nh_scpu_expect_next(cpu, 0x060FFA30u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FFA30u: {
            static const uint8_t expected_epoch[] = { 0xCAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF46u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(cpu->x - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF47u;
            if (nh_scpu_expect_next(cpu, 0x060FFA38u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FFA38u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0xF9u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF47u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFF42u;
                if (nh_scpu_expect_next(cpu, 0x060FFA10u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF49u;
            if (nh_scpu_expect_next(cpu, 0x060FFA48u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FFA48u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF49u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF4Bu;
            if (nh_scpu_expect_next(cpu, 0x060FFA5Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FFA5Au: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF4Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000006u) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF4Du;
            if (nh_scpu_expect_next(cpu, 0x060FFA6Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FFA6Au: {
            static const uint8_t expected_epoch[] = { 0x48u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF4Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF4Eu;
            if (nh_scpu_expect_next(cpu, 0x060FFA72u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FFA72u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF4Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF50u;
            if (nh_scpu_expect_next(cpu, 0x060FFA80u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FFA80u: {
            static const uint8_t expected_epoch[] = { 0xD4u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF50u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF52u;
            if (nh_scpu_expect_next(cpu, 0x060FFA90u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (6u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FFA90u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF52u,
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
            if ((((((((return_key != 0x06083B88u && return_key != 0x06084560u) && (return_key != 0x0609F308u && (return_key != 0x060AD3B0u && return_key != 0x060BA450u))) && ((return_key != 0x060BC9D8u && (return_key != 0x060C35E0u && return_key != 0x060CE800u)) && (return_key != 0x060D0348u && (return_key != 0x060D0E08u && return_key != 0x060D1F40u)))) && (((return_key != 0x060D8978u && (return_key != 0x060DC728u && return_key != 0x060DE560u)) && (return_key != 0x060E07E8u && (return_key != 0x060EB250u && return_key != 0x060EF178u))) && ((return_key != 0x060EFBA8u && (return_key != 0x06102690u && return_key != 0x061128C8u)) && (return_key != 0x06117438u && (return_key != 0x0611E8F0u && return_key != 0x06126430u))))) && ((((return_key != 0x0613A5A0u && return_key != 0x0613BBC8u) && (return_key != 0x0613DA00u && (return_key != 0x06152488u && return_key != 0x061535C8u))) && ((return_key != 0x06154718u && (return_key != 0x06184C88u && return_key != 0x061860C8u)) && (return_key != 0x06187AF8u && (return_key != 0x06189A98u && return_key != 0x0618A780u)))) && (((return_key != 0x0618B928u && (return_key != 0x0618BFD0u && return_key != 0x0618D4E8u)) && (return_key != 0x06193480u && (return_key != 0x061966A8u && return_key != 0x06198E68u))) && ((return_key != 0x0619C9B8u && (return_key != 0x0619D0E8u && return_key != 0x0619EBD8u)) && (return_key != 0x061A0370u && (return_key != 0x061ABA00u && return_key != 0x061B1B38u)))))) && (((((return_key != 0x061B8BC8u && return_key != 0x061B9C58u) && (return_key != 0x061BAFB8u && (return_key != 0x061D3C18u && return_key != 0x061D48F8u))) && ((return_key != 0x061DA3D0u && (return_key != 0x061DCFE8u && return_key != 0x061E3808u)) && (return_key != 0x06205928u && (return_key != 0x06206A90u && return_key != 0x0620C6C8u)))) && (((return_key != 0x062137D0u && (return_key != 0x062212C0u && return_key != 0x0622F078u)) && (return_key != 0x0623BEB8u && (return_key != 0x0623D410u && return_key != 0x062429C8u))) && ((return_key != 0x06247C10u && (return_key != 0x0624C680u && return_key != 0x06250F60u)) && (return_key != 0x06254F80u && (return_key != 0x06282200u && return_key != 0x06282E28u))))) && ((((return_key != 0x06284AC0u && return_key != 0x06287D98u) && (return_key != 0x0628A400u && (return_key != 0x0628EEE8u && return_key != 0x06290778u))) && ((return_key != 0x06291E68u && (return_key != 0x06292BF8u && return_key != 0x06297100u)) && (return_key != 0x0629EA20u && (return_key != 0x062A81D8u && return_key != 0x062AA450u)))) && (((return_key != 0x062B1D30u && (return_key != 0x062B8630u && return_key != 0x062B98C0u)) && (return_key != 0x062BC1A8u && (return_key != 0x062BFC80u && return_key != 0x062C29F0u))) && ((return_key != 0x062C7150u && (return_key != 0x062CFC80u && return_key != 0x062D0DC8u)) && (return_key != 0x062DA208u && (return_key != 0x06308A70u && return_key != 0x0630A838u))))))) && ((((((return_key != 0x0630CA90u && return_key != 0x06318088u) && (return_key != 0x0631FB90u && (return_key != 0x06342370u && return_key != 0x0634A010u))) && ((return_key != 0x06353CA8u && (return_key != 0x06354680u && return_key != 0x06382CF8u)) && (return_key != 0x063B2AD0u && (return_key != 0x063B5B98u && return_key != 0x063B7AC8u)))) && (((return_key != 0x063C7418u && (return_key != 0x063CA408u && return_key != 0x063D3A50u)) && (return_key != 0x063F0108u && (return_key != 0x063F65A0u && return_key != 0x063F7F30u))) && ((return_key != 0x06400848u && (return_key != 0x06405030u && return_key != 0x064071F0u)) && (return_key != 0x06410978u && (return_key != 0x06413088u && return_key != 0x0642A968u))))) && ((((return_key != 0x064328E0u && return_key != 0x06481CE0u) && (return_key != 0x06483AC0u && (return_key != 0x06486648u && return_key != 0x06488838u))) && ((return_key != 0x0648B368u && (return_key != 0x0648C1F0u && return_key != 0x0648D0A8u)) && (return_key != 0x0648F7F0u && (return_key != 0x06494CA0u && return_key != 0x064AE838u)))) && (((return_key != 0x064B2340u && (return_key != 0x064B5758u && return_key != 0x064C5EC0u)) && (return_key != 0x064C7258u && (return_key != 0x064C85F0u && return_key != 0x064CA4F0u))) && ((return_key != 0x064CBAC0u && (return_key != 0x064D12B0u && return_key != 0x064D4630u)) && (return_key != 0x064E3A08u && (return_key != 0x064E97E0u && return_key != 0x06509C10u)))))) && (((((return_key != 0x0650ACC0u && return_key != 0x0650B548u) && (return_key != 0x06516430u && (return_key != 0x065175A8u && return_key != 0x0651BA58u))) && ((return_key != 0x0651CE68u && (return_key != 0x06520740u && return_key != 0x06525FC8u)) && (return_key != 0x06527EB0u && (return_key != 0x0652B108u && return_key != 0x06534538u)))) && (((return_key != 0x06535B88u && (return_key != 0x06538910u && return_key != 0x06542A98u)) && (return_key != 0x06546018u && (return_key != 0x0654A3A0u && return_key != 0x06607D38u))) && ((return_key != 0x0660DB80u && (return_key != 0x06610AC0u && return_key != 0x06613D48u)) && (return_key != 0x06616B98u && (return_key != 0x066182B8u && return_key != 0x06619920u))))) && ((((return_key != 0x0661B588u && (return_key != 0x0665F330u && return_key != 0x06682858u)) && (return_key != 0x06689B60u && (return_key != 0x0668F8A0u && return_key != 0x06695468u))) && ((return_key != 0x06696788u && (return_key != 0x06696CB0u && return_key != 0x066976C0u)) && (return_key != 0x06698098u && (return_key != 0x0669DA78u && return_key != 0x0669E4F0u)))) && (((return_key != 0x066B08C8u && (return_key != 0x066B2540u && return_key != 0x066BBFD8u)) && (return_key != 0x066BC990u && (return_key != 0x066BD6B8u && return_key != 0x066BDF68u))) && ((return_key != 0x066BF7E8u && (return_key != 0x066C20D0u && return_key != 0x066DA778u)) && (return_key != 0x066DE660u && (return_key != 0x066E12A0u && return_key != 0x066E26D8u)))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FFA98u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF53u,
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
            cpu->pc = 0xFF54u;
            if (nh_scpu_expect_next(cpu, 0x060FFAA0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FFAA0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF54u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF56u;
            if (nh_scpu_expect_next(cpu, 0x060FFAB0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FFAB0u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF56u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF58u;
            if (nh_scpu_expect_next(cpu, 0x060FFAC2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FFAC2u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF58u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_pull8(cpu, bus, &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF59u;
            if (nh_scpu_expect_next(cpu, 0x060FFACAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060FFACAu: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF59u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000006u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF5Bu;
            if (nh_scpu_expect_next(cpu, 0x060FFADAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FFADAu: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF5Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF5Du;
            if (nh_scpu_expect_next(cpu, 0x060FFAE8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FFAE8u: {
            static const uint8_t expected_epoch[] = { 0xA2u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF5Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF60u;
            if (nh_scpu_expect_next(cpu, 0x060FFB00u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FFB00u: {
            static const uint8_t expected_epoch[] = { 0x68u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF60u,
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
            cpu->pc = 0xFF61u;
            if (nh_scpu_expect_next(cpu, 0x060FFB08u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FFB08u: {
            static const uint8_t expected_epoch[] = { 0x95u, 0x24u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF61u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint32_t address = ((uint32_t)cpu->d + 0x0024u + cpu->x) & 0xFFFFu;
            if (nh_scpu_write8(cpu, bus, address, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (address + 1u) & 0xFFFFu, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF63u;
            if (nh_scpu_expect_next(cpu, 0x060FFB18u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (5u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FFB18u: {
            static const uint8_t expected_epoch[] = { 0xE8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF63u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(cpu->x + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF64u;
            if (nh_scpu_expect_next(cpu, 0x060FFB20u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FFB20u: {
            static const uint8_t expected_epoch[] = { 0xE8u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF64u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->x = (uint16_t)(cpu->x + 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->x) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->x) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF65u;
            if (nh_scpu_expect_next(cpu, 0x060FFB28u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FFB28u: {
            static const uint8_t expected_epoch[] = { 0x88u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF65u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF66u;
            if (nh_scpu_expect_next(cpu, 0x060FFB30u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FFB30u: {
            static const uint8_t expected_epoch[] = { 0x88u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF66u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF67u;
            if (nh_scpu_expect_next(cpu, 0x060FFB38u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FFB38u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0xF7u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF67u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFF60u;
                if (nh_scpu_expect_next(cpu, 0x060FFB00u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF69u;
            if (nh_scpu_expect_next(cpu, 0x060FFB48u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FFB48u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF69u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF6Bu;
            if (nh_scpu_expect_next(cpu, 0x060FFB5Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FFB5Au: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF6Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t value = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000006u) & 0xFFFFu), &value) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)((cpu->a & 0xFF00u) | value);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0x00FFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x0080u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF6Du;
            if (nh_scpu_expect_next(cpu, 0x060FFB6Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FFB6Au: {
            static const uint8_t expected_epoch[] = { 0x48u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF6Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF6Eu;
            if (nh_scpu_expect_next(cpu, 0x060FFB72u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FFB72u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF6Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF70u;
            if (nh_scpu_expect_next(cpu, 0x060FFB80u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FFB80u: {
            static const uint8_t expected_epoch[] = { 0xD4u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF70u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t pointer_low = 0u, pointer_high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), &pointer_low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), &pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, pointer_low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFF72u;
            if (nh_scpu_expect_next(cpu, 0x060FFB90u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (6u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FFB90u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FF72u,
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
            if (((((((((return_key != 0x060842B8u && return_key != 0x06084AA0u) && (return_key != 0x06084CF8u && (return_key != 0x0609F420u && return_key != 0x060A36B8u))) && ((return_key != 0x060AE338u && return_key != 0x060BA958u) && (return_key != 0x060BD1B0u && (return_key != 0x060C6B00u && return_key != 0x060CFA98u)))) && (((return_key != 0x060D0DC8u && return_key != 0x060D18C0u) && (return_key != 0x060D3350u && (return_key != 0x060D9180u && return_key != 0x060D92D0u))) && ((return_key != 0x060D9430u && return_key != 0x060DC880u) && (return_key != 0x060DCA28u && (return_key != 0x060DF948u && return_key != 0x060E1120u))))) && ((((return_key != 0x060EC9F8u && return_key != 0x060EF768u) && (return_key != 0x060F0198u && (return_key != 0x061030E8u && return_key != 0x06113190u))) && ((return_key != 0x0611DC80u && return_key != 0x0611E210u) && (return_key != 0x06122838u && (return_key != 0x061230C0u && return_key != 0x06126D90u)))) && (((return_key != 0x0613BB88u && return_key != 0x0613CF38u) && (return_key != 0x0613E218u && (return_key != 0x06152530u && return_key != 0x06152690u))) && ((return_key != 0x06152780u && return_key != 0x06152918u) && (return_key != 0x06153588u && (return_key != 0x061536B0u && return_key != 0x061537F8u)))))) && (((((return_key != 0x06153948u && return_key != 0x06153AD0u) && (return_key != 0x061546D8u && (return_key != 0x061547E0u && return_key != 0x061548C0u))) && ((return_key != 0x06154A88u && return_key != 0x06154DC8u) && (return_key != 0x06155680u && (return_key != 0x06185D60u && return_key != 0x06187318u)))) && (((return_key != 0x06188508u && return_key != 0x06189B28u) && (return_key != 0x06189F28u && (return_key != 0x0618A360u && return_key != 0x0618A3C8u))) && ((return_key != 0x0618B8C0u && return_key != 0x0618BF90u) && (return_key != 0x0618D4A8u && (return_key != 0x0618DE18u && return_key != 0x06191BC8u))))) && ((((return_key != 0x061936E0u && return_key != 0x06196668u) && (return_key != 0x061967D0u && (return_key != 0x06198E28u && return_key != 0x0619AB38u))) && ((return_key != 0x0619B700u && return_key != 0x0619D0A8u) && (return_key != 0x0619D8C8u && (return_key != 0x0619DBB0u && return_key != 0x0619EDC0u)))) && (((return_key != 0x0619FC78u && return_key != 0x061A1780u) && (return_key != 0x061A2D80u && (return_key != 0x061ABE58u && return_key != 0x061AC2D8u))) && ((return_key != 0x061ACA68u && return_key != 0x061ACB58u) && (return_key != 0x061ACE38u && (return_key != 0x061AD268u && return_key != 0x061AF110u))))))) && ((((((return_key != 0x061B3340u && return_key != 0x061B9140u) && (return_key != 0x061B9EF8u && (return_key != 0x061BA6B0u && return_key != 0x061BAF78u))) && ((return_key != 0x061BB9E0u && return_key != 0x061D48B8u) && (return_key != 0x061D4D90u && (return_key != 0x061DA390u && return_key != 0x061DA578u)))) && (((return_key != 0x061DAD00u && return_key != 0x061DAEC8u) && (return_key != 0x061DCEB0u && (return_key != 0x061DCFA8u && return_key != 0x061DD348u))) && ((return_key != 0x061DD618u && return_key != 0x061DDA68u) && (return_key != 0x061E07B8u && (return_key != 0x061E4338u && return_key != 0x061E4698u))))) && ((((return_key != 0x061E4780u && return_key != 0x061E48B8u) && (return_key != 0x061E4910u && (return_key != 0x06205A10u && return_key != 0x06206A50u))) && ((return_key != 0x06206B88u && return_key != 0x0620C688u) && (return_key != 0x0620D998u && (return_key != 0x06217348u && return_key != 0x06224930u)))) && (((return_key != 0x0622FD90u && return_key != 0x0623CF98u) && (return_key != 0x0623E780u && (return_key != 0x06243500u && return_key != 0x0624C640u))) && ((return_key != 0x06250F20u && return_key != 0x06254F40u) && (return_key != 0x062576F0u && (return_key != 0x06282C70u && return_key != 0x06283BB8u)))))) && (((((return_key != 0x06287D58u && return_key != 0x06289BE0u) && (return_key != 0x0628DB60u && (return_key != 0x06290738u && return_key != 0x06291E28u))) && ((return_key != 0x06292BB8u && return_key != 0x06293788u) && (return_key != 0x06294C28u && (return_key != 0x06297AE0u && return_key != 0x0629AEE8u)))) && (((return_key != 0x0629EED0u && return_key != 0x0629F180u) && (return_key != 0x0629F300u && (return_key != 0x062A5460u && return_key != 0x062A8448u))) && ((return_key != 0x062A8A00u && return_key != 0x062AFCE0u) && (return_key != 0x062B26F8u && (return_key != 0x062B9668u && return_key != 0x062BAE68u))))) && ((((return_key != 0x062BCDC0u && return_key != 0x062C0108u) && (return_key != 0x062C0380u && (return_key != 0x062C5AE8u && return_key != 0x062C8468u))) && ((return_key != 0x062C8BB8u && return_key != 0x062C96A0u) && (return_key != 0x062D0D88u && (return_key != 0x062D1108u && return_key != 0x062DA870u)))) && (((return_key != 0x06309690u && return_key != 0x0630BAD0u) && (return_key != 0x0630D9A8u && (return_key != 0x06319D28u && return_key != 0x063255C8u))) && ((return_key != 0x06326240u && return_key != 0x06342408u) && (return_key != 0x06343348u && (return_key != 0x0634B988u && return_key != 0x06354640u)))))))) && (((((((return_key != 0x06354D20u && return_key != 0x063838C8u) && (return_key != 0x063B2C00u && (return_key != 0x063B2D28u && return_key != 0x063B3700u))) && ((return_key != 0x063B5F78u && return_key != 0x063B60D8u) && (return_key != 0x063B7718u && (return_key != 0x063B7780u && return_key != 0x063B8760u)))) && (((return_key != 0x063B89F8u && return_key != 0x063B91B0u) && (return_key != 0x063B9470u && (return_key != 0x063C9D98u && return_key != 0x063CA628u))) && ((return_key != 0x063CA748u && return_key != 0x063CA868u) && (return_key != 0x063CAE78u && (return_key != 0x063CB5B0u && return_key != 0x063CB780u))))) && ((((return_key != 0x063CB8A0u && return_key != 0x063CBCD8u) && (return_key != 0x063CC3F0u && (return_key != 0x063CE1B8u && return_key != 0x063D3E20u))) && ((return_key != 0x063D4128u && return_key != 0x063D53C0u) && (return_key != 0x063F0B68u && (return_key != 0x063F7618u && return_key != 0x063F81C8u)))) && (((return_key != 0x063F8390u && return_key != 0x063F8458u) && (return_key != 0x063F88C8u && (return_key != 0x063F9460u && return_key != 0x06401F00u))) && ((return_key != 0x06406580u && return_key != 0x06406A10u) && (return_key != 0x06409588u && (return_key != 0x064111E0u && return_key != 0x06412708u)))))) && (((((return_key != 0x06413198u && return_key != 0x06413B20u) && (return_key != 0x06414568u && (return_key != 0x0642ABC0u && return_key != 0x0642B208u))) && ((return_key != 0x0642B418u && return_key != 0x0642C540u) && (return_key != 0x06432E60u && (return_key != 0x06433D00u && return_key != 0x06483A80u)))) && (((return_key != 0x06484CA0u && return_key != 0x064873C8u) && (return_key != 0x06489150u && (return_key != 0x0648C1B0u && return_key != 0x0648D068u))) && ((return_key != 0x0648DEC0u && return_key != 0x06490078u) && (return_key != 0x064963E8u && (return_key != 0x064AE950u && return_key != 0x064AEFD0u))))) && ((((return_key != 0x064AF6E0u && return_key != 0x064AFA60u) && (return_key != 0x064B0010u && (return_key != 0x064B04A0u && return_key != 0x064B0630u))) && ((return_key != 0x064B0BE0u && return_key != 0x064B0F88u) && (return_key != 0x064B1430u && (return_key != 0x064B1718u && return_key != 0x064B28A8u)))) && (((return_key != 0x064B2C78u && return_key != 0x064B2EB0u) && (return_key != 0x064B3038u && (return_key != 0x064B38F0u && return_key != 0x064B73F0u))) && ((return_key != 0x064C7218u && return_key != 0x064C85B0u) && (return_key != 0x064C8F90u && (return_key != 0x064CAD60u && return_key != 0x064CB5B8u))))))) && ((((((return_key != 0x064CDE40u && return_key != 0x064D1D78u) && (return_key != 0x064D2050u && (return_key != 0x064D3378u && return_key != 0x064D3738u))) && ((return_key != 0x064D45F0u && return_key != 0x064D5950u) && (return_key != 0x064E3BB0u && (return_key != 0x064E42A8u && return_key != 0x064E4788u)))) && (((return_key != 0x064E4E18u && return_key != 0x064EA230u) && (return_key != 0x06509D40u && (return_key != 0x0650A348u && return_key != 0x0650ADF0u))) && ((return_key != 0x0650B2F8u && return_key != 0x0650B678u) && (return_key != 0x0650BC98u && (return_key != 0x06517568u && return_key != 0x065177C8u))))) && ((((return_key != 0x06519268u && return_key != 0x0651BEF8u) && (return_key != 0x0651D1B8u && (return_key != 0x06520E40u && return_key != 0x06526C98u))) && ((return_key != 0x06527478u && return_key != 0x06528260u) && (return_key != 0x06528660u && (return_key != 0x06528850u && return_key != 0x0652C0A0u)))) && (((return_key != 0x0652C948u && return_key != 0x0652DD90u) && (return_key != 0x065349E0u && (return_key != 0x06535EA0u && return_key != 0x065366B8u))) && ((return_key != 0x06536F80u && return_key != 0x0653C168u) && (return_key != 0x06543618u && (return_key != 0x06546980u && return_key != 0x0654A890u)))))) && (((((return_key != 0x0654B080u && return_key != 0x0654C668u) && (return_key != 0x0660AA08u && (return_key != 0x0660FC40u && return_key != 0x06612368u))) && ((return_key != 0x06615948u && return_key != 0x06617018u) && (return_key != 0x06618BA8u && (return_key != 0x06619AB8u && return_key != 0x0661A6C0u)))) && (((return_key != 0x0661DA30u && return_key != 0x06660F88u) && (return_key != 0x06682F70u && (return_key != 0x0668C4E0u && return_key != 0x066900A8u))) && ((return_key != 0x06696680u && return_key != 0x06696C70u) && (return_key != 0x06697680u && (return_key != 0x06698058u && return_key != 0x06698AB0u))))) && ((((return_key != 0x0669E1E8u && return_key != 0x0669F6D8u) && (return_key != 0x066B1968u && (return_key != 0x066B2928u && return_key != 0x066B4F30u))) && ((return_key != 0x066BC950u && return_key != 0x066BD378u) && (return_key != 0x066BDF28u && (return_key != 0x066BE7A8u && return_key != 0x066BFDD8u)))) && (((return_key != 0x066C2AF0u && return_key != 0x066DB5E8u) && (return_key != 0x066DF168u && (return_key != 0x066E13E8u && return_key != 0x066E1508u))) && ((return_key != 0x066E18D8u && (return_key != 0x066E2698u && return_key != 0x066E2810u)) && (return_key != 0x066E2920u && (return_key != 0x066E2A78u && return_key != 0x066E30D0u))))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        default: return NH_SCPU_NOT_MINE;
    }
}
