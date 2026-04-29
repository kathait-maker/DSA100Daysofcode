/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop(){
    struct node* temp = top;
    int x = temp->data;
    top = top->next;
    free(temp);
    return x;
}

int main(){
    char exp[100];
    int i = 0;

    fgets(exp,100,stdin);

    while(exp[i] != '\0'){
        
        if(isdigit(exp[i])){
            int num = 0;
            while(isdigit(exp[i])){
                num = num*10 + (exp[i]-'0');
                i++;
            }
            push(num);
        }
        else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/'){
            int b = pop();
            int a = pop();
            int res;

            if(exp[i]=='+') res = a+b;
            else if(exp[i]=='-') res = a-b;
            else if(exp[i]=='*') res = a*b;
            else res = a/b;

            push(res);
        }
        i++;
    }

    printf("%d",pop());
}
