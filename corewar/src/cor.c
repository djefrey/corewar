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

void open_cor_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    unsigned int len;
    header_t *header;

    if (fd == -1)
        return;
    len = get_file_size(fd);
    header = read_header(fd, len);
    close(fd);
    free(header);
}

header_t *read_header(int fd, int len)
{
    header_t *header;

    else if (!(header = malloc(sizeof(header_t))) || len < sizeof(header_t)) {
        close(fd);
        return (NULL);
    }
    read(fd, header, sizeof(header_t));
    return (header);
}