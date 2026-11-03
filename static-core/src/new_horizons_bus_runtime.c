#include "new_horizons_bus_runtime.h"

NHBusStop nh_bus_power_on(NHBusRuntime *bus, const uint8_t *rom,
                         size_t rom_size, NHBusPorts ports) {
    return nh_bus_power_on_profile(bus, rom, rom_size, ports,
                                   NH_MEMORY_POWER_ON_STRICT_UNKNOWN);
}

NHBusStop nh_bus_power_on_profile(NHBusRuntime *bus, const uint8_t *rom,
                                 size_t rom_size, NHBusPorts ports,
                                 NHMemoryPowerOnProfile profile) {
    NHMemoryResult result;
    const NHBusValue unknown = { 0u, 0u };
    const NHBusFailure no_failure = { NH_BUS_OK, NH_OWNER_BUS_08, 0u, 0u, 0u };
    if (bus == NULL || rom == NULL) return NH_BUS_BAD_ARGUMENT;
    /* Memory verifies the image before changing any state. Do not clear this
     * bus first: a rejected cartridge must not destroy an existing instance. */
    result = nh_memory_power_on_profile(&bus->memory, rom, rom_size, profile);
    if (result != NH_MEMORY_OK) return NH_BUS_BAD_ROM;
    bus->ports = ports;
    bus->mdr = unknown;
    bus->failure = no_failure;
    bus->wram_port_address = 0u;
    bus->memsel = 0u;
    return NH_BUS_OK;
}

static NHBusStop nh_bus_fail(NHBusRuntime *bus, NHBusStop reason,
                             NHBusComponent owner, uint32_t address,
                             NHBusValue byte) {
    if (bus != NULL && bus->failure.reason == NH_BUS_OK) {
        if (reason == NH_BUS_PPU_UNAVAILABLE) owner = NH_OWNER_PPU_11;
        else if (reason == NH_BUS_APUIO_UNAVAILABLE) owner = NH_OWNER_APUIO_12;
        else if (reason == NH_BUS_DMA_UNAVAILABLE) owner = NH_OWNER_DMA_10;
        else if (reason == NH_BUS_INPUT_UNAVAILABLE) owner = NH_OWNER_INPUT_15;
        else if (reason == NH_BUS_CLOCK_UNAVAILABLE) owner = NH_OWNER_CLOCK_09;
        bus->failure.reason = reason;
        bus->failure.owner = owner;
        bus->failure.address = address;
        bus->failure.value = byte.value;
        bus->failure.known_mask = byte.known_mask;
    }
    return reason;
}

static NHRegisterPort *nh_register_port(NHBusRuntime *bus, NHBusKind kind,
                                        NHBusStop *missing) {
    switch (kind) {
        case NH_BUS_PPU: *missing = NH_BUS_PPU_UNAVAILABLE; return &bus->ports.ppu;
        case NH_BUS_APUIO: *missing = NH_BUS_APUIO_UNAVAILABLE; return &bus->ports.apuio;
        case NH_BUS_DMA_IO: *missing = NH_BUS_DMA_UNAVAILABLE; return &bus->ports.dma;
        case NH_BUS_INPUT_IO: *missing = NH_BUS_INPUT_UNAVAILABLE; return &bus->ports.input;
        case NH_BUS_SCHEDULER_IO:
            *missing = NH_BUS_CLOCK_UNAVAILABLE; return &bus->ports.scheduler_registers;
        case NH_BUS_CPU_IO: *missing = NH_BUS_CPU_IO_UNAVAILABLE; return &bus->ports.cpu_io;
        default: *missing = NH_BUS_UNPROVED_REGISTER; return NULL;
    }
}

NHBusStop nh_bus_sample_reset_vector(NHBusRuntime *bus, uint16_t *vector) {
    uint8_t low = 0u, high = 0u;
    NHBusStop status;
    const NHBusValue unknown = { 0u, 0u };
    if (bus == NULL || vector == NULL) return NH_BUS_BAD_ARGUMENT;
    if (bus->failure.reason != NH_BUS_OK) return bus->failure.reason;
    if (bus->ports.clock.reset_read == NULL)
        return nh_bus_fail(bus, NH_BUS_CLOCK_UNAVAILABLE, NH_OWNER_CLOCK_09,
                           0x00FFFCu, unknown);
    status = bus->ports.clock.reset_read(bus->ports.clock.opaque, bus, 0x00FFFCu, &low);
    if (status != NH_BUS_OK)
        return nh_bus_fail(bus, status, NH_OWNER_CLOCK_09, 0x00FFFCu, unknown);
    if (bus->failure.reason != NH_BUS_OK) return bus->failure.reason;
    status = bus->ports.clock.reset_read(bus->ports.clock.opaque, bus, 0x00FFFDu, &high);
    if (status != NH_BUS_OK)
        return nh_bus_fail(bus, status, NH_OWNER_CLOCK_09, 0x00FFFDu, unknown);
    if (bus->failure.reason != NH_BUS_OK) return bus->failure.reason;
    *vector = (uint16_t)(low | ((uint16_t)high << 8u));
    return NH_BUS_OK;
}

NHBusStop nh_bus_read_sample(NHBusRuntime *bus, uint32_t address, NHBusValue *value) {
    NHBusRegion region;
    NHBusValue result;
    NHMemoryByte cell;
    NHDrivenByte driven = { 0u, 0u, 0u };
    NHBusStop status;
    NHRegisterPort *port;
    if (bus == NULL || value == NULL || nh_bus_classify(address, &region) == 0)
        return NH_BUS_BAD_ARGUMENT;
    if (bus->failure.reason != NH_BUS_OK) return bus->failure.reason;
    result = bus->mdr;
    if (region.kind == NH_BUS_ROM || region.kind == NH_BUS_WRAM || region.kind == NH_BUS_SRAM) {
        if (nh_memory_read(&bus->memory, address, &cell) != NH_MEMORY_OK)
            return nh_bus_fail(bus, NH_BUS_MEMORY_FAILURE, region.owner, address, result);
        result.value = cell.value;
        result.known_mask = cell.known != 0u ? 0xFFu : 0u;
    } else if (region.kind == NH_BUS_WRAM_PORT) {
        if (region.offset == 0x2180u) {
            const uint32_t target = 0x7E0000u | bus->wram_port_address;
            if (bus->wram_port_address >= NH_WRAM_BYTES ||
                nh_memory_read(&bus->memory, target, &cell) != NH_MEMORY_OK)
                return nh_bus_fail(bus, NH_BUS_MEMORY_FAILURE, region.owner, address, result);
            result.value = cell.value;
            result.known_mask = cell.known != 0u ? 0xFFu : 0u;
            bus->wram_port_address = (bus->wram_port_address + 1u) & 0x1FFFFu;
        }
        /* Reading the three write-only address latches returns open bus. */
    } else if (region.kind != NH_BUS_OPEN_EXTERNAL && region.kind != NH_BUS_OPEN_INTERNAL) {
        port = nh_register_port(bus, region.kind, &status);
        if (port == NULL || port->read == NULL)
            return nh_bus_fail(bus, status, region.owner, address, result);
        status = port->read(port->opaque, (uint16_t)region.offset, &driven);
        if (status != NH_BUS_OK)
            return nh_bus_fail(bus, status, region.owner, address, result);
        if (bus->failure.reason != NH_BUS_OK) return bus->failure.reason;
        {
            const uint8_t undriven = (uint8_t)(0xFFu ^ driven.driven_mask);
            result.value = (uint8_t)((driven.value & driven.driven_mask) |
                                     (bus->mdr.value & undriven));
            result.known_mask = (uint8_t)((driven.known_mask & driven.driven_mask) |
                                          (bus->mdr.known_mask & undriven));
        }
    }
    /* Internal CPU register reads sample returned bits but do not replace
     * the external MDR with a fabricated full register byte. */
    if (region.internal_io == 0u) bus->mdr = result;
    *value = result;
    return NH_BUS_OK;
}

NHBusStop nh_bus_write_commit(NHBusRuntime *bus, uint32_t address, NHBusValue value) {
    NHBusRegion region;
    NHBusStop status;
    NHRegisterPort *port;
    NHMemoryByte cell;
    if (bus == NULL || nh_bus_classify(address, &region) == 0) return NH_BUS_BAD_ARGUMENT;
    if (bus->failure.reason != NH_BUS_OK) return bus->failure.reason;
    cell.value = value.value;
    cell.known = value.known_mask == 0xFFu ? 1u : 0u;
    if (region.kind == NH_BUS_ROM || region.kind == NH_BUS_WRAM || region.kind == NH_BUS_SRAM) {
        if (nh_memory_write(&bus->memory, address, cell) != NH_MEMORY_OK)
            return nh_bus_fail(bus, NH_BUS_MEMORY_FAILURE, region.owner, address, value);
    } else if (region.kind == NH_BUS_WRAM_PORT) {
        if (region.offset == 0x2180u) {
            const uint32_t target = 0x7E0000u | bus->wram_port_address;
            if (bus->wram_port_address >= NH_WRAM_BYTES ||
                nh_memory_write(&bus->memory, target, cell) != NH_MEMORY_OK)
                return nh_bus_fail(bus, NH_BUS_MEMORY_FAILURE, region.owner, address, value);
            bus->wram_port_address = (bus->wram_port_address + 1u) & 0x1FFFFu;
        } else {
            const uint8_t consumed = region.offset == 0x2183u ? 1u : 0xFFu;
            if ((value.known_mask & consumed) != consumed)
                return nh_bus_fail(bus, NH_BUS_UNKNOWN_BYTE, region.owner, address, value);
            if (region.offset == 0x2181u)
                bus->wram_port_address = (bus->wram_port_address & 0x1FF00u) | value.value;
            else if (region.offset == 0x2182u)
                bus->wram_port_address = (bus->wram_port_address & 0x100FFu) |
                                         ((uint32_t)value.value << 8u);
            else
                bus->wram_port_address = (bus->wram_port_address & 0x0FFFFu) |
                                         ((uint32_t)(value.value & 1u) << 16u);
        }
    } else if (region.kind != NH_BUS_OPEN_EXTERNAL && region.kind != NH_BUS_OPEN_INTERNAL) {
        port = nh_register_port(bus, region.kind, &status);
        if (port == NULL || port->write == NULL)
            return nh_bus_fail(bus, status, region.owner, address, value);
        status = port->write(port->opaque, (uint16_t)region.offset, value);
        if (status != NH_BUS_OK)
            return nh_bus_fail(bus, status, region.owner, address, value);
        if (bus->failure.reason != NH_BUS_OK) return bus->failure.reason;
    }
    if (region.internal_io == 0u) bus->mdr = value;
    return NH_BUS_OK;
}

NHBusStop nh_bus_require_known(NHBusRuntime *bus, uint32_t address,
                              NHBusValue byte, uint8_t *value) {
    if (bus == NULL || value == NULL) return NH_BUS_BAD_ARGUMENT;
    if (bus->failure.reason != NH_BUS_OK) return bus->failure.reason;
    if (byte.known_mask != 0xFFu)
        return nh_bus_fail(bus, NH_BUS_UNKNOWN_BYTE, NH_OWNER_BUS_08, address, byte);
    *value = byte.value;
    return NH_BUS_OK;
}

static int nh_bus_guard_adapter(void *opaque, const NHScpuState *cpu,
                                uint32_t address, const uint8_t *expected, size_t count) {
    NHBusRuntime *bus = (NHBusRuntime *)opaque;
    NHStaticFetch fetch;
    size_t index;
    NHMemoryByte cell;
    const NHBusValue unknown = { 0u, 0u };
    if (bus == NULL || expected == NULL ||
        nh_static_fetch_descriptor(cpu, address, count, &fetch) == 0)
        return 0;
    if (bus->failure.reason != NH_BUS_OK) return 0;
    if (fetch.executable_epoch != 0u) {
        /* Reject the predecessor's constant-bank authority. Only this exact
         * registered shape can select the live-operand native successor.
         * Zero bank fields normalize the descriptor; they are not guest data. */
        if (expected[0] != 0x54u || expected[1] != 0u ||
            expected[2] != 0u || expected[3] != 0x6Bu) {
            nh_bus_fail(bus, NH_BUS_BAD_STATIC_GUARD, NH_OWNER_BUS_08, address, unknown);
            return 0;
        }
    }
    /* Metadata validation is observation only. The09 begin/read/write/finish
     * owner performs every actual source fetch on this same normal bus,
     * including deferred JSL operands and the distinct WRAM epoch lengths. */
    for (index = 0u; index < count; ++index) {
        if ((fetch.immutable_byte_mask & (1u << index)) != 0u) {
            const uint32_t target = (address & 0xFF0000u) |
                                    ((address + (uint32_t)index) & 0xFFFFu);
            if (nh_memory_peek(&bus->memory, target, &cell) != NH_MEMORY_OK ||
                cell.known == 0u || cell.value != expected[index]) {
                nh_bus_fail(bus, NH_BUS_BAD_STATIC_GUARD, NH_OWNER_BUS_08, target, unknown);
                return 0;
            }
        }
    }
    if (bus->ports.clock.begin == NULL) {
        nh_bus_fail(bus, NH_BUS_CLOCK_UNAVAILABLE, NH_OWNER_CLOCK_09, address, unknown);
        return 0;
    }
    {
        const NHBusStop status = bus->ports.clock.begin(bus->ports.clock.opaque, bus, cpu, &fetch, expected);
        if (status != NH_BUS_OK)
            nh_bus_fail(bus, status, NH_OWNER_CLOCK_09, address, unknown);
        return status == NH_BUS_OK && bus->failure.reason == NH_BUS_OK;
    }
}

static int nh_bus_cpu_read_adapter(void *opaque, const NHScpuState *cpu,
                                   uint32_t address, uint8_t *value) {
    NHBusRuntime *bus = (NHBusRuntime *)opaque;
    const NHBusValue unknown = { 0u, 0u };
    if (bus == NULL || value == NULL) return 0;
    if (bus->failure.reason != NH_BUS_OK) return 0;
    if (bus->ports.clock.read == NULL) {
        nh_bus_fail(bus, NH_BUS_CLOCK_UNAVAILABLE, NH_OWNER_CLOCK_09, address, unknown);
        return 0;
    }
    {
        const NHBusStop status = bus->ports.clock.read(bus->ports.clock.opaque, bus, cpu, address, value);
        if (status != NH_BUS_OK)
            nh_bus_fail(bus, status, NH_OWNER_CLOCK_09, address, unknown);
        return status == NH_BUS_OK && bus->failure.reason == NH_BUS_OK;
    }
}

static int nh_bus_cpu_write_adapter(void *opaque, const NHScpuState *cpu,
                                    uint32_t address, uint8_t value) {
    NHBusRuntime *bus = (NHBusRuntime *)opaque;
    const NHBusValue byte = { value, 0xFFu };
    if (bus == NULL) return 0;
    if (bus->failure.reason != NH_BUS_OK) return 0;
    if (bus->ports.clock.write == NULL) {
        nh_bus_fail(bus, NH_BUS_CLOCK_UNAVAILABLE, NH_OWNER_CLOCK_09, address, byte);
        return 0;
    }
    {
        const NHBusStop status = bus->ports.clock.write(bus->ports.clock.opaque, bus, cpu, address, value);
        if (status != NH_BUS_OK)
            nh_bus_fail(bus, status, NH_OWNER_CLOCK_09, address, byte);
        return status == NH_BUS_OK && bus->failure.reason == NH_BUS_OK;
    }
}

static int nh_bus_cpu_finish_adapter(void *opaque, const NHScpuState *cpu,
                                     uint32_t *cycles) {
    NHBusRuntime *bus = (NHBusRuntime *)opaque;
    const NHBusValue unknown = { 0u, 0u };
    if (bus == NULL || cpu == NULL || cycles == NULL) return 0;
    if (bus->failure.reason != NH_BUS_OK) return 0;
    if (bus->ports.clock.finish == NULL) {
        nh_bus_fail(bus, NH_BUS_CLOCK_UNAVAILABLE, NH_OWNER_CLOCK_09,
                    nh_scpu_address(cpu), unknown);
        return 0;
    }
    {
        const NHBusStop status = bus->ports.clock.finish(bus->ports.clock.opaque, bus, cpu, cycles);
        if (status != NH_BUS_OK)
            nh_bus_fail(bus, status, NH_OWNER_CLOCK_09, nh_scpu_address(cpu), unknown);
        return status == NH_BUS_OK && bus->failure.reason == NH_BUS_OK;
    }
}

static int nh_bus_cpu_copy_adapter(void *opaque, const NHScpuState *cpu,
                                   uint32_t source, uint32_t destination) {
    NHBusRuntime *bus = opaque;
    const NHBusValue unknown = { 0u, 0u };
    NHBusStop status;
    if (bus == NULL || cpu == NULL) return 0;
    if (bus->failure.reason != NH_BUS_OK) return 0;
    if (bus->ports.clock.copy8 == NULL) {
        nh_bus_fail(bus, NH_BUS_CLOCK_UNAVAILABLE, NH_OWNER_CLOCK_09, source, unknown);
        return 0;
    }
    status = bus->ports.clock.copy8(bus->ports.clock.opaque, bus, cpu, source, destination);
    if (status != NH_BUS_OK)
        nh_bus_fail(bus, status, NH_OWNER_CLOCK_09, source, unknown);
    return status == NH_BUS_OK && bus->failure.reason == NH_BUS_OK;
}

NHScpuBus nh_bus_scpu_view(NHBusRuntime *bus) {
    NHScpuBus view;
    view.opaque = bus;
    view.guard_code = nh_bus_guard_adapter;
    view.read8 = nh_bus_cpu_read_adapter;
    view.write8 = nh_bus_cpu_write_adapter;
    view.finish_instruction = nh_bus_cpu_finish_adapter;
    view.copy8 = nh_bus_cpu_copy_adapter;
    return view;
}
