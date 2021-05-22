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
    hud_t *hud = hud_create();
    scene_t *scene;

    if (!bonus || !window || !memory || !hud)
        return (NULL);
    memset(memory, 0, sizeof(int) * MEM_SIZE);
    bonus->window = window;
    bonus->memory = memory;
    bonus->cam_rot_x = 180;
    bonus->cam_rot_y = 65;
    bonus->cam_distance = 300;
    bonus->hud = hud;
    if (!(scene = scene_create(bonus)))
        return (NULL);
    scene_create_cubes(scene);
    bonus->scene = scene;
    return (bonus);
}

int bonus_update(bonus_t *bonus, vm_t *vm)
{
    int run = 1;

    UNUSED(vm);
    bonus_event(bonus, &run);
    bonus_camera_move_update(bonus);
    bonus_draw(bonus);
    return (run);
}

void bonus_event(bonus_t *bonus, int *run)
{
    sfEvent event;

    while (sfWindow_pollEvent(bonus->window, &event)) {
        switch (event.type) {
            case sfEvtClosed:
                *run = 0;
                break;
            case sfEvtResized:
                glViewport(0, 0, event.size.width, event.size.height);
                break;
            case sfEvtMouseWheelScrolled:
                bonus_camera_zoom(bonus, event.mouseWheelScroll);
                break;
            default:
                break;
        }
    }
}

void bonus_draw(bonus_t *bonus)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    scene_draw(bonus->scene, bonus);
    hud_render(bonus->hud);
    sfWindow_display(bonus->window);
}

void bonus_camera_move_update(bonus_t *bonus)
{
    char move = 0;

    if (sfKeyboard_isKeyPressed(sfKeyQ) ^ sfKeyboard_isKeyPressed(sfKeyD)) {
        bonus->cam_rot_x += sfKeyboard_isKeyPressed(sfKeyQ) ? -0.4 : 0.4;
        move = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ) ^ sfKeyboard_isKeyPressed(sfKeyS)) {
        bonus->cam_rot_y += sfKeyboard_isKeyPressed(sfKeyZ) ? 0.4 : -0.4;
        move = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyA) ^ sfKeyboard_isKeyPressed(sfKeyE)) {
        bonus->scene->camera->target[2] += sfKeyboard_isKeyPressed(sfKeyA) ?
        -4 * bonus->cam_distance / 100.0 : 4 * bonus->cam_distance / 100.0;
        move = 1;
    }
    if (move)
        camera_calculate_pos(bonus->scene->camera,
        bonus->cam_distance, bonus->cam_rot_x, bonus->cam_rot_y);
}

void bonus_camera_zoom(bonus_t *bonus, sfMouseWheelScrollEvent event)
{
    bonus->cam_distance += event.delta * -5;
    camera_calculate_pos(bonus->scene->camera,
    bonus->cam_distance, bonus->cam_rot_x, bonus->cam_rot_y);
}

void bonus_destroy(bonus_t *bonus)
{
    scene_destroy(bonus->scene);
    sfWindow_destroy(bonus->window);
    free(bonus->memory);
    free(bonus);
}