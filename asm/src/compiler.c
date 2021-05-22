/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** core function
*/

#include "asm.h"
#include "op.h"

/*
** Compile function
** Precompile, write header and compile ASM code
*/
void compile(asms_t *asms)
{
    precompile(asms);
    write_header(asms);
    compile_asm(asms);
}

/*
** Pre compilation
** Calculate the size of the program
** Register the labels
*/
void precompile(asms_t *asms)
{
    char **line;
    char **cpy;

    for (int i = 2; asms->lines[i]; i++) {
        line = split_line(asms->lines[i]);
        cpy = line;
        if (line[0][my_strlen(line[0]) - 1] == LABEL_CHAR) {
            register_label(line[0], asms->prog_size, asms);
            line++;
        }
        if (*line)
            asms->prog_size += get_operation_size(line);
        free_split(cpy);
    }
}

/*
** Write the header in fd_out
** Malloc needed to prevent garbage values due to padding
*/
void write_header(asms_t *asms)
{
    header_t *header = malloc(sizeof(header_t));

    if (!header)
        exit(84);
    header->magic = COREWAR_MAGIC_NUMBER;
    inverse_endian(&(header->magic), sizeof(int));
    get_cmd(NAME_CMD_STRING, asms->lines[0],
    (char*) &(header->prog_name), PROG_NAME_LENGTH + 1);
    header->prog_size = asms->prog_size;
    inverse_endian(&(header->prog_size), sizeof(int));
    get_cmd(COMMENT_CMD_STRING, asms->lines[1],
    (char*) &(header->comment), COMMENT_LENGTH + 1);
    write(asms->fd_out, header, sizeof(header_t));
    free(header);
}

/*
** Read file and write operations in machine code
*/
void compile_asm(asms_t *asms)
{
    char **line;
    char **cpy;
    op_t *op;

    for (int i = 2; asms->lines[i]; i++) {
        line = split_line(asms->lines[i]);
        cpy = line;
        if (line[0][my_strlen(line[0]) - 1] == LABEL_CHAR)
            line++;
        if (*line) {
            op = get_op_by_mnemonique(line[0]);
            if (op)
                write_operation_in_output_file(line, op, asms);
            else
                exit(put_error("Unknown operation\n"));
            asms->compile_pos += get_operation_size(line);
        }
        free_split(cpy);
    }
}