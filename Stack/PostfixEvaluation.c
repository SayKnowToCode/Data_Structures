/*
  Postfix Evaluation in C 
  Expression must be in a valid/desired format. 
  Operands are 1 to 9 as divide by 0 error is not handled.
  Only '+'  ,  '-'  , '*', '/' operators are expected. 
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define MaxSize 20

typedef struct
{
    int top;
    int A[MaxSize];
}Stack;

void initializeStack(Stack *S)
{
    S->top = -1;
}

bool IsEmpty(Stack S)
{
    if(S.top == -1)
        return true;
    return false;
}

bool IsFull(Stack S)
{
    if(S.top == MaxSize-1)
        return true;
    return false;
}

void Push(Stack *S, int data)
{
    if(IsFull(*S))
    {
        printf("Stack Overflow");
        return;
    }
    S->A[++(S->top)] = data;
}

void Pop(Stack *S)
{
    if(IsEmpty(*S))
    {
        printf("Stack Underflow");
        return;
    }
    --(S->top) ;
}

int Top(Stack *S)
{
    return S->A[S->top];
}

bool IsOperand(char ch)
{
    if(ch>='1' && ch<='9') return true;
    return false;
}

bool IsOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/') return true;
    return false;    
}


int performOperation(int op1, char oprt, int op2)
{
    switch (oprt)
    {
        case '+' :
            return op1+op2;

        case '-' :
            return op1-op2;

        case '*' :
            return op1*op2;

        case '/' :
            return op1/op2;
    }

    return 0;
}

// void Print(Stack *S)
// {
//     for(int i=0;i<=S->top;i++)
//     {
//         printf("%d ",S->A[i]);
//     }
//     printf("\n");
// }

int Evaluate(char *str)
{
    Stack S;
    initializeStack(&S);
    int i=0;

    while(str[i] != '\0')
    {
        if(IsOperand(str[i]))
        {
            Push(&S,(int)(str[i] - '0'));
            i++;
        }

        else if (IsOperator(str[i]))
        {
            char oprt = str[i]; 
            int op2 = Top(&S); Pop(&S);
            int op1 = Top(&S); Pop(&S);

            Push(&S,performOperation(op1,oprt,op2));                          
            i++;           
        }

        else
            i++; 

        //Print(&S);     
    }

    return (Top(&S));
}

int main()
{
    printf("Enter your string : ");
    char *str = NULL;
    size_t size = 0;
    getline(&str,&size,stdin);

    printf("The answer is : %d",Evaluate(str));
    free(str);
    return 0;
}