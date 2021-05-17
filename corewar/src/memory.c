/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** memory
*/

#include "corewar.h"
#include "vm.h"

int read_int(int addr, int size, vm_t *vm)
{
    char buff[sizeof(int)] = {0};
    int off = 4 - size;

    for (int i = 0; i < size; i++)
        buff[sizeof(int) - 1 - i - off] = *(vm->memory + (addr + i) % MEM_SIZE);
    return (*((int*) buff));
}

void write_int(int addr, int value, int size, vm_t *vm)
{
    char c;

    for (int i = 0; i < size; i++) {
        c = (value & (0xFF << i * 8)) >> i * 8;
        *(vm->memory + (addr + size - 1 - i) % MEM_SIZE) = c;
    }
}