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

vector<int>vec[100010];
int flag[100010];
set<int>st;
int cnt1,cnt2;

void dfs(int u)
{
    int sz = vec[u].size();
    for(int i=0;i<sz;i++)
    {
        int v = vec[u][i];
        if(!flag[v])
        {
            if(flag[u]==1)
                flag[v]=2,cnt2++;
            else
                flag[v]=1,cnt1++;
            dfs(v);
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,u,v,n,mx;
    scanf("%d",&tks);
    while(tks--)
    {
        st.clear();
        for(i=0;i<100010;i++)
        {
            vec[i].clear();
            flag[i]=0;
        }
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            vec[u].pb(v);
            vec[v].pb(u);
            st.insert(u);
            st.insert(v);
        }
        mx = 0;
        for(auto it : st)
        {
            cnt1 = cnt2 = 0;
            if(flag[it]==0)
            {
                flag[it]=1;
                cnt1++;
                dfs(it);
            }
            mx += max(cnt1,cnt2);
        }
        printf("Case %d: %d\n",ks++,mx);
    }

    return 0;
}
