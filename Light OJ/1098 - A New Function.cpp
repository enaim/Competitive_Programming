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
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld",&n);

        ll cnt = 1,i,x;
        ll sum= 0;
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
