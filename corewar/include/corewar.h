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

#define IND_SIZE 2
#define DIR_SIZE 4
#define REG_SIZE 4

#define TYPE_REG 1
#define TYPE_DIR 2
#define TYPE_IND 3

#define IDX_MOD 512

#define CYCLE_TO_DIE 1536
#define CYCLE_DELTA 5
#define NBR_LIVE 40

#define PROG_NAME_LENGTH 128
#define PROG_COMMENT_LENGTH 2048

#define UNUSED(value) ((void) value)

typedef int reg_t;

typedef struct champion_s champion_t;
typedef struct process_s process_t;
typedef struct vm_s vm_t;

typedef enum argument_e {
    NONE = 1,
    REGISTER = 2,
    DIRECT = 4,
    INDIRECT = 8,
} argument_t;

typedef struct header_s {
    int magic_number;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char prog_comment[PROG_COMMENT_LENGTH + 1];
} header_t;

typedef struct couple_s {
    process_t *process;
    vm_t *vm;
} couple_t;

typedef struct setup_s {
    int nb;
    int ids[4];
    int addrs[4];
    char *files[4];
} setup_t;

int argument_managemnt(int ac, char **av, vm_t *vm);
void argument_setup_struct(setup_t *setup);
int argument_read_value(int *id, int *addr, char **arg, vm_t *vm);
int argument_add_champion(setup_t *setup, int *id, int *addr, char *arg);
int argument_create_champions(setup_t *setup, vm_t *vm);
void calculate_minimum_champions_ids(setup_t *setup);
int champion_cmp_ids(void *data1, void *data2);

void read_header(header_t *header, int fd, unsigned int len);

void get_arguments_type(argument_t args[], process_t *process, vm_t *vm);
int get_arguments_value(argument_t args[],
int values[], char indexes, couple_t couple);
int get_arg_real_value(argument_t arg, int value, process_t *process, vm_t *vm);
int check_args_validity(argument_t args[], int values[],
char instruction_value);
int read_register_arg(int *addr, vm_t *vm);
int read_direct_arg(int *addr, char indexes, vm_t *vm);
int read_indirect_arg(int *addr, vm_t *vm);

int read_int(int addr, int size, vm_t *vm);
void write_int(int addr, int value, int size, vm_t *vm);
int write_file_in_memory(int addr, int fd, int size, vm_t *vm);

int get_file_size(int fd);
void inverse_endian(void *data, void *buf, size_t size);
int str_to_int(char *str);
champion_t *get_champion_by_id(vm_t *vm, int id);

#endif /* !COREWAR_H_ */
