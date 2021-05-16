/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** store
*/

#include <stdlib.h>
#include "my.h"
#include "my_list.h"
#include "tests.h"

Test(st, st_reg_to_reg)
{
    vm_t vm;
    process_t process;
    char instr[] = {3, 80, 1, 3};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    process.registers[1] = 12;
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    st_instruction(&process, NULL, &vm);
    cr_assert_eq(process.registers[1], 12);
    cr_assert_eq(process.registers[3], 12);
    cr_assert_eq(process.pc, 4);
}

Test(st, st_reg_to_idx)
{
    vm_t vm;
    process_t process;
    char instr[] = {3, 112, 1, 0, 6, 0, 0};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    process.registers[1] = 12;
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    st_instruction(&process, NULL, &vm);
    cr_assert_eq(process.registers[1], 12);
    cr_assert_eq(*(vm.memory + 5), 0);
    cr_assert_eq(*(vm.memory + 6), 12);
    cr_assert_eq(process.pc, 5);
}

Test(st, sti_add_direct)
{
    vm_t vm;
    process_t process;
    char instr[] = {3, 104, 1, 0, 0, 0, 6, 0, 0, 0, 5, 0};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    process.registers[1] = 12;
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    sti_instruction(&process, NULL, &vm);
    cr_assert_eq(process.registers[1], 12);
    cr_assert_eq(*(vm.memory + 11), 12);
    cr_assert_eq(process.pc, 11);
}


Test(st, sti_add_indirect)
{
    vm_t vm;
    process_t process;
    char instr[] = {3, 124, 1, 0, 6, 0, 7, 4, 0, 0, 0};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    process.registers[1] = 12;
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    sti_instruction(&process, NULL, &vm);
    cr_assert_eq(process.registers[1], 12);
    cr_assert_eq(*(vm.memory + 11), 12);
    cr_assert_eq(process.pc, 7);
}
