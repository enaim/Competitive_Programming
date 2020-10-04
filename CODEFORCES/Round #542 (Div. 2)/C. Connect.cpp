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
    int x,y;
};
node ar[3000];
node br[3000];

int r,c,cnt;
int flag[60][60];
int vis1[60][60];
int vis2[60][60];

void bfs(node a)
{
    int i,j;
    queue<node>q;
    q.push(a);
    while(!q.empty())
    {
        node t = q.front();
        q.pop();
        if(vis1[t.x][t.y]==1)
            continue;
        vis1[t.x][t.y]=1;
        ar[cnt++]=t;
        for(j=0;j<4;j++)
        {
            int m = t.x+dr[j];
            int n = t.y+dc[j];
            if(m<1 || m>r)  continue;
            if(n<1 || n>c)  continue;
            if(flag[m][n]==0 && vis1[m][n]==0)
            {
                node z;
                z.x = m;
                z.y = n;
                q.push(z);
            }
        }
    }
}

void bfs1(node a)
{
    int i,j;
    queue<node>q;
    q.push(a);
    while(!q.empty())
    {
        node t = q.front();
        q.pop();
        if(vis2[t.x][t.y]==1)
            continue;
        vis2[t.x][t.y]=1;
        br[cnt++]=t;
        for(j=0;j<4;j++)
        {
            int m = t.x+dr[j];
            int n = t.y+dc[j];
            if(m<1 || m>r)  continue;
            if(n<1 || n>c)  continue;
            if(flag[m][n]==0 && vis2[m][n]==0)
            {
                node z;
                z.x = m;
                z.y = n;
                q.push(z);
            }
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int x,i,j,sum,m,n;
    node s,d;
    char str[100];
    while(1==scanf("%d",&r))
    {
        c = r;
        scanf("%d%d%d%d",&s.x,&s.y,&d.x,&d.y);
        for(i=0;i<r;i++)
        {
            scanf("%s",str);
            for(j=0;j<c;j++)
            {
                x = str[j]-'0';
                flag[i+1][j+1]=x;
            }
        }
        cnt = 0;
        bfs(s);
        m  = cnt;
        if(vis1[d.x][d.y]==1)
        {
            printf("0\n");
            continue;
        }
        cnt = 0;
        bfs1(d);
        n  = cnt;
        sum = OO;

        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                sum = min(sum,sqr(ar[i].x-br[j].x)+sqr(ar[i].y-br[j].y));
        printf("%d\n",sum);
    }

    return 0;
}
