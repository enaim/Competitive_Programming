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

vector<int>adj[100010];
vector<int>level[100010];
vector<int>vec[100010];

int n,mx,mxc;
int L[100010];
int par[100010];
int ar[100010];
int child[100010];
int ch[100010];
int i,j,k,sz,u,v,x;

void Leveling()
{
    queue<int>Q;
    Q.push(1);
    L[1]=1;
    level[L[1]].pb(1);
    mx = 1;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        int sz = adj[u].size();
        for(int i=0;i<sz;i++)
        {
            int v = adj[u][i];
            L[v] = L[u]+1;
            level[L[v]].pb(v);
            mx = max(mx,L[v]);
            Q.push(v);
        }
    }
    for(i=0;i<100010;i++)
        child[i]=1,ch[0];

    sz = level[i].size();

    for(i=mx;i>1;i--)
    {
        sz = level[i].size();
        for(j=0;j<sz;j++)
        {
            u = level[i][j];
            child[par[u]]++;
        }
    }

    for(i=1;i<100010;i++)
        if(child[i]==1)
            ch[i]=1;
        else
            child[i]=0;

    for(i=mx;i>1;i--)
    {
        sz = level[i].size();
        for(j=0;j<sz;j++)
        {
            u = level[i][j];
            if(ch[u]==1)
                child[par[u]]++;
            else
                child[par[u]]+=child[u];
        }
    }

    mxc = 1;
    for(i=1;i<=n;i++)
    {
        vec[child[i]].pb(i);
        mxc = max(mxc,child[i]);
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%d",&n))
    {
        par[1]=1;
        for(i=2;i<=n;i++)
        {
            scanf("%d",&x);
            adj[x].pb(i);
            par[i]=x;
        }

        Leveling();

        k = 1;
        for(i=0;i<=mxc;i++)
        {
            sz = vec[i].size();
            int t =  k;
            for(j=k;j<sz+t;j++)
            {
                ar[j]=i;
                k++;
            }
        }

        for(i=1;i<=n;i++)
            printf("%d ",ar[i]);
        printf("\n");
    }

    return 0;
}
