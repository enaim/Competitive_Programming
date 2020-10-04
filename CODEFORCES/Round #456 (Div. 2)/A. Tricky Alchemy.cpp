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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll a,b,c,x,y;
    while(5==scanf("%lld%lld%lld%lld%lld",&x,&y,&a,&b,&c))
    {
        a = (a*2) + b;
        b = b + (c*3);
        ll sum = 0;
        if(a>x)
            sum = a-x;
        if(b>y)
            sum+= b-y;
        cout<<sum<<endl;
    }

    return 0;
}
