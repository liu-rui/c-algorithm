#include <stdio.h>
#include <stdlib.h>

int days[5001][12][31];

int leapYear(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int daysOfMonth[13][2] = {
        0, 0,
        31, 31,
        28, 29,
        31, 31,
        30, 30,
        31, 31,
        30, 30,
        31, 31,
        31, 31,
        30, 30,
        31, 31,
        30, 30,
        31, 31};


void init() {
    int year = 0, month = 1, day = 1, total = 1;

    while (year < 5001) {
        days[year][month][day] = total;
        total++;
        day++;

        if (day > daysOfMonth[month][leapYear(year)]) {
            month++;
            day = 1;

            if (month > 12) {
                year++;
                month = 1;
            }
        }
    }
}

int main() {
    init();
    int year = 0, month = 0, day = 0;

    while (scanf("%4d%2d%2d", &year, &month, &day) != EOF) {
        int nextYear = 0, nextMonth = 0, nextDay = 0;

        scanf("%4d%2d%2d", &nextYear, &nextMonth, &nextDay);
        printf("%d", abs(days[year][month][day] - days[nextYear][nextMonth][nextDay]) + 1);
    }
    return 0;
}