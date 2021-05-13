/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instructions
*/

#ifndef INSTRUCTIONS_H_
#define INSTRUCTIONS_H_

#define INSTRUCTIONS_NB 16

typedef struct vm_s vm_t;
typedef struct champion_s champion_t;
typedef struct process_s process_t;

typedef void (*instruction_fct_t)(process_t*, champion_t*, vm_t*);

void add_instruction(process_t *process, champion_t *champion, vm_t *vm);
void sub_instruction(process_t *process, champion_t *champion, vm_t *vm);
void and_instruction(process_t *process, champion_t *champion, vm_t *vm);
void or_instruction(process_t *process, champion_t *champion, vm_t *vm);
void xor_instruction(process_t *process, champion_t *champion, vm_t *vm);

void ld_instruction(process_t *process, champion_t *champion, vm_t *vm);
void ldi_instruction(process_t *process, champion_t *champion, vm_t *vm);
void lld_instruction(process_t *process, champion_t *champion, vm_t *vm);
void lldi_instruction(process_t *process, champion_t *champion, vm_t *vm);

void st_instruction(process_t *process, champion_t *champion, vm_t *vm);
void sti_instruction(process_t *process, champion_t *champion, vm_t *vm);
void fork_instruction(process_t *process, champion_t *champion, vm_t *vm);
void lfork_instruction(process_t *process, champion_t *champion, vm_t *vm);

void live_instruction(process_t *process, champion_t *champion, vm_t *vm);
void zjmp_instruction(process_t *process, champion_t *champion, vm_t *vm);
void aff_instruction(process_t *process, champion_t *champion, vm_t *vm);

const char INSTRUCTION_VALUE[] = {
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    14,
    15,
    16,
};

const instruction_fct_t INSTRUCTION_FCT[] = {
    &live_instruction,
    &ld_instruction,
    &st_instruction,
    &add_instruction,
    &sub_instruction,
    &and_instruction,
    &or_instruction,
    &xor_instruction,
    &zjmp_instruction,
    &ldi_instruction,
    &sti_instruction,
    &fork_instruction,
    &lld_instruction,
    &lldi_instruction,
    &lfork_instruction,
    &aff_instruction,
};

#endif /* !INSTRUCTIONS_H_ */
