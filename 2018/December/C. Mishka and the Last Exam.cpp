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

#define ConPnt(a)   {for(auto i: a){cout<<i<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto i: a){cout<<i.first<<": "<<i.second<<", ";}cout<<endl;}

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

ll ar[200010],br[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll n,i,x;
    while(1==scanf("%lld",&n))
    {
        for(i=1;i<=n/2;i++)
            scanf("%lld",&br[i]);
        ar[0]=0;
        for(i=1;i<200010;i++)
            ar[i]=1e19;
        for(i=1;i<=n/2;i++)
        {
            x = ar[i-1];
            if(br[i]-x<=ar[n-i+2])
            {
                ar[i]=x;
                ar[n-i+1]=br[i]-x;
            }
            else
            {
                ar[n-i+1] = ar[n-i+2];
                ar[i] = br[i]-ar[n-i+1];
            }
        }
        for(i=1;i<=n;i++)
            printf("%lld ",ar[i]);
    }

    return 0;
}
