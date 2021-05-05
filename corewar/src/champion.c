/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** champion
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_list.h"
#include "corewar.h"
#include "champion.h"
#include "process.h"

champion_t *champion_create(char *filepath, int id, char *memory, int addr)
{
    champion_t *champion;
    int fd = open(filepath, O_RDONLY);
    process_t *process;

    if (fd == -1 || !(champion = malloc(sizeof(champion_t)))
    || champion_read_header(champion, fd))
        return (NULL);
    champion->dead = 0;
    champion->prev_live_cycles = 1;
    champion->processes = NULL;
    if (!(process = process_create(id, addr))) {
        champion_destroy(champion);
        return (NULL);
    }
    create_list(&(champion->processes), process);
    read(fd, memory + addr, champion->header->prog_size);
    close(fd);
    return (champion);
}

int champion_read_header(champion_t *champion, int fd)
{
    header_t *header;
    unsigned int len = get_file_size(fd);

    if (len < sizeof(header_t) || !(header = malloc(sizeof(header_t))))
        return (1);
    read_header(header, fd, sizeof(header_t));
    if (header->magic_number != MAGIC_NUMBER || header->prog_size == 0) {
        free(header);
        return (1);
    }
    champion->header = header;
    return (0);
}

void champion_destroy(champion_t *champion)
{
    list_t *next;

    for (list_t *list = champion->processes; list; list = next) {
        next = list->next;
        process_destroy((process_t*) list->data);
        free(next);
    }
    free(champion->header);
    free(champion);
}