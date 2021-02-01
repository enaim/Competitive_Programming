#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

vector<int> adj[100],weight[100];
int dis[100];
int V,E,k= -1,temp;


struct node{
    int ndNmbr;
    int dist;
};

node Queue[100];

void insertIntoQueue(int nodeNumber, int distance)
{
    dis[nodeNumber] = distance;
    k++;
    Queue[k].ndNmbr = nodeNumber;
    Queue[k].dist = distance;
}

bool isQueueEmpty()
{
    if(k != -1)
        return false;
    return true;
}

int getMinCalculatedDis()
{
    int i,x,mn;

    mn = Queue[0].dist;
    temp = 0;
    for(i=0;i<=k;i++)
        if(Queue[i].dist < mn)
        {
            mn = Queue[i].dist;
            temp = i;
        }

    return Queue[temp].ndNmbr;
}

void pop()
{
     for(int i=temp;i<k;i++)
        Queue[i]=Queue[i+1];
    k--;
}

void Dijkstra(int Source)
{
    for(int i=1;i<=V;i++)
        dis[i] = OO;

    insertIntoQueue(Source,0);

    while(!isQueueEmpty())
    {
        int u = getMinCalculatedDis();

        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            int w = weight[u][i];
            int currentCalculatedDistance = w + dis[u];

            if(dis[v] > currentCalculatedDistance)
            {
                dis[v] = currentCalculatedDistance;
                insertIntoQueue( v, currentCalculatedDistance);
            }
        }
        pop();
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
            if(dis[i] < OO)
                printf("Vertex %d Distance from source is: %d\n",i,dis[i]);
            else
                printf("Impossible to reach in Node: %d\n",i);
    }

    return 0;
}
