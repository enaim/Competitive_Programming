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

int n;
int vis[110];
vector<int>vec[110],weight[110];

int dfs(int v,int cost,int cnt)
{
    int u,i;
    if(cnt==n)
        return cost;
    if(v!=1)
        vis[v]=1;
    for(i=0;i<2;i++)
    {
        u = vec[v][i];
        if(vis[u]==0 && u!=1)
            cost = dfs(u,cost+weight[v][i],cnt+1);
        if(cnt==n-1 && u==1)
            cost = dfs(u,cost+weight[v][i],cnt+1);
    }
    return cost;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,u,v,w;
    scanf("%d",&tks);
    while(tks--)
    {
        for(i=1;i<=100;i++)
            vec[i].clear(),weight[i].clear();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            vec[u].pb(v);
            weight[u].pb(0);
            vec[v].pb(u);
            weight[v].pb(w);
        }
        int mn = OO;
        memset(vis,0,sizeof vis);
        mn = min(mn,dfs(vec[1][0],weight[1][0],1));
        memset(vis,0,sizeof vis);
        mn = min(mn,dfs(vec[1][1],weight[1][1],1));
        printf("Case %d: %d\n",ks++,mn);
    }

    return 0;
}
