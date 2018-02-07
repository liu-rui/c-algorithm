#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef float stackElement;

typedef struct stack {
    stackElement data;
    struct stack *next;
} stack;

stack *create() {
    return (stack *) malloc(sizeof(stack));
}

void push(stack *root, stackElement data) {
    stack *node = (stack *) malloc(sizeof(stack));

    node->data = data;
    node->next = root->next;
    root->next = node;
}

stackElement pop(stack *root) {
    if (isEmpty(root)) { return 0; }
    stack *node = root->next;
    stackElement ret = node->data;

    root->next = node->next;
    free(node);
    return ret;
}

stackElement peek(stack *root) {
    if (isEmpty(root)) { return 0; }
    return root->next->data;
}

int isEmpty(stack *root) {
    return root == NULL || root->next == NULL ? 1 : 0;
}

void destroy(stack *root) {
    if (root == NULL) { return; }
    stack *node;

    while (root->next != NULL) {
        node = root->next;
        root->next = node->next;
        free(node);
    }
    free(root);
}

char signs[5] = {'\0', '+', '-', '*', '/'};
int signPriorities[5][5] = {
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        1, 1, 1, 0, 0,
        1, 1, 1, 0, 0
};

int getSignIndex(char sign) {
    for (int i = 0; i < 5; ++i) {
        if (signs[i] == sign) {
            return i;
        }
    }
    return -1;
}

stackElement calc(stackElement a, stackElement b, int sign) {
    switch (sign) {
        case 1:
            return a + b;
        case 2:
            return a - b;
        case 3:
            return a * b;
        case 4:
            return 1.000 * a / b;
    }
}

int main() {
    char str[210];

    for (;;) {
        fgets(str, 210, stdin);

        if (str[0] == '0') { break; }
        stack *signStack = create();
        stack *numberStack = create();
        int data = 0;

        for (int i = 0;; i++) {
            if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '\0') {
                int curSignIndex = getSignIndex(str[i]);

                push(numberStack, data);
                data = 0;

                while (!isEmpty(signStack)) {
                    if (signPriorities[curSignIndex][(int) peek(signStack)] == 1) {
                        break;
                    }

                    stackElement second = pop(numberStack);
                    stackElement first = pop(numberStack);
                    int signIndex = (int) pop(signStack);
                    stackElement ret = calc(first, second, signIndex);

                    push(numberStack, ret);
                }

                if (str[i] == '\0') {
                    break;
                } else {
                    push(signStack, curSignIndex);
                }
            } else if (str[i] >= '0' && str[i] <= '9') {
                data = data * 10 + (str[i] - '0');
            }
        }
        printf("%.2f\n", pop(numberStack));
    }
    return 0;
}