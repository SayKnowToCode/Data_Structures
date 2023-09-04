#include<stdio.h>

int Max(int a,int b)
{
    if(a>b) return a;
    else if (b>a) return b;
    else return a;  
}

int Cut(int n,int a,int b,int c)
{
    if(n==0) return 0;
    if(n < 0) return -1;

    int x = Cut(n-a,a,b,c);
    int y = Cut(n-b,a,b,c);
    int z = Cut(n-c,a,b,c);

    if(x==-1 && y==-1 && z==-1)
        return -1;

    return (Max(Max(x,y),z) + 1);
}

int main()
{
    int n = 5;
    int a = 2;
    int b = 5;
    int c = 1;
    printf("Maximum possible cuts = %d",Cut(n,a,b,c));
    return 0;
}