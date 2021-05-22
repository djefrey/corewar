/*
** EPITECH PROJECT, 2021
** opengl
** File description:
** camera
*/

#include <math.h>
#include "bonus.h"
#include "camera.h"

camera_t *camera_create(void)
{
    camera_t *camera = malloc(sizeof(camera_t));
    float fov = glm_rad(80);
    float aspect_ratio = ((float) WINDOW_WIDTH) / WINDOW_HEIGHT;

    if (!camera)
        return (NULL);
    glm_vec3_copy((vec3) {0.0f, 0.0f, 1.0f}, camera->pos);
    glm_vec3_copy((vec3) {0.0f, 0.0f, 0.0f}, camera->target);
    glm_perspective(fov, aspect_ratio, 0.1f, 1500.0f, camera->projection_matrix);
    return (camera);
}

void camera_set_pos(camera_t *camera, float x, float y, float z)
{
    glm_vec3_copy((vec3) {x, y, z}, camera->pos);
}

void camera_set_target(camera_t *camera, float x, float y, float z)
{
    glm_vec3_copy((vec3) {x, y, z}, camera->target);
}

void camera_get_projection_matrix(camera_t *camera, mat4 matrix)
{
    mat4 look_at;

    glm_lookat(camera->pos, camera->target, (vec3) {0, 1, 0}, look_at);
    glm_mat4_mul(camera->projection_matrix, look_at, matrix);
}

void camera_calculate_pos(camera_t *camera, float dist, float angle_x, float angle_y)
{
    float x = camera->target[0] + cos(angle_x * 3.14 / 180) * dist;
    float y = camera->target[1] + sin(angle_y * 3.14 / 180) * dist;
    float z = camera->target[2] + cos((angle_x + 90) * 3.14 / 180) * dist;

    camera_set_pos(camera, x, y, z);
}

void camera_destroy(camera_t *camera)
{
    free(camera);
}