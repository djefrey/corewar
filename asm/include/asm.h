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
#include "op.h"
#include "my.h"

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
    char *output;
    int fd_in;
    int fd_out;
    int size;
    int loop;
    char *file;
    char **tab_f;
    char ***mega_tab;
} asms_t;

typedef struct info_s {
    char *name;
    char *comment;
    char **instructions;
} info_t;

int compile(char *input, asms_t *asms);
void reformate_tab(asms_t *asms);
int put_error(char *str);

int prog(asms_t *asms);

int parse_struct(asms_t *asms);
char **my_asm_to_word_array(char const *str, int j, int k);
void reformate_string(asms_t *asms, int i);
char **my_str_to_asm_array(char const *str, int j, int k);

void name_new_file(char *input, asms_t *asms);

char **split_file(char *str);
char **split_line(char *line);
void free_split(char **split);

int read_source_file(asms_t *asms);

void inverse_endian(void *data, size_t size);
void write_data(int fd, void *value,
size_t size, char inverse);

int str_to_int(char *str);

#endif /* !ASM_H_ */
