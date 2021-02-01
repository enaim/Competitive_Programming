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

const int Size = 100;

vector<int> adj[Size],weight[Size],parent[Size];
int dis[Size];
int V,E;

struct node{
    int ndNmbr;
    int dist;

     node(int ndNmbr=0,int dist=0){
        this->ndNmbr = ndNmbr;
        this->dist = dist;
    }

    // Me < notMe
    bool operator < (const node& notMe)const {
        return dist > notMe.dist;
    }
};

void Dijkstra(int Source)
{
    priority_queue<node>pq;

    for(int i=1;i<=V;i++)
        dis[i] = OO;

    dis[Source] = 0;
    pq.push(node(Source,0));
    parent[Source].pb(-1);

    while(!pq.empty())
    {
        node top = pq.top();
        pq.pop();

        int u = top.ndNmbr;

        if(dis[u] < top.dist)   continue;

        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            int w = weight[u][i];
            int currentCalculatedDistance = w + dis[u];

            if(dis[v] > currentCalculatedDistance)
            {
                parent[v].pb(u);
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
    int Source;

    while(3 == scanf("%d%d%d",&V,&E,&Source))
    {
        for(i=1;i<=E;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            adj[u].pb(v);
            weight[u].pb(w);
        }

        Dijkstra(Source);

        for(int i=1;i<=V;i++)
        {
            if(dis[i] < OO)
                printf("Vertex %d Distance from source is: %d\n",i,dis[i]);
            else
                printf("Impossible to reach in Node: %d\n",i);

                printf("Path - > %d\n",parent[i][0]);
        }
    }

    return 0;
}
