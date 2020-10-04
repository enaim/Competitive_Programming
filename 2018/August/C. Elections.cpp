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
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

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

struct vote{
    ll ind,cost;
};

bool compare(vote a,vote b)
{
    return a.cost<b.cost;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll i,j,k,n,m,mn,cnt,temp,a,b,val;
    ll ans[3010],flag[3010],sz[3010];
    vote ar[3010];
    while(2==scanf("%lld%lld",&n,&m))
    {
        vector<ll>vec[3010];
        memset(sz,0,sizeof sz);
        for(i=1;i<=n;i++)
        {
            scanf("%lld%lld",&a,&b);
            sz[a]++;
            ar[i].ind = a;
            ar[i].cost = b;
        }

        sort(&ar[1],&ar[n+1],compare);

        for(i=1;i<=n;i++)
            vec[ar[i].ind].pb(i);

        for(i=1;i<=n;i++)
        {
            val = 0;
            cnt = 0;
            memset(flag,0,sizeof flag);
            for(k=0;k<sz[1];k++)
            {
                flag[vec[1][k]]++;
                cnt++;
            }
            for(j=2;j<=m;j++)
            {
                if(sz[j]>=i)
                {
                    for(k=0;k<sz[j]-i+1;k++)
                    {
                        val += ar[vec[j][k]].cost;
                        flag[vec[j][k]]++;
                        cnt++;
                    }
                }
            }
            if(cnt<i)
            {
                for(k=1;k<=n;k++)
                {
                    if(flag[k]==0 && cnt<i)
                    {
                        cnt++;
                        val+=ar[k].cost;
                    }
                }
            }

            ans[i]=val;
        }
        mn = 1e18;
        for(i=1;i<=n;i++)
        {
            mn = min(mn,ans[i]);
        }
        printf("%lld\n",mn);
    }

    return 0;
}
