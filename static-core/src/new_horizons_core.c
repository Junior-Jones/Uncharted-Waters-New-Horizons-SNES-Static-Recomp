#include "new_horizons_core.h"

#include "new_horizons_apu.h"
#include "new_horizons_dma.h"
#include "new_horizons_input.h"
#include "new_horizons_machine.h"
#include "new_horizons_ppu.h"
#include "new_horizons_sdsp.h"
#include "new_horizons_sram_file.h"
#include "new_horizons_rom_identity.h"
#include "../generated/integration/new_horizons_build_identity.h"

#include <stdlib.h>
#include <string.h>

_Static_assert((unsigned)NH_CORE_ROM_BYTES == (unsigned)NH_ROM_BYTES,
               "public ROM size drift");
_Static_assert((unsigned)NH_CORE_SRAM_FILE_BYTES == (unsigned)NH_SRAM_FILE_BYTES,
               "public SRAM image size drift");
_Static_assert((unsigned)NH_CORE_FRAME_PIXELS == (unsigned)NH_PPU_FRAME_PIXELS,
               "public frame capacity drift");
_Static_assert((unsigned)NH_CORE_POWER_ON_STRICT_UNKNOWN ==
               (unsigned)NH_MEMORY_POWER_ON_STRICT_UNKNOWN,
               "strict power-on profile drift");
_Static_assert((unsigned)NH_CORE_POWER_ON_DETERMINISTIC_ZERO_WRAM_V1 ==
               (unsigned)NH_MEMORY_POWER_ON_DETERMINISTIC_ZERO_WRAM_V1,
               "deterministic power-on profile drift");
_Static_assert((unsigned)NH_CORE_POWER_ON_DETERMINISTIC_ZERO_MACHINE_V2 ==
               (unsigned)NH_MEMORY_POWER_ON_DETERMINISTIC_ZERO_MACHINE_V2,
               "deterministic machine power-on profile drift");
_Static_assert((unsigned)NH_CORE_POWER_ON_DETERMINISTIC_ZERO_MACHINE_ARAM_V3 ==
               (unsigned)NH_MEMORY_POWER_ON_DETERMINISTIC_ZERO_MACHINE_ARAM_V3,
               "deterministic machine/ARAM power-on profile drift");

struct NHCore {
    uint8_t *rom;
    NHBusMachine08 storage;
    NHScheduler scheduler;
    NHClockRuntime clock;
    NHScpuState cpu;
    NHMachine09 machine;
    NHDma10 dma;
    NHPPU11 ppu;
    NHApu12 apu;
    NHInput15 input;
    NHSdsp16 sdsp;
    uint64_t terminal_raster_events;
    uint64_t terminal_cpu_boundaries;
    uint64_t pin_samples;
    uint64_t pin_drives;
};

static void sea_camera_seed(NHCore *core);
static void sea_retirement_seed(NHCore *core);
static void sea_camera_observe(NHCore *core);
static void sea_discovery_observe(NHCore *core);
static void sea_marker_retire_observe(NHCore *core);
static void sea_fleet_observe(NHCore *core);
static void chart_source_observe(NHCore *core);
static int sea_model_word(unsigned word, unsigned base, unsigned model);
static int sea_retired_actor(const NHCore *core, unsigned slot,
                            const NHCoreSeaTerrainInfo *scene,
                            NHPortActor14 *actor, unsigned *fleet);

typedef struct NHCoreSnapshotHeader17 {
    uint8_t magic[8];
    uint32_t version;
    uint32_t header_size;
    uint64_t state_size;
    uint64_t state_hash;
    uint8_t rom_sha256[32];
    uint8_t build_sha256[32];
    uint8_t pointer_size;
    uint8_t size_t_size;
    uint8_t reserved[14];
} NHCoreSnapshotHeader17;

enum { NH_CORE_SNAPSHOT_VERSION = 2u };

static NHCoreStatus public_status(NHBusStop status) {
    return status >= NH_BUS_OK && status <= NH_BUS_UNPROVED_REGISTER ?
        (NHCoreStatus)status : NH_CORE_CLOCK_UNAVAILABLE;
}

static int assembled(const NHCore *core) {
    return core != NULL && core->rom != NULL &&
           core->machine.storage == &core->storage &&
           core->machine.scheduler == &core->scheduler &&
           core->machine.clock == &core->clock &&
           core->machine.cpu == &core->cpu &&
           core->scheduler.bus == &core->storage.bus &&
           core->ppu.bus == &core->storage.bus &&
           core->apu.bus == &core->storage.bus &&
           core->input.bus == &core->storage.bus &&
           core->sdsp.bus == &core->storage.bus;
}

static int snapshot_quiescent(const NHCore *core) {
    return assembled(core) && core->scheduler.advancing == 0u &&
           core->scheduler.transfer_advancing == 0u &&
           core->dma.servicing == 0u && core->clock.active == 0u &&
           core->clock.reset_vector_phase == 0u &&
           core->clock.reset_cpu == NULL &&
           core->machine.cpu_reset_phase == NH_CPU_RESET_NONE;
}

static uint64_t snapshot_hash(const uint8_t *bytes, size_t size) {
    uint64_t hash = UINT64_C(1469598103934665603);
    size_t index;
    for (index = 0u; index < size; ++index) {
        hash ^= bytes[index];
        hash *= UINT64_C(1099511628211);
    }
    return hash;
}

static int snapshot_build_compatible(const uint8_t digest[32]) {
    /* These released 1.0.0 predecessors have the same serialized ABI and
     * saved-state continuation. Admit only these qualified identities;
     * all other old builds still
     * reject, and normal ROM/version/size/checksum validation remains intact. */
    static const uint8_t reset_predecessor[32]={
        0xdc,0x12,0xa2,0x3d,0xd4,0xbf,0x58,0x49,0x55,0x4e,0x9c,0x9e,0x76,0x42,0x10,0x4d,
        0x75,0xdd,0x27,0xd1,0xa8,0x25,0xf0,0xd5,0x60,0x28,0x8a,0xe6,0x61,0x65,0x55,0xd8};
    static const uint8_t snapshot_fix_release[32]={
        0x26,0x1b,0x75,0x00,0xcf,0xa5,0x99,0xef,0x34,0x0b,0x6d,0x6d,0x4e,0x11,0x25,0x69,
        0x3e,0x54,0x6f,0xdc,0x43,0xe0,0xf8,0xc3,0xe6,0xf1,0x8e,0xd4,0xa2,0x2a,0x82,0xa5};
    return memcmp(digest,nh_v17_build_identity_sha256,32u)==0 ||
           memcmp(digest,reset_predecessor,32u)==0 ||
           memcmp(digest,snapshot_fix_release,32u)==0;
}

static void clear_snapshot_bindings(NHCore *copy) {
    copy->rom = NULL;
    copy->storage.bus.memory.verified_rom = NULL;
    memset(&copy->storage.bus.ports, 0, sizeof(copy->storage.bus.ports));
    copy->storage.cpu_io.bus = NULL;
    memset(&copy->storage.cpu_io.pins, 0, sizeof(copy->storage.cpu_io.pins));
    copy->scheduler.bus = NULL;
    memset(&copy->scheduler.receivers, 0, sizeof(copy->scheduler.receivers));
    memset(&copy->scheduler.autojoy, 0, sizeof(copy->scheduler.autojoy));
    copy->clock.bus = NULL;
    copy->clock.math = NULL;
    memset(&copy->clock.timeline, 0, sizeof(copy->clock.timeline));
    copy->clock.plan = NULL;
    copy->clock.reset_cpu = NULL;
    copy->machine.storage = NULL;
    copy->machine.scheduler = NULL;
    copy->machine.clock = NULL;
    copy->machine.cpu = NULL;
    copy->dma.bus = NULL;
    copy->dma.scheduler = NULL;
    memset(&copy->dma.downstream, 0, sizeof(copy->dma.downstream));
    copy->ppu.bus = NULL;
    copy->ppu.scheduler = NULL;
    copy->ppu.wrio = NULL;
    copy->ppu.port_ui = NULL;
    memset(&copy->ppu.downstream, 0, sizeof(copy->ppu.downstream));
    copy->apu.bus = NULL;
    copy->apu.scheduler = NULL;
    memset(&copy->apu.downstream, 0, sizeof(copy->apu.downstream));
    copy->apu.sdsp = NULL;
    copy->input.bus = NULL;
    copy->input.scheduler = NULL;
    copy->sdsp.bus = NULL;
    copy->sdsp.aram = NULL;
    copy->sdsp.aram_known = NULL;
}

static int snapshot_bindings_clear(const NHCore *copy) {
    NHCore *check;
    int clear;
    if (copy == NULL) return 0;
    check = (NHCore *)malloc(sizeof(*check));
    if (check == NULL) return 0;
    memcpy(check, copy, sizeof(*check));
    clear_snapshot_bindings(check);
    clear = memcmp(check, copy, sizeof(*copy)) == 0;
    free(check);
    return clear;
}

static void restore_snapshot_bindings(NHCore *core, const NHCore *bindings) {
    core->rom = bindings->rom;
    core->storage.bus.memory.verified_rom = bindings->storage.bus.memory.verified_rom;
    core->storage.bus.ports = bindings->storage.bus.ports;
    core->storage.cpu_io.bus = bindings->storage.cpu_io.bus;
    core->storage.cpu_io.pins = bindings->storage.cpu_io.pins;
    core->scheduler.bus = bindings->scheduler.bus;
    core->scheduler.receivers = bindings->scheduler.receivers;
    core->scheduler.autojoy = bindings->scheduler.autojoy;
    core->clock.bus = bindings->clock.bus;
    core->clock.math = bindings->clock.math;
    core->clock.timeline = bindings->clock.timeline;
    core->clock.plan = NULL;
    core->clock.reset_cpu = NULL;
    core->machine.storage = bindings->machine.storage;
    core->machine.scheduler = bindings->machine.scheduler;
    core->machine.clock = bindings->machine.clock;
    core->machine.cpu = bindings->machine.cpu;
    core->dma.bus = bindings->dma.bus;
    core->dma.scheduler = bindings->dma.scheduler;
    core->dma.downstream = bindings->dma.downstream;
    core->ppu.bus = bindings->ppu.bus;
    core->ppu.scheduler = bindings->ppu.scheduler;
    core->ppu.wrio = bindings->ppu.wrio;
    core->ppu.port_ui = bindings->ppu.port_ui;
    core->ppu.downstream = bindings->ppu.downstream;
    core->apu.bus = bindings->apu.bus;
    core->apu.scheduler = bindings->apu.scheduler;
    core->apu.downstream = bindings->apu.downstream;
    core->apu.sdsp = bindings->apu.sdsp;
    core->input.bus = bindings->input.bus;
    core->input.scheduler = bindings->input.scheduler;
    core->sdsp.bus = bindings->sdsp.bus;
    core->sdsp.aram = bindings->sdsp.aram;
    core->sdsp.aram_known = bindings->sdsp.aram_known;
}

static int snapshot_failure_valid(const NHBusFailure *failure) {
    if (failure == NULL || failure->reason < NH_BUS_OK ||
        failure->reason > NH_BUS_UNPROVED_REGISTER) return 0;
    /* nh_bus_power_on_profile initializes the no-failure record to BUS_08. */
    if (failure->reason == NH_BUS_OK)
        return failure->owner == NH_OWNER_BUS_08 && failure->address == 0u &&
               failure->value == 0u && failure->known_mask == 0u;
    return failure->owner == NH_OWNER_BUS_08 ||
           failure->owner == NH_OWNER_CLOCK_09 ||
           failure->owner == NH_OWNER_DMA_10 ||
           failure->owner == NH_OWNER_PPU_11 ||
           failure->owner == NH_OWNER_APUIO_12 ||
           failure->owner == NH_OWNER_INPUT_15 ||
           failure->owner == NH_OWNER_SDSP_16;
}

static int snapshot_state_valid(const NHCore *state) {
    return state != NULL && snapshot_bindings_clear(state) &&
           state->storage.bus.memory.rom_size == NH_CORE_ROM_BYTES &&
           state->storage.bus.memory.power_on_profile <=
               NH_MEMORY_POWER_ON_DETERMINISTIC_ZERO_MACHINE_ARAM_V3 &&
           snapshot_failure_valid(&state->storage.bus.failure) &&
           state->scheduler.advancing == 0u &&
           state->scheduler.transfer_advancing == 0u &&
           state->dma.servicing == 0u && state->clock.active == 0u &&
           state->clock.wrapper_result_known[0] <= 1u &&
           state->clock.wrapper_result_known[1] <= 1u &&
           state->clock.wrapper_result_read_mask <= 3u &&
           state->clock.wrapper_result_write_mask <= 3u &&
           state->clock.wrapper_result_pending <= 1u &&
           state->clock.nmi_preserve_read_mask <= 3u &&
           state->clock.nmi_preserve_write_mask <= 3u &&
           state->clock.nmi_preserve_pending <= 1u &&
           state->clock.reset_vector_phase == 0u &&
           state->machine.cpu_reset_phase == NH_CPU_RESET_NONE &&
           state->scheduler.scanline < 263u &&
           state->scheduler.hclock <= NH_NTSC_NORMAL_LINE_CLOCKS &&
           state->scheduler.smp.target_cycles ==
               state->scheduler.smp.target_phase_units / 2u &&
           state->ppu.published_height <= NH_PPU_FRAME_MAX_HEIGHT &&
           state->apu.phase <= NH_APU12_FAILED &&
           state->apu.cpu_to_smp_pending_mask <= 0x0Fu &&
           state->apu.smp_phase_units == state->apu.smp_cycles * 2u &&
           state->sdsp.phase < NH_SDSP16_PHASES &&
           state->sdsp.pcm_read < NH_SDSP16_FIFO_FRAMES &&
           state->sdsp.pcm_write < NH_SDSP16_FIFO_FRAMES &&
           state->sdsp.pcm_count <= NH_SDSP16_FIFO_FRAMES &&
           nh_scpu_validate_state(&state->cpu) != 0;
}

static NHBusStop terminal_smp(void *opaque, NHBusRuntime *bus,
                              uint64_t target_phase_units) {
    NHCore *core = (NHCore *)opaque;
    if (core == NULL || bus != &core->storage.bus ||
        target_phase_units + UINT64_C(1) < core->apu.smp_phase_units)
        return NH_BUS_BAD_ARGUMENT;
    return NH_BUS_OK;
}

static NHBusStop terminal_raster(void *opaque, NHBusRuntime *bus,
                                 const NHScheduler *scheduler,
                                 NHRasterEvent event) {
    NHCore *core = (NHCore *)opaque;
    (void)event;
    if (core == NULL || bus != &core->storage.bus ||
        scheduler != &core->scheduler) return NH_BUS_BAD_ARGUMENT;
    ++core->terminal_raster_events;
    return NH_BUS_OK;
}

static NHBusStop terminal_boundary(void *opaque, NHBusRuntime *bus,
                                   const NHScheduler *scheduler, uint8_t kind,
                                   uint32_t address, uint8_t clocks) {
    NHCore *core = (NHCore *)opaque;
    (void)kind;
    (void)address;
    if (core == NULL || bus != &core->storage.bus ||
        scheduler != &core->scheduler ||
        (clocks != 6u && clocks != 8u && clocks != 12u))
        return NH_BUS_BAD_ARGUMENT;
    ++core->terminal_cpu_boundaries;
    return NH_BUS_OK;
}

static NHBusStop pin_sample(void *opaque, NHBusValue *pins) {
    NHCore *core = (NHCore *)opaque;
    if (core == NULL || pins == NULL) return NH_BUS_BAD_ARGUMENT;
    pins->value = 0xFFu;
    pins->known_mask = 0xFFu;
    ++core->pin_samples;
    return NH_BUS_OK;
}

static NHBusStop pin_drive(void *opaque, NHBusValue prior, NHBusValue next) {
    NHCore *core = (NHCore *)opaque;
    (void)prior;
    if (core == NULL || next.known_mask != 0xFFu) return NH_BUS_UNKNOWN_BYTE;
    ++core->pin_drives;
    return NH_BUS_OK;
}

static NHBusStop device_reset(void *opaque, NHBusRuntime *bus,
                              const NHScheduler *scheduler,
                              NHDeviceResetPhase phase,
                              uint32_t hold_master_clocks) {
    NHCore *core = (NHCore *)opaque;
    NHBusStop status;
    if (!assembled(core) || bus != &core->storage.bus ||
        scheduler != &core->scheduler ||
        hold_master_clocks != NH_RESET_STARTUP_MASTER_CLOCKS)
        return NH_BUS_BAD_ARGUMENT;
    if (phase == NH_DEVICE_RESET_PREFLIGHT || phase == NH_DEVICE_RESET_RELEASE)
        return NH_BUS_OK;
    if (phase != NH_DEVICE_RESET_ASSERT) return NH_BUS_BAD_ARGUMENT;
    core->clock.wrapper_result_known[0] = 0u;
    core->clock.wrapper_result_known[1] = 0u;
    core->clock.wrapper_result_read_mask = 0u;
    core->clock.wrapper_result_write_mask = 0u;
    core->clock.wrapper_result_pending = 0u;
    core->clock.nmi_preserve_known[0] = 0u;
    core->clock.nmi_preserve_known[1] = 0u;
    core->clock.nmi_preserve_read_mask = 0u;
    core->clock.nmi_preserve_write_mask = 0u;
    core->clock.nmi_preserve_pending = 0u;
    status = nh_ppu11_reset(&core->ppu);
    if (status == NH_BUS_OK) status = nh_dma10_reset(&core->dma);
    if (status == NH_BUS_OK) status = nh_input15_cpu_reset(&core->input);
    if (status == NH_BUS_OK) status = nh_apu12_cpu_reset(&core->apu);
    return status;
}

static NHBusStop assemble(NHCore *core, const uint8_t *sram_file,
                          size_t sram_file_size, NHCorePowerOnProfile profile) {
    NHBusPorts ports;
    NHPinPort pins;
    NHSchedulerReceivers receivers;
    NHDeviceResetPort reset;
    NHBusStop status;
    memset(&ports, 0, sizeof(ports));
    memset(&pins, 0, sizeof(pins));
    memset(&receivers, 0, sizeof(receivers));
    memset(&core->cpu, 0, sizeof(core->cpu));
    core->cpu.p = (uint8_t)(NH_P_I | NH_P_M | NH_P_X);
    core->cpu.e = 1u;
    core->cpu.s = 0x01FFu;
    pins.opaque = core;
    pins.sample = pin_sample;
    pins.drive = pin_drive;
    receivers.opaque = core;
    receivers.smp_sync = terminal_smp;
    receivers.raster_event = terminal_raster;
    receivers.cpu_boundary = terminal_boundary;
    status = nh_machine09_construct_profile(&core->machine, &core->storage,
        &core->scheduler, &core->clock, &core->cpu, core->rom,
        NH_CORE_ROM_BYTES, ports, pins, receivers,
        (NHMemoryPowerOnProfile)profile);
    if (status != NH_BUS_OK) return status;
    if (sram_file != NULL) {
        if (sram_file_size != NH_SRAM_FILE_BYTES ||
            nh_sram_file_decode(&core->storage.bus.memory, sram_file,
                                sram_file_size) != NH_MEMORY_OK)
            return NH_BUS_MEMORY_FAILURE;
    } else if (sram_file_size != 0u) return NH_BUS_BAD_ARGUMENT;
    status = nh_ppu11_power_on(&core->ppu, &core->storage.bus,
        &core->scheduler, &core->storage.cpu_io.wrio);
    if (status == NH_BUS_OK &&
        profile >= NH_CORE_POWER_ON_DETERMINISTIC_ZERO_MACHINE_V2)
        status = nh_ppu11_apply_zero_storage_profile(&core->ppu);
    if (status == NH_BUS_OK) status = nh_ppu11_bind(&core->ppu);
    if (status == NH_BUS_OK) status = nh_apu12_power_on(&core->apu,
        &core->storage.bus, &core->scheduler);
    if (status == NH_BUS_OK &&
        profile == NH_CORE_POWER_ON_DETERMINISTIC_ZERO_MACHINE_ARAM_V3)
        status = nh_apu12_apply_zero_aram_profile(&core->apu);
    if (status == NH_BUS_OK) status = nh_sdsp16_power_on(&core->sdsp,
        &core->storage.bus, core->apu.aram, core->apu.aram_known);
    if (status == NH_BUS_OK) status = nh_apu12_bind_sdsp(&core->apu, &core->sdsp);
    if (status == NH_BUS_OK) status = nh_apu12_bind(&core->apu);
    if (status == NH_BUS_OK) status = nh_input15_power_on(&core->input,
        &core->storage.bus, &core->scheduler);
    if (status == NH_BUS_OK) status = nh_input15_bind(&core->input);
    if (status == NH_BUS_OK) status = nh_dma10_bind(&core->dma,
        &core->storage.bus, &core->scheduler);
    if (status != NH_BUS_OK) return status;
    reset.opaque = core;
    reset.apply = device_reset;
    return nh_machine09_reset_with_devices(&core->machine, reset,
                                           NH_RESET_STARTUP_MASTER_CLOCKS);
}

NHCore *nh_core_create(const uint8_t *rom, size_t rom_size,
                       const uint8_t *sram_file, size_t sram_file_size,
                       NHCoreStatus *out_status) {
    return nh_core_create_profile(rom, rom_size, sram_file, sram_file_size,
                                  NH_CORE_POWER_ON_STRICT_UNKNOWN, out_status);
}

NHCore *nh_core_create_profile(const uint8_t *rom, size_t rom_size,
                       const uint8_t *sram_file, size_t sram_file_size,
                       NHCorePowerOnProfile profile, NHCoreStatus *out_status) {
    NHCore *core;
    NHBusStop status = NH_BUS_BAD_ARGUMENT;
    if (out_status != NULL) *out_status = NH_CORE_BAD_ARGUMENT;
    if (rom == NULL || rom_size != NH_CORE_ROM_BYTES ||
        (profile != NH_CORE_POWER_ON_STRICT_UNKNOWN &&
         profile != NH_CORE_POWER_ON_DETERMINISTIC_ZERO_WRAM_V1 &&
         profile != NH_CORE_POWER_ON_DETERMINISTIC_ZERO_MACHINE_V2 &&
         profile != NH_CORE_POWER_ON_DETERMINISTIC_ZERO_MACHINE_ARAM_V3) ||
        (sram_file == NULL && sram_file_size != 0u)) return NULL;
    core = (NHCore *)calloc(1u, sizeof(*core));
    if (core == NULL) return NULL;
    core->rom = (uint8_t *)malloc(NH_CORE_ROM_BYTES);
    if (core->rom == NULL) {
        free(core);
        return NULL;
    }
    memcpy(core->rom, rom, NH_CORE_ROM_BYTES);
    status = assemble(core, sram_file, sram_file_size, profile);
    if (status != NH_BUS_OK) {
        nh_core_destroy(core);
        if (out_status != NULL) *out_status = public_status(status);
        return NULL;
    }
    if (out_status != NULL) *out_status = NH_CORE_OK;
    return core;
}

void nh_core_destroy(NHCore *core) {
    if (core == NULL) return;
    free(core->ppu.port_ui);
    core->ppu.port_ui = NULL;
    free(core->rom);
    core->rom = NULL;
    free(core);
}

NHCoreStatus nh_core_reset(NHCore *core) {
    NHDeviceResetPort reset;
    if (!assembled(core)) return NH_CORE_BAD_ARGUMENT;
    if (core->ppu.port_ui) memset(core->ppu.port_ui, 0, sizeof(*core->ppu.port_ui));
    reset.opaque = core;
    reset.apply = device_reset;
    return public_status(nh_machine09_reset_with_devices(&core->machine, reset,
                         NH_RESET_STARTUP_MASTER_CLOCKS));
}

NHCoreStatus nh_core_set_standard_pad(NHCore *core, unsigned port,
                                      uint16_t state) {
    return !assembled(core) ? NH_CORE_BAD_ARGUMENT :
        public_status(nh_input15_set_standard_pad(&core->input, port, state));
}

NHCoreStatus nh_core_set_snes_mouse(NHCore *core, unsigned port,
                                    uint8_t buttons, int16_t delta_x,
                                    int16_t delta_y) {
    return !assembled(core) ? NH_CORE_BAD_ARGUMENT :
        public_status(nh_input15_set_snes_mouse(&core->input, port, buttons,
                                                delta_x, delta_y));
}

static NHCoreRunResult run_to_next_frame(NHCore *core, uint64_t step_limit,
    uint64_t *steps, NHCoreAudioProgressCallback progress, void *opaque) {
    uint64_t start_sequence, count = 0u;
    if (steps != NULL) *steps = 0u;
    if (!assembled(core) || step_limit == 0u) return NH_CORE_RUN_BAD_ARGUMENT;
    sea_camera_seed(core);
    chart_source_observe(core);
    start_sequence = core->ppu.published_sequence;
    while (count < step_limit) {
        NHScpuExecResult result;
        if (core->cpu.waiting != 0u || core->cpu.stopped != 0u) {
            uint8_t resumed = 0u;
            if (nh_machine09_advance_terminal(&core->machine,
                    NH_NTSC_NORMAL_LINE_CLOCKS, &resumed) != NH_BUS_OK)
                return NH_CORE_RUN_STOPPED;
            ++count;
            if (resumed == 0u && core->cpu.stopped != 0u)
                return NH_CORE_RUN_STOPPED;
        } else {
            /* Observational presentation correspondence only. The selected
             * static instruction still executes once through its normal bus. */
            if (core->ppu.port_ui && core->cpu.pbr==0xC5u && core->cpu.pc==0x3D3Du)
                chart_source_observe(core);
            if (core->ppu.port_ui && core->cpu.pbr == 0xC2u &&
                (core->cpu.pc == 0x0A8Du || core->cpu.pc == 0x0AB7u ||
                 core->cpu.pc == 0x0C0Fu || core->cpu.pc == 0x0EC9u))
                sea_camera_observe(core);
            if (core->ppu.port_ui && core->cpu.pbr == 0xC2u &&
                (core->cpu.pc == 0x1658u || core->cpu.pc == 0x154Cu))
                sea_fleet_observe(core);
            if (core->ppu.port_ui && core->cpu.pbr == 0xC1u && core->cpu.pc == 0x4814u)
                sea_fleet_observe(core);
            if (core->ppu.port_ui && core->cpu.pbr == 0xC1u && core->cpu.pc == 0x95C4u)
                sea_marker_retire_observe(core);
            if (core->ppu.port_ui &&
                ((core->cpu.pbr == 0xC9u &&
                  (core->cpu.pc == 0x606Cu || core->cpu.pc == 0x625Eu ||
                   core->cpu.pc == 0x62BBu || core->cpu.pc == 0x5FDAu ||
                   core->cpu.pc == 0x6154u || core->cpu.pc == 0x61C9u)) ||
                 (core->cpu.pbr == 0xC2u &&
                  (core->cpu.pc == 0x0ED0u || core->cpu.pc == 0x0F12u ||
                   core->cpu.pc == 0x0F1Eu))))
                sea_discovery_observe(core);
            result = nh_machine09_step(&core->machine);
            ++count;
            if (result != NH_SCPU_EXECUTED) return NH_CORE_RUN_STOPPED;
        }
        /* Jungle Strike's PCM-ready handoff: transfer an already-produced
           batch during execution. No guest timing/state policy is delegated. */
        if (progress != NULL && nh_sdsp16_pcm_available(&core->sdsp) >= 128u)
            progress(core, opaque);
        if (core->ppu.published_sequence != start_sequence) {
            /* A source free and its newly consumed OAM can occur during this
             * frame. Qualify host-only retirement metadata against that actual
             * published machine, not one frame late at the next entry. */
            sea_retirement_seed(core);
            /* A restore can begin inside an unqualified helper yet reach an
             * already proved source boundary during this very field. Recover
             * against that actual published machine before presenting it,
             * rather than leaving one visible native field until next entry.
             * The seed still requires its full source/stack/native guards. */
            if (core->ppu.port_ui && !core->ppu.port_ui->sea_camera_valid)
                sea_camera_seed(core);
            if (core->ppu.port_ui && core->cpu.pbr == 0xC2u &&
                (core->cpu.pc == 0x0F12u || core->cpu.pc == 0x0F1Eu))
                sea_discovery_observe(core);
            if (steps != NULL) *steps = count;
            return NH_CORE_RUN_FRAME_READY;
        }
    }
    if (steps != NULL) *steps = count;
    return NH_CORE_RUN_STEP_LIMIT;
}

NHCoreRunResult nh_core_run_to_next_frame(NHCore *core, uint64_t step_limit,
                                          uint64_t *steps) {
    return run_to_next_frame(core, step_limit, steps, NULL, NULL);
}

NHCoreRunResult nh_core_run_to_next_frame_streamed(
    NHCore *core, uint64_t step_limit, uint64_t *steps,
    NHCoreAudioProgressCallback progress, void *opaque) {
    return run_to_next_frame(core, step_limit, steps, progress, opaque);
}

int nh_core_read_published_frame(const NHCore *core, uint16_t *pixels,
                                 uint8_t *known, uint32_t capacity,
                                 uint16_t *width, uint16_t *height,
                                 uint64_t *sequence) {
    return assembled(core) && nh_ppu14_read_published_frame(&core->ppu, pixels,
        known, capacity, width, height, sequence);
}

size_t nh_core_pcm_available(const NHCore *core) {
    return assembled(core) ? nh_sdsp16_pcm_available(&core->sdsp) : 0u;
}

int nh_core_port_terrain_info(const NHCore *core, NHCorePortTerrainInfo *info) {
    const NHPPU11 *p;
    unsigned n;
    if (!assembled(core) || info == NULL) return 0;
    p = &core->ppu;
    if (!p->frame_ready || p->forced_blank || p->brightness == 0u ||
        p->interlace || p->overscan || p->published_height != 224u ||
        p->registers[5].known_mask != 255u || p->registers[5].value != 0x29u ||
        p->registers[8].known_mask != 255u || p->registers[8].value != 0x58u ||
        p->registers[11].known_mask != 255u || p->registers[11].value != 0x22u ||
        p->registers[0x2C].known_mask != 255u || !(p->registers[0x2C].value & 2u) ||
        p->bg_hofs[1].known_mask != 0x3FFu || p->bg_vofs[1].known_mask != 0x3FFu ||
        (p->bg_hofs[1].value >= 512u && p->bg_hofs[1].value < 1016u) ||
        p->bg_vofs[1].value >= 512u) return 0;
    for (n = 0u; n < 1024u; ++n) {
        NHMemoryByte map;
        unsigned tile, address = 0xB000u + n * 2u;
        if (nh_memory_peek(&core->storage.bus.memory, 0x7EA6A7u + n, &map) !=
            NH_MEMORY_OK || !map.known) return 0;
        /* Exact source-derived C4:2D32..2E0A tile/palette conversion. */
        tile = (((map.value & 7u) << 1u) + ((map.value >> 3u) << 5u)) | 0x800u;
        if (map.value >= 0x50u) tile += 0x400u;
        else if (map.value < 0x10u) tile += 0xC00u;
        /* C4:2DB2 rejects <30; equality calls C1:FDC1 at2DC0/2DD4/
         * 2DE8/2DFC SKIP the addition for3E/3F/48/49, not include them. */
        else if (map.value >= 0x30u && map.value != 0x3Eu && map.value != 0x3Fu &&
                 map.value != 0x48u && map.value != 0x49u) tile += 0x800u;
        if (p->vram[address].known_mask != 255u ||
            p->vram[address + 1u].known_mask != 255u ||
            (unsigned)(p->vram[address].value |
                       ((unsigned)p->vram[address + 1u].value << 8u)) != tile) return 0;
    }
    info->width = 512u; info->height = 288u;
    info->world_width = 512u; info->world_height = 512u;
    info->origin_x = 0u;
    n = p->bg_vofs[1].value > 32u ? p->bg_vofs[1].value - 32u : 0u;
    info->origin_y = (uint16_t)(n > 224u ? 224u : n);
    info->native_scroll_x = (int16_t)(p->bg_hofs[1].value < 512u ?
        (int)p->bg_hofs[1].value : (int)p->bg_hofs[1].value - 1024);
    info->native_scroll_y = (int16_t)p->bg_vofs[1].value;
    return 1;
}

int nh_core_read_port_terrain(const NHCore *core, uint16_t *pixels,
                              uint32_t capacity, NHCorePortTerrainInfo *info) {
    NHCorePortTerrainInfo scene;
    if (!nh_core_port_terrain_info(core, &scene) ||
        !nh_ppu14_read_port_terrain(&core->ppu, scene.origin_y, pixels, capacity)) return 0;
    if (info != NULL) *info = scene;
    return 1;
}

static int port_peek(const NHCore *core, uint32_t address, uint8_t *value) {
    NHMemoryByte byte;
    if (nh_memory_peek(&core->storage.bus.memory, address, &byte) != NH_MEMORY_OK ||
        !byte.known) return 0;
    *value = byte.value;
    return 1;
}

static int port_word(const NHCore *core, uint32_t address, unsigned *value) {
    uint8_t lo, hi;
    if (!port_peek(core, address, &lo) || !port_peek(core, address + 1u, &hi)) return 0;
    *value = lo | ((unsigned)hi << 8u);
    return 1;
}

static int port_unwrap(int raw, int hint, int period) {
    while (raw - hint > period / 2) raw -= period;
    while (hint - raw > period / 2) raw += period;
    return raw;
}

/* C2:160F sets descriptor+4=3, calls command09 at165B, THEN frees both
 * maps at1679/1696. The old consumed OAM may still be visible. Witness its
 * identity BEFORE that free. A new allocation at154C changes the source
 * maps before the old consumed OAM retires; witness that exact tail too.
 * No CPU, WRAM, PPU or serialized state is modified. */
static void sea_fleet_observe(NHCore *core) {
    NHPortUiCapture14 *ui = core->ppu.port_ui;
    unsigned slot, fleet, word, model;
    uint8_t mode, reverse, forward, flags;
    if (!ui || core->cpu.e || (core->cpu.p & NH_P_X) || core->cpu.dbr != 0x7Eu ||
        (core->cpu.d != 0u && core->cpu.d != 0x100u)) return;
    if (core->cpu.pbr == 0xC1u && core->cpu.pc == 0x4814u) {
        /* C1:4814..4886 initializes all70 EA17 identities and16 EA5D slots.
         * This is the actual fleet lifetime reset, unlike C2:0A8D which also
         * rebuilds an ordinary scrolling tile cache without resetting fleets. */
        if (!(core->cpu.p & NH_P_M)) {
            memset(ui->sea_retired_valid, 0, sizeof(ui->sea_retired_valid));
            ui->sea_camera_valid = 0u;
            ui->sea_camera_rebuilding = 0u;
            ui->sea_discovery_rows = ui->sea_discovery_refresh = 0u;
            ui->sea_marker_retired_valid = 0u;
        }
        return;
    }
    if (!port_peek(core, 0x7E2016u, &mode) || mode != 0xFFu) return;
    if (core->cpu.pc == 0x154Cu) {
        if ((core->cpu.p & NH_P_M) && port_word(core, core->cpu.s + 5u, &slot) &&
            slot >= 2u && slot < 16u && ui->sea_retired_valid[slot]) {
            unsigned index = 112u + slot, n, pair;
            if (nh_ppu14_object_native_hidden(&core->ppu, index) != 0) {
                ui->sea_retired_valid[slot] = 0u;
                return;
            }
            for (n = 0u; n < 4u; ++n) {
                if (core->ppu.oam[index * 4u + n].known_mask != 255u) {
                    ui->sea_retired_valid[slot] = 0u; return;
                }
                ui->sea_retired_pose[slot][n] = core->ppu.oam[index * 4u + n].value;
            }
            if (core->ppu.oam[512u + index / 4u].known_mask != 255u) {
                ui->sea_retired_valid[slot] = 0u; return;
            }
            pair = (core->ppu.oam[512u + index / 4u].value >> ((index & 3u) * 2u)) & 3u;
            word = ui->sea_retired_pose[slot][2] | ((unsigned)ui->sea_retired_pose[slot][3] << 8u);
            if (!(pair & 2u) || !sea_model_word(word, 0x2A00u, ui->sea_retired_model[slot])) {
                ui->sea_retired_valid[slot] = 0u; return;
            }
            ui->sea_retired_pose[slot][4] = (uint8_t)pair;
            ui->sea_retired_reallocated[slot] = 1u;
        }
        return;
    }
    if ((core->cpu.p & NH_P_M) ||
        !port_word(core, core->cpu.s + 1u, &slot) || slot < 2u || slot >= 16u) return;
    ui->sea_retired_valid[slot] = 0u;
    ui->sea_retired_reallocated[slot] = 0u;
    if (!port_word(core, core->cpu.s + 6u, &fleet) || fleet >= 70u ||
        !port_peek(core, 0x7EEA5Du + slot, &reverse) || reverse != fleet ||
        !port_peek(core, 0x7EEA17u + fleet, &forward) || forward != slot ||
        !port_peek(core, 0x7EE937u + slot * 6u + 4u, &flags) || flags != 3u ||
        !port_word(core, 0x7EE937u + slot * 6u + 2u, &word)) return;
    for (model = 0u; model < 4u && !sea_model_word(word, 0x2A00u, model); ++model) {}
    if (model == 4u) return;
    ui->sea_retired_fleet[slot] = (uint8_t)fleet;
    ui->sea_retired_model[slot] = (uint8_t)model;
    ui->sea_retired_valid[slot] = 1u;
}

int nh_core_observe_sea_weather(const NHCore *core, uint8_t *weather, uint8_t *mosaic) {
    uint8_t mode, flags;
    if (!assembled(core) || !weather || !mosaic ||
        !port_peek(core, 0x7E2016u, &mode) || mode != 255u ||
        !port_peek(core, 0x7E201Bu, &flags) ||
        core->ppu.registers[6].known_mask != 255u) return 0;
    *weather = flags; *mosaic = core->ppu.registers[6].value;
    return 1;
}

static void sea_camera_anchor(NHCore *core, unsigned wx, unsigned wy,
                               unsigned phase_x, unsigned phase_y) {
    NHPortUiCapture14 *ui = core->ppu.port_ui;
    if (!ui) return;
    if (wx >= 2160u || wy >= 1080u) { ui->sea_camera_valid = 0u; return; }
    ui->sea_anchor_x = (int32_t)wx * 8;
    ui->sea_anchor_y = (int32_t)wy * 8 + 8; /* C2:0A8D's initial vertical phase. */
    ui->sea_phase_x = (uint16_t)phase_x; ui->sea_phase_y = (uint16_t)phase_y;
    ui->sea_camera_valid = 1u;
}

/* C2:0AB8 saves old scroll, starts command45, THEN updates ring/target phase,
 * and acknowledges the cached global rectangle only at0EBD/0EC3. Observing
 * these real source boundaries avoids pairing a new ring with an old global
 * cache coordinate. Nothing here writes RAM, clocks, registers or CPU state. */
static void sea_camera_observe(NHCore *core) {
    NHPortUiCapture14 *ui = core->ppu.port_ui;
    unsigned wx, wy;
    uint8_t mode, phase_x, phase_y;
    /* C0:8068..8071 establishes C-call DBR7E/D0100; the native engine
     * also uses D0000. All observed camera addresses below are explicit long
     * globals, not offsets into either caller's scratch direct page. */
    if (!ui || core->cpu.e || (core->cpu.p & (NH_P_M | NH_P_X)) ||
        (core->cpu.d != 0u && core->cpu.d != 0x0100u) || core->cpu.dbr != 0x7Eu) return;
    if (!port_peek(core, 0x7E2016u, &mode) || mode != 0xFFu) {
        ui->sea_camera_valid = ui->sea_camera_rebuilding = 0u; return;
    }
    /*0A8D resets WRAM rings before04CB builds its replacement in DFC3.
     * The OLD consumed VRAM world remains live during that staging work.
     * Keep its proved correspondence, rather than discarding it22 fields
     * before the source requests its actual scroll/upload. */
    if (core->cpu.pc == 0x0A8Du) {
        ui->sea_camera_rebuilding = ui->sea_camera_valid;
        return;
    }
    if (core->cpu.pc == 0x0AB7u) {
        unsigned ring_x, ring_y;
        ui->sea_camera_rebuilding = 0u;
        /*04CB has returned after command06's0B81 transfer-completion wait.
         * The full map's source arguments are still atS+4/+6; acknowledgments
         * A259/25B are deliberately later. Join the NEW map to those actual
         * arguments and reset phases, never to the still-old acknowledgment. */
        if (!port_word(core, core->cpu.s + 4u, &wx) ||
            !port_word(core, core->cpu.s + 6u, &wy) ||
            !port_peek(core, 0x7EA257u, &phase_x) || phase_x != 0u ||
            !port_peek(core, 0x7EA258u, &phase_y) || phase_y != 8u ||
            !port_word(core, 0x7EA25Du, &ring_x) || ring_x != 0u ||
            !port_word(core, 0x7EA25Fu, &ring_y) || ring_y != 0u) {
            ui->sea_camera_valid = 0u; return;
        }
        sea_camera_anchor(core, wx, wy, phase_x, phase_y);
        return;
    }
    if (!port_word(core, 0x7EA259u, &wx) || !port_word(core, 0x7EA25Bu, &wy) ||
        !port_peek(core, 0x7EA257u, &phase_x) || !port_peek(core, 0x7EA258u, &phase_y)) {
        ui->sea_camera_valid = 0u; return;
    }
    /*0C0F: old rectangle/old phase;0EC9: acknowledged new rectangle/target
     * phase. Both represent the same world/VRAM relationship during the
     * native scroll controller's interpolation, including a delayed PPU copy. */
    sea_camera_anchor(core, wx, wy, phase_x, phase_y);
}

static void sea_retirement_seed(NHCore *core) {
    NHPortUiCapture14 *ui = core->ppu.port_ui;
    uint8_t mode;
    if (!ui || !port_peek(core, 0x7E2016u, &mode) || mode != 0xFFu) return;
    /* A restored machine can contain C2:160F's completed clear descriptor
     * and still-visible consumed OAM, but no optional host identity history.
     * Qualify that native tail from the actual source clear contract, without
     * inventing its old fleet identity or extending its pose into margins. */
    {
        unsigned slot;
        for (slot = 2u; slot < 16u; ++slot) {
            unsigned index = 112u + slot, shadow, word, model, n;
            uint8_t flags, reverse, forward;
            /* A valid bit is not proof that the old identity/model still
             * qualifies. Preserve any qualifying identified/reallocated tail;
             * otherwise allow the same source-clear reconstruction used after
             * restore. Failed reconstruction still leaves the normal guards in
             * force; anonymous tails never acquire an extended world pose. */
            if (ui->sea_retired_valid[slot] &&
                sea_retired_actor(core, slot, NULL, NULL, NULL)) continue;
            if (!port_peek(core, 0x7EEA5Du + slot, &reverse) || reverse != 255u ||
                !port_peek(core, 0x7EE937u + slot * 6u + 4u, &flags) || flags != 3u ||
                !port_word(core, 0x7EE937u + slot * 6u + 2u, &shadow) ||
                nh_ppu14_object_native_hidden(&core->ppu, index) != 0) continue;
            for (n = 0u; n < 4u; ++n)
                if (core->ppu.oam[index * 4u + n].known_mask != 255u) break;
            if (n != 4u || core->ppu.oam[512u + index / 4u].known_mask != 255u ||
                !((core->ppu.oam[512u + index / 4u].value >> ((index & 3u) * 2u)) & 2u)) continue;
            word = core->ppu.oam[index * 4u + 2u].value |
                ((unsigned)core->ppu.oam[index * 4u + 3u].value << 8u);
            if ((word & ~2u) != shadow) continue;
            for (model = 0u; model < 4u && !sea_model_word(word, 0x2A00u, model); ++model) {}
            if (model == 4u) continue;
            for (n = 0u; n < 70u; ++n)
                if (!port_peek(core, 0x7EEA17u + n, &forward) || forward == slot) break;
            if (n != 70u) continue;
            ui->sea_retired_fleet[slot] = 255u; /* explicitly unknown, not guessed */
            ui->sea_retired_model[slot] = (uint8_t)model;
            ui->sea_retired_reallocated[slot] = 0u;
            ui->sea_retired_valid[slot] = 1u;
        }
    }
}

/* Recover an OLD consumed map during C2:04CB's full-map RAM construction.
 * The stack offsets follow its six-byte FF38 save and fourteen-byte locals,
 * NOT a scan for coincidentally matching return bytes. Only source positions
 * with a proved stack shape qualify; other helper interiors remain fail-closed.
 * No guest state, instruction execution or optional host history is changed. */
static int sea_camera_seed_full_builder(NHCore *core, unsigned wx, unsigned wy,
                                        unsigned target_x, unsigned target_y) {
    NHPortUiCapture14 *ui = core->ppu.port_ui;
    unsigned s = core->cpu.s, pc = core->cpu.pc, bank = core->cpu.pbr;
    unsigned frame, value, old_x, old_y, cursor, cursor_bank;
    uint8_t status = core->cpu.p, byte;
    if (!ui || core->cpu.e || core->cpu.dbr != 0x7Eu ||
        (core->cpu.d != 0u && core->cpu.d != 0x0100u) ||
        target_x >= 2160u || target_y >= 1080u ||
        s > 0x1F80u) return 0;
    /* Exact native NMI entry, before the handler pushes any software saves.
     * Hardware has pushed PBR/PCH/PCL/P; unwind only that defined four-byte
     * frame. This also covers a frame-boundary snapshot of the builder. */
    if (bank == 0u && pc == 0x8490u) {
        if (!port_peek(core, s + 1u, &status) ||
            !port_word(core, s + 2u, &pc) ||
            !port_peek(core, s + 4u, &byte)) return 0;
        bank = byte; s += 4u;
    }
    if (status & (NH_P_M | NH_P_X)) return 0;
    if (bank == 0xC1u &&
        (pc == 0xFCA7u || pc == 0xFCA8u || pc == 0xFCAAu ||
         pc == 0xFCACu || pc == 0xFCAEu || pc == 0xFCB0u ||
         pc == 0xFCB2u || pc == 0xFCB4u)) {
        /* 0453 PHA;046F/0479 JSLFCA7 is stack-neutral 32-bit addition.
         * The exact two returns and the existing 057E->0453 frame prove
         * this is map-RAM construction, never a generic arithmetic caller. */
        if (!port_word(core, s + 1u, &value) ||
            (value != 0x0472u && value != 0x047Cu) ||
            !port_peek(core, s + 3u, &byte) || byte != 0xC2u) return 0;
        frame = s + 10u;
        if (!port_word(core, frame - 4u, &value) || value != 0x0581u ||
            !port_peek(core, frame - 2u, &byte) || byte != 0xC2u) return 0;
    } else if (bank == 0xC1u &&
               (pc == 0xFEAEu || pc == 0xFEB2u || pc == 0xFEB4u ||
                pc == 0xFEB5u || pc == 0xFEB7u || pc == 0xFEC2u ||
                pc == 0xFEC5u || pc == 0xFEC6u || pc == 0xFEC8u ||
                pc == 0xFECAu)) {
        /* 055E JSLFEAE compares the RAM-build column index with32.
         * FEAE JSLFEC2 adds exactly three bytes until its RTL; neither
         * helper writes camera/PPU state. NMI after RTL saves FEB2, not
         * the just-completed FECA instruction-entry diagnostic PC. */
        unsigned nested = pc >= 0xFEC2u;
        if (nested &&
            (!port_word(core, s + 1u, &value) || value != 0xFEB1u ||
             !port_peek(core, s + 3u, &byte) || byte != 0xC1u)) return 0;
        frame = s + (nested ? 6u : 3u);
        if (!port_word(core, frame - 2u, &value) || value != 0x0561u ||
            !port_peek(core, frame, &byte) || byte != 0xC2u) return 0;
    } else if (bank != 0xC2u) return 0;
    else if ((pc >= 0x0512u && pc <= 0x0540u) ||
        (pc >= 0x0547u && pc <= 0x0568u) ||
        (pc >= 0x0577u && pc <= 0x057Du) ||
        (pc >= 0x0583u && pc <= 0x05AFu)) {
        frame = s; /* no outstanding argument pushes in these intervals */
    } else if (pc >= 0x0453u && pc <= 0x0499u) {
        /* 057B PHA;057E JSL0453;0453 PHA..0498 PLA;0499 RTL. */
        frame = s + ((pc == 0x0453u || pc == 0x0499u) ? 5u : 7u);
        if (!port_word(core, frame - 4u, &value) || value != 0x0581u ||
            !port_peek(core, frame - 2u, &byte) || byte != 0xC2u) return 0;
    } else return 0;
    /* Full builder called ONLY by the observed 0A8D large-delta path here:
     * 0AB1 JSL04CB, and caller0B24 JSL0A8D. Both pending coordinates must
     * equal their actual arguments; neither call has acknowledged them yet. */
    if (frame > 0x1FDCu ||
        !port_word(core, frame + 21u, &value) || value != 0x0AB4u ||
        !port_peek(core, frame + 23u, &byte) || byte != 0xC2u ||
        !port_word(core, frame + 24u, &value) || value != target_x ||
        !port_word(core, frame + 26u, &value) || value != target_y ||
        !port_word(core, frame + 28u, &value) || value != 0x0B27u ||
        !port_peek(core, frame + 30u, &byte) || byte != 0xC2u ||
        !port_word(core, frame + 31u, &value) || value != target_x ||
        !port_word(core, frame + 33u, &value) || value != target_y ||
        !port_word(core, core->cpu.d + 0x24u, &cursor) ||
        !port_word(core, core->cpu.d + 0x26u, &cursor_bank) || cursor_bank != 0x7Eu ||
        cursor < 0xDFC3u || cursor > 0xE743u || ((cursor - 0xDFC3u) & 1u) ||
        !port_word(core, 0x7E0F6Fu, &old_x) || old_x > 255u ||
        !port_word(core, 0x7E0F71u, &old_y) || old_y > 255u ||
        (old_x & 7u) || (old_y & 7u)) return 0;
    /* The inactive command45 controller still retains the OLD completed
     * scroll. 0A8D reset the replacement's WRAM rings, not this controller or
     * the consumed VRAM. Actual PPU scroll remains the renderer's pixel phase. */
    sea_camera_anchor(core, wx, wy, old_x, old_y);
    ui->sea_camera_rebuilding = ui->sea_camera_valid;
    return ui->sea_camera_valid != 0u;
}

/* C1:2A7C waits for the PREVIOUS fleet/scroll update before its camera call
 * at2A8B. Pending23EE/F0 can already name the NEXT diagonal destination.
 * At command55 mode2's stack-neutral read, the prior acknowledged rectangle
 * still owns the controller's completed destination phase. Recover only this
 * exact call/save frame, not an arbitrary PC or an ocean-image match. */
static int sea_camera_seed_fleet_wait(NHCore *core, unsigned wx, unsigned wy,
                                     unsigned phase_x, unsigned phase_y,
                                     unsigned busy) {
    unsigned s = core->cpu.s, pc = core->cpu.pc, bank = core->cpu.pbr;
    unsigned popped = 0u, value, n, cx, cy, sx, sy;
    unsigned preparing = 0u, expected_d = 0u, expected_dbr = 0u, expected_width = 0u;
    uint8_t byte, status = core->cpu.p;
    if (!core->ppu.port_ui || core->cpu.e ||
        s > 0x1FDCu || wx >= 2160u || wy >= 1080u || busy > 8u) return 0;
    /* Recover only the exact native NMI-entry frame, before software saves. */
    if (bank == 0u && pc == 0x8490u) {
        if (!port_peek(core, s + 1u, &status) ||
            !port_word(core, s + 2u, &pc) ||
            !port_peek(core, s + 4u, &byte)) return 0;
        bank = byte; s += 4u;
    }
    if (bank == 0xC2u) {
        unsigned arguments;
        if ((status & (NH_P_M | NH_P_X)) || core->cpu.d != 0x0100u ||
            core->cpu.dbr != 0x7Eu) return 0;
        /* C2:1555's own source instructions: exact outstanding argument
         * bytes, including both command55 calls and their cleanup. The
         * mode0 branch is excluded by the actual caller's mode1 below. */
        switch (pc) {
            case 0x1555u: case 0x1557u: case 0x1559u:
            case 0x1578u: case 0x157Au: case 0x157Cu: case 0x157Eu:
            case 0x157Fu: case 0x1582u: case 0x1585u: case 0x1587u:
            case 0x158Au: case 0x158Du: case 0x158Fu: case 0x1591u:
            case 0x15B4u: case 0x160Eu: arguments = 0u; break;
            case 0x155Cu: case 0x1592u: arguments = 2u; break;
            case 0x155Fu: case 0x1594u: case 0x1598u: arguments = 4u; break;
            case 0x1562u: case 0x1599u: case 0x159Du: arguments = 6u; break;
            case 0x1565u: case 0x159Eu: arguments = 8u; break;
            case 0x1568u: case 0x15A1u: arguments = 10u; break;
            case 0x156Bu: case 0x15A4u: arguments = 12u; break;
            case 0x156Eu: case 0x1572u: case 0x1573u: case 0x1574u:
            case 0x1577u: case 0x15A7u: arguments = 14u; break;
            case 0x15AAu: case 0x15AEu: case 0x15AFu:
            case 0x15B0u: case 0x15B3u: arguments = 16u; break;
            default: return 0;
        }
        s += arguments;
        if (s > 0x1FFAu || !port_word(core, s + 1u, &value) || value != 0x2A7Fu ||
            !port_peek(core, s + 3u, &byte) || byte != 0xC1u ||
            !port_word(core, s + 4u, &value) || value != 1u) return 0;
        goto qualify_phase;
    }
    if (bank != 0xC0u) return 0;
    /* Entry/prologue SP positions share the same eventual callee frame as
     * the return tail. Only actually pushed saves may be read. */
    switch (pc) {
        case 0x8000u: case 0x95F7u: preparing = 1u; popped = 12u; break;
        case 0x95F8u: case 0x95FAu: preparing = 1u; popped = 11u; break;
        case 0x95FBu: preparing = 1u; popped = 9u; break;
        case 0x95FCu: preparing = 1u; popped = 7u; break;
        case 0x95FDu: preparing = 1u; popped = 5u; break;
        case 0x95FEu: preparing = 1u; popped = 3u; break;
        case 0x95FFu: preparing = 1u; popped = 2u; break;
        case 0x9601u: case 0x9603u: preparing = 1u; popped = 2u; expected_width = NH_P_M; break;
        case 0x9604u: preparing = 1u; popped = 1u; expected_width = NH_P_M; break;
        case 0x9605u: preparing = 1u; popped = 2u; expected_width = NH_P_M; break;
        case 0x9607u: case 0x960Au: case 0x960Bu: case 0x960Eu:
        case 0x9610u: case 0x9611u: case 0x9612u: case 0x9615u:
        case 0x9616u: case 0x9619u: case 0x961Cu: case 0x961Fu:
        case 0x9622u: case 0x9625u: case 0x9628u: case 0x962Bu:
        case 0x962Eu: case 0x962Fu: case 0x9630u:
            preparing = 1u; popped = 2u; break;
        default: break;
    }
    if (preparing) {
        expected_d = pc == 0x8000u || pc <= 0x960Au ? 0x0100u : 0u;
        expected_dbr = pc == 0x8000u || pc <= 0x9604u ? 0x7Eu : 0u;
    }
    if ((status & (NH_P_M | NH_P_X)) != expected_width) return 0;
    /* Command55 mode2 only reads0F7C. Its return tail copies the result and
     * restores saved registers; it cannot commit the next camera at2A8B.
     * Reconstruct the SAME original callee frame from each exact pop state,
     * not an arbitrary dispatcher range or a search for return bytes. */
    if (!preparing) switch (pc) {
        case 0x9633u: case 0x9635u: case 0x9637u: case 0x963Au:
        case 0x963Cu: case 0x963Fu: popped = 2u; break;
        case 0x9640u: popped = 3u; break; /* PLB */
        case 0x9641u: popped = 5u; break; /* PLY */
        case 0x9642u: popped = 7u; break; /* PLX */
        case 0x9643u: popped = 9u; break; /* PLA */
        case 0x9644u: popped = 11u; break; /* PLD */
        case 0x9645u: popped = 12u; break; /* PLP */
        default: if (pc < 0xBBF7u || pc > 0xBC01u) return 0;
    }
    if (!preparing) {
        expected_dbr = popped >= 3u ? 0x7Eu : 0u;
        expected_d = popped >= 11u ? 0x0100u : 0u;
    }
    if (s < popped || core->cpu.dbr != expected_dbr || core->cpu.d != expected_d) return 0;
    s -= popped;
    if (s > 0x1FDCu) return 0;
    /* Never inspect consumed stack bytes: an NMI may have overwritten them.
     * Validate live saves until their pop, then the restored register above. */
    if ((!popped && (!port_word(core, s + 1u, &value) || value != 0x9632u)) ||
        (popped < 3u && (!port_peek(core, s + 3u, &byte) || byte != 0x7Eu)) ||
        (popped < 11u && (!port_word(core, s + 10u, &value) || value != 0x0100u)) ||
        (popped < 12u && (!port_peek(core, s + 12u, &byte) || (byte & (NH_P_M | NH_P_X)))) ||
        !port_word(core, s + 13u, &value) ||
        !port_peek(core, s + 15u, &byte) || byte != 0xC2u) return 0;
    if (value == 0x1571u) {
        if (!port_word(core, s + 16u, &value) || value != 0x55u ||
            !port_word(core, s + 18u, &value) || value != 2u ||
            !port_word(core, s + 30u, &value) || value != 0x2A7Fu ||
            !port_peek(core, s + 32u, &byte) || byte != 0xC1u ||
            !port_word(core, s + 33u, &value) || value != 1u ||
            ((!preparing || pc >= 0x9628u) && pc != 0x8000u &&
             (!port_word(core, 0x54u, &value) || value != 2u))) return 0;
        for (n = 20u; n < 30u; n += 2u)
            if (!port_word(core, s + n, &value) || value) return 0;
    } else if (value == 0x15ADu && (preparing || popped)) {
        unsigned period, duration;
        if (!port_word(core, s + 16u, &value) || value != 0x55u ||
            !port_word(core, s + 18u, &value) || value != 1u ||
            !port_word(core, s + 20u, &value) || value != 0x71u ||
            !port_word(core, s + 22u, &value) || value != 0x0Fu ||
            !port_word(core, 0x7EA391u, &period) ||
            !port_word(core, s + 24u, &value) || value != period ||
            !port_word(core, 0x7EA393u, &duration) ||
            !port_word(core, s + 26u, &value) || value != duration ||
            !port_word(core, s + 28u, &value) || value != 0xE9F9u ||
            !port_word(core, s + 30u, &value) || value != 0x7Eu ||
            !port_word(core, s + 32u, &value) || value != 0x2A7Fu ||
            !port_peek(core, s + 34u, &byte) || byte != 0xC1u ||
            !port_word(core, s + 35u, &value) || value != 1u ||
            ((!preparing || pc >= 0x9628u) && pc != 0x8000u &&
             (!port_word(core, 0x54u, &value) || value != 1u))) return 0;
    } else return 0;
qualify_phase:
    if (!port_word(core, 0x7E0F6Fu, &cx) || !port_word(core, 0x7E0F71u, &cy) ||
        !port_word(core, 0x7E0F73u, &sx) || !port_word(core, 0x7E0F75u, &sy)) return 0;
    /* Modular16-bit arithmetic is the controller's actual source arithmetic;
     * only the low8 bits are consumed by this BG2 scroll phase. */
    if (((cx + busy * sx) & 255u) != phase_x ||
        ((cy + busy * sy) & 255u) != phase_y) return 0;
    sea_camera_anchor(core, wx, wy, phase_x, phase_y);
    return core->ppu.port_ui->sea_camera_valid != 0u;
}

/* C4:77D0's18-byte save/local frame, called at7BFA by the74-byte
 * cache-staging frame7A7B, itself called at7CFE by7CF1. These witnessed
 * stack-neutral positions precede any camera/VRAM commit; WRAM asset refresh
 * is not a new consumed map. Recover only their exact source call chain. */
/* Exact instruction entries in77D0's stack-neutral RAM-copy loops. These
 * entries never publish VRAM or acknowledge a camera. SEP/REP20 changes the
 * byte-copy accumulator width, not its local-frame ownership. */
static int sea_asset_copy_pc(unsigned pc, uint8_t status) {
    static const uint16_t word_pc[] = {
        0x788Bu,0x788Eu,0x7890u,0x7893u,0x7895u,0x7897u,0x7899u,0x789Du,0x789Fu,0x78A1u,
        0x78A4u,0x78A7u,0x78A9u,0x78ACu,0x78AEu,0x78B0u,0x78B2u,0x78B6u,0x78B8u,0x78BAu,
        0x78BDu,0x78BFu,0x78C1u,0x78C3u,0x78C6u,0x78C8u,0x78C9u,0x78CBu,0x78CEu,0x78D0u,
        0x78D2u,0x78D5u,0x78D7u,0x78D9u,0x78DCu,0x78DEu,0x78E1u,0x78E3u,0x78E5u,0x78E7u,
        0x78EBu,0x78EDu,0x78EFu,0x78F2u,0x78F6u,0x78F8u,0x78FCu,0x78FEu,0x7902u,0x7904u,
        0x7908u,0x790Bu,0x790Du,0x7911u,0x7913u,0x7914u,0x7915u,0x7917u,0x7919u,0x791Bu,
        0x791Du,0x7921u,0x7923u,0x7925u,0x7927u,0x7929u,0x793Bu,0x793Du,0x7951u,0x7953u,
        0x7956u,0x7958u,0x795Bu,0x795Du,0x795Fu,0x7961u,0x7964u,0x7966u,0x7968u,0x796Au,
        0x7972u,0x7974u,0x7977u,0x7979u,0x797Bu,0x797Du,0x7980u,0x7982u,0x7984u,0x7986u,
        0x7991u,0x7993u,0x7995u,0x7998u,0x799Au,0x799Cu,0x799Eu,0x79A1u,0x79A3u,0x79A5u,
        0x79A7u,0x79AFu,0x79B1u,0x79B4u,0x79B6u,0x79B8u,0x79BAu,0x79BDu,0x79BFu,0x79C1u,
        0x79C3u,0x79CEu,0x79D0u,0x79D2u,0x79D3u,0x79D5u,0x79D8u,0x79D9u,0x79DBu,0x79DEu,
        0x79E0u,0x79E2u,0x79E3u,0x79E5u
    };
    static const uint16_t byte_pc[] = {
        0x792Bu,0x792Du,0x792Fu,0x7932u,0x7934u,0x7937u,0x7939u,0x793Fu,0x7942u,0x7944u,
        0x7946u,0x7947u,0x7948u,0x794Au,0x794Du,0x794Fu,0x796Cu,0x796Eu,0x7970u,0x7988u,
        0x798Au,0x798Du,0x798Fu,0x79A9u,0x79ABu,0x79ADu,0x79C5u,0x79C7u,0x79CAu,0x79CCu
    };
    const uint16_t *pcs = (status & NH_P_M) ? byte_pc : word_pc;
    unsigned n, count = (unsigned)((status & NH_P_M) ?
        sizeof(byte_pc) / sizeof(byte_pc[0]) : sizeof(word_pc) / sizeof(word_pc[0]));
    if (status & NH_P_X) return 0;
    for (n = 0u; n < count; ++n) if (pc == pcs[n]) return 1;
    return 0;
}

static int sea_camera_seed_asset_stage(NHCore *core, unsigned wx, unsigned wy,
                                      unsigned phase_x, unsigned phase_y) {
    unsigned s = core->cpu.s, pc = core->cpu.pc, bank = core->cpu.pbr, value, cx, cy;
    uint8_t byte, status = core->cpu.p;
    if (core->cpu.e || core->cpu.dbr != 0x7Eu || core->cpu.d != 0x0100u) return 0;
    if (bank == 0u && pc == 0x8490u) {
        if (!port_peek(core, s + 1u, &status) ||
            !port_word(core, s + 2u, &pc) ||
            !port_peek(core, s + 4u, &byte)) return 0;
        bank = byte; s += 4u; /* exact hardware NMI entry only */
    }
    if (bank == 0xC4u) {
        if (!sea_asset_copy_pc(pc, status)) return 0;
    } else if (bank == 0xC1u && !(status & (NH_P_M | NH_P_X))) {
          unsigned owner, caller, comparison = 0u;
        if (pc == 0xFCA7u || pc == 0xFCA8u || pc == 0xFCAAu || pc == 0xFCACu ||
            pc == 0xFCAEu || pc == 0xFCB0u || pc == 0xFCB2u || pc == 0xFCB4u) {
            owner = s + 3u;
        } else if (pc == 0xFE12u || pc == 0xFE16u || pc == 0xFE18u ||
                   pc == 0xFE19u || pc == 0xFE1Bu) {
            owner = s + 3u; comparison = 1u;
        } else if (pc == 0xFEAEu || pc == 0xFEB2u || pc == 0xFEB4u ||
                   pc == 0xFEB5u || pc == 0xFEB7u) {
            owner = s + 3u; comparison = 2u;
        } else if (pc == 0xFEC2u || pc == 0xFEC5u || pc == 0xFEC6u ||
                   pc == 0xFEC8u || pc == 0xFECAu) {
            if (!port_word(core, s + 1u, &value) ||
                (value != 0xFE15u && value != 0xFEB1u) ||
                !port_peek(core, s + 3u, &byte) || byte != 0xC1u) return 0;
              comparison = value == 0xFE15u ? 1u : 2u;
            owner = s + 6u;
        } else return 0;
        /* Only this loop's actual source calls, never a stack scan or a
         * generic arithmetic helper. All have stack-neutral bodies. */
        if (!port_word(core, owner - 2u, &caller) ||
            !port_peek(core, owner, &byte) || byte != 0xC4u ||
            (!comparison && caller != 0x7910u && caller != 0x7920u) ||
            (comparison == 1u && caller != 0x78EAu) ||
            (comparison == 2u && caller != 0x789Cu && caller != 0x78B5u)) return 0;
        s = owner;
    } else return 0;
    if (
        s > 0x1F98u || wx >= 2160u || wy >= 1080u ||
        !port_word(core, s + 19u, &value) || value != 0x7BFDu ||
        !port_peek(core, s + 21u, &byte) || byte != 0xC4u ||
        !port_word(core, s + 100u, &value) || value != 0x7D01u ||
        !port_peek(core, s + 102u, &byte) || byte != 0xC4u ||
        !port_word(core, s + 103u, &value) ||
        !port_word(core, 0x7EA1F0u, &cx) || value != cx ||
        !port_word(core, 0x7E0F6Du, &value) || value ||
        !port_word(core, 0x7E0F6Fu, &cx) || cx != phase_x ||
        !port_word(core, 0x7E0F71u, &cy) || cy != phase_y) return 0;
    sea_camera_anchor(core, wx, wy, phase_x, phase_y);
    return core->ppu.port_ui->sea_camera_valid != 0u;
}

/* Reset/load/new observer discards history. Reseed an acknowledged idle
 * camera, or the exact destination of an active source scroll controller.
 * Never infer correspondence by matching an undifferentiated ocean image. */
static void sea_camera_seed(NHCore *core) {
    NHPortUiCapture14 *ui = core->ppu.port_ui;
    unsigned wx, wy, target_x, target_y, ring_x, ring_y, busy;
    unsigned prefix_pc = core->cpu.pc, prefix_bank = core->cpu.pbr;
    uint8_t mode, phase_x, phase_y;
    uint8_t prefix_status = core->cpu.p;
    if (!ui) return;
    if (!port_peek(core, 0x7E2016u, &mode) || mode != 0xFFu) {
        ui->sea_camera_valid = 0u;
        ui->sea_camera_rebuilding = 0u;
        memset(ui->sea_retired_valid, 0, sizeof(ui->sea_retired_valid));
        ui->sea_discovery_rows = ui->sea_discovery_refresh = 0u;
        ui->sea_marker_retired_valid = 0u;
        return;
    }
    sea_retirement_seed(core);
    if (ui->sea_camera_valid ||
        !port_word(core, 0x7EA259u, &wx) || !port_word(core, 0x7EA25Bu, &wy) ||
        !port_word(core, 0x7E23EEu, &target_x) || !port_word(core, 0x7E23F0u, &target_y) ||
        !port_word(core, 0x7E0F6Du, &busy) ||
        !port_word(core, 0x7EA25Du, &ring_x) || ring_x >= 32u ||
        !port_word(core, 0x7EA25Fu, &ring_y) || ring_y >= 32u ||
        !port_peek(core, 0x7EA257u, &phase_x) || phase_x != ring_x * 8u ||
        !port_peek(core, 0x7EA258u, &phase_y) || phase_y != ((ring_y * 8u + 8u) & 255u)) return;
    if (sea_camera_seed_fleet_wait(core, wx, wy, phase_x, phase_y, busy)) return;
    if (!busy && sea_camera_seed_asset_stage(core, wx, wy, phase_x, phase_y)) return;
    if (!busy) {
        /* A published snapshot may stop at the exact hardware NMI entry,
         * before any handler software save. Recover the interrupted view for
         * the SAME pre-camera fleet prefix below; do not admit handler PCs or
         * guess a dispatcher/call frame. Native NMI leaves D/DBR unchanged. */
        if (!core->cpu.e && prefix_bank == 0u && prefix_pc == 0x8490u &&
            core->cpu.s <= 0x1FFBu) {
            unsigned saved_pc;
            uint8_t saved_bank, saved_status;
            if (port_peek(core, core->cpu.s + 1u, &saved_status) &&
                port_word(core, core->cpu.s + 2u, &saved_pc) &&
                port_peek(core, core->cpu.s + 4u, &saved_bank)) {
                prefix_pc = saved_pc;
                prefix_bank = saved_bank;
                prefix_status = saved_status;
            }
        }
        if (wx == target_x && wy == target_y)
            sea_camera_anchor(core, wx, wy, phase_x, phase_y);
        else if (ring_x == 0u && ring_y == 0u && phase_x == 0u && phase_y == 8u &&
                 sea_camera_seed_full_builder(core, wx, wy, target_x, target_y)) {
            /* Source-qualified pending full replacement; old map still live. */
        }
        else if (!core->cpu.e && !(prefix_status & (NH_P_M | NH_P_X)) &&
                 prefix_bank == 0xC1u && core->cpu.dbr == 0x7Eu &&
                 (core->cpu.d == 0u || core->cpu.d == 0x100u) &&
                 prefix_pc >= 0x2828u && prefix_pc <= 0x2A8Bu &&
                 target_x < 2160u && target_y < 1080u &&
                 (int)target_x - (int)wx >= -1 && (int)target_x - (int)wx <= 1 &&
                 (int)target_y - (int)wy >= -1 && (int)target_y - (int)wy <= 1) {
            /* C1:2828..2A8B is the fleet-update prefix BEFORE its sole camera
             * call at2A8B (C2:0AB8). C9:7935..79F9 may already have advanced
             * the pending target, but this prefix cannot have committed the
             * new rings/phases at C2:0C32/0C72. On restore, use the acknowledged
             * OLD rectangle with its OLD phase. Do not infer this from equal
             * ocean tiles, a stale completed controller, or an arbitrary PC.
             * Full-camera rebuilds/global wraps are deliberately separate. */
            sea_camera_anchor(core, wx, wy, phase_x, phase_y);
        }
    } else {
        unsigned cx, cy, sx, sy, duration, period, source_period;
        uint8_t layer;
        int dx, dy, total_x, total_y, world_dx, world_dy;
        /* C0:A010(command45) records current scroll0F6F/71, per-step
         * increments73/75, count6D, period77, layer79. C0:91D5..924B
         * adds each increment then decrements count. Consequently current
         * + remaining*increment is the exact destination, even before the
         * final PPU-register copy. Reject a snapshot inside those writes. */
        if ((core->cpu.pbr == 0u || core->cpu.pbr == 0xC0u) &&
            core->cpu.pc >= 0x91D5u && core->cpu.pc < 0x9250u) return;
        if (!port_word(core, 0x7E0F6Fu, &cx) ||
            !port_word(core, 0x7E0F71u, &cy) ||
            !port_word(core, 0x7E0F73u, &sx) ||
            !port_word(core, 0x7E0F75u, &sy) ||
            !port_word(core, 0x7EA393u, &duration) || !duration || duration > 8u ||
            busy > duration || !port_word(core, 0x7E0F77u, &period) ||
            !port_word(core, 0x7EA391u, &source_period) || period != source_period ||
            !port_peek(core, 0x7E0F79u, &layer) || layer != 2u) return;
        dx = sx < 32768u ? (int)sx : (int)sx - 65536;
        dy = sy < 32768u ? (int)sy : (int)sy - 65536;
        if (dx < -8 || dx > 8 || dy < -8 || dy > 8) return;
        total_x = dx * (int)duration; total_y = dy * (int)duration;
        world_dx = (int)target_x - (int)wx; world_dy = (int)target_y - (int)wy;
        /* C2:0C32/0C72 update destination phases/rings before0EBF/0EC5
         * acknowledge the new world rectangle. Each acknowledgment may be
         * old or new, but the changed source step must be exactly one cell.
         * The phase must ALREADY equal the controller destination: an old
         * phase at0C0F cannot be paired with the pending world target. */
        if ((total_x != -8 && total_x != 0 && total_x != 8) ||
            (total_y != -8 && total_y != 0 && total_y != 8) ||
            (!total_x && !total_y) ||
            (world_dx && world_dx * 8 != total_x) ||
            (world_dy && world_dy * 8 != total_y) ||
            (((int)cx + (int)busy * dx) & 255) != phase_x ||
            (((int)cy + (int)busy * dy) & 255) != phase_y) return;
        sea_camera_anchor(core, target_x, target_y, phase_x, phase_y);
    }
}

/* Read-only presentation assets, NOT an alternative S-CPU/decompression path.
 * C4:778A points at a C0:A24C stream of144 metacodes; C4:78DE expands each
 * into four cells. All scratch is caller-local and excluded from snapshots.
 * The native CPU, its cache, clocks and decompressor remain untouched. */
typedef struct NHSeaAssetStream {
    const uint8_t *rom;
    uint32_t cursor;
    unsigned reservoir, tail, available;
} NHSeaAssetStream;

typedef struct NHSeaSource {
    const NHCore *core;
    unsigned count;
    uint16_t keys[16];
    uint8_t chunks[16][576];
} NHSeaSource;

static int sea_asset_byte(NHSeaAssetStream *stream, unsigned *value) {
    if (stream->cursor >= NH_CORE_ROM_BYTES) return 0;
    *value = stream->rom[stream->cursor++];
    return 1;
}

static int sea_asset_bits(NHSeaAssetStream *stream, unsigned amount) {
    unsigned lo, hi, missing;
    if ((amount & 1u) || amount > 32u) return 0;
    stream->reservoir = (stream->reservoir << (amount / 2u)) & 65535u;
    if (stream->available < amount) {
        missing = amount - stream->available;
        stream->reservoir |= (stream->tail & ((1u << (stream->available / 2u)) - 1u)) << (missing / 2u);
        if (!sea_asset_byte(stream, &lo) || !sea_asset_byte(stream, &hi)) return 0;
        stream->tail = lo | (hi << 8u);
        stream->available = 32u - missing;
        stream->reservoir |= (stream->tail >> (stream->available / 2u)) & ((1u << (missing / 2u)) - 1u);
    } else {
        stream->available -= amount;
        stream->reservoir |= (stream->tail >> (stream->available / 2u)) & ((1u << (amount / 2u)) - 1u);
    }
    stream->reservoir &= 65535u;
    return 1;
}

static int sea_asset_chunk(const NHCore *core, unsigned key, uint8_t *cells) {
    NHSeaAssetStream stream;
    uint8_t codes[144];
    unsigned pointer, flags = 0u, remaining = 0u, count = 0u, token, n;
    int terminated = 0;
    if (key >= 4050u) return 0;
    pointer = 0x3CDBAu + key * 3u;
    stream.rom = core->rom;
    stream.cursor = 0x11C07Eu + core->rom[pointer] +
        ((uint32_t)core->rom[pointer + 1u] << 8u) + ((uint32_t)core->rom[pointer + 2u] << 16u);
    stream.reservoir = stream.tail = stream.available = 0u;
    if (!sea_asset_bits(&stream, 32u)) return 0;
    for (token = 0u; token < 1024u; ++token) {
        unsigned literal, value, index, length, distance, consume;
        if (!remaining) {
            if (!sea_asset_byte(&stream, &flags)) return 0;
            remaining = 8u;
        }
        literal = flags & 128u; flags = (flags << 1u) & 255u; --remaining;
        if (literal) {
            if (count >= 144u || !sea_asset_byte(&stream, &value)) return 0;
            codes[count++] = (uint8_t)value;
            continue;
        }
        if (stream.reservoir & 32768u) length = 1u;
        else {
            value = stream.reservoir >> 1u; index = value >> 8u;
            if (!index) {
                length = (value >> 1u) | 128u;
                if (length == 255u) { terminated = 1; break; }
            } else if (index < 8u) length = value >> (core->rom[0xA16Eu + index] / 2u);
            else length = core->rom[0xA0EFu + index];
            if (!sea_asset_bits(&stream, core->rom[0xA12Fu + index])) return 0;
        }
        value = (stream.reservoir << 1u) & 65535u;
        if (value < 0x6000u) {
            index = ((value << 1u) & 65535u) >> 8u;
            distance = core->rom[0xA176u + index];
            consume = core->rom[0xA236u + (index >> 4u)];
        } else {
            index = value >> 13u;
            distance = ((stream.reservoir & 0xFFFu) | 0x1000u) >> (core->rom[0xA23Fu + index] / 2u);
            consume = core->rom[0xA244u + index];
        }
        if (!sea_asset_bits(&stream, consume)) return 0;
        ++distance; /* REP11 clears carry before the native SBC/MVN. */
        if (distance > count || length + 1u > 144u - count) return 0;
        for (n = 0u; n <= length; ++n) {
            codes[count] = codes[count - distance]; ++count;
        }
    }
    if (!terminated || count != 144u) return 0;
    for (n = 0u; n < 144u; ++n) {
        unsigned corner, x = (n % 12u) * 2u, y = (n / 12u) * 2u;
        for (corner = 0u; corner < 4u; ++corner)
            cells[(y + corner / 2u) * 24u + x + corner % 2u] = codes[n] < 16u ?
                (codes[n] & (8u >> corner) ? 128u : 0u) : core->rom[0xF0000u + codes[n] * 4u + corner];
    }
    return 1;
}

static int sea_raw_cell(NHSeaSource *source, int x, int y, uint8_t *value) {
    unsigned key, slot;
    if (x < 0 || x >= 2160 || y < 0 || y >= 1080) return 0;
    key = (unsigned)(y / 24) * 90u + (unsigned)(x / 24);
    for (slot = 0u; slot < source->count && source->keys[slot] != key; ++slot) {}
    if (slot == source->count) {
        if (slot >= 16u || !sea_asset_chunk(source->core, key, source->chunks[slot])) return 0;
        source->keys[slot] = (uint16_t)key; ++source->count;
    }
    *value = source->chunks[slot][(unsigned)(y % 24) * 24u + (unsigned)(x % 24)];
    return 1;
}

/* C4:7616/7627/76D7 hash lookup, C5:01C8/022A state records. The
 * immutable hash supplies identity, never state: discovery bits are WRAM. */
static int sea_site_state(const NHCore *core, unsigned x, unsigned y,
                          int village, uint8_t *flags) {
    unsigned lo, bank, hash = (x + y) % 255u, n;
    uint32_t table;
    if (!port_word(core, 0x7EA1F6u, &lo) || !port_word(core, 0x7EA1F8u, &bank)) return 0;
    table = lo | ((uint32_t)(bank & 255u) << 16u);
    for (n = 0u; n < 255u; ++n, hash = (hash + 19u) % 255u) {
        uint8_t id;
        unsigned sx, sy, record;
        if (!port_peek(core, table + hash + (village ? 256u : 0u), &id) || id == 255u) return 0;
        record = village ? 0x7E8D14u + 7u * id : 0x7E735Cu + 22u * id;
        if (!port_word(core, record, &sx) || !port_word(core, record + 2u, &sy)) return 0;
        if (sx == x && sy == y)
            return port_peek(core, record + (village ? 6u : 21u), flags);
    }
    return 0;
}

static int sea_source_cell(NHSeaSource *source, int x, int y,
                            unsigned depth, uint8_t *value) {
    int qx, qy = y & ~1;
    uint8_t head, flags;
    if (y < 0 || y >= 1080 || depth > 64u) return 0;
    /* C9:78FF..7924 normalizes pending longitude modulo0870; latitude
     * instead has bounded follow limits. Wrap real world assets, NOT VRAM. */
    x %= 2160;
    if (x < 0) x += 2160;
    qx = x & ~1;
    /* C4's72x72 WRAM buffer is refreshed in place while an older native
     * raster is still displayed;23F6/F8 even temporarily hold chunk units.
     * Use immutable ROM assets plus actual live discovery flags throughout,
     * including the original view. The native raster join stays mandatory. */
    if (!sea_raw_cell(source, qx, qy, &head)) return 0;
    if (head == 0xBCu || head == 0xC0u) {
        if (!sea_site_state(source->core, (unsigned)qx, (unsigned)qy, 0, &flags)) return 0;
        if (source->core->ppu.port_ui &&
            !source->core->ppu.port_ui->sea_discovery_village &&
            source->core->ppu.port_ui->sea_discovery_x == (unsigned)qx &&
            source->core->ppu.port_ui->sea_discovery_y == (unsigned)qy &&
            (source->core->ppu.port_ui->sea_discovery_rows & (1u << (y - qy))))
            flags &= (uint8_t)~0x10u;
        if (!(flags & 0x10u)) { *value = 0x80u; return 1; }
    } else if (head == 0xC4u) {
        if (!sea_site_state(source->core, (unsigned)qx, (unsigned)qy, 1, &flags)) return 0;
        if (source->core->ppu.port_ui &&
            source->core->ppu.port_ui->sea_discovery_village &&
            source->core->ppu.port_ui->sea_discovery_x == (unsigned)qx &&
            source->core->ppu.port_ui->sea_discovery_y == (unsigned)qy &&
            (source->core->ppu.port_ui->sea_discovery_rows & (1u << (y - qy))))
            flags &= (uint8_t)~0x40u;
        if (!(flags & 0x40u)) {
            uint8_t previous;
            /* Native C4:7E4B reads the already processed preceding cell.
             * Never substitute raw water/land or assume a hidden village. */
            if (!sea_source_cell(source, qx - 1, qy, depth + 1u, &previous)) return 0;
            *value = previous == 0x86u ? 0x86u : 0x80u;
            return 1;
        }
    }
    return sea_raw_cell(source, x, y, value);
}

/* Exact C9 flag producers -> C9:4434 -> C4:7CF1 -> C2:0ED0.
 * Neither a live discovery bit nor an in-place RAM cache is a PPU publication.
 * C2:07B8 returns only after command06's ring-split row transfer waits.
 * Observe the caller's actual row and stack lifetime, not elapsed fields or
 * arbitrary land matching. All native raster/source joins remain mandatory. */
static void sea_discovery_observe(NHCore *core) {
    NHPortUiCapture14 *ui = core->ppu.port_ui;
    unsigned x, y, pointer, flags_offset, wx, wy, row, ret;
    uint8_t mode, flags, actual, bank;
    if (!ui || core->cpu.e || (core->cpu.p & NH_P_X) || core->cpu.dbr != 0x7Eu ||
        (core->cpu.d != 0u && core->cpu.d != 0x100u) ||
        !port_peek(core, 0x7E2016u, &mode) || mode != 0xFFu) return;
    if (core->cpu.pbr == 0xC9u) {
        NHSeaSource source = {0};
        uint8_t head, village = core->cpu.pc == 0x606Cu ||
            core->cpu.pc == 0x625Eu || core->cpu.pc == 0x62BBu;
        unsigned base = village ? 0x8D14u : 0x735Cu;
        unsigned stride = village ? 7u : 22u, count = village ? 100u : 130u;
        unsigned visible = village ? 0x40u : 0x10u;
        flags_offset = village ? 6u : 21u;
        if (!(core->cpu.p & NH_P_M) || core->cpu.y != flags_offset ||
            !port_word(core, core->cpu.d + (village ? 0x28u : 0x26u), &pointer) ||
            pointer < base || pointer >= base + stride * count ||
            (pointer - base) % stride != 0u ||
            !port_word(core, 0x7E0000u + pointer, &x) ||
            !port_word(core, 0x7E0002u + pointer, &y) ||
            x >= 2160u || y >= 1080u || (x & 1u) || (y & 1u) ||
            !port_peek(core, 0x7E0000u + pointer + flags_offset, &flags) ||
            (flags & visible) || (core->cpu.a & 255u) != (flags | visible) ||
            !sea_site_state(core, x, y, village, &actual) || actual != flags) return;
        source.core = core;
        if (!sea_raw_cell(&source, (int)x, (int)y, &head) ||
            (village ? head != 0xC4u : head != 0xBCu && head != 0xC0u)) return;
        ui->sea_discovery_x = (uint16_t)x;
        ui->sea_discovery_y = (uint16_t)y;
        ui->sea_discovery_village = village;
        ui->sea_discovery_rows = 3u;
        ui->sea_discovery_refresh = 0u;
        return;
    }
    if ((core->cpu.p & NH_P_M) || !ui->sea_discovery_rows) return;
    if (core->cpu.pc == 0x0ED0u) {
        /* Only this discovery caller, not unrelated redraws, owns the pending
         * primitive. JSL atC9:444C leaves the actual return C9:444F. */
        if (!port_word(core, core->cpu.s + 1u, &ret) || ret != 0x444Fu ||
            !port_peek(core, core->cpu.s + 3u, &bank) || bank != 0xC9u ||
            !port_word(core, 0x7E23EEu, &wx) || wx >= 2160u ||
            !port_word(core, 0x7E23F0u, &wy) || wy >= 1080u) return;
        ui->sea_discovery_stack = core->cpu.s;
        ui->sea_discovery_map_x = (uint16_t)wx;
        ui->sea_discovery_map_y = (uint16_t)wy;
        ui->sea_discovery_refresh = 1u;
        return;
    }
    if (!ui->sea_discovery_refresh) return;
    flags_offset = core->cpu.pc == 0x0F12u ? 10u : 0u;
    if ((unsigned)core->cpu.s + flags_offset + 6u != ui->sea_discovery_stack ||
        !port_word(core, core->cpu.s + flags_offset + 1u, &wx) ||
        !port_word(core, core->cpu.s + flags_offset + 3u, &wy) ||
        !port_word(core, core->cpu.s + flags_offset + 5u, &row) ||
        wx != ui->sea_discovery_map_x || wy != ui->sea_discovery_map_y) return;
    if (core->cpu.pc == 0x0F1Eu && row == 30u) {
        ui->sea_discovery_rows = ui->sea_discovery_refresh = 0u;
    } else if (core->cpu.pc == 0x0F12u && row < 30u &&
        wy + row >= ui->sea_discovery_y && wy + row <= ui->sea_discovery_y + 1u &&
        (ui->sea_discovery_x + 2160u - wx) % 2160u < 31u) {
        ui->sea_discovery_rows &= (uint8_t)~(1u << (wy + row - ui->sea_discovery_y));
    }
}

/* SourceC2:0067. Zero cells gain a N/E/S/W coast mask;80 is latitude-
 * dependent land; other low-seven-bit-nonzero bytes retain their source ID.
 * C2:014D indexes the45-word C2:B6E2 band table by global row/24.
 * C2:0453 adds the CF:0400 palette classification plus2, shifted10.
 * The one-cell halo is required, not silently replaced with water. */
static int sea_source_entry(NHSeaSource *source_map,
    int global_x, int global_y, uint16_t *entry) {
    const NHCore *core = source_map->core;
    uint8_t source, palette;
    unsigned band, tile;
    if (!entry || !sea_source_cell(source_map, global_x, global_y, 0u, &source)) return 0;
    band = (unsigned)core->rom[0x2B6E2u + ((unsigned)global_y / 24u) * 2u] |
        ((unsigned)core->rom[0x2B6E3u + ((unsigned)global_y / 24u) * 2u] << 8u);
    if (band > 8u) return 0;
    band = band <= 4u ? band + 1u : 9u - band;
    if (source & 0x7Fu) tile = source;
    else if (source) tile = 0x80u + band;
    else {
        static const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
        unsigned n, mask = 0u;
        for (n = 0u; n < 4u; ++n) {
            uint8_t neighbor;
            if (!sea_source_cell(source_map, global_x + dx[n], global_y + dy[n], 0u, &neighbor)) return 0;
            if (neighbor >= 0x80u) mask |= 1u << n;
        }
        tile = mask ? (band << 4u) + mask : 0x0Fu;
    }
    palette = core->rom[0xF0400u + tile];
    if (palette > 5u) return 0;
    *entry = (uint16_t)(tile | ((unsigned)(palette + 2u) << 10u));
    return 1;
}

static int sea_refuse(const NHCore *core, unsigned stage, unsigned subject,
                      unsigned expected, unsigned actual) {
    NHPortUiCapture14 *ui = core->ppu.port_ui;
    if (ui) {
        ui->sea_refusal_stage = stage; ui->sea_refusal_subject = subject;
        ui->sea_refusal_expected = expected; ui->sea_refusal_actual = actual;
    }
    return 0;
}

/* C2:5562 selects one of eight source rectangles, C2:4F8E/5110 builds
 * its W2 highlight, C2:5547/55E6 invokes C1:945C for flag108..111.
 * Source records are four WORDS: FF20 shifts index by3 (eight bytes).
 * Validate consumed window rows/flag fragments against ALL candidates:
 * the newly selected index can already be ahead of consumed HDMA/OAM. */
static void sea_marker_retire_observe(NHCore *core) {
    NHPortUiCapture14 *ui = core->ppu.port_ui;
    const NHPPU11 *p = &core->ppu;
    unsigned sx, sy, tx, ty, i;
    int x, y;
    uint8_t mode;
    if (!ui || core->cpu.e || (core->cpu.p & (NH_P_M | NH_P_X)) ||
        core->cpu.dbr != 0x7Eu || core->cpu.d != 0x0100u || core->cpu.a ||
        !port_peek(core, 0x7E2016u, &mode) || mode != 0xFFu ||
        !port_word(core, 0x7E9EEAu, &sx) || sx >= 2160u ||
        !port_word(core, 0x7E9EECu, &sy) || sy >= 1080u || (!sx && !sy) ||
        !port_word(core, 0x7E23EEu, &tx) || tx >= 2160u ||
        !port_word(core, 0x7E23F0u, &ty) || ty >= 1080u) return;
    x = ((int)sx - (int)tx) * 8 + 3;
    y = ((int)sy - (int)ty - 1) * 8 - 12;
    if (x < 0 || x > 240 || y < 0 || y > 208) return;
    /* Capture only the fully consumed exact source primitive. The later
     * global clear is not evidence for unrelated poses or a future flag. */
    for (i = 108u; i < 112u; ++i) {
        unsigned ox;
        if (nh_ppu14_object_native_hidden(p, i) != 0 ||
            !nh_ppu14_sea_marker_object(p, i) ||
            p->oam[i * 4u].known_mask != 255u ||
            p->oam[i * 4u + 1u].known_mask != 255u ||
            p->oam[512u + i / 4u].known_mask != 255u) return;
        ox = p->oam[i * 4u].value |
            (((p->oam[512u + i / 4u].value >> ((i & 3u) * 2u)) & 1u) << 8u);
        if (ox != (unsigned)x + ((i - 108u) & 1u) * 8u ||
            p->oam[i * 4u + 1u].value != (unsigned)y + ((i - 108u) >> 1u) * 8u) return;
    }
    ui->sea_marker_retired_x = (uint16_t)x;
    ui->sea_marker_retired_y = (uint16_t)y;
    ui->sea_marker_retired_valid = 1u;
}

static void sea_selection_qualify(const NHCore *core) {
    NHPortUiCapture14 *ui = core->ppu.port_ui;
    const NHPPU11 *p = &core->ppu;
    unsigned count, selected, mode, rect[8][4], i, n, y;
    unsigned site_x, site_y, target_x, target_y;
    int marker_ok = 1, window_ok, world_marker = 0, marker_x = 0, marker_y = 0;
    ui->sea_rect_qualified = ui->sea_marker_qualified = 0u;
    if (ui->sea_marker_retired_valid) {
        int all_hidden = 1;
        for (i = 108u; i < 112u; ++i)
            if (nh_ppu14_object_native_hidden(p, i) != 1) all_hidden = 0;
        if (all_hidden) ui->sea_marker_retired_valid = 0u;
    }
    if (!port_word(core, 0x7EFBD5u, &count) || count != 8u ||
        !port_word(core, 0x7EFBDDu, &selected) || selected >= 8u ||
        !port_word(core, 0x7EFBDFu, &mode)) return;
    /* C2:5619..562A clears FBDF before the pending OAM/window transfers
     * retire the consumed flag and highlight. The published OAM can still
     * contain the live flag for that field: require the same source-owned
     * rectangles, exact flag geometry and captured W2 rows below instead of
     * requiring an OAM hide which has not reached the PPU yet. */
    if (mode != 0x8200u && mode != 0u) return;
    /* C1:95FF..9630 repositions the anchored/Wait flag from the retained
     * world point9EEA/EC, not the old selector's raster-minus-one rectangle.
     * Its exact formula differs by one Y pixel. Retain both real source
     * publications while fragments update; never allow a free +/-1 tolerance.
     * No highlight is inferred from this independent flag producer. */
    if (!mode && port_word(core, 0x7E9EEAu, &site_x) && site_x < 2160u &&
        port_word(core, 0x7E9EECu, &site_y) && site_y < 1080u &&
        port_word(core, 0x7E23EEu, &target_x) && target_x < 2160u &&
        port_word(core, 0x7E23F0u, &target_y) && target_y < 1080u) {
        marker_x = ((int)site_x - (int)target_x) * 8 + 3;
        marker_y = ((int)site_y - (int)target_y - 1) * 8 - 12;
        world_marker = marker_x >= -15 && marker_x < 256 &&
                       marker_y >= -15 && marker_y < 224;
    }
    for (i = 0u; i < 8u; ++i) {
        for (n = 0u; n < 4u; ++n)
            if (!port_word(core, 0x7EF5B7u + i * 8u + n * 2u, &rect[i][n])) return;
        if (rect[i][0] >= 256u || rect[i][1] > 256u || rect[i][1] != rect[i][0] + 8u ||
            rect[i][2] < 12u || rect[i][3] > 224u || rect[i][3] != rect[i][2] + 8u) return;
    }
    for (i = 108u; i <= 111u; ++i) {
        unsigned x, oy;
        int hidden = nh_ppu14_object_native_hidden(p, i), match = 0;
        if (hidden == 1) continue;
        if (hidden < 0 || !nh_ppu14_sea_marker_object(p, i)) { marker_ok = 0; break; }
        x = p->oam[i * 4u].value |
            (((p->oam[512u + i / 4u].value >> ((i & 3u) * 2u)) & 1u) << 8u);
        oy = p->oam[i * 4u + 1u].value;
        for (n = 0u; n < 8u; ++n)
            if (x == rect[n][0] + 3u + ((i - 108u) & 1u) * 8u &&
                oy == rect[n][2] - 12u + ((i - 108u) >> 1u) * 8u) match = 1;
        if (world_marker &&
            x == ((unsigned)(marker_x + (int)((i - 108u) & 1u) * 8) & 511u) &&
            oy == ((unsigned)(marker_y + (int)((i - 108u) >> 1u) * 8) & 255u)) match = 1;
        if (!mode && ui->sea_marker_retired_valid &&
            x == ui->sea_marker_retired_x + ((i - 108u) & 1u) * 8u &&
            oy == ui->sea_marker_retired_y + ((i - 108u) >> 1u) * 8u) match = 1;
        if (!match) { marker_ok = 0; break; }
    }
    ui->sea_marker_qualified = (uint8_t)marker_ok;
    window_ok = ui->sea_rect_valid[ui->published] == 1u && ui->sea_rect_any[ui->published];
    for (y = 0u; window_ok && y < 224u; ++y) {
        unsigned left = ui->sea_rect_left[ui->published][y];
        unsigned right = ui->sea_rect_right[ui->published][y];
        int match = left == 255u && right == 0u;
        for (n = 0u; n < 8u && !match; ++n)
            if (left == rect[n][0] && right + 1u == rect[n][1] &&
                y + 1u >= rect[n][2] && y + 2u <= rect[n][3]) match = 1;
        if (!match) window_ok = 0;
    }
    ui->sea_rect_qualified = (uint8_t)window_ok;
}

int nh_core_sea_terrain_info(const NHCore *core, NHCoreSeaTerrainInfo *info) {
    const NHPPU11 *p;
    NHSeaSource source;
    unsigned wx, wy, ring_x, ring_y, x, y, columns, rows, scroll_x, scroll_y, joined = 0u;
    uint8_t mode;
    const NHPortUiCapture14 *ui;
    if (!assembled(core) || !info) return 0;
    if (core->ppu.port_ui)
        core->ppu.port_ui->sea_rect_qualified = core->ppu.port_ui->sea_marker_qualified = 0u;
    sea_refuse(core, 1u, 0u, 0u, 0u);
    p = &core->ppu;
    if (!p->frame_ready || p->forced_blank || !p->brightness ||
        p->interlace || p->overscan || p->published_height != 224u ||
        p->registers[5].known_mask != 255u || p->registers[5].value != 0x09u ||
        p->registers[8].known_mask != 255u || p->registers[8].value != 0x58u ||
        p->registers[11].known_mask != 255u || p->registers[11].value != 0x22u ||
        p->registers[0x2C].known_mask != 255u || !(p->registers[0x2C].value & 2u) ||
        p->bg_hofs[1].known_mask != 0x3FFu || p->bg_vofs[1].known_mask != 0x3FFu ||
        !port_peek(core, 0x7E2016u, &mode) || mode != 0xFFu ||
        !port_word(core, 0x7EA259u, &wx) || !port_word(core, 0x7EA25Bu, &wy) ||
        !port_word(core, 0x7EA25Du, &ring_x) || ring_x > 31u ||
        !port_word(core, 0x7EA25Fu, &ring_y) || ring_y > 31u) return 0;
    /* Use the source-committed correspondence, not a pending ring combined
     * with an older acknowledged global rectangle. Same actual PPU scroll. */
    ui = p->port_ui;
    sea_refuse(core, 2u, 0u, 0u, 0u);
    if (!ui || !ui->sea_camera_valid || ui->sequence != p->published_sequence ||
        !ui->valid[ui->published] || ui->frame_mode[ui->published] != 0x09u ||
        ui->sea_scroll_valid[ui->published] != 1u) return 0;
    sea_selection_qualify(core);
    if (ui->sea_mosaic_valid[ui->published] != 1u ||
        (ui->sea_mosaic[ui->published] != 0u && ui->sea_mosaic[ui->published] != 2u &&
         ui->sea_mosaic[ui->published] != 0x22u))
        return sea_refuse(core, 22u, 0u, 0x22u, ui->sea_mosaic[ui->published]);
    if (ui->sea_color_valid[ui->published] != 1u && !ui->sea_rect_qualified)
        return sea_refuse(core, 19u, 0u, 1u, ui->sea_color_valid[ui->published]);
    scroll_x = ui->sea_hofs[ui->published]; scroll_y = ui->sea_vofs[ui->published];
    info->native_origin_x = ui->sea_anchor_x +
        port_unwrap((int)scroll_x, ui->sea_phase_x, 256) - ui->sea_phase_x;
    info->native_origin_y = ui->sea_anchor_y +
        port_unwrap((int)scroll_y, ui->sea_phase_y, 256) - ui->sea_phase_y;
    if (info->native_origin_x < 0 || info->native_origin_y < 0) return 0;
    source.core = core; source.count = 0u;
    /* Include partial right/bottom cells when consumed scroll is sub-tile. */
    columns = 32u + (scroll_x & 7u ? 1u : 0u);
    rows = 28u + (scroll_y & 7u ? 1u : 0u);
    for (y = 0u; y < rows; ++y) for (x = 0u; x < columns; ++x) {
        unsigned tx = (scroll_x / 8u + x) & 31u;
        unsigned ty = (scroll_y / 8u + y) & 31u;
        unsigned cell = ty * 32u + tx;
        unsigned address = 0xB000u + cell * 2u;
        uint16_t expected = 0u;
        /* The source streams/cache-wraps masked gutters before they become
         * visible. Only entries actually selected by the native raster are
         * obligations. Keep every one of those exact; don't weaken the join
         * or invent a fixed239px crop for menus/windows/scroll fringes. */
        if (!ui->sea_bg2_seen[ui->published][cell]) continue;
        if (ui->sea_bg2_seen[ui->published][cell] != 1u)
            return sea_refuse(core, 3u, cell, 1u, ui->sea_bg2_seen[ui->published][cell]);
        if (!sea_source_entry(&source, info->native_origin_x / 8 + (int)x,
            info->native_origin_y / 8 + (int)y, &expected) ||
            p->vram[address].known_mask != 255u || p->vram[address + 1u].known_mask != 255u ||
            ui->sea_bg2_entry[ui->published][cell] != expected ||
            (unsigned)(p->vram[address].value | ((unsigned)p->vram[address + 1u].value << 8u)) != expected)
            return sea_refuse(core, 4u, cell, expected,
                p->vram[address].value | ((unsigned)p->vram[address + 1u].value << 8u));
        ++joined;
    }
    if (!joined) return sea_refuse(core, 5u, 0u, 1u, 0u);
    info->width = 512u; info->height = 288u;
    info->region_column = (uint16_t)(info->native_origin_x / (8 * 24) * 24);
    info->region_row = (uint16_t)(info->native_origin_y / (8 * 24) * 24);
    info->origin_x = info->native_origin_x - 128;
    info->origin_y = info->native_origin_y - 32;
    /* Normal sailing follows X0..0850,Y0..041A (C9:7935..79F9), keeping
     * the native selected world inside source bounds. Keep its centre/phase
     * unchanged. Expanded longitude wraps the2160-cell source world;
     * unavailable finite polar margins clear deliberately, never repeat sea.
     * A native view itself extending beyond source still needs a separate
     * actual-raster contract, not an assumed correction of native behavior. */
    if (info->native_origin_x + 255 >= 2160 * 8 ||
        info->native_origin_y + 223 >= 1080 * 8)
        return sea_refuse(core, 6u, 0u, (unsigned)info->origin_x, (unsigned)info->origin_y);
    return 1;
}

static int sea_pixel_cell(int pixel) {
    /* C division truncates toward zero; a fractional negative margin needs
     * mathematical floor so its tile and the positive phase remain paired. */
    return pixel >= 0 ? pixel / 8 : -((-pixel + 7) / 8);
}

int nh_core_read_sea_terrain(const NHCore *core, uint16_t *pixels,
                             uint32_t capacity, NHCoreSeaTerrainInfo *info) {
    NHCoreSeaTerrainInfo scene;
    NHSeaSource source;
    /* One extra source cell above/left supplies fog's native-anchored3px
     * blocks when an added-margin sample rounds to a negative output pixel. */
    uint16_t entries[66u * 38u] = {0};
    unsigned x, y, columns, rows;
    if (!pixels || capacity < 512u * 288u || !nh_core_sea_terrain_info(core, &scene)) return 0;
    source.core = core; source.count = 0u;
    columns = 65u + ((unsigned)scene.origin_x & 7u ? 1u : 0u);
    rows = 37u + ((unsigned)scene.origin_y & 7u ? 1u : 0u);
    for (y = 0u; y < rows; ++y) for (x = 0u; x < columns; ++x) {
        int gy = sea_pixel_cell(scene.origin_y) - 1 + (int)y;
        if (gy < 0 || gy >= 1080) entries[y * 66u + x] = NH_PPU_SEA_OUTSIDE_WORLD;
        else if (!sea_source_entry(&source, sea_pixel_cell(scene.origin_x) - 1 + (int)x,
            gy, &entries[y * 66u + x])) return 0;
    }
    if (!nh_ppu14_read_sea_terrain(&core->ppu, entries,
        (unsigned)scene.origin_x & 7u, (unsigned)scene.origin_y & 7u, pixels, capacity)) return 0;
    if (info) *info = scene;
    return 1;
}

/* Read-only counterpart of C9:671F's four-cell coastal visibility test.
 * Extending the presentation does not change which native fleet is simulated,
 * allocated, encountered, moved or written into the guest OAM shadow. */
static int sea_fleet_shore(NHSeaSource *source, unsigned x, unsigned y, int *visible) {
    unsigned dx, dy;
    *visible = 0;
    for (dy = 0u; dy < 2u && y + dy < 1080u; ++dy)
        for (dx = 0u; dx < 2u; ++dx) {
            uint8_t value;
            if (!sea_source_cell(source, (int)(x + dx), (int)(y + dy), 0u, &value)) return 0;
            if (value < 0x80u) { *visible = 1; return 1; }
        }
    return 1;
}

static int sea_model_word(unsigned word, unsigned base, unsigned model) {
    unsigned heading;
    word &= ~2u;
    for (heading = 0u; heading < 8u; ++heading)
        if (word == (base | (0xC0u + 64u * model + 4u * heading +
            (heading >= 4u ? 16u : 0u)))) return 1;
    return 0;
}

/* Qualify a still-visible consumed retirement tail by its observed source
 * free, finite model poses and both currently freed identity maps. Its exact
 * OAM position is presentation authority; never guess a replacement fleet. */
static int sea_retired_actor(const NHCore *core, unsigned slot,
                              const NHCoreSeaTerrainInfo *scene,
                              NHPortActor14 *actor, unsigned *fleet) {
    const NHPPU11 *p = &core->ppu;
    NHPortUiCapture14 *ui = p->port_ui;
    unsigned index = 112u + slot, offset = index * 4u, word, pair, raw_x, n;
    uint8_t reverse, forward;
    if (!ui || slot < 2u || slot >= 16u || !ui->sea_retired_valid[slot] ||
        (ui->sea_retired_fleet[slot] >= 70u && ui->sea_retired_fleet[slot] != 255u) ||
        !port_peek(core, 0x7EEA5Du + slot, &reverse) ||
        nh_ppu14_object_native_hidden(p, index) != 0) return 0;
    forward = 255u;
    if (ui->sea_retired_fleet[slot] < 70u &&
        !port_peek(core, 0x7EEA17u + ui->sea_retired_fleet[slot], &forward)) return 0;
    for (n = 0u; n < 4u; ++n) if (p->oam[offset + n].known_mask != 255u) return 0;
    if (p->oam[512u + index / 4u].known_mask != 255u) return 0;
    pair = (p->oam[512u + index / 4u].value >> ((index & 3u) * 2u)) & 3u;
    word = p->oam[offset + 2u].value | ((unsigned)p->oam[offset + 3u].value << 8u);
    if (ui->sea_retired_reallocated[slot]) {
        uint8_t assigned;
        unsigned n;
        /* C2:154A has committed a new forward/reverse pair, not an OAM
         * transfer. Admit only the old exact witnessed pose (animation XOR2
         * allowed). Any changed consumed pose ends this witness permanently. */
        if (reverse >= 70u || !port_peek(core, 0x7EEA17u + reverse, &assigned) || assigned != slot)
            return 0;
        for (n = 0u; n < 4u; ++n)
            if ((p->oam[offset + n].value & (n == 2u ? 0xFDu : 255u)) !=
                (ui->sea_retired_pose[slot][n] & (n == 2u ? 0xFDu : 255u))) break;
        if (n != 4u || pair != ui->sea_retired_pose[slot][4]) {
            ui->sea_retired_valid[slot] = 0u; return 0;
        }
    } else if (reverse != 255u || forward != 255u) return 0;
    if (!(pair & 2u) || !sea_model_word(word, 0x2A00u, ui->sea_retired_model[slot])) return 0;
    if (fleet) *fleet = ui->sea_retired_fleet[slot];
    if (actor) {
        raw_x = p->oam[offset].value | ((pair & 1u) << 8u);
        actor->world_x = (int16_t)((raw_x < 256u ? (int)raw_x : (int)raw_x - 512) +
            scene->native_origin_x - scene->origin_x);
        actor->world_y = (int16_t)((p->oam[offset + 1u].value > 240u ?
            (int)p->oam[offset + 1u].value - 256 : p->oam[offset + 1u].value) +
            scene->native_origin_y - scene->origin_y);
        actor->tile = (uint8_t)word; actor->attributes = (uint8_t)(word >> 8u); actor->large = 1u;
    }
    return 1;
}

/* C9:4E3C -> command5A table9738 -> C0:BC51 -> C0:9391. Do not
 * confuse this span controller with the independent fleet bitmap0EA9.
 * Count0 is the real disable/publication tail; consumed OAM, not that
 * count, decides visibility. All geometry/tile/flip constraints remain
 * enforced by the renderer candidate and native-pixel reconciliation. */
static int sea_mast_controller(const NHCore *core) {
    unsigned count, start, span, period, mask, phase;
    return port_word(core, 0x7E0E97u, &count) && (count == 0u || count == 0xFFFFu) &&
        port_word(core, 0x7E0E99u, &start) && start == 108u &&
        port_word(core, 0x7E0E9Bu, &span) && span == 1u &&
        port_word(core, 0x7E0E9Du, &period) && period == 15u &&
        port_word(core, 0x7E0E9Fu, &mask) && mask == 2u &&
        port_word(core, 0x7E0EA1u, &phase) && phase < period;
}

int nh_core_read_sea_world(const NHCore *core, uint16_t *pixels,
                           uint32_t capacity, NHCoreSeaTerrainInfo *info) {
    NHCoreSeaTerrainInfo scene;
    NHSeaSource source;
    NHPortActor14 actors[86];
    uint8_t retired[70] = {0};
    uint8_t native_clip[86];
    unsigned order[86], count = 0u, fleet, player, own_seen = 0u, phase, control, own_model, b;
    uint8_t fleet_mode;
    int foreign_suppressed;
    const NHPPU11 *p;
    if (!nh_core_read_sea_terrain(core, pixels, capacity, &scene) ||
        !port_word(core, 0x7EE806u, &player) || !port_peek(core, 0x7E201Bu, &fleet_mode)) return 0;
    p = &core->ppu;
    /* C1:2828..285D selects own-only updates for weather other than0/2.
     * This suppresses NEW logical foreign fleets, not already consumed OAM.
     * C1:2A5A -> C2:160F clears them through the normal publication sequence. */
    foreign_suppressed = (fleet_mode & 15u) != 0u && (fleet_mode & 15u) != 2u;
    if (nh_ppu14_object_native_hidden(p, 108u) == 0 &&
        nh_ppu14_sea_mast_object(p, 108u) && !sea_mast_controller(core))
        return sea_refuse(core, 24u, 108u, 0u, 0u);
    /* Source C0:BC7F configures C0:93DF's16-byte bitmap controller. Current
     * Sea admits exactly slots113..127, XOR0002;112 is the non-animated HUD
     * ship. New-view fleets synchronize to this observed group's live pose,
     * not a fabricated offscreen execution/interpolation history. */
    sea_refuse(core, 10u, 0u, 0u, 0u);
    if (!port_word(core, 0x7E0EA7u, &control) || control != 2u ||
        !port_word(core, 0x7EA3A5u, &own_model) || own_model >= 4u) return 0;
    for (b = 0u; b < 16u; ++b) {
        uint8_t bitmap;
        unsigned expected = b < 14u ? 0u : b == 14u ? 0x7Fu : 0xFFu;
        if (!port_peek(core, 0x7E0EA9u + b, &bitmap) || bitmap != expected) return 0;
    }
    if (p->oam[454].known_mask != 255u || p->oam[455].known_mask != 255u ||
        !sea_model_word(p->oam[454].value | ((unsigned)p->oam[455].value << 8u),
            0x2800u, own_model)) return 0;
    phase = p->oam[454].value & 2u;
    source.core = core; source.count = 0u;
    for (b = 2u; b < 16u; ++b) {
        NHPortActor14 actor;
        unsigned retired_fleet;
        if (!sea_retired_actor(core, b, &scene, &actor, &retired_fleet)) continue;
        if (retired_fleet < 70u) {
            if (retired[retired_fleet]) return sea_refuse(core, 17u, b, retired_fleet, 0u);
            retired[retired_fleet] = 1u;
        }
        actors[count] = actor;
        /* Normal identity-free tails keep the established native-only policy.
         * During weather suppression no logical margin fleets are emitted:
         * retain the COMPLETE already-consumed finite sprite at its actual
         * screen pose, including its source pixels past the old raster edge. */
        native_clip[count] = retired_fleet == 255u && !foreign_suppressed ? 2u : 0u;
        order[count++] = b;
    }
    for (fleet = 0u; fleet < 70u; ++fleet) {
        unsigned table = 0xAD030u + fleet * 2u;
        unsigned record = core->rom[table] | ((unsigned)core->rom[table + 1u] << 8u);
        unsigned x, y, ship, kind, model, heading, expected, native_order, clip = 1u;
        uint8_t flags, owner, slot, reverse;
        int world_x, world_y, own = record == player;
        NHPortActor14 actor;
        sea_refuse(core, 11u, fleet, 0u, 0u);
        /* The visible old native sprite is already represented above. Do not
         * duplicate it using the same fleet's newer logical record. */
        if (retired[fleet]) continue;
        if (!port_peek(core, 0x7E0000u + record + 0x29u, &flags) ||
            !port_peek(core, 0x7E0000u + record + 0x2Au, &owner)) return 0;
        if (!own && (!(flags & 0x11u) || owner == 255u)) continue;
        if (!port_word(core, 0x7E0000u + record, &x) || x >= 2160u ||
            !port_word(core, 0x7E0000u + record + 2u, &y) || y >= 1080u) return 0;
        world_x = port_unwrap((int)x * 8, scene.native_origin_x + 128, 2160 * 8);
        world_y = (int)y * 8 - 3;
        /* Keep one native interpolation cell of slack before deciding absent. */
        if (world_x + 24 <= scene.origin_x || world_x - 8 >= scene.origin_x + 512 ||
            world_y + 24 <= scene.origin_y || world_y - 8 >= scene.origin_y + 288) continue;
        {
            uint8_t ship_id, ship_kind, direction;
            if (!port_peek(core, 0x7E0000u + record + 0x32u, &ship_id) || ship_id >= 90u ||
                !port_peek(core, 0x7E0000u + record + 0x1Au, &direction)) return 0;
            table = 0xAD0BCu + (unsigned)ship_id * 2u;
            ship = core->rom[table] | ((unsigned)core->rom[table + 1u] << 8u);
            if (!port_peek(core, 0x7E0000u + ship + 0x12u, &ship_kind) || ship_kind >= 25u) return 0;
            kind = ship_kind; heading = direction & 7u;
        }
        model = core->rom[0x2B6C9u + kind];
        if (model >= 4u) return 0;
        expected = (own ? 0x2800u : 0x2A00u) |
            (0xC0u + 64u * model + 4u * heading + (heading >= 4u ? 16u : 0u));
        if (!port_peek(core, 0x7EEA17u + fleet, &slot)) return 0;
        if (!own && foreign_suppressed && slot == 255u) continue;
        native_order = 16u + fleet;
        actor.tile = (uint8_t)(expected ^ phase); actor.attributes = (uint8_t)(expected >> 8u); actor.large = 1u;
        if (own) own_seen = 1u;
        if (slot != 255u) {
            unsigned descriptor, word, offset, raw_x, pair, n;
            int hidden;
            uint8_t packed[4];
            if (!slot || slot >= 16u || (own && slot != 1u) ||
                !port_peek(core, 0x7EEA5Du + slot, &reverse) || reverse != fleet) return 0;
            descriptor = 0x7EE937u + (unsigned)slot * 6u;
            if (!port_word(core, descriptor + 2u, &word) || (word & 2u) ||
                !sea_model_word(word, own ? 0x2800u : 0x2A00u, model)) return 0;
            offset = (112u + slot) * 4u;
            for (n = 0u; n < 4u; ++n) {
                if (p->oam[offset + n].known_mask != 255u) return 0;
                packed[n] = p->oam[offset + n].value;
            }
            offset = 512u + (112u + slot) / 4u;
            if (p->oam[offset].known_mask != 255u) return 0;
            pair = (p->oam[offset].value >> (((112u + slot) & 3u) * 2u)) & 3u;
            raw_x = packed[0] | ((pair & 1u) << 8u);
            hidden = nh_ppu14_object_native_hidden(p, 112u + slot);
            if (hidden < 0) return sea_refuse(core, 18u, slot, 0u, 0u);
            /* A different newly allocated fleet can share a slot whose
             * witnessed old pose is still consumed. The tail is drawn above;
             * the new source fleet has no native pose yet, so only its added-
             * margin projection is eligible until OAM actually changes. */
            if (!hidden && sea_retired_actor(core, slot, &scene, NULL, NULL)) hidden = 1;
            if (!hidden) {
                int actual_x = port_unwrap((int)raw_x + scene.native_origin_x, world_x, 512);
                int actual_y = port_unwrap((int)packed[1] + scene.native_origin_y, world_y, 256);
                int distant = actual_x - world_x < -16 || actual_x - world_x > 16 ||
                    actual_y - world_y < -16 || actual_y - world_y > 16;
                if (!(pair & 2u) || (own && distant && !p->port_ui->sea_camera_rebuilding) ||
                    !sea_model_word(packed[2] | ((unsigned)packed[3] << 8u),
                        own ? 0x2800u : 0x2A00u, model))
                    return sea_refuse(core, 12u, fleet,
                        (unsigned)((actual_x - world_x) & 0xFFFF),
                        (unsigned)((actual_y - world_y) & 0xFFFF));
                if (!own && foreign_suppressed) {
                    /* Positively mapped/model-qualified consumed sprite only.
                     * Pending fog can precede its actual clear by8 fields.
                     * Preserve exact consumed screen coordinates and pixels;
                     * do not project a logical fleet into fog's new margins.
                     * The full emitted16x16 primitive may cross the old edge;
                     * clipping its body there would leave a visible seam. */
                    world_x = (raw_x < 256u ? (int)raw_x : (int)raw_x - 512) +
                        scene.native_origin_x;
                    world_y = (packed[1] > 240u ? (int)packed[1] - 256 :
                        (int)packed[1]) + scene.native_origin_y;
                    actor.tile = packed[2]; actor.attributes = packed[3];
                    clip = 0u;
                } else if (distant) {
                    NHPortActor14 consumed = actor;
                    unsigned insert = count;
                    /* Native C2:0FD7/1171 descriptors and consumed OAM can
                     * lag several logical fleet steps (observed fleet4:24px).
                     * The16px proximity assumption was not source authority.
                     * Keep this EXACT positive fleet OBJ in its native
                     * footprint only; do not claim it is the current logical
                     * fleet position, extend its lag into margins, or snap it.
                     * Current qualified source position supplies margins,
                     * just as for a source fleet without consumed native OAM.
                     * At most15 such/native-tail poses supplement70 records. */
                    if (count >= 86u) return sea_refuse(core, 16u, count, own_seen, 0u);
                    consumed.world_x = (int16_t)((raw_x < 256u ? (int)raw_x : (int)raw_x - 512) + 128);
                    consumed.world_y = (int16_t)((packed[1] > 240u ? (int)packed[1] - 256 : (int)packed[1]) + 32);
                    consumed.tile = packed[2]; consumed.attributes = packed[3];
                    while (insert && order[insert - 1u] > slot) {
                        actors[insert] = actors[insert - 1u]; order[insert] = order[insert - 1u];
                        native_clip[insert] = native_clip[insert - 1u]; --insert;
                    }
                    actors[insert] = consumed; order[insert] = slot;
                    native_clip[insert] = 2u; ++count;
                    /* During the observed0A8D..0AB7 cache handoff, the own
                     * logical longitude can already wrap and consumed OAM use
                     * the next view while still displayed with old terrain.
                     * Preserve that exact native
                     * footprint only. Unlike foreign fleets, do NOT add a
                     * second logical flagship in a newly exposed margin. */
                    if (own) continue;
                    /* actor remains the current source model/position,
                     * clip1 below excludes its entire original viewport. */
                } else {
                    world_x = actual_x; world_y = actual_y;
                    actor.tile = packed[2]; actor.attributes = packed[3];
                    clip = 0u;
                }
            } else if (own || foreign_suppressed)
                continue; /* No native ship is consumed here yet. In particular,
                           * a newly allocated slot can still contain an old
                           * hidden fleet's OAM while its new shadow awaits DMA.
                           * Never unwrap that unrelated hidden pose as this
                           * fleet, nor invent its native-view appearance. */
            /* Outside the native view, hidden allocated and unallocated
             * fleets share the qualified current-source projection policy;
             * neither has consumed visible interpolation to preserve. */
            native_order = slot;
        } else {
            int visible;
            if (own || !sea_fleet_shore(&source, x, y, &visible)) return 0;
            if (!visible) continue;
            /* A native-culled fleet has no invented interpolation history.
             * Display its current source position/model using live VRAM. */
        }
        actor.world_x = (int16_t)(world_x - scene.origin_x);
        actor.world_y = (int16_t)(world_y - scene.origin_y);
        {
            unsigned insert = count;
            if (count >= 86u) return sea_refuse(core, 16u, count, own_seen, 0u);
            while (insert && order[insert - 1u] > native_order) {
                actors[insert] = actors[insert - 1u]; order[insert] = order[insert - 1u];
                native_clip[insert] = native_clip[insert - 1u]; --insert;
            }
            actors[insert] = actor; order[insert] = native_order;
            native_clip[insert] = (uint8_t)clip; ++count;
        }
    }
    if (!own_seen || !nh_ppu14_draw_sea_fleets(p, actors, native_clip, count, pixels, capacity))
        return sea_refuse(core, 16u, count, own_seen, 0u);
    if (info) *info = scene;
    return 1;
}

int nh_core_combat_terrain_info(const NHCore *core, NHCoreCombatTerrainInfo *info) {
    const NHPPU11 *p;
    unsigned n, origin_y;
    int scroll_x, scroll_y;
    uint8_t camera_x, camera_y;
    if (!assembled(core) || info == NULL) return 0;
    p = &core->ppu;
    if (!p->frame_ready || p->forced_blank || p->brightness == 0u ||
        p->interlace || p->overscan || p->published_height != 224u ||
        p->registers[5].known_mask != 255u || p->registers[5].value != 0x29u ||
        p->registers[8].known_mask != 255u || p->registers[8].value != 0x58u ||
        p->registers[11].known_mask != 255u || p->registers[11].value != 0x22u ||
        p->registers[0x2C].known_mask != 255u || !(p->registers[0x2C].value & 2u) ||
        p->bg_hofs[1].known_mask != 0x3FFu || p->bg_vofs[1].known_mask != 0x3FFu ||
        (p->bg_hofs[1].value >= 512u && p->bg_hofs[1].value < 1016u) ||
        (p->bg_vofs[1].value >= 512u && p->bg_vofs[1].value < 1016u) ||
        !port_peek(core, 0x7EF492u, &camera_x) || camera_x > 31u ||
        !port_peek(core, 0x7EF493u, &camera_y) || camera_y > 31u) return 0;
    for (n = 0u; n < 1024u; ++n) {
        uint8_t source;
        unsigned word, address = 0xB000u + n * 2u;
        if (!port_peek(core, 0x7EEC29u + n, &source)) return 0;
        /* CD:3158..31BD, called for each cell by CD:3B48. Values below80
         * include ship occupancy flags; those remain the sea tile, not land.
         * Do not use the reused 7F:8000 upload staging buffer as authority. */
        if (source == 0u) word = 0x1004u;
        else if (source < 0x80u) word = 0x1002u;
        else if (source <= 0x86u) word = 0x1002u + 2u * (source - 0x80u);
        else word = 0x1020u + 2u * (source - 0x87u);
        if (p->vram[address].known_mask != 255u ||
            p->vram[address + 1u].known_mask != 255u ||
            (unsigned)(p->vram[address].value |
                       ((unsigned)p->vram[address + 1u].value << 8u)) != word) return 0;
    }
    info->width = 512u; info->height = 288u;
    info->world_width = 512u; info->world_height = 512u;
    info->origin_x = 0u;
    /* Sample the consumed tile plane's phase, not a guessed camera*16.
     * Tactical sprite projection has its own CD:1EB4 offsets/stagger. */
    scroll_x = p->bg_hofs[1].value < 512u ? (int)p->bg_hofs[1].value :
               (int)p->bg_hofs[1].value - 1024;
    scroll_y = p->bg_vofs[1].value < 512u ? (int)p->bg_vofs[1].value :
               (int)p->bg_vofs[1].value - 1024;
    origin_y = scroll_y > 32 ? (unsigned)(scroll_y - 32) : 0u;
    info->origin_y = (uint16_t)(origin_y > 224u ? 224u : origin_y);
    info->native_scroll_x = (int16_t)scroll_x;
    info->native_scroll_y = (int16_t)scroll_y;
    info->camera_column = camera_x; info->camera_row = camera_y;
    info->ship_status_mode = 0u;
    return 1;
}

int nh_core_read_combat_terrain(const NHCore *core, uint16_t *pixels,
                                uint32_t capacity, NHCoreCombatTerrainInfo *info) {
    NHCoreCombatTerrainInfo scene;
    /* Despite its historical Port name, this helper only samples a bounded
     * 32x32 Mode1 BG2 plane. Combat source qualification stays separate. */
    if (!nh_core_combat_terrain_info(core, &scene) ||
        !nh_ppu14_read_port_terrain(&core->ppu, scene.origin_y, pixels, capacity)) return 0;
    if (info != NULL) *info = scene;
    return 1;
}

static int combat_source_ship_word(const NHCore *core, uint32_t address,
                                   unsigned ship, unsigned index, unsigned *result) {
    unsigned table, descriptor, model, heading, word;
    uint8_t type, appearance, direction;
    if (ship > 0xFFF8u || !port_peek(core, 0x7E0007u + ship, &type) ||
        !port_peek(core, address + 12u, &direction)) return 0;
    table = 0xAD0BCu + 2u * type; /* C5:0190 / CA:D0BC */
    descriptor = core->rom[table] | ((unsigned)core->rom[table + 1u] << 8u);
    if (descriptor > 0xFFEDu ||
        !port_peek(core, 0x7E0012u + descriptor, &appearance)) return 0;
    model = core->rom[0x2B6C9u + appearance];
    heading = core->rom[0xDCCBDu + direction % 6u];
    word = 0xC0u + 64u * model + 4u * heading + (heading >= 4u ? 16u : 0u);
    if (word > 0x1FFu) return 0;
    *result = word | (index < 20u ? 0x2A00u : 0x2800u);
    return 1;
}

static int combat_consumed_ship_phase(unsigned consumed, unsigned base) {
    unsigned pose = consumed & 0x3Du; /* Remove only native phase bit1. */
    /* CD:CCBD's six headings produce offsets0,4,12,32,36,44 inside each
     * 64-character model block. Permit an older emitted heading while the
     * source record is ahead of OAM; do not mistake that for lost animation.
     * The complete model/name/palette/priority must still match. */
    if ((consumed & 0xFFC0u) != (base & 0xFFC0u) ||
        (pose != 0u && pose != 4u && pose != 12u && pose != 32u && pose != 36u && pose != 44u))
        return -1;
    return (int)(consumed & 2u);
}

/* Direct source-frame contracts only; no stack byte-pattern search. Normalize
 * the four local bytes of CD:4B5A through its stack-neutral multiply, compare,
 * C2:19C9 input tail, or its own body. Optional native IRQ entry is exactly
 *00:8490 BEFORE its prologue. Every helper return/argument is verified. */
static int combat_effect_wait(const NHCore *core, unsigned *parent, unsigned *caller) {
    unsigned s = core->cpu.s, pc = core->cpu.pc, bank = core->cpu.pbr;
    unsigned ret, wait, wait_s;
    uint8_t saved_bank;
    if (core->cpu.e || s > 0x1FBFu) return 0;
    if (bank == 0u && pc == 0x8490u) {
        if (!port_word(core, s + 2u, &pc) || !port_peek(core, s + 4u, &saved_bank)) return 0;
        bank = saved_bank; s += 4u;
    }
    if (bank == 0xC1u && pc >= 0xFA20u && pc <= 0xFA6Bu) {
        if (!port_word(core, s + 1u, &ret) || ret != 0x4B82u ||
            !port_peek(core, s + 3u, &saved_bank) || saved_bank != 0xCDu) return 0;
        wait_s = s + 3u;
    } else if (bank == 0xC1u && pc >= 0xFE7Au && pc <= 0xFE83u) {
        if (!port_word(core, s + 1u, &ret) || ret != 0x4B8Au ||
            !port_peek(core, s + 3u, &saved_bank) || saved_bank != 0xCDu) return 0;
        wait_s = s + 3u;
    } else if (bank == 0xC1u && pc >= 0xFECBu && pc <= 0xFED3u) {
        if (!port_word(core, s + 1u, &ret) || ret != 0xFE7Du ||
            !port_peek(core, s + 3u, &saved_bank) || saved_bank != 0xC1u ||
            !port_word(core, s + 4u, &ret) || ret != 0x4B8Au ||
            !port_peek(core, s + 6u, &saved_bank) || saved_bank != 0xCDu) return 0;
        wait_s = s + 6u;
    } else if (bank == 0xC2u && pc >= 0x1A49u && pc <= 0x1A4Fu) {
        if (!port_word(core, s + 3u, &ret) || ret != 0x4B62u ||
            !port_peek(core, s + 5u, &saved_bank) || saved_bank != 0xCDu ||
            !port_word(core, s + 6u, &wait) || wait != 0u) return 0;
        wait_s = s + 7u;
    } else if (bank == 0xCDu && pc >= 0x4B64u && pc <= 0x4B98u) {
        unsigned adjustment = pc == 0x4B98u ? 4u : pc == 0x4B97u ? 2u : 0u;
        if (s < adjustment) return 0;
        wait_s = s - adjustment;
    } else return 0;
    if (wait_s > 0x1FB9u || !port_word(core, wait_s + 5u, &ret) ||
        !port_peek(core, wait_s + 7u, &saved_bank) || saved_bank != 0xCDu ||
        !port_word(core, wait_s + 8u, &wait) ||
        !((wait == 1u && (ret == 0x4FCDu || ret == 0x5241u)) ||
          (wait == 3u && ret == 0x57F2u))) return 0;
    *parent = wait_s + 9u; *caller = ret;
    return 1;
}

/* CD:4BD6 horizontal and vertical launch/muzzle effects. Cached parent31/33
 * are the endpoint used by47B2; newer positions must not replace that pose.
 *3E68 event loops have separate source visibility/timing and are not invented
 * merely because a ship is visible in the wider presentation. */
static int combat_culled_shot_effect(const NHCore *core,
    const NHCoreCombatTerrainInfo *scene, unsigned slot, NHPortActor14 *pose) {
    unsigned ret, parent, caller, direction_word, cached_x, cached_y, current_major, distance;
    uint8_t saved_bank, high;
    int direction, native_x, native_y, difference;
    unsigned angle;
    const NHPPU11 *p = &core->ppu;
    if (!combat_effect_wait(core, &parent, &caller) || caller == 0x57F2u) return 0;
    if (!port_word(core, parent + 0x3Bu, &ret) || ret != 0x540Fu ||
        !port_peek(core, parent + 0x3Du, &saved_bank) || saved_bank != 0xCDu ||
        !port_word(core, parent + 1u, &direction_word) ||
        (direction_word != 1u && direction_word != 65535u) ||
        !port_word(core, parent + 0x31u, &cached_x) || cached_x > 511u ||
        !port_word(core, parent + 0x33u, &cached_y) || cached_y > 519u ||
        !port_word(core, parent + (caller == 0x4FCDu ? 7u : 9u), &current_major) || current_major > 519u ||
        !port_word(core, parent + (caller == 0x4FCDu ? 0x13u : 0x15u), &distance) ||
        !distance || distance > 512u) return 0;
    direction = direction_word == 1u ? 1 : -1;
    difference = (int)(caller == 0x4FCDu ? cached_x : cached_y) - (int)current_major;
    if (slot == 1u) {
        angle = (unsigned)(8 * abs(difference)) / distance;
        if (angle >= 4u) return 0; /*47F7 unsigned >=4 skips the muzzle. */
        native_x = (int)cached_x - 16 * scene->camera_column + 8 + (caller == 0x4FCDu ? direction * 8 : 0);
        native_y = (int)cached_y - 16 * scene->camera_row;
    } else if (slot == 0u) {
        unsigned x, y, start_x, start_y, fraction;
        int draw_x, draw_y;
        /* CD:4773 folds eight path phases0..7 to0,1,2,3,3,2,1,0.
         * Cached native35/37 precede the slope-coordinate update before wait.
         * Keep the launch-cell exclusion, independently of viewport culling. */
        fraction = (unsigned)(8 * abs(difference)) / (distance + 1u);
        if (fraction > 7u || !port_word(core, parent + 0x35u, &x) ||
            !port_word(core, parent + 0x37u, &y) ||
            !port_word(core, parent + 3u, &start_x) || start_x > 511u ||
            !port_word(core, parent + 5u, &start_y) || start_y > 519u) return 0;
        native_x = x < 32768u ? (int)x : (int)x - 65536;
        native_y = y < 32768u ? (int)y : (int)y - 65536;
        draw_x = native_x + 16 * scene->camera_column - 8;
        draw_y = native_y + 16 * scene->camera_row - 8;
        if (draw_x < 0 || draw_x > 511 || draw_y < 0 || draw_y > 519) return 0;
        if (draw_x + 4 >= (int)start_x && draw_x + 4 < (int)start_x + 16 &&
            draw_y + 4 >= (int)start_y && draw_y + 4 < (int)start_y + 16) return 0;
        angle = fraction < 4u ? fraction : 7u - fraction;
    } else return 0;
    if (native_x >= 0 && native_x <= 240 && native_y >= 0 && native_y <= 240) return 0;
    /* Only replace source-cleared slots, never actual emitted poses. */
    if (p->oam[slot * 4u].known_mask != 255u || p->oam[slot * 4u].value != 0x80u ||
        p->oam[slot * 4u + 1u].known_mask != 255u || p->oam[slot * 4u + 1u].value != 0xF0u ||
        p->oam[512].known_mask != 255u) return 0;
    high = (uint8_t)((p->oam[512].value >> (slot * 2u)) & 3u);
    if (!(high & 1u)) return 0;
    pose->world_x = (int16_t)(native_x + scene->native_scroll_x);
    pose->world_y = (int16_t)(native_y + scene->native_scroll_y);
    pose->tile = (uint8_t)((slot ? 0x80u : 0x60u) + angle * 2u);
    pose->attributes = 0x3Cu; pose->large = 1u;
    return 1;
}

static void combat_native_cell(uint16_t expected[1024], unsigned cell, unsigned group,
                                unsigned camera_x, unsigned camera_y) {
    int tx = 1 + 2 * ((int)(cell % 32u) - (int)camera_x);
    int ty = 1 + 2 * ((int)(cell / 32u) - (int)camera_y) + (int)(cell & 1u);
    unsigned x, y;
    for (y = 0u; y < 2u; ++y) for (x = 0u; x < 2u; ++x) {
        int dx = tx + (int)x, dy = ty + (int)y;
        if (dx >= 0 && dx < 32 && dy >= 0 && dy < 32)
            expected[(unsigned)dy * 32u + (unsigned)dx] =
                (uint16_t)(0x3540u + group * 4u + y * 2u + x);
    }
}

/* Optional full-world legal/path overlay. Return0 for a different/overlaid
 * BG1 scene,1 after a qualified extension,-1 if a qualified glyph read fails.
 * C1:A3F2..A64A and CD:090B/CD:CC65 are the authority, not zero cost bytes.
 * A complete native1024-word join prevents stale flags from admitting a menu. */
static int combat_extend_movement_grid(const NHCore *core,
    const NHCoreCombatTerrainInfo *scene, uint16_t *pixels, uint32_t capacity) {
    const NHPPU11 *p = &core->ppu;
    uint16_t expected[1024] = {0}, path[10];
    uint8_t candidates[1024], groups[1024] = {0}, length, directions[10];
    unsigned n, x, y, origin, present = 0u;
    if (p->registers[7].known_mask != 255u || p->registers[7].value != 0x5Cu ||
        p->registers[0x31].known_mask != 255u || (p->registers[0x31].value & 1u) ||
        p->bg_hofs[0].known_mask != 0x3FFu || p->bg_hofs[0].value != 0u ||
        p->bg_vofs[0].known_mask != 0x3FFu || p->bg_vofs[0].value != 0u ||
        !port_peek(core, 0x7EF491u, &length) || length > 9u) return 0;
    for (n = 0u; n <= length; ++n) {
        unsigned cell;
        if (!port_word(core, 0x7EF473u + n * 2u, &cell) || cell >= 1024u ||
            !port_peek(core, 0x7EF487u + n, &directions[n]) || directions[n] > 5u) return 0;
        path[n] = (uint16_t)cell;
    }
    origin = path[length];
    for (n = 0u; n < 1024u; ++n) {
        unsigned word, address = 0xB800u + n * 2u;
        if (p->vram[address].known_mask != 255u || p->vram[address + 1u].known_mask != 255u ||
            !port_peek(core, 0x7F7000u + n, &candidates[n])) return 0;
        word = p->vram[address].value | ((unsigned)p->vram[address + 1u].value << 8u);
        if (word && (word < 0x3540u || word > 0x356Bu)) return 0;
        present += word != 0u;
        if ((candidates[n] & 0x10u) && n != origin)
            groups[n] = (uint8_t)((candidates[n] & 0x80u) ? 1u : 2u);
    }
    if (!present) return 0;
    /* Source native drawing loops15 columns by12 rows. Candidate flag10 is
     * tested before drawing; it is not inferred from a nonzero/zero cost. */
    for (y = scene->camera_row; y < 32u && y < (unsigned)scene->camera_row + 12u; ++y)
        for (x = scene->camera_column; x < 32u && x < (unsigned)scene->camera_column + 15u; ++x) {
            n = y * 32u + x;
            if (groups[n]) combat_native_cell(expected, n, groups[n] - 1u,
                scene->camera_column, scene->camera_row);
        }
    for (n = 1u; n <= length; ++n) {
        unsigned group = 5u + directions[n];
        combat_native_cell(expected, path[n], group, scene->camera_column, scene->camera_row);
        groups[path[n]] = (uint8_t)(group + 1u);
    }
    for (n = 0u; n < 1024u; ++n) {
        unsigned address = 0xB800u + n * 2u;
        unsigned word = p->vram[address].value | ((unsigned)p->vram[address + 1u].value << 8u);
        if (word != expected[n]) return 0;
    }
    for (n = 0u; n < 1024u; ++n) if (groups[n]) {
        int left = 8 + 16 * ((int)(n % 32u) - scene->camera_column) + scene->native_scroll_x;
        int top = 8 + 16 * ((int)(n / 32u) - scene->camera_row) +
                  8 * (int)(n & 1u) + scene->native_scroll_y - scene->origin_y;
        if (!nh_ppu14_draw_combat_cell(p, groups[n] - 1u, left, top, pixels, capacity)) return -1;
    }
    return 1;
}

typedef struct NHCombatShipStatus {
    uint16_t cell, crew;
    uint8_t hull, active, identity;
} NHCombatShipStatus;

/* CD:2374 prints hull above crew;24ED/2625 print a single lower line.
 * Native text may intentionally retain pre-hit values while source records
 * already contain damage. Qualify consumed glyph ownership/placement across
 * the ENTIRE BG3 map, never substitute the newer numeric values. Fixed R
 * information text lies outside these ship-relative anchors and fails this
 * join. This path preserves visible cached text; it does not infer hidden
 * ships' per-event cached values from their current records. */
static int combat_consumed_ship_status(const NHCore *core,
    const NHCoreCombatTerrainInfo *scene, const NHCombatShipStatus ships[40]) {
    const NHPPU11 *p = &core->ppu;
    uint8_t allowed[1024] = {0}; /*1=index,2=crew decimal,4=hull decimal*/
    uint16_t indices[1024] = {0};
    unsigned n, numeric = 0u;
    for (n = 0u; n < 40u; ++n) if (ships[n].active) {
        int col = (int)(ships[n].cell % 32u) - scene->camera_column;
        int row = (int)(ships[n].cell / 32u) - scene->camera_row;
        int tx = col * 2, ty = row * 2 + 1 + (int)(ships[n].cell & 1u);
        unsigned x, y, palette;
        if (col < 0 || col >= 15 || row < 0 || row >= 12) continue;
        palette = core->rom[0xDCC34u + ((ships[n].identity >> 6u) & 3u)];
        if (palette > 7u) return -1;
        if (tx + 1 < 32 && ty < 32) {
            unsigned pos = (unsigned)ty * 32u + (unsigned)tx + 1u;
            allowed[pos] |= 1u;
            indices[pos] = (uint16_t)(0x2360u | (palette << 10u) | (ships[n].identity & 15u));
        }
        for (y = 0u; y < 2u; ++y) for (x = 0u; x < 3u; ++x)
            if (tx + (int)x < 32 && ty + (int)y < 32)
                allowed[(unsigned)(ty + (int)y) * 32u + (unsigned)(tx + (int)x)] |=
                    (uint8_t)(4u | (y ? 2u : 0u));
    }
    for (n = 0u; n < 1024u; ++n) {
        unsigned address = 0xF800u + n * 2u, word;
        if (p->vram[address].known_mask != 255u || p->vram[address + 1u].known_mask != 255u) return 0;
        word = p->vram[address].value | ((unsigned)p->vram[address + 1u].value << 8u);
        if (!word) continue;
        if ((allowed[n] & 1u) && word == indices[n]) continue;
        if (((allowed[n] & 2u) && word >= 0x2770u && word <= 0x2779u) ||
            ((allowed[n] & 4u) && word >= 0x2B70u && word <= 0x2B79u)) { ++numeric; continue; }
        return 0;
    }
    if (!numeric) return 0;
    if (p->registers[9].known_mask != 255u || p->registers[9].value != 0x7Cu ||
        p->registers[0x31].known_mask != 255u || (p->registers[0x31].value & 4u) ||
        p->bg_hofs[2].known_mask != 0x3FFu || p->bg_hofs[2].value != 0u ||
        p->bg_vofs[2].known_mask != 0x3FFu || p->bg_vofs[2].value != 0u) return -1;
    return 3;
}

/* CD:24ED/2625 and their visibility wrappers emit three-column crew/hull
 * strings below ships. A complete BG3 join distinguishes those world labels
 * from the SAME digit font used inside fixed information windows. Never tag
 * all digit tiles as world provenance in the generic raster observer. */
static int combat_extend_ship_status(const NHCore *core,
    const NHCoreCombatTerrainInfo *scene, const NHCombatShipStatus ships[40],
    uint16_t *pixels, uint32_t capacity) {
    const NHPPU11 *p = &core->ppu;
    uint16_t expected[1024] = {0};
    unsigned n, mode = 0u, base;
    int text_camera_x, text_camera_y;
    for (n = 0u; n < 1024u; ++n) {
        unsigned address = 0xF800u + n * 2u, word, current;
        if (p->vram[address].known_mask != 255u || p->vram[address + 1u].known_mask != 255u) return 0;
        word = p->vram[address].value | ((unsigned)p->vram[address + 1u].value << 8u);
        if (!word) continue;
        if (word >= 0x2770u && word <= 0x2779u) current = 1u;
        else if (word >= 0x2B70u && word <= 0x2B79u) current = 2u;
        else return 0; /* Index labels/window text: not the all-fleet mode. */
        if (mode && mode != current) return 0;
        mode = current;
    }
    if (!mode) return 0;
    /*3739 shifts/repopulates the BG3 status plane while panning, whereas
     * F492/F493 retain the command camera. At a whole-cell consumed phase,
     * BG2's16*view-8 phase identifies the text producer's15x12 viewport.
     * Mid-cell frames may have an intentionally empty status plane; do not
     * substitute the old command camera or invent unconsumed label history. */
    if ((scene->native_scroll_x + 8) % 16 ||
        (scene->native_scroll_y + 8) % 16) return 0;
    text_camera_x = (scene->native_scroll_x + 8) / 16;
    text_camera_y = (scene->native_scroll_y + 8) / 16;
    if (p->registers[9].known_mask != 255u || p->registers[9].value != 0x7Cu ||
        p->registers[0x31].known_mask != 255u || (p->registers[0x31].value & 4u) ||
        p->bg_hofs[2].known_mask != 0x3FFu || p->bg_hofs[2].value != 0u ||
        p->bg_vofs[2].known_mask != 0x3FFu || p->bg_vofs[2].value != 0u) return -1;
    base = mode == 1u ? 0x2770u : 0x2B70u;
    for (n = 0u; n < 40u; ++n) if (ships[n].active) {
        int col = (int)(ships[n].cell % 32u) - text_camera_x;
        int row = (int)(ships[n].cell / 32u) - text_camera_y;
        int ty = row * 2 + 2 + (int)(ships[n].cell & 1u);
        unsigned value = mode == 1u ? ships[n].crew : ships[n].hull;
        unsigned i, divisor = 100u;
        if (value > 999u) return -1; /* %3d is a minimum width, not truncation. */
        for (i = 0u; i < 3u; ++i, divisor /= 10u) {
            int tx = col * 2 + (int)i;
            if (col >= 0 && col < 15 && row >= 0 && row < 12 &&
                tx >= 0 && tx < 32 && ty >= 0 && ty < 32 &&
                (value >= divisor || i == 2u))
                expected[(unsigned)ty * 32u + (unsigned)tx] = (uint16_t)(base + value / divisor % 10u);
        }
    }
    for (n = 0u; n < 1024u; ++n) {
        unsigned address = 0xF800u + n * 2u;
        if ((unsigned)(p->vram[address].value | ((unsigned)p->vram[address + 1u].value << 8u)) != expected[n])
            return 0; /* Check consumed mixed stats separately; a modal is not all-fleet text. */
    }
    for (n = 0u; n < 40u; ++n) if (ships[n].active) {
        /* CD:3C0C/3C19 starts BG2 at16*camera-8. CD:3739/39C1
         * then interpolates the view BEFORE3B3B commits F492/F493.
         * World anchors must not drift with that consumed scroll phase. */
        int left = 16 * (int)(ships[n].cell % 32u) - 8;
        int top = 16 * (int)(ships[n].cell / 32u) +
                  8 + 8 * (int)(ships[n].cell & 1u) - scene->origin_y;
        unsigned value = mode == 1u ? ships[n].crew : ships[n].hull;
        unsigned i, divisor = 100u;
        for (i = 0u; i < 3u; ++i, divisor /= 10u)
            if ((value >= divisor || i == 2u) &&
                !nh_ppu14_draw_combat_label(p, (uint16_t)(base + value / divisor % 10u),
                    left + (int)i * 8, top, pixels, capacity)) return -1;
    }
    return (int)mode;
}

int nh_core_read_combat_world(const NHCore *core, uint16_t *pixels,
                              uint32_t capacity, NHCoreCombatTerrainInfo *info,
                              uint64_t *unqualified_pose_slots) {
    NHCoreCombatTerrainInfo scene;
    NHPortActor14 actors[40];
    NHCombatShipStatus status_ships[40] = {{0}};
    uint8_t used[40] = {0};
    uint8_t owners[40] = {0}, groups[40] = {0};
    uint16_t label_entries[40] = {0};
    int16_t label_x[40] = {0}, label_y[40] = {0};
    int phases[4][2] = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}};
    int common_phase[2] = {-1, -1};
    uint32_t visited[40];
    unsigned fleet, count = 0u, visits = 0u, slot;
    uint64_t pending = 0u;
    unsigned animation_start, animation_count, animation_xor, flash_active, flash_xor;
    const NHPPU11 *p;
    if (!unqualified_pose_slots || !nh_core_combat_terrain_info(core, &scene)) return 0;
    p = &core->ppu;
    if (!(p->registers[3].known_mask & 0x80u) || (p->registers[3].value & 0x80u)) return 0;
    /* C0:9391 / 93DF controls. Never extrapolate unrelated tile/palette
     * effects as the source-proved two-frame ship cycle. */
    if (!port_word(core, 0x7E0E99u, &animation_start) ||
        !port_word(core, 0x7E0E9Bu, &animation_count) ||
        !port_word(core, 0x7E0E9Fu, &animation_xor) ||
        !port_word(core, 0x7E0EA3u, &flash_active) ||
        !port_word(core, 0x7E0EA7u, &flash_xor) ||
        animation_start != 80u || animation_count != 40u || animation_xor != 2u ||
        (flash_active && flash_xor != 2u)) return 0;
    memset(actors, 0, sizeof(actors));
    /* CD:1F0D: four ten-byte descriptors, with long heads. Actual nodes are
     * linked through +9, not a flat array of ten-byte ship records. */
    for (fleet = 0u; fleet < 4u; ++fleet) {
        unsigned node;
        uint8_t bank;
        if (!port_word(core, 0x7EF029u + fleet * 10u, &node) ||
            !port_peek(core, 0x7EF02Bu + fleet * 10u, &bank)) return 0;
        while (node || bank) {
            unsigned ship, cell, next, index, i, crew;
            uint8_t flags, identity, next_bank, hull;
            uint32_t address = ((uint32_t)bank << 16u) | node;
            if (bank != 0x7Eu || node > 0xFFE6u || visits == 40u) return 0;
            for (i = 0u; i < visits; ++i) if (visited[i] == address) return 0;
            visited[visits++] = address;
            if (!port_word(core, address + 2u, &ship) ||
                !port_word(core, address + 4u, &cell) || cell >= 1024u ||
                !port_word(core, address + 9u, &next) ||
                !port_peek(core, address + 11u, &next_bank) ||
                !port_peek(core, address + 14u, &flags) ||
                !port_peek(core, address + 15u, &identity) ||
                !port_word(core, 0x7E0000u + ship, &crew) ||
                !port_peek(core, 0x7E0002u + ship, &hull)) return 0;
            /* CD:0ACC selects40 OAM slots; CD:1F97..1FC4 applies source
             * activity checks independently of CD:1C57 native view culling. */
            index = 10u * ((identity >> 6u) & 3u) + (identity & 15u);
            if (index >= 40u || (identity & 15u) >= 10u || used[index]) return 0;
            used[index] = 1u;
            /* CD:1F97..1FA0 retains Y=2 after loading the ship pointer;
             * LDA ($0C),Y therefore tests HULL at record+2, not crew's low
             * byte at record+0. This is presentation activity, not a guest fix. */
            if (hull && !(flags & 0x40u)) {
                NHPortActor14 *actor = &actors[index];
                unsigned oam = 80u + index, pair, b, base_word, consumed_word;
                uint8_t packed[4];
                int hidden, cleared, hint_x, hint_y, world_x, world_y;
                /* Text writes follow linked-list/fleet traversal, not OAM
                 * slot order. Adjacent three-character labels can overlap. */
                status_ships[visits - 1u].active = 1u;
                status_ships[visits - 1u].cell = (uint16_t)cell;
                status_ships[visits - 1u].crew = (uint16_t)crew;
                status_ships[visits - 1u].hull = hull;
                status_ships[visits - 1u].identity = identity;
                for (b = 0u; b < 4u; ++b) {
                    if (p->oam[oam * 4u + b].known_mask != 255u) return 0;
                    packed[b] = p->oam[oam * 4u + b].value;
                }
                if (p->oam[512u + oam / 4u].known_mask != 255u) return 0;
                pair = (p->oam[512u + oam / 4u].value >> ((oam & 3u) * 2u)) & 3u;
                if (!combat_source_ship_word(core, address, ship, index, &base_word)) return 0;
                consumed_word = packed[2] | ((unsigned)packed[3] << 8u);
                owners[index] = (uint8_t)fleet;
                if (flash_active) {
                    uint8_t bits;
                    if (!port_peek(core, 0x7E0EA9u + oam / 8u, &bits)) return 0;
                    groups[index] = (uint8_t)((bits & (128u >> (oam & 7u))) != 0u);
                }
                /* An emitted appearance word remains useful as an animation
                 * reference even after C0:B99A clears only its XY. Placeholder
                 * words (e.g.0140) do not match this model/palette contract. */
                {
                    int phase = combat_consumed_ship_phase(consumed_word, base_word);
                    if (phase >= 0) {
                        if (phases[fleet][groups[index]] < 0) phases[fleet][groups[index]] = phase;
                        if (common_phase[groups[index]] < 0) common_phase[groups[index]] = phase;
                    }
                }
                hidden = nh_ppu14_object_native_hidden(p, oam);
                /* C0:B99A writes F080 to XY and ORs the X-high flag; it
                 * does NOT clear the previous LARGE bit or tile/attributes.
                 * Pair size alone therefore cannot identify a reused slot. */
                cleared = packed[0] == 0x80u && packed[1] == 0xF0u && (pair & 1u);
                if (hidden < 0 || (!hidden && !(pair & 2u))) return 0;
                /* During CD:3739 view interpolation, command55 can move a
                 * just-cleared slot by one4-pixel increment. C0:B99A writes
                 * raw(384,240); C0:9251 applies the signed1E00/1E80 deltas
                   * even to that clear pose. Recentring can consume two such
                   * increments before a ship re-emits (e.g.392,244 after the
                   * bottom-edge return). The bounded5x5 sentinel lattice
                 * is NOT a real emitted ship position (0CE4's15x12 view).
                 * These clear poses can survive3B3B's camera commit until
                 * redraw; equal command/consumed cameras do NOT invalidate
                 * them. Require fully native-hidden sentinel geometry;
                 * valid emitted/interpolating poses still win. */
                if (hidden && (pair & 1u)) {
                    unsigned raw_x = packed[0] | ((pair & 1u) << 8u);
                    if (raw_x >= 376u && raw_x <= 392u && !((raw_x - 376u) & 3u) &&
                        packed[1] >= 232u && packed[1] <= 248u && !((packed[1] - 232u) & 3u))
                        cleared = 1;
                }
                /* Source1EB4/0CE4 + initial BG2 phase16*camera-8
                 * yields these stable world anchors. During3739/39C1
                 * panning F492/F493 retain the OLD camera until3B3B;
                 * adding current scroll to that old camera would drift. */
                hint_x = 16 * (int)(cell % 32u);
                /* decode_object_read adds1 to raw OAMy; prepare_objects uses
                 * scanline+1, cancelling it. Published top is raw OAMy, just
                 * as in Port. CD:1EB4's source constant is7, not6. */
                hint_y = -1 + 16 * (int)(cell / 32u) + 8 * (int)(cell & 1u);
                if (hidden) {
                    unsigned palette = core->rom[0xDCC34u + ((identity >> 6u) & 3u)];
                    if (palette > 7u) return 0;
                    label_entries[index] = (uint16_t)(0x2360u | (palette << 10u) |
                                                       (identity & 15u));
                    label_x[index] = (int16_t)hint_x;
                    label_y[index] = (int16_t)(hint_y + 1 - scene.origin_y);
                }
                /* A real emitted sprite can be geometrically clipped; keep
                 * its pose unless it has the source clear-slot XY signature. */
                if (cleared || !(pair & 2u)) {
                    actor->tile = (uint8_t)base_word;
                    actor->attributes = (uint8_t)(base_word >> 8u);
                    actor->large = 1u; /* CD:0CE4 -> command09 flags2 */
                    world_x = hint_x; world_y = hint_y;
                    pending |= UINT64_C(1) << index;
                } else {
                    unsigned raw_x = packed[0] | ((pair & 1u) << 8u);
                    world_x = port_unwrap((int)raw_x + scene.native_scroll_x, hint_x, 512);
                    world_y = port_unwrap((int)packed[1] + scene.native_scroll_y, hint_y, 256);
                    if (abs(world_x - hint_x) > 32 || abs(world_y - hint_y) > 32) return 0;
                    actor->tile = packed[2]; actor->attributes = packed[3];
                    actor->large = (uint8_t)(pair >> 1u);
                }
                actor->world_x = (int16_t)world_x; actor->world_y = (int16_t)world_y;
                used[index] = 2u;
            }
            node = next; bank = next_bank;
        }
    }
    /* Offscreen extension policy: a never-emitted ship has no native pose to
     * preserve. Synchronize its source-derived model/heading with an observed
     * phase from the same fleet/effect group, then another fleet in that group.
     * This is NOT proof of a hypothetical native per-ship redraw history.
     * No valid reference means explicitly unfinished, never a guessed timer.
     * Actual emitted ship words are never replaced by this reconstruction. */
    for (slot = 0u; slot < 40u; ++slot) if (pending & (UINT64_C(1) << slot)) {
        int phase = phases[owners[slot]][groups[slot]];
        if (phase < 0) phase = common_phase[groups[slot]];
        if (phase >= 0) {
            actors[slot].tile ^= (uint8_t)phase;
            pending &= ~(UINT64_C(1) << slot);
        }
    }
    /* Native slot order, not fleet traversal order, owns equal-priority ties. */
    for (slot = 0u; slot < 40u; ++slot) {
        if (used[slot] == 2u) actors[count++] = actors[slot];
        else if (nh_ppu14_object_native_hidden(p, 80u + slot) != 1) return 0;
    }
    if (!count) return 0;
    if (!nh_ppu14_read_combat_world(p, scene.origin_y, actors, count, pixels, capacity)) return 0;
    if (combat_extend_movement_grid(core, &scene, pixels, capacity) < 0) return 0;
    for (slot = 2u; slot-- > 0u;) {
        if (nh_ppu14_combat_world_object(p, slot)) {
            unsigned pair = (p->oam[512].value >> (slot * 2u)) & 3u;
            unsigned raw_x = p->oam[slot * 4u].value | ((pair & 1u) << 8u);
            int left = (raw_x < 256u ? (int)raw_x : (int)raw_x - 512) + scene.native_scroll_x;
            int top = (int)p->oam[slot * 4u + 1u].value + scene.native_scroll_y - scene.origin_y;
            if (!nh_ppu14_draw_combat_object(p, slot, left, top, pixels, capacity)) return 0;
        } else {
            NHPortActor14 pose;
            if (combat_culled_shot_effect(core, &scene, slot, &pose) &&
                !nh_ppu14_draw_combat_pose(p, (uint16_t)(pose.tile | ((unsigned)pose.attributes << 8u)),
                    pose.world_x, pose.world_y - scene.origin_y, pixels, capacity)) return 0;
        }
    }
    {
        int status = combat_extend_ship_status(core, &scene, status_ships, pixels, capacity);
        if (!status) status = combat_consumed_ship_status(core, &scene, status_ships);
        if (status < 0) return 0;
        scene.ship_status_mode = (uint8_t)status;
    }
    /* Mixed cached stats qualify only the actual consumed glyphs. Retain
     * hidden index labels; do not invent hidden pre-hit numeric history. */
    for (slot = 0u; (scene.ship_status_mode == 0u || scene.ship_status_mode == 3u) && slot < 40u; ++slot)
        if (label_entries[slot] && !nh_ppu14_draw_combat_label(p, label_entries[slot],
            label_x[slot], label_y[slot], pixels, capacity)) return 0;
    *unqualified_pose_slots = pending;
    if (info) *info = scene;
    return 1;
}

/* C4:0B1E idle NPC producer plus retained native OAM interpolation poses.
 * Native visibility predicate C4:0AD0 is not an activity predicate: valid NPCs
 * outside its small rectangle must still appear in the widened town.
 * This is observational projection, never a write to guest camera or OAM. */
int nh_core_read_port_world(const NHCore *core, uint16_t *pixels,
                            uint32_t capacity, NHCorePortTerrainInfo *info) {
    NHCorePortTerrainInfo scene;
    NHPortActor14 actors[9];
    const NHPPU11 *p;
    unsigned camera_x, camera_y, player_x, player_y, base;
    uint8_t clock_half_hours;
    int night;
    unsigned slot, count = 0u;
    if (!nh_core_port_terrain_info(core, &scene) ||
        !port_word(core, 0x7E201Cu, &camera_x) ||
        !port_word(core, 0x7E201Eu, &camera_y) ||
        !port_word(core, 0x7E2020u, &player_x) ||
        !port_word(core, 0x7E2022u, &player_y) ||
        !port_word(core, 0x7EFC64u, &base) ||
        !port_peek(core, 0x7EA05Du, &clock_half_hours) || clock_half_hours > 48u ||
        camera_x > 31u || camera_y > 31u || player_x > 31u || player_y > 31u) return 0;
    /* C4:0586 selects night outside04:00..19:30. Both ordinary town draw
     * paths clear all ten slots (C3:A3ED/C4:37CB -> C4:0000), emit the player,
     * then C4:0B1E/C4:0D4B early-return through C4:2E6A at night. That routine
     * writes logical blocking records, not NPC sprites. Never resurrect those
     * records using the daytime attribute table. A mixed/other emitted batch
     * remains native until its source is qualified.48 is the midnight handoff. */
    night = clock_half_hours < 8u || clock_half_hours >= 40u;
    p = &core->ppu;
    /* Current batch uses fixed OAM order. Rotation needs its own composition
     * proof before it can be admitted, not an accidental new tie-break rule. */
    if (!(p->registers[3].known_mask & 0x80u) || (p->registers[3].value & 0x80u)) return 0;
    for (slot = 0u; slot < 10u; ++slot) {
        uint8_t packed[5], cell_x, cell_y, direction = 0u;
        unsigned b, index = 112u + slot, raw_x, pair;
        int hidden, world_x, world_y, hint_x, hint_y;
        NHPortActor14 actor;
        /* OAM is the consumed pose. EA6D is a reused command buffer and may
         * already contain next frame's pose while OAM still owns this one. */
        for (b = 0u; b < 4u; ++b) {
            if (p->oam[index * 4u + b].known_mask != 255u) return 0;
            packed[b] = p->oam[index * 4u + b].value;
        }
        if (p->oam[512u + index / 4u].known_mask != 255u) return 0;
        pair = (p->oam[512u + index / 4u].value >> ((index & 3u) * 2u)) & 3u;
        packed[4] = (uint8_t)pair;
        raw_x = packed[0] | ((pair & 1u) << 8u);
        /* C4:0000 creates small offscreen placeholders; C4:0074 emits every
         * real town actor LARGE. Animation updates packed16-bit positions:
         * Y can change F0->EE or carry into tile (00/02). Neither Y nor tile
         * remains a blank sentinel. Classify small placeholders by actual
         * native visibility: a wrapped X can still be hidden by its Y. */
        hidden = !(pair & 2u) && nh_ppu14_object_native_hidden(p, index) == 1;
        if (!hidden && !(pair & 2u)) return 0;
        if (night && slot != 0u) {
            if (!hidden) return 0;
            continue;
        }
        if (slot == 9u) { /* Special tenth slot not yet source-qualified. */
            if (!hidden) return 0;
            continue;
        }
        if (slot == 0u) {
            if (hidden || camera_x + player_x >= 32u || camera_y + player_y >= 32u) return 0;
            cell_x = (uint8_t)(camera_x + player_x);
            cell_y = (uint8_t)(camera_y + player_y);
        } else {
            if (!port_peek(core, 0x7E2024u + (slot - 1u) * 3u, &cell_x) ||
                !port_peek(core, 0x7E2025u + (slot - 1u) * 3u, &cell_y) ||
                !port_peek(core, 0x7E2026u + (slot - 1u) * 3u, &direction)) return 0;
            if (cell_x == 255u && cell_y == 255u && hidden) continue;
            /* C4:4B42..4B68 clears coordinate BYTES separately; C4:0AD0
             * culls out-of-map coordinates before any native actor emit.
             * A partially cleared/absent FF coordinate is NOT an idle NPC
             * to reconstruct. Whether read as255 or signed-1, its16px body
             * has no footprint in the finite512px town. Admit only the
             * actual hidden SMALL placeholder with an idle displacement
             * owner and an otherwise valid record. Never wrap it into town
             * or treat arbitrary32..254 coordinates as absent actors. */
            if (hidden && (cell_x == 255u || cell_y == 255u) &&
                (cell_x < 32u || cell_x == 255u) &&
                (cell_y < 32u || cell_y == 255u) && !(direction & 0xF8u)) {
                uint8_t moving;
                if (!port_peek(core, 0x7EFC8Au + (slot - 1u) * 3u, &moving) || moving) return 0;
                continue;
            }
            if (cell_x >= 32u || cell_y >= 32u || (direction & 0xF8u)) return 0;
        }
        hint_x = cell_x * 16; hint_y = cell_y * 16 - 9;
        if (hidden) {
            unsigned attributes, rom_offset;
            uint8_t moving;
            /* In this C4:0586-qualified normal branch, C4:0B1E's only skip
             * for valid NPC coordinates is native view culling. Destination
             * WRAM camera may already be ahead of the rendered camera; it is
             * NOT authority for deciding whether consumed OAM was culled. */
            if (!port_peek(core, 0x7EFC8Au + (slot - 1u) * 3u, &moving) || moving) return 0;
            if (direction & 4u) {
                attributes = 0x2B00u;
                rom_offset = 0x4BFE2u;
            } else {
                attributes = 0x2900u + (slot == 6u ? 0u : base);
                rom_offset = 0x4BFD6u + (slot - 1u) * 2u;
            }
            attributes += core->rom[rom_offset] | ((unsigned)core->rom[rom_offset + 1u] << 8u);
            if (direction & 1u) attributes += (direction & 3u) == 1u ? 4u : 0x4004u;
            else if ((direction & 3u) != 0u) attributes += 8u;
            actor.tile = (uint8_t)attributes;
            actor.attributes = (uint8_t)(attributes >> 8u);
            actor.large = 1u; /* C4:0074 emits pair2/3 for town actors. */
            /* Source world cells are camera-independent. Reapplying a newer
             * WRAM camera to an older PPU phase causes4..16px NPC jitter. */
            world_x = hint_x;
            world_y = hint_y;
        } else {
            world_x = port_unwrap((int)raw_x + scene.native_scroll_x, hint_x, 512);
            world_y = port_unwrap(packed[1] + scene.native_scroll_y, hint_y, 256);
            /* Keep the emitted sub-tile pose; never replace it with idle cell
             * coordinates just because a frame boundary cleared FC88. */
            if (world_x - hint_x < -32 || world_x - hint_x > 32 ||
                world_y - hint_y < -32 || world_y - hint_y > 32) return 0;
            actor.tile = packed[2]; actor.attributes = packed[3]; actor.large = (uint8_t)(pair >> 1u);
        }
        actor.world_x = (int16_t)world_x; actor.world_y = (int16_t)world_y;
        actors[count++] = actor;
    }
    if (!nh_ppu14_read_port_world(p, scene.origin_y, actors, count, pixels, capacity)) return 0;
    if (info) *info = scene;
    return 1;
}

static void chart_source_observe(NHCore *core) {
    NHPortUiCapture14 *ui=core->ppu.port_ui;
    uint8_t selection;
    unsigned stack;
    if (!ui) return;
    ui->chart_source_kind=255u;
    if (!assembled(core) || core->cpu.s>=0x08FAu ||
        !port_peek(core,0x7EFCB5u,&selection) || selection>1u) return;
    for (stack=(unsigned)core->cpu.s+1u; stack+3u<=0x0900u; ++stack) {
        uint8_t lo,hi,bank;
        if (!port_peek(core,stack,&lo) || !port_peek(core,stack+1u,&hi) ||
            !port_peek(core,stack+2u,&bank)) continue;
        if ((!selection && ((bank==0xC3u&&hi==0x9Fu&&lo==0xB9u) ||
             (bank==0xC4u&&hi==0x59u&&lo==0x77u) ||
             (bank==0xCEu&&hi==0x07u&&lo==0xB1u))) ||
            (selection && bank==0xCEu&&hi==0x19u&&lo==0x4Fu)) {
            ui->chart_source_kind=selection;
            return;
        }
    }
}

int nh_core_enable_port_ui_capture(NHCore *core, int enabled) {
    if (!snapshot_quiescent(core)) return 0;
    if (!enabled) {
        free(core->ppu.port_ui); core->ppu.port_ui = NULL;
        return 1;
    }
    if (!core->ppu.port_ui) {
        core->ppu.port_ui = (NHPortUiCapture14 *)calloc(1u, sizeof(*core->ppu.port_ui));
        if (core->ppu.port_ui) core->ppu.port_ui->chart_source_kind=255u;
    }
    return core->ppu.port_ui != NULL;
}

/* Group the actual selected native UI, not framebuffer colours or a guessed
 * game-mode byte. An 8px empty cell may separate a prompt/portrait from its
 * window, so join cells within two tile steps. Each joined widget receives
 * ONE translation, including OBJ cursors. Native edge gutters are8..16px:
 * the R location panel starts at16, while chat/status borders start at8.
 * A group reaching BOTH opposite edges remains centred on that axis; this
 * preserves full-height panels rather than stretching/splitting their text.
 * This is host presentation scratch, never guest/snapshot state. */
static void port_ui_anchors(const uint8_t tiles[32u * 28u],
                            uint16_t dx[32u * 28u], uint8_t dy[32u * 28u]) {
    uint8_t seen[32u * 28u] = {0};
    uint16_t queue[32u * 28u];
    unsigned start;
    for (start = 0u; start < 32u * 28u; ++start) {
        unsigned head = 0u, count = 0u, i, minx = 32u, maxx = 0u;
        unsigned miny = 28u, maxy = 0u;
        unsigned sources = 0u, shift_x = 128u, shift_y = 32u;
        if (!tiles[start] || seen[start]) continue;
        queue[count++] = (uint16_t)start; seen[start] = 1u;
        while (head < count) {
            unsigned cell = queue[head++], cx = cell % 32u, cy = cell / 32u;
            int nx, ny;
            if (cx < minx) minx = cx;
            if (cx > maxx) maxx = cx;
            if (cy < miny) miny = cy;
            if (cy > maxy) maxy = cy;
            sources |= tiles[cell];
            for (ny = (int)cy - 2; ny <= (int)cy + 2; ++ny)
                for (nx = (int)cx - 2; nx <= (int)cx + 2; ++nx) {
                    unsigned next;
                    if (nx < 0 || nx >= 32 || ny < 0 || ny >= 28) continue;
                    next = (unsigned)ny * 32u + (unsigned)nx;
                    if (!seen[next] && tiles[next]) {
                        seen[next] = 1u; queue[count++] = (uint16_t)next;
                    }
                }
        }
        if (sources == 2u && minx >= 24u && (maxy < 5u || miny >= 24u)) {
            shift_x = 256u; shift_y = maxy < 5u ? 0u : 64u;
        } else {
            if (minx <= 2u && maxx < 29u) shift_x = 0u;
            else if (minx > 2u && maxx >= 29u) shift_x = 256u;
            /* Row25 ends at207: the same16px edge gutter admitted on X.
             * CD:70AE -> C1:8106 also constructs the lower white message
             * at(x2,y18,width28,height6): its shorter frame/arrow ends BEFORE
             * row25, but shares the y18 origin of the taller C9:4F14 packet.
             * Anchor that actual whole lower-message group from its source
             * origin/width, not its text-dependent final row. Centred lists
             * and opposite-edge-spanning groups keep their old placement. */
            if (miny <= 2u && maxy < 25u) shift_y = 0u;
            else if (miny > 2u && (maxy >= 25u ||
                     (miny == 18u && minx == 2u && maxx == 29u))) shift_y = 64u;
        }
        for (i = 0u; i < count; ++i) {
            dx[queue[i]] = (uint16_t)shift_x;
            dy[queue[i]] = (uint8_t)shift_y;
        }
    }
}

int nh_core_read_port_frame(const NHCore *core, uint16_t *pixels,
                            uint32_t capacity, NHCorePortTerrainInfo *info) {
    NHCorePortTerrainInfo scene;
    const NHPortUiCapture14 *ui;
    uint16_t tile_dx[32u * 28u];
    uint8_t tile_dy[32u * 28u];
    unsigned x, y, buffer;
    if (!assembled(core) || !(ui = core->ppu.port_ui) ||
        ui->sequence != core->ppu.published_sequence ||
        !(ui->valid[ui->published]) || ui->dependent_math[ui->published] ||
        !nh_core_read_port_world(core, pixels, capacity, &scene)) return 0;
    buffer = ui->published;
    if (!ui->hud_only[buffer]) port_ui_anchors(ui->tiles[buffer], tile_dx, tile_dy);
    for (y = 0u; y < 224u; ++y) for (x = 0u; x < 256u; ++x) {
        unsigned dx = x + 128u, dy = y + 32u, offset = y * 256u + x;
        if (!(ui->masks[buffer][offset] & 3u)) continue;
        /* Walking HUD has a cheap exact fast path. Other widgets retain one
         * coherent translation across their text/backing/portrait/cursor. */
        if (ui->hud_only[buffer]) {
            dx = x + 256u;
            dy = y < 40u ? y : y + 64u;
        } else {
            unsigned tile = (y >> 3u) * 32u + (x >> 3u);
            dx = x + tile_dx[tile]; dy = y + tile_dy[tile];
        }
        pixels[dy * 512u + dx] = ui->pixels[buffer][offset];
    }
    if (info) *info = scene;
    return 1;
}

/* Sea has its own source-qualified OBJ ownership. Do not inherit Port's town
 * slots112..121 or Combat's80..119 ship convention. Selected high-priority BG1
 * windows and BG3 text stay whole UI groups; low-priority BG1/world weather is
 * explicitly unfinished rather than silently dragged into a menu margin. */
static unsigned sea_ui_mask(uint8_t provenance) {
    if (provenance & 0x80u) return 0u;
    if (provenance & 4u) return 3u;
    return provenance & 3u;
}

/* Source UI construction/clearing can straddle a native field. Validate every
 * LIVE fragment of the dedicated source group; cleared/hidden peers aren't
 * fabricated just to demand a completed widget. This changes no native OAM. */
static int sea_ui_partial_group(const NHCore *core, unsigned index,
    unsigned first, unsigned count, unsigned columns, unsigned base, unsigned phase_mask) {
    const NHPPU11 *p = &core->ppu;
    unsigned n, b, pair;
    int left, top;
    if (index < first || index >= first + count) return 0;
    for (b = 0u; b < 4u; ++b) if (p->oam[index * 4u + b].known_mask != 255u) return 0;
    left = (int)p->oam[index * 4u].value - (int)((index - first) % columns) * 8;
    top = (int)p->oam[index * 4u + 1u].value - (int)((index - first) / columns) * 8;
    if (left < 0 || top < 0 || left + (int)columns * 8 > 256 ||
        top + (int)((count + columns - 1u) / columns) * 8 > 224) return 0;
    for (n = 0u; n < count; ++n) {
        unsigned slot = first + n, word;
        int hidden = nh_ppu14_object_native_hidden(p, slot);
        if (hidden < 0) return 0;
        if (hidden) continue;
        for (b = 0u; b < 4u; ++b) if (p->oam[slot * 4u + b].known_mask != 255u) return 0;
        if (p->oam[512u + slot / 4u].known_mask != 255u) return 0;
        pair = (p->oam[512u + slot / 4u].value >> ((slot & 3u) * 2u)) & 3u;
        word = p->oam[slot * 4u + 2u].value | ((unsigned)p->oam[slot * 4u + 3u].value << 8u);
        if (pair || (word & ~phase_mask) != base + n ||
            p->oam[slot * 4u].value != (unsigned)left + n % columns * 8u ||
            p->oam[slot * 4u + 1u].value != (unsigned)top + n / columns * 8u) return 0;
    }
    return 1;
}

/* A source loop can publish a new prefix followed by an old suffix. Return
 * the prefix length (9 means unchanged), never accept a third/interleaved pose. */
static int sea_ui_radial_prefix(const int values[9], int maximum_step) {
    unsigned n, split = 9u;
    int next = values[0];
    for (n = 1u; n < 9u; ++n) {
        if (split == 9u && values[n] != values[0]) {
            int delta = values[n] - values[0];
            if (delta < -maximum_step || delta > maximum_step) return -1;
            split = n; next = values[n];
        }
        if (split != 9u && values[n] != next) return -1;
    }
    return (int)split;
}

/* C7:2F58 submits the nine-slot radial cursor to C1:85FB's56-step motion.
 * C1:E70D translates shadow OAM in index order, x THEN y per slot, marking
 * dirty0B27 only at E7D4. Native publication can therefore retain a partly
 * translated stencil. Its actual raster pixels are UI, not a world object.
 * Preserve them; do not require an invented atomic position for all9 pieces.
 * A complete24x24 widget fits232/200 coordinate ranges. Over55 interpolation
 * intervals its largest source step is ceil232/55=5, ceil200/55=4. */
static int sea_ui_radial_motion(const NHCore *core, unsigned index) {
    const NHPPU11 *p = &core->ppu;
    int left[9], top[9], phase[9], xsplit, ysplit;
    unsigned n, b;
    if (index >= 9u || p->registers[1].known_mask != 255u ||
        p->registers[1].value != 0u) return 0;
    for (n = 0u; n < 9u; ++n) {
        unsigned pair, word, base;
        if (nh_ppu14_object_native_hidden(p, n) != 0) return 0;
        for (b = 0u; b < 4u; ++b)
            if (p->oam[n * 4u + b].known_mask != 255u) return 0;
        if (p->oam[512u + n / 4u].known_mask != 255u) return 0;
        pair = (p->oam[512u + n / 4u].value >> ((n & 3u) * 2u)) & 3u;
        word = p->oam[n * 4u + 2u].value | ((unsigned)p->oam[n * 4u + 3u].value << 8u);
        base = word - n;
        /* EXACT five-item/two-blink source stencil, not arbitrary tile words.
         * Command09 can also publish a prefix of the next source blink/item. */
        if (pair || base < 0x3210u || base > 0x3261u ||
            (base - 0x3210u) % 9u) return 0;
        phase[n] = (int)((base - 0x3210u) / 9u);
        left[n] = (int)p->oam[n * 4u].value - (int)(n % 3u) * 8;
        top[n] = (int)p->oam[n * 4u + 1u].value - (int)(n / 3u) * 8;
        if (left[n] < 0 || left[n] > 232 || top[n] < 0 || top[n] > 200) return 0;
    }
    xsplit = sea_ui_radial_prefix(left, 5);
    ysplit = sea_ui_radial_prefix(top, 4);
    if (xsplit < 0 || ysplit < 0 || sea_ui_radial_prefix(phase, 9) < 0) return 0;
    /* E790 writes x before E7B9 writes y. At most ONE current slot can have
     * only x updated. A coordinate not changing has no observable split. */
    if (xsplit < 9 && ysplit < 9 &&
        (xsplit < ysplit || xsplit > ysplit + 1)) return 0;
    return 1;
}

static int sea_ui_object(const NHCore *core, unsigned index) {
    const NHPPU11 *p = &core->ppu;
    unsigned n;
    if (nh_ppu14_combat_ui_object(p, index)) return 1;
    if (sea_ui_radial_motion(core, index)) return 1;
    /* C2:6E8F/C6:032C's two four-word prompt phases; C7:1A87's nine
     * command-grid words; the adjacent second Yes/No group; C2:0F22 portrait. */
    if (index < 4u && sea_ui_partial_group(core, index, 0u, 4u, 2u, 0x3200u, 4u)) return 1;
    if (index < 18u && sea_ui_partial_group(core, index,
        index < 9u ? 0u : 9u, 9u, 3u, index < 9u ? 0x3210u : 0x3219u, 0u)) return 1;
    /* C7:2DBF/2E60 emits nine cursor words for five radial items and their
     * blink state:3200|(10+9*item+45*blink), item0..4,blink0/1. Source2D78
     * uploads exactly5A(90) tiles at10. This includes323D..3245, NOT an
     * arbitrary extra OBJ family or a guessed single observed frame. */
    if (index < 9u && p->oam[index * 4u + 2u].known_mask == 255u &&
        p->oam[index * 4u + 3u].known_mask == 255u) {
        unsigned word = p->oam[index * 4u + 2u].value |
            ((unsigned)p->oam[index * 4u + 3u].value << 8u);
        unsigned base = word - index;
        if (base >= 0x3210u && base <= 0x3261u && (base - 0x3210u) % 9u == 0u &&
            sea_ui_partial_group(core, index, 0u, 9u, 3u, base, 0u)) return 1;
    }
    if (index >= 50u && index < 80u &&
        sea_ui_partial_group(core, index, 50u, 30u, 5u, 0x37E0u, 0u)) return 1;
    /* C1:6572 uses C2:0FD7/1171 slot0, base3800, screen(200,64) for the
     * sailing-status panel's player ship. It is NOT a world fleet slot. */
    if (index == 112u) {
        unsigned model, pair, word;
        for (n = 0u; n < 4u; ++n) if (p->oam[448u + n].known_mask != 255u) return 0;
        if (p->oam[540].known_mask != 255u ||
            !port_word(core, 0x7EA3A5u, &model) || model >= 4u) return 0;
        pair = p->oam[540].value & 3u;
        word = p->oam[450].value | ((unsigned)p->oam[451].value << 8u);
        return pair == 2u && p->oam[448].value == 200u && p->oam[449].value == 64u &&
            !(word & 2u) && sea_model_word(word, 0x3800u, model);
    }
    return 0;
}

int nh_core_read_sea_frame(const NHCore *core, uint16_t *pixels,
                           uint32_t capacity, NHCoreSeaTerrainInfo *info) {
    NHCoreSeaTerrainInfo scene;
    const NHPortUiCapture14 *ui;
    uint8_t tiles[32u * 28u] = {0};
    uint16_t tile_dx[32u * 28u];
    uint8_t tile_dy[32u * 28u];
    unsigned x, y, buffer;
    /* A source-qualified chart belongs to its completed native publication,
     * even if the instruction crossing VBLANK has since changed map registers
     * or popped the UI caller. Never infer it from those later live registers. */
    if (assembled(core) && core->ppu.port_ui && core->ppu.port_ui->chart_valid &&
        core->ppu.port_ui->chart_sequence==core->ppu.published_sequence &&
        nh_ppu14_read_world_chart(&core->ppu,core->ppu.port_ui->chart_kind,pixels,capacity)) {
        if (info) { memset(info,0,sizeof(*info)); info->width=512u; info->height=288u; }
        return 1;
    }
    /* Shared C5:3D3D chart: Port/interior/Sea Start useFCB5=0; Select->Port
     * CE:194C usesFCB5=1 and adds the selected-port marker. The source reader
     * rejoins native composition and preserves both markers' OAM order.
     * Destination/story caller C8:5879 is not admitted by this join. */
    if (assembled(core) && core->cpu.s < 0x08FAu) {
        uint8_t selection;
        unsigned stack;
        if (port_peek(core,0x7EFCB5u,&selection) && selection<=1u)
            for (stack=(unsigned)core->cpu.s+1u; stack+3u<=0x0900u; ++stack) {
                uint8_t lo,hi,bank;
                if (!port_peek(core,stack,&lo) || !port_peek(core,stack+1u,&hi) ||
                    !port_peek(core,stack+2u,&bank)) continue;
                if (!((!selection && ((bank==0xC3u&&hi==0x9Fu&&lo==0xB9u) ||
                       (bank==0xC4u&&hi==0x59u&&lo==0x77u) ||
                       (bank==0xCEu&&hi==0x07u&&lo==0xB1u))) ||
                      (selection && bank==0xCEu&&hi==0x19u&&lo==0x4Fu))) continue;
                if (nh_ppu14_read_world_chart(&core->ppu,selection,pixels,capacity)) {
                    if (info) { memset(info,0,sizeof(*info)); info->width=512u; info->height=288u; }
                    return 1;
                }
                break;
            }
    }
    /* CE:0149 -> C5:C40B -> B8A8 persists across table construction,
     * ordering and Yes/No. Qualify source pixels as well as this parent;
     * the same Mode29 is also used by town/combat and is not a page ID. */
    if (assembled(core) && core->cpu.s < 0x08FAu) {
        static const uint8_t caller[] = {0x0Eu,0xC4u,0xC5u,0x4Cu,0x01u,0xCEu};
        unsigned stack;
        for (stack = (unsigned)core->cpu.s + 1u; stack + sizeof(caller) <= 0x0900u; ++stack) {
            unsigned j;
            for (j = 0u; j < sizeof(caller); ++j) {
                uint8_t value;
                if (!port_peek(core, stack + j, &value) || value != caller[j]) break;
            }
            if (j != sizeof(caller)) continue;
            if (nh_ppu14_read_rearrange(&core->ppu, pixels, capacity)) {
                if (info) { memset(info, 0, sizeof(*info)); info->width = 512u; info->height = 288u; }
                return 1;
            }
            break;
        }
    }
    /* CE:014F -> C5:80B2 Scrap keeps its two WORD locals before the
     * return to CE:0152, then the parent return to CE:0510. Local values
     * are fleet/menu state, not a fixed two-ship signature. */
    if (assembled(core) && core->cpu.s < 0x08F6u) {
        unsigned stack;
        for (stack = (unsigned)core->cpu.s + 1u; stack + 10u <= 0x0900u; ++stack) {
            static const uint8_t pattern[] = {0x52u,0x01u,0xCEu,0u,0u,0u,0u,0x10u,0x05u,0xCEu};
            unsigned j;
            for (j = 0u; j < sizeof(pattern); ++j) {
                uint8_t value;
                if (!port_peek(core, stack + j, &value) ||
                    ((j < 3u || j >= 7u) && value != pattern[j])) break;
            }
            if (j != sizeof(pattern)) continue;
            if (nh_ppu14_read_scrap_selector(&core->ppu, pixels, capacity) ||
                nh_ppu14_read_scrap_detail(&core->ppu, pixels, capacity)) {
                if (info) { memset(info, 0, sizeof(*info)); info->width = 512u; info->height = 288u; }
                return 1;
            }
            break;
        }
    }
    /* C8:3B8A/3CED draw the SAME C8:050F mode4 ship page as Scrap,
     * then C8:3B9B/3CFE retain it for Figurehead/Guns controls. Load Capacity
     * C8:3D7E/3D97/3DCC/3DD2/3E19 shares paper/page/message/quote/editor,
     * including the same C1:144C numeric ring at source-supplied positions.
     * Exact
     * paper/drawing/control returns cover drawing and its subsequent
     * controls. The common service return C4:61DB is not sufficient alone.
     * Reuse the full paper/tile/consumed-OBJ qualification; do not infer page
     * identity from Mode29, service name or a matching ship picture. */
    if (assembled(core) && core->cpu.s < 0x08FAu) {
        unsigned stack, page_caller = 0u, keyboard_caller = 0u, service_parent = 0u;
        unsigned moor_caller = 0u, moor_parent = 0u;
        unsigned used_parent = 0u, used_keyboard = 0u;
        for (stack = (unsigned)core->cpu.s + 1u; stack + 3u <= 0x0900u; ++stack) {
            uint8_t lo, hi, bank;
            if (!port_peek(core, stack, &lo) || !port_peek(core, stack + 1u, &hi) ||
                !port_peek(core, stack + 2u, &bank)) continue;
            if (bank == 0xC8u && hi == 0x3Bu && (lo == 0x74u || lo == 0x8Du || lo == 0x9Eu))
                page_caller = stack;
            if (bank == 0xC8u && ((hi == 0x3Cu && (lo == 0xD7u || lo == 0xF0u)) ||
                                 (hi == 0x3Du && lo == 0x01u)))
                page_caller = stack;
            if (bank == 0xC8u && ((hi == 0x3Du &&
                    (lo == 0x81u || lo == 0x9Au || lo == 0xCFu || lo == 0xD5u)) ||
                    (hi == 0x3Eu && lo == 0x1Cu)))
                page_caller = stack;
            if (bank == 0xC8u && hi == 0x3Eu &&
                (lo == 0xC1u || lo == 0xDAu || lo == 0xF7u || lo == 0xFCu))
                page_caller = stack; /* Rename paper/page/message/ack. */
            if (bank == 0xC8u && hi == 0x3Fu && lo == 0x2Cu)
                keyboard_caller = stack; /* C8:3F29 -> C9:429A. */
            /* C8:2A87 -> 137F owns BOTH Sell page calls1425/1538;
             * the second redraw follows a pending Commodore replacement.
             * Outer cargo/crew/price/decline callbacks retain that same page.
             * This admits presentation only; it never performs a sale or
             * substitutes missing target state. Full pixel grammar remains. */
            if (bank == 0xC8u && ((hi == 0x2Au &&
                    (lo == 0x8Au || lo == 0xA1u || lo == 0xADu || lo == 0xB5u ||
                     lo == 0xBAu || lo == 0xCDu || lo == 0xD9u || lo == 0xE1u ||
                     lo == 0xE6u || lo == 0xF0u || lo == 0xFCu)) ||
                    (hi == 0x2Bu && (lo == 0x13u || lo == 0x1Au || lo == 0x25u || lo == 0x2Au))))
                page_caller = stack;
            if (bank == 0xC4u && hi == 0x61u && lo == 0xDBu)
                service_parent = stack;
            /* Capital Harbor Moor's indirect table C2:FE2C selects Store
             * A48A or Commission A6B2. Both draw C8050F mode4 but use
             * Scrap's x176 confirmation, not the x184 transaction variant.
             * Require their exact paper/page/message/control returns AND
             * the shared AB78 Moor dispatcher parent; Exchange is not
             * admitted by this source join. Pixel/raster grammar still owns
             * acceptance, including staged construction and native exits. */
            if (bank == 0xC2u &&
                ((hi == 0xA5u && (lo == 0x58u || lo == 0x71u || lo == 0x83u ||
                                  lo == 0x8Eu || lo == 0x9Fu || lo == 0xAEu)) ||
                 (hi == 0xA7u && (lo == 0x8Fu || lo == 0xA8u || lo == 0xB3u ||
                                  lo == 0xC4u || lo == 0xD3u))))
                moor_caller = stack;
            if (bank == 0xC2u && hi == 0xABu && lo == 0x78u)
                moor_parent = stack;
            /* C8:27A3 supplies mode1 used-stock records to the SAME
             * ship-page producer. Its controls use C80000's x184YesNo.
             * C8:280C -> 19A1 retains this page for price/negotiation,
             * and C8:03D1 names the purchased ship with the shared keyboard.
             * The keyboard requires this actual Used Ship parent too; do
             * not admit other new-ship/story callers merely by C803D4. */
            if (bank == 0xC8u && hi == 0x27u &&
                (lo == 0x92u || lo == 0xA6u || lo == 0xCBu || lo == 0xD0u ||
                 lo == 0xD7u || lo == 0xDCu))
                page_caller = stack;
            if (bank == 0xC8u && hi == 0x28u && lo == 0x0Fu) {
                page_caller = stack;
                used_parent = stack;
            }
            if (bank == 0xC8u && hi == 0x03u && lo == 0xD4u)
                used_keyboard = stack;
        }
        if (used_keyboard && used_parent > used_keyboard && service_parent > used_parent &&
            (nh_ppu14_read_ship_name(&core->ppu, pixels, capacity) ||
             nh_ppu14_read_ship_transaction(&core->ppu, pixels, capacity))) {
            if (info) { memset(info, 0, sizeof(*info)); info->width = 512u; info->height = 288u; }
            return 1;
        }
        if (moor_caller && moor_parent > moor_caller && service_parent > moor_parent &&
            nh_ppu14_read_scrap_detail(&core->ppu, pixels, capacity)) {
            if (info) { memset(info, 0, sizeof(*info)); info->width = 512u; info->height = 288u; }
            return 1;
        }
        if (keyboard_caller && service_parent > keyboard_caller &&
            (nh_ppu14_read_ship_name(&core->ppu, pixels, capacity) ||
             nh_ppu14_read_ship_transaction(&core->ppu, pixels, capacity))) {
            if (info) { memset(info, 0, sizeof(*info)); info->width = 512u; info->height = 288u; }
            return 1;
        }
        if (page_caller && service_parent > page_caller &&
            nh_ppu14_read_ship_transaction(&core->ppu, pixels, capacity)) {
            if (info) { memset(info, 0, sizeof(*info)); info->width = 512u; info->height = 288u; }
            return 1;
        }
    }
    /* Own Fleet Info CE:0143 -> C5:380C. This active return/parent chain
     * persists during the source's staged header/ship drawing and fades.
     * It is NOT foreign View, real Sea terrain, or a generic Mode1 bypass. */
    if (assembled(core) && core->cpu.s < 0x08F4u) {
        static const uint8_t caller[] = {0x46u,0x01u,0xCEu,0u,0u,1u,0u,0x10u,0x05u,0xCEu};
        unsigned stack;
        for (stack = (unsigned)core->cpu.s + 1u; stack + sizeof(caller) <= 0x0900u; ++stack) {
            unsigned j;
            for (j = 0u; j < sizeof(caller); ++j) {
                uint8_t value;
                if (!port_peek(core, stack + j, &value) || value != caller[j]) break;
            }
            if (j != sizeof(caller)) continue;
            if (nh_ppu14_read_ship_info(&core->ppu, pixels, capacity) ||
                nh_ppu14_read_own_fleet(&core->ppu, pixels, capacity)) {
                if (info) { memset(info, 0, sizeof(*info)); info->width = 512u; info->height = 288u; }
                return 1;
            }
            break;
        }
    }
    /* CD:723A builds C5:1479's character card, then CD:7241 independently
     * asks Yes/No. The common Battle wrapper remains active across BOTH
     * construction and confirmation. Complete tile/OBJ/raster qualification
     * distinguishes this page from its selector and any stale Sea objects.
     * Other shared character-info callers are not certified by this route. */
    if (assembled(core) && core->cpu.s < 0x08FAu) {
        static const uint8_t caller[] = {0x09u,0xC4u,0xC5u,0xD7u,0x05u,0xCEu};
        unsigned stack;
        for (stack = (unsigned)core->cpu.s + 1u; stack + sizeof(caller) <= 0x0900u; ++stack) {
            unsigned j;
            for (j = 0u; j < sizeof(caller); ++j) {
                uint8_t value;
                if (!port_peek(core, stack + j, &value) || value != caller[j]) break;
            }
            if (j != sizeof(caller)) continue;
            if (nh_ppu14_read_character_card(&core->ppu, pixels, capacity)) {
                if (info) { memset(info, 0, sizeof(*info)); info->width = 512u; info->height = 288u; }
                return 1;
            }
            break;
        }
    }
    /* Actual View wrapper CE:05B3 -> C5:C386 -> C5:A1B2 remains on the
     * active native stack during its finite page. The tile/OBJ/raster qualifier
     * additionally distinguishes page phases from the SAME handler's selector.
     * No bus read, machine update, saved flag or general Mode1 guard waiver. */
    if (assembled(core) && core->cpu.s < 0x08FAu) {
        static const uint8_t caller[] = {0x89u,0xC3u,0xC5u,0xB6u,0x05u,0xCEu};
        unsigned stack;
        for (stack = (unsigned)core->cpu.s + 1u; stack + sizeof(caller) <= 0x0900u; ++stack) {
            unsigned j;
            for (j = 0u; j < sizeof(caller); ++j) {
                uint8_t value;
                if (!port_peek(core, stack + j, &value) || value != caller[j]) break;
            }
            if (j != sizeof(caller)) continue;
            /* Same existing Sea bitmap controller, now consumed by finite
             * information-strip sprites. Prove XOR0002 and its exact bitmap
             * rather than accepting a second tile merely from its appearance. */
            {
                unsigned control, bit;
                if (!port_word(core, 0x7E0EA7u, &control) || control != 2u) break;
                for (bit = 0u; bit < 16u; ++bit) {
                    uint8_t value;
                    unsigned expected = bit < 14u ? 0u : bit == 14u ? 0x7Fu : 0xFFu;
                    if (!port_peek(core, 0x7E0EA9u + bit, &value) || value != expected) break;
                }
                if (bit != 16u) break;
            }
            if (nh_ppu14_read_fleet_page(&core->ppu, pixels, capacity)) {
                if (info) { memset(info, 0, sizeof(*info)); info->width = 512u; info->height = 288u; }
                return 1;
            }
            break;
        }
    }
    if (!assembled(core) || !(ui = core->ppu.port_ui) ||
        ui->sequence != core->ppu.published_sequence || !ui->valid[ui->published] ||
        ui->frame_mode[ui->published] != 0x09u ||
        !nh_core_read_sea_world(core, pixels, capacity, &scene)) return 0;
    for (x = 0u; x < 128u; ++x) {
        int hidden = nh_ppu14_object_native_hidden(&core->ppu, x);
        if (hidden < 0) return 0;
        if (hidden) continue;
        if (nh_ppu14_sea_destination_object(&core->ppu, x)) continue;
        if (nh_ppu14_sea_mast_object(&core->ppu, x)) {
            if (!sea_mast_controller(core)) return sea_refuse(core, 24u, x, 0u, 0u);
            continue;
        }
        if (nh_ppu14_sea_marker_object(&core->ppu, x)) {
            if (!ui->sea_marker_qualified) return sea_refuse(core, 21u, x, 1u, 0u);
            continue;
        }
        if (nh_ppu14_sea_world_object(&core->ppu, x)) {
            uint8_t fleet = 255u, reverse;
            unsigned slot = x - 112u;
            if (sea_retired_actor(core, slot, &scene, NULL, NULL)) continue;
            if (!port_peek(core, 0x7EEA5Du + slot, &fleet) || fleet >= 70u ||
                !port_peek(core, 0x7EEA17u + fleet, &reverse) || reverse != slot)
                return sea_refuse(core, 13u, x, slot, fleet);
            continue;
        }
        /* C2:0F22/6E8F's common portrait and prompt producers are shared
         * source UI, not a blanket acceptance of all non-fleet sprites. */
        if (!sea_ui_object(core, x)) return sea_refuse(core, 14u, x, 0u, 0u);
    }
    buffer = ui->published;
    for (y = 0u; y < 224u; ++y) for (x = 0u; x < 256u; ++x) {
        unsigned offset = y * 256u + x;
        uint8_t provenance = ui->masks[buffer][offset];
        unsigned mask = sea_ui_mask(provenance);
        if ((provenance & 0x40u) || (provenance & 0x20u))
            return sea_refuse(core, 15u, offset, mask, provenance);
        if (ui->sea_mosaic_fringe[buffer][offset >> 3u] & (1u << (offset & 7u))) {
            if (ui->sea_mosaic[buffer] != 0x22u || mask ||
                (provenance & 4u) || !(provenance & 8u))
                return sea_refuse(core, 23u, offset, 0x22u, provenance);
            /* Keep the actual native BG2 pixel which sampled under a masked
             * native gutter. Only this witnessed footprint is authoritative;
             * added margins still use genuine global source terrain. The
             * ordinary pixel equality check below remains mandatory. */
            pixels[(y + 32u) * 512u + x + 128u] = ui->pixels[buffer][offset];
        }
        /* Every actually selected native BG2/fleet pixel must survive the
         * extended composition exactly. This also rejects an unqualified
         * palette/raster change or a wrongly applied fixed-color style.
         * Masked gutters are deliberately filled with newly exposed world,
         * so they are not treated as a required native black border. */
        if ((provenance & (8u | 0x80u)) && !mask &&
            pixels[(y + 32u) * 512u + x + 128u] != ui->pixels[buffer][offset])
            return sea_refuse(core, 20u, offset, ui->pixels[buffer][offset],
                pixels[(y + 32u) * 512u + x + 128u]);
        if (mask) tiles[(y >> 3u) * 32u + (x >> 3u)] |= (uint8_t)(1u << (mask - 1u));
    }
    port_ui_anchors(tiles, tile_dx, tile_dy);
    for (y = 0u; y < 224u; ++y) for (x = 0u; x < 256u; ++x) {
        unsigned offset = y * 256u + x, tile, dx, dy;
        if (!sea_ui_mask(ui->masks[buffer][offset])) continue;
        tile = (y >> 3u) * 32u + (x >> 3u);
        dx = x + tile_dx[tile]; dy = y + tile_dy[tile];
        pixels[dy * 512u + dx] = ui->pixels[buffer][offset];
    }
    if (info) *info = scene;
    sea_refuse(core, 0u, 0u, 0u, 0u);
    return 1;
}

/* Combat's BG1 legal/selected-cell markers are world fragments. They must
 * not merge into command windows merely because both happen to use BG1.
 * Additional OBJ provenance also restores non-ship slots112..121 which the
 * Port-specific low-bit convention intentionally omits. */
static unsigned combat_ui_mask(uint8_t provenance, unsigned ship_status_mode) {
    if (provenance & (8u | 0xC0u)) return 0u;
    if (ship_status_mode && (provenance & 3u) == 2u) return 0u;
    if (provenance & 4u) return 3u;
    return provenance & 3u;
}

int nh_core_read_combat_frame(const NHCore *core, uint16_t *pixels,
                              uint32_t capacity, NHCoreCombatTerrainInfo *info,
                              uint64_t *unqualified_pose_slots) {
    NHCoreCombatTerrainInfo scene;
    const NHPortUiCapture14 *ui;
    uint8_t tiles[32u * 28u] = {0};
    uint16_t tile_dx[32u * 28u];
    uint8_t tile_dy[32u * 28u];
    uint64_t pending;
    unsigned x, y, buffer;
    if (!unqualified_pose_slots || !assembled(core) || !(ui = core->ppu.port_ui) ||
        ui->sequence != core->ppu.published_sequence || !ui->valid[ui->published] ||
        !nh_core_read_combat_world(core, pixels, capacity, &scene, &pending)) return 0;
    /* Active non-ship OBJ effects need source-specific world/UI ownership;
     * never move them as menus merely because their slot is not a ship. */
    for (x = 0u; x < 128u; ++x) {
        const NHPPU11 *p = &core->ppu;
        int world_x, world_y, column;
        unsigned raw_x;
        if ((x >= 80u && x <= 119u) || nh_ppu14_object_native_hidden(p, x) == 1) continue;
        if (nh_ppu14_combat_ui_object(p, x)) continue;
        /* This is a positive source-word/size/grid check, not permission to
         * treat arbitrary slot0 inventory/portrait/effect sprites as world. */
        if (!nh_ppu14_combat_world_object(p, x)) return 0;
        /* Only the cell cursor has the staggered-grid invariant. Camera-
         * relative firing/impact effects move between cells at pixel scale. */
        if (x != 0u || p->oam[3].value != 0x32u) continue;
        raw_x = p->oam[0].value | ((unsigned)(p->oam[512].value & 1u) << 8u);
        world_x = (raw_x < 256u ? (int)raw_x : (int)raw_x - 512) + scene.native_scroll_x;
        world_y = (int)p->oam[1].value + scene.native_scroll_y;
        if (world_x < 0 || world_x >= 512 || (world_x & 15)) return 0;
        column = world_x / 16;
        if (world_y < -1 || world_y >= 512 || ((world_y + 1 - 8 * (column & 1)) & 15)) return 0;
    }
    buffer = ui->published;
    for (y = 0u; y < 224u; ++y) for (x = 0u; x < 256u; ++x) {
        unsigned offset = y * 256u + x;
        const uint8_t provenance = ui->masks[buffer][offset];
        const unsigned mask = combat_ui_mask(provenance, scene.ship_status_mode);
        /* Captured UI/fixed-color math can move intact. A subscreen-dependent
         * fragment or a world layer requiring unimplemented math cannot. */
        if ((mask && (provenance & 0x20u)) ||
            (!mask && !(provenance & 0xC0u) && (provenance & 0x10u)) ||
            ((provenance & 0xC0u) && (provenance & 0x20u))) return 0;
        if (mask) tiles[(y >> 3u) * 32u + (x >> 3u)] |= (uint8_t)(1u << (mask - 1u));
    }
    port_ui_anchors(tiles, tile_dx, tile_dy);
    /* Preserve native world-marker placement before adding edge-anchored UI.
     * No pad, camera, movement range, collision or guest map is rewritten. */
    for (y = 0u; y < 224u; ++y) for (x = 0u; x < 256u; ++x) {
        unsigned offset = y * 256u + x;
        int dx, dy;
        /* Full objects were sampled at rank10 before rank11 labels. Copying
         * their old visible fragments again could overwrite a newly exposed
         * higher-priority label near the original viewport boundary. */
        if (ui->masks[buffer][offset] & 0x80u) continue;
        if (!(ui->masks[buffer][offset] & 0xC0u) &&
            !(scene.ship_status_mode && (ui->masks[buffer][offset] & 3u) == 2u)) continue;
        dx = (int)x + scene.native_scroll_x - scene.origin_x;
        dy = (int)y + scene.native_scroll_y - scene.origin_y;
        if (dx >= 0 && dx < 512 && dy >= 0 && dy < 288)
            pixels[(unsigned)dy * 512u + (unsigned)dx] = ui->pixels[buffer][offset];
    }
    for (y = 0u; y < 224u; ++y) for (x = 0u; x < 256u; ++x) {
        unsigned offset = y * 256u + x, tile, dx, dy;
        if (!combat_ui_mask(ui->masks[buffer][offset], scene.ship_status_mode)) continue;
        tile = (y >> 3u) * 32u + (x >> 3u);
        dx = x + tile_dx[tile]; dy = y + tile_dy[tile];
        pixels[dy * 512u + dx] = ui->pixels[buffer][offset];
    }
    *unqualified_pose_slots = pending;
    if (info) *info = scene;
    return 1;
}

size_t nh_core_pcm_drain(NHCore *core, int16_t *stereo, uint8_t *known,
                         size_t capacity) {
    return assembled(core) ? nh_sdsp16_pcm_drain(&core->sdsp, stereo, known,
                                                  capacity) : 0u;
}

NHCoreStatus nh_core_encode_sram(const NHCore *core, uint8_t *file,
                                 size_t size, uint64_t *generation) {
    if (!assembled(core)) return NH_CORE_BAD_ARGUMENT;
    return nh_sram_file_encode(&core->storage.bus.memory, file, size,
        generation) == NH_MEMORY_OK ? NH_CORE_OK : NH_CORE_MEMORY_FAILURE;
}

int nh_core_ack_sram_flush(NHCore *core, uint64_t generation) {
    return assembled(core) &&
        nh_memory_ack_sram_flush(&core->storage.bus.memory, generation);
}

int nh_core_sram_dirty(const NHCore *core) {
    return assembled(core) && core->storage.bus.memory.sram_dirty != 0u;
}

size_t nh_core_snapshot_size(const NHCore *core) {
    if (!snapshot_quiescent(core) ||
        sizeof(NHCoreSnapshotHeader17) > SIZE_MAX - sizeof(NHCore)) return 0u;
    return sizeof(NHCoreSnapshotHeader17) + sizeof(NHCore);
}

int nh_core_save_snapshot(const NHCore *core, void *destination, size_t size) {
    NHCoreSnapshotHeader17 header;
    NHCore *copy;
    uint8_t *bytes = (uint8_t *)destination;
    size_t expected = nh_core_snapshot_size(core);
    if (destination == NULL || expected == 0u || size != expected) return 0;
    copy = (NHCore *)malloc(sizeof(*copy));
    if (copy == NULL) return 0;
    memcpy(copy, core, sizeof(*copy));
    clear_snapshot_bindings(copy);
    memset(&header, 0, sizeof(header));
    memcpy(header.magic, "NHSNAP17", 8u);
    header.version = NH_CORE_SNAPSHOT_VERSION;
    header.header_size = (uint32_t)sizeof(header);
    header.state_size = (uint64_t)sizeof(*copy);
    header.state_hash = snapshot_hash((const uint8_t *)copy, sizeof(*copy));
    header.pointer_size = (uint8_t)sizeof(void *);
    header.size_t_size = (uint8_t)sizeof(size_t);
    if (nh_sha256_bytes(core->rom, NH_CORE_ROM_BYTES, header.rom_sha256) == 0) {
        free(copy);
        return 0;
    }
    memcpy(header.build_sha256, nh_v17_build_identity_sha256,
           sizeof(header.build_sha256));
    memcpy(bytes, &header, sizeof(header));
    memcpy(bytes + sizeof(header), copy, sizeof(*copy));
    free(copy);
    return 1;
}

int nh_core_load_snapshot(NHCore *core, const void *source, size_t size) {
    NHCoreSnapshotHeader17 header;
    NHCore *candidate = NULL, *bindings = NULL;
    uint8_t digest[32];
    const uint8_t *bytes = (const uint8_t *)source;
    size_t expected;
    int ok = 0;
    if (!snapshot_quiescent(core) || source == NULL) return 0;
    expected = sizeof(header) + sizeof(NHCore);
    if (size != expected) return 0;
    memcpy(&header, bytes, sizeof(header));
    if (memcmp(header.magic, "NHSNAP17", 8u) != 0 ||
        header.version != NH_CORE_SNAPSHOT_VERSION ||
        header.header_size != sizeof(header) ||
        header.state_size != sizeof(NHCore) ||
        header.pointer_size != sizeof(void *) ||
        header.size_t_size != sizeof(size_t) ||
        nh_sha256_bytes(core->rom, NH_CORE_ROM_BYTES, digest) == 0 ||
        memcmp(header.rom_sha256, digest, sizeof(digest)) != 0 ||
        !snapshot_build_compatible(header.build_sha256))
        return 0;
    candidate = (NHCore *)malloc(sizeof(*candidate));
    bindings = (NHCore *)malloc(sizeof(*bindings));
    if (candidate == NULL || bindings == NULL) goto cleanup;
    memcpy(candidate, bytes + sizeof(header), sizeof(*candidate));
    if (header.state_hash != snapshot_hash((const uint8_t *)candidate,
                                            sizeof(*candidate)) ||
        !snapshot_state_valid(candidate)) goto cleanup;
    memcpy(bindings, core, sizeof(*bindings));
    memcpy(core, candidate, sizeof(*core));
    restore_snapshot_bindings(core, bindings);
    if (!assembled(core)) {
        memcpy(core, bindings, sizeof(*core));
        goto cleanup;
    }
    if (core->ppu.port_ui) memset(core->ppu.port_ui, 0, sizeof(*core->ppu.port_ui));
    ok = 1;
cleanup:
    free(bindings);
    free(candidate);
    return ok;
}

NHCoreStatus nh_core_diagnostic(const NHCore *core, NHCoreDiagnostic *out) {
    NHSchedulerDiagnostic scheduler;
    NHMemoryByte diagnostic_low;
    NHMemoryByte diagnostic_high;
    NHBusStop status;
    unsigned voice, dma_reg, stack_index;
    if (!assembled(core) || out == NULL) return NH_CORE_BAD_ARGUMENT;
    memset(out, 0, sizeof(*out));
    if (core->ppu.port_ui) {
        out->sea_refusal_stage = core->ppu.port_ui->sea_refusal_stage;
        out->sea_refusal_subject = core->ppu.port_ui->sea_refusal_subject;
        out->sea_refusal_expected = core->ppu.port_ui->sea_refusal_expected;
        out->sea_refusal_actual = core->ppu.port_ui->sea_refusal_actual;
    }
    status = nh_scheduler_diagnostic(&core->scheduler, &scheduler);
    if (status != NH_BUS_OK) return public_status(status);
    out->master_clock = scheduler.master_clock;
    out->completed_fields = scheduler.completed_fields;
    out->completed_cpu_cycles = core->cpu.completed_cycles;
    out->smp_cycles = core->apu.smp_cycles;
    out->smp_remainder = scheduler.smp_remainder;
    out->dsp_frames = core->sdsp.frames;
    out->published_frames = core->ppu.published_sequence;
    out->terminal_raster_events = core->terminal_raster_events;
    out->terminal_cpu_boundaries = core->terminal_cpu_boundaries;
    out->ssmp_instructions = core->apu.spc.instructions;
    out->pcm_known_frames = core->sdsp.known_frames;
    out->pcm_unknown_frames = core->sdsp.unknown_frames;
    out->pcm_overflows = core->sdsp.overflows;
    out->sdsp_aram_reads = core->sdsp.aram_reads;
    out->sdsp_aram_writes = core->sdsp.aram_writes;
    out->scpu_address = nh_scpu_address(&core->cpu);
    out->scpu_context_key = nh_scpu_context_key(&core->cpu);
    out->scpu_instruction_address = nh_scpu_address(&core->clock.entry);
    out->scpu_instruction_context = core->clock.context_key;
    out->scpu_instruction_s = core->clock.entry.s;
    out->failure_address = scheduler.bus_failure.address;
    out->pcm_fifo_frames = (uint32_t)core->sdsp.pcm_count;
    out->apu_uploaded_bytes = core->apu.uploaded_bytes;
    out->scpu_a = core->cpu.a;
    out->scpu_x = core->cpu.x;
    out->scpu_y = core->cpu.y;
    out->scpu_d = core->cpu.d;
    out->scpu_s = core->cpu.s;
    out->scpu_p = core->cpu.p;
    out->scpu_pbr = core->cpu.pbr;
    out->scpu_dbr = core->cpu.dbr;
    out->scpu_e = core->cpu.e;
    out->scpu_stack_window_base = (uint16_t)(core->cpu.s - 16u);
    for (stack_index = 0u; stack_index < 32u; ++stack_index) {
        NHMemoryByte stack_byte;
        const uint16_t address = (uint16_t)(
            out->scpu_stack_window_base + stack_index);
        if (nh_memory_peek(&core->storage.bus.memory, address,
                &stack_byte) == NH_MEMORY_OK) {
            out->scpu_stack_window_values[stack_index] = stack_byte.value;
            out->scpu_stack_window_known[stack_index] = stack_byte.known;
        }
    }
    if (nh_memory_peek(&core->storage.bus.memory, 0x000052u, &diagnostic_low) == NH_MEMORY_OK &&
        nh_memory_peek(&core->storage.bus.memory, 0x000053u, &diagnostic_high) == NH_MEMORY_OK) {
        out->wram_0052 = (uint16_t)(diagnostic_low.value |
                                    ((uint16_t)diagnostic_high.value << 8u));
        out->wram_0052_known_mask = (uint8_t)((diagnostic_low.known != 0u ? 1u : 0u) |
                                              (diagnostic_high.known != 0u ? 2u : 0u));
    }
    if (nh_memory_peek(&core->storage.bus.memory, 0x000068u, &diagnostic_low) == NH_MEMORY_OK &&
        nh_memory_peek(&core->storage.bus.memory, 0x000069u, &diagnostic_high) == NH_MEMORY_OK) {
        out->wram_0068 = (uint16_t)(diagnostic_low.value |
                                    ((uint16_t)diagnostic_high.value << 8u));
        out->wram_0068_known_mask = (uint8_t)((diagnostic_low.known != 0u ? 1u : 0u) |
                                              (diagnostic_high.known != 0u ? 2u : 0u));
    }
    if (nh_memory_peek(&core->storage.bus.memory, 0x00006Au, &diagnostic_low) == NH_MEMORY_OK &&
        nh_memory_peek(&core->storage.bus.memory, 0x00006Bu, &diagnostic_high) == NH_MEMORY_OK) {
        out->wram_006a = (uint16_t)(diagnostic_low.value |
                                    ((uint16_t)diagnostic_high.value << 8u));
        out->wram_006a_known_mask = (uint8_t)((diagnostic_low.known != 0u ? 1u : 0u) |
                                              (diagnostic_high.known != 0u ? 2u : 0u));
    }
    out->scanline = scheduler.scanline;
    out->hclock = scheduler.hclock;
    out->dot = scheduler.dot;
    out->ssmp_pc = core->apu.spc.pc;
    out->ssmp_a = core->apu.spc.a;
    out->ssmp_x = core->apu.spc.x;
    out->ssmp_y = core->apu.spc.y;
    out->ssmp_sp = core->apu.spc.sp;
    out->ssmp_psw = core->apu.spc.psw;
    out->sdsp_echo_pointer = core->sdsp.echo_pointer;
    out->sdsp_echo_offset = core->sdsp.echo_offset;
    out->sdsp_echo_length = core->sdsp.echo_length;
    out->failure_owner = (uint8_t)scheduler.bus_failure.owner;
    out->failure_value = scheduler.bus_failure.value;
    out->failure_known_mask = scheduler.bus_failure.known_mask;
    out->scpu_failed = core->cpu.failure.failed;
    out->apu_phase = (uint8_t)core->apu.phase;
    out->apu_expected_token = core->apu.expected_token;
    out->apu_last_ack = core->apu.last_ack;
    out->apu_cpu_port0 = core->apu.cpu_to_smp[0].value;
    out->apu_cpu_port1 = core->apu.cpu_to_smp[1].value;
    out->aram_21d1 = core->apu.aram[0x21D1u];
    out->aram_21d1_known = nh_apu12_aram_known(&core->apu, 0x21D1u);
    out->sdsp_flg = core->sdsp.registers[0x6Cu];
    out->sdsp_esa = core->sdsp.registers[0x6Du];
    out->sdsp_edl = core->sdsp.registers[0x7Du];
    out->sdsp_echo_writable = core->sdsp.echo_writable;
    out->ppu_mode = (uint8_t)(core->ppu.registers[5].value & 7u);
    out->ppu_forced_blank = core->ppu.forced_blank;
    out->ppu_brightness = core->ppu.brightness;
    out->ppu_main_screen = core->ppu.registers[0x2Cu].value;
    out->ppu_main_screen_known_mask = core->ppu.registers[0x2Cu].known_mask;
    for (voice = 0u; voice < NH_SDSP16_VOICES; ++voice)
        if (core->sdsp.voice[voice].active != 0u)
            out->sdsp_active_voice_mask |= (uint8_t)(1u << voice);
    out->power_on_profile = core->storage.bus.memory.power_on_profile;
    out->render_failure_kind = core->ppu.render_failure_kind;
    out->render_failure_value = core->ppu.render_failure_value;
    out->render_failure_known_mask = core->ppu.render_failure_known_mask;
    out->render_failure_address = core->ppu.render_failure_address;
    out->ppu_storage_reads = core->ppu.storage_reads;
    out->ppu_storage_writes = core->ppu.storage_writes;
    out->ppu_oam_data_writes = core->ppu.register_writes[4];
    out->dma_active_channel = core->dma.active_channel;
    out->hdma_enable = core->dma.hdma_enable;
    if (core->dma.active_channel != 0xFFu) {
        const unsigned channel = core->dma.active_channel & 7u;
        for (dma_reg = 0u; dma_reg < 12u; ++dma_reg) {
            out->dma_register_values[dma_reg] =
                core->dma.channel[channel].registers[dma_reg].value;
            out->dma_register_known_masks[dma_reg] =
                core->dma.channel[channel].registers[dma_reg].known_mask;
        }
    }
    out->status = public_status(scheduler.bus_failure.reason);
    memcpy(out->scpu_failure_reason, core->cpu.failure.reason,
           sizeof(out->scpu_failure_reason));
    return NH_CORE_OK;
}

const NHCoreTiming *nh_core_timing(void) {
    static const NHCoreTiming timing = {
        NH_MASTER_HZ_NUMERATOR, NH_MASTER_HZ_DENOMINATOR,
        NH_SMP_REFERENCE_HZ, NH_SDSP16_NATIVE_RATE_HZ,
        3579545u, 59561u, NH_NTSC_NORMAL_LINE_CLOCKS,
        NH_NTSC_SHORT_LINE_CLOCKS, NH_NTSC_LINES_PER_FIELD,
        NH_SMP_RATIO_NUMERATOR, NH_SMP_RATIO_DENOMINATOR,
        NH_SMP_INITIAL_REMAINDER, NH_RESET_STARTUP_MASTER_CLOCKS
    };
    return &timing;
}
