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
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr = 0;
    champion_t *alive = NULL;

    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, process, vm);
    process->pc = addr;
    process->cycles = 10;
    if (args[0] != DIRECT)
        return;
    for (list_t *list = vm->champions; list; list = list->next) {
        alive = (champion_t*) list->data;
        if (alive->id == values[0]) {
            my_printf("The player %i(%s) is alive\n",
            alive->id, alive->header->prog_name);
            alive->live_cycles = 0;
            break;
        }
    }
}

void aff_instruction(process_t *process, champion_t *champion, vm_t *vm)
{
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr = 0;
    char c;

    get_arguments_type(args, process, vm);
    addr = get_arguments_value(args, values, process, vm);
    process->pc = addr;
    process->cycles = 10;
    if (args[0] != REGISTER)
        return;
    c = process->registers[values[0]] % 256;
    write(1, &c, 1);
}