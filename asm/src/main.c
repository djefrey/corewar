/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** asm main
*/

#include "../include/asm.h"

int compile(char *input)
{
    char *output = malloc(my_strlen(input) + 3);
    int fd_input;
    int fd_output;

    output = my_strcat(output, &input[my_strlen(input) - 3]);
    output = my_strcat(output, ".cor");
    if ((fd_input = open(input, O_RDONLY)) < 0)
        return (put_error("Can't read file\n"));
    if ((fd_output = open(output, O_CREAT | O_RDWR, 0644)) < 0)
        return (put_error("Fail with open\n"));
}

int put_error(char *str)
{
    my_putstr(str);
    return (84);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (put_error("usage: ./asm file_name[.s]\n"));
    if (my_strcpm(&av[1][my_strlen(av[1]) - 3], ".s") != '0')
        return (put_error("Can't read file\n"));
    return (compile(av[1]));
}
