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

ll dp[50][5];

ll go(ll n,ll k)
{
    if(n==0LL)
        return 1;

    ll &re = dp[n][k];
    if(re!=-1)
        return re;

    re = 0;
    if(k==0)
    {
        re += go(n-1,1);
        if(n>1)
            re += go(n-1,2);
    }
    if(k==1)
    {
        re += go(n-1,0);
        if(n>1)
            re += go(n-1,3);
    }
    if(k==2)
        re += go(n-1,1);
    if(k==3)
        re += go(n-1,0);
    return re;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll ans,n;
    memset(dp,-1,sizeof dp);
    while(1==scanf("%lld",&n))
    {
        ans = 0LL;
        ans += go(n-1,0);
        ans += go(n-1,1);
        printf("%lld\n",ans);
    }

    return 0;
}
