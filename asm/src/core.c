/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** core function
*/

#include "asm.h"
#include "op.h"

/*
** Read file and write operations in machine code
*/
int prog(asms_t *asms)
{
    char **line;
    op_t *op;

    for (int i = 0; asms->mega_tab[i]; i++) {
        line = asms->mega_tab[i];
        op = get_op_by_mnemonique(line[0]);
        if (op)
            write_operation_in_output_file(line, op, asms);
    }
    return (0);
}

/*
** Set asms->output to the path of the output
*/
void name_new_file(char *input, asms_t *asms)
{
    char *output = NULL;
    int len = my_strlen(input);
    int i = 0;
    int size = 0;

    input[len - 2] = '\0';
    for (i = len - 2; input[i] != '/' && i >= 0; i--);
    i++;
    size = len - 1 - i;
    if (!(output = malloc(sizeof(char) * (size + 5))))
        exit(84);
    my_strcpy(output, input + i);
    asms->output = my_strcat(output, ".cor");
}

void header(asms_t *asms, info_t *info)
{
    header_t *header;

    header->magic = COREWAR_EXEC_MAGIC;
    my_strcpy(header->prog_name, info->name);
    my_strcpy(header->comment, info->comment);
    header->prog_size = asms->size;
    write(asms->fd_out, header, sizeof(header_t));
}