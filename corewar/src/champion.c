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
#include "corewar.h"
#include "champion.h"
#include "process.h"
#include "vm.h"

champion_t *champion_create(char *filepath, int id, int addr, vm_t *vm)
{
    champion_t *champion;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1 || !(champion = malloc(sizeof(champion_t)))
    || champion_read_header(champion, fd))
        return (NULL);
    champion->id = id;
    champion->nb_processes = 0;
    champion->processes = NULL;
    if (write_file_in_memory(addr, fd, champion->header->prog_size, vm))
        return (NULL);
    #ifdef BONUS
    bonus_write_champion_id(vm->bonus, addr, champion->header->prog_size, id);
    #endif
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

void champion_add_process(champion_t *champion, process_t *process)
{
    champion->nb_processes++;
    create_list(&(champion->processes), process);
}

void champion_update(champion_t *champion, vm_t *vm)
{
    process_t *process;
    list_t *next;

    for (list_t *list = champion->processes; list; list = next) {
        next = list->next;
        process = (process_t*) list->data;
        if (process_update(process, champion, vm)) {
            my_delete_node(&(champion->processes), process);
            process_destroy(process);
            champion->nb_processes--;
        }
    }
}

void champion_destroy(champion_t *champion)
{
    list_t *next;

    for (list_t *list = champion->processes; list; list = next) {
        next = list->next;
        process_destroy((process_t*) list->data);
        free(list);
    }
    free(champion->header);
    free(champion);
}