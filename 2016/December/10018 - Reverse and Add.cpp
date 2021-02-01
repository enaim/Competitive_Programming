#include<stdio.h>


bool palendrom(long long p)
{
    long long ar[25];
    long long c=0,x,i;
    while(p!=0)
    {
       ar[c++]=p%10;
       p/=10;
    }
    x=0;
    for(i=0;i<c/2;i++)
    {
        if(ar[i] != ar[c-1-i])
            x=1;
    }

    if(x==0)
        return false;
    return true;

}

long long rev(long long temp)
{
    long long sum=0;
    while(temp!=0)
        {
            sum=(sum*10)+(temp%10);
            temp=temp/10;
        }
    return sum;
}


int main()
{
    long long tks,p,cnt;
    scanf("%lld",&tks);

    while(tks--)
    {
        scanf("%lld",&p);
        cnt = 0;

        while(palendrom(p))
        {
            p = p + rev(p);
            cnt++;
        }

        printf("%lld %lld\n",cnt,p);
    }

    return 0;
}
