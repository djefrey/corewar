/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** memory
*/

#include "corewar.h"
#include "vm.h"
#include "process.h"

int get_values_from_coding(int *values,
int size, process_t *process, vm_t *vm)
{
    char coding = *(vm->memory + (process->pc + 1) % MEM_SIZE);
    int addr = (process->pc + 2) % MEM_SIZE;
    char code;

    for (int i = 3; i >= 0; i++) {
        code = (coding & (3 << (i * 2)) >> (i * 3));
        if (code == 0)
            break;
        values[3 - i] = get_value_from_memory(code, &addr, process, vm);
    }
    return (addr);
}

int get_value_from_memory(char code, int *addr, process_t *process, vm_t *vm)
{
    char buff[sizeof(int)];

    if (type == TYPE_REG) {
        for (int i = 0; i < REG_SIZE; i++)
            buff[REG_SIZE - 1 - i] = *(vm->memory + (*addr + i) % MEM_SIZE);
        *addr += REG_SIZE;
        return (process->registers[*((int*) buff)]);
    } else if (type == TYPE_DIR) {
        for (int i = 0; i < DIR_SIZE; i++)
            buff[DIR_SIZE - 1 - i] = *(vm->memory + (addr + i) % MEM_SIZE);
        *addr += DIR_SIZE;
        return (*((int*) buff));
    } else {
        for (int i = 0; i < IND_SIZE; i++)
            buff[IND_SIZE - 1 - i] = *(vm->memory + (addr + i) % MEM_SIZE);
        *addr += IND_SIZE;
        return (*(vm->memory + (process->pc + *((int*) buff)) % MEM_SIZE));
    }
    return (0);
}