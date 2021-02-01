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

    ll i,j,x[10000],ar[100],br[100],n,m,mx,ind;
    while(2==scanf("%lld%lld",&n,&m))
    {
        int cnt = 0;
        for(i=0;i<n;i++)
            scanf("%lld",&ar[i]);
        for(i=0;i<m;i++)
            scanf("%lld",&br[i]);

        mx = -1000000000000000020;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                x[cnt]=ar[i]*br[j];
                if(x[cnt]>mx)
                {
                    mx = x[cnt];
                    ind = i;
                }
                cnt++;
            }
        cnt = 0;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                if(ind==i)
                    continue;
                x[cnt]=ar[i]*br[j];
                cnt++;
            }
        sort(&x[0],&x[cnt]);
        printf("%lld\n",x[cnt-1]);
    }

    return 0;
}
