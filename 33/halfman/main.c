#include <stdio.h>
#include <stdlib.h>

int *create(int n) {
    return (int *) malloc(sizeof(int) * (n + 1));
}

void push(int *heap, int data) {
    heap[0]++;
    int i = heap[0];

    while (i / 2 >= 1 && heap[i / 2] > data) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = data;
}

int pop(int *heap) {
    if (heap[0] == 0) return 0;
    int ret = heap[1];
    int item = heap[heap[0]];
    int parent = 1;
    int child = 2;

    heap[0]--;

    if (heap[0] == 0) {
        return ret;
    }

    while (child <= heap[0]) {
        if (child + 1 <= heap[0] && heap[child] > heap[child + 1]) {
            child++;
        }

        if (heap[child] > item) {
            break;
        } else {
            heap[parent] = heap[child];
            parent = child;
            child *= 2;
        }
    }
    heap[parent] = item;
    return ret;
}

int isEmpty(int *heap) {
    return heap == NULL || heap[0] == 0 ? 1 : 0;
}

void destroy(int *heap) {
    free(heap);
}


int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        int *heap = create(n);

        int data;

        heap[0] = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", &data);
            push(heap, data);
        }

        int ret = 0;
        int first;
        int second;

        while (heap[0] > 1) {
            first = pop(heap);
            second = pop(heap);
            ret += first + second;
            push(heap, first + second);
        }
        destroy(heap);
        printf("%d\n", ret);
    }
    return 0;
}