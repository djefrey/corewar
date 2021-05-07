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
} asms_t;

char **my_str_to_word_array(char const *str, int j, int k);

#endif /* !ASM_H_ */
