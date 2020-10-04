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

    ll n,m,mn,mx,x,i,y;
    while(2==scanf("%lld%lld",&n,&m))
    {
        if(n==1 || m==0)
        {
            printf("%lld %lld\n",n,n);
            continue;
        }

        mn = min(n,m*2);
        for(i=1;i<=n;i++)
        {
            x = (i*(i-1))/2;

            if(x<=m)
                mx = n-i , y = x;
            else
                break;
        }
        if(m>y)
            mx--;
        printf("%lld %lld\n",n-mn,max(0LL,mx));
    }

    return 0;
}
