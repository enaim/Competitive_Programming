#include<bits/stdc++.h>
using namespace std;

long long ar[200010];
long long dp[200010][2];
int n;

long long go(int pos,int k)
{
    if(pos>(2*n)-1)
        return 0;
    long long &re = dp[pos][k];

    if(re != -1)
        return re;

    re = 0;
    if(k==0)
    {
        if(pos&1)
            re = max(re,ar[pos]+go(pos+1,1));
        re = max(re,go(pos+1,0));
    }
    else
    {
        if(pos%2==0)
            re = max(re,ar[pos]+go(pos+2,0));
        re = max(re,go(pos+1,1));
    }

    return re;
}

int main()
{
    int i;
    while(scanf("%d",&n)==1)
    {
        memset(dp,-1,sizeof dp);
        for(i=0;i<n;i++)
            scanf("%lld",&ar[i*2]);
        for(i=0;i<n;i++)
            scanf("%lld",&ar[i*2+1]);
        printf("%lld\n",max(go(0,0),go(0,1)));
    }

    return 0;
}
