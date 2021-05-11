/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** utils
*/

#include <stdlib.h>
#include "tests.h"

int create_criterion_vm(vm_t *vm)
{
    if (!(vm->memory = malloc(sizeof(char) * 128)))
        return (1);
    vm->cycles = 0;
    vm->dead_cycles = 100;
    vm->dump_cycles = -1;
    vm->champions = NULL;
    return (0);
}

void create_criterion_process(process_t *process)
{
    for (int i = 0; i < REG_NUMBER; i++)
        process->registers[i] = 0;
    process->pc = 0;
    process->carry = 0;
}