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

const int Size = 510;
vector<int>adj[Size],weight[Size];
int dis[Size];

struct node{
    int ndNmbr;
    int dist;

    node(int ndNmbr=0,int dist=0)
    {
        this->ndNmbr = ndNmbr;
        this->dist = dist;
    }

    bool operator < (const node& notMe)const{
        return notMe.dist<dist;
    }
};

void Dijkstra(int Source)
{
    priority_queue<node>pq;

    for(int i=0;i<Size;i++)
        dis[i]=OO;

    dis[Source]=0;
    pq.push(node(Source,0));

    while(!pq.empty())
    {
        node top = pq.top();
        pq.pop();

        int u = top.ndNmbr;

        if(dis[u]<top.dist)
            continue;

        int sz = adj[u].size();
        for(int i=0;i<sz;i++)
        {
            int v = adj[u][i];
            int w = weight[u][i];
            if(dis[v]>max(w,dis[u]))
            {
                dis[v]=max(w,dis[u]);
                pq.push(node(v,min(w,dis[u])));
            }
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,u,v,w,n,m,Source;
    scanf("%d",&tks);
    while(tks--)
    {
        for(i=0;i<Size;i++)
            adj[i].clear(),weight[i].clear();

        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            adj[u].pb(v);
            adj[v].pb(u);
            weight[u].pb(w);
            weight[v].pb(w);
        }
        scanf("%d",&Source);
        Dijkstra(Source);

        printf("Case %d:\n",ks++);
        for(i=0;i<n;i++)
        {
            if(dis[i]==OO)
                printf("Impossible\n");
            else
                printf("%d\n",dis[i]);
        }
    }

    return 0;
}
