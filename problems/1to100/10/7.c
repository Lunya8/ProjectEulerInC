#include <stdio.h>
#include <string.h>

static char* nums[10] = {"zero", "one", "two", "three", "four",
                         "five", "six", "seven", "eight", "nine"};

static char* teens_nums[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen",
                          "fifteen","sixteen", "seventeen", "eighteen", "nineteen"};

static char* tens_nums[8] = {"twenty", "thirty", "forty", "fifty", "sixty",
                        "seventy", "eighty", "ninety"};

size_t num_to_word_len(int num) {
    char buf[8];
    int length = sprintf(buf, "%d", num);
    int ones = buf[length-1] - '0', tens = 0, hundreds = 0, thousands = 0;

    if (length > 1) {
        tens = buf[length-2] - '0';
    }
    if (length > 2) {
        hundreds = buf[length-3] - '0';
    }
    if (length > 3) {
        thousands = buf[length-4] - '0';
    }

    char word_buf[64] = "";
    if (thousands) {
        strcat(word_buf, "onethousand");
    }
    if (hundreds) {
        strcat(word_buf, nums[hundreds]);
        strcat(word_buf, "hundred");
    }
    if (hundreds && (tens || ones)) {
        strcat(word_buf, "and");
    }
    if (tens) {
        if (tens == 1) {
            strcat(word_buf, teens_nums[ones]);
            goto end;
        }
        strcat(word_buf, tens_nums[tens-2]);
    }
    if (ones) {
        strcat(word_buf, nums[ones]);
    }

    end:
    return strlen(word_buf);
}

int main() {
    size_t sum = 0;
    for (int i = 1; i < 1001; i++) {
        sum += num_to_word_len(i);
    }

    printf("%zu\n", sum);
}