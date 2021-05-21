/*
** EPITECH PROJECT, 2021
** asm
** File description:
** arguments
*/

#include "asm.h"
#include "op.h"

/*
** Read 'args' arguments array provided
** Store arguments' type in args_type
*/
void get_operation_arguments(char *args[], argument_t args_type[4])
{
    char *arg;

    for (int i = 0; i < 4 && args[i + 1]; i++) {
        arg = args[i + 1];
        if (arg[0] == DIRECT_CHAR)
            args_type[i] = DIR_ARG;
        else if (arg[0] == REGISTER_CHAR)
            args_type[i] = REG_ARG;
        else
            args_type[i] = IND_ARG;
    }
}

/*
** Read 'args' and 'args_types' argument arrays provided
** Store arguments' values in values
*/
void get_operation_values(char *args[], argument_t args_type[4],
int values[4], asms_t *asms)
{
    int value;

    for (int i = 0; i < 4 && args_type[i] && args_type[i] != NONE_ARG; i++) {
        if ((args_type[i] == DIR_ARG && args[i + 1][1] == LABEL_CHAR)
        || (args_type[i] == IND_ARG && args[i + 1][0] == LABEL_CHAR))
            value = get_label_value(args[i + 1] + 1, asms) - asms->compile_pos;
        else if (args_type[i] == DIR_ARG || args_type[i] == REG_ARG)
            value = str_to_int(args[i + 1] + 1);
        else
            value = str_to_int(args[i + 1] + 1);
        if ((((args_type[i] == DIR_ARG && args[i + 1][1] != LABEL_CHAR)
        || args_type[i] == REG_ARG) && !my_str_isnum(args[i + 1] + 1))
        || (args_type[i] == IND_ARG && !my_str_isnum(args[i]))
        || (args_type[i] == REG_ARG && (value < 1 || value > REG_NUMBER)))
            exit(put_error("Invalid argument value\n"));
        values[i] = value;
    }
}

/*
** Check validity of the arguments provided
** Exit program if not valid
*/
void check_argument_validity(op_t *op, argument_t args[4])
{
    int nb_args = 0;

    for (; nb_args < 4 && args[nb_args]
    && args[nb_args] != NONE_ARG; nb_args++);
    if (op->nb_args != nb_args)
        exit(put_error("Invalid number of argument\n"));
    for (int i = 0; i < nb_args; i++) {
        if (!(op->args[i] & args[i]))
            exit(put_error("Invalid argument type\n"));
    }
}

/*
** Return the coding byte of the arguments provided
*/
char generate_coding_byte(argument_t args[4])
{
    char value = 0;

    for (int i = 0; i < 4; i++) {
        switch (args[i]) {
            case REG_ARG:
                value |= 1 << ((3 - i) * 2);
                break;
            case DIR_ARG:
                value |= 2 << ((3 - i) * 2);
                break;
            case IND_ARG:
                value |= 3 << ((3 - i) * 2);
                break;
            default:
                break;
        }
    }
    return (value);
}

/*
** Write the arguments' values according to their type
*/
void write_arguments_value(argument_t args[4],
int values[4], char indexes, asms_t *asms)
{
    for (int i = 0; i < 4; i++) {
        if (!args[i] || args[i] == NONE_ARG)
            continue;
        if (args[i] == REG_ARG)
            write_data(asms->fd_out, (char*) &values[i], 1, 0);
        else if (args[i] == DIR_ARG && !indexes)
            write_data(asms->fd_out, &values[i], 4, 1);
        else
            write_data(asms->fd_out, (short*) &values[i], 2, 1);
    }
}