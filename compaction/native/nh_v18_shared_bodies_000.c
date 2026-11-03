#include "nh_v18_shared.h"
NHScpuExecResult nh_v18_body_0000(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0x85u , ((unsigned int)nhp[0]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[1]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; if ( nh_scpu_write8 ( cpu , bus , ( uint32_t ) ( ( cpu -> d + ((unsigned int)nhp[2]) ) & 0xFFFFu ) , ( uint8_t ) cpu -> a ) != NH_SCPU_EXECUTED || nh_scpu_write8 ( cpu , bus , ( uint32_t ) ( ( cpu -> d + ((unsigned int)nhp[3]) ) & 0xFFFFu ) , ( uint8_t ) ( cpu -> a >> 8u ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> pbr = ((unsigned int)nhp[4]) ; cpu -> pc = ((unsigned int)nhp[5]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[6]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , ( 4u ) + ( ( cpu -> d & 0x00FFu ) != 0u ? 1u : 0u ) ) ;
}

NHScpuExecResult nh_v18_body_0001(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0x68u } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[0]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; uint8_t low = 0u , high = 0u ; if ( nh_scpu_pull8 ( cpu , bus , & low ) != NH_SCPU_EXECUTED || nh_scpu_pull8 ( cpu , bus , & high ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> a = ( uint16_t ) ( ( ( uint16_t ) high << 8u ) | low ) ; cpu -> p = ( uint8_t ) ( cpu -> p & ( uint8_t ) ~ ( NH_P_N | NH_P_Z ) ) ; if ( ( ( uint16_t ) ( cpu -> a ) & 0xFFFFu ) == 0u ) cpu -> p |= NH_P_Z ; if ( ( ( uint16_t ) ( cpu -> a ) & 0x8000u ) != 0u ) cpu -> p |= NH_P_N ; cpu -> pbr = ((unsigned int)nhp[1]) ; cpu -> pc = ((unsigned int)nhp[2]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[3]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 5u ) ;
}

NHScpuExecResult nh_v18_body_0002(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0x22u , ((unsigned int)nhp[0]) , ((unsigned int)nhp[1]) , ((unsigned int)nhp[2]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[3]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; if ( nh_scpu_write8 ( cpu , bus , ( uint32_t ) cpu -> s , ((unsigned int)nhp[4]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> s = ( uint16_t ) ( cpu -> s - 1u ) ; if ( nh_scpu_write8 ( cpu , bus , ( uint32_t ) cpu -> s , ((unsigned int)nhp[5]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> s = ( uint16_t ) ( cpu -> s - 1u ) ; if ( nh_scpu_write8 ( cpu , bus , ( uint32_t ) cpu -> s , ((unsigned int)nhp[6]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> s = ( uint16_t ) ( cpu -> s - 1u ) ; cpu -> pbr = ((unsigned int)nhp[2]) ; cpu -> pc = ((unsigned int)nhp[7]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[8]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 8u ) ;
}

NHScpuExecResult nh_v18_body_0003(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { ((unsigned int)nhp[0]) , ((unsigned int)nhp[1]) , ((unsigned int)nhp[2]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[3]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; if ( nh_scpu_write8 ( cpu , bus , ( uint32_t ) cpu -> s , ((unsigned int)nhp[4]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> s = ( uint16_t ) ( cpu -> s - 1u ) ; if ( nh_scpu_write8 ( cpu , bus , ( uint32_t ) cpu -> s , ((unsigned int)nhp[5]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> s = ( uint16_t ) ( cpu -> s - 1u ) ; cpu -> pbr = ((unsigned int)nhp[6]) ; cpu -> pc = ((unsigned int)nhp[7]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[8]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , ((unsigned int)nhp[9]) ) ;
}

NHScpuExecResult nh_v18_body_0004(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0xA3u , ((unsigned int)nhp[0]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[1]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; uint8_t low = 0u , high = 0u ; uint32_t address ; address = ( ( uint32_t ) cpu -> s + ((unsigned int)nhp[0]) ) & 0xFFFFu ; if ( nh_scpu_read8 ( cpu , bus , address , & low ) != NH_SCPU_EXECUTED || nh_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFu , & high ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; const uint16_t right = ( uint16_t ) ( low | ( ( uint16_t ) high << 8u ) ) ; cpu -> a = right ; cpu -> p = ( uint8_t ) ( cpu -> p & ( uint8_t ) ~ ( NH_P_N | NH_P_Z ) ) ; if ( ( ( uint16_t ) ( cpu -> a ) & 0xFFFFu ) == 0u ) cpu -> p |= NH_P_Z ; if ( ( ( uint16_t ) ( cpu -> a ) & 0x8000u ) != 0u ) cpu -> p |= NH_P_N ; cpu -> pbr = ((unsigned int)nhp[2]) ; cpu -> pc = ((unsigned int)nhp[3]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[4]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 5u ) ;
}

NHScpuExecResult nh_v18_body_0005(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0xA5u , ((unsigned int)nhp[0]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[1]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; uint8_t low = 0u , high = 0u ; if ( nh_scpu_read8 ( cpu , bus , ( uint32_t ) ( ( cpu -> d + ((unsigned int)nhp[2]) ) & 0xFFFFu ) , & low ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; if ( nh_scpu_read8 ( cpu , bus , ( uint32_t ) ( ( cpu -> d + ((unsigned int)nhp[3]) ) & 0xFFFFu ) , & high ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; const uint16_t value = ( uint16_t ) ( ( ( uint16_t ) high << 8u ) | low ) ; cpu -> a = value ; cpu -> p = ( uint8_t ) ( cpu -> p & ( uint8_t ) ~ ( NH_P_N | NH_P_Z ) ) ; if ( ( ( uint16_t ) ( value ) & 0xFFFFu ) == 0u ) cpu -> p |= NH_P_Z ; if ( ( ( uint16_t ) ( value ) & 0x8000u ) != 0u ) cpu -> p |= NH_P_N ; cpu -> pbr = ((unsigned int)nhp[4]) ; cpu -> pc = ((unsigned int)nhp[5]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[6]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , ( 4u ) + ( ( cpu -> d & 0x00FFu ) != 0u ? 1u : 0u ) ) ;
}

NHScpuExecResult nh_v18_body_0006(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0xA9u , ((unsigned int)nhp[0]) , ((unsigned int)nhp[1]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[2]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> a = ((unsigned int)nhp[3]) ; cpu -> p = ( uint8_t ) ( cpu -> p & ( uint8_t ) ~ ( NH_P_N | NH_P_Z ) ) ; if ( ( ( uint16_t ) ( cpu -> a ) & 0xFFFFu ) == 0u ) cpu -> p |= NH_P_Z ; if ( ( ( uint16_t ) ( cpu -> a ) & 0x8000u ) != 0u ) cpu -> p |= NH_P_N ; cpu -> pbr = ((unsigned int)nhp[4]) ; cpu -> pc = ((unsigned int)nhp[5]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[6]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 3u ) ;
}

NHScpuExecResult nh_v18_body_0007(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0x48u } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[0]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; if ( nh_scpu_write8 ( cpu , bus , ( uint32_t ) cpu -> s , ( uint8_t ) ( cpu -> a >> 8u ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> s = ( uint16_t ) ( cpu -> s - 1u ) ; if ( nh_scpu_write8 ( cpu , bus , ( uint32_t ) cpu -> s , ( uint8_t ) cpu -> a ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> s = ( uint16_t ) ( cpu -> s - 1u ) ; cpu -> pbr = ((unsigned int)nhp[1]) ; cpu -> pc = ((unsigned int)nhp[2]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[3]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 4u ) ;
}

NHScpuExecResult nh_v18_body_0008(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0x29u , ((unsigned int)nhp[0]) , ((unsigned int)nhp[1]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[2]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> a = ( uint16_t ) ( cpu -> a & ((unsigned int)nhp[3]) ) ; cpu -> p = ( uint8_t ) ( cpu -> p & ( uint8_t ) ~ ( NH_P_N | NH_P_Z ) ) ; if ( ( ( uint16_t ) ( cpu -> a ) & 0xFFFFu ) == 0u ) cpu -> p |= NH_P_Z ; if ( ( ( uint16_t ) ( cpu -> a ) & 0x8000u ) != 0u ) cpu -> p |= NH_P_N ; cpu -> pbr = ((unsigned int)nhp[4]) ; cpu -> pc = ((unsigned int)nhp[5]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[6]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 3u ) ;
}

NHScpuExecResult nh_v18_body_0009(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0x18u } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[0]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> p = ( uint8_t ) ( cpu -> p & ( uint8_t ) ~ NH_P_C ) ; cpu -> pbr = ((unsigned int)nhp[1]) ; cpu -> pc = ((unsigned int)nhp[2]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[3]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 2u ) ;
}

NHScpuExecResult nh_v18_body_000A(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0x83u , ((unsigned int)nhp[0]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[1]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; const uint32_t address = ( ( uint32_t ) cpu -> s + ((unsigned int)nhp[0]) ) & 0xFFFFu ; if ( nh_scpu_write8 ( cpu , bus , address , ( uint8_t ) cpu -> a ) != NH_SCPU_EXECUTED || nh_scpu_write8 ( cpu , bus , ( address + 1u ) & 0xFFFFu , ( uint8_t ) ( cpu -> a >> 8u ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> pbr = ((unsigned int)nhp[2]) ; cpu -> pc = ((unsigned int)nhp[3]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[4]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 5u ) ;
}

NHScpuExecResult nh_v18_body_000B(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0xAFu , ((unsigned int)nhp[0]) , ((unsigned int)nhp[1]) , ((unsigned int)nhp[2]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[3]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; uint8_t low = 0u , high = 0u ; uint32_t address ; address = ((unsigned int)nhp[4]) ; if ( nh_scpu_read8 ( cpu , bus , address , & low ) != NH_SCPU_EXECUTED || nh_scpu_read8 ( cpu , bus , ( address + 1u ) & 0xFFFFFFu , & high ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; const uint16_t right = ( uint16_t ) ( low | ( ( uint16_t ) high << 8u ) ) ; cpu -> a = right ; cpu -> p = ( uint8_t ) ( cpu -> p & ( uint8_t ) ~ ( NH_P_N | NH_P_Z ) ) ; if ( ( ( uint16_t ) ( cpu -> a ) & 0xFFFFu ) == 0u ) cpu -> p |= NH_P_Z ; if ( ( ( uint16_t ) ( cpu -> a ) & 0x8000u ) != 0u ) cpu -> p |= NH_P_N ; cpu -> pbr = ((unsigned int)nhp[5]) ; cpu -> pc = ((unsigned int)nhp[6]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[7]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 6u ) ;
}

NHScpuExecResult nh_v18_body_000C(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0x69u , ((unsigned int)nhp[0]) , ((unsigned int)nhp[1]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[2]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; const uint16_t left = cpu -> a ; const uint16_t right = ((unsigned int)nhp[3]) ; uint32_t sum ; uint16_t result ; if ( ( cpu -> p & NH_P_D ) != 0u ) return nh_scpu_stop ( cpu , nh_scpu_address ( cpu ) , "UNPROVED_DECIMAL_MODE" ) ; sum = ( uint32_t ) left + ( uint32_t ) right + ( ( ( cpu -> p & NH_P_C ) != 0u ) ? 1u : 0u ) ; result = ( uint16_t ) sum ; cpu -> a = result ; cpu -> p = ( uint8_t ) ( cpu -> p & ( uint8_t ) ~ ( NH_P_N | NH_P_V | NH_P_Z | NH_P_C ) ) ; if ( sum > 0xFFFFu ) cpu -> p |= NH_P_C ; if ( result == 0u ) cpu -> p |= NH_P_Z ; if ( ( result & 0x8000u ) != 0u ) cpu -> p |= NH_P_N ; if ( ( ( uint16_t ) ( ~ ( left ^ right ) ) & ( uint16_t ) ( left ^ result ) & 0x8000u ) != 0u ) cpu -> p |= NH_P_V ; cpu -> pbr = ((unsigned int)nhp[4]) ; cpu -> pc = ((unsigned int)nhp[5]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[6]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 3u ) ;
}

NHScpuExecResult nh_v18_body_000D(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0xD0u , ((unsigned int)nhp[0]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[1]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; if ( ( cpu -> p & NH_P_Z ) == 0u ) { cpu -> pbr = ((unsigned int)nhp[2]) ; cpu -> pc = ((unsigned int)nhp[3]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[4]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 3u ) ; } cpu -> pbr = ((unsigned int)nhp[2]) ; cpu -> pc = ((unsigned int)nhp[5]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[6]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 2u ) ;
}

NHScpuExecResult nh_v18_body_000E(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { 0xA0u , ((unsigned int)nhp[0]) , ((unsigned int)nhp[1]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[2]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> y = ((unsigned int)nhp[3]) ; cpu -> p = ( uint8_t ) ( cpu -> p & ( uint8_t ) ~ ( NH_P_N | NH_P_Z ) ) ; if ( ( ( uint16_t ) ( cpu -> y ) & 0xFFFFu ) == 0u ) cpu -> p |= NH_P_Z ; if ( ( ( uint16_t ) ( cpu -> y ) & 0x8000u ) != 0u ) cpu -> p |= NH_P_N ; cpu -> pbr = ((unsigned int)nhp[4]) ; cpu -> pc = ((unsigned int)nhp[5]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[6]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , 3u ) ;
}

NHScpuExecResult nh_v18_body_000F(NHScpuState *cpu, const NHScpuBus *bus, const uint32_t *nhp) {
    (void)nhp;
    const uint8_t expected_epoch [ ] = { ((unsigned int)nhp[0]) , ((unsigned int)nhp[1]) , ((unsigned int)nhp[2]) } ; if ( nh_scpu_guard_code ( cpu , bus , ((unsigned int)nhp[3]) , expected_epoch , sizeof ( expected_epoch ) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; cpu -> pbr = ((unsigned int)nhp[4]) ; cpu -> pc = ((unsigned int)nhp[5]) ; if ( nh_scpu_expect_next ( cpu , ((unsigned int)nhp[6]) ) != NH_SCPU_EXECUTED ) return NH_SCPU_STOPPED ; return nh_scpu_finish ( cpu , bus , ((unsigned int)nhp[7]) ) ;
}

