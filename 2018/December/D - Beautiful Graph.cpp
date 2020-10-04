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

const int Size = 300010;
const long long M = 998244353;

long long BigMod(long long b,long long p)
{
    long long x;

    if(p==0)
        return 1;

    x = BigMod(b,p/2);
    x = (x*x) % M;

    if(p%2 != 0)
        x=(x*b)%M;

    return x;
}

bool sign;
ll cnt,ans;
vector<ll>vv,vec[Size];
ll sz[Size];
ll vis[Size];
ll vis1[Size];
ll flag[Size];
ll flag1[Size];

void dfs(ll u)
{
    int i;
    for(i=0;i<sz[u];i++)
    {
        ll v = vec[u][i];
        if(vis[v]==0)
        {
            vis[v]=1;
            if(flag[u]==1)
                flag[v]=2;
            else
                flag[v]=1,cnt++;
            dfs(v);
        }
        if(flag[u]==flag[v])
            sign = 1;
    }
}

void dfss(ll u)
{
    int i;
    for(i=0;i<sz[u];i++)
    {
        ll v = vec[u][i];
        if(vis1[v]==0)
        {
            vis1[v]=1;
            if(flag1[u]==1)
                flag1[v]=2;
            else
                flag1[v]=1,cnt++;
            dfss(v);
        }
        if(flag1[u]==flag1[v])
            sign = 1;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    ll n,m,i,u,v;
    scanf("%d",&tks);
    while(tks--)
    {
        vv.clear();
        scanf("%lld%lld",&n,&m);
        if(m==0)
        {
            printf("%lld\n",BigMod(3,n)%M);
            continue;
        }
        for(i=1;i<=m;i++)
        {
            scanf("%lld%lld",&u,&v);
            vec[u].pb(v);
            vec[v].pb(u);
            sz[u]++;
            sz[v]++;
        }
        for(i=1;i<=n;i++)
        {
            ans = 1;
            if(vis[i]==0 && sz[i])
            {
                ans = 1;
                vis[i]=1;
                cnt = 1;
                flag[i]=1;
                sign = 0;
                dfs(i);
                if(sign==0)
                {
                    ans = (BigMod(2LL,cnt)%M);
                    ans%=M;
                }
                else
                    ans = 0;

                vis1[i]=1;
                cnt = 0;
                flag1[i]=2;
                sign = 0;
                dfss(i);
                if(sign==0)
                {
                    ans = (ans%M) + (BigMod(2LL,cnt)%M);
                    ans%=M;
                }
                else
                    ans = 0;
                vv.pb(ans);
            }
        }
        for(i=1;i<=n;i++)
        {
            if(vis[i]==0)
                vv.pb(3);
        }
        ans = 1;
        sign = 0;
        for(auto it: vv)
        {
            ans = (ans%M)*(it%M);
            ans%=M;
            if(it==0)
                sign = 1;
        }

        if(sign==0)
            printf("%lld\n",ans);
        else
            printf("0\n");
        for(i=1;i<=n;i++)
        {
            vec[i].clear();
            sz[i]=0;
            vis[i]=0;
            vis1[i]=0;
            flag[i]=0;
            flag1[i]=0;
        }
    }

    return 0;
}
