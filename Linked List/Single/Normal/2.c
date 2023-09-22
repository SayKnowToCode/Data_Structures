// Insert node at nth position

#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} ND;

ND* head = NULL;

void Insert(int x,int n)
{
    ND* temp1 = (ND*)malloc(sizeof(ND));
    temp1->data = x;
    if(n==1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    ND* temp2 = head;
    for(int i=1;i<n-1;i++)
    {temp2 = temp2->next; }
    temp1->next = temp2->next;
    temp2->next = temp1;
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
    Insert(2,1);
    Insert(3,2);
    Insert(4,1);
    Insert(5,2);
    Print();
}