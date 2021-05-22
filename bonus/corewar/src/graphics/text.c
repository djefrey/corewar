/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** text
*/

#include "bonus.h"
#include "my.h"
#include "text.h"

texts_t *texts_create(char *font_path)
{
    texts_t *texts = malloc(sizeof(texts_t));
    sfImage *image = sfImage_createFromFile(font_path);
    sfTexture *texture = NULL;

    if (!texts || !image)
        return (NULL);
    else if (!(texture = sfTexture_createFromImage(image, NULL)))
        return (NULL);
    glGenBuffers(1, &(texts->pos_buffer));
    texts->image = image;
    texts->font_texture = texture;
    texts->texts = NULL;
    return (texts);
}

text_t *text_create(char *str, sfVector2f pos, texts_t *texts)
{
    text_t *text = malloc(sizeof(text_t));

    if (!text)
        return (NULL);
    text->string = my_strdup(str);
    text->pos = pos;
    text->color = (sfVector3f) {1.0f, 1.0f, 1.0f};
    create_list(&(texts->texts), text);
    return (text);
}

text_t *text_create_size(size_t size, sfVector2f pos, texts_t *texts)
{
    text_t *text = malloc(sizeof(text_t));
    char *str = malloc(size);

    if (!text || !str)
        return (NULL);
    text->string = str;
    text->pos = pos;
    text->color = (sfVector3f) {1.0f, 1.0f, 1.0f};
    create_list(&(texts->texts), text);
    return (text);
}

void texts_renderlist(texts_t *texts, GLuint program_id)
{
    GLuint color_fact_id = glGetUniformLocation(program_id, "colorFactor");
    text_t *text;

    glUseProgram(program_id);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, texts->pos_buffer);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, NULL);
    sfTexture_bind(texts->font_texture);
    for (list_t *list = texts->texts; list; list = list->next) {
        text = (text_t*) list->data;
        glUniform3f(color_fact_id, text->color.x, text->color.y, text->color.z);
        text_render(text);
    }
    sfTexture_bind(NULL);
    glDisableVertexAttribArray(0);
    glUseProgram(0);
}

void text_render(text_t *text)
{
    unsigned int c;
    sfVector2f pos = text->pos;
    float x = 0;
    float y = 0;
    const float width = 24.0f;
    const float height = 24.0f;
    const float padding = 8.0f;
    sfVector2f text_pos;

    for (int i = 0; text->string[i]; i++) {
        c = text->string[i];
        if (c == '\n') {
            y -= height;
            x = 0;
            continue;
        }
        text_pos.x = (c % 16) / 16.0f;
        text_pos.y = (c / 16) / 16.0f;
        GLfloat box[4][4] = {
            {pos.x + x,         pos.y + y,          text_pos.x,                 (text_pos.y + 1.0f / 16.0f)},
            {pos.x + x + width, pos.y + y,          text_pos.x + 1.0f / 16.0f,  (text_pos.y + 1.0f / 16.0f)},
            {pos.x + x,         pos.y + y + height, text_pos.x,                 text_pos.y},
            {pos.x + x + width, pos.y + y + height, text_pos.x + 1.0f / 16.0f,  text_pos.y},
        };
        glBufferData(GL_ARRAY_BUFFER, sizeof(box), &box[0][0], GL_DYNAMIC_DRAW);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        x += padding;
    }
}

void texts_destroy(texts_t *texts)
{
    list_t *next;

    for (list_t *list = texts->texts; list; list = next) {
        next = list->next;
        text_destroy((text_t*) list->data);
        free(list);
    }
    sfTexture_destroy(texts->font_texture);
    sfImage_destroy(texts->image);
    glDeleteBuffers(1, &(texts->pos_buffer));
}

void text_destroy(text_t *text)
{
    free(text->string);
    free(text);
}