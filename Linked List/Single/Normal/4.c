//Delete all occurences of a particular character from a character linked list

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    char data;
    struct Node *next;
}Node;

Node *Insert(Node *head, char data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}

Node *DeleteChar(Node *head,char data)
{
    Node *temp = head;
    if(temp == NULL)
    {
        printf("Empty List !!!");
        return head;
    }

    while (temp->data == data)
    {
        head = temp->next;
        free(temp);
        temp = head;
    }
    
    Node *prev;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;

        if(temp->data == data)
        {
            prev->next = temp->next;
            free(temp);
            temp = prev;
        }
    }
    return head;
}

void Print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%c ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;
    head = Insert(head,'a');
    head = Insert(head,'b');
    head = Insert(head,'a');
    head = Insert(head,'c');
    head = Insert(head,'a');
    head = Insert(head,'a');
    head = Insert(head,'d');
    Print(head);
    head = DeleteChar(head,'a');
    Print(head);
    return 0;
}