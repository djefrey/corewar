/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** cube
*/

#include <stdlib.h>
#include "my_list.h"
#include "bonus.h"
#include "gameitem.h"
#include "transform.h"
#include "mesh.h"

gameitem_t *cube_create(mesh_t *mesh, int id)
{
    cube_t *item = malloc(sizeof(cube_t));
    transform_t *transform = transform_create();

    if (!item || !transform)
        return (NULL);
    item->mesh = mesh;
    item->transform = transform;
    item->id = id;
    return ((gameitem_t*) item);
}

int get_cube_size(cube_t *cube, bonus_t *bonus)
{
    unsigned int value = *(bonus->memory + cube->id);

    return (value & 0xFFFFFF);
}

int get_cube_champion(cube_t *cube, bonus_t *bonus)
{
    unsigned int value = *(bonus->memory + cube->id);

    return ((value & 0x7F000000) >> 24);
}

int is_cube_pc(cube_t *cube, bonus_t *bonus)
{
    unsigned int value = *(bonus->memory + cube->id);

    return ((value & 2147483648) > 0);
}

void cube_set_height(cube_t *cube, bonus_t *bonus)
{
    float size = get_cube_size(cube, bonus) / 2.0 + 1;

    transform_set_scale(cube->transform, 1, size, 1);
    transform_set_translation(cube->transform, cube->transform->translation[0],
    size, cube->transform->translation[2]);
}

void cube_set_color_factor_uniform(cube_t *cube,
GLuint color_fact_id, bonus_t *bonus)
{
    float lum = is_cube_pc(cube, bonus) ? 2.0f : 0.75f;
    sfVector3f color = generate_color(get_cube_champion(cube, bonus));

    glUniform3f(color_fact_id, color.x * lum, color.y * lum, color.z * lum);
}
