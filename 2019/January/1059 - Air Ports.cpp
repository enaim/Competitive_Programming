#include<bits/stdc++.h>
using namespace std;

const int Size = 100010;

int a,V,E,cnt;
int par[Size];
int rnk[Size];
set<int>st;

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

void MST_Kruskal()
{
    for(int i=0;i<Size;i++)
        Make_Set(i);

    sort(&ar[0],&ar[E],compare);

    cnt = 0;
    for(int i=0;i<E;i++)
    {
        if(Find_Set(ar[i].u) != Find_Set(ar[i].v) && ar[i].w<a)
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
    int tks,ks=1,u,v,w,i;
    scanf("%d",&tks);
    while(tks--)
    {
        st.clear();
        scanf("%d%d%d",&V,&E,&a);
        for(i=0;i<E;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            ar[i].u=u;
            ar[i].v=v;
            ar[i].w=w;
        }
        MST_Kruskal();
        int sum=0;
        for(i=0;i<cnt;i++)

            sum+=A[i].weight;
        for(i=1;i<=V;i++)
            st.insert(Find_Set(i));

        printf("Case %d: %d %d\n",ks++,sum+(st.size()*a),st.size());
    }

    return 0;
}
