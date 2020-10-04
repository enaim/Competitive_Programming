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

const int SIZE = 10010;

vector<int>adj[SIZE];
vector<int>weight[SIZE];
queue<int>Q;
set<int>st;

int k,V,E,mx;
int degree[SIZE],dis[SIZE],vis[SIZE];

void BFS()
{
    int temp,u;
    while(!Q.empty())
    {
        u = Q.front();
        vis[u]=1;
        Q.pop();
        if(degree[u]==0)
            continue;
        degree[u]--;
        int sz = adj[u].size();
        for(int i=0;i<sz;i++)
        {
            int v = adj[u][i];
            int w = weight[u][i];
            if(vis[v]==1)
                continue;
            mx = max(mx,dis[v]+dis[u]+w);
            dis[v]=max(dis[v],dis[u]+w);
            degree[v]--;
            if(degree[v]==1)
                Q.push(v);
        }
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,u,v,w;
    while(scanf("%d",&V)==1)
    {
        mx = 0;
        for(i=0;i<=V;i++)
        {
            degree[i]=0;
            dis[i]=0;
            vis[i]=0;
            adj[i].clear();
            weight[i].clear();
        }
        E = V-1;
        for(i=0;i<E;i++)
        {
            scanf("%d%d",&v,&u);
            w = 1;
            adj[v].pb(u);
            adj[u].pb(v);
            weight[u].pb(w);
            weight[v].pb(w);
            degree[u]++;
            degree[v]++;
        }

        for(i=0;i<V;i++)
            if(degree[i] == 1)
                Q.push(i);

        BFS();
        printf("%d\n",mx);
    }

    return 0;
}
