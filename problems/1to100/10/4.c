#include <stdio.h>

int collatz_length(long num) {
    int length = 1;
    while (num != 1) {
        length++;
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3*num + 1;
        }
    }
    return length;
}

int main() {
    int longest_chain = 0;
    int longest_source = 0;
    for (int i = 1; i < 1e6; i++) {
        int collatz_len = collatz_length(i);
        if (collatz_len > longest_chain) {
            longest_chain = collatz_len;
            longest_source = i;
        }
    }

    printf("Source: %d\nChain Length(for curiosity): %d\n", longest_source, longest_chain);
}

