/*
** EPITECH PROJECT, 2021
** opengl
** File description:
** transform
*/

#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include <cglm/cglm.h>

typedef struct transform_s {
    vec3 translation;
    vec3 rotation;
    vec3 scale;
} transform_t;

transform_t *transform_create(void);
void get_transform_matrix(transform_t *transform, mat4 matrix);
void transform_destroy(transform_t *transform);

void transform_set_translation(transform_t *transform, float x, float y, float z);
void transform_add_translation(transform_t *transform, float x, float y, float z);

void transform_set_rotation(transform_t *transform, float x, float y, float z);
void transform_add_rotation(transform_t *transform, float x, float y, float z);

void transform_set_scale(transform_t *transform, float x, float y, float z);
void transform_add_scale(transform_t *transform, float x, float y, float z);

#endif /* !TRANSFORM_H_ */
