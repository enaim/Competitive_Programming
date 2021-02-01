#include <stdio.h>
#include <string.h>
#include <math.h>


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int cnt[25];
    int tks,ks=1,n,x,y;

    scanf("%d",&tks);
    memset(cnt,0,sizeof cnt);

    while(tks--)
    {
        scanf("%d",&n);

        if(n==0)
            printf("0 0\n");
        else if(n<=10)
        {
            printf("%d %d\n",0+cnt[n],n-cnt[n]);
            cnt[n]++;
        }
        else
        {
            x=10;
            y=n - x;
            printf("%d %d\n",y+cnt[n],x-cnt[n]);
            cnt[n]++;
        }
    }

    return 0;
}
