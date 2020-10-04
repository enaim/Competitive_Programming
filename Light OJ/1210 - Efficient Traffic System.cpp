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
    int ind,s,e,mark;
};

int cnt;
node ar[20010];
int vis[20010];
int Mark[20010];
int indeg[20010];
int outdeg[20010];
vector<int>adj[20010],tadj[20010],component[20010];

bool compare(node a,node b)
{
    return a.e>b.e;
}
bool compare1(node a,node b)
{
    return a.ind<b.ind;
}

void dfs(int v)
{
    int i,sz,u;
    cnt++;
    ar[v].s = cnt;
    vis[v] = 1;
    sz = adj[v].size();
    for(i=0;i<sz;i++)
    {
        u = adj[v][i];
        if(vis[u]==0)
            dfs(u);
    }
    cnt++;
    ar[v].e = cnt;
}

void Tdfs(int v,int MARK)
{
    int i,sz,u;
    vis[v] = 1;
    Mark[v] = MARK;
    component[MARK].pb(v);
    sz = tadj[v].size();
    for(i=0;i<sz;i++)
    {
        u = tadj[v][i];
        if(vis[u]==0)
            Tdfs(u,MARK);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,n,m,u,v;
    scanf("%d",&tks);
    while(tks--)
    {
        for(i=1;i<=20000;i++)
            adj[i].clear(),tadj[i].clear(),component[i].clear(),indeg[i]=outdeg[i]=0;

        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            adj[u].pb(v);
            tadj[v].pb(u);
        }
        memset(vis,0,sizeof vis);
        cnt=0;
        for(i=1;i<=n;i++)
        {
            ar[i].ind = i;
            if(vis[i]==0)
                dfs(i);
        }
        sort(&ar[1],&ar[n+1],compare);
        memset(vis,0,sizeof vis);
        cnt = 1;
        for(i=1;i<=n;i++)
        {
            if(vis[ar[i].ind]==0)
                Tdfs(ar[i].ind,cnt),cnt++;
        }
        sort(&ar[1],&ar[n+1],compare1);
        for(i=1;i<cnt;i++)
        {
            int sz1 =  component[i].size();
            for(int k=0;k<sz1;k++)
            {
                int it = component[i][k];
                int sz =  adj[it].size();
                for(int j=0;j<sz;j++)
                {
                    u = adj[it][j];
                    if(Mark[it]!=Mark[u])
                    {
                        indeg[Mark[it]]++;
                        outdeg[Mark[u]]++;
                    }
                }
            }
        }

        int ans=0,cnt1=0,cnt2=0;
        for(i=1;i<cnt;i++)
        {
            if(indeg[i]==0)
                cnt1++;
            if(outdeg[i]==0)
                cnt2++;
        }
        ans = max(cnt1,cnt2);
        if(cnt-1==1)
            ans = 0;
        printf("Case %d: %d\n",ks++,ans);
     }

    return 0;
}
