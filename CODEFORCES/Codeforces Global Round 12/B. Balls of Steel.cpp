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

#define OO         2e9+10
#define OOO        5e18+10
#define pb         push_back
#define nn         printf("\n")
#define sf(a)      scanf("%d",&a)
#define ssf(str)   scanf("%s",str)
#define pf(a)      printf("%d\n",a)
#define sl(a)      scanf("%lld",&a)
#define pl(a)      printf("%lld\n",a)
#define sf2(a,b)   scanf("%d%d",&a,&b)
#define pf2(a,b)   printf("%d %d\n",a,b)
#define sl2(a,b)   scanf("%lld%lld",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pl2(a,b)   printf("%lld %lld\n",a,b)
#define sl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)  {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define FasterIO   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MapPnt(a)  {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

struct node{
    int x,y;
};
node ar[110];
int vis[110];
int level[110];
vector<int>vec[110];

int bfs(int u)
{
    int v;
    int mx = 0;
    queue<int>q;
    q.push(u);
    vis[u]=1;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        int sz = vec[u].size();
        for(int i=0;i<sz;i++)
        {
            v = vec[u][i];
            if(vis[v]==0)
            {
                vis[v]=1;
                level[v]=level[u]+1;
                mx = max(mx,level[v]);
                q.push(v);
            }
        }
    }
    return mx;
}


int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,n,k,j,mn;
        sf2(n,k);
        for(i=0;i<n;i++)
        {
            sf2(ar[i].x,ar[i].y);
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(abs(ar[i].x-ar[j].x)+abs(ar[i].y-ar[j].y)<=k)
                {
                    vec[i].pb(j);
                    vec[j].pb(i);
                }
            }
        }
        mn = OO;
        for(i=0;i<n;i++)
        {
            memset(vis,0,sizeof vis);
            memset(level,0,sizeof level);
            int x = bfs(i);
            for(j=0;j<n;j++)
                if(vis[j]==0)
                    break;
            if(j==n && x==1)
                mn = min(mn,x);
        }
        for(i=0;i<n;i++)
            vec[i].clear();
        if(mn==OO)
            puts("-1");
        else
            pf(mn);
    }

    return 0;
}
