/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** asm
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "corewar.h"

void read_header(header_t *header, int fd, unsigned int len)
{
    int magic_number;
    int prog_size;

    if (len < sizeof(header_t))
        return;
    read(fd, header, sizeof(header_t));
    inverse_endian(&(header->magic_number), &magic_number, sizeof(int));
    inverse_endian(&(header->prog_size), &prog_size, sizeof(int));
    header->magic_number = magic_number;
    header->prog_size = prog_size;
}