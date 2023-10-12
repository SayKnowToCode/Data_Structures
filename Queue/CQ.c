// Implementing a Circular Queue

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
    Q->size = size;
    Q->front = Q->rear = -1;
    Q->A = (int *)malloc(sizeof(int) * Q->size);
    return Q;
}

bool isEmpty(Queue *Q)
{
    if (Q->front == -1)
        return true;
    return false;
}

bool isFull(Queue *Q)
{
    if ((Q->rear - Q->front) == (Q->size - 1))
        return true;
    return false;
}

void DeQ(Queue *Q)
{
    if (isEmpty(Q))
    {
        printf("Queue empty\n");
        return;
    }
    if (Q->front == Q->rear)
    {
        Q->front = Q->rear = -1;
        return;
    }

    ((++(Q->front)) % Q->size);
}

int Peek(Queue *Q)
{
    return Q->A[Q->front];
}

void Print(Queue *Q)
{
    int i = Q->front;
    for (; i <= Q->rear; i++)
    {
        printf("%d ", Q->A[(i) % (Q->size)]);
    }
    printf("\n");
}

void EnQ(Queue *Q, int data)
{
    if (isFull(Q))
    {
        printf("Queue is full");
        return;

        // Queue *LQ = createQ(Q->size);
        // int i = Q->front;
        // for (; i <= Q->rear; i++)
        // {
        //     EnQ(LQ,(Q->A[(i)%(Q->size)]));
        // }
        // Q->size = 2 * Q->size;
        // Q->A = (int *)realloc(Q->A, Q->size * sizeof(int));
        // i=0;
        // while (!isEmpty(LQ))
        // {
        //     Q->A[i] = Peek(LQ);
        //     DeQ(LQ);
        //     i++;
        // }
        // free(LQ);
        // Q->front = 0;
        // Q->rear = i-1;
    }
    else if (isEmpty(Q))
    {
        Q->front = 0;
    }

    Q->A[++(Q->rear) % Q->size] = data;
}

void PrintArray(Queue *Q)
{
    for (int i = 0; i < Q->size; i++)
    {
        printf("%d ", Q->A[i]);
    }
    printf("\n");
}

int main()
{
    Queue *Q = createQ(5);
    EnQ(Q, 1);
    Print(Q);
    EnQ(Q, 2);
    Print(Q);
    EnQ(Q, 3);
    Print(Q);
    DeQ(Q);
    Print(Q);
    DeQ(Q);
    Print(Q);
    EnQ(Q, 4);
    Print(Q);
    EnQ(Q, 5);
    Print(Q);
    DeQ(Q);
    Print(Q);
    EnQ(Q, 6);
    Print(Q);
    EnQ(Q, 6);
    Print(Q);
    EnQ(Q, 6);
    Print(Q);
    EnQ(Q, 6);
    Print(Q);
    DeQ(Q);
    Print(Q);
    EnQ(Q, 6);
    Print(Q);

    return 0;
}