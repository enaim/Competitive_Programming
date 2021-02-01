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

ll ar[100010];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        ll cnt = 0,i,n,sum=0LL,x,z;
        scanf("%lld%lld",&n,&x);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&z);
            if(z>=x)
                sum+=(z-x);
            else
                ar[cnt++]=z;
        }
        sort(&ar[0],&ar[cnt],greater<ll>());
        ll cnt1 = 0;
        for(i=0;i<cnt;i++)
        {
            if(sum+ar[i]>=x)
            {
                sum-=(x-ar[i]);
                cnt1++;
                continue;
            }
            break;
        }
        printf("%lld\n",(n-cnt)+cnt1);
    }

    return 0;
}
