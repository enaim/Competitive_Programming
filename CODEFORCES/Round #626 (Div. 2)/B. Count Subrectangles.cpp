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

ll cnt,cnt1,ans2,ans1,ans;
ll row[40010];
ll col[40010];
ll sum[40010];
ll sum1[40010];

void func(ll i,ll x)
{
    ll l,r,mid;

    l = 0;
    r = cnt1-1;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(col[mid]<i)
            l = mid+1;
        else
            r = mid-1;
    }
    ans1 = r+1;

    l = 0;
    r = cnt-1;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(row[mid]<x)
            l = mid+1;
        else
            r = mid-1;
    }
    ans2 = r+1;
}

void cal(ll left1,ll left2,ll i,ll x)
{
    ans = 0;
    ll s1,s2;
    if(left1>=cnt1 || left2>=cnt)
        return;
    if(left1>0)
        s2 = sum1[cnt1-1]-sum1[left1-1];
    else
        s2 = sum1[cnt1-1];

    if(left2>0)
        s1 = sum[cnt-1]-sum[left2-1];
    else
        s1 = sum[cnt-1];

    s1 = s1-((x-1)*(cnt-left2));
    s2 = s2-((i-1)*(cnt1-left1));
    ans = s1*s2;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll i,n,m,k,x;
    while(3==scanf("%lld%lld%lld",&n,&m,&k))
    {
        ll one = 0;
        cnt = 0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&x);
            if(x==1)
                one++;
            else
                row[cnt++]=one,one=0;
        }
        if(x==1)
            row[cnt++]=one;

        sort(&row[0],&row[cnt]);
        sum[0] = row[0];
        for(i=1;i<cnt;i++)
            sum[i]=row[i]+sum[i-1];

        one = 0;
        cnt1 = 0;
        for(i=0;i<m;i++)
        {
            scanf("%lld",&x);
            if(x==1)
                one++;
            else
                col[cnt1++]=one,one=0;
        }
        if(x==1)
            col[cnt1++]=one;

        sort(&col[0],&col[cnt1]);
        sum1[0] = col[0];
        for(i=1;i<cnt1;i++)
            sum1[i]=col[i]+sum1[i-1];

        ll result = 0LL;
        for(i=1;i<=sqrt(k+1);i++)
        {
            if(k%i==0)
            {
                x = k/i;
                func(i,x);
                cal(ans1,ans2,i,x);
                result+=ans;
                if(x!=i)
                {
                    func(x,i);
                    cal(ans1,ans2,x,i);
                    result+=ans;
                }
            }
        }
        printf("%lld\n",result);
    }

    return 0;
}
