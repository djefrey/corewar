/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** core function
*/

#include "asm.h"
#include "inst.h"

int prog(asms_t *asms)
{
    char **tab;
    void (*func[])(asms_t *, char **) = {live, add, sub, ld, st,
    and, or, xor, aff, lld, sti, NULL};

    for (int i = 0; asms->mega_tab[i]; i++) {
        for (int j = 0; j < 11; j++) {
            if (my_strcmp(asms->mega_tab[i][0], inst[j]) == 0) {
                tab = asms->mega_tab[i];
                func[j](asms, tab);
            }
        }
    }
    return (0);
}