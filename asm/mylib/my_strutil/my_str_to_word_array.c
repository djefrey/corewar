/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** split string into string array
*/

#include <stdlib.h>
#include "my.h"

static int get_rows(char const *str)
{
    int size = 0;
    int row_size = 0;
    unsigned char split = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_letter(str[i]) && !is_digit(str[i])) {
            if (row_size > 0)
                split = 1;
        } else  {
            if (split) {
                size++;
                row_size = 0;
                split = 0;
            }
            row_size++;
        }
    }
    return (size);
}

static int get_columns(char const *str)
{
    int sel_word = 0;
    int word_size = 0;
    int biggest = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_letter(str[i]) && !is_digit(str[i])) {
            biggest = (biggest > word_size ? biggest : word_size);
            word_size = 0;
            sel_word++;
        } else {
            word_size++;
        }
    }
    biggest = (biggest > word_size ? biggest : word_size);
    return (biggest);
}

static char **create_array(int rows, int columns)
{
    char **array = malloc(sizeof(char*) * (rows + 1));
    for (int i = 0; i < rows; i++) {
        array[i] = malloc(sizeof(char) * (columns + 1));
    }
    return (array);
}

static void copy_words(char const *str, char **array, int size)
{
    int sel_word = 0;
    int sel_letter = 0;

    for (int i = 0; sel_word < size; i++) {
        if (!is_letter(str[i]) && !is_digit(str[i])) {
            if (sel_letter == 0)
                continue;
            array[sel_word][sel_letter] = '\0';
            sel_letter = 0;
            sel_word++;
        } else {
            array[sel_word][sel_letter] = str[i];
            sel_letter++;
        }
    }
}

char **my_str_to_word_array(char const *str)
{
    int rows = get_rows(str);
    int columns = get_columns(str);
    char **array = create_array(rows, columns);

    copy_words(str, array, rows);
    return (array);
}