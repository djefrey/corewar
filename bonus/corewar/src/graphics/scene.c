/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** scene
*/

#include <stdlib.h>
#include "bonus.h"
#include "mesh.h"
#include "gameitem.h"

scene_t *scene_create(void)
{
    scene_t *scene = malloc(sizeof(scene_t));
    camera_t *camera = camera_create();
    hud_t *hud = hud_create();

    if (!scene || !camera || !hud)
        return;
    camera_set_pos(camera, -120, 320, 480);
    camera_set_target(camera, 80, 0, 480);
    scene->meshes = NULL;
    scene->cubes = NULL;
    scene->camera = camera;
    scene->hud = hud;
    return (scene);
}

void scene_draw(scene_t *scene, bonus_t *bonus)
{
    mesh_t *mesh;
    mat4 projection_matrix;

    glm_mat4_identity(projection_matrix);
    camera_get_projection_matrix(scene->camera, projection_matrix);
    for (list_t *list = scene->meshes; list; list = list->next) {
        mesh = (mesh_t*) list->data;
        mesh->mesh_drawlist_fct(mesh, projection_matrix, bonus);
    }
    hud_render(scene->hud);
}

void scene_destroy(scene_t *scene)
{
    list_t *next;

    for (list_t *list = scene->meshes; list; list = next) {
        next = list->next;
        mesh_destroy((mesh_t*) list->data);
        free(list);
    }
    for (list_t *list = scene->cubes; list; list = next) {
        next = list->next;
        gameitem_destroy((gameitem_t*) list->data);
        free(list);
    }
    camera_destroy(scene->camera);
    free(scene);
}