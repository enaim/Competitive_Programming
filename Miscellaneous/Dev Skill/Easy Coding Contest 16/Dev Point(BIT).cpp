#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

typedef long long ll;
typedef pair<int,int>pii;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}
template<class T>T sqr(T a){
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;
const int SIZE = 100010;

ll n;
ll ar[SIZE];
ll BIT[SIZE];
ll sum[SIZE];

void update(ll index,ll v)
{
    while(index<=n)
    {
        BIT[index] += v;
        index += index &- index;
    }
}

ll Query(ll index)
{
    ll ans = 0;
    while(index>0)
    {
        ans += BIT[index];
        index -= index &- index;
    }
    return ans;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll i,e,s,x,t,v,tks,m,q,y,ks=1;
    scanf("%lld",&tks);
    while(tks--)
    {
        memset(BIT,0,sizeof BIT);
        printf("Case %lld:\n",ks++);
        scanf("%lld%lld%lld",&n,&m,&q);

        for(i=1;i<=n;i++)
            scanf("%lld",&ar[i]);

        sum[0]=0;
        for(i=1;i<=m;i++)
        {
            scanf("%lld",&x);
            sum[i] = sum[i-1] + x;
        }
        for(i=1;i<=n;i++)
        {
            update(i,ar[i]);
            update(i+1,-ar[i]);
        }

        while(q--)
        {
            scanf("%lld%lld",&x,&y);
            scanf("%lld%lld",&s,&e);
            update(s,sum[y]-sum[x-1]);
            update(e+1,-(sum[y]-sum[x-1]));
        }

        for(i=1;i<=n;i++)
        {
            ll ans = Query(i);
            if(i==n)
                printf("%lld\n",ans);
            else
                printf("%lld ",ans);
        }
    }

    return 0;
}
