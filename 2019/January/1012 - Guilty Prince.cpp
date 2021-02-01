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

char str[25][25];
int flag[25][25];
int cnt,w,h;

void dfs(int i,int j)
{
    flag[i][j]=1;
    cnt++;
    if(i+1<h)
    {
        if(str[i+1][j]=='.'&& flag[i+1][j]==0)
            dfs(i+1,j);
    }
    if(j+1<w)
    {
        if(str[i][j+1]=='.' && flag[i][j+1]==0)
            dfs(i,j+1);
    }
    if(i-1>-1)
    {
        if(str[i-1][j]=='.' && flag[i-1][j]==0)
            dfs(i-1,j);
    }
    if(j-1>-1)
    {
        if(str[i][j-1]=='.' && flag[i][j-1]==0)
            dfs(i,j-1);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,i,j,x,y;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(flag,0,sizeof flag);
        cnt = 0;
        scanf("%d%d",&w,&h);
        for(i=0;i<h;i++)
        {
            scanf("%s",str[i]);
            for(j=0;j<w;j++)
                if(str[i][j]=='@')
                    x = i,y = j;
        }
        dfs(x,y);

        printf("Case %d: %d\n",ks++,cnt++);
    }

    return 0;
}
