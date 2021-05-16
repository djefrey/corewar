/*
** EPITECH PROJECT, 2021
** functions
** File description:
** funct1
*/

#include "../include/asm.h"

void sti(asms_t *asms)
{
    int a = 0x0b;

    write(asms->fd_out, &a, T_REG);
}