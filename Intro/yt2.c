#include<stdio.h>

// int main()
// {
//     int x = 5;
//     int *p = &x;
//     *p = 6;
//     int **q = &p;
//     int ***r = &q;

//     printf("%d \n",*p );
//     printf("%d \n",*q );
//     printf("%d \n",**q );
//     printf("%d \n",*r );
//     printf("%d \n",**r );
//     printf("%d \n",***r );
//     printf("\n");
//     ***r = 10;
//     printf("%d \n",x);
//     **q = *p + 45;
//     printf("%d \n",x);
//     return 0;
// }

// void main()
// {
//     int A[] = {2,3,4,5,8};
//     for(int i=0;i<5;i++)
//     {
//         printf("%d \n",A+i);
//         printf("%d \n",&A[i]);
//         printf("%d \n",A[i]);
//         printf("%d \n",*(A+i));
//         printf("\n");
//     }
// }

void main()
{
    int a[] = {1,2,3,4,5};
    int *p = a;

    printf("%d \n",*(p+2));
    printf("%d \n",*(a+2));
}
