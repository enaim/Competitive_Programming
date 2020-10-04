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

int dis[200010];
int vis[200010];

int cnt;
vector<int>vec[200010];
void dfs(int u,int d)
{
    vis[u]=1;
    int v,i,sz;
    int x = cnt;
    sz = vec[u].size();
    for(i=0;i<sz;i++)
    {
        v = vec[u][i];
        if(vis[v]==0)
            dfs(v,d+1);
    }
    int y = cnt;
    dis[cnt++]=d-(y-x);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,k,u,v;
    while(2==scanf("%d%d",&n,&k))
    {
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&u,&v);
            vec[u].pb(v);
            vec[v].pb(u);
        }
        dfs(1,0);
        sort(&dis[0],&dis[n]);
        ll sum = 0LL;
        for(i=n-1;i>=0;i--)
        {
            sum+=dis[i];
            k--;
            if(k==0)
                break;
        }
        printf("%lld\n",sum);
    }

    return 0;
}
