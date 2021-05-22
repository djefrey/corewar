/*
** EPITECH PROJECT, 2021
** corewa
** File description:
** hud
*/

#include <stdlib.h>
#include "my.h"
#include "bonus.h"
#include "hud.h"
#include "info_text.h"

hud_t *hud_create(void)
{
    hud_t *hud = malloc(sizeof(hud_t));
    texts_t *texts = texts_create("bonus/corewar/res/fonts/1st-Sortie.png");
    GLuint text_program_id = load_shaders(
        "bonus/corewar/res/shaders/text/text_vertex.glsl",
        "bonus/corewar/res/shaders/text/text_fragment.glsl"
    );

    if (!hud)
        return (NULL);
    hud->texts = texts;
    hud->text_program_id = text_program_id;
    hud->cycles_text = text_create_size(40, (sfVector2f) {0, 24}, texts);
    return (hud);
}

void hud_update(hud_t *hud, vm_t *vm)
{
    for (list_t *list = hud->infotexts; list; list = list->next)
        infotext_update((infotext_t*) list->data, vm);
    hud_update_cycles_text(hud->cycles_text, vm);
}

void hud_render(hud_t *hud)
{
    texts_renderlist(hud->texts, hud->text_program_id);
}

void hud_update_cycles_text(text_t *text, vm_t *vm)
{
    int len;

    my_strcpy(text->string, "Cycles: ");
    len = my_strlen(text->string);
    gcvt(vm->cycles, 6, text->string + len);
    my_strcat(text->string, " - Lives cycles: ");
    len = my_strlen(text->string);
    gcvt(vm->lives_cycles, 4, text->string + len);
    my_strcat(text->string, " / ");
    len = my_strlen(text->string);
    gcvt(vm->dead_cycles, 4, text->string + len);
    len = my_strlen(text->string);
    text->pos.x = 400 - (len * 9) / 2;
}

void hud_destroy(hud_t *hud)
{
    texts_destroy(hud->texts);
    glDeleteProgram(hud->text_program_id);
}