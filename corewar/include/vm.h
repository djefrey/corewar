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
    list_t *processes;
} vm_t;

int vm_write_file_in_memory(vm_t *vm, int fd, int addr, int size);

#endif /* !VM_H_ */
