/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** utils
*/

#include <stdlib.h>
#include "tests.h"
#include "my.h"
#include "my_list.h"

int create_criterion_vm(vm_t *vm)
{
    if (!(vm->memory = malloc(sizeof(char) * 128)))
        return (1);
    vm->cycles = 0;
    vm->dead_cycles = 100;
    vm->dump_cycles = -1;
    vm->champions = NULL;
    return (0);
}

void create_criterion_process(process_t *process)
{
    for (int i = 0; i < REG_NUMBER; i++)
        process->registers[i] = 0;
    process->pc = 0;
    process->carry = 0;
}

int create_real_test_environment(vm_t *vm,
champion_t *champion, process_t *process)
{
    header_t *header = malloc(sizeof(header_t));

    if (!header || create_criterion_vm(vm))
        return (1);
    create_criterion_process(process);
    header->magic_number = 0;
    header->prog_size = 0;
    my_strcpy(header->prog_name, "TestChamp\0");
    my_strcpy(header->prog_comment, "A test champion\0");
    champion->header = header;
    champion->id = 1;
    champion->dead = 0;
    champion->live_cycles = 0;
    champion->processes = NULL;
    create_list(&(champion->processes), process);
    create_list(&(vm->champions), champion);
    return (0);
}