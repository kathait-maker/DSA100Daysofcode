/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/

#include <stdio.h>

int main() {
    int n, m, i;
    int stack[100];
    int top = -1;

    // number of elements to push
    scanf("%d", &n);

    // push elements
    for(i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        stack[++top] = x;
    }

    // number of pops
    scanf("%d", &m);

    // pop elements
    for(i = 0; i < m; i++) {
        if(top >= 0)
            top--;
    }

    // display stack from top to bottom
    for(i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if(i != 0) printf(" ");
    }

    return 0;
}
