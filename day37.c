/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/

#include <stdio.h>

int arr[1000];
int size = 0;

void insert(int x){
    arr[size++] = x;
}

int findMin(){
    if(size == 0) return -1;
    
    int minIndex = 0;
    for(int i = 1; i < size; i++){
        if(arr[i] < arr[minIndex])
            minIndex = i;
    }
    return minIndex;
}

void delete(){
    if(size == 0){
        printf("-1\n");
        return;
    }

    int minIndex = findMin();
    printf("%d\n", arr[minIndex]);

    for(int i = minIndex; i < size-1; i++)
        arr[i] = arr[i+1];

    size--;
}

void peek(){
    if(size == 0){
        printf("-1\n");
        return;
    }

    int minIndex = findMin();
    printf("%d\n", arr[minIndex]);
}

int main(){
    int n, x;
    char op[10];

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%s", op);

        if(op[0] == 'i'){
            scanf("%d", &x);
            insert(x);
        }
        else if(op[0] == 'd'){
            delete();
        }
        else if(op[0] == 'p'){
            peek();
        }
    }

    return 0;
}
