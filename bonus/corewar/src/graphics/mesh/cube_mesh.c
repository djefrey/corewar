/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** cube mesh
*/

#include <stdlib.h>
#include "mesh.h"
#include "transform.h"
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

mesh_t *cube_mesh_create(void)
{
    mesh_t *mesh = mesh_create(cube_vertex,
    cube_colors, cube_indices, (int[2]) {24, 36});
    GLuint program_id = load_shaders(
        "bonus/corewar/res/shaders/cube/cube_vertex.glsl",
        "bonus/corewar/res/shaders/cube/cube_fragment.glsl"
    );

    if (!mesh)
        return (NULL);
    mesh->program_id = program_id;
    mesh->mesh_drawlist_fct = &cube_mesh_drawlist;
    mesh->mesh_destroy_fct = &cube_mesh_destroy;
    return (mesh);
}

void cube_mesh_drawinit(mesh_t *mesh)
{
    glUseProgram(mesh->program_id);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, mesh->vertex_buffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, mesh->color_buffer);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indices_buffer);
}

void cube_mesh_drawlist(mesh_t *mesh, mat4 projection_matrix, bonus_t *bonus)
{
    GLuint matrix_id = glGetUniformLocation(mesh->program_id, "MVP");
    GLuint color_fact_id = glGetUniformLocation(mesh->program_id, "colorFactor");
    mat4 mvp;
    cube_t *item;

    cube_mesh_drawinit(mesh);
    for (list_t *list = mesh->items; list; list = list->next) {
        item = (cube_t*) list->data;
        get_transform_matrix(item->transform, mvp);
        glm_mat4_mul(projection_matrix, mvp, mvp);
        glUniformMatrix4fv(matrix_id, 1, GL_FALSE, &mvp[0][0]);
        cube_set_height(item, bonus);
        cube_set_color_factor_uniform(item, color_fact_id, bonus);
        glDrawElements(GL_TRIANGLES, mesh->vertices, GL_UNSIGNED_INT, (void*) 0);
    }
    cube_mesh_drawend(mesh);
}

void cube_mesh_drawend(mesh_t *mesh)
{
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);
    glUseProgram(0);
}

void cube_mesh_destroy(mesh_t *mesh)
{
    glDeleteProgram(mesh->program_id);
    mesh_destroy(mesh);
}