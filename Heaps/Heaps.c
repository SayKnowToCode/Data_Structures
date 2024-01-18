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
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Heapify(Heap *H, int i)
{
    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if ((left < H->size) && (H->A[left] > H->A[largest]))
        largest = left;

    if ((right < H->size) && (H->A[right] > H->A[largest]))
        largest = right;

    if (largest != i)
    {
        swap(&H->A[i], &H->A[largest]);
        Heapify(H, largest);
    }
}

void Insert(Heap *H, int x)
{
    ++(H->size);
    if (H->size > H->maxSize)
    {
        printf("Heap Full \n");
        return;
    }

    H->A[H->size - 1] = x;

    for (int i = (H->size / 2) - 1; i >= 0; i--)
        Heapify(H, i);
}

int extractMax(Heap *H)
{
    int temp = H->A[0];

    H->A[0] = H->A[H->size - 1];
    --(H->size);

    for (int i = (H->size / 2) - 1; i >= 0; i--)
        Heapify(H, i);

    return temp;
}

void PrintHeap(Heap *H)
{
    for (int i = 0; i < H->size; i++)
    {
        printf("%d ", H->A[i]);
    }
    printf("\n");
}

void HeapSort(Heap *H)
{
    printf("\nThe HeapSort is : ");
    while (H->size != 0)
    {
        printf("%d ", extractMax(H));

        for (int i = (H->size / 2) - 1; i >= 0; i--)
            Heapify(H, i);
    }
    printf("\n");
}

void main()
{
    Heap *H = createHeap(10);
    Insert(H, 7);
    PrintHeap(H);
    Insert(H, 2);
    PrintHeap(H);
    Insert(H, 65);
    PrintHeap(H);
    Insert(H, 13);
    PrintHeap(H);
    Insert(H, 1);
    PrintHeap(H);
    Insert(H, 25);
    PrintHeap(H);
    Insert(H, 8);
    PrintHeap(H);

    Insert(H, 38);
    PrintHeap(H);

    Insert(H, 54);
    PrintHeap(H);

    HeapSort(H);
}