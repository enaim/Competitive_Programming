#include<stdio.h>


int main()
{
    int ar[10];
    int tks,ks=1,n,i,cnt;

    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        cnt = 0;
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                ar[cnt]=i;
                cnt++;
            }
            if(cnt==2)
                break;
        }
        printf("Case #%d: %d = %d * %d = %d * %d\n",ks++,n,ar[0],n/ar[0],ar[1],n/ar[1]);
    }

    return 0;
}
