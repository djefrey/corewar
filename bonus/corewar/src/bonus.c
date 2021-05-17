/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** bonus main
*/

#include <stdlib.h>
#include <unistd.h>
#include "bonus.h"
#include "scene.h"
#include "mesh.h"

bonus_t *bonus_create(void)
{
    bonus_t *bonus = malloc(sizeof(bonus_t));
    sfWindow *window = window_create();
    unsigned int *memory = malloc(sizeof(int) * 64);
    scene_t *scene = scene_create();
    GLuint program_id = load_shaders("bonus/corewar/res/shaders/vertex.glsl",
    "bonus/corewar/res/shaders/fragment.glsl");

    if (!bonus || !window || !memory || !scene)
        return (NULL);
    scene_create_cubes(scene);
    bonus->window = window;
    bonus->memory = memory;
    bonus->scene = scene;
    bonus->program_id = program_id;
    return (bonus);
}

int bonus_update(bonus_t *bonus, vm_t *vm)
{
    int run = 1;

    camera_set_pos(bonus->scene->camera, bonus->scene->camera->pos[0] + 0.1, 6, 2);
    bonus_event(bonus, &run);
    bonus_draw(bonus);
    return (run);
}

void bonus_event(bonus_t *bonus, int *run)
{
    sfEvent event;

    while (sfWindow_pollEvent(bonus->window, &event)) {
        if (event.type == sfEvtClosed) {
            *run = 0;
        } else if (event.type == sfEvtResized)
            glViewport(0, 0, event.size.width, event.size.height);
    }
}

void bonus_draw(bonus_t *bonus)
{
    GLuint matrix_id = glGetUniformLocation(bonus->program_id, "MVP");

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    scene_draw(bonus->scene, matrix_id);
    sfWindow_display(bonus->window);
}

void bonus_destroy(bonus_t *bonus)
{
    scene_destroy(bonus->scene);
    sfWindow_destroy(bonus->window);
    free(bonus->memory);
    free(bonus);
}