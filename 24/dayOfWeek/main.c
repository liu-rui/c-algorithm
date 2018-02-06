#include <stdio.h>
#include <string.h>

char monthNames[13][20] = {
        "",
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
};

char weekNames[7][20] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
};


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

int getMonth(char *monthName) {
    for (int i = 0; i < 13; i++) {
        if (strcmp(monthNames[i], monthName) == 0) {
            return i;
        }
    }
    return -1;
}

int __isLeapYear(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}


int days[5001][12][31];


void init() {
    int year = 0;
    int month = 1;
    int day = 1;
    int total = 1;

    while (year != 5001) {
        days[year][month][day] = total;

        total++;
        day++;

        if (day > daysOfMonth[month][__isLeapYear(year)]) {
            day = 1;
            month++;

            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
}

char *getWeek(int day) {
    int dayOfWeek = (7 - day % 7) % 7;
    return weekNames[dayOfWeek];

}

int main() {
    init();
//    printf("%d\n", getWeek(days[2018][2][4] - days[2001][10][9]));
//    printf("%d\n", getWeek(days[2018][2][4] - days[2001][10][14]));
//    printf("%d\n", getWeek(days[2018][2][4] - days[1997][3][7]));
//    printf("%d\n", getWeek(days[2018][2][4] - days[2043][5][6]));

    int year;
    char monthName[20];
    int day;

    while (scanf("%d%s%d", &day, monthName, &year) != EOF) {
        printf("%s\n", getWeek(days[2018][2][4] - days[year][getMonth(monthName)][day]));
    }
    return 0;
}