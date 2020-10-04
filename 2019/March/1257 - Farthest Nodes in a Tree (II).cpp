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

int mx,ind;
int vis[30010];
int dis[3][30010];
vector<int>vec[30010],weight[30010];

void dfs(int v,int cost,int cnt)
{
    int sz,u,w,i;
    vis[v]=1;
    dis[cnt][v]=cost;
    if(mx<cost)
        mx=cost,ind=v;
    sz = vec[v].size();
    for(i=0;i<sz;i++)
    {
        u = vec[v][i];
        w = weight[v][i];
        if(vis[u]==1)
            continue;
        vis[u]=1;
        dfs(u,cost+w,cnt);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,u,v,w,V;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&V);
        for(i=0;i<V;i++)
            vec[i].clear(),weight[i].clear();
        for(i=1;i<V;i++)
        {
            scanf("%d%d%d",&v,&u,&w);
            vec[v].pb(u);
            vec[u].pb(v);
            weight[u].pb(w);
            weight[v].pb(w);
        }

        mx = 0;
        for(i=0;i<V;i++)
            dis[0][i]=0,vis[i]=0;
        dfs(0,0,0);

        mx = 0;
        for(i=0;i<V;i++)
            dis[1][i]=0,vis[i]=0;
        dfs(ind,0,1);

        mx = 0;
        for(i=0;i<V;i++)
            dis[2][i]=0,vis[i]=0;
        dfs(ind,0,2);

        printf("Case %d:\n",ks++);
        for(i=0;i<V;i++)
            printf("%d\n",max(dis[1][i],dis[2][i]));
    }

    return 0;
}
