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

const int Size = 60;
int cnt,cnt1,E;
int rnk[Size];
int par[Size];
set<int>st;
map<string,int>mp;

struct edge{
    int u,v,w;
};
edge ar[Size];

struct src{
    int from,to,weight;
};
src A[Size];

bool compare(edge a,edge b)
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
    for(int i=0;i<Size;i++)
        Make_Set(i);

    sort(&ar[0],&ar[E],compare);

    cnt1 = 0;
    for(int i=0;i<E;i++)
    {
        if(Find_Set(ar[i].u) != Find_Set(ar[i].v))
        {
            A[cnt1].from = ar[i].u;
            A[cnt1].to = ar[i].v;
            A[cnt1++].weight = ar[i].w;
            Union(ar[i].u,ar[i].v);
        }
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,c;
    char str1[60],str2[60];
    scanf("%d",&tks);
    while(tks--)
    {
        mp.clear();
        cnt = 1;
        scanf("%d",&E);
        for(i=0;i<E;i++)
        {
            scanf("%s%s%d",str1,str2,&c);
            if(!mp[str1])
                mp[str1]=cnt++;
            if(!mp[str2])
                mp[str2]=cnt++;
            ar[i].u = mp[str1];
            ar[i].v = mp[str2];
            ar[i].w = c;
        }

        MST_Kruskal();
        int sum = 0;
        st.clear();
        for(i=0;i<min(cnt-1,cnt1);i++)
        {
            st.insert(Find_Set(A[i].from));
            st.insert(Find_Set(A[i].to));
            sum+=A[i].weight;
        }
        if(st.size()==1)
            printf("Case %d: %d\n",ks++,sum);
        else
            printf("Case %d: Impossible\n",ks++);
    }

    return 0;
}
