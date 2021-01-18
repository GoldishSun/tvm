// memory.h
//
// Memory for
// virtual machine.

#pragma once
#ifndef TVM_MEMORY_H
#define TVM_MEMORY_H

typedef struct VirtualMachineMemory {
    static constexpr int maximum_label_memory = 1024 * 4;
    static constexpr int maximum_garbage_memory = 1024 * 4;
    static constexpr int maximum_variable_memory = 1024 * 4;
    static constexpr int maximum_constant_memory = 1024 * 4;

    char label_memory[maximum_label_memory];
    char garbage_memory[maximum_garbage_memory];
    char variable_memory[maximum_variable_memory];
    char constant_memory[maximum_constant_memory];
} Memory;

#endif
