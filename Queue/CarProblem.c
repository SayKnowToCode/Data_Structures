#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct
{
    char NumberPlate[5];
    int counter;
}Car;

typedef struct
{
    int front;
    int rear;
    unsigned size;
    Car *A;
}Queue;

Queue *createQ(unsigned size)
{
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    Q->size = size;
    Q->front = Q->rear = -1;
    Q->A = (Car *)malloc(Q->size * sizeof(Car));
    return Q;
}

bool isEmpty(Queue *Q)
{  
    if(Q->front == -1) return true;
    return false;
}

bool isFull(Queue *Q)
{  
    if(Q->rear == Q->size-1) return true;
    return false;
}

int EnQ(Queue *Q,Car data)
{
    if(isFull(Q))
    {
        return -1;
    }
    else if(isEmpty(Q))
    {
        Q->front = 0;
    }

    Q->A[++(Q->rear)] = data;
    return 1;
}

void DeQ(Queue *Q)
{
    if(isEmpty(Q))
    {
        printf("Queue Empty !!");
        return;
    }
    if(Q->front == Q->rear)
    {
        Q->front = Q->rear = -1;
        return;
    }
    ++(Q->front);
}

Car Peek(Queue *Q)
{
    return Q->A[Q->front];
}

int main()
{
    Queue *ParkingSlot = createQ(3);
    Queue *SpareSlot = createQ(3);
    Queue *WaitingSlot = createQ(3);
    while(true)
    {
        printf("Enter number plate ");
        Car c1;
        scanf("%s",c1.NumberPlate);
        c1.counter = 0;
        char ch_n,ch;
        ch_n = getchar();
        printf("Enter A or D : ");
        scanf("%c",&ch);
        ch_n = getchar();

        if(ch == 'A')
        {
            int c = EnQ(ParkingSlot,c1);
            if(c==-1)
            {
                printf("Parking SLot is full, Pls wait in Queue\n");
                int w = EnQ(WaitingSlot,c1);
                if(w==-1)
                printf("Waiting Queue also full, cannot EnQ\n");
            }
        }
        else if(ch == 'D')
        {
            if(isEmpty(ParkingSlot)) 
            {
                printf("Already Empty, Atleast one Arrival should be made \n");
                continue;
            }
            while(!isEmpty(ParkingSlot))
            {
                Car c2 = Peek(ParkingSlot);
                if(strcmp(c2.NumberPlate,c1.NumberPlate))
                {
                    EnQ(SpareSlot,c2);
                }
                else
                {
                    c2.counter++;
                    printf("Car %s moved out with count = %d\n",c2.NumberPlate,c2.counter);
                }
                DeQ(ParkingSlot);
            }
            while(!isEmpty(SpareSlot))
            {
                Car c2 = Peek(SpareSlot);
                c2.counter++;
                EnQ(ParkingSlot,c2);
                DeQ(SpareSlot);
            }
            if(isEmpty(WaitingSlot) == false)
            {
                EnQ(ParkingSlot,Peek(WaitingSlot));
                DeQ(WaitingSlot);
            }
        }
        int x;
        printf("If you want to exit, enter 0 or enter 1 to continue ");
        scanf("%d",&x);
        ch_n = getchar();
        if(x==0) break;
    }
    return 0;
}