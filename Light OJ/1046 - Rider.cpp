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

int dr[]={ 1, 1,-1,-1,-2, 2,-2, 2};
int dc[]={-2, 2,-2, 2, 1, 1,-1,-1};

struct node{
    int x,y,z,r;
};
int r,c;
node ar[110];
int vis[11][11];
int sum[11][11];
char str[11][11];
int possible[11][11];

bool check(node t)
{
    if(t.x>=0 && t.x<r && t.y>=0 && t.y<c)
        return true;
    return false;
}

void bfs(int pos)
{
    int i;
    node v,t;
    v = ar[pos];
    vis[v.x][v.y]=1;
    queue<node>Q;
    Q.push(v);
    while(!Q.empty())
    {
        v = Q.front();
        Q.pop();
        sum[v.x][v.y]+=((v.z+v.r-1)/v.r);
        possible[v.x][v.y]++;
        for(i=0;i<8;i++)
        {
            t.x = v.x + dr[i];
            t.y = v.y + dc[i];
            t.z = v.z + 1;
            t.r = v.r;
            if(check(t) && vis[t.x][t.y]==0)
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

    int tks,ks=1,i,j,cnt;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(sum,0,sizeof sum);
        memset(possible,0,sizeof possible);

        scanf("%d%d",&r,&c);
        for(i=0;i<r;i++)
            scanf("%s",str[i]);

        cnt = 0;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                if(str[i][j]!='.')
                {
                    ar[cnt].x = i;
                    ar[cnt].y = j;
                    ar[cnt].z = 0;
                    ar[cnt].r = str[i][j]-'0';
                    cnt++;
                }
            }
        for(i=0;i<cnt;i++)
        {
            memset(vis,0,sizeof vis);
            bfs(i);
        }

        int mn = OO;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                if(possible[i][j]==cnt)
                    mn = min(mn,sum[i][j]);
        if(mn==OO)
            mn = -1;
        printf("Case %d: %d\n",ks++,mn);
    }

    return 0;
}
