#include<stdio.h>

void TOH(int n,char *Start,char *Spare,char *Destination)
{
    if(n==1)
    {
        printf("Move 1 from %s to %s\n",Start,Destination);
        return;
    }
    TOH(n-1,Start,Destination,Spare);
    printf("Move %d from %s to %s\n",n,Start,Destination);
    TOH(n-1,Spare,Start,Destination); 
}

int main()
{
    int n=2;
    TOH(n,"Start","Spare","Destination");
    return 0;
}