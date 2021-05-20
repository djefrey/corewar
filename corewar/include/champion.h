/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** champion
*/

#ifndef CHAMPION_H_
#define CHAMPION_H_

typedef struct vm_s vm_t;
typedef struct process_s process_t;
typedef struct header_s header_t;

typedef struct champion_s {
    header_t *header;
    int id;
    int nb_processes;
    list_t *processes;
} champion_t;

champion_t *champion_create(char *filepath, int id, int addr, vm_t *vm);
int champion_read_header(champion_t *champion, int fd);
void champion_add_process(champion_t *champion, process_t *process);
void champion_update(champion_t *champion, vm_t *vm);
void champion_destroy(champion_t *champion);

#endif /* !CHAMPION_H_ */
