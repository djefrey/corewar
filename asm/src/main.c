/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** asm main
*/

#include "asm.h"

int main(int ac, char **av)
{
    asms_t asms = {0};

    if (ac != 2)
        return (put_error("usage: ./asm file_name[.s]\n"));
    else if (my_strcmp(&av[1][my_strlen(av[1]) - 2], ".s") != 0)
        return (put_error("Can't read file\n"));
    return (init_compilation(av[1], &asms));
}

int init_compilation(char *input, asms_t *asms)
{
    int in_fd = open(input, O_RDONLY);
    char *file_content;

    if (in_fd == -1)
        return (put_error("Can't read input file\n"));
    open_output_file(input, asms);
    if (!(file_content = read_source_file(in_fd)))
        return (84);
    close(in_fd);
    asms->lines = split_file(file_content);
    precompile(asms);
    compile(asms);
    free_split(asms->lines);
    free(file_content);
    close(asms->fd_out);
    return (0);
}

int put_error(char *str)
{
    my_putstr(str);
    return (84);
}