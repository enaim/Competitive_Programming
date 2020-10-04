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

vector<int>vec[1010];
int color[1010];
int visited[1010];
set<int>st;

int bfs(int u)
{
    visited[u]=1;
    color[u]=1;
    queue<int>Q;
    Q.push(u);
    st.clear();
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        st.insert(u);
        int sz = vec[u].size();
        for(int i=0;i<sz;i++)
        {
            int v = vec[u][i];
            if(visited[v]==0)
            {
                visited[v]=1;
                color[v] = !color[u];
                Q.push(v);
            }
        }
    }
    int one=0,zero=0;
    for(auto it:st)
    {
        if(color[it])
            one++;
        else
            zero++;
    }
    return max(one,zero);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,n,e,u,v;
        for(i=1;i<=1000;i++)
        {
            vec[i].clear();
            visited[i] = 0;
        }

        scanf("%d%d",&n,&e);
        for(i=0;i<e;i++)
        {
            scanf("%d%d",&u,&v);
            vec[u].pb(v);
            vec[v].pb(u);
        }
        int sum = 0;
        for(i=1;i<=n;i++)
        {
            if(!visited[i] && vec[i].size()>0)
                sum+=bfs(i);
            else if(!visited[i])
                sum++;
        }
        printf("Case %d: %d\n",ks++,sum);
    }


    return 0;
}
