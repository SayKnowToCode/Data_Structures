// Object Oriented Implementation but using C (Arrays) !!!

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 5

typedef struct 
{
    int A[MaxSize];
    int top;
}Stack;

void initializeStack(Stack *S)
{
    S->top = -1;
}

bool IsEmpty(Stack S)
{
    return (S.top == -1);
}

bool IsFull(Stack S)
{
    return (S.top == MaxSize-1);
}

void Push(Stack *S, int data)
{
    if(IsFull(*S))
    {
        printf("Stack Overflow Error ! \n");
        return;
    }
    S->A[++(S->top)] = data;
}

void Pop(Stack *S)
{
    if(IsEmpty(*S))
    {
        printf("Stack Underflow Error ! \n");
        return;
    }
    --(S->top);
}

int Peek(Stack *S)
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

void main()
{
    Stack S;
    initializeStack(&S);
    Push(&S,5);
    Push(&S,1);
    Push(&S,2);
    Pop(&S);
    Print(&S);
    printf("%d\n",Peek(&S));
    Push(&S,-2);
    Print(&S);
    Push(&S,2);
    Push(&S,2);
    Push(&S,2);
    Pop(&S);
    Pop(&S);
    Pop(&S);
    Pop(&S);
    Pop(&S);
    Pop(&S);
}
