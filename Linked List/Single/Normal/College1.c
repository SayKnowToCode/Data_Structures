
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

Node *InsertAtPosition(Node *head, int data,int position)
{ 
    if(head == NULL || position==1)
    { 
        if (head==NULL) printf("List is empty hence Inserting at position 1\n");
        head = InsertAtHead(head,data);
        return head;
    }
    else if (position == size+1)
    {
        head = InsertAtTail(head,data);
        return head;
    }

    else if(position<1 || position > size+1)
    {
        printf("Valid positions are %d to %d, Pls enter a valid position",1,(size+1));
        return head;
    }

    Node *temp = head;
    for (int i = 1; i < position-1; i++)
    {
        temp = temp->next;
    }
    Node *temp2 = GetNewNode(data);
    temp2->next = temp->next;
    temp->next = temp2;
    ++size;
    return head;   
}

Node *DeleteAtHead(Node *head)
{
    if(head == NULL)
    {
        printf("list is already empty \n");
        return head;
    }

    Node *temp = head;
    head = head->next;
    free(temp);
    --size;
    return head;
}

Node *DeleteAtTail(Node *head)
{
    if(head == NULL)
    {
        printf("list is already empty \n");
        return head;
    }
    else if (head->next == NULL)
    {
        printf("Last Element removed from list \n");
        free(head);
        --size;
        return NULL;
    }
    
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    --size;
    return head;
}

Node *DeleteAtPosition(Node *head,int position)
{
    if(head == NULL)
    {
        printf("list is already empty \n");
        return head;
    }
    else if (position == 1)
    {
        head = DeleteAtHead(head);
        return head;
    }
    else if (position == size)
    {
        head = DeleteAtTail(head);
        return head;
    }
    else if (position<1 || position>size)
    {
        printf("Valid positions are %d to %d, Pls enter a valid position",1,(size));
        return head;
    }
    

    Node *temp = head;
    for (int i = 1; i < position-1; i++)
    {
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
    --size;
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
    Node* head = NULL;
    Node* tail = NULL;

    for (int i=1; i<=5; i++)
    { head = InsertAtHead(head,i); }
    Print(head);
}
