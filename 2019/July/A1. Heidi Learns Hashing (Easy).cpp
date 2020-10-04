#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll func1(ll x,ll r)
{
    return (r-(x*x)-x-1)/(2*x);
}

ll func2(ll x,ll y)
{
    return x*x + 2*x*y + x + 1;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    ll r,y,i;
    while(scanf("%lld",&r)==1)
    {
        ll sq = sqrt(r);
        int f = 0;
        for(i = 1;i<sq;i++)
        {
            y = func1(i,r);
            if(y<=0)
                continue;
            if(func2(i,y)==r)
            {
                f = 1;
                break;
            }
        }
        if(f)
            printf("%lld %lld\n",i,y);
        else
            printf("NO\n");
    }

    return 0;
}
