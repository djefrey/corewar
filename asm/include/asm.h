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
#include "../../corewar/include/my.h"

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

static char *inst[] = {
    "live",
    "add",
    "sub",
    "ld",
    "st",
    "and",
    "or",
    "xor",
    "aff",
    "lld",
    "sti",
    "zjmp",
    "ldi",
    "ldi",
    "fork",
    "lfork",
    "lldi",
};

char **my_str_to_word_array(char const *str, int j, int k);
int parse_struct(asms_t *asms);
char **my_asm_to_word_array(char const *str, int j, int k);
void reformate_string(asms_t *asms, int i);
char *my_strjoin(char *str, char *to_add);
char *my_strjoin_char(char *str, char c);
char *coding_byte(asms_t *asms, char **tab, char *ret);
char *coding_byte_first(asms_t *asms, char **tab);
int pwr(int nb, int inc);
int bin_to_dec(int bin);
int print_reg(int nb, asms_t *asms);
void indir_or_dir(char *str, asms_t *asms);
void double_print_register(asms_t *asms, char **tab, int inc);
void double_print_ind(asms_t *asms, char **tab, int inc);
void its_first(asms_t *asms, char **tab, int inc);
void its_last(asms_t *asms, char **tab, int inc);
void swap(void *data);
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

#endif /* !ASM_H_ */
