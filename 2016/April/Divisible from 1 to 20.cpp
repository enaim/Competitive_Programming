#include<stdio.h>


int main()
{

    int i=1;

    while(1)
    {
        if(i%11==0 && i%12==0 && i%13==0
        && i%14==0 && i%15==0 && i%16==0
        && i%17==0 && i%18==0 && i%19==0
        && i%20==0)
        {
            printf("%d\n", i);
            return 0;
        }

        i++;
    }

    return 0;
}

