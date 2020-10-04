#include <stdio.h>
#include <string.h>
#include <math.h>

long long dp[1000][1000];

long long nCr(long long n,long long r)
{
    if(n<r ) return 0;
    if(r==0) return 1;

    long long &ret = dp[n][r];

    if(ret>-1)  return ret;

    ret = nCr(n-1,r-1)+nCr(n-1,r);

    return ret;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    long long n,r;

//    memset(dp,0,sizeof dp);
    memset(dp,-1,sizeof dp);

    while(2==scanf("%lld%lld",&n,&r))
    {
        printf("%lld\n",nCr(n,r));
    }

    return 0;
}

