#include <stdio.h>

long lcm(long n1, long n2) {
    long interval = (n1 > n2 ? n1 : n2);
    long not_interval = (n1 > n2 ? n2 : n1);
    long i;
    for (i = interval; i % not_interval != 0; i += interval);

    return i;
}

int main() {
    long current_lcm = 1;
    for (int i = 1; i < 20; i++) {
        current_lcm = lcm(current_lcm, i+1);
    }
    printf("%zu\n", current_lcm);
}