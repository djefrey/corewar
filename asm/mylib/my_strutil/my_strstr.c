/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** find the first occurence of a string in an other
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int length_str = my_strlen(str);
    int length_find = my_strlen(to_find);
    int offset = 0;

    while (length_find + offset <= length_str) {
        for (int i = 0; i < length_find; i++) {
            if (str[offset + i] != to_find[i])
                break;
            else if (i == length_find - 1) {
                return (str + offset);
            }
        }
        offset++;
    }
    return ((void*) 0);
}