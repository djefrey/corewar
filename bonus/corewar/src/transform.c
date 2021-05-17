/*
** EPITECH PROJECT, 2021
** opengl
** File description:
** transform
*/

#include "transform.h"

transform_t *transform_create(void)
{
    transform_t *transform = malloc(sizeof(transform_t));

    if (!transform)
        return (NULL);
    glm_vec3_copy((vec3) {0, 0, 0}, transform->translation);
    glm_vec3_copy((vec3) {0, 0, 0}, transform->rotation);
    glm_vec3_copy((vec3) {1, 1, 1}, transform->scale);
    return (transform);
}

void transform_set_translation(transform_t *transform, float x, float y, float z)
{
    glm_vec3_copy((vec3) {x, y, z}, transform->translation);
}

void transform_add_translation(transform_t *transform, float x, float y, float z)
{
    glm_vec3_add(transform->translation, (vec3) {x, y, z}, transform->translation);
}

void transform_set_rotation(transform_t *transform, float x, float y, float z)
{
    glm_vec3_copy((vec3) {x, y, z}, transform->rotation);
}

void transform_add_rotation(transform_t *transform, float x, float y, float z)
{
    glm_vec3_add(transform->rotation, (vec3) {x, y, z}, transform->rotation);
}

void transform_set_scale(transform_t *transform, float x, float y, float z)
{
    glm_vec3_copy((vec3) {x, y, z}, transform->scale);
}

void transform_add_scale(transform_t *transform, float x, float y, float z)
{
    glm_vec3_add(transform->scale, (vec3) {x, y, z}, transform->scale);
}

void get_transform_matrix(transform_t *transform, mat4 matrix)
{
    glm_mat4_identity(matrix);
    glm_translate(matrix, transform->translation);
    glm_rotate(matrix, transform->rotation[0], (vec3) {1, 0, 0});
    glm_rotate(matrix, transform->rotation[1], (vec3) {0, 1, 0});
    glm_rotate(matrix, transform->rotation[2], (vec3) {0, 0, 1});
    glm_scale(matrix, transform->scale);
}

void transform_destroy(transform_t *transform)
{
    free(transform);
}