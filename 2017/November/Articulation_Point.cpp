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
#include <queue>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)
#define sqr(a)  (a*a)
#define NIL -1

typedef long long ll;

const double pi = acos(-1.0);
const double eps = 1e-8;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const int SIZE = 100;

vector<int> adj[SIZE];
int V,E;

int timee;
void APUtil(int u, bool visited[], int disc[],int low[], int parent[], bool ap[])
{
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++timee;
    for (int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i];
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            APUtil(v, visited, disc, low, parent, ap);
            low[u]  = min(low[u], low[v]);

            if (parent[u] == NIL && children > 1)
                ap[u] = true;
            if (parent[u] != NIL && low[v] >= disc[u])
                ap[u] = true;
        }
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}

void AP()
{
    bool visited[SIZE];
    int disc[SIZE];
    int low[SIZE];
    int parent[SIZE];
    bool ap[SIZE];
    for(int i=0;i<SIZE;i++)
    {
        ap[i]=false;
        visited[i]=false;
    }

    for (int i = 0; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
        ap[i] = false;
    }

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            APUtil(i, visited, disc, low, parent, ap);

    for (int i = 0; i < V; i++)
    {
        if (ap[i] == true)
                printf("%d ",i);
    }
    printf("\n");
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int u,v,i;
    while(2==scanf("%d%d",&V,&E))
    {
        for(i=0;i<SIZE;i++)
            adj[i].clear();

        timee = 0;
        for(i=0;i<E;i++)
        {
            scanf("%d%d",&u,&v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        AP();
    }

    return 0;
}
