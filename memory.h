// memory.h
//
// Memory for
// virtual machine.

#pragma once
#ifndef TVM_MEMORY_H
#define TVM_MEMORY_H

#include "raise.h"

#include <string.h>
#include <stdlib.h>

typedef struct VirtualMachineMemory {
    static constexpr int maximum_label_memory = 1024 * 4;
    static constexpr int maximum_variable_memory = 1024 * 4;

    char* label_memory;
    char* variable_memory;

    char* label_separator = ";";
    char* variable_separator = ";";
    char* label_name_value_separator = ":";
    char* variable_name_value_separator = ":";

    void push_label(char* name, char* value) {
        int after_memory = strlen(this->label_memory) + strlen(this->label_separator) + strlen(name) + strlen(this->label_name_value_separator) + strlen(value);

        if (after_memory < this->maximum_label_memory) {
            char *memory_copy = (char*)malloc(strlen(this->label_memory) + strlen(this->label_separator) + 1);

            strcpy(memory_copy, this->label_memory);
            strcat(memory_copy, this->label_separator);

            char *memory_copy2 = (char*)malloc(strlen(memory_copy) + strlen(name) + 1);

            strcpy(memory_copy2, memory_copy);
            strcat(memory_copy2, name);

            char *memory_copy3 = (char*)malloc(strlen(memory_copy2) + strlen(this->label_name_value_separator) + 1);

            strcpy(memory_copy3, memory_copy2);
            strcat(memory_copy3, this->label_name_value_separator);

            char *memory_copy4 = (char*)malloc(strlen(memory_copy3) + strlen(value) + 1);

            strcpy(memory_copy4, memory_copy3);
            strcat(memory_copy4, value);

            this->label_memory = memory_copy4;

            free(memory_copy);
            free(memory_copy2);
            free(memory_copy3);
            free(memory_copy4);
        } else {
            raise("NotEnoughMemory", "Not enough memory for virtual machine.\n Free the garbage before defining label.", 1);
        }
    }
} Memory;

#endif
