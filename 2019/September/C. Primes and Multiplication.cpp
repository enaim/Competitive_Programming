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

ll mod = 1e9+7;

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


const int FLAG_SIZE = 1001000;
const int PRIME_SIZE = 80000;

bool flag[FLAG_SIZE];
int prime[PRIME_SIZE];

void sieve()
{
    int i,j,ind = 1,d;
    prime[ind++]=2;

    for(i=3;i<FLAG_SIZE;i+=2)
    {
        if(flag[i] == false)
        {
            prime[ind++]=i;

            if(i > FLAG_SIZE/i) ///cause i*i > FLAG_SIZE
                continue;

            for(j=i*i,d=i+i;j<=FLAG_SIZE;j+=d)
                flag[j]=true;
        }
    }
}

bool IsPrime(ll n)
{
    int i;
    if(n==2LL)
        return true;
    if(n%2LL==0LL || n==1LL)
        return false;
    for(i=1;prime[i]<=n/prime[i];i++)
        if(n%prime[i]==0LL)
            return false;
    return true;
}


vector<ll>vec;
ll a,b,x,n,z,i,j,eq,last,sum;
ll ar[100];

int main()
{
    sieve();
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%lld%lld",&x,&n))
    {
        set<ll>st;
        vec.clear();
        for(i=2;i*i<=x;i++)
        {
            if(x%i==0LL)
            {
                z = x/i;
                st.insert(i);
                st.insert(z);
            }
        }
        st.insert(x);

        for(auto it:st)
        {
            if(IsPrime(it))
                vec.pb(it);
        }

        ll sz = vec.size();
        ll ans = 1LL;

        for(i=0;i<sz;i++)
        {
            z = 1LL;
            ll cnt = 0LL;
            int c = 1;
            for(j=1;j<=63;j++)
            {
                if(z>1e18/vec[i])
                    break;
                ar[c] = z*vec[i];
                z = ar[c];
                c++;
            }
            last = sum = 0LL;
            for(j=c-1;j>=1;j--)
            {
                cnt = (n/ar[j])-last;
                sum+=(cnt*j);
                last += cnt;
            }
            ans=((ans%mod)*BigMod(vec[i],sum,mod))%mod;
        }

        printf("%lld\n",ans);
    }

    return 0;
}
