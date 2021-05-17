/*
** EPITECH PROJECT, 2021
** opengl
** File description:
** shaders
*/

#include <stdlib.h>
#include <stdio.h>
#include "bonus.h"

GLuint load_shaders(char *vertex_filepath, char *fragment_filepath)
{
    GLuint vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);
    GLuint program_id = 0;

    printf("Compile %s / %s\n", vertex_filepath, fragment_filepath);
    compile_shader(vertex_shader_id, vertex_filepath);
    compile_shader(fragment_shader_id, fragment_filepath);
    program_id = create_program(vertex_shader_id, fragment_shader_id);
    return (program_id);
}

void compile_shader(int shader_id, char *filepath)
{
    char *code = read_file(filepath);
    int info_log_length = 0;
    char *error;

    if (!code) {
        printf("WARNING: cannot open/read '%s' !\n", filepath);
        return;
    }
    glShaderSource(shader_id, 1, (const char * const *) &code, NULL);
    glCompileShader(shader_id);
    glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &info_log_length);
    if (info_log_length > 0) {
        error = malloc(sizeof(char) * (info_log_length + 1));
        if (!error)
            return;
        glGetShaderInfoLog(shader_id, info_log_length, NULL, error);
        printf("%s: %s\n", filepath, error);
        free(error);
    }
    free(code);
}

GLuint create_program(int vertex_shader_id, int fragment_shader_id)
{
    GLuint program_id = glCreateProgram();

    glAttachShader(program_id, vertex_shader_id);
    glAttachShader(program_id, fragment_shader_id);
    glLinkProgram(program_id);
    check_program(program_id);
    glDetachShader(program_id, vertex_shader_id);
    glDetachShader(program_id, fragment_shader_id);
    glDeleteShader(vertex_shader_id);
    glDeleteShader(fragment_shader_id);
    return (program_id);
}

void check_program(int program_id)
{
    GLint result = 0;
    int info_log_length = 0;
    char *error = NULL;

    glGetShaderiv(program_id, GL_LINK_STATUS, &result);
    glGetShaderiv(program_id, GL_INFO_LOG_LENGTH, &info_log_length);
    if (info_log_length > 0) {
        error = malloc(sizeof(char) * (info_log_length + 1));
        if (!error)
            return;
        glGetShaderInfoLog(program_id, info_log_length, NULL, error);
        printf("%i: %s\n", result, error);
        free(error);
    }
}