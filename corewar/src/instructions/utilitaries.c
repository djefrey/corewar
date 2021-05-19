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

    process->cycles = 10;
    value = read_int(process->pc + 1, 4, vm);
    process->pc = (process->pc + 5) % MEM_SIZE;
    for (list_t *list = vm->champions; list; list = list->next) {
        alive = (champion_t*) list->data;
        if (alive->id == value) {
            my_printf("Le joueur %i (%s) est en vie.\n",
            alive->id, alive->header->prog_name);
            alive->live_cycles = 0;
            break;
        }
    }
}

void zjmp_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    int value = read_int(process->pc + 1, IND_SIZE, vm);

    process->cycles = 20;
    if (process->carry == 1)
        process->pc = (process->pc + value % IDX_MOD) % MEM_SIZE;
    else
        process->pc = (process->pc + 3) % MEM_SIZE;
}

void aff_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr = 0;
    char c;

    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, 0, (couple_t) {process, vm});
    if (args[0] == REGISTER && values[0] >= 0 && values < REG_NUMBER) {
        c = process->registers[values[0]] % 256;
        write(1, &c, 1);
    }
    process->pc= addr;
    process->cycles = 10;
}