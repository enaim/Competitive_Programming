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

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<ll,ll>pii;

template<class T> T abs(T x)
{
    if(x<0) return -x;
    return x;
}
template<class T>T sqr(T a)
{
    return a*a;
}
const long long  M =1e9+7;
const double pi = acos(-1.0);
const double eps = 1e-8;

const ll Size = 100010;
vector<ll>adj[Size],vec,ve;

ll vis[Size];
ll ar[Size];
ll cnt;

void dfs(ll u)
{
    ll i,v;
    vis[u]=1LL;
    ll sz = adj[u].size();
    for(i=0; i<sz; i++)
    {
        v = adj[u][i];
        if(vis[v]==0LL)
        {
            vis[v]=1LL;
            cnt++;
            dfs(v);
        }
    }
}

void func()
{
    ll n,m,i,s,u,v;
    scanf("%lld%lld",&n,&m);

    for(i=0; i<m; i++)
    {
        scanf("%lld%lld",&u,&v);
        adj[u].pb(v);
        ar[v]++;
    }
    for(i=1;i<=n;i++)
    {
        if(ar[i]==0LL)
            ve.pb(i);
    }
    s = ve.size();
    for(i=0; i<s; i++)
    {
        cnt=1;
        ll t = ve[i];
        if(vis[t]==0LL)
        {
            dfs(t);
            vec.pb(cnt);
        }
    }

}

ll bigmod(ll a,ll b)
{
    ll res = 1,x;
    x = a%M;
    while(b)
    {
        if(b&1)
            res = (res*x)%M;
        x = (x*x)%M;
        b>>=1;
    }
    return res;
}

ll invmod(ll a)
{
    return bigmod(a,M-2);
}

ll Need(ll maxi, ll mini)
{
   // cout<<"N  "<<maxi<<"  "<<mini<<endl;
    ll divident=1LL,divider=1LL;
    for(ll i=maxi+1; i<=(maxi+mini); i++) divident=(divident*i)%M;

    for(ll i=2; i<=mini; i++) divider=(divider*i)%M;

    return (divident*invmod(divider))%M;
}

void Solve()
{
   // cout<<"GGG"<<endl;
    sort(vec.begin(),vec.end());
    ll ans=1LL;
    ll a=vec[0],b=0LL;
    for(ll i=1LL; i<(ll)vec.size(); i++)
    {
        b=vec[i];
        ans =( ans*Need(max(a,b),min(a,b)) )%M;
        a=a+b;
    }
    printf("%lld\n",ans);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    func();
    if((int)vec.size() == 1)
    {
        printf("1\n");
    }
    else Solve();

    return 0;
}
/*
4 2
1 2
3 4
*/
