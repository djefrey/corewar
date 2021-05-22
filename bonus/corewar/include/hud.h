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
    list_t *infotexts;
    text_t *cycles_text;
} hud_t;

hud_t *hud_create(void);
void hud_update(hud_t *hud, vm_t *vm);
void hud_render(hud_t *hud);
void hud_update_cycles_text(text_t *text, vm_t *vm);
void hud_destroy(hud_t *hud);

#endif /* !HUD_H_ */
