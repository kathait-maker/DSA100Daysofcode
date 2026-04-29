/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Stack structure
struct Stack {
    struct Node* arr[MAX];
    int top;
};

// Initialize stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Check empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Push
void push(struct Stack* s, struct Node* node) {
    if (s->top < MAX - 1) {
        s->arr[++s->top] = node;
    }
}

// Pop
struct Node* pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[s->top--];
    }
    return NULL;
}

// Zigzag traversal
void zigzagTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack s1, s2;
    initStack(&s1);
    initStack(&s2);

    push(&s1, root);

    while (!isEmpty(&s1) || !isEmpty(&s2)) {

        // Left to Right
        while (!isEmpty(&s1)) {
            struct Node* temp = pop(&s1);
            printf("%d ", temp->data);

            if (temp->left)
                push(&s2, temp->left);

            if (temp->right)
                push(&s2, temp->right);
        }

        // Right to Left
        while (!isEmpty(&s2)) {
            struct Node* temp = pop(&s2);
            printf("%d ", temp->data);

            if (temp->right)
                push(&s1, temp->right);

            if (temp->left)
                push(&s1, temp->left);
        }
    }
}

// Build tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0)
        return NULL;

    struct Node* nodes[MAX];

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n)
                nodes[i]->left = nodes[left];

            if (right < n)
                nodes[i]->right = nodes[right];
        }
    }

    return nodes[0];
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}
