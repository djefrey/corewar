/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** tests header
*/

#ifndef TESTS_H_
#define TESTS_H_

#include <criterion/criterion.h>
#include "corewar.h"
#include "process.h"
#include "vm.h"

int create_criterion_vm(vm_t *vm);
void create_criterion_process(process_t *process);

#endif /* !TESTS_H_ */
