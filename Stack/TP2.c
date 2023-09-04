// Stack stored in heap to Evaluate Prefix Expression

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
        //printf("Error : Stack Overflow");
        //return;
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

int Top(Stack *S)
{
    return S->A[S->top];
}

void Print(Stack *S)
{
    for(int i=0;i<=S->top;i++)
    {
        printf("%d ",S->A[i]);
    }
    printf("\n");
}

bool isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/') return true;
    return false;
}

bool isOperand(char ch)
{
    if(ch>='1' && ch<='9') return true;
    return false;
}

int performCalculation(int op1,char oprt,int op2)
{
    switch(oprt)
    {
        case '+':
            return op1+op2;
        case '-':
            return op1-op2;
        case '*':
            return op1*op2;
        case '/':
            return op1/op2;
    }
    return 0;
}

void Evaluate(char *str,int len)
{
    Stack *S = createStack(len);
    int i=len-1;

    while(i>=0)
    {
        if(isOperand(str[i]))
        {
            Push(S,(int)(str[i] - '0'));
            i--;
        }

        else if(isOperator(str[i]))
        {
            int op1 = Top(S); Pop(S);
            int op2 = Top(S); Pop(S);

            Push(S,performCalculation(op1,str[i],op2));
            i--;
        }

        else
            i--;

        Print(S);
    }

    printf("\nThe value is %d\n",Top(S));
    free(S);
}

void main()
{
    printf("Enter the prefix expression ");
    char *str = NULL;
    size_t size = 0;
    getline(&str,&size,stdin);
   
    Evaluate(str,(int)strlen(str));
    free(str);
}