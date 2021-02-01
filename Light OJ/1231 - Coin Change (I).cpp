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

const long long m=100000007;

ll n;
ll ar[60],cr[60];
ll dp[52][1010];

ll go(ll pos,ll k)
{
    if(k==0LL)
        return 1LL;
    if(k<0LL || pos==n)
        return 0;

    ll &re = dp[pos][k];

    if(re!=-1LL)
        return re;

    re = 0LL;
    for(ll i=0;i<=cr[pos];i++)
        re = ((re%m)+(go(pos+1,k-(ar[pos]*i))%m))%m;

    return re%m;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll i,ans,k;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        memset(dp,-1LL,sizeof dp);
        scanf("%lld%lld",&n,&k);
        for(i=0;i<n;i++)
            scanf("%lld",&ar[i]);
        for(i=0;i<n;i++)
            scanf("%lld",&cr[i]);

        ans = go(0LL,k);
        printf("Case %d: %lld\n",ks++,ans);
    }

    return 0;
}
