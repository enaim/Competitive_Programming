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

int sum,cnt;
int ar[1010];
int vis[1010];
vector<int>vec[1010];

void dfs(int v)
{
    vis[v]=1;
    int u,i,sz;
    sum+=ar[v];
    cnt++;
    sz = vec[v].size();
    for(i=0;i<sz;i++)
    {
        u = vec[v][i];
        if(vis[u]==0)
            dfs(u);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,avg,n,m,u,v;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&n,&m);

        for(i=1;i<=n;i++)
            vec[i].clear(),vis[i]=0;

        sum = 0;
        for(i=1;i<=n;i++)
            scanf("%d",&ar[i]),sum+=ar[i];

        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            vec[u].pb(v);
            vec[v].pb(u);
        }
        if(sum%n!=0)
        {
            printf("Case %d: No\n",ks++);
            continue;
        }
        avg = sum/n;

        for(i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                sum = cnt = 0;
                dfs(i);
                if(sum%cnt!=0 || sum/cnt!=avg)
                    break;
            }
        }
        if(i==n+1)
            printf("Case %d: Yes\n",ks++);
        else
            printf("Case %d: No\n",ks++);
    }

    return 0;
}
