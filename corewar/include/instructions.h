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

typedef struct instruction_s {
    char value;
    int cycles;
    char nb_args;
    char args[4];
    instruction_fct_t fct;
} instruction_t;

extern const instruction_t INSTRUCTIONS[INSTRUCTIONS_NB];

#endif /* !INSTRUCTIONS_H_ */
