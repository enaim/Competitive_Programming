#include<stdio.h>


int main()
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("for: %d\n",i);
    }


    i=0;
    while(i<5)
    {
        printf("while: %d\n",i);

        i++;
    }


    return 0;
}
