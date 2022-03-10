#include <stdio.h>
#include <math.h>

#include "readability.h"

int is_prime(int num) {
    if (num == 2) return 1;
    for (int i = 2; i < ceil(sqrt(num))+1; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    long sum = 0;
    for (int i = 2; i < NUM(2,000,000); i++) {
        if (is_prime(i)) sum += i;
    }

    printf("%zu\n", sum);
}