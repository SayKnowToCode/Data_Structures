#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int front;
    int rear;
    unsigned size;
    int *A;
} Queue;

Queue *createQ(unsigned size)
{
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    Q->front = Q->rear = -1;
    Q->size = size;
    Q->A = (int *)malloc(Q->size * sizeof(int));
    return Q;
}

bool isFull(Queue *Q)
{
    if (Q->rear == Q->size - 1)
        return true;
    return false;
}

bool isEmpty(Queue *Q)
{
    if (Q->front == -1)
        return true;
    return false;
}

void EnQ(Queue *Q, int data)
{
    if (isFull(Q))
    {
        printf("Queue full\n");
        return;
    }
    else if (isEmpty(Q))
    {
        Q->front = 0;
    }

    Q->A[++(Q->rear)] = data;
}

void DeQ(Queue *Q)
{
    // int temp;
    if (isEmpty(Q))
    {
        printf("Queue Empty\n");
        return;
    }
    else if (Q->front == Q->rear)
    {
        // int temp = Q->A[Q->front];
        Q->front = Q->rear = -1;
        return;
    }

    ++(Q->front);
}

int Peek(Queue *Q)
{
    return Q->A[Q->front];
}

void PrintQ(Queue *Q)
{
    for (int i = Q->front; i <= Q->rear; i++)
    {
        printf("%d ", Q->A[i]);
    }
    printf("\n");
}

void main()
{
    printf("Enter size of Q u want : ");
    int size;
    scanf("%d", &size);
    Queue *Q = createQ(size);

    EnQ(Q, 1);
    EnQ(Q, 2);
    DeQ(Q);
    EnQ(Q, 3);
    printf("%d \n", Peek(Q));
    EnQ(Q, 4);
    DeQ(Q);
    EnQ(Q, 5);

    PrintQ(Q);
    DeQ(Q);

    printf("%d", Peek(Q));
}