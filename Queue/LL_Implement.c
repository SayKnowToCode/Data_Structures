// Linked List implementation of Queue

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
}ND;

ND *front = NULL;
ND *rear = NULL;

bool IsEmpty()
{
    if((front == NULL) && (rear == NULL))
        return true;
    
    return false;
}

void Enqueue(int x)
{
    ND *temp = (ND*)malloc(sizeof(ND));
    temp->data = x;
    temp->next = NULL;

    if(IsEmpty())
    {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void Dequeue()
{
    if(IsEmpty())
    {
        printf("Empty Queue");
        return;
    }

    if(front == rear)
    {
        front = rear = NULL;
        return;
    }

    ND *temp = front;
    front = front->next;
    free(temp);
}

int Top()
{
    return rear->data;
}

void Print(ND *temp)
{
    if(temp == NULL){return;}
    printf("%d ",temp->data);
    Print(temp->next);   
}

void main()
{
    for(int i=1;i<=5;i++)
    {
        Enqueue(i);
    }
    Print(front);
    Dequeue();
    Dequeue();
    Print(front);
}