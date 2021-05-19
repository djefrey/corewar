/*
** EPITECH PROJECT, 2021
** functions
** File description:
** funct1
*/

#include "asm.h"

void and(asms_t *asms, char **tab)
{
    int a = 0x06;
    int str;
    int dec;

    if (tab[1] == NULL || tab[2] == NULL || tab[3] == NULL || tab[4] != NULL
    || tab[3][0] != 'r')
        exit (84);
    print_reg(a, asms);
    str = coding_byte_first(asms, tab);
    str = coding_byte(asms, tab, str);
    dec = str_to_int(str);
    dec = bin_to_dec(dec);
    double_print_register(asms, tab, 0);
    double_print_ind(asms, tab, 0);
    its_first(asms, tab, 0);
    its_last(asms, tab, 0);
    print_reg(str_to_int(tab[3]), asms);
    return;
}

void or(asms_t *asms, char **tab)
{
    int a = 0x07;
    int str;
    int dec;

    if (tab[1] == NULL || tab[2] == NULL || tab[3] == NULL || tab[4] != NULL
    || tab[3][0] != 'r')
        exit (84);
    print_reg(a, asms);
    str = coding_byte_first(asms, tab);
    str = coding_byte(asms, tab, str);
    dec = str_to_int(str);
    dec = bin_to_dec(dec);
    double_print_register(asms, tab, 0);
    double_print_ind(asms, tab, 0);
    its_first(asms, tab, 0);
    its_last(asms, tab, 0);
    print_reg(str_to_int(tab[3]), asms);
    return;
}

void xor(asms_t *asms, char **tab)
{
    int a = 0x08;
    int str;
    int dec;

    if (tab[1] == NULL || tab[2] == NULL || tab[3] == NULL || tab[4] != NULL
    || tab[3][0] != 'r')
        exit (84);
    print_reg(a, asms);
    str = coding_byte_first(asms, tab);
    str = coding_byte(asms, tab, str);
    dec = str_to_int(str);
    dec = bin_to_dec(dec);
    double_print_register(asms, tab, 0);
    double_print_ind(asms, tab, 0);
    its_first(asms, tab, 0);
    its_last(asms, tab, 0);
    print_reg(str_to_int(tab[3]), asms);
    return;
}

void aff(asms_t *asms, char **tab)
{
    int a = 0x10;
    int str;
    int dec;

    if (tab[1] == NULL || tab[1][0] != REGISTER || tab[2] != NULL)
        exit (84);
    print_reg(a, asms);
    str = coding_byte_first(asms, tab);
    str = coding_byte(asms, tab, str);
    dec = str_to_int(str);
    dec = bin_to_dec(dec);
    print_reg(dec, asms);
    print_reg(str_to_int(tab[1]), asms);
    return;
}

void lld(asms_t *asms, char **tab)
{
    int a = 0x0d;
    int str;
    int dec;

    if (tab[1] == NULL || tab[2] == NULL || tab[3] != NULL || tab[2][0] != 'r')
        exit (84);
    print_reg(a, asms);
    str = coding_byte_first(asms, tab);
    str = coding_byte(asms, tab, str);
    dec = str_to_int(str);
    dec = bin_to_dec(dec);
    print_reg(dec, asms);
    indir_or_dir(tab[1], asms);
    print_reg(str_to_int(tab[2]), asms);
    return;
}