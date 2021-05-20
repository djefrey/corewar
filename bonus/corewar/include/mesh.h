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

typedef struct bonus_s bonus_t;

typedef struct mesh_s {
    GLuint vertex_buffer;
    GLuint color_buffer;
    GLuint indices_buffer;
    int vertices;
    int triangles;
    list_t *items;
    GLuint program_id;
    void (*mesh_drawlist_fct)(struct mesh_s *mesh,
    mat4 projection_matrix, bonus_t *bonus);
    void (*mesh_destroy_fct)(struct mesh_s *mesh);
} mesh_t;

typedef void (*mesh_drawlist_fct_t)(mesh_t *mesh,
mat4 projection_matrix, bonus_t *bonus);
typedef void (*mesh_destroy_fct_t)(mesh_t *mesh);

mesh_t *mesh_create(GLfloat vertex_array[],
GLfloat color_array[], GLuint indices_array[], int size[2]);
void mesh_destroy(mesh_t *mesh);

mesh_t *cube_mesh_create(void);
void cube_mesh_drawinit(mesh_t *mesh);
void cube_mesh_drawlist(mesh_t *mesh, mat4 projection_matrix, bonus_t *bonus);
void cube_mesh_drawend(mesh_t *mesh);
void cube_mesh_destroy(mesh_t *mesh);

#endif /* !MESH_H_ */
