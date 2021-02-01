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

#define OO         2e9+10
#define OOO        5e18+10
#define pb         push_back
#define nn         printf("\n")
#define sf(a)      scanf("%d",&a)
#define ssf(str)   scanf("%s",str)
#define pf(a)      printf("%d\n",a)
#define sl(a)      scanf("%lld",&a)
#define pl(a)      printf("%lld\n",a)
#define sf2(a,b)   scanf("%d%d",&a,&b)
#define pf2(a,b)   printf("%d %d\n",a,b)
#define sl2(a,b)   scanf("%lld%lld",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pl2(a,b)   printf("%lld %lld\n",a,b)
#define sl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)  {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define FasterIO   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MapPnt(a)  {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

int mx;
int level[510];
int vis[510];
map<string,int>mp;
vector<int>vec[510];

void bfs()
{
    queue<int>q;
    q.push(1);
    level[1]=1;
    vis[1]=1;
    int i,u,v;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        int sz = vec[u].size();
        for(i=0;i<sz;i++)
        {
            v = vec[u][i];
            if(vis[v]==0)
            {
                level[v]=level[u]+1;
                mx = max(level[v],mx);
                vis[v]=1;
                q.push(v);
            }
        }
    }
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    for(int i=0;i<500;i++)
    {
        vec[i].clear();
        vis[i]=0;
        level[i]=0;
    }
    mp.clear();
    mp["polycarp"]=1;
    int cnt = 2;
    int i,n;
    sf(n);
    string str,str1,str2;
    for(i=0;i<n;i++)
    {
        cin>>str1>>str>>str2;
        for(int j=0;j<str1.size();j++)
        {
            if(str1[j]<'a')
                str1[j] = str1[j]+('a'-'A');
        }
        for(int j=0;j<str2.size();j++)
        {
            if(str2[j]<'a')
                str2[j] = str2[j]+('a'-'A');
        }
        if(mp[str1]==0)
        {
            mp[str1]=cnt;
            cnt++;
        }
        if(mp[str2]==0)
        {
            mp[str2]=cnt;
            cnt++;
        }
        vec[mp[str2]].pb(mp[str1]);
    }
    mx = 1;
    bfs();
    pf(mx);

    return 0;
}
