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
#include <stack>
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

typedef long long ll;
typedef pair<int,int>pii;

template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}
template<class T>T sqr(T a){
    return a*a;
}

const double pi = acos(-1.0);
const double eps = 1e-8;


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll i,n,one,two,p1,p2,sum1,sum2;
    ll ar[100010];
    ll br[100010];

    while(1==scanf("%lld",&n))
    {
        for(i=1;i<=n;i++)
            scanf("%lld",&ar[i]);
        for(i=1;i<=n;i++)
            scanf("%lld",&br[i]);

        sort(&ar[1],&ar[n+1]);
        sort(&br[1],&br[n+1]);

        sum1 = sum2 = 0;
        p1 = n;
        p2 = n;

        one = ar[p1];
        two = br[p2];

        for(i=0;p1>0 || p2>0;i++)
        {
            if(i%2==0)
            {
                if((one>=two || p2<=0) && p1>0)
                {
                    sum1+=one;
                    p1--;
                }
                else
                    p2--;
            }
            else
            {
                if((one<=two || p1<=0) && p2>0)
                {
                    sum2+=two;
                    p2--;
                }
                else
                    p1--;
            }

            if(p1>0)
                one = ar[p1];
            if(p2>0)
                two = br[p2];
        }
        printf("%lld\n",sum1-sum2);
    }

    return 0;
}
