#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int size = 0;

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *GetNewNode(int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->prev = temp->next = NULL;
    return temp;
}

Node *InsertAtHead(Node *head, int x)
{
    Node *temp = GetNewNode(x);
    if (head == NULL)
    {
        return temp;
    }

    temp->next = head;
    head->prev = temp;
    head = temp;
    size++;
    return head;
}

Node *InsertAtTail(Node *head, int x)
{
    Node *temp = GetNewNode(x);
    if (head == NULL)
    {
        return temp;
    }

    Node *dummy = head;
    while (dummy->next != NULL)
    {
        dummy = dummy->next;
    }

    dummy->next = temp;
    temp->prev = dummy;
    size++;
    return head;
}

Node *InsertAfterPosition(Node *head, int x, int pos)
{
    if (pos < 0 || pos > size)
    {
        printf("Invalid position !!! The valid positions are %d to %d \n", 0, size);
        return head;
    }
    else if (pos == 0)
    {
        head = InsertAtHead(head, x);
    }
    else if (pos == size)
    {
        head = InsertAtTail(head, x);
    }
    else
    {
        Node *temp = GetNewNode(x);
        Node *dummy = head;
        for (int i = 1; i < pos; i++)
        {
            dummy = dummy->next;
        }

        temp->next = dummy->next;
        dummy->next = temp;
        temp->prev = dummy;
    }
    size++;
    return head;
}

void PrintLL(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List !!!\n");
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node *Sort(Node *head)
{
    Node *temp1 = head;
    while (temp1->next != NULL)
    {
        Node *temp2 = temp1->next;
        while (temp2 != NULL)
        {
            if (temp2->data < temp1->data)
            {
                int val = temp1->data;
                temp1->data = temp2->data;
                temp2->data = val;
            }

            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return head;
}

void main()
{
    Node *head = NULL;

    head = InsertAtHead(head, 1);
    head = InsertAtHead(head, 2);
    head = InsertAtHead(head, 3);
    PrintLL(head);

    head = InsertAtTail(head, 4);
    head = InsertAtTail(head, 5);
    PrintLL(head);

    head = InsertAfterPosition(head, 9, 0);
    PrintLL(head);
    head = InsertAfterPosition(head, 7, 1);
    PrintLL(head);
    head = InsertAfterPosition(head, 8, 6);
    PrintLL(head);

    head = Sort(head);
    PrintLL(head);
}