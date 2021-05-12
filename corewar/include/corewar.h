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

#define MEM_SIZE (6*1024)

#define REG_NUMBER 16

#define REG_SIZE 1
#define IND_SIZE 2
#define DIR_SIZE 4

#define TYPE_REG 1
#define TYPE_DIR 2
#define TYPE_IND 3

#define IDX_MOD 512

#define CYCLE_TO_DIE 1536
#define CYCLE_DELTA 5
#define NBR_LIVE 40

#define PROG_NAME_LENGTH 128
#define PROG_COMMENT_LENGTH 2048

typedef int reg_t;

typedef struct process_s process_t;
typedef struct vm_s vm_t;

typedef enum argument_e {
    NONE,
    REGISTER,
    DIRECT,
    INDIRECT,
} argument_t;

typedef struct header_s {
    int magic_number;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char prog_comment[PROG_COMMENT_LENGTH + 1];
} header_t;

void read_header(header_t *header, int fd, unsigned int len);

void get_arguments_type(argument_t args[], process_t *process, vm_t *vm);
int get_arguments_value(argument_t args[],
int values[], process_t *process, vm_t *vm);
int read_register_arg(int *addr, vm_t *vm);
int read_direct_arg(int *addr, vm_t *vm);
int read_indirect_arg(int *addr, vm_t *vm);

int get_file_size(int fd);
void inverse_endian(void *data, void *buf, size_t size);
int get_arg_real_value(argument_t arg, int value, process_t *process, vm_t *vm);
int read_int(int addr, int size, vm_t *vm);

#endif /* !COREWAR_H_ */
