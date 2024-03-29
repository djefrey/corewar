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
    process->is_alive = 0;
    champion_add_process(champion, process);
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
    fork->cycles = -2;
    fork->is_alive = 0;
    return (fork);
}

int process_update(process_t *process, champion_t *champion, vm_t *vm)
{
    char instruction = 0;

    if (process->cycles > 0) {
        process->cycles--;
        return (0);
    }
    #ifdef BONUS
    bonus_set_actual_pc(vm->bonus, process->pc, 0);
    #endif
    if (process->cycles == 0) {
        instruction = *(vm->memory + process->pc % MEM_SIZE);
        for (int i = 0; i < INSTRUCTIONS_NB; i++) {
            if (INSTRUCTIONS[i].value == instruction) {
                INSTRUCTIONS[i].fct(process, champion, vm);
                break;
            }
        }
    }
    process_next_instruction(process, vm);
    return (0);
}

/*
** Check next instruction validity
** - If valid, set process->cycles
** - Else move to next instruction
** process->cycles:
** - 0 / -2 => Execute instruction after n cycles (-2 = fork)
** - -1 => Execute instruction after n - 1 cycles
*/
void process_next_instruction(process_t *process, vm_t *vm)
{
    char instruction = *(vm->memory + process->pc % MEM_SIZE);

    for (int i = 0; i < INSTRUCTIONS_NB; i++) {
        if (INSTRUCTIONS[i].value == instruction) {
            process->cycles = process->cycles == 0 || process->cycles == -2
            ? INSTRUCTIONS[i].cycles
            : INSTRUCTIONS[i].cycles - 1;
            #ifdef BONUS
            bonus_set_actual_pc(vm->bonus, process->pc, 1);
            #endif
            return;
        }
    }
    process->cycles = -1;
    process->pc = (process->pc + 1) % MEM_SIZE;
    #ifdef BONUS
    bonus_set_actual_pc(vm->bonus, process->pc, 1);
    #endif
}

void process_destroy(process_t *process)
{
    free(process);
}