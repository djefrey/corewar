/*
** EPITECH PROJECT, 2021
** B-CPE-201-STG-2-1-corewar-thomas.parenteau
** File description:
** print_file
*/

#include "../include/asm.h"

void swap(void *data)
{
    unsigned char *temp;

    bytes *byte = (bytes *)data;
    temp = (*byte)[0];
    (*byte)[0] = (*byte)[1];
    (*byte)[1] = temp;
}

void indir_or_dir(char *str, asms_t *asms)
{
    int nb = 0;

    if (str[0] == DIRECT) {
        if (asms->loop == 0) {
            asms->size += 4;
            return;
        }
        nb = my_getnbr(str);
        nb = BIT_SWAP(nb);
        nb = (nb << 16) | (nb >> 16);
        write(asms->fd_out, &nb, 4);
    }
    if (str[0] != DIRECT) {
        if (asms->loop == 0) {
            asms->size += 2;
            return;
        }
        nb = my_getnbr(str);
        swap(&nb);
        write(asms->fd_out, &nb, 2);
    }
}

int print_reg(int nb, asms_t *asms)
{
    if (asms->loop == 0) {
        asms->size++;
        return (0);
    }
    write(asms->fd_out, &nb, 1);
}