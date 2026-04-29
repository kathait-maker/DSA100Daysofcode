/*Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Check mirror
int isMirror(struct Node* t1, struct Node* t2) {
    if (t1 == NULL && t2 == NULL)
        return 1;

    if (t1 == NULL || t2 == NULL)
        return 0;

    if (t1->data != t2->data)
        return 0;

    return isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// Check symmetric
int isSymmetric(struct Node* root) {
    if (root == NULL)
        return 1;

    return isMirror(root->left, root->right);
}

int main() {
    int N, i, val;

    scanf("%d", &N);

    if (N == 0) {
        printf("YES");
        return 0;
    }

    struct Node* nodes[N];

    // Create nodes
    for (i = 0; i < N; i++) {
        scanf("%d", &val);

        if (val == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(val);
    }

    // Link children
    for (i = 0; i < N; i++) {
        if (nodes[i] != NULL) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < N)
                nodes[i]->left = nodes[left];

            if (right < N)
                nodes[i]->right = nodes[right];
        }
    }

    if (isSymmetric(nodes[0]))
        printf("YES");
    else
        printf("NO");

    return 0;
}
