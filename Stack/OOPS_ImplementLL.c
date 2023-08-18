// Object Oriented Implementation but using C (LL) !!!

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
}ND;

typedef struct Stack
{
    ND *head;
}Stack;

void initializeStack(Stack *S)
{
    S->head = NULL;
}

bool IsEmpty(Stack S)
{
    return (S.head == NULL);
}

void Push(Stack *S, int entry)
{
    ND *temp = (ND*)malloc(sizeof(ND));
    temp->data = entry;
    temp->next = S->head;
    S->head = temp;
}

void Pop(Stack *S)
{
    if(IsEmpty(*S))
    {
        printf("Stack Underflow Error ! \n");
        return;
    }
    ND* temp = S->head;
    S->head = temp->next;
    free(temp);
}

int Peek(Stack *S)
{
    return S->head->data;
}

void Print(Stack *S)
{
    ND *temp = S->head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    Stack S;
    initializeStack(&S);
    Push(&S,1);
    Push(&S,2);
    Push(&S,3);
    Print(&S);
    printf("%d \n",Peek(&S)); 
    Pop(&S);
    Pop(&S);
    Pop(&S);
    Pop(&S);  
    Push(&S,1);
    Push(&S,2);
    Push(&S,3);
    Push(&S,4);
    Push(&S,5);
    Push(&S,6);
    Push(&S,7);
    Push(&S,8);
    Push(&S,9);
    Push(&S,0);
    Print(&S);
}