/*
** EPITECH PROJECT, 2021
** corewa
** File description:
** hud
*/

#include "bonus.h"
#include "hud.h"

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
    text_create("ABCDEFGHIJKLMNOPQ", (sfVector2f) {0, 0}, texts);
    return (hud);
}

void hud_render(hud_t *hud)
{
    texts_renderlist(hud->texts, hud->text_program_id);
}

void hud_destroy(hud_t *hud)
{
    texts_destroy(hud->texts);
    glDeleteProgram(hud->text_program_id);
}