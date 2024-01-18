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
        printf("%dx^%d + ", temp->coefficient, temp->power);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    Node *exp1 = NULL;
    Node *exp2 = NULL;

    printf("Enter max power from both the expression : ");
    int maxP;
    scanf("%d", &maxP);

    for (int i = 0; i <= maxP; i++)
    {
        int c;
        printf("Enter coefficient of power %d for Expression 1 : ", i);
        scanf("%d", &c);
        exp1 = InsertAtTail(exp1, c, i);

        printf("Enter coefficient of power %d for Expression 2 : ", i);
        scanf("%d", &c);
        exp2 = InsertAtTail(exp2, c, i);
    }

    Node *temp1 = exp1;
    Node *temp2 = exp2;
    Node *exp3 = NULL;

    while (temp1 != NULL)
    {
        temp2 = exp2;
        while (temp2 != NULL)
        {
            int flag = 0;
            if (exp3 != NULL)
            {
                Node *temp3 = exp3;
                while (temp3 != NULL)
                {
                    if ((temp1->power + temp2->power) == temp3->power)
                    {
                        temp3->coefficient += temp1->coefficient * temp2->coefficient;
                        flag = 1;
                        break;
                    }
                    temp3 = temp3->next;
                }
            }

            if (flag == 0)
            {
                exp3 = InsertAtTail(exp3, temp1->coefficient * temp2->coefficient, temp1->power + temp2->power);
            }

            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    Print(exp1);
    Print(exp2);
    Print(exp3);
}