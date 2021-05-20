/*
** EPITECH PROJECT, 2021
** opengl
** File description:
** gameitem
*/

#include <stdlib.h>
#include "my_list.h"
#include "gameitem.h"
#include "transform.h"
#include "mesh.h"

gameitem_t *gameitem_create(mesh_t *mesh)
{
    gameitem_t *item = malloc(sizeof(gameitem_t));
    transform_t *transform = transform_create();

    if (!item || !transform)
        return (NULL);
    item->mesh = mesh;
    item->transform = transform;
    return (item);
}

void gameitem_destroy(gameitem_t *item)
{
    transform_destroy(item->transform);
    free(item);
}