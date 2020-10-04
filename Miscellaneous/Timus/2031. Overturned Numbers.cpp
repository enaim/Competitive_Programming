#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    int n;
    while(1==scanf("%d",&n))
    {
        if(n==1)
            printf("16\n");
        else if(n==2)
            printf("16 06\n");
        else if(n==3)
            printf("16 06 68\n");
        else if(n==4)
            printf("16 06 68 88\n");
        else
            printf("Glupenky Pierre\n");
    }

    return 0;
}
