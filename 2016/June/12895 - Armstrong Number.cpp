#include <stdio.h>
#include <string.h>
#include <math.h>

long long power(int x,int y)
{
    long long result = 1,i;
    for(i=1;i<=y;i++)
        result*=x;
    return result;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int ar[12];
    int n,temp,m,cnt,tks,i;
    long long sum;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        temp = n;

        cnt = 0;
        while(n != 0)
        {
            ar[cnt++] = n%10;
            n=n/10;
        }

        sum = 0;
        for(i=0;i<cnt;i++)
        {
            sum = sum + power(ar[i],cnt);
        }

        if(temp == sum)
            printf("Armstrong\n");
        else
            printf("Not Armstrong\n");
    }

    return 0;
}


