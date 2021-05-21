/*
** EPITECH PROJECT, 2021
** asm
** File description:
** label
*/

#include <stdlib.h>
#include "asm.h"

void register_label(char *label_name, int pos, asms_t *asms)
{
    int len = my_strlen(label_name);
    label_t *label;
    char *name;

    check_label_name_validty(label_name, len);
    if (!(label = malloc(sizeof(label_t)))
    || !(name = malloc(sizeof(char) * len)))
        return;
    my_strncpy(name, label_name, len - 1);
    name[len] = 0;
    label->name = name;
    label->pos = pos;
    create_list(&(asms->labels), label);
}

void check_label_name_validty(char *label, int len)
{
    char valid = 1;

    for (int i = 0; i < len - 1; i++) {
        valid = 0;
        for (int j = 0; j < 37; j++) {
            if (label[i] == LABEL_CHARS[j]) {
                valid = 1;
            }
        }
        if (!valid)
            exit(put_error("Label name not valid !\n"));
    }
}

int get_label_value(char *label_name, asms_t *asms)
{
    label_t *label;
    char *name = label_name + 1;
    int len = my_strlen(name);

    for (list_t *list = asms->labels; list; list = list->next) {
        label = (label_t*) list->data;
        if (!my_strcmp(name, label->name)
        && len == my_strlen(label->name))
            return (label->pos);
    }
    exit(put_error("Unknown label !\n"));
}