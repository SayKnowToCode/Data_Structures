#include<stdio.h>

void increment(int *p)
{
    *p += 1;
}

void main()
{
    int a=10;
    increment(&a);
    printf("%d\n",a);
}