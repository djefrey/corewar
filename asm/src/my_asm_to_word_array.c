/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday08-thomas.parenteau
** File description:
** my_str_to_word_array
*/

#include "asm.h"

static int check_carac(int carac)
{
    if (carac == ',' || carac == ' ')
        return (1);
    return (0);
}

static int jump_non_alpha(char const *str, int k)
{
    while (check_carac(str[k + 1]) == 1 || str[k + 1] == '#')
        k++;
    return (k);
}

static int len_of_word(char const *str, int k)
{
    int len = 0;

    while (str[k] != '\0') {
        if (check_carac(str[k + 1]) == 1)
            return (len + 1);
        k++;
        len++;
    }
    return (len + 1);
}

static int total_word(char const *str)
{
    int i = 0;
    int carac = 0;

    while (str[i] != '\0') {
        if (check_carac(str[i]) == 1 && check_carac(str[i + 1]) != 1)
            carac++;
        i++;
    }
    return (carac);
}

char **my_asm_to_word_array(char const *str, int j, int k)
{
    char **tab = malloc(sizeof(char *) * (total_word(str) + 1));
    int l = 0;
    while (j < total_word(str) + 1) {
        k = jump_non_alpha(str, k);
        tab[j] = malloc(sizeof(char) * (len_of_word(str, k) + 1));
        while (str[k] != '\0' && check_carac(str[k]) != 1) {
            tab[j][l] = str[k];
            k++;
            l++;
        }
        tab[j][l] = '\0';
        j++;
        k++;
        l = 0;
    }
    tab[j] = 0;
    return (tab);
}
