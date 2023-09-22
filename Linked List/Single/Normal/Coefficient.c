#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int power;
    int coefficient;
    struct Node *next;
} Node;

int size = 0;

Node *GetNewNode(int coefficient, int power)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->power = power;
    temp->coefficient = coefficient;
    temp->next = NULL;
    return temp;
}

Node *InsertAtTail(Node *head, int coefficient, int power)
{
    Node *temp = GetNewNode(coefficient, power);
    if (head == NULL)
    {
        head = temp;
        ++size;
        return head;
    }
    Node *temp2 = head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
    ++size;
    return head;
}

void Print(Node *head)
{
    Node *temp = head;
    printf("Expression is : ");
    while (temp != NULL)
    {
        printf("%dx^%d ", temp->coefficient, temp->power);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    Node *exp1 = NULL;
    Node *exp2 = NULL;

    printf("Enter max power from both expressions : ");
    int maxP;
    scanf("%d", &maxP);

    for (int i = maxP; i >= 0; i--)
    {
        int coefficient;
        printf("Enter coefficient of power %d for Expression 1 ", i);
        scanf("%d", &coefficient);
        exp1 = InsertAtTail(exp1, coefficient, i);
        printf("Enter coefficient of power %d for Expression 2 ", i);
        scanf("%d", &coefficient);
        exp2 = InsertAtTail(exp2, coefficient, i);
    }

    Node *exp3 = NULL;
    Node *temp1 = exp1;
    Node *temp2 = exp2;

    for (int i = maxP; i >= 0; i--)
    {
        exp3 = InsertAtTail(exp3,(temp1->coefficient+temp2->coefficient),i);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    Print(exp3);
}