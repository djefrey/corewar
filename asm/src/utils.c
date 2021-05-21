/*
** EPITECH PROJECT, 2021
** asm
** File description:
** utils
*/

#include <stdlib.h>
#include "my.h"
#include "asm.h"

static void check_cmd_validity(char *cmd_name, char *line, int *i)
{
    for (; line[*i]; *i += 1) {
        if (line[*i] != '.')
            continue;
        else if (my_strcmp(cmd_name, line + *i)) {
            my_printf("Wrong command on line %i %s\n", *i);
            exit(84);
        } else
            break;
    }
    if (!line[*i]) {
        my_printf("Missing command on line %i\n", *i);
        exit(84);
    }
}

static void copy_to_buffer(char *str, char *buff, int size, int buff_size)
{
    for (int i = 0; i < buff_size; i++) {
        buff[i] = i < size ? str[i] : 0;
    }
}

char *get_cmd(char *cmd_name, char *line, char *buff, int buff_size)
{
    char *value;
    int start = 0;
    int size = 0;

    check_cmd_validity(cmd_name, line, &start);
    for (; line[start] != '"' && line[start]; start++);
    if (!line[start])
        exit(put_error("Missing command value\n"));
    start++;
    for (; line[start + size] != '"' && line[start + size]; size++);
    if (!line[start + size])
        exit(put_error("Invalid command value\n"));
    if (!(value = malloc(sizeof(char) * (size))))
        exit(84);
    copy_to_buffer(value, buff, size, buff_size);
    return (value);
}

int str_to_int(char *str)
{
    char neg = 0;
    int value = 0;

    if (*str == '-') {
        neg = 1;
        str++;
    }
    while (*str) {
        if (*str < '0' || *str > '9')
            return (0);
        value = value * 10 + (*str - '0');
        str++;
    }
    return (neg ? -value : value);
}