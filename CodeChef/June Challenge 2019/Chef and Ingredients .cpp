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

const long long M = 1e9+7;

ll func(ll a,ll b)
{
    return ((a%M)*(b%M))%M;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll x,y,z,ans,temp,n,k,sum,a,rem,mul,t,m,sub;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld%lld",&n,&k);

        ans = 0LL;
        sum = k-1LL;

        z = max(0LL,k-n);
        m = n-1;
        t = z/m;
        rem = z%m;
        t  = t-1;

        mul = func(z,t+1);

        if(t%2==0LL)
        {
            a = t/2;
            sub = func(a,t+1)%M;
            sub = func(m,sub)%M;
        }
        else
        {
            a = (t+1)/2;
            sub = func(a,t)%M;
            sub = func(m,sub)%M;
        }

        ans = ((mul-sub)%M)+sum+rem;

        printf("%lld\n",(ans+M)%M);
    }

    return 0;
}
