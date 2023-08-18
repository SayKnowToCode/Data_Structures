#include<stdio.h>

int k=0;

int compare(int a,int b)
{
    if(a>b) return 1;
    else return -1;
}

void BubbleSort(int A[],int n, int (*ptr)(int,int))
{
    int i,j,temp=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(ptr(A[j],A[j+1]) > 0)
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

void main()
{
    int A[] = {3,5,2,1,4,6};
    BubbleSort(A,6,compare);
    
    for(int i=0;i<6;i++)
    {
        printf("%d ",A[i]);
    }
}