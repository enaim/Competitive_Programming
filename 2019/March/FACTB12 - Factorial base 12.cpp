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

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}
template<class T>T sqr(T a){
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;

const int FLAG_SIZE = 1001000;
const int PRIME_SIZE = 80000;

bool flag[FLAG_SIZE];
ll prime[PRIME_SIZE];

void sieve()
{
    ll i,j,ind = 1LL,d;
    prime[ind++]=2LL;

    for(i=3LL;i<FLAG_SIZE;i+=2LL)
    {
        if(flag[i] == false)
        {
            prime[ind++]=i;

            if(i > FLAG_SIZE/i)
                continue;

            for(j=i*i,d=i+i;j<=FLAG_SIZE;j+=d)
                flag[j]=true;
        }
    }
}

ll i,n,cnt,ans,t,b,x,mn;

map<ll,ll>mp,mp1;
set<ll>st;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    sieve();
    b = 12;
    for(i=1;prime[i]<=b/prime[i];i++)
    {
        cnt = 0LL;
        while(b%prime[i]==0LL)
        {
            b/=prime[i];
            cnt++;
        }
        if(cnt!=0LL)
        {
            st.insert(prime[i]);
            mp[prime[i]]=cnt;
        }
    }
    if(b!=1LL)
    {
        st.insert(b);
        mp[b]=1LL;
    }
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld",&n);
        mp1.clear();
        for(auto it: st)
        {
            x = it;
            t = x;
            ans = 0LL;
            while(x<=n)
            {
                ans+=(n/x);
                if(x<=n/t)
                    x = t*x;
                else
                    break;
            }
            mp1[t]=ans/mp[t];
        }

        mn = 9223372036854775807;
        for(auto it : st)
        {
            if(mn>mp1[it])
                mn = mp1[it];
        }
        printf("%lld\n",mn);
    }

    return 0;
}
