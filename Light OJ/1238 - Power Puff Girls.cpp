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
node h;
int r,c,mx;
char str[21][21];
int vis[21][21];

void print(node a)
{
    printf("%d,%d - > %d\n",a.x,a.y,a.z);
}

void bfs(node v)
{
    int i,j,f=1;
    node t;
    queue<node>Q;
    Q.push(v);
    vis[v.x][v.y]=1;
    while(!Q.empty())
    {
        v = Q.front();
        Q.pop();
        for(i=0;i<4 && f;i++)
        {
            t.x = v.x + dr[i];
            t.y = v.y + dc[i];
            t.z = v.z + 1;
            if(t.x==h.x && t.y==h.y)
            {
                f = 0;
                mx = max(mx,t.z);
            }
            else if(t.x>=0 && t.y>=0 && t.x<r && t.y<c && vis[t.x][t.y]==0)
            {
                if(str[t.x][t.y]!='#')
                {
                    Q.push(t);
                    vis[t.x][t.y]=1;
                }
            }
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    node a,b,cc;
    int tks,ks=1,i,j;
    scanf("%d",&tks);
    while(tks--)
    {
        a.x=-1;
        a.y=-1;
        b.x=-1;
        b.y=-1;
        cc.x=-1;
        cc.y=-1;
        scanf("%d%d",&r,&c);
        for(i=0;i<r;i++)
        {
            scanf("%s",str[i]);
            for(j=0;j<c;j++)
            {
                if(str[i][j]=='a')
                    a.x = i,a.y = j,a.z=0;
                if(str[i][j]=='b')
                    b.x = i,b.y = j,b.z=0;
                if(str[i][j]=='c')
                    cc.x = i,cc.y = j,cc.z=0;
                if(str[i][j]=='h')
                    h.x = i,h.y = j;
                if(str[i][j]=='m')
                    str[i][j]='#';
            }
        }
        mx = 0;
        memset(vis,0,sizeof vis);
        bfs(a);
        memset(vis,0,sizeof vis);
        bfs(b);
        memset(vis,0,sizeof vis);
        bfs(cc);

        printf("Case %d: %d\n",ks++,mx);
    }

    return 0;
}
