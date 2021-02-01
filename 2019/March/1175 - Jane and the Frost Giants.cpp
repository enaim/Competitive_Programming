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

int dr[]={1, 0, 0,-1};
int dc[]={0,-1, 1, 0};

struct node{
    int x,y,z;
};

node jane;
int r,c,cnt,mn;
node fire[40010];
int vis[210][210];
int vis1[210][210];
int mov[210][210];
char str[210][210];

bool check(node t)
{
    if(t.x>=0 && t.x<r && t.y>=0 && t.y<c)
        return true;
    return false;
}

bool border(node v)
{
    if(v.x==0 || v.y==0 || v.x==r-1 || v.y == c-1)
        return true;
    return false;
}

void bfs()
{
    int i;
    node v,t;
    queue<node>Q;
    for(i=0;i<cnt;i++)
    {
        v = fire[i];
        vis[v.x][v.y]=1;
        mov[v.x][v.y]=0;
        Q.push(v);
    }
    while(!Q.empty())
    {
        v = Q.front();
        Q.pop();
        for(i=0;i<4;i++)
        {
            t.x = v.x+dr[i];
            t.y = v.y+dc[i];
            t.z = v.z+1;
            if(check(t) && vis[t.x][t.y]==0 && str[t.x][t.y]!='#')
            {
                vis[t.x][t.y]=1;
                mov[t.x][t.y]=t.z;
                Q.push(t);
            }
        }
    }
}

void bfs1()
{
    int i;
    mn=OO;
    node v,t;
    queue<node>Q;
    v = jane;
    vis1[v.x][v.y]=1;

    if(border(v) && mov[v.x][v.y]>0)
    {
        mn = 1;
        return;
    }
    Q.push(v);
    while(!Q.empty())
    {
        v = Q.front();
        Q.pop();
        for(i=0;i<4;i++)
        {
            t.x = v.x+dr[i];
            t.y = v.y+dc[i];
            t.z = v.z+1;
            if(check(t) && vis1[t.x][t.y]==0 && str[t.x][t.y]=='.' && t.z<mov[t.x][t.y])
            {
                vis1[t.x][t.y]=1;
                if(border(t))
                    mn = min(mn,t.z+1);
                Q.push(t);
            }
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,j;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d",&r,&c);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                vis[i][j]=0,vis1[i][j]=0;

        for(i=0;i<r;i++)
            scanf("%s",str[i]);

        cnt = 0;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                if(str[i][j]=='J')
                    jane.x = i,jane.y = j,jane.z = 0;
                else if(str[i][j]=='F')
                    fire[cnt].x = i,fire[cnt].y = j,fire[cnt].z = 0,cnt++;
        bfs();
        bfs1();
        if(mn==OO)
            printf("Case %d: IMPOSSIBLE\n",ks++);
        else
            printf("Case %d: %d\n",ks++,mn);
    }

    return 0;
}
