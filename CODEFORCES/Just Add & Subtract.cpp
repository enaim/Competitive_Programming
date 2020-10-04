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
#include <queue>
#include <bitset>

using namespace std;

#define deb(a)    cout<<__LINE__<<"# "<<#a<<" -> "<<a<<endl;
#define pb push_back
#define OO 2e9+10

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

ll ar[100010];
ll sum[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    char str[3];
    ll n,l,r,q,i,m=1000000007;
    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        printf("Case %d:\n",ks++);
        scanf("%lld%lld",&n,&q);
        scanf("%lld",&ar[1]);
        sum[0]=0;
        sum[1]=0;
        ar[1] %= m;
        sum[1] = ar[1];
        for(i=2;i<=n;i++)
        {
            sum[i]=0;
            scanf("%lld",&ar[i]);
            ar[i] %= m;
            sum[i] = sum[i-1] + ar[i];
            sum[i] %= m;
        }
        while(q--)
        {
            scanf("%s",str);
            if(str[0]=='+')
            {
                scanf("%lld%lld",&l,&r);
                ll c = sum[r]-sum[l-1]+m;
                printf("%lld\n",c%m);
            }
            else
            {
                scanf("%lld%lld",&l,&r);
                ll c = (ar[l]-ar[r]) + m;
                printf("%lld\n",c%m);
            }
        }
    }

    return 0;
}
