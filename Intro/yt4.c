#include<stdio.h>

int sumOfElements1(int A[],int size)
{
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum += A[i];
    }
    return sum;
}

int sumOfElements2(int A[])
{
    int size = sizeof(A)/sizeof(A[0]);
    printf("%d %d %d \n",sizeof(A),sizeof(A[0]),size);
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum += A[i];
    }
    return sum;
}

void main()
{
    int A[] = {1,2,3,4,5};
    int size = sizeof(A)/sizeof(A[0]);
    printf("%d %d %d \n",sizeof(A),sizeof(A[0]),size);
    printf("%d \n",sumOfElements1(A,size));
    printf("%d \n",sumOfElements2(A));
}

/* Array always passed by reference so when we pass A we only pass &A[0] and any change made in the called function
   sumOfElements() will be reflected in the calling function main() */ 