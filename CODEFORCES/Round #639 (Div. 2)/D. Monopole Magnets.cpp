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

int dr[]={1, 0, 0,-1};
int dc[]={0,-1, 1, 0};

struct node{
    int x,y;
};

char str[1010][1010];
int vis[1010][1010];
int row[1010];
int col[1010];
int r,c;

void bfs(node u)
{
    vis[u.x][u.y]=1;
    queue<node>q;
    q.push(u);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            node v;
            v.x = dr[i]+u.x;
            v.y = dc[i]+u.y;
            if(v.x>=0 && v.x<r && v.y>=0 && v.y<c && str[v.x][v.y]=='#' && vis[v.x][v.y]==0)
                vis[v.x][v.y]=1,
                q.push(v);
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%d%d",&r,&c))
    {
        int flag=0,f,l,i,j;
        for(i=0;i<r;i++)
            scanf("%s",str[i]);

        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(str[i][j]=='#')
                    row[i]++;
            }
            if(row[i]<=1)
                continue;
            f = -1;
            l = -1;
            for(j=0;j<c;j++)
            {
                if(str[i][j]=='#')
                {
                    if(f==-1)
                        f = j;
                    l = j;
                }
            }
            if(l-f+1 != row[i])
            {
                flag = 1;
                break;
            }
        }
        if(flag)
        {
            printf("-1\n");
            continue;
        }
        for(j=0;j<c;j++)
        {
            for(i=0;i<r;i++)
            {
                if(str[i][j]=='#')
                    col[j]++;
            }
            if(col[j]<=1)
                continue;

            f = -1;
            l = -1;
            for(i=0;i<r;i++)
            {
                if(str[i][j]=='#')
                {
                    if(f==-1)
                        f = i;
                    l = i;
                }
            }
            if(l-f+1 != col[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag)
        {
            printf("-1\n");
            continue;
        }

        for(i=0;i<r;i++)
            if(row[i]==0)
                flag = 1;
        for(j=0;j<c;j++)
            if(col[j]==0)
                flag = 1;

        for(i=0;i<r;i++)
        {
            if(row[i]==0)
            {
                for(j=0;j<c;j++)
                    if(col[j]==0)
                        flag = 0;
            }
        }
        if(flag)
        {
            printf("-1\n");
            continue;
        }

        int cnt = 0;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(str[i][j]=='#' && vis[i][j]==0)
                {
                    node t;
                    t.x = i;
                    t.y = j;
                    bfs(t);
                    cnt++;
                }
            }
        }

        printf("%d\n",cnt);
    }

    return 0;
}
