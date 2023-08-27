#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct 
{
    int top;
    unsigned size;
    char *A;
}Stack;

Stack *createStack(unsigned size)
{
    Stack *S = (Stack *)malloc(sizeof(Stack));
    S->top = -1;
    S->A = (char *)malloc(size * sizeof(char));
    return S;
}

bool isFull(Stack *S)
{
    if(S->top == S->size - 1) return true;
    return false;
}

bool isEmpty(Stack *S)
{
    if(S->top == -1) return true;
    return false;
}

void Push(Stack *S,int data)
{
    if(isFull(S))
    {
        printf("Stack Overflow !!");
        return;
    }
    S->A[++(S->top)] = data;
}

void Pop(Stack *S)
{
    if(isFull(S))
    {
        printf("Stack Overflow !!");
        return;
    }
    --(S->top) ;
}

char Top(Stack *S)
{
    return S->A[S->top];
}

bool isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/') return true;
    return false;
}

bool isOperand(char ch)
{
    if(ch>='a' && ch<='z') return true;
    if(ch>='A' && ch<='Z') return true;
    if(ch>='1' && ch<='9') return true;
    return false;
}

int Priority(char op)
{
    switch (op)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return 0;
}

bool checkParenthesis(char a, char b)
{
    if(a=='(' && b==')') return true;
    if(a=='{' && b=='}') return true;
    if(a=='[' && b==']') return true;
    return false;
}

void Convert(char *str, int length, char *op)
{
    Stack *S = createStack(length);
    int i=0;
    int j=0;

    while(str[i] != '\0')
    {
        if(isOperand(str[i]))
        {
            op[j] = str[i];
            j++;
            i++;
        }

        else if (isOperator(str[i]))
        {
            while(!isEmpty(S) && isOperator(Top(S)) && (Priority(str[i]) < Priority(Top(S))))
            {
                op[j] = Top(S);
                Pop(S);
                j++;
            }
            Push(S,str[i]);
            i++;
        }

        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            Push(S,str[i]);
            i++;
        }

        else if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            while (checkParenthesis(str[i],Top(S)) == false)
            {
                op[j] = Top(S);
                Pop(S);
                j++;
            }
            Pop(S);
            i++;           
        }

        else
            i++;
           
    }

    while (!isEmpty(S))
    {
        op[j] = Top(S);
        Pop(S);
        j++;
    }

    op[j] = '\0';
    
}

int main()
{
    printf("Enter the infix expression : ");
    char *str = NULL;
    size_t size = 0;
    getline(&str,&size,stdin);
    strcpy(str,strrev(str));

    char op[strlen(str)];
    Convert(str,strlen(str),op);

    printf("The prefix expression is : %s",strrev(op));
    // Dont forget to reverse op !!!!!!!

    free(str);
    return 0;
}