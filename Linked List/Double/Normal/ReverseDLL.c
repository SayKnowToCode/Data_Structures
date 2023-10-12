// This is done by just swapping the data

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

int size = 0;

Node *GetNewNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

Node *InsertAtHead(Node *head, int data)
{
    Node *temp = GetNewNode(data);
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
    ++size;
    return head;
}

Node *InsertAtTail(Node *head, int data)
{
    if (head == NULL)
    {
        head = GetNewNode(data);
        return head;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *temp2 = GetNewNode(data);
    temp2->prev = temp;
    temp->next = temp2;
    ++size;
    return head;
}

Node *InsertAtPosition(Node *head, int position, int data)
{
    if (head == NULL || position == 1)
    {
        if (head == NULL)
            printf("List is empty hence Inserting at position 1\n");
        head = InsertAtHead(head, data);
        return head;
    }
    else if (position == size + 1)
    {
        head = InsertAtTail(head, data);
        return head;
    }

    else if (position < 1 || position > size + 1)
    {
        printf("Valid positions are %d to %d, Pls enter a valid position", 1, (size + 1));
        return head;
    }

    Node *temp = head;
    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;
    }
    Node *temp2 = GetNewNode(data);
    temp2->next = temp->next;
    temp->next = temp2;
    temp2->prev = temp;
    ++size;
    return head;
}

void Print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrint(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

Node *ReverseList(Node *head)
{
    Node *j = head;
    while (j->next != NULL)
    {
        j = j->next;
    }
    Node *i = head;

    while (i != j)
    {
        int temp = i->data;
        i->data = j->data;
        j->data = temp;

        i = i->next;
        if (i == j)
            break;
        j = j->prev;
    }

    return head;
}

void main()
{
    Node *head = NULL;

    for (int i = 1; i <= 5; i++)
    {
        head = InsertAtTail(head, i);
    }
    Print(head);
    ReversePrint(head);
    head = ReverseList(head);
    Print(head);
}