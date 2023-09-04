// Tower of Hanoi implementation using Stack

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

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
        printf("Error : Stack Overflow\n");
        return;
        //S->size = S->size * 2;
        //S->A = (int *)realloc(S->A, (S->size)*sizeof(int));
    }
    S->A[++(S->top)] = data;
}

void Pop(Stack *S)
{
    if(isEmpty(S))
    {
        printf("Error : Stack Underflow\n");
        return;
    }
    --(S->top);
}

int Top(Stack *S)
{
    if(isEmpty(S)) return -1;
    return S->A[S->top];
}

void Print(Stack *S)
{
    if(isEmpty(S)) printf("--");
    for(int i=0;i<=S->top;i++)
    {
        printf("%d ",S->A[i]);
    }
    printf("\n");
}

Stack *Preference(Stack *S1, Stack *S2)
{
    if(Top(S1) % 2 == 0)
    {
        Push(S1,0);  
        return S1;
    }
    if(Top(S2) % 2 == 0)
    {
        Push(S2,0);
        return S2;
    }

    if(isEmpty(S1))
    {
        Push(S1,0);  
        return S1;
    }
    if(isEmpty(S2)) 
    {
        Push(S2,0);  
        return S2;
    }
}

void PrintDestination(unsigned n)
{
    Stack *Start = createStack(n);
    Stack *Spare = createStack(n);
    Stack *Destination = createStack(n);
    Stack *LockStack;

    for (int i = n; i > 0; i--)
    {
        Push(Start,i);
    }
    Print(Start);
    if(n%2==0)
    {
        Push(Spare,Top(Start)); 
        Pop(Start);
        LockStack = Spare;
    }
    else
    {
        Push(Destination,Top(Start)); 
        Pop(Start);
        LockStack = Destination;
    }
    printf("\n");
    Print(Start);
    Print(Spare);
    Print(Destination);
    printf("\n");
    int i=1;
    while(1)
    {
        if(isEmpty(Start) && isEmpty(Spare) && isFull(Destination))
        break;

        //if(i==7) break;

        if(LockStack == Spare)
        {
            if(Top(Start) == 1)
            {
                LockStack = Preference(Spare,Destination);
                Pop(LockStack);
                Push(LockStack,Top(Start)); Pop(Start);
            }
            else if(Top(Destination) == 1)
            {
                LockStack = Preference(Spare,Start);
                Pop(LockStack);
                Push(LockStack,Top(Destination)); Pop(Destination);
            }
            else if(isEmpty(Start))
            {
                Push(Start,Top(Destination));
                Pop(Destination);
                LockStack = Start;
            }
            else if(isEmpty(Destination))
            {
                Push(Destination,Top(Start));
                Pop(Start);
                LockStack = Destination;
            }
            else
            {
                if(Top(Start) > Top(Destination))
                {
                    Push(Start,Top(Destination));
                    Pop(Destination);
                    LockStack = Start;
                }
                else if(Top(Destination) > Top(Start))
                {
                    Push(Destination,Top(Start));
                    Pop(Start);
                    LockStack = Destination;
                }
                else if(Top(Spare) > Top(Start))
                {
                    Push(Spare,Top(Start));
                    Pop(Start);
                    LockStack = Spare;
                }
                else if(Top(Spare) > Top(Destination))
                {
                    Push(Spare,Top(Destination));
                    Pop(Destination);
                    LockStack = Spare;
                }           
            }  
        }

        else if(LockStack == Destination)
        {
            if(Top(Start) == 1)
            {
                LockStack = Preference(Spare,Destination);
                Pop(LockStack);
                Push(LockStack,Top(Start)); Pop(Start);
            }
            else if(Top(Spare) == 1)
            {
                LockStack = Preference(Destination,Start);
                Pop(LockStack);
                Push(LockStack,Top(Spare)); Pop(Spare);
            }
            else if(isEmpty(Start))
            {
                Push(Start,Top(Spare));
                Pop(Spare);
                LockStack = Start;
            }
            else if(isEmpty(Spare))
            {
                Push(Spare,Top(Start));
                Pop(Start);
                LockStack = Spare;
            }
            else
            {
                if(Top(Start) > Top(Spare))
                {
                    Push(Start,Top(Spare));
                    Pop(Spare);
                    LockStack = Start;
                }
                else if (Top(Spare) > Top(Start))
                {
                    Push(Spare,Top(Start));
                    Pop(Start);
                    LockStack = Spare;
                }
                else if (Top(Destination) > Top(Start))
                {
                    Push(Destination,Top(Start));
                    Pop(Start);
                    LockStack = Destination;
                }
                else if (Top(Destination) > Top(Spare))
                {
                    Push(Destination,Top(Start));
                    Pop(Start);
                    LockStack = Destination;
                }
            }
        }
        
        else if(LockStack == Start)
        {
            if(Top(Spare) == 1)
            {
                LockStack = Preference(Start,Destination);
                Pop(LockStack);
                Push(LockStack,Top(Spare)); Pop(Spare);
            }
            else if(Top(Destination) == 1)
            {
                LockStack = Preference(Spare,Start);
                Pop(LockStack);
                Push(LockStack,Top(Destination)); Pop(Destination);
            }
            else if(isEmpty(Destination))
            {
                Push(Destination,Top(Spare));
                Pop(Spare);
                LockStack = Destination;
            }
            else if(isEmpty(Spare))
            {
                Push(Spare,Top(Destination));
                Pop(Destination);
                LockStack = Spare;
            }
            else
            {
                if(Top(Destination) > Top(Spare))
                {
                    Push(Destination,Top(Spare));
                    Pop(Spare);
                    LockStack = Destination;
                }
                else if (Top(Spare) > Top(Destination))
                {
                    Push(Spare,Top(Destination));
                    Pop(Destination);
                    LockStack = Spare;
                }
                else if (Top(Start) > Top(Destination))
                {
                    Push(Start,Top(Destination));
                    Pop(Destination);
                    LockStack = Start;
                }
                else if (Top(Start) > Top(Spare))
                {
                    Push(Start,Top(Start));
                    Pop(Start);
                    LockStack = Start;
                }
            }
        }
        i++;
        Print(Start);
        Print(Spare);
        Print(Destination);
        printf("\n");
    }
    printf("Number of moves required = %d",i);
}

void main()
{
    printf("Enter number of discs you want : ");
    int n;
    scanf("%d",&n);

    PrintDestination(n);
}