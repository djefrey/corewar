/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** capitalize every letter at start of a word
*/

static unsigned char is_letter_or_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    else
        return (0);
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0 || !is_letter_or_digit(str[i - 1])) {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] -= 32;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
    return (str);
}
