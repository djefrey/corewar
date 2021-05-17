/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** fork
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_list.h"
#include "tests.h"

Test(fork, fork_instruction)
{
    vm_t vm;
    champion_t champion;
    process_t process;
    char instr[] = {0xc, 128, 0, 1};

    if (create_real_test_environment(&vm, &champion, &process))
        return;
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    fork_instruction(&process, &champion, &vm);
    cr_assert_eq(((process_t*) champion.processes->data)->pc, 1);
    cr_assert_eq(((process_t*) champion.processes->next->data)->pc, 4);
    free(champion.header);
}

Test(fork, lfork_instruction)
{
    vm_t vm;
    champion_t champion;
    process_t process;
    char instr[] = {0xc, 128, 0, 0, 4, 0};

    if (create_real_test_environment(&vm, &champion, &process))
        return;
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    lfork_instruction(&process, &champion, &vm);
    cr_assert_eq(((process_t*) champion.processes->data)->pc, 1024);
    cr_assert_eq(((process_t*) champion.processes->next->data)->pc, 6);
    free(champion.header);
}