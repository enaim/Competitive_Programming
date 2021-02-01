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

const int SIZE = 110,Size = 10100;

int V,E,cnt=0;
int rnk[SIZE],parent[SIZE];

struct Coordinate{
    double x;
    double y;
};

Coordinate cor[SIZE];

struct Edge{
    int u,v;
    double w;
};
Edge ar[Size];

struct src
{
    int from;
    int to;
    double weight;
};
src A[SIZE];

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
    for(i=0;i<V;i++)
        Make_Set(i);

    sort(&ar[0],&ar[E],compare);

    cnt = 0;
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

    int tks,ks=1,cnt1,i,j;
    double sum;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&V);

        if(V==0)
        {
            printf("0.00\n");
            continue;
        }
        for(i=0;i<V;i++)
        {
            scanf("%lf",&cor[i].x);
            scanf("%lf",&cor[i].y);
        }

        cnt1 = 0;
        for(i=0;i<V;i++)
        {
            for(j=0;j<V;j++)
            {
                ar[cnt1].u = i;
                ar[cnt1].v = j;
                ar[cnt1].w=sqrt((pow((cor[i].x - cor[j].x),2)) + (pow((cor[i].y - cor[j].y),2)));
                cnt1++;
            }

        }
        E = cnt1 - 1;
        MST_KRUSKAL();

        sum = 0;
        for(i=0;i<V-1;i++)
            sum+=A[i].weight;

        if(tks==0)
            printf("%.2lf\n",sum);

        else
            printf("%.2lf\n\n",sum);

    }

    return 0;
}
