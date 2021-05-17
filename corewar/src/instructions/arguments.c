/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** memory
*/

#include "corewar.h"
#include "vm.h"
#include "process.h"

void get_arguments_type(argument_t args[], process_t *process, vm_t *vm)
{
    char coding = *(vm->memory + (process->pc + 1) % MEM_SIZE);
    char code;

    for (int i = 3; i >= 0; i--) {
        code = (coding & (3 << (i * 2))) >> (i * 2);
        switch (code) {
            case TYPE_REG:
                args[3 - i] = REGISTER;
                break;
            case TYPE_DIR:
                args[3 - i] = DIRECT;
                break;
            case TYPE_IND:
                args[3 - i] = INDIRECT;
                break;
            default:
                args[3 - i] = NONE;
                break;
        }
    }
}

int get_arguments_value(argument_t args[],
int values[], process_t *process, vm_t *vm)
{
    int addr = (process->pc + 2) % MEM_SIZE;

    for (int i = 0; i < 4; i++) {
        switch (args[i]) {
            case REGISTER:
                values[i] = read_register_arg(&addr, vm);
                break;
            case DIRECT:
                values[i] = read_direct_arg(&addr, vm);
                break;
            case INDIRECT:
                values[i] = read_indirect_arg(&addr, vm);
                break;
            case NONE:
                break;
        }
    }
    return (addr);
}

int read_register_arg(int *addr, vm_t *vm)
{
    char buff[sizeof(int)] = {0};

    buff[0] = *(vm->memory + *addr);
    *addr = (*addr + 1) % MEM_SIZE;
    return (*((int*) buff) - 1);
}

int read_direct_arg(int *addr, vm_t *vm)
{
    int value = read_int(*addr, DIR_SIZE, vm);

    *addr = (*addr + DIR_SIZE) % MEM_SIZE;
    return (value);
}

int read_indirect_arg(int *addr, vm_t *vm)
{
    int value = read_int(*addr, IND_SIZE, vm);

    *addr = (*addr + IND_SIZE) % MEM_SIZE;
    return (value);
}