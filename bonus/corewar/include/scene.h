/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** scene
*/

#ifndef SCENE_H_
#define SCENE_H_

#include <SFML/Graphics/Transform.h>

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "my_list.h"

#include "camera.h"
#include "hud.h"

typedef struct bonus_s bonus_t;

typedef struct scene_s {
    list_t *meshes;
    list_t *cubes;
    camera_t *camera;
} scene_t;

scene_t *scene_create(bonus_t *bonus);
void scene_draw(scene_t *scene, bonus_t *bonus);
void scene_destroy(scene_t *scene);

#endif /* !SCENE_H_ */
