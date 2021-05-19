/*
** EPITECH PROJECT, 2021
** B-CPE-201-STG-2-1-corewar-thomas.parenteau
** File description:
** utils
*/

#include "asm.h"

void its_last(asms_t *asms, char **tab, int inc)
{
    if (tab[1 + inc][0] != REGISTER && tab[2 + inc][0] == REGISTER) {
        indir_or_dir(tab[1 + inc], asms);
        print_reg(str_to_int(tab[2 + inc]), asms);
    }
}

void its_first(asms_t *asms, char **tab, int inc)
{
    if (tab[1 + inc][0] == REGISTER && tab[2 + inc][0] != REGISTER) {
        print_reg(str_to_int(tab[1 + inc]), asms);
        indir_or_dir(tab[2 + inc], asms);
    }
}

void double_print_register(asms_t *asms, char **tab, int inc)
{
    if (tab[1 + inc][0] == REGISTER && tab[2 + inc][0] == REGISTER) {
        print_reg(str_to_int(tab[1 + inc]), asms);
        print_reg(str_to_int(tab[2 + inc]), asms);
    }
}

void double_print_ind(asms_t *asms, char **tab, int inc)
{
    if (tab[1 + inc][0] != REGISTER && tab[2 + inc][0] != REGISTER) {
        indir_or_dir(tab[1 + inc], asms);
        indir_or_dir(tab[2 + inc], asms);
    }
}

int str_to_int(char *str)
{
    int value = 0;

    while (*str) {
        if (*str < '0' || *str > '9')
            return (-1);
        value = value * 10 + (*str - '0');
        str++;
    }
    return (value);
}