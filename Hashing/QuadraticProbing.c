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
int c1 = 1;
int c2 = 3;

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
        int index = ((key % H->m) + (c1*i) + (c2*i*i)) % H->m;
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
        int i = 1;
        while (1)
        {
            int j = ((key % H->m) + (c1*i) + (c2*i*i)) % H->m;
            if(j == index) 
            {
                printf("Element not found\n");
                return;
            }
            
            if (H->A[j] == 0)
            {
                printf("Element not found\n");
                return;
            }
            else if (H->A[j] == key)
            {
                printf("Element found at index %d\n", j);
                return;
            }
            i++;
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

    Search(H,34);
    Search(H,36);
    Search(H,18);
}