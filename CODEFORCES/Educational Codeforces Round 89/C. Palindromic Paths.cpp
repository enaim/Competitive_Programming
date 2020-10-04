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

struct node{
    int x,y,l;
};

int r,c;
int lev[2][32][32];
int vis[2][32][32];
int ar[32][32];
vector<int>vec[100];

void bfs(node u, int f)
{
    queue<node>Q;
    Q.push(u);
    vis[f][u.x][u.y]=1;
    lev[f][u.x][u.y]=1;
    while(!Q.empty())
    {
        node v;
        u = Q.front();
        Q.pop();
        if(u.x+1<r && vis[f][u.x+1][u.y]==0)
        {
            vis[f][u.x+1][u.y]=1;
            v.x = u.x+1;
            v.y = u.y;
            lev[f][v.x][v.y] = lev[f][u.x][u.y]+1;
            Q.push(v);
        }
        if(u.y+1<c && vis[f][u.x][u.y+1]==0)
        {
            vis[f][u.x][u.y+1]=1;
            v.x = u.x;
            v.y = u.y+1;
            lev[f][v.x][v.y] = lev[f][u.x][u.y]+1;
            Q.push(v);
        }
    }
    return;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int i,j,half,level;
        memset(vis,0,sizeof vis);
        memset(lev,0,sizeof lev);
        for(i=0;i<95;i++)
            vec[i].clear();

        scanf("%d%d",&r,&c);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                scanf("%d",&ar[i][j]);
        node u;
        u.x = 0;
        u.y = 0;
        bfs(u,0);

        level = r+c-1;
        half = (level+1)/2;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                int x = lev[0][i][j];
                if(x <= half)
                    vec[x].pb(ar[i][j]);
                else
                    vec[level-x+1].pb(ar[i][j]);
            }
        }
        int ans=0;
        if(level%2==1)
            half--;

        for(i=1;i<=half;i++)
        {
            int sz = vec[i].size();
            int cnt1=0,cnt2=0;
            for(j=0;j<sz;j++)
            {
                if(vec[i][j]==0)
                    cnt1++;
                else
                    cnt2++;
            }
            ans+=min(cnt1,cnt2);
        }
        printf("%d\n",ans);
    }

    return 0;
}
