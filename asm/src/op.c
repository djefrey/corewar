/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instructions list
*/

#include "op.h"

const op_t OPS[] = {
    {0x01, 10, 1, {DIR_ARG, NONE_ARG, NONE_ARG, NONE_ARG},
        "live"},
    {0x02, 5, 2, {DIR_ARG | IND_ARG, REG_ARG, NONE_ARG, NONE_ARG},
        "ld"},
    {0x03, 5, 2, {REG_ARG, IND_ARG | REG_ARG, NONE_ARG, NONE_ARG},
        "st"},
    {0x04, 10, 3, {REG_ARG, REG_ARG, REG_ARG, NONE_ARG},
        "add"},
    {0x05, 10, 3, {REG_ARG, REG_ARG, REG_ARG, NONE_ARG},
        "sub"},
    {0x06, 6, 3, {REG_ARG | DIR_ARG | IND_ARG, REG_ARG | DIR_ARG | IND_ARG,
        REG_ARG, NONE_ARG}, "and"},
    {0x07, 6, 3, {REG_ARG | DIR_ARG | IND_ARG, REG_ARG | DIR_ARG | IND_ARG,
        REG_ARG, NONE_ARG}, "or"},
    {0x08, 6, 3, {REG_ARG | DIR_ARG | IND_ARG, REG_ARG | DIR_ARG | IND_ARG,
        REG_ARG, NONE_ARG}, "xor"},
    {0x09, 20, 1, {DIR_ARG, NONE_ARG, NONE_ARG, NONE_ARG},
        "zjmp"},
    {0x0a, 25, 3, {REG_ARG | DIR_ARG | IND_ARG, REG_ARG | DIR_ARG,
        REG_ARG, NONE_ARG}, "ldi"},
    {0x0b, 25, 3, {REG_ARG, REG_ARG | DIR_ARG | IND_ARG,
        REG_ARG | DIR_ARG, NONE_ARG}, "sti"},
    {0x0c, 800, 1, {DIR_ARG, NONE_ARG, NONE_ARG, NONE_ARG},
        "fork"},
    {0x0d, 10, 2, {DIR_ARG | IND_ARG, REG_ARG, NONE_ARG, NONE_ARG},
        "lld"},
    {0x0e, 50, 3, {REG_ARG | DIR_ARG | IND_ARG,
        REG_ARG | DIR_ARG, REG_ARG, NONE_ARG}, "lldi"},
    {0x0f, 1000, 1, {DIR_ARG, NONE_ARG, NONE_ARG, NONE_ARG},
        "lfork"},
    {0x010, 2, 1, {REG_ARG, NONE_ARG, NONE_ARG, NONE_ARG},
        "aff"},
};