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


int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        int h,c,t;
        ll l,r,mid,ans;
        double sum1,sum2,sum,dif,target,ans1,ans2,mn;
        scanf("%d%d%d",&h,&c,&t);
        if(t==h)
        {
            printf("1\n");
            continue;
        }
        if(t*2<=h+c)
        {
            printf("2\n");
            continue;
        }
        target = t;
        l = 0;
        r = 1e12;
        while(l<=r)
        {
            mid = (l+r)/2;
            sum1 = (mid*h) + h;
            sum2 = (mid*c);
            sum = mid+mid;
            sum = sum+1.0;
            dif = (sum1+sum2)/(double)sum;
            if(dif>=target)
                l = mid+1;
            else
                r = mid-1;
        }
        mid = r+1;
        sum1 = (mid*h) + h;
        sum2 = (mid*c);
        sum = mid+mid;
        sum = sum+1.0;
        dif = (sum1+sum2)/(double)sum;
        mn = dif;
        ans = mid+mid+1;
        for(ll k = max(0LL,r-5);k<=r+5;k++)
        {
            mid = k;
            sum1 = (mid*h) + h;
            sum2 = (mid*c);
            sum = mid+mid;
            sum = sum+1.0;
            dif = (sum1+sum2)/(double)sum;
            if(abs(target-mn)>abs(target-dif))
            {
                ans = mid+mid+1;
                mn = dif;
            }
            else if(abs(abs(target-mn)-abs(target-dif))<eps && ans>mid+mid+1)
            {
                ans = mid+mid+1;
                mn = dif;
            }
        }

        printf("%lld\n",ans);
    }

    return 0;
}
