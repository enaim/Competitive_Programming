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

int dr[] = {-2,-2,-1,-1, 1,1, 2,2};
int dc[] = {-1, 1,-2, 2,-2,2,-1,1};

int dx[]={-1,-1,-1, 0, 0, 1, 1, 1};
int dy[]={-1, 0, 1,-1, 1,-1, 0, 1};


const int SIZE = 110;

char str[SIZE][SIZE];
int dis[SIZE][SIZE];
bool flag[SIZE][SIZE];

struct vartex{
    int row,column;
};
vartex a;
int r,c;

void Colour()
{
    int i,j,l,x,y;

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        {
            if(str[i][j]=='A')
            {
                a.row    = i;
                a.column = j;
            }
            if(str[i][j]=='Z')
            {
                flag[i][j]=false;
                for(l=0;l<8;l++)
                {
                    x = i + dr[l];
                    y = j + dc[l];
                    if(x < r && x>=0 && y <c && y>=0)
                    {
                        if(str[x][y]!='A' && str[x][y]!='B')
                            flag[x][y] =false;
                    }
                }
            }
        }
}


int BFS()
{
    int i,j,x,y;
    vartex h;
    queue<vartex>Q;
    Q.push(a);
    dis[a.row][a.column]=0;
    flag[a.row][a.column]=false;

    while(!Q.empty())
    {
        h = Q.front();
        Q.pop();
        for(i=0;i<8;i++)
        {
            x = h.row+dx[i];
            y = h.column+dy[i];
            if(x < r && x>=0 && y <c && y>=0)
            {
                if(flag[x][y])
                {
                    a.row    = x;
                    a.column = y;
                    Q.push(a);
                    flag[x][y]=false;
                    dis[x][y]=dis[h.row][h.column]+1;
                }
                if(str[x][y]=='B')
                    return  dis[x][y];
            }
        }
    }

    return 0;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int tks,ks=1,ans,i;

    scanf("%d",&tks);
    while(tks--)
    {
        memset(flag,true,sizeof flag);

        scanf("%d%d",&r,&c);

        for(i=0;i<r;i++)
            scanf("%s",str[i]);

        Colour();
        ans = BFS();

        if(ans==0)
            printf("King Peter, you can't go now!\n");
        else
            printf("Minimal possible length of a trip is %d\n",ans);
    }

    return 0;
}
