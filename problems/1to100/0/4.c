#include <stdio.h>

int num_is_palindrome(int num) {
    char buf[16];
    int len = sprintf(buf, "%d", num);
    for (int i = 0; i < len/2; i++) {
        if (buf[i] != buf[len-i-1]) return 0;
    }
    return 1;
}

int main() {
    int solution = 0;

    for (int n1 = 999; n1 > 99; n1--) {
        for (int n2 = 999; n2 > 99; n2--) {
            if (num_is_palindrome(n1 * n2) && n1 * n2 > solution) solution = n1 * n2;
        }
    }

    printf("Solution: %d\n", solution);
}