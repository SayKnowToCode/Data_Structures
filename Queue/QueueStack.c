// Implement Queue using Stack

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct 
{
    int top;
    unsigned size;
    int *A;
}Stack;

Stack *createStack(unsigned size)
{
    Stack *S = (Stack*)malloc(sizeof(Stack));
    S->top = -1;
    S->size = size;
    S->A = (int *)malloc(S->size * sizeof(int));
    return S;
}

bool isEmpty(Stack *S)
{
    if(S->top == -1) return true;
    return false;
}

bool isFull(Stack *S)
{
    if(S->top == (S->size)-1) return true;
    return false;
}

void Push(Stack *S,int data)
{
    if(isFull(S))
    {
        S->size = S->size * 2;
        S->A = (int *)realloc(S->A, (S->size)*sizeof(int));
    }
    S->A[++(S->top)] = data;
}

void Pop(Stack *S)
{
    if(isEmpty(S))
    {
        printf("Error : Stack Underflow");
        return;
    }
    --(S->top);
}

int Peek(Stack *S)
{
    return S->A[S->top];
}

void Print(Stack *S)
{
    printf("Rear -> ");
    for(int i=0;i<=S->top;i++)
    {
        printf("%d ",S->A[i]);
    }
    printf(" -> Front \n");
}

void main()
{
    Stack *Queue = createStack(10);
    Stack *S = createStack(10);
    printf("A Stack of size 10 will be created by defaut and you can use it as a Queue\n\n");
    while(1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Top/Peek\n");
        printf("4. isEmpty\n");
        printf("5. isFull\n");
        printf("5. Print Queue\n");
        printf("Enter -1 to Exit\n");
        printf("Enter your choice : ");
        int ch;
        scanf("%d",&ch);

        if(ch==-1) break;

        switch (ch)
        {
            case 1:
            {
                printf("Enter data : ");
                int data;
                scanf("%d",&data);
                
                if(isEmpty(Queue)) 
                {   
                    Push(Queue,data);
                    continue;
                }

                while (!isEmpty(Queue))
                {
                    Push(S,Peek(Queue));
                    Pop(Queue);
                }
                Push(Queue,data);
                while (!isEmpty(S))
                {
                    Push(Queue,Peek(S));
                    Pop(S);
                }
                break;  
            }

            case 2:
            {
                Pop(Queue);
                break;
            }

            case 3:
            {
                printf("%d\n",Peek(Queue));
                break;
            }

            case 4:
            {
                printf("%d\n",isEmpty(Queue));
                break;
            }

            case 5:
            {
                printf("%d\n",isFull(Queue));
                break;
            }

            case 6:
            {
                Print(Queue);
                break;
            }

            default:
            {
                printf("Wrong choice. Pls enter valid choice \n");
                continue;
            }
        }
    }
}