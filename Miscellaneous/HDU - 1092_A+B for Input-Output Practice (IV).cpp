#include<stdio.h>


int main()
{
    int x,n,sum,i;
    while(1==scanf("%d",&n) && n)
    {
        sum = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            sum = sum + x;
        }
        printf("%d\n",sum);
    }

    return 0;
}
