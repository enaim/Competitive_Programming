#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define OO         2e9+10
#define OOO        5e18+10
#define pb         push_back
#define nn         printf("\n")
#define sf(a)      scanf("%d",&a)
#define ssf(str)   scanf("%s",str)
#define pf(a)      printf("%d\n",a)
#define sl(a)      scanf("%lld",&a)
#define pl(a)      printf("%lld\n",a)
#define sf2(a,b)   scanf("%d%d",&a,&b)
#define pf2(a,b)   printf("%d %d\n",a,b)
#define sl2(a,b)   scanf("%lld%lld",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pl2(a,b)   printf("%lld %lld\n",a,b)
#define sl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)  {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define FasterIO   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MapPnt(a)  {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T sqr(T a){
    return a*a;
}
template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);

vector<ll>auction,normal;
ll vis[110];
ll ar[110];

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll i,n,m,x,sum;
    while(2==scanf("%lld%lld",&n,&m))
    {
        for(i=1;i<=n;i++)
            sl(ar[i]);
        for(i=1;i<=m;i++)
        {
            sl(x);
            vis[x]=1;
        }
        for(i=1;i<=n;i++)
        {
            if(vis[i]==0LL)
                normal.pb(ar[i]);
            else
                auction.pb(ar[i]);
        }
        sum = 0LL;
        ll sz = normal.size();
        for(i=0;i<sz;i++)
            sum+=normal[i];
        sz = auction.size();
        sort(auction.rbegin(),auction.rend());
        if(sum<=auction[0])
            sum = sum + auction[0];
        else
            sum = sum + sum;
        for(i=1;i<sz;i++)
            sum = sum+sum;
        pl(sum);
    }

    return 0;
}
