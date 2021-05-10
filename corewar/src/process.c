/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** process
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_list.h"
#include "process.h"
#include "champion.h"
#include "vm.h"

process_t *process_create(champion_t *champion, int addr, char *memory)
{
    process_t *process = malloc(sizeof(process_t));

    if (!process)
        return (NULL);
    process->registers[0] = champion->id;
    for (int i = 1; i < REG_NUMBER; i++)
        process->registers[i] = 0;
    process->pc = addr;
    process->carry = 0;
    create_list(&(champion->processes), process);
    return (process);
}

process_t *process_fork(process_t *original, int pc)
{
    process_t *process = malloc(sizeof(process_t));

    if (!process)
        return (NULL);
    for (int i = 0; i < REG_NUMBER; i++)
        process->registers[i] = original->registers[i];
    process->pc = pc;
    process->carry = original->carry;
    return (process);
}

void process_update(process_t* process, champion_t *champion, vm_t *vm)
{

}

void process_destroy(process_t *process)
{
    free(process);
}