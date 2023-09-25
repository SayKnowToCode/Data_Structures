#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char start = '0';

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

void DFS(char ch, int n, char Info[n][3], node **List)
{
    node *temp = List[IndexingFunction(ch)];
    Info[IndexingFunction(ch)][2] = '1';

    printf("%c ", temp->vertex);
    while (temp->next != NULL)
    {
        if (Info[IndexingFunction(temp->next->vertex)][2] == '1')
        {
            temp = temp->next;
            continue;
        }

        DFS(temp->next->vertex, n, Info, List);
        temp = temp->next;
    }
}

void DFS_UTIL(int n, char Info[n][3], node **List)
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

    DFS(ch, n, Info, List);
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
    DFS_UTIL(n, Info, List);
    printf("\n");
    PrintInfo(n, Info);

    return 0;
}