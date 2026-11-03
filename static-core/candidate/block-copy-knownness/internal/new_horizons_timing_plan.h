#ifndef NEW_HORIZONS_TIMING_PLAN_H
#define NEW_HORIZONS_TIMING_PLAN_H

#include <stddef.h>
#include <stdint.h>

typedef enum NHTimingKind {
    NH_TIMING_FETCH, NH_TIMING_READ, NH_TIMING_WRITE, NH_TIMING_INTERNAL
} NHTimingKind;

typedef enum NHTimingCondition {
    NH_TIMING_ALWAYS, NH_TIMING_DIRECT_LOW_NONZERO,
    NH_TIMING_BRANCH_TAKEN, NH_TIMING_BRANCH_TAKEN_AND_PAGE_CROSSED,
    NH_TIMING_INDEX_PAGE_CROSSED
} NHTimingCondition;

typedef enum NHTimingRole {
    NH_TIMING_INSTRUCTION, NH_TIMING_STACK, NH_TIMING_CALL,
    NH_TIMING_POINTER_INDEX, NH_TIMING_RETURN, NH_TIMING_STACK_PREPARE,
    NH_TIMING_RETURN_INCREMENT, NH_TIMING_DIRECT_PAGE, NH_TIMING_POINTER,
    NH_TIMING_BLOCK_SOURCE, NH_TIMING_BLOCK_DESTINATION,
    NH_TIMING_BLOCK_INDEX, NH_TIMING_BLOCK_COUNT, NH_TIMING_STATUS_WIDTH,
    NH_TIMING_BRANCH, NH_TIMING_BRANCH_PAGE, NH_TIMING_BRANCH_LONG,
    NH_TIMING_STACK_INCREMENT, NH_TIMING_IMPLIED, NH_TIMING_ACCUMULATOR_SWAP,
    NH_TIMING_DIRECT_INDEX, NH_TIMING_STACK_RELATIVE, NH_TIMING_INDEX_ADD,
    NH_TIMING_PAYLOAD, NH_TIMING_MODIFY
} NHTimingRole;

enum {
    NH_TIMING_INDEX_NONE, NH_TIMING_INDEX_X, NH_TIMING_INDEX_Y
};
enum {
    NH_TIMING_PAGE_NONE, NH_TIMING_PAGE_OPERAND, NH_TIMING_PAGE_POINTER
};

typedef struct NHTimingEvent {
    uint8_t kind;
    uint8_t role;
    uint8_t index;
    uint8_t condition;
} NHTimingEvent;

typedef struct NHTimingPlan {
    uint32_t first_event;
    uint8_t event_count;
    uint8_t fetch_count;
    uint8_t branch_mask;
    uint8_t branch_set;
    uint8_t index_register;
    uint8_t page_base_source;
    /* RTI polls restored I from its actual status-stack sample. Other admitted
     * instructions poll entry I, including CLI/SEI/PLP/REP/SEP. */
    uint16_t irq_status_from_stack;
} NHTimingPlan;

typedef struct NHTimingBinding {
    uint32_t context_key;
    uint32_t plan_index;
} NHTimingBinding;

extern const NHTimingEvent nh_timing_events[];
extern const NHTimingPlan nh_timing_plans[];
extern const NHTimingBinding nh_timing_bindings[];
extern const uint32_t nh_timing_bank_first[257];
extern const size_t nh_timing_event_count;
extern const size_t nh_timing_plan_count;
extern const size_t nh_timing_binding_count;

/* Exact-key lookup only. No guest byte/opcode decoding or context admission.
 * Data is a construction candidate until callback/phase qualification and the
 * one09 clock owner are joined. Missing keys never select a generic plan. */
const NHTimingPlan *nh_timing_plan_lookup(uint32_t context_key);

#endif
