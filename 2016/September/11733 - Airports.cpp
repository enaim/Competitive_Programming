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

const int SIZE = 10010;
const int Size = 100010;

int V,E,cost,A;
int rnk[SIZE],parent[SIZE];


struct Edge{int u,v,w;
};
Edge ar[Size];


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
    for(i=1;i<=V;i++)
        Make_Set(i);

    sort(&ar[0],&ar[E],compare);

    for(i=0;i<E;i++)
    {
        if(ar[i].w < A)
        {
            if(Find_Set(ar[i].u) != Find_Set(ar[i].v))
            {
                cost+=ar[i].w;
                Union(ar[i].u,ar[i].v);
            }
        }
        else
            break;
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,tks,ks=1,cnt;
    scanf("%d",&tks);

    while(tks--)
    {
        cost = 0;
        cnt = 0;
        scanf("%d%d%d",&V,&E,&A);
        for(i=0;i<E;i++)
            scanf("%d%d%d",&ar[i].u,&ar[i].v,&ar[i].w);

        MST_KRUSKAL();

        for(i=1;i<=V;i++)
            if(parent[i] == i)
                cnt++;
            cost+=(cnt*A);

        printf("Case #%d: %d %d\n",ks++,cost,cnt);
    }

    return 0;
}
