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

ll ar[200010],cost[200010],deg[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll i,v,n,mn,ans;
    while(1==scanf("%lld",&n))
    {
        memset(deg,0,sizeof deg);
        for(i=1;i<=n;i++)
            scanf("%lld",&cost[i]);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&ar[i]);
            deg[ar[i]]++;
        }
        queue<ll>Q;
        for(i=1;i<=n;i++)
        {
            if(deg[i]==0)
                Q.push(i);
        }
        while(!Q.empty())
        {
            ll v = Q.front();
            Q.pop();
            deg[ar[v]]--;
            if(deg[ar[v]]==0)
                Q.push(ar[v]);
        }
        ans = 0;
        for(i=1;i<=n;i++)
        {
            if(deg[i]==0)
                continue;
            v = i;
            mn = OO;
            while(deg[v]!=0)
            {
                deg[v] = 0;
                mn = min(mn,cost[v]);
                v = ar[v];
            }
            ans+=mn;
        }
        printf("%lld\n",ans);
    }

    return 0;
}
