/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** opengl
*/

#include "bonus.h"
#include "mesh.h"
#include "gameitem.h"

GLfloat cube_vertex[24] = {
    -1.0f, 1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, -1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, -1.0f, 1.0f,
    1.0f, 1.0f, -1.0f,
    1.0f, -1.0f, -1.0f
};

GLfloat cube_colors[24] = {
    1.0f, 1.0f, 1.0f,
    0.5f, 0.5f, 0.5f,
    1.0f, 1.0f, 1.0f,
    0.5f, 0.5f, 0.5f,
    1.0f, 1.0f, 1.0f,
    0.5f, 0.5f, 0.5f,
    1.0f, 1.0f, 1.0f,
    0.5f, 0.5f, 0.5f,
};

GLuint cube_indices[36] = {
    0,1,2,2,1,3,
    4,5,6,6,5,7,
    3,1,5,5,1,7,
    0,2,6,6,2,4,
    6,7,0,0,7,1,
    2,3,4,4,3,5
};

sfWindow *window_create(void)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    sfWindow *window = sfWindow_create(mode,
    WINDOW_TITLE, sfDefaultStyle, NULL);

    if (!window)
        return (NULL);
    glewInit();
    glEnable(GL_DEPTH_TEST);
    glDepthRange(0.0f, 1.0f);
    glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);
    glClearColor(0.0f, 0.1f, 0.0f, 0.0f);
    sfWindow_setFramerateLimit(window, 30);
    return (window);
}

void scene_create_cubes(scene_t *scene)
{
    mesh_t *cube = mesh_create(cube_vertex,
    cube_colors, cube_indices, (int[2]) {24, 36});
    gameitem_t *item;

    if (!cube)
        return (NULL);
    create_list(&(scene->meshes), cube);
    for (int i = 0; i < MEM_SIZE; i++) {
        item = cube_create(cube, i);
        transform_set_translation(item->transform, i % 32 * 5, 0, i / 32 * 5);
        create_list(&(cube->items), item);
        create_list(&(scene->cubes), item);
    }
}