/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** vm
*/

#include <stdlib.h>
#include <unistd.h>
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