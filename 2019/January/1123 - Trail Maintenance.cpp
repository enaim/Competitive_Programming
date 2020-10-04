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
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}
template<class T>T sqr(T a){
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;

int V,E,cnt;
int rnk[210];
int par[210];
set<int>st;

struct Edge{
    int u,v,w;
};
Edge ar[6010];

struct src{
    int from,to,weight;
};
src A[210];

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
        if(rnk[x]==rnk[y])
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
    for(int i=1;i<=V;i++)
        Make_Set(i);

    sort(&ar[0],&ar[E],compare);

    cnt = 0;
    for(int i=0;i<E;i++)
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

    int tks,ks=1,i,j,sum,W,flag;
    scanf("%d",&tks);
    while(tks--)
    {
        E = flag = 0;
        printf("Case %d:\n",ks++);
        scanf("%d%d",&V,&W);
        for(i=0;i<W;i++)
        {
            if(i<V-1)
            {
                scanf("%d%d%d",&ar[i].u,&ar[i].v,&ar[i].w);
                E = i+1;
            }
            else
            {
                if(flag)
                    for(j=0;j<V-1;j++)
                    {
                        ar[j].u=A[j].from;
                        ar[j].v=A[j].to;
                        ar[j].w=A[j].weight;
                    }
                else
                    j = i;
                scanf("%d%d%d",&ar[j].u,&ar[j].v,&ar[j].w);
                E = j + 1;
            }

            if(E>=V-1)
                MST_Kruskal();

            st.clear();
            for(j=1;j<=V;j++)
                st.insert(Find_Set(j));

            if(st.size()==1 && E>=V-1)
            {
                flag = 1;
                sum = 0;
                for(j=0;j<V-1;j++)
                    sum+=A[j].weight;
            }

            if(st.size()==1 && E>=V-1)
                printf("%d\n",sum);
            else
                printf("-1\n");
        }
    }

    return 0;
}
