// Inserting a node at the end

#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} ND;

ND* head = NULL;

void Insert(int x)
{
    ND* temp = (ND*)malloc(sizeof(ND));
    temp->data = x;
    if(head == NULL)
    {
        temp->next = NULL;
        head = temp;
        return;
    }
    ND* temp2 = head;
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
    temp->next = NULL;
}

void Delete(int n)
{
    ND* temp = head;
    if(n==1)
    {
        head = temp->next;
        free(temp);
        return;
    }   
    for(int i=1;i<n-1;i++)
    {
        temp = temp->next;
    }
    ND* temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

void Print()
{
    ND* temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void main()
{
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    Print();
    int n;
    printf("\nEnter delete position ");
    scanf("%d",&n);
    Delete(n);
    Print();
    printf("\nEnter delete position ");
    scanf("%d",&n);
    Delete(n);
    Print();
}