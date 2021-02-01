#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll func(ll m,ll n)
{
    return ((n*(n+1)/2)-((m*(m-1))/2));
}

ll n,sum;

int main()
{
    int tks,ks=1;
    while(scanf("%lld",&n)==1 && n)
    {
        ll cnt = 1,i,x;
        ll sum= 0LL;
        for(i=2;i<=n/i;i++)
        {
            cnt++;
            x = n/i;
            sum += func(i,n/i);
            sum+=(x-cnt)*i;
        }

        printf("Case %d: %lld\n",ks++,sum);
    }

    return 0;
}
