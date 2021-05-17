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
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr = 0;

    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, 0, (couple_t) {process, vm});
    process->pc = addr;
    process->cycles = 10;
    if (args[0] != REGISTER || args[1] != REGISTER || args[2] != REGISTER)
        return;
    process->registers[values[2]] =
    process->registers[values[0]] + process->registers[values[1]];
    if (process->registers[values[2]] == 0)
        process->carry = 1;
    else
        process->carry = 0;
}

void sub_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr = 0;

    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, 0, (couple_t) {process, vm});
    process->pc = addr;
    process->cycles = 10;
    if (args[0] != REGISTER || args[1] != REGISTER || args[2] != REGISTER)
        return;
    process->registers[values[2]] =
    process->registers[values[0]] - process->registers[values[1]];
    if (process->registers[values[2]] == 0)
        process->carry = 1;
    else
        process->carry = 0;
}

void and_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr = 0;

    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, 0, (couple_t) {process, vm});
    process->pc = addr;
    process->cycles = 6;
    if (args[0] == NONE || args[1] == NONE || args[2] != REGISTER)
        return;
    process->registers[values[2]] = get_arg_real_value(args[0], values[0],
    process, vm) & get_arg_real_value(args[1], values[1], process, vm);
    if (process->registers[values[2]] == 0)
        process->carry = 1;
    else
        process->carry = 0;
}

void or_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr = 0;

    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, 0, (couple_t) {process, vm});
    process->pc = addr;
    process->cycles = 6;
    if (args[0] == NONE || args[1] == NONE  || args[2] != REGISTER)
        return;
    process->registers[values[2]] = get_arg_real_value(args[0], values[0],
    process, vm) | get_arg_real_value(args[1], values[1], process, vm);
    if (process->registers[values[2]] == 0)
        process->carry = 1;
    else
        process->carry = 0;
}

void xor_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {0};
    int values[4] = {0};
    int addr = 0;

    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, 0, (couple_t) {process, vm});
    process->pc = addr;
    process->cycles = 6;
    if (args[0] == NONE || args[1] == NONE  || args[2] != REGISTER)
        return;
    process->registers[values[2]] = get_arg_real_value(args[0], values[0],
    process, vm) ^ get_arg_real_value(args[1], values[1], process, vm);
    if (process->registers[values[2]] == 0)
        process->carry = 1;
    else
        process->carry = 0;
}