/*
** EPITECH PROJECT, 2021
** opengl
** File description:
** mesh
*/

#ifndef MESH_H_
#define MESH_H_

#include <SFML/Graphics/Transform.h>

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <cglm/cglm.h>

#include "my_list.h"

typedef struct mesh_s {
    GLuint vertex_buffer;
    GLuint color_buffer;
    int vertices;
    int triangles;
    list_t *items;
} mesh_t;

mesh_t *mesh_create(GLfloat vertex_array[], GLfloat color_array[], int vertices);
void mesh_drawinit(mesh_t *mesh);
void mesh_drawlist(mesh_t *mesh, GLuint matrix_id, mat4 projection_matrix);
void mesh_drawend(mesh_t *mesh);
void mesh_destroy(mesh_t *mesh);

#endif /* !MESH_H_ */
