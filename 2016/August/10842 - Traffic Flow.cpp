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

const int SIZE = 10100;

int V,E;
int rnk[SIZE],parent[SIZE];


struct Edge{int u,v,w;
};
Edge ar[SIZE];

struct src
{
    int from;
    int to;
    int weight;
};
src A[110];

bool compare(Edge a,Edge b)
{
    return a.w>b.w;
}

bool compare2(src a,src b)
{
    return a.weight<b.weight;
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
    int i,cnt=0;
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
//    freopen("in1.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i;
    int Source,ks = 1,t;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&V,&E);
        for(i=0;i<E;i++)
            scanf("%d%d%d",&ar[i].u,&ar[i].v,&ar[i].w);

        MST_KRUSKAL();

        sort(&A[0],&A[V-1],compare2);

        printf("Case #%d: %d\n",ks++,A[0].weight);
    }

    return 0;
}
