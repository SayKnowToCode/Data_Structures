#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Hashing
{
    unsigned m;
    char *Status;
    int *Value;

} Hash;

int size = 0;

Hash *createHash(unsigned m)
{
    Hash *H = (Hash *)malloc(sizeof(Hash));
    H->m = m;
    H->Status = (char *)malloc(H->m * sizeof(int));
    H->Value = (int *)malloc(H->m * sizeof(int));

    for (int i = 0; i < m; i++)
    {
        H->Status[i] = 'E';
    }

    for (int i = 0; i < m; i++)
    {
        H->Value[i] = -1;
    }

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
        if (H->Status[index] == 'E' || H->Status[index] == 'D')
        {
            H->Value[index] = key;
            H->Status[index] = 'O';
            ++size;
            break;
        }
        else
            i++;
    }
}

void Delete(Hash *H, int key)
{
    if (size == 0)
    {
        printf("Hash Table is already empty");
        return;
    }

    int i = 0;
    while (true)
    {
        int index = ((key % H->m) + i) % H->m;
        if (H->Status[index] == 'O')
        {
            if (H->Value[index] == key)
            {
                H->Status[index] = 'D';
            }
            break;
        }
        else
            i++;
    }
}

void Search(Hash *H, int key)
{
    int index = ((key % H->m) + 0) % H->m;

    while (1)
    {
        if (H->Status[index] == 'E')
        {
            printf("Element not found\n");
            return;
        }

        else
        {
            if (H->Value[index] == key && H->Status[index] == 'O')
            {
                printf("Success\n");
                return;
            }
        }

        index++;
    }
}

void Print(Hash *H)
{
    for (int i = 0; i < H->m; i++)
    {
        printf("%d\t%c\t%d \n", i, H->Status[i], H->Value[i]);
    }
    printf("\n");
}

void main()
{
    int m;
    printf("Enter size m : ");
    scanf("%d", &m);
    Hash *H = createHash(m);

    Insert(H, 18);
    Insert(H, 26);
    Insert(H, 35);
    Insert(H, 9);
    // Print(H);
    Search(H, 15);
    Search(H, 48);
    Delete(H, 35);
    Search(H, 9);
    Insert(H, 64);
    Insert(H, 47);
    Search(H, 35);
    printf("\n");
    Print(H);
}
