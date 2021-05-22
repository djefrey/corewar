/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** informations text
*/

#ifndef INFO_TEXT_H_
#define INFO_TEXT_H_

#include "text.h"

typedef struct vm_s vm_t;

typedef struct infotext_s {
    char *string;
    sfVector2f pos;
    sfVector3f color;
    int champion_id;
} infotext_t;

void infotext_create(int champion_id, sfVector2f pos, hud_t *hud);
void infotext_update(infotext_t *text, vm_t *vm);

#endif /* !INFO_TEXT_H_ */
