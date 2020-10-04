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

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}
template<class T>T sqr(T a){
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;

ll x,y,n;

void first()
{
    ll sr,s,r,ans;
    sr = (x-1)/2;
    sr = n*sr;
    r = x%2;
    if(r==1)
        ans = ((y+1)/2) + sr;
    else
        ans = ((n+1)/2) + sr + (y/2);
    cout<<ans<<endl;
}

void second()
{
    ll s = ((n*n)+1)/2;
    ll sr,r,ans;
    sr = (x-1)/2;
    sr = n*sr;
    r = x%2;
    if(r==1)
        ans = (y/2) + sr;
    else
        ans = (n/2)+ sr+ ((y+1)/2);
    cout<<ans+s<<endl;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll q;
    while(2==scanf("%lld%lld",&n,&q))
    {
        while(q--)
        {
            scanf("%lld%lld",&x,&y);
            if(x%2==y%2)
                first();
            else
                second();
        }
    }

    return 0;
}
