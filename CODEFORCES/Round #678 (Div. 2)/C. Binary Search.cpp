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

const int SIZE = 1000010;
const int mod = 1e9+7;
long long fac[SIZE];
const double eps = 1e-8;
const double pi = acos(-1.0);

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

    return (((fac[n] * modInverse(fac[r], p))%p) * (modInverse(fac[n - r], p) % p)) % p;
}

void init()
{
    fac[0] = 1LL;
    for (int i = 1; i < SIZE; i++)
        fac[i] = (fac[i - 1] * i) % mod;
}


int dp[1010][1010];
int target;
vector<int>vec,vec2;

int go1(int left, int right)
{
    if(left>=right)
    {
        if(left>0 && left-1==target)
            return 1;
        return 0;
    }

    int &re = dp[left][right];
    if(re != -1)
        return re;
    re = 0;

    int mid = (left+right)/2;
    re = go1(mid+1,right);
    if(re==1)
    {
        if(mid!=target)
            vec.pb(0);
        return 1;
    }
    re = go1(left,mid);
    if(re==1)
    {
        if(mid!=target)
            vec.pb(1);
        return 1;
    }
    return re;
}

ll calculate(vector<int>vec,int n, int val)
{
    int sz = vec.size();
    int small = 0, big = 0, i;
    for(i=0;i<sz;i++)
        if(vec[i]==0)
            small++;
        else
            big++;
    if(small > val-1 || big > n-val)
        return 0;
    ll ans = fac[n-big-small-1]*((nCrModPFermat(n-val,big, mod)*nCrModPFermat(val-1,small, mod))%mod);
    ans%=mod;
    ans*=fac[big];
    ans%=mod;
    ans*=fac[small];
    ans%=mod;
    return ans;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    init();
    int n,val;
    ll ans = 0;
    while(3==scanf("%d%d%d",&n,&val,&target))
    {
        ans = 0;
        vec.clear();
        vec2.clear();
        memset(dp,-1,sizeof dp);
        int x = go1(0,n);

        reverse(vec.begin(),vec.end());

        ans += calculate(vec,n,val);

        pl(ans%mod);
    }

    return 0;
}
