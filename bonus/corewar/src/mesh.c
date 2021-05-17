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
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indices_buffer);
}

void mesh_drawlist(mesh_t *mesh, GLuint program_id,
mat4 projection_matrix, bonus_t *bonus)
{
    GLuint matrix_id = glGetUniformLocation(program_id, "MVP");
    GLuint color_fact_id = glGetUniformLocation(program_id, "colorFactor");
    mat4 mvp;
    cube_t *item;

    mesh_drawinit(mesh);
    for (list_t *list = mesh->items; list; list = list->next) {
        item = (cube_t*) list->data;
        get_transform_matrix(item->transform, mvp);
        glm_mat4_mul(projection_matrix, mvp, mvp);
        glUniformMatrix4fv(matrix_id, 1, GL_FALSE, &mvp[0][0]);
        cube_set_height(item, bonus);
        cube_set_color_factor_uniform(item, color_fact_id, bonus);
        glDrawElements(GL_TRIANGLES, mesh->vertices, GL_UNSIGNED_INT, (void*) 0);
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