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

const int SIZE = 200010;

int V,E,cnt=0;
int rnk[SIZE],parent[SIZE];
int deg[SIZE];

struct Edge{int u,v,w;
};
Edge ar[SIZE];

struct src
{
    int from;
    int to;
    int weight;
};
src A[SIZE];

bool compare(Edge a,Edge b)
{
    if(a.w==b.w)
        return a.u<b.u;
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
        parent[y] = x;
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
    for(i=0;i<V;i++)
        Make_Set(i);

    sort(&ar[0],&ar[E],compare);

    for(i=0;i<E;i++)
    {
        if(Find_Set(ar[i].u) != Find_Set(ar[i].v))
        {
            A[cnt].from = ar[i].u;
            A[cnt].to = ar[i].v;
            A[cnt++].weight = ar[i].w;

            Union(ar[i].u,ar[i].v);
        }
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,u,v;

    while(2 == scanf("%d%d",&V,&E))
    {
        for(i=0;i<E;i++)
        {
            scanf("%d%d",&ar[i].u,&ar[i].v);
            deg[ar[i].u]++;
            deg[ar[i].v]++;
        }
        for(i=0;i<E;i++)
        {
            if(deg[ar[i].u]<deg[ar[i].v])
                swap(ar[i].u,ar[i].v);
            if(deg[ar[i].u]==deg[ar[i].v])
            {
                u = ar[i].u;
                v = ar[i].v;
                ar[i].u=min(u,v);
                ar[i].v=max(u,v);
            }
            ar[i].w = min(-deg[ar[i].u],-deg[ar[i].v]);
        }
        MST_KRUSKAL();
        for(i=0;i<V-1;i++)
            printf("%d %d\n",A[i].from,A[i].to);
    }

    return 0;
}
