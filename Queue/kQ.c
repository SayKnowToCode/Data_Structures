#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    int *front;
    int *rear;
    int k;
    int size;
} kQueues;

kQueues *initialize(int k, int size)
{
    kQueues *kQ = (kQueues *)malloc(sizeof(kQueues));
    kQ->arr = (int *)malloc(k * size * sizeof(int));
    kQ->front = (int *)malloc(k * sizeof(int));
    kQ->rear = (int *)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++)
    {
        kQ->front[i] = -1;
        kQ->rear[i] = -1;
    }

    for (int i = 0; i < k * size; i++)
    {
        kQ->arr[i] = 0;
    }

    kQ->k = k;
    kQ->size = size;
    return kQ;
}

bool isFull(kQueues *kQ, int qn)
{
    if (kQ->rear[qn] == (kQ->k * (qn + 1) - 1))
        return true;
    return false;
}

bool isEmpty(kQueues *kQ, int qn)
{
    if (kQ->front[qn] == -1)
        return true;
    return false;
}

void EnQ(int x, int qn, kQueues *kQ)
{
    if (qn >= kQ->k)
    {
        printf("Such a Q doesnt exist \n");
        return;
    }

    if (isEmpty(kQ, qn))
    {
        kQ->front[qn] = qn * kQ->k;
        kQ->rear[qn] = kQ->front[qn];

        kQ->arr[kQ->rear[qn]] = x;
        return;
    }
    else if (isFull(kQ, qn))
    {
        printf("Queue %d is full \n", qn);
        return;
    }

    kQ->arr[++(kQ->rear[qn])] = x;
}

void DeQ(int qn, kQueues *kQ)
{
    if (isEmpty(kQ, qn))
    {
        printf("Queue %d is already empty\n", qn);
        return;
    }
    else if (kQ->front[qn] == kQ->rear[qn])
    {
        kQ->arr[kQ->front[qn]] = 0;
        kQ->front[qn] = kQ->rear[qn] = -1;
        return;
    }

    int temp = kQ->arr[kQ->front[qn]];
    kQ->arr[kQ->front[qn]] = 0;
    ++(kQ->front[qn]);

    printf("The element dequed is %d \n", temp);
    return;
}

void DisplayQ(int qn, kQueues *kQ)
{
    if (qn >= kQ->k)
    {
        printf("Such a Q doesnt exist \n");
        return;
    }

    if (isEmpty(kQ, qn))
    {
        printf("Queue is empty. Cannot Print it \n");
        return;
    }

    for (int i = kQ->front[qn]; i <= kQ->rear[qn]; i++)
    {
        printf("%d ", kQ->arr[i]);
    }
    printf("\n");
}

void DisplayAll(kQueues *kQ)
{
    for (int i = 0; i < kQ->k * kQ->size; i++)
    {
        printf("%d ", kQ->arr[i]);
    }
    printf("\n");
}

void main()
{
    printf("Enter number of queues you want : ");
    int k;
    scanf("%d", &k);

    printf("Enter size of each queue : ");
    int size;
    scanf("%d", &size);
    kQueues *kQ = initialize(k, size);

    EnQ(1, 2, kQ);
    EnQ(2, 2, kQ);
    EnQ(3, 2, kQ);

    EnQ(1, 0, kQ);
    EnQ(2, 0, kQ);
    EnQ(3, 0, kQ);

    EnQ(1, 1, kQ);
    EnQ(2, 1, kQ);
    EnQ(3, 1, kQ);

    DisplayQ(0, kQ);
    DisplayQ(1, kQ);
    DisplayQ(2, kQ);
    DisplayAll(kQ);

    DeQ(2, kQ);
    DeQ(1, kQ);
    DeQ(2, kQ);
    DeQ(0, kQ);
    DeQ(2, kQ);
    DeQ(2, kQ);

    DisplayQ(0, kQ);
    DisplayQ(1, kQ);
    DisplayQ(2, kQ);
    DisplayAll(kQ);
}