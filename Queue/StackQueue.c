// Implement Stack using Queue

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
    Q->A = (int *)malloc(Q->size * sizeof(int));
    return Q;
}

bool isEmpty(Queue *Q)
{
    if(Q->front == -1) return true;
    return false;
}

bool isFull(Queue *Q)
{
    if(((Q->rear + 1) % Q->size) == Q->front) return true;
    return false;
}

void Enqueue(Queue *Q,int data)
{
    if(isFull(Q))
    {
        printf("Queue is Full");
        return;
    }

    if(isEmpty(Q)) Q->front=0;

    Q->A[++(Q->rear)] = data;
}

void Dequeue(Queue *Q)
{
    if(isEmpty(Q))
    {
        printf("Queue is Empty");
        return;
    }

    ++(Q->front);
    if(Q->front > Q->rear)
    {
        Q->front = Q->rear = -1;
    }
}

int Peek(Queue *Q)
{
    return Q->A[Q->front];
}

void Print(Queue *Q)
{
    int i = Q->front;
    printf("Top <- ");
    while(i <= Q->rear)
    {
        printf("%d ",Q->A[i]);
        i++;
    }
    printf("\n"); 
}

void main()
{
    Queue *Stack = createQueue(10);
    Queue *Q = createQueue(10);
    printf("A Circular Queue of size 10 will be created by defaut and you can use it as a Stack\n\n");
    while(1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top/Peek\n");
        printf("4. isEmpty\n");
        printf("5. isFull\n");
        printf("Enter -1 to Exit\n");
        printf("Enter your choice : ");
        int ch;
        scanf("%d",&ch);

        if(ch==-1) break;

        switch (ch)
        {
            case 1:
            {
                printf("Enter data : ");
                int data;
                scanf("%d",&data);
                
                if(isEmpty(Stack)) 
                {   
                    Enqueue(Stack,data);
                    continue;
                }

                while (!isEmpty(Stack))
                {
                    Enqueue(Q,Peek(Stack));
                    Dequeue(Stack);
                }
                Enqueue(Stack,data);
                while (!isEmpty(Q))
                {
                    Enqueue(Stack,Peek(Q));
                    Dequeue(Q);
                }
                break;  
            }

            case 2:
            {
                Dequeue(Stack);
                break;
            }

            case 3:
            {
                printf("%d\n",Peek(Stack));
                break;
            }

            case 4:
            {
                printf("%d\n",isEmpty(Stack));
                break;
            }

            case 5:
            {
                printf("%d\n",isFull(Stack));
                break;
            }

            case 6:
            {
                Print(Stack);
                break;
            }

            default:
            {
                printf("Wrong choice. Pls enter valid choice \n");
                continue;
            }
        }
    }
}