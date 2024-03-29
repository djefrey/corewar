/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** virtual machine
*/

#ifndef VM_H_
#define VM_H_

#include "my_list.h"

#ifdef BONUS
typedef struct bonus_s bonus_t;
typedef struct vm_s vm_t;

void bonus_create(vm_t *vm);
int bonus_update(bonus_t *bonus, vm_t *vm);
void bonus_write_champion_id(bonus_t *bonus, int addr, int size, int id);
void bonus_set_actual_pc(bonus_t *bonus, int addr, char actual);
void bonus_add_infotext(bonus_t *bonus, int champion_id);
void bonus_destroy(bonus_t *bonus);
#endif

typedef struct vm_s {
    char *memory;
    int cycles;
    int dead_cycles;
    int dump_cycles;
    int last_live;
    int nb_lives;
    int lives_cycles;
    list_t *champions;
#ifdef BONUS
    bonus_t *bonus;
#endif
} vm_t;

int vm_init(vm_t *vm);
void vm_dump(vm_t *vm);
void vm_print_winner(vm_t *vm);
void vm_destroy(vm_t *vm);

void vm_run(vm_t *vm);
int vm_update_champions(vm_t *vm);
int vm_cycles(vm_t *vm);
void vm_process_alive(vm_t *vm);

#endif /* !VM_H_ */
