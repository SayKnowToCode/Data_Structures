#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Heap
{
    int size;
    int maxSize;
    int *A;
} Heap;

Heap *createHeap(int maxSize)
{
    Heap *H = (Heap *)malloc(sizeof(Heap));
    H->size = 0;
    H->maxSize = maxSize;
    H->A = (int *)malloc(sizeof(int) * maxSize);
    return H;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(Heap *H, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if ((left < H->size) && (H->A[left] < H->A[smallest]))
        smallest = left;

    if ((right < H->size) && (H->A[right] < H->A[smallest]))
        smallest = right;

    if (smallest != i)
    {
        swap(&H->A[i], &H->A[smallest]);
        Heapify(H, smallest);
    }
}

void Insert(Heap *H, int x)
{
    ++(H->size);

    if (H->size > H->maxSize)
    {
        printf("Heap full \n");
        return;
    }

    H->A[H->size - 1] = x;

    for (int i = (H->size / 2) - 1; i >= 0; i--)
        Heapify(H, i);
}

int extractMin(Heap *H)
{
    if (H->size == 0)
    {
        printf("Heap Empty \n");
        return -1;
    }

    int temp = H->A[0];
    H->A[0] = H->A[H->size - 1];
    --(H->size);

    for (int i = (H->size / 2) - 1; i >= 0; i--)
        Heapify(H, i);
    return temp;
}

void HeapSort(Heap *H)
{
    printf("\nThe HeapSort is : ");
    while (H->size != 0)
    {
        printf("%d ", extractMin(H));

        for (int i = (H->size / 2) - 1; i >= 0; i--)
            Heapify(H, i);
    }
}

void PrintHeap(Heap *H)
{
    for (int i = 0; i < H->size; i++)
    {
        printf("%d ", H->A[i]);
    }
    printf("\n");
}

void main()
{
    Heap *H = createHeap(10);

    Insert(H, 2);
    PrintHeap(H);
    Insert(H, 5);
    PrintHeap(H);
    Insert(H, 15);
    PrintHeap(H);
    Insert(H, 62);
    PrintHeap(H);
    Insert(H, 1);
    PrintHeap(H);
    Insert(H, 37);
    PrintHeap(H);
    Insert(H, 26);
    PrintHeap(H);
    Insert(H, 8);
    PrintHeap(H);
    Insert(H, 11);
    PrintHeap(H);
    Insert(H, 3);
    PrintHeap(H);

    HeapSort(H);
}