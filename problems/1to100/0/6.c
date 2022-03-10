#include <stdio.h>

inline long square(long num) {
    return num * num;
}

int main() {
    long sum_of_squares = 0;
    for (int i = 1; i <= 100; i++) {
        sum_of_squares += square(i);
    }

    long square_of_sum = 0;
    for (int i = 1; i <= 100; i++) {
        square_of_sum += i;
    }
    square_of_sum = square(square_of_sum);

    printf("%zu\n", square_of_sum - sum_of_squares);
}