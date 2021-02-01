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

ll flag[200010];
ll ar[200010];
ll mod = 998244353;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll n,k;
    while(2==scanf("%lld%lld",&n,&k))
    {
        ll mn = OO,i,last,sum=0LL,ans=1LL;
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
            if(ar[i]>n-k)
            {
                flag[i]=1LL;
                mn = min(mn,i);
                sum+=ar[i];
            }
        }
        last = mn;
        for(i=mn+1;i<n;i++)
        {
            if(flag[i])
            {
                ans = ans*(i-last);
                ans%=mod;
                last = i;
            }
        }
        printf("%lld %lld\n",sum,ans);
    }

    return 0;
}
