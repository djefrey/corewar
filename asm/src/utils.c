/*
** EPITECH PROJECT, 2021
** B-CPE-201-STG-2-1-corewar-thomas.parenteau
** File description:
** utils
*/

#include "../include/asm.h"

void its_last(asms_t *asms, char **tab, int inc)
{
    if (tab[1 + inc][0] != REGISTER && tab[2 + inc][0] == REGISTER) {
        indir_or_dir(tab[1 + inc], asms);
        print_reg(my_getnbr(tab[2 + inc]), asms);
    }
    return;
}

void its_first(asms_t *asms, char **tab, int inc)
{
    if (tab[1 + inc][0] == REGISTER && tab[2 + inc][0] != REGISTER) {
        print_reg(my_getnbr(tab[1 + inc]), asms);
        indir_or_dir(tab[2 + inc], asms);
    }
    return;
}

void double_print_register(asms_t *asms, char **tab, int inc)
{
    if (tab[1 + inc][0] == REGISTER && tab[2 + inc][0] == REGISTER) {
        print_reg(my_getnbr(tab[1 + inc]), asms);
        print_reg(my_getnbr(tab[2 + inc]), asms);
    }
    return;
}

void double_print_ind(asms_t *asms, char **tab, int inc)
{
    if (tab[1 + inc][0] != REGISTER && tab[2 + inc][0] != REGISTER) {
        indir_or_dir(tab[1 + inc], asms);
        indir_or_dir(tab[2 + inc], asms);
    }
    return;
}