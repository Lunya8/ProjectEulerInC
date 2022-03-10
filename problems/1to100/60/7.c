#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <inttypes.h>

long bruteforce(long** triangle, int triangle_length) {
    for (int i = 1; i < triangle_length; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) triangle[i][j] += triangle[i-1][j];
            else if (j == i) triangle[i][j] += triangle[i-1][i-1];
            else {
                triangle[i][j] += (triangle[i-1][j-1] > triangle[i-1][j] ? triangle[i-1][j-1] : triangle[i-1][j]);
            }
        }
    }

    long greatest = 0;
    for (int i = 0; i < triangle_length; i++) {
        if (triangle[triangle_length-1][i] > greatest) greatest = triangle[triangle_length-1][i];
    }

    return greatest;
}

int main() {
    const int triangle_length = 100;
    char* substrings[triangle_length];
    FILE* input = fopen("triangle_for_67.txt", "r");
    for (int i = 0; i < triangle_length; i++) {
        substrings[i] = calloc(512, 1);
        fgets(substrings[i], 512, input);
    }


    long* triangle[triangle_length];
    for (int i = 0; i < triangle_length; i++) {
        triangle[i] = calloc(i+1, sizeof(long));
        for (int j = 0; j < i+1; j++) {
            triangle[i][j] = strtoimax(strsep(&substrings[i], " "), NULL, 10);
        }
    }


    printf("%zu\n", bruteforce(triangle, triangle_length));
}