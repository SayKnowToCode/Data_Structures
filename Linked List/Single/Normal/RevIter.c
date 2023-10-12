// Delete all occurences of a particular character from a character linked list

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *Insert(Node *head, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = head;
    head = temp;
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

Node *Reverse(Node *head)
{
    if (head == NULL)
        return head;

    Node *prev = NULL;
    Node *current = head;
    Node *ahead;

    while (current != NULL)
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
    Node *head = NULL;
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 8);
    Print(head);
    head = Reverse(head);
    Print(head);
}
