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

ll sum;
ll ar[100010];
ll br[100010];
ll flag[100010];
ll l,r,mid,x,j,i,m,mx,mn,n,val;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(1==scanf("%lld",&n))
    {
        ll cnt = 0;
        sum = 0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&m);
            for(j=0;j<m;j++)
            {
                scanf("%lld",&x);
                if(j==0)
                {
                    mn = x;
                    mx = x;
                }
                else
                {
                    if(mn<x)
                        flag[i]=1LL;
                    mn = min(mn,x);
                    mx = max(mx,x);
                }
            }
            if(flag[i]==1LL)
                continue;
            ar[cnt]=mn;
            br[cnt++]=mx;

        }

        ll temp = n;
        n = cnt;
        cnt = 0;

        for(i=0;i<temp;i++)
        {
            if(flag[i]==1LL)
            {
                sum+=(((2LL*temp)-1LL)-(cnt*2LL));
                cnt++;
            }
        }

        sort(&ar[0],&ar[n]);
        sort(&br[0],&br[n]);

        for(i=0;i<n;i++)
        {
            val = ar[i];
            l = 0;
            r = n-1;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(br[mid]<=val)
                    l = mid+1;
                else
                    r = mid-1;
            }
            sum+=(n-(r+1));
        }
        printf("%lld\n",sum);
    }

    return 0;
}
