#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MaxSize 50

typedef struct 
{
    char A[MaxSize];
    int top;
}Stack;

void initializeStack(Stack *S)
{
    S->top = -1;
}

bool IsEmpty(Stack S)
{
    return (S.top == -1);
}

bool IsFull(Stack S)
{
    return (S.top == MaxSize-1);
}

void Push(Stack *S, char data)
{
    if(IsFull(*S))
    {
        printf("Stack Overflow Error ! \n");
        return;
    }
    S->A[++(S->top)] = data;
}

void Pop(Stack *S)
{
    if(IsEmpty(*S))
    {
        printf("Stack Underflow Error ! \n");
        return;
    }
    --(S->top);
}

char Top(Stack *S)
{
    return S->A[S->top];
}

bool CheckParanthesis(char a, char b)
{
    if(a=='(' && b==')') return true;
    if(a=='{' && b=='}') return true;
    if(a=='[' && b==']') return true;
    return false;
}

bool CheckOrder(char str[])
{
    int i=0;
    Stack S;
    initializeStack(&S);
    while(*(str+i) != '\0')
    {
        if(*(str+i) == '(' || *(str+i) == '{' || *(str+i) == '[')
            Push(&S,*(str+i));
        
        else if (*(str+i) == ')' || *(str+i) == '}' || *(str+i) == ']')
        {
            if(IsEmpty(S)) return false;

            if (CheckParanthesis(Top(&S),*(str+i))) 
                Pop(&S);
            else
                return false;
        }
        i++;
    }
    return (IsEmpty(S) ? true : false) ;
}

void main()
{
    printf("Enter a string : ");
    char str[50];
    scanf("%[^\n]s",str);
    (CheckOrder(str)) ? printf("Expression is balanced") : printf("Expression is not balanced");
}