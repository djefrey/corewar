/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** asm header
*/

#ifndef ASM_H_
#define ASM_H_

#define MAGIC_NUMBER 0xea83f3
# define BIT_SWAP(x) ((x >> 24) & 0xff) | ((x << 8) & 0xff0000) \
    | ((x >> 8) & 0xff00) | ((x << 24) & 0xff000000)

typedef unsigned char bytes[2];

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "op.h"
#include "my.h"

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

int read_source_file(asms_t *asms);

void inverse_endian(void *data, size_t size);
void write_data(int fd, void *value,
size_t size, char inverse);

int str_to_int(char *str);

#endif /* !ASM_H_ */
