/*
** EPITECH PROJECT, 2021
** functions
** File description:
** funct1
*/

#include "asm.h"

char *coding_byte(char **tab, char *ret)
{
    for (int i = 2; tab[i]; i++) {
        if (tab[i][0] == DIRECT)
            ret = my_strmerge(ret, "01");
        else if (tab[i][0] == REGISTER)
            ret = my_strmerge(ret, "10");
        else
            ret = my_strmerge(ret, "11");
    }
    while(my_strlen(ret) < 8)
        ret = my_strmerge(ret, "0");
    return (ret);
}

char *coding_byte_first(char **tab)
{
    char *ret;

    if (tab[1][0] == DIRECT)
        ret = my_strdup("10");
    else if (tab[1][0] == REGISTER)
        ret = my_strdup("01");
    else
        ret = my_strdup("11");
    return (ret);
}

int pwr(int nb, int inc)
{
    int ret = 1;

    if (inc == 0)
        return (ret);
    for (; inc >= 1; inc--)
        ret *= nb;
    return (ret);
}

int bin_to_dec(int bin)
{
    int dec = 0;
    int i = 0;
    int rest = 0;

    while (bin != 0) {
        rest = bin % 10;
        bin /= 10;
        dec += rest * pwr(2, i);
        i++;
    }
    return (dec);
}

void sti(asms_t *asms, char **tab)
{
    int a = 0x0b;
    char *str;
    int dec;

    if (tab[1] == NULL || tab[2] == NULL || tab[3] != NULL
    || tab[1][0] != REGISTER)
        exit (84);
    print_reg(a, asms);
    str = coding_byte_first(tab);
    str = coding_byte(tab, str);
    dec = str_to_int(str);
    dec = bin_to_dec(dec);
    print_reg(str_to_int(tab[1]), asms);
    double_print_register(asms, tab, 1);
    double_print_ind(asms, tab, 1);
    its_first(asms, tab, 1);
    its_last(asms, tab, 1);
    return;
}