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

typedef long long ll;
typedef pair<int,int>pii;

template<class T> T abs(T x)
{
    if(x<0)
        return -x;
    return x;
}
template<class T>T sqr(T a)
{
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;

ll ar[35];
ll arr[100010];

ll bin(ll x)
{
    ll l = 0,mid;
    ll r = 31;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(ar[mid]==x || (ar[mid]<x) && ar[mid+1]>x)
            return mid;
        if(ar[mid]>x)
            r = mid-1;
        else
            l = mid+1;
    }
    return mid;
}


ll go(ll n)
{
    ll x,y,z;
    if(n==1)
        return 1;
    if(n<100000)
        return arr[n];
    x = bin(n);
    y = 1<<x+1;
    z = 1<<x;
    if(1LL<<x==n)
        return 0;
    if(y-n==1)
        return 1;
    if(n-z==1)
        return 1;
    ll mn = OO;
    mn = min(mn,1+go(y-n));
    mn = min(mn,1+go(n-z));
    return mn;
}


ll go1(ll n)
{
    ll x,y,z;
    if(n==1)
        return 1;
    x = bin(n);
    y = 1<<x+1;
    z = 1<<x;
    if(1LL<<x==n)
        return 0;
    if(y-n==1)
        return 1;
    if(n-z==1)
        return 1;
    ll mn = OO;
    mn = min(mn,1+go1(y-n));
    mn = min(mn,1+go1(n-z));
    return mn;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll i,n;
    for(i=0;i<=34;i++)
        ar[i]=pow(2,i);
    arr[1]=1;
    for(i=2;i<100000;i++)
        arr[i]=go1(i);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld",&n);
        if(n==1)
            printf("1\n");
        else if(n<100000)
            printf("%lld\n",arr[n]+1);
        else
            printf("%lld\n",go(n)+1);
    }

    return 0;
}
