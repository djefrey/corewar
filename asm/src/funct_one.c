/*
** EPITECH PROJECT, 2021
** functions
** File description:
** funct1
*/

#include "../include/asm.h"

void live(asms_t *asms, char **tab)
{
    int a = 0x01;

    if (tab[1] == NULL || tab[1][0] == ' ' || tab[1][0] == '\0'
    || tab[2] != NULL)
        exit (84);
    print_reg(a, asms);
    indir_or_dir(tab[1], asms);
}

void add(asms_t *asms, char **tab)
{
    int a = 0x02;

    if (tab[1] == NULL || tab[2] == NULL || tab[3] != NULL || tab[4] != NULL)
        exit (84);
    print_reg(a, asms);
    print_reg(bin_to_dec(my_getnbr("01010100")), asms);
    print_reg(my_getnbr(tab[1]), asms);
    print_reg(my_getnbr(tab[2]), asms);
    print_reg(my_getnbr(tab[3]), asms);
}

void st(asms_t *asms, char **tab)
{
    int a = 0x03;
    char *str;
    int dec;

    if (tab[1] == NULL || tab[2] == NULL || tab[3] != NULL ||
    tab[1][0] != REGISTER)
        exit (84);
    print_reg(a, asms);
    str = coding_byte_first(asms, tab);
    str = coding_byte(asms, tab, str);
    dec = my_getnbr(str);
    dec = bin_to_dec(dec);
    print_reg(dec, asms);
    print_reg(my_getnbr(tab[1]), asms);
    indir_or_dir(tab[2], asms);
    return;
}

void ld(asms_t *asms, char **tab)
{
    int a = 0x04;
    char *str;
    int dec;

    if (tab[1] == NULL || tab[2] == NULL || tab[2][0] != 'r' || tab[3] != NULL)
        exit (84);
    print_reg(a, asms);
    str = coding_byte_first(asms, tab);
    str = coding_byte(asms, tab, str);
    dec = my_getnbr(str);
    dec = bin_to_dec(dec);
    print_reg(dec, asms);
    indir_or_dir(tab[1], asms);
    print_reg(my_getnbr(tab[2]), asms);
}

void sub(asms_t *asms, char **tab)
{
    int a = 0x05;

    if (tab[1] == NULL || tab[2] == NULL || tab[3] != NULL || tab[4] != NULL)
        exit (84);
    print_reg(a, asms);
    print_reg(bin_to_dec(my_getnbr("01010100")), asms);
    print_reg(my_getnbr(tab[1]), asms);
    print_reg(my_getnbr(tab[2]), asms);
    print_reg(my_getnbr(tab[3]), asms);
}