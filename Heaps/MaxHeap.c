#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int MaxSize;

typedef struct MaxHeap
{
    unsigned size;
    int *A;
}Heap;

Heap *createHeap(unsigned size)
{
    Heap *H = (Heap *)malloc(sizeof(Heap));
    H->size = 0;
    MaxSize = size;
    H->A = (int *)malloc(MaxSize * sizeof(int));
    return H;
}

void Insert(Heap *H,int data)
{
    ++(H->size);
    if(H->size > MaxSize) return;

    H->A[H->size-1] = data;
    int i = H->size;
    while (H->A[(i)-1] >= H->A[(i/2)-1])
    {
        if(i<=1) break;

        int temp = H->A[(i)-1];
        H->A[(i)-1] = H->A[(i/2)-1];
        H->A[(i/2)-1] = temp;
        i = i/2;
    }
}

void Delete(Heap *H)
{
    H->A[0] = H->A[H->size - 1];
    --(H->size);
    if(H->size == 0) return;

    int i=1,x;

    do
    {
        if((2*i) <= H->size)
        {
            x = 2*i;
            if(H->A[x-1] > H->A[x])
                x = x-1;
        }
        else
        {
            return;
        }

        int temp = H->A[i-1];
        H->A[i-1] = H->A[x];
        H->A[x] = temp;
        i = 2*i;
    }
    while (H->A[i-1] <= H->A[x]);
}

int Peek(Heap *H)
{
    // return H->A[0];
    printf(" %d\n",H->A[0]);
    return 0;
}

void Print(Heap *H)
{
    for(int i=0;i<H->size;i++)
    {
        printf("%d ",H->A[i]);
    }
    printf("\n");
}

void main()
{
    Heap *H = createHeap(5);
    Insert(H,1); Print(H);
    Insert(H,2); Print(H);
    Insert(H,3); Print(H);
    Insert(H,4); Print(H);
    Insert(H,5); Print(H);
    Delete(H);   Print(H);
    Delete(H);   Print(H); 
    Insert(H,8); Print(H);
    Insert(H,7); Print(H);
    Delete(H);   Print(H);
    Delete(H);   Print(H);
    
    free(H);
}