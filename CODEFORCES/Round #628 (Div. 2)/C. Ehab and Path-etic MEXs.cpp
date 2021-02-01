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

struct node{
    int x,y;
    int ind;
};
map<pii,int>mp;
node ar[100010];
int deg[100010];
int vis[100010];
vector<int>vec[100010];
queue<int>Q;
int cnt;

void bfs()
{
    int i,u,v,a,b;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        if(vis[u]==1)
            continue;
        vis[u]=1;
        int sz = vec[u].size();
        for(i=0;i<sz;i++)
        {
            v = vec[u][i];
            if(vis[v]==1)
                continue;
            a = u;
            b = v;
            if(a>b)
                swap(a,b);
            pii x = make_pair(a,b);
            mp[x]=cnt;
            cnt++;
            deg[v]--;
            if(deg[v]==1)
                Q.push(v);
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,u,v;
    while(1==scanf("%d",&n))
    {
        cnt = 0;
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&u,&v);
            if(u>v)
                swap(u,v);
            ar[i].x = u;
            ar[i].y = v;
            vec[u].pb(v);
            vec[v].pb(u);
            deg[u]++;
            deg[v]++;
        }
        for(i=1;i<=n;i++)
        {
            if(deg[i]==1)
                Q.push(i);
        }
        bfs();
        for(i=0;i<n-1;i++)
            printf("%d\n",mp[make_pair(ar[i].x,ar[i].y)]);
    }

    return 0;
}
