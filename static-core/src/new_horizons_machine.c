#include "new_horizons_machine.h"
#include "nh_v07_generated.h"
#include <string.h>

static NHBusStop machine_stop(NHMachine09 *machine, NHBusStop reason, const char *message) {
    if (machine->storage->bus.failure.reason == NH_BUS_OK) {
        machine->storage->bus.failure.reason = reason;
        machine->storage->bus.failure.owner = NH_OWNER_CLOCK_09;
        machine->storage->bus.failure.address = nh_scpu_address(machine->cpu);
        machine->storage->bus.failure.value = 0u;
        machine->storage->bus.failure.known_mask = 0u;
    }
    nh_scpu_stop(machine->cpu, nh_scpu_address(machine->cpu), message);
    return machine->storage->bus.failure.reason;
}

static NHBusStop machine_cycle(NHMachine09 *machine, NHMachineCycle kind,
                                uint32_t address, uint8_t *byte) {
    NHBusStop status;
    if (machine->cpu->completed_cycles == UINT64_MAX)
        return machine_stop(machine, NH_BUS_CLOCK_UNAVAILABLE, "CPU_CYCLE_COUNTER_OVERFLOW");
    status = nh_clock_machine_cycle(machine->clock, kind, address, byte);
    machine->cpu->completed_cycles += machine->clock->machine_cycle_completed;
    if (status != NH_BUS_OK) return machine_stop(machine, status, "HARDWARE_ENTRY_BUS_CYCLE_FAILED");
    return NH_BUS_OK;
}

static NHBusStop push_byte(NHMachine09 *machine, uint8_t byte) {
    NHScpuState *cpu = machine->cpu;
    const NHBusStop status = machine_cycle(machine, NH_MACHINE_WRITE, cpu->s, &byte);
    if (status != NH_BUS_OK) return status;
    cpu->s = cpu->e != 0u ? (uint16_t)(0x0100u | ((cpu->s - 1u) & 0xFFu)) :
                           (uint16_t)(cpu->s - 1u);
    return NH_BUS_OK;
}

NHBusStop nh_machine09_construct(NHMachine09 *machine, NHBusMachine08 *storage,
                                  NHScheduler *scheduler, NHClockRuntime *clock,
                                  NHScpuState *cpu, const uint8_t *rom, size_t rom_size,
                                  NHBusPorts ports, NHPinPort pins,
                                  NHSchedulerReceivers receivers) {
    return nh_machine09_construct_profile(machine, storage, scheduler, clock,
        cpu, rom, rom_size, ports, pins, receivers,
        NH_MEMORY_POWER_ON_STRICT_UNKNOWN);
}

NHBusStop nh_machine09_construct_profile(NHMachine09 *machine,
                                  NHBusMachine08 *storage,
                                  NHScheduler *scheduler, NHClockRuntime *clock,
                                  NHScpuState *cpu, const uint8_t *rom, size_t rom_size,
                                  NHBusPorts ports, NHPinPort pins,
                                  NHSchedulerReceivers receivers,
                                  NHMemoryPowerOnProfile profile) {
    NHBusStop status;
    if (machine == NULL || storage == NULL || scheduler == NULL || clock == NULL ||
        cpu == NULL || rom == NULL || nh_scpu_validate_state(cpu) == 0 ||
        receivers.smp_sync == NULL || receivers.raster_event == NULL ||
        receivers.cpu_boundary == NULL) return NH_BUS_BAD_ARGUMENT;
    /*08 validates the cartridge before changing storage. Do not memset the
     * assembled machine or copy its embedded owners to temporary addresses. */
    status = nh_bus_machine08_power_on_profile(storage, rom, rom_size, ports,
                                               pins, profile);
    if (status != NH_BUS_OK) return status;
    status = nh_scheduler_cold(scheduler, &storage->bus, receivers);
    if (status != NH_BUS_OK) return status;
    status = nh_clock_bind(clock, &storage->bus, &storage->cpu_io,
                           nh_scheduler_timeline(scheduler));
    if (status != NH_BUS_OK) return status;
    status = nh_machine09_bind(machine, storage, scheduler, clock, cpu);
    if (status != NH_BUS_OK) return status;
    /* A newly constructed machine cannot dispatch the caller's arbitrary PC
     * before its explicit reset release. Use the existing assertion owner,
     * including its proved forced register/latch state, not just a phase tag. */
    return nh_machine09_cpu_reset_assert(machine);
}

NHBusStop nh_machine09_bind(NHMachine09 *machine, NHBusMachine08 *storage,
                             NHScheduler *scheduler, NHClockRuntime *clock, NHScpuState *cpu) {
    NHTimelinePort timeline;
    if (machine == NULL || storage == NULL || scheduler == NULL || clock == NULL ||
        cpu == NULL || nh_scpu_validate_state(cpu) == 0 ||
        scheduler->bus != &storage->bus || clock->bus != &storage->bus ||
        storage->cpu_io.bus != &storage->bus || clock->math != &storage->cpu_io.math ||
        clock->active != 0u || scheduler->poll_valid != 0u ||
        scheduler->advancing != 0u || clock->reset_vector_phase != 0u ||
        clock->reset_cpu != NULL) return NH_BUS_BAD_ARGUMENT;
    timeline = nh_scheduler_timeline(scheduler);
    if (clock->timeline.opaque != timeline.opaque || clock->timeline.start_cycle != timeline.start_cycle ||
        clock->timeline.advance != timeline.advance || clock->timeline.interrupt_poll != timeline.interrupt_poll)
        return NH_BUS_BAD_ARGUMENT;
    machine->storage = storage;
    machine->scheduler = scheduler;
    machine->clock = clock;
    machine->cpu = cpu;
    machine->cpu_reset_phase = NH_CPU_RESET_NONE;
    machine->cpu_reset_assert_clock = 0u;
    machine->cpu_reset_release_clock = 0u;
    storage->bus.ports.clock = nh_clock_port(clock);
    storage->bus.ports.scheduler_registers = nh_scheduler_register_port(scheduler);
    return NH_BUS_OK;
}

NHBusStop nh_machine09_interrupt_entry(NHMachine09 *machine, uint8_t interrupt) {
    NHScpuState *cpu;
    NHBusStop status;
    uint16_t vector;
    uint8_t byte = 0u, low = 0u, high = 0u, pushed_status;
    if (machine == NULL || machine->cpu == NULL || machine->storage == NULL ||
        machine->clock == NULL || machine->scheduler == NULL ||
        (interrupt != 1u && interrupt != 2u)) return NH_BUS_BAD_ARGUMENT;
    cpu = machine->cpu;
    if (machine->storage->bus.failure.reason != NH_BUS_OK) return machine->storage->bus.failure.reason;
    if (machine->cpu_reset_phase != NH_CPU_RESET_NONE) return NH_BUS_BAD_ARGUMENT;
    if (cpu->failure.failed != 0u || machine->clock->active != 0u ||
        machine->scheduler->poll_valid != 0u || cpu->stopped != 0u || cpu->waiting != 0u)
        return machine_stop(machine, NH_BUS_CLOCK_UNAVAILABLE, "INVALID_HARDWARE_ENTRY_BOUNDARY");
    /* 5A22's first interrupt cycle is a real opcode-address read, contrary
     * to the generic table's IO label. Its byte is discarded, not decoded. */
    status = machine_cycle(machine, NH_MACHINE_FETCH_DISCARD, nh_scpu_address(cpu), &byte);
    if (status != NH_BUS_OK) return status;
    status = machine_cycle(machine, NH_MACHINE_INTERNAL, nh_scpu_address(cpu), &byte);
    if (status != NH_BUS_OK) return status;
    if (cpu->e == 0u) {
        status = push_byte(machine, cpu->pbr);
        if (status != NH_BUS_OK) return status;
    }
    status = push_byte(machine, (uint8_t)(cpu->pc >> 8u));
    if (status != NH_BUS_OK) return status;
    status = push_byte(machine, (uint8_t)cpu->pc);
    if (status != NH_BUS_OK) return status;
    pushed_status = cpu->e != 0u ? (uint8_t)(cpu->p & (uint8_t)~0x10u) : cpu->p;
    status = push_byte(machine, pushed_status);
    if (status != NH_BUS_OK) return status;
    /* Frame contains pre-entry flags. This is neither a BRK signature-byte
     * fetch nor a PC increment: save the actual retirement PC. */
    cpu->p = (uint8_t)((cpu->p | NH_P_I) & (uint8_t)~NH_P_D);
    cpu->pbr = 0u;
    vector = cpu->e != 0u ? (interrupt == 1u ? 0xFFFAu : 0xFFFEu) :
                           (interrupt == 1u ? 0xFFEAu : 0xFFEEu);
    status = machine_cycle(machine, NH_MACHINE_READ, vector, &low);
    if (status != NH_BUS_OK) return status;
    status = machine_cycle(machine, NH_MACHINE_READ, (uint32_t)vector + 1u, &high);
    if (status != NH_BUS_OK) return status;
    cpu->pc = (uint16_t)(low | ((uint16_t)high << 8u));
    if (nh_timing_plan_lookup(nh_scpu_context_key(cpu)) == NULL)
        return machine_stop(machine, NH_BUS_CLOCK_UNAVAILABLE, "UNADMITTED_INTERRUPT_VECTOR_CONTEXT");
    return NH_BUS_OK;
}

NHBusStop nh_machine09_retire(NHMachine09 *machine) {
    NHBusStop status;
    uint8_t interrupt = 0u;
    if (machine == NULL || machine->cpu == NULL || machine->scheduler == NULL ||
        machine->clock == NULL || machine->storage == NULL) return NH_BUS_BAD_ARGUMENT;
    if (machine->cpu_reset_phase != NH_CPU_RESET_NONE) return NH_BUS_BAD_ARGUMENT;
    if (machine->cpu->failure.failed != 0u || machine->clock->active != 0u)
        return machine_stop(machine, NH_BUS_CLOCK_UNAVAILABLE, "FAILED_INSTRUCTION_CANNOT_RETIRE");
    status = nh_scheduler_take_interrupt(machine->scheduler, &interrupt);
    if (status != NH_BUS_OK) return machine_stop(machine, status, "MISSING_RETIREMENT_INTERRUPT_POLL");
    return interrupt != 0u ? nh_machine09_interrupt_entry(machine, interrupt) : NH_BUS_OK;
}

NHScpuExecResult nh_machine09_step(NHMachine09 *machine) {
    NHScpuBus view;
    NHScpuExecResult result;
    if (machine == NULL || machine->cpu == NULL || machine->storage == NULL ||
        machine->clock == NULL || machine->scheduler == NULL) return NH_SCPU_STOPPED;
    if (machine->cpu->failure.failed != 0u || machine->storage->bus.failure.reason != NH_BUS_OK)
        return NH_SCPU_STOPPED;
    if (machine->cpu_reset_phase != NH_CPU_RESET_NONE) return NH_SCPU_STOPPED;
    if (machine->cpu->waiting != 0u || machine->cpu->stopped != 0u) {
        /* A hardware halt isn't a bus fault. The run owner advances suspended
         * domains with advance_terminal, not by dispatching another opcode. */
        return NH_SCPU_STOPPED;
    }
    if (machine->clock->active != 0u || machine->scheduler->poll_valid != 0u) {
        machine_stop(machine, NH_BUS_CLOCK_UNAVAILABLE, "UNRETIRED_INSTRUCTION_BOUNDARY");
        return NH_SCPU_STOPPED;
    }
    view = nh_bus_scpu_view(&machine->storage->bus);
    result = nh_v07_dispatch(machine->cpu, &view);
    if (result != NH_SCPU_EXECUTED) return result;
    if (nh_machine09_retire(machine) != NH_BUS_OK) return NH_SCPU_STOPPED;
    return NH_SCPU_EXECUTED;
}

NHBusStop nh_machine09_cpu_reset_assert(NHMachine09 *machine) {
    NHScpuState *cpu;
    NHBusStop status;
    if (machine == NULL || machine->cpu == NULL || machine->storage == NULL ||
        machine->clock == NULL || machine->scheduler == NULL) return NH_BUS_BAD_ARGUMENT;
    if (machine->scheduler->advancing != 0u ||
        machine->cpu_reset_phase == NH_CPU_RESET_RELEASING) return NH_BUS_BAD_ARGUMENT;
    if (machine->cpu_reset_phase == NH_CPU_RESET_HELD)
        return machine->storage->bus.failure.reason;
    /* A live instruction cannot be interrupted by a host call halfway through
     * its native body. A failed body may be cancelled at its diagnostic cut. */
    if (machine->clock->active != 0u && machine->cpu->failure.failed == 0u &&
        machine->storage->bus.failure.reason == NH_BUS_OK) return NH_BUS_BAD_ARGUMENT;
    machine->cpu_reset_phase = NH_CPU_RESET_HELD;
    machine->cpu_reset_assert_clock = machine->scheduler->master_clock;
    machine->cpu_reset_release_clock = 0u;
    cpu = machine->cpu;
    status = nh_bus_machine08_reset_latches(machine->storage);
    if (status != NH_BUS_OK) {
        machine->cpu_reset_phase = NH_CPU_RESET_FAILED;
        return machine_stop(machine, status, "CPU_RESET_LATCH_ASSERTION_FAILED");
    }
    machine->clock->active = 0u;
    machine->clock->reset_vector_phase = 0u;
    machine->clock->reset_cpu = NULL;
    status = nh_scheduler_reset_cpu_latches(machine->scheduler);
    if (status != NH_BUS_OK) {
        machine->cpu_reset_phase = NH_CPU_RESET_FAILED;
        return machine_stop(machine, status, "INPUT_ABORT_DURING_RESET_FAILED");
    }
    memset(&cpu->failure, 0, sizeof(cpu->failure));
    cpu->e = 1u;
    cpu->p = (uint8_t)((cpu->p | NH_P_I | NH_P_M | NH_P_X) & (uint8_t)~NH_P_D);
    cpu->d = 0u;
    cpu->dbr = 0u;
    cpu->pbr = 0u;
    cpu->x &= 0xFFu;
    cpu->y &= 0xFFu;
    cpu->s = (uint16_t)(0x0100u | (cpu->s & 0xFFu));
    cpu->waiting = 0u;
    cpu->stopped = 0u;
    return NH_BUS_OK;
}

NHBusStop nh_machine09_cpu_reset_hold(NHMachine09 *machine, uint32_t wall_clocks) {
    NHBusStop status;
    if (machine == NULL || machine->cpu == NULL || machine->storage == NULL ||
        machine->clock == NULL || machine->scheduler == NULL ||
        machine->cpu_reset_phase != NH_CPU_RESET_HELD) return NH_BUS_BAD_ARGUMENT;
    if (machine->storage->bus.failure.reason != NH_BUS_OK)
        return machine->storage->bus.failure.reason;
    status = nh_scheduler_advance_wall(machine->scheduler, wall_clocks);
    if (status != NH_BUS_OK) {
        machine->cpu_reset_phase = NH_CPU_RESET_FAILED;
        return machine_stop(machine, status, "CPU_RESET_HOLD_DOMAIN_FAILED");
    }
    return NH_BUS_OK;
}

static NHBusStop reset_release_failed(NHMachine09 *machine, NHBusStop status) {
    machine->cpu_reset_phase = NH_CPU_RESET_FAILED;
    return status;
}

static NHBusStop reset_device_phase(NHMachine09 *machine, NHDeviceResetPort port,
                                     NHDeviceResetPhase phase, uint32_t hold_clocks) {
    const uint64_t before_clock = machine->scheduler->master_clock;
    const NHSmpClockJoin before_smp = machine->scheduler->smp;
    const NHBusFailure prior_fault = machine->storage->bus.failure;
    NHBusStop status;
    /* Reuse the existing no-recursive-advance boundary. This is not a second
     * reset clock or permission to execute a transfer from a reset callback. */
    machine->scheduler->advancing = 1u;
    status = port.apply(port.opaque, &machine->storage->bus, machine->scheduler, phase, hold_clocks);
    machine->scheduler->advancing = 0u;
    if (phase == NH_DEVICE_RESET_PREFLIGHT &&
        (machine->storage->bus.failure.reason != prior_fault.reason ||
         machine->storage->bus.failure.owner != prior_fault.owner ||
         machine->storage->bus.failure.address != prior_fault.address ||
         machine->storage->bus.failure.value != prior_fault.value ||
         machine->storage->bus.failure.known_mask != prior_fault.known_mask)) {
        if (prior_fault.reason != NH_BUS_OK) machine->storage->bus.failure = prior_fault;
        machine->cpu_reset_phase = NH_CPU_RESET_FAILED;
        return machine_stop(machine, machine->storage->bus.failure.reason != NH_BUS_OK ?
                            machine->storage->bus.failure.reason : NH_BUS_CLOCK_UNAVAILABLE,
                            "DEVICE_RESET_PREFLIGHT_CHANGED_FAULT");
    }
    if (machine->scheduler->master_clock != before_clock ||
        machine->scheduler->smp.target_phase_units != before_smp.target_phase_units ||
        machine->scheduler->smp.target_cycles != before_smp.target_cycles ||
        machine->scheduler->smp.remainder != before_smp.remainder) {
        machine->cpu_reset_phase = NH_CPU_RESET_FAILED;
        return machine_stop(machine, NH_BUS_CLOCK_UNAVAILABLE, "DEVICE_RESET_ADVANCED_CLOCK");
    }
    if (phase == NH_DEVICE_RESET_PREFLIGHT) {
        /* Policy rejection is not a hardware assertion or a guest fault.
         * An unchanged existing fault must remain recoverable by CPU assert. */
        return status;
    }
    if (status == NH_BUS_OK && machine->storage->bus.failure.reason != NH_BUS_OK)
        status = machine->storage->bus.failure.reason;
    if (status != NH_BUS_OK) {
        machine->cpu_reset_phase = NH_CPU_RESET_FAILED;
        return machine_stop(machine, status, "DEVICE_RESET_CONTRACT_FAILED");
    }
    return NH_BUS_OK;
}

NHBusStop nh_machine09_reset_with_devices(NHMachine09 *machine, NHDeviceResetPort port,
                                          uint32_t hold_master_clocks) {
    NHBusStop status;
    if (machine == NULL || machine->storage == NULL || machine->scheduler == NULL ||
        machine->clock == NULL || machine->cpu == NULL ||
        machine->scheduler->advancing != 0u ||
        machine->cpu_reset_phase == NH_CPU_RESET_RELEASING)
        return NH_BUS_BAD_ARGUMENT;
    if ((machine->clock->active != 0u || machine->scheduler->poll_valid != 0u) &&
        machine->storage->bus.failure.reason == NH_BUS_OK && machine->cpu->failure.failed == 0u)
        return NH_BUS_BAD_ARGUMENT;
    if (port.apply == NULL) return NH_BUS_UNPROVED_REGISTER;
    /* Preflight is observational and must reject an unqualified scope/duration
     * before asserting CPU reset. Recovery of an existing fault is performed
     * by the existing CPU assertion owner, never by clearing it here. */
    status = reset_device_phase(machine, port, NH_DEVICE_RESET_PREFLIGHT, hold_master_clocks);
    if (status != NH_BUS_OK) return status;
    status = nh_machine09_cpu_reset_assert(machine);
    if (status != NH_BUS_OK) return status;
    status = reset_device_phase(machine, port, NH_DEVICE_RESET_ASSERT, hold_master_clocks);
    if (status != NH_BUS_OK) return status;
    status = nh_machine09_cpu_reset_hold(machine, hold_master_clocks);
    if (status != NH_BUS_OK) return status;
    status = reset_device_phase(machine, port, NH_DEVICE_RESET_RELEASE, hold_master_clocks);
    if (status != NH_BUS_OK) return status;
    return nh_machine09_reset_release_cpu(machine);
}

NHBusStop nh_machine09_reset_release_cpu(NHMachine09 *machine) {
    NHScpuState *cpu;
    NHBusStop status;
    uint16_t vector = 0u;
    if (machine == NULL || machine->cpu == NULL || machine->storage == NULL ||
        machine->clock == NULL || machine->scheduler == NULL ||
        machine->cpu_reset_phase != NH_CPU_RESET_HELD ||
        machine->scheduler->advancing != 0u) return NH_BUS_BAD_ARGUMENT;
    if (machine->storage->bus.failure.reason != NH_BUS_OK)
        return machine->storage->bus.failure.reason;
    cpu = machine->cpu;
    /* Discard reset-time pending CPU signals before release; device state and
     * oscillator phase are not cold-initialized again here. */
    status = nh_scheduler_reset_cpu_latches(machine->scheduler);
    if (status != NH_BUS_OK) {
        machine->cpu_reset_phase = NH_CPU_RESET_FAILED;
        return machine_stop(machine, status, "CPU_RESET_RELEASE_LATCH_FAILED");
    }
    machine->cpu_reset_phase = NH_CPU_RESET_RELEASING;
    machine->cpu_reset_release_clock = machine->scheduler->master_clock;
    /* Follow the inspected mature reset accounting, not a second bespoke
     * startup profile layered on modeled physical reset microcycles. */
    status = nh_clock_reset_vector_begin(machine->clock, cpu);
    if (status != NH_BUS_OK) {
        status = machine_stop(machine, status, "RESET_VECTOR_BOUNDARY_REJECTED");
        return reset_release_failed(machine, status);
    }
    status = nh_bus_sample_reset_vector(&machine->storage->bus, &vector);
    if (status != NH_BUS_OK) {
        status = machine_stop(machine, status, "RESET_VECTOR_READ_FAILED");
        return reset_release_failed(machine, status);
    }
    cpu->pc = vector;
    if (nh_timing_plan_lookup(nh_scpu_context_key(cpu)) == NULL) {
        status = machine_stop(machine, NH_BUS_CLOCK_UNAVAILABLE, "UNADMITTED_RESET_VECTOR_CONTEXT");
        return reset_release_failed(machine, status);
    }
    status = nh_scheduler_advance_wall(machine->scheduler, NH_RESET_STARTUP_MASTER_CLOCKS);
    if (status != NH_BUS_OK) return reset_release_failed(machine, status);
    machine->cpu_reset_phase = NH_CPU_RESET_NONE;
    return NH_BUS_OK;
}

NHBusStop nh_machine09_advance_terminal(NHMachine09 *machine, uint32_t wall_clocks,
                                        uint8_t *resumed) {
    NHBusStop status;
    uint32_t elapsed = 0u;
    uint8_t byte = 0u;
    NHTimelinePort timeline;
    if (machine == NULL || machine->cpu == NULL || machine->storage == NULL ||
        machine->clock == NULL || machine->scheduler == NULL || resumed == NULL)
        return NH_BUS_BAD_ARGUMENT;
    *resumed = 0u;
    if (machine->cpu_reset_phase != NH_CPU_RESET_NONE) return NH_BUS_BAD_ARGUMENT;
    if (machine->storage->bus.failure.reason != NH_BUS_OK) return machine->storage->bus.failure.reason;
    if (machine->cpu->failure.failed != 0u || machine->clock->active != 0u ||
        machine->scheduler->poll_valid != 0u)
        return machine_stop(machine, NH_BUS_CLOCK_UNAVAILABLE, "INVALID_TERMINAL_ADVANCE_BOUNDARY");
    if (machine->cpu->stopped == 0u && machine->cpu->waiting == 0u) return NH_BUS_BAD_ARGUMENT;
    for (;;) {
        if (machine->cpu->stopped == 0u && (machine->scheduler->nmi_pending != 0u ||
            machine->scheduler->nmi_edge_latched != 0u ||
            machine->scheduler->nmi_line != 0u || machine->scheduler->irq_line != 0u ||
            machine->scheduler->external_irq != 0u)) {
            machine->cpu->waiting = 0u;
            status = machine_cycle(machine, NH_MACHINE_INTERNAL, nh_scpu_address(machine->cpu), &byte);
            if (status != NH_BUS_OK) return status;
            timeline = nh_scheduler_timeline(machine->scheduler);
            status = timeline.interrupt_poll(timeline.opaque, &machine->storage->bus,
                                             machine->cpu->p, nh_scpu_context_key(machine->cpu));
            if (status != NH_BUS_OK) return machine_stop(machine, status, "WAI_WAKE_POLL_FAILED");
            status = machine_cycle(machine, NH_MACHINE_INTERNAL, nh_scpu_address(machine->cpu), &byte);
            if (status != NH_BUS_OK) return status;
            status = nh_machine09_retire(machine);
            if (status != NH_BUS_OK) return status;
            *resumed = 1u;
            return NH_BUS_OK;
        }
        if (elapsed == wall_clocks) return NH_BUS_OK;
        status = nh_scheduler_advance_wall(machine->scheduler, 1u);
        if (status != NH_BUS_OK) return machine_stop(machine, status, "SUSPENDED_DOMAIN_ADVANCE_FAILED");
        ++elapsed;
    }
}
