// Doubly Linked List and some functions related to it 

#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data;
    struct Node * next;
    struct Node * prev;
}ND;

ND* head = NULL;

ND* GetNewNode(int x)
{
    ND* temp = (ND*)malloc(sizeof(ND));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void InsertAtHead(int x)
{
    ND* temp = GetNewNode(x);
    if(head == NULL)
    {
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void Print()
{
    ND *temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void ReversePrint()
{
    ND* temp = head;
    while(temp->next != NULL){temp = temp->next;}
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->prev;
    }
}

void main()
{
    InsertAtHead(1);
    InsertAtHead(2);
    InsertAtHead(3);
    InsertAtHead(4);
    InsertAtHead(5);
    Print();
    printf("\n");
    ReversePrint();
}