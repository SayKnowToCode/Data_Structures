// Reverse a Linked List using a Explicit Stack
// Usind ND **head is used in Reverse function as argument and ND *head method is commented out

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 10

typedef struct Node
{
    int data;
    struct Node *next;
}ND;

typedef struct 
{
    ND* A[MaxSize];
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

void Push(Stack *S,ND *temp)
{
    if(IsFull(*S))
    {
        printf("Stack Overflow\n");
        return;
    }
    S->A[++(S->top)] = temp;
}

void Pop(Stack *S)
{
    if(IsEmpty(*S))
    {
        printf("Stack Underflow\n");
        return;
    }
    --(S->top);
}

ND *Top(Stack *S)
{
    return S->A[S->top];
}

void Reverse(ND **head)
{
    if(*head == NULL) return;

    Stack S;
    initializeStack(&S);
    ND *temp = *head;
    while(temp != NULL)
    {
        Push(&S,temp);
        temp = temp->next;
    }
    *head = Top(&S);
    temp = *head;
    Pop(&S);
    while(!IsEmpty(S))
    {
        temp->next = Top(&S);
        Pop(&S);
        temp = temp->next;
    }
    temp->next = NULL;
}

// ND *Reverse(ND *head)
// {
//     if(head == NULL) return head;

//     Stack S;
//     initializeStack(&S);
//     ND *temp = head;
//     while(temp != NULL)
//     {
//         Push(&S,temp);
//         temp = temp->next;
//     }
//     head = Top(&S);
//     temp = head;
//     Pop(&S);
//     while(!IsEmpty(S))
//     {
//         temp->next = Top(&S);
//         Pop(&S);
//         temp = temp->next;
//     }
//     temp->next = NULL;
//     return head;
// }

void Print(ND *head)
{
    ND *temp = head;
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main() 
{
    ND* head = NULL;
    for (int i = 1; i <= 5; i++) {
        ND* newNode = (ND*)malloc(sizeof(ND));
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }
    Print(head);
    Reverse(&head);
    // head = Reverese(head);
    Print(head);
}