/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** corewar main
*/

#include <stdlib.h>
#include "corewar.h"
#include "vm.h"

int main(int ac, char **av)
{
    vm_t vm = {NULL, 0, CYCLE_TO_DIE, -1, NULL};

    if (!(vm.memory = malloc(sizeof(char) * MEM_SIZE)))
        return (84);
    return (0);
}