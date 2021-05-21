/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** memory
*/

#include "corewar.h"
#include "vm.h"
#include "process.h"
#include "instructions.h"

/*
** Fill args[] with the arguments of the coding byte
*/
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

/*
** Fill values[] with the arguments' values (values written in the memory)
** Return the end address of the actuel instruction
*/
int get_arguments_value(argument_t args[],
int values[], char indexes, couple_t couple)
{
    int addr = (couple.process->pc + 2) % MEM_SIZE;

    for (int i = 0; i < 4; i++) {
        switch (args[i]) {
            case REGISTER:
                values[i] = read_register_arg(&addr, couple.vm);
                break;
            case DIRECT:
                values[i] = read_direct_arg(&addr, indexes, couple.vm);
                break;
            case INDIRECT:
                values[i] = read_indirect_arg(&addr, couple.vm);
                break;
            case NONE:
                break;
        }
    }
    return (addr);
}

/*
** Check if arguments from coding byte are valid
** Return 1 if valid, 0 if not
*/
int check_args_validity(argument_t args[], int values[],
char instruction_value)
{
    instruction_t instruction = INSTRUCTIONS[instruction_value - 1];
    int nb_args = 0;

    for (; nb_args < 4 && args[nb_args] != NONE; nb_args++);
    if (instruction.nb_args != nb_args)
        return (0);
    for (int i = 0; i < instruction.nb_args; i++) {
        if (!(instruction.args[i] & args[i]))
            return (0);
        else if (args[i] == REGISTER
        && (values[i] < 0 || values[i] >= REG_NUMBER))
            return (0);
    }
    return (1);
}

/*
** Return argument "real" value
** - Register: return process->register[VALUE]
** - Direct: return VALUE
** - Indirect: return value at PC + VALUE % IDX_MOD
*/
int get_arg_real_value(argument_t arg, int value, process_t *process, vm_t *vm)
{
    switch (arg) {
        case REGISTER:
            return (value < 0 || value >= REG_NUMBER ?
            0 : process->registers[value]);
        case DIRECT:
            return (value);
        case INDIRECT:
            return (read_int((process->pc + value % IDX_MOD)
            % MEM_SIZE, 1, vm));
        case NONE:
            return (0);
    }
    return (0);
}