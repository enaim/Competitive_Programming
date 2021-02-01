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

long long ar[200010],i,sum,ans,x,h,n,rem,mn,ind,y,z;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(2==scanf("%lld%lld",&h,&n))
    {
        sum = 0LL;
        mn = 0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&ar[i]);
            sum+=ar[i];
            if(sum<mn)
            {
                mn = sum;
                ind = i;
            }
        }
        if(sum>=0 && abs(mn)<h)
        {
            printf("-1\n");
            continue;
        }
        x = abs(mn);
        y = abs(sum);
        z = h-x;
        if(x>=h)
        {
            ans=0;
            rem = h;
        }
        else
        {
            ans = (z+y-1)/y;
            rem = h-(ans*y);
        }

        ans*=n;

        for(i=1;i<=n;i++)
        {
            if(ar[i]<0)
                rem -= abs(ar[i]);
            else
                rem += abs(ar[i]);
            ans++;
            if(rem<=0)
                break;
        }
        printf("%lld\n",ans);
    }

    return 0;
}
