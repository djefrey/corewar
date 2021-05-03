/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** asm header
*/

#ifndef ASM_H_
#define ASM_H_

#define MAGIC_NUMBER 0xea83f3

#define COMMENT_CHAR '#'
#define LABEL_CHAR ':'
#define DIRECT_CHAR '%'
#define SEPARATOR_CHAR ','

#define LABEL_CHAR "abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING ".name"
#define COMMENT_CMD_STRING ".comment"

#define PROG_NAME_LENGTH 128
#define PROG_COMMENT_LENGTH 2048

#define REG_NUMBER 16

#define IND_SIZE 2
#define DIR_SIZE 4

#define TYPE_REG 1
#define TYPE_DIR 2
#define TYPE_IND 4

typedef struct header_s {
    int magic_number;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char prog_comment[PROG_COMMENT_LENGTH + 1];
} header_t;

#endif /* !ASM_H_ */
