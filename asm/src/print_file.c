/*
** EPITECH PROJECT, 2021
** B-CPE-201-STG-2-1-corewar-thomas.parenteau
** File description:
** print_file
*/

#include "asm.h"

void inverse_endian(void *data, size_t size)
{
    char buff[size];

    for (unsigned i = 0; i < size; i++)
        (buff)[size - i - 1] = ((char*) data)[i];
    for (unsigned i = 0; i < size; i++)
        ((char *) data)[i] = buff[i];
}

void indir_or_dir(char *str, asms_t *asms)
{
    int nb = 0;

    if (str[0] == DIRECT) {
        if (asms->loop == 0) {
            asms->size += 4;
            return;
        }
        nb = str_to_int(str);
        nb = BIT_SWAP(nb);
        nb = (nb << 16) | (nb >> 16);
        write(asms->fd_out, &nb, 4);
    }
    if (str[0] != DIRECT) {
        if (asms->loop == 0) {
            asms->size += 2;
            return;
        }
        nb = str_to_int(str);
        inverse_endian(&nb, sizeof(int));
        write(asms->fd_out, &nb, 2);
    }
}

void print_reg(int nb, asms_t *asms)
{
    if (asms->loop == 0) {
        asms->size++;
        return;
    }
    write(asms->fd_out, &nb, 1);
}