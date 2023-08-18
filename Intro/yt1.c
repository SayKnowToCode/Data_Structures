#include<stdio.h>

void main()
{
    int a = 1025;
    int *p;
    p = &a;
    printf("Size of integer is %d bytes\n",sizeof(int));
    printf("Address = %d, Value = %d\n",p,*p);
    printf("Address = %d, Value = %d\n",p+1,*(p+1));
    char *c;
    // c = p; // Compilation Error(Warning actually)
    c = (char*)p; // type casting
    printf("Size of character is %d bytes\n",sizeof(char));
    printf("Address = %d, Value = %d\n",c,*c);
    printf("Address = %d, Value = %d\n",c+1,*(c+1));
}

// void main()
// {
//     int a = 1025;
//     int *p;
//     p = &a;
//     printf("Size of integer is %d bytes\n",sizeof(int));
//     printf("Address = %d, Value = %d\n",p,*p);
//     // Void Pointer - Generic Pointer
//     void *p0;
//     p0 = p;
//     // printf("Address = %d, Value = %d\n",p0,*p0); // Compilation error due to *p0
//     printf("Address = %d");
//     //p0+1 also not possible
// }

