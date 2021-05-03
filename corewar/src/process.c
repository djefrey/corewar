/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** process
*/

#include <stdlib.h>
#include <unistd.h>
#include "process.h"

process_t *process(int id, int pc)
{
    process_t *process = malloc(sizeof(process_t));

    if (!process)
        return (NULL);
    process->registers[0] = id;
    for (int i = 1; i < REG_NUMBER; i++)
        process->registers[i] = 0;
    process->pc = pc;
    process->carry = 0;
    return (process);
}

process_t *process_clone(process_t *original)
{
    process_t *process = malloc(sizeof(process_t));

    if (!process)
        return (NULL);
    for (int i = 0; i < REG_NUMBER; i++)
        process->registers[i] = original->registers[i];
    process->pc = original->pc;
    process->carry = original->carry;
    return (process);
}

void process_destroy(process_t *process)
{
    free(process);
}