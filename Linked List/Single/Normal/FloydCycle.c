#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

int size=0;
Node *loop = NULL;

Node *GetNewNode(int data)
{
    Node* temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

Node *InsertAtTail(Node *head, int data)
{
    Node *temp = GetNewNode(data);
    
    if(data == 3) loop = temp;
    
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
    if (data == 6)
    {
        temp->next = loop;
    }
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

void main()
{
    int flag = 0;
    Node *head = NULL;
    for (int i = 1; i <= 6; i++)
    {
        head = InsertAtTail(head,i);
    }

    Node *i = head;
    Node *j = head->next;

    while (1)
    {
        if(i==j && i!=NULL) 
        { flag = 1;
          break; }

        i=i->next;
        j=j->next->next;
    }
    
    if (flag == 1)
    {
        printf("Loop exists");
    }
    else
    {
        printf("No loop found");
    }   
}