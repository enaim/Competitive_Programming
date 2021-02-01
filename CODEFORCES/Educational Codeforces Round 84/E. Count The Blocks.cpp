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

ll mod = 998244353;
ll ans[200010];

long long BigMod (long long b,long long p,long long M)
{
    long long ans = 1;
    while(p)
    {
        if(p & 1)
            ans = (ans * b) % M;
        b = (b * b) % M;
        p = p >> 1;
    }

    return ans;
}

void func(ll n)
{
    ll sum = 0;

    ans[1] = 10LL;

    sum = 10LL;
    for(ll i=2LL;i<=n+5;i++)
    {
        ll x = (9LL*i) + 1LL;
        x = (x%mod)*BigMod(10,i-1,mod);
        ans[i] = ((x+mod) - sum)%mod;
        sum+=ans[i];
        sum = sum % mod;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll n;
    while(1==scanf("%lld",&n))
    {
        func(n);
        for(ll i=n;i>=1;i--)
            printf("%lld ",ans[i]);
        printf("\n");
    }

    return 0;
}
