// To reverse a string using Stack

#include<stdio.h>
#include<stdbool.h>

#define MaxSize 100

static char A[MaxSize];
static int top = -1;

void Push(char data)
{
    if(top == MaxSize)
    {
        printf("Error : Stack Overflow");
        return ;
    }
    A[++top] = data;
}

void Pop()
{
    if(top == -1)
    {
        printf("Error : Stack Empty");
        return;
    }
    top -- ;
}

char Top()
{
    return A[top];
}

bool IsEmpty()
{
    if(top == -1)
        return true;
    else
        return false;
}

void main()
{
    char str[50];
    printf("Enter a string : ");
    scanf("%[^\n]s",str);
    int i=0;
    while(str[i] != '\0')
    {
        Push(str[i]);
        i++;
    }
    i=0;
    while((str[i] != '\0')&&(!IsEmpty()))
    {
        str[i] = Top();
        Pop();
        i++;
    }
    printf("%s",str);
}