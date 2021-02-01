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

ll func(ll n)
{
    ll sum=0,i,j,k;
    ll cnt = (n*(n-3))/2;
    cnt-=(n-3);
    for(i=2;i<=n;i++)
    {
        if(i==n-1)
            n--;
        for(j=i+2;j<=n;j++)
        {
            cnt--;
            k = j;
            ll node = k-i-1;
            ll connect = i - 1;
            sum+=(node*connect);
            if(cnt==0)
                break;
        }
        if(cnt==0)
            break;
    }
    return sum;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1;
    scanf("%d",&tks);
    while(tks--)
    {
        ll n;
        scanf("%lld",&n);
        printf("Case %d: %lld\n",ks++,func(n));
    }

    return 0;
}
