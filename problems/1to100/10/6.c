#include <stdio.h>

int main() {
    char digits[1024];
    // initialize digits to all 0
    for (int i = 0; i < 1024; i++) digits[i] = 0;
    digits[0] = 1; // initial value

    // double 1000 times
    for (int i = 0; i < 1000; i++) {

        // for every digit
        for (int j = 1023; j >= 0; j--) {
            if (digits[j] == 0) continue;

            digits[j] *= 2;
            if (digits[j] > 9) {
                digits[j+1]++;
                digits[j] %= 10;
            }
        }
    }

    long sum = 0;
    for (int i = 0; i < 1024; i++) {
        sum += digits[i];
    }

    printf("%zu\n", sum);
}