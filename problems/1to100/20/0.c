#include <stdio.h>

int main() {
    int number[512];
    for (int i = 0; i < 512; i++) number[i] = 0;
    number[0] = 1;
    for (int i = 1; i < 101; i++) {
        for (int j = 511; j >= 0; j--) {
            if (number[j] == 0) continue;
            number[j] *= i;
            int k = j;
            while (number[k] > 9) {
                int carry = (number[k] / 10);
                int hundred_carry = (carry / 10);
                carry %= 10;
                int thousand_carry = hundred_carry / 10;
                hundred_carry %= 10;
                int new_num = number[k] % 10;
                number[k] = new_num;
                number[k+1] += carry;
                number[k+2] += hundred_carry;
                number[k+3] += thousand_carry;

                k++;
            }
        }
    }

    long sum = 0;
    for (int i = 0; i < 512; i++) {
        sum += number[i];
    }

    printf("%zu\n", sum);
}