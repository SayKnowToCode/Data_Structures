#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    int front;
    int rear;
    unsigned size;
    int *A;
}Queue;

Queue *createQueue(unsigned size)
{
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    Q->front = Q->rear = -1;
    Q->size = size;
    Q->A = (int *)malloc(sizeof(int) * Q->size);
    return Q;
}

bool isEmpty(Queue *Q)
{
    if(Q->front == -1) return true;
    return false;
}

bool isFull(Queue *Q)
{
    if(((Q->rear+1) % Q->size) == Q->front) return true;
    return false;
}

void Enqueue(Queue *Q,int data)
{
    if(isFull(Q))
    {
        printf("Queue Full");
        return;
    }

    if(isEmpty(Q)) Q->front=0;

    Q->rear = (Q->rear+1) % Q->size;
    Q->A[Q->rear] = data;
}

void Dequeue(Queue *Q)
{
    if(isEmpty(Q))
    {
        printf("Queue Empty\n");
        return;
    }

    if(Q->front == Q->rear)
    {
        Q->front = Q->rear = -1;
        return;
    }

    Q->front = (Q->front + 1) % Q->size;
}

int Peek(Queue *Q)
{
    if(isEmpty(Q))
    {
        printf("Queue is Empty. Hence returning -1");
        return -1;
    }
    return Q->A[Q->front];
}

void Print(Queue *Q)
{
    if(isEmpty(Q)) return;

    printf("Front <- ");
    int i=Q->front;
    while(i != Q->rear)
    {
        printf("%d ",Q->A[i]);
        i = (i+1) % Q->size;
    }   
    printf("%d <- Rear \n",Q->A[i]);
}

void main()
{
    Queue *Q = createQueue(5);
    Enqueue(Q,1);  Print(Q);
    Enqueue(Q,2);  Print(Q);
    Enqueue(Q,3);  Print(Q);
    Enqueue(Q,4);  Print(Q);
    Dequeue(Q);    Print(Q);
    Enqueue(Q,5);  Print(Q);
    Dequeue(Q);    Print(Q);
    Enqueue(Q,6);  Print(Q);
    Enqueue(Q,7);  Print(Q);
    Enqueue(Q,8);  Print(Q);
    printf("%d\n",Peek(Q));
    Dequeue(Q); Print(Q);
    Enqueue(Q,9); Print(Q);
    Dequeue(Q); Print(Q);
    Dequeue(Q); Print(Q);
    Dequeue(Q); Print(Q);
    Dequeue(Q); Print(Q);
    Dequeue(Q); Print(Q);
    
    free(Q);
}