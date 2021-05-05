/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** process
*/

#ifndef PROCESS_H_
#define PROCESS_H_

#include "corewar.h"

typedef struct vm_s vm_t;

typedef struct process_s {
    reg_t registers[REG_NUMBER];
    reg_t pc;
    char carry;
} process_t;

process_t *process_create(int id, int pc);
process_t *process_clone(process_t *original);
void process_execute(process_t *process, vm_t *vm);
void process_destroy(process_t *process);

#endif /* !PROCESS_H_ */
