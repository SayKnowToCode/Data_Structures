// Array Implementation of stack 

#include<stdio.h>
#include<stdbool.h>

#define MaxSize 101

static int A[MaxSize];
static int top = -1;

void Push(int data)
{
    if(top == MaxSize)
    {
        printf("Error : Stack Overflow");
        return ;
    }
    A[++top] = data;
}

void Pop()
{
    if(top == -1)
    {
        printf("Error : Stack Empty");
        return;
    }
    top -- ;
}

void Top()
{
    printf("The value at top is %d\n",A[top]);
}

bool IsEmpty()
{
    if(top == -1)
        return true;
    else
        return false;
}

void Print()
{
    for(int i=0;i<=top;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

void main()
{
    printf("%d \n",IsEmpty());
    Push(1);
    Push(2);
    Push(3);
    Print();
    Pop();
    Push(4);
    Push(5);
    Print();
}