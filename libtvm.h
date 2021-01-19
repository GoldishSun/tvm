#include <stdlib.h>

int max_mem;
char* var_mem;
char* lbl_mem;

void mem_init() {
    max_mem = 1024 * 4;

    var_mem = (char*)malloc((1024 * 4) + 1);
    lbl_mem = (char*)malloc((1024 * 4) + 1);
}