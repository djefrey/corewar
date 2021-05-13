/*
** EPITECH PROJECT, 2021
** functions
** File description:
** funct1
*/

#include "../include/asm.h"

void and(asms_t *asms)
{
    int a = 0x06;

    write(asms->fd_out, &a, T_REG);
}

void or(asms_t *asms)
{
    int a = 0x07;

    write(asms->fd_out, &a, T_REG);
}

void xor(asms_t *asms)
{
    int a = 0x08;

    write(asms->fd_out, &a, T_REG);
}

void aff(asms_t *asms)
{
    int a = 0x10;

    write(asms->fd_out, &a, T_REG);
}

void lld(asms_t *asms)
{
    int a = 0x0a;

    write(asms->fd_out, &a, T_REG);
}