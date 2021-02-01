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

int vis[30010];
vector<int>vec[130010];
set<int>st;

void dfs(int u)
{
    int i,v;

    for(i=0;i<vec[u].size();i++)
    {

        v = vec[u][i];
        if(vis[v]==0)
        {
            vis[v]=1;
            st.insert(v);
            dfs(v);
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n,mn=OO,mx=2,u,v;
    while(1==scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            vec[u].pb(v);
            vec[v].pb(u);
        }
        for(i=1;i<=2*n;i++)
        {
            if(vis[i]==0)
            {
                st.clear();
                vis[i]=1;
                st.insert(i);
                dfs(i);
                if((int)st.size()<=1)
                    continue;
                mn = min(mn,(int)st.size());
                mx = max(mx,(int)st.size());
            }
        }
        printf("%d %d\n",mn,mx);
    }

    return 0;
}
