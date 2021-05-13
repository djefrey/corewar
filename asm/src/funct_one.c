/*
** EPITECH PROJECT, 2021
** functions
** File description:
** funct1
*/

#include "../include/asm.h"

void live(asms_t *asms)
{
    int a = 0x01;

    write(asms->fd_out, &a, T_REG);
}

void add(asms_t *asms)
{
    int a = 0x02;

    write(asms->fd_out, &a, T_REG);
}

void sub(asms_t *asms)
{
    int a = 0x03;

    write(asms->fd_out, &a, T_REG);
}

void ld(asms_t *asms)
{
    int a = 0x04;

    write(asms->fd_out, &a, T_REG);
}

void st(asms_t *asms)
{
    int a = 0x05;

    write(asms->fd_out, &a, T_REG);
}