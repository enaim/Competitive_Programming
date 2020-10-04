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
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

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

int n,m;
ll dp[28][28];

ll go(int i,int j)
{
    if(i==m && j==n)
        return 1;
    if(i>m || j>n)
        return 0;
    ll &re = dp[i][j];
    if(re != -1)
        return re;
    re = 0;

    re += go(i,j+1);
    re += go(i+1,j);

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
        ll ans = go(1,1);
        printf("Case %d: %lld\n",ks++,ans);
    }

    return 0;
}
