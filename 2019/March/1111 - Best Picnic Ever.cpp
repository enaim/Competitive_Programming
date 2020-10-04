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

vector<int>vec[1010];
int ar[1010];
int vis[1010];
int flag[1010];

void dfs(int u)
{
    int i,v,sz;
    vis[u]=1;
    flag[u]++;
    sz = vec[u].size();
    for(i=0;i<sz;i++)
    {
        v = vec[u][i];
        if(vis[v]==0)
            dfs(v);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,k,cnt,n,m,u,v,i;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d",&k,&n,&m);
        for(i=1;i<=n;i++)
        {
            vec[i].clear();
            flag[i]=0;
        }
        for(i=0;i<k;i++)
            scanf("%d",&ar[i]);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            vec[u].pb(v);
        }
        for(i=0;i<n;i++)
        {
            memset(vis,0,sizeof vis);
            dfs(ar[i]);
        }
        cnt = 0;
        for(i=1;i<=n;i++)
            if(flag[i]==k)
                cnt++;
        printf("Case %d: %d\n",ks++,cnt);
    }
    return 0;
}
