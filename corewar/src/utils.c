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
            return ((int) *(vm->memory + (value) % MEM_SIZE));
        case NONE:
            return (0);
    }
}