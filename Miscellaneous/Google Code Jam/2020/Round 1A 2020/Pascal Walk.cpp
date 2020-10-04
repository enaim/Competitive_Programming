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

int dr[]={ -1,-1, 0, 0, 1, 1};
int dc[]={-1, 0, -1, 1, 0, 1};

struct node{
    int x,y;
};
node arr[510];
ll ar[510][510];
int vis[40][40];

int flag,ans;

void dfs(int i,int j,ll sum,int step,ll n)
{
    vis[i][j]=1;
    if(sum==n && step<=500)
    {
        ans = step;
        flag = 1;
        return;
    }
    if(step>=499)
        return;
    int a,b,k;
    for(k=0;k<6;k++)
    {
        a = i+dr[k];
        b = j+dc[k];
        if(a>=1 && b<=a && b>0 && a<35 && b<35)
        {
            if(vis[a][b]==1)
                continue;
            if(ar[a][b]==1e18)
                continue;
            if(sum+ar[a][b]>n)
                continue;
            dfs(a,b,sum+ar[a][b],step+1,n);
            if(flag==1)
            {
                break;
            }
        }
    }
    if(flag==1)
    {
        arr[step].x = a;
        arr[step].y = b;
    }
    vis[i][j]=0;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,j;
    ar[1][1]=1;
    ll sum=0LL;
    for(i=1;i<=505;i++)
    {
        ar[i][1]=ar[i][i]=1;
        for(j=2;j<i;j++)
        {
            if(ar[i-1][j-1]+ar[i-1][j]>1e9)
                ar[i][j]=1e18;
            else
                ar[i][j]=ar[i-1][j-1]+ar[i-1][j];
        }
    }

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(vis,0,sizeof vis);
        ll n;
        flag = 0;
        scanf("%lld",&n);
        if(n==1)
        {
            printf("Case #%d:\n",ks++);
            printf("1 1\n");
            continue;
        }
        flag = 0;
        dfs(1,1,1,0,n);
        printf("Case #%d:\n1 1\n",ks++);
        for(i=0;i<ans;i++)
            printf("%d %d\n",arr[i].x,arr[i].y);
    }


    return 0;
}

