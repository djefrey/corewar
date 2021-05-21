/*
** EPITECH PROJECT, 2021
** asm
** File description:
** operations
*/

#include "asm.h"

/*
** Return the pointer of the value in op_t array with the given mnemonique
*/
op_t *get_op_by_mnemonique(char *mnemonique)
{
    int len = my_strlen(mnemonique);

    for (int i = 0; i < NB_OPS; i++) {
        if (!my_strcmp(mnemonique, OPS[i].mnemonique)
        && len == my_strlen(OPS[i].mnemonique))
            return (&(OPS[i]));
    }
    return (NULL);
}

/*
** Return the size of the operation (in bytes)
** The arguments of the operation are considered as valid
*/
int get_operation_size(char **line)
{
    op_t *op = get_op_by_mnemonique(line[0]);
    argument_t args[4] = {NONE_ARG};
    int size = 1;

    get_operation_arguments(line, args);
    for (int i = 0; i < 4; i++) {
        if (args[i] == NONE_ARG)
            break;
        if (args[i] == REG_ARG)
            size += sizeof(char);
        else if ((args[i] == DIR_ARG) && !op->use_indexes)
            size += sizeof(int);
        else
            size += sizeof(short);
    }
    return (size);
}

/*
** Write the operation at the given line in machine code
*/
void write_operation_in_output_file(char **line, op_t *op, asms_t *asms)
{
    argument_t args[4] = {NONE_ARG};
    int values[4] = {0};
    char coding_byte = 0;

    get_operation_arguments(line, args);
    check_argument_validity(op, args);
    get_operation_values(line, args, values, asms);
    write_data(asms->fd_out, &(op->value), 1, 0);
    if (op->has_coding_byte) {
        coding_byte = generate_coding_byte(args);
        write_data(asms->fd_out, &coding_byte, 1, 0);
    }
    write_arguments_value(args, values, op->use_indexes, asms);
}