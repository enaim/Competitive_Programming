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

int adj[1010];
bool vis[1010];

void dfs(int u)
{
    vis[u]=true;
    int v = adj[u];
    if(vis[v]==false)
        dfs(v);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,u,cnt,tks;
    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d",&n);

        memset(adj,0,sizeof adj);
        memset(vis,0,sizeof vis);

        for(i=1;i<=n;i++)
        {
            scanf("%d",&u);
            adj[i]=u;
        }

        cnt = 0;
        for(i=1;i<=n;i++)
        {
            if(vis[i]==true)
                continue;
            cnt++;
            dfs(i);
        }

        printf("%d\n",cnt);
    }

    return 0;
}
