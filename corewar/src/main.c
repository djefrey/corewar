/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** corewar main
*/

#include <stdlib.h>
#include "corewar.h"
#include "vm.h"
#include "champion.h"

int main(int ac, char **av)
{
    #ifndef BONUS
    vm_t vm = {NULL, 0, CYCLE_TO_DIE, -1, NULL};
    #else
    vm_t vm = {NULL, 0, CYCLE_TO_DIE, -1, NULL, bonus_create()};
    #endif

    if (!(vm.memory = malloc(sizeof(char) * MEM_SIZE)))
        return (84);
    for (int i = 0; i < MEM_SIZE; i++)
        *(vm.memory + i) = 0;
    if (argument_managemnt(ac, av, &vm)) {
        vm_destroy(&vm);
        return (84);
    }
    vm_run(&vm);
    vm_destroy(&vm);
    return (0);
}