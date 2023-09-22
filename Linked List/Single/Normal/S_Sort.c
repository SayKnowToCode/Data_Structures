#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

int size=0;

Node *GetNewNode(int data)
{
    Node* temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

Node *InsertAtHead(Node *head, int data)
{
    Node *temp = GetNewNode(data);
    if(head == NULL)
    { 
        head = temp;
        ++size;
        return head;
    }

    temp->next = head;
    head = temp;
    ++size;
    return head;
}

Node *InsertAtTail(Node *head, int data)
{
    Node *temp = GetNewNode(data);
    if(head == NULL)
    { 
        head = temp;
        ++size;
        return head;
    }
    Node *temp2 = head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
    ++size;
    return head;
}

void Print(Node *head)
{
    Node* temp = head;
    printf("List is : ");
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}


Node *Sort(Node *head)
{
    Node *i = head;
    
    while (i!=NULL)
    {
        Node *temp = i;
        Node *j = i->next;
        while (j!=NULL)
        {
            if(j->data < temp->data) temp = j;
            j = j->next;
        }
        int dummy = temp->data;
        temp->data = i->data;
        i->data = dummy;

        i = i->next;
    }

    return head;  
}

void main()
{
    Node *head = NULL;
    for (int i=1; i<=5; i++) head = InsertAtHead(head,i);
    for (int i=6; i<=10; i++) head = InsertAtTail(head,i);
    Print(head);
    head = Sort(head);
    Print(head);
}