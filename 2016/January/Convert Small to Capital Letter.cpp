#include <stdio.h>
#include <string.h>
#include <math.h>


bool isUpperCase(char c){return 'A'<=c && c<= 'Z';}

int main()
{
    char n[100];
    int i='A';

    while(gets(n))
    {
        for(i=0;n[i]>0;i++)
        {
            n[i]-=32;
//            printf("%d -> %c\n",n[i],n[i]);
        }
        printf("%s\n",n);
    }

    return 0;
}


