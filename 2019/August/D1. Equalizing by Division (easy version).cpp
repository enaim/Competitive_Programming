#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define OO 2e9+10
#define pb push_back
#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define ConPnt(a)   {for(auto it: a){cout<<it<<", ";}cout<<endl;}
#define MapPnt(a)   {for(auto it: a){cout<<it.first<<": "<<it.second<<", ";}cout<<endl;}

typedef long long ll;
typedef pair<int,int>pii;

template<class T>T sqr(T a){
    return a*a;
}
template<class T> T abs(T x){
    if(x<0) return -x;
    return x;
}

const double eps = 1e-8;
const double pi = acos(-1.0);

ll ar[200010];
ll br[200010];
ll cost[200010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll ans,i,n,x,k;
    while(2==scanf("%lld%lld",&n,&k))
    {
        ll mn = 1e19+10;
        for(i=0;i<n;i++)
            scanf("%lld",&br[i]);

        sort(&br[0],&br[n]);

        for(i=0;i<n;i++)
        {
            x = br[i];
            ar[x]++;
            if(ar[x]>=k)
                mn = min(mn,cost[x]);

            ll cnt = 1LL;
            while(x!=0LL)
            {
                ar[x/2LL]++;
                cost[x/2LL]+=cnt;
                x/=2LL;
                if(ar[x]>=k)
                    mn = min(mn,cost[x]);
                cnt++;
            }
        }

        printf("%lld\n",mn);
    }

    return 0;
}
