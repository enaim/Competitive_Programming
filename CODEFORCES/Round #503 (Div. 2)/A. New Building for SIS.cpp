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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll n,h,a,b,k,ta,tb,fa,fb,sum1,sum2;
    while(5==scanf("%lld%lld%lld%lld%lld",&n,&h,&a,&b,&k))
    {
        while(k--)
        {
            scanf("%lld%lld%lld%lld",&ta,&fa,&tb,&fb);
            sum1 = abs(ta-tb);
            if(fa>fb)
                swap(fa,fb);
            if((a<=fa && fa<=b) || (a<=fb && fb<=b) || (ta==tb))
                sum2 = fb-fa;
            else
            {
                if(fa<a)
                {
                    sum2 = a-fa;
                    sum2+=abs(a-fb);
                }
                else
                {
                    sum2 = fa-b;
                    sum2+=abs(b-fb);
                }
            }
            printf("%lld\n",sum1+sum2);
        }
    }

    return 0;
}
