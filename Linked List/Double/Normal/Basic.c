// Doubly Linked List and some functions related to it

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} ND;

ND *head = NULL;

ND *GetNewNode(int data)
{
    ND *temp = (ND *)malloc(sizeof(ND));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void InsertAtHead(int data)
{
    ND *temp = GetNewNode(data);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void InsertAtTail(int data)
{
    if (head == NULL)
    {
        head = GetNewNode(data);
        return;
    }

    ND *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    ND *temp2 = GetNewNode(data);
    temp2->prev = temp;
    temp->next = temp2;
}

void InsertAtPosition(int pos, int data)
{
    if (pos == 1)
    {
        InsertAtHead(data);
        return;
    }

    ND *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
        InsertAtTail(data);
    else
    {
        ND *temp2 = GetNewNode(data);
        temp2->next = temp->next;
        temp2->prev = temp;
        temp2->next->prev = temp2;
        temp->next = temp2;
    }
}

void DeleteAtHead()
{
    if (head == NULL)
    {
        printf("Empty List");
        return;
    }
    head = head->next;
    free(head->prev);
    head->prev = NULL;
}

void DeleteAtTail()
{
    if (head == NULL)
    {
        printf("Empty List");
        return;
    }
    ND *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ND *temp2 = temp->prev;
    temp2->next = NULL;
    free(temp);
}

void DeleteAtPosition(int pos)
{
    if (pos == 1)
    {
        DeleteAtHead();
        return;
    }

    ND *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (temp->next->next == NULL)
    {
        DeleteAtTail();
    }

    else
    {
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}

void Print()
{
    ND *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrint()
{
    ND *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

void main()
{
    InsertAtHead(1);
    InsertAtHead(2);
    InsertAtHead(3);
    InsertAtTail(4);
    InsertAtTail(5);
    Print();
    DeleteAtHead();
    Print();
    DeleteAtTail();
    Print();
    InsertAtPosition(4, 6);
    InsertAtPosition(3, 7);
    Print();
    DeleteAtPosition(5);
    Print();
}