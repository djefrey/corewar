/*
** EPITECH PROJECT, 2021
** opengl
** File description:
** mesh
*/

#include <stdlib.h>
#include "mesh.h"
#include "transform.h"
#include "gameitem.h"

mesh_t *mesh_create(GLfloat vertex_array[],
GLfloat color_array[], GLuint indices_array[], int size[2])
{
    mesh_t *mesh = malloc(sizeof(mesh_t));

    if (!mesh)
        return (NULL);
    mesh->vertices = size[1];
    mesh->triangles = size[1] / 3;
    mesh->items = NULL;
    glGenBuffers(1, &(mesh->vertex_buffer));
    glBindBuffer(GL_ARRAY_BUFFER, mesh->vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER,  size[0] * sizeof(GLfloat), vertex_array, GL_STATIC_DRAW);
    glGenBuffers(1, &(mesh->color_buffer));
    glBindBuffer(GL_ARRAY_BUFFER, mesh->color_buffer);
    glBufferData(GL_ARRAY_BUFFER, size[0] * sizeof(GLfloat), color_array, GL_STATIC_DRAW);
    glGenBuffers(1, &(mesh->indices_buffer));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indices_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size[1] * sizeof(GLuint), indices_array, GL_STATIC_DRAW);
    mesh->mesh_destroy_fct = &mesh_destroy;
    return (mesh);
}

void mesh_destroy(mesh_t *mesh)
{
    list_t *next;

    for (list_t *list = mesh->items; list; list = next) {
        next = list->next;
        free(list);
    }
    free(mesh);
}