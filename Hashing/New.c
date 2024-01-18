#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Hash
{
    int m;
    int *value;
} Hash;

int size = 0;

Hash *createHash(int m)
{
    Hash *H = (Hash *)malloc(sizeof(Hash));
    H->m = m;
    H->value = (int *)malloc(sizeof(int) * H->m);

    for (int i = 0; i < m; i++)
    {
        H->value[i] = -1;
    }

    return H;
}

void Insert(Hash *H, int key)
{
    if (size == H->m)
    {
        printf("Hash Table already full \n");
        return;
    }

    int i = 0;

    while (true)
    {
        int index = ((key % H->m) + i) % H->m;

        if (H->value[index] == -1)
        {
            H->value[index] = key;
            size++;
            return;
        }
        i++;
    }
}

void Search(Hash *H, int key)
{
    if (size == 0)
    {
        printf("Hash Table already empty \n");
        return;
    }

    int i = 0;

    while (true)
    {
        int index = ((key % H->m) + i) % H->m;

        if (H->value[index] == key)
        {
            printf("Search Successful\n");
            printf("Element found at index %d\n", index);
            return;
        }
        else if (H->value[index] == -1)
        {
            printf("Element not found\n");
            return;
        }

        i++;
    }
}

void PrintHash(Hash *H)
{
    for (int i = 0; i < H->m; i++)
    {
        printf("%d \t %d \n", i, H->value[i]);
    }
}

void main()
{
    printf("Enter size of Hash you want : ");
    int m;
    scanf("%d", &m);

    Hash *H = createHash(m);

    PrintHash(H);
    printf("\n");
    Insert(H, 3);
    Insert(H, 52);
    Insert(H, 76);
    Insert(H, 24);

    PrintHash(H);

    Search(H, 4);
    Search(H, 72);
    Search(H, 52);
}