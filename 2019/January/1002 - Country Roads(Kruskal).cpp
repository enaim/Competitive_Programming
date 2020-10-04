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

const int Size = 16010;

int cnt,V,E;
int par[Size];
int rnk[Size];
int vis[Size];
int cost[Size];
vector<int>adj[Size],wei[Size];

struct edge{
    int u,v,w;
};
edge ar[Size];

struct src{
    int from,to,weight;
};
src A[Size];

bool compare(edge a,edge b)
{
    return a.w<b.w;
}

int Find_Set(int x)
{
    if(x!=par[x])
        par[x] = Find_Set(par[x]);
    return par[x];
}

void Link(int x,int y)
{
    if(rnk[x]>rnk[y])
        par[y]=x;
    else
    {
        par[x]=y;
        if(rnk[x]==rnk[y])
            rnk[y]++;
    }
}

void Union(int x,int y)
{
    Link(Find_Set(x),Find_Set(y));
}

void Make_Set(int x)
{
    rnk[x]=0;
    par[x]=x;
}

void MST_Kruskal()
{
    for(int i=0;i<Size;i++)
        Make_Set(i);
    sort(&ar[0],&ar[E],compare);
    cnt = 0;
    for(int i=0;i<E;i++)
    {
        if(Find_Set(ar[i].u) != Find_Set(ar[i].v))
        {
            A[cnt].from = ar[i].u;
            A[cnt].to = ar[i].v;
            A[cnt].weight = ar[i].w;
            cnt++;
            Union(ar[i].u,ar[i].v);
        }
    }
}

void dfs(int u,int mx)
{
    vis[u]=1;
    int sz = adj[u].size();
    for(int i=0;i<sz;i++)
    {
        int v = adj[u][i];
        int w = wei[u][i];
        if(vis[v])
            continue;
        cost[v]=max(w,mx);
        dfs(v,cost[v]);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,s;
    scanf("%d",&tks);
    while(tks--)
    {
        for(i=0;i<Size;i++)
        {
            adj[i].clear();
            wei[i].clear();
            cost[i]=-1;
            vis[i]=0;
        }
        scanf("%d%d",&V,&E);
        for(i=0;i<E;i++)
            scanf("%d%d%d",&ar[i].u,&ar[i].v,&ar[i].w);
        scanf("%d",&s);

        MST_Kruskal();
        for(i=0;i<min(V-1,cnt);i++)
        {
            adj[A[i].from].pb(A[i].to);
            adj[A[i].to].pb(A[i].from);
            wei[A[i].from].pb(A[i].weight);
            wei[A[i].to].pb(A[i].weight);

        }
        dfs(s,0);

        printf("Case %d:\n",ks++);;
        for(i=0;i<V;i++)
        {
            if(i==s)
                printf("0\n");
            else if(cost[i]==-1)
                printf("Impossible\n",cost[i]);
            else
                printf("%d\n",cost[i]);
        }
    }

    return 0;
}
