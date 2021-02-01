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

vector<int>vec[10010];
map<string,int>mp;
queue<int>Q;
int deg[10010];
int TS[10010];
int k;

void BFS()
{
    int i,u;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        int sz = vec[u].size();
        for(i=0;i<sz;i++)
        {
            int v = vec[u][i];
            deg[v]--;
            if(!deg[v])
            {
                TS[k++]=v;
                Q.push(v);
            }
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,n,i,u,v,cnt;
    char str1[12],str2[12];
    scanf("%d",&tks);
    while(tks--)
    {
        for(i=0;i<10010;i++)
            vec[i].clear();
        mp.clear();
        memset(deg,0,sizeof deg);
        cnt = k = 0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s%s",str1,str2);
            if(!mp[str1])
                mp[str1]=cnt++;
            if(!mp[str2])
                mp[str2]=cnt++;

            u = mp[str1];
            v = mp[str2];

            deg[v]++;
            vec[u].pb(v);
        }
        for(i=0;i<cnt;i++)
            if(deg[i]==0)
            {
                TS[k++]=i;
                Q.push(i);
            }
        BFS();
        if(k==cnt)
            printf("Case %d: Yes\n",ks++);
        else
            printf("Case %d: No\n",ks++);
    }


    return 0;
}
