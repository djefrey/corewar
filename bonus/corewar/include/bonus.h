/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** bonus
*/

#ifndef BONUS_H_
#define BONUS_H_

#include <SFML/Window.h>

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "corewar.h"
#include "vm.h"

#include "scene.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WINDOW_TITLE "Corewar"

typedef struct bonus_s {
    sfWindow *window;
    unsigned int *memory;
    scene_t *scene;
    float cam_distance;
    float cam_rot_x;
    float cam_rot_y;
} bonus_t;

bonus_t *bonus_create(void);
int bonus_update(bonus_t *bonus, vm_t *vm);
void bonus_event(bonus_t *bonus, int *run);
void bonus_camera_move_update(bonus_t *bonus);
void bonus_camera_zoom(bonus_t *bonus, sfMouseWheelScrollEvent event);
void bonus_draw(bonus_t *bonus);
void bonus_destroy(bonus_t *bonus);

sfWindow *window_create(void);
void scene_create_cubes(scene_t *scene);

GLuint load_shaders(char *vertex_filepath, char *fragment_filepath);
void compile_shader(int shader_id, char *filepath);
GLuint create_program(int vertex_shader_id, int fragment_shader_id);
void check_program(int program_id);

char *read_file(char *path);

#endif /* !BONUS_H_ */
