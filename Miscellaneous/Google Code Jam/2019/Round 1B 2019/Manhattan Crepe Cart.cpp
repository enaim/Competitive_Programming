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

#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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
const int SIZE = 100010;

vector<int>vec1[100010],vec2[100010];

int n;
int BITx[SIZE];

void updatex(int index,int v)
{
    while(index<=n)
    {
        BITx[index] += v;
        index += index &- index;
    }
}

int Queryx(int index)
{
    int ans = 0;
    while(index>0)
    {
        ans += BITx[index];
        index -= index &- index;
    }
    return ans;
}


int BITy[SIZE];

void updatey(int index,int v)
{
    while(index<=n)
    {
        BITy[index] += v;
        index += index &- index;
    }
}

int Queryy(int index)
{
    int ans = 0;
    while(index>0)
    {
        ans += BITy[index];
        index -= index &- index;
    }
    return ans;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,x,y,q,mx1,mx2,i;
    char s[10];
    scanf("%d",&tks);
    while(tks--)
    {
        for(i=0;i<=1e5+5;i++)
        {
            vec1[i].clear();
            vec2[i].clear();
        }
        memset(BITx,0,sizeof BITx);
        memset(BITy,0,sizeof BITy);

        scanf("%d%d",&q,&n);
        n++;
        while(q--)
        {
            scanf("%d%d%s",&x,&y,s);
            x++;
            y++;
            if(s[0]=='E')
            {
                updatex(x+1,1);
                updatex(n+1,-1);
                updatey(1,1);
                updatey(n+1,-1);
            }
            if(s[0]=='W')
            {
                updatex(1,1);
                updatex(x,-1);
                updatey(1,1);
                updatey(n+1,-1);
            }
            if(s[0]=='N')
            {
                updatey(y+1,1);
                updatey(n+1,-1);
                updatex(1,1);
                updatex(n+1,-1);
            }
            if(s[0]=='S')
            {
                updatey(1,1);
                updatey(y,-1);
                updatex(1,1);
                updatex(n+1,-1);
            }
        }
        mx1 = -OO;
        for(i=0;i<=n;i++)
        {
            x = Queryx(i);
            mx1 = max(mx1,x);
            vec1[x].pb(i);
        }

        mx2 = -OO;
        for(i=0;i<=n;i++)
        {
            y = Queryy(i);
            mx2 = max(mx2,y);
            vec2[y].pb(i);
        }
        x = vec1[mx1][0];
        y = vec2[mx2][0];

        printf("Case #%d: %d %d\n",ks++,x-1,y-1);
    }


    return 0;
}
