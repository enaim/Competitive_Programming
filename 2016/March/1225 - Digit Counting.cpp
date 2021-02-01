#include<stdio.h>
#include<math.h>
#include<string.h>


int main()
{
    int N,t,r,i,temp,x;
    int cnt[15];

//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    scanf("%d",&t);
    r=0;
    while(r<t)
    {
        scanf("%d",&N);
        memset(cnt,0,sizeof cnt);
        for(i=1;i<=N;i++)
        {
            temp=i;
            while(temp != 0)
            {
                x=temp%10;
                cnt[x]++;
                temp=temp/10;
            }
        }
        for(i=0;i<10;i++)
        {
            if(i==9)
                printf("%d",cnt[i]);
            else
                printf("%d ",cnt[i]);
        }
        r++;
        printf("\n");
    }

    return 0;
}
