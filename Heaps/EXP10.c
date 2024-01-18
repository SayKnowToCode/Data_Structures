#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int arr[], int N, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < N && arr[l] < arr[smallest])
        smallest = l;

    if (r < N && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);

        heapify(arr, N, smallest);
    }
}

void printHeap(int arr[], int N)
{

    for (int i = 0; i < N; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void buildHeap(int arr[], int N)
{
    int startIdx = (N / 2) - 1;

    for (int i = startIdx; i >= 0; i--)
    {
        heapify(arr, N, i);
        printHeap(arr, N);
    }
}

int main()
{
    int arr[100];
    int k = 0, i = 0;
    printf("Enter values of array : \n");
    while (true)
    {
        scanf("%d", &k);
        if (k == -1)
            break;

        arr[i] = k;
        i++;
    }
    int N = i;

    printf("\n");
    buildHeap(arr, N);

    return 0;
}
