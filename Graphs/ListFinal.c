#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node
{
    char ch;
    int index;
    int status;
} Node;

Node *N;

typedef struct ListNode
{
    char ch;
    struct ListNode *next;
} ListNode;

ListNode *InsertAtTail(ListNode *head, char ch)
{
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    temp->ch = ch;
    temp->next = NULL;

    if (head == NULL)
    {
        return temp;
    }

    ListNode *temp2 = head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    temp2->next = temp;
    return head;
}

ListNode **createGraph(int n)
{
    ListNode **List = (ListNode **)malloc(sizeof(ListNode));
    N = (Node *)malloc(sizeof(Node) * n);

    for (int i = 0; i < n; i++)
    {
        getchar();
        printf("Enter name of node : ");
        char ch;
        scanf("%c", &ch);

        List[i] = NULL;
        List[i] = InsertAtTail(List[i], ch);

        N[i].ch = ch;
        N[i].index = i;
        N[i].status = 0;
    }

    for (int i = 0; i < n; i++)
    {

        while (true)
        {
            getchar();
            printf("Enter neighbor of %c. Press 0 to exit : ", N[i].ch);
            char nb;
            scanf("%c", &nb);

            if (nb == '0')
                break;

            List[i] = InsertAtTail(List[i], nb);
        }
    }

    return List;
}

void PrintLL(ListNode *head)
{
    while (head != NULL)
    {
        printf("%c ", head->ch);
        head = head->next;
    }
    printf("\n");
}

void PrintAdjList(ListNode **List, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%c -> ", List[i]->ch);
        PrintLL(List[i]->next);
    }
}

void DFS(ListNode **List, int n, char ch)
{
    int i;
    for (int k = 0; k < n; k++)
    {
        if (List[k]->ch == ch)
        {
            i = N[k].index;
        }
    }

    ListNode *temp = List[i];

    while (temp != NULL)
    {
        if (N[i].status == 0)
        {
            printf("%c ", List[i]->ch);
            N[i].status = 1;

            ListNode *temp2 = temp->next;
            while (temp2 != NULL)
            {
                DFS(List, n, temp2->ch);
                temp2 = temp2->next;
            }
        }

        temp = temp->next;
    }
}

void DFS_Util(ListNode **List, int n)
{
    getchar();
    printf("Enter start node : ");
    char ch;
    scanf("%c", &ch);

    printf("\nThe DFS is : ");
    DFS(List, n, ch);
}

void main()
{
    printf("Enter number of nodes you desire : ");
    int n;
    scanf("%d", &n);

    ListNode **List = createGraph(n);
    PrintAdjList(List, n);

    DFS_Util(List, n);
}