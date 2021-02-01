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
#include <queue>

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

const int SIZE = 110;

vector<int>adj[SIZE];

int k,V,E;
int TS[SIZE];
bool clr[SIZE];

void DFS_VISIT(int u)
{
    int i,v;
    clr[u]=false;
    for(i=0;i<adj[u].size();i++)
    {
        v = adj[u][i];
        if(clr[v]==true)
        {
            DFS_VISIT(v);
        }
    }
    clr[u]=false;
    TS[k++]=u;
}

void DFS()
{
    int i;

    for(i=1;i<=V;i++)
        clr[i]=true;

    for(i=1;i<=V;i++)
    {
        if(clr[i]==true)
            DFS_VISIT(i);
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,u,v;
    while(2==scanf("%d%d",&V,&E) && (V || E))
    {
        k = 0;
        for(i=0;i<=V;i++)
        {
            TS[i]=0;
            adj[i].clear();
        }

        for(i=0;i<E;i++)
        {
            scanf("%d%d",&v,&u);
            adj[u].pb(v);
        }

        DFS();

        for(i=0;i<k;i++)
        {
            if(i == (k-1))
                printf("%d",TS[i]);
            else
                printf("%d ",TS[i]);
        }
        printf("\n");
    }
    return 0;
}
