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

ll n,c,mid,l,r,x,i,ans,t,mx;

ll func(ll t)
{
    return t*(c-(n*t));
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld%lld",&n,&c);
        if(n==0 || c==0)
        {
            ans = 0;
            printf("Case %d: %lld\n",ks++,ans);
            continue;
        }
        l = 0;
        r = c/n;
        mid = (l+r)/2;
        ans = 0;
        mx = -1e19;
        for(i=max(l,mid-10LL);i<=min(mid+10LL,r);i++)
        {
            t = func(i);
            if(t>mx)
            {
                mx = t;
                ans = i;
            }
        }

        printf("Case %d: %lld\n",ks++,ans);
    }

    return 0;
}
