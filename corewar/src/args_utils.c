/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** arguments utils
*/

#include "corewar.h"
#include "champion.h"
#include "vm.h"

void calculate_minimum_champions_ids(setup_t *setup)
{
    int assigned_ids = 0;
    int smallest = 1;

    while (assigned_ids != 4) {
        assigned_ids = 0;
        smallest = 1;
        for (int i = 0; i < 4; i++) {
            if (setup->ids[i] == smallest) {
                smallest++;
                i = -1;
            }
        }
        for (int i = 0; i < 4; i++) {
            if (setup->ids[i] == -1) {
                setup->ids[i] = smallest;
                break;
            } else
                assigned_ids++;
        }
    }
}

void calculate_optimise_addresses(setup_t *setup)
{
    int already_assigned = 0;
    int assigned_addrs[4] = {0};

    for (int i = 0; i < 4; i++) {
        if (setup->addrs[i] > -1) {
            assigned_addrs[already_assigned] = setup->addrs[i];
            already_assigned++;
        }
    }
}

void champion_cmp_ids(void *data1, void *data2)
{
    champion_t *champion1 = (champion_t*) data1;
    champion_t *champion2 = (champion_t*) data2;

    return (champion1->id - champion2->id);
}