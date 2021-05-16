/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** asm main
*/

#include "../include/asm.h"

int put_error(char *str)
{
    my_putstr(str);
    return (84);
}

void reformate_tab(asms_t *asms)
{
    for (int i = 0; asms->tab_f[i]; i++)
        reformate_string(asms, i);
    for (int i = 0; asms->tab_f[i]; i++) {
        if (asms->tab_f[0][0] != '.') {
            ++asms->tab_f;
        }
    }
    for (int i = 0; asms->tab_f[i]; i++) {
        if (asms->tab_f[i][0] == '\0') {
            asms->tab_f[i] = 0;
        }
    }
}

int compile(char *input, asms_t *asms)
{
    char *output = malloc(my_strlen(input) + 3);

    if ((asms->fd_in = open(input, O_RDONLY)) < 0)
        return (put_error("Can't read file\n"));
    input[my_strlen(input) - 2] = '\0';
    asms->output = my_strcat(output, input);
    asms->output = my_strcat(output, ".cor");
    if ((asms->fd_out = open(output, O_CREAT | O_RDWR, 0644)) < 0)
        return (put_error("Fail with open\n"));
    if (read(asms->fd_in, asms->file, 4095) == -1)
        return (put_error("Fail with read\n"));
    asms->file = realloc(asms->file, (my_strlen(asms->file) + 1));
    asms->tab_f = my_str_to_word_array(asms->file, 0, 0);
    reformate_tab(asms);
    return (parse_struct(asms));
}

asms_t *init_struct(void)
{
    asms_t *asms = malloc(sizeof(asms_t));

    asms->fd_in = 0;
    asms->fd_out = 0;
    asms->output = NULL;
    asms->file = malloc(sizeof(char) * 4096);
    asms->tab_f = NULL;
    return (asms);
}

int main(int ac, char **av)
{
    asms_t *asms = init_struct();

    if (ac != 2)
        return (put_error("usage: ./asm file_name[.s]\n"));
    if (my_strcmp(&av[1][my_strlen(av[1]) - 2], ".s") != 0)
        return (put_error("Can't read file\n"));
    return (compile(my_strdup(av[1]), asms));
}
