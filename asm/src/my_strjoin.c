/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** my_str_realloc
*/

#include <stdlib.h>

int my_strlen(char *mot);

char *my_strcat(char *dest, char const *src);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src);

char *my_strjoin(char *str, char *to_add)
{
    char *buffer = NULL;

    if (!str && !to_add)
        return (NULL);
    if (!str)
        return (my_strdup(to_add));
    if (!to_add)
        return (my_strdup(str));
    if (!(buffer = malloc(sizeof(*buffer) * (my_strlen(str) +
    my_strlen(to_add) + 1))))
        return (NULL);
    my_strcpy(buffer, str);
    my_strcat(buffer, to_add);
    return (buffer);
}