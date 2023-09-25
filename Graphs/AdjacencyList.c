#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct node
{
    char vertex;
    struct node *next;   
}node;

node *InsertAtTail(node *head,char ch)
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

node **createGraph(int n)
{
    
    char ch = 'A';
    node **List = (node **)malloc(n * sizeof(node *));
    
    for (int i = 0; i < n; i++)
    {
        List[i] = (node *)malloc(sizeof(node));
        List[i]->vertex = ch;
        List[i]->next = NULL;

        while (true)
        {
            printf("Enter neighbour of %c, Enter 0 to exit : ",ch);
            char ch;
            scanf("%c",&ch);
            getchar();
            if(ch == '0') break;

            List[i] = InsertAtTail(List[i],ch);
        }
        ch++;
    }

    return List;
}

void PrintLinkList(node *head)
{
    printf("%c -> ",head->vertex);
    node *temp = head->next;
    while (temp != NULL)
    {
        printf(" %c",temp->vertex);
        temp = temp->next;
    }
    printf("\n");
}

void PrintAdjList(node **List,int n)
{
    for(int i=0;i<n;i++)
    {
        PrintLinkList(List[i]);
    }
}

int main()
{
    printf("Enter number of nodes you desire : ");
    int n;
    scanf("%d",&n);
    getchar();
    node **List = createGraph(n);
    PrintAdjList(List,n);
    return 0;
}