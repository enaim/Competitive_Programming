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

ll func(ll n)
{
    return (n*(n+1))/2;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll l,r,n,x,mid;
    int tks,ks=1,f;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld",&n);
        f = 0;
        l = 1;
        r = 1e5;
        while(l<=r)
        {
            mid = (l+r)/2;
            x = func(mid);
            if(n==x)
            {
                f = 1;
                break;
            }
            if(x<n)
                l = mid+1;
            else
                r = mid-1;
        }
        if(f)
            printf("%lld\n",mid);
        else
            printf("NAI\n");
    }

    return 0;
}
