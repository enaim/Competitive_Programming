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

long long ar[100010];
long long sum[100010];
long long i,x,ind,n,q,ans,z;

ll func(ll n)
{
    return (n*(n+1))/2LL;
}

int main()
{
    int tks,ks=1,t;
    scanf("%d",&tks);
    while(tks--)
    {
        printf("Case %d:\n",ks++);
        scanf("%lld%lld",&n,&q);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&ar[i]);
            if(i!=0LL)
                sum[i]=ar[i]+sum[i-1];
            else
                sum[i]=ar[i];
        }

        ans = 0LL;
        for(i=0;i<n-1;i++)
            ans+=((n-1-i)*ar[i])-(sum[n-1]-sum[i]);

        while(q--)
        {
            scanf("%d",&t);
            if(t==0)
            {
                scanf("%lld%lld",&ind,&x);
                if(ar[ind]==x)
                    continue;
                else if(ar[ind]<x)
                    ans-=(abs(ar[ind]-x)*ind);
                else
                    ans+=(abs(ar[ind]-x)*ind);

                z = n-1-ind;
                ans-=(z*ar[ind]);
                ans+=(z*x);
                ar[ind]=x;
            }
            else
                printf("%lld\n",ans);
        }
    }

    return 0;
}
