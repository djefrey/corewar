/*
** EPITECH PROJECT, 2021
** B-CPE-201-STG-2-1-corewar-thomas.parenteau
** File description:
** print_file
*/

#include "asm.h"

/*
** Inverse the endian of the given DATA of size SIZE
*/
void inverse_endian(void *data, size_t size)
{
    char buff[size];

    for (unsigned i = 0; i < size; i++)
        (buff)[size - i - 1] = ((char*) data)[i];
    for (unsigned i = 0; i < size; i++)
        ((char *) data)[i] = buff[i];
}

/*
** Write DATA of size SIZE into FD
** Inverse flag to inverse endian
*/
void write_data(int fd, void *value,
size_t size, char inverse)
{
    if (inverse)
        inverse_endian(value, size);
    write(fd, value, size);
}
