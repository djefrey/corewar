/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** asm parsing
*/

#include "../include/asm.h"

char *get_name_comment(char *str)
{
    char *result = malloc((my_strlen(str)));
    int i = 0;
    int j = 0;

    for (i; str[i] != '"'; ++i);
    i++;
    if (str[i] == ' ')
        ++i;
    for (i; str[i] != '"'; ++i) {
            result[j] = str[i];
            j++;
    }
    if (result[j - 1] == ' ')
        result[j - 1] = '\0';
    else
        result[j] = '\0';
    return (result);
}

int parse_struct(asms_t *asms)
{
    info_t *info = malloc(sizeof(info_t));

    info->name = get_name_comment(asms->tab_f[0]);
    info->comment = get_name_comment(asms->tab_f[1]);
    printf("%s, %s\n", info->name, info->comment);
}