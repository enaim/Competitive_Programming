#include <stdio.h>
#include <string.h>
#include <math.h>


long long BigMod (int b,int p,int m)
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

    int b,p,m,c;
    long long x;

    while(3==scanf("%d%d%d",&b,&p,&m))
    {
        x=BigMod(b,p,m);
        c=x;
        printf("%d\n",c);
    }

    return 0;
}
