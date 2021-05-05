/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** champion
*/

#ifndef CHAMPION_H_
#define CHAMPION_H_

typedef struct champion_s {
    header_t *header;
    char dead;
    int prev_live_cycles;
    list_t *processes;
} champion_t;

champion_t *champion_create(char *filepath, int id, char *memory, int addr);
int champion_read_header(champion_t *champion, int fd);
void champion_destroy(champion_t *champion);

#endif /* !CHAMPION_H_ */
