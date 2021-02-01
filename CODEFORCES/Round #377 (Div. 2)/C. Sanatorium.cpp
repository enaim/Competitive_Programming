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
#include <queue>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)

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

    long long x,a,b,c,add;

    while(3==scanf("%lld%lld%lld",&a,&b,&c))
    {
        add = 0 ;

        if(a>=b && a>=c)
            x = a;
        else if(b>=a && b>=c)
            x=b;
        else
            x=c;

        if((x-1)>a)
            add+=(x-1-a);
        if((x-1)>b)
            add+=(x-1-b);
        if((x-1)>c)
            add+=(x-1-c);

        printf("%I64d\n",add);
    }

    return 0;
}
