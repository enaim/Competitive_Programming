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

ll n,k,z,ans;

bool func(ll t)
{
//    cout<<" - > "<<t<<endl;
    for(ll i=t*k;i<=(t+1)*(k);i++)
    {
//        printf("i - >%d\n",i);
        if((i%k)*(i/k)==n)
        {
//            cout<<"naim"<<endl;
            if(i<ans)
                ans = i;
//            cout<<ans<<endl;
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll i;
    while(2==scanf("%lld%lld",&n,&k))
    {
        ans = 1e18;
        z = n*k;
        for(i=1;i<=k-1;i++)
            func(n/i);
        printf("%lld\n",ans);
    }

    return 0;
}
