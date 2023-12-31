/*
  Infix to Postfix conversion in C 
  Input expression must be in a valid/desired format. 
  Operands and operator, both must be single character.
  Only '+'  ,  '-'  , '*', '/' operators are expected. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MaxSize 10

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

bool IsOperand(char ch)
{
    if(ch >= 'a' && ch <= 'z') return true;
    if(ch >= 'A' && ch <= 'Z') return true;
    if(ch >= '1' && ch <= '9') return true;

    return false;
}

bool IsOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' )
        return true;
    return false;
}

bool CheckParanthesis(char a, char b)
{
    if(a=='(' && b==')') return true;
    if(a=='{' && b=='}') return true;
    if(a=='[' && b==']') return true;
    return false;
}

int Priority(char ch)
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

void Convert(char *str,int lenght,char * op)
{
    int i=0;
    int j=0;
    Stack S;
    initializeStack(&S);

    while(i<lenght)
    {
        if(IsOperand(str[i]))
        {
            op[j] = str[i];
            j++;
            i++;
        }

        else if (IsOperator(str[i]))
        {
            while (!IsEmpty(S) && IsOperator(Top(&S)) && ((Priority(str[i]))<=(Priority(Top(&S)))))
            {
                op[j] = Top(&S);
                Pop(&S);
                j++;
            }
            Push(&S,str[i]);
            i++;
        }

        else if (str[i]=='(' || str[i]=='{' || str[i]=='[')
        {
            Push(&S,str[i]);
            i++;
        }

        else if (str[i]==')' || str[i]=='}' || str[i]==']')
        {
            while(!CheckParanthesis(Top(&S),str[i]))
            {
                op[j] = Top(&S);
                Pop(&S);
                j++;
            }
            Pop(&S);
            i++;
        }
        
        else
            i++;
        
    }

    while(!IsEmpty(S))
    {
        op[j] = Top(&S);
        Pop(&S);
        j++;
    }

    op[j] = '\0';
}

int main()
{
    printf("Enter str1 : ");
    char str1[25] ;
    scanf("%[^\n]s",str1);

    char c;
    while (((c=getchar()) != '\n') && (c != EOF));

    printf("Enter str2 : ");
    // Use dynamic memory allocation for the input string
    char *str2 = NULL;
    size_t size = 0;
    getline(&str2, &size, stdin);

    char Output1[strlen(str1)];
    Convert(str1,strlen(str1),Output1);
    printf("%s\n",Output1);

    char Output2[strlen(str2)];
    Convert(str2,strlen(str2),Output2);
    printf("%s\n",Output2);

    //Free the dynamically allocated memory
    free(str2);

    return 0;
}