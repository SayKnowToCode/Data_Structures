#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n;
    scanf("%d",&n);
    int *p = (int *)malloc(n*sizeof(int));
    // int *p = (int *)calloc(n,sizeof(int));
    for(int i=0;i<n;i++)
    {
        p[i] = i+1;
    }
    free(p);
    //p = NULL;
    for(int i=0;i<n;i++)
    {
        printf("%d ",p[i]);
    }
}