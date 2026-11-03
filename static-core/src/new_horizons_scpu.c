#include "new_horizons_scpu.h"

static void nh_copy_reason(char *destination, size_t capacity, const char *source) {
    size_t index = 0u;
    if (capacity == 0u) return;
    if (source != NULL) {
        while (index + 1u < capacity && source[index] != '\0') {
            destination[index] = source[index];
            ++index;
        }
    }
    destination[index] = '\0';
}

uint32_t nh_scpu_context_key(const NHScpuState *cpu) {
    const uint32_t m = (cpu->p & NH_P_M) != 0u ? 1u : 0u;
    const uint32_t x = (cpu->p & NH_P_X) != 0u ? 1u : 0u;
    return ((uint32_t)cpu->pbr << 19u) | ((uint32_t)cpu->pc << 3u)
        | ((uint32_t)cpu->e << 2u) | (m << 1u) | x;
}

uint32_t nh_scpu_address(const NHScpuState *cpu) {
    return ((uint32_t)cpu->pbr << 16u) | (uint32_t)cpu->pc;
}

int nh_scpu_validate_state(const NHScpuState *cpu) {
    if (cpu == NULL || cpu->e > 1u) return 0;
    if (cpu->e != 0u && (cpu->p & (NH_P_M | NH_P_X)) != (NH_P_M | NH_P_X)) return 0;
    if ((cpu->p & NH_P_X) != 0u && ((cpu->x | cpu->y) & 0xFF00u) != 0u) return 0;
    if (cpu->e != 0u && (cpu->s & 0xFF00u) != 0x0100u) return 0;
    return 1;
}

NHScpuExecResult nh_scpu_stop(NHScpuState *cpu, uint32_t address,
                              const char *reason) {
    if (cpu != NULL) {
        cpu->failure.failed = 1u;
        cpu->failure.context_key = nh_scpu_context_key(cpu);
        cpu->failure.address = address & 0xFFFFFFu;
        nh_copy_reason(cpu->failure.reason, sizeof(cpu->failure.reason), reason);
    }
    return NH_SCPU_STOPPED;
}

NHScpuExecResult nh_scpu_guard_code(NHScpuState *cpu, const NHScpuBus *bus,
                                    uint32_t address, const uint8_t *bytes,
                                    size_t count) {
    if (bus == NULL || bus->guard_code == NULL || bytes == NULL || count == 0u)
        return nh_scpu_stop(cpu, address, "MISSING_CODE_GUARD_OWNER");
    if (bus->guard_code(bus->opaque, cpu, address & 0xFFFFFFu, bytes, count) == 0)
        return nh_scpu_stop(cpu, address, "SOURCE_BYTE_GUARD_MISMATCH");
    return NH_SCPU_EXECUTED;
}

NHScpuExecResult nh_scpu_read8(NHScpuState *cpu, const NHScpuBus *bus,
                               uint32_t address, uint8_t *value) {
    if (bus == NULL || bus->read8 == NULL || value == NULL)
        return nh_scpu_stop(cpu, address, "MISSING_READ8_OWNER");
    if (bus->read8(bus->opaque, cpu, address & 0xFFFFFFu, value) == 0)
        return nh_scpu_stop(cpu, address, "UNOWNED_OR_FAILED_READ8");
    return NH_SCPU_EXECUTED;
}

NHScpuExecResult nh_scpu_write8(NHScpuState *cpu, const NHScpuBus *bus,
                                uint32_t address, uint8_t value) {
    if (bus == NULL || bus->write8 == NULL)
        return nh_scpu_stop(cpu, address, "MISSING_WRITE8_OWNER");
    if (bus->write8(bus->opaque, cpu, address & 0xFFFFFFu, value) == 0)
        return nh_scpu_stop(cpu, address, "UNOWNED_OR_FAILED_WRITE8");
    return NH_SCPU_EXECUTED;
}

NHScpuExecResult nh_scpu_copy8(NHScpuState *cpu, const NHScpuBus *bus,
                               uint32_t source, uint32_t destination) {
    if (bus == NULL || bus->copy8 == NULL)
        return nh_scpu_stop(cpu, source, "MISSING_COPY8_OWNER");
    if (bus->copy8(bus->opaque, cpu, source & 0xFFFFFFu,
                   destination & 0xFFFFFFu) == 0)
        return nh_scpu_stop(cpu, source, "UNOWNED_OR_FAILED_COPY8");
    return NH_SCPU_EXECUTED;
}

NHScpuExecResult nh_scpu_pull8(NHScpuState *cpu, const NHScpuBus *bus,
                               uint8_t *value) {
    cpu->s = cpu->e != 0u
        ? (uint16_t)(0x0100u | ((cpu->s + 1u) & 0x00FFu))
        : (uint16_t)(cpu->s + 1u);
    return nh_scpu_read8(cpu, bus, (uint32_t)cpu->s, value);
}

NHScpuExecResult nh_scpu_expect_next(NHScpuState *cpu, uint32_t expected_key) {
    if (nh_scpu_context_key(cpu) != expected_key)
        return nh_scpu_stop(cpu, nh_scpu_address(cpu), "UNPROVED_SUCCESSOR_CONTEXT");
    return NH_SCPU_EXECUTED;
}

NHScpuExecResult nh_scpu_finish(NHScpuState *cpu, const NHScpuBus *bus,
                                uint32_t cycles) {
    if (bus == NULL || bus->finish_instruction == NULL ||
        bus->finish_instruction(bus->opaque, cpu, &cycles) == 0)
        return nh_scpu_stop(cpu, nh_scpu_address(cpu),
                            "TIMING_PLAN_MISMATCH_OR_UNAVAILABLE");
    cpu->completed_cycles += (uint64_t)cycles;
    return NH_SCPU_EXECUTED;
}
