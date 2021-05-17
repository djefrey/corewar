/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** arguments
*/

#include <stdlib.h>
#include "my.h"
#include "my_list.h"
#include "tests.h"

Test(arguments, read_registers)
{
    vm_t vm;
    process_t process;
    char instr[] = {1, 84, 1, 2, 3};
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr;

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    process.registers[0] = 10;
    process.registers[1] = 20;
    process.registers[2] = 30;
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    get_arguments_type(args, &process, &vm);
    addr = get_arguments_value(args, values, 0, (couple_t) {&process, &vm});
    cr_assert_eq(args[0], REGISTER);
    cr_assert_eq(args[1], REGISTER);
    cr_assert_eq(args[2], REGISTER);
    cr_assert_eq(values[0], 0);
    cr_assert_eq(values[1], 1);
    cr_assert_eq(values[2], 2);
    cr_assert_eq(get_arg_real_value(args[0], values[0], &process, &vm), 10);
    cr_assert_eq(get_arg_real_value(args[1], values[1], &process, &vm), 20);
    cr_assert_eq(get_arg_real_value(args[2], values[2], &process, &vm), 30);
    cr_assert_eq(addr, 5);
}

Test(arguments, read_directs)
{
    vm_t vm;
    process_t process;
    char instr[] = {1, 168, 0, 0, 0, 5, 0, 0, 0, 10, 0, 0, 0, 15};
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr;

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    get_arguments_type(args, &process, &vm);
    addr = get_arguments_value(args, values, 0, (couple_t) {&process, &vm});
    cr_assert_eq(args[0], DIRECT);
    cr_assert_eq(args[1], DIRECT);
    cr_assert_eq(args[2], DIRECT);
    cr_assert_eq(values[0], 5);
    cr_assert_eq(values[1], 10);
    cr_assert_eq(values[2], 15);
    cr_assert_eq(get_arg_real_value(args[0], values[0], &process, &vm), 5);
    cr_assert_eq(get_arg_real_value(args[1], values[1], &process, &vm), 10);
    cr_assert_eq(get_arg_real_value(args[2], values[2], &process, &vm), 15);
    cr_assert_eq(addr, 14);
}

Test(arguments, read_indirects)
{
    vm_t vm;
    process_t process;
    char instr[] = {1, 252, 0, 0, 0, 1, 0, 8, 15};
    argument_t args[4] = {NONE};
    int values[4] = {0};
    int addr;

    if (create_criterion_vm(&vm))
        return;
    create_criterion_process(&process);
    for (unsigned int i = 0; i < sizeof(instr); i++)
        vm.memory[i] = instr[i];
    get_arguments_type(args, &process, &vm);
    addr = get_arguments_value(args, values, 0, (couple_t) {&process, &vm});
    cr_assert_eq(args[0], INDIRECT);
    cr_assert_eq(args[1], INDIRECT);
    cr_assert_eq(args[2], INDIRECT);
    cr_assert_eq(values[0], 0);
    cr_assert_eq(values[1], 1);
    cr_assert_eq(values[2], 8);
    cr_assert_eq(get_arg_real_value(args[0], values[0], &process, &vm), 1);
    cr_assert_eq(get_arg_real_value(args[1], values[1], &process, &vm), -4);
    cr_assert_eq(get_arg_real_value(args[2], values[2], &process, &vm), 15);
    cr_assert_eq(addr, 8);
}
