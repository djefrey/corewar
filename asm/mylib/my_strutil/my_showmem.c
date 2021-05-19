/*
** EPITECH PROJECT, 2020
** my_showmem
** File description:
** show a memory dump of a given string
*/

#include "my.h"

static unsigned int get_nbr_length(long nb)
{
    int div = 1;
    int length = 1;

    while (nb / div > 9) {
        length++;
        div *= 10;
    }
    return length;
}

static void print_line_nbr(int offset)
{
    int line_nbr = offset / 16 * 10;
    int nbr_length = get_nbr_length(line_nbr);

    for (int i = 0; i < 8 - nbr_length; i++) {
        my_putchar('0');
    }
    if (nbr_length == 1)
        my_putchar('0');
    my_putnbr_base(line_nbr, "0123456789");
    my_putchar(':');
    my_putchar(' ');
}

static void print_line_hex(char const *str, int offset, int size)
{
    for (int i = 0; i < 16; i++) {
        if (offset + i < size) {
            unsigned char c = str[offset + i];
            if (c == '\0') {
                my_putchar('0');
                my_putchar('0');
            } else if (c < 17)
                my_putchar('0');
            my_putnbr_base(c, "0123456789abcdef");
        } else {
            my_putchar(' ');
            my_putchar(' ');
        }
        if (i > 0 && i % 2 == 1)
            my_putchar(' ');
    }
    my_putchar(' ');
}

static void print_line_str(char const *str, int offset, int size)
{
    for (int i = 0; i < 16; i++) {
        if (offset + i < size) {
            char c = str[offset + i];
            if (is_printable(c)) {
                my_putchar(c);
            } else {
                my_putchar('.');
            }
        } else {
            my_putchar('.');
        }
    }
}

int my_showmem(char const *str, int size)
{
    for (int i = 0; i < size; i += 16) {
        print_line_nbr(i);
        print_line_hex(str, i, size);
        print_line_str(str, i, size);
        my_putchar('\n');
    }
    return (0);
}
