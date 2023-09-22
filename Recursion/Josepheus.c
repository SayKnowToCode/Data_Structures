#include<stdio.h>

int jos(int n,int k)
{
    if(n==1)
        return 0;

    return (jos(n-1,k)+k)%n;
}

int main()
{
    int n=4,k=8;
    printf("%d",jos(n,k) + 1);
    return 0;
}
