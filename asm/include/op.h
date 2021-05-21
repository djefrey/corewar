/*
** EPITECH PROJECT, 2021
** asm
** File description:
** op header
*/

#ifndef _OP_H_
#define _OP_H_

#define PROG_NAME_LENGTH 128
#define COMMENT_LENGTH 2048

#define NB_OPS 16

typedef struct asms_s asms_t;

typedef enum argument_e {
    NONE_ARG = 1,
    REG_ARG = 2,
    DIR_ARG = 4,
    IND_ARG = 8,
} argument_t;

typedef struct header_s {
   int magic;
   char prog_name[PROG_NAME_LENGTH + 1];
   int prog_size;
   char comment[COMMENT_LENGTH + 1];
} header_t;

typedef struct op_s {
   char value;
   int cycles;
   char nb_args;
   char args[4];
   char *mnemonique;
   char use_indexes;
   char has_coding_byte;
} op_t;

extern op_t OPS[];

op_t *get_op_by_mnemonique(char *mnemonique);
int get_operation_size(char **line);
void write_operation_in_output_file(char **line, op_t *op, asms_t *asms);

void get_operation_arguments(char *args[], argument_t args_type[4]);
void get_operation_values(char *args[], argument_t args_type[4],
int values[4], asms_t *asms);
void check_argument_validity(op_t *op, argument_t args[4]);
char generate_coding_byte(argument_t args[4]);
void write_arguments_value(argument_t args[4],
int values[4], char indexes, asms_t *asms);

#endif
