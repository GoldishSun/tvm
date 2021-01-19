// raise.h
//
// Functions for
// raising errors.

#pragma once
#ifndef TVM_RAISE_H
#define TVM_RAISE_H

#include <stdio.h>
#include <stdlib.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void terminate_vm(int _exit_code) {
    printf("\n [ Process terminated with code " RED "%s" RESET " ] \n", _exit_code);

    exit(_exit_code);
}

void raise_error(char* _err_name, char* _err_desc, int _exit_code) {
    printf(RED "%s" RESET " with code " YEL "%i" RESET ".\n", _err_name, _exit_code);
    printf(WHT " %s\n" RESET, _err_desc);

    terminate_vm(_exit_code);
}

#endif
