#include <stdio.h>
#include <stdlib.h>

int *p;

void printHello(char *name)
{
    printf("Hello %s\n",name);
}

int *Add(int *a, int *b) // declaring a function that would return int *
{
    p = (int *)malloc(sizeof(int));
    // int c = *a + *b;
    *p = *a + *b;
    return p;
    // return &c;
}

int Sum(int a, int b)
{
    return a+b;
}

// void main()
// {
//     int a=2,b=4;
//     int *ptr = Add(&a,&b);
//     printHello();
//     printf("Sum = %d",*ptr);
//     free(p);
// }

int main()
{
    int (*p)(int,int);    // declaring a function pointer - parenthesis for p is important
    p = &Sum;             // p = Sum also valid
    int c = (*p)(2,3);    // c = p(2,3) also valid
    printf("%d ",c);
    void (*ptr)(char *) = printHello;
    ptr("Ninad Maadhavi");
    return 0;
}