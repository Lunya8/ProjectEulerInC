#include <stdio.h>

double possibilities_of(int width, int height) {
    double n1 = (height + width);
    double n2 = width;
    double prod = 1;
    for (double i = 1; i <= n2; i++) {
        prod *= (n1 + 1 - i) / i;
    }

    return prod;
}

int main() {
    printf("%f\n", possibilities_of(20, 20));

}