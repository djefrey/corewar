/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** corewar header
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#define MAGIC_NUMBER 0xea83f3

#define REG_NUMBER 16
#define REG_SIZE 4

#define IND_SIZE 2
#define DIR_SIZE 4

#define CYCLE_TO_DIE 1536
#define CYCLE_DELTA 5
#define NBR_LIVE 40

#define PROG_NAME_LENGTH 128
#define PROG_COMMENT_LENGTH 2048

typedef struct header_s {
    short magic_number;
    char prog_name[PROG_NAME_LENGTH];
    int prog_size;
    char prog_comment[PROG_COMMENT_LENGTH];
} header_t;

#endif /* !COREWAR_H_ */
