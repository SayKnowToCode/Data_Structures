// Inserting a node at the beginning 
//Printing all elements

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node* head;

void Insert(int x)
{
    struct Node* temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = head;
    head = temp;
}
void Print()
{
    struct Node* temp = head;
    printf("List is : ");
    while (temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    head = NULL;

    printf("Enter how many numbers u want ");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        printf("Enter the element ");
        scanf("%d",&x);
        Insert(x);
        Print();
    }
}
