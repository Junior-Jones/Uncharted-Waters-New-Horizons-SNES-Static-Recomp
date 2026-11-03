#ifndef NEW_HORIZONS_SRAM_FILE_H
#define NEW_HORIZONS_SRAM_FILE_H

#include "new_horizons_memory.h"

enum { NH_SRAM_FILE_HEADER_BYTES = 80u,
       NH_SRAM_FILE_PAYLOAD_BYTES = NH_SRAM_BYTES + NH_SRAM_BYTES / 8u,
       NH_SRAM_FILE_BYTES = NH_SRAM_FILE_HEADER_BYTES + NH_SRAM_FILE_PAYLOAD_BYTES };

/* Portable in-game battery save, not a machine snapshot. Buffers must be
 * disjoint from the live memory instance. Call only at a quiescent host
 * boundary. Encoding does not acknowledge a filesystem flush: the host must
 * atomically persist the completed image before acknowledging its generation.
 * Decoding validates everything before the one initial SRAM load/commit. */
NHMemoryResult nh_sram_file_encode(const NHMemory *memory, uint8_t *file,
                                   size_t size, uint64_t *generation);
NHMemoryResult nh_sram_file_decode(NHMemory *memory, const uint8_t *file,
                                   size_t size);

#endif
