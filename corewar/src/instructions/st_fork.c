/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** st + fork instructions
*/

#include "corewar.h"
#include "vm.h"
#include "champion.h"
#include "process.h"

void st_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr = 0;
    int write_addr = 0;
    int original_pc = process->pc;

    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, process, vm);
    process->pc = addr;
    process->cycles = 5;
    if (args[0] != REGISTER || !(args[1] == REGISTER || args[1] == INDIRECT))
        return;
    if (args[1] == REGISTER)
        process->registers[values[1]] = process->registers[values[0]];
    else {
        write_addr = original_pc
        + get_arg_real_value(args[1], values[1], process, vm) % IDX_MOD;
        *(vm->memory + write_addr % MEM_SIZE) =
        ((char) process->registers[values[0]]);
    }
}

void sti_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr = 0;
    int write_addr = 0;

    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, process, vm);
    if (args[0] != REGISTER || args[1] == NONE)
        return;
    write_addr = process->pc
    + (get_arg_real_value(args[1], values[1], process, vm)
    + get_arg_real_value(args[2], values[2], process, vm)) % IDX_MOD;
    *(vm->memory + write_addr % MEM_SIZE) =
    ((char) process->registers[values[0]]);
    process->pc = addr;
    process->cycles = 25;
}

void fork_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr = 0;
    int fork_addr = 0;
    int original_pc = process->pc;
    process_t *fork = NULL;

    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, process, vm);
    process->pc = addr;
    fork->cycles = 800;
    if (args[0] != DIRECT)
        return;
    fork_addr = original_pc +
    get_arg_real_value(args[0], values[0], process, vm) % IDX_MOD;
    if (!(fork = process_fork(process, fork_addr)))
        return;
    create_list(&(champion->processes), fork);
}

void lfork_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr = 0;
    int fork_addr = 0;
    int original_pc = process->pc;
    process_t *fork = NULL;

    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, process, vm);
    process->pc = addr;
    fork->cycles = 1000;
    if (args[0] != DIRECT)
        return;
    fork_addr = original_pc +
    get_arg_real_value(args[0], values[0], process, vm);
    if (!(fork = process_fork(process, fork_addr)))
        return;
    create_list(&(champion->processes), fork);
}
