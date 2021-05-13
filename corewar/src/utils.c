/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** utils
*/

#include <unistd.h>
#include "corewar.h"
#include "vm.h"
#include "process.h"

int get_file_size(int fd)
{
    int size;

    size = lseek(fd, 0L, SEEK_END);
    lseek(fd, 0L, SEEK_SET);
    return (size);
}

void inverse_endian(void *data, void *buf, size_t size)
{
    for (unsigned i = 0; i < size; i++)
        ((char*) buf)[size - i - 1] = ((char*) data)[i];
}

int get_arg_real_value(argument_t arg, int value, process_t *process, vm_t *vm)
{
    switch (arg) {
        case REGISTER:
            return (process->registers[value]);
        case DIRECT:
            return (value);
        case INDIRECT:
            return (read_int((process->pc + value % IDX_MOD)
            % MEM_SIZE, 1, vm));
        case NONE:
            return (0);
    }
    return (0);
}

int read_int(int addr, int size, vm_t *vm)
{
    char buff[sizeof(int)] = {0};
    int off = 4 - size;

    for (int i = 0; i < size; i++)
        buff[sizeof(int) - 1 - i - off] = *(vm->memory + (addr + i) % MEM_SIZE);
    return (*((int*) buff));
}

int str_to_int(char *str)
{
    int value = 0;

    while (*str) {
        if (*str < '0' || *str > '9')
            return (-1);
        value = value * 10 + (*str - '0');
        str++;
    }
    return (value);
}