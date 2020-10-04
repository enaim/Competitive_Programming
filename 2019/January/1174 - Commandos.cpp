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

vector<int>adj[110];
int dis[110];
int dis1[110];
int par[110];
int flag[110];

struct node{
    int ndNmbr;
    int dist;
    node(int ndNmbr=0,int dist=0)
    {
        this->ndNmbr=ndNmbr;
        this->dist=dist;
    }
    bool operator<(const node& notMe)const{
        return notMe.dist<dist;
    }
};

void Dijkstra(int source)
{
    priority_queue<node>pq;

    for(int i=0;i<110;i++)
        dis[i]=OO;
    dis[source]=0;
    par[source]=-1;
    pq.push(node(source,0));

    while(!pq.empty())
    {
        node top=pq.top();
        pq.pop();
        int u = top.ndNmbr;
        if(dis[u]<top.dist)
            continue;
        int sz = adj[u].size();
        for(int i=0;i<sz;i++)
        {
            int v = adj[u][i];
            int w = dis[u]+1;
            if(dis[v]>w)
            {
                par[v]=u;
                dis[v]=w;
                pq.push(node(v,dis[v]));
            }
        }
    }
}

void Dijkstra_1(int source)
{
    priority_queue<node>pq;

    for(int i=0;i<110;i++)
        dis1[i]=OO;
    dis1[source]=0;
    pq.push(node(source,0));

    while(!pq.empty())
    {
        node top=pq.top();
        pq.pop();
        int u = top.ndNmbr;
        if(dis1[u]<top.dist)
            continue;
        int sz = adj[u].size();
        for(int i=0;i<sz;i++)
        {
            int v = adj[u][i];
            int w = dis1[u]+1;
            if(dis1[v]>w)
            {
                dis1[v]=w;
                pq.push(node(v,dis1[v]));
            }
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,n,m,s,d,u,v;
    scanf("%d",&tks);
    while(tks--)
    {
        for(i=0;i<110;i++)
        {
            adj[i].clear();
            flag[i]=0;
            par[i]=0;
        }

        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        scanf("%d%d",&s,&d);
        Dijkstra(s);
        Dijkstra_1(d);

        int mx = 0;
        for(i=0;i<n;i++)
            if(dis[i]!=OO)
                mx = max(mx,dis[i]);

        flag[s]=1;
        flag[d]=1;
        int x = par[d];
        while(x!=s && x!=-1)
        {
            flag[x]=1;
            x = par[x];
        }

        int mx1 = 0;
        for(i=0;i<n;i++)
            if(!flag[i] && dis1[i]!=OO)
                mx1 = max(mx1,dis1[i]-(mx-dis[i]));

        printf("Case %d: %d\n",ks++,mx+mx1);
    }

    return 0;
}
