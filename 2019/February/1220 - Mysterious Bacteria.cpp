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

const int Flag_Size = 1000010;
const int Prime_Size = 80010;

bool flag[Flag_Size];
int prime[Prime_Size];

void Sieve()
{
    int i,j,ind = 1,d;
    prime[ind++]=2;

    for(i=3;i<Flag_Size;i+=2)
    {
        if(flag[i]==false)
        {
            prime[ind++]=i;
            if(i>Flag_Size/i)
                continue;
            for(j=i*i,d = i+i;j<Flag_Size;j+=d)
                flag[j]=true;
        }
    }
}

map<ll,ll>mp;
set<ll>st;
set<ll>:: iterator it;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    Sieve();

    ll tks,ks=1,n,x,ans,i,cnt,z,p;
    scanf("%lld",&tks);
    while(tks--)
    {
        mp.clear();
        st.clear();
        scanf("%lld",&n);
        z = n;
        n = abs(n);
        ans = 1;
        for(i=1;prime[i]<=n/prime[i];i++)
        {
            cnt = 0;
            p = prime[i];
            while(n%p==0)
            {
                cnt++;
                n/=p;
            }
            if(cnt)
            {
                st.insert(p);
                mp[p]=cnt;
            }
        }
        if(n!=1)
        {
            st.insert(n);
            mp[n]=1LL;
        }
        ans = 0;
        for(it=st.begin();it!=st.end();it++)
            ans = __gcd(ans,mp[*it]);
        if(z<0 && ans%2==0)
        {
            while(ans%2==0)
                ans/=2;
            printf("Case %lld: %lld\n",ks++,ans);
        }
        else
            printf("Case %lld: %lld\n",ks++,ans);
    }

    return 0;
}
