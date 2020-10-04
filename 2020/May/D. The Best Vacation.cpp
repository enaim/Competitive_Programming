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

ll ar[400010];
ll sum1[400010];
ll sum2[400010];
ll i,n,x,dis,temp,val;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%lld%lld",&n,&x))
    {
        ll mx = 0LL, ans = 0LL;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&ar[i]);
            ar[i+n]=ar[i];
            mx = max(mx,ar[i]);
        }
        if(mx >= x)
        {
            temp = mx-x;
            ans = ((mx*(mx+1LL))/2LL)-((temp*(temp+1LL))/2LL);
            printf("%lld\n",ans);
            return 0;
        }
        n=n*2;
        i=0;
        sum1[0]=ar[i];
        sum2[0]=(ar[i]*(ar[i]+1LL))/2LL;
        for(i=1;i<n;i++)
        {
            sum1[i]=sum1[i-1]+ar[i];
            sum2[i]=sum2[i-1]+((ar[i]*(ar[i]+1LL))/2LL);
        }
        int l,r,mid,last;
        for(i=0;i<n;i++)
        {
            if(sum1[i]>=x)
            {
                l = 0;
                r = i;
                while(l<=r)
                {
                    mid = (l+r)/2;
                    if(mid==0)
                        dis = sum1[i];
                    else
                        dis = sum1[i]-sum1[mid-1];
                    if(dis>=x)
                    {
                        last = mid;
                        l = mid + 1;
                    }
                    else
                        r = mid - 1;
                }

                if(last==0)
                {
                    dis = sum1[i];
                    if(dis>x)
                        temp = dis-x;
                    val = sum2[i]-((temp*(temp+1LL))/2LL);
                }
                else
                {
                    dis = sum1[i]-sum1[last-1];
                    val = sum2[i]-sum2[last-1];
                    if(dis>x)
                        temp = dis-x;
                    val = val-((temp*(temp+1LL))/2LL);
                }
                ans = max(ans,val);
            }
        }

        printf("%lld\n",ans);
    }

    return 0;
}
