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
    while (H->A[(i)-1] <= H->A[(i/2)-1])
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
            if(H->A[x-1] < H->A[x])
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
    while (H->A[i-1] >= H->A[x]);
}

int Peek(Heap *H)
{
    return H->A[0];
    // printf(" %d\n",H->A[0]);
    // return 0;
}

void Heapify(Heap *H) // My function to bubble sort entire right and left subtrees
{
    int i = H->size;
    int temp;
    while(i>1)
    {
        if(i/2 == (i-1)/2)
        {
            if(H->A[i-1] <= H->A[i-2])
            {
                if(H->A[i-1] < H->A[(i/2)-1])
                {
                    temp = H->A[i-1];
                    H->A[i-1] = H->A[(i/2)-1];
                    H->A[(i/2)-1] = temp;
                } 
            }
            else
            {
                if(H->A[i-2] < H->A[(i/2)-1])
                {
                    temp = H->A[i-2];
                    H->A[i-2] = H->A[(i/2)-1];
                    H->A[(i/2)-1] = temp;
                }
            }
            i = i-2;
        }
        else
        {
            if(H->A[i-1] < H->A[(i/2)-1])
            {
                temp = H->A[i-1];
                H->A[i-1] = H->A[(i/2)-1];
                H->A[(i/2)-1] = temp;
            }
            i--;
        }
    }
}

void minHeapify(Heap *H, int i) // Chat GPT Code 
{
    int smallest = i; // Initialize the smallest as the current node
    int left = 2 * i + 1; // Calculate the left child's index
    int right = 2 * i + 2; // Calculate the right child's index

    // Check if the left child is smaller than the current smallest
    if (left < H->size && H->A[left] < H->A[smallest])
        smallest = left;

    // Check if the right child is smaller than the current smallest
    if (right < H->size && H->A[right] < H->A[smallest])
        smallest = right;

    // If the smallest element is not the current node, swap them and recursively heapify
    if (smallest != i)
    {
        int temp = H->A[i];
        H->A[i] = H->A[smallest];
        H->A[smallest] = temp;

        // Recursively heapify the affected subtree
        minHeapify(H, smallest);
    }
}

void DecreaseKey(Heap *H, int key,int data)
{
    if(key > H->size-1 || key<0)
    {
        printf("Invalid Key Input");
        return;
    }

    H->A[key] = data;
    Heapify(H);
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
    Heap *H = createHeap(10);
    // Insert(H,5); Print(H); Heapify(H);  Print(H); 
    // Insert(H,4); Print(H); Heapify(H);  Print(H);
    // Insert(H,3); Print(H); Heapify(H);  Print(H);
    // Insert(H,2); Print(H); Heapify(H);  Print(H);
    // Insert(H,1); Print(H); Heapify(H);  Print(H);
    // Delete(H);   Print(H); Heapify(H);  Print(H); minHeapify(H,0); Print(H);
    // Delete(H);   Print(H); Heapify(H);  Print(H); minHeapify(H,0); Print(H);
    // Insert(H,8); Print(H); Heapify(H);  Print(H);
    // Insert(H,7); Print(H); Heapify(H);  Print(H);
    // Delete(H);   Print(H); Heapify(H);  Print(H); minHeapify(H,0); Print(H);
    // Delete(H);   Print(H); Heapify(H);  Print(H); minHeapify(H,0); Print(H);
    // Insert(H,1); Print(H); Heapify(H);  Print(H);

    Insert(H,5); Print(H);
    Insert(H,4); Print(H);
    Insert(H,3); Print(H);
    Insert(H,2); Print(H);
    Insert(H,1); Print(H);
    Delete(H); Print(H);
    Insert(H,7); Print(H);
    Insert(H,8); Print(H);
    DecreaseKey(H,4,1); Print(H);
    free(H);
}