//
// Created by liurui on 18-2-6.
//

#ifndef TEST1_MYSORT_H
#define TEST1_MYSORT_H
typedef struct {
    char name[100];
    int age;
    int score;
} student;

int compare(student a, student b);

void quickSort(student *ary ,int begin, int end);

#endif //TEST1_MYSORT_H
