#include <stdio.h>

int main()
{
    int A[101];
    for (int i = 0; i < 101; i++)
    {
        A[i] = 0;
    }

    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            if ((j % i) == 0)
            {
                if (A[j] == 0)
                    A[j] = 1;
                else
                    A[j] = 0;
            }
        }
    }
    printf("\n");
    for (int i = 1; i <= 100; i++)
    {
        printf("%d ", A[i]);
        if (i % 10 == 0)
        {
            printf("\n");
        }
    }

    for (int i = 1; i <= 100; i++)
    {
        if (A[i] == 1)
        {
            printf("%d ", i);
        }
    }

    return 0;
}