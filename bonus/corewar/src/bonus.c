/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** bonus main
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bonus.h"
#include "scene.h"
#include "mesh.h"

void setup_memory(unsigned int *memory)
{
    memset(memory, 0, sizeof(int) * MEM_SIZE);
    for (int i = 0; i < 128; i++) {
        *(memory + i) = 0x1000000 | (i * 2);
    }
    for (int i = 0; i < 128; i++) {
        *(memory + MEM_SIZE / 4 + i) = 0x2000000 | (i * 2);
    }
    for (int i = 0; i < 128; i++) {
        *(memory + MEM_SIZE / 4 * 2 + i) = 0x3000000 | (i * 2);
    }
    for (int i = 0; i < 128; i++) {
        *(memory + MEM_SIZE / 4 * 3+ i) = 0x4000000 | (i * 2);
    }
}

bonus_t *bonus_create(void)
{
    bonus_t *bonus = malloc(sizeof(bonus_t));
    sfWindow *window = window_create();
    unsigned int *memory = malloc(sizeof(int) * 64);
    scene_t *scene = scene_create();
    GLuint program_id = load_shaders("bonus/corewar/res/vertex.glsl",
    "bonus/corewar/res/fragment.glsl");

    if (!bonus || !window || !memory || !scene)
        return (NULL);
    setup_memory(memory);
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
    glUseProgram(bonus->program_id);
    scene_draw(bonus->scene, bonus->program_id, bonus);
    glUseProgram(0);
    sfWindow_display(bonus->window);
}

void bonus_destroy(bonus_t *bonus)
{
    scene_destroy(bonus->scene);
    sfWindow_destroy(bonus->window);
    free(bonus->memory);
    free(bonus);
}