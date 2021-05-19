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