#include<stdio.h>


int main()
{
    int tks,i,n,s,sum,cnt;
    int ar[100];
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&n,&s);
        sum = 0;
        cnt = 0;
        for(i=n;i<=s;i++)
        {
            ar[cnt] = (2 * n * n) + 1;
            sum += ar[cnt];
            n++;
            cnt++;
        }
        printf("%d %d %d\n",ar[0],ar[cnt-1],sum);
    }

    return 0;
}
