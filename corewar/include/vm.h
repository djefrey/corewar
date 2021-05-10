/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** virtual machine
*/

#ifndef VM_H_
#define VM_H_

#include "my_list.h"

typedef struct vm_s {
    char *memory;
    int cycles;
    int dead_cycles;
    int dump_cycles;
    list_t *champions;
} vm_t;

void vm_run(vm_t *vm);
int vm_write_file_in_memory(vm_t *vm, int fd, int addr, int size);
void vm_dump(vm_t *vm);
void vm_destroy(vm_t *vm);

#endif /* !VM_H_ */
