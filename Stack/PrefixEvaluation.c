/*
  Prefix Evaluation in C 
  Expression must be in a valid/desired format. 
  Operands are 1 to 9 as divide by 0 error is not handled.
  Only '+'  ,  '-'  , '*', '/' operators are expected. 
*/

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
    Stack *S = (Stack *)malloc(sizeof(Stack));
    S->top = -1;
    S->A = (int *)malloc(size * sizeof(int));
    return S;
}

bool isFull(Stack *S)
{
    if(S->top == S->size - 1 ) return true;
    return false;
}

bool isEmpty(Stack *S)
{
    if(S->top == -1 ) return true;
    return false;
}

void Push(Stack *S,int data)
{
    if(isFull(S))
    {
        printf("Stack Overflow !!");
        return;

        // S->size = S->size * 2;
        // S->A = (int *)realloc(S->A, S->size * sizeof(int));
    }
    S->A[++(S->top)] = data;
}

void Pop(Stack *S)
{
    if(isEmpty(S))
    {
        printf("Stack Underflow !!");
        return;
    }
    --(S->top) ;
}

int Top(Stack *S)
{
    return S->A[S->top];
}

bool isOperand(char ch)
{
    if(ch>='1' && ch<='9') return true;
    return false;
}

bool isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/') return true;
    return false;
}

int performCalc(int op1, char oprt, int op2)
{
    switch (oprt)
    {
        case '+' : return op1+op2;
        case '-' : return op1-op2;
        case '*' : return op1*op2;
        case '/' : return op1/op2;
    }
    return 0;
}

int Evaluate(char *str)
{
    printf("Enter size of stack you desire : ");
    unsigned size;
    scanf("%u",&size);
    Stack *S = createStack(size);

    int i=0;
    while (str[i] != '\0')
    {
        if(isOperand(str[i]))
        {
            Push(S,(int)(str[i] - '0'));
            i++;
        }

        else if(isOperator(str[i]))
        {
            int op2 = Top(S); Pop(S);
            int op1 = Top(S); Pop(S);
            Push(S,performCalc(op1,str[i],op2));
            i++;
        }

        else
            i++;
    }

    int k = Top(S); Pop(S);
    free(S);
    return k;    
}

int main()
{
    printf("Enter prefix expression : ");
    char *str = NULL;
    size_t size = 0;
    getline(&str,&size,stdin);
    strcpy(str,strrev(str));

    printf("%d\n",Evaluate(str));
    free(str);

    return 0;
}