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

//int dr[]={1, 0, 0,-1};                //4 Direction
//int dc[]={0,-1, 1, 0};

//int dr[]={-1,-1,-1, 0, 0, 1, 1, 1;    //8 direction
//int dc[]={-1, 0, 1,-1, 1,-1, 0, 1};

//int dr[]={ 1, 1,-1,-1,-2, 2,-2, 2;    //Knight Direction
//int dc[]={-2, 2,-2, 2, 1, 1,-1,-1};

const int Size = 110;

vector<int> adj[Size],parent[Size];
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
        dis[i] = -OO;;

    dis[Source] = 0;
    pq.push(node(Source,0));
    parent[Source].pb(-1);

    while(!pq.empty())
    {
        node top = pq.top();
        pq.pop();

        int u = top.ndNmbr;

        if(dis[u] > top.dist)   continue;

        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            int currentCalculatedDistance = 1 + dis[u];

            if(dis[v] < currentCalculatedDistance)
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

    int i,u,v,ks=1;
    int Source;

    while(1 == scanf("%d",&V) && V)
    {
        scanf("%d",&Source);
        for(i=1;;i++)
        {
            scanf("%d%d",&u,&v);
            if(u==v && u==0)
                break;
            adj[u].pb(v);

        }

        Dijkstra(Source);
        int mx = - OO;
        int ind = 0;
        for(int i=1;i<=V;i++)
        {
            if(mx<dis[i])
            {
                mx = dis[i];
                ind = i;
            }
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",ks++,Source,dis[ind],ind);

        for(i=1;i<=V;i++)
            adj[i].clear();
    }

    return 0;
}
