/*
** EPITECH PROJECT, 2021
** asm
** File description:
** reader
*/

#include "asm.h"

int get_file_size(int fd)
{
    int size;

    size = lseek(fd, 0L, SEEK_END);
    lseek(fd, 0L, SEEK_SET);
    return (size);
}

int read_source_file(asms_t *asms)
{
    int size = get_file_size(asms->fd_in);
    char *buff;

    if (size == 0)
        return (1);
    buff = malloc(sizeof(char) * size);
    read(asms->fd_in, buff, size);
    asms->file = buff;
    return (0);
}
