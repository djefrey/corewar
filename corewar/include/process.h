/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** process
*/

#ifndef PROCESS_H_
#define PROCESS_H_

#include "corewar.h"

typedef struct champion_s champion_t;
typedef struct vm_s vm_t;

typedef struct process_s {
    reg_t registers[REG_NUMBER];
    reg_t pc;
    char carry;
} process_t;

process_t *process_create(champion_t *champion, int addr, char *memory);
process_t *process_fork(process_t *original, int pc);
void process_update(process_t* process, champion_t *champion, vm_t *vm);
void process_destroy(process_t *process);

#endif /* !PROCESS_H_ */
