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

    UNUSED(champion);
    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, 0, (couple_t) {process, vm});
    if (check_args_validity(args, values, 0x4)) {
        process->registers[values[2]] =
        process->registers[values[0]] + process->registers[values[1]];
        if (process->registers[values[2]] == 0)
            process->carry = 1;
        else
            process->carry = 0;
    }
    process->pc = addr;
}

void sub_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr = 0;

    UNUSED(champion);
    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, 0, (couple_t) {process, vm});
    if (check_args_validity(args, values, 0x5)) {
        process->registers[values[2]] =
        process->registers[values[0]] - process->registers[values[1]];
        if (process->registers[values[2]] == 0)
            process->carry = 1;
        else
            process->carry = 0;
    }
    process->pc = addr;
}

void and_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr = 0;

    UNUSED(champion);
    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, 0, (couple_t) {process, vm});
    if (check_args_validity(args, values, 0x6)) {
        process->registers[values[2]] = get_arg_real_value(args[0], values[0],
        process, vm) & get_arg_real_value(args[1], values[1], process, vm);
        if (process->registers[values[2]] == 0)
            process->carry = 1;
        else
            process->carry = 0;
    }
    process->pc = addr;
}

void or_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr = 0;

    UNUSED(champion);
    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, 0, (couple_t) {process, vm});
    if (check_args_validity(args, values, 0x7)) {
        process->registers[values[2]] = get_arg_real_value(args[0], values[0],
        process, vm) | get_arg_real_value(args[1], values[1], process, vm);
        if (process->registers[values[2]] == 0)
            process->carry = 1;
        else
            process->carry = 0;
    }
    process->pc = addr;
}

void xor_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {0};
    int values[4] = {0};
    int addr = 0;

    UNUSED(champion);
    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, 0, (couple_t) {process, vm});
    if (check_args_validity(args, values, 0x8)) {
        process->registers[values[2]] = get_arg_real_value(args[0], values[0],
        process, vm) ^ get_arg_real_value(args[1], values[1], process, vm);
        if (process->registers[values[2]] == 0)
            process->carry = 1;
        else
            process->carry = 0;
    }
    process->pc = addr;
}