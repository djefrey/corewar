/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** hud
*/

#ifndef HUD_H_
#define HUD_H_

#include "text.h"

typedef struct hud_s {
    GLuint text_program_id;
    texts_t *texts;
} hud_t;

hud_t *hud_create(void);
void hud_render(hud_t *hud);
void hud_destroy(hud_t *hud);

#endif /* !HUD_H_ */
