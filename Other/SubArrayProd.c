#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

void Sort(int arr[],int n)
{
    int i, j;  
    for (i = 0; i < n - 1; i++) 
    {  
        for (j = 0; j < n - i - 1; j++) 
        {  
            if (arr[j] > arr[j + 1]) 
            {  
                int temp = arr[j];  
                arr[j] = arr[j + 1];  
                arr[j + 1] = temp;  
            }  
        }  
    } 
}  


void main()
{
    int a[] = {-1,-1,-1,-1};
    int *b,prod=1;

    int i,j=0,c=0,flag;
    int length = sizeof(a)/sizeof(a[0]);
    for(i=0;i<length;i++)
    {
        if(a[i]==0 || a[i]==1)
        {
            if(a[i]==1)
                c = 1;

            continue;
        }
        
        else if (a[i] > 0)
        {
            prod = prod * a[i];
            c++;
        }

        else
        {
            b[j] = a[i];
            j++;
        }
    }
    i=0;
    if(j%2 == 0)
    {
        while (i<j)
        {
            prod = prod * (abs(b[i]));
            i++;
            c++;
        }    
    }
    else
    {
        Sort(b,j);
        while (i<j-1)
        {
            prod = prod * (abs(b[i]));
            i++;
            c++;
        }  
    }
    if(c==0)
        prod = 0;
    
    printf("The product is %d\n",prod);
    printf("Number of elements used = %d",c);
}