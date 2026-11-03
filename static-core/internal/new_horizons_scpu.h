#ifndef NEW_HORIZONS_SCPU_H
#define NEW_HORIZONS_SCPU_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum {
    NH_P_C = 0x01u,
    NH_P_Z = 0x02u,
    NH_P_I = 0x04u,
    NH_P_D = 0x08u,
    NH_P_X = 0x10u,
    NH_P_M = 0x20u,
    NH_P_V = 0x40u,
    NH_P_N = 0x80u
};

typedef enum NHScpuExecResult {
    NH_SCPU_EXECUTED = 0,
    NH_SCPU_NOT_MINE = 1,
    NH_SCPU_STOPPED = 2
} NHScpuExecResult;

typedef struct NHScpuFailure {
    uint8_t failed;
    uint32_t context_key;
    uint32_t address;
    char reason[128];
} NHScpuFailure;

typedef struct NHScpuState {
    uint16_t a;
    uint16_t x;
    uint16_t y;
    uint16_t s;
    uint16_t d;
    uint16_t pc;
    uint8_t dbr;
    uint8_t pbr;
    uint8_t p;
    uint8_t e;
    uint8_t waiting;
    uint8_t stopped;
    uint64_t completed_cycles;
    NHScpuFailure failure;
} NHScpuState;

/* 07C owns only direct static instruction bodies. Later bus/timing owners
 * implement these callbacks; a missing or rejected callback always stops. */
typedef struct NHScpuBus {
    void *opaque;
    int (*guard_code)(void *opaque, const NHScpuState *cpu, uint32_t address,
                      const uint8_t *expected, size_t count);
    int (*read8)(void *opaque, const NHScpuState *cpu,
                 uint32_t address, uint8_t *value);
    int (*write8)(void *opaque, const NHScpuState *cpu,
                  uint32_t address, uint8_t value);
    int (*finish_instruction)(void *opaque, const NHScpuState *cpu,
                              uint32_t *cycles);
    /* One literal block-move byte: addresses are known CPU values;payload
     * knownness belongs to the bus and must survive the timed read/write. */
    int (*copy8)(void *opaque, const NHScpuState *cpu,
                 uint32_t source, uint32_t destination);
} NHScpuBus;

uint32_t nh_scpu_context_key(const NHScpuState *cpu);
uint32_t nh_scpu_address(const NHScpuState *cpu);
int nh_scpu_validate_state(const NHScpuState *cpu);
NHScpuExecResult nh_scpu_stop(NHScpuState *cpu, uint32_t address,
                              const char *reason);
NHScpuExecResult nh_scpu_guard_code(NHScpuState *cpu, const NHScpuBus *bus,
                                    uint32_t address, const uint8_t *bytes,
                                    size_t count);
NHScpuExecResult nh_scpu_read8(NHScpuState *cpu, const NHScpuBus *bus,
                               uint32_t address, uint8_t *value);
NHScpuExecResult nh_scpu_write8(NHScpuState *cpu, const NHScpuBus *bus,
                                uint32_t address, uint8_t value);
NHScpuExecResult nh_scpu_pull8(NHScpuState *cpu, const NHScpuBus *bus,
                               uint8_t *value);
NHScpuExecResult nh_scpu_copy8(NHScpuState *cpu, const NHScpuBus *bus,
                               uint32_t source, uint32_t destination);
NHScpuExecResult nh_scpu_expect_next(NHScpuState *cpu, uint32_t expected_key);
NHScpuExecResult nh_scpu_finish(NHScpuState *cpu, const NHScpuBus *bus,
                                uint32_t cycles);

#ifdef __cplusplus
}
#endif

#endif
