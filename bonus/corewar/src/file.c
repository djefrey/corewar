/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** file utils
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *read_file(char *path)
{
    FILE *file = fopen(path, "r");
    char *str = NULL;
    size_t len = 0;
    char *buf = NULL;
    size_t n = 0;
    ssize_t line_len = 0;

    if (!file)
        return (NULL);
    while ((line_len = getline(&buf, &n, file)) > -1) {
        str = realloc(str, len + line_len + 1);
        if (!str)
            return (NULL);
        strcpy(str + len, buf);
        free(buf);
        buf = NULL;
        len += line_len;
    }
    fclose(file);
    str[len] = 0;
    return (str);
}