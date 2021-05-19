/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** return 1 if str is only composed of lower alphabetic characters
*/

unsigned char is_low_letter(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    else
        return (0);
}

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_low_letter(str[i]))
            return (0);
    }
    return (1);
}
