// Reverse a linked list(iterative method) and passing head as argument 

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

ND *Reverse(ND *head)
{
    ND *prev,*current,*ahead;
    prev = NULL;
    current = head;
    while(current != NULL)
    {
        ahead = current->next;
        current->next = prev;
        prev = current;
        current = ahead;
    }
    head = prev;
    return head;
}

void main()
{
    ND* head = NULL;
    head = Insert(head,2);
    head = Insert(head,4);
    head = Insert(head,6);
    head = Insert(head,8);
    Print(head);
    head = Reverse(head);
    Print(head);
}