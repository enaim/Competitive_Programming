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

vector<int>vec[100010];
int deg[100010];
int vis[100010];
int ar[100010];
int flag;

void dfs(int u,int dis)
{
    int i,v;
    vis[u]=1;
    int sz = vec[u].size();
    for(i=0;i<sz;i++)
    {
        v = vec[u][i];
        if(vis[v]==0)
            dfs(v,dis+1);
        if(deg[v]==1 && (dis+1)%2==1)
            flag = 1;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,cnt,ans,u,v;
    while(1==scanf("%d",&n))
    {
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&u,&v);
            vec[u].pb(v);
            vec[v].pb(u);
            deg[u]++;
            deg[v]++;
        }
        for(i=1;i<=n;i++)
            if(deg[i]==1)
            {
                dfs(i,0);
                break;
            }
        for(i=1;i<=n;i++)
        {
            if(deg[i]==1)
                ar[vec[i][0]]++;
        }
        cnt = n-1;
        ans = 0;
        for(i=1;i<=n;i++)
        {
            if(ar[i])
            {
                cnt-=ar[i];
                ans++;
            }
        }
        ans+=cnt;
        if(flag)
            printf("3 %d\n",ans);
        else
            printf("1 %d\n",ans);
    }

    return 0;
}
