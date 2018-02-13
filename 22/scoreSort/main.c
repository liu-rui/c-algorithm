//
// Created by liurui on 2/13/18.
//

#include <stdio.h>
#include <string.h>

typedef struct student {
    char name[100];
    int age;
    int score;
} student;

int compare(student a, student b);

void sort(student *students, int begin, int end);

void print(student *students, int begin, int end);

int main() {
    student students[1000];
    int n;

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%s%d%d", students[i].name, &students[i].age, &students[i].score);
        }
        sort(students, 0, n - 1);
        print(students, 0, n - 1);
    }
    return 0;
}

void sort(student *students, int begin, int end) {
    if (begin >= end) { return; }
    int i = begin;
    int j = end;
    student item = students[i];

    while (i < j) {
        while (i < j && compare(students[j], item) > 0) {
            j--;
        }

        if (i < j) {
            students[i++] = students[j];
        }

        while (i < j && compare(students[i], item) <= 0) {
            i++;
        }

        if (i < j) {
            students[j--] = students[i];
        }
    }
    students[i] = item;
    sort(students, begin, i - 1);
    sort(students, i + 1, end);
}

void print(student *students, int begin, int end) {
    for (int i = begin; i <= end; i++) {
        printf("%s %d %d\n", students[i].name, students[i].age, students[i].score);
    }
}

int compare(student a, student b) {
    if (a.score != b.score) {
        return a.score > b.score;
    }

    int nameCompare = strcmp(a.name, b.name);

    if (nameCompare != 0) {
        return nameCompare;
    }

    if (a.age != b.age) {
        return a.age > b.age;
    }
}