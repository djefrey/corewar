/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** st + fork instructions
*/

#include "my.h"
#include "my_list.h"
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

    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, 0, (couple_t) {process, vm});
    if (args[0] == REGISTER && (args[1] == REGISTER || args[1] == INDIRECT)) {
        if (args[1] == REGISTER)
            process->registers[values[1]] = process->registers[values[0]];
        else {
            write_addr = (process->pc + values[1] % IDX_MOD) % MEM_SIZE;
            write_int(write_addr, process->registers[values[0]], REG_SIZE, vm);
        }
    }
    process->pc = addr;
    process->cycles = 5;
}

void sti_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr = 0;
    int write_addr = 0;

    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, 1, (couple_t) {process, vm});
    if (args[0] == REGISTER && args[1] != NONE && args[2] != NONE) {
        write_addr = process->pc
        + (get_arg_real_value(args[1], values[1], process, vm)
        + get_arg_real_value(args[2], values[2], process, vm)) % IDX_MOD;
        write_int(write_addr, process->registers[values[0]], REG_SIZE, vm);
    }
    process->pc = addr;
    process->cycles = 25;
}

void fork_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr = 0;
    int fork_addr = 0;
    process_t *fork = NULL;

    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, 1, (couple_t) {process, vm});
    if (args[0] == DIRECT) {
        fork_addr = (process->pc + values[0] % IDX_MOD) % MEM_SIZE;
        if ((fork = process_fork(process, fork_addr)))
            create_list(&(champion->processes), fork);
    }
    process->pc = addr;
    process->cycles = 800;
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
    addr = get_arguments_value(args, values, 0, (couple_t) {process, vm});
    if (args[0] == DIRECT) {
        fork_addr = (original_pc + values[0]) % MEM_SIZE;
        if ((fork = process_fork(process, fork_addr)))
            create_list(&(champion->processes), fork);
    }
    process->pc = addr;
    process->cycles = 1000;
}
