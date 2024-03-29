/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** operations
*/

#include <stdlib.h>
#include "my.h"
#include "my_list.h"
#include "tests.h"

Test(operations, add_instruction)
{
    vm_t vm;
    process_t process;
    char instr[] = {4, 84, 1, 2, 3};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    process.registers[0] = 12;
    process.registers[1] = 15;
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    add_instruction(&process, NULL, &vm);
    cr_assert_eq(process.registers[0], 12);
    cr_assert_eq(process.registers[1], 15);
    cr_assert_eq(process.registers[2], 27);
    cr_assert_eq(process.pc, 5);
}

Test(operations, sub_instruction)
{
    vm_t vm;
    process_t process;
    char instr[] = {4, 84, 1, 2, 3};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    process.registers[0] = 15;
    process.registers[1] = 12;
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    sub_instruction(&process, NULL, &vm);
    cr_assert_eq(process.registers[0], 15);
    cr_assert_eq(process.registers[1], 12);
    cr_assert_eq(process.registers[2], 3);
    cr_assert_eq(process.pc, 5);
}

Test(operations, and_instruction)
{
    vm_t vm;
    process_t process;
    char instr[] = {4, 164, 0, 0, 0, 5, 0, 0, 0, 3, 5};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    and_instruction(&process, NULL, &vm);
    cr_assert_eq(process.registers[4], 1);
    cr_assert_eq(process.carry, 0);
    cr_assert_eq(process.pc, 11);
}

Test(operations, and_null_instruction)
{
    vm_t vm;
    process_t process;
    char instr[] = {4, 164, 0, 0, 0, 5, 0, 0, 0, 0, 5};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    and_instruction(&process, NULL, &vm);
    cr_assert_eq(process.registers[4], 0);
    cr_assert_eq(process.carry, 1);
    cr_assert_eq(process.pc, 11);
}

Test(operations, or_instruction)
{
    vm_t vm;
    process_t process;
    char instr[] = {4, 164, 0, 0, 0, 5, 0, 0, 0, 3, 5};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    or_instruction(&process, NULL, &vm);
    cr_assert_eq(process.registers[4], 7);
    cr_assert_eq(process.carry, 0);
    cr_assert_eq(process.pc, 11);
}

Test(operations, or_null_instruction)
{
    vm_t vm;
    process_t process;
    char instr[] = {4, 164, 0, 0, 0, 0, 0, 0, 0, 0, 5};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    or_instruction(&process, NULL, &vm);
    cr_assert_eq(process.registers[4], 0);
    cr_assert_eq(process.carry, 1);
    cr_assert_eq(process.pc, 11);
}

Test(operations, xor_instruction)
{
    vm_t vm;
    process_t process;
    char instr[] = {4, 164, 0, 0, 0, 5, 0, 0, 0, 1, 5};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    xor_instruction(&process, NULL, &vm);
    cr_assert_eq(process.registers[4], 4);
    cr_assert_eq(process.carry, 0);
    cr_assert_eq(process.pc, 11);
}

Test(operations, xor_null_instruction)
{
    vm_t vm;
    process_t process;
    char instr[] = {4, 164, 0, 0, 0, 5, 0, 0, 0, 5, 5};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    xor_instruction(&process, NULL, &vm);
    cr_assert_eq(process.registers[4], 0);
    cr_assert_eq(process.carry, 1);
    cr_assert_eq(process.pc, 11);
}
