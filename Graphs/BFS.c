#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char start = '0';

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

void PrintQ(Queue *Q)
{
    if (isEmpty(Q))
        return;

    printf("Front <- ");
    int i = Q->front;
    while (i != Q->rear)
    {
        printf("%c ", Q->A[i]);
        i = (i + 1) % Q->size;
    }
    printf("%d <- Rear \n", Q->A[i]);
}

typedef struct node
{
    char vertex;
    struct node *next;
} node;

node *InsertAtTail(node *head, char ch)
{
    node *temp = head;
    node *temp2 = (node *)malloc(sizeof(node));
    temp2->vertex = ch;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = temp2;
    temp2->next = NULL;
    return head;
}

node **createGraph(int n, char Info[n][3])
{

    char ch = 'A';
    node **List = (node **)malloc(n * sizeof(node *));

    for (int i = 0; i < n; i++)
    {
        List[i] = (node *)malloc(sizeof(node));
        List[i]->vertex = ch;
        List[i]->next = NULL;

        Info[i][0] = ch;
        Info[i][1] = '0';
        Info[i][2] = '0';

        while (true)
        {
            printf("Enter neighbour of %c, Enter 0 to exit : ", ch);
            char ch;
            scanf("%c", &ch);
            getchar();
            if (ch == '0')
                break;

            List[i] = InsertAtTail(List[i], ch);
        }
        ch++;
    }

    return List;
}

void PrintLinkList(node *head)
{
    printf("%c -> ", head->vertex);
    node *temp = head->next;
    while (temp != NULL)
    {
        printf(" %c", temp->vertex);
        temp = temp->next;
    }
    printf("\n");
}

void PrintAdjList(node **List, int n)
{
    for (int i = 0; i < n; i++)
    {
        PrintLinkList(List[i]);
    }
}

int IndexingFunction(char ch)
{
    return ((int)(ch) - (int)('A'));
}

void BFS(node **List, int n, char Info[n][3])
{
    Queue *Q = createQueue(n);

    printf("Enter start Node : ");
    char ch;
    scanf("%c", &ch);

    if (IndexingFunction(ch) > n - 1)
    {
        printf("Such a node doesnt exist\n");
        return;
    }

    start = ch;
    getchar();

    do
    {
        if (Info[IndexingFunction(ch)][2] == '0')
        {
            EnQ(Q, ch);
            Info[IndexingFunction(ch)][2] = '1';
        }

        node *temp = List[IndexingFunction(ch)]->next;
        while (temp != NULL)
        {
            if (Info[IndexingFunction(temp->vertex)][2] == '0')
            {
                EnQ(Q, temp->vertex);
                Info[IndexingFunction(temp->vertex)][1] = ch;
                Info[IndexingFunction(temp->vertex)][2] = '1';
            }
            temp = temp->next;
        }

        printf("%c ", ch);
        DeQ(Q);
        if (isEmpty(Q))
            break;
        ch = Peek(Q);
    } while (true);
    printf("\n");
}

void PrintInfo(int n, char Info[n][3])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c ", Info[i][j]);
        }
        printf("\n");
    }
}

void GetShortestPath(int n, char Info[n][3])
{
    if (start == '0')
    {
        printf("First call BFS function !!! \n");
        return;
    }

    printf("Your start point is %c \n", start);
    printf("Enter destination : ");
    char dest;
    scanf("%c", &dest);
    getchar();

    if (Info[IndexingFunction(dest)][2] == '0')
    {
        printf("Node was not searched by BFS so cannot be reached\n");
        return;
    }

    printf("Shortest path from %c to %c is : ", start, dest);

    while (Info[IndexingFunction(dest)][1] != '0')
    {
        printf("%c <- ", dest);
        dest = Info[IndexingFunction(dest)][1];
    }
    printf("%c", dest);
}

int main()
{
    printf("Enter number of nodes you desire : ");
    int n;
    scanf("%d", &n);
    getchar();
    char Info[n][3];
    node **List = createGraph(n, Info);
    PrintAdjList(List, n);
    printf("\n");
    PrintInfo(n, Info);
    printf("\n");
    BFS(List, n, Info);
    printf("\n");
    PrintInfo(n, Info);
    printf("\n");
    GetShortestPath(n, Info);

    return 0;
}