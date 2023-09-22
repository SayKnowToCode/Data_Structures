//Reverse a linked list using recursion
// Dont use global variable !!!

#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} ND;

ND* Insert(ND* head, int x)
{
    ND* temp = (ND*)malloc(sizeof(ND));
    temp->data = x;
    if(head == NULL)
    {
        temp->next = NULL;
        head = temp;
        return head;
    }
    ND* temp2 = head;
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
    temp->next = NULL;
    return head;
}

void Print(ND* head)
{
    ND* temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

ND* Reverse(ND* temp)
{
    if(temp->next == NULL)
    {
        ND* head = temp;
        return head;
    }

    ND* head = Reverse(temp->next);
    temp->next->next = temp;
    temp->next = NULL;
    return head;
}

void main()
{
    ND* head = NULL;
    head = Insert(head,6);
    head = Insert(head,4);
    head = Insert(head,1);
    head = Insert(head,7);
    Print(head);
    printf("\n");
    head = Reverse(head);
    Print(head);
}