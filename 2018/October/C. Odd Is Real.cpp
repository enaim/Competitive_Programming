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

ll func(ll l,ll r)
{
    ll first=0,second=0;
    ll x = sqrt(l);
    ll y = sqrt(r);

    if(x*x<l)
        x++;
    if(y*y>r)
        y--;

    if(x*x>=l && x*x<=r)
        first = x;
    if(y*y>=l && y*y<=r)
        second = y;

    if(!first || !second)
        return 0;

    if(x==y && first && second)
        return 1;

    return second-first+1;
}


ll func1(ll l,ll r,ll L,ll R)
{
    ll first=0,second=0;
    ll x = sqrt(l);
    ll y = sqrt(r);

    while(x*x*2<L)
        x++;
    while(y*y*2>R)
        y--;

    if(x*x*2>=L && x*x*2<=R)
        first = x;
    if(y*y*2>=L && y*y*2<=R)
        second = y;

    if(!first || !second)
        return 0;

    if(x==y && first && second)
        return 1;

    return second-first+1;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll sum;
    int tks,ks=1,i;
    scanf("%d",&tks);
    while(tks--)
    {
        ll l,r,sum=0;
        scanf("%lld%lld",&l,&r);
        ll l1 = (l+1)/2;
        ll r1 = (r+1)/2;

        sum += func(l,r);
        sum += func1(l1,r1,l,r);

        printf("Case %d: %lld\n",ks++,sum);
    }

    return 0;
}
