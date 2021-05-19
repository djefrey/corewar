/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** instructions list
*/

#include "corewar.h"
#include "instructions.h"

const instruction_t INSTRUCTIONS[INSTRUCTIONS_NB] = {
    {0x01, 10, 0, {NONE, NONE, NONE, NONE},
        &live_instruction},
    {0x02, 5, 2, {DIRECT | INDIRECT, REGISTER, NONE, NONE},
        &ld_instruction},
    {0x03, 5, 2, {REGISTER, INDIRECT | REGISTER, NONE, NONE},
        &st_instruction},
    {0x04, 10, 3, {REGISTER, REGISTER, REGISTER, NONE},
        &add_instruction},
    {0x05, 10, 3, {REGISTER, REGISTER, REGISTER, NONE},
        &sub_instruction},
    {0x06, 6, 3, {REGISTER, REGISTER, REGISTER, NONE},
        &and_instruction},
    {0x07, 6, 3, {REGISTER, REGISTER, REGISTER, NONE},
        &or_instruction},
    {0x08, 6, 3, {REGISTER, REGISTER, REGISTER, NONE},
        &xor_instruction},
    {0x09, 20, 0, {NONE, NONE, NONE, NONE},
        &zjmp_instruction},
    {0x0a, 25, 3, {REGISTER | DIRECT | INDIRECT,
        REGISTER | DIRECT, REGISTER, NONE}, &ldi_instruction},
    {0x0b, 25, 3, {REGISTER, REGISTER | DIRECT | INDIRECT,
        REGISTER | DIRECT, NONE}, &sti_instruction},
    {0x0c, 800, 0, {NONE, NONE, NONE, NONE},
        &fork_instruction},
    {0x0d, 10, 2, {DIRECT | INDIRECT, REGISTER, NONE, NONE},
        &lld_instruction},
    {0x0e, 50, 3, {REGISTER | DIRECT | INDIRECT,
        REGISTER | DIRECT, REGISTER, NONE}, &lldi_instruction},
    {0x0f, 1000, 0, {NONE, NONE, NONE, NONE},
        &lfork_instruction},
    {0x010, 2, 1, {DIRECT, NONE, NONE, NONE},
        &aff_instruction},
};