/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** opengl
*/

#include "bonus.h"
#include "mesh.h"
#include "gameitem.h"

sfWindow *window_create(void)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    sfContextSettings settings = {24, 8, 2, 3, 3, sfContextDefault, 0};
    sfWindow *window = sfWindow_create(mode,
    WINDOW_TITLE, sfDefaultStyle, &settings);

    if (!window)
        return (NULL);
    glewInit();
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LEQUAL);
    glDepthRange(0.0f, 1.0f);
    glClearDepth(1.0f);
	glEnable(GL_CULL_FACE);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.0f, 0.1f, 0.0f, 0.0f);
    sfWindow_setFramerateLimit(window, 60);
    return (window);
}

void scene_create_cubes(scene_t *scene)
{
    mesh_t *cube_mesh = cube_mesh_create();
    gameitem_t *item;

    if (!cube_mesh)
        return;
    create_list(&(scene->meshes), cube_mesh);
    for (int i = 0; i < MEM_SIZE; i++) {
        item = cube_create(cube_mesh, i);
        transform_set_translation(item->transform, i % 32 * 5, 0, i / 32 * 5);
        create_list(&(cube_mesh->items), item);
        create_list(&(scene->cubes), item);
    }
}