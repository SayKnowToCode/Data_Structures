/*
  Infix to Prefix conversion in C 
  Input expression must be in a valid/desired format. 
  Operands and operator, both must be single character.
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
    char A[MaxSize];
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

void Push(Stack *S, char data)
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

char Top(Stack *S)
{
    return S->A[S->top];
}

bool IsOperand(char ch)
{
    if(ch>='1' && ch<='9') return true;
    if(ch>='a' && ch<='z') return true;
    if(ch>='A' && ch<='Z') return true;
    return false;
}

bool IsOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/') return true;
    return false;    
}

int GetPriority(char ch)
{
    switch (ch)
    {
        case '+' :
        case '-' :
            return 1;
        case '*' :
        case '/' :
            return 2;
    }
    return 0;
}

bool CheckParanthesis(char a,char b)
{
    if(a=='(' && b==')') return true;
    if(a=='{' && b=='}') return true;
    if(a=='[' && b==']') return true;
    return false;
}

void Convert(char *str, char *op)
{
    int i=0;
    while(str[i] != '\0')
    {
        i++;
    }
    --i;

    int j=0;
    Stack S;
    initializeStack(&S);

    while(i>=0)
    {
        if(IsOperand(str[i]))
        {
            op[j] = str[i];
            j++;
            i--; 
        }

        else if(IsOperator(str[i]))
        {
            while (!IsEmpty(S) && IsOperator(Top(&S)) && (GetPriority(str[i]) < GetPriority(Top(&S))))
            {
                op[j] = Top(&S);
                Pop(&S);
                j++;
            }
            Push(&S,str[i]);
            i--;
        }

        else if(str[i]==')' || str[i]=='}' || str[i]==']')
        {
            Push(&S,str[i]);
            i--;
        }

        else if(str[i]=='(' || str[i]=='{' || str[i]=='[')
        {
            while (CheckParanthesis(str[i],Top(&S)) == false)
            {
                op[j] = Top(&S);
                Pop(&S);
                j++;
            }
            Pop(&S);
            i--;
        }

        else
            i--;
    }

    while (!IsEmpty(S))
    {
        op[j] = Top(&S);
        Pop(&S);
        j++;
    }

    op[j] = '\0';  
}

void main()
{
    printf("Enter the expression : ");
    char *str = NULL;
    size_t size = 0;
    getline(&str,&size,stdin);

    char op[strlen(str)];

    Convert(str,op);
    
    for(int i = strlen(op)-1; i>=0 ; i--)
    {
        printf("%c",op[i]);
    }
}