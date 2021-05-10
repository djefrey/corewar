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
    NULL,
    NULL,
    &add_instruction,
    &sub_instruction,
    &and_instruction,
    &or_instruction,
    &xor_instruction,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

#endif /* !INSTRUCTIONS_H_ */
