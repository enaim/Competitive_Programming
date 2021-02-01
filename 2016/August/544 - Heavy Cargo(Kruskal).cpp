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

const int Edge_Size = 20000;
const int SIZE = 210;

int V,E,cnt=0,result,X,Y;
int rnk[SIZE],parent[SIZE];


struct Edge{int u,v,w;
};
Edge ar[Edge_Size];

struct src
{
    int from;
    int to;
    int weight;
};
src A[SIZE];

bool compare(Edge a,Edge b)
{
    return a.w>b.w;
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

int MST_KRUSKAL()
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
            if(Find_Set(X) == Find_Set(Y))
            {
                result = ar[i].w;
                return result;
            }
        }
    }
}


int main()
{
//    freopen("in1.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int Source,W,i,r,c,a,b,ks = 1;
    char s1[40],s2[40];

    map<string,int>mp;

    while(2 == scanf("%d%d",&V,&E) &&V &&E)
    {
        mp.clear();
        c = 1;
        r=0;
        for(i=0;i<E;i++)
        {
            scanf("%s%s%d",s1,s2,&W);
            if(!mp[s1])
                mp[s1]=c++;
            if(!mp[s2])
                mp[s2]=c++;

            a = mp[s1];         b = mp[s2];
            ar[r].u = a;        ar[r].v=b;      ar[r].w = W;    r++;
        }
        scanf("%s%s",s1,s2);

        X = mp[s1];
        Y = mp[s2];

        result = MST_KRUSKAL();

        printf("Scenario #%d\n",ks++);
        printf("%d tons\n\n",result);
    }

    return 0;
}
