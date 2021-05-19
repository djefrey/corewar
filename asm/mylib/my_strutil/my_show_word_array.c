/*
** EPITECH PROJECT, 2020
** my_show_word_array
** File description:
** display the content of a string array
*/

#include "my.h"

int my_show_word_array(char **tab)
{
    while (*tab != 0) {
        my_putstr(*tab);
        my_putchar('\n');
        tab++;
    }
    return (0);
}
