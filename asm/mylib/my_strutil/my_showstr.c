/*
** EPITECH PROJECT, 2020
** my_showstr
** File description:
** show non-printable characters of a string
*/

#include "my.h"

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_printable(str[i])) {
            my_putchar('\\');
            if (str[i] < 17)
                my_putchar('0');
            my_putnbr_base(str[i], "0123456789abcdef");
        } else {
            my_putchar(str[i]);
        }
    }
    return (0);
}
