/*
** EPITECH PROJECT, 2020
** swap.c
** File description:
** swap the content of two strings pointers
*/

void my_strswap(char **a, char **b)
{
    char *c = *a;

    *a = *b;
    *b = c;
}
