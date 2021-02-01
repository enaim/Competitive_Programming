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

ll ar[1000010];
ll i,n,k;

long long BigMod (long long b,long long p,long long m)
{
    long long x;

    if( p==0 )
        return 1;

    x = BigMod(b,p/2,m);
    x = (x*x) % m;

    if(p%2 != 0)
        x=(x*b)%m;

    return x;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    ar[0]=1;
    for(i=1;i<=1e6;i++)
    {
        ar[i]=ar[i-1]*i;
        ar[i]%=1000003;
    }
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld%lld",&n,&k);
        ll ans =((ar[k]*ar[n-k])%1000003);
        ans = ar[n]*BigMod(ans,1000003-2,1000003);
        printf("Case %d: %lld\n",ks++,ans%1000003);
    }

    return 0;
}
