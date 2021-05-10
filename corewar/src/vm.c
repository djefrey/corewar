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

void vm_update(vm_t *vm)
{

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

void vm_destroy(vm_t *vm)
{
    free(vm->memory);
    free(vm);
}