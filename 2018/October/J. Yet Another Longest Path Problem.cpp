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

struct node{
    int x,y;
};

bool vis[100010];
int flag[100010];
vector<int>adj[100010];
node ar[100010];

void bfs()
{
    queue<int>Q;
    Q.push(1);
    flag[1]=0;
    vis[1]=false;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        int sz = adj[u].size();
        for(int i=0;i<sz;i++)
        {
            int v = adj[u][i];
            if(vis[v]==true)
            {
                if(flag[u]==0)
                    flag[v]=1;
                else
                    flag[v]=0;
                Q.push(v);
                vis[v]=false;
            }
        }
    }
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,n,i,u,v;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            flag[i]=-1;
            vis[i]=true;
            adj[i].clear();
        }

        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&u,&v);
            ar[i].x = u;
            ar[i].y = v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bfs();
        printf("Case %d:\n",ks++);
        for(i=0;i<n-1;i++)
        {
            if(flag[ar[i].x]==0)
                printf("%d %d\n",ar[i].x,ar[i].y);
            else
                printf("%d %d\n",ar[i].y,ar[i].x);
        }
    }


    return 0;
}
