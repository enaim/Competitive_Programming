#include<stdio.h>


int main()
{
    int i=0,j;

    for(i=1;i<=6;i++)
    {
        for(j=1;j<=6;j++)
            printf("%d-%d\t",i,j);
        printf("\n");
    }

    return 0;
}
