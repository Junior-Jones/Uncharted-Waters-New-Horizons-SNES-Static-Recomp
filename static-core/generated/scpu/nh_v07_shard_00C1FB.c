/* Generated direct New Horizons S-CPU authority; do not edit. */
#include "nh_v07_generated.h"

NHScpuExecResult nh_v07_shard_00C1FB(NHScpuState *cpu, const NHScpuBus *bus) {
    switch (nh_scpu_context_key(cpu)) {
        case 0x060FD803u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x30u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB00u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x30u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB02u;
            if (nh_scpu_expect_next(cpu, 0x060FD810u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD810u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB02u,
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
            cpu->pc = 0xFB04u;
            if (nh_scpu_expect_next(cpu, 0x060FD820u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD820u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB04u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB06u;
            if (nh_scpu_expect_next(cpu, 0x060FD830u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD830u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB06u,
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
            cpu->pc = 0xFB08u;
            if (nh_scpu_expect_next(cpu, 0x060FD840u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD840u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB08u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB0Au;
            if (nh_scpu_expect_next(cpu, 0x060FD850u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD850u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB0Au,
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
            if ((((((((return_key != 0x060850B8u && return_key != 0x0608A180u) && (return_key != 0x060A05C8u && (return_key != 0x060A08B0u && return_key != 0x060A1708u))) && ((return_key != 0x060A22C0u && return_key != 0x060C2CF8u) && (return_key != 0x060C2DF8u && (return_key != 0x060C4A40u && return_key != 0x060C4B78u)))) && (((return_key != 0x060C5050u && return_key != 0x060FF8A0u) && (return_key != 0x061468A0u && (return_key != 0x06149120u && return_key != 0x06149208u))) && ((return_key != 0x061492F8u && (return_key != 0x061494A8u && return_key != 0x06149658u)) && (return_key != 0x0614A878u && (return_key != 0x0614A960u && return_key != 0x0618E4E8u))))) && ((((return_key != 0x061921F0u && return_key != 0x061D63D8u) && (return_key != 0x061D7B08u && (return_key != 0x061D8EE0u && return_key != 0x061D96C0u))) && ((return_key != 0x06280288u && (return_key != 0x06283490u && return_key != 0x06287720u)) && (return_key != 0x06292370u && (return_key != 0x06292810u && return_key != 0x06299CB0u)))) && (((return_key != 0x062ABF28u && return_key != 0x062AC280u) && (return_key != 0x062AC550u && (return_key != 0x062BA3D0u && return_key != 0x062BA500u))) && ((return_key != 0x062BA890u && (return_key != 0x062BA9C0u && return_key != 0x06303410u)) && (return_key != 0x06309D98u && (return_key != 0x0630D328u && return_key != 0x06310558u)))))) && (((((return_key != 0x063128B0u && return_key != 0x063129B0u) && (return_key != 0x0631E928u && (return_key != 0x0631F270u && return_key != 0x063222E0u))) && ((return_key != 0x06323860u && return_key != 0x06336BF8u) && (return_key != 0x063371B8u && (return_key != 0x06337378u && return_key != 0x06343970u)))) && (((return_key != 0x06343D10u && return_key != 0x063440B0u) && (return_key != 0x06344450u && (return_key != 0x06345B18u && return_key != 0x06345C80u))) && ((return_key != 0x06345DE8u && (return_key != 0x06346230u && return_key != 0x06352048u)) && (return_key != 0x0638EC68u && (return_key != 0x0638FCA0u && return_key != 0x06394818u))))) && ((((return_key != 0x0639A948u && return_key != 0x063AFF40u) && (return_key != 0x063B32B8u && (return_key != 0x063B33C8u && return_key != 0x063B7258u))) && ((return_key != 0x063B8310u && (return_key != 0x063BB440u && return_key != 0x063BB7C8u)) && (return_key != 0x063BD838u && (return_key != 0x063C7A28u && return_key != 0x063C7CE0u)))) && (((return_key != 0x063D4598u && return_key != 0x063D4B90u) && (return_key != 0x063D8530u && (return_key != 0x063D8A70u && return_key != 0x063D9590u))) && ((return_key != 0x063D97F0u && (return_key != 0x063DA510u && return_key != 0x063DA830u)) && (return_key != 0x063DACB8u && (return_key != 0x063DAD10u && return_key != 0x063DBAF0u))))))) && ((((((return_key != 0x063DBD60u && return_key != 0x063DBFE8u) && (return_key != 0x063DC108u && (return_key != 0x063DC258u && return_key != 0x063DC968u))) && ((return_key != 0x063DCC90u && return_key != 0x063E9850u) && (return_key != 0x063EAED8u && (return_key != 0x063EB6A8u && return_key != 0x063F54E8u)))) && (((return_key != 0x063F5720u && return_key != 0x063F7958u) && (return_key != 0x063F7C98u && (return_key != 0x063F9528u && return_key != 0x063FA500u))) && ((return_key != 0x06400548u && (return_key != 0x06400718u && return_key != 0x064007C8u)) && (return_key != 0x06405BF8u && (return_key != 0x0640CF30u && return_key != 0x0640CFE0u))))) && ((((return_key != 0x0640D4E0u && return_key != 0x0640D9B0u) && (return_key != 0x06411948u && (return_key != 0x0641C520u && return_key != 0x0642BD38u))) && ((return_key != 0x0642BE98u && (return_key != 0x06431360u && return_key != 0x064313B8u)) && (return_key != 0x06431540u && (return_key != 0x064339C0u && return_key != 0x06433B20u)))) && (((return_key != 0x06435E90u && return_key != 0x06437578u) && (return_key != 0x064375D0u && (return_key != 0x064809B0u && return_key != 0x06480BD8u))) && ((return_key != 0x064812D8u && (return_key != 0x06483FC8u && return_key != 0x06484858u)) && (return_key != 0x06487E10u && (return_key != 0x064897B0u && return_key != 0x06491FD8u)))))) && (((((return_key != 0x06496860u && return_key != 0x0649B1E0u) && (return_key != 0x0649C3D0u && (return_key != 0x064B6390u && return_key != 0x064C4D08u))) && ((return_key != 0x064DC338u && (return_key != 0x064DC520u && return_key != 0x064DD630u)) && (return_key != 0x064DD818u && (return_key != 0x06512798u && return_key != 0x06512918u)))) && (((return_key != 0x065131D0u && return_key != 0x06513548u) && (return_key != 0x06513920u && (return_key != 0x06513B70u && return_key != 0x06524108u))) && ((return_key != 0x06534220u && (return_key != 0x06534320u && return_key != 0x066115F0u)) && (return_key != 0x06611CB8u && (return_key != 0x066A1670u && return_key != 0x066A1988u))))) && ((((return_key != 0x066A1D38u && return_key != 0x066A2050u) && (return_key != 0x066A2420u && (return_key != 0x066A2738u && return_key != 0x066A2A70u))) && ((return_key != 0x066A2D88u && (return_key != 0x066A3348u && return_key != 0x066A6DC8u)) && (return_key != 0x066A6F20u && (return_key != 0x066A8168u && return_key != 0x066A82C0u)))) && (((return_key != 0x066DAA40u && return_key != 0x066E4250u) && (return_key != 0x066E43D8u && (return_key != 0x0670F288u && return_key != 0x0670F7E0u))) && ((return_key != 0x06712098u && (return_key != 0x067122C0u && return_key != 0x0671AA90u)) && (return_key != 0x0671AE98u && (return_key != 0x0671DBB8u && return_key != 0x0671DF08u)))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FD858u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x18u, 0xFBu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB0Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x0Eu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB18u;
            if (nh_scpu_expect_next(cpu, 0x060FD8C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060FD878u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB0Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000020u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000021u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB11u;
            if (nh_scpu_expect_next(cpu, 0x060FD888u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD888u: {
            static const uint8_t expected_epoch[] = { 0x10u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB11u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFB17u;
                if (nh_scpu_expect_next(cpu, 0x060FD8B8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB13u;
            if (nh_scpu_expect_next(cpu, 0x060FD898u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD898u: {
            static const uint8_t expected_epoch[] = { 0x5Cu, 0x60u, 0xFDu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB13u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD60u;
            if (nh_scpu_expect_next(cpu, 0x060FEB00u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060FD8B8u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB17u,
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
            if (((((((((return_key != 0x0608FE88u && (return_key != 0x0608FFB8u && return_key != 0x06090788u)) && ((return_key != 0x060908E0u && return_key != 0x06090D70u) && (return_key != 0x060911C0u && return_key != 0x06092B00u))) && ((return_key != 0x06092C30u && (return_key != 0x06093400u && return_key != 0x06093558u)) && ((return_key != 0x060939E8u && return_key != 0x06093E38u) && (return_key != 0x06095E18u && return_key != 0x060A0AF0u)))) && (((return_key != 0x060A0C10u && (return_key != 0x060A0E00u && return_key != 0x060A0F40u)) && ((return_key != 0x060A20A0u && return_key != 0x060B3180u) && (return_key != 0x060B31D8u && return_key != 0x060B69A8u))) && ((return_key != 0x060C14D0u && (return_key != 0x060C1860u && return_key != 0x060C1D20u)) && ((return_key != 0x060C1DE0u && return_key != 0x060C2420u) && (return_key != 0x060C24E0u && return_key != 0x060C5280u))))) && ((((return_key != 0x060C5390u && (return_key != 0x060C54B8u && return_key != 0x060C5510u)) && ((return_key != 0x060CEAE0u && return_key != 0x060CF198u) && (return_key != 0x060CFF50u && return_key != 0x060D0928u))) && ((return_key != 0x060D13E0u && (return_key != 0x060D1C48u && return_key != 0x060D2240u)) && ((return_key != 0x060D3058u && return_key != 0x060D3758u) && (return_key != 0x060D4DE8u && return_key != 0x060D6C40u)))) && (((return_key != 0x060D7D50u && (return_key != 0x060E0DA0u && return_key != 0x060E9150u)) && ((return_key != 0x060EB568u && return_key != 0x060EBC10u) && (return_key != 0x060EC588u && return_key != 0x061010D8u))) && ((return_key != 0x06102A00u && (return_key != 0x06103AD0u && return_key != 0x06104118u)) && ((return_key != 0x06104D50u && return_key != 0x0612E738u) && (return_key != 0x061336E8u && return_key != 0x06133DD0u)))))) && (((((return_key != 0x0613E0B0u && (return_key != 0x0613E148u && return_key != 0x061451D8u)) && ((return_key != 0x06148388u && return_key != 0x06148550u) && (return_key != 0x06148718u && return_key != 0x06149B50u))) && ((return_key != 0x06149C48u && (return_key != 0x0614B8E0u && return_key != 0x0614BA40u)) && ((return_key != 0x0614BBA0u && return_key != 0x0614CBA8u) && (return_key != 0x0614CC30u && return_key != 0x0614CCD0u)))) && (((return_key != 0x061581E0u && (return_key != 0x061808C8u && return_key != 0x061809F0u)) && ((return_key != 0x06184170u && return_key != 0x06185628u) && (return_key != 0x06185FF8u && return_key != 0x061863C8u))) && ((return_key != 0x06186BE0u && (return_key != 0x06187740u && return_key != 0x061879F8u)) && ((return_key != 0x06188F80u && return_key != 0x0618AF10u) && (return_key != 0x0618B060u && return_key != 0x0618CB10u))))) && ((((return_key != 0x0618DA10u && (return_key != 0x0618EE40u && return_key != 0x0618EF70u)) && ((return_key != 0x0618F160u && return_key != 0x061952A0u) && (return_key != 0x06196AF8u && return_key != 0x06199B20u))) && ((return_key != 0x0619B1A0u && (return_key != 0x0619B7A0u && return_key != 0x061A0928u)) && ((return_key != 0x061A09A0u && return_key != 0x061A0DC0u) && (return_key != 0x061A0FB0u && return_key != 0x061A12A0u)))) && (((return_key != 0x061A68A0u && (return_key != 0x061A6D50u && return_key != 0x061A71A8u)) && ((return_key != 0x061A7658u && return_key != 0x061A9810u) && (return_key != 0x061ABBC8u && return_key != 0x061ABC80u))) && ((return_key != 0x061AD6B8u && (return_key != 0x061AE6D0u && return_key != 0x061AE878u)) && ((return_key != 0x061AEA18u && return_key != 0x061AEB30u) && (return_key != 0x061AECF8u && return_key != 0x061B2890u))))))) && ((((((return_key != 0x061C30F0u && (return_key != 0x061C3180u && return_key != 0x061C38C0u)) && ((return_key != 0x061C3948u && return_key != 0x061CA8B0u) && (return_key != 0x061D3D70u && return_key != 0x061D3DF8u))) && ((return_key != 0x061D84E0u && (return_key != 0x061DABF8u && return_key != 0x061DADC0u)) && ((return_key != 0x061DAF58u && return_key != 0x061DB330u) && (return_key != 0x061DC978u && return_key != 0x061DCD68u)))) && (((return_key != 0x061DEA68u && (return_key != 0x061E2210u && return_key != 0x061E24A0u)) && ((return_key != 0x061E26D8u && return_key != 0x061E2968u) && (return_key != 0x06240180u && return_key != 0x062401C8u))) && ((return_key != 0x06240258u && (return_key != 0x062403E0u && return_key != 0x06240428u)) && ((return_key != 0x062405B0u && return_key != 0x062405F8u) && (return_key != 0x06240688u && return_key != 0x06240810u))))) && ((((return_key != 0x06240858u && (return_key != 0x06240B10u && return_key != 0x06240BB0u)) && ((return_key != 0x062433B0u && return_key != 0x062817E8u) && (return_key != 0x06281888u && return_key != 0x06282110u))) && ((return_key != 0x062833B0u && (return_key != 0x06283660u && return_key != 0x06283728u)) && ((return_key != 0x06283948u && return_key != 0x06283AB8u) && (return_key != 0x06284EC8u && return_key != 0x06284F68u)))) && (((return_key != 0x06287B80u && (return_key != 0x06287BD8u && return_key != 0x06290F60u)) && ((return_key != 0x062911B8u && return_key != 0x06298E88u) && (return_key != 0x06299408u && return_key != 0x06299EF0u))) && ((return_key != 0x0629A010u && (return_key != 0x0629A200u && return_key != 0x0629A340u)) && ((return_key != 0x062A29A8u && return_key != 0x062A2A80u) && (return_key != 0x062A2F60u && return_key != 0x062A3120u)))))) && (((((return_key != 0x062A3548u && (return_key != 0x062A3620u && return_key != 0x062A5938u)) && ((return_key != 0x062A5A20u && return_key != 0x062C37A0u) && (return_key != 0x062C3A58u && return_key != 0x062C40D0u))) && ((return_key != 0x062C43B0u && (return_key != 0x062CE438u && return_key != 0x062CF208u)) && ((return_key != 0x062D14D8u && return_key != 0x062D3570u) && (return_key != 0x062D4328u && return_key != 0x062D43C8u)))) && (((return_key != 0x062D4420u && (return_key != 0x062D72F0u && return_key != 0x062D7348u)) && ((return_key != 0x063079E8u && return_key != 0x06308088u) && (return_key != 0x06337928u && return_key != 0x06337AB8u))) && ((return_key != 0x06343010u && (return_key != 0x06353D90u && return_key != 0x06353E38u)) && ((return_key != 0x0635A8E0u && return_key != 0x06388530u) && (return_key != 0x063A61F8u && return_key != 0x063A6328u))))) && ((((return_key != 0x063B7000u && (return_key != 0x063B7160u && return_key != 0x063B9DA0u)) && ((return_key != 0x063BA388u && return_key != 0x063BAFA8u) && (return_key != 0x063BB138u && return_key != 0x063C0E10u))) && ((return_key != 0x063C1790u && (return_key != 0x063C2A28u && return_key != 0x063C3B80u)) && ((return_key != 0x063C3D90u && return_key != 0x063C4938u) && (return_key != 0x063C7188u && return_key != 0x063CA268u)))) && (((return_key != 0x063D1260u && (return_key != 0x063D3120u && return_key != 0x063D43F0u)) && ((return_key != 0x063D4720u && return_key != 0x063D4A28u) && (return_key != 0x063DE5E0u && return_key != 0x063DE8D0u))) && (((return_key != 0x063E3678u && return_key != 0x063E5D98u) && (return_key != 0x063E60B0u && return_key != 0x063EAE60u)) && ((return_key != 0x063F97A0u && return_key != 0x064011A0u) && (return_key != 0x06401278u && return_key != 0x06402BD8u)))))))) && (((((((return_key != 0x06403048u && (return_key != 0x06403108u && return_key != 0x06403608u)) && ((return_key != 0x06408188u && return_key != 0x06408328u) && (return_key != 0x06408558u && return_key != 0x06408710u))) && ((return_key != 0x0640EFF0u && (return_key != 0x06410840u && return_key != 0x06411F18u)) && ((return_key != 0x06416EA0u && return_key != 0x0641D658u) && (return_key != 0x0641E2A0u && return_key != 0x0642B9A8u)))) && (((return_key != 0x0642BB88u && (return_key != 0x0642D438u && return_key != 0x0642F2B0u)) && ((return_key != 0x0642F3C8u && return_key != 0x064317D0u) && (return_key != 0x06432088u && return_key != 0x06432210u))) && ((return_key != 0x064335A8u && (return_key != 0x064335F0u && return_key != 0x06433828u)) && ((return_key != 0x06433870u && return_key != 0x064361E8u) && (return_key != 0x06436258u && return_key != 0x06438CB8u))))) && ((((return_key != 0x06438E50u && (return_key != 0x06438ED8u && return_key != 0x06439038u)) && ((return_key != 0x0643B7F0u && return_key != 0x0643B860u) && (return_key != 0x0643D0C8u && return_key != 0x0643D138u))) && ((return_key != 0x06487648u && (return_key != 0x06487700u && return_key != 0x06487C00u)) && ((return_key != 0x0648AB40u && return_key != 0x0648B528u) && (return_key != 0x0648B5D0u && return_key != 0x0648C3B0u)))) && (((return_key != 0x0648C458u && (return_key != 0x0648D268u && return_key != 0x0648D310u)) && ((return_key != 0x0648FB80u && return_key != 0x06490110u) && (return_key != 0x06494928u && return_key != 0x06494E38u))) && ((return_key != 0x0649F1F0u && (return_key != 0x064AF450u && return_key != 0x064AF520u)) && ((return_key != 0x064B1EB8u && return_key != 0x064B4D80u) && (return_key != 0x064B4E70u && return_key != 0x064B6628u)))))) && (((((return_key != 0x064BBC60u && (return_key != 0x064BBD90u && return_key != 0x064C42E8u)) && ((return_key != 0x064C4670u && return_key != 0x064C6860u) && (return_key != 0x064C7BF8u && return_key != 0x064D0858u))) && ((return_key != 0x064D2480u && (return_key != 0x064D2580u && return_key != 0x064D3F48u)) && ((return_key != 0x064D4200u && return_key != 0x064D6238u) && (return_key != 0x064D65D8u && return_key != 0x064DFFE0u)))) && (((return_key != 0x064E0038u && (return_key != 0x064E4400u && return_key != 0x064E74D8u)) && ((return_key != 0x064E79A8u && return_key != 0x064E7E80u) && (return_key != 0x064EA0D8u && return_key != 0x064EC348u))) && ((return_key != 0x064ED080u && (return_key != 0x064ED160u && return_key != 0x064EDCA0u)) && ((return_key != 0x064EDDF0u && return_key != 0x064EE398u) && (return_key != 0x064EE4A0u && return_key != 0x064EE588u))))) && ((((return_key != 0x064EEA58u && (return_key != 0x064EEB60u && return_key != 0x064EEC48u)) && ((return_key != 0x064EF1A0u && return_key != 0x064EF2A8u) && (return_key != 0x064EF390u && return_key != 0x064EF978u))) && ((return_key != 0x064EFA80u && (return_key != 0x064EFB68u && return_key != 0x064F0DD0u)) && ((return_key != 0x064F0ED8u && return_key != 0x064F0FC0u) && (return_key != 0x064F4E28u && return_key != 0x064F4F90u)))) && (((return_key != 0x064F51C0u && (return_key != 0x064F52E0u && return_key != 0x06501368u)) && ((return_key != 0x06501960u && return_key != 0x06501D90u) && (return_key != 0x0650EAD0u && return_key != 0x0650EDA0u))) && ((return_key != 0x0650EF60u && (return_key != 0x06510760u && return_key != 0x06512198u)) && ((return_key != 0x06512A58u && return_key != 0x06512E50u) && (return_key != 0x06513010u && return_key != 0x065132E0u))))))) && ((((((return_key != 0x06513A88u && (return_key != 0x06513CB8u && return_key != 0x06513F28u)) && ((return_key != 0x06515230u && return_key != 0x06516870u) && (return_key != 0x06517F00u && return_key != 0x065194F8u))) && ((return_key != 0x0651A7E0u && (return_key != 0x0651AAE8u && return_key != 0x0651C1D0u)) && ((return_key != 0x0651DE90u && return_key != 0x0651F150u) && (return_key != 0x0651F540u && return_key != 0x0651F7F8u)))) && (((return_key != 0x06521BC8u && (return_key != 0x06523EE8u && return_key != 0x065248B0u)) && ((return_key != 0x06525110u && return_key != 0x06527738u) && (return_key != 0x06529478u && return_key != 0x06532490u))) && ((return_key != 0x06532568u && (return_key != 0x06545820u && return_key != 0x06583218u)) && ((return_key != 0x065833B0u && return_key != 0x0660F5E8u) && (return_key != 0x0660F738u && return_key != 0x06610898u))))) && ((((return_key != 0x066127E0u && (return_key != 0x06616CF8u && return_key != 0x06618D60u)) && ((return_key != 0x0661A420u && return_key != 0x0661AA80u) && (return_key != 0x0661B898u && return_key != 0x0661BAB8u))) && ((return_key != 0x0661C830u && (return_key != 0x0661D3F8u && return_key != 0x06647548u)) && ((return_key != 0x06647978u && return_key != 0x06683EE8u) && (return_key != 0x066870F8u && return_key != 0x0668C7B8u)))) && (((return_key != 0x0668C840u && (return_key != 0x0668F118u && return_key != 0x0668FBF8u)) && ((return_key != 0x06691570u && return_key != 0x066924E8u) && (return_key != 0x06692EA8u && return_key != 0x06694030u))) && ((return_key != 0x066950C0u && (return_key != 0x06695DD0u && return_key != 0x06697190u)) && ((return_key != 0x06697B08u && return_key != 0x06698560u) && (return_key != 0x0669B700u && return_key != 0x0669C1A0u)))))) && (((((return_key != 0x0669C218u && (return_key != 0x0669C2F8u && return_key != 0x0669C370u)) && ((return_key != 0x0669C470u && return_key != 0x0669C4E8u) && (return_key != 0x0669F218u && return_key != 0x0669F270u))) && ((return_key != 0x0669F918u && (return_key != 0x066A0D78u && return_key != 0x066A6120u)) && ((return_key != 0x066A66B8u && return_key != 0x066A70E8u) && (return_key != 0x066A7170u && return_key != 0x066A72D8u)))) && (((return_key != 0x066A7360u && (return_key != 0x066A8488u && return_key != 0x066A8510u)) && ((return_key != 0x066A8678u && return_key != 0x066A8700u) && (return_key != 0x066A9D10u && return_key != 0x066A9ED0u))) && ((return_key != 0x066AA230u && (return_key != 0x066AA438u && return_key != 0x066AAD70u)) && ((return_key != 0x066AB160u && return_key != 0x066B9550u) && (return_key != 0x066B9680u && return_key != 0x066B9E30u))))) && ((((return_key != 0x066BA468u && (return_key != 0x066BB898u && return_key != 0x066BBEC8u)) && ((return_key != 0x066BC508u && return_key != 0x066BC688u) && (return_key != 0x066BCF30u && return_key != 0x066BD0B0u))) && ((return_key != 0x066BEB40u && (return_key != 0x066BFBA8u && return_key != 0x066C8740u)) && ((return_key != 0x066D0C58u && return_key != 0x066D0CA0u) && (return_key != 0x066D10F8u && return_key != 0x066D1140u)))) && (((return_key != 0x066D1610u && (return_key != 0x066D1658u && return_key != 0x066D6720u)) && ((return_key != 0x066D6810u && return_key != 0x066D9608u) && (return_key != 0x066D9680u && return_key != 0x06704E98u))) && (((return_key != 0x06708510u && return_key != 0x0670A558u) && (return_key != 0x0670B1B8u && return_key != 0x0670B258u)) && ((return_key != 0x067170C0u && return_key != 0x06717638u) && (return_key != 0x06717AA0u && return_key != 0x06717E58u))))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FD8C0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB18u,
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
            cpu->pc = 0xFB1Au;
            if (nh_scpu_expect_next(cpu, 0x060FD8D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD8D0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB1Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB1Cu;
            if (nh_scpu_expect_next(cpu, 0x060FD8E0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD8E0u: {
            static const uint8_t expected_epoch[] = { 0x45u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB1Cu,
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
            cpu->pc = 0xFB1Eu;
            if (nh_scpu_expect_next(cpu, 0x060FD8F0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD8F0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB1Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000020u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000021u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB20u;
            if (nh_scpu_expect_next(cpu, 0x060FD900u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD900u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB20u,
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
            cpu->pc = 0xFB22u;
            if (nh_scpu_expect_next(cpu, 0x060FD910u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD910u: {
            static const uint8_t expected_epoch[] = { 0x10u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB22u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFB2Cu;
                if (nh_scpu_expect_next(cpu, 0x060FD960u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB24u;
            if (nh_scpu_expect_next(cpu, 0x060FD920u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD920u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB24u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB25u;
            if (nh_scpu_expect_next(cpu, 0x060FD928u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD928u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB25u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB28u;
            if (nh_scpu_expect_next(cpu, 0x060FD940u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD940u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB28u,
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
            cpu->pc = 0xFB2Au;
            if (nh_scpu_expect_next(cpu, 0x060FD950u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD950u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB2Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB2Cu;
            if (nh_scpu_expect_next(cpu, 0x060FD960u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD960u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB2Cu,
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
            cpu->pc = 0xFB2Eu;
            if (nh_scpu_expect_next(cpu, 0x060FD970u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD970u: {
            static const uint8_t expected_epoch[] = { 0x10u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB2Eu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFB38u;
                if (nh_scpu_expect_next(cpu, 0x060FD9C0u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB30u;
            if (nh_scpu_expect_next(cpu, 0x060FD980u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD980u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB30u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB31u;
            if (nh_scpu_expect_next(cpu, 0x060FD988u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD988u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB31u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB34u;
            if (nh_scpu_expect_next(cpu, 0x060FD9A0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD9A0u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB34u,
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
            cpu->pc = 0xFB36u;
            if (nh_scpu_expect_next(cpu, 0x060FD9B0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD9B0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB36u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB38u;
            if (nh_scpu_expect_next(cpu, 0x060FD9C0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD9C0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB38u,
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
            cpu->pc = 0xFB3Au;
            if (nh_scpu_expect_next(cpu, 0x060FD9D0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FD9D0u: {
            static const uint8_t expected_epoch[] = { 0xC9u, 0x00u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB3Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - 0x0100u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= 0x0100u) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB3Du;
            if (nh_scpu_expect_next(cpu, 0x060FD9E8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FD9E8u: {
            static const uint8_t expected_epoch[] = { 0x90u, 0x18u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB3Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFB57u;
                if (nh_scpu_expect_next(cpu, 0x060FDAB8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB3Fu;
            if (nh_scpu_expect_next(cpu, 0x060FD9F8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FD9F8u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB3Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000008u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB41u;
            if (nh_scpu_expect_next(cpu, 0x060FDA08u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDA08u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x10u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB41u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x0010u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB44u;
            if (nh_scpu_expect_next(cpu, 0x060FDA20u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FDA20u: {
            static const uint8_t expected_epoch[] = { 0x06u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB44u,
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
            cpu->pc = 0xFB46u;
            if (nh_scpu_expect_next(cpu, 0x060FDA30u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDA30u: {
            static const uint8_t expected_epoch[] = { 0x26u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB46u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000008u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t old = (uint16_t)(low | ((uint16_t)high << 8u));
            const uint16_t result = (uint16_t)(((uint32_t)old << 1u) | ((cpu->p & NH_P_C) != 0u ? 1u : 0u));
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000008u) & 0xFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | ((old >> 15u) & 1u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB48u;
            if (nh_scpu_expect_next(cpu, 0x060FDA40u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDA40u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB48u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB49u;
            if (nh_scpu_expect_next(cpu, 0x060FDA48u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDA48u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB49u,
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
            cpu->pc = 0xFB4Bu;
            if (nh_scpu_expect_next(cpu, 0x060FDA58u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDA58u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB4Bu,
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
            cpu->pc = 0xFB4Du;
            if (nh_scpu_expect_next(cpu, 0x060FDA68u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDA68u: {
            static const uint8_t expected_epoch[] = { 0x90u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB4Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFB53u;
                if (nh_scpu_expect_next(cpu, 0x060FDA98u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB4Fu;
            if (nh_scpu_expect_next(cpu, 0x060FDA78u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDA78u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB4Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000008u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB51u;
            if (nh_scpu_expect_next(cpu, 0x060FDA88u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDA88u: {
            static const uint8_t expected_epoch[] = { 0xE6u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB51u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t result = (uint16_t)(value + 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB53u;
            if (nh_scpu_expect_next(cpu, 0x060FDA98u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDA98u: {
            static const uint8_t expected_epoch[] = { 0x88u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB53u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB54u;
            if (nh_scpu_expect_next(cpu, 0x060FDAA0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDAA0u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0xEEu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB54u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFB44u;
                if (nh_scpu_expect_next(cpu, 0x060FDA20u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB56u;
            if (nh_scpu_expect_next(cpu, 0x060FDAB0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDAB0u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB56u,
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
            if ((((((((return_key != 0x060A0D38u && return_key != 0x060A18B0u) && (return_key != 0x060A2C58u && return_key != 0x060A2D98u)) && ((return_key != 0x060FD878u && return_key != 0x060FE308u) && (return_key != 0x060FE348u && return_key != 0x0610F520u))) && (((return_key != 0x061107B8u && return_key != 0x0613F068u) && (return_key != 0x061429E0u && return_key != 0x06142D38u)) && ((return_key != 0x06143C28u && return_key != 0x06146D70u) && (return_key != 0x06185520u && return_key != 0x06186AD8u)))) && ((((return_key != 0x0618F860u && return_key != 0x0618F9A0u) && (return_key != 0x0618FAC0u && return_key != 0x061977C0u)) && ((return_key != 0x0619F8D8u && return_key != 0x061A8588u) && (return_key != 0x061AD920u && return_key != 0x061B2958u))) && (((return_key != 0x061B2A98u && return_key != 0x061B2C08u) && (return_key != 0x061CB690u && return_key != 0x0623E880u)) && ((return_key != 0x0623F8D0u && return_key != 0x06283850u) && (return_key != 0x06287280u && (return_key != 0x06287378u && return_key != 0x062998F0u)))))) && (((((return_key != 0x0629A138u && return_key != 0x0629B420u) && (return_key != 0x062AA7A8u && return_key != 0x062AAFA8u)) && ((return_key != 0x062AAFF0u && return_key != 0x062AB270u) && (return_key != 0x062AC080u && return_key != 0x062AC678u))) && (((return_key != 0x062E1900u && return_key != 0x062E1A38u) && (return_key != 0x0630BE30u && return_key != 0x06314710u)) && ((return_key != 0x063172E8u && return_key != 0x06317B68u) && (return_key != 0x0631B070u && (return_key != 0x0631B428u && return_key != 0x0631B708u))))) && ((((return_key != 0x0631B7F8u && return_key != 0x0631B8C0u) && (return_key != 0x0631B9B0u && return_key != 0x0631BDB0u)) && ((return_key != 0x0631C120u && return_key != 0x063276F8u) && (return_key != 0x063293E0u && return_key != 0x06330A78u))) && (((return_key != 0x06330BD8u && return_key != 0x0633D588u) && (return_key != 0x0633DAC0u && return_key != 0x0633DEB0u)) && ((return_key != 0x06344C60u && return_key != 0x06346858u) && (return_key != 0x06388358u && (return_key != 0x06388828u && return_key != 0x06388DC0u))))))) && ((((((return_key != 0x063898C8u && return_key != 0x0638A558u) && (return_key != 0x0638ABE0u && return_key != 0x06392D80u)) && ((return_key != 0x063B07B0u && return_key != 0x063B1158u) && (return_key != 0x063BA260u && return_key != 0x063EE270u))) && (((return_key != 0x063EEE68u && return_key != 0x063EF740u) && (return_key != 0x063F0EF8u && return_key != 0x0640F520u)) && ((return_key != 0x06412418u && return_key != 0x064124E0u) && (return_key != 0x0641D280u && return_key != 0x0641DEC8u)))) && ((((return_key != 0x06420330u && return_key != 0x06420610u) && (return_key != 0x06420AE8u && return_key != 0x06481590u)) && ((return_key != 0x064816A8u && return_key != 0x06482920u) && (return_key != 0x06483030u && return_key != 0x064837E0u))) && (((return_key != 0x064B62B0u && return_key != 0x064B6530u) && (return_key != 0x064B6750u && return_key != 0x064B68F0u)) && ((return_key != 0x064B6B08u && return_key != 0x064B6C78u) && (return_key != 0x064CB9D0u && (return_key != 0x064D5180u && return_key != 0x064E01C8u)))))) && (((((return_key != 0x064E0270u && return_key != 0x064E0330u) && (return_key != 0x064E6260u && return_key != 0x064E6328u)) && ((return_key != 0x064E63E8u && return_key != 0x065101D8u) && (return_key != 0x06510510u && return_key != 0x065108C0u))) && (((return_key != 0x06510BD0u && return_key != 0x06510D18u) && (return_key != 0x06510E70u && return_key != 0x06512B58u)) && ((return_key != 0x0652DB08u && return_key != 0x0660B608u) && (return_key != 0x06613B50u && (return_key != 0x06613C10u && return_key != 0x066A3C78u))))) && ((((return_key != 0x066A3F50u && return_key != 0x066AC7E0u) && (return_key != 0x066AC940u && return_key != 0x066ACAD8u)) && ((return_key != 0x066ACB70u && return_key != 0x066AEEA0u) && (return_key != 0x066BC2F8u && return_key != 0x066BCD50u))) && (((return_key != 0x066C3428u && return_key != 0x0670F998u) && (return_key != 0x06712768u && return_key != 0x06712A00u)) && ((return_key != 0x06713268u && return_key != 0x0671E6B0u) && (return_key != 0x0671F100u && (return_key != 0x0671F3C8u && return_key != 0x0671F8A0u)))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FDAB8u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB57u,
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
            cpu->pc = 0xFB59u;
            if (nh_scpu_expect_next(cpu, 0x060FDAC8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDAC8u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x04u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB59u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x004204u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, 0x004205u, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB5Du;
            if (nh_scpu_expect_next(cpu, 0x060FDAE8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FDAE8u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB5Du,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB5Fu;
            if (nh_scpu_expect_next(cpu, 0x060FDAFAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FDAFAu: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB5Fu,
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
            cpu->pc = 0xFB61u;
            if (nh_scpu_expect_next(cpu, 0x060FDB0Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDB0Au: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x06u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB61u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x004206u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB65u;
            if (nh_scpu_expect_next(cpu, 0x060FDB2Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FDB2Au: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB65u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB66u;
            if (nh_scpu_expect_next(cpu, 0x060FDB32u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDB32u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB66u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB67u;
            if (nh_scpu_expect_next(cpu, 0x060FDB3Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDB3Au: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB67u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB68u;
            if (nh_scpu_expect_next(cpu, 0x060FDB42u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDB42u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB68u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB69u;
            if (nh_scpu_expect_next(cpu, 0x060FDB4Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDB4Au: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB69u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB6Au;
            if (nh_scpu_expect_next(cpu, 0x060FDB52u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDB52u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB6Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB6Bu;
            if (nh_scpu_expect_next(cpu, 0x060FDB5Au) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDB5Au: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB6Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB6Cu;
            if (nh_scpu_expect_next(cpu, 0x060FDB62u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDB62u: {
            static const uint8_t expected_epoch[] = { 0xC2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB6Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB6Eu;
            if (nh_scpu_expect_next(cpu, 0x060FDB70u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FDB70u: {
            static const uint8_t expected_epoch[] = { 0xAFu, 0x14u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB6Eu,
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
            cpu->pc = 0xFB72u;
            if (nh_scpu_expect_next(cpu, 0x060FDB90u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FDB90u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB72u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB74u;
            if (nh_scpu_expect_next(cpu, 0x060FDBA0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDBA0u: {
            static const uint8_t expected_epoch[] = { 0xAFu, 0x16u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB74u,
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
            cpu->pc = 0xFB78u;
            if (nh_scpu_expect_next(cpu, 0x060FDBC0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FDBC0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB78u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000008u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB7Au;
            if (nh_scpu_expect_next(cpu, 0x060FDBD0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDBD0u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB7Au,
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
            if ((((((((return_key != 0x060A0D38u && return_key != 0x060A18B0u) && (return_key != 0x060A2C58u && return_key != 0x060A2D98u)) && ((return_key != 0x060FD878u && return_key != 0x060FE308u) && (return_key != 0x060FE348u && return_key != 0x0610F520u))) && (((return_key != 0x061107B8u && return_key != 0x0613F068u) && (return_key != 0x061429E0u && return_key != 0x06142D38u)) && ((return_key != 0x06143C28u && return_key != 0x06146D70u) && (return_key != 0x06185520u && return_key != 0x06186AD8u)))) && ((((return_key != 0x0618F860u && return_key != 0x0618F9A0u) && (return_key != 0x0618FAC0u && return_key != 0x061977C0u)) && ((return_key != 0x0619F8D8u && return_key != 0x061A8588u) && (return_key != 0x061AD920u && return_key != 0x061B2958u))) && (((return_key != 0x061B2A98u && return_key != 0x061B2C08u) && (return_key != 0x061CB690u && return_key != 0x0623E880u)) && ((return_key != 0x0623F8D0u && return_key != 0x06283850u) && (return_key != 0x06287280u && (return_key != 0x06287378u && return_key != 0x062998F0u)))))) && (((((return_key != 0x0629A138u && return_key != 0x0629B420u) && (return_key != 0x062AA7A8u && return_key != 0x062AAFA8u)) && ((return_key != 0x062AAFF0u && return_key != 0x062AB270u) && (return_key != 0x062AC080u && return_key != 0x062AC678u))) && (((return_key != 0x062E1900u && return_key != 0x062E1A38u) && (return_key != 0x0630BE30u && return_key != 0x06314710u)) && ((return_key != 0x063172E8u && return_key != 0x06317B68u) && (return_key != 0x0631B070u && (return_key != 0x0631B428u && return_key != 0x0631B708u))))) && ((((return_key != 0x0631B7F8u && return_key != 0x0631B8C0u) && (return_key != 0x0631B9B0u && return_key != 0x0631BDB0u)) && ((return_key != 0x0631C120u && return_key != 0x063276F8u) && (return_key != 0x063293E0u && return_key != 0x06330A78u))) && (((return_key != 0x06330BD8u && return_key != 0x0633D588u) && (return_key != 0x0633DAC0u && return_key != 0x0633DEB0u)) && ((return_key != 0x06344C60u && return_key != 0x06346858u) && (return_key != 0x06388358u && (return_key != 0x06388828u && return_key != 0x06388DC0u))))))) && ((((((return_key != 0x063898C8u && return_key != 0x0638A558u) && (return_key != 0x0638ABE0u && return_key != 0x06392D80u)) && ((return_key != 0x063B07B0u && return_key != 0x063B1158u) && (return_key != 0x063BA260u && return_key != 0x063EE270u))) && (((return_key != 0x063EEE68u && return_key != 0x063EF740u) && (return_key != 0x063F0EF8u && return_key != 0x0640F520u)) && ((return_key != 0x06412418u && return_key != 0x064124E0u) && (return_key != 0x0641D280u && return_key != 0x0641DEC8u)))) && ((((return_key != 0x06420330u && return_key != 0x06420610u) && (return_key != 0x06420AE8u && return_key != 0x06481590u)) && ((return_key != 0x064816A8u && return_key != 0x06482920u) && (return_key != 0x06483030u && return_key != 0x064837E0u))) && (((return_key != 0x064B62B0u && return_key != 0x064B6530u) && (return_key != 0x064B6750u && return_key != 0x064B68F0u)) && ((return_key != 0x064B6B08u && return_key != 0x064B6C78u) && (return_key != 0x064CB9D0u && (return_key != 0x064D5180u && return_key != 0x064E01C8u)))))) && (((((return_key != 0x064E0270u && return_key != 0x064E0330u) && (return_key != 0x064E6260u && return_key != 0x064E6328u)) && ((return_key != 0x064E63E8u && return_key != 0x065101D8u) && (return_key != 0x06510510u && return_key != 0x065108C0u))) && (((return_key != 0x06510BD0u && return_key != 0x06510D18u) && (return_key != 0x06510E70u && return_key != 0x06512B58u)) && ((return_key != 0x0652DB08u && return_key != 0x0660B608u) && (return_key != 0x06613B50u && (return_key != 0x06613C10u && return_key != 0x066A3C78u))))) && ((((return_key != 0x066A3F50u && return_key != 0x066AC7E0u) && (return_key != 0x066AC940u && return_key != 0x066ACAD8u)) && ((return_key != 0x066ACB70u && return_key != 0x066AEEA0u) && (return_key != 0x066BC2F8u && return_key != 0x066BCD50u))) && (((return_key != 0x066C3428u && return_key != 0x0670F998u) && (return_key != 0x06712768u && return_key != 0x06712A00u)) && ((return_key != 0x06713268u && return_key != 0x0671E6B0u) && (return_key != 0x0671F100u && (return_key != 0x0671F3C8u && return_key != 0x0671F8A0u)))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FDBD8u: {
            static const uint8_t expected_epoch[] = { 0x22u, 0x88u, 0xFBu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB7Bu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xC1u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0xFBu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)cpu->s, 0x7Eu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->s = (uint16_t)(cpu->s - 1u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB88u;
            if (nh_scpu_expect_next(cpu, 0x060FDC40u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 8u);
        }

        case 0x060FDBF8u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB7Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000020u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000021u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB81u;
            if (nh_scpu_expect_next(cpu, 0x060FDC08u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDC08u: {
            static const uint8_t expected_epoch[] = { 0x10u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB81u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFB87u;
                if (nh_scpu_expect_next(cpu, 0x060FDC38u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB83u;
            if (nh_scpu_expect_next(cpu, 0x060FDC18u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDC18u: {
            static const uint8_t expected_epoch[] = { 0x5Cu, 0x69u, 0xFDu, 0xC1u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB83u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFD69u;
            if (nh_scpu_expect_next(cpu, 0x060FEB48u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 4u);
        }

        case 0x060FDC38u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB87u,
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
            if (((((((return_key != 0x06086580u && (return_key != 0x06086AE0u && return_key != 0x06086C60u)) && (return_key != 0x06087258u && (return_key != 0x060A09D0u && return_key != 0x060A1828u))) && ((return_key != 0x060A23E0u && (return_key != 0x060A2648u && return_key != 0x060A5DE0u)) && (return_key != 0x060A7098u && (return_key != 0x060AF1B8u && return_key != 0x060AF868u)))) && (((return_key != 0x060C2F48u && (return_key != 0x060C4A98u && return_key != 0x060C4BD0u)) && (return_key != 0x060C5188u && (return_key != 0x0610FC58u && return_key != 0x06110298u))) && ((return_key != 0x061468F8u && (return_key != 0x06148970u && return_key != 0x06148B00u)) && (return_key != 0x0614D7C0u && (return_key != 0x0618E608u && return_key != 0x061CB9B8u))))) && ((((return_key != 0x06283510u && (return_key != 0x06287770u && return_key != 0x0628F7E0u)) && (return_key != 0x062923C8u && (return_key != 0x06292868u && return_key != 0x06299DD0u))) && ((return_key != 0x06305178u && (return_key != 0x06312B00u && return_key != 0x063315D0u)) && (return_key != 0x06345B70u && (return_key != 0x06345E48u && return_key != 0x06346288u)))) && (((return_key != 0x0634AA80u && (return_key != 0x063AFF98u && return_key != 0x063B3510u)) && (return_key != 0x063D94B8u && (return_key != 0x063DA438u && return_key != 0x063DB930u))) && ((return_key != 0x063DCB00u && (return_key != 0x063EB700u && return_key != 0x063FA1D8u)) && (return_key != 0x063FA328u && (return_key != 0x063FA428u && return_key != 0x06400348u)))))) && (((((return_key != 0x064005A0u && (return_key != 0x06400770u && return_key != 0x06409950u)) && (return_key != 0x0640CF88u && (return_key != 0x0640D160u && return_key != 0x0640D538u))) && ((return_key != 0x0640DA08u && (return_key != 0x06411848u && return_key != 0x064119A0u)) && (return_key != 0x06415848u && (return_key != 0x06480C30u && return_key != 0x064810F0u)))) && (((return_key != 0x06481200u && (return_key != 0x064839F8u && return_key != 0x06484020u)) && (return_key != 0x064898D0u && (return_key != 0x064920B0u && return_key != 0x06492318u))) && ((return_key != 0x06492598u && (return_key != 0x064926E0u && return_key != 0x06498920u)) && (return_key != 0x064B6410u && (return_key != 0x064C4908u && return_key != 0x064CAE00u))))) && ((((return_key != 0x06534470u && (return_key != 0x06537610u && return_key != 0x0653AFF0u)) && (return_key != 0x0654B528u && (return_key != 0x0661C970u && return_key != 0x06621950u))) && ((return_key != 0x06621DC8u && (return_key != 0x06622A08u && return_key != 0x06622F48u)) && (return_key != 0x06623488u && (return_key != 0x066289B8u && return_key != 0x0662AF48u)))) && (((return_key != 0x0665B768u && (return_key != 0x0665FF20u && return_key != 0x06667338u)) && (return_key != 0x066A6F70u && (return_key != 0x066A7E18u && return_key != 0x066A8310u))) && ((return_key != 0x066A91B8u && (return_key != 0x0670F2E0u && return_key != 0x0670F838u)) && ((return_key != 0x06712190u && return_key != 0x0671AAE8u) && (return_key != 0x0671AEF0u && return_key != 0x0671DFC8u))))))))
                return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_RTL_CONTINUATION");
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FDC40u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB88u,
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
            cpu->pc = 0xFB8Au;
            if (nh_scpu_expect_next(cpu, 0x060FDC50u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDC50u: {
            static const uint8_t expected_epoch[] = { 0x45u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB8Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000006u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000007u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = (uint16_t)(cpu->a ^ (uint16_t)(low | ((uint16_t)high << 8u)));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB8Cu;
            if (nh_scpu_expect_next(cpu, 0x060FDC60u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDC60u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB8Cu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000020u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000021u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB8Eu;
            if (nh_scpu_expect_next(cpu, 0x060FDC70u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDC70u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB8Eu,
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
            cpu->pc = 0xFB90u;
            if (nh_scpu_expect_next(cpu, 0x060FDC80u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDC80u: {
            static const uint8_t expected_epoch[] = { 0x10u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB90u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFBA1u;
                if (nh_scpu_expect_next(cpu, 0x060FDD08u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB92u;
            if (nh_scpu_expect_next(cpu, 0x060FDC90u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDC90u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB92u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB93u;
            if (nh_scpu_expect_next(cpu, 0x060FDC98u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDC98u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB93u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB96u;
            if (nh_scpu_expect_next(cpu, 0x060FDCB0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FDCB0u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB96u,
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
            cpu->pc = 0xFB98u;
            if (nh_scpu_expect_next(cpu, 0x060FDCC0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDCC0u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB98u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB9Au;
            if (nh_scpu_expect_next(cpu, 0x060FDCD0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDCD0u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB9Au,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFB9Du;
            if (nh_scpu_expect_next(cpu, 0x060FDCE8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FDCE8u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB9Du,
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
            cpu->pc = 0xFB9Fu;
            if (nh_scpu_expect_next(cpu, 0x060FDCF8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDCF8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FB9Fu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000002u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000003u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBA1u;
            if (nh_scpu_expect_next(cpu, 0x060FDD08u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDD08u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBA1u,
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
            cpu->pc = 0xFBA3u;
            if (nh_scpu_expect_next(cpu, 0x060FDD18u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDD18u: {
            static const uint8_t expected_epoch[] = { 0x10u, 0x0Fu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBA3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_N) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFBB4u;
                if (nh_scpu_expect_next(cpu, 0x060FDDA0u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBA5u;
            if (nh_scpu_expect_next(cpu, 0x060FDD28u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDD28u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBA5u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBA6u;
            if (nh_scpu_expect_next(cpu, 0x060FDD30u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDD30u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBA6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBA9u;
            if (nh_scpu_expect_next(cpu, 0x060FDD48u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FDD48u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBA9u,
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
            cpu->pc = 0xFBABu;
            if (nh_scpu_expect_next(cpu, 0x060FDD58u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDD58u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBABu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000004u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000005u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBADu;
            if (nh_scpu_expect_next(cpu, 0x060FDD68u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDD68u: {
            static const uint8_t expected_epoch[] = { 0xA9u, 0x00u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBADu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->a = 0x0000u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->a) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->a) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBB0u;
            if (nh_scpu_expect_next(cpu, 0x060FDD80u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FDD80u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBB0u,
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
            cpu->pc = 0xFBB2u;
            if (nh_scpu_expect_next(cpu, 0x060FDD90u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDD90u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBB2u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000006u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000007u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBB4u;
            if (nh_scpu_expect_next(cpu, 0x060FDDA0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDDA0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBB4u,
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
            cpu->pc = 0xFBB6u;
            if (nh_scpu_expect_next(cpu, 0x060FDDB0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDDB0u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0x07u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBB6u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFBBFu;
                if (nh_scpu_expect_next(cpu, 0x060FDDF8u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBB8u;
            if (nh_scpu_expect_next(cpu, 0x060FDDC0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDDC0u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBB8u,
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
            cpu->pc = 0xFBBAu;
            if (nh_scpu_expect_next(cpu, 0x060FDDD0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDDD0u: {
            static const uint8_t expected_epoch[] = { 0xC9u, 0x00u, 0x01u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBBAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t left = cpu->a;
            const uint16_t result = (uint16_t)(left - 0x0100u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z | NH_P_C));
            if (left >= 0x0100u) cpu->p |= NH_P_C;
            if (result == 0u) cpu->p |= NH_P_Z;
            if ((result & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBBDu;
            if (nh_scpu_expect_next(cpu, 0x060FDDE8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FDDE8u: {
            static const uint8_t expected_epoch[] = { 0x90u, 0x28u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBBDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFBE7u;
                if (nh_scpu_expect_next(cpu, 0x060FDF38u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBBFu;
            if (nh_scpu_expect_next(cpu, 0x060FDDF8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDDF8u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBBFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000008u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBC1u;
            if (nh_scpu_expect_next(cpu, 0x060FDE08u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDE08u: {
            static const uint8_t expected_epoch[] = { 0x64u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBC1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), 0u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBC3u;
            if (nh_scpu_expect_next(cpu, 0x060FDE18u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDE18u: {
            static const uint8_t expected_epoch[] = { 0xA0u, 0x20u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBC3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = 0x0020u;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBC6u;
            if (nh_scpu_expect_next(cpu, 0x060FDE30u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FDE30u: {
            static const uint8_t expected_epoch[] = { 0x06u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBC6u,
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
            cpu->pc = 0xFBC8u;
            if (nh_scpu_expect_next(cpu, 0x060FDE40u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDE40u: {
            static const uint8_t expected_epoch[] = { 0x26u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBC8u,
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
            cpu->pc = 0xFBCAu;
            if (nh_scpu_expect_next(cpu, 0x060FDE50u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDE50u: {
            static const uint8_t expected_epoch[] = { 0x26u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBCAu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000008u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t old = (uint16_t)(low | ((uint16_t)high << 8u));
            const uint16_t result = (uint16_t)(((uint32_t)old << 1u) | ((cpu->p & NH_P_C) != 0u ? 1u : 0u));
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000008u) & 0xFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | ((old >> 15u) & 1u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBCCu;
            if (nh_scpu_expect_next(cpu, 0x060FDE60u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDE60u: {
            static const uint8_t expected_epoch[] = { 0x26u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBCCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), &low) != NH_SCPU_EXECUTED ||
                nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t old = (uint16_t)(low | ((uint16_t)high << 8u));
            const uint16_t result = (uint16_t)(((uint32_t)old << 1u) | ((cpu->p & NH_P_C) != 0u ? 1u : 0u));
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)((cpu->p & (uint8_t)~NH_P_C) | ((old >> 15u) & 1u));
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBCEu;
            if (nh_scpu_expect_next(cpu, 0x060FDE70u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDE70u: {
            static const uint8_t expected_epoch[] = { 0x38u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBCEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p |= NH_P_C;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBCFu;
            if (nh_scpu_expect_next(cpu, 0x060FDE78u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDE78u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBCFu,
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
            cpu->pc = 0xFBD1u;
            if (nh_scpu_expect_next(cpu, 0x060FDE88u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDE88u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBD1u,
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
            cpu->pc = 0xFBD3u;
            if (nh_scpu_expect_next(cpu, 0x060FDE98u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDE98u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x22u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBD3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000022u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000023u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBD5u;
            if (nh_scpu_expect_next(cpu, 0x060FDEA8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDEA8u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBD5u,
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
            cpu->pc = 0xFBD7u;
            if (nh_scpu_expect_next(cpu, 0x060FDEB8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDEB8u: {
            static const uint8_t expected_epoch[] = { 0xE5u, 0x06u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBD7u,
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
            cpu->pc = 0xFBD9u;
            if (nh_scpu_expect_next(cpu, 0x060FDEC8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDEC8u: {
            static const uint8_t expected_epoch[] = { 0x90u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBD9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_C) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFBE3u;
                if (nh_scpu_expect_next(cpu, 0x060FDF18u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBDBu;
            if (nh_scpu_expect_next(cpu, 0x060FDED8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDED8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBDBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBDDu;
            if (nh_scpu_expect_next(cpu, 0x060FDEE8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDEE8u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x22u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBDDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000022u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000023u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            cpu->a = value;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(value) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(value) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBDFu;
            if (nh_scpu_expect_next(cpu, 0x060FDEF8u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDEF8u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBDFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000008u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBE1u;
            if (nh_scpu_expect_next(cpu, 0x060FDF08u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDF08u: {
            static const uint8_t expected_epoch[] = { 0xE6u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBE1u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            uint8_t low = 0u, high = 0u;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), &low) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_read8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), &high) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            const uint16_t value = (uint16_t)(((uint16_t)high << 8u) | low);
            const uint16_t result = (uint16_t)(value + 1u);
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000001u) & 0xFFFFu), (uint8_t)(result >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000000u) & 0xFFFFu), (uint8_t)result) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(result) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(result) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBE3u;
            if (nh_scpu_expect_next(cpu, 0x060FDF18u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (7u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDF18u: {
            static const uint8_t expected_epoch[] = { 0x88u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBE3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->y = (uint16_t)(cpu->y - 1u);
            cpu->p = (uint8_t)(cpu->p & (uint8_t)~(NH_P_N | NH_P_Z));
            if (((uint16_t)(cpu->y) & 0xFFFFu) == 0u) cpu->p |= NH_P_Z;
            if (((uint16_t)(cpu->y) & 0x8000u) != 0u) cpu->p |= NH_P_N;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBE4u;
            if (nh_scpu_expect_next(cpu, 0x060FDF20u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDF20u: {
            static const uint8_t expected_epoch[] = { 0xD0u, 0xE0u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBE4u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if ((cpu->p & NH_P_Z) == 0u) {
                cpu->pbr = 0xC1u;
                cpu->pc = 0xFBC6u;
                if (nh_scpu_expect_next(cpu, 0x060FDE30u) != NH_SCPU_EXECUTED)
                    return NH_SCPU_STOPPED;
                return nh_scpu_finish(cpu, bus, 3u);
            }
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBE6u;
            if (nh_scpu_expect_next(cpu, 0x060FDF30u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDF30u: {
            static const uint8_t expected_epoch[] = { 0x6Bu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBE6u,
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

        case 0x060FDF38u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBE7u,
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
            cpu->pc = 0xFBE9u;
            if (nh_scpu_expect_next(cpu, 0x060FDF48u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDF48u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x08u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBE9u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000008u) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x000009u) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBEBu;
            if (nh_scpu_expect_next(cpu, 0x060FDF58u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDF58u: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x02u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBEBu,
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
            cpu->pc = 0xFBEDu;
            if (nh_scpu_expect_next(cpu, 0x060FDF68u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDF68u: {
            static const uint8_t expected_epoch[] = { 0x85u, 0x0Au };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBEDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Au) & 0xFFFFu), (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, (uint32_t)((cpu->d + 0x00000Bu) & 0xFFFFu), (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBEFu;
            if (nh_scpu_expect_next(cpu, 0x060FDF78u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (4u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDF78u: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x04u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBEFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x004204u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED ||
                nh_scpu_write8(cpu, bus, 0x004205u, (uint8_t)(cpu->a >> 8u)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBF3u;
            if (nh_scpu_expect_next(cpu, 0x060FDF98u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 6u);
        }

        case 0x060FDF98u: {
            static const uint8_t expected_epoch[] = { 0xE2u, 0x20u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBF3u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->p = (uint8_t)(cpu->p | 0x20u);
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBF5u;
            if (nh_scpu_expect_next(cpu, 0x060FDFAAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 3u);
        }

        case 0x060FDFAAu: {
            static const uint8_t expected_epoch[] = { 0xA5u, 0x04u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBF5u,
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
            cpu->pc = 0xFBF7u;
            if (nh_scpu_expect_next(cpu, 0x060FDFBAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, (3u) + ((cpu->d & 0x00FFu) != 0u ? 1u : 0u));
        }

        case 0x060FDFBAu: {
            static const uint8_t expected_epoch[] = { 0x8Fu, 0x06u, 0x42u, 0x00u };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBF7u,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            if (nh_scpu_write8(cpu, bus, 0x004206u, (uint8_t)cpu->a) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBFBu;
            if (nh_scpu_expect_next(cpu, 0x060FDFDAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 5u);
        }

        case 0x060FDFDAu: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBFBu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBFCu;
            if (nh_scpu_expect_next(cpu, 0x060FDFE2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDFE2u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBFCu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBFDu;
            if (nh_scpu_expect_next(cpu, 0x060FDFEAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDFEAu: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBFDu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBFEu;
            if (nh_scpu_expect_next(cpu, 0x060FDFF2u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDFF2u: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBFEu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFBFFu;
            if (nh_scpu_expect_next(cpu, 0x060FDFFAu) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        case 0x060FDFFAu: {
            static const uint8_t expected_epoch[] = { 0xEAu };
            if (nh_scpu_guard_code(cpu, bus, 0xC1FBFFu,
                                   expected_epoch, sizeof(expected_epoch)) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            cpu->pbr = 0xC1u;
            cpu->pc = 0xFC00u;
            if (nh_scpu_expect_next(cpu, 0x060FE002u) != NH_SCPU_EXECUTED)
                return NH_SCPU_STOPPED;
            return nh_scpu_finish(cpu, bus, 2u);
        }

        default: return NH_SCPU_NOT_MINE;
    }
}
