// Linked List implementation of Stack

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

 typedef struct Node
{
    int data;
    struct Node* next;
}ND ;

ND* top = NULL;

void Push(int x)
{
    ND* temp = (ND *)malloc(sizeof(ND));
    temp->data = x;
    temp->next = top;
    top = temp;
}

void Pop()
{
    if(top == NULL)
    {
        printf("Error : Stack Empty");
        return;
    }
    ND* temp = top;
    top = temp->next;
    free(temp);
}

void Top()
{
    printf("The value at top is %d\n",top->data);
}

bool IsEmpty()
{
    if(top == NULL)
        return true;
    else
        return false;
}

void Print()
{
    ND *temp = top;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    printf("%d\n",IsEmpty());
    Push(1);
    Push(2);
    Print();
    Pop();
    Push(3);
    Push(4);
    Print();
    Top();
    Push(5);
    printf("%d\n",IsEmpty());
    Print();
}