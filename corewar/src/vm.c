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

void vm_run(vm_t *vm)
{
    champion_t *champion;
    int living = 4;

    while (living > 1) {
        living = 0;
        vm->cycles++;
        for (list_t *list = vm->champions; list; list = list->next) {
            champion = (champion_t*) list->data;
            champion_update(champion, vm);
            living += !champion->dead;
        }
        if (vm->dump_cycles > -1 && vm->cycles % vm->dump_cycles == 0)
            vm_dump(vm);
    }
}

int vm_write_file_in_memory(vm_t *vm, int fd, int addr, int size)
{
    if ((addr + size) > MEM_SIZE) {
        read(fd, vm->memory + addr, size % MEM_SIZE);
        size -= size % MEM_SIZE;
        if (size > MEM_SIZE)
            return (1);
        read(fd, vm->memory, size);
    } else
        read(fd, vm->memory + addr, size);
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

void vm_destroy(vm_t *vm)
{
    list_t *next;

    for (list_t *list = vm->champions; list; list = next) {
        next = list->next;
        champion_destroy((champion_t*) list->data);
    }
    free(vm->memory);
}