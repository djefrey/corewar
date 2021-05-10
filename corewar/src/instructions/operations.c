/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** operations instruction
*/

#include "corewar.h"
#include "vm.h"
#include "champion.h"
#include "process.h"

void add_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    int reg1 = (int) *(vm->memory + (process->pc + 2) % MEM_SIZE);
    int reg2 = (int) *(vm->memory + (process->pc + 2 + REG_SIZE) % MEM_SIZE);
    int reg3 = (int) *(vm->memory +
    (process->pc + 2 + REG_SIZE * 2) % MEM_SIZE);

    process->registers[reg3] =
    process->registers[reg1] + process->registers[reg2];
    if (process->registers[reg3] == 0)
        process->carry = 1;
    else
        process->carry = 0;
    process->pc = (process->pc + 2 + 3 * REG_SIZE) % MEM_SIZE;
}

void sub_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    int reg1 = (int) *(vm->memory + (process->pc + 2) % MEM_SIZE);
    int reg2 = (int) *(vm->memory + (process->pc + 2 + REG_SIZE) % MEM_SIZE);
    int reg3 = (int) *(vm->memory +
    (process->pc + 2 + REG_SIZE * 2) % MEM_SIZE);

    process->registers[reg3] =
    process->registers[reg1] - process->registers[reg2];
    if (process->registers[reg3] == 0)
        process->carry = 1;
    else
        process->carry = 0;
    process->pc = (process->pc + 2 + 3 * REG_SIZE) % MEM_SIZE;
}

void and_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    int values[2] = {0};
    int addr = get_values_from_coding(values, 2, process, vm);
    int reg = (int) *(memory->vm + addr % MEM_SIZE);

    process->registers[reg] = values[0] & values[1];
    if (process->registers[reg] == 0)
        process->carry = 1;
    else
        process->carry = 0;
    process->pc = (addr + REG_SIZE) % MEM_SIZE;
}

void or_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    int values[2] = {0};
    int addr = get_values_from_coding(values, 2, process, vm);
    int reg = (int) *(memory->vm + addr % MEM_SIZE);

    if (process->registers[reg] == 0)
        process->carry = 1;
    else
        process->carry = 0;
    process->registers[reg] = values[0] | values[1];
    process->pc = (addr + REG_SIZE) % MEM_SIZE;
}

void xor_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    int values[2] = {0};
    int addr = get_values_from_coding(values, 2, process, vm);
    int reg = (int) *(memory->vm + addr % MEM_SIZE);

    if (process->registers[reg] == 0)
        process->carry = 1;
    else
        process->carry = 0;
    process->registers[reg] = values[0] ^ values[1];
    process->pc = (addr + REG_SIZE) % MEM_SIZE;
}