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

    long long a,b,c,n,x,y,ans,mx;

    while(4==scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&c))
    {
        ans = 0;
        x = n%4;
        y = 4 - x;
        if(y==1)
        {
            if(a<(b+c) && a<(c*3))
                ans = a;
            else if(c*3 < b+c)
                ans = c*3;
            else
                ans = b+c;
        }
        if(y==2)
        {
            if((2*a) < b && (2*a) < (2*c))
                ans = (2*a);
            else if(2*c < b)
                ans = 2*c;
            else
                ans = b;
        }
        if(y==3)
        {
            if((a*3) < (a+b))
                mx = a*3;
            else
                mx = a+b;
            if(mx<c)
                ans = mx;
            else
                ans = c;
        }

        printf("%I64d\n",ans);
    }

    return 0;
}
