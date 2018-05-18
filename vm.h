#ifndef __VM_H__
#define __VM_H__

#include "object.h"
#include "bytecode.h"

typedef struct vm
{
    stack_ptr sp;
    stack_ptr fp;
    mem_ptr gp;
    ip_ptr ip;

    int stack_size;
    struct gc_stack * stack;
    struct gc * collector;

    unsigned int line_no;
    char running;
} vm;

typedef struct vm_execute_str
{
    bytecode_type type;
    void (* execute)(vm * machine, bytecode * code);
} vm_execute_str;

void vm_execute_unknown(vm * machine, bytecode * code);
void vm_execute_int(vm * machine, bytecode * code);
void vm_execute_id_local(vm * machine, bytecode * code);
void vm_execute_id_global(vm * machine, bytecode * code);
void vm_execute_id_func_func(vm * machine, bytecode * code);
void vm_execute_id_func_addr(vm * machine, bytecode * code);
void vm_execute_jumpz(vm * machine, bytecode * code);
void vm_execute_jump(vm * machine, bytecode * code);
void vm_execute_label(vm * machine, bytecode * code);
void vm_execute_op_neg(vm * machine, bytecode * code);
void vm_execute_op_add(vm * machine, bytecode * code);
void vm_execute_op_sub(vm * machine, bytecode * code);
void vm_execute_op_mul(vm * machine, bytecode * code);
void vm_execute_op_div(vm * machine, bytecode * code);
void vm_execute_op_lt(vm * machine, bytecode * code);
void vm_execute_op_gt(vm * machine, bytecode * code);
void vm_execute_op_lte(vm * machine, bytecode * code);
void vm_execute_op_gte(vm * machine, bytecode * code);
void vm_execute_op_eq(vm * machine, bytecode * code);
void vm_execute_func_def(vm * machine, bytecode * code);
void vm_execute_global_vec(vm * machine, bytecode * code);
void vm_execute_mark(vm * machine, bytecode * code);
void vm_execute_call(vm * machine, bytecode * code);
void vm_execute_ret(vm * machine, bytecode * code);
void vm_execute_line(vm * machine, bytecode * code);
void vm_execute_halt(vm * machine, bytecode * code);

void vm_check_stack(vm * machine);
int vm_execute(vm * machine, bytecode * code, unsigned int size);

vm * vm_new(unsigned int mem_size, unsigned int stack_size);
void vm_delete(vm * machine);

void vm_print(vm * machine);

#endif /* __VM_H__ */

