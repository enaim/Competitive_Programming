#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll m = 1000000007;
ll k,x,n;
ll dp[100010][3];

ll go(ll pos,ll prev)
{
    if(pos==n)
        return 1;

    ll &re = dp[pos][prev];

    if(re != -1)
        return re;

    re = 0;

    if(prev != 0 && 1 != x)
    {
        re +=(go(pos+1,0)%m);
        re %= m;
    }

    if(prev != 1 && pos != n-1 && 1 != x)
    {
        re += (go(pos+1,1)%m);
        re %= m;
    }

    if(prev != 0 && prev != 1 && 1 == x && pos != n-1)
    {
        re += (go(pos+1,0)%m);
        re %= m;
    }

    if(prev!=2 && 1!=x)
    {
        re += (((k-2)*(go(pos+1,2)%m))%m) ;
        re %= m;
    }
    else if(prev!=2 && 1==x)
    {
        re += (((k-1)*(go(pos+1,2)%m))% m);
        re%=m;
    }
    else if(1==x)
    {
        re += (((k-2)*(go(pos+1,2)%m))%m);
        re%=m;
    }
    else
    {
        re += (((k-3)*(go(pos+1,2)%m))%m);
        re%=m;
    }

    return re;
}


int main()
{
    while(3==scanf("%lld%lld%lld",&n,&k,&x))
    {
        memset(dp,-1,sizeof dp);
        ll ans = go(2,0);
        printf("%lld\n",ans);
    }

    return 0;
}
