#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <inttypes.h>

const char* triangle_str = "75\n"
                           "95 64\n"
                           "17 47 82\n"
                           "18 35 87 10\n"
                           "20 04 82 47 65\n"
                           "19 01 23 75 03 34\n"
                           "88 02 77 73 07 63 67\n"
                           "99 65 04 28 06 16 70 92\n"
                           "41 41 26 56 83 40 80 70 33\n"
                           "41 48 72 33 47 32 37 16 94 29\n"
                           "53 71 44 65 25 43 91 52 97 51 14\n"
                           "70 11 33 28 77 73 17 78 39 68 17 57\n"
                           "91 71 52 38 17 14 91 43 58 50 27 29 48\n"
                           "63 66 04 68 89 53 67 30 73 16 69 87 40 31\n"
                           "04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";

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
    char* substrings[15];
    char* dup = strdup(triangle_str);
    for (int i = 0; i < 15; i++) {
        substrings[i] = strsep(&dup, "\n");
    }

    long* triangle[15];
    for (int i = 0; i < 15; i++) {
        triangle[i] = calloc(i+1, sizeof(long));
        for (int j = 0; j < i+1; j++) {
            triangle[i][j] = strtoimax(strsep(&substrings[i], " "), NULL, 10);
        }
    }

    printf("%zu\n", bruteforce(triangle, 15));
}