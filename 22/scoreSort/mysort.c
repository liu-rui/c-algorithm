//
// Created by liurui on 18-2-6.
//


#include <string.h>
#include "mysort.h"

int compare(student a, student b) {
    if (a.score != b.score) return a.score > b.score;
    int i = strcmp(a.name, b.name);

    if (i != 0) return i;
    return a.age > b.age;
}

void quickSort(student *ary, int begin, int end) {
    if (begin >= end)return;
    int i = begin;
    int j = end;
    student item = ary[i];

    while (i < j) {
        while (i < j && compare(ary[j], item) > 0) {
            j--;
        }

        if (i < j) {
            ary[i++] = ary[j];
        }

        while (i < j && compare(ary[i], item) <= 0) {
            i++;
        }

        if (i < j) {
            ary[j--] = ary[i];
        }
    }
    ary[i] = item;
    quickSort(ary, begin, i - 1);
    quickSort(ary, i + 1, end);
}