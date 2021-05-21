/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** vm
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "corewar.h"
#include "vm.h"
#include "process.h"
#include "champion.h"

int vm_init(vm_t *vm)
{
    #ifdef BONUS
    bonus_t *bonus = bonus_create();
    #endif
    char *memory = malloc(sizeof(char) * MEM_SIZE);

    if (!memory)
        return (1);
    vm->memory = memory;
    vm->cycles = 0;
    vm->dead_cycles = CYCLE_TO_DIE;
    vm->dump_cycles = -1;
    vm->last_live = -1;
    vm->nb_lives = 0;
    vm->champions = NULL;
    #ifdef BONUS
    vm->bonus = bonus;
    #endif
    for (int i = 0; i < MEM_SIZE; i++)
        *(memory + i) = 0;
    return (0);
}

void vm_dump(vm_t *vm)
{
    unsigned char value_str[4] = {'0', '0', ' ', '\n'};
    unsigned char value;

    for (int i = 0; i < MEM_SIZE; i++) {
        if (i % 32 == 0) {
            if (i == 0)
                write(1, "0    : ", 7);
            else
                my_printf("%-5X: ", i);
        }
        value =  *(vm->memory + i);
        value_str[0] = value / 16 < 10 ?
        '0' + value / 16 : 'A' + value / 16 - 10;
        value_str[1] = value % 16 < 10 ?
        '0' + value % 16 : 'A' + value % 16 - 10;
        if (i % 32 == 31)
            write(1, value_str, 4);
        else
            write(1, value_str, 3);
    }
}

void vm_print_winner(vm_t *vm)
{
    champion_t *last_live = get_champion_by_id(vm, vm->last_live);

    if (last_live)
        my_printf("The player %i (%s) has won.\n",
        vm->last_live, last_live->header->prog_name);
    else
        my_printf("Nobody won.\n");
}

void vm_destroy(vm_t *vm)
{
    list_t *next;

    for (list_t *list = vm->champions; list; list = next) {
        next = list->next;
        champion_destroy((champion_t*) list->data);
    }
    free(vm->memory);
    #ifdef BONUS
    bonus_destroy(vm->bonus);
    #endif
}