#include<stdio.h>


int main()
{
    int cnt=1,T,n,x,sum,i;
    while(scanf("%d",&T)==1)
    {
        while(cnt<=T)
        {
            scanf("%d",&n);
            sum = 0;
            for(i=0;i<n;i++)
            {
                scanf("%d",&x);
                sum+=x;
            }
            if(cnt == T)
                printf("%d\n",sum);
            else
                printf("%d\n\n",sum);
            cnt++;
        }
    }

    return 0;
}
