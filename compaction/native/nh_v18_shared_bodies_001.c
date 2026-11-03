#include "nh_v18_shared.h"
NHScpuExecResult nh_v18_body_0010(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0xF0u , ((unsigned int)nhp[0]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[1]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; if ( ( cpu -> p & NH_P_Z ) != 0u ) { cpu -> pbr = ((unsigned int)nhp[2]) ; cpu -> pc = ((unsigned int)nhp[3]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[4]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 3u ) ; } cpu -> pbr = ((unsigned int)nhp[2]) ; cpu -> pc = ((unsigned int)nhp[5]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[6]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 2u ) ;
}

NHScpuExecResult nh_v18_body_0011(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0xC2u , ((unsigned int)nhp[0]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[1]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> p = ( uint8_t ) ( cpu -> p & ( uint8_t ) ~ ((unsigned int)nhp[0]) ) ; cpu -> pbr = ((unsigned int)nhp[2]) ; cpu -> pc = ((unsigned int)nhp[3]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[4]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 3u ) ;
}

NHScpuExecResult nh_v18_body_0012(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0xE2u , 0x20u } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[0]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> p = ( uint8_t ) ( cpu -> p | 0x20u ) ; cpu -> pbr = ((unsigned int)nhp[1]) ; cpu -> pc = ((unsigned int)nhp[2]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[3]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 3u ) ;
}

NHScpuExecResult nh_v18_body_0013(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0x80u , ((unsigned int)nhp[0]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[1]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> pbr = ((unsigned int)nhp[2]) ; cpu -> pc = ((unsigned int)nhp[3]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[4]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 3u ) ;
}

NHScpuExecResult nh_v18_body_0014(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0x1Au } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[0]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> a = ( uint16_t ) ( cpu -> a + 1u ) ; cpu -> p = ( uint8_t ) ( cpu -> p & ( uint8_t ) ~ ( NH_P_N | NH_P_Z ) ) ; if ( ( ( uint16_t ) ( cpu -> a ) & 0xFFFFu ) == 0u ) cpu -> p |= NH_P_Z ; if ( ( ( uint16_t ) ( cpu -> a ) & 0x8000u ) != 0u ) cpu -> p |= NH_P_N ; cpu -> pbr = ((unsigned int)nhp[1]) ; cpu -> pc = ((unsigned int)nhp[2]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[3]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 2u ) ;
}

NHScpuExecResult nh_v18_body_0015(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0x64u , ((unsigned int)nhp[0]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[1]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; if ( nh_scpu_write8 ( cpu , bus , ( uint32_t ) ( ( cpu -> d + ((unsigned int)nhp[2]) ) & 0xFFFFu ) , 0u ) != NH_SCPU_EXECUTED || nh_scpu_write8 ( cpu , bus , ( uint32_t ) ( ( cpu -> d + ((unsigned int)nhp[3]) ) & 0xFFFFu ) , 0u ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> pbr = ((unsigned int)nhp[4]) ; cpu -> pc = ((unsigned int)nhp[5]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[6]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , ( 4u ) + ( ( cpu -> d & 0x00FFu ) != 0u ? 1u : 0u ) ) ;
}

NHScpuExecResult nh_v18_body_0016(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0x0Au } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[0]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; const uint16_t value = cpu -> a ; cpu -> a = ( uint16_t ) ( value << 1u ) ; cpu -> p = ( uint8_t ) ( cpu -> p & ( uint8_t ) ~ NH_P_C ) ; if ( ( value & 0x8000u ) != 0u ) cpu -> p |= NH_P_C ; cpu -> p = ( uint8_t ) ( cpu -> p & ( uint8_t ) ~ ( NH_P_N | NH_P_Z ) ) ; if ( ( ( uint16_t ) ( cpu -> a ) & 0xFFFFu ) == 0u ) cpu -> p |= NH_P_Z ; if ( ( ( uint16_t ) ( cpu -> a ) & 0x8000u ) != 0u ) cpu -> p |= NH_P_N ; cpu -> pbr = ((unsigned int)nhp[1]) ; cpu -> pc = ((unsigned int)nhp[2]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[3]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 2u ) ;
}

NHScpuExecResult nh_v18_body_0017(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0x3Bu } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[0]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> a = cpu -> s ; cpu -> p = ( uint8_t ) ( cpu -> p & ( uint8_t ) ~ ( NH_P_N | NH_P_Z ) ) ; if ( ( ( uint16_t ) ( cpu -> a ) & 0xFFFFu ) == 0u ) cpu -> p |= NH_P_Z ; if ( ( ( uint16_t ) ( cpu -> a ) & 0x8000u ) != 0u ) cpu -> p |= NH_P_N ; cpu -> pbr = ((unsigned int)nhp[1]) ; cpu -> pc = ((unsigned int)nhp[2]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[3]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 2u ) ;
}

NHScpuExecResult nh_v18_body_0018(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0xD4u , ((unsigned int)nhp[0]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[1]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; uint8_t pointer_low = 0u , pointer_high = 0u ; if ( nh_scpu_read8 ( cpu , bus , ( uint32_t ) ( ( cpu -> d + ((unsigned int)nhp[2]) ) & 0xFFFFu ) , & pointer_low ) != NH_SCPU_EXECUTED || nh_scpu_read8 ( cpu , bus , ( uint32_t ) ( ( cpu -> d + ((unsigned int)nhp[3]) ) & 0xFFFFu ) , & pointer_high ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; if ( nh_scpu_write8 ( cpu , bus , ( uint32_t ) cpu -> s , pointer_high ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> s = ( uint16_t ) ( cpu -> s - 1u ) ; if ( nh_scpu_write8 ( cpu , bus , ( uint32_t ) cpu -> s , pointer_low ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> s = ( uint16_t ) ( cpu -> s - 1u ) ; cpu -> pbr = ((unsigned int)nhp[4]) ; cpu -> pc = ((unsigned int)nhp[5]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[6]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , ( 6u ) + ( ( cpu -> d & 0x00FFu ) != 0u ? 1u : 0u ) ) ;
}

NHScpuExecResult nh_v18_body_0019(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0x6Bu } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[0]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; uint8_t low = 0u , high = 0u , return_bank = 0u ; if ( nh_scpu_pull8 ( cpu , bus , & low ) != NH_SCPU_EXECUTED || nh_scpu_pull8 ( cpu , bus , & high ) != NH_SCPU_EXECUTED || nh_scpu_pull8 ( cpu , bus , & return_bank ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> pc = ( uint16_t ) ( ( ( ( uint16_t ) high << 8u ) | low ) + 1u ) ; cpu -> pbr = return_bank ; if ( nh_scpu_context_key ( cpu ) != ((unsigned int)nhp[1]) ) return nh_scpu_stop ( cpu , nh_scpu_address ( cpu ) , "UNPROVED_RTL_CONTINUATION" ) ; return nh_scpu_finish ( cpu , bus , 6u ) ;
}

NHScpuExecResult nh_v18_body_001A(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0xB1u , ((unsigned int)nhp[0]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[1]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; uint8_t pointer_low = 0u , pointer_high = 0u , low = 0u , high = 0u ; if ( nh_scpu_read8 ( cpu , bus , ( uint32_t ) ( ( cpu -> d + ((unsigned int)nhp[2]) ) & 0xFFFFu ) , & pointer_low ) != NH_SCPU_EXECUTED || nh_scpu_read8 ( cpu , bus , ( uint32_t ) ( ( cpu -> d + ((unsigned int)nhp[3]) ) & 0xFFFFu ) , & pointer_high ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; const uint32_t address = ( ( ( ( uint32_t ) cpu -> dbr << 16u ) | ( ( uint32_t ) pointer_high << 8u ) | pointer_low ) + cpu -> y ) & 0xFFFFFFu ; if ( nh_scpu_read8 ( cpu , bus , address , & low ) != NH_SCPU_EXECUTED || nh_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , & high ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> a = ( uint16_t ) ( low | ( ( uint16_t ) high << 8u ) ) ; cpu -> p = ( uint8_t ) ( cpu -> p & ( uint8_t ) ~ ( NH_P_N | NH_P_Z ) ) ; if ( ( ( uint16_t ) ( cpu -> a ) & 0xFFFFu ) == 0u ) cpu -> p |= NH_P_Z ; if ( ( ( uint16_t ) ( cpu -> a ) & 0x8000u ) != 0u ) cpu -> p |= NH_P_N ; cpu -> pbr = ((unsigned int)nhp[4]) ; cpu -> pc = ((unsigned int)nhp[5]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[6]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , ( 7u ) + ( ( cpu -> d & 0x00FFu ) != 0u ? 1u : 0u ) ) ;
}

NHScpuExecResult nh_v18_body_001B(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0xA7u , ((unsigned int)nhp[0]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[1]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; uint8_t lo = 0u , hi = 0u ; uint32_t address ; uint8_t bank = 0u ; if ( nh_scpu_read8 ( cpu , bus , ( uint32_t ) ( ( cpu -> d + ((unsigned int)nhp[2]) ) & 0xFFFFu ) , & lo ) != NH_SCPU_EXECUTED || nh_scpu_read8 ( cpu , bus , ( uint32_t ) ( ( cpu -> d + ((unsigned int)nhp[3]) ) & 0xFFFFu ) , & hi ) != NH_SCPU_EXECUTED || nh_scpu_read8 ( cpu , bus , ( uint32_t ) ( ( cpu -> d + ((unsigned int)nhp[4]) ) & 0xFFFFu ) , & bank ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; address = ( ( uint32_t ) bank << 16 ) | ( ( uint32_t ) hi << 8 ) | ( uint32_t ) lo ; if ( nh_scpu_read8 ( cpu , bus , address , & lo ) != NH_SCPU_EXECUTED || nh_scpu_read8 ( cpu , bus , ( address + 1u ) & 0x00FFFFFFu , & hi ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; const uint16_t right = ( uint16_t ) ( ( uint16_t ) lo | ( ( uint16_t ) hi << 8 ) ) ; cpu -> a = right ; cpu -> p = ( uint8_t ) ( cpu -> p & ( uint8_t ) ~ ( NH_P_N | NH_P_Z ) ) ; if ( ( ( uint16_t ) ( cpu -> a ) & 0xFFFFu ) == 0u ) cpu -> p |= NH_P_Z ; if ( ( ( uint16_t ) ( cpu -> a ) & 0x8000u ) != 0u ) cpu -> p |= NH_P_N ; cpu -> pbr = ((unsigned int)nhp[5]) ; cpu -> pc = ((unsigned int)nhp[6]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[7]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , ( 7u ) + ( ( cpu -> d & 0x00FFu ) != 0u ? 1u : 0u ) ) ;
}

NHScpuExecResult nh_v18_body_001C(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0xC9u , ((unsigned int)nhp[0]) , ((unsigned int)nhp[1]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[2]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; const uint16_t left = cpu -> a ; const uint16_t result = ( uint16_t ) ( left - ((unsigned int)nhp[3]) ) ; cpu -> p = ( uint8_t ) ( cpu -> p & ( uint8_t ) ~ ( NH_P_N | NH_P_Z | NH_P_C ) ) ; if ( left >= ((unsigned int)nhp[3]) ) cpu -> p |= NH_P_C ; if ( result == 0u ) cpu -> p |= NH_P_Z ; if ( ( result & 0x8000u ) != 0u ) cpu -> p |= NH_P_N ; cpu -> pbr = ((unsigned int)nhp[4]) ; cpu -> pc = ((unsigned int)nhp[5]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[6]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 3u ) ;
}

NHScpuExecResult nh_v18_body_001D(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0x1Bu } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[0]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> s = cpu -> a ; cpu -> pbr = ((unsigned int)nhp[1]) ; cpu -> pc = ((unsigned int)nhp[2]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[3]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 2u ) ;
}

NHScpuExecResult nh_v18_body_001E(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0xB7u , ((unsigned int)nhp[0]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[1]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; uint8_t pointer_low = 0u , pointer_high = 0u ; if ( nh_scpu_read8 ( cpu , bus , ( uint32_t ) ( ( cpu -> d + ((unsigned int)nhp[2]) ) & 0xFFFFu ) , & pointer_low ) != NH_SCPU_EXECUTED || nh_scpu_read8 ( cpu , bus , ( uint32_t ) ( ( cpu -> d + ((unsigned int)nhp[3]) ) & 0xFFFFu ) , & pointer_high ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; uint8_t pointer_bank = 0u , low = 0u , high = 0u ; if ( nh_scpu_read8 ( cpu , bus , ( uint32_t ) ( ( cpu -> d + ((unsigned int)nhp[4]) ) & 0xFFFFu ) , & pointer_bank ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; const uint32_t address = ( ( ( ( uint32_t ) pointer_bank << 16u ) | ( ( uint32_t ) pointer_high << 8u ) | pointer_low ) + cpu -> y ) & 0xFFFFFFu ; if ( nh_scpu_read8 ( cpu , bus , address , & low ) != NH_SCPU_EXECUTED || nh_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , & high ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> a = ( uint16_t ) ( low | ( ( uint16_t ) high << 8u ) ) ; cpu -> p = ( uint8_t ) ( cpu -> p & ( uint8_t ) ~ ( NH_P_N | NH_P_Z ) ) ; if ( ( ( uint16_t ) ( cpu -> a ) & 0xFFFFu ) == 0u ) cpu -> p |= NH_P_Z ; if ( ( ( uint16_t ) ( cpu -> a ) & 0x8000u ) != 0u ) cpu -> p |= NH_P_N ; cpu -> pbr = ((unsigned int)nhp[5]) ; cpu -> pc = ((unsigned int)nhp[6]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[7]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , ( 7u ) + ( ( cpu -> d & 0x00FFu ) != 0u ? 1u : 0u ) ) ;
}

NHScpuExecResult nh_v18_body_001F(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0x8Fu , ((unsigned int)nhp[0]) , ((unsigned int)nhp[1]) , ((unsigned int)nhp[2]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[3]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; if ( nh_scpu_write8 ( cpu , bus , ((unsigned int)nhp[4]) , ( uint8_t ) cpu -> a ) != NH_SCPU_EXECUTED || nh_scpu_write8 ( cpu , bus , ((unsigned int)nhp[5]) , ( uint8_t ) ( cpu -> a >> 8u ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> pbr = ((unsigned int)nhp[6]) ; cpu -> pc = ((unsigned int)nhp[7]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[8]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 6u ) ;
}

