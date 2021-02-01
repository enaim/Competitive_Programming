#include<stdio.h>


int main()
{
    int x,n,sum,i,cnt=0,t;
    scanf("%d",&t);
    while(cnt<t)
    {
        scanf("%d",&n);
        sum = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            sum = sum + x;
        }
        printf("%d\n",sum);
        cnt++;
    }

    return 0;
}
