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

ll flag[50010];
ll ar[50010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        ll a,b,i,l,r;
        int q;
        scanf("%lld%lld%d",&a,&b,&q);
        ll z = a*b;
        z = z/__gcd(a,b);
        ll sum=0LL;
        ar[0]=0LL;
        for(i=1LL;i<=z;i++)
        {
            flag[i]=0LL;
            ll x = (i%a)%b;
            ll y = (i%b)%a;
            if(x!=y)
                flag[i]=1LL,sum++;
            ar[i]=ar[i-1]+flag[i];
        }
        while(q--)
        {
            scanf("%lld%lld",&l,&r);
            int f = 0;
            ll ans = 0LL;
            ll temp1 = (l-1LL)%z;
            ll temp2 = r%z;
            ll val1 = (((l-1LL)/z)*sum)+ar[temp1];
            ll val2 = ((r/z)*sum)+ar[temp2];
            ans = val2 - val1;
            printf("%lld ",ans);
        }
        printf("\n");
    }

    return 0;
}
