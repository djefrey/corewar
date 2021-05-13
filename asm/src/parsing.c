/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** asm parsing
*/

#include "../include/asm.h"

void reformate_string(asms_t *asms, int i)
{
    for (; asms->tab_f[i][0] == ' '; ++asms->tab_f[i]);
}

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
    int i = 0;

    info->name = get_name_comment(asms->tab_f[0]);
    ++asms->tab_f;
    info->comment = get_name_comment(asms->tab_f[0]);
    ++asms->tab_f;
    for (; asms->tab_f[i]; ++i);
    asms->mega_tab = malloc(sizeof(char **) * i + 1);
    for (i = 0; asms->tab_f[i]; ++i)
        asms->mega_tab[i] = my_asm_to_word_array(asms->tab_f[i], 0, 0);
    return (prog(asms));
}