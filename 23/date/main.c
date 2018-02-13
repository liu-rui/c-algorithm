//
// Created by liurui on 2/13/18.
//

#include <stdio.h>

int daysOfMonths[13][2] = {
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
        31, 31,
};

int days[5001][12][31];

int leapYear(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

void init() {
    int year = 1;
    int month = 1;
    int day = 1;
    int totalDay = 1;

    while (year < 5001) {
        days[year][month][day] = totalDay;

        totalDay++;
        day++;

        if (day > daysOfMonths[month][leapYear(year)]) {
            day = 1;
            month++;

            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
}

int main() {
    init();
    int year, month, day;

    while (scanf("%4d%2d%2d", &year, &month, &day) != EOF) {
        int nextYear, nextMonth, nextDay;
        scanf("%4d%2d%2d", &nextYear, &nextMonth, &nextDay);

        printf("%d", days[nextYear][nextMonth][nextDay] - days[year][month][day] + 1);
    }
    return 0;
}