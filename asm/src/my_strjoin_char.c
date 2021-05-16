/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** my_str_realloc_one
*/

#include <stdlib.h>

int my_strlen(char *mot);

char *my_strjoin_char(char *str, char c)
{
    char *buffer;
    int i = 0;
    int j = 0;

    if (!str) {
        str = malloc(sizeof(char) * 1);
        str[0] = '\0';
    }
    buffer = malloc(sizeof(*buffer) * (my_strlen(str) + 2));
    while (str[i] != '\0') {
        buffer[i] = str[i];
        i++;
    }
    buffer[i] = c;
    buffer[i + 1] = '\0';
    return (buffer);
}