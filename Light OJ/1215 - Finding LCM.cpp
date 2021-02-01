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
const int Prime_Size = 100010;

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

map<ll,ll>mp,mp1;
set<ll>st;
set<ll>::iterator it;
ll f,cnt;

void func(ll L)
{
    mp.clear();
    mp1.clear();
    st.clear();

    for(int i=1;prime[i]<=L/prime[i];i++)
    {
        cnt = 0LL;
        while(L%prime[i]==0LL)
        {
            cnt++;
            L/=prime[i];
        }
        if(cnt!=0LL)
        {
            mp[prime[i]]=cnt;
            st.insert(prime[i]);
        }
    }
    if(L!=1LL)
    {
        mp[L]=1LL;
        st.insert(L);
    }
}

void func1(ll n)
{
    if(f==1LL)
        return;
    for(int i=1;prime[i]<=n/prime[i];i++)
    {
        cnt = 0LL;
        while(n%prime[i]==0LL)
        {
            n/=prime[i];
            cnt++;
        }
        if(cnt)
        {
            if(mp[prime[i]]==0LL)
                f = 1LL;
            else
            {
                if(cnt>mp[prime[i]])
                    f = 1LL;
                if(cnt==mp[prime[i]])
                    mp1[prime[i]]=1LL;
            }
        }
        if(f)
            return;
    }
    if(n!=1LL)
    {
        if(mp[n]==0LL)
            f = 1LL;
        else
        {
            if(mp[n]==0LL)
                f = 1LL;
            else if(1LL==mp[n])
                mp1[n]=1LL;
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    Sieve();

    int tks,ks=1;
    ll a,b,ans,L,x;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld%lld%lld",&a,&b,&L);
        f = 0;
        func(L);
        func1(a);
        func1(b);
        ans = 1LL;
        for(it = st.begin();it!=st.end();it++)
        {
            if(mp1[*it]==0LL)
            {
                x = mp[*it];
                while(x--)
                    ans*=*it;
            }
        }
        if(f==1LL)
            printf("Case %d: impossible\n",ks++);
        else
            printf("Case %d: %lld\n",ks++,ans);
    }

    return 0;
}
