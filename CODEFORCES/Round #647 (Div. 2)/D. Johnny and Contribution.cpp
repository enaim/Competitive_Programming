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
const int Size = 500010;

struct node{
    int ind,val;
};

bool compare(node a,node b)
{
    return a.val<b.val;
}

node ar[500010];
int vis[500010];
int last[500010];
set<int>st[500010];
vector<int>vec[500010];
vector<int>ans;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j,n,m,u,v,x;
    while(2==scanf("%d%d",&n,&m))
    {
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            vec[u].pb(v);
            vec[v].pb(u);
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            ar[i].ind = i;
            ar[i].val = x;
        }
        sort(&ar[1],&ar[n+1],compare);
        int flag = 0;
        for(i=1;i<=n;i++)
        {
            u = ar[i].ind;
            v = ar[i].val;
            if(v!=last[u]+1)
                break;
            ans.pb(u);
            vis[u]=1;
            int sz = vec[u].size();
            for(j=0;j<sz;j++)
            {
                x = vec[u][j];
                if(vis[x])
                    continue;
                last[x]=v;
                st[x].insert(v);
                if(st[x].size()!=last[x])
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(i==n+1)
            for(i=0;i<n;i++)
                printf("%d ",ans[i]);
        else
            printf("-1");
        printf("\n");
    }

    return 0;
}
