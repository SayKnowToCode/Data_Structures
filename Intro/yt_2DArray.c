#include<stdio.h>

void main()
{
    int B[2][3] = {{2,3,6},{4,5,8}};
    int (*p)[3] = B;   //int *p = B; This is not allowed 
    

    printf("%d \n",B);
    printf("%d \n",*B);
    printf("%d \n",B+1);
    printf("%d \n",B+2);
    printf("%d \n",*(B+1));
    printf("%d \n",*(B+1)+2);
    printf("%d \n",*(*B));
    printf("%d \n",*B+1);
    printf("%d \n",*(*(B+1)+1));

    printf("%d \n",p);
    printf("%d \n",*p);
    printf("%d \n",p+1);
    printf("%d \n",p+2);
    printf("%d \n",*(p+1));
    printf("%d \n",*(p+1)+2);
    printf("%d \n",*(*p));
    printf("%d \n",*p+1);
    printf("%d \n",*(*(p+1)+1));
}