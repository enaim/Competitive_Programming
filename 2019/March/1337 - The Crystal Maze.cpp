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

int part,r,c,q;
int ar[3010];
char str[510][510];
int vis[510][510];
struct node{
    int x,y;
};
queue<node>Q;

void BFS(int i,int j)
{
    int cnt = 0;
    node v,t;
    v.x = i;
    v.y = j;
    if(str[v.x][v.y]=='C')
        cnt++;
    vis[v.x][v.y]=part;
    Q.push(v);
    while(!Q.empty())
    {
        v = Q.front();
        Q.pop();
        for(i=0;i<4;i++)
        {
            t.x = v.x+dr[i];
            t.y = v.y+dc[i];
            if(t.x>=0 && t.x<r && t.y>=0 && t.y<c)
            {
                if(vis[t.x][t.y]==0 && (str[t.x][t.y]=='.' || str[t.x][t.y]=='C'))
                {
                    Q.push(t);
                    vis[t.x][t.y]=part;
                    if(str[t.x][t.y]=='C')
                        cnt++;
                }
            }
        }
    }
    ar[part]=cnt;
    part++;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,j;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d",&r,&c,&q);
        memset(vis,0,sizeof vis);
        for(i=0;i<r;i++)
            scanf("%s",str[i]);
        part=1;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                if(vis[i][j]==0 && (str[i][j]=='.' || str[i][j]=='C'))
                    BFS(i,j);
            }

        printf("Case %d:\n",ks++);
        while(q--)
        {
            scanf("%d%d",&i,&j);
            printf("%d\n",ar[vis[i-1][j-1]]);
        }
    }

    return 0;
}
