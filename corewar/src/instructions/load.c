/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** load instructions
*/

#include "corewar.h"
#include "vm.h"
#include "champion.h"
#include "process.h"

void ld_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr = 0;

    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, 0, (couple_t) {process, vm});
    if ((args[0] == DIRECT || args[0] == INDIRECT) && args[1] == REGISTER) {
        if (args[0] == INDIRECT)
            process->registers[values[1]] =
            read_int(process->pc + values[0] % IDX_MOD, REG_SIZE, vm);
        else if (args[0] == DIRECT)
            process->registers[values[1]] = values[0];
        if (process->registers[values[1]] == 0)
            process->carry = 1;
        else
            process->carry = 0;
    }
    process->cycles = 5;
    process->pc = addr;
}

void ldi_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr = 0;
    int read_addr = 0;

    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, 1, (couple_t) {process, vm});
    if ((args[1] == DIRECT || args[1] == REGISTER) && args[2] == REGISTER) {
        read_addr = process->pc
        + (get_arg_real_value(args[0], values[0], process, vm)
        + get_arg_real_value(args[1], values[1], process, vm)) % IDX_MOD;
        process->registers[values[2]] = read_int(read_addr, REG_SIZE, vm);
        if (process->registers[values[2]] == 0)
            process->carry = 1;
        else
            process->carry = 0;
    }
    process->cycles = 25;
    process->pc = addr;
}

void lld_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr = 0;

    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, 0, (couple_t) {process, vm});
    if (args[1] == REGISTER) {
        if (args[0] == INDIRECT)
            process->registers[values[1]] =
            read_int(process->pc + values[0], REG_SIZE, vm);
        else if (args[0] == DIRECT)
            process->registers[values[1]] = values[0];
        if (process->registers[values[1]] == 0)
            process->carry = 1;
        else
            process->carry = 0;
    }
    process->pc = addr;
    process->cycles = 10;
}

void lldi_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr = 0;
    int read_addr = 0;

    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, 1, (couple_t) {process, vm});
    if ((args[1] == DIRECT || args[1] == REGISTER) && args[2] == REGISTER) {
        read_addr = process->pc
        + (get_arg_real_value(args[0], values[0], process, vm)
        + get_arg_real_value(args[1], values[1], process, vm));
        process->registers[values[2]] = read_int(read_addr, REG_SIZE, vm);
        if (process->registers[values[2]] == 0)
            process->carry = 1;
        else
            process->carry = 0;
    }
    process->pc = addr;
    process->cycles = 50;
}