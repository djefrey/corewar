/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** vm run
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "corewar.h"
#include "vm.h"
#include "process.h"
#include "champion.h"

void vm_run(vm_t *vm)
{
    int living = 4;

    while (living > 1) {
        living = vm_update_champions(vm);
        if (vm_cycles(vm))
            break;
        #ifdef BONUS
        if (!bonus_update(vm->bonus, vm))
            break;
        #endif
    }
    vm_print_winner(vm);
}

/*
** Update all champions
** Return the number of living ones
*/
int vm_update_champions(vm_t *vm)
{
    champion_t *champion;
    int living = 0;

    for (list_t *list = vm->champions; list; list = list->next) {
        champion = (champion_t*) list->data;
        champion_update(champion, vm);
        living += champion->nb_processes > 0;
    }
    return (living);
}

int vm_cycles(vm_t *vm)
{
    if (vm->cycles == vm->dump_cycles) {
        vm_dump(vm);
        return (1);
    }
    if (vm->nb_lives >= NBR_LIVE) {
        vm->nb_lives = 0;
        vm->dead_cycles -= CYCLE_DELTA;
        if (vm->dead_cycles <= 0)
            vm->dead_cycles = 1;
    }
    if (vm->cycles && vm->lives_cycles >= vm->dead_cycles) {
        vm->lives_cycles = 0;
        vm_process_alive(vm);
    } else
        vm->lives_cycles++;
    vm->cycles++;
    return (0);
}

/*
** Check if every processes call "live"
** If a process has called live, is_alive is reset
** Else the process is killed
*/
void vm_process_alive(vm_t *vm)
{
    list_t *next;
    champion_t *champion;
    process_t *process;

    for (list_t *list = vm->champions; list; list = list->next) {
        champion = (champion_t*) list->data;
        for (list_t *p_list = champion->processes; p_list; p_list = next) {
            next = p_list->next;
            process = (process_t*) p_list->data;
            if (!process->is_alive) {
                #ifdef BONUS
                bonus_set_actual_pc(vm->bonus, process->pc, 0);
                #endif
                my_delete_node(&(champion->processes), process);
                process_destroy(process);
                champion->nb_processes--;
            } else
                process->is_alive = 0;
        }
    }
}