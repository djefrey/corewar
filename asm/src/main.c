/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** asm main
*/

#include "asm.h"

int main(int ac, char **av)
{
    asms_t asms = {0};

    if (ac != 2)
        return (put_error("usage: ./asm file_name[.s]\n"));
    else if (my_strcmp(&av[1][my_strlen(av[1]) - 2], ".s") != 0)
        return (put_error("Can't read file\n"));
    return (compile(av[1], &asms));
}

int compile(char *input, asms_t *asms)
{
    if ((asms->fd_in = open(input, O_RDONLY)) < 0)
        return (put_error("Can't read file\n"));
    name_new_file(input, asms);
    if ((asms->fd_out = open(asms->output, O_CREAT | O_RDWR, 0644)) < 0)
        return (put_error("Fail with open\n"));
    else if (read_source_file(asms))
        return (84);
    asms->tab_f = my_str_to_asm_array(asms->file, 0, 0);
    reformate_tab(asms);
    return (parse_struct(asms));
}

void reformate_tab(asms_t *asms)
{
    for (int i = 0; asms->tab_f[i]; i++)
        reformate_string(asms, i);
    for (int i = 0; asms->tab_f[i]; i++) {
        if (asms->tab_f[0][0] != '.')
            ++asms->tab_f;
    }
    for (int i = 0; asms->tab_f[i]; i++) {
        if (asms->tab_f[i][0] == '\0')
            asms->tab_f[i] = 0;
    }
}

int put_error(char *str)
{
    my_putstr(str);
    return (84);
}