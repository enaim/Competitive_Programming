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

int n,m,flag;
queue<node>Q;
vector<node>vec;
int vis[52][52];
int pos[52][52];
int imp[52][52];
char str[52][52];

void bfs(node u)
{
    int k;
    vis[u.x][u.y] = 1;
    Q.push(u);
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        vec.pb(u);
        if((u.x == n-1 && u.y == m-1) || pos[u.x][u.y]==1)
        {
            flag = 1;
            break;
        }
        if(imp[u.x][u.y]==1)
            break;
        for(k=0;k<4;k++)
        {
            int a = u.x+dr[k];
            int b = u.y+dc[k];
            if(a>=0 && a<n && b>=0 && b<m && str[a][b]!='#' && vis[a][b]==0)
            {
                vis[a][b]=1;
                node t;
                t.x = a;
                t.y = b;
                Q.push(t);
            }
        }
    }
    while(!Q.empty())
    {
        u = Q.front();
        vec.pb(u);
        Q.pop();
    }

    int sz = vec.size();
    if(flag == 1)
        for(k=0;k<sz;k++)
            pos[vec[k].x][vec[k].y]=1;
    else
        for(k=0;k<sz;k++)
            imp[vec[k].x][vec[k].y]=1;

    for(k=0;k<sz;k++)
        vis[vec[k].x][vec[k].y]=0;

    vec.clear();
    return;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,j,k,a,b;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(vis,0,sizeof vis);
        memset(pos,0,sizeof pos);
        memset(imp,0,sizeof imp);

        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%s",str[i]);

        int f=0,g=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(str[i][j]=='G')
                    g++;
                else if(str[i][j]=='B')
                {
                    for(k=0;k<4;k++)
                    {
                        a = i+dr[k];
                        b = j+dc[k];
                        if(a>=0 && a<n && b>=0 && b<m && str[a][b]=='.')
                            str[a][b]='#';
                        else if(a>=0 && a<n && b>=0 && b<m && str[a][b]=='G')
                            f = 1;
                    }
                }
            }
        }
        if(g==0)
        {
            printf("Yes\n");
            continue;
        }
        if(f)
        {
            printf("No\n");
            continue;
        }
        f = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(str[i][j]=='G' || str[i][j]=='B')
                {
                    node u;
                    u.x = i;
                    u.y = j;

                    flag = 0;
                    bfs(u);

                    if(flag)
                    {
                        if(str[i][j]=='B')
                        {
                            f = 1;
                            break;
                        }
                    }
                    else if(str[i][j]=='G')
                    {
                        f = 1;
                        break;
                    }
                }
            }
            if(f)
                break;
        }
        if(f)
            printf("No\n");
        else
            printf("Yes\n");
    }

    return 0;
}
