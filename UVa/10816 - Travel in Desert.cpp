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
#include <queue>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const int Size = 110;
const int SIZE_E = 10010;

int V,E,Source,Destination;
double mx;

//Dijkstra
vector<int> adj[Size];
vector<double>weight[Size],temp[Size];
double dis[Size];
int par[Size];

struct node{
    int ndNmbr;
    double dist;

     node(int ndNmbr=0,double dist=0){
        this->ndNmbr = ndNmbr;
        this->dist = dist;
    }

    // Me < notMe
    bool operator < (const node& notMe)const {
        return dist > notMe.dist;
    }
};

void Dijkstra()
{
    priority_queue<node>pq;

    for(int i=1;i<=V;i++)
        dis[i] = OO;

    dis[Source] = 0;
    pq.push(node(Source,0));
    par[Source] = -1 ;

    while(!pq.empty())
    {
        node top = pq.top();
        pq.pop();

        int u = top.ndNmbr;

        if(dis[u] < top.dist)   continue;

        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            double w = weight[u][i];
            double currentCalculatedDistance = w + dis[u];

            if(temp[u][i] > mx)    continue;

            if(dis[v] > currentCalculatedDistance)
            {
                par[v] = u;
                dis[v] = currentCalculatedDistance;
                pq.push(node( v, currentCalculatedDistance));
            }
        }
    }
}


//Kruskal
int rnk[Size],parent[Size];

struct Edge{
    int u,v;
    double w;
};
Edge ar[SIZE_E];

bool compare(Edge a,Edge b)
{
    return a.w<b.w;
}

int Find_Set(int x)
{
    if(x != parent[x])
        parent[x] = Find_Set(parent[x]);

    return parent[x];
}

void Link(int x,int y)
{
    if(rnk[x] > rnk[y])
    {
        parent[y] = x;
    }
    else
    {
        parent[x] = y;

        if(rnk[x] == rnk[y])
            rnk[y]++;
    }
}

void Union(int x,int y)
{
    Link(Find_Set(x),Find_Set(y));
}

void Make_Set(int x)
{
    parent[x] = x;
    rnk[x] = 0;
}

void MST_KRUSKAL()
{
    int i;
    for(i=1;i<=V;i++)
        Make_Set(i);

    sort(&ar[0],&ar[E],compare);
    for(i=0;i<E;i++)
    {
        if(Find_Set(ar[i].u) != Find_Set(ar[i].v))
        {
            Union(ar[i].u,ar[i].v);
            if(Find_Set(Source) == Find_Set(Destination))
            {
                mx = ar[i].w;
                break;
            }
        }
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int arr[Size];
    int a,b,x,cnt;
    double c,d,length;
    while(4==scanf("%d%d%d%d",&V,&E,&Source,&Destination))
    {
        for(int i=1;i<=V;i++)
        {
            adj[i].clear();
            weight[i].clear();
            temp[i].clear();
        }

        for(int i=0;i<E;i++)
        {
            scanf("%d%d%lf%lf",&a,&b,&c,&d);
            ar[i].u = a;
            ar[i].v = b;
            ar[i].w = c;

            adj[a].pb(b);
            adj[b].pb(a);
            temp[a].pb(c);
            temp[b].pb(c);
            weight[a].pb(d);
            weight[b].pb(d);
        }

        MST_KRUSKAL();
        Dijkstra();

        x = Destination;
        cnt = 0;

        while(par[x] != -1)
        {
            arr[cnt++] = par[x];
            x = arr[cnt-1];
        }

        for(int i=cnt-1;i>=0;i--)
            printf("%d ",arr[i]);
        printf("%d\n%.1lf %.1lf\n",Destination,dis[Destination],mx);
    }

    return 0;
}
