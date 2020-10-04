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

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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
    int u,v;
};
node ar[200010];

vector<int>vec[200010];
int flag[200010];
int vis[200010],f;

void bfs(int v)
{
    flag[v]=1;
    queue<int>Q;
    Q.push(v);
    vis[v]=1;
    while(!Q.empty())
    {
        v = Q.front();
        Q.pop();
        int sz = vec[v].size();
        for(int i=0;i<sz;i++)
        {
            int u = vec[v][i];
            if(vis[u]==0)
            {
                if(flag[v]==1)
                    flag[u]=0;
                else
                    flag[u]=1;
                Q.push(u);
                vis[u]=1;
            }
            else if(flag[v]==flag[u])
            {
                while(!Q.empty())
                    Q.pop();
                f = 1;
                return;
            }
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int i,n,m,u,v;
    while(2==scanf("%d%d",&n,&m))
    {
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            ar[i].u=u;
            ar[i].v=v;
            vec[u].pb(v);
            vec[v].pb(u);
        }
        f = 0;
        bfs(1);
        if(f)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for(i=0;i<m;i++)
        {
            printf("%d",!flag[ar[i].v]);
        }
        printf("\n");
    }

    return 0;
}
