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

const int Size = 2510;

int V,E,cnt;
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
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,sum,sum1,i,j,x;
    scanf("%d",&tks);
    while(tks--)
    {
        sum = 0;
        cnt=0;
        scanf("%d",&V);
        for(i=0;i<V;i++)
            for(j=0;j<V;j++)
            {
                scanf("%d",&x);
                if(x==0)
                    continue;
                ar[cnt].u=i;
                ar[cnt].v=j;
                ar[cnt++].w=x;
                sum+=x;
            }
        E = cnt;
        MST_Kruskal();
        sum1 = 0;
        st.clear();
        for(i=0;i<V-1;i++)
        {
            st.insert(Find_Set(i));
            if(i<cnt)
                sum1+=A[i].weight;
        }
        st.insert(Find_Set(V-1));
        if(st.size()==1)
            printf("Case %d: %d\n",ks++,sum-sum1);
        else
            printf("Case %d: -1\n",ks++,sum);
    }

    return 0;
}
