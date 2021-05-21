/*
** EPITECH PROJECT, 2021
** asm
** File description:
** utils
*/

#include "asm.h"

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