/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** corewar header
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include <stdint.h>
#include <stddef.h>

#define MAGIC_NUMBER 0xea83f3

#define REG_NUMBER 16

#define IND_SIZE 2
#define DIR_SIZE 4

#define TYPE_REG 1
#define TYPE_DIR 2
#define TYPE_IND 4

#define CYCLE_TO_DIE 1536
#define CYCLE_DELTA 5
#define NBR_LIVE 40

#define PROG_NAME_LENGTH 128
#define PROG_COMMENT_LENGTH 2048

typedef int reg_t;

typedef struct header_s {
    int magic_number;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char prog_comment[PROG_COMMENT_LENGTH + 1];
} header_t;

void read_header(header_t *header, int fd, unsigned int len);

int get_file_size(int fd);
void inverse_endian(void *data, void *buf, size_t size);

#endif /* !COREWAR_H_ */
