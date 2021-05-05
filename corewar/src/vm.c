/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** vm
*/

#include <stdlib.h>
#include <unistd.h>
#include "corewar.h"
#include "vm.h"
#include "process.h"

void vm_update(vm_t *vm)
{

}

void vm_destroy(vm_t *vm)
{
    free(vm->memory);
    free(vm);
}