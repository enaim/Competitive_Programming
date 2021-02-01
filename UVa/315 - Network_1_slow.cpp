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

vector<int> adj[100];
int V,E;

int timee,cnt;
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
    bool visited[110];
    int disc[110];
    int low[110];
    int parent[110];
    bool ap[110];
    for(int i=1;i<=110;i++)
    {
        ap[i]=false;
        visited[i]=false;
    }

    for (int i = 1; i <= V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
        ap[i] = false;
    }

    for (int i = 1; i <= V; i++)
        if (visited[i] == false)
            APUtil(i, visited, disc, low, parent, ap);

    for (int i = 1; i <= V; i++)
    {
        if (ap[i] == true)
            cnt++;
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int u,v,i,x;
    while(1==scanf("%d",&V) && V)
    {
        for(i=0;i<110;i++)
            adj[i].clear();

        timee = 0;
        cnt = 0;
        while(true)
        {
            string str;
            getline(cin,str);
            if(str[0] == '0')
                break;
            stringstream ss;
            ss<<str;
            int val,u;
            ss>>u;
            while(ss>>v)
            {
                adj[u].pb(v);
                adj[v].pb(u);
            }
        }
        AP();
        printf("%d\n",cnt);
    }

    return 0;
}
