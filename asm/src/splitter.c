/*
** EPITECH PROJECT, 2021
** asm
** File description:
** splitter
*/

#include <stdlib.h>
#include "asm.h"

static void add_element_to_array(char ***array,
int *size, char *start, int *element_size)
{
    char *element;

    if (start[0] == COMMENT_CHAR) {
        *element_size = 0;
        return;
    }
    if (!(element = malloc(sizeof(char) * (*element_size + 1))))
        exit(84);
    my_strncpy(element, start, *element_size);
    *array = realloc(*array, sizeof(char*) * (*size + 2));
    (*array)[*size] = element;
    (*array)[*size + 1] = NULL;
    *size += 1;
    *element_size = 0;
}

/*
** Split file content into a two-dimensional array
** Ignore comments
*/
char **split_file(char *str)
{
    char **array = NULL;
    int size = 0;
    char *start = str;
    int line_size = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '\n') {
            if (line_size == 0) {
                start = str + i + 1;
                continue;
            }
            add_element_to_array(&array, &size, start, &line_size);
            start = str + i + 1;
            continue;
        } else
            line_size++;
    }
    if (line_size > 0)
        add_element_to_array(&array, &size, start, &line_size);
    return (array);
}

/*
** Split line into a two-dimensional array
** Split spaces, tabs and commas
*/
char **split_line(char *line)
{
    char **array = NULL;
    int size = 0;
    char *start = line;
    int word_size = 0;

    for (int i = 0; line[i]; i++) {
        if (line[i] == '\n' || line[i] == '\t'
        || line[i] == ' ' || line[i] == ',') {
            if (word_size == 0) {
                start = line + i + 1;
                continue;
            }
            add_element_to_array(&array, &size, start, &word_size);
            start = line + i + 1;
            continue;
        } else
            word_size++;
    }
    if (word_size > 0)
        add_element_to_array(&array, &size, start, &word_size);
    return (array);
}

void free_split(char **split)
{
    for (int i = 0; split[i]; i++)
        free(split[i]);
    free(split);
}