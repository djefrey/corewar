/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** process
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_list.h"
#include "corewar.h"
#include "process.h"
#include "champion.h"
#include "vm.h"
#include "instructions.h"

process_t *process_create(champion_t *champion, int addr)
{
    process_t *process = malloc(sizeof(process_t));

    if (!process)
        return (NULL);
    for (int i = 0; i < REG_NUMBER; i++)
        process->registers[i] = 0;
    process->registers[0] = champion->id;
    process->pc = addr;
    process->carry = 0;
    process->cycles = -1;
    create_list(&(champion->processes), process);
    return (process);
}

process_t *process_fork(process_t *original, int pc)
{
    process_t *fork = malloc(sizeof(process_t));

    if (!fork)
        return (NULL);
    for (int i = 0; i < REG_NUMBER; i++)
        fork->registers[i] = original->registers[i];
    fork->pc = pc;
    fork->carry = original->carry;
    fork->cycles = original->cycles;
    return (fork);
}

void process_update(process_t *process, champion_t *champion, vm_t *vm)
{
    char instruction = 0;

    if (process->cycles > 0) {
        process->cycles--;
        return;
    }
    if (process->cycles == -1) {
        process_next_instruction(process, vm);
    } else {
        instruction = *(vm->memory + process->pc % MEM_SIZE);
        for (int i = 0; i < INSTRUCTIONS_NB; i++) {
            if (INSTRUCTIONS[i].value == instruction) {
                INSTRUCTIONS[i].fct(process, champion, vm);
                break;
            }
        }
        process_next_instruction(process, vm);
    }
}

/*
** Check next instruction validity
** - If valid, set process->cycles
** - Else move to next instruction
*/
void process_next_instruction(process_t *process, vm_t *vm)
{
    char instruction = *(vm->memory + process->pc % MEM_SIZE);

    for (int i = 0; i < INSTRUCTIONS_NB; i++) {
        if (INSTRUCTIONS[i].value == instruction) {
            process->cycles = process->cycles == 0
            ? INSTRUCTIONS[i].cycles
            : INSTRUCTIONS[i].cycles - 1;
            break;
        }
    }
    process->cycles = -1;
    process->pc = (process->pc + 1) % MEM_SIZE;
}

void process_destroy(process_t *process)
{
    free(process);
}