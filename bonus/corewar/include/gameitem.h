/*
** EPITECH PROJECT, 2021
** opengl
** File description:
** gameitem
*/

#ifndef GAMEITEM_H_
#define GAMEITEM_H_

#include "transform.h"

typedef struct mesh_s mesh_t;

typedef struct gameitem_s {
    mesh_t *mesh;
    transform_t *transform;
} gameitem_t;

gameitem_t *gameitem_create(mesh_t *mesh);
void gameitem_destroy(gameitem_t *item);

#endif /* !GAMEITEM_H_ */
