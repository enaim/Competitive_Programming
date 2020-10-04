#include <stdio.h>
#include <string.h>
#include <math.h>


long long BigMod (long long b,long long p,long long m)
{
    long long x;

    if( p==0 )
        return 1;

    x = BigMod(b,p/2,m);
    x = (x*x) % m;

    if(p%2 != 0)
        x=(x*b)%m;

    return x;
}


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    long long b,p,m,x;

    while(3==scanf("%lld%lld%lld",&b,&p,&m))
    {
        x=BigMod(b,p,m);
        printf("%lld\n",x);
    }

    return 0;
}
