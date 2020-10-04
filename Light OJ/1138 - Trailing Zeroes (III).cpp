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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll l,r,sum,mid,x,n,mn;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld",&n);
        l = 1;
        r = 1e18;
        mn = OO;
        while(l<=r)
        {
            mid = (l+r)/2LL;
            x = 5;
            sum = 0;
            while(x<=mid)
            {
                sum+=(mid/x);
                x*=5;
            }
            if(sum==n)
            {
                mn = mid;
                r = mid-1;
            }
            else if(sum<n)
                l = mid+1;
            else
                r = mid-1;
        }
        if(mn==OO)
            printf("Case %d: impossible\n",ks++,mn);
        else
            printf("Case %d: %lld\n",ks++,mn);
    }

    return 0;
}
