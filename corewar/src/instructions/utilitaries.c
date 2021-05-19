/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** utilitaries
*/

#include <unistd.h>
#include "my.h"
#include "corewar.h"
#include "vm.h"
#include "champion.h"
#include "process.h"

void live_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    champion_t *alive = NULL;
    int value = -1;

    UNUSED(champion);
    value = read_int(process->pc + 1, 4, vm);
    process->pc = (process->pc + 5) % MEM_SIZE;
    process->live_cycles = 0;
    for (list_t *list = vm->champions; list; list = list->next) {
        alive = (champion_t*) list->data;
        if (alive->id == value) {
            my_printf("Le joueur %i (%s) est en vie.\n",
            alive->id, alive->header->prog_name);
            vm->last_live = alive->id;
            break;
        }
    }
}

void zjmp_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    int value = read_int(process->pc + 1, IND_SIZE, vm);

    UNUSED(champion);
    if (process->carry == 1)
        process->pc = (process->pc + value % IDX_MOD) % MEM_SIZE;
    else
        process->pc = (process->pc + 3) % MEM_SIZE;
}

void aff_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr;
    char c;

    UNUSED(champion);
    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, 1, (couple_t) {process, vm});
    if (check_args_validity(args, values, 0x10)) {
        c = process->registers[values[0]] % 256;
        write(1, &c, 1);
    }
    process->pc = addr;
}