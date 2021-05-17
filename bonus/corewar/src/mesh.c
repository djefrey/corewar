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

mesh_t *mesh_create(GLfloat vertex_array[], GLfloat color_array[], int vertices)
{
    mesh_t *mesh = malloc(sizeof(mesh_t));
    size_t size = sizeof(GLfloat) * vertices * 3;

    if (!mesh)
        return (NULL);
    mesh->vertices = vertices;
    mesh->triangles = vertices / 3;
    mesh->items = NULL;
    glGenBuffers(1, &(mesh->vertex_buffer));
    glBindBuffer(GL_ARRAY_BUFFER, mesh->vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, size, vertex_array, GL_STATIC_DRAW);
    glGenBuffers(1, &(mesh->color_buffer));
    glBindBuffer(GL_ARRAY_BUFFER, mesh->color_buffer);
    glBufferData(GL_ARRAY_BUFFER, size, color_array, GL_STATIC_DRAW);
    return (mesh);
}

void mesh_drawinit(mesh_t *mesh)
{
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, mesh->vertex_buffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, mesh->color_buffer);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
}

void mesh_drawlist(mesh_t *mesh, GLuint matrix_id, mat4 projection_matrix)
{
    mat4 mvp;
    gameitem_t *item;

    mesh_drawinit(mesh);
    for (list_t *list = mesh->items; list; list = list->next) {
        item = (gameitem_t*) list->data;
        get_transform_matrix(item->transform, mvp);
        glm_mat4_mul(projection_matrix, mvp, mvp);
        glUniformMatrix4fv(matrix_id, 1, GL_FALSE, &mvp[0][0]);
        glDrawArrays(GL_TRIANGLES, 0, mesh->vertices);
    }
    mesh_drawend(mesh);
}

void mesh_drawend(mesh_t *mesh)
{
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);
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