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
#include <queue>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO (1<<25)
#define sqr(a)  (a*a)

typedef long long ll;

const double pi = acos(-1.0);
const double eps = 1e-8;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

int ar[100010],br[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    long long n,temp,i,sum;

    while(1==scanf("%lld",&n))
    {
        sum = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            sum+=ar[i];
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&br[i]);
        }
        sort(&br[0],&br[n]);
        temp = br[n-1]+br[n-2];
        if(temp>=sum)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
