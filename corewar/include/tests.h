/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** tests header
*/

#ifndef TESTS_H_
#define TESTS_H_

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"
#include "vm.h"
#include "process.h"
#include "champion.h"

int create_criterion_vm(vm_t *vm);
void create_criterion_process(process_t *process);
int create_real_test_environment(vm_t *vm,
champion_t *champion, process_t *process);


void add_instruction(process_t *process, champion_t *champion, vm_t *vm);
void sub_instruction(process_t *process, champion_t *champion, vm_t *vm);
void and_instruction(process_t *process, champion_t *champion, vm_t *vm);
void or_instruction(process_t *process, champion_t *champion, vm_t *vm);
void xor_instruction(process_t *process, champion_t *champion, vm_t *vm);

void ld_instruction(process_t *process, champion_t *champion, vm_t *vm);
void ldi_instruction(process_t *process, champion_t *champion, vm_t *vm);
void lld_instruction(process_t *process, champion_t *champion, vm_t *vm);
void lldi_instruction(process_t *process, champion_t *champion, vm_t *vm);

void st_instruction(process_t *process, champion_t *champion, vm_t *vm);
void sti_instruction(process_t *process, champion_t *champion, vm_t *vm);
void fork_instruction(process_t *process, champion_t *champion, vm_t *vm);
void lfork_instruction(process_t *process, champion_t *champion, vm_t *vm);

void live_instruction(process_t *process, champion_t *champion, vm_t *vm);
void zjmp_instruction(process_t *process, champion_t *champion, vm_t *vm);
void aff_instruction(process_t *process, champion_t *champion, vm_t *vm);

#endif /* !TESTS_H_ */
