/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** live + aff
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_list.h"
#include "tests.h"

Test(live, live_instruction, .init = cr_redirect_stdout)
{
    vm_t vm;
    champion_t champion;
    process_t process;
    char instr[] = {1, 0, 0, 0, 1};

    if (create_real_test_environment(&vm, &champion, &process))
        return;
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    champion.live_cycles = 10;
    live_instruction(&process, &champion, &vm);
    cr_assert_stdout_eq_str("Le joueur 1 (TestChamp) est en vie.\n");
    cr_assert_eq(champion.live_cycles, 0);
    cr_assert_eq(process.pc, 5);
    free(champion.header);
}

Test(aff, aff_instruction, .init = cr_redirect_stdout)
{
    vm_t vm;
    process_t process;
    char instr[] = {10, 64, 1, 10, 64, 2, 10, 64, 3, 10, 64, 1, 10, 64, 4};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    process.registers[0] = 't';
    process.registers[1] = 'e';
    process.registers[2] = 's';
    process.registers[3] = '\n';
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    aff_instruction(&process, NULL, &vm);
    aff_instruction(&process, NULL, &vm);
    aff_instruction(&process, NULL, &vm);
    aff_instruction(&process, NULL, &vm);
    aff_instruction(&process, NULL, &vm);
    cr_assert_stdout_eq_str("test\n");
    cr_assert_eq(process.pc, 15);
}