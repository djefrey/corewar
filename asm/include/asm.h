/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** asm header
*/

#ifndef ASM_H_
#define ASM_H_

#define MAGIC_NUMBER 0xea83f3

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
    char *file;
    char **tab_f;
    char ***mega_tab;
} asms_t;

typedef struct info_s {
    char *name;
    char *comment;
    char **instructions;
} info_t;

char **my_str_to_word_array(char const *str, int j, int k);
int parse_struct(asms_t *asms);
char **my_asm_to_word_array(char const *str, int j, int k);
void live(asms_t *asms);
void add(asms_t *asms);
void sub(asms_t *asms);
void st(asms_t *asms);
void ld(asms_t *asms);
void and(asms_t *asms);
void or(asms_t *asms);
void xor(asms_t *asms);
void lld(asms_t *asms);
void aff(asms_t *asms);
void sti(asms_t *asms);

#endif /* !ASM_H_ */
