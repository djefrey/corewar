/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** asm header
*/

#ifndef ASM_H_
#define ASM_H_

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include "my_list.h"
#include "op.h"

#define MAX_ARGS_NUMBER 4

#define COMMENT_CHAR '#'
#define LABEL_CHAR ':'
#define DIRECT_CHAR '%'
#define REGISTER_CHAR 'r'
#define SEPARATOR_CHAR ','

#define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING ".name"
#define COMMENT_CMD_STRING ".comment"

#define REG_NUMBER 16

#define IND_SIZE 2
#define DIR_SIZE 4
#define REG_SIZE 4

#define COREWAR_MAGIC_NUMBER 0xea83f3

typedef struct asms_s {
    int fd_out;
    int prog_size;
    int compile_pos;
    char **lines;
    list_t *labels;
} asms_t;

typedef struct label_s {
    char *name;
    int pos;
} label_t;

typedef struct info_s {
    char *name;
    char *comment;
    char **instructions;
} info_t;

int init_compilation(char *input, asms_t *asms);
int put_error(char *str);

int open_output_file(char *input, asms_t *asms);
char *get_output_filename(char *input);

void compile(asms_t *asms);
void precompile(asms_t *asms);
void write_header(asms_t *asms);
void compile_asm(asms_t *asms);

char **split_file(char *str);
char **split_line(char *line);
void free_split(char **split);

char *read_source_file(int fd_in);

void register_label(char *label_name, int pos, asms_t *asms);
void check_label_name_validty(char *label, int len);
int get_label_value(char *label_name, asms_t *asms);

void inverse_endian(void *data, size_t size);
void write_data(int fd, void *value,
size_t size, char inverse);

char *get_cmd(char *cmd_name, char *line, char *buff, int buff_size);
int str_to_int(char *str);

#endif /* !ASM_H_ */
