// Implement a queue using Array
// Remember problem with linear array hence circular implemnetation of Array !!! ----> (i+1) % ArraySize

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 5
static int front = -1,rear = -1;
static int A[MaxSize];

bool IsEmpty();
bool IsFull();

void Enqueue(int data)
{
    if(IsFull())
    {
        printf("Queue is Full");
        return;
    }

    else if(IsEmpty())
    {
        ++front;
        ++rear;
    }

    else
    {
        rear = (rear+1) % MaxSize;
    }

    A[rear] = data;
}

void Dequeue()
{
    if(IsEmpty())
    {
        printf("Queue is Empty");
        return;
    }

    front = (front+1) % MaxSize;

    if(front == ((rear + 1) % MaxSize))
    {
        front = -1;
        rear = -1;
    }
}

int top()
{
    return A[front % MaxSize];
}

bool IsEmpty()
{
    if((front == -1) && (rear == -1))
        return true;
    else
        return false;
}

bool IsFull()
{
    if(((rear + 1) % MaxSize) == front)
        return true;
    else
        return false;
}

void Print()
{
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

void main()
{
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Print();
}