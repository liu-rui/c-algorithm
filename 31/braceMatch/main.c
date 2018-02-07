#include <stdio.h>
#include <stdlib.h>

typedef char stackElement;


typedef struct stack {
    stackElement data;
    struct stack *next;
} stack;


stack *createStack() {
    return (stack *) malloc(sizeof(stack));
}

void push(stack *root, stackElement data) {
    stack *node = (stack *) malloc(sizeof(stack));

    node->data = data;
    node->next = root->next;

    root->next = node;
}

stackElement pop(stack *root) {
    stack *node = root->next;

    if (node != NULL) {
        stackElement ret = node->data;

        root->next = node->next;
        free(node);
        return ret;

    } else {
        return 0;
    }
}

stackElement peek(stack *root) {
    stack *node = root->next;

    if (node != NULL) {
        return node->data;
    } else {
        return 0;
    }
}

int isEmpty(stack *root) {
    return root == NULL || root->next == NULL ? 1 : 0;
}

void detroyStack(stack *root) {
    stack *node;

    while (root->next != NULL) {
        node = root->next;
        root->next = node->next;
        free(node);
    }
    free(root);
}

int main() {
    char str[100];
    char ret[100];

    while (scanf("%s", str) != EOF) {
        stack *root = createStack();

        for (int i = 0; str[i] != '\0'; ++i) {
            switch (str[i]) {
                case '(':
                    push(root, i);
                    break;
                case ')':
                    if (isEmpty(root)) {
                        ret[i] = '?';
                    } else {
                        int prev = pop(root);
                        ret[prev] = ' ';
                        ret[i] = ' ';
                    }
                    break;
                default:
                    ret[i] = ' ';
            }
        }

        while (!isEmpty(root)) {
            int prev = pop(root);
            ret[prev] = '$';
        }
        detroyStack(root);

        printf("%s", ret);
    }
    return 0;
}