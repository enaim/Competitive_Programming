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

const int SIZE = 100;

vector<int> adj[SIZE],weight[SIZE];
int dis[SIZE],par[SIZE];
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

void Prims(int Source)
{
    priority_queue<node>pq;

    for(int i=1;i<=V;i++)
        dis[i] = OO;

    dis[Source] = 0;
    par[Source] = -1;
    pq.push(node(Source,0));

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
            int currentCalculatedDistance = w ;

            if(dis[v] > currentCalculatedDistance)
            {
                dis[v] = currentCalculatedDistance;
                pq.push(node( v, currentCalculatedDistance));
                par[v] = u;
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

        Prims(Source);

        for(i=1;i<=V;i++)
            printf("dis[%d] - > %d\n",i,dis[i]);
        for(i=V;i>=1;i--)
            printf("parent[%d] - > %d\n",i,par[i]);
    }

    return 0;
}
