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
#define OO (1<<25)

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
int mod = 1e9 + 7;
int n,k,x;
long long dp[110][1010];
long long go(int prev,int rem)
{
    if(rem == 0)
        return 1;
    long long &re = dp[prev][rem];
    if(re != -1)
        return re;

    re = 0;
    for(int i=1;i<=k;i++)
    {
        if(prev != i && !(rem==1 && i==x))
            re = (re%mod) + (go(i,rem-1)%mod);
    }
    return re;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(3==scanf("%d%d%d",&n,&k,&x))
    {
        memset(dp,-1,sizeof dp);
        long long ans = go(1,n-2);
        printf("%lld\n",ans);
    }

    return 0;
}
