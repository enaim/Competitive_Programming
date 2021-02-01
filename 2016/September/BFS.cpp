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

const int SIZE = 100;

int dis[SIZE],parent[SIZE],Queue[SIZE];
int V,E,Front = -1,Rare = -1;
bool clr[SIZE];
vector<int>adj[SIZE];


void BFS(int Source)
{
    for(int i=1;i<=V;i++)
    {
        clr[i]= true;
        dis[i] = OO;
    }

    clr[Source] = false;
    dis[Source] = 0;
    Queue[++Rare] = Source;

    while(Front != Rare)
    {
        int u,v,w;
        u = Queue[++Front];

        for(int i=0;i<adj[u].size();i++)
        {
            v = adj[u][i];
            if(clr[v] == true)
            {
                clr[v] = false;
                dis[v] = dis[u] + 1;
                parent[v] = u;
                Queue[++Rare] = v;
            }
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int Source,i,u,v,w;

    while(3==scanf("%d%d%d",&V,&E,&Source))
    {
        for(i=0;i<E;i++)
        {
            scanf("%d%d",&u,&v);
            adj[u].pb(v);
        }

        BFS(Source);

        for(i=1;i<=V;i++)
            printf("From ->%d - To ->%d dis=%d  parent ->%d\n",Source,i,dis[i],parent[i]);
    }

    return 0;
}
