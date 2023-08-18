#include <stdio.h>

void print(char *);

int main()
{
    char c[20] = "Hello";
    print(c);
    return 0;
}

void print(char *c) // if we pass const char *c as argument we can only read the string not write it
{
    c[0] = 'A';
    while (*c != '\0')
    {
        printf("%c",*c);
        c++;
    }
    printf("\n");
}