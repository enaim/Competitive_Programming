#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <iostream>
#include <algorithm>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;

typedef long long ll;

const double pi = acos(-1.0);

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    long long mul,div,x,k,n,i,j,m,a,b;
    while(2==scanf("%lld%lld",&n,&k))
    {
        if(n==0 && k==0)
            break;

        if((n-k) > k)
        {
            j=1;
            mul=1;
            div=1;
            for(i=n-k+1;i<=n;i++)
            {
                m = __gcd(i,j);
                a = i/m;
                b = j/m;
                mul*=a;
                div*=b;
                m = __gcd(mul,div);
                mul/=m;
                div/=m;
                j++;
            }
        }
        else
        {
            j=1;
            mul=1;
            div=1;
            for(i=k+1;i<=n;i++)
            {
                m =__gcd(i,j);
                a = i/m;
                b = j/m;
                mul*=a;
                div*=b;
                m = __gcd(mul,div);
                mul/=m;
                div/=m;
                j++;
            }
        }
        printf("%lld\n",mul);
    }

    return 0;
}

