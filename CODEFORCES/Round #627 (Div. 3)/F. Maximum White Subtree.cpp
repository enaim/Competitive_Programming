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

int ar[200010];
int dp[200010];
int ans[200010];
vector<int>vec[200010];

void dfs(int u=1,int p=-1)
{
    dp[u]=ar[u];
    int sz = vec[u].size();
    for(int i=0;i<sz;i++)
    {
        int v = vec[u][i];
        if(v==p)
            continue;
        dfs(v,u);
        dp[u] += max(dp[v],0);
    }
}

void dfs1(int u=1,int p=-1,int sum=0)
{
    ans[u] = dp[u]+sum;
    int sz = vec[u].size();
    for(int i=0;i<sz;i++)
    {
        int v = vec[u][i];
        if(v==p)
            continue;
        dfs1(v,u,max(ans[u]-max(dp[v],0),0));
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,u,v;
    while(1==scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ar[i]);
            if(!ar[i])
                ar[i]=-1;
        }
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            vec[u].pb(v);
            vec[v].pb(u);
        }
        dfs();
        dfs1();
        for(i=1;i<=n;i++)
            printf("%d ",ans[i]);;
        printf("\n");
    }

    return 0;
}
