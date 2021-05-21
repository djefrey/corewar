/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** bonus main
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "corewar.h"
#include "bonus.h"
#include "scene.h"
#include "mesh.h"

bonus_t *bonus_create(void)
{
    bonus_t *bonus = malloc(sizeof(bonus_t));
    sfWindow *window = window_create();
    unsigned int *memory = malloc(sizeof(int) * MEM_SIZE);
    scene_t *scene = scene_create();

    if (!bonus || !window || !memory || !scene)
        return (NULL);
    memset(memory, 0, sizeof(int) * MEM_SIZE);
    scene_create_cubes(scene);
    bonus->window = window;
    bonus->memory = memory;
    bonus->scene = scene;
    return (bonus);
}

int bonus_update(bonus_t *bonus, vm_t *vm)
{
    int run = 1;

    UNUSED(vm);
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    scene_draw(bonus->scene, bonus);
    sfWindow_display(bonus->window);
}

void bonus_destroy(bonus_t *bonus)
{
    scene_destroy(bonus->scene);
    sfWindow_destroy(bonus->window);
    free(bonus->memory);
    free(bonus);
}