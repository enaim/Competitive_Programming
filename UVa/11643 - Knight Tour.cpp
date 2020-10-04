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
#include <queue>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

int dr[] = {-1,-2,-2,-1, 1, 2,2,1};
int dc[] = {-2,-1, 1, 2,-2,-1,1,2};

struct cell{
    int x,y;
};

int dis[1100][1100];
cell Knight[20];
int n,m;
int dp[(1<<16)-1][20];
int ar[1100][1100];


bool corner1(int pos)
{
    if( (Knight[pos].x == 1 && Knight[pos].y == 1 && Knight[1].x == 2 && Knight[1].y == 2)     ||
        (Knight[pos].x == 2 && Knight[pos].y == 2 && Knight[1].x == 1 && Knight[1].y == 1)     ||

        (Knight[pos].x == n && Knight[pos].y == n && Knight[1].x == n-1 && Knight[1].y == n-1) ||
        (Knight[pos].x == n-1 && Knight[pos].y == n-1 && Knight[1].x == n && Knight[1].y == n) ||

        (Knight[pos].x == 1 && Knight[pos].y == n && Knight[1].x == 2 && Knight[1].y == n-1)   ||
        (Knight[pos].x == 2 && Knight[pos].y == n-1 && Knight[1].x == 1 && Knight[1].y == n)   ||

        (Knight[pos].x == n && Knight[pos].y == 1 && Knight[1].x == n-1 && Knight[1].y == 2)   ||
        (Knight[pos].x == n-1 && Knight[pos].y == 2 && Knight[1].x == n && Knight[1].y == 1)      )
        return true;
    return false;
}


bool corner2(int pos,int i)
{
     if((Knight[pos].x == 1 && Knight[pos].y == 1 && Knight[i].x == 2 && Knight[i].y == 2)     ||
        (Knight[pos].x == 2 && Knight[pos].y == 2 && Knight[i].x == 1 && Knight[i].y == 1)     ||

        (Knight[pos].x == n && Knight[pos].y == n && Knight[i].x == n-1 && Knight[i].y == n-1) ||
        (Knight[pos].x == n-1 && Knight[pos].y == n-1 && Knight[i].x == n && Knight[i].y == n) ||

        (Knight[pos].x == 1 && Knight[pos].y == n && Knight[i].x == 2 && Knight[i].y == n-1)   ||
        (Knight[pos].x == 2 && Knight[pos].y == n-1 && Knight[i].x == 1 && Knight[i].y == n)   ||

        (Knight[pos].x == n && Knight[pos].y == 1 && Knight[i].x == n-1 && Knight[i].y == 2)   ||
        (Knight[pos].x == n-1 && Knight[pos].y == 2 && Knight[i].x == n && Knight[i].y == 1)     )
        return true;
    return false;
}


void bfs()
{
    memset(dis,0,sizeof dis);
    memset(ar,0,sizeof ar);

    queue<cell>Q;
    cell t,t1;
    t.x = 20;
    t.y = 20;
    Q.push(t);

    while(!Q.empty())
    {
        t = Q.front();
        Q.pop();
        for(int i=0;i<8;i++)
        {
            t1.x = t.x + dr[i];
            t1.y = t.y + dc[i];

            if(t1.x<1 || t1.x>1080 || t1.y<1 || t1.y>1080)
                continue;
            else if(!ar[t1.x][t1.y])
            {
                if(t1.x == 20 && t1.y == 20)
                {
                    ar[t1.x][t1.y] = 0;
                    continue;
                }
                else if(dis[abs(20-t1.x)][abs(20-t1.y)] == 0)
                    dis[abs(20-t1.x)][abs(20-t1.y)] = ar[t.x][t.y] + 1;

                ar[t1.x][t1.y] = ar[t.x][t.y] + 1;
                Q.push(t1);
            }
        }
    }
}


int  Knight_Tour(int k,int pos)
{
    if((1<<m)-1 == k)
    {
        if(corner1(pos))
            return 4;

        return dis[abs(Knight[1].x - Knight[pos].x)][abs(Knight[1].y - Knight[pos].y)];
    }

    int &re = dp[k][pos];
    if(re != -1)
        return re;
    re = OO;
    for(int i=2;i<=m;i++)
    {
        if((k & (1<<i-1)) == 0)
        {
            if(corner2(pos,i))
                re = min(re , 4 + Knight_Tour(k | (1<<i-1),i));
            else
                re = min(re ,dis[abs(Knight[pos].x - Knight[i].x)][abs(Knight[pos].y - Knight[i].y)]
                    + Knight_Tour(k | (1<<i-1),i));
        }
    }

    return re;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    bfs();

    int tks,ks=1,res;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(dp,-1,sizeof dp);
        scanf("%d%d",&n,&m);

        for(int i=1;i<=m;i++)
            scanf("%d%d",&Knight[i].x,&Knight[i].y);

        res = Knight_Tour(1,1);

        printf("Case %d: %d\n",ks++,res);
    }

    return 0;
}
