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
#include "vm.h"

champion_t *champion_create(char *filepath, int id, int addr, vm_t *vm)
{
    champion_t *champion;
    int fd = open(filepath, O_RDONLY);
    process_t *process;

    if (fd == -1 || !(champion = malloc(sizeof(champion_t)))
    || champion_read_header(champion, fd))
        return (NULL);
    champion->id = id;
    champion->dead = 0;
    champion->live_cycles = 0;
    champion->processes = NULL;
    if (vm_write_file_in_memory(vm, fd, addr, champion->header->prog_size))
        return (NULL);
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

void champion_update(champion_t *champion, vm_t *vm)
{
    process_t *process;

    champion->live_cycles++;
    for (list_t *list = champion->processes; list; list = list->next) {
        process = (process_t*) list->data;
        process_update(process, champion, vm);
    }
    if (champion->live_cycles >= vm->dead_cycles)
        champion->dead = 1;
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