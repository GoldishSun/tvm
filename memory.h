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

int maximum_label_memory;
int maximum_variable_memory;

char* label_memory;
char* variable_memory;

char* label_separator;
char* variable_separator;
char* label_name_value_separator;
char* variable_name_value_separator;

void mem_init() {
    maximum_label_memory = 1024 * 4;
    maximum_variable_memory = 1024 * 4;
    label_separator = ";";
    variable_separator = ";";
    label_name_value_separator = ":";
    variable_name_value_separator = ":";
}

void push_label(char* name, char* value) {
    int after_memory = strlen(label_memory) + strlen(label_separator) + strlen(name) + strlen(label_name_value_separator) + strlen(value);

    if (after_memory < maximum_label_memory) {
        char *memory_copy = (char*)malloc(strlen(label_memory) + strlen(label_separator) + 1);

        strcpy(memory_copy, label_memory);
        strcat(memory_copy, label_separator);

        char *memory_copy2 = (char*)malloc(strlen(memory_copy) + strlen(name) + 1);

        strcpy(memory_copy2, memory_copy);
        strcat(memory_copy2, name);

        char *memory_copy3 = (char*)malloc(strlen(memory_copy2) + strlen(label_name_value_separator) + 1);

        strcpy(memory_copy3, memory_copy2);
        strcat(memory_copy3, label_name_value_separator);

        char *memory_copy4 = (char*)malloc(strlen(memory_copy3) + strlen(value) + 1);

        strcpy(memory_copy4, memory_copy3);
        strcat(memory_copy4, value);

        label_memory = memory_copy4;

        free(memory_copy);
        free(memory_copy2);
        free(memory_copy3);
        free(memory_copy4);
    } else {
        raise_error("NotEnoughMemory", "Not enough memory for virtual machine.\n Free the garbage before defining label.", 1);
    }
}

#endif
