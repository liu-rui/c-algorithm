#include <stdio.h>
#include <string.h>

typedef struct {
    char id[10];
    char name[10];
    char sex[2];
    int score;
} student;

int compare(student a, student b) {
    return strcmp(a.id, b.id);
}

void sort(student *ary, int begin, int end) {
    if (begin >= end) { return; }
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
    sort(ary, begin, i - 1);
    sort(ary, i + 1, end);
}


student *binarySearch(student *ary, char *id, int begin, int end) {
    while (begin <= end) {
        int mid = begin + (end - begin) / 2;
        int compare = strcmp(ary[mid].id, id);

        if (compare == 0) {
            return &ary[mid];
        } else if (compare > 0) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    return NULL;
}


int main() {
    student ary[1000];
    int n, m;

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%s%s%s%d", ary[i].id, ary[i].name, ary[i].sex, &ary[i].score);
        }

        sort(ary, 0, n - 1);
        scanf("%d", &m);

        char inputId[2];
        student *found = NULL;

        for (int j = 0; j < m; ++j) {
            scanf("%s", inputId);
            found = binarySearch(ary, inputId, 0, n - 1);

            if (found == NULL) {
                printf("No Answer!");
            } else {
                printf("%s %s %s %d", found->id, found->name, found->sex, found->score);
            }
            printf("\n");
        }
    }
    return 0;
}