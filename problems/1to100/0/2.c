#include <stdio.h>
#include "readability.h"

int main() {
    int mem[256] = {0, 1};
    int mem_len = 1;
    int sum = 0;

    while (mem[mem_len++] < NUM(4,000,000)) {
        mem[mem_len] = mem[mem_len-1] + mem[mem_len-2];
        if (mem[mem_len] % 2 == 0) {
            sum += mem[mem_len];
        }
    }

    printf("Solution: %d\n", sum);
}