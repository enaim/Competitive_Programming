#include <stdio.h>
#include <string.h>
#include <math.h>


long long BigMod (long long b,long long p,long long M)
{
    long long ans = 1;
    while(p)
    {
        if(p & 1)
            ans = (ans * b) % M;
        b = (b * b) % M;
        p = p >> 1;
    }

    return ans;
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
