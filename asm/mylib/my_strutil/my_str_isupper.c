/*
** EPITECH PROJECT, 2020
** my_str_isupper
** File description:
** return 1 if str is only composed of upper alphabetic characters
*/

unsigned char is_up_letter(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    else
        return (0);
}

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_up_letter(str[i]))
            return (0);
    }
    return (1);
}
