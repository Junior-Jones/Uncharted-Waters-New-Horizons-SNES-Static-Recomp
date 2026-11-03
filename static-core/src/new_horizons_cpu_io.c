#include "new_horizons_cpu_io.h"
#include <string.h>

NHBusStop nh_bus_machine08_power_on(NHBusMachine08 *machine,
                                   const uint8_t *rom, size_t rom_size,
                                   NHBusPorts ports, NHPinPort pins) {
    return nh_bus_machine08_power_on_profile(machine, rom, rom_size, ports, pins,
                                             NH_MEMORY_POWER_ON_STRICT_UNKNOWN);
}

NHBusStop nh_bus_machine08_power_on_profile(NHBusMachine08 *machine,
                                           const uint8_t *rom, size_t rom_size,
                                           NHBusPorts ports, NHPinPort pins,
                                           NHMemoryPowerOnProfile profile) {
    NHBusStop status;
    if (machine == NULL) return NH_BUS_BAD_ARGUMENT;
    status = nh_bus_power_on_profile(&machine->bus, rom, rom_size, ports, profile);
    if (status != NH_BUS_OK) return status;
    nh_cpu_io_power_on(&machine->cpu_io, &machine->bus, pins);
    /* Replace the supplied CPU-I/O slot with this sole08 owner's binding.
     * Other devices are retained, never silently synthesized. */
    machine->bus.ports.cpu_io = nh_cpu_io_port(&machine->cpu_io);
    return NH_BUS_OK;
}

NHBusStop nh_bus_machine08_reset_latches(NHBusMachine08 *machine) {
    const NHBusValue released = { 0xFFu, 0xFFu };
    const NHBusFailure no_failure = { NH_BUS_OK, NH_OWNER_BUS_08, 0u, 0u, 0u };
    NHBusStop status;
    NHBusValue prior;
    if (machine == NULL || machine->cpu_io.bus != &machine->bus)
        return NH_BUS_BAD_ARGUMENT;
    if (nh_memory_warm_reset(&machine->bus.memory) != NH_MEMORY_OK)
        return NH_BUS_BAD_ROM;
    prior = machine->cpu_io.wrio;
    if (prior.value != released.value || prior.known_mask != released.known_mask) {
        const NHBusFailure prior_failure = machine->bus.failure;
        if (machine->cpu_io.pins.drive == NULL) return NH_BUS_INPUT_UNAVAILABLE;
        /* Propagate the actual pin transition; no software-write MMIO cycle
         * is invented for reset. Receiver owns any external/raster effects. */
        machine->cpu_io.wrio = released;
        /* Temporarily open a fresh diagnostic window for this receiver.
         * A failed reset must retain a preceding first fault; a successful
         * callback may not conceal a newly latched fault behind returnOK. */
        machine->bus.failure = no_failure;
        status = machine->cpu_io.pins.drive(machine->cpu_io.pins.opaque, prior, released);
        if (status == NH_BUS_OK && machine->bus.failure.reason != NH_BUS_OK)
            status = machine->bus.failure.reason;
        if (status != NH_BUS_OK) {
            if (prior_failure.reason != NH_BUS_OK)
                machine->bus.failure = prior_failure;
            return status;
        }
    }
    machine->bus.memsel = 0u;
    machine->bus.wram_port_address = 0u;
    machine->bus.failure = no_failure;
    /* MDR is not declared known by reset; ordinary reset bus cycles update
     * it. Math state is preserved, and09 must clock it during reset cycles. */
    return NH_BUS_OK;
}

void nh_cpu_io_power_on(NHCPU_IO *io, NHBusRuntime *bus, NHPinPort pins) {
    if (io == NULL) return;
    memset(io, 0, sizeof(*io));
    io->bus = bus;
    io->pins = pins;
    io->wrio.value = 0xFFu;
    io->wrio.known_mask = 0xFFu;
    nh_math_power_on(&io->math);
}

static NHBusStop nh_cpu_io_read(void *opaque, uint16_t reg, NHDrivenByte *byte) {
    NHCPU_IO *io = (NHCPU_IO *)opaque;
    if (io == NULL || io->bus == NULL || byte == NULL) return NH_BUS_BAD_ARGUMENT;
    if (reg >= 0x4214u && reg <= 0x4217u) return nh_math_read(&io->math, reg, byte);
    if (reg == 0x4213u) {
        const uint8_t low = (uint8_t)((0xFFu ^ io->wrio.value) & io->wrio.known_mask);
        NHBusValue pins = { 0u, 0u };
        NHBusStop status;
        if (low != 0xFFu) {
            if (io->pins.sample == NULL) return NH_BUS_INPUT_UNAVAILABLE;
            status = io->pins.sample(io->pins.opaque, &pins);
            if (status != NH_BUS_OK) return status;
        }
        byte->value = (uint8_t)(io->wrio.value & pins.value);
        /* Open-collector zero annihilates an unknown external pin level.
         * Known external zero similarly annihilates an unknown output. */
        byte->known_mask = (uint8_t)(low |
            ((0xFFu ^ pins.value) & pins.known_mask) |
            (io->wrio.known_mask & pins.known_mask));
        byte->driven_mask = 0xFFu;
        return NH_BUS_OK;
    }
    if (reg == 0x4201u || (reg >= 0x4202u && reg <= 0x4206u) || reg == 0x420Du) {
        /* All these are write-only. Reading does not reveal the shadow latch. */
        byte->value = 0u;
        byte->known_mask = 0u;
        byte->driven_mask = 0u;
        return NH_BUS_OK;
    }
    return NH_BUS_UNPROVED_REGISTER;
}

static NHBusStop nh_cpu_io_write(void *opaque, uint16_t reg, NHBusValue byte) {
    NHCPU_IO *io = (NHCPU_IO *)opaque;
    if (io == NULL || io->bus == NULL) return NH_BUS_BAD_ARGUMENT;
    if (reg >= 0x4202u && reg <= 0x4206u) return nh_math_write(&io->math, reg, byte);
    if (reg == 0x420Du) {
        if ((byte.known_mask & 1u) == 0u) return NH_BUS_UNKNOWN_BYTE;
        io->bus->memsel = byte.value & 1u;
        return NH_BUS_OK;
    }
    if (reg == 0x4201u) {
        NHBusValue prior = io->wrio;
        if (byte.known_mask != 0xFFu) return NH_BUS_UNKNOWN_BYTE;
        if (io->pins.drive == NULL) return NH_BUS_INPUT_UNAVAILABLE;
        io->wrio = byte;
        /* The later input/raster owners see both levels, not a copied WRIO
         * register. They own external pin settling and counter-latch effects. */
        return io->pins.drive(io->pins.opaque, prior, byte);
    }
    if (reg >= 0x4213u && reg <= 0x4217u) return NH_BUS_OK;
    return NH_BUS_UNPROVED_REGISTER;
}

NHRegisterPort nh_cpu_io_port(NHCPU_IO *io) {
    NHRegisterPort port;
    port.opaque = io;
    port.read = nh_cpu_io_read;
    port.write = nh_cpu_io_write;
    return port;
}
