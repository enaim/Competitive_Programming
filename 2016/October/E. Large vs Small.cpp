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


    double mx,mn,n;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lf",&n);
        if(ks == 1)
        {
            mx = n;
            mn = n;
        }
        else if(mx < n)
        {
            mx = n;
        }
        else if(mn > n)
            mn = n;

        printf("Case %d: %.2lf\n",ks++,mx/mn);
    }


    return 0;
}
