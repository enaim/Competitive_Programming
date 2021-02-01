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

    int n,m,i,j;
    double ar[1010],br[1010],mass,oil,ans,mid;
    while(2==scanf("%d%d",&n,&m))
    {
        for(i=0;i<n;i++)
        {
            scanf("%lf",&ar[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%lf",&br[i]);
        }
        double l = 0;
        double f = 2e9;
        int ks = 1000;
        ans = 1e9+10;
        while(ks--)
        {
            mid = (l+f)/2.0;
            mass = m+mid;
            for(i=0;i<n;i++)
            {
                mass -= mass/ar[i];
                if(i==n-1)
                    continue;
                mass -= mass/br[i+1];
            }
            mass -= mass/br[0];
            if(mass>=m)
            {
                if(mid<ans)
                    ans = mid;
                f = mid;
            }
            else
                l = mid+.000000000001;
        }
        if(ans == 1e9+10)
            printf("-1\n");
        else
            printf("%.10lf\n",ans);
    }

    return 0;
}
