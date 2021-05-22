/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** infomations texts
*/

#include <stdlib.h>
#include "my.h"
#include "my_list.h"
#include "bonus.h"
#include "hud.h"
#include "info_text.h"
#include "corewar.h"
#include "champion.h"
#include "vm.h"

void infotext_create(int champion_id, sfVector2f pos, hud_t *hud)
{
    infotext_t *text = malloc(sizeof(infotext_t));
    char *str = malloc(sizeof(char) * 129);

    if (!text || !str)
        return;
    text->string = str;
    text->pos = pos;
    text->color = (sfVector3f) {1.0f, 1.0f, 1.0f};
    text->champion_id = champion_id;
    create_list(&(hud->texts->texts), text);
    create_list(&(hud->infotexts), text);
}

void infotext_update(infotext_t *text, vm_t *vm)
{
    champion_t *champion = get_champion_by_id(vm, text->champion_id);
    sfVector3f color = generate_color(champion->id);
    int len;

    if (!champion) {
        my_strcpy(text->string, "ERR.");
        return;
    }
    text->color = color;
    len = my_strlen(champion->header->prog_name);
    if (len > 32) {
        my_strncpy(text->string, champion->header->prog_name, 32);
        my_strcat(text->string, "...\n");
    } else {
        my_strcpy(text->string, champion->header->prog_name);
        my_strcat(text->string, "\n");
    }
    len = len > 32 ? 36 : len + 1;
    gcvt(champion->nb_processes, 3, text->string + len);
    my_strcat(text->string, " processes");
}