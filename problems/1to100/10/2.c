#include <stdio.h>
#include <math.h>

long divisors(long num) {
    long div_count = 0;
    double sqrt_num = sqrt((double)num);
    if (sqrt_num == floor(sqrt_num)) div_count--;
    for (long i = 1; i <= floor(sqrt_num); i++) {
        if (num % i == 0) div_count += 2;
    }

    return div_count;
}

int main() {
    long number = 0;
    for (long i = 1; divisors(number) < 500; number += i, i++);
    printf("%zu\n", number);
}