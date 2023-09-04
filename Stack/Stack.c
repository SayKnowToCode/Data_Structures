// Another implementation of Stack where size is user input and Stack is stored in heap

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    int top;
    unsigned size;
    int *A;
}Stack;

Stack *createStack(unsigned size)
{
    Stack *S = (Stack*)malloc(sizeof(Stack));
    S->top = -1;
    S->size = size;
    S->A = (int *)malloc(S->size * sizeof(int));
    return S;
}

bool isEmpty(Stack *S)
{
    if(S->top == -1) return true;
    return false;
}

bool isFull(Stack *S)
{
    if(S->top == (S->size)-1) return true;
    return false;
}

void Push(Stack *S,int data)
{
    if(isFull(S))
    {
        //printf("Error : Stack Overflow");
        //return;
        S->size = S->size * 2;
        S->A = (int *)realloc(S->A, (S->size)*sizeof(int));
    }
    S->A[++(S->top)] = data;
}

void Pop(Stack *S)
{
    if(isEmpty(S))
    {
        printf("Error : Stack Underflow");
        return;
    }
    --(S->top);
}

int Top(Stack *S)
{
    return S->A[S->top];
}

void Print(Stack *S)
{
    for(int i=0;i<=S->top;i++)
    {
        printf("%d ",S->A[i]);
    }
    printf("\n");
}

int main()
{
    printf("Enter the size for the stack you want to create : ");
    int size;
    scanf("%d",size);
    Stack *S = createStack(size);
    Push(S,1); Print(S);
    Push(S,2); Print(S);
    Push(S,3); Print(S);
    Pop(S);Print(S);
    Push(S,4); Print(S);
    printf("%d\n",Top(S));
    Pop(S); Pop(S);
    printf("%d\n",Top(S));
    Pop(S);Pop(S);
    free(S);
    return 0;
}