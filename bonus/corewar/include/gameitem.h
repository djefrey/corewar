/*
** EPITECH PROJECT, 2021
** opengl
** File description:
** gameitem
*/

#ifndef GAMEITEM_H_
#define GAMEITEM_H_

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "transform.h"

typedef struct bonus_s bonus_t;
typedef struct mesh_s mesh_t;

typedef struct gameitem_s {
    mesh_t *mesh;
    transform_t *transform;
} gameitem_t;

typedef struct cube_s {
    mesh_t *mesh;
    transform_t *transform;
    unsigned int id;
} cube_t;

gameitem_t *gameitem_create(mesh_t *mesh);
void gameitem_destroy(gameitem_t *item);

gameitem_t *cube_create(mesh_t *mesh, int id);
int get_cube_id(cube_t *cube, bonus_t *bonus);
int get_cube_champion(cube_t *cube, bonus_t *bonus);
void cube_set_height(cube_t *cube, bonus_t *bonus);
void cube_set_color_factor_uniform(cube_t *cube,
GLuint color_fact_id, bonus_t *bonus);

#endif /* !GAMEITEM_H_ */
