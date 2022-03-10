#include <stdio.h>
#include <math.h>

int is_prime(long num) {
    if (num == 2) return 1;
    for (long i = 2; i < (long)ceil(sqrt((double)num))+1; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int prime_count = 0;
    long i;
    for (i = 2; prime_count != 10001; i++) {
        if (is_prime(i)) {
            prime_count++;
            printf("%zu\n", i);
        }
    }

    printf("%zu\n", i-1);
}