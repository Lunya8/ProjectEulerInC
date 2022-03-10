#include <stdio.h>

int month_lengths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int sundays = 0;
    int date = 1;

    for (int year = 1901; year < 2001; year++) {
        int leap_year = 0;
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0) {
                    leap_year = 1;
                }
            } else {
                leap_year = 1;
            }
        }

        for (int month = 0; month < 12; month++) {
            int length = month_lengths[month];
            if (month == 1 && leap_year) length++;
            for (int day = 0; day < length; day++) {
                if (day == 0 && date == 6) sundays++;
                date++;
                if (date == 7) date = 0;
            }
        }
    }

    printf("%d\n", sundays);
}