#include <stdio.h>

struct thing {
    int height;
    int price;
    float rate;
} items[1000];

int compare(struct thing a, struct thing b) {
    if (a.rate == b.rate) {
        return 0;
    } else {
        return a.rate > b.rate;
    }
}

void sort(int begin, int end) {
    if (begin >= end) {
        return;
    }

    int i = begin;
    int j = end;
    struct thing item = items[begin];

    while (i < j) {
        while (i < j && compare(items[j], item) <=0) {
            j--;
        }

        if (i < j) {
            items[i++] = items[j];
        }

        while (i < j && compare(items[i], item) > 0) {
            i++;
        }

        if (i < j) {
            items[j--] = items[i];
        }
    }
    items[i] = item;
    sort(begin, i - 1);
    sort(i + 1, end);
}


int main() {
    int m, n;

    while (scanf("%d%d", &m, &n) != EOF && m != -1 && n != -1) {

        for (int i = 0; i < n; i++) {
            scanf("%d%d", &items[i].height, &items[i].price);
            items[i].rate = 1.000 *  items[i].height / items[i].price;
        }

        sort(0, n - 1);
        float ret = 0;

        for (int i = 0; i < n && m > 0; i++) {
            if (m >= items[i].price) {
                ret += items[i].height;
                m -= items[i].price;
            } else {
                ret += items[i].rate * m;
                m = 0;
            }
        }
        printf("%.3f\n", ret);
    }
    return 0;
}