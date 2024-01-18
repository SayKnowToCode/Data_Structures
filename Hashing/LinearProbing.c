#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Hashing
{
    unsigned m;
    int *A;
} Hash;

int size = 0;

Hash *createHash(unsigned m)
{
    Hash *H = (Hash *)malloc(sizeof(Hash));
    H->m = m;
    H->A = (int *)calloc(H->m, sizeof(int));
    return H;
}

void Insert(Hash *H, int key)
{
    if (size == H->m)
    {
        printf("Hash Table is Full");
        return;
    }

    int i = 0;
    while (true)
    {
        int index = ((key % H->m) + i) % H->m;
        if (H->A[index] == 0)
        {
            H->A[index] = key;
            ++size;
            break;
        }
        else
            i++;
    }
}

void Search(Hash *H, int key)
{
    int index = ((key % H->m) + 0) % H->m;

    if (H->A[index] == 0)
    {
        printf("Element not found\n");
        return;
    }
    else if (H->A[index] == key)
    {
        printf("Element found at index %d\n", index);
        return;
    }
    else
    {
        int i = index + 1;
        while (1)
        {
            if (H->A[i] == 0)
            {
                printf("Element not found\n");
                return;
            }
            else if (H->A[i] == key)
            {
                printf("Element found at index %d\n", i);
                return;
            }
            i = ++i % H->m;
            if (i == index)
            {
                printf("Element not found\n");
                return;
            }
        }
    }
}

void Print(Hash *H)
{
    for (int i = 0; i < H->m; i++)
    {
        printf("%d ", H->A[i]);
    }
    printf("\n");
}

void main()
{
    Hash *H = createHash(10);
    Insert(H, 27);
    Insert(H, 72);
    Insert(H, 63);
    Insert(H, 42);
    Insert(H, 36);
    Insert(H, 18);
    Insert(H, 29);
    Insert(H, 101);
    Print(H);

    Search(H, 34);
    Search(H, 36);
    Search(H, 18);
}