#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char treeE;


typedef struct tree {
    treeE data;
    struct tree *left;
    struct tree *right;
} tree;


void preOrder(tree *node) {
    if (node == NULL) { return; }
    printf("%c", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(tree *node) {
    if (node == NULL) { return; }
    inOrder(node->left);
    printf("%c", node->data);
    inOrder(node->right);
}

void postOrder(tree *node) {
    if (node == NULL) { return; }
    postOrder(node->left);
    postOrder(node->right);
    printf("%c", node->data);
}

tree *create(treeE data, tree *left, tree *right) {
    tree *node = (tree *) malloc(sizeof(tree));

    node->data = data;
    node->left = left;
    node->right = right;
    return node;
}

void destroy(tree *node) {
    if (node == NULL) { return; }
    destroy(node->left);
    destroy(node->right);
    free(node);
}

tree *build(char *preOrderString, int pStart, int pEnd, char *inOrderString, int iStart, int iEnd) {
    tree *node = create(preOrderString[pStart], NULL, NULL);
    int pos = -1;

    for (int i = iStart; i <= iEnd; i++) {
        if (preOrderString[pStart] == inOrderString[i]) {
            pos = i;
            break;
        }
    }

    if (pos != iStart) {
        node->left = build(preOrderString, pStart + 1, pStart + (pos - iStart), inOrderString, iStart, pos - 1);
    }

    if (pos != iEnd) {
        node->right = build(preOrderString, pStart + 1 + (pos - iStart), pEnd, inOrderString, pos + 1, iEnd);
    }
    return node;
}

int main() {
    char first[30];
    char second[30];

    while (scanf("%s", first) != EOF) {
        scanf("%s", second);
        int end = strlen(first) - 1;
        tree *root = build(first, 0, end, second, 0, end);

        postOrder(root);
        destroy(root);
    }
    return 0;
}