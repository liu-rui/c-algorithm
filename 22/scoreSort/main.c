#include <stdio.h>
#include "mysort.h"

student stu[1000];

int main() {
    int n = 0;

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%s%d%d", stu[i].name, &stu[i].age, &stu[i].score);
        }

        quickSort(stu, 0, n - 1);

        for (int i = 0; i < n; i++) {
            printf("%s %d %d\n", stu[i].name, stu[i].age, stu[i].score);
        }
    }
    return 0;
}