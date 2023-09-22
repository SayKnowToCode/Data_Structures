// Solving Josepheus Problem using CQ
// Implementing a Circular Queue

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
    if(Q->front == -1) return true;
    return false;
}

bool isFull(Queue *Q)
{
    if((Q->rear - Q->front) == (Q->size - 1)) return true;
    return false;
}

void DeQ(Queue *Q)
{
    if (isEmpty(Q))
    {
        printf("Queue empty\n");
        return;
    }
    if(Q->front == Q->rear)
    {
        Q->front = Q->rear = -1;
        return;
    }
    
    ((++(Q->front)) % Q->size);
}

int Peek(Queue *Q)
{
    return Q->A[Q->front % Q->size];
}

void Print(Queue *Q)
{
    int i = Q->front;
    for (; i <= Q->rear; i++)
    {
        printf("%d ",Q->A[(i)%(Q->size)]);
    }
    printf("\n");
}

void EnQ(Queue *Q,int data)
{
    if(isFull(Q))
    {
        printf("Queue is full");
        return;
    }
    else if (isEmpty(Q))
    {
        Q->front = 0;
    }

    Q->A[++(Q->rear) % Q->size] = data;   
}

int NonZeroElement(Queue *Q)
{
    for (int i = 0; i < Q->size; i++)
    {
        if(Q->A[i] != 0) return Q->A[i];
    }
}

void Josepheus(int n, int k)
{
    Queue *Q = createQ(n);
    for(int i=1;i<=n;i++)
        EnQ(Q,i);

    int KillCount = n;
    int i=1;
    while (KillCount!=1)
    {
        int x = Peek(Q);

        if(i%k == 0)
        {
            while(Peek(Q) == 0)
            {
                DeQ(Q);
                EnQ(Q,0);
            }
            DeQ(Q);
            --KillCount;
            EnQ(Q,0); 
        }

        else
        {  
            DeQ(Q);
            EnQ(Q,x);
            if(x==0) continue;
        }
        ++i;
    }
    printf("The last man alive is %d\n",NonZeroElement(Q));
    free(Q);
}

int main()
{
    while (true)
    {
        printf("n = ");
        int n;
        scanf("%d",&n);
        printf("k = ");
        int k;
        scanf("%d",&k);
        if(k==0)
        {
            printf("Incorrect Input,k cannot be 0 \n");
            continue;
        }
        if(k>=n)
        {
            printf("Incorrect Input,k cannot be greater than equal to n \n");
            continue;
        }
        Josepheus(n,k);
        return 0;
    }
}