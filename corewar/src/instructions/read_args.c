/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** args readers
*/

#include "corewar.h"
#include "vm.h"

int read_register_arg(int *addr, vm_t *vm)
{
    char buff[sizeof(int)] = {0};

    buff[0] = *(vm->memory + *addr);
    *addr = (*addr + 1) % MEM_SIZE;
    return (*((int*) buff) - 1);
}

int read_direct_arg(int *addr, char indexes, vm_t *vm)
{
    int value = !indexes
    ? read_int(*addr, DIR_SIZE, vm)
    : read_int(*addr, IND_SIZE, vm);

    *addr = !indexes
    ? (*addr + DIR_SIZE) % MEM_SIZE
    : (*addr + IND_SIZE) % MEM_SIZE;
    return (value);
}

int read_indirect_arg(int *addr, vm_t *vm)
{
    int value = read_int(*addr, IND_SIZE, vm);

    *addr = (*addr + IND_SIZE) % MEM_SIZE;
    return (value);
}