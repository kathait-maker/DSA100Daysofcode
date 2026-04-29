/*Problem Statement:
Convert a binary tree into its mirror image by swapping left and right children at every node.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print inorder traversal of mirrored tree

Example:
Input:
7
1 2 3 4 5 6 7

Output:
7 3 6 1 5 2 4

Explanation:
Each node’s left and right children are swapped recursively.*/

#include <stdio.h>

#define MAX 100

int tree[MAX];
int n;

/* Function to swap two subtrees */
void swapSubtrees(int i, int j)
{
    if (i >= n || j >= n)
        return;

    int temp = tree[i];
    tree[i] = tree[j];
    tree[j] = temp;

    swapSubtrees(2 * i + 1, 2 * j + 1);
    swapSubtrees(2 * i + 2, 2 * j + 2);
}

/* Mirror function */
void mirror(int i)
{
    if (i >= n || tree[i] == -1)
        return;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && right < n)
        swapSubtrees(left, right);

    mirror(left);
    mirror(right);
}

/* Inorder traversal */
void inorder(int i)
{
    if (i >= n || tree[i] == -1)
        return;

    inorder(2 * i + 1);
    printf("%d ", tree[i]);
    inorder(2 * i + 2);
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &tree[i]);

    mirror(0);
    inorder(0);

    return 0;
}
