// Doubly Linked List and some functions related to it 

#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data;
    struct Node * next;
    struct Node * prev;
}Node;

int size=0;

Node* GetNewNode(int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

Node *InsertAtHead(Node *head,int data)
{
    Node* temp = GetNewNode(data);
    if(head == NULL)
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

Node *InsertAtTail(Node *head,int data)
{
    if(head == NULL)
    {
        head = GetNewNode(data);
        return head;
    }

    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *temp2= GetNewNode(data);
    temp2->prev = temp;
    temp->next = temp2;
    ++size;
    return head;
}

Node *InsertAtPosition(Node *head,int position,int data)
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
    temp2->prev = temp;
    ++size;
    return head;   
}

void Print(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrint(Node *head)
{
    Node* temp = head;
    while(temp->next != NULL){temp = temp->next;}
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

Node *SortedList(Node *head1, Node *head2)
{
    Node *temp = head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;
    head2->prev = temp;

    Node *i = head1;
    
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
    return head1;
}

void main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;

    for (int i = 1; i <= 5; i++)
    {
        head1 = InsertAtTail(head1,i);
        head2 = InsertAtHead(head2,6*i);
    }
    Print(head1);
    Print(head2);
    Node *newHead = SortedList(head1,head2);
    Print(newHead);
}