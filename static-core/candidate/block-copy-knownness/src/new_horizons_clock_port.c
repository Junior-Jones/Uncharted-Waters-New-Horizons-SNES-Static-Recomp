#include "new_horizons_clock_port.h"
#include <string.h>

static NHBusStop clock_fail(NHClockRuntime *clock, NHBusStop reason,
                             uint32_t address) {
    NHBusRuntime *bus = clock->bus;
    if (bus->failure.reason == NH_BUS_OK) {
        bus->failure.reason = reason;
        bus->failure.owner = NH_OWNER_CLOCK_09;
        bus->failure.address = address;
        bus->failure.value = 0u;
        bus->failure.known_mask = 0u;
    }
    return bus->failure.reason;
}

static uint32_t fetch_address(const NHClockRuntime *clock, uint8_t index) {
    return (clock->fetch.fetch_address & 0xFF0000u) |
           ((clock->fetch.fetch_address + index) & 0xFFFFu);
}

static int deferred(const NHClockRuntime *clock, const NHTimingEvent *event) {
    const uint32_t address = fetch_address(clock, event->index);
    return event->kind == NH_TIMING_FETCH &&
           clock->fetch.deferred_operand_count != 0u &&
           address >= clock->fetch.deferred_operand_address &&
           address - clock->fetch.deferred_operand_address <
               clock->fetch.deferred_operand_count;
}

/* Decisions use captured entry facts and bytes actually sampled on the bus.
 * This is plan consumption, never an opcode or addressing-mode decoder. */
static int enabled(const NHClockRuntime *clock, uint8_t condition) {
    const NHTimingPlan *plan = clock->plan;
    const int taken = plan->branch_mask == 0u ||
        (((clock->entry.p & plan->branch_mask) != 0u) == (plan->branch_set != 0u));
    uint16_t base, index, next, target;
    int displacement;
    switch (condition) {
        case NH_TIMING_ALWAYS: return 1;
        case NH_TIMING_DIRECT_LOW_NONZERO: return (clock->entry.d & 0xFFu) != 0u;
        case NH_TIMING_BRANCH_TAKEN: return taken;
        case NH_TIMING_BRANCH_TAKEN_AND_PAGE_CROSSED:
            if (!taken) return 0;
            if ((clock->fetched_mask & 2u) == 0u) return -1;
            next = (uint16_t)(clock->entry.pc + 2u);
            displacement = clock->operands[1] < 128u ? clock->operands[1] :
                           (int)clock->operands[1] - 256;
            target = (uint16_t)((int)next + displacement);
            return taken && (next & 0xFF00u) != (target & 0xFF00u);
        case NH_TIMING_INDEX_PAGE_CROSSED:
            if (plan->page_base_source == NH_TIMING_PAGE_OPERAND) {
                if ((clock->fetched_mask & 2u) == 0u) return -1;
                base = clock->operands[1];
            } else if (plan->page_base_source == NH_TIMING_PAGE_POINTER) {
                if (clock->pointer_low_valid == 0u) return -1;
                base = clock->pointer_low;
            } else return -1;
            if (plan->index_register == NH_TIMING_INDEX_X) index = clock->entry.x;
            else if (plan->index_register == NH_TIMING_INDEX_Y) index = clock->entry.y;
            else return -1;
            return (uint32_t)base + index > 0xFFu;
        default: return -1;
    }
}

static NHBusStop advance(NHClockRuntime *clock, uint8_t clocks) {
    NHBusStop status = clock->timeline.advance(clock->timeline.opaque, clock->bus, clocks);
    if (status != NH_BUS_OK) return clock_fail(clock, status, nh_scpu_address(&clock->entry));
    return clock->bus->failure.reason;
}

static NHBusStop cycle_value(NHClockRuntime *clock, uint8_t kind, uint32_t address,
                              uint8_t *byte, uint8_t require_value, NHBusValue *payload) {
    NHBusValue sampled;
    /* Read/internal byte is output-only: never inspect an unwritten value.
     * Write data is still captured before rendezvous/receiver callbacks. */
    const NHBusValue written = kind == NH_TIMING_WRITE && payload != NULL ? *payload :
        (NHBusValue){ kind == NH_TIMING_WRITE ? *byte : 0u, 0xFFu };
    uint8_t clocks = 6u;
    NHBusStop status;
    if (kind != NH_TIMING_INTERNAL &&
        nh_bus_access_clocks(address, clock->bus->memsel, &clocks) == 0)
        return clock_fail(clock, NH_BUS_BAD_ARGUMENT, address);
    if (clocks < 4u) return clock_fail(clock, NH_BUS_CLOCK_UNAVAILABLE, address);
    status = clock->timeline.start_cycle(clock->timeline.opaque, clock->bus,
                                          kind, address, clocks);
    if (status != NH_BUS_OK) return clock_fail(clock, status, address);
    if (clock->bus->failure.reason != NH_BUS_OK) return clock->bus->failure.reason;
    if (clock->active != 0u) {
        uint8_t index;
        int last = 1;
        /* A future unresolved conditional cannot establish that this is the
         * last cycle. At the actual last cycle all governing samples exist.
         * A not-taken branch needs no displacement to suppress its penalty. */
        for (index = (uint8_t)(clock->cursor + 1u); index < clock->plan->event_count; ++index) {
            if (enabled(clock, nh_timing_events[clock->plan->first_event + index].condition) != 0) {
                last = 0;
                break;
            }
        }
        if (last) {
            if (clock->interrupt_polled != 0u || clock->irq_status_valid == 0u)
                return clock_fail(clock, NH_BUS_CLOCK_UNAVAILABLE, address);
            status = clock->timeline.interrupt_poll(clock->timeline.opaque, clock->bus,
                                                     clock->irq_status, clock->context_key);
            if (status != NH_BUS_OK) return clock_fail(clock, status, address);
            if (clock->bus->failure.reason != NH_BUS_OK) return clock->bus->failure.reason;
            clock->interrupt_polled = 1u;
        }
    }
    if (kind == NH_TIMING_FETCH || kind == NH_TIMING_READ) {
        status = advance(clock, (uint8_t)(clocks - 4u));
        if (status != NH_BUS_OK) return status;
        /* The ordered bus contract makes this cycle's arithmetic result
         * visible at the read sample. Advance the same08 owner here, not
         * after the value was captured or on a separate wall-clock model. */
        nh_math_pulse(clock->math);
        status = nh_bus_read_sample(clock->bus, address, &sampled);
        if (status != NH_BUS_OK) return clock_fail(clock, status, address);
        status = advance(clock, 4u);
        if (status != NH_BUS_OK) return status;
        ++clock->cycles;
        if (payload != NULL) { *payload = sampled; return NH_BUS_OK; }
        if (require_value != 0u) return nh_bus_require_known(clock->bus, address, sampled, byte);
        /* Ignored hardware-entry read: effects occurred, but unknown data is
         * never supplied as an execution value. */
        *byte = 0u;
        return NH_BUS_OK;
    }
    status = advance(clock, clocks);
    if (status != NH_BUS_OK) return status;
    /* Retire the prior operation before a completion-edge trigger commit;
     * the new operation must not receive this already elapsed CPU pulse. */
    nh_math_pulse(clock->math);
    ++clock->cycles; /* elapsed cycle, even if the completion-phase receiver fails */
    if (kind == NH_TIMING_WRITE) {
        status = nh_bus_write_commit(clock->bus, address, written);
        if (status != NH_BUS_OK) return clock_fail(clock, status, address);
    } else if (kind != NH_TIMING_INTERNAL)
        return clock_fail(clock, NH_BUS_CLOCK_UNAVAILABLE, address);
    return clock->bus->failure.reason;
}

static NHBusStop cycle(NHClockRuntime *clock, uint8_t kind, uint32_t address,
                        uint8_t *byte) {
    return cycle_value(clock, kind, address, byte, 1u, NULL);
}

NHBusStop nh_clock_machine_cycle(NHClockRuntime *clock, NHMachineCycle kind,
                                  uint32_t address, uint8_t *byte) {
    uint8_t timing_kind, require_value = 1u;
    NHBusStop status;
    if (clock != NULL) clock->machine_cycle_completed = 0u;
    if (clock == NULL || clock->bus == NULL || byte == NULL) return NH_BUS_BAD_ARGUMENT;
    if (clock->bus->failure.reason != NH_BUS_OK) return clock->bus->failure.reason;
    if (clock->active != 0u) return clock_fail(clock, NH_BUS_CLOCK_UNAVAILABLE, address);
    switch (kind) {
        case NH_MACHINE_INTERNAL: timing_kind = NH_TIMING_INTERNAL; break;
        case NH_MACHINE_FETCH_DISCARD: timing_kind = NH_TIMING_FETCH; require_value = 0u; break;
        case NH_MACHINE_READ_DISCARD: timing_kind = NH_TIMING_READ; require_value = 0u; break;
        case NH_MACHINE_READ: timing_kind = NH_TIMING_READ; break;
        case NH_MACHINE_WRITE: timing_kind = NH_TIMING_WRITE; break;
        default: return NH_BUS_BAD_ARGUMENT;
    }
    clock->cycles = 0u;
    status = cycle_value(clock, timing_kind, address, byte, require_value, NULL);
    clock->machine_cycle_completed = clock->cycles != 0u;
    return status;
}

static NHBusStop consume_fetch(NHClockRuntime *clock, const NHTimingEvent *event,
                                uint8_t *value) {
    const uint32_t address = fetch_address(clock, event->index);
    const uint16_t guard_index = (uint16_t)(address - clock->fetch.guard_address);
    NHBusStop status;
    if (event->index >= clock->fetch.fetch_count || guard_index >= clock->fetch.guard_count)
        return clock_fail(clock, NH_BUS_BAD_STATIC_GUARD, address);
    status = cycle(clock, NH_TIMING_FETCH, address, value);
    if (status != NH_BUS_OK) return status;
    if ((clock->fetch.immutable_byte_mask & (1u << guard_index)) != 0u &&
        *value != clock->expected[guard_index])
        return clock_fail(clock, NH_BUS_BAD_STATIC_GUARD, address);
    clock->operands[event->index] = *value;
    clock->fetched_mask |= (uint8_t)(1u << event->index);
    ++clock->cursor;
    return NH_BUS_OK;
}

/* Stop at a native data callback or a registered live operand callback.
 * All other queued fetch/internal events run in their declared position. */
static NHBusStop drain(NHClockRuntime *clock) {
    while (clock->cursor < clock->plan->event_count) {
        const NHTimingEvent *event = &nh_timing_events[clock->plan->first_event + clock->cursor];
        uint8_t byte = 0u;
        NHBusStop status;
        const int use = enabled(clock, event->condition);
        if (use < 0) return clock_fail(clock, NH_BUS_CLOCK_UNAVAILABLE, nh_scpu_address(&clock->entry));
        if (use == 0) { ++clock->cursor; continue; }
        if (event->kind == NH_TIMING_READ || event->kind == NH_TIMING_WRITE || deferred(clock, event))
            return NH_BUS_OK;
        if (event->kind == NH_TIMING_FETCH) status = consume_fetch(clock, event, &byte);
        else if (event->kind == NH_TIMING_INTERNAL) {
            status = cycle(clock, NH_TIMING_INTERNAL, nh_scpu_address(&clock->entry), &byte);
            if (status == NH_BUS_OK) ++clock->cursor;
        } else return clock_fail(clock, NH_BUS_CLOCK_UNAVAILABLE, nh_scpu_address(&clock->entry));
        if (status != NH_BUS_OK) return status;
    }
    return NH_BUS_OK;
}

static NHBusStop begin(void *opaque, NHBusRuntime *bus, const NHScpuState *cpu,
                        const NHStaticFetch *fetch, const uint8_t *expected) {
    NHClockRuntime *clock = opaque;
    NHStaticFetch checked;
    const NHTimingPlan *plan;
    if (clock == NULL || bus == NULL || clock->bus != bus || cpu == NULL ||
        fetch == NULL || expected == NULL) return NH_BUS_BAD_ARGUMENT;
    if (bus->failure.reason != NH_BUS_OK) return bus->failure.reason;
    if (clock->active != 0u || nh_static_fetch_descriptor(cpu, fetch->guard_address,
        fetch->guard_count, &checked) == 0)
        return clock_fail(clock, NH_BUS_BAD_STATIC_GUARD, nh_scpu_address(cpu));
    /* Compare fields, not structure padding. Only recomputed source metadata
     * is retained; caller-provided lengths/epoch/deferred fields cannot select
     * another sequence. */
    if (checked.fetch_address != fetch->fetch_address || checked.fetch_count != fetch->fetch_count ||
        checked.executable_epoch != fetch->executable_epoch ||
        checked.immutable_byte_mask != fetch->immutable_byte_mask ||
        checked.deferred_operand_address != fetch->deferred_operand_address ||
        checked.deferred_operand_count != fetch->deferred_operand_count)
        return clock_fail(clock, NH_BUS_BAD_STATIC_GUARD, nh_scpu_address(cpu));
    plan = nh_timing_plan_lookup(nh_scpu_context_key(cpu));
    if (plan == NULL || plan->fetch_count != checked.fetch_count ||
        (size_t)plan->first_event + plan->event_count > nh_timing_event_count)
        return clock_fail(clock, NH_BUS_CLOCK_UNAVAILABLE, nh_scpu_address(cpu));
    clock->entry = *cpu;
    clock->fetch = checked;
    memcpy(clock->expected, expected, checked.guard_count);
    memset(clock->operands, 0, sizeof(clock->operands));
    clock->plan = plan;
    clock->context_key = nh_scpu_context_key(cpu);
    clock->cycles = 0u;
    clock->cursor = 0u;
    clock->fetched_mask = 0u;
    clock->pointer_low_valid = 0u;
    clock->irq_status = cpu->p;
    clock->irq_status_valid = plan->irq_status_from_stack == 0u;
    clock->interrupt_polled = 0u;
    clock->active = 1u;
    return drain(clock);
}

static NHBusStop access_value(void *opaque, NHBusRuntime *bus, const NHScpuState *cpu,
                         uint32_t address, uint8_t kind, uint8_t *byte, NHBusValue *payload) {
    NHClockRuntime *clock = opaque;
    const NHTimingEvent *event;
    NHBusStop status;
    if (clock == NULL || bus == NULL || clock->bus != bus || cpu == NULL || byte == NULL)
        return NH_BUS_BAD_ARGUMENT;
    if (bus->failure.reason != NH_BUS_OK) return bus->failure.reason;
    if (clock->active == 0u) return clock_fail(clock, NH_BUS_CLOCK_UNAVAILABLE, address);
    status = drain(clock);
    if (status != NH_BUS_OK) return status;
    if (clock->cursor >= clock->plan->event_count)
        return clock_fail(clock, NH_BUS_CLOCK_UNAVAILABLE, address);
    event = &nh_timing_events[clock->plan->first_event + clock->cursor];
    if (deferred(clock, event)) {
        if (payload != NULL || kind != NH_TIMING_READ || address != fetch_address(clock, event->index))
            return clock_fail(clock, NH_BUS_CLOCK_UNAVAILABLE, address);
        return consume_fetch(clock, event, byte);
    }
    if (event->kind != kind) return clock_fail(clock, NH_BUS_CLOCK_UNAVAILABLE, address);
    if (payload != NULL && ((kind == NH_TIMING_READ && event->role != NH_TIMING_BLOCK_SOURCE) ||
        (kind == NH_TIMING_WRITE && event->role != NH_TIMING_BLOCK_DESTINATION)))
        return clock_fail(clock, NH_BUS_CLOCK_UNAVAILABLE, address);
    status = cycle_value(clock, kind, address, byte, 1u, payload);
    if (status != NH_BUS_OK) return status;
    if (kind == NH_TIMING_READ && event->role == NH_TIMING_POINTER && event->index == 0u) {
        clock->pointer_low = *byte;
        clock->pointer_low_valid = 1u;
    }
    if (kind == NH_TIMING_READ && event->role == NH_TIMING_STACK && event->index == 0u &&
        clock->plan->irq_status_from_stack != 0u) {
        clock->irq_status = *byte;
        clock->irq_status_valid = 1u;
    }
    ++clock->cursor;
    return NH_BUS_OK;
}

static NHBusStop read_byte(void *opaque, NHBusRuntime *bus, const NHScpuState *cpu,
                            uint32_t address, uint8_t *value) {
    return access_value(opaque, bus, cpu, address, NH_TIMING_READ, value, NULL);
}
static NHBusStop write_byte(void *opaque, NHBusRuntime *bus, const NHScpuState *cpu,
                             uint32_t address, uint8_t value) {
    return access_value(opaque, bus, cpu, address, NH_TIMING_WRITE, &value, NULL);
}
static NHBusStop copy_byte(void *opaque, NHBusRuntime *bus, const NHScpuState *cpu,
                            uint32_t source, uint32_t destination) {
    NHBusValue payload = { 0u, 0u };
    uint8_t unused = 0u;
    NHBusStop status = access_value(opaque, bus, cpu, source, NH_TIMING_READ, &unused, &payload);
    if (status != NH_BUS_OK) return status;
    return access_value(opaque, bus, cpu, destination, NH_TIMING_WRITE, &unused, &payload);
}
static NHBusStop finish(void *opaque, NHBusRuntime *bus, const NHScpuState *cpu,
                         uint32_t *cycles) {
    NHClockRuntime *clock = opaque;
    NHBusStop status;
    if (clock == NULL || bus == NULL || clock->bus != bus || cpu == NULL || cycles == NULL)
        return NH_BUS_BAD_ARGUMENT;
    if (bus->failure.reason != NH_BUS_OK) return bus->failure.reason;
    if (clock->active == 0u) return clock_fail(clock, NH_BUS_CLOCK_UNAVAILABLE, nh_scpu_address(cpu));
    status = drain(clock);
    if (status != NH_BUS_OK) return status;
    if (clock->cursor != clock->plan->event_count ||
        clock->interrupt_polled == 0u ||
        clock->fetched_mask != (uint8_t)((1u << clock->plan->fetch_count) - 1u))
        return clock_fail(clock, NH_BUS_CLOCK_UNAVAILABLE, nh_scpu_address(cpu));
    *cycles = clock->cycles;
    clock->active = 0u;
    return NH_BUS_OK;
}

NHBusStop nh_clock_bind(NHClockRuntime *clock, NHBusRuntime *bus, NHCPU_IO *io,
                         NHTimelinePort timeline) {
    NHRegisterPort port;
    if (clock == NULL || bus == NULL || io == NULL || io->bus != bus || timeline.start_cycle == NULL ||
        timeline.advance == NULL || timeline.interrupt_poll == NULL) return NH_BUS_BAD_ARGUMENT;
    port = nh_cpu_io_port(io);
    if (bus->ports.cpu_io.opaque != io || bus->ports.cpu_io.read != port.read ||
        bus->ports.cpu_io.write != port.write) return NH_BUS_BAD_ARGUMENT;
    memset(clock, 0, sizeof(*clock));
    clock->bus = bus;
    clock->math = &io->math;
    clock->timeline = timeline;
    return NH_BUS_OK;
}

NHBusStop nh_clock_reset_vector_begin(NHClockRuntime *clock, NHScpuState *cpu) {
    if (clock == NULL || clock->bus == NULL || cpu == NULL ||
        nh_scpu_validate_state(cpu) == 0) return NH_BUS_BAD_ARGUMENT;
    if (clock->bus->failure.reason != NH_BUS_OK) return clock->bus->failure.reason;
    if (clock->active != 0u || clock->reset_vector_phase != 0u)
        return clock_fail(clock, NH_BUS_CLOCK_UNAVAILABLE, 0xFFFCu);
    clock->reset_cpu = cpu;
    clock->reset_vector_phase = 1u;
    return NH_BUS_OK;
}

static NHBusStop reset_read(void *opaque, NHBusRuntime *bus, uint32_t address, uint8_t *byte) {
    NHClockRuntime *clock = opaque;
    NHBusStop status;
    NHBusValue sampled;
    if (clock == NULL || bus == NULL || clock->bus != bus || byte == NULL)
        return NH_BUS_BAD_ARGUMENT;
    if (bus->failure.reason != NH_BUS_OK) return bus->failure.reason;
    if (clock->reset_cpu == NULL ||
        (clock->reset_vector_phase == 1u ? address != 0xFFFCu :
         clock->reset_vector_phase == 2u ? address != 0xFFFDu : 1))
        return clock_fail(clock, NH_BUS_CLOCK_UNAVAILABLE, address);
    /* Untimed reset-vector sampling uses the same08 mapped/knownness owner.
     * The machine adds one186-clock startup interval, not seven extra cycles. */
    status = nh_bus_read_sample(bus, address, &sampled);
    if (status == NH_BUS_OK) status = nh_bus_require_known(bus, address, sampled, byte);
    if (status != NH_BUS_OK) return status;
    if (clock->reset_vector_phase == 1u) clock->reset_vector_phase = 2u;
    else { clock->reset_vector_phase = 0u; clock->reset_cpu = NULL; }
    return NH_BUS_OK;
}

NHClockPort nh_clock_port(NHClockRuntime *clock) {
    const NHClockPort port = { clock, begin, read_byte, write_byte, finish, reset_read, copy_byte };
    return port;
}
