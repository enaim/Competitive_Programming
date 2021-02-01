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

int vis[100010];
int p[100010];
int n,m,i,sz,u,v,t;
priority_queue<int>pq;
vector<int>vec,adj[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%d%d",&n,&m))
    {
        int s = 0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            adj[u].pb(v);
            adj[v].pb(u);
        }

        pq.push(1);
        p[1]=1;
        while(!pq.empty())
        {
            t = abs(pq.top());
            pq.pop();
            if(vis[t]==0)
            {
                vec.pb(t);
                s++;
                if(s==n)
                    break;
            }
            if(vis[t]==0)
            {
                vis[t]=1;
                sz = adj[t].size();
                for(i=0;i<sz;i++)
                {
                    v = adj[t][i];
                    if(vis[v]==0 && p[v]==0)
                    {
                        p[v]=1;
                        pq.push(-v);
                    }
                }
            }
        }
        for(i=0;i<n;i++)
            printf("%d ",vec[i]);
        printf("\n");
    }

    return 0;
}
