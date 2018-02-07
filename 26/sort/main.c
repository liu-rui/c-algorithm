#include <stdio.h>

#define T 500000

int main() {
    int n, m;

    while (scanf("%d%d", &n, &m) != EOF) {
        int ary[1000001] = {0};
        int data;

        for (int i = 0; i < n; ++i) {
            scanf("%d", &data);
            ary[data + T] = 1;
        }

        for (int j = 1000000; j >= 0 && m > 0; j--) {
            if (ary[j] == 0) {
                continue;
            } else {
                printf("%d ", j - T);
                m--;
            }
        }
        printf("\n");
    }
    return 0;
}