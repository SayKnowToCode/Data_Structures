#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    int front;
    int rear;
    unsigned size;
    char *A;
} Queue;

Queue *createQueue(unsigned size)
{
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    Q->front = Q->rear = -1;
    Q->size = size;
    Q->A = (char *)malloc(sizeof(char) * Q->size);
    return Q;
}

bool isEmpty(Queue *Q)
{
    if (Q->front == -1)
        return true;
    return false;
}

bool isFull(Queue *Q)
{
    if (((Q->rear + 1) % Q->size) == Q->front)
        return true;
    return false;
}

void EnQ(Queue *Q, char data)
{
    if (isFull(Q))
    {
        printf("Queue Full");
        return;
    }

    if (isEmpty(Q))
        Q->front = 0;

    Q->rear = (Q->rear + 1) % Q->size;
    Q->A[Q->rear] = data;
}

void DeQ(Queue *Q)
{
    if (isEmpty(Q))
    {
        printf("Queue Empty\n");
        return;
    }

    if (Q->front == Q->rear)
    {
        Q->front = Q->rear = -1;
        return;
    }

    Q->front = (Q->front + 1) % Q->size;
}

char Peek(Queue *Q)
{
    if (isEmpty(Q))
    {
        printf("Queue is Empty. Hence returning -1");
        return -1;
    }
    return Q->A[Q->front];
}

typedef struct Node
{
    char ch;
    int index;
    int status;
} Node;

Node *N;

int **createGraph(int n)
{
    int **M = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        M[i] = (int *)malloc(sizeof(int) * n);
    }

    N = (Node *)malloc(sizeof(Node) * n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            M[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        getchar();
        printf("Enter name of node : ");
        char ch;
        scanf("%c", &ch);

        N[i].ch = ch;
        N[i].index = i;
        N[i].status = 0;
    }

    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            getchar();
            int j;
            printf("Enter neighbour of %c. Press 0 to exit \n", N[i].ch);
            char nb;
            scanf("%c", &nb);

            if (nb == '0')
                break;

            for (int i = 0; i < n; i++)
            {
                if (N[i].ch == nb)
                    j = N[i].index;
            }

            M[i][j] = 1;
        }
    }

    return M;
}

void PrintMatrix(int **M, int n)
{
    for (int i = -1; i < n; i++)
    {
        for (int j = -1; j < n; j++)
        {
            if (i == -1 && j == -1)
                printf("\t");

            else if (i == -1)
            {
                printf("%c\t", N[j].ch);
            }

            else if (j == -1)
            {
                printf("%c\t", N[i].ch);
            }

            else
            {
                printf("%d\t", M[i][j]);
            }
        }
        printf("\n");
    }
}

void BFS(int **M, int n)
{
    getchar();
    int k;
    printf("Enter start node : ");
    char ch;
    scanf("%c", &ch);

    for (int i = 0; i < n; i++)
    {
        if (N[i].ch == ch)
        {
            k = N[i].index;
        }
    }

    Queue *Q = createQueue(n);
    EnQ(Q, N[k].ch);
    N[k].status = 1;

    while (!isEmpty(Q))
    {
        for (int i = 0; i < n; i++)
        {
            if (N[i].ch == Peek(Q))
            {
                k = N[i].index;
            }
        }

        int i = k;
        for (int j = 0; j < n; j++)
        {
            if (M[i][j] == 1)
            {
                if (N[j].status == 0)
                {
                    EnQ(Q, N[j].ch);
                    N[j].status = 1;
                }
            }
        }

        printf("%c ", Peek(Q));
        DeQ(Q);
    }
}

void DFS(int **M, int n, char ch)
{
    int i;
    for (int k = 0; k < n; k++)
    {
        if (N[k].ch == ch)
        {
            i = N[k].index;
            // i = k;
        }
    }

    for (int j = 0; j < n; j++)
    {
        if (M[i][j] == 1)
        {
            if (N[j].status == 0)
            {
                printf("%c ", N[j].ch);
                N[j].status = 1;
                DFS(M, n, N[j].ch);
            }
        }
    }
}

void DFS_Util(int **M, int n)
{
    getchar();
    int k;
    printf("Enter start node : ");
    char ch;
    scanf("%c", &ch);

    printf("DFS is : %c ", ch);
    DFS(M, n, ch);
}

void main()
{
    printf("Enter number of nodes you desire : ");
    int n;
    scanf("%d", &n);

    int **M = createGraph(n);
    PrintMatrix(M, n);
    printf("\n");

    // BFS(M, n);
    DFS_Util(M, n);
}