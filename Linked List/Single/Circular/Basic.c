#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int x = 0;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *GetNewNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

Node *InsertAtHead(Node *head, int data)
{
    Node *temp = GetNewNode(data);
    if (head == NULL)
    {
        head = temp;
        temp->next = head;
    }
    else
    {
        Node *temp2 = head;
        while (temp2->next != head)
        {
            temp2 = temp2->next;
        }
        temp->next = head;
        head = temp;
        temp2->next = head;
    }
    return head;
}

Node *InsertAtTail(Node *head, int data)
{
    Node *temp = GetNewNode(data);
    if (head == NULL)
    {
        head = temp;
        temp->next = head;
    }
    else
    {
        Node *temp2 = head;
        while (temp2->next != head)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
        temp->next = head;
    }
    return head;
}

Node *InsertAtPosition(Node *head, int pos, int data)
{
    // Always considering the position is valid, the error is not handled

    if (pos == 1)
    {
        head = InsertAtHead(head, data);
        return head;
    }

    Node *p = head;
    for (int i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }

    if (p->next == head)
        head = InsertAtTail(head, data);

    else
    {
        Node *temp = GetNewNode(data);
        temp->next = p->next;
        p->next = temp;
    }

    return head;
}

void Print(Node *head)
{
    Node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("%d", temp->data);
    printf("\n");
}

Node *DeleteAtHead(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        Node *temp = head;
        head = temp->next;
        x = temp->data;
        Node *temp2 = head;
        while (temp2->next != temp)
        {
            temp2 = temp2->next;
        }
        temp2->next = head;
        free(temp);
    }
    printf("The deleted value = %d\n", x);
    return head;
}

Node *DeleteAtTail(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        Node *temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        Node *temp2 = temp->next;
        temp->next = temp2->next;
        x = temp2->data;
        free(temp2);
    }
    printf("The deleted value = %d\n", x);
    return head;
}

Node *DeleteAtPosition(Node *head, int pos)
{
    if (pos == 1)
    {
        head = DeleteAtHead(head);
        return head;
    }

    Node *p = head;
    for (int i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }

    if (p->next->next == head)
    {
        head = DeleteAtTail(head);
        return head;
    }
    else
    {
        Node *temp = p->next;
        p->next = temp->next;
        x = temp->data;
        free(temp);
    }

    printf("The deleted value = %d\n", x);
    return head;
}

bool Search(Node *head, int data)
{
    Node *temp = head;
    while (temp->next != head)
    {
        if (temp->data == data)
            return true;

        temp = temp->next;
    }
    return false;
}

void main()
{
    Node *head = NULL;
    head = InsertAtHead(head, 1);
    head = InsertAtHead(head, 2);
    head = InsertAtHead(head, 3);
    head = InsertAtTail(head, 6);
    head = InsertAtTail(head, 9);
    Print(head);
    head = InsertAtPosition(head, 6, 5);
    Print(head);
    head = InsertAtPosition(head, 1, 7);
    Print(head);
    head = InsertAtPosition(head, 4, 0);
    Print(head);
    head = DeleteAtHead(head);
    Print(head);
    head = DeleteAtTail(head);
    Print(head);
    head = DeleteAtPosition(head, 3);
    Print(head);
    head = DeleteAtPosition(head, 5);
    Print(head);
    printf("%d\n", Search(head, 0));
    printf("%d\n", Search(head, 3));
}