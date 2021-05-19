/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
** put every letter to upcase
*/

char *my_strupcase(char *str)
{
    char c;

    for (int i = 0; str[i] != '\0'; i++) {
        c = str[i];
        if (c >= 'a' && c <= 'z')
            str[i] -= 32;
    }
    return (str);
}
