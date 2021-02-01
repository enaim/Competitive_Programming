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

int m,n;
int ar[10];
int dp[10][10];

int go(int pos,int prev)
{
    if(pos==n)
        return 1;
    int &re = dp[pos][prev];
    if(re!=-1)
        return re;
    re = 0;
    if(pos==0)
        for(int i=0;i<m;i++)
            re += go(pos+1,ar[i]);
    else
        for(int i=0;i<m;i++)
            if(abs(prev-ar[i])<=2)
                re += go(pos+1,ar[i]);
    return re;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(dp,-1,sizeof dp);
        scanf("%d%d",&m,&n);
        for(int i=0;i<m;i++)
            scanf("%d",&ar[i]);
        int ans = go(0,0);

        printf("Case %d: %d\n",ks++,ans);
    }

    return 0;
}
