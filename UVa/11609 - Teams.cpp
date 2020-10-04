#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <iostream>
#include <algorithm>

using namespace std;

const int m = 1000000007;

long long Modulo (int b,int p,int m)
{
    long long x;

    if( p==0 )
        return 1;

    x = Modulo(b,p/2,m);
    x = (x*x) % m;

    if(p%2 != 0)
        x=(x*b)%m;

    return x;
}



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,n;
    long long x;

    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d",&n);

        x=Modulo(2,n-1,m);
        int ans = (x*n)%m;

        printf("Case #%d: %d\n",ks++,ans);
    }

    return 0;
}

