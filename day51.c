/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6*/


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

int findLCA(struct Node* root, int n1, int n2) {
    while (root != NULL) {
        if (n1 < root->data && n2 < root->data)
            root = root->left;

        else if (n1 > root->data && n2 > root->data)
            root = root->right;

        else
            return root->data;
    }
    return -1;
}

int main() {
    int N, i, value;
    struct Node* root = NULL;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    printf("%d", findLCA(root, n1, n2));

    return 0;
}
