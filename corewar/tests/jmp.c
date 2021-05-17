/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** jmp
*/

#include <stdlib.h>
#include "my.h"
#include "my_list.h"
#include "tests.h"

Test(zjmp, zjmp_carry_0)
{
    vm_t vm;
    process_t process;
    char instr[] = {9, 128, 0, 0, 0, 1};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    process.carry = 0;
    zjmp_instruction(&process, NULL, &vm);
    cr_assert_eq(process.pc, 6);
}

Test(zjmp, zjmp_carry_1)
{
    vm_t vm;
    process_t process;
    char instr[] = {9, 128, 0, 0, 0, 1};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    process.carry = 1;
    zjmp_instruction(&process, NULL, &vm);
    cr_assert_eq(process.pc, 1);
}