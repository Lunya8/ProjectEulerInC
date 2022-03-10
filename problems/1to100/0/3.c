#include <stdio.h>
#include <math.h>
#include <readability.h>

int is_prime(long num) {
    if (num == 2) return 1;
    for (int i = 2; i <= ceil(sqrt((double)num)); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    long input_number = NUM(600,851,475,143);

    for (int i = 2; i <= (long)ceil(sqrt((double)input_number)); i++) {
        if (is_prime(input_number)) break;
        if (input_number % i != 0) continue;
        if (is_prime(i)) input_number /= i;
        i = 2;
    }
    printf("Solution: %zu\n", input_number);
}