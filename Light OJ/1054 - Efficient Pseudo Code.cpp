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

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T> T abs(T x)
{
    if(x<0)
        return -x;
    return x;
}
template<class T>T sqr(T a)
{
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;

const int Flag_Size = 1000010;
const int Prime_Size = 100010;
const int M =1000000007;

bool flag[Flag_Size];
int prime[Prime_Size];

void Sieve()
{
    int i,j,ind = 1,d;
    prime[ind++]=2;

    for(i=3; i<Flag_Size; i+=2)
    {
        if(flag[i]==false)
        {
            prime[ind++]=i;
            if(i>Flag_Size/i)
                continue;
            for(j=i*i,d = i+i; j<Flag_Size; j+=d)
                flag[j]=true;
        }
    }
}

long long BigMod (long long b,long long p)
{
    ll ans = 1;
    while(p)
    {
        if(p & 1)
            ans = (ans * b) % M;
        b = (b * b) % M;
        p = p >> 1;
    }

    return ans;
}

ll divisor(ll n,ll m)
{
    ll i,sum=1LL,cnt;
    for(i=1; prime[i]<=n/prime[i]; i++)
    {
        cnt = 0;
        while(n%prime[i]==0)
        {
            cnt++;
            n/=prime[i];
        }
        sum*=((((BigMod(prime[i],(cnt*m)+1)-1)%M) * ((BigMod(prime[i]-1,M-2))%M))%M);
        sum%=M;
    }
    if(n!=1)
    {
        if(n%M==0)
            sum *= 1;
        else
            sum *= ((((BigMod(n,m+1)-1)%M) * (BigMod(n-1,M-2)%M))%M);
    }

    return sum%M;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    Sieve();

    int tks,ks=1;
    ll n,m;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld%lld",&n,&m);
        printf("Case %d: %lld\n",ks++,divisor(n,m));
    }

    return 0;
}
