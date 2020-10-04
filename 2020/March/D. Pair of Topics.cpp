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

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int i,n;
    while(1==scanf("%d",&n))
    {
        ll ans = 0;
        for(i=0;i<n;i++)
            scanf("%d",&ar[i]);
        for(i=0;i<n;i++)
            scanf("%d",&br[i]);
        for(i=0;i<n;i++)
            ar[i] = ar[i]-br[i];

        sort(&ar[0],&ar[n]);
        for(i=0;i<n-1;i++)
        {
            ll val;
            if(ar[i]<=0LL)
                val = abs(ar[i])+1LL;
            else
                val = -(ar[i]-1LL);

            int l=i+1,r=n-1,mid;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(val>ar[mid])
                    l = mid+1;
                else
                    r = mid-1;

            }
            ans+=(n-(r+1));
        }
        printf("%lld\n",ans);
    }

    return 0;
}
