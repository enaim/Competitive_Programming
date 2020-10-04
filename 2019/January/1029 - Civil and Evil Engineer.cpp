#include<bits/stdc++.h>
using namespace std;

const int Size = 12010;

int E,cnt;
int par[Size];
int rnk[Size];

struct Edge{
    int u,v,w;
};
Edge ar[Size];

struct src{
    int from,to,weight;
} ;
src A[Size];

bool compare(Edge a,Edge b)
{
    return a.w<b.w;
}

bool compare1(Edge a,Edge b)
{
    return a.w>b.w;
}

int Find_Set(int x)
{
    if(x!=par[x])
        par[x]=Find_Set(par[x]);
    return par[x];
}

void Link(int x,int y)
{
    if(rnk[x]>rnk[y])
        par[y]=x;
    else
    {
        par[x]=y;
        if(rnk[x]>rnk[y])
            rnk[y]++;
    }
}

void Union(int x,int y)
{
    Link(Find_Set(x),Find_Set(y));
}

void Make_Set(int x)
{
    rnk[x]=0;
    par[x]=x;
}

void MST_Kruskal(int k)
{
    for(int i=0;i<Size;i++)
        Make_Set(i);
    if(k==1)
        sort(&ar[0],&ar[E],compare);
    if(k==2)
        sort(&ar[0],&ar[E],compare1);

    cnt = 0;
    for(int i=0;i<E;i++)
    {
        if(Find_Set(ar[i].u) != Find_Set(ar[i].v))
        {
            A[cnt].from = ar[i].u;
            A[cnt].to = ar[i].v;
            A[cnt].weight = ar[i].w;
            cnt++;
            Union(ar[i].u,ar[i].v);
        }
    }
}


int main()
{
    int tks,ks=1,u,v,w,n,i;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        u = v = w = 1;
        i = 0;
        while(u!=0 || v!=0 || w!=0)
        {
            scanf("%d%d%d",&u,&v,&w);
            ar[i].u=u;
            ar[i].v=v;
            ar[i].w=w;
            i++;
        }
        E = i;
        MST_Kruskal(1);
        int sum=0;
        for(i=0;i<n;i++)
            sum+=A[i].weight;

        MST_Kruskal(2);
        int sum1=0;
        for(i=0;i<n;i++)
            sum1+=A[i].weight;

        if((sum+sum1)%2==0)
            printf("Case %d: %d\n",ks++,(sum+sum1)/2);
        else
            printf("Case %d: %d/2\n",ks++,(sum+sum1));
    }

    return 0;
}
