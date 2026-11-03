#ifndef NEW_HORIZONS_FETCH_H
#define NEW_HORIZONS_FETCH_H

#include "new_horizons_scpu.h"

typedef struct NHStaticFetch {
    uint32_t guard_address;
    size_t guard_count;
    uint32_t fetch_address;
    size_t fetch_count;
    uint8_t executable_epoch;
    uint8_t immutable_byte_mask;
    uint32_t deferred_operand_address;
    size_t deferred_operand_count;
} NHStaticFetch;

/* Exact source metadata, not a runtime opcode decoder. Normal bus reads
 * perform the actual fetches; epoch metadata inspection remains separate.
 * For MVN, begin consumes the opcode; the native read8 calls consume the two
 * deferred operand slots before the payload read/write. They are instruction
 * fetches, not extra data cycles. RTL consumes no bank operands.09 must copy
 * this descriptor and the expected guard bytes before begin returns. */
int nh_static_fetch_descriptor(const NHScpuState *cpu, uint32_t guard_address,
                               size_t guard_count, NHStaticFetch *descriptor);

#endif
