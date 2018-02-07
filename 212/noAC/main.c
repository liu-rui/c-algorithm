#include <stdio.h>

struct item {
    int begin;
    int end;
} items[100];

int compare(struct item a, struct item b) {
    return a.end == b.end ? 0 : a.end > b.end;
}


void sort(int begin, int end) {
    if (begin >= end) { return; }
    int i = begin;
    int j = end;
    struct item cur = items[i];

    while (i < j) {
        while (i < j && compare(items[j], cur) > 0) {
            j--;
        }

        if (i < j) {
            items[i++] = items[j];
        }

        while (i < j && compare(items[i], cur) <= 0) {
            i++;
        }

        if (i < j) {
            items[j--] = items[i];
        }
    }
    items[i] = cur;
    sort(begin, i - 1);
    sort(i + 1, end);
}

int main() {
    int n;

    while (scanf("%d", &n) != EOF && n != 0) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &items[i].begin, &items[i].end);
        }

        sort(0, n - 1);
        int count = 0;
        int begin = 0;

        for (int i = 0; i < n; ++i) {
            if (begin <= items[i].begin) {
                count++;
                begin = items[i].end;
            }
        }
        printf("%d", count);
    }
    return 0;
}