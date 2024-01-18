#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char start = '0';
int time = 0;
int scc = 0;

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

node **createGraph(int n, char Info[n][4])
{
    node **List = (node **)malloc(n * sizeof(node *));

    for (int i = 0; i < n; i++)
    {
        char ch;
        printf("Enter name of node : ");
        scanf("%c", &ch);

        List[i] = (node *)malloc(sizeof(node));
        List[i]->vertex = ch;
        List[i]->next = NULL;

        Info[i][0] = ch;
        Info[i][1] = '0';
        Info[i][2] = '0';
        Info[i][3] = '0';

        while (true)
        {
            printf("Enter neighbour of %c, Enter 0 to exit : ", ch);
            char ch1;
            scanf(" %c", &ch1);

            if (ch1 == '0')
                break;

            List[i] = InsertAtTail(List[i], ch1);
        }
        getchar();
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

void DFS(char ch, int n, char Info[n][4], node **List)
{
    node *temp = List[IndexingFunction(ch)];
    Info[IndexingFunction(ch)][3] = '1';
    time++;
    Info[IndexingFunction(ch)][1] = (time + '0');

    printf("%c ", temp->vertex);
    while (temp->next != NULL)
    {
        if (Info[IndexingFunction(temp->next->vertex)][3] == '1')
        {
            temp = temp->next;
            continue;
        }

        DFS(temp->next->vertex, n, Info, List);
        temp = temp->next;
    }

    time++;
    Info[IndexingFunction(ch)][2] = (time + '0');
}

void DFS_UTIL(int n, char Info[n][4], node **List)
{
    printf("Enter start Node : ");
    char ch;
    scanf("%c", &ch);
    start = ch;

    if (IndexingFunction(ch) > n - 1)
    {
        printf("Such a node doesnt exist\n");
        return;
    }
    start = ch;
    getchar();

    time = 0;

    DFS(ch, n, Info, List);
    scc++;
    printf("  (SCC %d)\n", scc);

    for (int i = 0; i < n; i++)
    {
        if (Info[i][3] == '0')
        {
            DFS(Info[i][0], n, Info, List);
            scc++;
            printf("  (SCC %d)\n", scc);
        }
    }
}

void PrintInfo(int n, char Info[n][4])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%c ", Info[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("Enter number of nodes you desire : ");
    int n;
    scanf("%d", &n);
    getchar();
    char Info[n][4];
    node **List = createGraph(n, Info);
    PrintAdjList(List, n);
    printf("\n");
    PrintInfo(n, Info);
    printf("\n");
    DFS_UTIL(n, Info, List);
    printf("\n");
    // printf("SCC is full graph in this case \n");
    PrintInfo(n, Info);

    return 0;
}