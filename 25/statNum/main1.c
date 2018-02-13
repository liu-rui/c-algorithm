#include <stdio.h>

int main() {
    int n;

    while (scanf("%d", &n) != EOF && n != 0) {
        int scores[101] = {0};
        int score;

        for (int j = 0; j < n; j++) {
            scanf("%d", &score);
            scores[score]++;
        }

        scanf("%d", &score);
        printf("%d\n", scores[score]);
    }
    return 0;
}