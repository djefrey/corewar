/*
** EPITECH PROJECT, 2020
** my_strloccase
** File description:
** puts every letter in lowercase
*/

char *my_strlowcase(char *str)
{
    char c;

    for (int i = 0; str[i] != '\0'; i++) {
        c = str[i];
        if (c >= 'A' && c <= 'Z')
            str[i] += 32;
    }
    return (str);
}
