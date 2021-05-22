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

    UNUSED(champion);
    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, 0, (couple_t) {process, vm});
    if (check_args_validity(args, values, 0x3)) {
        if (args[1] == REGISTER)
            process->registers[values[1]] = process->registers[values[0]];
        else {
            write_addr = (process->pc + values[1] % IDX_MOD) % MEM_SIZE;
            write_int(write_addr, process->registers[values[0]], REG_SIZE, vm);
            #ifdef BONUS
            bonus_write_champion_id(vm->bonus, write_addr, REG_SIZE, champion->id);
            #endif
        }
    }
    process->pc = addr;
}

void sti_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr = 0;
    int write_addr = 0;

    UNUSED(champion);
    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, 1, (couple_t) {process, vm});
    if (check_args_validity(args, values, 0xb)) {
        write_addr = process->pc
        + (get_arg_real_value(args[1], values[1], process, vm)
        + get_arg_real_value(args[2], values[2], process, vm)) % IDX_MOD;
        write_int(write_addr, process->registers[values[0]], REG_SIZE, vm);
        #ifdef BONUS
        bonus_write_champion_id(vm->bonus, write_addr, REG_SIZE, champion->id);
        #endif
    }
    process->pc = addr;
}

void fork_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    int value = read_int(process->pc + 1, IND_SIZE, vm);
    int fork_addr = 0;
    process_t *fork = NULL;

    fork_addr = (process->pc + value % IDX_MOD) % MEM_SIZE;
    if (fork_addr < 0)
        fork_addr += MEM_SIZE;
    if ((fork = process_fork(process, fork_addr)))
        champion_add_process(champion, fork);
    process->pc = (process->pc + 3) % MEM_SIZE;
}

void lfork_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    int value = read_int(process->pc + 1, IND_SIZE, vm);
    int fork_addr = 0;
    process_t *fork = NULL;

    fork_addr = (process->pc + value) % MEM_SIZE;
    if (fork_addr < 0)
        fork_addr += MEM_SIZE;
    if ((fork = process_fork(process, fork_addr)))
        champion_add_process(champion, fork);
    process->pc = (process->pc + 3) % MEM_SIZE;
}
