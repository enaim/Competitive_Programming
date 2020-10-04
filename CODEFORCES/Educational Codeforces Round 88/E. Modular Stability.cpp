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

const int mod = 998244353;

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

ll fact[500010];
ll inv[500010];

void Factorial()
{
    ll i = 0;
    fact[0]=1;
    for(i=1;i<500010;i++)
        fact[i]=(fact[i-1]*i)%mod;
}

void Inverse()
{
    ll i = 0;
    inv[0]=1;
    for(i=1;i<500010;i++)
        inv[i]=BigMod(fact[i],mod-2,mod);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll n,k,i;
    Factorial();
    Inverse();

    while(2==scanf("%lld%lld",&n,&k))
    {
        ll ans = 0;
        for(i=1;i<=n;i++)
        {
            ll x = (n/i);
            if(x<k)
                continue;
            ans += ((fact[x-1]*((inv[k-1]*inv[x-k])%mod))%mod);
            ans %= mod;
        }
        printf("%lld\n",ans);
    }

    return 0;
}
