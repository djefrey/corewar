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
    int value = 0;

    if (addr < 0)
        addr += MEM_SIZE;
    for (int i = 0; i < size; i++)
        buff[sizeof(int) - 1 - i - off] =
        *(vm->memory + (addr + i) % MEM_SIZE);
    value = *((int*) buff);
    if (size == sizeof(char))
        return ((char) value);
    else if (size == sizeof(short))
        return ((short) value);
    else
        return (value);
}

void write_int(int addr, int value, int size, vm_t *vm)
{
    char c;

    if (addr < 0)
        addr += MEM_SIZE;
    for (int i = 0; i < size; i++) {
        c = (value & (0xFF << i * 8)) >> i * 8;
        *(vm->memory + (addr + size - 1 - i) % MEM_SIZE) = c;
    }
}