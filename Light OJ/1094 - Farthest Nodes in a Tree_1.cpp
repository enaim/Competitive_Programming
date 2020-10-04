#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define OO 2e9+10
#define pb push_back
#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T sqr(T a){
    return a*a;
}
template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);

vector<int>vec[30010];
vector<int>weight[30010];
int vis[30010];
int mx,ind;
void dfs(int u,int cost)
{
    vis[u]=1;
    if(mx<cost)
    {
        mx = cost;
        ind = u;
    }
    int sz = vec[u].size();
    for(int i=0;i<sz;i++)
    {
        int v = vec[u][i];
        if(vis[v]==0)
            dfs(v,cost+weight[u][i]);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,u,b,n,w,v;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            vec[i].clear();
            weight[i].clear();
        }

        for(i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            vec[u].pb(v);
            vec[v].pb(u);
            weight[u].pb(w);
            weight[v].pb(w);
        }
        mx = 0;
        memset(vis,0,sizeof vis);
        dfs(u,0);

        mx = 0;
        memset(vis,0,sizeof vis);
        dfs(ind,mx);

        printf("Case %d: %d\n",ks++,mx);
    }

    return 0;
}
