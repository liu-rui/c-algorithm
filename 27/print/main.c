#include <stdio.h>

int main() {
    int h;
    scanf("%d", &h);

    int count = h + (h - 1) * 2;

    for (int i = 0; i < h; i++) {

        int a = count - h - i * 2;

        for (int j = 0; j < count; ++j) {
            if (j >= a) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}