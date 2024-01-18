#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *InsertAtHead(Node *head, int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;

    if (head == NULL)
    {
        return temp;
    }

    temp->next = head;
    head = temp;
    return head;
}

Node *InsertAtTail(Node *head, int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;

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
    return head;
}

void PrintLL(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List \n");
        return;
    }

    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

int CheckPalindrome(Node *head)
{
    Node *head2 = NULL;
    Node *temp = head;

    while (temp != NULL)
    {
        head2 = InsertAtHead(head2, temp->data);
        temp = temp->next;
    }

    while (head != NULL)
    {
        if (head->data != head2->data)
            return 0;

        head = head->next;
        head2 = head2->next;
    }

    return 1;
}

Node *DeleteDuplicates(Node *head)
{
    Node *temp = head;
    while (true)
    {
        while ((temp->next != NULL) && (temp->data == temp->next->data))
        {
            temp->next = temp->next->next;
        }

        if (temp == NULL || temp->next == NULL)
            break;

        temp = temp->next;
    }

    return head;
}

Node *Partition(Node *head, int value)
{
    Node *less = NULL;
    Node *val = NULL;
    Node *more = NULL;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data < value)
        {
            less = InsertAtTail(less, temp->data);
        }
        else if (temp->data == value)
        {
            val = InsertAtTail(val, temp->data);
        }
        else
        {
            more = InsertAtTail(more, temp->data);
        }

        temp = temp->next;
    }

    temp = less;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = val;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = more;
    return less;
}

Node *Swap(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp = head;
    Node *temp2 = head->next;

    while (temp->next != NULL && temp2->next != NULL)
    {
        int dummy = temp->data;
        temp->data = temp2->data;
        temp2->data = dummy;

        temp = temp->next->next;
        temp2 = temp2->next->next;
    }

    return head;
}

void main()
{
    Node *head = NULL;

    head = InsertAtTail(head, 1);
    head = InsertAtTail(head, 5);
    head = InsertAtTail(head, 3);
    head = InsertAtTail(head, 2);
    head = InsertAtTail(head, 4);
    head = InsertAtTail(head, 2);

    PrintLL(head);

    // if (CheckPalindrome(head))
    // {
    //     printf("%d (It is Palindrome)", CheckPalindrome(head));
    // }
    // else
    // {
    //     printf("%d (It is not Palindrome)", CheckPalindrome(head));
    // }

    head = Partition(head, 3);
    PrintLL(head);

    // head = DeleteDuplicates(head);
    // PrintLL(head);

    head = Swap(head);
    PrintLL(head);
}