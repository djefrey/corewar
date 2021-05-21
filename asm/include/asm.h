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
#define DIRECT '%'
#define REGISTER 'r'

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

int parse_struct(asms_t *asms);
char **my_asm_to_word_array(char const *str, int j, int k);
void reformate_string(asms_t *asms, int i);
char *coding_byte(char **tab, char *ret);
char *coding_byte_first(char **tab);
int pwr(int nb, int inc);
int bin_to_dec(int bin);
void print_reg(int nb, asms_t *asms);
void indir_or_dir(char *str, asms_t *asms);
void double_print_register(asms_t *asms, char **tab, int inc);
void double_print_ind(asms_t *asms, char **tab, int inc);
void its_first(asms_t *asms, char **tab, int inc);
void its_last(asms_t *asms, char **tab, int inc);
void inverse_endian(void *data, size_t size);
void live(asms_t *asms, char **tab);
void add(asms_t *asms, char **tab);
void sub(asms_t *asms, char **tab);
void st(asms_t *asms, char **tab);
void ld(asms_t *asms, char **tab);
void and(asms_t *asms, char **tab);
void or(asms_t *asms, char **tab);
void xor(asms_t *asms, char **tab);
void lld(asms_t *asms, char **tab);
void aff(asms_t *asms, char **tab);
void sti(asms_t *asms, char **tab);
int str_to_int(char *str);
int prog(asms_t *asms);
void name_new_file(char *input, asms_t *asms);
char **my_str_to_asm_array(char const *str, int j, int k);

#endif /* !ASM_H_ */
