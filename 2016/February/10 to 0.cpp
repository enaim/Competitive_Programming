#include <stdio.h>
#include <string.h>
#include <math.h>

#define SZ 50
long long dp[SZ];

long long fun(long long n)
{
    if(n==0)        return 1;
    else if(n<0)    return 0;

    long long ret=0;

    if(dp[n]!=-1)
    {
        return dp[n];
    }

    for(int i=1;i<4;i++)
    {
        ret+=fun(n-i);

    }

    dp[n]=ret;
    return ret;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    long long n;

    for(int i=1;i<SZ;i++)
    {
        dp[i]=-1;
    }

    while(1==scanf("%lld",&n))
    {
        n=fun(n);
        printf("Total Way : %lld\n",n);
    }

    return 0;
}
