#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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
    Q->A = (int *)malloc(sizeof(int) * Q->size);
    return Q;
}

bool isFull(Queue *Q)
{
    if ((Q->rear - Q->front) == (Q->size - 1))
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
        printf("Q is full \n");
        return;
    }
    else if (isEmpty(Q))
    {
        Q->front = 0;
    }

    Q->A[(++Q->rear) % Q->size] = data;
}

void DeQ(Queue *Q)
{
    if (isEmpty(Q))
    {
        printf("Q is empty \n");
        return;
    }

    else if (Q->front == Q->rear)
    {
        Q->front = Q->rear = -1;
        return;
    }

    ++(Q->front);
}

int front(Queue *Q)
{
    return Q->A[Q->front % Q->size];
}

int rear(Queue *Q)
{
    return Q->A[Q->rear % Q->size];
}

void PrintQ(Queue *Q)
{
    if (isEmpty(Q))
    {
        printf("Q is empty, cannot prnt it \n");
        return;
    }

    for (int i = Q->front; i <= Q->rear; i++)
    {
        printf("%d ", Q->A[i % Q->size]);
    }
    printf("\n");
}

void main()
{
    printf("Enter size of Q : ");
    int size;
    scanf("%d", &size);

    Queue *Q = createQ(size);

    EnQ(Q, 1);
    EnQ(Q, 2);
    EnQ(Q, 3);
    EnQ(Q, 4);

    PrintQ(Q);

    DeQ(Q);
    DeQ(Q);

    PrintQ(Q);

    EnQ(Q, 6);
    EnQ(Q, 7);
    EnQ(Q, 8);
    EnQ(Q, 9);

    PrintQ(Q);

    printf("%d %d", front(Q), rear(Q));
}
