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
typedef pair<int,int> pii;

const int SIZE = 10010;

struct links{
    int a,b;
};
links ar[SIZE];

vector<int> adj[SIZE];
int V,E;
int  cnt;
int timee;
void BridgeUtil(int u, bool visited[], int disc[],int low[], int parent[])
{
    visited[u] = true;
    disc[u] = low[u] = ++timee;
    for (int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i];
        if (!visited[v])
        {
            parent[v] = u;
            BridgeUtil(v, visited, disc, low, parent);
            low[u]  = min(low[u], low[v]);

            if (low[v]>disc[u])
            {
                if(u<v)
                {
                    ar[cnt].a = u;
                    ar[cnt].b = v;
                }
                else
                {
                    ar[cnt].a = v;
                    ar[cnt].b = u;
                }
                cnt++;
            }

        }

        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}

void Bridge()
{
    bool visited[SIZE];
    int disc[SIZE];
    int low[SIZE];
    int parent[SIZE];

    for(int i=0;i<SIZE;i++)
    {
        visited[i]=false;
    }

    for (int i = 0; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
    }

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            BridgeUtil(i, visited, disc, low, parent);
}

bool compare(links a,links b)
{
    if(a.a == b.a)
        return a.b<b.b;
    return a.a<b.a;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int u,v,i,x,j,k,len,ks = 1,tks;
    char str[10];
    set<pii>st;
    scanf("%d",&tks);
    while(tks--)
    {
        printf("Case %d:\n",ks++);
        scanf("%d",&V);
        st.clear();
        for(i=0;i<SIZE;i++)
            adj[i].clear();

        timee = 0;
        cnt = 0;
        for(i=0;i<V;i++)
        {
            scanf("%d%s",&u,str);
            len = strlen(str);
            k = 1;
            x = 0;
            while(k < len-1)
            {
                x = x*10 + str[k]-'0';
                k++;
            }

            for(j=0;j<x;j++)
            {
                scanf("%d",&v);
                pair<int,int>a,b;
                a = make_pair(u,v);
                b = make_pair(v,u);

                set<pii>::iterator it,it1;
                it = st.find(a);
                it1 = st.find(b);
                if(*it == a || *it1 == b)
                    continue;
                else
                    st.insert(a);

                adj[u].pb(v);
                adj[v].pb(u);
            }
        }
        Bridge();
        printf("%d critical links\n",cnt);
        sort(&ar[0],&ar[cnt],compare);
        for(i=0;i<cnt;i++)
            printf("%d - %d\n",ar[i].a,ar[i].b);
    }

    return 0;
}
