#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

const int SIZE_V = 20010;

vector<int> adj[SIZE_V],weight[SIZE_V];
int dis[SIZE_V];
int V,E;

struct node{
    int ndNmbr;
    int dist;

     node(int ndNmbr=0,int dist=0){
        this->ndNmbr = ndNmbr;
        this->dist = dist;
    }

    bool operator < (const node& notMe)const {
        return dist > notMe.dist;
    }
};

void Dijkstra(int Source)
{
    priority_queue<node>pq;

    for(int i=0;i<V;i++)
        dis[i] = OO;

    dis[Source] = 0;
    pq.push(node(Source,0));

    while(!pq.empty())
    {
        node top = pq.top();
        pq.pop();

        int u = top.ndNmbr;

        if(dis[ u] <top.dist)   continue;

        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            int w = weight[u][i];
            int currentCalculatedDistance = w + dis[u];

            if(dis[v] > currentCalculatedDistance)
            {
                dis[v] = currentCalculatedDistance;
                pq.push(node( v, currentCalculatedDistance));
            }
        }
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,u,v,w;
    int Source,t,T,k=1;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&V,&E,&Source,&t);

        for(i=0;i<V;i++)
            weight[i].clear();

        for(i=0;i<V;i++)
            adj[i].clear();

        for(i=1;i<=E;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            adj[u].pb(v);
            adj[v].pb(u);
            weight[u].pb(w);
            weight[v].pb(w);
        }

        if(E > 0)
            Dijkstra(Source);


        if(dis[t] < OO && E != 0)
            printf("Case #%d: %d\n",k++,dis[t]);
        else
            printf("Case #%d: unreachable\n",k++);
    }

    return 0;
}
