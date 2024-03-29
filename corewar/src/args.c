/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** argument handling
*/

#include <stdlib.h>
#include "my.h"
#include "corewar.h"
#include "vm.h"
#include "champion.h"
#include "process.h"

int argument_managemnt(int ac, char **av, vm_t *vm)
{
    setup_t setup;
    int id = -1;
    int addr = -1;

    argument_setup_struct(&setup);
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-') {
            if ((i + 1) >= ac ||
            argument_read_value(&id, &addr, av + i, vm))
                return (1);
            i++;
        } else if (argument_add_champion(&setup, &id, &addr, av[i]))
            return (1);
    }
    return (argument_create_champions(&setup, vm));
}

void argument_setup_struct(setup_t *setup)
{
    setup->nb = 0;
    for (int i = 0; i < 4; i++) {
        setup->ids[i] = -1;
        setup->addrs[i] = -1;
        setup->files[i] = NULL;
    }
}

int argument_read_value(int *id, int *addr, char **arg, vm_t *vm)
{
    int len = my_strlen(arg[0]);

    if (len == 2) {
        if (arg[0][1] == 'n') {
            if ((*id = str_to_int(arg[1])) < 0)
                return (1);
        } else if (arg[0][1] == 'a') {
            if ((*addr = str_to_int(arg[1]) % MEM_SIZE) < 0)
                return (1);
        }
    } else {
        if (!my_strcmp("-dump", arg[0])) {
            if ((vm->dump_cycles = str_to_int(arg[1])) < 1)
                return (1);
        } else
            return (1);
    }
    return (0);
}

int argument_add_champion(setup_t *setup, int *id, int *addr, char *arg)
{
    if (setup->nb == 4)
        return (1);
    setup->ids[setup->nb] = *id;
    setup->addrs[setup->nb] = *addr;
    setup->files[setup->nb] = arg;
    *id = -1;
    *addr = -1;
    setup->nb += 1;
    return (0);
}

int argument_create_champions(setup_t *setup, vm_t *vm)
{
    champion_t *champion;

    if (setup->nb != 4)
        return (1);
    for (int i = 0; i < 4; i++) {
        calculate_minimum_champions_ids(setup);
        if (setup->addrs[i] == -1)
            setup->addrs[i] = (MEM_SIZE / 4) * i;
        champion = champion_create(setup->files[i],
        setup->ids[i], setup->addrs[i], vm);
        if (!champion || !(process_create(champion, setup->addrs[i])))
            return (1);
        create_list(&(vm->champions), champion);
        #ifdef BONUS
        bonus_add_infotext(vm->bonus, setup->ids[i]);
        #endif
    }
    my_sort_list(&(vm->champions), &champion_cmp_ids);
    return (0);
}