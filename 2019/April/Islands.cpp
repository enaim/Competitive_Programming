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

int dr[]={1, 0, 0,-1};
int dc[]={0,-1, 1, 0};

struct node{
    int x,y;
};
int r,c;
int vis[60][60];
char str[60][60];


void bfs(node v)
{
    int i;
    node t;
    queue<node>Q;
    Q.push(v);
    vis[v.x][v.y]=1;
    while(!Q.empty())
    {
        v = Q.front();
        Q.pop();
        for(i=0;i<4;i++)
        {
            t.x = v.x+dr[i];
            t.y = v.y+dc[i];
            if(t.x>=0 && t.x<r && t.y>=0 && t.y<c)
            if(vis[t.x][t.y]==0 && str[t.x][t.y]!='W')
            {
                vis[t.x][t.y]=1;
                Q.push(t);
            }
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j;
    node t;
    while(2==scanf("%d%d",&r,&c))
    {
        memset(vis,0,sizeof vis);
        for(i=0;i<r;i++)
            scanf("%s",str[i]);
        int cnt = 0;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(str[i][j]=='L' && vis[i][j]==0)
                {
                    cnt++;
                    t.x = i;
                    t.y = j;
                    bfs(t);
                }
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}
