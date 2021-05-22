/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** text
*/

#ifndef TEXT_H_
#define TEXT_H_

#include <SFML/Graphics.h>

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

typedef struct texts_s {
    sfImage *image;
    sfTexture *font_texture;
    GLuint pos_buffer;
    list_t *texts;
} texts_t;

typedef struct text_s {
    char *string;
    sfVector2f pos;
    sfVector3f color;
} text_t;

texts_t *texts_create(char *font_path);
text_t *text_create(char *str, sfVector2f pos, texts_t *texts);
text_t *text_create_size(size_t size, sfVector2f pos, texts_t *texts);
void texts_renderlist(texts_t *texts, GLuint program_id);
void text_render(text_t *text);
void texts_destroy(texts_t *texts);
void text_destroy(text_t *text);

#endif /* !TEXT_H_ */
