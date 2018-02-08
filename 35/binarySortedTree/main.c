#include <stdio.h>
#include <stdlib.h>

typedef int treeElement;

typedef struct binarySortedTree {
    treeElement data;
    struct binarySortedTree *left;
    struct binarySortedTree *right;
} binarySortedTree;


binarySortedTree *create(treeElement data) {
    binarySortedTree *node = (binarySortedTree *) malloc(sizeof(binarySortedTree));

    node->data = data;
    return node;
}

binarySortedTree *push(binarySortedTree *root, treeElement data) {
    if (root == NULL) {
        return create(data);
    }

    if (root->data > data) {
        root->left = push(root->left, data);
    } else if (root->data < data) {
        root->right = push(root->right, data);
    }
    return root;
}

void preOrder(binarySortedTree *root) {
    if (root == NULL) { return; }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(binarySortedTree *root) {
    if (root == NULL) { return; }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(binarySortedTree *root) {
    if (root == NULL) { return; }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

void destroy(binarySortedTree *root) {
    if (root == NULL) { return; }
    destroy(root->left);
    destroy(root->right);
    free(root);
}

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        binarySortedTree *root = NULL;
        treeElement data;

        for (int i = 0; i < n; ++i) {
            scanf("%d", &data);
            root = push(root, data);
        }

        preOrder(root);
        printf("\n");
        inOrder(root);
        printf("\n");
        postOrder(root);
        printf("\n");
        destroy(root);
    }
    return 0;
}