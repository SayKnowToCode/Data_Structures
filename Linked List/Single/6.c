//Printing linked list using recursion in both correct and reversed order 

#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} ND;

ND* head = NULL;

void Insert(int x)
{
    ND* temp = (ND*)malloc(sizeof(ND));
    temp->data = x;
    if(head == NULL)
    {
        temp->next = NULL;
        head = temp;
        return;
    }
    ND* temp2 = head;
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
    temp->next = NULL;
}

void PrintRev(ND *temp)
{
    if(temp == NULL)
    {return ;}
    PrintRev(temp->next);
    printf("%d ",temp->data);
}

void Print(ND *temp)
{
    if(temp == NULL)
    {return ;}
    printf("%d ",temp->data);
    Print(temp->next); 
}

void main()
{
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(8);
    Insert(10);
    PrintRev(head);
    Print(head);
}