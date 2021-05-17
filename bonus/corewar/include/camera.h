/*
** EPITECH PROJECT, 2021
** opengl
** File description:
** camera
*/

#ifndef CAMERA_H_
#define CAMERA_H_

#include <cglm/cglm.h>

typedef struct camera_s {
    vec3 pos;
    vec3 target;
    mat4 projection_matrix;
} camera_t;

camera_t *camera_create(void);
void camera_set_pos(camera_t *camera, float x, float y, float z);
void camera_set_target(camera_t *camera, float x, float y, float z);
void camera_get_projection_matrix(camera_t *camera, mat4 matrix);
void camera_destroy(camera_t *camera);

#endif /* !CAMERA_H_ */
