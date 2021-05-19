/*
** EPITECH PROJECT, 2020
** my_str_isprintable
** File description:
** return 1 if str is only composed of printable char
*/

unsigned char is_printable(char c)
{
    if (c >= 32)
        return (1);
    else
        return (0);
}

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_printable(str[i]))
            return (0);
    }
    return (1);
}
