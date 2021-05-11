/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** argument handling
*/

#include "my.h"
#include "vm.h"
#include "champion.h"

int champ_checker(int ac, char **av, int i, vm_t *vm)
{
    int id = 0;
    int addr = 0;
    champion_t *champ;

    if (my_strcmp(av[i], "-n")) {
        i += 2;
        id = my_getnbr(av[i - 1]);
    } else if (my_strcmp(av[i], "-a")) {
        i += 2;
        addr = my_getnbr(av[i - 1]);
    } else {
        if (!(champ = champion_create(av[i - 1], id, addr, vm)))
            vm_destroy(vm);
            exit(84);
        }
        create_list(&(vm->champions), champ);
    return (i);
}

int argument_managemnt(int ac, char **av, vm_t *vm)
{
    for (int i = 1; i < ac; i++) {
        if (my_strcmp(av[i], "-dump")) {
            i += 1;
            vm->dump_cycles = my_getnbr(av[i]);
        }
        i = champ_checker(ac, av, i + 1, vm);
    }
}
