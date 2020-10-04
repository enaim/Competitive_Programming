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


    int tks,ks=1,cnt,i;
    double ans;
    long long n,b;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%lld%lld",&b,&n);

        ans = log(n)/log(b);

        if(ans>0)
            printf("Case %d: %.5lf\n",ks++,ans);
        else
            printf("Case %d: Math Error!\n",ks++);
    }

    return 0;
}
