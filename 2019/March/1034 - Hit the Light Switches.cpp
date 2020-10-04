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

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

struct node{
    int ind,s,e,mark;
};
int cnt;
node ar[10010];
int deg[10010];
int vis[10010];
queue<int>Q;
vector<int>adj[10010],tadj[10010],component[10010];

bool compare(node a,node b)
{
    return a.e>b.e;
}

void dfs(int v)
{
    int i,sz,u;
    cnt++;
    ar[v].s = cnt;
    vis[v] = 1;
    sz = adj[v].size();
    for(i=0;i<sz;i++)
    {
        u = adj[v][i];
        if(vis[u]==0)
            dfs(u);
    }
    cnt++;
    ar[v].e = cnt;
}

void Tdfs(int v,int MARK)
{
    int i,sz,u;
    vis[v] = 1;
    ar[v].mark = MARK;
    component[MARK].pb(v);
    sz = tadj[v].size();
    for(i=0;i<sz;i++)
    {
        u = tadj[v][i];
        if(vis[u]==0)
            Tdfs(u,MARK);
    }
}

void traverse_dfs(int v)
{
    vis[v]=1;
    int sz = adj[v].size();
    for(int i=0;i<sz;i++)
    {
        int u = adj[v][i];
        if(vis[u]==0)
            traverse_dfs(u);
    }
}

void Topological_Sort()
{
    while(!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        int sz = component[v].size();
        int u = component[v][0];
        if(vis[u]==0)
            traverse_dfs(u);
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,j,n,m,u,v;
    scanf("%d",&tks);
    while(tks--)
    {
        for(i=1;i<=10000;i++)
            adj[i].clear(),tadj[i].clear(),component[i].clear();

        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            adj[u].pb(v);
            tadj[v].pb(u);
        }
        memset(vis,0,sizeof vis);
        cnt=0;
        for(i=1;i<=n;i++)
        {
            ar[i].ind = i;
            if(vis[i]==0)
                dfs(i);
        }
        sort(&ar[1],&ar[n+1],compare);
        memset(vis,0,sizeof vis);
        cnt = 1;
        for(i=1;i<=n;i++)
        {
            if(vis[ar[i].ind]==0)
                Tdfs(ar[i].ind,cnt),cnt++;       //Transpose DFS
        }
        memset(deg,0,sizeof deg);
        for(i=1;i<=n;i++)
        {
            int sz = adj[i].size();
            for(j=0;j<sz;j++)
            {
                u = i;
                v = adj[i][j];
                if(ar[u].mark != ar[v].mark)
                    deg[ar[v].mark]++;
            }
        }
        memset(vis,0,sizeof vis);
        int k = 0;
        for(i=1;i<cnt;i++)
            if(deg[i]==0)
            {
                Q.push(i);
                k++;
            }
        cnt = k;
        Topological_Sort();

        printf("Case %d: %d\n",ks++,cnt);
    }

    return 0;
}
