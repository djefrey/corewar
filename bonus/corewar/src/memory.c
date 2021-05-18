/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** memory
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bonus.h"
#include "scene.h"
#include "mesh.h"
#include "gameitem.h"

void bonus_write_champion_id(bonus_t *bonus, int addr, int size, int id)
{
    int value;

    for (int i = 0; i < size; i++) {
        value = *(bonus->memory + addr) & 0x00FFFFFF;
        value = value < 0x00FFFFFF ? (value + 1) & 0x00FFFFFF : value;
        value |= (id & 0x7F) << 24;
        *(bonus->memory + addr) = value;
        addr = (addr + 1) % MEM_SIZE;
    }
}

void bonus_set_actual_pc(bonus_t *bonus, int addr, char actual)
{
    if (actual)
        *(bonus->memory + addr) |= 2147483648;
    else
        *(bonus->memory + addr) &= 2147483647;
}