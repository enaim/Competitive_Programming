#include<stdio.h>
int main()
{
    int n,i,j,digit,t,temp;
    while(scanf("%d",&t)==1)
    {
        for(i=1; i<=t; i++)
            for(j=1; j<=t; j++)
            {
                if(i%j==0)
                    if(i*j>t)
                        if(i/j<t)
                        {
                            printf("%d %d\n",i,j);
                            return 0;
                        }
            }
        printf("-1\n");

    }
    return 0;
}
