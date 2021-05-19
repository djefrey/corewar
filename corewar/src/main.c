/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** corewar main
*/

#include <stdlib.h>
#include "vm.h"
#include "corewar.h"
#include "champion.h"

int main(int ac, char **av)
{
    vm_t vm;

    if (vm_init(&vm))
        return (84);
    if (argument_managemnt(ac, av, &vm)) {
        vm_destroy(&vm);
        return (84);
    }
    vm_run(&vm);
    vm_destroy(&vm);
    return (0);
}