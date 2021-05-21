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

void name_new_file(char *input, asms_t *asms)
{
    char *output = malloc(my_strlen(input) + 3);
    int len = my_strlen(input);

    for (; input[len] != '/' && len >= 0; len--);
    asms->output = my_strcat(output, input + len + 1);
    asms->output = my_strcat(output, ".cor");
}