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

vector<int>vec[410];
long long dp[25][25],n;

long long go(long long i ,long long j)
{
    for(int k=0;k<vec[i].size();k++)
    {
        if(vec[i][k] == j)
            return 0;
    }

    if(i==n && j==n)
        return 1;

    if(i>n || j>n)
        return 0;

    long long &re = dp[i][j];

    if(re != -1)
        return re;

    re = 0;
    re+= go(i,j+1) + go(i+1,j);

    return re;
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);


    int tks,ks=1,i,x,y;
    long long k;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(dp,-1,sizeof dp);
        for(i=0;i<22;i++)
            vec[i].clear();

        scanf("%lld%lld",&n,&k);
        for(i=0;i<k;i++)
        {
            scanf("%d%d",&x,&y);
            vec[x].pb(y);
        }

        long long ans = go(1,1);

        printf("%lld\n",ans);
    }

    return 0;
}
