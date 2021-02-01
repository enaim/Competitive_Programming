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

#define OO         2e9+10
#define OOO        5e18+10
#define pb         push_back
#define nn         printf("\n")
#define sf(a)      scanf("%d",&a)
#define ssf(str)   scanf("%s",str)
#define pf(a)      printf("%d\n",a)
#define sl(a)      scanf("%lld",&a)
#define pl(a)      printf("%lld\n",a)
#define sf2(a,b)   scanf("%d%d",&a,&b)
#define pf2(a,b)   printf("%d %d\n",a,b)
#define sl2(a,b)   scanf("%lld%lld",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pl2(a,b)   printf("%lld %lld\n",a,b)
#define sl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define deb(a)     cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)  {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define FasterIO   ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MapPnt(a)  {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

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

const int SIZE = 610000;

struct node{
    ll x,y;
};

ll n;
ll BIT[SIZE];
node ar[SIZE];
node br[SIZE];
ll flag[SIZE];
ll fac[SIZE];
set<ll>st;
map<ll,ll>mp;

long long power(long long x, long long y, long long p)
{
    long long res = 1;
    x = x % p;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

long long modInverse(long long n, long long p)
{
    return power(n, p - 2LL, p);
}

long long nCrModPFermat(long long n,  long long r, long long p)
{
    if (r == 0LL)
        return 1LL;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

void update(ll index, ll v)
{
    while(index<=n)
    {
        BIT[index] += v;
        index += index &- index;
    }
}

ll Query(ll index)
{
    ll ans = 0LL;
    while(index>0)
    {
        ans += BIT[index];
        index -= index &- index;
    }
    return ans;
}


int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll i,j,ans,k;
    ll mod = 998244353;
    fac[0] = 1LL;
    for (int i = 1; i < SIZE; i++)
        fac[i] = (fac[i - 1] * i) % mod;

    while(scanf("%lld%lld",&n,&k)==2)
    {
        ll temp = n;
        for(i=1;i<=n;i++)
        {
            scanf("%lld%lld",&ar[i].x,&ar[i].y);
            st.insert(ar[i].x);
            st.insert(ar[i].y);
        }
        ll cnt = 1LL;
        for(auto it:st)
        {
            mp[it] = cnt++;
        }
        n = cnt-1;
        for(i=1;i<=temp;i++)
        {
            br[i].x = mp[ar[i].x];
            br[i].y = mp[ar[i].y];
        }

        for(i=1;i<=temp;i++)
            flag[br[i].y]++;

        for(i=1;i<=temp;i++)
        {
            update(br[i].x,1LL);
            update(br[i].y+1,-1LL);
        }

        ll sum = 0LL;
        for(i=1;i<=n;i++)
        {
            if(flag[i])
            {
                ans = Query(i);
                for(j=1;j<=flag[i];j++)
                {
                    ans--;
                    if(ans>=k-1)
                    {
                        sum += nCrModPFermat(ans,k-1LL,mod);
                        sum %= mod;
                    }
                    else
                        break;
                }
            }
        }
        pl(sum);
    }

    return 0;
}
