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

ll dp[510][510];

ll go(ll n,ll last)
{
    if(n==0LL)
        return 1LL;
    if(n<=last)
        return 0LL;
    ll &re = dp[n][last];
    if(re!=-1)
        return re;
    re = 0LL;
    for(ll i=last+1;i<=n;i++)
        re+=go(n-i,i);
    return re;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll ans,n;
    while(1==scanf("%lld",&n))
    {
        memset(dp,-1LL,sizeof dp);
        ans = 0LL;
        for(ll i=1;i<n;i++)
        {
            if(n-i>i)
                ans += go(n-i,i);
        }
        printf("%lld\n",ans);
    }

    return 0;
}
