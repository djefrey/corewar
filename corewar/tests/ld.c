/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** load
*/

#include <stdlib.h>
#include "my.h"
#include "my_list.h"
#include "tests.h"

Test(ld, ld_direct_to_reg)
{
    vm_t vm;
    process_t process;
    char instr[] = {2, 144, 0, 0, 0, 5, 1};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    ld_instruction(&process, NULL, &vm);
    cr_assert_eq(process.registers[0], 5);
    cr_assert_eq(process.pc, 7);
}

Test(ld, ld_indirect_to_reg)
{
    vm_t vm;
    process_t process;
    char instr[] = {2, 208, 0, 5, 1, 0, 0, 0, 15};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    ld_instruction(&process, NULL, &vm);
    cr_assert_eq(process.registers[0], 15);
    cr_assert_eq(process.pc, 5);
}

Test(ld, ldi_direct_to_reg)
{
    vm_t vm;
    process_t process;
    char instr[] = {0xa, 164, 0, 5, 0, 2, 1, 0, 0, 0, 15};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    ldi_instruction(&process, NULL, &vm);
    cr_assert_eq(process.registers[0], 15);
    cr_assert_eq(process.pc, 7);
}

Test(ld, ldi_reg_indirect_to_reg)
{
    vm_t vm;
    process_t process;
    char instr[] = {0xa, 212, 0, 5, 1, 2, 0, 0, 0, 15};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    process.registers[0] = 4;
    ldi_instruction(&process, NULL, &vm);
    cr_assert_eq(process.registers[1], 15);
    cr_assert_eq(process.pc, 6);
}

Test(ld, lld_direct_to_reg)
{
    vm_t vm;
    process_t process;
    char instr[] = {2, 144, 0, 0, 0, 5, 1};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    lld_instruction(&process, NULL, &vm);
    cr_assert_eq(process.registers[0], 5);
    cr_assert_eq(process.pc, 7);
}

Test(ld, lld_indirect_to_reg)
{
    vm_t vm;
    process_t process;
    char instr[] = {2, 208, 0, 5, 1, 0, 0, 0, 15};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    lld_instruction(&process, NULL, &vm);
    cr_assert_eq(process.registers[0], 15);
    cr_assert_eq(process.pc, 5);
}

Test(ld, lldi_direct_to_reg)
{
    vm_t vm;
    process_t process;
    char instr[] = {0xa, 164, 0, 4, 0, 3, 1, 0, 0, 0, 15};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    lldi_instruction(&process, NULL, &vm);
    cr_assert_eq(process.registers[0], 15);
    cr_assert_eq(process.pc, 7);
}

Test(ld, lldi_reg_indirect_to_reg)
{
    vm_t vm;
    process_t process;
    char instr[] = {0xa, 212, 0, 5, 1, 2, 0, 0, 0, 15};

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    process.registers[0] = 4;
    lldi_instruction(&process, NULL, &vm);
    cr_assert_eq(process.registers[1], 15);
    cr_assert_eq(process.pc, 6);
}
